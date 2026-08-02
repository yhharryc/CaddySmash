#include "SquadCore/StateTree/SquadStateTreeTasks.h"

#include "Combat/AttackOrchestratorComponent.h"
#include "Combat/AttackProfile.h"
#include "Combat/AttackTypes.h"
#include "Combat/WeaponHitscanComponent.h"
#include "SquadCore/StateTree/SquadStateTreeLog.h"
#include "SquadCore/CompliancePolicy.h"
#include "SquadCore/LootEvaluator.h"
#include "SquadCore/SquadManagerSubsystem.h"
#include "SquadCore/SquadMemberComponent.h"
#include "SquadCore/ThreatEvaluator.h"
#include "StateTreeExecutionContext.h"
#include "Combat/CombatWeaponActor.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/Pawn.h"
#include "VisualLogger/VisualLogger.h"

namespace
{
    static const TCHAR* ToRunStatusString(const EStateTreeRunStatus Status)
    {
        switch (Status)
        {
        case EStateTreeRunStatus::Running: return TEXT("Running");
        case EStateTreeRunStatus::Succeeded: return TEXT("Succeeded");
        case EStateTreeRunStatus::Failed: return TEXT("Failed");
        case EStateTreeRunStatus::Stopped: return TEXT("Stopped");
        case EStateTreeRunStatus::Unset: return TEXT("Unset");
        default: return TEXT("Unknown");
        }
    }

    static bool IsTaskConsideredForCompletion(const UStateTreeTaskBlueprintBase* Task)
    {
#if WITH_EDITORONLY_DATA
        return Task ? Task->bConsideredForCompletion : false;
#else
        return false;
#endif
    }

    static EStateTreeRunStatus LogTaskReturn(
        AActor* OwnerActor,
        const USquadMemberComponent* Member,
        const TCHAR* TaskName,
        const UStateTreeTaskBlueprintBase* Task,
        const EStateTreeRunStatus Status,
        const TCHAR* Reason)
    {
        const bool bConsidered = IsTaskConsideredForCompletion(Task);
        UE_VLOG_UELOG(
            OwnerActor,
            LogSquadStateTree,
            Verbose,
            TEXT("[ST:%s] Return=%s Considered=%d Reason=%s"),
            TaskName,
            ToRunStatusString(Status),
            bConsidered ? 1 : 0,
            Reason ? Reason : TEXT(""));

        if (Member && Member->bDebugAI)
        {
            UE_LOG(
                LogSquadStateTree,
                Verbose,
                TEXT("[ST:%s] Return=%s Considered=%d Reason=%s"),
                TaskName,
                ToRunStatusString(Status),
                bConsidered ? 1 : 0,
                Reason ? Reason : TEXT(""));
        }

        return Status;
    }

    static ACombatWeaponActor* FindCombatWeaponActor(AActor* OwnerActor)
    {
        if (!OwnerActor)
        {
            return nullptr;
        }

        if (ACombatWeaponActor* Weapon = Cast<ACombatWeaponActor>(OwnerActor))
        {
            return Weapon;
        }

        TArray<AActor*> Attached;
        OwnerActor->GetAttachedActors(Attached);
        for (AActor* Child : Attached)
        {
            if (ACombatWeaponActor* Found = Cast<ACombatWeaponActor>(Child))
            {
                return Found;
            }
        }

        return nullptr;
    }

    static void SetDebugTask(USquadMemberComponent* Member, const FName TaskName)
    {
        if (Member)
        {
            Member->DebugLastTask = TaskName;
        }
    }

    static float GetWeaponAttackDuration(ACombatWeaponActor* Weapon)
    {
        if (!Weapon)
        {
            return 0.f;
        }

        if (Weapon->MotionType == EWeaponMotionType::None)
        {
            return 0.f;
        }

        return FMath::Max(0.f, Weapon->ThrustDuration) + FMath::Max(0.f, Weapon->ReturnDuration);
    }

    static float FindHitscanRange(AActor* OwnerActor)
    {
        if (!OwnerActor)
        {
            return 0.f;
        }

        if (UWeaponHitscanComponent* Hitscan = OwnerActor->FindComponentByClass<UWeaponHitscanComponent>())
        {
            return FMath::Max(0.f, Hitscan->Range);
        }

        TArray<AActor*> Attached;
        OwnerActor->GetAttachedActors(Attached);
        for (AActor* Child : Attached)
        {
            if (!Child)
            {
                continue;
            }

            if (UWeaponHitscanComponent* Hitscan = Child->FindComponentByClass<UWeaponHitscanComponent>())
            {
                return FMath::Max(0.f, Hitscan->Range);
            }
        }

        return 0.f;
    }

