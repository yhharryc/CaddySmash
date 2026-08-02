#include "Vehicle/HitRegister/Nodes/HRN_EmitVehicleCollisionGameplayEvents.h"

#include "Abilities/GameplayAbilityTargetTypes.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Actor.h"
#include "Vehicle/CaddyVehiclePawn.h"

namespace
{
    static float GetCollisionEventsAttrValue(const TMap<FGameplayTag, float>& Attributes, const FGameplayTag& Tag, const float DefaultValue = 0.0f)
    {
        if (!Tag.IsValid())
        {
            return DefaultValue;
        }

        if (const float* Value = Attributes.Find(Tag))
        {
            return *Value;
        }
        return DefaultValue;
    }

    static void EmitGameplayEventToTarget(const FGameplayTag EventTag, FHitRegisterContext& Context)
    {
        AActor* TargetActor = Context.Hit.GetActor();
        if (!TargetActor || !EventTag.IsValid())
        {
            return;
        }

        FGameplayEventData EventData;
        EventData.EventTag = EventTag;
        EventData.Instigator = Context.Attack.Instigator.Get();
        EventData.Target = TargetActor;
        EventData.OptionalObject = Context.Attack.SourceObject.Get();
        EventData.EventMagnitude = Context.Damage.FinalDamage;
        EventData.TargetTags.AppendTags(Context.Attack.Tags);

        if (Context.Hit.bBlockingHit)
        {
            EventData.TargetData.Add(new FGameplayAbilityTargetData_SingleTargetHit(Context.Hit));
        }

        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(TargetActor, EventTag, EventData);
    }
}

UHRN_EmitVehicleCollisionGameplayEvents::UHRN_EmitVehicleCollisionGameplayEvents()
{
    KnockbackGameplayEventTag = FGameplayTag::RequestGameplayTag(FName("Event.Collision.Knockback"), false);
    StaggerGameplayEventTag = FGameplayTag::RequestGameplayTag(FName("Event.Collision.Stagger"), false);

    ImpactTierTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.ImpactTier"), false);
    LightImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Light"), false);
    MediumImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Medium"), false);
    HeavyImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Heavy"), false);
}

EHitNodeResult UHRN_EmitVehicleCollisionGameplayEvents::Execute_Implementation(FHitRegisterContext& Context)
{
    AActor* TargetActor = Context.Hit.GetActor();
    if (!TargetActor)
    {
        return EHitNodeResult::Continue;
    }

    if (bEmitOnAuthorityOnly && !TargetActor->HasAuthority())
    {
        return EHitNodeResult::Continue;
    }

    if (bRequireVehiclePawnTarget && !Cast<ACaddyVehiclePawn>(TargetActor))
    {
        return EHitNodeResult::Continue;
    }

    if (bRequirePositiveFinalDamage && Context.Damage.FinalDamage <= FMath::Max(0.0f, MinFinalDamage))
    {
        return EHitNodeResult::Continue;
    }

    if (bEmitKnockbackGameplayEvent)
    {
        EmitGameplayEventToTarget(KnockbackGameplayEventTag, Context);
    }

    float ImpactTierValue = GetCollisionEventsAttrValue(Context.Attack.Attributes, ImpactTierTag, 0.0f);
    if (ImpactTierValue <= 0.0f)
    {
        if (HeavyImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(HeavyImpactTag))
        {
            ImpactTierValue = 3.0f;
        }
        else if (MediumImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(MediumImpactTag))
        {
            ImpactTierValue = 2.0f;
        }
        else if (LightImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(LightImpactTag))
        {
            ImpactTierValue = 1.0f;
        }
    }

    bool bAllowStagger = false;
    if (bStaggerOnHeavyImpact && ImpactTierValue >= 3.0f)
    {
        bAllowStagger = true;
    }
    else if (bStaggerOnMediumImpact && ImpactTierValue >= 2.0f)
    {
        bAllowStagger = true;
    }
    else if (bStaggerOnLightImpact && ImpactTierValue >= 1.0f)
    {
        bAllowStagger = true;
    }

    if (bEmitStaggerGameplayEvent && bAllowStagger)
    {
        EmitGameplayEventToTarget(StaggerGameplayEventTag, Context);
    }

    return EHitNodeResult::Continue;
}
