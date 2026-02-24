#include "DebugFramework/DebugFrameworkSubsystem.h"

#include "Algo/Sort.h"
#include "DebugFramework/DebugFrameworkLog.h"
#include "DebugFramework/DebugFrameworkPlayerControllerUtils.h"
#include "DebugFramework/DebugFrameworkProvider.h"
#include "DebugFramework/DebugFrameworkSettings.h"
#include "DebugFramework/DebugFrameworkUserSettings.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "HAL/IConsoleManager.h"
#include "HAL/PlatformTime.h"
#include "Misc/ConfigCacheIni.h"
#include "UObject/UObjectIterator.h"

namespace
{
    static TAutoConsoleVariable<int32> CVarDebugFrameworkLogInput(
        TEXT("debugframework.LogInput"),
        0,
        TEXT("Enable debug framework input logs (0/1)."),
        ECVF_Cheat);

    static bool IsCtrlDown(const APlayerController* PlayerController)
    {
        return PlayerController
            && (PlayerController->IsInputKeyDown(EKeys::LeftControl) || PlayerController->IsInputKeyDown(EKeys::RightControl));
    }

    static bool IsAltDown(const APlayerController* PlayerController)
    {
        return PlayerController
            && (PlayerController->IsInputKeyDown(EKeys::LeftAlt) || PlayerController->IsInputKeyDown(EKeys::RightAlt));
    }

    static bool IsShiftDown(const APlayerController* PlayerController)
    {
        return PlayerController
            && (PlayerController->IsInputKeyDown(EKeys::LeftShift) || PlayerController->IsInputKeyDown(EKeys::RightShift));
    }

    static bool IsCmdDown(const APlayerController* PlayerController)
    {
        return PlayerController
            && (PlayerController->IsInputKeyDown(EKeys::LeftCommand) || PlayerController->IsInputKeyDown(EKeys::RightCommand));
    }

    static bool AreChordModifiersSatisfied(const APlayerController* PlayerController, const FDebugFrameworkInputChord& Chord)
    {
        const bool bCtrlDown = IsCtrlDown(PlayerController);
        const bool bAltDown = IsAltDown(PlayerController);
        const bool bShiftDown = IsShiftDown(PlayerController);
        const bool bCmdDown = IsCmdDown(PlayerController);

        if (Chord.bRequireExactModifiers)
        {
            return bCtrlDown == Chord.bCtrl
                && bAltDown == Chord.bAlt
                && bShiftDown == Chord.bShift
                && bCmdDown == Chord.bCmd;
        }

        return (!Chord.bCtrl || bCtrlDown)
            && (!Chord.bAlt || bAltDown)
            && (!Chord.bShift || bShiftDown)
            && (!Chord.bCmd || bCmdDown);
    }

    static FDebugFrameworkInputChord ResolveToggleChord(const UDebugFrameworkSettings* Settings)
    {
        FDebugFrameworkInputChord Chord;
        if (Settings)
        {
            Chord = Settings->ToggleVisibilityChord;
            if (!Chord.IsValid() && Settings->ToggleVisibilityKey.IsValid())
            {
                Chord.Key = Settings->ToggleVisibilityKey;
                Chord.bCtrl = false;
                Chord.bAlt = false;
                Chord.bShift = false;
                Chord.bCmd = false;
                Chord.bRequireExactModifiers = false;
            }
        }
        return Chord;
    }

    static FString BuildChordString(const FDebugFrameworkInputChord& Chord)
    {
        return FString::Printf(
            TEXT("Key=%s Ctrl=%d Alt=%d Shift=%d Cmd=%d Exact=%d"),
            *Chord.Key.GetDisplayName().ToString(),
            Chord.bCtrl ? 1 : 0,
            Chord.bAlt ? 1 : 0,
            Chord.bShift ? 1 : 0,
            Chord.bCmd ? 1 : 0,
            Chord.bRequireExactModifiers ? 1 : 0);
    }

