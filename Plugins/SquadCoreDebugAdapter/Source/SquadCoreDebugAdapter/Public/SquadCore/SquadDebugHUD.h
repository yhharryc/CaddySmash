#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SquadDebugHUD.generated.h"

UCLASS(BlueprintType)
class SQUADCOREDEBUGADAPTER_API ASquadDebugHUD : public AHUD
{
    GENERATED_BODY()

public:
    ASquadDebugHUD();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    int32 MaxEntries = 32;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    float LineHeight = 14.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad|Debug")
    FLinearColor TextColor = FLinearColor::White;

protected:
    virtual void DrawHUD() override;

private:
    bool IsHudEnabled() const;
};
