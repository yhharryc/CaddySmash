#include "Vehicle/ArcadeVehicleMovementComponent.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/Pawn.h"
#include "Vehicle/CaddyVehicleTuningDataAsset.h"

UArcadeVehicleMovementComponent::UArcadeVehicleMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    SetIsReplicatedByDefault(false);
}

float UArcadeVehicleMovementComponent::GetMaxSpeed() const
{
    return GasConfig.MaxForwardSpeed;
}

void UArcadeVehicleMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    ApplyTuningFromDataAsset();
}

void UArcadeVehicleMovementComponent::SetTuningDataAsset(UCaddyVehicleTuningDataAsset* InTuningDataAsset, bool bApplyImmediately)
{
    TuningDataAsset = InTuningDataAsset;
    if (bApplyImmediately)
    {
        ApplyTuningFromDataAsset();
    }
}

void UArcadeVehicleMovementComponent::ApplyTuningFromDataAsset()
{
    if (!TuningDataAsset)
    {
        return;
    }

    GasConfig = TuningDataAsset->GasConfig;
    HandlingConfig = TuningDataAsset->HandlingConfig;
}

FVector2D UArcadeVehicleMovementComponent::GetLocalPlanarVelocity() const
{
    if (!UpdatedComponent)
    {
        return FVector2D::ZeroVector;
    }

    const FVector LocalVelocity = UpdatedComponent->GetComponentRotation().UnrotateVector(Velocity);
    return FVector2D(LocalVelocity.X, LocalVelocity.Y);
}

float UArcadeVehicleMovementComponent::GetTargetYawFromMoveIntent() const
{
    if (!bHasMoveIntent)
    {
        return UpdatedComponent ? UpdatedComponent->GetComponentRotation().Yaw : 0.0f;
    }

    return FMath::RadiansToDegrees(FMath::Atan2(MoveIntentWorldDir.Y, MoveIntentWorldDir.X));
}

void UArcadeVehicleMovementComponent::SetMoveIntent(const FVector2D& InWorldDirection)
{
    const float InputSize = InWorldDirection.Size();
    if (InputSize < HandlingConfig.MoveIntentDeadZone)
    {
        bHasMoveIntent = false;
        MoveIntentWorldDir = FVector2D::ZeroVector;
        return;
    }

    bHasMoveIntent = true;
    MoveIntentWorldDir = InWorldDirection / InputSize;
}

void UArcadeVehicleMovementComponent::SetThrottleInput(float InThrottle)
{
    ThrottleInput = FMath::Clamp(InThrottle, 0.0f, 1.0f);
}

void UArcadeVehicleMovementComponent::SetBrakeReverseInput(float InBrakeReverse)
{
    BrakeReverseInput = FMath::Clamp(InBrakeReverse, 0.0f, 1.0f);
}

void UArcadeVehicleMovementComponent::SetDriftInput(float InDrift)
{
    DriftInput = FMath::Clamp(InDrift, 0.0f, 1.0f);
    bIsDrifting = DriftInput >= HandlingConfig.DriftInputThreshold;
}

void UArcadeVehicleMovementComponent::TickComponent(
    float DeltaTime,
    enum ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    DrawDebugVisuals();

    if (!PawnOwner->HasAuthority())
    {
        return;
    }

    UpdateVelocity(DeltaTime);
    UpdateSteering(DeltaTime, Velocity.SizeSquared2D());
    PerformMovement(DeltaTime);
}

void UArcadeVehicleMovementComponent::UpdateSteering(float DeltaTime, float PlanarSpeedSqr)
{
    if (!bHasMoveIntent)
    {
        return;
    }

    if (PlanarSpeedSqr < FMath::Square(HandlingConfig.MinSpeedForSteering))
    {
        return;
    }

    const float SteeringRateDegPerSec = bIsDrifting
        ? HandlingConfig.SteeringRateDegPerSec * HandlingConfig.DriftSteeringRateMultiplier
        : HandlingConfig.SteeringRateDegPerSec;
    const float TargetYaw = FMath::RadiansToDegrees(FMath::Atan2(MoveIntentWorldDir.Y, MoveIntentWorldDir.X));
    const float CurrentYaw = UpdatedComponent->GetComponentRotation().Yaw;
    const float NewYaw = FMath::FixedTurn(CurrentYaw, TargetYaw, SteeringRateDegPerSec * DeltaTime);
    UpdatedComponent->SetWorldRotation(FRotator(0.0f, NewYaw, 0.0f));
}

