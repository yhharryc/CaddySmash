#include "DebugFrameworkUI/DebugFrameworkControlMenuWidget.h"

#include "Algo/Sort.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/ScrollBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "DebugFrameworkUI/DebugFrameworkMenuRowWidget.h"
#include "DebugFrameworkUI/DebugFrameworkUISubsystem.h"
#include "DebugFramework/DebugFrameworkLog.h"
#include "HAL/IConsoleManager.h"

namespace
{
    static bool ShouldLogUI()
    {
        static IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("debugframework.LogUI"));
        return CVar && CVar->GetInt() != 0;
    }
}

void UDebugFrameworkControlMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("MenuRootBorder"));
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
        Brush.TintColor = FSlateColor(FLinearColor(0.01f, 0.01f, 0.01f, 0.85f));
        RootBorder->SetBrush(Brush);
        RootBorder->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
        RootBorder->SetPadding(FMargin(8.f, 8.f));
        RootBorder->SetClipping(EWidgetClipping::ClipToBoundsAlways);
    }

    if (!RootBox)
    {
        RootBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuRootBox"));
        if (RootBorder)
        {
            RootBorder->SetContent(RootBox);
        }
    }

    if (!TopBar)
    {
        TopBar = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("TopBar"));
        if (RootBox)
        {
            if (UVerticalBoxSlot* TopBarSlot = RootBox->AddChildToVerticalBox(TopBar))
            {
                TopBarSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 6.f));
            }
        }
    }

    if (!TitleText)
    {
        TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
        TitleText->SetText(FText::FromString(TEXT("Debug Tools")));
        TitleText->SetColorAndOpacity(FLinearColor(0.94f, 0.94f, 0.98f, 1.f));
        if (TopBar)
        {
            if (UHorizontalBoxSlot* TitleSlot = TopBar->AddChildToHorizontalBox(TitleText))
            {
                TitleSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                TitleSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
            }
        }
    }

    if (!TopBarSpacer && TopBar)
    {
        TopBarSpacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass(), TEXT("TopBarSpacer"));
        if (TopBarSpacer)
        {
            if (UHorizontalBoxSlot* SpacerSlot = TopBar->AddChildToHorizontalBox(TopBarSpacer))
            {
                SpacerSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
            }
        }
    }

    if (!ShowAllButton)
    {
        ShowAllButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ShowAllButton"));
        ShowAllButton->SetBackgroundColor(FLinearColor(0.12f, 0.18f, 0.24f, 1.f));
        if (TopBar)
        {
            if (UHorizontalBoxSlot* ButtonSlot = TopBar->AddChildToHorizontalBox(ShowAllButton))
            {
                ButtonSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                ButtonSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
                ButtonSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
            }
        }
    }

    if (ShowAllButton)
    {
        ShowAllButton->OnClicked.RemoveDynamic(this, &UDebugFrameworkControlMenuWidget::HandleShowAllClicked);
        ShowAllButton->OnClicked.AddDynamic(this, &UDebugFrameworkControlMenuWidget::HandleShowAllClicked);
    }

    if (!ShowAllButtonText)
    {
        ShowAllButtonText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ShowAllButtonText"));
        ShowAllButtonText->SetText(FText::FromString(TEXT("Show All")));
        ShowAllButtonText->SetColorAndOpacity(FLinearColor::White);
        if (ShowAllButton)
        {
            ShowAllButton->SetContent(ShowAllButtonText);
        }
    }

    if (!SearchBox)
    {
        SearchBox = WidgetTree->ConstructWidget<UEditableTextBox>(UEditableTextBox::StaticClass(), TEXT("SearchBox"));
        SearchBox->SetHintText(FText::FromString(TEXT("Search panel title or id")));
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
        SearchBox->OnTextChanged.RemoveDynamic(this, &UDebugFrameworkControlMenuWidget::HandleSearchChanged);
        SearchBox->OnTextChanged.AddDynamic(this, &UDebugFrameworkControlMenuWidget::HandleSearchChanged);
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

    bForceRebuildList = true;
    RebuildVisibleRows();

    if (ShouldLogUI())
    {
        UE_LOG(LogDebugFramework, Display, TEXT("MenuRefresh: panels=%d tools=%d rows=%d filter=\"%s\""),
            CachedPanels.Num(),
            ToolCounts.Num(),
            RowsByPanelId.Num(),
            *SearchFilterLower);
    }
}

void UDebugFrameworkControlMenuWidget::Setup(UDebugFrameworkSubsystem* InSubsystem, UDebugFrameworkUISubsystem* InUISubsystem)
{
    DebugSubsystem = InSubsystem;
    UISubsystem = InUISubsystem;
}

