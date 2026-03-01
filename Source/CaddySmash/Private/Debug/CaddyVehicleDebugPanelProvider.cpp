#include "Debug/CaddyVehicleDebugPanelProvider.h"

#include "Curves/CurveFloat.h"
#include "HitRegister/HitRegisterPipeline.h"
#include "HitRegisterCollision/HitRegisterTargetingProfile.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/CaddyVehicleCameraComponent.h"
#include "Vehicle/CaddyVehicleFeelComponent.h"
#include "Vehicle/CaddyVehiclePawn.h"
#include "Vehicle/CaddyVehicleSkillConfigDataAsset.h"
#include "Vehicle/CaddyVehicleSkillComponent.h"
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

    static FString TagToString(const FGameplayTag& Tag)
    {
        return Tag.IsValid() ? Tag.ToString() : TEXT("Default");
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
    case ECaddyVehicleDebugPanelType::Feel:
        GatherFeelRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::Skill:
        GatherSkillRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::Camera:
        GatherCameraRows(OutRows);
        break;
    case ECaddyVehicleDebugPanelType::Collision:
        GatherCollisionRows(OutRows);
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
    AddRow(
        OutRows,
        TEXT("Health"),
        FString::Printf(TEXT("%.1f / %.1f"), Pawn->GetVehicleHealth(), Pawn->GetVehicleMaxHealth()),
        Pawn->GetVehicleHealth() <= 0.0f ? FLinearColor::Red : FLinearColor::White);
    AddRow(OutRows, TEXT("KnockbackResist"), FString::Printf(TEXT("%.2f"), Pawn->GetVehicleKnockbackResistance()));

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
    const UCaddyVehicleSkillConfigDataAsset* SkillConfigAsset = Pawn->GetSkillConfigDataAsset();
    AddRow(OutRows, TEXT("TuningAsset"), TuningAsset ? TuningAsset->GetName() : TEXT("None"));
    AddRow(OutRows, TEXT("SkillConfigAsset"), SkillConfigAsset ? SkillConfigAsset->GetName() : TEXT("None"));
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
    AddRow(OutRows, TEXT("CollisionMode"), StaticEnum<ECaddyVehicleCollisionResponseMode>()
        ? StaticEnum<ECaddyVehicleCollisionResponseMode>()->GetNameStringByValue(static_cast<int64>(MovementComponent->CollisionConfig.ResponseMode))
        : TEXT("Unknown"));
    AddRow(OutRows, TEXT("CollisionRetainRatio"), FString::Printf(TEXT("%.2f"), MovementComponent->CollisionConfig.SpeedRetainRatio));
    AddRow(OutRows, TEXT("CollisionIterations"), FString::Printf(TEXT("%d"), MovementComponent->CollisionConfig.MaxCollisionIterations));
    AddRow(OutRows, TEXT("WallGlideInterp"), FString::Printf(TEXT("%.2f"), MovementComponent->CollisionConfig.WallGlideVelocityInterpSpeed));
    AddRow(OutRows, TEXT("WallGlideAssist"), FString::Printf(TEXT("%.2f"), MovementComponent->CollisionConfig.WallGlideInputAssist));
    AddRow(OutRows, TEXT("WallGlideMinNormal"), FString::Printf(TEXT("%.1f"), MovementComponent->CollisionConfig.MinNormalImpactSpeedForGlide));
    AddRow(OutRows, TEXT("WallGlideMinSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->CollisionConfig.MinWallGlideSpeed));
    AddRow(OutRows, TEXT("PushOutDistance"), FString::Printf(TEXT("%.1f"), MovementComponent->CollisionConfig.PushOutDistance));
    if (const UCaddyVehicleCameraComponent* CameraComponent = Pawn->GetVehicleCameraComponent())
    {
        AddRow(OutRows, TEXT("Cam BaseArmLen"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BaseArmLength));
        AddRow(OutRows, TEXT("Cam BasePitch"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BasePitchDeg));
        AddRow(OutRows, TEXT("Cam BaseFOV"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BaseFOV));
    }
    if (const UCaddyVehicleFeelComponent* FeelComponent = Pawn->GetVehicleFeelComponent())
    {
        AddRow(OutRows, TEXT("Feel Enabled"), BoolToOnOff(FeelComponent->FeelConfig.bEnableFeel));
        AddRow(OutRows, TEXT("Feel EngineVar"), FString::Printf(TEXT("%.3f"), FeelComponent->FeelConfig.EngineScaleVibration.BaseVariance));
        AddRow(OutRows, TEXT("Feel EngineFreq"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.EngineScaleVibration.BaseFrequencyHz));
        AddRow(OutRows, TEXT("Feel MaxLean"), FString::Printf(TEXT("%.1f"), FeelComponent->FeelConfig.MaxLateralLeanRollDeg));
        AddRow(OutRows, TEXT("Feel ImpactScale"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.ImpactPulseScale));
    }
    if (const UCaddyVehicleSkillComponent* SkillComponent = Pawn->GetVehicleSkillComponent())
    {
        AddRow(OutRows, TEXT("Skill Enabled"), BoolToOnOff(SkillComponent->BrakeDashConfig.bEnableBrakeDashSkill));
        AddRow(OutRows, TEXT("Skill Cooldown"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.CooldownSeconds));
        AddRow(OutRows, TEXT("Skill DashPeakMax"), FString::Printf(TEXT("%.1f"), SkillComponent->BrakeDashConfig.DashPeakSpeedAtMaxCharge));
        AddRow(OutRows, TEXT("Skill MaxCharge"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.MaxChargeSeconds));
    }
}

void UCaddyVehicleDebugPanelProvider::GatherFeelRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UCaddyVehicleFeelComponent* FeelComponent = Pawn ? Pawn->GetVehicleFeelComponent() : nullptr;
    if (!Pawn || !FeelComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or feel component missing"), FLinearColor::Red);
        return;
    }

    AddRow(OutRows, TEXT("Enabled"), BoolToOnOff(FeelComponent->FeelConfig.bEnableFeel));
    AddRow(OutRows, TEXT("RigReady"), BoolToOnOff(FeelComponent->IsFeelRigReady()));
    AddRow(OutRows, TEXT("EngineStrength"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentIdleStrength()));
    AddRow(OutRows, TEXT("EngineSpeedAlpha"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentEngineScaleSpeedAlpha()));
    AddRow(OutRows, TEXT("EngineVariance"), FString::Printf(TEXT("%.4f"), FeelComponent->GetCurrentEngineScaleVariance()));
    AddRow(OutRows, TEXT("EngineFreqHz"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentEngineScaleFrequencyHz()));
    AddRow(OutRows, TEXT("EngineWave"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentEngineScaleWave()));
    AddRow(OutRows, TEXT("AccelAlpha"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentForwardAccelAlpha()));
    AddRow(OutRows, TEXT("SpeedStretch"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentSpeedStretchAlpha()));
    AddRow(OutRows, TEXT("LeanRollDeg"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentLeanRollDeg()));
    AddRow(OutRows, TEXT("ImpactStrength"), FString::Printf(TEXT("%.2f"), FeelComponent->GetCurrentImpactStrength()));

    const FVector Offset = FeelComponent->GetCurrentLocationOffset();
    const FRotator RotationOffset = FeelComponent->GetCurrentRotationOffset();
    const FVector ScaleMultiplier = FeelComponent->GetCurrentScaleMultiplier();
    AddRow(OutRows, TEXT("LocOffset"), FString::Printf(TEXT("(%.2f, %.2f, %.2f)"), Offset.X, Offset.Y, Offset.Z));
    AddRow(OutRows, TEXT("RotOffset"), FString::Printf(TEXT("(%.2f, %.2f, %.2f)"), RotationOffset.Pitch, RotationOffset.Yaw, RotationOffset.Roll));
    AddRow(OutRows, TEXT("ScaleMult"), FString::Printf(TEXT("(%.3f, %.3f, %.3f)"), ScaleMultiplier.X, ScaleMultiplier.Y, ScaleMultiplier.Z));

    AddRow(OutRows, TEXT("Cfg Eng Enabled"), BoolToOnOff(FeelComponent->FeelConfig.EngineScaleVibration.bEnableEngineScaleVibration));
    AddRow(OutRows, TEXT("Cfg Eng BaseVar"), FString::Printf(TEXT("%.4f"), FeelComponent->FeelConfig.EngineScaleVibration.BaseVariance));
    AddRow(OutRows, TEXT("Cfg Eng BaseHz"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.EngineScaleVibration.BaseFrequencyHz));
    AddRow(OutRows, TEXT("Cfg Eng SpeedNorm"), FString::Printf(TEXT("%.1f"), FeelComponent->FeelConfig.EngineScaleVibration.SpeedForCurveNormalization));
    AddRow(OutRows, TEXT("Cfg Eng ThrottleVar"), FString::Printf(TEXT("%.3f"), FeelComponent->FeelConfig.EngineScaleVibration.ThrottleVarianceBoost));
    AddRow(OutRows, TEXT("Cfg Eng ThrottleHz"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.EngineScaleVibration.ThrottleFrequencyBoostHz));
    AddRow(OutRows, TEXT("Cfg Eng MaxVar"), FString::Printf(TEXT("%.3f"), FeelComponent->FeelConfig.EngineScaleVibration.MaxVariance));
    AddRow(OutRows, TEXT("Cfg Eng MinHz"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.EngineScaleVibration.MinFrequencyHz));
    AddRow(OutRows, TEXT("Cfg Eng MaxHz"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.EngineScaleVibration.MaxFrequencyHz));
    AddRow(OutRows, TEXT("Cfg Eng VarCurve"), FeelComponent->FeelConfig.EngineScaleVibration.VarianceBySpeedCurve
        ? FeelComponent->FeelConfig.EngineScaleVibration.VarianceBySpeedCurve->GetName()
        : TEXT("None"));
    AddRow(OutRows, TEXT("Cfg Eng FreqCurve"), FeelComponent->FeelConfig.EngineScaleVibration.FrequencyBySpeedCurve
        ? FeelComponent->FeelConfig.EngineScaleVibration.FrequencyBySpeedCurve->GetName()
        : TEXT("None"));
    AddRow(OutRows, TEXT("Cfg MaxAccelDeform"), FString::Printf(TEXT("%.1f"), FeelComponent->FeelConfig.MaxAccelSquashStretch));
    AddRow(OutRows, TEXT("Cfg MaxSpeedStretch"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.MaxSpeedStretch));
    AddRow(OutRows, TEXT("Cfg MaxLeanRoll"), FString::Printf(TEXT("%.1f"), FeelComponent->FeelConfig.MaxLateralLeanRollDeg));
    AddRow(OutRows, TEXT("Cfg ImpactDuration"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.ImpactPulseDuration));
    AddRow(OutRows, TEXT("Cfg ImpactScale"), FString::Printf(TEXT("%.2f"), FeelComponent->FeelConfig.ImpactPulseScale));
    AddRow(OutRows, TEXT("Cfg ImpactKick"), FString::Printf(TEXT("%.1f"), FeelComponent->FeelConfig.ImpactPulseLocationKick));
}

void UCaddyVehicleDebugPanelProvider::GatherSkillRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UCaddyVehicleSkillComponent* SkillComponent = Pawn ? Pawn->GetVehicleSkillComponent() : nullptr;
    if (!Pawn || !SkillComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or skill component missing"), FLinearColor::Red);
        return;
    }

    const UEnum* SkillStateEnum = StaticEnum<ECaddyVehicleSkillState>();
    const FString StateLabel = SkillStateEnum
        ? SkillStateEnum->GetNameStringByValue(static_cast<int64>(SkillComponent->GetSkillState()))
        : TEXT("Unknown");

    AddRow(OutRows, TEXT("Enabled"), BoolToOnOff(SkillComponent->BrakeDashConfig.bEnableBrakeDashSkill));
    AddRow(OutRows, TEXT("UseGASStateMachine"), BoolToOnOff(SkillComponent->bUseGASAbilityStateMachine));
    AddRow(OutRows, TEXT("RigReady"), BoolToOnOff(SkillComponent->IsSkillRigReady()));
    AddRow(OutRows, TEXT("State"), StateLabel);
    AddRow(OutRows, TEXT("Active"), BoolToOnOff(SkillComponent->IsSkillActive()));
    AddRow(OutRows, TEXT("CanTrigger"), BoolToOnOff(SkillComponent->CanTriggerSkillNow()));
    AddRow(OutRows, TEXT("StateTime"), FString::Printf(TEXT("%.3f"), SkillComponent->GetStateElapsedSeconds()));
    AddRow(OutRows, TEXT("CooldownRemain"), FString::Printf(TEXT("%.3f"), SkillComponent->GetCooldownRemainingSeconds()));
    AddRow(OutRows, TEXT("TriggerHold"), FString::Printf(TEXT("%.3f"), SkillComponent->GetTriggerHoldSeconds()));
    AddRow(OutRows, TEXT("InputPressed"), BoolToOnOff(SkillComponent->IsSkillInputPressed()));
    AddRow(OutRows, TEXT("OverrideSpeed"), FString::Printf(TEXT("%.1f"), SkillComponent->GetCurrentOverrideSpeed()));
    AddRow(OutRows, TEXT("ChargeSec"), FString::Printf(TEXT("%.3f"), SkillComponent->GetCurrentChargeSeconds()));
    AddRow(OutRows, TEXT("ChargeAlpha"), FString::Printf(TEXT("%.2f"), SkillComponent->GetCurrentChargeAlpha()));
    AddRow(OutRows, TEXT("DashDurActive"), FString::Printf(TEXT("%.3f"), SkillComponent->GetActiveDashDuration()));
    AddRow(OutRows, TEXT("DashPeakActive"), FString::Printf(TEXT("%.1f"), SkillComponent->GetActiveDashPeakSpeed()));

    const FVector2D AimDirection = SkillComponent->GetCurrentAimDirection();
    const FVector2D DashDirection = SkillComponent->GetDashDirection();
    AddRow(OutRows, TEXT("AimDir"), FString::Printf(TEXT("(%.2f, %.2f)"), AimDirection.X, AimDirection.Y));
    AddRow(OutRows, TEXT("DashDir"), FString::Printf(TEXT("(%.2f, %.2f)"), DashDirection.X, DashDirection.Y));
    AddRow(OutRows, TEXT("UsingAbilityAim"), BoolToOnOff(SkillComponent->IsUsingAbilityTargetAim()));
    AddRow(OutRows, TEXT("HasAbilityTarget"), BoolToOnOff(SkillComponent->HasCurrentAbilityTarget()));
    AddRow(OutRows, TEXT("AbilityTargetActor"), GetNameSafe(SkillComponent->GetCurrentAbilityTargetActor()));
    const FVector AbilityTargetLocation = SkillComponent->GetCurrentAbilityTargetLocation();
    AddRow(OutRows, TEXT("AbilityTargetLoc"), FString::Printf(TEXT("(%.1f, %.1f, %.1f)"), AbilityTargetLocation.X, AbilityTargetLocation.Y, AbilityTargetLocation.Z));
    if (const AActor* TargetActor = SkillComponent->GetCurrentAbilityTargetActor())
    {
        AddRow(
            OutRows,
            TEXT("AbilityTargetDist"),
            FString::Printf(TEXT("%.1f"), FVector::Dist2D(Pawn->GetActorLocation(), TargetActor->GetActorLocation())));
    }

    const UEnum* TriggerModeEnum = StaticEnum<ECaddyVehicleSkillTriggerMode>();
    AddRow(OutRows, TEXT("Cfg TriggerMode"), TriggerModeEnum
        ? TriggerModeEnum->GetNameStringByValue(static_cast<int64>(SkillComponent->BrakeDashConfig.TriggerMode))
        : TEXT("Unknown"));
    const UEnum* AimSelectionModeEnum = StaticEnum<ECaddyVehicleSkillAimSelectionMode>();
    AddRow(OutRows, TEXT("Cfg AimMode"), AimSelectionModeEnum
        ? AimSelectionModeEnum->GetNameStringByValue(static_cast<int64>(SkillComponent->BrakeDashConfig.AbilityTargeting.AimSelectionMode))
        : TEXT("Unknown"));
    AddRow(OutRows, TEXT("Cfg AbilityTarget"), BoolToOnOff(SkillComponent->BrakeDashConfig.AbilityTargeting.bEnableAbilityTargeting));
    AddRow(OutRows, TEXT("Cfg TargetTraceDist"), FString::Printf(TEXT("%.1f"), SkillComponent->BrakeDashConfig.AbilityTargeting.TraceDistance));
    AddRow(OutRows, TEXT("Cfg TargetTraceRadius"), FString::Printf(TEXT("%.1f"), SkillComponent->BrakeDashConfig.AbilityTargeting.TraceRadius));
    AddRow(OutRows, TEXT("Cfg TargetTraceChannel"), FString::Printf(TEXT("%d"), static_cast<int32>(SkillComponent->BrakeDashConfig.AbilityTargeting.TraceChannel.GetValue())));
    const UHitRegisterTargetingProfile* TargetingProfile = SkillComponent->BrakeDashConfig.AbilityTargeting.TargetingProfile.Get();
    AddRow(OutRows, TEXT("Cfg TargetProfile"), TargetingProfile ? TargetingProfile->GetName() : TEXT("None"));
    AddRow(OutRows, TEXT("Cfg TargetDebug"), BoolToOnOff(SkillComponent->BrakeDashConfig.AbilityTargeting.bEnableDebugDraw));
    AddRow(OutRows, TEXT("Cfg TriggerThrottle"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.TriggerThrottleThreshold));
    AddRow(OutRows, TEXT("Cfg TriggerBrake"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.TriggerBrakeThreshold));
    AddRow(OutRows, TEXT("Cfg TriggerHold"), FString::Printf(TEXT("%.3f"), SkillComponent->BrakeDashConfig.TriggerInputHoldSeconds));
    AddRow(OutRows, TEXT("Cfg Cooldown"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.CooldownSeconds));
    AddRow(OutRows, TEXT("Cfg BrakeDuration"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.BrakeDuration));
    AddRow(OutRows, TEXT("Cfg MinCharge"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.MinChargeSeconds));
    AddRow(OutRows, TEXT("Cfg MaxCharge"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.MaxChargeSeconds));
    AddRow(OutRows, TEXT("Cfg DashDurMin"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.DashDurationAtMinCharge));
    AddRow(OutRows, TEXT("Cfg DashDurMax"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.DashDurationAtMaxCharge));
    AddRow(OutRows, TEXT("Cfg DashPeakMin"), FString::Printf(TEXT("%.1f"), SkillComponent->BrakeDashConfig.DashPeakSpeedAtMinCharge));
    AddRow(OutRows, TEXT("Cfg DashPeakMax"), FString::Printf(TEXT("%.1f"), SkillComponent->BrakeDashConfig.DashPeakSpeedAtMaxCharge));
    AddRow(OutRows, TEXT("Cfg CarryRatio"), FString::Printf(TEXT("%.2f"), SkillComponent->BrakeDashConfig.PostDashCarryRatio));
    AddRow(OutRows, TEXT("Cfg BrakeCurve"), SkillComponent->BrakeDashConfig.BrakeSpeedAlphaCurve
        ? SkillComponent->BrakeDashConfig.BrakeSpeedAlphaCurve->GetName()
        : TEXT("None"));
    AddRow(OutRows, TEXT("Cfg ChargeCurve"), SkillComponent->BrakeDashConfig.ChargeAlphaCurve
        ? SkillComponent->BrakeDashConfig.ChargeAlphaCurve->GetName()
        : TEXT("None"));
    AddRow(OutRows, TEXT("Cfg DashCurve"), SkillComponent->BrakeDashConfig.DashSpeedAlphaCurve
        ? SkillComponent->BrakeDashConfig.DashSpeedAlphaCurve->GetName()
        : TEXT("None"));
}

