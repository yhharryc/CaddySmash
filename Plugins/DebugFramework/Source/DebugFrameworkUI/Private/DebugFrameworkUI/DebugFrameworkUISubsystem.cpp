#include "DebugFrameworkUI/DebugFrameworkUISubsystem.h"

#include "DebugFramework/DebugFrameworkLog.h"
#include "DebugFramework/DebugFrameworkPlayerControllerUtils.h"
#include "DebugFramework/DebugFrameworkSettings.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "DebugFramework/DebugFrameworkTypes.h"
#include "Components/CanvasPanelSlot.h"
#include "DebugFrameworkUI/DebugFrameworkControlMenuWidget.h"
#include "DebugFrameworkUI/DebugFrameworkOverlayWidget.h"
#include "DebugFrameworkUI/DebugFrameworkPanelWidget.h"
#include "DebugFrameworkUI/DebugFrameworkToolPanelWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "HAL/IConsoleManager.h"
#include "UObject/UObjectIterator.h"

namespace
{
    static constexpr int32 DebugOverlayZOrder = 1000000;
    static constexpr int32 DebugControlMenuZOrder = 1000001;
    static const FVector2D DebugControlMenuPosition(20.f, 20.f);
    static const FVector2D DebugControlMenuSize(420.f, 420.f);

    static TAutoConsoleVariable<int32> CVarDebugFrameworkLogUI(
        TEXT("debugframework.LogUI"),
        0,
        TEXT("Enable debug framework UI logs (0/1)."),
        ECVF_Cheat);

    static bool ShouldForceMenuVisible(const UWorld* World, const UDebugFrameworkSettings* Settings)
    {
        if (!World || !Settings)
        {
            const EWorldType::Type WorldType = World ? World->WorldType.GetValue() : EWorldType::None;
            const bool bIsEditorContext = WorldType == EWorldType::Editor
                || WorldType == EWorldType::EditorPreview
                || WorldType == EWorldType::PIE;
#if WITH_EDITOR
            return bIsEditorContext;
#else
            return false;
#endif
        }

        const EWorldType::Type WorldType = World->WorldType.GetValue();
        const bool bIsEditorContext = WorldType == EWorldType::Editor
            || WorldType == EWorldType::EditorPreview
            || WorldType == EWorldType::PIE;

#if WITH_EDITOR
        if (Settings->bAlwaysShowControlMenuInEditor && bIsEditorContext)
        {
            return true;
        }
#endif

#if !UE_BUILD_SHIPPING
        if (Settings->bAlwaysShowControlMenuInNonShipping)
        {
            return true;
        }
#endif

        return false;
    }

    static UDebugFrameworkUISubsystem* FindUISubsystemForConsoleWorld(UWorld* InWorld)
    {
        if (InWorld)
        {
            return InWorld->GetSubsystem<UDebugFrameworkUISubsystem>();
        }

        if (GEngine)
        {
            for (const FWorldContext& Context : GEngine->GetWorldContexts())
            {
                UWorld* World = Context.World();
                if (!World)
                {
                    continue;
                }

                if (UDebugFrameworkUISubsystem* Subsystem = World->GetSubsystem<UDebugFrameworkUISubsystem>())
                {
                    return Subsystem;
                }
            }
        }

        for (TObjectIterator<UWorld> It; It; ++It)
        {
            if (UDebugFrameworkUISubsystem* Subsystem = It->GetSubsystem<UDebugFrameworkUISubsystem>())
            {
                return Subsystem;
            }
        }

        return nullptr;
    }

    static FAutoConsoleCommand CCmdDebugFrameworkUIDiag(
        TEXT("debugframework.uidiag"),
        TEXT("Print UI subsystem and panel state diagnostics."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            if (UDebugFrameworkUISubsystem* UISubsystem = FindUISubsystemForConsoleWorld(nullptr))
            {
                UISubsystem->DumpDiagnostics();
            }
            else
            {
                UE_LOG(LogDebugFramework, Warning, TEXT("UIDiag failed: no DebugFrameworkUISubsystem world found."));
            }
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkUIRebuild(
        TEXT("debugframework.uirebuild"),
        TEXT("Force rebuild of debug overlay widget and panel widgets."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            if (UDebugFrameworkUISubsystem* UISubsystem = FindUISubsystemForConsoleWorld(nullptr))
            {
                UISubsystem->ForceRebuildUI();
            }
            else
            {
                UE_LOG(LogDebugFramework, Warning, TEXT("UIRebuild failed: no DebugFrameworkUISubsystem world found."));
            }
        }));
}

void UDebugFrameworkUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    RefreshAccumulator = 0.f;
    LastLoggedPanelCount = INDEX_NONE;
}

