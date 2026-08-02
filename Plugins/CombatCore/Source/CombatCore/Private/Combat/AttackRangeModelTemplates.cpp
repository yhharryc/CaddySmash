#include "Combat/AttackRangeModelTemplates.h"

UAttackRangeModel_MeleeThrust::UAttackRangeModel_MeleeThrust(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bAffectThrustDistance = true;
    bAffectHitscanRange = false;

    RangeInputMin = 120.f;
    RangeInputMax = 450.f;

    MinThrustDistance = 35.f;
    MaxThrustDistance = 145.f;

    DistanceCompensationBias = 0.75f;
    StaticReach = 15.f;
    HitSlack = 8.f;
    bUseDistanceCompensation = true;
}

UAttackRangeModel_RangedHitscan::UAttackRangeModel_RangedHitscan(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bAffectThrustDistance = false;
    bAffectHitscanRange = true;

    HitscanRangeScale = 1.f;

    // Kept for completeness; not used when thrust mapping is disabled.
    RangeInputMin = 100.f;
    RangeInputMax = 2500.f;
    MinThrustDistance = 0.f;
    MaxThrustDistance = 0.f;
    DistanceCompensationBias = 0.f;
    StaticReach = 0.f;
    HitSlack = 0.f;
    bUseDistanceCompensation = false;
}