void UArcadeVehicleMovementComponent::UpdateVelocity(float DeltaTime)
{
    const FRotator ActorRot = UpdatedComponent->GetComponentRotation();
    FVector LocalVelocity = ActorRot.UnrotateVector(Velocity);

    const bool bHasThrottle = ThrottleInput > KINDA_SMALL_NUMBER;
    const bool bHasBrakeReverse = BrakeReverseInput > KINDA_SMALL_NUMBER;

    if (bHasThrottle && !bHasBrakeReverse)
    {
        const float ForwardAcceleration = ThrottleInput * GasConfig.ForwardAcceleration;
        LocalVelocity.X += ForwardAcceleration * DeltaTime;
    }

    if (bHasBrakeReverse)
    {
        const float BrakeStrength = BrakeReverseInput;
        if (LocalVelocity.X > 0.0f)
        {
            LocalVelocity.X = FMath::FInterpConstantTo(
                LocalVelocity.X,
                0.0f,
                DeltaTime,
                GasConfig.BrakeDeceleration * BrakeStrength);
        }
        else
        {
            LocalVelocity.X -= BrakeStrength * GasConfig.ReverseAcceleration * DeltaTime;
            LocalVelocity.X = FMath::Max(LocalVelocity.X, -GasConfig.MaxReverseSpeed);
        }
    }

    if (!bHasThrottle && !bHasBrakeReverse)
    {
        LocalVelocity.X = FMath::FInterpConstantTo(
            LocalVelocity.X,
            0.0f,
            DeltaTime,
            GasConfig.CoastDeceleration);
    }

    LocalVelocity.X *= FMath::Max(0.0f, 1.0f - (HandlingConfig.LinearDrag * DeltaTime));
    LocalVelocity.X = FMath::Clamp(LocalVelocity.X, -GasConfig.MaxReverseSpeed, GasConfig.MaxForwardSpeed);

    const float LateralFrictionInterpSpeed = bIsDrifting
        ? HandlingConfig.DriftLateralFrictionInterpSpeed
        : HandlingConfig.LateralFrictionInterpSpeed;
    LocalVelocity.Y = FMath::FInterpTo(LocalVelocity.Y, 0.0f, DeltaTime, LateralFrictionInterpSpeed);
    LocalVelocity.Z = 0.0f;

    Velocity = ActorRot.RotateVector(LocalVelocity);
    Velocity.Z = 0.0f;
}

void UArcadeVehicleMovementComponent::PerformMovement(float DeltaTime)
{
    if (Velocity.SizeSquared2D() <= FMath::Square(HandlingConfig.StopSpeedThreshold))
    {
        Velocity = FVector::ZeroVector;
        return;
    }

    const FVector Delta = Velocity * DeltaTime;
    FHitResult Hit;
    SafeMoveUpdatedComponent(Delta, UpdatedComponent->GetComponentQuat(), true, Hit);

    if (Hit.IsValidBlockingHit())
    {
        SlideAlongSurface(Delta, 1.0f - Hit.Time, Hit.Normal, Hit, true);
        Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal) * HandlingConfig.CollisionSpeedRetainRatio;
        Velocity.Z = 0.0f;
    }
}

void UArcadeVehicleMovementComponent::DrawDebugVisuals() const
{
    if (!bEnableDebugDraw || !UpdatedComponent || !PawnOwner)
    {
        return;
    }

    if (bDebugDrawOnlyForLocalPawn && !PawnOwner->IsLocallyControlled())
    {
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    const FVector Origin = UpdatedComponent->GetComponentLocation() + FVector(0.0f, 0.0f, DebugDrawZOffset);
    const FRotator ActorRotation = UpdatedComponent->GetComponentRotation();
    const FVector Forward = ActorRotation.RotateVector(FVector::ForwardVector);
    const FVector Right = ActorRotation.RotateVector(FVector::RightVector);
    const float Thickness = FMath::Max(0.0f, DebugLineThickness);
    const float BaseLength = FMath::Max(10.0f, DebugDirectionLineLength);

    DrawDebugLine(World, Origin, Origin + (Forward * BaseLength), FColor::Green, false, 0.0f, 0, Thickness);
    DrawDebugLine(World, Origin, Origin + (Right * (BaseLength * 0.45f)), FColor(100, 140, 255), false, 0.0f, 0, Thickness * 0.75f);

    if (bHasMoveIntent)
    {
        const FVector TargetDirection = FVector(MoveIntentWorldDir.X, MoveIntentWorldDir.Y, 0.0f).GetSafeNormal();
        DrawDebugLine(World, Origin, Origin + (TargetDirection * BaseLength), FColor::Cyan, false, 0.0f, 0, Thickness);
    }

    const FVector PlanarVelocity(Velocity.X, Velocity.Y, 0.0f);
    const float PlanarSpeed = PlanarVelocity.Size();
    if (PlanarSpeed > 1.0f)
    {
        const float VelocityLength = FMath::Clamp(PlanarSpeed * FMath::Max(0.01f, DebugVelocityLineScale), 60.0f, BaseLength * 1.8f);
        const FVector VelocityDirection = PlanarVelocity / PlanarSpeed;
        DrawDebugLine(World, Origin, Origin + (VelocityDirection * VelocityLength), FColor::Yellow, false, 0.0f, 0, Thickness);
    }

    const FVector2D LocalVelocity = GetLocalPlanarVelocity();
    if (FMath::Abs(LocalVelocity.Y) > 1.0f)
    {
        const float LateralLength = FMath::Clamp(FMath::Abs(LocalVelocity.Y) * 0.06f, 40.0f, BaseLength);
        const float LateralSign = FMath::Sign(LocalVelocity.Y);
        DrawDebugLine(World, Origin, Origin + (Right * LateralLength * LateralSign), FColor::Orange, false, 0.0f, 0, Thickness);
    }

    if (bIsDrifting)
    {
        DrawDebugSphere(World, Origin + FVector(0.0f, 0.0f, 14.0f), 12.0f, 10, FColor::Magenta, false, 0.0f, 0, Thickness * 0.75f);
    }
}
