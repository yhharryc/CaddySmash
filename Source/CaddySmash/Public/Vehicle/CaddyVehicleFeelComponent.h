#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaddyVehicleFeelComponent.generated.h"

class UArcadeVehicleMovementComponent;
class UCurveFloat;
class USceneComponent;

USTRUCT(BlueprintType)
struct FCaddyVehicleEngineScaleVibrationConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ToolTip="Enable engine vibration represented only by mesh scale changes."))
    bool bEnableEngineScaleVibration = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Base scale variance around 1.0 when speed is near zero (engine already running)."))
    float BaseVariance = 0.018f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.01", ToolTip="Base oscillation frequency in Hz when speed is near zero."))
    float BaseFrequencyHz = 6.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="1.0", ToolTip="Speed in cm/s used to normalize curve input to [0,1]."))
    float SpeedForCurveNormalization = 1800.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ToolTip="Optional curve for variance multiplier by normalized speed (X: 0..1 speed alpha, Y: multiplier)."))
    TObjectPtr<UCurveFloat> VarianceBySpeedCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ToolTip="Optional curve for frequency multiplier by normalized speed (X: 0..1 speed alpha, Y: multiplier)."))
    TObjectPtr<UCurveFloat> FrequencyBySpeedCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Extra variance added by current throttle or brake input."))
    float ThrottleVarianceBoost = 0.010f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Extra frequency (Hz) added by current throttle or brake input."))
    float ThrottleFrequencyBoostHz = 1.6f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Interpolation speed for variance changes."))
    float VarianceInterpSpeed = 9.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Interpolation speed for frequency changes."))
    float FrequencyInterpSpeed = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.0", ToolTip="Upper clamp for final scale variance."))
    float MaxVariance = 0.08f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.01", ToolTip="Lower clamp for final vibration frequency in Hz."))
    float MinFrequencyHz = 2.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ClampMin="0.01", ToolTip="Upper clamp for final vibration frequency in Hz."))
    float MaxFrequencyHz = 15.0f;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleFeelConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel", meta=(ToolTip="Master switch for the runtime vehicle feel effects layer."))
    bool bEnableFeel = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|EngineScale", meta=(ToolTip="Engine scale vibration profile (non-linear with optional speed curves)."))
    FCaddyVehicleEngineScaleVibrationConfig EngineScaleVibration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ToolTip="Enables acceleration-driven squash/stretch deformation."))
    bool bEnableAccelerationDeform = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="1.0", ToolTip="Forward acceleration magnitude that maps to full deform strength, in cm/s^2."))
    float MaxForwardAccelForDeform = 9000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="0.0", ClampMax="0.5", ToolTip="Maximum acceleration-based squash/stretch scale delta."))
    float MaxAccelSquashStretch = 0.07f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="0.0", ClampMax="0.5", ToolTip="Maximum additional forward stretch based on current speed."))
    float MaxSpeedStretch = 0.03f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="1.0", ToolTip="Forward speed in cm/s that maps to full speed-based stretch."))
    float MaxSpeedForStretch = 2200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean", meta=(ToolTip="Enables lateral lean roll based on slip or cornering speed."))
    bool bEnableLateralLean = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean", meta=(ClampMin="1.0", ToolTip="Lateral speed in cm/s that maps to full lean roll."))
    float LateralSpeedForMaxLean = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean", meta=(ClampMin="0.0", ToolTip="Maximum roll angle for lateral lean, in degrees."))
    float MaxLateralLeanRollDeg = 7.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ToolTip="Enables one-shot impact pulse on recent blocking collisions."))
    bool bEnableImpactPulse = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.01", ToolTip="Duration of each impact pulse effect, in seconds."))
    float ImpactPulseDuration = 0.28f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="1.0", ToolTip="Normal impact speed in cm/s that maps to full impact pulse strength."))
    float ImpactNormalSpeedForMaxPulse = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ToolTip="Scale burst amount applied by impact pulse."))
    float ImpactPulseScale = 0.10f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ToolTip="Location kick distance in cm applied opposite to impact normal."))
    float ImpactPulseLocationKick = 7.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ToolTip="Rotational kick magnitude in degrees applied by impact pulse."))
    float ImpactPulseRotationKickDeg = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Smoothing", meta=(ClampMin="0.0", ToolTip="Interpolation speed for location or rotation feel offsets."))
    float OffsetInterpSpeed = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Smoothing", meta=(ClampMin="0.0", ToolTip="Interpolation speed for scale changes caused by feel effects."))
    float ScaleInterpSpeed = 10.0f;
};

