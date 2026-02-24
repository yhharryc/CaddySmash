#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitRegisterTeamInterface.generated.h"

UINTERFACE(BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterTeamAgent : public UInterface
{
    GENERATED_BODY()
};

class HITREGISTERCOLLISION_API IHitRegisterTeamAgent
{
    GENERATED_BODY()

public:
    /** Return a stable team/faction id. Use INDEX_NONE for unassigned. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    int32 GetTeamId() const;
};
