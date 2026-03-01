#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "CaddyVehicleSkillComponent.generated.h"

class UArcadeVehicleMovementComponent;
class UCurveFloat;
class UHitRegisterTargetingProfile;
class AActor;
class UCaddyVehicleBrakeDashAbility;

UENUM(BlueprintType)
enum class ECaddyVehicleSkillState : uint8
{
    Ready,
    Braking,
    Charging,
    Dashing
};

UENUM(BlueprintType)
enum class ECaddyVehicleSkillTriggerMode : uint8
{
    InputActionHold,
    BrakeThrottleCombo
};

UENUM(BlueprintType)
enum class ECaddyVehicleSkillAimSelectionMode : uint8
{
    InputOnly,
    AbilityTargetOnly,
    AbilityTargetPreferInputFallback
};

USTRUCT(BlueprintType)
struct FCaddyVehicleSkillAbilityTargetingConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ToolTip="Enables ability-target based aim selection for skill charge/dash phases."))
    bool bEnableAbilityTargeting = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ToolTip="How aim direction is resolved between movement input and ability target."))
    ECaddyVehicleSkillAimSelectionMode AimSelectionMode = ECaddyVehicleSkillAimSelectionMode::AbilityTargetPreferInputFallback;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ClampMin="10.0", ToolTip="Ability target trace distance in cm."))
    float TraceDistance = 1800.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ClampMin="0.0", ToolTip="Sphere sweep radius used for ability target acquisition in cm."))
    float TraceRadius = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ToolTip="Collision channel used by ability target trace."))
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Pawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ToolTip="Optional targeting profile for filtering ability target candidates (teams/self/allies/enemies)."))
    TObjectPtr<UHitRegisterTargetingProfile> TargetingProfile = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting|Debug", meta=(ToolTip="Draw debug lines/sphere for ability target query and resolved target."))
    bool bEnableDebugDraw = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting|Debug", meta=(ClampMin="0.0", ToolTip="Debug shape persistence in seconds. 0 draws for one frame only."))
    float DebugPersistSeconds = 0.0f;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleBrakeDashSkillConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash", meta=(ToolTip="Master switch for brake-dash skill logic."))
    bool bEnableBrakeDashSkill = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash", meta=(ToolTip="Trigger source mode for entering the skill."))
    ECaddyVehicleSkillTriggerMode TriggerMode = ECaddyVehicleSkillTriggerMode::BrakeThrottleCombo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Combo", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Throttle threshold required when TriggerMode is BrakeThrottleCombo."))
    float TriggerThrottleThreshold = 0.85f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Combo", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Brake threshold required when TriggerMode is BrakeThrottleCombo."))
    float TriggerBrakeThreshold = 0.85f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash", meta=(ClampMin="0.0", ToolTip="Hold duration required before skill can enter braking phase, in seconds."))
    float TriggerInputHoldSeconds = 0.02f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash", meta=(ClampMin="0.0", ToolTip="Cooldown duration after dash completion, in seconds."))
    float CooldownSeconds = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Brake", meta=(ClampMin="0.01", ToolTip="Emergency brake duration, in seconds."))
    float BrakeDuration = 0.34f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Brake", meta=(ToolTip="Optional non-linear curve for braking speed alpha. X: normalized time [0..1], Y: speed alpha [1..0]."))
    TObjectPtr<UCurveFloat> BrakeSpeedAlphaCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ClampMin="0.01", ToolTip="Maximum charge duration. Holding longer will auto-release at max, in seconds."))
    float MaxChargeSeconds = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ClampMin="0.0", ToolTip="Minimum charge time required before release can trigger dash, in seconds."))
    float MinChargeSeconds = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ToolTip="Optional charge mapping curve. X: hold alpha [0..1], Y: output charge alpha [0..1]."))
    TObjectPtr<UCurveFloat> ChargeAlphaCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Minimum move-intent magnitude required to update aim direction while charging."))
    float AimInputDeadZone = 0.10f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Targeting", meta=(ToolTip="Ability-target based aim selection settings for skill charge/dash."))
    FCaddyVehicleSkillAbilityTargetingConfig AbilityTargeting;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ToolTip="Rotate vehicle toward aimed direction while braking and charging."))
    bool bRotateOwnerToAimDuringCharge = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Charge", meta=(ClampMin="0.0", ToolTip="Yaw rotation speed for aim steering, in deg/s."))
    float AimRotationRateDegPerSec = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ClampMin="0.01", ToolTip="Dash duration at zero charge, in seconds."))
    float DashDurationAtMinCharge = 0.22f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ClampMin="0.01", ToolTip="Dash duration at full charge, in seconds."))
    float DashDurationAtMaxCharge = 0.42f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ClampMin="0.0", ToolTip="Dash peak speed at zero charge, in cm/s."))
    float DashPeakSpeedAtMinCharge = 2600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ClampMin="0.0", ToolTip="Dash peak speed at full charge, in cm/s."))
    float DashPeakSpeedAtMaxCharge = 4200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ToolTip="Optional non-linear curve for dash speed alpha. X: normalized dash time [0..1], Y: speed alpha [1..0]."))
    TObjectPtr<UCurveFloat> DashSpeedAlphaCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill|BrakeDash|Dash", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Carry-over ratio of dash peak speed applied after dash exits."))
    float PostDashCarryRatio = 0.30f;
};