void UDebugFrameworkUISubsystem::Deinitialize()
{
    for (TPair<FName, TObjectPtr<UDebugFrameworkPanelWidget>>& Pair : PanelWidgets)
    {
        if (Pair.Value)
        {
            Pair.Value->RemoveFromParent();
        }
    }
    PanelWidgets.Reset();

    if (OverlayWidget)
    {
        OverlayWidget->RemoveFromParent();
        OverlayWidget = nullptr;
    }

    if (ControlMenuWidget)
    {
        ControlMenuWidget->RemoveFromParent();
        ControlMenuWidget = nullptr;
    }

    for (TPair<FName, TObjectPtr<UDebugFrameworkToolPanelWidget>>& Pair : ToolPanels)
    {
        if (Pair.Value)
        {
            Pair.Value->RemoveFromParent();
        }
    }
    ToolPanels.Reset();

    LastLoggedPanelCount = INDEX_NONE;

    Super::Deinitialize();
}

void UDebugFrameworkUISubsystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    UDebugFrameworkSubsystem* DebugSubsystem = World->GetSubsystem<UDebugFrameworkSubsystem>();
    if (!DebugSubsystem)
    {
        return;
    }

    APlayerController* PlayerController = ResolveOwningPlayerController();
    if (!PlayerController)
    {
        return;
    }

    EnsureOverlayWidget(PlayerController);
    if (!OverlayWidget)
    {
        return;
    }

    EnsureControlMenuWidget(PlayerController);

    const bool bOverlayVisible = DebugSubsystem->IsVisible();
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const bool bMenuVisible = (Settings && Settings->bControlMenuFollowsOverlay)
        ? bOverlayVisible
        : (bOverlayVisible || ShouldForceMenuVisible(World, Settings));

    OverlayWidget->SetVisibility(bOverlayVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (ControlMenuWidget)
    {
        ControlMenuWidget->SetVisibility(bMenuVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
        ControlMenuWidget->SetIsEnabled(true);
        ControlMenuWidget->SetRenderOpacity(1.f);
    }
    const float RefreshInterval = Settings ? FMath::Max(0.02f, Settings->DataRefreshInterval) : 0.1f;

    RefreshAccumulator += DeltaTime;
    if (RefreshAccumulator < RefreshInterval)
    {
        return;
    }

    RefreshAccumulator = 0.f;
    if (!bOverlayVisible && !bMenuVisible)
    {
        return;
    }

    RefreshPanels(PlayerController, bOverlayVisible);
}

TStatId UDebugFrameworkUISubsystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UDebugFrameworkUISubsystem, STATGROUP_Tickables);
}

bool UDebugFrameworkUISubsystem::DoesSupportWorldType(EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::GamePreview;
}

