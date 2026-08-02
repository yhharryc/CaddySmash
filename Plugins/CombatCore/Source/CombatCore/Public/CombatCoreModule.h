#pragma once

#include "Modules/ModuleManager.h"

class FCombatCoreModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};
