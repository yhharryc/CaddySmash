#include "Vehicle/Abilities/Targeting/CaddyVehicleSkillTargetActor_Trace.h"

#include "Abilities/GameplayAbility.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "HitRegister/HitRegisterTypes.h"
#include "HitRegisterCollision/HitRegisterCollisionSubsystem.h"
#include "HitRegisterCollision/HitRegisterCollisionTypes.h"
#include "HitRegisterCollision/HitRegisterTargetingProfile.h"

ACaddyVehicleSkillTargetActor_Trace::ACaddyVehicleSkillTargetActor_Trace(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    ShouldProduceTargetDataOnServer = true;
    bDestroyOnConfirmation = false;
    bReplicates = false;
    PrimaryActorTick.bCanEverTick = false;
}

void ACaddyVehicleSkillTargetActor_Trace::Configure(
    const float InTraceDistance,
    const float InTraceRadius,
    const ECollisionChannel InTraceChannel,
    UHitRegisterTargetingProfile* InTargetingProfile,
    const bool bInEnableDebugDraw,
    const float InDebugPersistSeconds)
{
    TraceDistance = FMath::Max(10.0f, InTraceDistance);
    TraceRadius = FMath::Max(0.0f, InTraceRadius);
    TraceChannel = InTraceChannel;
    TargetingProfile = InTargetingProfile;
    bEnableDebugDraw = bInEnableDebugDraw;
    DebugPersistSeconds = FMath::Max(0.0f, InDebugPersistSeconds);
}

void ACaddyVehicleSkillTargetActor_Trace::SetAimDirectionHint2D(const FVector2D& InAimDirectionHint)
{
    AimDirectionHint = InAimDirectionHint;
}

void ACaddyVehicleSkillTargetActor_Trace::StartTargeting(UGameplayAbility* Ability)
{
    Super::StartTargeting(Ability);
    SourceActor = Ability ? Ability->GetAvatarActorFromActorInfo() : nullptr;
}

FVector ACaddyVehicleSkillTargetActor_Trace::ResolveTraceDirection() const
{
    if (AimDirectionHint.SizeSquared() > KINDA_SMALL_NUMBER)
    {
        return FVector(AimDirectionHint.X, AimDirectionHint.Y, 0.0f).GetSafeNormal2D();
    }

    return SourceActor ? SourceActor->GetActorForwardVector().GetSafeNormal2D() : FVector::ForwardVector;
}

