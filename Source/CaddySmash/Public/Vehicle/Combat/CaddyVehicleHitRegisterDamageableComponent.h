#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegisterGAS/HitRegisterGASDamageableComponent.h"
#include "CaddyVehicleHitRegisterDamageableComponent.generated.h"

/**
 * Vehicle-specific HitRegister GAS adapter.
 * Applies damage via GAS and emits gameplay event for knockback ability routing.
 */
UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UCaddyVehicleHitRegisterDamageableComponent : public UHitRegisterGASDamageableComponent
{
    GENERATED_BODY()

public:
    UCaddyVehicleHitRegisterDamageableComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|Knockback")
    bool bEmitKnockbackGameplayEvent = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister|Knockback", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag KnockbackGameplayEventTag;

    virtual bool ApplyDamage_Implementation(FHitRegisterContext& Context) override;

private:
    void EmitKnockbackGameplayEvent(const FHitRegisterContext& Context) const;
};

