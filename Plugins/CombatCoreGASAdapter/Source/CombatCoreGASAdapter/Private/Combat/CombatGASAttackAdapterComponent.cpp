#include "Combat/CombatGASAttackAdapterComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Combat/AttackAbility.h"
#include "Combat/AttackOrchestratorComponent.h"
#include "Combat/AttackProfile.h"
#include "Combat/CombatCoreGASAdapterLog.h"

UCombatGASAttackAdapterComponent::UCombatGASAttackAdapterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

UAbilitySystemComponent* UCombatGASAttackAdapterComponent::ResolveASC() const
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return nullptr;
    }

    return UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner);
}

TSubclassOf<UGameplayAbility> UCombatGASAttackAdapterComponent::ResolveAbilityClass(const FCombatAttackRequest& Request) const
{
    const UAttackProfile* Profile = Request.Profile.Get();
    if (!Profile)
    {
        return nullptr;
    }

    UClass* RawClass = Profile->AbilityClass.Get();
    if (!RawClass)
    {
        return nullptr;
    }

    if (!RawClass->IsChildOf(UGameplayAbility::StaticClass()))
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: profile ability class %s is not a GameplayAbility"), *GetNameSafe(RawClass));
        return nullptr;
    }

    return RawClass;
}

bool UCombatGASAttackAdapterComponent::IsProfileAbilityActive(UAbilitySystemComponent* ASC, TSubclassOf<UGameplayAbility> AbilityClass) const
{
    if (!ASC || !AbilityClass)
    {
        return false;
    }

    if (FGameplayAbilitySpec* Spec = ASC->FindAbilitySpecFromClass(AbilityClass))
    {
        return Spec->IsActive();
    }

    return false;
}

UAttackAbility* UCombatGASAttackAdapterComponent::FindAttackAbilityInstance(FGameplayAbilitySpec* Spec) const
{
    if (!Spec)
    {
        return nullptr;
    }

    if (UAttackAbility* Primary = Cast<UAttackAbility>(Spec->GetPrimaryInstance()))
    {
        return Primary;
    }

    UAttackAbility* FirstFound = nullptr;
    const TArray<UGameplayAbility*> Instances = Spec->GetAbilityInstances();
    for (UGameplayAbility* Instance : Instances)
    {
        UAttackAbility* AttackInstance = Cast<UAttackAbility>(Instance);
        if (!AttackInstance)
        {
            continue;
        }

        if (!FirstFound)
        {
            FirstFound = AttackInstance;
        }

        if (AttackInstance->IsActive())
        {
            return AttackInstance;
        }
    }

    return FirstFound;
}

bool UCombatGASAttackAdapterComponent::BeginAttackIntent_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request)
{
    if (!Orchestrator)
    {
        return false;
    }

    UAbilitySystemComponent* ASC = ResolveASC();
    if (!ASC)
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: no ASC on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    const TSubclassOf<UGameplayAbility> AbilityClass = ResolveAbilityClass(Request);
    if (!AbilityClass)
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: missing or invalid profile ability on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    const bool bShouldAutoGrant = Orchestrator ? Orchestrator->bAutoGrantAbility : bAutoGrantAbility;
    if (bShouldAutoGrant && !ASC->FindAbilitySpecFromClass(AbilityClass))
    {
        ASC->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1, INDEX_NONE, this));
    }

    if (IsProfileAbilityActive(ASC, AbilityClass))
    {
        return true;
    }

    const bool bActivated = ASC->TryActivateAbilityByClass(AbilityClass);
    UE_LOG(LogCombatCoreGAS, Log, TEXT("CombatGASAttackAdapter: TryActivate %s on %s -> %s"),
        *GetNameSafe(AbilityClass),
        *GetNameSafe(GetOwner()),
        bActivated ? TEXT("true") : TEXT("false"));

    return bActivated;
}

bool UCombatGASAttackAdapterComponent::TryCommitAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request)
{
    if (!Orchestrator)
    {
        return false;
    }

    UAbilitySystemComponent* ASC = ResolveASC();
    if (!ASC)
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: no ASC for commit on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    const TSubclassOf<UGameplayAbility> AbilityClass = ResolveAbilityClass(Request);
    if (!AbilityClass)
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: missing or invalid ability class for commit on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    if (!IsProfileAbilityActive(ASC, AbilityClass))
    {
        const bool bActivated = ASC->TryActivateAbilityByClass(AbilityClass);
        UE_LOG(LogCombatCoreGAS, Log, TEXT("CombatGASAttackAdapter: TryActivateBeforeCommit %s on %s -> %s"),
            *GetNameSafe(AbilityClass),
            *GetNameSafe(GetOwner()),
            bActivated ? TEXT("true") : TEXT("false"));

        if (!IsProfileAbilityActive(ASC, AbilityClass))
        {
            return false;
        }
    }

    if (FGameplayAbilitySpec* Spec = ASC->FindAbilitySpecFromClass(AbilityClass))
    {
        UAttackAbility* AttackAbility = FindAttackAbilityInstance(Spec);
        if (!AttackAbility)
        {
            const UGameplayAbility* AbilityCDO = AbilityClass ? AbilityClass->GetDefaultObject<UGameplayAbility>() : nullptr;
            const int32 InstancingPolicy = AbilityCDO ? static_cast<int32>(AbilityCDO->GetInstancingPolicy()) : -1;
            UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: no UAttackAbility instance for %s on %s (active=%d policy=%d)"),
                *GetNameSafe(AbilityClass),
                *GetNameSafe(GetOwner()),
                Spec->IsActive() ? 1 : 0,
                InstancingPolicy);
            return false;
        }

        if (AttackAbility->RequestCommitFromOrchestrator())
        {
            UE_LOG(LogCombatCoreGAS, Log, TEXT("CombatGASAttackAdapter: commit ability instance on %s"), *GetNameSafe(GetOwner()));
            return true;
        }

        UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: RequestCommitFromOrchestrator failed on %s"), *GetNameSafe(GetOwner()));
        return false;
    }

    UE_LOG(LogCombatCoreGAS, Warning, TEXT("CombatGASAttackAdapter: no ability spec for %s on %s"),
        *GetNameSafe(AbilityClass),
        *GetNameSafe(GetOwner()));
    return false;
}

void UCombatGASAttackAdapterComponent::CancelAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, const FCombatAttackRequest& Request)
{
    if (!Orchestrator)
    {
        return;
    }

    UAbilitySystemComponent* ASC = ResolveASC();
    if (!ASC)
    {
        return;
    }

    const TSubclassOf<UGameplayAbility> AbilityClass = ResolveAbilityClass(Request);

    ASC->LocalInputCancel();
    if (AbilityClass)
    {
        if (FGameplayAbilitySpec* Spec = ASC->FindAbilitySpecFromClass(AbilityClass))
        {
            ASC->CancelAbilityHandle(Spec->Handle);
        }
    }
}
