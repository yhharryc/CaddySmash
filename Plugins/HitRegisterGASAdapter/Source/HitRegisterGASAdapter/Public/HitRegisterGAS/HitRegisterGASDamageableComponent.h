#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterInterfaces.h"
#include "HitRegisterGASDamageableComponent.generated.h"

class UGameplayEffect;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHitRegisterContextEvent, const FHitRegisterContext&, Context);

/**
 * GAS adapter: attach to any actor with an AbilitySystemComponent to make it damageable by HitRegisterCore.
 * It applies an Instant GameplayEffect (configured per-project) with a set-by-caller magnitude.
 */
UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class HITREGISTERGASADAPTER_API UHitRegisterGASDamageableComponent : public UActorComponent, public IDamageApplier, public IHitReceiver
{
    GENERATED_BODY()

public:
    UHitRegisterGASDamageableComponent();

    /** GE to apply to self. Should have an Instant modifier to your Health attribute using SetByCaller. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|GAS")
    TSubclassOf<UGameplayEffect> DamageEffectClass;

    /** SetByCaller tag (defaults from HitRegisterSettings if unset). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|GAS")
    FGameplayTag DamageSetByCallerTag;

    /** Optional SetByCaller tag used to carry crit flag to downstream damage events. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|GAS")
    FGameplayTag CritSetByCallerTag;

    /** Apply only on authority by default. If you use prediction, you may enable this. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|GAS")
    bool bApplyOnAuthorityOnly = true;

    /** If true, ApplyDamage returns false when it cannot find ASC or DamageEffectClass is missing. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|GAS")
    bool bFailIfCannotApply = true;

    /** Fired when hit is confirmed (even if damage ends up 0). */
    UPROPERTY(BlueprintAssignable, Category="HitRegister|Events")
    FHitRegisterContextEvent OnHit;

    /** Fired after damage effect is applied (only if damage > 0). */
    UPROPERTY(BlueprintAssignable, Category="HitRegister|Events")
    FHitRegisterContextEvent OnDamaged;

    /** Fired after pipeline post-damage hook. */
    UPROPERTY(BlueprintAssignable, Category="HitRegister|Events")
    FHitRegisterContextEvent OnPostDamageEvent;

    // --- IDamageApplier ---
    virtual bool ApplyDamage_Implementation(FHitRegisterContext& Context) override;

    // --- IHitReceiver ---
    virtual bool ShouldAcceptHit_Implementation(FHitRegisterContext& Context) override { return true; }
    virtual void OnHitConfirmed_Implementation(const FHitRegisterContext& Context) override;
    virtual void OnPostDamage_Implementation(const FHitRegisterContext& Context) override;

private:
    class UAbilitySystemComponent* ResolveASC() const;
};
