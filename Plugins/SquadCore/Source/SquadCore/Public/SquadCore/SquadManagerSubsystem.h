#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SquadCore/SquadTypes.h"
#include "SquadManagerSubsystem.generated.h"

class UFormationAsset;
class USquadSlotAssignmentPolicy;

UCLASS()
class SQUADCORE_API USquadManagerSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Squad")
    void SetFormationAsset(UFormationAsset* InFormation);

    UFUNCTION(BlueprintCallable, Category="Squad")
    void SetSlotAssignmentPolicy(USquadSlotAssignmentPolicy* InPolicy);

    UFUNCTION(BlueprintCallable, Category="Squad")
    void SetFormationLeader(AActor* InLeader);

    UFUNCTION(BlueprintPure, Category="Squad")
    AActor* GetFormationLeader() const { return FormationLeader.Get(); }

    UFUNCTION(BlueprintCallable, Category="Squad")
    int32 RegisterMember(AActor* Member);

    UFUNCTION(BlueprintCallable, Category="Squad")
    void UnregisterMember(AActor* Member);

    UFUNCTION(BlueprintPure, Category="Squad")
    bool GetAssignedSlot(AActor* Member, int32& OutSlotId) const;

    UFUNCTION(BlueprintCallable, Category="Squad")
    bool GetSlotWorldLocation(int32 SlotId, FVector& OutLocation) const;

    UFUNCTION(BlueprintCallable, Category="Squad")
    bool GetSlotWorldTransform(int32 SlotId, FTransform& OutTransform) const;

private:
    FVector ResolveSlotOffset(int32 SlotId) const;

    UPROPERTY()
    TObjectPtr<UFormationAsset> Formation;

    UPROPERTY()
    TObjectPtr<USquadSlotAssignmentPolicy> SlotAssignmentPolicy;

    UPROPERTY()
    TWeakObjectPtr<AActor> FormationLeader;

    TMap<TWeakObjectPtr<AActor>, int32> MemberToSlot;
    TSet<int32> OccupiedSlots;
};
