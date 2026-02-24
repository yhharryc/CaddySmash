#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputCoreTypes.h"
#include "DebugFrameworkSettings.generated.h"

USTRUCT(BlueprintType)
struct DEBUGFRAMEWORKCORE_API FDebugFrameworkInputChord
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    FKey Key = EKeys::F10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    bool bCtrl = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    bool bAlt = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    bool bShift = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    bool bCmd = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DebugFramework")
    bool bRequireExactModifiers = false;

    bool IsValid() const { return Key.IsValid(); }
};

UENUM(BlueprintType)
enum class EDebugFrameworkPlayerControllerPolicy : uint8
{
    FirstLocal,
    PrimaryLocalPlayer,
    ExplicitLocalPlayerIndex
};

UCLASS(Config=Game, DefaultConfig, BlueprintType)
class DEBUGFRAMEWORKCORE_API UDebugFrameworkSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UDebugFrameworkSettings();

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bEnabledByDefault = false;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bForceVisibleInEditor = false;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bForceVisibleInNonShipping = false;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bAlwaysShowControlMenuInEditor = false;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bAlwaysShowControlMenuInNonShipping = false;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework")
    bool bControlMenuFollowsOverlay = true;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Input")
    FDebugFrameworkInputChord ToggleVisibilityChord;

    /** Policy for selecting which local player controller owns debug input and UI. */
    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Input")
    EDebugFrameworkPlayerControllerPolicy PlayerControllerPolicy = EDebugFrameworkPlayerControllerPolicy::FirstLocal;

    /** Used when policy is ExplicitLocalPlayerIndex. */
    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Input", meta=(ClampMin="0"))
    int32 ExplicitLocalPlayerIndex = 0;

    UPROPERTY(Config, meta=(DeprecatedProperty, DeprecationMessage="Use ToggleVisibilityChord", DisplayName="Toggle Visibility Key (Deprecated)"))
    FKey ToggleVisibilityKey;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels", meta=(ClampMin="0.02", ClampMax="1.0"))
    float DataRefreshInterval = 0.1f;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels")
    FVector2D DefaultPanelPosition = FVector2D(80.f, 80.f);

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels")
    FVector2D DefaultPanelSize = FVector2D(420.f, 260.f);

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels")
    FVector2D MinPanelSize = FVector2D(220.f, 140.f);

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels")
    FVector2D MaxPanelSize = FVector2D(1200.f, 900.f);

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Panels", meta=(ClampMin="0.01", ClampMax="1.0"))
    float MouseWheelResizeStep = 0.08f;

    UPROPERTY(EditAnywhere, Config, BlueprintReadOnly, Category="DebugFramework|Persistence", meta=(ClampMin="0.1", ClampMax="10.0"))
    float SaveThrottleSeconds = 0.5f;

    UFUNCTION(BlueprintCallable, Category="DebugFramework")
    static const UDebugFrameworkSettings* Get() { return GetDefault<UDebugFrameworkSettings>(); }

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
    virtual FName GetSectionName() const override { return TEXT("DebugFramework"); }

#if WITH_EDITOR
    virtual FText GetSectionText() const override;
    virtual FText GetSectionDescription() const override;
#endif
};
