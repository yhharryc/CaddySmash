#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaddyVehicleCameraComponent.generated.h"

class UArcadeVehicleMovementComponent;
class UCameraComponent;
class USpringArmComponent;

USTRUCT(BlueprintType)
struct FCaddyVehicleCameraConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    bool bEnableDynamicCamera = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(ClampMin="200.0"))
    float BaseArmLength = 1400.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(ClampMin="-89.0", ClampMax="0.0"))
    float BasePitchDeg = -72.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(ClampMin="30.0", ClampMax="170.0"))
    float BaseFOV = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    FVector BaseWorldTargetOffset = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Speed", meta=(ClampMin="1.0"))
    float MaxSpeedForEffects = 2200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Speed")
    float MaxSpeedPitchOffsetDeg = 6.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Speed")
    float MaxSpeedArmLengthOffset = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Speed")
    float MaxSpeedFOVOffset = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|LookAhead", meta=(ClampMin="0.0"))
    float LookAheadDistance = 180.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|LookAhead", meta=(ClampMin="0.0"))
    float LookAheadInterpSpeed = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Roll", meta=(ClampMin="0.0"))
    float MaxLateralRollDeg = 7.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Roll", meta=(ClampMin="1.0"))
    float LateralSpeedForMaxRoll = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Roll", meta=(ClampMin="0.0"))
    float RollInterpSpeed = 6.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag")
    bool bEnableCameraLag = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag", meta=(ClampMin="0.0"))
    float CameraLagSpeedAtLowSpeed = 12.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag", meta=(ClampMin="0.0"))
    float CameraLagSpeedAtHighSpeed = 7.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag", meta=(ClampMin="0.0"))
    float CameraLagMaxDistance = 340.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag")
    bool bEnableCameraRotationLag = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Lag", meta=(ClampMin="0.0"))
    float CameraRotationLagSpeed = 12.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Smoothing", meta=(ClampMin="0.0"))
    float TransformInterpSpeed = 4.0f;
};

UCLASS(ClassGroup=(Camera), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UCaddyVehicleCameraComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCaddyVehicleCameraComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    FCaddyVehicleCameraConfig CameraConfig;

    UFUNCTION(BlueprintCallable, Category="Camera")
    void SetCameraConfig(const FCaddyVehicleCameraConfig& InConfig, bool bSnapToConfig = false);

    UFUNCTION(BlueprintCallable, Category="Camera")
    void BindCameraRig(
        UArcadeVehicleMovementComponent* InMovementComponent,
        USpringArmComponent* InSpringArmComponent,
        UCameraComponent* InCameraComponent);

    UFUNCTION(BlueprintPure, Category="Camera")
    bool IsCameraRigReady() const;

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentSpeedAlpha() const { return CurrentSpeedAlpha; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentArmLength() const { return CurrentArmLength; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentPitchDeg() const { return CurrentPitchDeg; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentFOV() const { return CurrentFOV; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentRollDeg() const { return CurrentRollDeg; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    float GetCurrentCameraLagSpeed() const { return CurrentCameraLagSpeed; }

    UFUNCTION(BlueprintPure, Category="Camera|Telemetry")
    FVector GetCurrentWorldTargetOffset() const { return CurrentWorldTargetOffset; }

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void ResolveRigReferences();
    void CacheCameraBaseTransform();
    bool ShouldUpdateCamera() const;
    void ApplyLagSettings(float SpeedAlpha) const;
    void SnapToCurrentConfig();

    TWeakObjectPtr<UArcadeVehicleMovementComponent> MovementComponent;
    TWeakObjectPtr<USpringArmComponent> SpringArmComponent;
    TWeakObjectPtr<UCameraComponent> CameraComponent;

    bool bHasCachedBaseCameraTransform = false;
    FVector BaseCameraRelativeLocation = FVector::ZeroVector;
    FRotator BaseCameraRelativeRotation = FRotator::ZeroRotator;

    float CurrentSpeedAlpha = 0.0f;
    float CurrentArmLength = 0.0f;
    float CurrentPitchDeg = 0.0f;
    float CurrentFOV = 0.0f;
    float CurrentRollDeg = 0.0f;
    float CurrentCameraLagSpeed = 0.0f;
    FVector CurrentWorldTargetOffset = FVector::ZeroVector;
};
