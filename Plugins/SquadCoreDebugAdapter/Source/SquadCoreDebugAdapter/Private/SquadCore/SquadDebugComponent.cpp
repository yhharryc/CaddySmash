#include "SquadCore/SquadDebugComponent.h"

#include "Blueprint/UserWidget.h"
#include "DrawDebugHelpers.h"
#include "HAL/IConsoleManager.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "SquadCore/SquadManagerSubsystem.h"
#include "SquadCore/SquadMemberComponent.h"
#include "SquadCore/SquadDebugWidget.h"
#include "Combat/AttackProfile.h"
#include "Engine/World.h"
#include "Components/WidgetComponent.h"

static TAutoConsoleVariable<int32> CVarSquadDebug(
    TEXT("squad.Debug"),
    0,
    TEXT("Enable Squad debug rendering (0/1)."),
    ECVF_Cheat);

static TAutoConsoleVariable<int32> CVarSquadDebugWorld(
    TEXT("squad.Debug.World"),
    1,
    TEXT("Enable Squad debug world drawing (0/1)."),
    ECVF_Cheat);

namespace
{
    static void AddDebugRow(TArray<FDebugFrameworkPanelRow>& OutRows, const FString& Label, const FString& Value, const FLinearColor& Color = FLinearColor::White)
    {
        FDebugFrameworkPanelRow& Row = OutRows.AddDefaulted_GetRef();
        Row.Label = Label;
        Row.Value = Value;
        Row.Color = Color;
    }
}

USquadDebugComponent::USquadDebugComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void USquadDebugComponent::BeginPlay()
{
    Super::BeginPlay();

    if (UWorld* World = GetWorld())
    {
        if (UDebugFrameworkSubsystem* DebugSubsystem = World->GetSubsystem<UDebugFrameworkSubsystem>())
        {
            DebugSubsystem->RegisterProvider(this);
        }
    }
}

void USquadDebugComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        if (UDebugFrameworkSubsystem* DebugSubsystem = World->GetSubsystem<UDebugFrameworkSubsystem>())
        {
            DebugSubsystem->UnregisterProvider(this);
        }
    }

    Super::EndPlay(EndPlayReason);
}

void USquadDebugComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!IsDebugEnabled())
    {
        if (DebugWidgetComponent)
        {
            DebugWidgetComponent->SetHiddenInGame(true);
        }
        return;
    }

    EnsureWidgetComponent();
    if (DebugWidgetComponent)
    {
        DebugWidgetComponent->SetHiddenInGame(false);
    }

    UWorld* World = GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    if (UpdateInterval > 0.f && (Now - LastUpdateTime) < UpdateInterval)
    {
        return;
    }
    LastUpdateTime = Now;

    UpdateSnapshot();
    UpdateWidget();
    DrawWorldDebug();
}

bool USquadDebugComponent::IsDebugEnabled() const
{
    return bEnabled && CVarSquadDebug.GetValueOnGameThread() != 0;
}

void USquadDebugComponent::UpdateSnapshot()
{
    AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return;
    }

    UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;

    Snapshot = FSquadDebugSnapshot();
    Snapshot.Owner = OwnerActor;

    USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();
    if (Member)
    {
        Snapshot.DebugLastTask = Member->DebugLastTask;
        Snapshot.SlotId = Member->SlotId;
        Snapshot.SlotWorldPos = Member->SlotWorldPos;
        Snapshot.bShouldObeyFormation = Member->bShouldObeyFormation;
        Snapshot.bTemporarilyOutOfFormation = Member->bIsTemporarilyOutOfFormation;
        Snapshot.PressureValue = Member->PressureValue;
        Snapshot.BestTarget = Member->BestTarget;
        Snapshot.ThreatCount = Member->ThreatList.Num();
        Snapshot.LootScore = Member->LootCandidate.Score;
        Snapshot.LootActor = Member->LootCandidate.LootActor;
        Snapshot.AttackProfile = Member->LastAttackProfile;
        Snapshot.AttackRange = Member->CurrentAttackRange > 0.f ? Member->CurrentAttackRange : (Member->LastAttackProfile ? Member->LastAttackProfile->Range : 0.f);
        Snapshot.AggressionRange = Member->CurrentAggressionRange;
        Snapshot.bInAttackRange = Member->bBestTargetInAttackRange;
        Snapshot.bInAggressionRange = Member->bBestTargetInAggressionRange;
        Snapshot.NextAttackTime = Member->NextAttackTime;
        Snapshot.CooldownRemaining = FMath::Max(0.f, Member->NextAttackTime - Now);
    }

    if (USquadManagerSubsystem* Manager = World ? World->GetSubsystem<USquadManagerSubsystem>() : nullptr)
    {
        if (AActor* Leader = Manager->GetFormationLeader())
        {
            Snapshot.DistanceToLeader = FVector::Distance(OwnerActor->GetActorLocation(), Leader->GetActorLocation());
        }
    }

    if (Snapshot.BestTarget)
    {
        Snapshot.DistanceToTarget = Member ? Member->DistanceToBestTarget : FVector::Distance(OwnerActor->GetActorLocation(), Snapshot.BestTarget->GetActorLocation());
    }
}

