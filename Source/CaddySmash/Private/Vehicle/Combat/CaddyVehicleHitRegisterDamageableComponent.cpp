#include "Vehicle/Combat/CaddyVehicleHitRegisterDamageableComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Vehicle/Combat/CaddyVehicleDamageGameplayEffect.h"

UCaddyVehicleHitRegisterDamageableComponent::UCaddyVehicleHitRegisterDamageableComponent()
{
    DamageEffectClass = UCaddyVehicleDamageGameplayEffect::StaticClass();
    KnockbackGameplayEventTag = FGameplayTag::RequestGameplayTag(FName("Event.Collision.Knockback"), false);
}

bool UCaddyVehicleHitRegisterDamageableComponent::ApplyDamage_Implementation(FHitRegisterContext& Context)
{
    const bool bApplied = Super::ApplyDamage_Implementation(Context);
    if (bApplied && bEmitKnockbackGameplayEvent && Context.Damage.FinalDamage > KINDA_SMALL_NUMBER)
    {
        EmitKnockbackGameplayEvent(Context);
    }
    return bApplied;
}

void UCaddyVehicleHitRegisterDamageableComponent::EmitKnockbackGameplayEvent(const FHitRegisterContext& Context) const
{
    AActor* Owner = GetOwner();
    if (!Owner || !KnockbackGameplayEventTag.IsValid())
    {
        return;
    }

    FGameplayEventData EventData;
    EventData.EventTag = KnockbackGameplayEventTag;
    EventData.Instigator = Context.Attack.Instigator.Get();
    EventData.Target = Owner;
    EventData.OptionalObject = Context.Attack.SourceObject.Get();
    EventData.EventMagnitude = Context.Damage.FinalDamage;
    EventData.TargetTags.AppendTags(Context.Attack.Tags);

    if (Context.Hit.bBlockingHit)
    {
        EventData.TargetData.Add(new FGameplayAbilityTargetData_SingleTargetHit(Context.Hit));
    }

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Owner, KnockbackGameplayEventTag, EventData);
}

