#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "ArcadeVehicleMovementComponent.generated.h"

USTRUCT(BlueprintType)
struct FCaddyVehicleGasConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float MaxForwardSpeed = 2200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float ForwardAcceleration = 6200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float CoastDeceleration = 2600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float BrakeDeceleration = 8200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float MaxReverseSpeed = 920.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0"))
    float ReverseAcceleration = 3600.0f;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleHandlingConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0"))
    float SteeringRateDegPerSec = 540.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0"))
    float MinSpeedForSteering = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0"))
    float LateralFrictionInterpSpeed = 7.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0"))
    float LinearDrag = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0"))
    float StopSpeedThreshold = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ClampMax="1.0"))
    float CollisionSpeedRetainRatio = 0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ClampMax="1.0"))
    float MoveIntentDeadZone = 0.12f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0"))
    float DriftLateralFrictionInterpSpeed = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="1.0"))
    float DriftSteeringRateMultiplier = 1.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0", ClampMax="1.0"))
    float DriftInputThreshold = 0.15f;
};

class UCaddyVehicleTuningDataAsset;

UCLASS(ClassGroup=(Movement), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UArcadeVehicleMovementComponent : public UPawnMovementComponent
{
    GENERATED_BODY()

public:
    UArcadeVehicleMovementComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Config")
    FCaddyVehicleGasConfig GasConfig;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Config")
    FCaddyVehicleHandlingConfig HandlingConfig;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Config")
    TObjectPtr<UCaddyVehicleTuningDataAsset> TuningDataAsset = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug")
    bool bEnableDebugDraw = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug", meta=(ClampMin="50.0"))
    float DebugDirectionLineLength = 280.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug", meta=(ClampMin="0.01"))
    float DebugVelocityLineScale = 0.08f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug", meta=(ClampMin="0.0"))
    float DebugDrawZOffset = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug", meta=(ClampMin="0.0"))
    float DebugLineThickness = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug")
    bool bDebugDrawOnlyForLocalPawn = true;

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetMoveIntent(const FVector2D& InWorldDirection);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetThrottleInput(float InThrottle);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetBrakeReverseInput(float InBrakeReverse);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetDriftInput(float InDrift);

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    FVector2D GetMoveIntent() const { return MoveIntentWorldDir; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    float GetThrottleInput() const { return ThrottleInput; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    float GetBrakeReverseInput() const { return BrakeReverseInput; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    float GetDriftInput() const { return DriftInput; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    bool IsDrifting() const { return bIsDrifting; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    bool HasMoveIntent() const { return bHasMoveIntent; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Config")
    UCaddyVehicleTuningDataAsset* GetTuningDataAsset() const { return TuningDataAsset; }

    UFUNCTION(BlueprintCallable, Category="Vehicle|Config")
    void SetTuningDataAsset(UCaddyVehicleTuningDataAsset* InTuningDataAsset, bool bApplyImmediately = true);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Config")
    void ApplyTuningFromDataAsset();

    UFUNCTION(BlueprintPure, Category="Vehicle|Telemetry")
    FVector2D GetLocalPlanarVelocity() const;

    UFUNCTION(BlueprintPure, Category="Vehicle|Telemetry")
    float GetForwardSpeed() const { return GetLocalPlanarVelocity().X; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Telemetry")
    float GetLateralSpeed() const { return GetLocalPlanarVelocity().Y; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Telemetry")
    float GetTargetYawFromMoveIntent() const;

    virtual float GetMaxSpeed() const override;
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    FVector2D MoveIntentWorldDir = FVector2D::ZeroVector;
    float ThrottleInput = 0.0f;
    float BrakeReverseInput = 0.0f;
    float DriftInput = 0.0f;
    bool bHasMoveIntent = false;
    bool bIsDrifting = false;

    void UpdateSteering(float DeltaTime, float PlanarSpeedSqr);
    void UpdateVelocity(float DeltaTime);
    void PerformMovement(float DeltaTime);
    void DrawDebugVisuals() const;
};
