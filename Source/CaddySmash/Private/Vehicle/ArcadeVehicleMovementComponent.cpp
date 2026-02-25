#include "Vehicle/ArcadeVehicleMovementComponent.h"

#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "HitRegister/HitRegisterBPLibrary.h"
#include "HitRegister/HitRegisterPipeline.h"
#include "HitRegister/HitRegisterTypes.h"
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
    CollisionConfig = TuningDataAsset->CollisionConfig;
    CollisionHitRegisterPipeline = TuningDataAsset->CollisionHitRegisterPipeline;
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

float UArcadeVehicleMovementComponent::GetTimeSinceLastBlockingHit() const
{
    if (LastBlockingHitWorldTime < 0.0f || !GetWorld())
    {
        return -1.0f;
    }

    return GetWorld()->GetTimeSeconds() - LastBlockingHitWorldTime;
}

FString UArcadeVehicleMovementComponent::GetLastCollisionActorName() const
{
    return LastBlockingHitActor.IsValid() ? LastBlockingHitActor->GetName() : TEXT("None");
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

    FVector RemainingDelta = Velocity * DeltaTime;
    const int32 MaxIterations = FMath::Clamp(CollisionConfig.MaxCollisionIterations, 1, 4);
    for (int32 Iteration = 0; Iteration < MaxIterations; ++Iteration)
    {
        if (RemainingDelta.SizeSquared2D() <= FMath::Square(HandlingConfig.StopSpeedThreshold * DeltaTime))
        {
            break;
        }

        FHitResult Hit;
        const FVector PreImpactVelocity = Velocity;
        SafeMoveUpdatedComponent(RemainingDelta, UpdatedComponent->GetComponentQuat(), true, Hit);

        if (!Hit.IsValidBlockingHit())
        {
            break;
        }

        HandleBlockingCollision(PreImpactVelocity, Hit, RemainingDelta, DeltaTime);

        const float RemainingTimeRatio = FMath::Clamp(1.0f - Hit.Time, 0.0f, 1.0f);
        if (RemainingTimeRatio <= KINDA_SMALL_NUMBER)
        {
            break;
        }

        RemainingDelta = Velocity * DeltaTime * RemainingTimeRatio;
    }

    if (Velocity.SizeSquared2D() <= FMath::Square(HandlingConfig.StopSpeedThreshold))
    {
        Velocity = FVector::ZeroVector;
    }
}

void UArcadeVehicleMovementComponent::HandleBlockingCollision(
    const FVector& PreImpactVelocity,
    const FHitResult& Hit,
    const FVector& AttemptedDelta,
    float DeltaTime)
{
    FHitResult SlideHit = Hit;
    SlideAlongSurface(AttemptedDelta, 1.0f - Hit.Time, Hit.Normal, SlideHit, true);

    float NormalImpactSpeed = 0.0f;
    FVector TangentDirection = FVector::ZeroVector;
    FVector ResolvedPlanarVelocity = FVector::VectorPlaneProject(PreImpactVelocity, Hit.Normal)
        * FMath::Clamp(CollisionConfig.SpeedRetainRatio, 0.0f, 1.0f);

    if (CollisionConfig.ResponseMode == ECaddyVehicleCollisionResponseMode::ArcadeWallGlide)
    {
        ResolvedPlanarVelocity = ComputeArcadeWallGlideVelocity(PreImpactVelocity, Hit, DeltaTime, NormalImpactSpeed, TangentDirection);
    }
    else
    {
        const FVector PlanarNormal = FVector(Hit.Normal.X, Hit.Normal.Y, 0.0f).GetSafeNormal();
        const FVector PlanarVelocity = FVector(PreImpactVelocity.X, PreImpactVelocity.Y, 0.0f);
        NormalImpactSpeed = FMath::Max(0.0f, -FVector::DotProduct(PlanarVelocity, PlanarNormal));
        TangentDirection = FVector::VectorPlaneProject(PlanarVelocity, PlanarNormal).GetSafeNormal2D();
    }

    Velocity = ResolvedPlanarVelocity;
    Velocity.Z = 0.0f;

    const float TotalSpeed = FVector(PreImpactVelocity.X, PreImpactVelocity.Y, 0.0f).Size();
    CacheCollisionTelemetry(Hit, TotalSpeed, NormalImpactSpeed, TangentDirection);
    TryEmitCollisionHitRegisterEvent(Hit, TotalSpeed, NormalImpactSpeed);

    if (CollisionConfig.PushOutDistance > KINDA_SMALL_NUMBER)
    {
        const FVector PlanarNormal = FVector(Hit.Normal.X, Hit.Normal.Y, 0.0f).GetSafeNormal();
        if (!PlanarNormal.IsNearlyZero())
        {
            FHitResult PushOutHit;
            SafeMoveUpdatedComponent(PlanarNormal * CollisionConfig.PushOutDistance, UpdatedComponent->GetComponentQuat(), true, PushOutHit);
        }
    }
}