void UCaddyVehicleDebugPanelProvider::GatherCameraRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UCaddyVehicleCameraComponent* CameraComponent = Pawn ? Pawn->GetVehicleCameraComponent() : nullptr;
    if (!Pawn || !CameraComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or camera component missing"), FLinearColor::Red);
        return;
    }

    AddRow(OutRows, TEXT("DynamicCamera"), BoolToOnOff(CameraComponent->CameraConfig.bEnableDynamicCamera));
    AddRow(OutRows, TEXT("RigReady"), BoolToOnOff(CameraComponent->IsCameraRigReady()));
    AddRow(OutRows, TEXT("SpeedAlpha"), FString::Printf(TEXT("%.2f"), CameraComponent->GetCurrentSpeedAlpha()));
    AddRow(OutRows, TEXT("ArmLength"), FString::Printf(TEXT("%.1f"), CameraComponent->GetCurrentArmLength()));
    AddRow(OutRows, TEXT("PitchDeg"), FString::Printf(TEXT("%.1f"), CameraComponent->GetCurrentPitchDeg()));
    AddRow(OutRows, TEXT("FOV"), FString::Printf(TEXT("%.1f"), CameraComponent->GetCurrentFOV()));
    AddRow(OutRows, TEXT("RollDeg"), FString::Printf(TEXT("%.2f"), CameraComponent->GetCurrentRollDeg()));
    AddRow(OutRows, TEXT("LagSpeed"), FString::Printf(TEXT("%.2f"), CameraComponent->GetCurrentCameraLagSpeed()));

    const FVector Offset = CameraComponent->GetCurrentWorldTargetOffset();
    AddRow(OutRows, TEXT("WorldOffset"), FString::Printf(TEXT("(%.1f, %.1f, %.1f)"), Offset.X, Offset.Y, Offset.Z));

    AddRow(OutRows, TEXT("Cfg BaseArmLen"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BaseArmLength));
    AddRow(OutRows, TEXT("Cfg BasePitch"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BasePitchDeg));
    AddRow(OutRows, TEXT("Cfg BaseFOV"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.BaseFOV));
    AddRow(OutRows, TEXT("Cfg MaxPitchOff"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.MaxSpeedPitchOffsetDeg));
    AddRow(OutRows, TEXT("Cfg MaxArmOff"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.MaxSpeedArmLengthOffset));
    AddRow(OutRows, TEXT("Cfg MaxFOVOff"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.MaxSpeedFOVOffset));
    AddRow(OutRows, TEXT("Cfg LookAhead"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.LookAheadDistance));
    AddRow(OutRows, TEXT("Cfg MaxRoll"), FString::Printf(TEXT("%.1f"), CameraComponent->CameraConfig.MaxLateralRollDeg));
}

