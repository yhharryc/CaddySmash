#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AttackProfile.generated.h"

class UAttackRangeModel;

UCLASS(BlueprintType)
class COMBATCORE_API UAttackProfile : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    float IntentDuration = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    float CommitWindowStart = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    float CommitWindowEnd = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    float Cooldown = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    float Range = 200.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    TObjectPtr<UAttackRangeModel> RangeModel = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    FGameplayTag AttackType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<UDataAsset> HitConfig = nullptr;

    /**
     * Optional adapter-specific attack ability class.
     * Core does not depend on GAS; adapters interpret this type at runtime.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Adapter")
    TSubclassOf<UObject> AbilityClass;
};
