#include "Vehicle/Abilities/CaddyVehicleBrakeDashAbility.h"

#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/Abilities/Targeting/CaddyVehicleSkillTargetActor_Trace.h"
#include "Vehicle/CaddyVehicleSkillComponent.h"

UCaddyVehicleBrakeDashAbility::UCaddyVehicleBrakeDashAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
    ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
}

bool UCaddyVehicleBrakeDashAbility::CanActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayTagContainer* SourceTags,
    const FGameplayTagContainer* TargetTags,
    FGameplayTagContainer* OptionalRelevantTags) const
{
    if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
    {
        return false;
    }

    if (!ResolveSkillRig(false))
    {
        return false;
    }

    const UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    if (!SkillComponent
        || !SkillComponent->bUseGASAbilityStateMachine
        || !SkillComponent->BrakeDashConfig.bEnableBrakeDashSkill)
    {
        return false;
    }

    if (SkillComponent->SkillState != ECaddyVehicleSkillState::Ready)
    {
        return false;
    }

    if (SkillComponent->CooldownRemainingSeconds > KINDA_SMALL_NUMBER)
    {
        return false;
    }

    return IsTriggerSourceHeld();
}

void UCaddyVehicleBrakeDashAbility::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    if (!ResolveSkillRig(true))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    UWorld* World = GetWorld();
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!World || !SkillComponent || !MovementComponent)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    DestroySkillTargetActor();
    CachedTargetDataHandle.Clear();

    SkillComponent->SkillState = ECaddyVehicleSkillState::Ready;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->TriggerHoldSeconds = 0.0f;
    SkillComponent->bTriggerLatch = false;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    SkillComponent->CurrentChargeSeconds = 0.0f;
    SkillComponent->CurrentChargeAlpha = 0.0f;
    SkillComponent->ActiveDashDuration = 0.0f;
    SkillComponent->ActiveDashPeakSpeed = 0.0f;
    SkillComponent->bUsingAbilityTargetAim = false;
    SkillComponent->CurrentAbilityTargetActor = nullptr;
    SkillComponent->CurrentAbilityTargetLocation = FVector::ZeroVector;
    MovementComponent->SetExternalVelocityControlEnabled(false);

    LastTickTimeSeconds = World->GetTimeSeconds();
    World->GetTimerManager().SetTimer(
        SkillTickTimerHandle,
        this,
        &UCaddyVehicleBrakeDashAbility::TickSkillStateMachine,
        1.0f / 120.0f,
        true);

    TickSkillStateMachine();
}

void UCaddyVehicleBrakeDashAbility::EndAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const bool bReplicateEndAbility,
    const bool bWasCancelled)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(SkillTickTimerHandle);
    }
    DestroySkillTargetActor();
    CachedTargetDataHandle.Clear();

    if (bWasCancelled)
    {
        AbortToReady();
    }

    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

bool UCaddyVehicleBrakeDashAbility::ResolveSkillRig(const bool bLogFailures) const
{
    APawn* Pawn = CachedPawn.Get();
    if (!Pawn)
    {
        Pawn = Cast<APawn>(GetAvatarActorFromActorInfo());
        if (!Pawn && CurrentActorInfo)
        {
            Pawn = Cast<APawn>(CurrentActorInfo->AvatarActor.Get());
        }
        CachedPawn = Pawn;
    }

    if (!Pawn)
    {
        return false;
    }

    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    if (!SkillComponent)
    {
        SkillComponent = Pawn->FindComponentByClass<UCaddyVehicleSkillComponent>();
        CachedSkillComponent = SkillComponent;
    }

    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!MovementComponent)
    {
        MovementComponent = Pawn->FindComponentByClass<UArcadeVehicleMovementComponent>();
        CachedMovement = MovementComponent;
    }

    const bool bReady = SkillComponent && MovementComponent;
    if (!bReady && bLogFailures)
    {
        UE_LOG(LogTemp, Warning, TEXT("CaddyVehicleBrakeDashAbility: missing skill or movement component on %s"), *GetNameSafe(Pawn));
    }
    return bReady;
}

