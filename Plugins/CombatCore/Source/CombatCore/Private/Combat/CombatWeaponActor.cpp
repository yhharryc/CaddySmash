#include "Combat/CombatWeaponActor.h"

#include "Combat/CombatCoreLog.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"

ACombatWeaponActor::ACombatWeaponActor()
{
    PrimaryActorTick.bCanEverTick = true;
    SetActorTickEnabled(false);

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    AimRoot = CreateDefaultSubobject<USceneComponent>(TEXT("AimRoot"));
    AimRoot->SetupAttachment(Root);
    AimRoot->SetMobility(EComponentMobility::Movable);

    MotionRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MotionRoot"));
    MotionRoot->SetupAttachment(AimRoot);
    MotionRoot->SetMobility(EComponentMobility::Movable);

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(MotionRoot);
    Mesh->SetMobility(EComponentMobility::Movable);

    Tip = CreateDefaultSubobject<USceneComponent>(TEXT("Tip"));
    Tip->SetupAttachment(Mesh);
}

void ACombatWeaponActor::BeginPlay()
{
    Super::BeginPlay();

    if (MotionRoot && MotionRoot->GetAttachParent() != AimRoot)
    {
        MotionRoot->AttachToComponent(AimRoot, FAttachmentTransformRules::KeepRelativeTransform);
    }
    if (Mesh && Mesh->GetAttachParent() != MotionRoot)
    {
        Mesh->AttachToComponent(MotionRoot, FAttachmentTransformRules::KeepRelativeTransform);
    }
    if (Tip && Tip->GetAttachParent() != Mesh)
    {
        Tip->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform);
    }

    MotionBaseLocation = MotionRoot->GetRelativeLocation();
    BaseAimRotation = AimRoot->GetRelativeRotation();

    if (bAttachToOwnerOnBeginPlay)
    {
        AActor* OwnerActor = GetOwner();
        if (OwnerActor)
        {
            USceneComponent* AttachComp = OwnerActor->FindComponentByClass<USkeletalMeshComponent>();
            if (!AttachComp)
            {
                AttachComp = OwnerActor->GetRootComponent();
            }
            if (AttachComp)
            {
                AttachToComponent(AttachComp, FAttachmentTransformRules::KeepRelativeTransform, AttachSocketName);
            }
        }
    }

    UpdateTickEnabled();
}

void ACombatWeaponActor::ExecuteAttack_Implementation(FCombatAttackContext& Context)
{
    CacheAttackContext(Context);
    ActiveThrustDistance = Context.ExecutionParams.bOverrideThrustDistance ? FMath::Max(0.f, Context.ExecutionParams.ThrustDistance) : -1.f;

    UE_LOG(LogCombatCore, Log, TEXT("CombatWeaponActor: ExecuteAttack %s MotionType=%d AutoPlay=%d"),
        *GetNameSafe(this),
        static_cast<int32>(MotionType),
        bAutoPlayMotionOnExecute ? 1 : 0);

    if (bAutoPlayMotionOnExecute)
    {
        StartMotion();
    }

    OnExecuteAttack(Context);
}

void ACombatWeaponActor::StartMotion()
{
    if (MotionType == EWeaponMotionType::None)
    {
        return;
    }

    MotionPhase = EMotionPhase::Out;
    MotionTime = 0.f;
    UpdateTickEnabled();
    OnMotionStarted();
}

void ACombatWeaponActor::StopMotion()
{
    MotionPhase = EMotionPhase::None;
    MotionTime = 0.f;
    ActiveThrustDistance = -1.f;
    MotionRoot->SetRelativeLocation(MotionBaseLocation);
    UpdateTickEnabled();
    OnMotionEnded();
    HandleMotionEnded();
    if (bAutoClearContextOnMotionEnd)
    {
        ClearCachedAttackContext();
    }
}

bool ACombatWeaponActor::IsMotionActive() const
{
    return MotionPhase != EMotionPhase::None;
}

void ACombatWeaponActor::AimAtActor(AActor* Target, bool bSnap)
{
    AimTarget = Target;
    if (Target)
    {
        if (bSnap || AimInterpSpeed <= 0.f)
        {
            ApplyAim(Target->GetActorLocation(), 0.f, true);
            bPendingAimInterp = false;
        }
        else
        {
            bPendingAimInterp = true;
        }
    }
    else
    {
        bPendingAimInterp = false;
    }
    UpdateTickEnabled();
}

void ACombatWeaponActor::ClearAimTarget()
{
    AimTarget.Reset();
    AimRoot->SetRelativeRotation(BaseAimRotation);
    bPendingAimInterp = false;
    UpdateTickEnabled();
}

bool ACombatWeaponActor::GetCachedAttackContext(FCombatAttackContext& OutContext) const
{
    if (!bHasCachedContext)
    {
        return false;
    }

    OutContext = CachedContext;
    return true;
}

void ACombatWeaponActor::ClearCachedAttackContext()
{
    CachedContext = FCombatAttackContext();
    bHasCachedContext = false;
}