    static FString BuildModifierStateString(const APlayerController* PlayerController)
    {
        return FString::Printf(
            TEXT("Ctrl=%d Alt=%d Shift=%d Cmd=%d"),
            IsCtrlDown(PlayerController) ? 1 : 0,
            IsAltDown(PlayerController) ? 1 : 0,
            IsShiftDown(PlayerController) ? 1 : 0,
            IsCmdDown(PlayerController) ? 1 : 0);
    }

    static UDebugFrameworkSubsystem* FindSubsystemForConsoleWorld(UWorld* InWorld)
    {
        if (InWorld)
        {
            return InWorld->GetSubsystem<UDebugFrameworkSubsystem>();
        }

        if (!GEngine)
        {
            return nullptr;
        }

        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            UWorld* ContextWorld = Context.World();
            if (!ContextWorld)
            {
                continue;
            }
            if (UDebugFrameworkSubsystem* Subsystem = ContextWorld->GetSubsystem<UDebugFrameworkSubsystem>())
            {
                return Subsystem;
            }
        }

        for (TObjectIterator<UWorld> It; It; ++It)
        {
            UWorld* CandidateWorld = *It;
            if (!CandidateWorld)
            {
                continue;
            }

            if (UDebugFrameworkSubsystem* Subsystem = CandidateWorld->GetSubsystem<UDebugFrameworkSubsystem>())
            {
                return Subsystem;
            }
        }

