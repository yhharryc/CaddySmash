#include "Vehicle/CaddyVehicleFeelComponent.h"

#include "Camera/CameraShakeBase.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/Effects/CaddyVehicleCollisionCameraShake.h"

UCaddyVehicleFeelComponent::UCaddyVehicleFeelComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    FeelConfig.CollisionFeel.CameraShakeClass = UCaddyVehicleCollisionCameraShake::StaticClass();
}

void UCaddyVehicleFeelComponent::SetFeelConfig(const FCaddyVehicleFeelConfig& InConfig, bool bSnapToConfig)
{
    FeelConfig = InConfig;
    if (bSnapToConfig)
    {
        SnapToBaseTransform();
    }
}

void UCaddyVehicleFeelComponent::BindFeelRig(UArcadeVehicleMovementComponent* InMovementComponent, USceneComponent* InVisualComponent)
{
    MovementComponent = InMovementComponent;
    VisualComponent = InVisualComponent;
    CacheVisualBaseTransform();
    SnapToBaseTransform();
}

bool UCaddyVehicleFeelComponent::IsFeelRigReady() const
{
    return MovementComponent.IsValid() && VisualComponent.IsValid();
}

void UCaddyVehicleFeelComponent::BeginPlay()
{
    Super::BeginPlay();
    ResolveRigReferences();
    SnapToBaseTransform();
}

void UCaddyVehicleFeelComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    if (!IsFeelRigReady())
    {
        ResolveRigReferences();
    }

    if (!ShouldUpdateFeel())
    {
        return;
    }

    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    USceneComponent* Visual = VisualComponent.Get();
    if (!Movement || !Visual)
    {
        return;
    }

    if (!FeelConfig.bEnableFeel)
    {
        SnapToBaseTransform();
        return;
    }

    const float ForwardSpeed = Movement->GetForwardSpeed();
    const float LateralSpeed = Movement->GetLateralSpeed();

    float ForwardAccel = 0.0f;
    if (bHasPreviousForwardSpeed)
    {
        ForwardAccel = (ForwardSpeed - PreviousForwardSpeed) / DeltaTime;
    }
    PreviousForwardSpeed = ForwardSpeed;
    bHasPreviousForwardSpeed = true;

    float ForwardAccelAlpha = 0.0f;
    if (FeelConfig.bEnableAccelerationDeform)
    {
        ForwardAccelAlpha = FMath::Clamp(
            ForwardAccel / FMath::Max(1.0f, FeelConfig.MaxForwardAccelForDeform),
            -1.0f,
            1.0f);
    }
    CurrentForwardAccelAlpha = FMath::FInterpTo(
        CurrentForwardAccelAlpha,
        ForwardAccelAlpha,
        DeltaTime,
        FeelConfig.ScaleInterpSpeed);

    float SpeedStretchAlpha = 0.0f;
    if (FeelConfig.bEnableAccelerationDeform)
    {
        SpeedStretchAlpha = FMath::Clamp(
            FMath::Abs(ForwardSpeed) / FMath::Max(1.0f, FeelConfig.MaxSpeedForStretch),
            0.0f,
            1.0f);
    }
    CurrentSpeedStretchAlpha = FMath::FInterpTo(
        CurrentSpeedStretchAlpha,
        SpeedStretchAlpha,
        DeltaTime,
        FeelConfig.ScaleInterpSpeed);

    const FCaddyVehicleEngineScaleVibrationConfig& EngineScale = FeelConfig.EngineScaleVibration;
    const float TargetSpeedAlpha = FMath::Clamp(
        FMath::Abs(ForwardSpeed) / FMath::Max(1.0f, EngineScale.SpeedForCurveNormalization),
        0.0f,
        1.0f);
    CurrentEngineScaleSpeedAlpha = FMath::FInterpTo(
        CurrentEngineScaleSpeedAlpha,
        TargetSpeedAlpha,
        DeltaTime,
        FMath::Max(1.0f, EngineScale.FrequencyInterpSpeed));

    float VarianceTarget = 0.0f;
    float FrequencyTargetHz = 0.0f;
    float EngineStrengthTarget = 0.0f;
    if (EngineScale.bEnableEngineScaleVibration)
    {
        const float VarianceMultiplier = EvaluateEngineCurveMultiplier(
            EngineScale.VarianceBySpeedCurve,
            CurrentEngineScaleSpeedAlpha,
            1.45f,
            0.62f);
        const float FrequencyMultiplier = EvaluateEngineCurveMultiplier(
            EngineScale.FrequencyBySpeedCurve,
            CurrentEngineScaleSpeedAlpha,
            1.60f,
            0.58f);
        const float InputAmount = FMath::Max(Movement->GetThrottleInput(), Movement->GetBrakeReverseInput());

        VarianceTarget = (EngineScale.BaseVariance * VarianceMultiplier) + (InputAmount * EngineScale.ThrottleVarianceBoost);
        VarianceTarget = FMath::Clamp(VarianceTarget, 0.0f, EngineScale.MaxVariance);

        FrequencyTargetHz = (EngineScale.BaseFrequencyHz * FrequencyMultiplier) + (InputAmount * EngineScale.ThrottleFrequencyBoostHz);
        FrequencyTargetHz = FMath::Clamp(FrequencyTargetHz, EngineScale.MinFrequencyHz, EngineScale.MaxFrequencyHz);

        EngineStrengthTarget = VarianceMultiplier;
    }

    CurrentIdleStrength = FMath::FInterpTo(
        CurrentIdleStrength,
        EngineStrengthTarget,
        DeltaTime,
        FMath::Max(0.0f, EngineScale.VarianceInterpSpeed));
    CurrentEngineScaleVariance = FMath::FInterpTo(
        CurrentEngineScaleVariance,
        VarianceTarget,
        DeltaTime,
        FMath::Max(0.0f, EngineScale.VarianceInterpSpeed));
    CurrentEngineScaleFrequencyHz = FMath::FInterpTo(
        CurrentEngineScaleFrequencyHz,
        FrequencyTargetHz,
        DeltaTime,
        FMath::Max(0.0f, EngineScale.FrequencyInterpSpeed));

    if (CurrentEngineScaleFrequencyHz > KINDA_SMALL_NUMBER)
    {
        constexpr float TwoPi = 6.2831853071795864769f;
        EngineScaleOscillatorPhase = FMath::Fmod(
            EngineScaleOscillatorPhase + (CurrentEngineScaleFrequencyHz * DeltaTime * TwoPi),
            TwoPi);
    }
    else
    {
        EngineScaleOscillatorPhase = 0.0f;
    }

    if (EngineScale.bEnableEngineScaleVibration)
    {
        float Wave = FMath::Sin(EngineScaleOscillatorPhase);
        Wave += 0.35f * FMath::Sin((EngineScaleOscillatorPhase * 2.17f) + 1.1f);
        CurrentEngineScaleWave = FMath::Clamp(Wave / 1.35f, -1.0f, 1.0f);
    }
    else
    {
        CurrentEngineScaleWave = 0.0f;
    }

    float LeanTarget = 0.0f;
    if (FeelConfig.bEnableLateralLean)
    {
        const float LateralAlpha = FMath::Clamp(
            LateralSpeed / FMath::Max(1.0f, FeelConfig.LateralSpeedForMaxLean),
            -1.0f,
            1.0f);
        LeanTarget = -LateralAlpha * FeelConfig.MaxLateralLeanRollDeg;
    }
    CurrentLeanRollDeg = FMath::FInterpTo(CurrentLeanRollDeg, LeanTarget, DeltaTime, FeelConfig.OffsetInterpSpeed);

    if (FeelConfig.bUseMovementCollisionImpactPulseFallback)
    {
        TryTriggerImpactPulse(DeltaTime);
    }
    UpdateHitStop(DeltaTime);
    float ImpactPulseAlpha = 0.0f;
    if (FeelConfig.bEnableImpactPulse && ImpactPulseStartTime >= 0.0f && GetWorld())
    {
        const float Elapsed = GetWorld()->GetTimeSeconds() - ImpactPulseStartTime;
        const float Duration = FMath::Max(0.01f, FeelConfig.ImpactPulseDuration);
        const float T = FMath::Clamp(Elapsed / Duration, 0.0f, 1.0f);
        if (T >= 1.0f)
        {
            ImpactPulseStartTime = -1.0f;
            ImpactPulseStrength = 0.0f;
        }
        else
        {
            const float Envelope = (1.0f - T) * (1.0f - T);
            ImpactPulseAlpha = ImpactPulseStrength * Envelope;
        }
    }
    // Keep collision pulse snappy so left/right response is visible on the first frames.
    CurrentImpactStrength = FMath::Clamp(ImpactPulseAlpha, 0.0f, 1.0f);

    const FVector ImpactWorldNormal = ImpactPulseNormal.GetSafeNormal2D();
    const FVector ImpactLocationOffset = -ImpactWorldNormal * (FeelConfig.ImpactPulseLocationKick * CurrentImpactStrength);

    FVector ImpactLocalNormal = ImpactWorldNormal;
    if (Visual)
    {
        const FVector VisualForward = Visual->GetForwardVector().GetSafeNormal2D();
        const FVector VisualRight = Visual->GetRightVector().GetSafeNormal2D();
        ImpactLocalNormal = FVector(
            FVector::DotProduct(ImpactWorldNormal, VisualForward),
            FVector::DotProduct(ImpactWorldNormal, VisualRight),
            0.0f).GetSafeNormal2D();
    }
    CurrentImpactWorldNormal = ImpactWorldNormal;
    CurrentImpactLocalNormal = ImpactLocalNormal;

    float MovementSide = 0.0f;
    if (FeelConfig.bPreferMovementHitSideForRoll && Movement)
    {
        const float Age = Movement->GetTimeSinceLastBlockingHit();
        const AActor* OtherActor = Movement->GetLastCollisionActor();
        const AActor* OwnerActor = GetOwner();
        if (Age >= 0.0f && Age <= 0.20f && OtherActor && Visual && OwnerActor)
        {
            const FVector ToOther = (OtherActor->GetActorLocation() - OwnerActor->GetActorLocation()).GetSafeNormal2D();
            if (!ToOther.IsNearlyZero())
            {
                MovementSide = FVector::DotProduct(ToOther, Visual->GetRightVector().GetSafeNormal2D());
            }
        }
    }
    CurrentImpactRollSideFromMovement = MovementSide;

    float ImpactRollInput = ImpactLocalNormal.Y;
    if (!FMath::IsNearlyZero(MovementSide, KINDA_SMALL_NUMBER))
    {
        ImpactRollInput = MovementSide;
    }
    if (FeelConfig.bImpactRollUseSideSignOnly && !FMath::IsNearlyZero(ImpactRollInput, KINDA_SMALL_NUMBER))
    {
        ImpactRollInput = FMath::Sign(ImpactRollInput);
    }
    CurrentImpactRollInput = ImpactRollInput;

    const FRotator ImpactRotationOffset(
        ImpactLocalNormal.X * FeelConfig.ImpactPulsePitchDirection * FeelConfig.ImpactPulseRotationKickDeg * CurrentImpactStrength,
        0.0f,
        ImpactRollInput * FeelConfig.ImpactPulseRollDirection * FeelConfig.ImpactPulseRotationKickDeg * CurrentImpactStrength);
    CurrentImpactPitchDeg = ImpactRotationOffset.Pitch;
    CurrentImpactRollDeg = ImpactRotationOffset.Roll;

    FVector ScaleTarget = FVector::OneVector;
    if (FeelConfig.bEnableAccelerationDeform)
    {
        const float AccelStretch = CurrentForwardAccelAlpha * FeelConfig.MaxAccelSquashStretch;
        const float SpeedStretch = CurrentSpeedStretchAlpha * FeelConfig.MaxSpeedStretch;
        const float LongitudinalStretch = AccelStretch + SpeedStretch;
        const float SideCompress = LongitudinalStretch * 0.45f;

        ScaleTarget.X += LongitudinalStretch;
        ScaleTarget.Y -= SideCompress;
        ScaleTarget.Z -= SideCompress;
    }

    if (FeelConfig.bEnableImpactPulse)
    {
        const float ImpactScale = FeelConfig.ImpactPulseScale * CurrentImpactStrength;
        ScaleTarget.X -= ImpactScale * 0.5f;
        ScaleTarget.Y += ImpactScale * 0.25f;
        ScaleTarget.Z += ImpactScale * 0.25f;
    }

    const float EngineUniformScaleDelta = CurrentEngineScaleWave * CurrentEngineScaleVariance;
    ScaleTarget *= (1.0f + EngineUniformScaleDelta);

    ScaleTarget.X = FMath::Max(0.5f, ScaleTarget.X);
    ScaleTarget.Y = FMath::Max(0.5f, ScaleTarget.Y);
    ScaleTarget.Z = FMath::Max(0.5f, ScaleTarget.Z);

    CurrentScaleMultiplier = FMath::VInterpTo(
        CurrentScaleMultiplier,
        ScaleTarget,
        DeltaTime,
        FeelConfig.ScaleInterpSpeed);

    CurrentLocationOffset = FMath::VInterpTo(
        CurrentLocationOffset,
        ImpactLocationOffset,
        DeltaTime,
        FeelConfig.OffsetInterpSpeed);

    const float LeanAtImpact = FMath::Clamp(FeelConfig.LeanMultiplierAtMaxImpact, 0.0f, 1.0f);
    const bool bImpactActive = CurrentImpactStrength > KINDA_SMALL_NUMBER || ImpactPulseStartTime >= 0.0f;
    const float LeanMultiplier = (FeelConfig.bOverrideLeanWhileImpactActive && bImpactActive)
        ? LeanAtImpact
        : FMath::Lerp(1.0f, LeanAtImpact, CurrentImpactStrength);
    CurrentComposedLeanRollDeg = CurrentLeanRollDeg * LeanMultiplier;

    FRotator RotationTarget = ImpactRotationOffset;
    RotationTarget.Roll += CurrentComposedLeanRollDeg;
    RotationTarget.Roll += CurrentImpactRollImpulseDeg;
    CurrentRotationOffset = FMath::RInterpTo(
        CurrentRotationOffset,
        RotationTarget,
        DeltaTime,
        FeelConfig.OffsetInterpSpeed);

    CurrentImpactRollImpulseDeg = FMath::FInterpTo(
        CurrentImpactRollImpulseDeg,
        0.0f,
        DeltaTime,
        FMath::Max(0.0f, FeelConfig.ImpactRollImpulseDecaySpeed));

    if (bStaggerActive && GetWorld())
    {
        const float Elapsed = GetWorld()->GetTimeSeconds() - StaggerStartTime;
        const float Duration = FMath::Max(0.01f, StaggerDuration);
        const float T = FMath::Clamp(Elapsed / Duration, 0.0f, 1.0f);
        if (T >= 1.0f)
        {
            bStaggerActive = false;
            CurrentStaggerYaw = 0.0f;
        }
        else
        {
            float Alpha = T;
            if (StaggerCurve.IsValid())
            {
                Alpha = StaggerCurve->GetFloatValue(T);
            }
            else
            {
                Alpha = FMath::InterpEaseInOut(0.0f, 1.0f, T, 2.0f);
            }

            const float TotalYaw = 360.0f * FMath::Max(0, StaggerSpins);
            CurrentStaggerYaw = StaggerDirection * TotalYaw * Alpha;
        }
    }

    RotationTarget = CurrentRotationOffset;
    RotationTarget.Yaw += CurrentStaggerYaw;
    CurrentRotationOffset = RotationTarget;

    Visual->SetRelativeLocation(BaseRelativeLocation + CurrentLocationOffset);
    Visual->SetRelativeRotation(BaseRelativeRotation + CurrentRotationOffset);
    Visual->SetRelativeScale3D(BaseRelativeScale * CurrentScaleMultiplier);
}

