#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DebugFrameworkTypes.h"
#include "DebugFrameworkProvider.generated.h"

UINTERFACE(BlueprintType)
class DEBUGFRAMEWORKCORE_API UDebugFrameworkProvider : public UInterface
{
    GENERATED_BODY()
};

class DEBUGFRAMEWORKCORE_API IDebugFrameworkProvider
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    FName GetDebugPanelId() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    FText GetDebugPanelTitle() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    FName GetDebugToolId() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    FText GetDebugToolTitle() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    int32 GetDebugSortOrder() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="DebugFramework")
    void GatherDebugRows(UPARAM(ref) TArray<FDebugFrameworkPanelRow>& OutRows) const;

    virtual FName GetDebugToolId_Implementation() const { return NAME_None; }
    virtual FText GetDebugToolTitle_Implementation() const { return FText::GetEmpty(); }
};
