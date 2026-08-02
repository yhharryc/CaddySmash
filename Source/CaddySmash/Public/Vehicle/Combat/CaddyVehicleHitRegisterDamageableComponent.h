#pragma once

#include "CoreMinimal.h"
#include "HitRegisterGAS/HitRegisterGASDamageableComponent.h"
#include "CaddyVehicleHitRegisterDamageableComponent.generated.h"

/**
 * Vehicle-specific HitRegister GAS adapter.
 * Keeps damage application setup in one place (DamageEffectClass).
 * Event/feel dispatch is handled by explicit HitRegister nodes.
 */
UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class CADDYSMASH_API UCaddyVehicleHitRegisterDamageableComponent
    : public UHitRegisterGASDamageableComponent
{
    GENERATED_BODY()

public:
    UCaddyVehicleHitRegisterDamageableComponent();
};
