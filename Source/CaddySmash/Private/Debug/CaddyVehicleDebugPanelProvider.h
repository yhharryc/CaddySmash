#pragma once

#include "CoreMinimal.h"
#include "DebugFramework/DebugFrameworkProvider.h"
#include "CaddyVehicleDebugPanelProvider.generated.h"

class ACaddyVehiclePawn;

UENUM()
enum class ECaddyVehicleDebugPanelType : uint8
{
    Core,
    Input,
    Tuning,
    Camera,
    Collision,
    DebugDraw
};

UCLASS()
class CADDYSMASH_API UCaddyVehicleDebugPanelProvider : public UObject, public IDebugFrameworkProvider
{
    GENERATED_BODY()

public:
    void Initialize(
        ACaddyVehiclePawn* InVehiclePawn,
        FName InPanelId,
        const FText& InPanelTitle,
        FName InToolId,
        const FText& InToolTitle,
        int32 InSortOrder,
        ECaddyVehicleDebugPanelType InPanelType);

    virtual FName GetDebugPanelId_Implementation() const override;
    virtual FText GetDebugPanelTitle_Implementation() const override;
    virtual FName GetDebugToolId_Implementation() const override;
    virtual FText GetDebugToolTitle_Implementation() const override;
    virtual int32 GetDebugSortOrder_Implementation() const override;
    virtual void GatherDebugRows_Implementation(TArray<FDebugFrameworkPanelRow>& OutRows) const override;

private:
    void GatherCoreRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;
    void GatherInputRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;
    void GatherTuningRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;
    void GatherCameraRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;
    void GatherCollisionRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;
    void GatherDebugDrawRows(TArray<FDebugFrameworkPanelRow>& OutRows) const;

    TWeakObjectPtr<ACaddyVehiclePawn> VehiclePawn;
    FName PanelId = NAME_None;
    FText PanelTitle;
    FName ToolId = NAME_None;
    FText ToolTitle;
    int32 SortOrder = 0;
    ECaddyVehicleDebugPanelType PanelType = ECaddyVehicleDebugPanelType::Core;
};