        return nullptr;
    }

    static const TCHAR* WorldTypeToString(EWorldType::Type WorldType)
    {
        switch (WorldType)
        {
        case EWorldType::None: return TEXT("None");
        case EWorldType::Game: return TEXT("Game");
        case EWorldType::Editor: return TEXT("Editor");
        case EWorldType::PIE: return TEXT("PIE");
        case EWorldType::EditorPreview: return TEXT("EditorPreview");
        case EWorldType::GamePreview: return TEXT("GamePreview");
        case EWorldType::GameRPC: return TEXT("GameRPC");
        case EWorldType::Inactive: return TEXT("Inactive");
        default: return TEXT("Unknown");
        }
    }

    static void LogWorldDiagnostics()
    {
        if (!GEngine)
        {
            UE_LOG(LogDebugFramework, Warning, TEXT("No GEngine when collecting world diagnostics."));
            return;
        }

        int32 ContextCount = 0;
        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            ++ContextCount;
            UWorld* World = Context.World();
            const bool bHasWorld = (World != nullptr);
            const bool bHasSubsystem = World && World->GetSubsystem<UDebugFrameworkSubsystem>() != nullptr;

            UE_LOG(
                LogDebugFramework,
                Display,
                TEXT("WorldContext[%d]: Type=%s HasWorld=%d WorldName=%s HasDebugSubsystem=%d"),
                ContextCount - 1,
                World ? WorldTypeToString(World->WorldType) : TEXT("NoWorld"),
                bHasWorld ? 1 : 0,
                World ? *World->GetName() : TEXT("None"),
                bHasSubsystem ? 1 : 0);
        }

        UE_LOG(LogDebugFramework, Display, TEXT("World diagnostics complete. ContextCount=%d"), ContextCount);
    }

    static void ToggleVisibilityFromConsole(UWorld* InWorld)
    {
        if (UDebugFrameworkSubsystem* Subsystem = FindSubsystemForConsoleWorld(InWorld))
        {
            Subsystem->ToggleVisible();
            UE_LOG(LogDebugFramework, Display, TEXT("Console toggle executed. Visible=%d"), Subsystem->IsVisible() ? 1 : 0);
            return;
        }

        UE_LOG(LogDebugFramework, Warning, TEXT("Console toggle failed: no DebugFrameworkSubsystem world found."));
    }

    static void SetVisibilityFromConsole(UWorld* InWorld, bool bVisible)
    {
        if (UDebugFrameworkSubsystem* Subsystem = FindSubsystemForConsoleWorld(InWorld))
        {
            Subsystem->SetVisible(bVisible);
            UE_LOG(LogDebugFramework, Display, TEXT("Console set visibility executed. Visible=%d"), Subsystem->IsVisible() ? 1 : 0);
            return;
        }

        UE_LOG(LogDebugFramework, Warning, TEXT("Console set visibility failed: no DebugFrameworkSubsystem world found."));
    }

    static void ResetLayoutsFromConsole(UWorld* InWorld)
    {
        if (UDebugFrameworkSubsystem* Subsystem = FindSubsystemForConsoleWorld(InWorld))
        {
            Subsystem->ResetPanelLayouts();
            UE_LOG(LogDebugFramework, Display, TEXT("Console reset layout executed."));
            return;
        }

        UE_LOG(LogDebugFramework, Warning, TEXT("Console reset layout failed: no DebugFrameworkSubsystem world found."));
    }

    static FAutoConsoleCommand CCmdDebugFrameworkToggle(
        TEXT("debugframework.toggle"),
        TEXT("Toggle debug framework overlay visibility."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            ToggleVisibilityFromConsole(nullptr);
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkShow(
        TEXT("debugframework.show"),
        TEXT("Show debug framework overlay."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            SetVisibilityFromConsole(nullptr, true);
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkHide(
        TEXT("debugframework.hide"),
        TEXT("Hide debug framework overlay."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            SetVisibilityFromConsole(nullptr, false);
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkResetLayout(
        TEXT("debugframework.resetlayout"),
        TEXT("Clear saved panel layout and rebuild at default positions."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            ResetLayoutsFromConsole(nullptr);
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkShowAllPanels(
        TEXT("debugframework.showallpanels"),
        TEXT("Show all debug panels that were closed from the overlay."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            if (UDebugFrameworkSubsystem* Subsystem = FindSubsystemForConsoleWorld(nullptr))
            {
                Subsystem->ShowAllPanels();
                UE_LOG(LogDebugFramework, Display, TEXT("Console show all panels executed."));
            }
            else
            {
                UE_LOG(LogDebugFramework, Warning, TEXT("Console show all panels failed: no DebugFrameworkSubsystem world found."));
            }
        }));

    static FAutoConsoleCommand CCmdDebugFrameworkDiag(
        TEXT("debugframework.diag"),
        TEXT("Print world contexts and debug subsystem presence."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            LogWorldDiagnostics();
        }));
}

void UDebugFrameworkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    LoadUserSettings();
}

void UDebugFrameworkSubsystem::Deinitialize()
{
    FlushUserSettingsIfDirty(true);
    RegisteredProviders.Reset();
    PanelLayoutsById.Reset();
    Super::Deinitialize();
}

void UDebugFrameworkSubsystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    PollVisibilityToggleInput();
    CleanupInvalidProviders();
    FlushUserSettingsIfDirty(false);
}

TStatId UDebugFrameworkSubsystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UDebugFrameworkSubsystem, STATGROUP_Tickables);
}

bool UDebugFrameworkSubsystem::DoesSupportWorldType(EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::GamePreview;
}

void UDebugFrameworkSubsystem::RegisterProvider(UObject* ProviderObject)
{
    if (!ProviderObject || !ProviderObject->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()))
    {
        return;
    }

    for (const TWeakObjectPtr<UObject>& Existing : RegisteredProviders)
    {
        if (Existing.Get() == ProviderObject)
        {
            return;
        }
    }

    RegisteredProviders.Add(ProviderObject);
    ProvidersChangedEvent.Broadcast();
}

void UDebugFrameworkSubsystem::UnregisterProvider(UObject* ProviderObject)
{
    if (!ProviderObject)
    {
        return;
    }

    const int32 RemovedCount = RegisteredProviders.RemoveAll(
        [ProviderObject](const TWeakObjectPtr<UObject>& Entry)
        {
            return Entry.Get() == ProviderObject;
        });

    if (RemovedCount > 0)
    {
        ProvidersChangedEvent.Broadcast();
    }
}

void UDebugFrameworkSubsystem::SetVisible(bool bInVisible)
{
    if (bVisible == bInVisible)
    {
        return;
    }

    bVisible = bInVisible;
    MarkSettingsDirty();
    VisibilityChangedEvent.Broadcast(bVisible);
    UE_LOG(LogDebugFramework, Display, TEXT("Overlay visibility changed: %d"), bVisible ? 1 : 0);
}