FVector UArcadeVehicleMovementComponent::ComputeArcadeWallGlideVelocity(
    const FVector& PreImpactVelocity,
    const FHitResult& Hit,
    float DeltaTime,
    float& OutNormalImpactSpeed,
    FVector& OutTangentDirection) const
{
    OutNormalImpactSpeed = 0.0f;
    OutTangentDirection = FVector::ZeroVector;

    const FVector PlanarNormal = FVector(Hit.Normal.X, Hit.Normal.Y, 0.0f).GetSafeNormal();
    if (PlanarNormal.IsNearlyZero())
    {
        return FVector::ZeroVector;
    }

    const FVector PlanarVelocity = FVector(PreImpactVelocity.X, PreImpactVelocity.Y, 0.0f);
    const FVector PlanarProjectedVelocity = FVector::VectorPlaneProject(PlanarVelocity, PlanarNormal);
    const float ProjectedSpeed = PlanarProjectedVelocity.Size();

    OutNormalImpactSpeed = FMath::Max(0.0f, -FVector::DotProduct(PlanarVelocity, PlanarNormal));
    OutTangentDirection = PlanarProjectedVelocity.GetSafeNormal2D();

    float TargetSpeed = ProjectedSpeed;
    if (OutNormalImpactSpeed >= CollisionConfig.MinNormalImpactSpeedForGlide)
    {
        TargetSpeed = FMath::Max(TargetSpeed, OutNormalImpactSpeed * CollisionConfig.HeadOnGlideSpeedScale);
    }

    if (OutNormalImpactSpeed >= CollisionConfig.MinNormalImpactSpeedForGlide && TargetSpeed < CollisionConfig.MinWallGlideSpeed)
    {
        TargetSpeed = CollisionConfig.MinWallGlideSpeed;
    }

    if (OutTangentDirection.IsNearlyZero())
    {
        FVector PreferredDirection = UpdatedComponent
            ? UpdatedComponent->GetForwardVector().GetSafeNormal2D()
            : FVector::ForwardVector;
        if (bHasMoveIntent)
        {
            PreferredDirection = FVector(MoveIntentWorldDir.X, MoveIntentWorldDir.Y, 0.0f).GetSafeNormal();
        }

        const FVector TangentA = FVector::CrossProduct(FVector::UpVector, PlanarNormal).GetSafeNormal2D();
        const FVector TangentB = -TangentA;
        const float DotA = FVector::DotProduct(TangentA, PreferredDirection);
        const float DotB = FVector::DotProduct(TangentB, PreferredDirection);
        OutTangentDirection = (DotA >= DotB) ? TangentA : TangentB;
    }

    FVector DesiredVelocity = OutTangentDirection * TargetSpeed;

    if (bHasMoveIntent)
    {
        const FVector IntentDirection = FVector(MoveIntentWorldDir.X, MoveIntentWorldDir.Y, 0.0f).GetSafeNormal();
        const FVector IntentAlongWall = FVector::VectorPlaneProject(IntentDirection, PlanarNormal).GetSafeNormal2D();
        if (!IntentAlongWall.IsNearlyZero())
        {
            const float Assist = FMath::Clamp(CollisionConfig.WallGlideInputAssist, 0.0f, 1.0f);
            DesiredVelocity = FMath::Lerp(DesiredVelocity, IntentAlongWall * TargetSpeed, Assist);
            OutTangentDirection = DesiredVelocity.GetSafeNormal2D();
        }
    }

    const float RetainRatio = FMath::Clamp(CollisionConfig.SpeedRetainRatio, 0.0f, 1.0f);
    DesiredVelocity *= RetainRatio;

    const float InterpSpeed = FMath::Max(0.0f, CollisionConfig.WallGlideVelocityInterpSpeed);
    const FVector Blended = (InterpSpeed <= KINDA_SMALL_NUMBER)
        ? DesiredVelocity
        : FMath::VInterpTo(PlanarProjectedVelocity, DesiredVelocity, DeltaTime, InterpSpeed);

    FVector Result = FVector(Blended.X, Blended.Y, 0.0f);
    if (OutNormalImpactSpeed >= CollisionConfig.MinNormalImpactSpeedForGlide
        && Result.SizeSquared2D() < FMath::Square(CollisionConfig.MinWallGlideSpeed * RetainRatio * 0.5f)
        && !OutTangentDirection.IsNearlyZero())
    {
        Result = OutTangentDirection * (CollisionConfig.MinWallGlideSpeed * RetainRatio);
    }

    return Result;
}