    static float ResolveEffectiveAttackRange(AActor* OwnerActor, const USquadMemberComponent* Member)
    {
        if (Member && Member->LastAttackProfile && Member->LastAttackProfile->Range > 0.f)
        {
            return FMath::Max(0.f, Member->LastAttackProfile->Range);
        }

        if (ACombatWeaponActor* Weapon = FindCombatWeaponActor(OwnerActor))
        {
            if (Weapon->DefaultAttackProfile && Weapon->DefaultAttackProfile->Range > 0.f)
            {
                return FMath::Max(0.f, Weapon->DefaultAttackProfile->Range);
            }
        }

        const float HitscanRange = FindHitscanRange(OwnerActor);
        if (HitscanRange > 0.f)
        {
            return HitscanRange;
        }

        return Member ? FMath::Max(0.f, Member->CurrentAttackRange) : 0.f;
    }

    static float ResolveAggressionRange(
        const USquadTask_EvaluateThreats* Task,
        const UThreatEvaluator* Evaluator,
        const float AttackRange)
    {
        if (!Task)
        {
            return FMath::Max(0.f, AttackRange);
        }

        if (Task->AggressionRangeOverride >= 0.f)
        {
            return FMath::Max(0.f, Task->AggressionRangeOverride);
        }

        if (AttackRange > 0.f)
        {
            return FMath::Max(Task->MinAggressionRange, AttackRange * FMath::Max(0.f, Task->AggressionRangeMultiplier));
        }

        if (Evaluator && Evaluator->MaxRange > 0.f)
        {
            return FMath::Max(Task->MinAggressionRange, Evaluator->MaxRange);
        }

        return FMath::Max(0.f, Task->MinAggressionRange);
    }
}

USquadTask_AssignSlot::USquadTask_AssignSlot(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = false;
#if WITH_EDITORONLY_DATA
    // This task initializes data but should not drive parent state completion.
    bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus USquadTask_AssignSlot::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("AssignSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    UWorld* World = OwnerActor->GetWorld();
    if (!World)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("AssignSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoWorld"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    USquadManagerSubsystem* Manager = World->GetSubsystem<USquadManagerSubsystem>();
    if (!Member || !Manager)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("AssignSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoMemberOrManager"));
    }
    SetDebugTask(Member, TEXT("AssignSlot"));

    const int32 SlotId = Manager->RegisterMember(OwnerActor);
    Member->SlotId = SlotId;

    FVector SlotPos;
    if (Manager->GetSlotWorldLocation(SlotId, SlotPos))
    {
        Member->SlotWorldPos = SlotPos;
    }

    // One-shot setup task; do not keep it running to avoid noisy completion status.
    return LogTaskReturn(OwnerActor, Member, TEXT("AssignSlot"), this, EStateTreeRunStatus::Succeeded, TEXT("Assigned"));
}

USquadTask_UpdateSlotWorldPos::USquadTask_UpdateSlotWorldPos(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = true;
}

EStateTreeRunStatus USquadTask_UpdateSlotWorldPos::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    if (AActor* OwnerActor = GetOwnerActor(Context))
    {
        if (USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>())
        {
            SetDebugTask(Member, TEXT("UpdateSlotWorldPos"));
            return LogTaskReturn(OwnerActor, Member, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Running, TEXT("Enter"));
        }
        return LogTaskReturn(OwnerActor, nullptr, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    return LogTaskReturn(nullptr, nullptr, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
}

EStateTreeRunStatus USquadTask_UpdateSlotWorldPos::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    SetDebugTask(Member, TEXT("UpdateSlotWorldPos"));

    if (bOnlyWhenObeying && !Member->bShouldObeyFormation)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Running, TEXT("SkipNotObeying"));
    }

    USquadManagerSubsystem* Manager = OwnerActor->GetWorld()->GetSubsystem<USquadManagerSubsystem>();
    if (!Manager)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Failed, TEXT("NoManager"));
    }

    FVector SlotPos;
    if (Manager->GetSlotWorldLocation(Member->SlotId, SlotPos))
    {
        Member->SlotWorldPos = SlotPos;
    }

    return LogTaskReturn(OwnerActor, Member, TEXT("UpdateSlotWorldPos"), this, EStateTreeRunStatus::Running, TEXT("UpdatedOrUnchanged"));
}

