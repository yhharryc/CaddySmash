#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "CaddyVehicleDamageGameplayEffect.generated.h"

/**
 * Default instant damage GE for vehicle collision damage.
 * Expects SetByCaller magnitude tag Data.Damage and writes into IncomingDamage attribute.
 */
UCLASS()
class CADDYSMASH_API UCaddyVehicleDamageGameplayEffect : public UGameplayEffect
{
    GENERATED_BODY()

public:
    UCaddyVehicleDamageGameplayEffect();
};

