#include "Combat/AttackAbility.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Combat/CombatCoreGASAdapterLog.h"
#include "Combat/AttackRangeModel.h"
#include "Combat/AttackProfile.h"
#include "Combat/AttackOrchestratorComponent.h"
#include "Combat/CombatWeaponActor.h"
#include "Combat/WeaponExecutor.h"
#include "Engine/World.h"
#include "TimerManager.h"

namespace
{
    static UObject* FindWeaponExecutorOnActor(AActor* Actor)
    {
        if (!Actor) return nullptr;
        if (Actor->GetClass()->ImplementsInterface(UWeaponExecutor::StaticClass()))
        {
            return Actor;
        }
        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UWeaponExecutor::StaticClass()))
            {
                return Comp;
            }
        }
        return nullptr;
    }

    static UObject* FindWeaponExecutor(AActor* Actor)
    {
        if (!Actor) return nullptr;
        if (UObject* Direct = FindWeaponExecutorOnActor(Actor))
        {
            return Direct;
        }
        TArray<AActor*> Attached;
        Actor->GetAttachedActors(Attached);
        for (AActor* Child : Attached)
        {
            if (UObject* Found = FindWeaponExecutorOnActor(Child))
            {
                return Found;
            }
        }
        return nullptr;
    }
}

UAttackAbility::UAttackAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    CachedHandle = Handle;
    CachedActorInfo = ActorInfo;
    CachedActivationInfo = ActivationInfo;

    if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: Missing ActorInfo/Avatar"));
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    FCombatAttackContext Context;
    UObject* WeaponObj = nullptr;
    if (!BuildContext(ActorInfo, Context, WeaponObj))
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: BuildContext failed for %s"), *GetNameSafe(ActorInfo->AvatarActor.Get()));
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    if (!WeaponObj || !WeaponObj->GetClass()->ImplementsInterface(UWeaponExecutor::StaticClass()))
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: No WeaponExecutor for %s"), *GetNameSafe(ActorInfo->AvatarActor.Get()));
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    if (!IWeaponExecutor::Execute_CanExecuteAttack(WeaponObj, Context))
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: CanExecuteAttack false for %s"), *GetNameSafe(ActorInfo->AvatarActor.Get()));
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    CachedContext = Context;
    CachedWeaponObject = WeaponObj;
    bHasCachedContext = true;
    bCommitRequested = false;
    UE_LOG(LogCombatCoreGAS, Log, TEXT("AttackAbility: Context ready for %s"), *GetNameSafe(ActorInfo->AvatarActor.Get()));
    OnAttackContextReady(CachedContext);

    if (const UAttackProfile* Profile = CachedContext.Request.Profile)
    {
        if (Profile->IntentDuration > 0.f)
        {
            if (UWorld* World = GetWorld())
            {
                World->GetTimerManager().SetTimer(IntentTimeoutHandle, this, &UAttackAbility::HandleIntentTimeout, Profile->IntentDuration, false);
            }
        }
    }
}

void UAttackAbility::HandleConfirm()
{
    CommitAndExecute();
}

void UAttackAbility::HandleCancel()
{
    UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: HandleCancel on %s"), *GetNameSafe(this));
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
}

bool UAttackAbility::RequestCommitFromOrchestrator()
{
    if (!IsActive())
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: RequestCommit called while not active on %s"), *GetNameSafe(this));
        return false;
    }

    return CommitAndExecute();
}

void UAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    UE_LOG(LogCombatCoreGAS, Log, TEXT("AttackAbility: EndAbility %s cancelled=%d commitRequested=%d owner=%s"),
        *GetNameSafe(this),
        bWasCancelled ? 1 : 0,
        bCommitRequested ? 1 : 0,
        *GetNameSafe(ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr));
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(IntentTimeoutHandle);
        World->GetTimerManager().ClearTimer(MotionTimeoutHandle);
    }
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

bool UAttackAbility::GetAttackContext(FCombatAttackContext& OutContext) const
{
    if (!bHasCachedContext)
    {
        return false;
    }
    OutContext = CachedContext;
    return true;
}

bool UAttackAbility::BuildContext(const FGameplayAbilityActorInfo* ActorInfo, FCombatAttackContext& OutContext, UObject*& OutWeaponObject)
{
    if (!ActorInfo) return false;

    AActor* Avatar = ActorInfo->AvatarActor.Get();
    if (!Avatar) return false;

    UAttackOrchestratorComponent* Orchestrator = Avatar->FindComponentByClass<UAttackOrchestratorComponent>();
    if (!Orchestrator) return false;

    FCombatAttackRequest Request;
    if (!Orchestrator->ConsumePendingRequest(Request))
    {
        return false;
    }

    OutContext.Request = Request;
    OutContext.World = Avatar->GetWorld();

    OutWeaponObject = Request.WeaponObject;
    if (!OutWeaponObject)
    {
        OutWeaponObject = FindWeaponExecutor(Avatar);
    }

    return true;
}

