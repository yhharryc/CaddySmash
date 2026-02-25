#include "Game/CaddyPlayerController.h"

#include "Kismet/GameplayStatics.h"

ACaddyPlayerController::ACaddyPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void ACaddyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    SetInputMode(InputMode);
}

APlayerController* ACaddyPlayerController::SpawnAdditionalLocalPlayer()
{
    return UGameplayStatics::CreatePlayer(this, -1, true);
}
