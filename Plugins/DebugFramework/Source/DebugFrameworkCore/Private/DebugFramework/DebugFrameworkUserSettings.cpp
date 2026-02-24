#include "DebugFramework/DebugFrameworkUserSettings.h"

bool UDebugFrameworkUserSettings::FindLayout(FName PanelId, FDebugFrameworkPanelLayout& OutLayout) const
{
    for (const FDebugFrameworkPanelLayout& Entry : PanelLayouts)
    {
        if (Entry.PanelId == PanelId)
        {
            OutLayout = Entry;
            return true;
        }
    }
    return false;
}

void UDebugFrameworkUserSettings::UpsertLayout(const FDebugFrameworkPanelLayout& Layout)
{
    for (FDebugFrameworkPanelLayout& Entry : PanelLayouts)
    {
        if (Entry.PanelId == Layout.PanelId)
        {
            Entry = Layout;
            return;
        }
    }

    PanelLayouts.Add(Layout);
}
