#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SquadCore/SquadTypes.h"
#include "SquadMemberComponent.generated.h"

class UCompliancePolicy;
class UThreatEvaluator;
class ULootEvaluator;
class UAttackProfile;

UCLASS(ClassGroup=(Squad), meta=(BlueprintSpawnableComponent))
class SQUADCORE_API USquadMemberComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USquadMemberComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<UCompliancePolicy> CompliancePolicy = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<UThreatEvaluator> ThreatEvaluator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<ULootEvaluator> LootEvaluator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    ELootPolicy LootPolicy = ELootPolicy::OnlySafe;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    int32 SlotId = INDEX_NONE;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    FVector SlotWorldPos = FVector::ZeroVector;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    bool bShouldObeyFormation = true;

    /** True while AI is temporarily leaving formation to improve attack position. */
    UPROPERTY(BlueprintReadWrite, Category="Squad|Movement")
    bool bIsTemporarilyOutOfFormation = false;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    float PressureValue = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    TArray<FThreatCandidate> ThreatList;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    TObjectPtr<AActor> BestTarget = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="Squad")
    FLootCandidate LootCandidate;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    TObjectPtr<UAttackProfile> LastAttackProfile = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    float NextAttackTime = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    float CurrentAttackRange = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    float CurrentAggressionRange = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    float CurrentDesiredAttackDistance = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    float DistanceToBestTarget = 0.f;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    bool bBestTargetInAttackRange = false;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Combat")
    bool bBestTargetInAggressionRange = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDebugAI = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|AI")
    bool bAllowStateTreeWhenLeader = false;

    UPROPERTY(BlueprintReadWrite, Category="Squad|Debug")
    FName DebugLastTask = NAME_None;
};