float UCaddyVehicleFeelComponent::EvaluateEngineCurveMultiplier(
    const UCurveFloat* Curve,
    const float SpeedAlpha,
    const float FallbackPeakMultiplier,
    const float FallbackCruiseMultiplier) const
{
    if (Curve)
    {
        return Curve->GetFloatValue(SpeedAlpha);
    }

    constexpr float PeakAlpha = 0.16f;
    if (SpeedAlpha <= PeakAlpha)
    {
        const float T = FMath::Clamp(SpeedAlpha / PeakAlpha, 0.0f, 1.0f);
        return FMath::InterpEaseInOut(1.0f, FallbackPeakMultiplier, T, 2.0f);
    }

    const float T = FMath::Clamp((SpeedAlpha - PeakAlpha) / (1.0f - PeakAlpha), 0.0f, 1.0f);
    return FMath::InterpEaseInOut(FallbackPeakMultiplier, FallbackCruiseMultiplier, T, 2.3f);
}

void UCaddyVehicleFeelComponent::ResolveRigReferences()
{
    if (IsFeelRigReady())
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

    if (!VisualComponent.IsValid())
    {
        TArray<USceneComponent*> SceneComponents;
        OwnerPawn->GetComponents(SceneComponents);
        for (USceneComponent* SceneComponent : SceneComponents)
        {
            if (!SceneComponent || SceneComponent == OwnerPawn->GetRootComponent())
            {
                continue;
            }

            if (SceneComponent->GetName().Contains(TEXT("VehicleMesh")))
            {
                VisualComponent = SceneComponent;
                break;
            }
        }
    }

    CacheVisualBaseTransform();
}

