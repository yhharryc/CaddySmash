#include "Vehicle/CaddyVehicleCameraComponent.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"

UCaddyVehicleCameraComponent::UCaddyVehicleCameraComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UCaddyVehicleCameraComponent::SetCameraConfig(const FCaddyVehicleCameraConfig& InConfig, bool bSnapToConfig)
{
    CameraConfig = InConfig;
    if (bSnapToConfig)
    {
        SnapToCurrentConfig();
    }
}

void UCaddyVehicleCameraComponent::BindCameraRig(
    UArcadeVehicleMovementComponent* InMovementComponent,
    USpringArmComponent* InSpringArmComponent,
    UCameraComponent* InCameraComponent)
{
    MovementComponent = InMovementComponent;
    SpringArmComponent = InSpringArmComponent;
    CameraComponent = InCameraComponent;
    CacheCameraBaseTransform();
    SnapToCurrentConfig();
}

bool UCaddyVehicleCameraComponent::IsCameraRigReady() const
{
    return MovementComponent.IsValid() && SpringArmComponent.IsValid() && CameraComponent.IsValid();
}

void UCaddyVehicleCameraComponent::BeginPlay()
{
    Super::BeginPlay();
    ResolveRigReferences();
    SnapToCurrentConfig();
}

void UCaddyVehicleCameraComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    if (!IsCameraRigReady())
    {
        ResolveRigReferences();
    }

    if (!ShouldUpdateCamera())
    {
        return;
    }

    const APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn)
    {
        return;
    }

    UArcadeVehicleMovementComponent* Movement = MovementComponent.Get();
    USpringArmComponent* SpringArm = SpringArmComponent.Get();
    UCameraComponent* Camera = CameraComponent.Get();
    if (!Movement || !SpringArm || !Camera)
    {
        return;
    }

    const float PlanarSpeed = OwnerPawn->GetVelocity().Size2D();
    const float SpeedAlphaTarget = CameraConfig.bEnableDynamicCamera
        ? FMath::Clamp(PlanarSpeed / FMath::Max(1.0f, CameraConfig.MaxSpeedForEffects), 0.0f, 1.0f)
        : 0.0f;
    CurrentSpeedAlpha = FMath::FInterpTo(CurrentSpeedAlpha, SpeedAlphaTarget, DeltaTime, CameraConfig.TransformInterpSpeed);

    const float TargetPitch = CameraConfig.BasePitchDeg + (CameraConfig.MaxSpeedPitchOffsetDeg * CurrentSpeedAlpha);
    const float TargetArmLength = CameraConfig.BaseArmLength + (CameraConfig.MaxSpeedArmLengthOffset * CurrentSpeedAlpha);
    const float TargetFOV = CameraConfig.BaseFOV + (CameraConfig.MaxSpeedFOVOffset * CurrentSpeedAlpha);

    FVector LookAheadDirection = FVector::ZeroVector;
    if (Movement->HasMoveIntent())
    {
        const FVector2D MoveIntent = Movement->GetMoveIntent();
        LookAheadDirection = FVector(MoveIntent.X, MoveIntent.Y, 0.0f).GetSafeNormal();
    }
    else if (PlanarSpeed > KINDA_SMALL_NUMBER)
    {
        LookAheadDirection = FVector(OwnerPawn->GetVelocity().X, OwnerPawn->GetVelocity().Y, 0.0f).GetSafeNormal();
    }
    else
    {
        LookAheadDirection = OwnerPawn->GetActorForwardVector().GetSafeNormal2D();
    }

    const FVector TargetWorldOffset = CameraConfig.BaseWorldTargetOffset
        + (LookAheadDirection * CameraConfig.LookAheadDistance * CurrentSpeedAlpha);
    CurrentWorldTargetOffset = FMath::VInterpTo(
        CurrentWorldTargetOffset,
        TargetWorldOffset,
        DeltaTime,
        CameraConfig.LookAheadInterpSpeed);

    const float LateralAlpha = FMath::Clamp(
        Movement->GetLateralSpeed() / FMath::Max(1.0f, CameraConfig.LateralSpeedForMaxRoll),
        -1.0f,
        1.0f);
    const float TargetRoll = LateralAlpha * CameraConfig.MaxLateralRollDeg;
    CurrentRollDeg = FMath::FInterpTo(CurrentRollDeg, TargetRoll, DeltaTime, CameraConfig.RollInterpSpeed);

    const float NewArmLength = FMath::FInterpTo(
        SpringArm->TargetArmLength,
        TargetArmLength,
        DeltaTime,
        CameraConfig.TransformInterpSpeed);
    SpringArm->TargetArmLength = NewArmLength;

    FRotator ArmRotation = SpringArm->GetRelativeRotation();
    ArmRotation.Pitch = FMath::FInterpTo(
        ArmRotation.Pitch,
        TargetPitch,
        DeltaTime,
        CameraConfig.TransformInterpSpeed);
    ArmRotation.Roll = 0.0f;
    SpringArm->SetRelativeRotation(ArmRotation);
    SpringArm->TargetOffset = CurrentWorldTargetOffset;

    const float NewFOV = FMath::FInterpTo(Camera->FieldOfView, TargetFOV, DeltaTime, CameraConfig.TransformInterpSpeed);
    Camera->SetFieldOfView(NewFOV);

    if (bHasCachedBaseCameraTransform)
    {
        FRotator CameraRotation = BaseCameraRelativeRotation;
        CameraRotation.Roll += CurrentRollDeg;
        Camera->SetRelativeRotation(CameraRotation);
        Camera->SetRelativeLocation(BaseCameraRelativeLocation);
    }

    ApplyLagSettings(CurrentSpeedAlpha);

    CurrentCameraLagSpeed = SpringArm->CameraLagSpeed;
    CurrentArmLength = SpringArm->TargetArmLength;
    CurrentPitchDeg = SpringArm->GetRelativeRotation().Pitch;
    CurrentFOV = Camera->FieldOfView;
}

