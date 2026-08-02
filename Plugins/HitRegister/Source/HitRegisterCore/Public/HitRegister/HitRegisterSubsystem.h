#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HitRegisterTypes.h"
#include "HitRegisterPipeline.h"
#include "HitRegisterSubsystem.generated.h"

UCLASS()
class HITREGISTERCORE_API UHitRegisterSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    /** Execute a hit registration pipeline. Returns false if stopped early (miss/invalid/rejected/failed apply). */
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    bool ExecuteHitRegister(const FAttackRequest& Attack, const FHitResult& Hit, UHitRegisterPipeline* Pipeline, UPARAM(ref) FHitRegisterContext& OutContext);
};