UCLASS(ClassGroup=(Effects), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UCaddyVehicleFeelComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCaddyVehicleFeelComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel")
    FCaddyVehicleFeelConfig FeelConfig;

    UFUNCTION(BlueprintCallable, Category="Feel")
    void SetFeelConfig(const FCaddyVehicleFeelConfig& InConfig, bool bSnapToConfig = false);

    UFUNCTION(BlueprintCallable, Category="Feel")
    void BindFeelRig(UArcadeVehicleMovementComponent* InMovementComponent, USceneComponent* InVisualComponent);

    UFUNCTION(BlueprintPure, Category="Feel")
    bool IsFeelRigReady() const;

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentIdleStrength() const { return CurrentIdleStrength; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentEngineScaleSpeedAlpha() const { return CurrentEngineScaleSpeedAlpha; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentEngineScaleVariance() const { return CurrentEngineScaleVariance; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentEngineScaleFrequencyHz() const { return CurrentEngineScaleFrequencyHz; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentEngineScaleWave() const { return CurrentEngineScaleWave; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentForwardAccelAlpha() const { return CurrentForwardAccelAlpha; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentSpeedStretchAlpha() const { return CurrentSpeedStretchAlpha; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentLeanRollDeg() const { return CurrentLeanRollDeg; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactStrength() const { return CurrentImpactStrength; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentLocationOffset() const { return CurrentLocationOffset; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FRotator GetCurrentRotationOffset() const { return CurrentRotationOffset; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentScaleMultiplier() const { return CurrentScaleMultiplier; }

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    float EvaluateEngineCurveMultiplier(
        const UCurveFloat* Curve,
        float SpeedAlpha,
        float FallbackPeakMultiplier,
        float FallbackCruiseMultiplier) const;

    void ResolveRigReferences();
    bool ShouldUpdateFeel() const;
    void CacheVisualBaseTransform();
    void SnapToBaseTransform();
    void TryTriggerImpactPulse(float DeltaTime);

    TWeakObjectPtr<UArcadeVehicleMovementComponent> MovementComponent;
    TWeakObjectPtr<USceneComponent> VisualComponent;

    bool bHasCachedVisualBaseTransform = false;
    FVector BaseRelativeLocation = FVector::ZeroVector;
    FRotator BaseRelativeRotation = FRotator::ZeroRotator;
    FVector BaseRelativeScale = FVector::OneVector;

    bool bHasPreviousForwardSpeed = false;
    float PreviousForwardSpeed = 0.0f;
    float LastObservedCollisionAge = -1.0f;
    float ImpactPulseStartTime = -1.0f;
    float ImpactPulseStrength = 0.0f;
    FVector ImpactPulseNormal = FVector::ZeroVector;

    float CurrentIdleStrength = 0.0f;
    float EngineScaleOscillatorPhase = 0.0f;
    float CurrentEngineScaleSpeedAlpha = 0.0f;
    float CurrentEngineScaleVariance = 0.0f;
    float CurrentEngineScaleFrequencyHz = 0.0f;
    float CurrentEngineScaleWave = 0.0f;
    float CurrentForwardAccelAlpha = 0.0f;
    float CurrentSpeedStretchAlpha = 0.0f;
    float CurrentLeanRollDeg = 0.0f;
    float CurrentImpactStrength = 0.0f;
    FVector CurrentLocationOffset = FVector::ZeroVector;
    FRotator CurrentRotationOffset = FRotator::ZeroRotator;
    FVector CurrentScaleMultiplier = FVector::OneVector;
};
