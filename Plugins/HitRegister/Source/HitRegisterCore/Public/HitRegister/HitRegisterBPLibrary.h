#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HitRegisterTypes.h"
#include "HitRegisterBPLibrary.generated.h"

class UHitRegisterPipeline;

UCLASS()
class HITREGISTERCORE_API UHitRegisterBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Load the default pipeline from settings (returns null if not set or not loaded). */
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    static UHitRegisterPipeline* GetDefaultPipeline();

    /** Execute with explicit pipeline (recommended). */
    UFUNCTION(BlueprintCallable, Category="HitRegister", meta=(WorldContext="WorldContextObject"))
    static bool ExecuteHitRegister(UObject* WorldContextObject, const FAttackRequest& Attack, const FHitResult& Hit, UHitRegisterPipeline* Pipeline, UPARAM(ref) FHitRegisterContext& OutContext);

    /** Execute using default pipeline from settings. */
    UFUNCTION(BlueprintCallable, Category="HitRegister", meta=(WorldContext="WorldContextObject"))
    static bool ExecuteHitRegisterDefault(UObject* WorldContextObject, const FAttackRequest& Attack, const FHitResult& Hit, UPARAM(ref) FHitRegisterContext& OutContext);
};
