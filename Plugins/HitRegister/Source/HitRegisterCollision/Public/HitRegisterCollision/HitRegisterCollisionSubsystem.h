#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HitRegister/HitRegisterTypes.h"
#include "HitRegisterCollisionTypes.h"
#include "HitRegisterCollisionSubsystem.generated.h"

class UHitRegisterPipeline;
class UHitRegisterTargetingProfile;
class AActor;

UCLASS()
class HITREGISTERCOLLISION_API UHitRegisterCollisionSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void FilterCandidates(const FAttackRequest& Attack, const FHitCandidateBatch& InBatch, const UHitRegisterTargetingProfile* TargetingProfile, const FHitRegisterDedupeSettings& Settings, FHitCandidateBatch& OutBatch);

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void FilterCandidatesSimple(const FHitCandidateBatch& InBatch, const FHitRegisterDedupeSettings& Settings, FHitCandidateBatch& OutBatch);

    /**
     * Execute pipeline for every candidate that passed filtering.
     * OutContexts includes both success and stopped results so callers can drive UI/telemetry from one stream.
     */
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void ExecuteForCandidates(const FAttackRequest& Attack, UHitRegisterPipeline* Pipeline, const FHitCandidateBatch& Batch, TArray<FHitRegisterContext>& OutContexts);

    /** Convenience: filter (targeting + dedupe) then execute in one call. */
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void FilterAndExecuteCandidates(const FAttackRequest& Attack, const FHitCandidateBatch& InBatch, const UHitRegisterTargetingProfile* TargetingProfile, const FHitRegisterDedupeSettings& Settings, UHitRegisterPipeline* Pipeline, TArray<FHitRegisterContext>& OutContexts);

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void ClearDedupeForAttack(int32 AttackId, AActor* Instigator);

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void ClearAllDedupe();

private:
    TMap<FHitDedupeKey, float> LastHitTimeByKey;
};
