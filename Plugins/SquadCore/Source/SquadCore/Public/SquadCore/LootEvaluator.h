#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SquadCore/SquadTypes.h"
#include "LootEvaluator.generated.h"

UCLASS(BlueprintType, Blueprintable)
class SQUADCORE_API ULootEvaluator : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TSubclassOf<AActor> LootClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float MaxRange = 800.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float DistanceWeight = 1.f;

    UFUNCTION(BlueprintNativeEvent, Category="Squad")
    void EvaluateLoot(AActor* Source, TArray<FLootCandidate>& OutLoot) const;
    virtual void EvaluateLoot_Implementation(AActor* Source, TArray<FLootCandidate>& OutLoot) const;
};
