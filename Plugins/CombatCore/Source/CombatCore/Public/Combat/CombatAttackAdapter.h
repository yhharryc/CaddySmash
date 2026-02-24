#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Combat/AttackTypes.h"
#include "CombatAttackAdapter.generated.h"

class UAttackOrchestratorComponent;

UINTERFACE(BlueprintType)
class COMBATCORE_API UCombatAttackAdapter : public UInterface
{
    GENERATED_BODY()
};

class COMBATCORE_API ICombatAttackAdapter
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combat|Adapter")
    bool BeginAttackIntent(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combat|Adapter")
    bool TryCommitAttack(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combat|Adapter")
    void CancelAttack(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request);
};
