#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Combat/AttackTypes.h"
#include "AttackRangeModel.generated.h"

class UCurveFloat;

UCLASS(BlueprintType, Blueprintable)
class COMBATCORE_API UAttackRangeModel : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    bool bAffectThrustDistance = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    bool bAffectHitscanRange = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float RangeInputMin = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float RangeInputMax = 700.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float MinThrustDistance = 30.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float MaxThrustDistance = 140.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float DistanceCompensationBias = 0.65f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float StaticReach = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float HitSlack = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    float HitscanRangeScale = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    bool bUseDistanceCompensation = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat|Range")
    TObjectPtr<UCurveFloat> RangeToDistanceCurve = nullptr;

    UFUNCTION(BlueprintNativeEvent, Category="Combat|Range")
    void BuildExecutionParams(const FCombatAttackContext& Context, float DistanceToTarget, FCombatAttackExecutionParams& InOutParams) const;
    virtual void BuildExecutionParams_Implementation(const FCombatAttackContext& Context, float DistanceToTarget, FCombatAttackExecutionParams& InOutParams) const;
};

