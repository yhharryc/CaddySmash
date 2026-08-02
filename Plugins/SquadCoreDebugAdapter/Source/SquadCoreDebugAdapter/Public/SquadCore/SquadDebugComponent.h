#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebugFramework/DebugFrameworkProvider.h"
#include "SquadDebugComponent.generated.h"

class UUserWidget;
class UWidgetComponent;
class USquadDebugWidget;

USTRUCT(BlueprintType)
struct FSquadDebugSnapshot
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<AActor> Owner = nullptr;

    UPROPERTY(BlueprintReadOnly)
    FName DebugLastTask = NAME_None;

    UPROPERTY(BlueprintReadOnly)
    int32 SlotId = INDEX_NONE;

    UPROPERTY(BlueprintReadOnly)
    FVector SlotWorldPos = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly)
    bool bShouldObeyFormation = true;

    UPROPERTY(BlueprintReadOnly)
    bool bTemporarilyOutOfFormation = false;

    UPROPERTY(BlueprintReadOnly)
    float PressureValue = 0.f;

    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<AActor> BestTarget = nullptr;

    UPROPERTY(BlueprintReadOnly)
    int32 ThreatCount = 0;

    UPROPERTY(BlueprintReadOnly)
    float LootScore = 0.f;

    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<AActor> LootActor = nullptr;

    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<UObject> AttackProfile = nullptr;

    UPROPERTY(BlueprintReadOnly)
    float AttackRange = 0.f;

    UPROPERTY(BlueprintReadOnly)
    float AggressionRange = 0.f;

    UPROPERTY(BlueprintReadOnly)
    bool bInAttackRange = false;

    UPROPERTY(BlueprintReadOnly)
    bool bInAggressionRange = false;

    UPROPERTY(BlueprintReadOnly)
    float NextAttackTime = 0.f;

    UPROPERTY(BlueprintReadOnly)
    float CooldownRemaining = 0.f;

    UPROPERTY(BlueprintReadOnly)
    float DistanceToLeader = 0.f;

    UPROPERTY(BlueprintReadOnly)
    float DistanceToTarget = 0.f;
};

UCLASS(ClassGroup=(Squad), meta=(BlueprintSpawnableComponent))
class SQUADCOREDEBUGADAPTER_API USquadDebugComponent : public UActorComponent, public IDebugFrameworkProvider
{
    GENERATED_BODY()

public:
    USquadDebugComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    float UpdateInterval = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawWorld = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawText3D = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bUseWidget = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    TSubclassOf<UUserWidget> WidgetClass = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FVector2D WidgetDrawSize = FVector2D(260.f, 140.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FVector WidgetOffset = FVector(0.f, 0.f, 120.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bWidgetDrawAtDesiredSize = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bWidgetScreenSpace = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawFormation = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawTargeting = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawAttackRange = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bDrawLeaderLine = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    float TextVerticalOffset = 120.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    float LineThickness = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FColor FormationColor = FColor::Green;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FColor TargetColor = FColor::Red;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FColor LeaderColor = FColor::Cyan;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FColor TextColor = FColor::White;

    UFUNCTION(BlueprintCallable, Category="Squad|Debug")
    FSquadDebugSnapshot GetSnapshot() const { return Snapshot; }

    virtual FName GetDebugPanelId_Implementation() const override;
    virtual FText GetDebugPanelTitle_Implementation() const override;
    virtual FName GetDebugToolId_Implementation() const override;
    virtual FText GetDebugToolTitle_Implementation() const override;
    virtual int32 GetDebugSortOrder_Implementation() const override;
    virtual void GatherDebugRows_Implementation(TArray<FDebugFrameworkPanelRow>& OutRows) const override;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    float LastUpdateTime = -1.f;

    UPROPERTY(Transient)
    FSquadDebugSnapshot Snapshot;

    UPROPERTY(Transient)
    TObjectPtr<UWidgetComponent> DebugWidgetComponent = nullptr;

    void UpdateSnapshot();
    void DrawWorldDebug() const;
    bool IsDebugEnabled() const;

    void EnsureWidgetComponent();
    void UpdateWidget();
};