void UDebugFrameworkUISubsystem::DumpDiagnostics() const
{
    const UWorld* World = GetWorld();
    UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: World=%s Type=%d"), *GetNameSafe(World), World ? static_cast<int32>(World->WorldType) : -1);

    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const UDebugFrameworkSubsystem* DebugSubsystem = World ? World->GetSubsystem<UDebugFrameworkSubsystem>() : nullptr;
    const bool bOverlayVisible = DebugSubsystem ? DebugSubsystem->IsVisible() : false;
    const bool bForceMenu = ShouldForceMenuVisible(World, Settings);
    UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: SettingsValid=%d ForceMenu=%d OverlayVisible=%d AlwaysMenuEditor=%d AlwaysMenuNonShipping=%d MenuFollowsOverlay=%d"),
        Settings != nullptr ? 1 : 0,
        bForceMenu ? 1 : 0,
        bOverlayVisible ? 1 : 0,
        Settings ? (Settings->bAlwaysShowControlMenuInEditor ? 1 : 0) : 0,
        Settings ? (Settings->bAlwaysShowControlMenuInNonShipping ? 1 : 0) : 0,
        Settings ? (Settings->bControlMenuFollowsOverlay ? 1 : 0) : 0);

    UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: OverlayValid=%d InViewport=%d Visibility=%d"),
        OverlayWidget != nullptr ? 1 : 0,
        (OverlayWidget && OverlayWidget->IsInViewport()) ? 1 : 0,
        OverlayWidget ? static_cast<int32>(OverlayWidget->GetVisibility()) : -1);

    UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: MenuValid=%d InViewport=%d Visibility=%d"),
        ControlMenuWidget != nullptr ? 1 : 0,
        (ControlMenuWidget && ControlMenuWidget->IsInViewport()) ? 1 : 0,
        ControlMenuWidget ? static_cast<int32>(ControlMenuWidget->GetVisibility()) : -1);

    if (ControlMenuWidget)
    {
        const FVector2D DesiredSize = ControlMenuWidget->GetDesiredSize();
        const FGeometry& Geometry = ControlMenuWidget->GetCachedGeometry();
        const FVector2D AbsPos = Geometry.GetAbsolutePosition();
        const FVector2D AbsSize = Geometry.GetAbsoluteSize();
        UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: MenuDesired=(%.1f, %.1f) MenuAbsPos=(%.1f, %.1f) MenuAbsSize=(%.1f, %.1f)"),
            DesiredSize.X, DesiredSize.Y, AbsPos.X, AbsPos.Y, AbsSize.X, AbsSize.Y);
    }

    UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: PanelWidgets=%d"), PanelWidgets.Num());

    for (const TPair<FName, TObjectPtr<UDebugFrameworkPanelWidget>>& Pair : PanelWidgets)
    {
        const UDebugFrameworkPanelWidget* Panel = Pair.Value.Get();
        const UCanvasPanelSlot* CanvasSlot = Panel ? Cast<UCanvasPanelSlot>(Panel->Slot) : nullptr;
        const FVector2D Position = CanvasSlot ? CanvasSlot->GetPosition() : FVector2D::ZeroVector;
        const FVector2D Size = CanvasSlot ? CanvasSlot->GetSize() : FVector2D::ZeroVector;

        UE_LOG(LogDebugFramework, Display, TEXT("UIDiag: Panel=%s Valid=%d Parent=%d Visibility=%d Pos=(%.1f, %.1f) Size=(%.1f, %.1f)"),
            *Pair.Key.ToString(),
            Panel ? 1 : 0,
            (Panel && Panel->GetParent()) ? 1 : 0,
            Panel ? static_cast<int32>(Panel->GetVisibility()) : -1,
            Position.X,
            Position.Y,
            Size.X,
            Size.Y);
    }
}

void UDebugFrameworkUISubsystem::ForceRebuildUI()
{
    for (TPair<FName, TObjectPtr<UDebugFrameworkPanelWidget>>& Pair : PanelWidgets)
    {
        if (Pair.Value)
        {
            Pair.Value->RemoveFromParent();
        }
    }
    PanelWidgets.Reset();

    if (OverlayWidget)
    {
        OverlayWidget->RemoveFromParent();
        OverlayWidget = nullptr;
    }

    if (ControlMenuWidget)
    {
        ControlMenuWidget->RemoveFromParent();
        ControlMenuWidget = nullptr;
    }

    RefreshAccumulator = 0.f;
    LastLoggedPanelCount = INDEX_NONE;
    UE_LOG(LogDebugFramework, Display, TEXT("UI rebuild requested. Overlay and panel widgets cleared."));
}

APlayerController* UDebugFrameworkUISubsystem::ResolveOwningPlayerController() const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return nullptr;
    }

    return DebugFramework::ResolvePlayerController(World, UDebugFrameworkSettings::Get());
}

void UDebugFrameworkUISubsystem::EnsureOverlayWidget(APlayerController* PlayerController)
{
    if (!PlayerController)
    {
        return;
    }

    if (OverlayWidget && IsValid(OverlayWidget))
    {
        if (!OverlayWidget->IsInViewport())
        {
            OverlayWidget->AddToViewport(DebugOverlayZOrder);
        }
        return;
    }

    OverlayWidget = CreateWidget<UDebugFrameworkOverlayWidget>(PlayerController, UDebugFrameworkOverlayWidget::StaticClass());
    if (OverlayWidget)
    {
        OverlayWidget->TakeWidget();
        OverlayWidget->AddToViewport(DebugOverlayZOrder);
        if (CVarDebugFrameworkLogUI.GetValueOnGameThread() != 0)
        {
            UE_LOG(LogDebugFramework, Display, TEXT("Debug overlay widget created and added to viewport. ZOrder=%d"), DebugOverlayZOrder);
        }
    }
}

