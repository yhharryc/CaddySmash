#include "HitRegister/Nodes/HRN_AdjudicateVehicleCollision.h"
#include "GameFramework/Actor.h"

namespace
{
    static float GetAttrOrDefault(const TMap<FGameplayTag, float>& Attributes, const FGameplayTag& Tag, const float DefaultValue = 0.0f)
    {
        if (!Tag.IsValid())
        {
            return DefaultValue;
        }

        if (const float* Value = Attributes.Find(Tag))
        {
            return *Value;
        }
        return DefaultValue;
    }

    static void SetAttr(TMap<FGameplayTag, float>& Attributes, const FGameplayTag& Tag, const float Value)
    {
        if (Tag.IsValid())
        {
            Attributes.Add(Tag, Value);
        }
    }
}

UHRN_AdjudicateVehicleCollision::UHRN_AdjudicateVehicleCollision()
{
    TotalSpeedTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.TotalSpeed"), false);
    TargetSpeedTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.TargetSpeed"), false);
    NormalImpactSpeedTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.NormalImpactSpeed"), false);
    RelativeNormalImpactSpeedTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.RelativeNormalImpactSpeed"), false);
    DriftingStateTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.IsDrifting"), false);
    SkillDashingStateTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.IsSkillDashing"), false);
    TargetVehicleStateTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.TargetIsVehicle"), false);

    ImpactScoreOutputTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.ImpactScore"), false);
    ImpactTierOutputTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.ImpactTier"), false);
    EffectiveNormalImpactSpeedOutputTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.EffectiveNormalImpactSpeed"), false);

    LightImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Light"), false);
    MediumImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Medium"), false);
    HeavyImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Heavy"), false);
    ClashTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Clash"), false);
}

