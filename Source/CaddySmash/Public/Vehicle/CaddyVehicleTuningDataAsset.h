#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/CaddyVehicleCameraComponent.h"
#include "Vehicle/CaddyVehicleFeelComponent.h"
#include "CaddyVehicleTuningDataAsset.generated.h"

class UHitRegisterPipeline;

UCLASS(BlueprintType)
class CADDYSMASH_API UCaddyVehicleTuningDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config", meta=(ToolTip="Gas and longitudinal speed profile for this vehicle preset."))
    FCaddyVehicleGasConfig GasConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config", meta=(ToolTip="Handling and drift behavior profile for this vehicle preset."))
    FCaddyVehicleHandlingConfig HandlingConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config", meta=(ToolTip="Collision response and collision-to-hit-event bridge settings."))
    FCaddyVehicleCollisionConfig CollisionConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Camera", meta=(ToolTip="Top-down camera behavior profile (speed effects, lag, look-ahead, roll)."))
    FCaddyVehicleCameraConfig CameraConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Feel", meta=(ToolTip="Visual game-feel profile (engine scale vibration, deform, lean, impact pulse)."))
    FCaddyVehicleFeelConfig FeelConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config|Collision|HitRegister", meta=(ToolTip="Optional explicit HitRegister pipeline used when publishing collision events for this preset."))
    TObjectPtr<UHitRegisterPipeline> CollisionHitRegisterPipeline = nullptr;
};
