#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugFrameworkMenuRowWidget.generated.h"

class UButton;
class UDebugFrameworkControlMenuWidget;
class UDebugFrameworkSubsystem;
class UHorizontalBox;
class UTextBlock;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkMenuRowWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    void SetupRow(UDebugFrameworkSubsystem* InSubsystem, FName InPanelId, const FText& InPanelTitle);
    void SetupToolRow(UDebugFrameworkControlMenuWidget* InOwnerMenu, FName InToolId, const FText& InToolTitle, int32 InCount);
    void RefreshState();
    bool MatchesFilter(const FString& FilterLower) const;
    FName GetPanelId() const { return PanelId; }
    bool IsToolRow() const { return bIsToolRow; }
    FString GetSortKey() const { return SortKey; }

private:
    UFUNCTION()
    void HandleToggleClicked();

    UPROPERTY(Transient)
    TObjectPtr<UHorizontalBox> RootRow = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TitleText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UButton> ToggleButton = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> ToggleButtonText = nullptr;

    TWeakObjectPtr<UDebugFrameworkSubsystem> DebugSubsystem;
    TWeakObjectPtr<UDebugFrameworkControlMenuWidget> OwnerMenu;
    FName PanelId = NAME_None;
    FText PanelTitle;
    FString SortKey;
    bool bIsToolRow = false;
};
