#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DebugFrameworkUISubsystem.generated.h"

class APlayerController;
class UDebugFrameworkControlMenuWidget;
class UDebugFrameworkOverlayWidget;
class UDebugFrameworkPanelWidget;
class UDebugFrameworkToolPanelWidget;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkUISubsystem : public UTickableWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;
    virtual bool IsTickableInEditor() const override { return true; }
    virtual bool DoesSupportWorldType(EWorldType::Type WorldType) const override;

    void DumpDiagnostics() const;
    void ForceRebuildUI();
    void OpenToolPanel(FName ToolId, const FText& ToolTitle);
    void CloseToolPanel(FName ToolId);

private:
    APlayerController* ResolveOwningPlayerController() const;
    void EnsureOverlayWidget(APlayerController* PlayerController);
    void EnsureControlMenuWidget(APlayerController* PlayerController);
    void RefreshPanels(APlayerController* PlayerController, bool bUpdatePanelWidgets);
    void RemoveStalePanels(const TSet<FName>& ActivePanelIds);

    UPROPERTY(Transient)
    TObjectPtr<UDebugFrameworkOverlayWidget> OverlayWidget = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UDebugFrameworkControlMenuWidget> ControlMenuWidget = nullptr;

    UPROPERTY(Transient)
    TMap<FName, TObjectPtr<UDebugFrameworkPanelWidget>> PanelWidgets;

    UPROPERTY(Transient)
    TMap<FName, TObjectPtr<UDebugFrameworkToolPanelWidget>> ToolPanels;

    float RefreshAccumulator = 0.f;
    int32 LastLoggedPanelCount = INDEX_NONE;
};