bool UCaddyVehicleBrakeDashAbility::IsTriggerSourceHeld() const
{
    const UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    const UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        return false;
    }

    if (SkillComponent->BrakeDashConfig.TriggerMode == ECaddyVehicleSkillTriggerMode::BrakeThrottleCombo)
    {
        return MovementComponent->GetThrottleInput() >= SkillComponent->BrakeDashConfig.TriggerThrottleThreshold
            && MovementComponent->GetBrakeReverseInput() >= SkillComponent->BrakeDashConfig.TriggerBrakeThreshold;
    }

    return SkillComponent->bSkillInputPressed;
}

float UCaddyVehicleBrakeDashAbility::ComputeDeltaTime()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return 1.0f / 120.0f;
    }

    const double NowSeconds = World->GetTimeSeconds();
    const float DeltaTime = (LastTickTimeSeconds > 0.0)
        ? FMath::Clamp(static_cast<float>(NowSeconds - LastTickTimeSeconds), 0.0f, 0.1f)
        : World->GetDeltaSeconds();
    LastTickTimeSeconds = NowSeconds;
    return DeltaTime;
}

ACaddyVehicleSkillTargetActor_Trace* UCaddyVehicleBrakeDashAbility::GetOrCreateSkillTargetActor()
{
    if (ACaddyVehicleSkillTargetActor_Trace* ExistingTargetActor = SkillTargetActor.Get())
    {
        return ExistingTargetActor;
    }

    if (!ResolveSkillRig(false))
    {
        return nullptr;
    }

    UWorld* World = GetWorld();
    APawn* Pawn = CachedPawn.Get();
    if (!World || !Pawn)
    {
        return nullptr;
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = Pawn;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ACaddyVehicleSkillTargetActor_Trace* TargetActor = World->SpawnActor<ACaddyVehicleSkillTargetActor_Trace>(
        ACaddyVehicleSkillTargetActor_Trace::StaticClass(),
        Pawn->GetActorLocation(),
        FRotator::ZeroRotator,
        SpawnParams);
    if (!TargetActor)
    {
        return nullptr;
    }

    TargetActor->SetActorHiddenInGame(true);
    TargetActor->StartTargeting(this);
    TargetActor->TargetDataReadyDelegate.AddUObject(this, &UCaddyVehicleBrakeDashAbility::HandleSkillTargetDataReady);
    SkillTargetActor = TargetActor;
    return TargetActor;
}

void UCaddyVehicleBrakeDashAbility::DestroySkillTargetActor()
{
    if (ACaddyVehicleSkillTargetActor_Trace* TargetActor = SkillTargetActor.Get())
    {
        TargetActor->TargetDataReadyDelegate.RemoveAll(this);
        TargetActor->Destroy();
    }
    SkillTargetActor = nullptr;
}

void UCaddyVehicleBrakeDashAbility::HandleSkillTargetDataReady(const FGameplayAbilityTargetDataHandle& DataHandle)
{
    CachedTargetDataHandle = DataHandle;
}

void UCaddyVehicleBrakeDashAbility::RefreshTargetDataFromGAS()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        CachedTargetDataHandle.Clear();
        return;
    }

    const FCaddyVehicleSkillAbilityTargetingConfig& TargetingConfig = SkillComponent->BrakeDashConfig.AbilityTargeting;
    if (!TargetingConfig.bEnableAbilityTargeting)
    {
        CachedTargetDataHandle.Clear();
        return;
    }

    ACaddyVehicleSkillTargetActor_Trace* TargetActor = GetOrCreateSkillTargetActor();
    if (!TargetActor)
    {
        CachedTargetDataHandle.Clear();
        return;
    }

    FVector2D AimHint = FVector2D::ZeroVector;
    if (MovementComponent->HasMoveIntent())
    {
        const FVector2D MoveIntent = MovementComponent->GetMoveIntent();
        if (MoveIntent.SizeSquared() >= FMath::Square(SkillComponent->BrakeDashConfig.AimInputDeadZone))
        {
            AimHint = MoveIntent.GetSafeNormal();
        }
    }
    if (AimHint.IsNearlyZero())
    {
        AimHint = SkillComponent->CurrentAimDirection.IsNearlyZero()
            ? SkillComponent->ResolveFallbackAimDirection()
            : SkillComponent->CurrentAimDirection;
    }

    TargetActor->Configure(
        TargetingConfig.TraceDistance,
        TargetingConfig.TraceRadius,
        TargetingConfig.TraceChannel,
        TargetingConfig.TargetingProfile.Get(),
        TargetingConfig.bEnableDebugDraw,
        TargetingConfig.DebugPersistSeconds);
    TargetActor->SetAimDirectionHint2D(AimHint);

    CachedTargetDataHandle.Clear();
    TargetActor->ConfirmTargetingAndContinue();
}

