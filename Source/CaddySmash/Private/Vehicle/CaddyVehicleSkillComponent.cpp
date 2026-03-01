#include "Vehicle/CaddyVehicleSkillComponent.h"

#include "Curves/CurveFloat.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "HitRegister/HitRegisterTypes.h"
#include "HitRegisterCollision/HitRegisterCollisionSubsystem.h"
#include "HitRegisterCollision/HitRegisterCollisionTypes.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"

UCaddyVehicleSkillComponent::UCaddyVehicleSkillComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UCaddyVehicleSkillComponent::SetSkillConfig(const FCaddyVehicleBrakeDashSkillConfig& InConfig, bool bSnapToReady)
{
    BrakeDashConfig = InConfig;
    if (bSnapToReady)
    {
        AbortToReady();
    }
}

void UCaddyVehicleSkillComponent::BindSkillRig(UArcadeVehicleMovementComponent* InMovementComponent)
{
    MovementComponent = InMovementComponent;
    if (InMovementComponent)
    {
        InMovementComponent->AddTickPrerequisiteComponent(this);
    }
}

bool UCaddyVehicleSkillComponent::IsSkillRigReady() const
{
    return MovementComponent.IsValid();
}

void UCaddyVehicleSkillComponent::SetSkillInputPressed(const bool bPressed)
{
    bSkillInputPressed = bPressed;
}

bool UCaddyVehicleSkillComponent::CanTriggerSkillNow() const
{
    return BrakeDashConfig.bEnableBrakeDashSkill
        && SkillState == ECaddyVehicleSkillState::Ready
        && CooldownRemainingSeconds <= KINDA_SMALL_NUMBER;
}

void UCaddyVehicleSkillComponent::BeginPlay()
{
    Super::BeginPlay();
    ResolveRigReferences();
}

void UCaddyVehicleSkillComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    if (!IsSkillRigReady())
    {
        ResolveRigReferences();
    }

    if (!ShouldUpdateSkill())
    {
        return;
    }

    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!OwnerPawn || !Movement)
    {
        return;
    }

    CooldownRemainingSeconds = FMath::Max(0.0f, CooldownRemainingSeconds - DeltaTime);

    if (bUseGASAbilityStateMachine)
    {
        if (SkillState == ECaddyVehicleSkillState::Ready)
        {
            bUsingAbilityTargetAim = false;
            CurrentAbilityTargetActor = nullptr;
            CurrentAbilityTargetLocation = FVector::ZeroVector;
        }
        return;
    }

    const bool bTriggerSourceHeld = (BrakeDashConfig.TriggerMode == ECaddyVehicleSkillTriggerMode::BrakeThrottleCombo)
        ? IsComboTriggerHeld()
        : bSkillInputPressed;

    if (!bTriggerSourceHeld)
    {
        TriggerHoldSeconds = 0.0f;
        bTriggerLatch = false;
    }

    if (!BrakeDashConfig.bEnableBrakeDashSkill)
    {
        if (SkillState != ECaddyVehicleSkillState::Ready)
        {
            AbortToReady();
        }
        bUsingAbilityTargetAim = false;
        CurrentAbilityTargetActor = nullptr;
        CurrentAbilityTargetLocation = FVector::ZeroVector;
        return;
    }

    if (SkillState == ECaddyVehicleSkillState::Ready
        && CooldownRemainingSeconds <= KINDA_SMALL_NUMBER
        && bTriggerSourceHeld
        && !bTriggerLatch)
    {
        TriggerHoldSeconds += DeltaTime;
        if (TriggerHoldSeconds >= BrakeDashConfig.TriggerInputHoldSeconds)
        {
            bTriggerLatch = true;
            EnterBrakePhase();
        }
    }

    if (SkillState == ECaddyVehicleSkillState::Ready)
    {
        bUsingAbilityTargetAim = false;
        CurrentAbilityTargetActor = nullptr;
        CurrentAbilityTargetLocation = FVector::ZeroVector;
        return;
    }

    StateElapsedSeconds += DeltaTime;

    switch (SkillState)
    {
    case ECaddyVehicleSkillState::Braking:
    {
        UpdateAimDirection();
        RotateOwnerTowardCurrentAim(DeltaTime);

        const float BrakeDuration = FMath::Max(0.01f, BrakeDashConfig.BrakeDuration);
        const float T = FMath::Clamp(StateElapsedSeconds / BrakeDuration, 0.0f, 1.0f);
        const float SpeedAlpha = FMath::Clamp(EvaluateBrakeSpeedAlpha(T), 0.0f, 1.0f);
        CurrentOverrideSpeed = BrakingStartSpeed * SpeedAlpha;
        ApplyOverrideVelocity(BrakingVelocityDirection * CurrentOverrideSpeed);

        if (T >= 1.0f)
        {
            ApplyOverrideVelocity(FVector::ZeroVector);
            EnterChargingPhase();
        }
        break;
    }
    case ECaddyVehicleSkillState::Charging:
    {
        UpdateAimDirection();
        RotateOwnerTowardCurrentAim(DeltaTime);

        CurrentChargeSeconds = FMath::Clamp(StateElapsedSeconds, 0.0f, FMath::Max(0.01f, BrakeDashConfig.MaxChargeSeconds));
        CurrentChargeAlpha = EvaluateChargeAlpha(CurrentChargeSeconds);

        CurrentOverrideSpeed = 0.0f;
        ApplyOverrideVelocity(FVector::ZeroVector);

        const bool bReachedMaxCharge = CurrentChargeSeconds >= BrakeDashConfig.MaxChargeSeconds;
        const bool bCanRelease = CurrentChargeSeconds >= BrakeDashConfig.MinChargeSeconds;
        const bool bReleased = !bTriggerSourceHeld;

        if (bReachedMaxCharge || (bReleased && bCanRelease))
        {
            EnterDashPhase();
        }
        break;
    }
    case ECaddyVehicleSkillState::Dashing:
    {
        const float DashDuration = FMath::Max(0.01f, ActiveDashDuration);
        const float T = FMath::Clamp(StateElapsedSeconds / DashDuration, 0.0f, 1.0f);
        const float DashAlpha = FMath::Clamp(EvaluateDashSpeedAlpha(T), 0.0f, 1.0f);
        CurrentOverrideSpeed = ActiveDashPeakSpeed * DashAlpha;
        ApplyOverrideVelocity(FVector(DashDirection.X, DashDirection.Y, 0.0f) * CurrentOverrideSpeed);

        if (T >= 1.0f)
        {
            ExitDashPhase();
        }
        break;
    }
    default:
        break;
    }
}

