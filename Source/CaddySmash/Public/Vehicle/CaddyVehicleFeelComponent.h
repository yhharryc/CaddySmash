#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaddyVehicleFeelComponent.generated.h"

class UArcadeVehicleMovementComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FCaddyVehicleFeelConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel")
    bool bEnableFeel = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle")
    bool bEnableIdleEngineShake = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle", meta=(ClampMin="0.0"))
    float IdleShakeMaxSpeed = 220.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle", meta=(ClampMin="0.0"))
    float IdleShakeLocationAmplitude = 2.4f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle", meta=(ClampMin="0.0"))
    float IdleShakeRotationAmplitudeDeg = 1.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle", meta=(ClampMin="0.0"))
    float IdleShakeFrequency = 9.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Idle", meta=(ClampMin="0.0"))
    float IdleInputBoost = 0.7f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform")
    bool bEnableAccelerationDeform = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="1.0"))
    float MaxForwardAccelForDeform = 9000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="0.0", ClampMax="0.5"))
    float MaxAccelSquashStretch = 0.07f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="0.0", ClampMax="0.5"))
    float MaxSpeedStretch = 0.03f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Deform", meta=(ClampMin="1.0"))
    float MaxSpeedForStretch = 2200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean")
    bool bEnableLateralLean = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean", meta=(ClampMin="1.0"))
    float LateralSpeedForMaxLean = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Lean", meta=(ClampMin="0.0"))
    float MaxLateralLeanRollDeg = 7.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact")
    bool bEnableImpactPulse = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.01"))
    float ImpactPulseDuration = 0.28f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="1.0"))
    float ImpactNormalSpeedForMaxPulse = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0"))
    float ImpactPulseScale = 0.10f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0"))
    float ImpactPulseLocationKick = 7.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Impact", meta=(ClampMin="0.0"))
    float ImpactPulseRotationKickDeg = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Smoothing", meta=(ClampMin="0.0"))
    float OffsetInterpSpeed = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feel|Smoothing", meta=(ClampMin="0.0"))
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
    float CurrentForwardAccelAlpha = 0.0f;
    float CurrentSpeedStretchAlpha = 0.0f;
    float CurrentLeanRollDeg = 0.0f;
    float CurrentImpactStrength = 0.0f;
    FVector CurrentLocationOffset = FVector::ZeroVector;
    FRotator CurrentRotationOffset = FRotator::ZeroRotator;
    FVector CurrentScaleMultiplier = FVector::OneVector;
};
