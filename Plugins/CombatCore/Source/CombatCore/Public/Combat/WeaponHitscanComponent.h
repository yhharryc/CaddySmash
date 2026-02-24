#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/WeaponExecutor.h"
#include "WeaponHitscanComponent.generated.h"

UCLASS(ClassGroup=(Combat), meta=(BlueprintSpawnableComponent))
class COMBATCORE_API UWeaponHitscanComponent : public UActorComponent, public IWeaponExecutor
{
    GENERATED_BODY()

public:
    UWeaponHitscanComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float Range = 2000.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float Damage = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bDrawDebug = false;

    virtual bool CanExecuteAttack_Implementation(FCombatAttackContext& Context) override { return true; }
    virtual void ExecuteAttack_Implementation(FCombatAttackContext& Context) override;
};