void UCaddyVehicleBrakeDashAbility::ResolveAndApplyAimDirection()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    APawn* Pawn = CachedPawn.Get();
    if (!SkillComponent || !MovementComponent || !Pawn)
    {
        return;
    }

    FVector2D InputAim = FVector2D::ZeroVector;
    const bool bHasInputAim = MovementComponent->HasMoveIntent()
        && MovementComponent->GetMoveIntent().SizeSquared() >= FMath::Square(SkillComponent->BrakeDashConfig.AimInputDeadZone);
    if (bHasInputAim)
    {
        InputAim = MovementComponent->GetMoveIntent().GetSafeNormal();
    }

    FVector2D AbilityTargetAim = FVector2D::ZeroVector;
    AActor* AbilityTargetActor = nullptr;
    FVector AbilityTargetLocation = FVector::ZeroVector;
    bool bHasAbilityTargetAim = false;

    if (SkillComponent->BrakeDashConfig.AbilityTargeting.bEnableAbilityTargeting)
    {
        RefreshTargetDataFromGAS();

        if (const FGameplayAbilityTargetData* TargetData = CachedTargetDataHandle.Get(0))
        {
            const FHitResult* HitResult = TargetData->GetHitResult();
            if (HitResult)
            {
                AbilityTargetActor = HitResult->GetActor();
                AbilityTargetLocation = HitResult->ImpactPoint.IsNearlyZero() ? HitResult->Location : HitResult->ImpactPoint;
            }
            else
            {
                const TArray<TWeakObjectPtr<AActor>> TargetActors = TargetData->GetActors();
                if (TargetActors.Num() > 0 && TargetActors[0].IsValid())
                {
                    AbilityTargetActor = TargetActors[0].Get();
                    AbilityTargetLocation = AbilityTargetActor->GetActorLocation();
                }
            }
        }

        if (!AbilityTargetLocation.IsNearlyZero())
        {
            FVector ToTarget = AbilityTargetLocation - Pawn->GetActorLocation();
            ToTarget.Z = 0.0f;
            if (!ToTarget.IsNearlyZero())
            {
                AbilityTargetAim = FVector2D(ToTarget.X, ToTarget.Y).GetSafeNormal();
                bHasAbilityTargetAim = !AbilityTargetAim.IsNearlyZero();
            }
        }
    }

    bool bSelectedAbilityTargetAim = false;
    FVector2D SelectedAim = SkillComponent->CurrentAimDirection;
    switch (SkillComponent->BrakeDashConfig.AbilityTargeting.AimSelectionMode)
    {
    case ECaddyVehicleSkillAimSelectionMode::InputOnly:
        if (bHasInputAim)
        {
            SelectedAim = InputAim;
        }
        break;
    case ECaddyVehicleSkillAimSelectionMode::AbilityTargetOnly:
        if (bHasAbilityTargetAim)
        {
            SelectedAim = AbilityTargetAim;
            bSelectedAbilityTargetAim = true;
        }
        break;
    case ECaddyVehicleSkillAimSelectionMode::AbilityTargetPreferInputFallback:
    default:
        if (bHasAbilityTargetAim)
        {
            SelectedAim = AbilityTargetAim;
            bSelectedAbilityTargetAim = true;
        }
        else if (bHasInputAim)
        {
            SelectedAim = InputAim;
        }
        break;
    }

    if (SelectedAim.IsNearlyZero())
    {
        SelectedAim = SkillComponent->ResolveFallbackAimDirection();
    }
    SkillComponent->CurrentAimDirection = SelectedAim.IsNearlyZero()
        ? FVector2D(1.0f, 0.0f)
        : SelectedAim.GetSafeNormal();

    if (bSelectedAbilityTargetAim)
    {
        SkillComponent->bUsingAbilityTargetAim = true;
        SkillComponent->CurrentAbilityTargetActor = AbilityTargetActor;
        SkillComponent->CurrentAbilityTargetLocation = AbilityTargetLocation;
    }
    else
    {
        SkillComponent->bUsingAbilityTargetAim = false;
        SkillComponent->CurrentAbilityTargetActor = nullptr;
        SkillComponent->CurrentAbilityTargetLocation = FVector::ZeroVector;
    }
}

