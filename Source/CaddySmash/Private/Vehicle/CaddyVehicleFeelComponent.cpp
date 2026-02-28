#include "Vehicle/CaddyVehicleFeelComponent.h"

#include "Components/SceneComponent.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/Pawn.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"

UCaddyVehicleFeelComponent::UCaddyVehicleFeelComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
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

    TryTriggerImpactPulse(DeltaTime);
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
    CurrentImpactStrength = FMath::FInterpTo(CurrentImpactStrength, ImpactPulseAlpha, DeltaTime, FeelConfig.OffsetInterpSpeed);

    const FVector ImpactLocationOffset = -ImpactPulseNormal.GetSafeNormal2D() * (FeelConfig.ImpactPulseLocationKick * CurrentImpactStrength);
    const FRotator ImpactRotationOffset(
        ImpactPulseNormal.X * FeelConfig.ImpactPulseRotationKickDeg * CurrentImpactStrength,
        0.0f,
        ImpactPulseNormal.Y * FeelConfig.ImpactPulseRotationKickDeg * CurrentImpactStrength);

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

    FRotator RotationTarget = ImpactRotationOffset;
    RotationTarget.Roll += CurrentLeanRollDeg;
    CurrentRotationOffset = FMath::RInterpTo(
        CurrentRotationOffset,
        RotationTarget,
        DeltaTime,
        FeelConfig.OffsetInterpSpeed);

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
    CurrentImpactStrength = 0.0f;
    CurrentLocationOffset = FVector::ZeroVector;
    CurrentRotationOffset = FRotator::ZeroRotator;
    CurrentScaleMultiplier = FVector::OneVector;
    ImpactPulseStrength = 0.0f;
    ImpactPulseStartTime = -1.0f;
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
