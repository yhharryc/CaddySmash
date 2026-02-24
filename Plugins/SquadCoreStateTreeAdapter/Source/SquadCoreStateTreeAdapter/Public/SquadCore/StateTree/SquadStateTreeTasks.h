#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "SquadStateTreeTasks.generated.h"

class UAttackProfile;
class UAttackOrchestratorComponent;
class UCompliancePolicy;
class ULootEvaluator;
class UThreatEvaluator;

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_AssignSlot : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_AssignSlot(const FObjectInitializer& ObjectInitializer);

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_UpdateSlotWorldPos : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_UpdateSlotWorldPos(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    bool bOnlyWhenObeying = false;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_ComputeCompliance : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_ComputeCompliance(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<UCompliancePolicy> PolicyOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float HealthRatioOverride = 1.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_EvaluateThreats : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_EvaluateThreats(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<UThreatEvaluator> EvaluatorOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float UpdateInterval = 0.3f;

    /** Grace period to keep the last BestTarget when evaluations temporarily return none. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float BestTargetGraceTime = 0.35f;

    /** If >=0, use this as aggression range instead of deriving from attack range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float AggressionRangeOverride = -1.f;

    /** Aggression range = AttackRange * Multiplier (when no override). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float AggressionRangeMultiplier = 1.75f;

    /** Lower bound for aggression range when attack range is small or unavailable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float MinAggressionRange = 300.f;

    /** Hysteresis used when determining whether target is in attack range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float AttackRangeHysteresis = 20.f;

    /** Hysteresis used when determining whether target is in aggression range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float AggressionRangeHysteresis = 80.f;

    /** Desired distance to hold from target once in combat. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float DesiredAttackBuffer = 40.f;

    UPROPERTY(Transient)
    float LastUpdateTime = -1.f;

    UPROPERTY(Transient)
    float LastBestTargetTime = -1.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_EvaluateLoot : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_EvaluateLoot(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<ULootEvaluator> EvaluatorOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float UpdateInterval = 0.5f;

    UPROPERTY(Transient)
    float LastUpdateTime = -1.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_BeginAttackIntent : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_BeginAttackIntent(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<UAttackProfile> AttackProfileOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float BaseDamage = 10.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_CommitAttack : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_CommitAttack(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float CommitDelay = 0.05f;

    /** Keep task alive for at least this long after sending commit to avoid same-frame complete/re-enter loops. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float MinPostCommitHold = 0.05f;

    /** If >= 0, overrides AttackProfile cooldown. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float CooldownOverride = -1.f;

    /** Deprecated compatibility flag: task now always waits until cooldown end to avoid re-entry spam. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bWaitForCooldownBeforeSucceed = true;

    /** If true, attack commit waits until target is inside the effective attack range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bRequireTargetInAttackRange = true;

    /** Extra tolerance to avoid edge jitter when checking attack range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float AttackRangeTolerance = 15.f;

    UPROPERTY(Transient)
    float StartTime = -1.f;

    UPROPERTY(Transient)
    bool bCommitted = false;

    UPROPERTY(Transient)
    float AttackEndTime = -1.f;

    UPROPERTY(Transient)
    float CooldownEndTime = -1.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_AimAtBestTarget : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_AimAtBestTarget(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bSnap = true;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadTask_MoveToSlot : public UStateTreeTaskBlueprintBase
{
    GENERATED_BODY()

public:
    USquadTask_MoveToSlot(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float AcceptanceRadius = 80.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    bool bRequireObey = true;

    /** Allow temporary movement away from slot while trying to enter attack range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    bool bAllowOutOfWayWhenAttacking = true;

    /** Maximum distance AI can deviate from current slot while going out-of-way. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float MaxOutOfWayDistance = 220.f;

    /** Small buffer to avoid stepping to exact attack range edge every tick. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Combat")
    float AttackRangeBuffer = 40.f;

protected:
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) override;
};
