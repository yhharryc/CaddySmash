#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HitRegisterNode.h"
#include "HitRegisterPipeline.generated.h"

/**
 * Data-driven hit registration pipeline. Nodes are instanced so each asset can hold per-node tuning.
 */
UCLASS(BlueprintType)
class HITREGISTERCORE_API UHitRegisterPipeline : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="HitRegister")
    TArray<TObjectPtr<UHitRegisterNode>> Nodes;
};