float UCaddyVehicleSkillComponent::EvaluateBrakeSpeedAlpha(const float NormalizedTime) const
{
    if (BrakeDashConfig.BrakeSpeedAlphaCurve)
    {
        return BrakeDashConfig.BrakeSpeedAlphaCurve->GetFloatValue(NormalizedTime);
    }

    const float X = FMath::Clamp(NormalizedTime, 0.0f, 1.0f);
    return FMath::Pow(1.0f - X, 2.2f);
}

float UCaddyVehicleSkillComponent::EvaluateDashSpeedAlpha(const float NormalizedTime) const
{
    if (BrakeDashConfig.DashSpeedAlphaCurve)
    {
        return BrakeDashConfig.DashSpeedAlphaCurve->GetFloatValue(NormalizedTime);
    }

    const float X = FMath::Clamp(NormalizedTime, 0.0f, 1.0f);
    return FMath::InterpEaseInOut(1.0f, 0.0f, X, 1.6f);
}

float UCaddyVehicleSkillComponent::EvaluateChargeAlpha(const float ChargeSeconds) const
{
    const float MaxCharge = FMath::Max(0.01f, BrakeDashConfig.MaxChargeSeconds);
    const float HoldAlpha = FMath::Clamp(ChargeSeconds / MaxCharge, 0.0f, 1.0f);
    if (BrakeDashConfig.ChargeAlphaCurve)
    {
        return FMath::Clamp(BrakeDashConfig.ChargeAlphaCurve->GetFloatValue(HoldAlpha), 0.0f, 1.0f);
    }

    return HoldAlpha;
}

FVector2D UCaddyVehicleSkillComponent::ResolveFallbackAimDirection() const
{
    const AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return FVector2D(1.0f, 0.0f);
    }

    const FVector Forward = OwnerActor->GetActorForwardVector().GetSafeNormal2D();
    if (Forward.IsNearlyZero())
    {
        return FVector2D(1.0f, 0.0f);
    }

    return FVector2D(Forward.X, Forward.Y);
}