void UCaddyVehicleBrakeDashAbility::TickSkillStateMachine()
{
    if (!IsActive())
    {
        return;
    }

    if (!ResolveSkillRig(true))
    {
        EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
        return;
    }

    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
        return;
    }

    const float DeltaTime = ComputeDeltaTime();
    if (DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    if (!SkillComponent->BrakeDashConfig.bEnableBrakeDashSkill)
    {
        AbortToReady();
        EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
        return;
    }

    const bool bTriggerSourceHeld = IsTriggerSourceHeld();
    if (!bTriggerSourceHeld)
    {
        SkillComponent->TriggerHoldSeconds = 0.0f;
        SkillComponent->bTriggerLatch = false;
    }

    if (SkillComponent->SkillState == ECaddyVehicleSkillState::Ready
        && SkillComponent->CooldownRemainingSeconds <= KINDA_SMALL_NUMBER
        && bTriggerSourceHeld
        && !SkillComponent->bTriggerLatch)
    {
        SkillComponent->TriggerHoldSeconds += DeltaTime;
        if (SkillComponent->TriggerHoldSeconds >= SkillComponent->BrakeDashConfig.TriggerInputHoldSeconds)
        {
            SkillComponent->bTriggerLatch = true;
            EnterBrakePhase();
        }
    }

    if (SkillComponent->SkillState == ECaddyVehicleSkillState::Ready)
    {
        if (!bTriggerSourceHeld)
        {
            EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
        }
        return;
    }

    SkillComponent->StateElapsedSeconds += DeltaTime;

    switch (SkillComponent->SkillState)
    {
    case ECaddyVehicleSkillState::Braking:
    {
        ResolveAndApplyAimDirection();
        SkillComponent->RotateOwnerTowardCurrentAim(DeltaTime);

        const float BrakeDuration = FMath::Max(0.01f, SkillComponent->BrakeDashConfig.BrakeDuration);
        const float T = FMath::Clamp(SkillComponent->StateElapsedSeconds / BrakeDuration, 0.0f, 1.0f);
        const float SpeedAlpha = FMath::Clamp(SkillComponent->EvaluateBrakeSpeedAlpha(T), 0.0f, 1.0f);
        SkillComponent->CurrentOverrideSpeed = SkillComponent->BrakingStartSpeed * SpeedAlpha;
        SkillComponent->ApplyOverrideVelocity(SkillComponent->BrakingVelocityDirection * SkillComponent->CurrentOverrideSpeed);

        if (T >= 1.0f)
        {
            SkillComponent->ApplyOverrideVelocity(FVector::ZeroVector);
            EnterChargingPhase();
        }
        break;
    }
    case ECaddyVehicleSkillState::Charging:
    {
        ResolveAndApplyAimDirection();
        SkillComponent->RotateOwnerTowardCurrentAim(DeltaTime);

        SkillComponent->CurrentChargeSeconds = FMath::Clamp(
            SkillComponent->StateElapsedSeconds,
            0.0f,
            FMath::Max(0.01f, SkillComponent->BrakeDashConfig.MaxChargeSeconds));
        SkillComponent->CurrentChargeAlpha = SkillComponent->EvaluateChargeAlpha(SkillComponent->CurrentChargeSeconds);

        SkillComponent->CurrentOverrideSpeed = 0.0f;
        SkillComponent->ApplyOverrideVelocity(FVector::ZeroVector);

        const bool bReachedMaxCharge = SkillComponent->CurrentChargeSeconds >= SkillComponent->BrakeDashConfig.MaxChargeSeconds;
        const bool bCanRelease = SkillComponent->CurrentChargeSeconds >= SkillComponent->BrakeDashConfig.MinChargeSeconds;
        const bool bReleased = !bTriggerSourceHeld;
        if (bReachedMaxCharge || (bReleased && bCanRelease))
        {
            EnterDashPhase();
        }
        break;
    }
    case ECaddyVehicleSkillState::Dashing:
    {
        const float DashDuration = FMath::Max(0.01f, SkillComponent->ActiveDashDuration);
        const float T = FMath::Clamp(SkillComponent->StateElapsedSeconds / DashDuration, 0.0f, 1.0f);
        const float DashAlpha = FMath::Clamp(SkillComponent->EvaluateDashSpeedAlpha(T), 0.0f, 1.0f);
        SkillComponent->CurrentOverrideSpeed = SkillComponent->ActiveDashPeakSpeed * DashAlpha;
        SkillComponent->ApplyOverrideVelocity(
            FVector(SkillComponent->DashDirection.X, SkillComponent->DashDirection.Y, 0.0f) * SkillComponent->CurrentOverrideSpeed);

        if (T >= 1.0f)
        {
            ExitDashPhase();
            EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
        }
        break;
    }
    default:
        break;
    }
}

