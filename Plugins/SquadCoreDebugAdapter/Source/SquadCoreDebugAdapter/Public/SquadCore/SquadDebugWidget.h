#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SquadCore/SquadDebugComponent.h"
#include "SquadDebugWidget.generated.h"

class UTextBlock;
class UVerticalBox;
class UBorder;

UCLASS(BlueprintType)
class SQUADCOREDEBUGADAPTER_API USquadDebugWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FLinearColor TextColor = FLinearColor::White;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FLinearColor BackgroundColor = FLinearColor(0.f, 0.f, 0.f, 0.6f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FMargin PanelPadding = FMargin(6.f, 4.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bShowHeader = true;

    UFUNCTION(BlueprintCallable, Category="Squad|Debug")
    void UpdateFromSnapshot(const FSquadDebugSnapshot& InSnapshot);

protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(Transient)
    TObjectPtr<UBorder> RootBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> RootBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> HeaderText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TaskText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TargetText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> ThreatText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> CooldownText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> SlotText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> LootText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> DistanceText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> ProfileText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> PressureText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> LeaderText = nullptr;

    UPROPERTY(Transient)
    FSquadDebugSnapshot Snapshot;

    UTextBlock* AddLine(const FName& Name);
    void RefreshText();
};