FVector UCaddyVehicleSkillComponent::ResolveAbilityTargetTraceDirection() const
{
    const UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (Movement && Movement->HasMoveIntent())
    {
        const FVector2D MoveIntent = Movement->GetMoveIntent();
        if (MoveIntent.SizeSquared() >= FMath::Square(BrakeDashConfig.AimInputDeadZone))
        {
            return FVector(MoveIntent.X, MoveIntent.Y, 0.0f).GetSafeNormal2D();
        }
    }

    if (const AActor* OwnerActor = GetOwner())
    {
        return OwnerActor->GetActorForwardVector().GetSafeNormal2D();
    }

    return FVector::ForwardVector;
}

bool UCaddyVehicleSkillComponent::TryResolveAbilityTargetAim(FVector2D& OutAimDirection)
{
    OutAimDirection = FVector2D::ZeroVector;
    CurrentAbilityTargetActor = nullptr;
    CurrentAbilityTargetLocation = FVector::ZeroVector;
    bUsingAbilityTargetAim = false;

    const FCaddyVehicleSkillAbilityTargetingConfig& TargetConfig = BrakeDashConfig.AbilityTargeting;
    if (!TargetConfig.bEnableAbilityTargeting)
    {
        return false;
    }

    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    UWorld* World = GetWorld();
    if (!OwnerPawn || !World)
    {
        return false;
    }

    const FVector TraceDirection = ResolveAbilityTargetTraceDirection();
    if (TraceDirection.IsNearlyZero())
    {
        return false;
    }

    const FVector TraceStart = OwnerPawn->GetActorLocation();
    const FVector TraceEnd = TraceStart + (TraceDirection * FMath::Max(10.0f, TargetConfig.TraceDistance));

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(CaddyVehicleSkillAbilityTarget), false, OwnerPawn);
    QueryParams.AddIgnoredActor(OwnerPawn);

    TArray<FHitResult> RawHits;
    bool bHadRawHit = false;
    if (TargetConfig.TraceRadius > KINDA_SMALL_NUMBER)
    {
        bHadRawHit = World->SweepMultiByChannel(
            RawHits,
            TraceStart,
            TraceEnd,
            FQuat::Identity,
            TargetConfig.TraceChannel,
            FCollisionShape::MakeSphere(TargetConfig.TraceRadius),
            QueryParams);
    }
    else
    {
        FHitResult LineHit;
        bHadRawHit = World->LineTraceSingleByChannel(
            LineHit,
            TraceStart,
            TraceEnd,
            TargetConfig.TraceChannel,
            QueryParams);
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
        if (!HitActor || HitActor == OwnerPawn || !HitComponent)
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
    if (TargetConfig.TargetingProfile)
    {
        if (UHitRegisterCollisionSubsystem* CollisionSubsystem = World->GetSubsystem<UHitRegisterCollisionSubsystem>())
        {
            FAttackRequest AttackRequest;
            AttackRequest.Instigator = OwnerPawn;

            FHitRegisterDedupeSettings NoDedupe;
            NoDedupe.Policy = EHitRegisterDedupePolicy::None;
            NoDedupe.CooldownSeconds = 0.0f;

            CollisionSubsystem->FilterCandidates(
                AttackRequest,
                RawBatch,
                TargetConfig.TargetingProfile,
                NoDedupe,
                FilteredBatch);
        }
    }

    if (FilteredBatch.Candidates.Num() <= 0)
    {
        DrawAbilityTargetDebug(TraceStart, TraceEnd, bHadRawHit, false, FVector::ZeroVector);
        return false;
    }

    const FHitCandidate& TargetCandidate = FilteredBatch.Candidates[0];

    FVector TargetLocation = TargetCandidate.Hit.ImpactPoint;
    if (TargetLocation.IsNearlyZero())
    {
        if (AActor* TargetActor = TargetCandidate.TargetActor.Get())
        {
            TargetLocation = TargetActor->GetActorLocation();
        }
        else if (UPrimitiveComponent* TargetComp = TargetCandidate.TargetComponent.Get())
        {
            TargetLocation = TargetComp->GetComponentLocation();
        }
    }

    FVector ToTarget = TargetLocation - OwnerPawn->GetActorLocation();
    ToTarget.Z = 0.0f;
    if (ToTarget.IsNearlyZero())
    {
        DrawAbilityTargetDebug(TraceStart, TraceEnd, bHadRawHit, false, FVector::ZeroVector);
        return false;
    }

    OutAimDirection = FVector2D(ToTarget.X, ToTarget.Y).GetSafeNormal();
    CurrentAbilityTargetActor = TargetCandidate.TargetActor;
    CurrentAbilityTargetLocation = TargetLocation;
    bUsingAbilityTargetAim = true;

    DrawAbilityTargetDebug(TraceStart, TraceEnd, bHadRawHit, true, TargetLocation);
    return true;
}