bool UCaddyVehicleFeelComponent::ShouldUpdateFeel() const
{
    const APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn)
    {
        return false;
    }

    return IsFeelRigReady();
}

void UCaddyVehicleFeelComponent::CacheVisualBaseTransform()
{
    USceneComponent* Visual = VisualComponent.Get();
    if (!Visual || bHasCachedVisualBaseTransform)
    {
        return;
    }

    BaseRelativeLocation = Visual->GetRelativeLocation();
    BaseRelativeRotation = Visual->GetRelativeRotation();
    BaseRelativeScale = Visual->GetRelativeScale3D();
    bHasCachedVisualBaseTransform = true;
}

void UCaddyVehicleFeelComponent::SnapToBaseTransform()
{
    if (!IsFeelRigReady())
    {
        return;
    }

    USceneComponent* Visual = VisualComponent.Get();
    if (!Visual)
    {
        return;
    }

    CurrentIdleStrength = 0.0f;
    EngineScaleOscillatorPhase = 0.0f;
    CurrentEngineScaleSpeedAlpha = 0.0f;
    CurrentEngineScaleVariance = 0.0f;
    CurrentEngineScaleFrequencyHz = 0.0f;
    CurrentEngineScaleWave = 0.0f;
    CurrentForwardAccelAlpha = 0.0f;
    CurrentSpeedStretchAlpha = 0.0f;
    CurrentLeanRollDeg = 0.0f;
    CurrentComposedLeanRollDeg = 0.0f;
    CurrentImpactPitchDeg = 0.0f;
    CurrentImpactRollDeg = 0.0f;
    CurrentImpactRollInput = 0.0f;
    CurrentImpactRollSideFromMovement = 0.0f;
    CurrentImpactRollImpulseDeg = 0.0f;
    CurrentImpactStrength = 0.0f;
    CurrentLocationOffset = FVector::ZeroVector;
    CurrentRotationOffset = FRotator::ZeroRotator;
    CurrentScaleMultiplier = FVector::OneVector;
    CurrentImpactWorldNormal = FVector::ZeroVector;
    CurrentImpactLocalNormal = FVector::ZeroVector;
    ImpactPulseStrength = 0.0f;
    ImpactPulseStartTime = -1.0f;
    HitStopEndTime = -1.0f;
    HitStopTimeDilation = 1.0f;
    bStaggerActive = false;
    StaggerStartTime = -1.0f;
    StaggerDuration = 0.0f;
    StaggerSpins = 0;
    StaggerDirection = 1.0f;
    CurrentStaggerYaw = 0.0f;
    StaggerCurve.Reset();
    LastObservedCollisionAge = -1.0f;
    bHasPreviousForwardSpeed = false;
    PreviousForwardSpeed = 0.0f;

    if (bHasCachedVisualBaseTransform)
    {
        Visual->SetRelativeLocation(BaseRelativeLocation);
        Visual->SetRelativeRotation(BaseRelativeRotation);
        Visual->SetRelativeScale3D(BaseRelativeScale);
    }
}

