#include "DebugFrameworkUI/DebugFrameworkPanelWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/ScrollBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "DebugFramework/DebugFrameworkSettings.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "InputCoreTypes.h"

void UDebugFrameworkPanelWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PanelRoot"));
        WidgetTree->RootWidget = RootBorder;
    }

    if (!RootBorder)
    {
        RootBorder = Cast<UBorder>(WidgetTree->RootWidget);
    }

    if (RootBorder)
    {
        RootBorder->SetPadding(FMargin(8.f, 6.f));
        RootBorder->SetBrushColor(FLinearColor(0.02f, 0.02f, 0.02f, 0.78f));
        RootBorder->SetClipping(EWidgetClipping::ClipToBoundsAlways);
    }

    if (!ContentBox)
    {
        ContentBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ContentBox"));
        if (RootBorder)
        {
            RootBorder->SetContent(ContentBox);
        }
    }

    if (!ActionBarBorder)
    {
        ActionBarBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ActionBarBorder"));
        ActionBarBorder->SetPadding(FMargin(2.f, 1.f));
        ActionBarBorder->SetBrushColor(FLinearColor(0.10f, 0.10f, 0.10f, 0.96f));
        if (UVerticalBoxSlot* ActionSlot = ContentBox ? ContentBox->AddChildToVerticalBox(ActionBarBorder) : nullptr)
        {
            ActionSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 4.f));
            ActionSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
        }
    }

    if (!HeaderBox)
    {
        HeaderBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ActionBarBox"));
        if (ActionBarBorder)
        {
            ActionBarBorder->SetContent(HeaderBox);
        }
    }

    if (!CloseButton)
    {
        if (HeaderBox)
        {
            USpacer* RightSpacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass(), TEXT("ActionBarSpacer"));
            if (RightSpacer)
            {
                if (UHorizontalBoxSlot* SpacerSlot = HeaderBox->AddChildToHorizontalBox(RightSpacer))
                {
                    SpacerSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
                }
            }
        }

        CloseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CloseButton"));
        CloseButton->SetBackgroundColor(FLinearColor(0.26f, 0.10f, 0.10f, 1.f));
        if (HeaderBox)
        {
            if (UHorizontalBoxSlot* CloseSlot = HeaderBox->AddChildToHorizontalBox(CloseButton))
            {
                CloseSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
                CloseSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
                CloseSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                CloseSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 0.f));
            }
        }
    }

    if (CloseButton)
    {
        CloseButton->OnClicked.RemoveDynamic(this, &UDebugFrameworkPanelWidget::HandleCloseClicked);
        CloseButton->OnClicked.AddDynamic(this, &UDebugFrameworkPanelWidget::HandleCloseClicked);
    }

    if (!CloseButtonText)
    {
        CloseButtonText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CloseButtonText"));
        CloseButtonText->SetText(FText::FromString(TEXT("x")));
        CloseButtonText->SetColorAndOpacity(FLinearColor::White);
        if (CloseButton)
        {
            CloseButton->SetContent(CloseButtonText);
        }
    }

    if (!HeaderBorder)
    {
        HeaderBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("HeaderBorder"));
        HeaderBorder->SetPadding(FMargin(4.f, 3.f));
        HeaderBorder->SetBrushColor(FLinearColor(0.14f, 0.14f, 0.14f, 0.95f));
        if (UVerticalBoxSlot* HeaderSlot = ContentBox ? ContentBox->AddChildToVerticalBox(HeaderBorder) : nullptr)
        {
            HeaderSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 6.f));
            HeaderSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
        }
    }

    if (!TitleText)
    {
        TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
        TitleText->SetColorAndOpacity(FLinearColor(0.90f, 0.90f, 0.95f, 1.f));
        TitleText->SetText(FText::FromName(PanelId));
        if (HeaderBorder)
        {
            HeaderBorder->SetContent(TitleText);
        }
    }

    if (!RowsScrollBox)
    {
        RowsScrollBox = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("RowsScrollBox"));
        RowsScrollBox->SetOrientation(EOrientation::Orient_Vertical);
        if (ContentBox)
        {
            if (UVerticalBoxSlot* RowsSlot = ContentBox->AddChildToVerticalBox(RowsScrollBox))
            {
                RowsSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
            }
        }
    }

    if (!RowsBox)
    {
        RowsBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("RowsBox"));
        if (RowsScrollBox)
        {
            RowsScrollBox->AddChild(RowsBox);
        }
    }
}

FReply UDebugFrameworkPanelWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot || !InMouseEvent.IsAltDown())
    {
        return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
    }

    const FKey ClickedButton = InMouseEvent.GetEffectingButton();
    if (ClickedButton == EKeys::LeftMouseButton)
    {
        bDragging = true;
        MouseStartScreen = InMouseEvent.GetScreenSpacePosition();
        DragStartPosition = CanvasSlot->GetPosition();
        return FReply::Handled().CaptureMouse(TakeWidget());
    }

    if (ClickedButton == EKeys::RightMouseButton)
    {
        bResizing = true;
        bAutoAdjustHeightToContent = false;
        MouseStartScreen = InMouseEvent.GetScreenSpacePosition();
        ResizeStartSize = CanvasSlot->GetSize();
        return FReply::Handled().CaptureMouse(TakeWidget());
    }

    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UDebugFrameworkPanelWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    bool bHandled = false;
    const FKey ReleasedButton = InMouseEvent.GetEffectingButton();

    if (bDragging && ReleasedButton == EKeys::LeftMouseButton)
    {
        bDragging = false;
        bHandled = true;
    }

    if (bResizing && ReleasedButton == EKeys::RightMouseButton)
    {
        bResizing = false;
        bHandled = true;
    }

    if (bHandled)
    {
        PushLayoutToSubsystem();
        return FReply::Handled().ReleaseMouseCapture();
    }

    return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

FReply UDebugFrameworkPanelWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (!bDragging && !bResizing)
    {
        return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
    }

    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        bDragging = false;
        bResizing = false;
        return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
    }

    const float ViewportScale = FMath::Max(GetViewportScale(), KINDA_SMALL_NUMBER);
    const FVector2D Delta = (InMouseEvent.GetScreenSpacePosition() - MouseStartScreen) / ViewportScale;

    if (bDragging)
    {
        CanvasSlot->SetPosition(DragStartPosition + Delta);
    }

    if (bResizing)
    {
        SetPanelSize(ResizeStartSize + Delta);
    }

    PushLayoutToSubsystem();
    return FReply::Handled();
}

FReply UDebugFrameworkPanelWidget::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (!InMouseEvent.IsAltDown())
    {
        return Super::NativeOnMouseWheel(InGeometry, InMouseEvent);
    }

    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return Super::NativeOnMouseWheel(InGeometry, InMouseEvent);
    }

    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const float Step = Settings ? Settings->MouseWheelResizeStep : 0.08f;
    const float Factor = 1.f + (Step * InMouseEvent.GetWheelDelta());
    bAutoAdjustHeightToContent = false;
    SetPanelSize(CanvasSlot->GetSize() * Factor);
    PushLayoutToSubsystem();
    return FReply::Handled();
}

void UDebugFrameworkPanelWidget::SetupPanel(UDebugFrameworkSubsystem* InSubsystem, FName InPanelId, const FText& InTitle)
{
    DebugSubsystem = InSubsystem;
    PanelId = InPanelId;
    if (TitleText)
    {
        TitleText->SetText(InTitle);
    }
}

void UDebugFrameworkPanelWidget::HandleCloseClicked()
{
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    if (!Subsystem || PanelId.IsNone())
    {
        return;
    }

    Subsystem->SetPanelVisible(PanelId, false);
    SetVisibility(ESlateVisibility::Collapsed);
}

