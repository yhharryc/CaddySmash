#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CaddyVehicleKnockbackAbility.generated.h"

class UArcadeVehicleMovementComponent;

USTRUCT(BlueprintType)
struct FCaddyVehicleKnockbackTierConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Knockback", meta=(ClampMin="0.0"))
    float OverrideSpeed = 650.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Knockback", meta=(ClampMin="0.01"))
    float OverrideDuration = 0.14f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Knockback", meta=(ClampMin="0.0", ClampMax="1.0"))
    float CarryVelocityRatio = 0.15f;
};

/**
 * Event-driven knockback ability for collision combat feedback.
 * Triggered by gameplay event tags emitted from damageable component.
 */
UCLASS()
class CADDYSMASH_API UCaddyVehicleKnockbackAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UCaddyVehicleKnockbackAbility();

protected:
    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;

    virtual void EndAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        bool bReplicateEndAbility,
        bool bWasCancelled) override;

private:
    void FinishKnockback();
    FVector2D ResolveKnockbackDirection(const APawn& Pawn, const FGameplayEventData* TriggerEventData) const;
    const FCaddyVehicleKnockbackTierConfig& ResolveTierConfig(const FGameplayEventData* TriggerEventData) const;

    UPROPERTY(EditAnywhere, Category="Knockback|Trigger", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag KnockbackEventTag;

    UPROPERTY(EditAnywhere, Category="Knockback|Trigger")
    FGameplayTag LightImpactTag;

    UPROPERTY(EditAnywhere, Category="Knockback|Trigger")
    FGameplayTag MediumImpactTag;

    UPROPERTY(EditAnywhere, Category="Knockback|Trigger")
    FGameplayTag HeavyImpactTag;

    UPROPERTY(EditAnywhere, Category="Knockback|Fallback", meta=(ClampMin="0.0"))
    float MediumDamageThreshold = 28.0f;

    UPROPERTY(EditAnywhere, Category="Knockback|Fallback", meta=(ClampMin="0.0"))
    float HeavyDamageThreshold = 52.0f;

    UPROPERTY(EditAnywhere, Category="Knockback|Tier")
    FCaddyVehicleKnockbackTierConfig LightKnockback;

    UPROPERTY(EditAnywhere, Category="Knockback|Tier")
    FCaddyVehicleKnockbackTierConfig MediumKnockback;

    UPROPERTY(EditAnywhere, Category="Knockback|Tier")
    FCaddyVehicleKnockbackTierConfig HeavyKnockback;

    TWeakObjectPtr<UArcadeVehicleMovementComponent> ActiveMovementComponent;
    FVector ActiveDirection = FVector::ZeroVector;
    float ActiveCarrySpeed = 0.0f;
    FTimerHandle KnockbackTimerHandle;
};

