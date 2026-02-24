#include "SquadCore/StateTree/SquadStateTreeConditions.h"

#include "SquadCore/StateTree/SquadStateTreeLog.h"
#include "SquadCore/SquadMemberComponent.h"
#include "SquadCore/SquadManagerSubsystem.h"
#include "StateTreeExecutionContext.h"
#include "VisualLogger/VisualLogger.h"

namespace
{
    static bool LogConditionResult(
        AActor* OwnerActor,
        const USquadMemberComponent* Member,
        const TCHAR* ConditionName,
        const bool bResult,
        const TCHAR* Detail)
    {
        UE_VLOG_UELOG(
            OwnerActor,
            LogSquadStateTree,
            Verbose,
            TEXT("[STCond:%s] Result=%d Detail=%s"),
            ConditionName,
            bResult ? 1 : 0,
            Detail ? Detail : TEXT(""));

        if (Member && Member->bDebugAI)
        {
            UE_LOG(
                LogSquadStateTree,
                Verbose,
                TEXT("[STCond:%s] Result=%d Detail=%s"),
                ConditionName,
                bResult ? 1 : 0,
                Detail ? Detail : TEXT(""));
        }

        return bResult;
    }
}

USquadCond_HasBestTarget::USquadCond_HasBestTarget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_HasBestTarget::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("HasBestTarget"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    const bool bResult = Member && IsValid(Member->BestTarget);
    return LogConditionResult(OwnerActor, Member, TEXT("HasBestTarget"), bResult, bResult ? TEXT("BestTargetValid") : TEXT("BestTargetNull"));
}

USquadCond_NoBestTarget::USquadCond_NoBestTarget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_NoBestTarget::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("NoBestTarget"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    const bool bResult = !Member || !IsValid(Member->BestTarget);
    return LogConditionResult(OwnerActor, Member, TEXT("NoBestTarget"), bResult, bResult ? TEXT("BestTargetMissing") : TEXT("BestTargetValid"));
}

USquadCond_AllowStateTreeControl::USquadCond_AllowStateTreeControl(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_AllowStateTreeControl::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("AllowStateTreeControl"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    const UWorld* World = OwnerActor->GetWorld();
    const USquadManagerSubsystem* Manager = World ? World->GetSubsystem<USquadManagerSubsystem>() : nullptr;
    if (!Manager)
    {
        return LogConditionResult(OwnerActor, Member, TEXT("AllowStateTreeControl"), true, TEXT("NoManagerAllow"));
    }

    const AActor* Leader = Manager->GetFormationLeader();
    if (!Leader)
    {
        return LogConditionResult(OwnerActor, Member, TEXT("AllowStateTreeControl"), true, TEXT("NoLeaderAllow"));
    }

    if (Leader != OwnerActor)
    {
        return LogConditionResult(OwnerActor, Member, TEXT("AllowStateTreeControl"), true, TEXT("NotLeaderAllow"));
    }

    if (Member && Member->bAllowStateTreeWhenLeader)
    {
        return LogConditionResult(OwnerActor, Member, TEXT("AllowStateTreeControl"), true, TEXT("LeaderOverrideAllow"));
    }

    return LogConditionResult(OwnerActor, Member, TEXT("AllowStateTreeControl"), bAllowLeader, bAllowLeader ? TEXT("ConfigAllowLeader") : TEXT("ConfigBlockLeader"));
}

USquadCond_AttackReady::USquadCond_AttackReady(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_AttackReady::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("AttackReady"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogConditionResult(OwnerActor, nullptr, TEXT("AttackReady"), false, TEXT("NoMember"));
    }

    const UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    const bool bResult = Now >= Member->NextAttackTime;
    return LogConditionResult(OwnerActor, Member, TEXT("AttackReady"), bResult, bResult ? TEXT("NowGTEAttackTime") : TEXT("CooldownNotReady"));
}

USquadCond_TargetInAttackRange::USquadCond_TargetInAttackRange(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_TargetInAttackRange::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("TargetInAttackRange"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogConditionResult(OwnerActor, nullptr, TEXT("TargetInAttackRange"), false, TEXT("NoMember"));
    }

    const bool bHasTarget = IsValid(Member->BestTarget);
    const bool bResult = bHasTarget && Member->bBestTargetInAttackRange;
    return LogConditionResult(
        OwnerActor,
        Member,
        TEXT("TargetInAttackRange"),
        bResult,
        bResult ? TEXT("InAttackRange") : (bHasTarget ? TEXT("TargetOutOfRange") : TEXT("NoTarget")));
}

USquadCond_TargetOutOfAttackRange::USquadCond_TargetOutOfAttackRange(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool USquadCond_TargetOutOfAttackRange::TestCondition(FStateTreeExecutionContext& Context) const
{
    AActor* OwnerActor = GetOwnerActor(Context);
    if (!OwnerActor)
    {
        return LogConditionResult(nullptr, nullptr, TEXT("TargetOutOfAttackRange"), false, TEXT("NoOwnerActor"));
    }

    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (!Member)
    {
        return LogConditionResult(OwnerActor, nullptr, TEXT("TargetOutOfAttackRange"), true, TEXT("NoMember"));
    }

    const bool bHasTarget = IsValid(Member->BestTarget);
    const bool bResult = !bHasTarget || !Member->bBestTargetInAttackRange;
    return LogConditionResult(
        OwnerActor,
        Member,
        TEXT("TargetOutOfAttackRange"),
        bResult,
        bResult ? (bHasTarget ? TEXT("TargetOutOfRange") : TEXT("NoTarget")) : TEXT("InAttackRange"));
}
