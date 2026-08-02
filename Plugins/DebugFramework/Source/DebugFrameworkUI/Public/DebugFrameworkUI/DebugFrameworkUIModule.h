#pragma once

#include "Modules/ModuleManager.h"

class FDebugFrameworkUIModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
