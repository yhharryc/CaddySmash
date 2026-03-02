#include "Vehicle/Combat/CaddyVehicleHitRegisterDamageableComponent.h"

#include "Vehicle/Combat/CaddyVehicleDamageGameplayEffect.h"

UCaddyVehicleHitRegisterDamageableComponent::UCaddyVehicleHitRegisterDamageableComponent()
{
    DamageEffectClass = UCaddyVehicleDamageGameplayEffect::StaticClass();
}
