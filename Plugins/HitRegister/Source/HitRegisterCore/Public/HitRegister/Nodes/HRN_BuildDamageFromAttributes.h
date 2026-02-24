#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_BuildDamageFromAttributes.generated.h"

/**
 * Simple damage builder: RawDamage = BaseDamage + FlatBonus ; then * (1+PercentBonus).
 * All bonuses are read from Attack.Attributes using the configured tags.
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class HITREGISTERCORE_API UHRN_BuildDamageFromAttributes : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    /** Added directly to base damage. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Damage")
    FGameplayTag FlatBonusTag;

    /** Percentage bonus, expected 0.2 for +20%. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Damage")
    FGameplayTag PercentBonusTag;

    /** Optional multiplier applied at end, expected 1.5 for +50%. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Damage")
    FGameplayTag MultiplierTag;

    UHRN_BuildDamageFromAttributes();

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};
