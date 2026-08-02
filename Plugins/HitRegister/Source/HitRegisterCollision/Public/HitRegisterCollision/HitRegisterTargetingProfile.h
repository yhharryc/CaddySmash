#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HitRegisterTargetingProfile.generated.h"

UENUM(BlueprintType)
enum class EHitTargetMode : uint8
{
    All,
    AllExceptSelf,
    AlliesOnly,
    EnemiesOnly,
    AlliesExceptSelf,
    SelfOnly
};

UENUM(BlueprintType)
enum class EHitTargetUnknownPolicy : uint8
{
    Allow,
    Reject
};

UCLASS(BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterTargetingProfile : public UDataAsset
{
    GENERATED_BODY()

public:
    /** Target selection mode. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister")
    EHitTargetMode Mode = EHitTargetMode::AllExceptSelf;

    /** Behavior when team info is missing on either source or target. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HitRegister")
    EHitTargetUnknownPolicy UnknownTeamPolicy = EHitTargetUnknownPolicy::Allow;
};