void ACaddyVehicleSkillTargetActor_Trace::ConfirmTargetingAndContinue()
{
    FGameplayAbilityTargetDataHandle OutTargetData;

    UWorld* World = GetWorld();
    AActor* Source = SourceActor.Get();
    if (!World || !Source || !ShouldProduceTargetData())
    {
        TargetDataReadyDelegate.Broadcast(OutTargetData);
        return;
    }

    const FVector TraceDirection = ResolveTraceDirection();
    if (TraceDirection.IsNearlyZero())
    {
        TargetDataReadyDelegate.Broadcast(OutTargetData);
        return;
    }

    const FVector TraceStart = Source->GetActorLocation();
    const FVector TraceEnd = TraceStart + (TraceDirection * TraceDistance);
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(CaddyVehicleSkillTargetActorTrace), false, Source);
    QueryParams.AddIgnoredActor(Source);

    TArray<FHitResult> RawHits;
    bool bHadRawHit = false;
    if (TraceRadius > KINDA_SMALL_NUMBER)
    {
        bHadRawHit = World->SweepMultiByChannel(
            RawHits,
            TraceStart,
            TraceEnd,
            FQuat::Identity,
            TraceChannel,
            FCollisionShape::MakeSphere(TraceRadius),
            QueryParams);
    }
    else
    {
        FHitResult LineHit;
        bHadRawHit = World->LineTraceSingleByChannel(LineHit, TraceStart, TraceEnd, TraceChannel, QueryParams);
        if (bHadRawHit)
        {
            RawHits.Add(LineHit);
        }
    }

    FHitCandidateBatch RawBatch;
    RawBatch.Candidates.Reserve(RawHits.Num());

    int32 AttackId = 1;
    for (const FHitResult& Hit : RawHits)
    {
        AActor* HitActor = Hit.GetActor();
        UPrimitiveComponent* HitComponent = Hit.GetComponent();
        if (!HitActor || HitActor == Source || !HitComponent)
        {
            continue;
        }

        FHitCandidate& Candidate = RawBatch.Candidates.AddDefaulted_GetRef();
        Candidate.TargetActor = HitActor;
        Candidate.TargetComponent = HitComponent;
        Candidate.Hit = Hit;
        Candidate.AttackId = AttackId++;
    }

    RawBatch.Candidates.Sort([TraceStart](const FHitCandidate& A, const FHitCandidate& B)
    {
        return FVector::DistSquared(TraceStart, A.Hit.ImpactPoint) < FVector::DistSquared(TraceStart, B.Hit.ImpactPoint);
    });

    FHitCandidateBatch FilteredBatch = RawBatch;
    if (TargetingProfile)
    {
        if (UHitRegisterCollisionSubsystem* CollisionSubsystem = World->GetSubsystem<UHitRegisterCollisionSubsystem>())
        {
            FAttackRequest AttackRequest;
            AttackRequest.Instigator = Source;

            FHitRegisterDedupeSettings NoDedupe;
            NoDedupe.Policy = EHitRegisterDedupePolicy::None;
            NoDedupe.CooldownSeconds = 0.0f;

            CollisionSubsystem->FilterCandidates(
                AttackRequest,
                RawBatch,
                TargetingProfile,
                NoDedupe,
                FilteredBatch);
        }
    }

    bool bAcceptedTarget = false;
    FVector AcceptedTargetLocation = FVector::ZeroVector;
    if (FilteredBatch.Candidates.Num() > 0)
    {
        FHitResult BestHit = FilteredBatch.Candidates[0].Hit;
        if (!BestHit.bBlockingHit)
        {
            BestHit.bBlockingHit = true;
            BestHit.TraceStart = TraceStart;
            BestHit.TraceEnd = TraceEnd;
        }

        OutTargetData.Add(new FGameplayAbilityTargetData_SingleTargetHit(BestHit));
        bAcceptedTarget = true;
        AcceptedTargetLocation = BestHit.ImpactPoint.IsNearlyZero()
            ? BestHit.Location
            : BestHit.ImpactPoint;
    }

    if (bEnableDebugDraw)
    {
        const APawn* SourcePawn = Cast<APawn>(Source);
        if (!SourcePawn || SourcePawn->IsLocallyControlled())
        {
            const FColor TraceColor = bAcceptedTarget
                ? FColor::Green
                : (bHadRawHit ? FColor::Yellow : FColor::Red);
            const float Thickness = 2.0f;

            DrawDebugLine(
                World,
                TraceStart + FVector(0.0f, 0.0f, 30.0f),
                TraceEnd + FVector(0.0f, 0.0f, 30.0f),
                TraceColor,
                false,
                DebugPersistSeconds,
                0,
                Thickness);

            if (TraceRadius > KINDA_SMALL_NUMBER)
            {
                DrawDebugSphere(
                    World,
                    TraceEnd + FVector(0.0f, 0.0f, 30.0f),
                    TraceRadius,
                    12,
                    TraceColor,
                    false,
                    DebugPersistSeconds,
                    0,
                    1.0f);
            }

            if (bAcceptedTarget)
            {
                DrawDebugLine(
                    World,
                    TraceStart + FVector(0.0f, 0.0f, 16.0f),
                    AcceptedTargetLocation + FVector(0.0f, 0.0f, 16.0f),
                    FColor::Cyan,
                    false,
                    DebugPersistSeconds,
                    0,
                    Thickness);
                DrawDebugSphere(
                    World,
                    AcceptedTargetLocation + FVector(0.0f, 0.0f, 16.0f),
                    18.0f,
                    10,
                    FColor::Cyan,
                    false,
                    DebugPersistSeconds,
                    0,
                    1.3f);
            }
        }
    }

    TargetDataReadyDelegate.Broadcast(OutTargetData);
}

