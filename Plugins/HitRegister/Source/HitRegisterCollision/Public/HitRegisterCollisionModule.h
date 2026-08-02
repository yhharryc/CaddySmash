#pragma once

#include "Modules/ModuleManager.h"

class FHitRegisterCollisionModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