void UDebugFrameworkSubsystem::ToggleVisible()
{
    SetVisible(!bVisible);
}

void UDebugFrameworkSubsystem::SetToggleVisibilityChord(const FDebugFrameworkInputChord& InChord, bool bSaveConfig)
{
    if (!InChord.IsValid())
    {
        return;
    }

    UDebugFrameworkSettings* MutableSettings = GetMutableDefault<UDebugFrameworkSettings>();
    if (!MutableSettings)
    {
        return;
    }

    MutableSettings->ToggleVisibilityChord = InChord;
    if (bSaveConfig)
    {
        MutableSettings->SaveConfig();
    }
}

FDebugFrameworkInputChord UDebugFrameworkSubsystem::GetToggleVisibilityChord() const
{
    return ResolveToggleChord(UDebugFrameworkSettings::Get());
}

void UDebugFrameworkSubsystem::CollectPanelData(TArray<FDebugFrameworkPanelData>& OutPanels) const
{
    OutPanels.Reset();

    for (const TWeakObjectPtr<UObject>& Entry : RegisteredProviders)
    {
        UObject* ProviderObject = Entry.Get();
        if (!ProviderObject || !ProviderObject->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()))
        {
            continue;
        }

        FDebugFrameworkPanelData PanelData;
        PanelData.PanelId = IDebugFrameworkProvider::Execute_GetDebugPanelId(ProviderObject);
        if (PanelData.PanelId.IsNone())
        {
            continue;
        }

        PanelData.Title = IDebugFrameworkProvider::Execute_GetDebugPanelTitle(ProviderObject);
        if (PanelData.Title.IsEmpty())
        {
            PanelData.Title = FText::FromName(PanelData.PanelId);
        }

        PanelData.ToolId = IDebugFrameworkProvider::Execute_GetDebugToolId(ProviderObject);
        if (PanelData.ToolId.IsNone())
        {
            PanelData.ToolId = PanelData.PanelId;
        }

        PanelData.ToolTitle = IDebugFrameworkProvider::Execute_GetDebugToolTitle(ProviderObject);
        if (PanelData.ToolTitle.IsEmpty())
        {
            PanelData.ToolTitle = FText::FromName(PanelData.ToolId);
        }

        PanelData.SortOrder = IDebugFrameworkProvider::Execute_GetDebugSortOrder(ProviderObject);
        IDebugFrameworkProvider::Execute_GatherDebugRows(ProviderObject, PanelData.Rows);
        OutPanels.Add(MoveTemp(PanelData));
    }

    Algo::Sort(OutPanels, [](const FDebugFrameworkPanelData& A, const FDebugFrameworkPanelData& B)
    {
        if (A.SortOrder != B.SortOrder)
        {
            return A.SortOrder < B.SortOrder;
        }
        return A.PanelId.ToString() < B.PanelId.ToString();
    });
}

bool UDebugFrameworkSubsystem::GetOrCreatePanelLayout(FName PanelId, FDebugFrameworkPanelLayout& OutLayout)
{
    if (PanelId.IsNone())
    {
        return false;
    }

    if (FDebugFrameworkPanelLayout* Existing = PanelLayoutsById.Find(PanelId))
    {
        OutLayout = *Existing;
        return true;
    }

    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const FVector2D BasePosition = Settings ? Settings->DefaultPanelPosition : FVector2D(80.f, 80.f);
    const FVector2D BaseSize = Settings ? Settings->DefaultPanelSize : FVector2D(420.f, 260.f);
    const float CascadeOffset = 26.f * static_cast<float>(PanelLayoutsById.Num());

    FDebugFrameworkPanelLayout NewLayout;
    NewLayout.PanelId = PanelId;
    NewLayout.Position = BasePosition + FVector2D(CascadeOffset, CascadeOffset);
    NewLayout.Size = BaseSize;

    UpdatePanelLayout(NewLayout);
    OutLayout = NewLayout;
    return false;
}

