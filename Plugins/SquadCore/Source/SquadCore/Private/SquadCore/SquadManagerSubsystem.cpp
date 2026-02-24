#include "SquadCore/SquadManagerSubsystem.h"

#include "SquadCore/FormationAsset.h"
#include "SquadCore/SquadSlotAssignmentPolicy.h"

void USquadManagerSubsystem::SetFormationAsset(UFormationAsset* InFormation)
{
    Formation = InFormation;
}

void USquadManagerSubsystem::SetSlotAssignmentPolicy(USquadSlotAssignmentPolicy* InPolicy)
{
    SlotAssignmentPolicy = InPolicy;
}

void USquadManagerSubsystem::SetFormationLeader(AActor* InLeader)
{
    FormationLeader = InLeader;
}

int32 USquadManagerSubsystem::RegisterMember(AActor* Member)
{
    if (!Member)
    {
        return INDEX_NONE;
    }

    if (const int32* Existing = MemberToSlot.Find(Member))
    {
        return *Existing;
    }

    int32 SelectedSlot = INDEX_NONE;
    if (Formation)
    {
        if (SlotAssignmentPolicy)
        {
            TArray<int32> OccupiedArray;
            OccupiedArray.Reserve(OccupiedSlots.Num());
            for (const int32 Slot : OccupiedSlots)
            {
                OccupiedArray.Add(Slot);
            }
            SelectedSlot = SlotAssignmentPolicy->SelectSlot(Member, Formation->Slots, OccupiedArray);
        }
        else
        {
            for (int32 Index = 0; Index < Formation->Slots.Num(); ++Index)
            {
                if (!OccupiedSlots.Contains(Index))
                {
                    SelectedSlot = Index;
                    break;
                }
            }
        }
    }

    if (SelectedSlot == INDEX_NONE)
    {
        SelectedSlot = 0;
    }

    MemberToSlot.Add(Member, SelectedSlot);
    OccupiedSlots.Add(SelectedSlot);
    return SelectedSlot;
}

void USquadManagerSubsystem::UnregisterMember(AActor* Member)
{
    if (!Member)
    {
        return;
    }

    int32 SlotId = INDEX_NONE;
    if (MemberToSlot.RemoveAndCopyValue(Member, SlotId))
    {
        OccupiedSlots.Remove(SlotId);
    }
}

bool USquadManagerSubsystem::GetAssignedSlot(AActor* Member, int32& OutSlotId) const
{
    if (!Member)
    {
        return false;
    }
    if (const int32* Found = MemberToSlot.Find(Member))
    {
        OutSlotId = *Found;
        return true;
    }
    return false;
}

bool USquadManagerSubsystem::GetSlotWorldLocation(int32 SlotId, FVector& OutLocation) const
{
    FVector Offset = ResolveSlotOffset(SlotId);
    if (AActor* Leader = FormationLeader.Get())
    {
        const FTransform LeaderTransform = Leader->GetActorTransform();
        OutLocation = LeaderTransform.TransformPosition(Offset);
        return true;
    }

    OutLocation = Offset;
    return false;
}

bool USquadManagerSubsystem::GetSlotWorldTransform(int32 SlotId, FTransform& OutTransform) const
{
    FVector Offset = ResolveSlotOffset(SlotId);
    if (AActor* Leader = FormationLeader.Get())
    {
        const FTransform LeaderTransform = Leader->GetActorTransform();
        OutTransform = FTransform(LeaderTransform.GetRotation(), LeaderTransform.TransformPosition(Offset), LeaderTransform.GetScale3D());
        return true;
    }

    OutTransform = FTransform(FRotator::ZeroRotator, Offset);
    return false;
}

FVector USquadManagerSubsystem::ResolveSlotOffset(int32 SlotId) const
{
    if (!Formation)
    {
        return FVector::ZeroVector;
    }

    FVector Offset = FVector::ZeroVector;
    if (Formation->GetSlotOffset(SlotId, Offset))
    {
        return Offset;
    }

    return FVector::ZeroVector;
}
