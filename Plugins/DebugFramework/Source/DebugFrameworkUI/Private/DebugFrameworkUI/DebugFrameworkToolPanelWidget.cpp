#include "DebugFrameworkUI/DebugFrameworkToolPanelWidget.h"

#include "Algo/Sort.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/ScrollBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "DebugFramework/DebugFrameworkSettings.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "DebugFrameworkUI/DebugFrameworkMenuRowWidget.h"
#include "DebugFrameworkUI/DebugFrameworkUISubsystem.h"
#include "InputCoreTypes.h"

void UDebugFrameworkToolPanelWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ToolPanelRoot"));
        WidgetTree->RootWidget = RootBorder;
    }

    if (!RootBorder)
    {
        RootBorder = Cast<UBorder>(WidgetTree->RootWidget);
    }

    if (RootBorder)
    {
        FSlateBrush Brush;
        Brush.DrawAs = ESlateBrushDrawType::Box;
        Brush.TintColor = FSlateColor(FLinearColor(0.02f, 0.02f, 0.02f, 0.90f));
        RootBorder->SetBrush(Brush);
        RootBorder->SetPadding(FMargin(8.f, 6.f));
        RootBorder->SetClipping(EWidgetClipping::ClipToBoundsAlways);
    }

    if (!RootBox)
    {
        RootBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ToolPanelRootBox"));
        if (RootBorder)
        {
            RootBorder->SetContent(RootBox);
        }
    }

    if (!HeaderBox)
    {
        HeaderBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HeaderBox"));
        if (RootBox)
        {
            if (UVerticalBoxSlot* HeaderSlot = RootBox->AddChildToVerticalBox(HeaderBox))
            {
                HeaderSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 6.f));
            }
        }
    }

    if (!TitleText)
    {
        TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
        TitleText->SetColorAndOpacity(FLinearColor(0.94f, 0.94f, 0.98f, 1.f));
        TitleText->SetText(ToolTitle.IsEmpty() ? FText::FromString(TEXT("Debug Tool")) : ToolTitle);
        if (HeaderBox)
        {
            if (UHorizontalBoxSlot* TitleSlot = HeaderBox->AddChildToHorizontalBox(TitleText))
            {
                TitleSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                TitleSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
            }
        }
    }

    if (HeaderBox)
    {
        USpacer* RightSpacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass(), TEXT("HeaderSpacer"));
        if (RightSpacer)
        {
            if (UHorizontalBoxSlot* SpacerSlot = HeaderBox->AddChildToHorizontalBox(RightSpacer))
            {
                SpacerSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
            }
        }
    }

    if (!CloseButton)
    {
        CloseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("CloseButton"));
        CloseButton->SetBackgroundColor(FLinearColor(0.26f, 0.10f, 0.10f, 1.f));
        if (HeaderBox)
        {
            if (UHorizontalBoxSlot* CloseSlot = HeaderBox->AddChildToHorizontalBox(CloseButton))
            {
                CloseSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                CloseSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
                CloseSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
            }
        }
    }

    if (CloseButton)
    {
        CloseButton->OnClicked.RemoveDynamic(this, &UDebugFrameworkToolPanelWidget::HandleCloseClicked);
        CloseButton->OnClicked.AddDynamic(this, &UDebugFrameworkToolPanelWidget::HandleCloseClicked);
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

    if (!SearchBox)
    {
        SearchBox = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("SearchBox"));
        SearchBox->SetHintText(FText::FromString(TEXT("Search character or panel")));
        if (RootBox)
        {
            if (UVerticalBoxSlot* SearchSlot = RootBox->AddChildToVerticalBox(SearchBox))
            {
                SearchSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 6.f));
            }
        }
    }

    if (SearchBox)
    {
        SearchBox->OnTextChanged.RemoveDynamic(this, &UDebugFrameworkToolPanelWidget::HandleSearchChanged);
        SearchBox->OnTextChanged.AddDynamic(this, &UDebugFrameworkToolPanelWidget::HandleSearchChanged);
    }

    if (!ListScrollBox)
    {
        ListScrollBox = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ListScrollBox"));
        ListScrollBox->SetOrientation(EOrientation::Orient_Vertical);
        if (RootBox)
        {
            if (UVerticalBoxSlot* ListSlot = RootBox->AddChildToVerticalBox(ListScrollBox))
            {
                ListSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
            }
        }
    }
}

void UDebugFrameworkToolPanelWidget::SetupToolPanel(UDebugFrameworkUISubsystem* InUISubsystem, UDebugFrameworkSubsystem* InSubsystem, FName InToolId, const FText& InToolTitle)
{
    UISubsystem = InUISubsystem;
    DebugSubsystem = InSubsystem;
    ToolId = InToolId;
    ToolTitle = InToolTitle;

    if (TitleText)
    {
        TitleText->SetText(ToolTitle);
    }
}

void UDebugFrameworkToolPanelWidget::RefreshPanels(const TArray<FDebugFrameworkPanelData>& InPanels)
{
    if (!ListScrollBox)
    {
        return;
    }

    TSet<FName> ActiveIds;
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    for (const FDebugFrameworkPanelData& Panel : InPanels)
    {
        if (Panel.PanelId.IsNone() || Panel.ToolId != ToolId)
        {
            continue;
        }

        ActiveIds.Add(Panel.PanelId);

        UDebugFrameworkMenuRowWidget* RowWidget = nullptr;
        if (TObjectPtr<UDebugFrameworkMenuRowWidget>* Existing = RowsByPanelId.Find(Panel.PanelId))
        {
            RowWidget = Existing->Get();
        }

        if (!RowWidget || !IsValid(RowWidget))
        {
            RowWidget = WidgetTree->ConstructWidget<UDebugFrameworkMenuRowWidget>(UDebugFrameworkMenuRowWidget::StaticClass(), *FString::Printf(TEXT("ToolRow_%d"), RowsByPanelId.Num()));
            if (!RowWidget)
            {
                continue;
            }
            RowsByPanelId.Add(Panel.PanelId, RowWidget);
        }

        RowWidget->SetupRow(Subsystem, Panel.PanelId, Panel.Title);
        RowWidget->RefreshState();
    }

    for (auto It = RowsByPanelId.CreateIterator(); It; ++It)
    {
        if (!ActiveIds.Contains(It.Key()))
        {
            if (It.Value())
            {
                It.Value()->RemoveFromParent();
            }
            It.RemoveCurrent();
        }
    }

    RebuildVisibleRows();
}

