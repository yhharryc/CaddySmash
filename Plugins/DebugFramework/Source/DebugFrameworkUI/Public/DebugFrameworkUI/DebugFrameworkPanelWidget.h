#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugFramework/DebugFrameworkTypes.h"
#include "DebugFrameworkPanelWidget.generated.h"

class UBorder;
class UButton;
class UCanvasPanelSlot;
class UDebugFrameworkSubsystem;
class UHorizontalBox;
class UScrollBox;
class UTextBlock;
class UVerticalBox;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkPanelWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    void SetupPanel(UDebugFrameworkSubsystem* InSubsystem, FName InPanelId, const FText& InTitle);
    void ApplyPanelData(const FDebugFrameworkPanelData& InData);
    void ApplyLayout(const FDebugFrameworkPanelLayout& InLayout);

private:
    UFUNCTION()
    void HandleCloseClicked();

    void AdjustPanelSizeToContent(int32 RowCount) const;
    UCanvasPanelSlot* GetCanvasSlot() const;
    void PushLayoutToSubsystem() const;
    void SetPanelSize(const FVector2D& InSize) const;
    FVector2D ClampPanelSize(const FVector2D& InSize) const;
    float GetViewportScale() const;

    UPROPERTY(Transient)
    TObjectPtr<UBorder> RootBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> ContentBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UBorder> ActionBarBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UBorder> HeaderBorder = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UHorizontalBox> HeaderBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> TitleText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UButton> CloseButton = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UTextBlock> CloseButtonText = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UScrollBox> RowsScrollBox = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UVerticalBox> RowsBox = nullptr;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UTextBlock>> RowTextBlocks;

    TWeakObjectPtr<UDebugFrameworkSubsystem> DebugSubsystem;
    FName PanelId = NAME_None;

    UPROPERTY(EditAnywhere, Category="DebugFramework|Layout")
    bool bAutoAdjustHeightToContent = true;

    UPROPERTY(EditAnywhere, Category="DebugFramework|Layout")
    float AutoRowHeight = 20.f;

    UPROPERTY(EditAnywhere, Category="DebugFramework|Layout")
    float AutoBaseHeight = 54.f;

    UPROPERTY(EditAnywhere, Category="DebugFramework|Layout")
    int32 MaxAutoRowsBeforeScroll = 14;

    bool bDragging = false;
    bool bResizing = false;

    FVector2D MouseStartScreen = FVector2D::ZeroVector;
    FVector2D DragStartPosition = FVector2D::ZeroVector;
    FVector2D ResizeStartSize = FVector2D(420.f, 260.f);
};
