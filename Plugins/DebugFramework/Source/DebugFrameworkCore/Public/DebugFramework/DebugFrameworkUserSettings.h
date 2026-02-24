#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DebugFrameworkTypes.h"
#include "DebugFrameworkUserSettings.generated.h"

UCLASS(Config=GameUserSettings, DefaultConfig)
class DEBUGFRAMEWORKCORE_API UDebugFrameworkUserSettings : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(Config)
    bool bVisible = true;

    UPROPERTY(Config)
    TArray<FDebugFrameworkPanelLayout> PanelLayouts;

    UPROPERTY(Config)
    TArray<FName> HiddenPanelIds;

    bool FindLayout(FName PanelId, FDebugFrameworkPanelLayout& OutLayout) const;
    void UpsertLayout(const FDebugFrameworkPanelLayout& Layout);

    static const UDebugFrameworkUserSettings* Get() { return GetDefault<UDebugFrameworkUserSettings>(); }
    static UDebugFrameworkUserSettings* GetMutable() { return GetMutableDefault<UDebugFrameworkUserSettings>(); }
};