void UDebugFrameworkToolPanelWidget::ApplyLayout(const FDebugFrameworkPanelLayout& InLayout)
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return;
    }

    CanvasSlot->SetPosition(InLayout.Position);
    CanvasSlot->SetSize(ClampPanelSize(InLayout.Size));
}

FReply UDebugFrameworkToolPanelWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
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
        MouseStartScreen = InMouseEvent.GetScreenSpacePosition();
        ResizeStartSize = CanvasSlot->GetSize();
        return FReply::Handled().CaptureMouse(TakeWidget());
    }

    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UDebugFrameworkToolPanelWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
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

FReply UDebugFrameworkToolPanelWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
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

FReply UDebugFrameworkToolPanelWidget::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
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
    SetPanelSize(CanvasSlot->GetSize() * Factor);
    PushLayoutToSubsystem();
    return FReply::Handled();
}

void UDebugFrameworkToolPanelWidget::HandleCloseClicked()
{
    if (UDebugFrameworkUISubsystem* UI = UISubsystem.Get())
    {
        UI->CloseToolPanel(ToolId);
    }
}

void UDebugFrameworkToolPanelWidget::HandleSearchChanged(const FText& InText)
{
    SearchFilterLower = InText.ToString();
    SearchFilterLower.ToLowerInline();
    SearchFilterLower.TrimStartAndEndInline();
    bForceRebuildList = true;
    RebuildVisibleRows();
}

void UDebugFrameworkToolPanelWidget::RebuildVisibleRows()
{
    if (!ListScrollBox)
    {
        return;
    }

    TArray<UDebugFrameworkMenuRowWidget*> Rows;
    Rows.Reserve(RowsByPanelId.Num());
    for (const TPair<FName, TObjectPtr<UDebugFrameworkMenuRowWidget>>& Pair : RowsByPanelId)
    {
        UDebugFrameworkMenuRowWidget* Row = Pair.Value.Get();
        if (!Row || !IsValid(Row))
        {
            continue;
        }

        if (Row->MatchesFilter(SearchFilterLower))
        {
            Rows.Add(Row);
        }
    }

    Algo::Sort(Rows, [](const UDebugFrameworkMenuRowWidget* A, const UDebugFrameworkMenuRowWidget* B)
    {
        if (!A || !B)
        {
            return A != nullptr;
        }
        return A->GetSortKey() < B->GetSortKey();
    });

    FString NewSignature;
    NewSignature.Reserve(Rows.Num() * 32);
    NewSignature += SearchFilterLower;
    NewSignature += TEXT("|");
    for (const UDebugFrameworkMenuRowWidget* Row : Rows)
    {
        NewSignature += Row ? Row->GetPanelId().ToString() : TEXT("None");
        NewSignature += TEXT(";");
    }

    if (!bForceRebuildList && NewSignature == CachedListSignature)
    {
        return;
    }

    CachedListSignature = MoveTemp(NewSignature);
    bForceRebuildList = false;

    ListScrollBox->ClearChildren();
    for (UDebugFrameworkMenuRowWidget* Row : Rows)
    {
        ListScrollBox->AddChild(Row);
    }
}

void UDebugFrameworkToolPanelWidget::PushLayoutToSubsystem() const
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    if (!CanvasSlot || !Subsystem || ToolId.IsNone())
    {
        return;
    }

    FDebugFrameworkPanelLayout Layout;
    Layout.PanelId = GetLayoutPanelId();
    Layout.Position = CanvasSlot->GetPosition();
    Layout.Size = CanvasSlot->GetSize();
    Subsystem->UpdatePanelLayout(Layout);
}

void UDebugFrameworkToolPanelWidget::SetPanelSize(const FVector2D& InSize) const
{
    UCanvasPanelSlot* CanvasSlot = GetCanvasSlot();
    if (!CanvasSlot)
    {
        return;
    }

    CanvasSlot->SetSize(ClampPanelSize(InSize));
}

FVector2D UDebugFrameworkToolPanelWidget::ClampPanelSize(const FVector2D& InSize) const
{
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const FVector2D MinSize = Settings ? Settings->MinPanelSize : FVector2D(220.f, 140.f);
    const FVector2D MaxSize = Settings ? Settings->MaxPanelSize : FVector2D(1200.f, 900.f);

    FVector2D Clamped = InSize;
    Clamped.X = FMath::Clamp(Clamped.X, MinSize.X, MaxSize.X);
    Clamped.Y = FMath::Clamp(Clamped.Y, MinSize.Y, MaxSize.Y);
    return Clamped;
}

UCanvasPanelSlot* UDebugFrameworkToolPanelWidget::GetCanvasSlot() const
{
    return Cast<UCanvasPanelSlot>(Slot);
}

float UDebugFrameworkToolPanelWidget::GetViewportScale() const
{
    return UWidgetLayoutLibrary::GetViewportScale(this);
}

FName UDebugFrameworkToolPanelWidget::GetLayoutPanelId() const
{
    return FName(*FString::Printf(TEXT("ToolPanel.%s"), *ToolId.ToString()));
}
