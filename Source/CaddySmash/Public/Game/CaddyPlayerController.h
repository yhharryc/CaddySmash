#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CaddyPlayerController.generated.h"

UCLASS()
class CADDYSMASH_API ACaddyPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ACaddyPlayerController();
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category="Caddy|LocalMultiplayer")
    APlayerController* SpawnAdditionalLocalPlayer();
};
