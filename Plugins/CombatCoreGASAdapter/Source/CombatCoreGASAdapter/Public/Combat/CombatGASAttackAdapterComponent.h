#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/CombatAttackAdapter.h"
#include "CombatGASAttackAdapterComponent.generated.h"

class UAbilitySystemComponent;
class UAttackAbility;
class UAttackOrchestratorComponent;
class UGameplayAbility;
struct FGameplayAbilitySpec;

UCLASS(ClassGroup=(Combat), meta=(BlueprintSpawnableComponent))
class COMBATCOREGASADAPTER_API UCombatGASAttackAdapterComponent : public UActorComponent, public ICombatAttackAdapter
{
    GENERATED_BODY()

public:
    UCombatGASAttackAdapterComponent();

    /** If true, grant the profile ability when missing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bAutoGrantAbility = true;

    virtual bool BeginAttackIntent_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request) override;
    virtual bool TryCommitAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request) override;
    virtual void CancelAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request) override;

private:
    UAbilitySystemComponent* ResolveASC() const;
    TSubclassOf<UGameplayAbility> ResolveAbilityClass(const FCombatAttackRequest& Request) const;
    bool IsProfileAbilityActive(UAbilitySystemComponent* ASC, TSubclassOf<UGameplayAbility> AbilityClass) const;
    UAttackAbility* FindAttackAbilityInstance(FGameplayAbilitySpec* Spec) const;
};
