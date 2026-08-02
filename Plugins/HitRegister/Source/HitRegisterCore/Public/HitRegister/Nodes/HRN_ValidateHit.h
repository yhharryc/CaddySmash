#pragma once

#include "CoreMinimal.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_ValidateHit.generated.h"

UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class HITREGISTERCORE_API UHRN_ValidateHit : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    /** If true, requires a damage applier to be found on the hit actor (actor or any component). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bRequireDamageApplier = true;

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};