void UCaddyVehicleBrakeDashAbility::EnterBrakePhase()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        return;
    }

    SkillComponent->SkillState = ECaddyVehicleSkillState::Braking;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    SkillComponent->CurrentChargeSeconds = 0.0f;
    SkillComponent->CurrentChargeAlpha = 0.0f;
    SkillComponent->ActiveDashDuration = 0.0f;
    SkillComponent->ActiveDashPeakSpeed = 0.0f;

    ResolveAndApplyAimDirection();
    if (SkillComponent->CurrentAimDirection.IsNearlyZero())
    {
        SkillComponent->CurrentAimDirection = SkillComponent->ResolveFallbackAimDirection();
    }

    const FVector CurrentVelocity = MovementComponent->GetPlanarVelocityWorld();
    SkillComponent->BrakingStartSpeed = CurrentVelocity.Size2D();
    if (SkillComponent->BrakingStartSpeed > KINDA_SMALL_NUMBER)
    {
        SkillComponent->BrakingVelocityDirection = CurrentVelocity.GetSafeNormal2D();
    }
    else
    {
        SkillComponent->BrakingVelocityDirection = FVector(
            SkillComponent->CurrentAimDirection.X,
            SkillComponent->CurrentAimDirection.Y,
            0.0f).GetSafeNormal2D();
    }

    MovementComponent->SetExternalVelocityControlEnabled(true);
}

void UCaddyVehicleBrakeDashAbility::EnterChargingPhase()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    if (!SkillComponent)
    {
        return;
    }

    SkillComponent->SkillState = ECaddyVehicleSkillState::Charging;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    SkillComponent->CurrentChargeSeconds = 0.0f;
    SkillComponent->CurrentChargeAlpha = 0.0f;
}