void UDebugFrameworkUISubsystem::EnsureControlMenuWidget(APlayerController* PlayerController)
{
    if (!PlayerController)
    {
        return;
    }

    if (ControlMenuWidget && IsValid(ControlMenuWidget))
    {
        if (!ControlMenuWidget->IsInViewport())
        {
            ControlMenuWidget->AddToViewport(DebugControlMenuZOrder);
        }
        ControlMenuWidget->SetPositionInViewport(DebugControlMenuPosition, false);
        ControlMenuWidget->SetDesiredSizeInViewport(DebugControlMenuSize);
        return;
    }

    ControlMenuWidget = CreateWidget<UDebugFrameworkControlMenuWidget>(PlayerController, UDebugFrameworkControlMenuWidget::StaticClass());
    if (ControlMenuWidget)
    {
        ControlMenuWidget->TakeWidget();
        ControlMenuWidget->AddToViewport(DebugControlMenuZOrder);
        ControlMenuWidget->SetPositionInViewport(DebugControlMenuPosition, false);
        ControlMenuWidget->SetDesiredSizeInViewport(DebugControlMenuSize);
        ControlMenuWidget->SetVisibility(ESlateVisibility::Visible);
        ControlMenuWidget->SetIsEnabled(true);
        ControlMenuWidget->SetRenderOpacity(1.f);
    }
}

void UDebugFrameworkUISubsystem::RefreshPanels(APlayerController* PlayerController, bool bUpdatePanelWidgets)
{
    UWorld* World = GetWorld();
    UDebugFrameworkSubsystem* DebugSubsystem = World ? World->GetSubsystem<UDebugFrameworkSubsystem>() : nullptr;
    if (!DebugSubsystem || !OverlayWidget || !PlayerController)
    {
        return;
    }

    TArray<FDebugFrameworkPanelData> PanelData;
    DebugSubsystem->CollectPanelData(PanelData);

    if (ControlMenuWidget)
    {
        ControlMenuWidget->Setup(DebugSubsystem, this);
        ControlMenuWidget->RefreshMenu(PanelData);
    }

    if (CVarDebugFrameworkLogUI.GetValueOnGameThread() != 0 && LastLoggedPanelCount != PanelData.Num())
    {
        LastLoggedPanelCount = PanelData.Num();
        UE_LOG(LogDebugFramework, Display, TEXT("UI refresh: provider panels=%d, active widgets=%d, visible=%d, overlayInViewport=%d, overlayVis=%d, menuInViewport=%d"),
            PanelData.Num(),
            PanelWidgets.Num(),
            DebugSubsystem->IsVisible() ? 1 : 0,
            OverlayWidget && OverlayWidget->IsInViewport() ? 1 : 0,
            OverlayWidget ? static_cast<int32>(OverlayWidget->GetVisibility()) : -1,
            ControlMenuWidget && ControlMenuWidget->IsInViewport() ? 1 : 0);
    }

    if (!bUpdatePanelWidgets)
    {
        return;
    }

    TSet<FName> ActivePanelIds;
    for (const FDebugFrameworkPanelData& Data : PanelData)
    {
        if (Data.PanelId.IsNone())
        {
            continue;
        }

        if (!DebugSubsystem->IsPanelVisible(Data.PanelId))
        {
            continue;
        }

        ActivePanelIds.Add(Data.PanelId);

        UDebugFrameworkPanelWidget* PanelWidget = nullptr;
        if (TObjectPtr<UDebugFrameworkPanelWidget>* Existing = PanelWidgets.Find(Data.PanelId))
        {
            PanelWidget = Existing->Get();
        }

        if (!PanelWidget || !IsValid(PanelWidget))
        {
            PanelWidget = CreateWidget<UDebugFrameworkPanelWidget>(PlayerController, UDebugFrameworkPanelWidget::StaticClass());
            if (!PanelWidget)
            {
                continue;
            }

            PanelWidget->TakeWidget();
            FDebugFrameworkPanelLayout Layout;
            DebugSubsystem->GetOrCreatePanelLayout(Data.PanelId, Layout);
            if (!OverlayWidget->AddPanelWidget(PanelWidget, Layout.Position, Layout.Size))
            {
                if (CVarDebugFrameworkLogUI.GetValueOnGameThread() != 0)
                {
                    UE_LOG(LogDebugFramework, Warning, TEXT("AddPanelWidget failed for panel %s (new widget)."), *Data.PanelId.ToString());
                }
                continue;
            }
            PanelWidgets.Add(Data.PanelId, PanelWidget);
        }
        else if (!PanelWidget->GetParent())
        {
            FDebugFrameworkPanelLayout Layout;
            DebugSubsystem->GetOrCreatePanelLayout(Data.PanelId, Layout);
            if (!OverlayWidget->AddPanelWidget(PanelWidget, Layout.Position, Layout.Size))
            {
                if (CVarDebugFrameworkLogUI.GetValueOnGameThread() != 0)
                {
                    UE_LOG(LogDebugFramework, Warning, TEXT("AddPanelWidget failed for panel %s (reattach)."), *Data.PanelId.ToString());
                }
                continue;
            }
        }

        FDebugFrameworkPanelLayout CurrentLayout;
        DebugSubsystem->GetOrCreatePanelLayout(Data.PanelId, CurrentLayout);
        PanelWidget->ApplyLayout(CurrentLayout);

        PanelWidget->SetupPanel(DebugSubsystem, Data.PanelId, Data.Title);
        PanelWidget->ApplyPanelData(Data);
        PanelWidget->SetVisibility(ESlateVisibility::Visible);
    }

    RemoveStalePanels(ActivePanelIds);

    if (bUpdatePanelWidgets)
    {
        for (auto It = ToolPanels.CreateIterator(); It; ++It)
        {
            UDebugFrameworkToolPanelWidget* ToolPanel = It.Value().Get();
            if (!ToolPanel || !IsValid(ToolPanel))
            {
                It.RemoveCurrent();
                continue;
            }

            const FName LayoutId = FName(*FString::Printf(TEXT("ToolPanel.%s"), *ToolPanel->GetToolId().ToString()));
            FDebugFrameworkPanelLayout Layout;
            DebugSubsystem->GetOrCreatePanelLayout(LayoutId, Layout);
            ToolPanel->ApplyLayout(Layout);
            ToolPanel->RefreshPanels(PanelData);
        }
    }
}

