#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AttackTypes.h"
#include "AttackOrchestratorComponent.generated.h"

class UAttackProfile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttackRequestEvent, const FCombatAttackRequest&, Request);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackSimpleEvent);

UCLASS(ClassGroup=(Combat), meta=(BlueprintSpawnableComponent))
class COMBATCORE_API UAttackOrchestratorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAttackOrchestratorComponent();

    UFUNCTION(BlueprintCallable, Category="Combat")
    bool BeginAttackIntent(const FCombatAttackRequest& Request);

    UFUNCTION(BlueprintCallable, Category="Combat")
    void CommitAttack();

    /** Attempts to send confirm only when the profile ability is active (or can be activated now). */
    UFUNCTION(BlueprintCallable, Category="Combat")
    bool TryCommitAttack();

    UFUNCTION(BlueprintCallable, Category="Combat")
    void CancelAttack();

    UFUNCTION(BlueprintCallable, Category="Combat")
    bool ConsumePendingRequest(FCombatAttackRequest& OutRequest);

    UFUNCTION(BlueprintCallable, Category="Combat")
    void ClearPendingRequest();

    UPROPERTY(BlueprintAssignable, Category="Combat|Events")
    FAttackRequestEvent OnIntentStarted;

    UPROPERTY(BlueprintAssignable, Category="Combat|Events")
    FAttackSimpleEvent OnCommitRequested;

    UPROPERTY(BlueprintAssignable, Category="Combat|Events")
    FAttackSimpleEvent OnCancelled;

    /** If true, grant the ability on first use when missing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bAutoGrantAbility = true;

private:
    UObject* ResolveAttackAdapter(const FCombatAttackRequest& Request) const;
    UAttackProfile* ResolveProfile(const FCombatAttackRequest& Request) const;

    FCombatAttackRequest PendingRequest;
    bool bHasPendingRequest = false;
};
