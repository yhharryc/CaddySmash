#include "DebugFrameworkUI/DebugFrameworkOverlayWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UDebugFrameworkOverlayWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (!WidgetTree->RootWidget)
    {
        RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
        WidgetTree->RootWidget = RootCanvas;
    }

    if (!RootCanvas)
    {
        RootCanvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
    }
}

UCanvasPanelSlot* UDebugFrameworkOverlayWidget::AddPanelWidget(UUserWidget* PanelWidget, const FVector2D& Position, const FVector2D& Size)
{
    if (!PanelWidget)
    {
        return nullptr;
    }

    if (!RootCanvas)
    {
        if (!WidgetTree->RootWidget)
        {
            RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
            WidgetTree->RootWidget = RootCanvas;
        }
        else
        {
            RootCanvas = Cast<UCanvasPanel>(WidgetTree->RootWidget);
        }
    }

    if (!RootCanvas)
    {
        return nullptr;
    }

    if (PanelWidget->GetParent())
    {
        PanelWidget->RemoveFromParent();
    }

    UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(PanelWidget);
    if (!CanvasSlot)
    {
        return nullptr;
    }

    CanvasSlot->SetAutoSize(false);
    CanvasSlot->SetPosition(Position);
    CanvasSlot->SetSize(Size);
    CanvasSlot->SetAlignment(FVector2D::ZeroVector);
    CanvasSlot->SetZOrder(1);
    return CanvasSlot;
}