void UArcadeVehicleMovementComponent::TryEmitCollisionHitRegisterEvent(const FHitResult& Hit, float TotalSpeed, float NormalImpactSpeed)
{
    bLastCollisionTriggeredHitRegister = false;
    bLastCollisionHitRegisterSucceeded = false;
    LastCollisionHitRegisterStatus = TEXT("Filtered");

    if (!PawnOwner || !PawnOwner->HasAuthority())
    {
        LastCollisionHitRegisterStatus = TEXT("AuthorityOnly");
        return;
    }

    const FCaddyVehicleCollisionHitRegisterConfig& HitRegisterConfig = CollisionConfig.HitRegister;
    if (!HitRegisterConfig.bEnableCollisionHitRegister)
    {
        LastCollisionHitRegisterStatus = TEXT("Disabled");
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        LastCollisionHitRegisterStatus = TEXT("NoWorld");
        return;
    }

    const float Now = World->GetTimeSeconds();
    if (HitRegisterConfig.EventCooldownSeconds > 0.0f
        && LastCollisionHitRegisterWorldTime >= 0.0f
        && (Now - LastCollisionHitRegisterWorldTime) < HitRegisterConfig.EventCooldownSeconds)
    {
        LastCollisionHitRegisterStatus = TEXT("Cooldown");
        return;
    }

    if (TotalSpeed < HitRegisterConfig.MinSpeedForEvent)
    {
        LastCollisionHitRegisterStatus = TEXT("SpeedBelowThreshold");
        return;
    }

    if (NormalImpactSpeed < HitRegisterConfig.MinNormalImpactSpeedForEvent)
    {
        LastCollisionHitRegisterStatus = TEXT("NormalSpeedBelowThreshold");
        return;
    }

    FAttackRequest AttackRequest;
    AttackRequest.Instigator = PawnOwner;
    AttackRequest.SourceObject = this;
    AttackRequest.BaseDamage = FMath::Max(
        0.0f,
        HitRegisterConfig.BaseDamageBias + (NormalImpactSpeed * HitRegisterConfig.BaseDamageByNormalImpactSpeed));
    AttackRequest.Tags.AppendTags(HitRegisterConfig.BaseTags);

    const UPrimitiveComponent* HitComponent = Hit.GetComponent();
    if (HitComponent)
    {
        if (HitComponent->GetCollisionObjectType() == ECC_WorldStatic && HitRegisterConfig.WorldStaticTag.IsValid())
        {
            AttackRequest.Tags.AddTag(HitRegisterConfig.WorldStaticTag);
        }
        if (HitComponent->GetCollisionObjectType() == ECC_WorldDynamic && HitRegisterConfig.WorldDynamicTag.IsValid())
        {
            AttackRequest.Tags.AddTag(HitRegisterConfig.WorldDynamicTag);
        }
        if (HitComponent->GetCollisionObjectType() == ECC_Pawn && HitRegisterConfig.PawnTag.IsValid())
        {
            AttackRequest.Tags.AddTag(HitRegisterConfig.PawnTag);
        }
    }

    if (bIsDrifting && HitRegisterConfig.DriftingTag.IsValid())
    {
        AttackRequest.Tags.AddTag(HitRegisterConfig.DriftingTag);
    }

    if (HitRegisterConfig.SpeedAttributeTag.IsValid())
    {
        AttackRequest.Attributes.Add(HitRegisterConfig.SpeedAttributeTag, TotalSpeed);
    }
    if (HitRegisterConfig.NormalImpactSpeedAttributeTag.IsValid())
    {
        AttackRequest.Attributes.Add(HitRegisterConfig.NormalImpactSpeedAttributeTag, NormalImpactSpeed);
    }
    if (HitRegisterConfig.DriftingAttributeTag.IsValid())
    {
        AttackRequest.Attributes.Add(HitRegisterConfig.DriftingAttributeTag, bIsDrifting ? 1.0f : 0.0f);
    }

    FHitRegisterContext Context;
    bool bHitRegisterResult = false;
    if (CollisionHitRegisterPipeline)
    {
        bHitRegisterResult = UHitRegisterBPLibrary::ExecuteHitRegister(this, AttackRequest, Hit, CollisionHitRegisterPipeline, Context);
    }
    else
    {
        bHitRegisterResult = UHitRegisterBPLibrary::ExecuteHitRegisterDefault(this, AttackRequest, Hit, Context);
    }

    bLastCollisionTriggeredHitRegister = true;
    bLastCollisionHitRegisterSucceeded = bHitRegisterResult;
    LastCollisionHitRegisterWorldTime = Now;

    if (bHitRegisterResult)
    {
        LastCollisionHitRegisterStatus = TEXT("Success");
    }
    else
    {
        const UEnum* StopReasonEnum = StaticEnum<EHitRegisterStopReason>();
        const FString StopReason = StopReasonEnum
            ? StopReasonEnum->GetNameStringByValue(static_cast<int64>(Context.Result.StopReason))
            : TEXT("Unknown");
        LastCollisionHitRegisterStatus = FString::Printf(TEXT("Stopped:%s"), *StopReason);
    }
}

