#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_EmitVehicleCollisionFeel.generated.h"

/**
 * Emits collision feel to vehicle pawn via multicast, using the current HitRegister context.
 * Recommended position in pipeline: after collision adjudication, before/after damage both acceptable.
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class CADDYSMASH_API UHRN_EmitVehicleCollisionFeel : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    UHRN_EmitVehicleCollisionFeel();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bEmitOnAuthorityOnly = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bEmitToTargetVehicle = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bEmitToInstigatorVehicle = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bInvertImpactNormalForInstigator = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bRequireVehiclePawnTarget = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel")
    bool bRequireBlockingHit = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel", meta=(ClampMin="0.0"))
    float MinNormalImpactSpeed = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|InputAttrs")
    FGameplayTag NormalImpactSpeedTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|InputAttrs")
    FGameplayTag ImpactTierTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|InputTags")
    FGameplayTag LightImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|InputTags")
    FGameplayTag MediumImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|InputTags")
    FGameplayTag HeavyImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|OutputAttrs")
    FGameplayTag FeelRecipientCountOutputTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|CollisionFeel|OutputAttrs")
    FGameplayTag FeelExecutedOutputTag;

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};
