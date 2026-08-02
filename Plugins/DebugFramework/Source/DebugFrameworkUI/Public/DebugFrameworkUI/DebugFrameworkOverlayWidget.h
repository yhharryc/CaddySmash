#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugFrameworkOverlayWidget.generated.h"

class UCanvasPanel;
class UCanvasPanelSlot;

UCLASS()
class DEBUGFRAMEWORKUI_API UDebugFrameworkOverlayWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UCanvasPanelSlot* AddPanelWidget(UUserWidget* PanelWidget, const FVector2D& Position, const FVector2D& Size);

private:
    UPROPERTY(Transient)
    TObjectPtr<UCanvasPanel> RootCanvas = nullptr;
};
