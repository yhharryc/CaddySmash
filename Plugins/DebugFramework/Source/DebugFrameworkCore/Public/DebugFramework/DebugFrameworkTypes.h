#pragma once

#include "CoreMinimal.h"
#include "DebugFrameworkTypes.generated.h"

USTRUCT(BlueprintType)
struct DEBUGFRAMEWORKCORE_API FDebugFrameworkPanelRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FString Label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FString Value;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FLinearColor Color = FLinearColor::White;
};

USTRUCT(BlueprintType)
struct DEBUGFRAMEWORKCORE_API FDebugFrameworkPanelData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FName PanelId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FName ToolId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FText ToolTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    int32 SortOrder = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    TArray<FDebugFrameworkPanelRow> Rows;
};

USTRUCT(BlueprintType)
struct DEBUGFRAMEWORKCORE_API FDebugFrameworkPanelLayout
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FName PanelId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FVector2D Position = FVector2D(80.f, 80.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FVector2D Size = FVector2D(420.f, 260.f);
};