bool UCaddyVehicleSkillComponent::IsComboTriggerHeld() const
{
    const UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!Movement)
    {
        return false;
    }

    return Movement->GetThrottleInput() >= BrakeDashConfig.TriggerThrottleThreshold
        && Movement->GetBrakeReverseInput() >= BrakeDashConfig.TriggerBrakeThreshold;
}

void UCaddyVehicleSkillComponent::ResolveRigReferences()
{
    if (IsSkillRigReady())
    {
        return;
    }

    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn)
    {
        return;
    }

    if (!MovementComponent.IsValid())
    {
        MovementComponent = OwnerPawn->FindComponentByClass<UArcadeVehicleMovementComponent>();
    }
}

bool UCaddyVehicleSkillComponent::ShouldUpdateSkill() const
{
    const APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn || !OwnerPawn->HasAuthority())
    {
        return false;
    }

    return IsSkillRigReady();
}

void UCaddyVehicleSkillComponent::UpdateAimDirection()
{
    const UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!Movement)
    {
        return;
    }

    bUsingAbilityTargetAim = false;
    CurrentAbilityTargetActor = nullptr;
    CurrentAbilityTargetLocation = FVector::ZeroVector;

    FVector2D AbilityTargetAim = FVector2D::ZeroVector;
    const bool bHasAbilityTargetAim = TryResolveAbilityTargetAim(AbilityTargetAim);

    FVector2D InputAim = FVector2D::ZeroVector;
    const bool bHasInputAim = Movement->HasMoveIntent()
        && Movement->GetMoveIntent().SizeSquared() >= FMath::Square(BrakeDashConfig.AimInputDeadZone);
    if (bHasInputAim)
    {
        InputAim = Movement->GetMoveIntent().GetSafeNormal();
    }

    bool bSelectedAbilityTargetAim = false;
    FVector2D SelectedAim = CurrentAimDirection;
    switch (BrakeDashConfig.AbilityTargeting.AimSelectionMode)
    {
    case ECaddyVehicleSkillAimSelectionMode::InputOnly:
        if (bHasInputAim)
        {
            SelectedAim = InputAim;
        }
        break;
    case ECaddyVehicleSkillAimSelectionMode::AbilityTargetOnly:
        if (bHasAbilityTargetAim)
        {
            SelectedAim = AbilityTargetAim;
            bSelectedAbilityTargetAim = true;
        }
        break;
    case ECaddyVehicleSkillAimSelectionMode::AbilityTargetPreferInputFallback:
    default:
        if (bHasAbilityTargetAim)
        {
            SelectedAim = AbilityTargetAim;
            bSelectedAbilityTargetAim = true;
        }
        else if (bHasInputAim)
        {
            SelectedAim = InputAim;
        }
        break;
    }

    if (SelectedAim.IsNearlyZero())
    {
        SelectedAim = ResolveFallbackAimDirection();
    }

    CurrentAimDirection = SelectedAim.GetSafeNormal();
    if (CurrentAimDirection.IsNearlyZero())
    {
        CurrentAimDirection = FVector2D(1.0f, 0.0f);
    }

    if (!bSelectedAbilityTargetAim || !CurrentAbilityTargetActor.IsValid())
    {
        bUsingAbilityTargetAim = false;
        CurrentAbilityTargetActor = nullptr;
        CurrentAbilityTargetLocation = FVector::ZeroVector;
    }
}

