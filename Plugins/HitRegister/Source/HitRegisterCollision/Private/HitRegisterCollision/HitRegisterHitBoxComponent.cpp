#include "HitRegisterCollision/HitRegisterHitBoxComponent.h"

#include "HitRegisterCollision/HitRegisterHurtBoxComponent.h"

namespace
{
    static bool IsSelfOnlyTargeting(const UHitRegisterTargetingProfile* Profile)
    {
        return Profile && Profile->Mode == EHitTargetMode::SelfOnly;
    }
}

UHitRegisterHitBoxComponent::UHitRegisterHitBoxComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    SetCanEverAffectNavigation(false);
    SetGenerateOverlapEvents(true);
    SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void UHitRegisterHitBoxComponent::BeginPlay()
{
    Super::BeginPlay();
    LastSweepTransform = GetComponentTransform();
}

void UHitRegisterHitBoxComponent::BeginHitWindow(int32 AttackId)
{
    bActive = true;
    ActiveAttackId = AttackId;
    LastQueryTime = 0.f;
    LastSweepTransform = GetComponentTransform();
}

void UHitRegisterHitBoxComponent::EndHitWindow()
{
    bActive = false;
}

void UHitRegisterHitBoxComponent::StartContinuous(int32 AttackId)
{
    bActive = true;
    ActiveAttackId = AttackId;
    LastQueryTime = 0.f;
    LastSweepTransform = GetComponentTransform();
}

void UHitRegisterHitBoxComponent::StopContinuous()
{
    bActive = false;
}

void UHitRegisterHitBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bActive || Mode == EHitRegisterHitBoxMode::Disabled)
    {
        return;
    }

    if (Mode == EHitRegisterHitBoxMode::WindowSweep)
    {
        GenerateSweepCandidates();
    }
    else if (Mode == EHitRegisterHitBoxMode::ContinuousOverlap)
    {
        const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.f;
        if (QueryInterval <= 0.f || (Now - LastQueryTime) >= QueryInterval)
        {
            GenerateOverlapCandidates();
            LastQueryTime = Now;
        }
    }
}

void UHitRegisterHitBoxComponent::GenerateSweepCandidates()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    const FTransform Current = GetComponentTransform();
    const FVector Start = LastSweepTransform.GetLocation();
    const FVector End = Current.GetLocation();

    FCollisionQueryParams Params(SCENE_QUERY_STAT(HitRegisterHitBoxSweep), false, GetOwner());
    if (!IsSelfOnlyTargeting(TargetingProfile))
    {
        Params.AddIgnoredActor(GetOwner());
    }

    TArray<FHitResult> Hits;
    const FCollisionShape Shape = FCollisionShape::MakeBox(GetScaledBoxExtent());
    World->SweepMultiByChannel(Hits, Start, End, Current.GetRotation(), TraceChannel, Shape, Params);

    LastSweepTransform = Current;

    EmitCandidates(Hits);
}

void UHitRegisterHitBoxComponent::GenerateOverlapCandidates()
{
    TArray<UPrimitiveComponent*> Overlaps;
    GetOverlappingComponents(Overlaps);

    const bool bAllowOwner = IsSelfOnlyTargeting(TargetingProfile);
    AActor* OwnerActor = GetOwner();
    TArray<FHitResult> Hits;
    Hits.Reserve(Overlaps.Num());

    for (UPrimitiveComponent* Comp : Overlaps)
    {
        if (!Comp || Comp == this)
        {
            continue;
        }
        if (!bAllowOwner && bIgnoreOwner && OwnerActor && Comp->GetOwner() == OwnerActor)
        {
            continue;
        }

        AActor* TargetOwner = Comp->GetOwner();
        const FVector HitLoc = Comp->GetComponentLocation();
        const FVector HitNorm = FVector::UpVector;
        FHitResult Hit(TargetOwner, Comp, HitLoc, HitNorm);
        Hit.bBlockingHit = true;
        Hits.Add(Hit);
    }

    EmitCandidates(Hits);
}

void UHitRegisterHitBoxComponent::EmitCandidates(const TArray<FHitResult>& Hits)
{
    if (Hits.Num() == 0)
    {
        return;
    }

    const bool bAllowOwner = IsSelfOnlyTargeting(TargetingProfile);
    AActor* OwnerActor = GetOwner();
    FHitCandidateBatch Batch;
    Batch.Candidates.Reserve(Hits.Num());

    const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.f;

    for (const FHitResult& Hit : Hits)
    {
        if (!bAllowOwner && bIgnoreOwner && OwnerActor && Hit.GetActor() == OwnerActor)
        {
            continue;
        }
        FHitCandidate Candidate;
        Candidate.AttackId = ActiveAttackId;
        Candidate.Timestamp = Now;
        Candidate.Hit = Hit;
        Candidate.HitBox = this;
        Candidate.TargetActor = Hit.GetActor();
        Candidate.TargetComponent = Hit.GetComponent();
        Candidate.Tags = Tags;

        if (UPrimitiveComponent* Comp = Hit.GetComponent())
        {
            Candidate.HurtBox = Cast<UHitRegisterHurtBoxComponent>(Comp);
        }

        Batch.Candidates.Add(Candidate);
    }

    OnCandidatesGenerated.Broadcast(Batch);
}
