#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "CaddyVehicleStaggerAbility.generated.h"

USTRUCT(BlueprintType)
struct FCaddyVehicleStaggerTierConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stagger", meta=(ClampMin="0.0"))
    float DurationSeconds = 0.4f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stagger", meta=(ClampMin="1"))
    int32 Spins = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stagger", meta=(ClampMin="0.0"))
    float InputLockSeconds = 0.4f;
};

UCLASS()
class CADDYSMASH_API UCaddyVehicleStaggerAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UCaddyVehicleStaggerAbility();

    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;

protected:
    UPROPERTY(EditAnywhere, Category="Stagger|Trigger", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag StaggerEventTag;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier")
    FCaddyVehicleStaggerTierConfig LightTier;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier")
    FCaddyVehicleStaggerTierConfig MediumTier;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier")
    FCaddyVehicleStaggerTierConfig HeavyTier;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier")
    FCaddyVehicleStaggerTierConfig DefaultTier;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag LightImpactTag;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag MediumImpactTag;

    UPROPERTY(EditAnywhere, Category="Stagger|Tier", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag HeavyImpactTag;

private:
    const FCaddyVehicleStaggerTierConfig& ResolveTierConfig(const FGameplayEventData* TriggerEventData) const;
    void FinishStagger();

    FTimerHandle FinishTimerHandle;
    TWeakObjectPtr<class ACaddyVehiclePawn> CachedPawn;
};
