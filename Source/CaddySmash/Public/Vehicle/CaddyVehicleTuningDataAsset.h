#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "CaddyVehicleTuningDataAsset.generated.h"

UCLASS(BlueprintType)
class CADDYSMASH_API UCaddyVehicleTuningDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config")
    FCaddyVehicleGasConfig GasConfig;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config")
    FCaddyVehicleHandlingConfig HandlingConfig;
};
