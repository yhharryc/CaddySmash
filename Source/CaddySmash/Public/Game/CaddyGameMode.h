#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CaddyGameMode.generated.h"

UCLASS()
class CADDYSMASH_API ACaddyGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ACaddyGameMode();

    virtual void BeginPlay() override;
    virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Caddy|LocalMultiplayer", meta=(ClampMin="1", UIMin="1"))
    int32 DesiredLocalPlayerCount = 1;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Caddy|LocalMultiplayer")
    bool bAutoCreateLocalPlayers = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Caddy|LocalMultiplayer")
    bool bUsePlayerStartTagIndex = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Caddy|LocalMultiplayer")
    FName PlayerStartTagPrefix = "Player";
};