void UCaddyVehicleFeelComponent::TryTriggerImpactPulse(float DeltaTime)
{
    if (!FeelConfig.bEnableImpactPulse || !MovementComponent.IsValid())
    {
        LastObservedCollisionAge = -1.0f;
        return;
    }

    // Explicit collision-feel events from HitRegister should take priority.
    // Fallback exists only for cases where pipeline-driven feel is missing.
    const float LastFeelAge = GetLastCollisionFeelEventAgeSeconds();
    if (LastFeelAge >= 0.0f && LastFeelAge <= 0.20f)
    {
        return;
    }

    const UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    const float CollisionAge = Movement ? Movement->GetTimeSinceLastBlockingHit() : -1.0f;
    if (CollisionAge < 0.0f)
    {
        LastObservedCollisionAge = -1.0f;
        return;
    }

    const bool bNewHit = (LastObservedCollisionAge < 0.0f)
        || (CollisionAge + KINDA_SMALL_NUMBER < LastObservedCollisionAge)
        || (CollisionAge <= DeltaTime * 1.5f);
    LastObservedCollisionAge = CollisionAge;

    if (!bNewHit || !GetWorld())
    {
        return;
    }

    const float NormalImpactSpeed = Movement->GetLastCollisionNormalImpactSpeed();
    const float Strength = FMath::Clamp(
        NormalImpactSpeed / FMath::Max(1.0f, FeelConfig.ImpactNormalSpeedForMaxPulse),
        0.0f,
        1.0f);
    if (Strength <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    ImpactPulseStrength = FMath::Max(ImpactPulseStrength, Strength);
    ImpactPulseStartTime = GetWorld()->GetTimeSeconds();
    ImpactPulseNormal = Movement->GetLastCollisionNormal().GetSafeNormal2D();
}

void UCaddyVehicleFeelComponent::UpdateHitStop(float DeltaTime)
{
    (void)DeltaTime;
    if (HitStopEndTime < 0.0f || !GetWorld())
    {
        return;
    }

    if (GetWorld()->GetTimeSeconds() >= HitStopEndTime)
    {
        HitStopEndTime = -1.0f;
        HitStopTimeDilation = 1.0f;

        if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
        {
            OwnerPawn->CustomTimeDilation = 1.0f;
        }
    }
}

void UCaddyVehicleFeelComponent::TriggerCollisionFeel(
    const float NormalImpactSpeed,
    const ECaddyVehicleCollisionImpactTier ImpactTier,
    const FVector& ImpactNormal)
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    FVector ResolvedImpactNormal = ImpactNormal.GetSafeNormal2D();
    if (ResolvedImpactNormal.IsNearlyZero())
    {
        if (const APawn* OwnerPawn = Cast<APawn>(GetOwner()))
        {
            ResolvedImpactNormal = -OwnerPawn->GetActorForwardVector().GetSafeNormal2D();
        }
    }
    if (ResolvedImpactNormal.IsNearlyZero())
    {
        ResolvedImpactNormal = FVector::ForwardVector;
    }

    CollisionFeelEventCount++;
    LastCollisionFeelEventTime = World->GetTimeSeconds();
    LastCollisionFeelEventNormalWorld = ResolvedImpactNormal;

    if (!FeelConfig.CollisionFeel.bEnableCollisionFeel)
    {
        return;
    }

    const float MaxSpeed = FMath::Max(1.0f, FeelConfig.CollisionFeel.ImpactNormalSpeedForMaxStrength);
    float Strength = FMath::Clamp(NormalImpactSpeed / MaxSpeed, 0.0f, 1.0f);

    if (ImpactTier == ECaddyVehicleCollisionImpactTier::Heavy)
    {
        Strength = FMath::Max(Strength, 0.9f);
    }
    else if (ImpactTier == ECaddyVehicleCollisionImpactTier::Medium)
    {
        Strength = FMath::Max(Strength, 0.6f);
    }
    else if (ImpactTier == ECaddyVehicleCollisionImpactTier::Light)
    {
        Strength = FMath::Max(Strength, 0.35f);
    }

    if (Strength < FeelConfig.CollisionFeel.MinImpactStrength)
    {
        return;
    }

    {
        // Use the same side basis as runtime pulse roll so initial event impulse does not flip direction.
        FVector RollBasisRight = FVector::ZeroVector;
        if (const USceneComponent* Visual = VisualComponent.Get())
        {
            RollBasisRight = Visual->GetRightVector().GetSafeNormal2D();
        }
        if (RollBasisRight.IsNearlyZero())
        {
            if (const APawn* OwnerPawn = Cast<APawn>(GetOwner()))
            {
                RollBasisRight = OwnerPawn->GetActorRightVector().GetSafeNormal2D();
            }
        }

        float RollInput = !RollBasisRight.IsNearlyZero()
            ? FVector::DotProduct(ResolvedImpactNormal, RollBasisRight)
            : 0.0f;

        if (FeelConfig.bPreferMovementHitSideForRoll)
        {
            const UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
            const AActor* OwnerActor = GetOwner();
            if (Movement && OwnerActor)
            {
                const float Age = Movement->GetTimeSinceLastBlockingHit();
                const AActor* OtherActor = Movement->GetLastCollisionActor();
                if (Age >= 0.0f && Age <= 0.20f && OtherActor && !RollBasisRight.IsNearlyZero())
                {
                    const FVector ToOther = (OtherActor->GetActorLocation() - OwnerActor->GetActorLocation()).GetSafeNormal2D();
                    if (!ToOther.IsNearlyZero())
                    {
                        RollInput = FVector::DotProduct(ToOther, RollBasisRight);
                    }
                }
            }
        }

        if (FeelConfig.bImpactRollUseSideSignOnly && !FMath::IsNearlyZero(RollInput, KINDA_SMALL_NUMBER))
        {
            RollInput = FMath::Sign(RollInput);
        }
        if (!FMath::IsNearlyZero(RollInput, KINDA_SMALL_NUMBER))
        {
            const float EventImpulse = RollInput
                * FeelConfig.ImpactPulseRollDirection
                * FMath::Max(0.0f, FeelConfig.ImpactRollImpulseOnEventDeg)
                * Strength;
            CurrentImpactRollImpulseDeg += EventImpulse;
            const float MaxImpulseAbs = FMath::Max(0.0f, FeelConfig.ImpactRollImpulseOnEventDeg) * 2.0f;
            if (MaxImpulseAbs > KINDA_SMALL_NUMBER)
            {
                CurrentImpactRollImpulseDeg = FMath::Clamp(CurrentImpactRollImpulseDeg, -MaxImpulseAbs, MaxImpulseAbs);
            }
        }
    }

    if (FeelConfig.bEnableImpactPulse)
    {
        ImpactPulseNormal = ResolvedImpactNormal;
        ImpactPulseStrength = FMath::Max(ImpactPulseStrength, Strength);
        ImpactPulseStartTime = World->GetTimeSeconds();
    }

    const float HitStopDuration = FeelConfig.CollisionFeel.HitStopDuration * Strength;
    if (HitStopDuration > KINDA_SMALL_NUMBER)
    {
        HitStopEndTime = World->GetTimeSeconds() + HitStopDuration;
        HitStopTimeDilation = FMath::Lerp(1.0f, FeelConfig.CollisionFeel.HitStopTimeDilation, Strength);

        if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
        {
            OwnerPawn->CustomTimeDilation = HitStopTimeDilation;
        }
    }

    if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
    {
        if (OwnerPawn->IsLocallyControlled() && FeelConfig.CollisionFeel.CameraShakeClass)
        {
            if (APlayerController* PlayerController = OwnerPawn->GetController<APlayerController>())
            {
                if (PlayerController->PlayerCameraManager)
                {
                    const float ShakeScale = FeelConfig.CollisionFeel.CameraShakeScale * Strength;
                    PlayerController->PlayerCameraManager->StartCameraShake(FeelConfig.CollisionFeel.CameraShakeClass, ShakeScale);
                }
            }
        }
    }
}

