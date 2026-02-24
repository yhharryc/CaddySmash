#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HitRegisterTeamInterface.h"
#include "HitRegisterTeamComponent.generated.h"

/** Simple team component for projects without a custom team system. */
UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class HITREGISTERCOLLISION_API UHitRegisterTeamComponent : public UActorComponent, public IHitRegisterTeamAgent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Team")
    int32 TeamId = 0;

    virtual int32 GetTeamId_Implementation() const override { return TeamId; }
};