void UDebugFrameworkSubsystem::UpdatePanelLayout(const FDebugFrameworkPanelLayout& InLayout)
{
    if (InLayout.PanelId.IsNone())
    {
        return;
    }

    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const FVector2D MinSize = Settings ? Settings->MinPanelSize : FVector2D(220.f, 140.f);
    const FVector2D MaxSize = Settings ? Settings->MaxPanelSize : FVector2D(1200.f, 900.f);

    FDebugFrameworkPanelLayout Clamped = InLayout;
    Clamped.Size.X = FMath::Clamp(Clamped.Size.X, MinSize.X, MaxSize.X);
    Clamped.Size.Y = FMath::Clamp(Clamped.Size.Y, MinSize.Y, MaxSize.Y);

    FDebugFrameworkPanelLayout* Existing = PanelLayoutsById.Find(Clamped.PanelId);
    if (Existing && Existing->Position.Equals(Clamped.Position, 0.1f) && Existing->Size.Equals(Clamped.Size, 0.1f))
    {
        return;
    }

    PanelLayoutsById.Add(Clamped.PanelId, Clamped);
    MarkSettingsDirty();
}

void UDebugFrameworkSubsystem::ResetPanelLayouts()
{
    PanelLayoutsById.Reset();
    MarkSettingsDirty();
    UE_LOG(LogDebugFramework, Display, TEXT("Panel layouts reset."));
}

void UDebugFrameworkSubsystem::SetPanelVisible(FName PanelId, bool bInVisible)
{
    if (PanelId.IsNone())
    {
        return;
    }

    const bool bWasHidden = HiddenPanelIds.Contains(PanelId);
    if (bInVisible)
    {
        HiddenPanelIds.Remove(PanelId);
    }
    else
    {
        HiddenPanelIds.Add(PanelId);
    }

    const bool bIsHidden = HiddenPanelIds.Contains(PanelId);
    if (bWasHidden != bIsHidden)
    {
        MarkSettingsDirty();
        ProvidersChangedEvent.Broadcast();
        UE_LOG(LogDebugFramework, Display, TEXT("Panel visibility changed: %s -> %d"), *PanelId.ToString(), bInVisible ? 1 : 0);
    }
}

bool UDebugFrameworkSubsystem::IsPanelVisible(FName PanelId) const
{
    if (PanelId.IsNone())
    {
        return false;
    }

    return !HiddenPanelIds.Contains(PanelId);
}

void UDebugFrameworkSubsystem::ShowAllPanels()
{
    if (HiddenPanelIds.Num() == 0)
    {
        return;
    }

    HiddenPanelIds.Reset();
    MarkSettingsDirty();
    ProvidersChangedEvent.Broadcast();
    UE_LOG(LogDebugFramework, Display, TEXT("All panels are now visible."));
}

void UDebugFrameworkSubsystem::CleanupInvalidProviders()
{
    const int32 RemovedCount = RegisteredProviders.RemoveAll(
        [](const TWeakObjectPtr<UObject>& Entry)
        {
            UObject* ProviderObject = Entry.Get();
            return !ProviderObject || !ProviderObject->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass());
        });

    if (RemovedCount > 0)
    {
        ProvidersChangedEvent.Broadcast();
    }
}

void UDebugFrameworkSubsystem::PollVisibilityToggleInput()
{
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    if (!Settings)
    {
        bToggleKeyWasDown = false;
        return;
    }

    const FDebugFrameworkInputChord ToggleChord = ResolveToggleChord(Settings);
    if (!ToggleChord.IsValid())
    {
        bToggleKeyWasDown = false;
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        bToggleKeyWasDown = false;
        return;
    }

    APlayerController* PlayerController = DebugFramework::ResolvePlayerController(World, Settings);

    if (!PlayerController)
    {
        bToggleKeyWasDown = false;
        return;
    }

    const bool bKeyDownNow = PlayerController->IsInputKeyDown(ToggleChord.Key);
    const bool bModsSatisfied = AreChordModifiersSatisfied(PlayerController, ToggleChord);

    if (bKeyDownNow && !bToggleKeyWasDown)
    {
        if (bModsSatisfied)
        {
            ToggleVisible();
            if (CVarDebugFrameworkLogInput.GetValueOnGameThread() != 0)
            {
                UE_LOG(LogDebugFramework, Display, TEXT("Toggle chord matched (%s). Visible=%d"),
                    *BuildChordString(ToggleChord),
                    bVisible ? 1 : 0);
            }
        }
        else if (CVarDebugFrameworkLogInput.GetValueOnGameThread() != 0)
        {
            UE_LOG(LogDebugFramework, Display, TEXT("Toggle key pressed but modifiers did not match. Required=[%s], Current=[%s]"),
                *BuildChordString(ToggleChord),
                *BuildModifierStateString(PlayerController));
        }
    }

    bToggleKeyWasDown = bKeyDownNow;
}

