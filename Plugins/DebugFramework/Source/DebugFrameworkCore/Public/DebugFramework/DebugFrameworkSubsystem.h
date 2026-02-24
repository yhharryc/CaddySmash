#pragma once

#include "CoreMinimal.h"
#include "DebugFrameworkSettings.h"
#include "Subsystems/WorldSubsystem.h"
#include "DebugFrameworkTypes.h"
#include "DebugFrameworkSubsystem.generated.h"

class UDebugFrameworkUserSettings;

DECLARE_MULTICAST_DELEGATE(FDebugFrameworkProvidersChanged);
DECLARE_MULTICAST_DELEGATE_OneParam(FDebugFrameworkVisibilityChanged, bool);

UCLASS()
class DEBUGFRAMEWORKCORE_API UDebugFrameworkSubsystem : public UTickableWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;
    virtual bool IsTickableInEditor() const override { return true; }
    virtual bool DoesSupportWorldType(EWorldType::Type WorldType) const override;

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void RegisterProvider(UObject* ProviderObject);

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void UnregisterProvider(UObject* ProviderObject);

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void SetVisible(bool bInVisible);

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void ToggleVisible();

    UFUNCTION(BlueprintPure, Category="DebugFramework")
    bool IsVisible() const { return bVisible; }

    UFUNCTION(BlueprintCallable, Category="DebugFramework|Input")
    void SetToggleVisibilityChord(const FDebugFrameworkInputChord& InChord, bool bSaveConfig = true);

    UFUNCTION(BlueprintPure, Category="DebugFramework|Input")
    FDebugFrameworkInputChord GetToggleVisibilityChord() const;

    void CollectPanelData(TArray<FDebugFrameworkPanelData>& OutPanels) const;

    bool GetOrCreatePanelLayout(FName PanelId, FDebugFrameworkPanelLayout& OutLayout);
    void UpdatePanelLayout(const FDebugFrameworkPanelLayout& InLayout);

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void ResetPanelLayouts();

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void SetPanelVisible(FName PanelId, bool bInVisible);

    UFUNCTION(BlueprintPure, Category="DebugFramework")
    bool IsPanelVisible(FName PanelId) const;

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    void ShowAllPanels();

    FDebugFrameworkProvidersChanged& OnProvidersChanged() { return ProvidersChangedEvent; }
    FDebugFrameworkVisibilityChanged& OnVisibilityChanged() { return VisibilityChangedEvent; }

private:
    void CleanupInvalidProviders();
    void PollVisibilityToggleInput();
    void LoadUserSettings();
    void MarkSettingsDirty();
    void FlushUserSettingsIfDirty(bool bForce);

    bool bVisible = true;
    bool bSettingsDirty = false;
    bool bToggleKeyWasDown = false;
    double LastSaveTimeSeconds = 0.0;

    TArray<TWeakObjectPtr<UObject>> RegisteredProviders;
    TMap<FName, FDebugFrameworkPanelLayout> PanelLayoutsById;
    TSet<FName> HiddenPanelIds;

    FDebugFrameworkProvidersChanged ProvidersChangedEvent;
    FDebugFrameworkVisibilityChanged VisibilityChangedEvent;
};
