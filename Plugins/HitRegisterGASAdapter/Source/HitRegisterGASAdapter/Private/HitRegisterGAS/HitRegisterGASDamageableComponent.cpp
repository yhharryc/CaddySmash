#include "HitRegisterGAS/HitRegisterGASDamageableComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GameplayEffect.h"

#include "HitRegister/HitRegisterSettings.h"

UHitRegisterGASDamageableComponent::UHitRegisterGASDamageableComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    CritSetByCallerTag = FGameplayTag::RequestGameplayTag(FName("Gameplay.Damage.Flags.Crit"), false);
}

UAbilitySystemComponent* UHitRegisterGASDamageableComponent::ResolveASC() const
{
    AActor* Owner = GetOwner();
    if (!Owner) return nullptr;
    return UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner);
}

void UHitRegisterGASDamageableComponent::OnHitConfirmed_Implementation(const FHitRegisterContext& Context)
{
    OnHit.Broadcast(Context);
}

void UHitRegisterGASDamageableComponent::OnPostDamage_Implementation(const FHitRegisterContext& Context)
{
    OnPostDamageEvent.Broadcast(Context);
}

bool UHitRegisterGASDamageableComponent::ApplyDamage_Implementation(FHitRegisterContext& Context)
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return !bFailIfCannotApply;
    }

    if (bApplyOnAuthorityOnly && !Owner->HasAuthority())
    {
        // For replicated games, do damage on server.
        return true;
    }

    UAbilitySystemComponent* ASC = ResolveASC();
    if (!ASC)
    {
        return !bFailIfCannotApply;
    }

    if (!DamageEffectClass)
    {
        // Project must supply a GE that modifies the correct health attribute.
        return !bFailIfCannotApply;
    }

    // Choose tag: component override -> settings default
    FGameplayTag SBC_Tag = DamageSetByCallerTag;
    if (!SBC_Tag.IsValid())
    {
        if (const UHitRegisterSettings* Settings = UHitRegisterSettings::Get())
        {
            SBC_Tag = Settings->DamageSetByCallerTag;
        }
    }

    const float DamageToApply = FMath::Max(0.f, Context.Damage.FinalDamage);
    if (DamageToApply <= 0.f)
    {
        // Consider hit accepted but no damage.
        return true;
    }

    FGameplayEffectContextHandle GEContext = ASC->MakeEffectContext();
    if (Context.Attack.Instigator)
    {
        GEContext.AddInstigator(Context.Attack.Instigator.Get(), Context.Attack.Instigator.Get());
    }
    if (Context.Attack.SourceObject)
    {
        GEContext.AddSourceObject(Context.Attack.SourceObject.Get());
    }
    GEContext.AddHitResult(Context.Hit, true);

    const float Level = 1.f;
    FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(DamageEffectClass, Level, GEContext);
    if (!SpecHandle.IsValid())
    {
        return !bFailIfCannotApply;
    }

    if (SBC_Tag.IsValid())
    {
        SpecHandle.Data->SetSetByCallerMagnitude(SBC_Tag, DamageToApply);
    }

    FGameplayTag CritTag = CritSetByCallerTag;
    if (!CritTag.IsValid())
    {
        CritTag = FGameplayTag::RequestGameplayTag(FName("Gameplay.Damage.Flags.Crit"), false);
    }
    if (CritTag.IsValid() && (Context.Damage.bIsCrit || Context.Attack.Tags.HasTag(CritTag)))
    {
        // Store crit as a SetByCaller scalar so recipients can read it from EffectSpec.
        SpecHandle.Data->SetSetByCallerMagnitude(CritTag, 1.f);
    }

    ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

    // Best-effort fill result fields.
    Context.Result.AppliedToHealth += DamageToApply;

    OnDamaged.Broadcast(Context);
    return true;
}