void UCaddyVehicleCameraComponent::ResolveRigReferences()
{
    if (IsCameraRigReady())
    {
        return;
    }

    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn)
    {
        return;
    }

    if (!MovementComponent.IsValid())
    {
        MovementComponent = OwnerPawn->FindComponentByClass<UArcadeVehicleMovementComponent>();
    }
    if (!SpringArmComponent.IsValid())
    {
        SpringArmComponent = OwnerPawn->FindComponentByClass<USpringArmComponent>();
    }
    if (!CameraComponent.IsValid())
    {
        CameraComponent = OwnerPawn->FindComponentByClass<UCameraComponent>();
    }

    CacheCameraBaseTransform();
}

void UCaddyVehicleCameraComponent::CacheCameraBaseTransform()
{
    UCameraComponent* Camera = CameraComponent.Get();
    if (!Camera || bHasCachedBaseCameraTransform)
    {
        return;
    }

    BaseCameraRelativeLocation = Camera->GetRelativeLocation();
    BaseCameraRelativeRotation = Camera->GetRelativeRotation();
    bHasCachedBaseCameraTransform = true;
}

bool UCaddyVehicleCameraComponent::ShouldUpdateCamera() const
{
    const APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (!OwnerPawn || !OwnerPawn->IsLocallyControlled())
    {
        return false;
    }

    return IsCameraRigReady();
}

void UCaddyVehicleCameraComponent::ApplyLagSettings(float SpeedAlpha) const
{
    USpringArmComponent* SpringArm = SpringArmComponent.Get();
    if (!SpringArm)
    {
        return;
    }

    SpringArm->bEnableCameraLag = CameraConfig.bEnableCameraLag;
    SpringArm->bEnableCameraRotationLag = CameraConfig.bEnableCameraRotationLag;
    SpringArm->CameraLagMaxDistance = FMath::Max(0.0f, CameraConfig.CameraLagMaxDistance);
    SpringArm->CameraRotationLagSpeed = FMath::Max(0.0f, CameraConfig.CameraRotationLagSpeed);
    SpringArm->CameraLagSpeed = FMath::Lerp(
        FMath::Max(0.0f, CameraConfig.CameraLagSpeedAtLowSpeed),
        FMath::Max(0.0f, CameraConfig.CameraLagSpeedAtHighSpeed),
        FMath::Clamp(SpeedAlpha, 0.0f, 1.0f));
}

void UCaddyVehicleCameraComponent::SnapToCurrentConfig()
{
    if (!IsCameraRigReady())
    {
        return;
    }

    USpringArmComponent* SpringArm = SpringArmComponent.Get();
    UCameraComponent* Camera = CameraComponent.Get();
    if (!SpringArm || !Camera)
    {
        return;
    }

    CurrentSpeedAlpha = 0.0f;
    CurrentRollDeg = 0.0f;
    CurrentWorldTargetOffset = CameraConfig.BaseWorldTargetOffset;

    SpringArm->TargetArmLength = CameraConfig.BaseArmLength;
    FRotator ArmRotation = SpringArm->GetRelativeRotation();
    ArmRotation.Pitch = CameraConfig.BasePitchDeg;
    ArmRotation.Roll = 0.0f;
    SpringArm->SetRelativeRotation(ArmRotation);
    SpringArm->TargetOffset = CameraConfig.BaseWorldTargetOffset;

    Camera->SetFieldOfView(CameraConfig.BaseFOV);
    if (bHasCachedBaseCameraTransform)
    {
        Camera->SetRelativeLocation(BaseCameraRelativeLocation);
        Camera->SetRelativeRotation(BaseCameraRelativeRotation);
    }

    ApplyLagSettings(0.0f);
    CurrentCameraLagSpeed = SpringArm->CameraLagSpeed;
    CurrentArmLength = SpringArm->TargetArmLength;
    CurrentPitchDeg = SpringArm->GetRelativeRotation().Pitch;
    CurrentFOV = Camera->FieldOfView;
}
