#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugFramework/DebugFrameworkTypes.h"
#include "DebugFrameworkControlMenuWidget.generated.h"

class UBorder;
class UButton;
class UDebugFrameworkMenuRowWidget;
class UDebugFrameworkUISubsystem;
class UDebugFrameworkSubsystem;
class UEditableTextBox;
class UHorizontalBox;
class UScrollBox;
class USpacer;
class UTextBlock;
class UVerticalBox;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkControlMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    void Setup(UDebugFrameworkSubsystem* InSubsystem, UDebugFrameworkUISubsystem* InUISubsystem);
    void RefreshMenu(const TArray<FDebugFrameworkPanelData>& InPanels);
    void OpenToolPanel(FName InToolId);

private:
    UFUNCTION()
    void HandleShowAllClicked();

    UFUNCTION()
    void HandleSearchChanged(const FText& InText);

    void RebuildVisibleRows();

    UPROPERTY(Transient)
    TObjectPtr<UBorder> RootBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> RootBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UHorizontalBox> TopBar = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TitleText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<USpacer> TopBarSpacer = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UButton> ShowAllButton = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> ShowAllButtonText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UEditableTextBox> SearchBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UScrollBox> ListScrollBox = nullptr;

    UPROPERTY(Transient)
    TMap<FName, TObjectPtr<UDebugFrameworkMenuRowWidget>> RowsByPanelId;

    UPROPERTY(Transient)
    TArray<FDebugFrameworkPanelData> CachedPanels;

    TMap<FName, FText> ToolTitles;
    TMap<FName, int32> ToolCounts;

    TWeakObjectPtr<UDebugFrameworkUISubsystem> UISubsystem;
    TWeakObjectPtr<UDebugFrameworkSubsystem> DebugSubsystem;
    FString SearchFilterLower;
    FString CachedListSignature;
    bool bForceRebuildList = false;
};
