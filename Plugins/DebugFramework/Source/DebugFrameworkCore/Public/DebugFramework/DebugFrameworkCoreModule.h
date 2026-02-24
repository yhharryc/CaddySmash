#pragma once

#include "Modules/ModuleManager.h"

class FDebugFrameworkCoreModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
