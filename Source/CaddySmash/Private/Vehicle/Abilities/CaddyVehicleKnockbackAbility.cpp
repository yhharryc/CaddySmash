#include "Vehicle/Abilities/CaddyVehicleKnockbackAbility.h"

#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/CaddyVehiclePawn.h"

UCaddyVehicleKnockbackAbility::UCaddyVehicleKnockbackAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
    ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
    bRetriggerInstancedAbility = true;

    KnockbackEventTag = FGameplayTag::RequestGameplayTag(FName("Event.Collision.Knockback"), false);
    LightImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Light"), false);
    MediumImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Medium"), false);
    HeavyImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Heavy"), false);

    FAbilityTriggerData TriggerData;
    TriggerData.TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;
    TriggerData.TriggerTag = KnockbackEventTag;
    AbilityTriggers.Add(TriggerData);

    LightKnockback.OverrideSpeed = 620.0f;
    LightKnockback.OverrideDuration = 0.12f;
    LightKnockback.CarryVelocityRatio = 0.12f;

    MediumKnockback.OverrideSpeed = 950.0f;
    MediumKnockback.OverrideDuration = 0.16f;
    MediumKnockback.CarryVelocityRatio = 0.16f;

    HeavyKnockback.OverrideSpeed = 1320.0f;
    HeavyKnockback.OverrideDuration = 0.22f;
    HeavyKnockback.CarryVelocityRatio = 0.20f;
}

void UCaddyVehicleKnockbackAbility::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    APawn* Pawn = Cast<APawn>(GetAvatarActorFromActorInfo());
    UWorld* World = GetWorld();
    if (!Pawn || !World)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    UArcadeVehicleMovementComponent* MovementComponent = Pawn->FindComponentByClass<UArcadeVehicleMovementComponent>();
    if (!MovementComponent)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    const FVector2D KnockbackDirection2D = ResolveKnockbackDirection(*Pawn, TriggerEventData);
    if (KnockbackDirection2D.IsNearlyZero())
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    const FCaddyVehicleKnockbackTierConfig& TierConfig = ResolveTierConfig(TriggerEventData);
    const FVector Direction = FVector(KnockbackDirection2D.X, KnockbackDirection2D.Y, 0.0f).GetSafeNormal2D();
    float KnockbackSpeed = FMath::Max(0.0f, TierConfig.OverrideSpeed);
    if (const ACaddyVehiclePawn* VehiclePawn = Cast<ACaddyVehiclePawn>(Pawn))
    {
        KnockbackSpeed *= (1.0f - FMath::Clamp(VehiclePawn->GetVehicleKnockbackResistance(), 0.0f, 0.95f));
    }
    const float KnockbackDuration = FMath::Max(0.01f, TierConfig.OverrideDuration);

    MovementComponent->SetExternalVelocityControlEnabled(true);
    MovementComponent->SetExternalPlanarVelocityWorld(Direction * KnockbackSpeed);

    ActiveMovementComponent = MovementComponent;
    ActiveDirection = Direction;
    ActiveCarrySpeed = KnockbackSpeed * FMath::Clamp(TierConfig.CarryVelocityRatio, 0.0f, 1.0f);

    World->GetTimerManager().ClearTimer(KnockbackTimerHandle);
    World->GetTimerManager().SetTimer(
        KnockbackTimerHandle,
        this,
        &UCaddyVehicleKnockbackAbility::FinishKnockback,
        KnockbackDuration,
        false);
}

void UCaddyVehicleKnockbackAbility::EndAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const bool bReplicateEndAbility,
    const bool bWasCancelled)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(KnockbackTimerHandle);
    }

    if (bWasCancelled)
    {
        if (UArcadeVehicleMovementComponent* MovementComponent = ActiveMovementComponent.Get())
        {
            MovementComponent->SetExternalVelocityControlEnabled(false);
        }
    }

    ActiveMovementComponent = nullptr;
    ActiveDirection = FVector::ZeroVector;
    ActiveCarrySpeed = 0.0f;

    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UCaddyVehicleKnockbackAbility::FinishKnockback()
{
    if (UArcadeVehicleMovementComponent* MovementComponent = ActiveMovementComponent.Get())
    {
        MovementComponent->SetExternalVelocityControlEnabled(false);
        if (!ActiveDirection.IsNearlyZero() && ActiveCarrySpeed > KINDA_SMALL_NUMBER)
        {
            MovementComponent->SetExternalPlanarVelocityWorld(ActiveDirection * ActiveCarrySpeed);
        }
    }

    EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

FVector2D UCaddyVehicleKnockbackAbility::ResolveKnockbackDirection(
    const APawn& Pawn,
    const FGameplayEventData* TriggerEventData) const
{
    if (TriggerEventData && TriggerEventData->Instigator)
    {
        const FVector ToTarget = Pawn.GetActorLocation() - TriggerEventData->Instigator->GetActorLocation();
        const FVector2D ToTarget2D(ToTarget.X, ToTarget.Y);
        if (!ToTarget2D.IsNearlyZero())
        {
            return ToTarget2D.GetSafeNormal();
        }
    }

    const FVector Fallback = -Pawn.GetActorForwardVector().GetSafeNormal2D();
    return FVector2D(Fallback.X, Fallback.Y).GetSafeNormal();
}

const FCaddyVehicleKnockbackTierConfig& UCaddyVehicleKnockbackAbility::ResolveTierConfig(const FGameplayEventData* TriggerEventData) const
{
    if (TriggerEventData)
    {
        if (HeavyImpactTag.IsValid() && TriggerEventData->TargetTags.HasTag(HeavyImpactTag))
        {
            return HeavyKnockback;
        }
        if (MediumImpactTag.IsValid() && TriggerEventData->TargetTags.HasTag(MediumImpactTag))
        {
            return MediumKnockback;
        }
        if (LightImpactTag.IsValid() && TriggerEventData->TargetTags.HasTag(LightImpactTag))
        {
            return LightKnockback;
        }

        if (TriggerEventData->EventMagnitude >= HeavyDamageThreshold)
        {
            return HeavyKnockback;
        }
        if (TriggerEventData->EventMagnitude >= MediumDamageThreshold)
        {
            return MediumKnockback;
        }
    }

    return LightKnockback;
}