USquadTask_ComputeCompliance::USquadTask_ComputeCompliance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = false;
#if WITH_EDITORONLY_DATA
    // Periodic policy refresh should not complete the state on its own.
    bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus USquadTask_ComputeCompliance::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("ComputeCompliance"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("ComputeCompliance"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    SetDebugTask(Member, TEXT("ComputeCompliance"));

    UCompliancePolicy* Policy = PolicyOverride ? PolicyOverride : Member->CompliancePolicy;
    if (!Policy)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("ComputeCompliance"), this, EStateTreeRunStatus::Running, TEXT("NoPolicySkip"));
    }

    FSquadComplianceContext ComplianceContext;
    ComplianceContext.PressureValue = Member->PressureValue;
    ComplianceContext.HealthRatio = HealthRatioOverride;

    if (USquadManagerSubsystem* Manager = OwnerActor->GetWorld()->GetSubsystem<USquadManagerSubsystem>())
    {
        if (AActor* Leader = Manager->GetFormationLeader())
        {
            ComplianceContext.DistanceToLeader = FVector::Distance(OwnerActor->GetActorLocation(), Leader->GetActorLocation());
        }
    }

    Member->bShouldObeyFormation = Policy->ShouldObeyFormation(ComplianceContext);
    return LogTaskReturn(OwnerActor, Member, TEXT("ComputeCompliance"), this, EStateTreeRunStatus::Succeeded, TEXT("Computed"));
}

USquadTask_EvaluateThreats::USquadTask_EvaluateThreats(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = true;
}

EStateTreeRunStatus USquadTask_EvaluateThreats::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    LastUpdateTime = -1.f;
    LastBestTargetTime = -1.f;
    return Tick(Context, 0.f);
}

