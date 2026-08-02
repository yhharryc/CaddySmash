#include "Vehicle/Combat/CaddyVehicleDamageGameplayEffect.h"

#include "Vehicle/Combat/CaddyVehicleAttributeSet.h"

UCaddyVehicleDamageGameplayEffect::UCaddyVehicleDamageGameplayEffect()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;
    Period = 0.0f;

    FGameplayModifierInfo& DamageModifier = Modifiers.AddDefaulted_GetRef();
    DamageModifier.Attribute = UCaddyVehicleAttributeSet::GetIncomingDamageAttribute();
    DamageModifier.ModifierOp = EGameplayModOp::Additive;

    FSetByCallerFloat SetByCaller;
    SetByCaller.DataTag = FGameplayTag::RequestGameplayTag(FName("Data.Damage"), false);
    if (!SetByCaller.DataTag.IsValid())
    {
        SetByCaller.DataName = FName("Data.Damage");
    }
    DamageModifier.ModifierMagnitude = FGameplayEffectModifierMagnitude(SetByCaller);
}

