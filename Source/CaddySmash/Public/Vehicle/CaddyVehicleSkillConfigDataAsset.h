#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Vehicle/CaddyVehicleSkillComponent.h"
#include "CaddyVehicleSkillConfigDataAsset.generated.h"

class UGameplayAbility;

UCLASS(BlueprintType)
class CADDYSMASH_API UCaddyVehicleSkillConfigDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Skill", meta=(ToolTip="GAS ability class implementing this vehicle skill. If empty, built-in brake-dash ability will be used."))
    TSubclassOf<UGameplayAbility> SkillAbilityClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Skill", meta=(ToolTip="Brake-dash skill profile for this vehicle."))
    FCaddyVehicleBrakeDashSkillConfig BrakeDashConfig;
};
