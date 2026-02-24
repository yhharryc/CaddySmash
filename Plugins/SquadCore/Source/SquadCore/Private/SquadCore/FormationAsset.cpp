#include "SquadCore/FormationAsset.h"

bool UFormationAsset::GetSlotOffset(int32 SlotIndex, FVector& OutOffset) const
{
    if (!Slots.IsValidIndex(SlotIndex))
    {
        return false;
    }

    OutOffset = Slots[SlotIndex].Offset;
    return true;
}
