#include "DebugFramework/DebugFrameworkSettings.h"

#include "InputCoreTypes.h"

UDebugFrameworkSettings::UDebugFrameworkSettings()
{
    ToggleVisibilityChord.Key = EKeys::F10;
    ToggleVisibilityChord.bCtrl = true;
    ToggleVisibilityChord.bAlt = false;
    ToggleVisibilityChord.bShift = false;
    ToggleVisibilityChord.bCmd = false;
    ToggleVisibilityChord.bRequireExactModifiers = false;
}

#if WITH_EDITOR
FText UDebugFrameworkSettings::GetSectionText() const
{
    return NSLOCTEXT("DebugFramework", "SettingsSectionText", "Debug Framework");
}

FText UDebugFrameworkSettings::GetSectionDescription() const
{
    return NSLOCTEXT("DebugFramework", "SettingsSectionDescription", "Runtime debug overlay and panel interaction settings.");
}
#endif
