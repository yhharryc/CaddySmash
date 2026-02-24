#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HitRegisterCollisionSettings.generated.h"

class UHitRegisterRelationResolverAsset;

UCLASS(Config=Game, DefaultConfig, BlueprintType)
class HITREGISTERCOLLISION_API UHitRegisterCollisionSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    /** Optional relation resolver asset with strong type constraints. */
    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="HitRegister|Team")
    TSoftObjectPtr<UHitRegisterRelationResolverAsset> RelationResolver;

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    static const UHitRegisterCollisionSettings* Get() { return GetDefault<UHitRegisterCollisionSettings>(); }

    bool ValidateSettings(FString* OutError = nullptr) const;
};
