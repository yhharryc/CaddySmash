#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitRegisterTypes.h"
#include "HitRegisterInterfaces.generated.h"

/**
 * Optional: implemented by an Actor or Component to receive hit events (even if damage ends up 0).
 */
UINTERFACE(BlueprintType)
class HITREGISTERCORE_API UHitReceiver : public UInterface
{
    GENERATED_BODY()
};

class HITREGISTERCORE_API IHitReceiver
{
    GENERATED_BODY()

public:
    /** Return false to reject the hit and stop the pipeline. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    bool ShouldAcceptHit(UPARAM(ref) FHitRegisterContext& Context);

    /** Always called when a hit is confirmed (after validation). */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    void OnHitConfirmed(const FHitRegisterContext& Context);

    /** Called after damage was applied (even if 0, you decide in adapter). */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    void OnPostDamage(const FHitRegisterContext& Context);
};

/**
 * Implemented by an Actor or Component that can apply damage described in Context.
 * Core does not care how (GAS GE, custom stats, etc.).
 */
UINTERFACE(BlueprintType)
class HITREGISTERCORE_API UDamageApplier : public UInterface
{
    GENERATED_BODY()
};

class HITREGISTERCORE_API IDamageApplier
{
    GENERATED_BODY()

public:
    /** Return true if damage application succeeded. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    bool ApplyDamage(UPARAM(ref) FHitRegisterContext& Context);
};