EStateTreeRunStatus USquadTask_EvaluateThreats::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    if (UpdateInterval > 0.f && (Now - LastUpdateTime) < UpdateInterval)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Running, TEXT("IntervalGate"));
    }
    LastUpdateTime = Now;

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    SetDebugTask(Member, TEXT("EvaluateThreats"));

    if (LastBestTargetTime < 0.f && IsValid(Member->BestTarget))
    {
        LastBestTargetTime = Now;
    }

    const float AttackRange = ResolveEffectiveAttackRange(OwnerActor, Member);
    UThreatEvaluator* Evaluator = EvaluatorOverride ? EvaluatorOverride : Member->ThreatEvaluator;
    const float AggressionRange = ResolveAggressionRange(this, Evaluator, AttackRange);
    Member->CurrentAttackRange = AttackRange;
    Member->CurrentAggressionRange = AggressionRange;
    Member->CurrentDesiredAttackDistance = FMath::Max(0.f, AttackRange - FMath::Max(0.f, DesiredAttackBuffer));

    const FVector OwnerLocation = OwnerActor->GetActorLocation();
    const auto UpdateRangeFlagsForTarget = [this, Member, OwnerLocation, AttackRange, AggressionRange](AActor* Target)
    {
        if (!Member || !IsValid(Target))
        {
            if (Member)
            {
                Member->DistanceToBestTarget = 0.f;
                Member->bBestTargetInAttackRange = false;
                Member->bBestTargetInAggressionRange = false;
            }
            return;
        }

        const float Distance = FVector::Distance(OwnerLocation, Target->GetActorLocation());
        Member->DistanceToBestTarget = Distance;

        const float AttackEnter = FMath::Max(0.f, AttackRange);
        const float AttackExit = AttackEnter + FMath::Max(0.f, AttackRangeHysteresis);
        const float AttackThreshold = Member->bBestTargetInAttackRange ? AttackExit : AttackEnter;
        Member->bBestTargetInAttackRange = AttackThreshold > 0.f && Distance <= AttackThreshold;

        const float AggroEnter = FMath::Max(0.f, AggressionRange);
        const float AggroExit = AggroEnter + FMath::Max(0.f, AggressionRangeHysteresis);
        const float AggroThreshold = Member->bBestTargetInAggressionRange ? AggroExit : AggroEnter;
        Member->bBestTargetInAggressionRange = AggroThreshold > 0.f && Distance <= AggroThreshold;
    };

    if (!Evaluator)
    {
        Member->ThreatList.Reset();
        if (BestTargetGraceTime > 0.f && IsValid(Member->BestTarget) && (Now - LastBestTargetTime) < BestTargetGraceTime)
        {
            UpdateRangeFlagsForTarget(Member->BestTarget);
            return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Running, TEXT("NoEvaluatorGraceHold"));
        }
        Member->BestTarget = nullptr;
        UpdateRangeFlagsForTarget(nullptr);
        return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Running, TEXT("NoEvaluatorCleared"));
    }

    Evaluator->EvaluateThreats(OwnerActor, Member->ThreatList);
    if (AggressionRange > 0.f)
    {
        const float AggressionRangeSq = FMath::Square(AggressionRange);
        Member->ThreatList.RemoveAllSwap(
            [OwnerLocation, AggressionRangeSq](const FThreatCandidate& Candidate)
            {
                return !IsValid(Candidate.Target) || FVector::DistSquared(OwnerLocation, Candidate.Target->GetActorLocation()) > AggressionRangeSq;
            },
            EAllowShrinking::No);
    }

    float BestScore = -FLT_MAX;
    AActor* BestTarget = nullptr;
    for (const FThreatCandidate& Candidate : Member->ThreatList)
    {
        if (Candidate.Score > BestScore)
        {
            BestScore = Candidate.Score;
            BestTarget = Candidate.Target;
        }
    }

    if (BestTarget)
    {
        Member->BestTarget = BestTarget;
        LastBestTargetTime = Now;
    }
    else
    {
        if (BestTargetGraceTime > 0.f && IsValid(Member->BestTarget) && (Now - LastBestTargetTime) < BestTargetGraceTime)
        {
            UpdateRangeFlagsForTarget(Member->BestTarget);
            return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Running, TEXT("NoThreatsGraceHold"));
        }
        Member->BestTarget = nullptr;
    }
    UpdateRangeFlagsForTarget(Member->BestTarget);

    if (Member->bDebugAI)
    {
        UE_LOG(LogSquadStateTree, Log, TEXT("SquadAI: %s threats=%d best=%s dist=%.1f atk=%.1f aggro=%.1f inAtk=%d inAggro=%d"),
            *GetNameSafe(OwnerActor),
            Member->ThreatList.Num(),
            *GetNameSafe(Member->BestTarget),
            Member->DistanceToBestTarget,
            Member->CurrentAttackRange,
            Member->CurrentAggressionRange,
            Member->bBestTargetInAttackRange ? 1 : 0,
            Member->bBestTargetInAggressionRange ? 1 : 0);
    }
    return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateThreats"), this, EStateTreeRunStatus::Running, TEXT("Evaluated"));
}

USquadTask_EvaluateLoot::USquadTask_EvaluateLoot(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = true;
}

EStateTreeRunStatus USquadTask_EvaluateLoot::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    LastUpdateTime = -1.f;
    return Tick(Context, 0.f);
}

USquadTask_BeginAttackIntent::USquadTask_BeginAttackIntent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = false;
#if WITH_EDITORONLY_DATA
    // One-shot setup task; CommitAttack controls the combat loop lifetime.
    bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus USquadTask_BeginAttackIntent::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    UAttackOrchestratorComponent* Orchestrator = OwnerActor->FindComponentByClass<UAttackOrchestratorComponent>();
    if (!Orchestrator)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Failed, TEXT("NoOrchestrator"));
    }

    FCombatAttackRequest Request;
    Request.Instigator = OwnerActor;
    Request.SourceObject = OwnerActor;
    Request.Profile = AttackProfileOverride;
    Request.TargetActor = Member ? Member->BestTarget : nullptr;
    if (!IsValid(Request.TargetActor))
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Failed, TEXT("NoValidTarget"));
    }

    ACombatWeaponActor* Weapon = FindCombatWeaponActor(OwnerActor);
    if (!Request.Profile && Weapon)
    {
        Request.Profile = Weapon->DefaultAttackProfile;
        Request.SourceObject = Weapon;
    }

    if (Weapon && !Request.WeaponObject)
    {
        // Ensure the attack ability can resolve a weapon executor.
        Request.WeaponObject = Weapon;
        if (Request.SourceObject == OwnerActor)
        {
            Request.SourceObject = Weapon;
        }
    }

    Request.BaseDamage = BaseDamage;

    if (!Request.Profile)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Failed, TEXT("NoAttackProfile"));
    }

    if (Member)
    {
        Member->LastAttackProfile = Request.Profile;
        SetDebugTask(Member, TEXT("BeginAttackIntent"));
    }

    const bool bStarted = Orchestrator->BeginAttackIntent(Request);
    if (!bStarted)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Failed, TEXT("BeginAttackIntentReturnedFalse"));
    }

    // One-shot setup task; CommitAttack keeps the loop alive.
    return LogTaskReturn(OwnerActor, Member, TEXT("BeginAttackIntent"), this, EStateTreeRunStatus::Succeeded, TEXT("IntentStarted"));
}

