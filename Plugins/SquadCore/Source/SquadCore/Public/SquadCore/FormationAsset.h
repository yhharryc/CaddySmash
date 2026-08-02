#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SquadCore/SquadTypes.h"
#include "FormationAsset.generated.h"

UCLASS(BlueprintType)
class SQUADCORE_API UFormationAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
    TArray<FSquadSlot> Slots;

    UFUNCTION(BlueprintCallable, Category="Squad")
    bool GetSlotOffset(int32 SlotIndex, FVector& OutOffset) const;
};
