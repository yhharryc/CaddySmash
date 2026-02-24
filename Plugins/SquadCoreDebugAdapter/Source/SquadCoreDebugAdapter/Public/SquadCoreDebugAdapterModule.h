#pragma once

#include "Modules/ModuleManager.h"

class FSquadCoreDebugAdapterModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};