void UDebugFrameworkControlMenuWidget::RefreshMenu(const TArray<FDebugFrameworkPanelData>& InPanels)
{
    CachedPanels = InPanels;
    ToolTitles.Reset();
    ToolCounts.Reset();
    if (ListScrollBox && ListScrollBox->GetChildrenCount() == 0)
    {
        bForceRebuildList = true;
    }

    if (SearchBox)
    {
        SearchFilterLower = SearchBox->GetText().ToString();
        SearchFilterLower.ToLowerInline();
        SearchFilterLower.TrimStartAndEndInline();
    }

    for (const FDebugFrameworkPanelData& Panel : CachedPanels)
    {
        FName ToolId = Panel.ToolId;
        FText ToolTitle = Panel.ToolTitle;
        if (ToolId.IsNone())
        {
            ToolId = Panel.PanelId;
            if (ToolTitle.IsEmpty())
            {
                ToolTitle = Panel.Title;
            }
        }

        if (ToolId.IsNone())
        {
            continue;
        }

        int32& Count = ToolCounts.FindOrAdd(ToolId);
        ++Count;

        if (!ToolTitles.Contains(ToolId) && !ToolTitle.IsEmpty())
        {
            ToolTitles.Add(ToolId, ToolTitle);
        }
    }

    TSet<FName> ActiveIds;
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    for (const TPair<FName, int32>& ToolPair : ToolCounts)
    {
        const FName ToolId = ToolPair.Key;
        ActiveIds.Add(ToolId);

        UDebugFrameworkMenuRowWidget* RowWidget = nullptr;
        if (TObjectPtr<UDebugFrameworkMenuRowWidget>* Existing = RowsByPanelId.Find(ToolId))
        {
            RowWidget = Existing->Get();
        }

        if (!RowWidget || !IsValid(RowWidget))
        {
            RowWidget = WidgetTree->ConstructWidget<UDebugFrameworkMenuRowWidget>(UDebugFrameworkMenuRowWidget::StaticClass(), *FString::Printf(TEXT("MenuRow_%d"), RowsByPanelId.Num()));
            if (!RowWidget)
            {
                continue;
            }
            RowsByPanelId.Add(ToolId, RowWidget);
        }

        const FText ToolTitle = ToolTitles.Contains(ToolId) ? ToolTitles[ToolId] : FText::FromName(ToolId);
        RowWidget->SetupToolRow(this, ToolId, ToolTitle, ToolPair.Value);
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

void UDebugFrameworkControlMenuWidget::OpenToolPanel(FName InToolId)
{
    if (InToolId.IsNone())
    {
        return;
    }
    UDebugFrameworkUISubsystem* UI = UISubsystem.Get();
    if (!UI)
    {
        return;
    }

    const FText ToolTitle = ToolTitles.Contains(InToolId) ? ToolTitles[InToolId] : FText::FromName(InToolId);
    UI->OpenToolPanel(InToolId, ToolTitle);
}

void UDebugFrameworkControlMenuWidget::HandleShowAllClicked()
{
    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    if (!Subsystem)
    {
        return;
    }

    Subsystem->SetVisible(true);
    Subsystem->ShowAllPanels();
    for (const TPair<FName, TObjectPtr<UDebugFrameworkMenuRowWidget>>& Pair : RowsByPanelId)
    {
        if (Pair.Value)
        {
            Pair.Value->RefreshState();
        }
    }
}

void UDebugFrameworkControlMenuWidget::HandleSearchChanged(const FText& InText)
{
    SearchFilterLower = InText.ToString();
    SearchFilterLower.ToLowerInline();
    SearchFilterLower.TrimStartAndEndInline();
    bForceRebuildList = true;
    RebuildVisibleRows();
}

void UDebugFrameworkControlMenuWidget::RebuildVisibleRows()
{
    if (!ListScrollBox)
    {
        return;
    }

    if (SearchBox)
    {
        SearchFilterLower = SearchBox->GetText().ToString();
        SearchFilterLower.ToLowerInline();
        SearchFilterLower.TrimStartAndEndInline();
    }

    if (ListScrollBox->GetChildrenCount() == 0)
    {
        bForceRebuildList = true;
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

        if (!Row->IsToolRow())
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

    const bool bWasForced = bForceRebuildList;
    CachedListSignature = MoveTemp(NewSignature);
    bForceRebuildList = false;

    ListScrollBox->ClearChildren();
    for (UDebugFrameworkMenuRowWidget* Row : Rows)
    {
        ListScrollBox->AddChild(Row);
    }

    if (ShouldLogUI())
    {
        UE_LOG(LogDebugFramework, Display, TEXT("MenuBuild: rows=%d filter=\"%s\" force=%d"),
            Rows.Num(),
            *SearchFilterLower,
            bWasForced ? 1 : 0);
    }
}
