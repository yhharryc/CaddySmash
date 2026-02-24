#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeConditionBlueprintBase.h"
#include "SquadStateTreeConditions.generated.h"

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_HasBestTarget : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_HasBestTarget(const FObjectInitializer& ObjectInitializer);

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_NoBestTarget : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_NoBestTarget(const FObjectInitializer& ObjectInitializer);

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_AllowStateTreeControl : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_AllowStateTreeControl(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    bool bAllowLeader = false;

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_AttackReady : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_AttackReady(const FObjectInitializer& ObjectInitializer);

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_TargetInAttackRange : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_TargetInAttackRange(const FObjectInitializer& ObjectInitializer);

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

UCLASS(BlueprintType)
class SQUADCORESTATETREEADAPTER_API USquadCond_TargetOutOfAttackRange : public UStateTreeConditionBlueprintBase
{
    GENERATED_BODY()

public:
    USquadCond_TargetOutOfAttackRange(const FObjectInitializer& ObjectInitializer);

protected:
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};
