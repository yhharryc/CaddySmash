#include "Vehicle/Combat/CaddyVehicleAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UCaddyVehicleAttributeSet::UCaddyVehicleAttributeSet()
{
    InitMaxHealth(100.0f);
    InitHealth(100.0f);
    InitIncomingDamage(0.0f);
    InitKnockbackResistance(0.0f);
}

void UCaddyVehicleAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetMaxHealthAttribute())
    {
        NewValue = FMath::Max(1.0f, NewValue);
    }
    else if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }
    else if (Attribute == GetIncomingDamageAttribute())
    {
        NewValue = FMath::Max(0.0f, NewValue);
    }
    else if (Attribute == GetKnockbackResistanceAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 0.95f);
    }
}

void UCaddyVehicleAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    if (Data.EvaluatedData.Attribute == GetIncomingDamageAttribute())
    {
        const float DamageToApply = FMath::Max(0.0f, GetIncomingDamage());
        SetIncomingDamage(0.0f);
        if (DamageToApply > 0.0f)
        {
            const float NewHealth = FMath::Clamp(GetHealth() - DamageToApply, 0.0f, GetMaxHealth());
            SetHealth(NewHealth);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
    }
    else if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
    {
        SetMaxHealth(FMath::Max(1.0f, GetMaxHealth()));
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
    }
    else if (Data.EvaluatedData.Attribute == GetKnockbackResistanceAttribute())
    {
        SetKnockbackResistance(FMath::Clamp(GetKnockbackResistance(), 0.0f, 0.95f));
    }
}

void UCaddyVehicleAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UCaddyVehicleAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCaddyVehicleAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCaddyVehicleAttributeSet, IncomingDamage, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UCaddyVehicleAttributeSet, KnockbackResistance, COND_None, REPNOTIFY_Always);
}

void UCaddyVehicleAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCaddyVehicleAttributeSet, Health, OldValue);
}

void UCaddyVehicleAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCaddyVehicleAttributeSet, MaxHealth, OldValue);
}

void UCaddyVehicleAttributeSet::OnRep_IncomingDamage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCaddyVehicleAttributeSet, IncomingDamage, OldValue);
}

void UCaddyVehicleAttributeSet::OnRep_KnockbackResistance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UCaddyVehicleAttributeSet, KnockbackResistance, OldValue);
}