void UCaddyVehicleSkillComponent::RotateOwnerTowardCurrentAim(const float DeltaTime)
{
    if (!BrakeDashConfig.bRotateOwnerToAimDuringCharge || CurrentAimDirection.IsNearlyZero())
    {
        return;
    }

    AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return;
    }

    const float TargetYaw = FMath::RadiansToDegrees(FMath::Atan2(CurrentAimDirection.Y, CurrentAimDirection.X));
    const float NewYaw = FMath::FixedTurn(
        OwnerActor->GetActorRotation().Yaw,
        TargetYaw,
        BrakeDashConfig.AimRotationRateDegPerSec * DeltaTime);
    OwnerActor->SetActorRotation(FRotator(0.0f, NewYaw, 0.0f));
}

void UCaddyVehicleSkillComponent::EnterBrakePhase()
{
    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!Movement)
    {
        return;
    }

    SkillState = ECaddyVehicleSkillState::Braking;
    StateElapsedSeconds = 0.0f;
    CurrentOverrideSpeed = 0.0f;
    CurrentChargeSeconds = 0.0f;
    CurrentChargeAlpha = 0.0f;
    ActiveDashDuration = 0.0f;
    ActiveDashPeakSpeed = 0.0f;

    UpdateAimDirection();
    if (CurrentAimDirection.IsNearlyZero())
    {
        CurrentAimDirection = ResolveFallbackAimDirection();
    }

    const FVector CurrentVelocity = Movement->GetPlanarVelocityWorld();
    BrakingStartSpeed = CurrentVelocity.Size2D();
    if (BrakingStartSpeed > KINDA_SMALL_NUMBER)
    {
        BrakingVelocityDirection = CurrentVelocity.GetSafeNormal2D();
    }
    else
    {
        BrakingVelocityDirection = FVector(CurrentAimDirection.X, CurrentAimDirection.Y, 0.0f).GetSafeNormal2D();
    }

    Movement->SetExternalVelocityControlEnabled(true);
}

void UCaddyVehicleSkillComponent::EnterChargingPhase()
{
    SkillState = ECaddyVehicleSkillState::Charging;
    StateElapsedSeconds = 0.0f;
    CurrentOverrideSpeed = 0.0f;
    CurrentChargeSeconds = 0.0f;
    CurrentChargeAlpha = 0.0f;
}

void UCaddyVehicleSkillComponent::EnterDashPhase()
{
    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!Movement)
    {
        AbortToReady();
        return;
    }

    UpdateAimDirection();
    DashDirection = CurrentAimDirection.IsNearlyZero() ? ResolveFallbackAimDirection() : CurrentAimDirection.GetSafeNormal();
    if (DashDirection.IsNearlyZero())
    {
        DashDirection = FVector2D(1.0f, 0.0f);
    }

    CurrentChargeSeconds = FMath::Clamp(CurrentChargeSeconds, 0.0f, FMath::Max(0.01f, BrakeDashConfig.MaxChargeSeconds));
    CurrentChargeAlpha = EvaluateChargeAlpha(CurrentChargeSeconds);

    ActiveDashDuration = FMath::Lerp(BrakeDashConfig.DashDurationAtMinCharge, BrakeDashConfig.DashDurationAtMaxCharge, CurrentChargeAlpha);
    ActiveDashPeakSpeed = FMath::Lerp(BrakeDashConfig.DashPeakSpeedAtMinCharge, BrakeDashConfig.DashPeakSpeedAtMaxCharge, CurrentChargeAlpha);
    ActiveDashDuration = FMath::Max(0.01f, ActiveDashDuration);
    ActiveDashPeakSpeed = FMath::Max(0.0f, ActiveDashPeakSpeed);

    SkillState = ECaddyVehicleSkillState::Dashing;
    StateElapsedSeconds = 0.0f;
    CurrentOverrideSpeed = 0.0f;
    Movement->SetExternalVelocityControlEnabled(true);
}

