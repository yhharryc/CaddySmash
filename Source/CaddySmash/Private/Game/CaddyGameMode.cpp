#include "Game/CaddyGameMode.h"

#include "Game/CaddyPlayerController.h"
#include "Vehicle/CaddyVehiclePawn.h"

ACaddyGameMode::ACaddyGameMode()
{
    DefaultPawnClass = ACaddyVehiclePawn::StaticClass();
    PlayerControllerClass = ACaddyPlayerController::StaticClass();
}
