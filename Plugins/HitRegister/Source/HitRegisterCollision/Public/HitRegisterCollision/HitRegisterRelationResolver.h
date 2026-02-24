#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "HitRegisterRelationResolver.generated.h"

UENUM(BlueprintType)
enum class EHitRegisterRelation : uint8
{
    Ally,
    Enemy,
    Neutral,
    Unknown
};

UINTERFACE(BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterRelationResolver : public UInterface
{
    GENERATED_BODY()
};

class HITREGISTERCOLLISION_API IHitRegisterRelationResolver
{
    GENERATED_BODY()

public:
    /** Return relation between source and target. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="HitRegister")
    EHitRegisterRelation GetRelation(AActor* Source, AActor* Target) const;
};

/**
 * Strongly-typed resolver asset base class for collision settings binding.
 */
UCLASS(Abstract, BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterRelationResolverAsset : public UDataAsset, public IHitRegisterRelationResolver
{
    GENERATED_BODY()
};