void USquadDebugComponent::DrawWorldDebug() const
{
    if (!bDrawWorld || CVarSquadDebugWorld.GetValueOnGameThread() == 0)
    {
        return;
    }

    const AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return;
    }

    UWorld* World = OwnerActor->GetWorld();
    const float Duration = FMath::Max(0.f, UpdateInterval + 0.02f);
    const FVector OwnerLoc = OwnerActor->GetActorLocation();

    if (bDrawText3D)
    {
        const FString ProfileName = Snapshot.AttackProfile ? Snapshot.AttackProfile->GetName() : TEXT("None");
        const FString TargetName = Snapshot.BestTarget ? Snapshot.BestTarget->GetName() : TEXT("None");
        const FString Text = FString::Printf(
            TEXT("%s\nTask:%s\nTarget:%s\nCD:%.2f Slot:%d Obey:%d OOW:%d"),
            *OwnerActor->GetName(),
            *Snapshot.DebugLastTask.ToString(),
            *TargetName,
            Snapshot.CooldownRemaining,
            Snapshot.SlotId,
            Snapshot.bShouldObeyFormation ? 1 : 0,
            Snapshot.bTemporarilyOutOfFormation ? 1 : 0);

        DrawDebugString(
            World,
            OwnerLoc + FVector(0.f, 0.f, TextVerticalOffset),
            Text,
            nullptr,
            TextColor,
            Duration,
            false);
    }

    if (bDrawFormation && Snapshot.SlotId != INDEX_NONE)
    {
        DrawDebugLine(World, OwnerLoc, Snapshot.SlotWorldPos, FormationColor, false, Duration, 0, LineThickness);
        DrawDebugSphere(World, Snapshot.SlotWorldPos, 20.f, 12, FormationColor, false, Duration, 0, 0.8f);
    }

    if (bDrawTargeting && Snapshot.BestTarget)
    {
        DrawDebugLine(World, OwnerLoc, Snapshot.BestTarget->GetActorLocation(), TargetColor, false, Duration, 0, LineThickness);
        DrawDebugSphere(World, Snapshot.BestTarget->GetActorLocation(), 16.f, 10, TargetColor, false, Duration, 0, 0.6f);
    }

    if (bDrawLeaderLine && Snapshot.DistanceToLeader > 0.f)
    {
        if (USquadManagerSubsystem* Manager = World->GetSubsystem<USquadManagerSubsystem>())
        {
            if (AActor* Leader = Manager->GetFormationLeader())
            {
                DrawDebugLine(World, OwnerLoc, Leader->GetActorLocation(), LeaderColor, false, Duration, 0, LineThickness);
            }
        }
    }

    if (bDrawAttackRange && Snapshot.AttackRange > 0.f)
    {
        DrawDebugSphere(World, OwnerLoc, Snapshot.AttackRange, 16, FColor::Yellow, false, Duration, 0, 0.5f);
    }
}

void USquadDebugComponent::EnsureWidgetComponent()
{
    if (!bUseWidget || DebugWidgetComponent)
    {
        return;
    }

    AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return;
    }

    USceneComponent* RootComp = OwnerActor->GetRootComponent();
    if (!RootComp)
    {
        return;
    }

    DebugWidgetComponent = NewObject<UWidgetComponent>(OwnerActor);
    if (!DebugWidgetComponent)
    {
        return;
    }

    DebugWidgetComponent->SetupAttachment(RootComp);
    DebugWidgetComponent->SetRelativeLocation(WidgetOffset);
    DebugWidgetComponent->SetWidgetSpace(bWidgetScreenSpace ? EWidgetSpace::Screen : EWidgetSpace::World);
    DebugWidgetComponent->SetTwoSided(true);
    DebugWidgetComponent->SetDrawSize(WidgetDrawSize);
    DebugWidgetComponent->SetDrawAtDesiredSize(bWidgetDrawAtDesiredSize);
    DebugWidgetComponent->SetPivot(FVector2D(0.5f, 0.f));

    TSubclassOf<UUserWidget> UseClass = WidgetClass;
    if (!UseClass)
    {
        UseClass = USquadDebugWidget::StaticClass();
    }
    DebugWidgetComponent->SetWidgetClass(UseClass);

    DebugWidgetComponent->RegisterComponent();
}