void UDebugFrameworkUISubsystem::RemoveStalePanels(const TSet<FName>& ActivePanelIds)
{
    for (auto It = PanelWidgets.CreateIterator(); It; ++It)
    {
        UDebugFrameworkPanelWidget* PanelWidget = It.Value().Get();
        const bool bShouldRemove = !PanelWidget || !IsValid(PanelWidget) || !ActivePanelIds.Contains(It.Key());
        if (bShouldRemove)
        {
            if (PanelWidget)
            {
                PanelWidget->RemoveFromParent();
            }
            It.RemoveCurrent();
        }
    }
}

void UDebugFrameworkUISubsystem::OpenToolPanel(FName ToolId, const FText& ToolTitle)
{
    if (ToolId.IsNone())
    {
        return;
    }

    UWorld* World = GetWorld();
    UDebugFrameworkSubsystem* DebugSubsystem = World ? World->GetSubsystem<UDebugFrameworkSubsystem>() : nullptr;
    APlayerController* PlayerController = ResolveOwningPlayerController();
    if (!World || !DebugSubsystem || !PlayerController || !OverlayWidget)
    {
        return;
    }

    DebugSubsystem->SetVisible(true);

    if (TObjectPtr<UDebugFrameworkToolPanelWidget>* Existing = ToolPanels.Find(ToolId))
    {
        if (Existing->Get() && IsValid(Existing->Get()))
        {
            (*Existing)->SetVisibility(ESlateVisibility::Visible);
            return;
        }
    }

    UDebugFrameworkToolPanelWidget* ToolPanel = CreateWidget<UDebugFrameworkToolPanelWidget>(PlayerController, UDebugFrameworkToolPanelWidget::StaticClass());
    if (!ToolPanel)
    {
        return;
    }

    ToolPanel->TakeWidget();
    ToolPanel->SetupToolPanel(this, DebugSubsystem, ToolId, ToolTitle);

    const FName LayoutId = FName(*FString::Printf(TEXT("ToolPanel.%s"), *ToolId.ToString()));
    FDebugFrameworkPanelLayout Layout;
    DebugSubsystem->GetOrCreatePanelLayout(LayoutId, Layout);
    if (OverlayWidget->AddPanelWidget(ToolPanel, Layout.Position, Layout.Size))
    {
        ToolPanel->ApplyLayout(Layout);
        ToolPanels.Add(ToolId, ToolPanel);
    }
}

void UDebugFrameworkUISubsystem::CloseToolPanel(FName ToolId)
{
    if (ToolId.IsNone())
    {
        return;
    }

    TObjectPtr<UDebugFrameworkToolPanelWidget>* Existing = ToolPanels.Find(ToolId);
    if (!Existing)
    {
        return;
    }

    if (Existing->Get() && IsValid(Existing->Get()))
    {
        (*Existing)->RemoveFromParent();
    }
    ToolPanels.Remove(ToolId);
}
