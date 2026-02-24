#pragma once

#include "CoreMinimal.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_ApplyDamageViaInterface.generated.h"

/**
 * Calls IDamageApplier::ApplyDamage on the hit actor (or any of its components).
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class HITREGISTERCORE_API UHRN_ApplyDamageViaInterface : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    /** If true, Stop when no applier found; otherwise just Continue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bStopIfNoApplier = true;

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};
