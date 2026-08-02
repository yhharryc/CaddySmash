#pragma once

#include "CoreMinimal.h"
#include "AttackTypes.generated.h"

class AActor;
class UWorld;
class UAttackProfile;

USTRUCT(BlueprintType)
struct COMBATCORE_API FCombatAttackRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<AActor> Instigator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<UObject> SourceObject = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<UAttackProfile> Profile = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<UObject> WeaponObject = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<AActor> TargetActor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float BaseDamage = 10.f;
};

USTRUCT(BlueprintType)
struct COMBATCORE_API FCombatAttackExecutionParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float EffectiveAttackRange = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bOverrideThrustDistance = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float ThrustDistance = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bOverrideHitscanRange = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float HitscanRange = 0.f;
};

USTRUCT(BlueprintType)
struct COMBATCORE_API FCombatAttackContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    FCombatAttackRequest Request;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    FCombatAttackExecutionParams ExecutionParams;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TObjectPtr<UWorld> World = nullptr;
};
