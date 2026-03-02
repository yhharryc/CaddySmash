#pragma once

#include "CoreMinimal.h"
#include "Shakes/LegacyCameraShake.h"
#include "CaddyVehicleCollisionCameraShake.generated.h"

UCLASS()
class CADDYSMASH_API UCaddyVehicleCollisionCameraShake : public ULegacyCameraShake
{
    GENERATED_BODY()

public:
    UCaddyVehicleCollisionCameraShake();
};
