#include "SquadCore/SquadSlotAssignmentPolicy.h"

int32 USquadSlotAssignmentPolicy::SelectSlot_Implementation(AActor* Member, const TArray<FSquadSlot>& Slots, const TArray<int32>& OccupiedSlots) const
{
    return INDEX_NONE;
}

int32 USquadSlotAssignmentPolicy_FirstFree::SelectSlot_Implementation(AActor* Member, const TArray<FSquadSlot>& Slots, const TArray<int32>& OccupiedSlots) const
{
    for (int32 Index = 0; Index < Slots.Num(); ++Index)
    {
        if (!OccupiedSlots.Contains(Index))
        {
            return Index;
        }
    }
    return INDEX_NONE;
}
