#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SquadCore/SquadTypes.h"
#include "SquadSlotAssignmentPolicy.generated.h"

UCLASS(BlueprintType, Abstract)
class SQUADCORE_API USquadSlotAssignmentPolicy : public UDataAsset
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category="Squad")
    int32 SelectSlot(AActor* Member, const TArray<FSquadSlot>& Slots, const TArray<int32>& OccupiedSlots) const;
    virtual int32 SelectSlot_Implementation(AActor* Member, const TArray<FSquadSlot>& Slots, const TArray<int32>& OccupiedSlots) const;
};

UCLASS(BlueprintType)
class SQUADCORE_API USquadSlotAssignmentPolicy_FirstFree : public USquadSlotAssignmentPolicy
{
    GENERATED_BODY()

public:
    virtual int32 SelectSlot_Implementation(AActor* Member, const TArray<FSquadSlot>& Slots, const TArray<int32>& OccupiedSlots) const override;
};
