#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PressureComponent.generated.h"

class USquadMemberComponent;

UCLASS(ClassGroup=(Squad), meta=(BlueprintSpawnableComponent))
class SQUADCORE_API UPressureComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPressureComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float UpdateInterval = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float QueryRadius = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float ThreatWeight = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float MaxPressure = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TSubclassOf<AActor> ThreatClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    bool bAutoUpdate = true;

    UPROPERTY(BlueprintReadOnly, Category="Squad")
    float PressureValue = 0.f;

    UFUNCTION(BlueprintCallable, Category="Squad")
    void UpdatePressure();

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle UpdateTimerHandle;
    void UpdatePressureInternal();
};