void ACombatWeaponActor::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (bDrawAimDebug && AimRoot)
    {
        const FVector Start = AimRoot->GetComponentLocation();
        const FVector End = Start + (AimRoot->GetForwardVector() * AimDebugLength);
        DrawDebugLine(GetWorld(), Start, End, FColor::Cyan, false, -1.f, 0, 2.f);
    }

    UpdateAim(DeltaSeconds);

    if (MotionPhase != EMotionPhase::None)
    {
        UpdateMotion(DeltaSeconds);
    }
}

void ACombatWeaponActor::UpdateMotion(float DeltaSeconds)
{
    if (MotionPhase == EMotionPhase::None)
    {
        return;
    }

    MotionTime += DeltaSeconds;

    const float OutDuration = FMath::Max(0.001f, ThrustDuration);
    const float BackDuration = FMath::Max(0.001f, ReturnDuration);

    if (MotionPhase == EMotionPhase::Out)
    {
        const float Alpha = FMath::Clamp(MotionTime / OutDuration, 0.f, 1.f);
        const float Ease = FMath::InterpEaseOut(0.f, 1.f, Alpha, 2.f);
        const FVector Offset = ThrustAxis.GetSafeNormal() * GetMotionThrustDistance() * Ease;
        MotionRoot->SetRelativeLocation(MotionBaseLocation + Offset);

        if (Alpha >= 1.f)
        {
            MotionPhase = EMotionPhase::Return;
            MotionTime = 0.f;
        }
        return;
    }

    const float Alpha = FMath::Clamp(MotionTime / BackDuration, 0.f, 1.f);
    const float Ease = FMath::InterpEaseOut(1.f, 0.f, Alpha, 2.f);
    const FVector Offset = ThrustAxis.GetSafeNormal() * GetMotionThrustDistance() * Ease;
    MotionRoot->SetRelativeLocation(MotionBaseLocation + Offset);

    if (Alpha >= 1.f)
    {
        StopMotion();
    }
}

void ACombatWeaponActor::UpdateAim(float DeltaSeconds)
{
    if (!AimTarget.IsValid())
    {
        return;
    }

    const bool bAtTarget = ApplyAim(AimTarget->GetActorLocation(), DeltaSeconds, false);
    if (bPendingAimInterp && !bMaintainAimAtTarget && bAtTarget)
    {
        bPendingAimInterp = false;
        UpdateTickEnabled();
    }
}

bool ACombatWeaponActor::ApplyAim(const FVector& TargetLocation, float DeltaSeconds, bool bSnap)
{
    const FVector Origin = AimRoot->GetComponentLocation();
    FVector ToTarget = TargetLocation - Origin;
    if (bAimYawOnly)
    {
        ToTarget.Z = 0.f;
    }

    if (ToTarget.IsNearlyZero())
    {
        return true;
    }

    FRotator AimWorldRot = ToTarget.Rotation();
    if (bAimYawOnly)
    {
        AimWorldRot.Pitch = 0.f;
        AimWorldRot.Roll = 0.f;
    }
    AimWorldRot.Yaw += AimYawOffset;

    if (USceneComponent* Parent = AimRoot->GetAttachParent())
    {
        const FQuat ParentQuat = Parent->GetComponentQuat();
        const FQuat RelativeQuat = ParentQuat.Inverse() * AimWorldRot.Quaternion();
        FRotator DesiredRelRot = RelativeQuat.Rotator();
        if (!bSnap && AimInterpSpeed > 0.f)
        {
            const FRotator Current = AimRoot->GetRelativeRotation();
            const FRotator NewRot = FMath::RInterpTo(Current, DesiredRelRot, DeltaSeconds, AimInterpSpeed);
            AimRoot->SetRelativeRotation(NewRot);
            return NewRot.Equals(DesiredRelRot, 0.1f);
        }
        AimRoot->SetRelativeRotation(DesiredRelRot);
        return true;
    }
    FRotator DesiredWorldRot = AimWorldRot;
    if (!bSnap && AimInterpSpeed > 0.f)
    {
        const FRotator Current = GetActorRotation();
        const FRotator NewRot = FMath::RInterpTo(Current, AimWorldRot, DeltaSeconds, AimInterpSpeed);
        SetActorRotation(NewRot);
        return NewRot.Equals(AimWorldRot, 0.1f);
    }
    SetActorRotation(DesiredWorldRot);
    return true;
}

void ACombatWeaponActor::UpdateTickEnabled()
{
    const bool bWantsTick = (MotionPhase != EMotionPhase::None)
        || (AimTarget.IsValid() && (bMaintainAimAtTarget || bPendingAimInterp))
        || bDrawAimDebug;
    SetActorTickEnabled(bWantsTick);
}

float ACombatWeaponActor::GetMotionThrustDistance() const
{
    return ActiveThrustDistance >= 0.f ? ActiveThrustDistance : FMath::Max(0.f, ThrustDistance);
}

void ACombatWeaponActor::CacheAttackContext(const FCombatAttackContext& Context)
{
    CachedContext = Context;
    bHasCachedContext = true;
}

void ACombatWeaponActor::HandleMotionEnded()
{
}
