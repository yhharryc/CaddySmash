#include "DebugFrameworkUI/DebugFrameworkMenuRowWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "DebugFrameworkUI/DebugFrameworkControlMenuWidget.h"

void UDebugFrameworkMenuRowWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("RootRow"));
        WidgetTree->RootWidget = RootRow;
    }

    if (!RootRow)
    {
        RootRow = Cast<UHorizontalBox>(WidgetTree->RootWidget);
    }

    if (!TitleText)
    {
        TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
        TitleText->SetColorAndOpacity(FLinearColor(0.86f, 0.88f, 0.92f, 1.f));
        TitleText->SetAutoWrapText(true);
        if (RootRow)
        {
            if (UHorizontalBoxSlot* TitleSlot = RootRow->AddChildToHorizontalBox(TitleText))
            {
                TitleSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
                TitleSlot->SetPadding(FMargin(0.f, 2.f, 6.f, 2.f));
            }
        }
    }

    if (!ToggleButton)
    {
        ToggleButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("ToggleButton"));
        ToggleButton->SetBackgroundColor(FLinearColor(0.18f, 0.18f, 0.20f, 1.f));
        if (RootRow)
        {
            if (UHorizontalBoxSlot* ButtonSlot = RootRow->AddChildToHorizontalBox(ToggleButton))
            {
                ButtonSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                ButtonSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
                ButtonSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
            }
        }
    }

    if (ToggleButton)
    {
        ToggleButton->OnClicked.RemoveDynamic(this, &UDebugFrameworkMenuRowWidget::HandleToggleClicked);
        ToggleButton->OnClicked.AddDynamic(this, &UDebugFrameworkMenuRowWidget::HandleToggleClicked);
    }

    if (!ToggleButtonText)
    {
        ToggleButtonText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ToggleButtonText"));
        ToggleButtonText->SetColorAndOpacity(FLinearColor::White);
        if (ToggleButton)
        {
            ToggleButton->SetContent(ToggleButtonText);
        }
    }

    if (TitleText && !PanelTitle.IsEmpty())
    {
        TitleText->SetText(PanelTitle);
    }

    RefreshState();
}

void UDebugFrameworkMenuRowWidget::SetupRow(UDebugFrameworkSubsystem* InSubsystem, FName InPanelId, const FText& InPanelTitle)
{
    DebugSubsystem = InSubsystem;
    OwnerMenu = nullptr;
    PanelId = InPanelId;
    PanelTitle = InPanelTitle;
    bIsToolRow = false;

    SortKey = PanelTitle.ToString();
    SortKey.ToLowerInline();

    if (TitleText)
    {
        TitleText->SetText(PanelTitle);
    }

    RefreshState();
}

void UDebugFrameworkMenuRowWidget::SetupToolRow(UDebugFrameworkControlMenuWidget* InOwnerMenu, FName InToolId, const FText& InToolTitle, int32 InCount)
{
    OwnerMenu = InOwnerMenu;
    DebugSubsystem = nullptr;
    PanelId = InToolId;
    bIsToolRow = true;

    const FString TitleWithCount = FString::Printf(TEXT("%s (%d)"), *InToolTitle.ToString(), InCount);
    PanelTitle = FText::FromString(TitleWithCount);

    SortKey = InToolTitle.ToString();
    SortKey.ToLowerInline();

    if (TitleText)
    {
        TitleText->SetText(PanelTitle);
    }

    RefreshState();
}

void UDebugFrameworkMenuRowWidget::RefreshState()
{
    if (bIsToolRow)
    {
        if (ToggleButtonText)
        {
            ToggleButtonText->SetText(FText::FromString(TEXT("Open")));
        }

        if (ToggleButton)
        {
            ToggleButton->SetBackgroundColor(FLinearColor(0.12f, 0.18f, 0.24f, 1.f));
        }
        return;
    }

    const UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    const bool bVisible = Subsystem && Subsystem->IsPanelVisible(PanelId);

    if (ToggleButtonText)
    {
        ToggleButtonText->SetText(FText::FromString(bVisible ? TEXT("Hide") : TEXT("Show")));
    }

    if (ToggleButton)
    {
        ToggleButton->SetBackgroundColor(bVisible
            ? FLinearColor(0.20f, 0.12f, 0.12f, 1.f)
            : FLinearColor(0.10f, 0.20f, 0.12f, 1.f));
    }
}

bool UDebugFrameworkMenuRowWidget::MatchesFilter(const FString& FilterLower) const
{
    if (FilterLower.IsEmpty())
    {
        return true;
    }

    const FString TitleLower = PanelTitle.ToString().ToLower();
    const FString IdLower = PanelId.ToString().ToLower();
    return TitleLower.Contains(FilterLower) || IdLower.Contains(FilterLower);
}

void UDebugFrameworkMenuRowWidget::HandleToggleClicked()
{
    if (bIsToolRow)
    {
        if (UDebugFrameworkControlMenuWidget* Menu = OwnerMenu.Get())
        {
            Menu->OpenToolPanel(PanelId);
        }
        return;
    }

    UDebugFrameworkSubsystem* Subsystem = DebugSubsystem.Get();
    if (!Subsystem || PanelId.IsNone())
    {
        return;
    }

    const bool bVisible = Subsystem->IsPanelVisible(PanelId);
    if (!bVisible)
    {
        Subsystem->SetVisible(true);
    }
    Subsystem->SetPanelVisible(PanelId, !bVisible);
    RefreshState();
}
