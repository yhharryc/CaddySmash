#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SquadCore/SquadTypes.h"
#include "ThreatEvaluator.generated.h"

UCLASS(BlueprintType, Blueprintable)
class SQUADCORE_API UThreatEvaluator : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TSubclassOf<AActor> ThreatClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float MaxRange = 1200.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float DistanceWeight = 1.f;

    UFUNCTION(BlueprintNativeEvent, Category="Squad")
    void EvaluateThreats(AActor* Source, TArray<FThreatCandidate>& OutThreats) const;
    virtual void EvaluateThreats_Implementation(AActor* Source, TArray<FThreatCandidate>& OutThreats) const;
};
