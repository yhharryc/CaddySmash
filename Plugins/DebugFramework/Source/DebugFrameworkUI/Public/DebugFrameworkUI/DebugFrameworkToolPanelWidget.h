#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugFramework/DebugFrameworkTypes.h"
#include "DebugFrameworkToolPanelWidget.generated.h"

class UBorder;
class UButton;
class UCanvasPanelSlot;
class UDebugFrameworkMenuRowWidget;
class UDebugFrameworkSubsystem;
class UDebugFrameworkUISubsystem;
class UEditableTextBox;
class UHorizontalBox;
class UScrollBox;
class UTextBlock;
class UVerticalBox;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkToolPanelWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    void SetupToolPanel(UDebugFrameworkUISubsystem* InUISubsystem, UDebugFrameworkSubsystem* InSubsystem, FName InToolId, const FText& InToolTitle);
    void RefreshPanels(const TArray<FDebugFrameworkPanelData>& InPanels);
    void ApplyLayout(const FDebugFrameworkPanelLayout& InLayout);

    FName GetToolId() const { return ToolId; }

private:
    UFUNCTION()
    void HandleCloseClicked();

    UFUNCTION()
    void HandleSearchChanged(const FText& InText);

    void RebuildVisibleRows();
    void PushLayoutToSubsystem() const;
    void SetPanelSize(const FVector2D& InSize) const;
    FVector2D ClampPanelSize(const FVector2D& InSize) const;
    UCanvasPanelSlot* GetCanvasSlot() const;
    float GetViewportScale() const;
    FName GetLayoutPanelId() const;

    UPROPERTY(Transient)
    TObjectPtr<UBorder> RootBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> RootBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UHorizontalBox> HeaderBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TitleText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UButton> CloseButton = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> CloseButtonText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UEditableTextBox> SearchBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UScrollBox> ListScrollBox = nullptr;

    UPROPERTY(Transient)
    TMap<FName, TObjectPtr<UDebugFrameworkMenuRowWidget>> RowsByPanelId;

    TWeakObjectPtr<UDebugFrameworkUISubsystem> UISubsystem;
    TWeakObjectPtr<UDebugFrameworkSubsystem> DebugSubsystem;
    FName ToolId = NAME_None;
    FText ToolTitle;

    FString SearchFilterLower;
    FString CachedListSignature;
    bool bForceRebuildList = false;

    bool bDragging = false;
    bool bResizing = false;

    FVector2D MouseStartScreen = FVector2D::ZeroVector;
    FVector2D DragStartPosition = FVector2D::ZeroVector;
    FVector2D ResizeStartSize = FVector2D(420.f, 260.f);
};