bool UAttackAbility::CommitAndExecute()
{
    bCommitRequested = true;
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(IntentTimeoutHandle);
    }

    if (!CachedActorInfo || !CachedWeaponObject)
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: Confirm but missing cached data"));
        EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
        return false;
    }

    if (!CommitAbility(CachedHandle, CachedActorInfo, CachedActivationInfo))
    {
        UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: CommitAbility failed on %s"), *GetNameSafe(CachedActorInfo->AvatarActor.Get()));
        EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
        return false;
    }

    FCombatAttackExecutionParams ExecutionParams = CachedContext.ExecutionParams;
    if (ExecutionParams.EffectiveAttackRange <= 0.f)
    {
        if (const UAttackProfile* Profile = CachedContext.Request.Profile)
        {
            ExecutionParams.EffectiveAttackRange = FMath::Max(0.f, Profile->Range);
        }
    }

    float DistanceToTarget = 0.f;
    if (const AActor* OwnerActor = CachedActorInfo ? CachedActorInfo->AvatarActor.Get() : nullptr)
    {
        if (const AActor* TargetActor = CachedContext.Request.TargetActor.Get())
        {
            DistanceToTarget = FVector::Distance(OwnerActor->GetActorLocation(), TargetActor->GetActorLocation());
        }
    }

    if (const UAttackProfile* Profile = CachedContext.Request.Profile)
    {
        if (Profile->RangeModel)
        {
            Profile->RangeModel->BuildExecutionParams(CachedContext, DistanceToTarget, ExecutionParams);
        }
        else
        {
            // Default melee fallback: map profile range into thrust distance when no custom model is set.
            if (const ACombatWeaponActor* WeaponActor = Cast<ACombatWeaponActor>(CachedWeaponObject.Get()))
            {
                if (WeaponActor->MotionType == EWeaponMotionType::Thrust && ExecutionParams.EffectiveAttackRange > 0.f)
                {
                    ExecutionParams.bOverrideThrustDistance = true;
                    ExecutionParams.ThrustDistance = FMath::Clamp(ExecutionParams.EffectiveAttackRange * 0.35f, 25.f, 160.f);
                }
            }
        }
    }
    CachedContext.ExecutionParams = ExecutionParams;

    UE_LOG(LogCombatCoreGAS, Log, TEXT("AttackAbility: ExecuteAttack on %s"), *GetNameSafe(CachedActorInfo->AvatarActor.Get()));
    IWeaponExecutor::Execute_ExecuteAttack(CachedWeaponObject, CachedContext);
    
    // Set motion timeout to prevent ability from lingering indefinitely.
    // The ability should be ended by Blueprint/Motion callbacks, but this is a safety net.
    if (UWorld* World = GetWorld())
    {
        float TimeoutDuration = 5.0f; // Default fallback
        
        // Use AttackProfile's CommitWindowEnd as reference if available
        if (const UAttackProfile* Profile = CachedContext.Request.Profile)
        {
            // Add some buffer time beyond the expected motion duration
            TimeoutDuration = Profile->CommitWindowEnd + 1.0f;
        }
        
        World->GetTimerManager().SetTimer(
            MotionTimeoutHandle,
            this,
            &UAttackAbility::HandleMotionTimeout,
            FMath::Max(0.1f, TimeoutDuration),
            false
        );
        
        UE_LOG(LogCombatCoreGAS, Log, TEXT("AttackAbility: Motion timeout set to %.2f seconds on %s"),
            TimeoutDuration,
            *GetNameSafe(CachedActorInfo->AvatarActor.Get()));
    }
    
    return true;
}

void UAttackAbility::HandleIntentTimeout()
{
    if (bCommitRequested || !IsActive())
    {
        return;
    }

    UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: Intent timeout on %s owner=%s"),
        *GetNameSafe(this),
        *GetNameSafe(CachedActorInfo ? CachedActorInfo->AvatarActor.Get() : nullptr));
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
}

void UAttackAbility::HandleMotionTimeout()
{
    if (!IsActive())
    {
        return;
    }

    UE_LOG(LogCombatCoreGAS, Warning, TEXT("AttackAbility: Motion timeout triggered on %s - ending ability as safety net"),
        *GetNameSafe(CachedActorInfo ? CachedActorInfo->AvatarActor.Get() : nullptr));
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, false);
}