USquadTask_CommitAttack::USquadTask_CommitAttack(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = true;
#if WITH_EDITORONLY_DATA
    // CommitAttack should keep AttackLoop alive; ensure it's considered for completion by default.
    bConsideredForCompletion = true;
#endif
}

EStateTreeRunStatus USquadTask_CommitAttack::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    StartTime = -1.f;
    bCommitted = false;
    AttackEndTime = -1.f;
    CooldownEndTime = -1.f;

#if WITH_EDITORONLY_DATA
    if (!bConsideredForCompletion)
    {
        if (AActor* OwnerActor = GetOwnerActor(Context))
        {
            if (const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>())
            {
                if (Member->bDebugAI)
                {
                    UE_LOG(LogSquadStateTree, Warning, TEXT("SquadAI: CommitAttack not considered for completion; AttackLoop may complete every tick. Fix StateTree asset."));
                }
            }
        }
    }
#endif

    return Tick(Context, 0.f);
}

EStateTreeRunStatus USquadTask_CommitAttack::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("CommitAttack"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    if (StartTime < 0.f)
    {
        StartTime = Now;
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    SetDebugTask(Member, TEXT("CommitAttack"));
    if (Member && Now < Member->NextAttackTime)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("WaitingNextAttackTime"));
    }

    if (CommitDelay > 0.f && (Now - StartTime) < CommitDelay)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("WaitingCommitDelay"));
    }

    if (bRequireTargetInAttackRange && Member)
    {
        if (!IsValid(Member->BestTarget))
        {
            return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("NoValidTarget"));
        }

        if (Member->CurrentAttackRange > 0.f)
        {
            if (!Member->bBestTargetInAttackRange)
            {
                return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("TargetOutOfAttackRange"));
            }
        }
        else
        {
            const float AttackRange = ResolveEffectiveAttackRange(OwnerActor, Member);
            const float DistToTarget = FVector::Distance(OwnerActor->GetActorLocation(), Member->BestTarget->GetActorLocation());
            if (DistToTarget > (AttackRange + FMath::Max(0.f, AttackRangeTolerance)))
            {
                return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("TargetOutOfAttackRange"));
            }
        }
    }

    UAttackOrchestratorComponent* Orchestrator = OwnerActor->FindComponentByClass<UAttackOrchestratorComponent>();
    if (!Orchestrator)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Failed, TEXT("NoOrchestrator"));
    }

    if (!bCommitted)
    {
        if (!Orchestrator->TryCommitAttack())
        {
            return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("TryCommitAttackFalse"));
        }

        bCommitted = true;

        const float AttackDuration = [OwnerActor, Member]()
        {
            if (ACombatWeaponActor* Weapon = FindCombatWeaponActor(OwnerActor))
            {
                const float WeaponDuration = GetWeaponAttackDuration(Weapon);
                if (WeaponDuration > 0.f)
                {
                    return WeaponDuration;
                }
            }

            if (Member && Member->LastAttackProfile)
            {
                return FMath::Max(0.f, Member->LastAttackProfile->CommitWindowEnd);
            }

            return 0.f;
        }();

        const float EffectiveAttackEndTime = Now + FMath::Max(AttackDuration, FMath::Max(0.05f, MinPostCommitHold));

        float CooldownSeconds = 0.f;
        if (CooldownOverride >= 0.f)
        {
            CooldownSeconds = CooldownOverride;
        }
        else if (Member && Member->LastAttackProfile)
        {
            CooldownSeconds = Member->LastAttackProfile->Cooldown;
        }

        this->AttackEndTime = EffectiveAttackEndTime;
        CooldownEndTime = this->AttackEndTime + FMath::Max(0.f, CooldownSeconds);
        if (Member)
        {
            Member->NextAttackTime = CooldownEndTime;
        }

        if (Member && Member->bDebugAI)
        {
            UE_LOG(LogSquadStateTree, Log, TEXT("SquadAI: %s commit attack duration=%.2f cooldown=%.2f"),
                *GetNameSafe(OwnerActor),
                AttackDuration,
                CooldownSeconds);
        }
    }

    // Motion can be longer than profile estimates, so treat active weapon motion as authoritative.
    if (ACombatWeaponActor* Weapon = FindCombatWeaponActor(OwnerActor))
    {
        if (Weapon->IsMotionActive())
        {
            return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("WeaponMotionActive"));
        }
    }

    if (AttackEndTime > 0.f && Now < AttackEndTime)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("WaitingAttackEnd"));
    }

    if (CooldownEndTime > 0.f && Now < CooldownEndTime)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("WaitingCooldown"));
    }

    // Stay in the same state and start the next attack cycle without relying on state completion transitions.
    bCommitted = false;
    StartTime = Now;
    AttackEndTime = -1.f;
    CooldownEndTime = -1.f;
    return LogTaskReturn(OwnerActor, Member, TEXT("CommitAttack"), this, EStateTreeRunStatus::Running, TEXT("CycleResetForNextAttack"));
}