UCLASS(ClassGroup=(Vehicle), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UCaddyVehicleSkillComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCaddyVehicleSkillComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill", meta=(ToolTip="When enabled, skill state machine is driven by GAS ability instead of this component tick."))
    bool bUseGASAbilityStateMachine = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skill")
    FCaddyVehicleBrakeDashSkillConfig BrakeDashConfig;

    UFUNCTION(BlueprintCallable, Category="Skill")
    void SetSkillConfig(const FCaddyVehicleBrakeDashSkillConfig& InConfig, bool bSnapToReady = false);

    UFUNCTION(BlueprintCallable, Category="Skill")
    void BindSkillRig(UArcadeVehicleMovementComponent* InMovementComponent);

    UFUNCTION(BlueprintPure, Category="Skill")
    bool IsSkillRigReady() const;

    UFUNCTION(BlueprintCallable, Category="Skill|Input")
    void SetSkillInputPressed(bool bPressed);

    UFUNCTION(BlueprintPure, Category="Skill|Input")
    bool IsSkillInputPressed() const { return bSkillInputPressed; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    ECaddyVehicleSkillState GetSkillState() const { return SkillState; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetStateElapsedSeconds() const { return StateElapsedSeconds; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetCooldownRemainingSeconds() const { return CooldownRemainingSeconds; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetTriggerHoldSeconds() const { return TriggerHoldSeconds; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    bool IsSkillActive() const { return SkillState != ECaddyVehicleSkillState::Ready; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    bool CanTriggerSkillNow() const;

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    FVector2D GetCurrentAimDirection() const { return CurrentAimDirection; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    FVector2D GetDashDirection() const { return DashDirection; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetCurrentOverrideSpeed() const { return CurrentOverrideSpeed; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetCurrentChargeSeconds() const { return CurrentChargeSeconds; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetCurrentChargeAlpha() const { return CurrentChargeAlpha; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetActiveDashDuration() const { return ActiveDashDuration; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    float GetActiveDashPeakSpeed() const { return ActiveDashPeakSpeed; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    bool HasCurrentAbilityTarget() const { return CurrentAbilityTargetActor.IsValid(); }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    AActor* GetCurrentAbilityTargetActor() const { return CurrentAbilityTargetActor.Get(); }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    FVector GetCurrentAbilityTargetLocation() const { return CurrentAbilityTargetLocation; }

    UFUNCTION(BlueprintPure, Category="Skill|Telemetry")
    bool IsUsingAbilityTargetAim() const { return bUsingAbilityTargetAim; }

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    friend class UCaddyVehicleBrakeDashAbility;

    float EvaluateBrakeSpeedAlpha(float NormalizedTime) const;
    float EvaluateDashSpeedAlpha(float NormalizedTime) const;
    float EvaluateChargeAlpha(float ChargeSeconds) const;
    FVector2D ResolveFallbackAimDirection() const;
    FVector ResolveAbilityTargetTraceDirection() const;
    bool IsComboTriggerHeld() const;
    void ResolveRigReferences();
    bool ShouldUpdateSkill() const;
    bool TryResolveAbilityTargetAim(FVector2D& OutAimDirection);
    void UpdateAimDirection();
    void RotateOwnerTowardCurrentAim(float DeltaTime);
    void EnterBrakePhase();
    void EnterChargingPhase();
    void EnterDashPhase();
    void ExitDashPhase();
    void AbortToReady();
    void ApplyOverrideVelocity(const FVector& InWorldVelocity);
    void DrawAbilityTargetDebug(
        const FVector& TraceStart,
        const FVector& TraceEnd,
        bool bHadRawHit,
        bool bAcceptedTarget,
        const FVector& AcceptedTargetLocation) const;

    TWeakObjectPtr<UArcadeVehicleMovementComponent> MovementComponent;

    ECaddyVehicleSkillState SkillState = ECaddyVehicleSkillState::Ready;
    float StateElapsedSeconds = 0.0f;
    float CooldownRemainingSeconds = 0.0f;
    float TriggerHoldSeconds = 0.0f;
    bool bTriggerLatch = false;
    bool bSkillInputPressed = false;

    FVector2D CurrentAimDirection = FVector2D(1.0f, 0.0f);
    FVector2D DashDirection = FVector2D(1.0f, 0.0f);
    FVector BrakingVelocityDirection = FVector::ForwardVector;
    float BrakingStartSpeed = 0.0f;
    float CurrentOverrideSpeed = 0.0f;
    float CurrentChargeSeconds = 0.0f;
    float CurrentChargeAlpha = 0.0f;
    float ActiveDashDuration = 0.0f;
    float ActiveDashPeakSpeed = 0.0f;
    TWeakObjectPtr<AActor> CurrentAbilityTargetActor;
    FVector CurrentAbilityTargetLocation = FVector::ZeroVector;
    bool bUsingAbilityTargetAim = false;
};