void UCaddyVehicleSkillComponent::ExitDashPhase()
{
    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    if (!Movement)
    {
        AbortToReady();
        return;
    }

    Movement->SetExternalVelocityControlEnabled(false);
    const float CarrySpeed = ActiveDashPeakSpeed * FMath::Clamp(BrakeDashConfig.PostDashCarryRatio, 0.0f, 1.0f);
    const FVector CarryVelocity = FVector(DashDirection.X, DashDirection.Y, 0.0f).GetSafeNormal2D() * CarrySpeed;
    Movement->SetExternalPlanarVelocityWorld(CarryVelocity);

    SkillState = ECaddyVehicleSkillState::Ready;
    StateElapsedSeconds = 0.0f;
    CurrentOverrideSpeed = 0.0f;
    BrakingStartSpeed = 0.0f;
    CooldownRemainingSeconds = FMath::Max(0.0f, BrakeDashConfig.CooldownSeconds);
    bUsingAbilityTargetAim = false;
    CurrentAbilityTargetActor = nullptr;
    CurrentAbilityTargetLocation = FVector::ZeroVector;
}

void UCaddyVehicleSkillComponent::AbortToReady()
{
    if (UArcadeVehicleMovementComponent* Movement = MovementComponent.Get())
    {
        Movement->SetExternalVelocityControlEnabled(false);
    }

    SkillState = ECaddyVehicleSkillState::Ready;
    StateElapsedSeconds = 0.0f;
    CurrentOverrideSpeed = 0.0f;
    BrakingStartSpeed = 0.0f;
    CurrentChargeSeconds = 0.0f;
    CurrentChargeAlpha = 0.0f;
    ActiveDashDuration = 0.0f;
    ActiveDashPeakSpeed = 0.0f;
    bUsingAbilityTargetAim = false;
    CurrentAbilityTargetActor = nullptr;
    CurrentAbilityTargetLocation = FVector::ZeroVector;
}

void UCaddyVehicleSkillComponent::ApplyOverrideVelocity(const FVector& InWorldVelocity)
{
    if (UArcadeVehicleMovementComponent* Movement = MovementComponent.Get())
    {
        Movement->SetExternalPlanarVelocityWorld(InWorldVelocity);
    }
}

void UCaddyVehicleSkillComponent::DrawAbilityTargetDebug(
    const FVector& TraceStart,
    const FVector& TraceEnd,
    const bool bHadRawHit,
    const bool bAcceptedTarget,
    const FVector& AcceptedTargetLocation) const
{
    const FCaddyVehicleSkillAbilityTargetingConfig& TargetConfig = BrakeDashConfig.AbilityTargeting;
    if (!TargetConfig.bEnableAbilityTargeting || !TargetConfig.bEnableDebugDraw)
    {
        return;
    }

    const APawn* OwnerPawn = Cast<APawn>(GetOwner());
    UWorld* World = GetWorld();
    if (!OwnerPawn || !OwnerPawn->IsLocallyControlled() || !World)
    {
        return;
    }

    const float PersistSeconds = FMath::Max(0.0f, TargetConfig.DebugPersistSeconds);
    const float Thickness = 2.0f;
    const FColor TraceColor = bAcceptedTarget
        ? FColor::Green
        : (bHadRawHit ? FColor::Yellow : FColor::Red);

    DrawDebugLine(
        World,
        TraceStart + FVector(0.0f, 0.0f, 25.0f),
        TraceEnd + FVector(0.0f, 0.0f, 25.0f),
        TraceColor,
        false,
        PersistSeconds,
        0,
        Thickness);

    if (TargetConfig.TraceRadius > KINDA_SMALL_NUMBER)
    {
        DrawDebugSphere(
            World,
            TraceEnd + FVector(0.0f, 0.0f, 25.0f),
            TargetConfig.TraceRadius,
            12,
            TraceColor,
            false,
            PersistSeconds,
            0,
            1.0f);
    }

    if (!bAcceptedTarget)
    {
        return;
    }

    DrawDebugLine(
        World,
        TraceStart + FVector(0.0f, 0.0f, 12.0f),
        AcceptedTargetLocation + FVector(0.0f, 0.0f, 12.0f),
        FColor::Cyan,
        false,
        PersistSeconds,
        0,
        Thickness);

    DrawDebugSphere(
        World,
        AcceptedTargetLocation + FVector(0.0f, 0.0f, 12.0f),
        20.0f,
        10,
        FColor::Cyan,
        false,
        PersistSeconds,
        0,
        1.5f);
}
