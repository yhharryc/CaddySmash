#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HitRegisterTypes.h"
#include "HitRegisterNode.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class HITREGISTERCORE_API UHitRegisterNode : public UObject
{
    GENERATED_BODY()

public:
    /** Return Continue/Stop to gate the pipeline. */
    UFUNCTION(BlueprintNativeEvent, Category="HitRegister")
    EHitNodeResult Execute(UPARAM(ref) FHitRegisterContext& Context);
    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) { return EHitNodeResult::Continue; }
};