EStateTreeRunStatus USquadTask_EvaluateLoot::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("EvaluateLoot"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    if (UpdateInterval > 0.f && (Now - LastUpdateTime) < UpdateInterval)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("EvaluateLoot"), this, EStateTreeRunStatus::Running, TEXT("IntervalGate"));
    }
    LastUpdateTime = Now;

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("EvaluateLoot"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }

    ULootEvaluator* Evaluator = EvaluatorOverride ? EvaluatorOverride : Member->LootEvaluator;
    if (!Evaluator)
    {
        Member->LootCandidate = FLootCandidate{};
        return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateLoot"), this, EStateTreeRunStatus::Running, TEXT("NoEvaluatorCleared"));
    }

    TArray<FLootCandidate> LootCandidates;
    Evaluator->EvaluateLoot(OwnerActor, LootCandidates);

    float BestScore = -FLT_MAX;
    FLootCandidate Best;
    for (const FLootCandidate& Candidate : LootCandidates)
    {
        if (Candidate.Score > BestScore)
        {
            BestScore = Candidate.Score;
            Best = Candidate;
        }
    }

    Member->LootCandidate = Best;
    if (Member->bDebugAI)
    {
        UE_LOG(LogSquadStateTree, Log, TEXT("SquadAI: %s loot score=%.2f actor=%s"),
            *GetNameSafe(OwnerActor),
            Member->LootCandidate.Score,
            *GetNameSafe(Member->LootCandidate.LootActor));
    }
    return LogTaskReturn(OwnerActor, Member, TEXT("EvaluateLoot"), this, EStateTreeRunStatus::Running, TEXT("Evaluated"));
}

USquadTask_AimAtBestTarget::USquadTask_AimAtBestTarget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = false;
#if WITH_EDITORONLY_DATA
    // Aiming is setup work and should not complete/interrupt the attack state.
    bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus USquadTask_AimAtBestTarget::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("AimAtBestTarget"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member || !IsValid(Member->BestTarget))
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("AimAtBestTarget"), this, EStateTreeRunStatus::Failed, TEXT("NoMemberOrBestTarget"));
    }
    SetDebugTask(Member, TEXT("AimAtBestTarget"));

    ACombatWeaponActor* Weapon = FindCombatWeaponActor(OwnerActor);

    if (!Weapon)
    {
        return LogTaskReturn(OwnerActor, Member, TEXT("AimAtBestTarget"), this, EStateTreeRunStatus::Failed, TEXT("NoWeapon"));
    }

    Weapon->AimAtActor(Member->BestTarget, bSnap);
    if (Member->bDebugAI)
    {
        UE_LOG(LogSquadStateTree, Log, TEXT("SquadAI: %s aim at %s"),
            *GetNameSafe(OwnerActor),
            *GetNameSafe(Member->BestTarget));
    }
    // One-shot setup task; CommitAttack keeps the loop alive.
    return LogTaskReturn(OwnerActor, Member, TEXT("AimAtBestTarget"), this, EStateTreeRunStatus::Succeeded, TEXT("Aimed"));
}

USquadTask_MoveToSlot::USquadTask_MoveToSlot(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bShouldCallTick = true;
}

