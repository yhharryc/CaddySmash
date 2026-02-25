#include "Debug/CaddyVehicleDebugPanelProvider.h"

#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/CaddyVehiclePawn.h"
#include "Vehicle/CaddyVehicleTuningDataAsset.h"

namespace
{
    static void AddRow(
        TArray<FDebugFrameworkPanelRow>& OutRows,
        const FString& Label,
        const FString& Value,
        const FLinearColor Color = FLinearColor::White)
    {
        FDebugFrameworkPanelRow& Row = OutRows.AddDefaulted_GetRef();
        Row.Label = Label;
        Row.Value = Value;
        Row.Color = Color;
    }

    static FString BoolToOnOff(const bool bValue)
    {
        return bValue ? TEXT("On") : TEXT("Off");
    }

    static FString NetRoleToString(const ENetRole Role)
    {
        const UEnum* Enum = StaticEnum<ENetRole>();
        return Enum ? Enum->GetNameStringByValue(static_cast<int64>(Role)) : TEXT("Unknown");
    }
}

void UCaddyVehicleDebugPanelProvider::Initialize(
    ACaddyVehiclePawn* InVehiclePawn,
    FName InPanelId,
    const FText& InPanelTitle,
    FName InToolId,
    const FText& InToolTitle,
    int32 InSortOrder,
    ECaddyVehicleDebugPanelType InPanelType)
{
    VehiclePawn = InVehiclePawn;
    PanelId = InPanelId;
    PanelTitle = InPanelTitle;
    ToolId = InToolId;
    ToolTitle = InToolTitle;
    SortOrder = InSortOrder;
    PanelType = InPanelType;
}

FName UCaddyVehicleDebugPanelProvider::GetDebugPanelId_Implementation() const
{
    return PanelId;
}

FText UCaddyVehicleDebugPanelProvider::GetDebugPanelTitle_Implementation() const
{
    return PanelTitle;
}

FName UCaddyVehicleDebugPanelProvider::GetDebugToolId_Implementation() const
{
    return ToolId;
}

FText UCaddyVehicleDebugPanelProvider::GetDebugToolTitle_Implementation() const
{
    return ToolTitle;
}

int32 UCaddyVehicleDebugPanelProvider::GetDebugSortOrder_Implementation() const
{
    return SortOrder;
}

void UCaddyVehicleDebugPanelProvider::GatherDebugRows_Implementation(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    OutRows.Reset();

    switch (PanelType)
    {
    case ECaddyVehicleDebugPanelType::Core:
        GatherCoreRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::Input:
        GatherInputRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::Tuning:
        GatherTuningRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::DebugDraw:
        GatherDebugDrawRows(OutRows);
        break;
    default:
        break;
    }

    if (OutRows.Num() == 0)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("No data"), FLinearColor::Yellow);
    }
}

void UCaddyVehicleDebugPanelProvider::GatherCoreRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = Pawn ? Pawn->GetVehicleMovementComponent() : nullptr;
    if (!Pawn || !MovementComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or movement missing"), FLinearColor::Red);
        return;
    }

    AddRow(OutRows, TEXT("Pawn"), GetNameSafe(Pawn));
    AddRow(OutRows, TEXT("Authority"), Pawn->HasAuthority() ? TEXT("Yes") : TEXT("No"), Pawn->HasAuthority() ? FLinearColor::Green : FLinearColor::Yellow);
    AddRow(OutRows, TEXT("LocalRole"), NetRoleToString(Pawn->GetLocalRole()));
    AddRow(OutRows, TEXT("RemoteRole"), NetRoleToString(Pawn->GetRemoteRole()));
    AddRow(OutRows, TEXT("WorldSpeed"), FString::Printf(TEXT("%.1f"), Pawn->GetVelocity().Size2D()));

    const FVector2D LocalVelocity = MovementComponent->GetLocalPlanarVelocity();
    AddRow(OutRows, TEXT("ForwardSpeed"), FString::Printf(TEXT("%.1f"), LocalVelocity.X));
    AddRow(OutRows, TEXT("LateralSpeed"), FString::Printf(TEXT("%.1f"), LocalVelocity.Y));
    AddRow(OutRows, TEXT("CurrentYaw"), FString::Printf(TEXT("%.1f"), Pawn->GetActorRotation().Yaw));
    AddRow(OutRows, TEXT("TargetYaw"), MovementComponent->HasMoveIntent()
        ? FString::Printf(TEXT("%.1f"), MovementComponent->GetTargetYawFromMoveIntent())
        : TEXT("n/a"));
    AddRow(OutRows, TEXT("Drifting"), BoolToOnOff(MovementComponent->IsDrifting()), MovementComponent->IsDrifting() ? FLinearColor(1.0f, 0.4f, 0.9f, 1.0f) : FLinearColor::White);
}

