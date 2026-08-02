#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_EmitVehicleCollisionGameplayEvents.generated.h"

/**
 * Emits collision gameplay events from HitRegister context (knockback / stagger).
 * Recommended position in pipeline: after damage application.
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class CADDYSMASH_API UHRN_EmitVehicleCollisionGameplayEvents : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    UHRN_EmitVehicleCollisionGameplayEvents();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents")
    bool bEmitOnAuthorityOnly = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents")
    bool bRequireVehiclePawnTarget = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents")
    bool bRequirePositiveFinalDamage = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents", meta=(ClampMin="0.0"))
    float MinFinalDamage = KINDA_SMALL_NUMBER;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Knockback")
    bool bEmitKnockbackGameplayEvent = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Knockback", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag KnockbackGameplayEventTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Stagger")
    bool bEmitStaggerGameplayEvent = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Stagger", meta=(Categories="GameplayEventTagsCategory"))
    FGameplayTag StaggerGameplayEventTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Stagger")
    bool bStaggerOnLightImpact = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Stagger")
    bool bStaggerOnMediumImpact = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Stagger")
    bool bStaggerOnHeavyImpact = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Impact")
    FGameplayTag ImpactTierTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Impact")
    FGameplayTag LightImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Impact")
    FGameplayTag MediumImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionEvents|Impact")
    FGameplayTag HeavyImpactTag;

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};
