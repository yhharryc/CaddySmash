#pragma once

#include "CoreMinimal.h"
#include "Combat/AttackRangeModel.h"
#include "AttackRangeModelTemplates.generated.h"

UCLASS(BlueprintType)
class COMBATCORE_API UAttackRangeModel_MeleeThrust : public UAttackRangeModel
{
    GENERATED_BODY()

public:
    UAttackRangeModel_MeleeThrust(const FObjectInitializer& ObjectInitializer);
};

UCLASS(BlueprintType)
class COMBATCORE_API UAttackRangeModel_RangedHitscan : public UAttackRangeModel
{
    GENERATED_BODY()

public:
    UAttackRangeModel_RangedHitscan(const FObjectInitializer& ObjectInitializer);
};

