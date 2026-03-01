#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterNode.h"
#include "HRN_AdjudicateVehicleCollision.generated.h"

UENUM(BlueprintType)
enum class EHRVehicleCollisionImpactTier : uint8
{
    None = 0,
    Light = 1,
    Medium = 2,
    Heavy = 3
};

/**
 * Collision combat adjudication node.
 * Reads raw collision attributes from Attack.Attributes, computes tier/damage, and writes final values back into context.
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class HITREGISTERCORE_API UHRN_AdjudicateVehicleCollision : public UHitRegisterNode
{
    GENERATED_BODY()

public:
    UHRN_AdjudicateVehicleCollision();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision")
    bool bRequireVehicleTarget = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision")
    bool bUseRelativeNormalImpactSpeed = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision")
    bool bStopIfBelowLightThreshold = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float ImpactScoreScale = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float LightImpactScoreThreshold = 280.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float MediumImpactScoreThreshold = 620.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float HeavyImpactScoreThreshold = 980.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float LightDamageMultiplier = 0.65f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float MediumDamageMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float HeavyDamageMultiplier = 1.55f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float DamageByNormalImpactSpeed = 0.012f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float DamageBias = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float DriftingImpactMultiplier = 1.10f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision", meta=(ClampMin="0.0"))
    float SkillDashImpactMultiplier = 1.60f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|Clash")
    bool bEnableHeadOnClashTag = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|Clash", meta=(ClampMin="-1.0", ClampMax="1.0"))
    float ClashFacingDotThreshold = 0.60f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|Clash", meta=(ClampMin="0.0", ClampMax="1.0"))
    float ClashSpeedRatioThreshold = 0.70f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|Clash", meta=(ClampMin="0.0"))
    float ClashMinRelativeNormalSpeed = 600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag TotalSpeedTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag TargetSpeedTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag NormalImpactSpeedTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag RelativeNormalImpactSpeedTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag DriftingStateTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag SkillDashingStateTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|InputTags")
    FGameplayTag TargetVehicleStateTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputTags")
    FGameplayTag LightImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputTags")
    FGameplayTag MediumImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputTags")
    FGameplayTag HeavyImpactTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputTags")
    FGameplayTag ClashTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputAttrs")
    FGameplayTag EffectiveNormalImpactSpeedOutputTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputAttrs")
    FGameplayTag ImpactScoreOutputTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister|Collision|OutputAttrs")
    FGameplayTag ImpactTierOutputTag;

    virtual EHitNodeResult Execute_Implementation(FHitRegisterContext& Context) override;
};