EHitNodeResult UHRN_AdjudicateVehicleCollision::Execute_Implementation(FHitRegisterContext& Context)
{
    const TMap<FGameplayTag, float>& Attributes = Context.Attack.Attributes;
    const float TotalSpeed = GetAttrOrDefault(Attributes, TotalSpeedTag, 0.0f);
    const float TargetSpeed = GetAttrOrDefault(Attributes, TargetSpeedTag, 0.0f);
    const float NormalImpactSpeed = GetAttrOrDefault(Attributes, NormalImpactSpeedTag, 0.0f);
    const float RelativeNormalImpactSpeed = GetAttrOrDefault(Attributes, RelativeNormalImpactSpeedTag, 0.0f);
    const bool bIsDrifting = GetAttrOrDefault(Attributes, DriftingStateTag, 0.0f) > 0.5f;
    const bool bIsSkillDashing = GetAttrOrDefault(Attributes, SkillDashingStateTag, 0.0f) > 0.5f;
    const bool bTargetIsVehicle = GetAttrOrDefault(Attributes, TargetVehicleStateTag, 0.0f) > 0.5f;

    if (bRequireVehicleTarget && !bTargetIsVehicle)
    {
        Context.Result.StopReason = EHitRegisterStopReason::StoppedByNode;
        return EHitNodeResult::Stop;
    }

    const float EffectiveNormalImpactSpeed = bUseRelativeNormalImpactSpeed
        ? FMath::Max(NormalImpactSpeed, RelativeNormalImpactSpeed)
        : NormalImpactSpeed;

    float ImpactScore = FMath::Max(0.0f, ImpactScoreScale) * EffectiveNormalImpactSpeed;
    if (bIsDrifting)
    {
        ImpactScore *= FMath::Max(0.0f, DriftingImpactMultiplier);
    }
    if (bIsSkillDashing)
    {
        ImpactScore *= FMath::Max(0.0f, SkillDashImpactMultiplier);
    }

    EHRVehicleCollisionImpactTier ImpactTier = EHRVehicleCollisionImpactTier::None;
    if (ImpactScore >= HeavyImpactScoreThreshold)
    {
        ImpactTier = EHRVehicleCollisionImpactTier::Heavy;
    }
    else if (ImpactScore >= MediumImpactScoreThreshold)
    {
        ImpactTier = EHRVehicleCollisionImpactTier::Medium;
    }
    else if (ImpactScore >= LightImpactScoreThreshold)
    {
        ImpactTier = EHRVehicleCollisionImpactTier::Light;
    }

    if (ImpactTier == EHRVehicleCollisionImpactTier::None && bStopIfBelowLightThreshold)
    {
        Context.Result.StopReason = EHitRegisterStopReason::StoppedByNode;
        return EHitNodeResult::Stop;
    }

    float TierDamageMultiplier = 1.0f;
    if (ImpactTier == EHRVehicleCollisionImpactTier::Light)
    {
        TierDamageMultiplier = FMath::Max(0.0f, LightDamageMultiplier);
    }
    else if (ImpactTier == EHRVehicleCollisionImpactTier::Medium)
    {
        TierDamageMultiplier = FMath::Max(0.0f, MediumDamageMultiplier);
    }
    else if (ImpactTier == EHRVehicleCollisionImpactTier::Heavy)
    {
        TierDamageMultiplier = FMath::Max(0.0f, HeavyDamageMultiplier);
    }

    const float BaseDamage = FMath::Max(0.0f, DamageBias + (EffectiveNormalImpactSpeed * DamageByNormalImpactSpeed));
    const float FinalDamage = BaseDamage * TierDamageMultiplier;

    Context.Attack.BaseDamage = FinalDamage;
    Context.Damage.RawDamage = FinalDamage;
    Context.Damage.MitigatedDamage = FinalDamage;
    Context.Damage.FinalDamage = FinalDamage;

    SetAttr(Context.Attack.Attributes, EffectiveNormalImpactSpeedOutputTag, EffectiveNormalImpactSpeed);
    SetAttr(Context.Attack.Attributes, ImpactScoreOutputTag, ImpactScore);
    SetAttr(Context.Attack.Attributes, ImpactTierOutputTag, static_cast<float>(ImpactTier));

    if (ImpactTier == EHRVehicleCollisionImpactTier::Light && LightImpactTag.IsValid())
    {
        Context.Attack.Tags.AddTag(LightImpactTag);
    }
    else if (ImpactTier == EHRVehicleCollisionImpactTier::Medium && MediumImpactTag.IsValid())
    {
        Context.Attack.Tags.AddTag(MediumImpactTag);
    }
    else if (ImpactTier == EHRVehicleCollisionImpactTier::Heavy && HeavyImpactTag.IsValid())
    {
        Context.Attack.Tags.AddTag(HeavyImpactTag);
    }

    if (bEnableHeadOnClashTag && bTargetIsVehicle && ClashTag.IsValid())
    {
        const AActor* SourceActor = Context.Attack.Instigator.Get();
        const AActor* TargetActor = Context.Hit.GetActor();
        if (SourceActor && TargetActor)
        {
            const FVector SourceForward = SourceActor->GetActorForwardVector().GetSafeNormal2D();
            const FVector TargetForward = TargetActor->GetActorForwardVector().GetSafeNormal2D();
            const float FacingDot = FVector::DotProduct(SourceForward, -TargetForward);
            const float MaxSpeed = FMath::Max(TotalSpeed, TargetSpeed);
            const float SpeedRatio = (MaxSpeed > KINDA_SMALL_NUMBER)
                ? (FMath::Min(TotalSpeed, TargetSpeed) / MaxSpeed)
                : 0.0f;

            if (FacingDot >= ClashFacingDotThreshold
                && SpeedRatio >= ClashSpeedRatioThreshold
                && RelativeNormalImpactSpeed >= ClashMinRelativeNormalSpeed)
            {
                Context.Attack.Tags.AddTag(ClashTag);
            }
        }
    }

    return EHitNodeResult::Continue;
}
