#include "HitRegister/Nodes/HRN_BuildDamageFromAttributes.h"

UHRN_BuildDamageFromAttributes::UHRN_BuildDamageFromAttributes()
{
    // Reasonable defaults (projects can override):
    FlatBonusTag = FGameplayTag::RequestGameplayTag(FName("Attr.Damage.Flat"), false);
    PercentBonusTag = FGameplayTag::RequestGameplayTag(FName("Attr.Damage.Percent"), false);
    MultiplierTag = FGameplayTag::RequestGameplayTag(FName("Attr.Damage.Multiplier"), false);
}

static float GetAttrOrZero(const TMap<FGameplayTag, float>& Map, const FGameplayTag& Tag)
{
    if (!Tag.IsValid()) return 0.f;
    if (const float* Val = Map.Find(Tag))
    {
        return *Val;
    }
    return 0.f;
}

EHitNodeResult UHRN_BuildDamageFromAttributes::Execute_Implementation(FHitRegisterContext& Context)
{
    const float Base = Context.Attack.BaseDamage;
    const float Flat = GetAttrOrZero(Context.Attack.Attributes, FlatBonusTag);
    const float Pct  = GetAttrOrZero(Context.Attack.Attributes, PercentBonusTag);
    float Multiplier = 1.f;
    {
        const float M = GetAttrOrZero(Context.Attack.Attributes, MultiplierTag);
        if (MultiplierTag.IsValid() && M != 0.f)
        {
            Multiplier = M;
        }
    }

    const float Raw = (Base + Flat) * (1.f + Pct) * Multiplier;

    Context.Damage.RawDamage = Raw;
    Context.Damage.MitigatedDamage = Raw;
    Context.Damage.FinalDamage = Raw;

    return EHitNodeResult::Continue;
}
