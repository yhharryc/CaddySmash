#include "Combat/AttackOrchestratorComponent.h"

#include "Combat/CombatAttackAdapter.h"
#include "Combat/CombatCoreLog.h"
#include "Combat/AttackProfile.h"

namespace
{
    static bool IsAdapterObject(UObject* Object)
    {
        return Object && Object->GetClass()->ImplementsInterface(UCombatAttackAdapter::StaticClass());
    }
}

UAttackOrchestratorComponent::UAttackOrchestratorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

UObject* UAttackOrchestratorComponent::ResolveAttackAdapter(const FCombatAttackRequest& Request) const
{
    if (IsAdapterObject(Request.SourceObject.Get()))
    {
        return Request.SourceObject.Get();
    }

    if (IsAdapterObject(Request.WeaponObject.Get()))
    {
        return Request.WeaponObject.Get();
    }

    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return nullptr;
    }

    if (IsAdapterObject(Owner))
    {
        return Owner;
    }

    TArray<UActorComponent*> Components;
    Owner->GetComponents(Components);
    for (UActorComponent* Component : Components)
    {
        if (IsAdapterObject(Component))
        {
            return Component;
        }
    }

    return nullptr;
}

UAttackProfile* UAttackOrchestratorComponent::ResolveProfile(const FCombatAttackRequest& Request) const
{
    return Request.Profile.Get();
}

bool UAttackOrchestratorComponent::BeginAttackIntent(const FCombatAttackRequest& Request)
{
    PendingRequest = Request;
    bHasPendingRequest = true;

    UObject* Adapter = ResolveAttackAdapter(Request);
    if (!Adapter)
    {
        UE_LOG(LogCombatCore, Warning, TEXT("AttackOrchestrator: no attack adapter on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    UAttackProfile* Profile = ResolveProfile(Request);
    if (!Profile)
    {
        UE_LOG(LogCombatCore, Warning, TEXT("AttackOrchestrator: missing profile on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    const bool bStarted = ICombatAttackAdapter::Execute_BeginAttackIntent(Adapter, this, Request);
    UE_LOG(LogCombatCore, Log, TEXT("AttackOrchestrator: begin intent via %s on %s -> %s"),
        *GetNameSafe(Adapter),
        *GetNameSafe(GetOwner()),
        bStarted ? TEXT("true") : TEXT("false"));

    if (bStarted)
    {
        OnIntentStarted.Broadcast(Request);
    }

    return bStarted;
}

void UAttackOrchestratorComponent::CommitAttack()
{
    TryCommitAttack();
}

bool UAttackOrchestratorComponent::TryCommitAttack()
{
    if (!bHasPendingRequest)
    {
        UE_LOG(LogCombatCore, Warning, TEXT("AttackOrchestrator: try commit without pending request on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    UObject* Adapter = ResolveAttackAdapter(PendingRequest);
    if (!Adapter)
    {
        UE_LOG(LogCombatCore, Warning, TEXT("AttackOrchestrator: no attack adapter for commit on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    const bool bCommitted = ICombatAttackAdapter::Execute_TryCommitAttack(Adapter, this, PendingRequest);
    UE_LOG(LogCombatCore, Log, TEXT("AttackOrchestrator: try commit via %s on %s -> %s"),
        *GetNameSafe(Adapter),
        *GetNameSafe(GetOwner()),
        bCommitted ? TEXT("true") : TEXT("false"));

    if (bCommitted)
    {
        OnCommitRequested.Broadcast();
    }

    return bCommitted;
}

void UAttackOrchestratorComponent::CancelAttack()
{
    UE_LOG(LogCombatCore, Warning, TEXT("AttackOrchestrator: cancel attack on %s hasPending=%d"),
        *GetNameSafe(GetOwner()),
        bHasPendingRequest ? 1 : 0);

    if (bHasPendingRequest)
    {
        if (UObject* Adapter = ResolveAttackAdapter(PendingRequest))
        {
            ICombatAttackAdapter::Execute_CancelAttack(Adapter, this, PendingRequest);
        }
    }
    ClearPendingRequest();
    OnCancelled.Broadcast();
}

bool UAttackOrchestratorComponent::ConsumePendingRequest(FCombatAttackRequest& OutRequest)
{
    if (!bHasPendingRequest)
    {
        return false;
    }

    OutRequest = PendingRequest;
    return true;
}

void UAttackOrchestratorComponent::ClearPendingRequest()
{
    PendingRequest = FCombatAttackRequest();
    bHasPendingRequest = false;
}
