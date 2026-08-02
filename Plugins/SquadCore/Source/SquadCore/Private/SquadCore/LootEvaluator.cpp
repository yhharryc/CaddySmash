#include "SquadCore/LootEvaluator.h"

#include "Kismet/GameplayStatics.h"

void ULootEvaluator::EvaluateLoot_Implementation(AActor* Source, TArray<FLootCandidate>& OutLoot) const
{
    OutLoot.Reset();
    if (!Source || !LootClass)
    {
        return;
    }

    UWorld* World = Source->GetWorld();
    if (!World)
    {
        return;
    }

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(World, LootClass, FoundActors);

    const FVector Origin = Source->GetActorLocation();
    const float MaxRangeSq = FMath::Square(FMath::Max(1.f, MaxRange));

    for (AActor* Actor : FoundActors)
    {
        if (!Actor || Actor == Source)
        {
            continue;
        }

        const float DistSq = FVector::DistSquared(Origin, Actor->GetActorLocation());
        if (DistSq > MaxRangeSq)
        {
            continue;
        }

        const float Alpha = 1.f - FMath::Clamp(DistSq / MaxRangeSq, 0.f, 1.f);

        FLootCandidate Candidate;
        Candidate.LootActor = Actor;
        Candidate.Score = Alpha * DistanceWeight;
        OutLoot.Add(Candidate);
    }
}