void UArcadeVehicleMovementComponent::CacheCollisionTelemetry(
    const FHitResult& Hit,
    float TotalSpeed,
    float NormalImpactSpeed,
    const FVector& TangentDirection)
{
    UWorld* World = GetWorld();
    LastBlockingHitWorldTime = World ? World->GetTimeSeconds() : -1.0f;
    LastBlockingHitSpeed = TotalSpeed;
    LastBlockingHitNormalSpeed = NormalImpactSpeed;
    LastBlockingHitLocation = Hit.ImpactPoint;
    LastBlockingHitNormal = Hit.Normal.GetSafeNormal();
    LastBlockingHitTangent = TangentDirection.GetSafeNormal2D();
    LastBlockingHitActor = Hit.GetActor();
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

    const float CollisionAge = (LastBlockingHitWorldTime >= 0.0f) ? (World->GetTimeSeconds() - LastBlockingHitWorldTime) : BIG_NUMBER;
    if (CollisionAge <= CollisionConfig.DebugPersistSeconds)
    {
        const FVector HitPoint = LastBlockingHitLocation + FVector(0.0f, 0.0f, 3.0f);
        const FVector HitNormal = LastBlockingHitNormal.GetSafeNormal();
        const FVector HitTangent = LastBlockingHitTangent.GetSafeNormal2D();

        DrawDebugSphere(World, HitPoint, 10.0f, 10, FColor::Red, false, 0.0f, 0, Thickness);
        if (!HitNormal.IsNearlyZero())
        {
            DrawDebugLine(World, HitPoint, HitPoint + (HitNormal * 120.0f), FColor::Red, false, 0.0f, 0, Thickness);
        }
        if (!HitTangent.IsNearlyZero())
        {
            DrawDebugLine(World, HitPoint, HitPoint + (HitTangent * 120.0f), FColor::Blue, false, 0.0f, 0, Thickness);
        }

        if (bLastCollisionTriggeredHitRegister)
        {
            const FColor HitRegisterColor = bLastCollisionHitRegisterSucceeded ? FColor::Green : FColor::Orange;
            DrawDebugSphere(World, HitPoint + FVector(0.0f, 0.0f, 18.0f), 6.0f, 8, HitRegisterColor, false, 0.0f, 0, Thickness * 0.8f);
        }
    }
}