void UCaddyVehicleDebugPanelProvider::GatherCollisionRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
    const ACaddyVehiclePawn* Pawn = VehiclePawn.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = Pawn ? Pawn->GetVehicleMovementComponent() : nullptr;
    if (!Pawn || !MovementComponent)
    {
        AddRow(OutRows, TEXT("Status"), TEXT("Vehicle or movement missing"), FLinearColor::Red);
        return;
    }

    const float TimeSinceHit = MovementComponent->GetTimeSinceLastBlockingHit();
    AddRow(OutRows, TEXT("LastHitAge"), TimeSinceHit >= 0.0f ? FString::Printf(TEXT("%.3fs"), TimeSinceHit) : TEXT("n/a"));
    AddRow(OutRows, TEXT("LastHitActor"), MovementComponent->GetLastCollisionActorName());
    AddRow(OutRows, TEXT("Raw TotalSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->GetLastCollisionSpeed()));
    AddRow(OutRows, TEXT("Raw NormalImpact"), FString::Printf(TEXT("%.1f"), MovementComponent->GetLastCollisionNormalImpactSpeed()));
    AddRow(OutRows, TEXT("Raw RelNormal"), FString::Printf(TEXT("%.1f"), MovementComponent->GetLastCollisionRelativeNormalSpeed()));
    AddRow(OutRows, TEXT("Pipeline EffNormal"), FString::Printf(TEXT("%.1f"), MovementComponent->GetLastCollisionEffectiveNormalSpeed()));
    AddRow(OutRows, TEXT("Pipeline ImpactScore"), FString::Printf(TEXT("%.1f"), MovementComponent->GetLastCollisionImpactScore()));
    const UEnum* ImpactTierEnum = StaticEnum<ECaddyVehicleCollisionImpactTier>();
    AddRow(
        OutRows,
        TEXT("Pipeline ImpactTier"),
        ImpactTierEnum
            ? ImpactTierEnum->GetNameStringByValue(static_cast<int64>(MovementComponent->GetLastCollisionImpactTier()))
            : TEXT("Unknown"));
    AddRow(OutRows, TEXT("LastTargetVehicle"), BoolToOnOff(MovementComponent->WasLastCollisionTargetVehicle()));
    AddRow(OutRows, TEXT("LastDuringDash"), BoolToOnOff(MovementComponent->WasLastCollisionDuringSkillDash()));

    const FVector HitLocation = MovementComponent->GetLastCollisionLocation();
    const FVector HitNormal = MovementComponent->GetLastCollisionNormal();
    const FVector HitTangent = MovementComponent->GetLastCollisionTangent();
    AddRow(OutRows, TEXT("HitLocation"), FString::Printf(TEXT("(%.1f, %.1f, %.1f)"), HitLocation.X, HitLocation.Y, HitLocation.Z));
    AddRow(OutRows, TEXT("HitNormal"), FString::Printf(TEXT("(%.2f, %.2f, %.2f)"), HitNormal.X, HitNormal.Y, HitNormal.Z));
    AddRow(OutRows, TEXT("HitTangent"), FString::Printf(TEXT("(%.2f, %.2f, %.2f)"), HitTangent.X, HitTangent.Y, HitTangent.Z));

    AddRow(OutRows, TEXT("HitRegisterEnabled"), BoolToOnOff(MovementComponent->CollisionConfig.HitRegister.bEnableCollisionHitRegister));
    const UHitRegisterPipeline* HitRegisterPipeline = MovementComponent->CollisionHitRegisterPipeline.Get();
    AddRow(OutRows, TEXT("HR Pipeline"), HitRegisterPipeline ? HitRegisterPipeline->GetName() : TEXT("None"));
    AddRow(OutRows, TEXT("HitRegisterTriggered"), BoolToOnOff(MovementComponent->DidLastCollisionTriggerHitRegister()));
    AddRow(
        OutRows,
        TEXT("HitRegisterSuccess"),
        BoolToOnOff(MovementComponent->DidLastCollisionHitRegisterSucceed()),
        MovementComponent->DidLastCollisionHitRegisterSucceed() ? FLinearColor::Green : FLinearColor::Yellow);
    AddRow(OutRows, TEXT("HitRegisterStatus"), MovementComponent->GetLastCollisionHitRegisterStatus());
    AddRow(OutRows, TEXT("HR MinSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->CollisionConfig.HitRegister.MinSpeedForEvent));
    AddRow(OutRows, TEXT("HR MinNormalSpeed"), FString::Printf(TEXT("%.1f"), MovementComponent->CollisionConfig.HitRegister.MinNormalImpactSpeedForEvent));
    AddRow(OutRows, TEXT("HR Cooldown"), FString::Printf(TEXT("%.2f"), MovementComponent->CollisionConfig.HitRegister.EventCooldownSeconds));
    AddRow(OutRows, TEXT("AttrTag TotalSpeed"), TagToString(MovementComponent->CollisionConfig.HitRegister.SpeedAttributeTag));
    AddRow(OutRows, TEXT("AttrTag NormalImpact"), TagToString(MovementComponent->CollisionConfig.HitRegister.NormalImpactSpeedAttributeTag));
    AddRow(OutRows, TEXT("AttrTag TargetSpeed"), TagToString(MovementComponent->CollisionConfig.HitRegister.TargetSpeedAttributeTag));
    AddRow(OutRows, TEXT("AttrTag RelNormal"), TagToString(MovementComponent->CollisionConfig.HitRegister.RelativeNormalSpeedAttributeTag));
    AddRow(OutRows, TEXT("AttrTag IsDrifting"), TagToString(MovementComponent->CollisionConfig.HitRegister.DriftingAttributeTag));
    AddRow(OutRows, TEXT("AttrTag IsDashing"), TagToString(MovementComponent->CollisionConfig.HitRegister.SkillDashingAttributeTag));
    AddRow(OutRows, TEXT("AttrTag TargetVehicle"), TagToString(MovementComponent->CollisionConfig.HitRegister.TargetVehicleAttributeTag));
    AddRow(OutRows, TEXT("AttrTag OutEffNormal"), TagToString(MovementComponent->CollisionConfig.HitRegister.EffectiveNormalSpeedAttributeTag));
    AddRow(OutRows, TEXT("AttrTag OutScore"), TagToString(MovementComponent->CollisionConfig.HitRegister.ImpactScoreAttributeTag));
    AddRow(OutRows, TEXT("AttrTag OutTier"), TagToString(MovementComponent->CollisionConfig.HitRegister.ImpactTierAttributeTag));
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
    AddRow(OutRows, TEXT("CollisionDebugPersist"), FString::Printf(TEXT("%.2f"), MovementComponent->CollisionConfig.DebugPersistSeconds));
}
