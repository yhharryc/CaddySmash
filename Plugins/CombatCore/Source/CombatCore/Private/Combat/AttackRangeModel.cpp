#include "Combat/AttackRangeModel.h"

#include "Combat/AttackProfile.h"
#include "Curves/CurveFloat.h"

void UAttackRangeModel::BuildExecutionParams_Implementation(
    const FCombatAttackContext& Context,
    const float DistanceToTarget,
    FCombatAttackExecutionParams& InOutParams) const
{
    const UAttackProfile* Profile = Context.Request.Profile;
    const float InputRange = FMath::Max(0.f, InOutParams.EffectiveAttackRange > 0.f ? InOutParams.EffectiveAttackRange : (Profile ? Profile->Range : 0.f));
    if (InputRange <= 0.f)
    {
        return;
    }

    if (bAffectHitscanRange)
    {
        InOutParams.bOverrideHitscanRange = true;
        InOutParams.HitscanRange = FMath::Max(0.f, InputRange * FMath::Max(0.f, HitscanRangeScale));
    }

    if (!bAffectThrustDistance)
    {
        return;
    }

    const float InMin = FMath::Min(RangeInputMin, RangeInputMax);
    const float InMax = FMath::Max(RangeInputMin, RangeInputMax);
    const float AlphaRaw = (InMax > InMin) ? ((InputRange - InMin) / (InMax - InMin)) : 1.f;
    float Alpha = FMath::Clamp(AlphaRaw, 0.f, 1.f);
    if (RangeToDistanceCurve)
    {
        Alpha = FMath::Clamp(RangeToDistanceCurve->GetFloatValue(Alpha), 0.f, 1.f);
    }

    const float NominalThrust = FMath::Lerp(MinThrustDistance, MaxThrustDistance, Alpha);
    float FinalThrust = NominalThrust;
    if (bUseDistanceCompensation && DistanceToTarget > 0.f)
    {
        const float NeededThrust = FMath::Max(0.f, DistanceToTarget - FMath::Max(0.f, StaticReach) - FMath::Max(0.f, HitSlack));
        FinalThrust = FMath::Lerp(NominalThrust, NeededThrust, FMath::Clamp(DistanceCompensationBias, 0.f, 1.f));
    }

    InOutParams.bOverrideThrustDistance = true;
    InOutParams.ThrustDistance = FMath::Clamp(FinalThrust, FMath::Min(MinThrustDistance, MaxThrustDistance), FMath::Max(MinThrustDistance, MaxThrustDistance));
}