void UDebugFrameworkPanelWidget::ApplyPanelData(const FDebugFrameworkPanelData& InData)
{
    if (TitleText)
    {
        TitleText->SetText(InData.Title);
    }

    if (!RowsBox)
    {
        return;
    }

    const int32 RequiredRows = FMath::Max(1, InData.Rows.Num());
    const UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    const float WrapWidth = CanvasSlot ? FMath::Max(120.f, CanvasSlot->GetSize().X - 28.f) : 380.f;

    while (RowTextBlocks.Num() < RequiredRows)
    {
        const FName RowName(*FString::Printf(TEXT("RowText_%d"), RowTextBlocks.Num()));
        UTextBlock* NewRow = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), RowName);
        if (!NewRow)
        {
            break;
        }

        NewRow->SetColorAndOpacity(FLinearColor::White);
        NewRow->SetAutoWrapText(true);
        NewRow->SetWrapTextAt(WrapWidth);
        if (UVerticalBoxSlot* SlotWidget = RowsBox->AddChildToVerticalBox(NewRow))
        {
            SlotWidget->SetPadding(FMargin(0.f, 1.f));
        }
        RowTextBlocks.Add(NewRow);
    }

    for (int32 Index = 0; Index < RowTextBlocks.Num(); ++Index)
    {
        UTextBlock* RowText = RowTextBlocks[Index];
        if (!RowText)
        {
            continue;
        }

        if (InData.Rows.Num() == 0)
        {
            RowText->SetVisibility(Index == 0 ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
            if (Index == 0)
            {
                RowText->SetText(FText::FromString(TEXT("(no data)")));
                RowText->SetColorAndOpacity(FLinearColor(0.65f, 0.65f, 0.70f, 1.f));
            }
            continue;
        }

        if (Index >= InData.Rows.Num())
        {
            RowText->SetVisibility(ESlateVisibility::Collapsed);
            continue;
        }

        const FDebugFrameworkPanelRow& SourceRow = InData.Rows[Index];
        const FString Combined = SourceRow.Value.IsEmpty()
            ? SourceRow.Label
            : FString::Printf(TEXT("%s: %s"), *SourceRow.Label, *SourceRow.Value);

        RowText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
        RowText->SetText(FText::FromString(Combined));
        RowText->SetColorAndOpacity(SourceRow.Color);
        RowText->SetAutoWrapText(true);
        RowText->SetWrapTextAt(WrapWidth);
    }

    AdjustPanelSizeToContent(RequiredRows);
}

void UDebugFrameworkPanelWidget::ApplyLayout(const FDebugFrameworkPanelLayout& InLayout)
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return;
    }

    CanvasSlot->SetPosition(InLayout.Position);
    CanvasSlot->SetSize(ClampPanelSize(InLayout.Size));
}

void UDebugFrameworkPanelWidget::AdjustPanelSizeToContent(int32 RowCount) const
{
    if (!bAutoAdjustHeightToContent || bResizing)
    {
        return;
    }

    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return;
    }

    const int32 EffectiveRows = FMath::Min(FMath::Max(1, RowCount), FMath::Max(1, MaxAutoRowsBeforeScroll));
    FVector2D TargetSize = CanvasSlot->GetSize();
    TargetSize.Y = AutoBaseHeight + (AutoRowHeight * static_cast<float>(EffectiveRows));
    CanvasSlot->SetSize(ClampPanelSize(TargetSize));
}

UCanvasPanelSlot* UDebugFrameworkPanelWidget::GetCanvasSlot() const
{
    return Cast<UCanvasPanelSlot>(Slot);
}

void UDebugFrameworkPanelWidget::PushLayoutToSubsystem() const
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    if (!CanvasSlot || !Subsystem || PanelId.IsNone())
    {
        return;
    }

    FDebugFrameworkPanelLayout Layout;
    Layout.PanelId = PanelId;
    Layout.Position = CanvasSlot->GetPosition();
    Layout.Size = CanvasSlot->GetSize();
    Subsystem->UpdatePanelLayout(Layout);
}

void UDebugFrameworkPanelWidget::SetPanelSize(const FVector2D& InSize) const
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return;
    }

    CanvasSlot->SetSize(ClampPanelSize(InSize));
}

FVector2D UDebugFrameworkPanelWidget::ClampPanelSize(const FVector2D& InSize) const
{
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const FVector2D MinSize = Settings ? Settings->MinPanelSize : FVector2D(220.f, 140.f);
    const FVector2D MaxSize = Settings ? Settings->MaxPanelSize : FVector2D(1200.f, 900.f);

    FVector2D Clamped = InSize;
    Clamped.X = FMath::Clamp(Clamped.X, MinSize.X, MaxSize.X);
    Clamped.Y = FMath::Clamp(Clamped.Y, MinSize.Y, MaxSize.Y);
    return Clamped;
}

float UDebugFrameworkPanelWidget::GetViewportScale() const
{
    return UWidgetLayoutLibrary::GetViewportScale(this);
}
