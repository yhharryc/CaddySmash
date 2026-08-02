#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaddyVehicleFeelComponent.generated.h"

class UArcadeVehicleMovementComponent;
class UCurveFloat;
class UCameraShakeBase;
class USceneComponent;
enum class ECaddyVehicleCollisionImpactTier : uint8;

USTRUCT(BlueprintType)
struct FCaddyVehicleStaggerFeelConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Stagger", meta=(ToolTip="Optional curve for stagger yaw alpha over time (X: 0..1, Y: 0..1)."))
    TObjectPtr<UCurveFloat> StaggerYawAlphaCurve = nullptr;
};

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
struct FCaddyVehicleCollisionFeelConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ToolTip="Enable collision-driven game feel (hit stop, camera shake)."))
    bool bEnableCollisionFeel = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ClampMin="0.0", ToolTip="Minimum impact strength required to trigger collision feel effects (0..1)."))
    float MinImpactStrength = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ClampMin="1.0", ToolTip="Normal impact speed in cm/s that maps to full collision feel strength."))
    float ImpactNormalSpeedForMaxStrength = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ClampMin="0.0", ToolTip="Base hit stop duration in seconds at full strength."))
    float HitStopDuration = 0.06f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Time dilation applied during hit stop at full strength."))
    float HitStopTimeDilation = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ToolTip="Camera shake class triggered on collision feel."))
    TSubclassOf<UCameraShakeBase> CameraShakeClass = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ClampMin="0.0", ToolTip="Base camera shake scale at full strength."))
    float CameraShakeScale = 1.0f;
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ToolTip="Use movement-local collision detection as fallback source for impact pulse when no collision feel event is received from pipeline."))
    bool bUseMovementCollisionImpactPulseFallback = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="-1.0", ClampMax="1.0", ToolTip="Sign and weight for pitch response from impact direction in vehicle local space."))
    float ImpactPulsePitchDirection = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="-1.0", ClampMax="1.0", ToolTip="Sign and weight for roll response from impact direction in vehicle local space. Use -1 to flip left/right tilt."))
    float ImpactPulseRollDirection = -1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ToolTip="When enabled, impact roll uses only lateral side sign (left/right) and ignores forward/backward component so roll direction is always obvious."))
    bool bImpactRollUseSideSignOnly = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ToolTip="Prefer side detection from the target vehicle's own latest movement collision partner (if fresh) for roll direction. Helps keep left/right roll consistent even if upstream event normals differ."))
    bool bPreferMovementHitSideForRoll = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ToolTip="When an impact pulse is active, force lean multiplier to LeanMultiplierAtMaxImpact instead of blending by strength. Prevents lean from masking hit direction."))
    bool bOverrideLeanWhileImpactActive = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ToolTip="Instant roll impulse (deg) injected at collision feel event at full strength. Guarantees immediate directional response."))
    float ImpactRollImpulseOnEventDeg = 6.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ToolTip="Decay speed for event roll impulse. Higher values settle faster."))
    float ImpactRollImpulseDecaySpeed = 12.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Multiplier applied to lateral lean at max impact strength. Lower values make impact roll dominate initial hit reaction."))
    float LeanMultiplierAtMaxImpact = 0.15f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Collision", meta=(ToolTip="Collision feel tuning (hit stop and camera shake)."))
    FCaddyVehicleCollisionFeelConfig CollisionFeel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Stagger", meta=(ToolTip="Stagger feel tuning (spin curve)."))
    FCaddyVehicleStaggerFeelConfig StaggerFeel;

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
    float GetCurrentComposedLeanRollDeg() const { return CurrentComposedLeanRollDeg; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactPitchDeg() const { return CurrentImpactPitchDeg; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactRollDeg() const { return CurrentImpactRollDeg; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactRollInput() const { return CurrentImpactRollInput; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactRollSideFromMovement() const { return CurrentImpactRollSideFromMovement; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactRollImpulseDeg() const { return CurrentImpactRollImpulseDeg; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetCurrentImpactStrength() const { return CurrentImpactStrength; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentLocationOffset() const { return CurrentLocationOffset; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FRotator GetCurrentRotationOffset() const { return CurrentRotationOffset; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentScaleMultiplier() const { return CurrentScaleMultiplier; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentImpactWorldNormal() const { return CurrentImpactWorldNormal; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetCurrentImpactLocalNormal() const { return CurrentImpactLocalNormal; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    int32 GetCollisionFeelEventCount() const { return CollisionFeelEventCount; }

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    float GetLastCollisionFeelEventAgeSeconds() const;

    UFUNCTION(BlueprintPure, Category="Feel|Telemetry")
    FVector GetLastCollisionFeelEventNormalWorld() const { return LastCollisionFeelEventNormalWorld; }

    UFUNCTION(BlueprintPure, Category="Feel|Stagger")
    bool IsStaggerActive() const { return bStaggerActive; }

    UFUNCTION(BlueprintPure, Category="Feel|Stagger")
    float GetCurrentStaggerYaw() const { return CurrentStaggerYaw; }

    UFUNCTION(BlueprintPure, Category="Feel|Stagger")
    float GetStaggerTimeRemaining() const;

    UFUNCTION(BlueprintPure, Category="Feel|Collision")
    float GetHitStopTimeRemaining() const;

    UFUNCTION(BlueprintPure, Category="Feel|Collision")
    float GetHitStopTimeDilation() const { return HitStopTimeDilation; }

    UFUNCTION(BlueprintCallable, Category="Feel|Collision")
    void TriggerCollisionFeel(float NormalImpactSpeed, ECaddyVehicleCollisionImpactTier ImpactTier, const FVector& ImpactNormal);

    UFUNCTION(BlueprintCallable, Category="Feel|Stagger")
    void StartStagger(float DurationSeconds, int32 Spins, float DirectionSign, UCurveFloat* OptionalCurve);

    UFUNCTION(BlueprintCallable, Category="Feel|Stagger")
    void StopStagger();

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
    void UpdateHitStop(float DeltaTime);

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
    float HitStopEndTime = -1.0f;
    float HitStopTimeDilation = 1.0f;

    bool bStaggerActive = false;
    float StaggerStartTime = -1.0f;
    float StaggerDuration = 0.0f;
    int32 StaggerSpins = 0;
    float StaggerDirection = 1.0f;
    float CurrentStaggerYaw = 0.0f;
    TWeakObjectPtr<UCurveFloat> StaggerCurve;

    float CurrentIdleStrength = 0.0f;
    float EngineScaleOscillatorPhase = 0.0f;
    float CurrentEngineScaleSpeedAlpha = 0.0f;
    float CurrentEngineScaleVariance = 0.0f;
    float CurrentEngineScaleFrequencyHz = 0.0f;
    float CurrentEngineScaleWave = 0.0f;
    float CurrentForwardAccelAlpha = 0.0f;
    float CurrentSpeedStretchAlpha = 0.0f;
    float CurrentLeanRollDeg = 0.0f;
    float CurrentComposedLeanRollDeg = 0.0f;
    float CurrentImpactPitchDeg = 0.0f;
    float CurrentImpactRollDeg = 0.0f;
    float CurrentImpactRollInput = 0.0f;
    float CurrentImpactRollSideFromMovement = 0.0f;
    float CurrentImpactRollImpulseDeg = 0.0f;
    float CurrentImpactStrength = 0.0f;
    FVector CurrentLocationOffset = FVector::ZeroVector;
    FRotator CurrentRotationOffset = FRotator::ZeroRotator;
    FVector CurrentScaleMultiplier = FVector::OneVector;
    FVector CurrentImpactWorldNormal = FVector::ZeroVector;
    FVector CurrentImpactLocalNormal = FVector::ZeroVector;
    int32 CollisionFeelEventCount = 0;
    float LastCollisionFeelEventTime = -1.0f;
    FVector LastCollisionFeelEventNormalWorld = FVector::ZeroVector;
};
