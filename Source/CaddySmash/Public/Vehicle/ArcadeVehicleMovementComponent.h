#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PawnMovementComponent.h"
#include "ArcadeVehicleMovementComponent.generated.h"

USTRUCT(BlueprintType)
struct FCaddyVehicleGasConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Maximum forward speed in cm/s when fully accelerated."))
    float MaxForwardSpeed = 2200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Acceleration while throttle is pressed, in cm/s^2."))
    float ForwardAcceleration = 6200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Natural deceleration when no throttle or brake input is active, in cm/s^2."))
    float CoastDeceleration = 2600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Deceleration applied while brake/reverse is pressed during forward motion, in cm/s^2."))
    float BrakeDeceleration = 8200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Maximum reverse speed in cm/s."))
    float MaxReverseSpeed = 920.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gas", meta=(ClampMin="0.0", ToolTip="Acceleration while reversing, in cm/s^2."))
    float ReverseAcceleration = 3600.0f;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleHandlingConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ToolTip="Yaw steering turn speed in degrees per second."))
    float SteeringRateDegPerSec = 540.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ToolTip="Minimum planar speed required before steering starts affecting yaw, in cm/s."))
    float MinSpeedForSteering = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ToolTip="How quickly sideways velocity is damped toward zero during normal driving. Higher values increase grip."))
    float LateralFrictionInterpSpeed = 7.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ToolTip="Linear drag applied each tick to reduce overall planar speed."))
    float LinearDrag = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ToolTip="Speeds below this threshold are snapped to rest to avoid micro-sliding, in cm/s."))
    float StopSpeedThreshold = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Input magnitude threshold required to consider move intent valid."))
    float MoveIntentDeadZone = 0.12f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0", ToolTip="Sideways damping while drifting. Lower values keep more slide and create longer drifts."))
    float DriftLateralFrictionInterpSpeed = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="1.0", ToolTip="Multiplier applied to steering rate while drift is active."))
    float DriftSteeringRateMultiplier = 1.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handling|Drift", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Minimum drift input value needed to enter/maintain drift state."))
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Enables publishing collision-derived hit events to HitRegister."))
    bool bEnableCollisionHitRegister = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0", ToolTip="Minimum vehicle speed required to emit a collision hit event, in cm/s."))
    float MinSpeedForEvent = 550.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0", ToolTip="Minimum normal impact speed (toward the surface) required to emit an event, in cm/s."))
    float MinNormalImpactSpeedForEvent = 180.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0", ToolTip="Minimum time between collision hit events, in seconds."))
    float EventCooldownSeconds = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0", ToolTip="Damage coefficient multiplied by normal impact speed to produce base damage."))
    float BaseDamageByNormalImpactSpeed = 0.012f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ClampMin="0.0", ToolTip="Flat damage added on top of the impact-speed scaled damage."))
    float BaseDamageBias = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Always-applied gameplay tags attached to emitted collision hit events."))
    FGameplayTagContainer BaseTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Tag appended when the collision target is world static geometry."))
    FGameplayTag WorldStaticTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Tag appended when the collision target is world dynamic geometry."))
    FGameplayTag WorldDynamicTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Tag appended when the collision target is a pawn."))
    FGameplayTag PawnTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Tag appended when the vehicle is drifting at impact time."))
    FGameplayTag DriftingTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Optional attribute tag receiving the vehicle total speed value on event publish."))
    FGameplayTag SpeedAttributeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Optional attribute tag receiving the normal impact speed value on event publish."))
    FGameplayTag NormalImpactSpeedAttributeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="Optional attribute tag receiving drifting state (0 or 1) on event publish."))
    FGameplayTag DriftingAttributeTag;
};

USTRUCT(BlueprintType)
struct FCaddyVehicleCollisionConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(ToolTip="Selects how blocking hits reshape vehicle velocity."))
    ECaddyVehicleCollisionResponseMode ResponseMode = ECaddyVehicleCollisionResponseMode::ArcadeWallGlide;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="Ratio of speed preserved after a blocking collision."))
    float SpeedRetainRatio = 0.62f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision", meta=(ClampMin="1", ClampMax="4", ToolTip="Maximum sweep-resolve iterations per movement tick for corner stability."))
    int32 MaxCollisionIterations = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ToolTip="How quickly post-impact velocity converges toward wall-glide tangent velocity."))
    float WallGlideVelocityInterpSpeed = 14.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ClampMax="1.0", ToolTip="How much move intent can steer glide direction along the wall tangent."))
    float WallGlideInputAssist = 0.45f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ToolTip="Minimum normal impact speed required to apply stronger arcade glide behavior."))
    float MinNormalImpactSpeedForGlide = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ToolTip="Minimum glide speed preserved during stronger impacts, in cm/s."))
    float MinWallGlideSpeed = 260.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ToolTip="Head-on impact fallback scale converting impact speed into tangent glide speed."))
    float HeadOnGlideSpeedScale = 0.50f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Arcade", meta=(ClampMin="0.0", ToolTip="Small separation push along hit normal to reduce sticky wall contact, in cm."))
    float PushOutDistance = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|Debug", meta=(ClampMin="0.0", ToolTip="How long collision debug lines remain visible, in seconds."))
    float DebugPersistSeconds = 0.9f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision|HitRegister", meta=(ToolTip="HitRegister publishing configuration for collision-driven events."))
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
