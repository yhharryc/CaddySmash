#pragma once

#include "CoreMinimal.h"
#include "DebugFrameworkSettings.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

namespace DebugFramework
{
    inline APlayerController* ResolvePlayerController(const UWorld* World, const UDebugFrameworkSettings* Settings)
    {
        if (!World)
        {
            return nullptr;
        }

        const auto FindFirstLocal = [World]() -> APlayerController*
        {
            APlayerController* FirstFound = nullptr;
            for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
            {
                APlayerController* PlayerController = It->Get();
                if (!FirstFound)
                {
                    FirstFound = PlayerController;
                }
                if (PlayerController && PlayerController->IsLocalController() && PlayerController->GetLocalPlayer())
                {
                    return PlayerController;
                }
            }

            return FirstFound ? FirstFound : World->GetFirstPlayerController();
        };

        const EDebugFrameworkPlayerControllerPolicy Policy = Settings
            ? Settings->PlayerControllerPolicy
            : EDebugFrameworkPlayerControllerPolicy::FirstLocal;

        if (Policy == EDebugFrameworkPlayerControllerPolicy::PrimaryLocalPlayer)
        {
            if (UGameInstance* GameInstance = World->GetGameInstance())
            {
                if (ULocalPlayer* PrimaryPlayer = GameInstance->GetFirstGamePlayer())
                {
                    if (APlayerController* PrimaryController = PrimaryPlayer->PlayerController)
                    {
                        return PrimaryController;
                    }
                }
            }
            return FindFirstLocal();
        }

        if (Policy == EDebugFrameworkPlayerControllerPolicy::ExplicitLocalPlayerIndex)
        {
            if (UGameInstance* GameInstance = World->GetGameInstance())
            {
                const TArray<ULocalPlayer*>& Players = GameInstance->GetLocalPlayers();
                const int32 Index = Settings ? Settings->ExplicitLocalPlayerIndex : 0;
                if (Players.IsValidIndex(Index) && Players[Index] && Players[Index]->PlayerController)
                {
                    return Players[Index]->PlayerController;
                }
            }
            return FindFirstLocal();
        }

        return FindFirstLocal();
    }
}
