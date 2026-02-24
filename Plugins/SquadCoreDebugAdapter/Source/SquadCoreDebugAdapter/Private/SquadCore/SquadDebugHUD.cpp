#include "SquadCore/SquadDebugHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "HAL/IConsoleManager.h"
#include "SquadCore/SquadDebugComponent.h"

static TAutoConsoleVariable<int32> CVarSquadDebugHud(
    TEXT("squad.Debug.HUD"),
    1,
    TEXT("Enable Squad debug HUD list (0/1)."),
    ECVF_Cheat);

ASquadDebugHUD::ASquadDebugHUD()
{
}

bool ASquadDebugHUD::IsHudEnabled() const
{
    return bEnabled && CVarSquadDebugHud.GetValueOnGameThread() != 0;
}

void ASquadDebugHUD::DrawHUD()
{
    Super::DrawHUD();

    if (!IsHudEnabled() || !Canvas)
    {
        return;
    }

    const float StartX = 24.f;
    float CursorY = 24.f;
    int32 Count = 0;

    DrawText(TEXT("Squad Debug"), TextColor, StartX, CursorY);
    CursorY += LineHeight;

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    for (TActorIterator<AActor> It(World); It; ++It)
    {
        if (Count >= MaxEntries)
        {
            break;
        }

        AActor* Actor = *It;
        if (!Actor)
        {
            continue;
        }

        USquadDebugComponent* DebugComp = Actor->FindComponentByClass<USquadDebugComponent>();
        if (!DebugComp)
        {
            continue;
        }

        const FSquadDebugSnapshot Snapshot = DebugComp->GetSnapshot();
        if (!Snapshot.Owner)
        {
            continue;
        }

        const FString TargetName = Snapshot.BestTarget ? Snapshot.BestTarget->GetName() : TEXT("None");
        const FString ProfileName = Snapshot.AttackProfile ? Snapshot.AttackProfile->GetName() : TEXT("None");
        const FString Line = FString::Printf(
            TEXT("%s | Task:%s | Target:%s | Profile:%s | CD:%.2f | Slot:%d | OOW:%d"),
            *Snapshot.Owner->GetName(),
            *Snapshot.DebugLastTask.ToString(),
            *TargetName,
            *ProfileName,
            Snapshot.CooldownRemaining,
            Snapshot.SlotId,
            Snapshot.bTemporarilyOutOfFormation ? 1 : 0);

        DrawText(Line, TextColor, StartX, CursorY);
        CursorY += LineHeight;
        ++Count;
    }
}
