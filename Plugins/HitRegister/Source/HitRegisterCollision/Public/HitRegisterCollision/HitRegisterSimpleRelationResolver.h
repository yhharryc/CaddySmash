#pragma once

#include "CoreMinimal.h"
#include "HitRegisterRelationResolver.h"
#include "HitRegisterSimpleRelationResolver.generated.h"

/** Default resolver: same TeamId => Ally, different => Enemy, missing => Unknown. */
UCLASS(BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterSimpleRelationResolver : public UHitRegisterRelationResolverAsset
{
    GENERATED_BODY()

public:
    virtual EHitRegisterRelation GetRelation_Implementation(AActor* Source, AActor* Target) const override;
};