void UDebugFrameworkSubsystem::LoadUserSettings()
{
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    bVisible = Settings ? Settings->bEnabledByDefault : true;

    bool bVisibleFromConfig = false;
    if (GConfig && GConfig->GetBool(TEXT("/Script/DebugFrameworkCore.DebugFrameworkUserSettings"), TEXT("bVisible"), bVisibleFromConfig, GGameUserSettingsIni))
    {
        bVisible = bVisibleFromConfig;
    }

    const UWorld* World = GetWorld();
    const EWorldType::Type WorldType = World
        ? World->WorldType.GetValue()
        : EWorldType::None;
    const bool bIsEditorContext = WorldType == EWorldType::Editor
        || WorldType == EWorldType::EditorPreview
        || WorldType == EWorldType::PIE;

#if WITH_EDITOR
    if (((Settings && Settings->bForceVisibleInEditor) || !Settings) && bIsEditorContext)
    {
        bVisible = true;
    }
#endif

#if !UE_BUILD_SHIPPING
    if (Settings && Settings->bForceVisibleInNonShipping)
    {
        bVisible = true;
    }
#endif

    const UDebugFrameworkUserSettings* UserSettings = UDebugFrameworkUserSettings::Get();
    if (!UserSettings)
    {
        return;
    }

    PanelLayoutsById.Reset();
    HiddenPanelIds.Reset();
    for (const FDebugFrameworkPanelLayout& Layout : UserSettings->PanelLayouts)
    {
        if (!Layout.PanelId.IsNone())
        {
            PanelLayoutsById.Add(Layout.PanelId, Layout);
        }
    }

    for (const FName HiddenId : UserSettings->HiddenPanelIds)
    {
        if (!HiddenId.IsNone())
        {
            HiddenPanelIds.Add(HiddenId);
        }
    }
}

void UDebugFrameworkSubsystem::MarkSettingsDirty()
{
    bSettingsDirty = true;
}

void UDebugFrameworkSubsystem::FlushUserSettingsIfDirty(bool bForce)
{
    if (!bSettingsDirty)
    {
        return;
    }

    const double NowSeconds = FPlatformTime::Seconds();
    const UDebugFrameworkSettings* Settings = UDebugFrameworkSettings::Get();
    const double SaveThrottleSeconds = Settings ? static_cast<double>(Settings->SaveThrottleSeconds) : 0.5;

    if (!bForce && (NowSeconds - LastSaveTimeSeconds) < SaveThrottleSeconds)
    {
        return;
    }

    UDebugFrameworkUserSettings* UserSettings = UDebugFrameworkUserSettings::GetMutable();
    if (!UserSettings)
    {
        return;
    }

    UserSettings->bVisible = bVisible;
    UserSettings->PanelLayouts.Reset();
    UserSettings->PanelLayouts.Reserve(PanelLayoutsById.Num());
    for (const TPair<FName, FDebugFrameworkPanelLayout>& Pair : PanelLayoutsById)
    {
        UserSettings->PanelLayouts.Add(Pair.Value);
    }

    UserSettings->HiddenPanelIds.Reset();
    UserSettings->HiddenPanelIds.Reserve(HiddenPanelIds.Num());
    for (const FName HiddenId : HiddenPanelIds)
    {
        UserSettings->HiddenPanelIds.Add(HiddenId);
    }
    UserSettings->SaveConfig();

    LastSaveTimeSeconds = NowSeconds;
    bSettingsDirty = false;
}