void UCaddyVehicleDebugPanelProvider::GatherInputRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = Pawn ? Pawn->GetVehicleMovementComponent() : nullptr;
    if (!Pawn || !MovementComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or movement missing"), FLinearColor::Red);
        return;
    }

    const FVector2D RawInput = Pawn->GetRawMoveInput();
    const FVector2D MoveIntent = MovementComponent->GetMoveIntent();

    AddRow(OutRows, TEXT("RawMoveInput"), FString::Printf(TEXT("(%.2f, %.2f)"), RawInput.X, RawInput.Y));
    AddRow(OutRows, TEXT("MoveIntent"), FString::Printf(TEXT("(%.2f, %.2f)"), MoveIntent.X, MoveIntent.Y));
    AddRow(OutRows, TEXT("HasMoveIntent"), BoolToOnOff(MovementComponent->HasMoveIntent()));
    AddRow(OutRows, TEXT("ThrottleInput"), FString::Printf(TEXT("%.2f"), MovementComponent->GetThrottleInput()));
    AddRow(OutRows, TEXT("BrakeReverseInput"), FString::Printf(TEXT("%.2f"), MovementComponent->GetBrakeReverseInput()));
    AddRow(OutRows, TEXT("DriftInput"), FString::Printf(TEXT("%.2f"), MovementComponent->GetDriftInput()));
    AddRow(OutRows, TEXT("DriftThreshold"), FString::Printf(TEXT("%.2f"), MovementComponent->HandlingConfig.DriftInputThreshold));
    AddRow(OutRows, TEXT("SteerMinSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->HandlingConfig.MinSpeedForSteering));
}

void UCaddyVehicleDebugPanelProvider::GatherTuningRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = Pawn ? Pawn->GetVehicleMovementComponent() : nullptr;
    if (!Pawn || !MovementComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or movement missing"), FLinearColor::Red);
        return;
    }

    const UCaddyVehicleTuningDataAsset* TuningAsset = MovementComponent->GetTuningDataAsset();
    AddRow(OutRows, TEXT("TuningAsset"), TuningAsset ? TuningAsset->GetName() : TEXT("None"));
    AddRow(OutRows, TEXT("PresetCount"), FString::Printf(TEXT("%d"), Pawn->GetRuntimeTuningPresetCount()));
    AddRow(
        OutRows,
        TEXT("ActivePreset"),
        FString::Printf(TEXT("[%d] %s"), Pawn->GetActiveRuntimeTuningPresetIndex(), *Pawn->GetActiveRuntimeTuningPresetName()),
        FLinearColor(0.55f, 0.90f, 1.0f, 1.0f));
    AddRow(OutRows, TEXT("SwitchNext"), TEXT("caddy.vehicle.tuning.next"), FLinearColor(0.75f, 0.85f, 1.0f, 1.0f));
    AddRow(OutRows, TEXT("SwitchPrev"), TEXT("caddy.vehicle.tuning.prev"), FLinearColor(0.75f, 0.85f, 1.0f, 1.0f));
    AddRow(OutRows, TEXT("SwitchSet"), TEXT("caddy.vehicle.tuning.set <index>"), FLinearColor(0.75f, 0.85f, 1.0f, 1.0f));
    AddRow(OutRows, TEXT("MaxForwardSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.MaxForwardSpeed));
    AddRow(OutRows, TEXT("ForwardAcceleration"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.ForwardAcceleration));
    AddRow(OutRows, TEXT("CoastDeceleration"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.CoastDeceleration));
    AddRow(OutRows, TEXT("BrakeDeceleration"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.BrakeDeceleration));
    AddRow(OutRows, TEXT("MaxReverseSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.MaxReverseSpeed));
    AddRow(OutRows, TEXT("ReverseAcceleration"), FString::Printf(TEXT("%.1f"), MovementComponent->GasConfig.ReverseAcceleration));
    AddRow(OutRows, TEXT("SteeringRateDegPerSec"), FString::Printf(TEXT("%.1f"), MovementComponent->HandlingConfig.SteeringRateDegPerSec));
    AddRow(OutRows, TEXT("LateralFrictionInterp"), FString::Printf(TEXT("%.2f"), MovementComponent->HandlingConfig.LateralFrictionInterpSpeed));
    AddRow(OutRows, TEXT("DriftLateralFriction"), FString::Printf(TEXT("%.2f"), MovementComponent->HandlingConfig.DriftLateralFrictionInterpSpeed));
    AddRow(OutRows, TEXT("DriftSteeringMultiplier"), FString::Printf(TEXT("%.2f"), MovementComponent->HandlingConfig.DriftSteeringRateMultiplier));
    AddRow(OutRows, TEXT("LinearDrag"), FString::Printf(TEXT("%.2f"), MovementComponent->HandlingConfig.LinearDrag));
}

void UCaddyVehicleDebugPanelProvider::GatherDebugDrawRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = Pawn ? Pawn->GetVehicleMovementComponent() : nullptr;
    if (!Pawn || !MovementComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or movement missing"), FLinearColor::Red);
        return;
    }

    AddRow(OutRows, TEXT("EnableDebugDraw"), BoolToOnOff(MovementComponent->bEnableDebugDraw));
    AddRow(OutRows, TEXT("LocalOnly"), BoolToOnOff(MovementComponent->bDebugDrawOnlyForLocalPawn));
    AddRow(OutRows, TEXT("DirectionLineLength"), FString::Printf(TEXT("%.1f"), MovementComponent->DebugDirectionLineLength));
    AddRow(OutRows, TEXT("VelocityLineScale"), FString::Printf(TEXT("%.3f"), MovementComponent->DebugVelocityLineScale));
    AddRow(OutRows, TEXT("DrawZOffset"), FString::Printf(TEXT("%.1f"), MovementComponent->DebugDrawZOffset));
    AddRow(OutRows, TEXT("LineThickness"), FString::Printf(TEXT("%.1f"), MovementComponent->DebugLineThickness));
}
