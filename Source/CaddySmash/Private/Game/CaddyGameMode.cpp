#include "Game/CaddyGameMode.h"

#include "Game/CaddyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerStart.h"
#include "Vehicle/CaddyVehiclePawn.h"

ACaddyGameMode::ACaddyGameMode()
{
    DefaultPawnClass = ACaddyVehiclePawn::StaticClass();
    PlayerControllerClass = ACaddyPlayerController::StaticClass();
}

void ACaddyGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (!bAutoCreateLocalPlayers || DesiredLocalPlayerCount <= 1)
    {
        return;
    }

    if (GetNetMode() == NM_DedicatedServer)
    {
        return;
    }

    UGameInstance* GameInstance = GetGameInstance();
    if (!GameInstance)
    {
        return;
    }

    const int32 ExistingLocalPlayers = GameInstance->GetNumLocalPlayers();
    for (int32 Index = ExistingLocalPlayers; Index < DesiredLocalPlayerCount; ++Index)
    {
        UGameplayStatics::CreatePlayer(this, -1, true);
    }
}

AActor* ACaddyGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
    if (bUsePlayerStartTagIndex)
    {
        const APlayerController* PlayerController = Cast<APlayerController>(Player);
        if (PlayerController)
        {
            const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
            if (LocalPlayer)
            {
                const int32 ControllerId = LocalPlayer->GetControllerId();
                const FName DesiredTag(*FString::Printf(TEXT("%s%d"), *PlayerStartTagPrefix.ToString(), ControllerId));

                TArray<AActor*> PlayerStarts;
                UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), PlayerStarts);
                for (AActor* Start : PlayerStarts)
                {
                    const APlayerStart* PlayerStart = Cast<APlayerStart>(Start);
                    if (PlayerStart && PlayerStart->PlayerStartTag == DesiredTag)
                    {
                        return Start;
                    }
                }
            }
        }
    }

    return Super::ChoosePlayerStart_Implementation(Player);
}