void UCaddyVehicleBrakeDashAbility::EnterDashPhase()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        AbortToReady();
        return;
    }

    ResolveAndApplyAimDirection();
    SkillComponent->DashDirection = SkillComponent->CurrentAimDirection.IsNearlyZero()
        ? SkillComponent->ResolveFallbackAimDirection()
        : SkillComponent->CurrentAimDirection.GetSafeNormal();
    if (SkillComponent->DashDirection.IsNearlyZero())
    {
        SkillComponent->DashDirection = FVector2D(1.0f, 0.0f);
    }

    SkillComponent->CurrentChargeSeconds = FMath::Clamp(
        SkillComponent->CurrentChargeSeconds,
        0.0f,
        FMath::Max(0.01f, SkillComponent->BrakeDashConfig.MaxChargeSeconds));
    SkillComponent->CurrentChargeAlpha = SkillComponent->EvaluateChargeAlpha(SkillComponent->CurrentChargeSeconds);

    SkillComponent->ActiveDashDuration = FMath::Lerp(
        SkillComponent->BrakeDashConfig.DashDurationAtMinCharge,
        SkillComponent->BrakeDashConfig.DashDurationAtMaxCharge,
        SkillComponent->CurrentChargeAlpha);
    SkillComponent->ActiveDashPeakSpeed = FMath::Lerp(
        SkillComponent->BrakeDashConfig.DashPeakSpeedAtMinCharge,
        SkillComponent->BrakeDashConfig.DashPeakSpeedAtMaxCharge,
        SkillComponent->CurrentChargeAlpha);
    SkillComponent->ActiveDashDuration = FMath::Max(0.01f, SkillComponent->ActiveDashDuration);
    SkillComponent->ActiveDashPeakSpeed = FMath::Max(0.0f, SkillComponent->ActiveDashPeakSpeed);

    SkillComponent->SkillState = ECaddyVehicleSkillState::Dashing;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    MovementComponent->SetExternalVelocityControlEnabled(true);
}

void UCaddyVehicleBrakeDashAbility::ExitDashPhase()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent || !MovementComponent)
    {
        AbortToReady();
        return;
    }

    MovementComponent->SetExternalVelocityControlEnabled(false);
    const float CarrySpeed = SkillComponent->ActiveDashPeakSpeed
        * FMath::Clamp(SkillComponent->BrakeDashConfig.PostDashCarryRatio, 0.0f, 1.0f);
    const FVector CarryVelocity = FVector(SkillComponent->DashDirection.X, SkillComponent->DashDirection.Y, 0.0f)
        .GetSafeNormal2D() * CarrySpeed;
    MovementComponent->SetExternalPlanarVelocityWorld(CarryVelocity);

    SkillComponent->SkillState = ECaddyVehicleSkillState::Ready;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    SkillComponent->BrakingStartSpeed = 0.0f;
    SkillComponent->CooldownRemainingSeconds = FMath::Max(0.0f, SkillComponent->BrakeDashConfig.CooldownSeconds);
    SkillComponent->bUsingAbilityTargetAim = false;
    SkillComponent->CurrentAbilityTargetActor = nullptr;
    SkillComponent->CurrentAbilityTargetLocation = FVector::ZeroVector;
}

void UCaddyVehicleBrakeDashAbility::AbortToReady()
{
    UCaddyVehicleSkillComponent* SkillComponent = CachedSkillComponent.Get();
    UArcadeVehicleMovementComponent* MovementComponent = CachedMovement.Get();
    if (!SkillComponent)
    {
        return;
    }

    if (MovementComponent)
    {
        MovementComponent->SetExternalVelocityControlEnabled(false);
    }

    SkillComponent->SkillState = ECaddyVehicleSkillState::Ready;
    SkillComponent->StateElapsedSeconds = 0.0f;
    SkillComponent->CurrentOverrideSpeed = 0.0f;
    SkillComponent->BrakingStartSpeed = 0.0f;
    SkillComponent->CurrentChargeSeconds = 0.0f;
    SkillComponent->CurrentChargeAlpha = 0.0f;
    SkillComponent->ActiveDashDuration = 0.0f;
    SkillComponent->ActiveDashPeakSpeed = 0.0f;
    SkillComponent->bUsingAbilityTargetAim = false;
    SkillComponent->CurrentAbilityTargetActor = nullptr;
    SkillComponent->CurrentAbilityTargetLocation = FVector::ZeroVector;
}
