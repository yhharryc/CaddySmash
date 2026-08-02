#include "SquadCore/SquadDebugWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

void USquadDebugWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("RootBorder"));
        WidgetTree->RootWidget = RootBorder;
    }

    if (!RootBorder)
    {
        RootBorder = Cast<UBorder>(WidgetTree->RootWidget);
    }

    if (RootBorder)
    {
        RootBorder->SetBrushColor(BackgroundColor);
        RootBorder->SetPadding(PanelPadding);
    }

    if (!RootBox)
    {
        RootBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("RootBox"));
        if (RootBorder)
        {
            RootBorder->SetContent(RootBox);
        }
    }

    HeaderText = AddLine(TEXT("HeaderText"));
    TaskText = AddLine(TEXT("TaskText"));
    TargetText = AddLine(TEXT("TargetText"));
    ThreatText = AddLine(TEXT("ThreatText"));
    CooldownText = AddLine(TEXT("CooldownText"));
    SlotText = AddLine(TEXT("SlotText"));
    LootText = AddLine(TEXT("LootText"));
    DistanceText = AddLine(TEXT("DistanceText"));
    ProfileText = AddLine(TEXT("ProfileText"));
    PressureText = AddLine(TEXT("PressureText"));
    LeaderText = AddLine(TEXT("LeaderText"));

    RefreshText();
}

void USquadDebugWidget::UpdateFromSnapshot(const FSquadDebugSnapshot& InSnapshot)
{
    Snapshot = InSnapshot;
    RefreshText();
}

UTextBlock* USquadDebugWidget::AddLine(const FName& Name)
{
    if (!RootBox)
    {
        return nullptr;
    }

    UTextBlock* Line = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), Name);
    if (!Line)
    {
        return nullptr;
    }

    Line->SetColorAndOpacity(TextColor);
    Line->SetJustification(ETextJustify::Left);
    if (UVerticalBoxSlot* BoxSlot = RootBox->AddChildToVerticalBox(Line))
    {
        BoxSlot->SetPadding(FMargin(0.f, 1.f));
    }
    return Line;
}

void USquadDebugWidget::RefreshText()
{
    if (!RootBox)
    {
        return;
    }

    const FString OwnerName = Snapshot.Owner ? Snapshot.Owner->GetName() : TEXT("None");
    const FString TargetName = Snapshot.BestTarget ? Snapshot.BestTarget->GetName() : TEXT("None");
    const FString TaskName = Snapshot.DebugLastTask.ToString();
    const FString LootName = Snapshot.LootActor ? Snapshot.LootActor->GetName() : TEXT("None");
    const FString ProfileName = Snapshot.AttackProfile ? Snapshot.AttackProfile->GetName() : TEXT("None");

    if (HeaderText)
    {
        HeaderText->SetText(FText::FromString(OwnerName));
        HeaderText->SetVisibility(bShowHeader ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    if (TaskText)
    {
        TaskText->SetText(FText::FromString(FString::Printf(TEXT("Task: %s"), *TaskName)));
    }

    if (TargetText)
    {
        TargetText->SetText(FText::FromString(FString::Printf(TEXT("Target: %s"), *TargetName)));
    }

    if (ThreatText)
    {
        ThreatText->SetText(FText::FromString(FString::Printf(TEXT("Threats: %d"), Snapshot.ThreatCount)));
    }

    if (CooldownText)
    {
        CooldownText->SetText(FText::FromString(FString::Printf(TEXT("CD: %.2f"), Snapshot.CooldownRemaining)));
    }

    if (SlotText)
    {
        SlotText->SetText(FText::FromString(FString::Printf(
            TEXT("Slot: %d Obey: %d OOW: %d"),
            Snapshot.SlotId,
            Snapshot.bShouldObeyFormation ? 1 : 0,
            Snapshot.bTemporarilyOutOfFormation ? 1 : 0)));
    }

    if (LootText)
    {
        LootText->SetText(FText::FromString(FString::Printf(TEXT("Loot: %.2f %s"), Snapshot.LootScore, *LootName)));
    }

    if (DistanceText)
    {
        DistanceText->SetText(FText::FromString(FString::Printf(TEXT("Dist: %.0f"), Snapshot.DistanceToTarget)));
    }

    if (ProfileText)
    {
        ProfileText->SetText(FText::FromString(FString::Printf(TEXT("Profile: %s Range: %.0f"), *ProfileName, Snapshot.AttackRange)));
    }

    if (PressureText)
    {
        PressureText->SetText(FText::FromString(FString::Printf(TEXT("Pressure: %.2f"), Snapshot.PressureValue)));
    }

    if (LeaderText)
    {
        LeaderText->SetText(FText::FromString(FString::Printf(TEXT("LeaderDist: %.0f"), Snapshot.DistanceToLeader)));
    }
}
