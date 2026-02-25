#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
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
    float MoveIntentDeadZone = 0.12f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0"))
    float DriftLateralFrictionInterpSpeed = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="1.0"))
    float DriftSteeringRateMultiplier = 1.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0", ClampMax="1.0"))
    float DriftInputThreshold = 0.15f;
};

UENUM(BlueprintType)
enum class ECaddyVehicleCollisionResponseMode : uint8
{
    SlideOnly,
    ArcadeWallGlide
};

USTRUCT(BlueprintType)
struct FCaddyVehicleCollisionHitRegisterConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    bool bEnableCollisionHitRegister = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0"))
    float MinSpeedForEvent = 550.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0"))
    float MinNormalImpactSpeedForEvent = 180.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0"))
    float EventCooldownSeconds = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0"))
    float BaseDamageByNormalImpactSpeed = 0.012f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0"))
    float BaseDamageBias = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTagContainer BaseTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag WorldStaticTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag WorldDynamicTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag PawnTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag DriftingTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag SpeedAttributeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag NormalImpactSpeedAttributeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FGameplayTag DriftingAttributeTag;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleCollisionConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
    ECaddyVehicleCollisionResponseMode ResponseMode = ECaddyVehicleCollisionResponseMode::ArcadeWallGlide;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(ClampMin="0.0", ClampMax="1.0"))
    float SpeedRetainRatio = 0.62f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(ClampMin="1", ClampMax="4"))
    int32 MaxCollisionIterations = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0"))
    float WallGlideVelocityInterpSpeed = 14.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ClampMax="1.0"))
    float WallGlideInputAssist = 0.45f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0"))
    float MinNormalImpactSpeedForGlide = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0"))
    float MinWallGlideSpeed = 260.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0"))
    float HeadOnGlideSpeedScale = 0.50f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0"))
    float PushOutDistance = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Debug", meta=(ClampMin="0.0"))
    float DebugPersistSeconds = 0.9f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister")
    FCaddyVehicleCollisionHitRegisterConfig HitRegister;
};

class UCaddyVehicleTuningDataAsset;
class UHitRegisterPipeline;

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
    FCaddyVehicleCollisionConfig CollisionConfig;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Config")
    TObjectPtr<UCaddyVehicleTuningDataAsset> TuningDataAsset = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Config|Collision|HitRegister")
    TObjectPtr<UHitRegisterPipeline> CollisionHitRegisterPipeline = nullptr;

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

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    float GetTimeSinceLastBlockingHit() const;

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    bool DidLastCollisionTriggerHitRegister() const { return bLastCollisionTriggeredHitRegister; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    bool DidLastCollisionHitRegisterSucceed() const { return bLastCollisionHitRegisterSucceeded; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    float GetLastCollisionSpeed() const { return LastBlockingHitSpeed; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    float GetLastCollisionNormalImpactSpeed() const { return LastBlockingHitNormalSpeed; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    FVector GetLastCollisionLocation() const { return LastBlockingHitLocation; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    FVector GetLastCollisionNormal() const { return LastBlockingHitNormal; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    FVector GetLastCollisionTangent() const { return LastBlockingHitTangent; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    FString GetLastCollisionHitRegisterStatus() const { return LastCollisionHitRegisterStatus; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Collision")
    FString GetLastCollisionActorName() const;

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
    void HandleBlockingCollision(
        const FVector& PreImpactVelocity,
        const FHitResult& Hit,
        const FVector& AttemptedDelta,
        float DeltaTime);
    FVector ComputeArcadeWallGlideVelocity(
        const FVector& PreImpactVelocity,
        const FHitResult& Hit,
        float DeltaTime,
        float& OutNormalImpactSpeed,
        FVector& OutTangentDirection) const;
    void TryEmitCollisionHitRegisterEvent(const FHitResult& Hit, float TotalSpeed, float NormalImpactSpeed);
    void CacheCollisionTelemetry(
        const FHitResult& Hit,
        float TotalSpeed,
        float NormalImpactSpeed,
        const FVector& TangentDirection);
    void DrawDebugVisuals() const;

    float LastBlockingHitWorldTime = -1.0f;
    float LastCollisionHitRegisterWorldTime = -1.0f;
    float LastBlockingHitSpeed = 0.0f;
    float LastBlockingHitNormalSpeed = 0.0f;
    FVector LastBlockingHitLocation = FVector::ZeroVector;
    FVector LastBlockingHitNormal = FVector::ZeroVector;
    FVector LastBlockingHitTangent = FVector::ZeroVector;
    TWeakObjectPtr<AActor> LastBlockingHitActor;
    bool bLastCollisionTriggeredHitRegister = false;
    bool bLastCollisionHitRegisterSucceeded = false;
    FString LastCollisionHitRegisterStatus = TEXT("n/a");
};