float UCaddyVehicleFeelComponent::GetLastCollisionFeelEventAgeSeconds() const
{
    if (!GetWorld() || LastCollisionFeelEventTime < 0.0f)
    {
        return -1.0f;
    }
    return GetWorld()->GetTimeSeconds() - LastCollisionFeelEventTime;
}

void UCaddyVehicleFeelComponent::StartStagger(
    const float DurationSeconds,
    const int32 Spins,
    const float DirectionSign,
    UCurveFloat* OptionalCurve)
{
    if (DurationSeconds <= KINDA_SMALL_NUMBER || Spins <= 0)
    {
        return;
    }

    bStaggerActive = true;
    StaggerStartTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
    StaggerDuration = DurationSeconds;
    StaggerSpins = Spins;
    StaggerDirection = (DirectionSign >= 0.0f) ? 1.0f : -1.0f;
    if (OptionalCurve)
    {
        StaggerCurve = OptionalCurve;
    }
    else
    {
        StaggerCurve = FeelConfig.StaggerFeel.StaggerYawAlphaCurve;
    }
    CurrentStaggerYaw = 0.0f;
}

void UCaddyVehicleFeelComponent::StopStagger()
{
    bStaggerActive = false;
    StaggerStartTime = -1.0f;
    StaggerDuration = 0.0f;
    StaggerSpins = 0;
    StaggerDirection = 1.0f;
    StaggerCurve.Reset();
    CurrentStaggerYaw = 0.0f;
}

float UCaddyVehicleFeelComponent::GetStaggerTimeRemaining() const
{
    if (!bStaggerActive || !GetWorld())
    {
        return 0.0f;
    }

    const float Elapsed = GetWorld()->GetTimeSeconds() - StaggerStartTime;
    return FMath::Max(0.0f, StaggerDuration - Elapsed);
}

float UCaddyVehicleFeelComponent::GetHitStopTimeRemaining() const
{
    if (HitStopEndTime < 0.0f || !GetWorld())
    {
        return 0.0f;
    }

    return FMath::Max(0.0f, HitStopEndTime - GetWorld()->GetTimeSeconds());
}
