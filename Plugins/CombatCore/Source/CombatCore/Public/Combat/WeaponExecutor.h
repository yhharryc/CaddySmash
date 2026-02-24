#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Combat/AttackTypes.h"
#include "WeaponExecutor.generated.h"

UINTERFACE(BlueprintType)
class COMBATCORE_API UWeaponExecutor : public UInterface
{
    GENERATED_BODY()
};

class COMBATCORE_API IWeaponExecutor
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combat")
    bool CanExecuteAttack(UPARAM(ref) FCombatAttackContext& Context);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combat")
    void ExecuteAttack(UPARAM(ref) FCombatAttackContext& Context);
};
