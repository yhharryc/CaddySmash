#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "CaddyVehicleBrakeDashAbility.generated.h"

class APawn;
class UArcadeVehicleMovementComponent;
class UCaddyVehicleSkillComponent;
class ACaddyVehicleSkillTargetActor_Trace;

UCLASS()
class CADDYSMASH_API UCaddyVehicleBrakeDashAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UCaddyVehicleBrakeDashAbility();

protected:
    virtual bool CanActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayTagContainer* SourceTags = nullptr,
        const FGameplayTagContainer* TargetTags = nullptr,
        FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;

    virtual void EndAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        bool bReplicateEndAbility,
        bool bWasCancelled) override;

private:
    bool ResolveSkillRig(bool bLogFailures) const;
    bool IsTriggerSourceHeld() const;
    float ComputeDeltaTime();
    void ResolveAndApplyAimDirection();
    void RefreshTargetDataFromGAS();
    void HandleSkillTargetDataReady(const FGameplayAbilityTargetDataHandle& DataHandle);
    ACaddyVehicleSkillTargetActor_Trace* GetOrCreateSkillTargetActor();
    void DestroySkillTargetActor();
    void TickSkillStateMachine();
    void EnterBrakePhase();
    void EnterChargingPhase();
    void EnterDashPhase();
    void ExitDashPhase();
    void AbortToReady();

    mutable TWeakObjectPtr<APawn> CachedPawn;
    mutable TWeakObjectPtr<UArcadeVehicleMovementComponent> CachedMovement;
    mutable TWeakObjectPtr<UCaddyVehicleSkillComponent> CachedSkillComponent;
    TWeakObjectPtr<ACaddyVehicleSkillTargetActor_Trace> SkillTargetActor;
    FGameplayAbilityTargetDataHandle CachedTargetDataHandle;

    FTimerHandle SkillTickTimerHandle;
    double LastTickTimeSeconds = 0.0;
};
