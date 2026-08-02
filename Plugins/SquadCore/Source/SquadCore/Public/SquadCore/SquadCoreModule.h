#pragma once

#include "Modules/ModuleManager.h"

class FSquadCoreModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};
