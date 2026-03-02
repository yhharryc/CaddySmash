#include "Vehicle/Abilities/CaddyVehicleStaggerAbility.h"

#include "GameFramework/Actor.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "TimerManager.h"
#include "Vehicle/CaddyVehiclePawn.h"

UCaddyVehicleStaggerAbility::UCaddyVehicleStaggerAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    StaggerEventTag = FGameplayTag::RequestGameplayTag(FName("Event.Collision.Stagger"), false);
    LightImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Light"), false);
    MediumImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Medium"), false);
    HeavyImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Heavy"), false);

    DefaultTier.DurationSeconds = 0.35f;
    DefaultTier.Spins = 1;
    DefaultTier.InputLockSeconds = 0.35f;

    LightTier.DurationSeconds = 0.35f;
    LightTier.Spins = 1;
    LightTier.InputLockSeconds = 0.35f;

    MediumTier.DurationSeconds = 0.55f;
    MediumTier.Spins = 2;
    MediumTier.InputLockSeconds = 0.55f;

    HeavyTier.DurationSeconds = 0.8f;
    HeavyTier.Spins = 3;
    HeavyTier.InputLockSeconds = 0.8f;
}

void UCaddyVehicleStaggerAbility::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    ACaddyVehiclePawn* Pawn = Cast<ACaddyVehiclePawn>(ActorInfo->AvatarActor.Get());
    if (!Pawn)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    const FCaddyVehicleStaggerTierConfig& Config = ResolveTierConfig(TriggerEventData);
    if (Config.DurationSeconds <= KINDA_SMALL_NUMBER || Config.Spins <= 0)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    FVector ImpactNormal = Pawn->GetActorForwardVector();
    if (TriggerEventData)
    {
        for (const TSharedPtr<FGameplayAbilityTargetData>& Data : TriggerEventData->TargetData.Data)
        {
            if (!Data.IsValid())
            {
                continue;
            }
            if (const FHitResult* HitResult = Data->GetHitResult())
            {
                ImpactNormal = HitResult->Normal;
                break;
            }
        }
    }

    const FVector Forward = Pawn->GetActorForwardVector().GetSafeNormal2D();
    const FVector PlanarNormal = FVector(ImpactNormal.X, ImpactNormal.Y, 0.0f).GetSafeNormal();
    const float CrossZ = FVector::CrossProduct(Forward, -PlanarNormal).Z;
    const float DirectionSign = (FMath::Abs(CrossZ) > KINDA_SMALL_NUMBER) ? FMath::Sign(CrossZ) : 1.0f;

    CachedPawn = Pawn;
    Pawn->Multicast_BeginStagger(Config.DurationSeconds, Config.Spins, DirectionSign);

    if (UWorld* World = Pawn->GetWorld())
    {
        World->GetTimerManager().ClearTimer(FinishTimerHandle);
        World->GetTimerManager().SetTimer(
            FinishTimerHandle,
            this,
            &UCaddyVehicleStaggerAbility::FinishStagger,
            FMath::Max(0.01f, Config.InputLockSeconds),
            false);
    }

    EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

const FCaddyVehicleStaggerTierConfig& UCaddyVehicleStaggerAbility::ResolveTierConfig(const FGameplayEventData* TriggerEventData) const
{
    if (TriggerEventData)
    {
        if (TriggerEventData->TargetTags.HasTagExact(HeavyImpactTag))
        {
            return HeavyTier;
        }
        if (TriggerEventData->TargetTags.HasTagExact(MediumImpactTag))
        {
            return MediumTier;
        }
        if (TriggerEventData->TargetTags.HasTagExact(LightImpactTag))
        {
            return LightTier;
        }
    }

    return DefaultTier;
}

void UCaddyVehicleStaggerAbility::FinishStagger()
{
    if (ACaddyVehiclePawn* Pawn = CachedPawn.Get())
    {
        Pawn->Multicast_EndStagger();
    }
}
