#include "HitRegisterCollisionModule.h"

#include "HitRegisterCollision/HitRegisterCollisionLog.h"
#include "HitRegisterCollision/HitRegisterCollisionSettings.h"
#include "Modules/ModuleManager.h"

void FHitRegisterCollisionModule::StartupModule()
{
    FString ValidationError;
    if (const UHitRegisterCollisionSettings* Settings = UHitRegisterCollisionSettings::Get())
    {
        if (!Settings->ValidateSettings(&ValidationError))
        {
            UE_LOG(LogHitRegisterCollision, Error, TEXT("%s"), *ValidationError);
        }
    }
}

void FHitRegisterCollisionModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FHitRegisterCollisionModule, HitRegisterCollision)
