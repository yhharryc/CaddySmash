#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AttackTypes.h"
#include "AttackAbility.generated.h"

UCLASS()
class COMBATCOREGASADAPTER_API UAttackAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UAttackAbility();

    /** For AI/state-tree flow: commit the currently active attack ability instance immediately. */
    UFUNCTION(BlueprintCallable, Category="Combat")
    bool RequestCommitFromOrchestrator();

protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

    UFUNCTION(BlueprintCallable, Category="Combat")
    bool GetAttackContext(FCombatAttackContext& OutContext) const;

    UFUNCTION(BlueprintImplementableEvent, Category="Combat")
    void OnAttackContextReady(const FCombatAttackContext& Context);

    UFUNCTION()
    void HandleConfirm();

    UFUNCTION()
    void HandleCancel();

private:
    void HandleIntentTimeout();
    void HandleMotionTimeout();
    bool CommitAndExecute();
    bool BuildContext(const FGameplayAbilityActorInfo* ActorInfo, FCombatAttackContext& OutContext, UObject*& OutWeaponObject);

    FGameplayAbilitySpecHandle CachedHandle;
    const FGameplayAbilityActorInfo* CachedActorInfo = nullptr;
    FGameplayAbilityActivationInfo CachedActivationInfo;
    FCombatAttackContext CachedContext;
    TObjectPtr<UObject> CachedWeaponObject = nullptr;
    bool bHasCachedContext = false;
    bool bCommitRequested = false;
    FTimerHandle IntentTimeoutHandle;
    FTimerHandle MotionTimeoutHandle;
};