void USquadDebugComponent::UpdateWidget()
{
    if (!DebugWidgetComponent)
    {
        return;
    }

    if (UUserWidget* UserWidget = DebugWidgetComponent->GetUserWidgetObject())
    {
        if (USquadDebugWidget* DebugWidget = Cast<USquadDebugWidget>(UserWidget))
        {
            DebugWidget->UpdateFromSnapshot(Snapshot);
        }
    }
}

FName USquadDebugComponent::GetDebugPanelId_Implementation() const
{
    const AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return NAME_None;
    }

    return FName(*FString::Printf(TEXT("Squad.%s"), *GetPathNameSafe(OwnerActor)));
}

FText USquadDebugComponent::GetDebugPanelTitle_Implementation() const
{
    const AActor* OwnerActor = GetOwner();
    return FText::FromString(FString::Printf(TEXT("[Squad] %s"), OwnerActor ? *OwnerActor->GetName() : TEXT("Unknown")));
}

FName USquadDebugComponent::GetDebugToolId_Implementation() const
{
    return TEXT("DebugTool.CharacterAI");
}

FText USquadDebugComponent::GetDebugToolTitle_Implementation() const
{
    return FText::FromString(TEXT("Character AI Debug"));
}

int32 USquadDebugComponent::GetDebugSortOrder_Implementation() const
{
    return 100;
}

void USquadDebugComponent::GatherDebugRows_Implementation(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    OutRows.Reset();

    const AActor* OwnerActor = GetOwner();
    if (!OwnerActor)
    {
        return;
    }

    const UWorld* World = OwnerActor->GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;
    const USquadMemberComponent* Member = OwnerActor->FindComponentByClass<USquadMemberComponent>();

    if (!Member)
    {
        AddDebugRow(OutRows, TEXT("State"), TEXT("No SquadMemberComponent"), FLinearColor(0.7f, 0.7f, 0.7f, 1.f));
        return;
    }

    const FString TargetName = Member->BestTarget ? Member->BestTarget->GetName() : TEXT("None");
    const FString ProfileName = Member->LastAttackProfile ? Member->LastAttackProfile->GetName() : TEXT("None");
    const FString LootName = Member->LootCandidate.LootActor ? Member->LootCandidate.LootActor->GetName() : TEXT("None");
    const float CooldownRemaining = FMath::Max(0.f, Member->NextAttackTime - Now);

    AddDebugRow(OutRows, TEXT("Task"), Member->DebugLastTask.ToString());
    AddDebugRow(OutRows, TEXT("Target"), TargetName);
    AddDebugRow(OutRows, TEXT("Profile"), ProfileName);
    AddDebugRow(OutRows, TEXT("Cooldown"), FString::Printf(TEXT("%.2f"), CooldownRemaining));
    AddDebugRow(OutRows, TEXT("ThreatCount"), FString::FromInt(Member->ThreatList.Num()));
    AddDebugRow(OutRows, TEXT("Slot"), FString::FromInt(Member->SlotId));
    AddDebugRow(OutRows, TEXT("AttackRange"), FString::Printf(TEXT("%.0f"), Member->CurrentAttackRange));
    AddDebugRow(OutRows, TEXT("AggressionRange"), FString::Printf(TEXT("%.0f"), Member->CurrentAggressionRange));
    AddDebugRow(OutRows, TEXT("InAttackRange"), Member->bBestTargetInAttackRange ? TEXT("Yes") : TEXT("No"));
    AddDebugRow(OutRows, TEXT("InAggressionRange"), Member->bBestTargetInAggressionRange ? TEXT("Yes") : TEXT("No"));
    AddDebugRow(OutRows, TEXT("Pressure"), FString::Printf(TEXT("%.2f"), Member->PressureValue));
    AddDebugRow(OutRows, TEXT("Loot"), FString::Printf(TEXT("%.2f (%s)"), Member->LootCandidate.Score, *LootName));

    if (World)
    {
        if (const USquadManagerSubsystem* Manager = World->GetSubsystem<USquadManagerSubsystem>())
        {
            if (const AActor* Leader = Manager->GetFormationLeader())
            {
                const float DistToLeader = FVector::Distance(OwnerActor->GetActorLocation(), Leader->GetActorLocation());
                AddDebugRow(OutRows, TEXT("LeaderDistance"), FString::Printf(TEXT("%.0f"), DistToLeader));
            }
        }
    }

    const float DistToTarget = Member->BestTarget
        ? FVector::Distance(OwnerActor->GetActorLocation(), Member->BestTarget->GetActorLocation())
        : 0.f;
    AddDebugRow(OutRows, TEXT("TargetDistance"), FString::Printf(TEXT("%.0f"), DistToTarget));
}