EStateTreeRunStatus USquadTask_MoveToSlot::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    SetDebugTask(Member, TEXT("MoveToSlot"));

    if (bRequireObey && !Member->bShouldObeyFormation)
    {
        Member->bIsTemporarilyOutOfFormation = false;
        if (APawn* Pawn = Cast<APawn>(OwnerActor))
        {
            if (AController* Controller = Pawn->GetController())
            {
                Controller->StopMovement();
            }
        }
        return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("EnterSkipNotObeying"));
    }

    Member->bIsTemporarilyOutOfFormation = false;
    return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("Enter"));
}

EStateTreeRunStatus USquadTask_MoveToSlot::Tick(FStateTreeExecutionContext& Context, const float DeltaTime)
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogTaskReturn(nullptr, nullptr, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoOwnerActor"));
    }

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogTaskReturn(OwnerActor, nullptr, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Failed, TEXT("NoMember"));
    }
    SetDebugTask(Member, TEXT("MoveToSlot"));

    if (bRequireObey && !Member->bShouldObeyFormation)
    {
        Member->bIsTemporarilyOutOfFormation = false;
        if (APawn* Pawn = Cast<APawn>(OwnerActor))
        {
            if (AController* Controller = Pawn->GetController())
            {
                Controller->StopMovement();
            }
        }
        return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("TickSkipNotObeying"));
    }

    const FVector OwnerLocation = OwnerActor->GetActorLocation();
    FVector Target = Member->SlotWorldPos;
    bool bOutOfWay = false;

    if (bAllowOutOfWayWhenAttacking && MaxOutOfWayDistance > 0.f && IsValid(Member->BestTarget))
    {
        const float AttackRange = ResolveEffectiveAttackRange(OwnerActor, Member);
        if (AttackRange > KINDA_SMALL_NUMBER)
        {
            const FVector TargetLocation = Member->BestTarget->GetActorLocation();
            const float CurrentDistToTarget = FVector::Distance(OwnerLocation, TargetLocation);
            const float DesiredDistance = Member->CurrentDesiredAttackDistance > 0.f
                ? Member->CurrentDesiredAttackDistance
                : FMath::Max(0.f, AttackRange - FMath::Max(0.f, AttackRangeBuffer));

            if (CurrentDistToTarget > DesiredDistance)
            {
                const float NeedAdvance = CurrentDistToTarget - DesiredDistance;
                const FVector AdvanceDir = (TargetLocation - OwnerLocation).GetSafeNormal2D();
                if (!AdvanceDir.IsNearlyZero())
                {
                    FVector Candidate = OwnerLocation + AdvanceDir * FMath::Min(NeedAdvance, MaxOutOfWayDistance);

                    // Clamp candidate around slot to keep this as a temporary deviation.
                    const FVector SlotLocation = Member->SlotWorldPos;
                    FVector OffsetFromSlot = Candidate - SlotLocation;
                    if (OffsetFromSlot.SizeSquared2D() > FMath::Square(MaxOutOfWayDistance))
                    {
                        OffsetFromSlot = OffsetFromSlot.GetSafeNormal2D() * MaxOutOfWayDistance;
                        Candidate = SlotLocation + FVector(OffsetFromSlot.X, OffsetFromSlot.Y, 0.f);
                    }

                    Target = Candidate;
                    bOutOfWay = true;
                }
            }
        }
    }

    Member->bIsTemporarilyOutOfFormation = bOutOfWay;
    const float Radius = FMath::Max(1.f, AcceptanceRadius);
    const float DistSq = FVector::DistSquared(OwnerLocation, Target);

    if (DistSq <= FMath::Square(Radius))
    {
        if (!bOutOfWay)
        {
            if (APawn* Pawn = Cast<APawn>(OwnerActor))
            {
                if (AController* Controller = Pawn->GetController())
                {
                    Controller->StopMovement();
                }
            }
            // Keep movement task alive while holding slot so parent combat state does not complete unexpectedly.
            return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("HoldSlot"));
        }
        return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("HoldOutOfWay"));
    }

    if (APawn* Pawn = Cast<APawn>(OwnerActor))
    {
        if (AController* Controller = Pawn->GetController())
        {
            if (AAIController* AIController = Cast<AAIController>(Controller))
            {
                AIController->MoveToLocation(Target, Radius);
            }
            else
            {
                UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Target);
            }
        }
    }

    return LogTaskReturn(OwnerActor, Member, TEXT("MoveToSlot"), this, EStateTreeRunStatus::Running, TEXT("Moving"));
}

