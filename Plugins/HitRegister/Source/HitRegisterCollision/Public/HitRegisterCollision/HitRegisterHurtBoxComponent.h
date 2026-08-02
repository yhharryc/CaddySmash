#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameplayTagContainer.h"
#include "HitRegisterCollisionTypes.h"
#include "HitRegisterHurtBoxComponent.generated.h"

UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class HITREGISTERCOLLISION_API UHitRegisterHurtBoxComponent : public UBoxComponent
{
    GENERATED_BODY()

public:
    UHitRegisterHurtBoxComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FName HurtBoxId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FGameplayTagContainer Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float DamageMultiplier = 1.f;
};
