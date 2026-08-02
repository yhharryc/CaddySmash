#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "HitRegisterSettings.generated.h"

class UHitRegisterPipeline;

UCLASS(Config=Game, DefaultConfig, BlueprintType)
class HITREGISTERCORE_API UHitRegisterSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    /** Default pipeline used by helper functions if none is provided. */
    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="HitRegister")
    TSoftObjectPtr<UHitRegisterPipeline> DefaultPipeline;

    /** Default set-by-caller tag used by GAS adapter (can be overridden per component). */
    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="HitRegister|GAS")
    FGameplayTag DamageSetByCallerTag;

    /** Convenience: returns settings singleton. */
    UFUNCTION(BlueprintCallable, Category="HitRegister")
    static const UHitRegisterSettings* Get() { return GetDefault<UHitRegisterSettings>(); }

    UHitRegisterSettings();
};
