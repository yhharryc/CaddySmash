#include "HitRegisterCollision/HitRegisterSimpleRelationResolver.h"

#include "HitRegisterTeamUtils.h"

EHitRegisterRelation UHitRegisterSimpleRelationResolver::GetRelation_Implementation(AActor* Source, AActor* Target) const
{
    int32 TeamA = INDEX_NONE;
    int32 TeamB = INDEX_NONE;
    const bool bHasA = HitRegisterTeamUtils::TryGetTeamId(Source, TeamA);
    const bool bHasB = HitRegisterTeamUtils::TryGetTeamId(Target, TeamB);
    if (!bHasA || !bHasB)
    {
        return EHitRegisterRelation::Unknown;
    }
    return (TeamA == TeamB) ? EHitRegisterRelation::Ally : EHitRegisterRelation::Enemy;
}
