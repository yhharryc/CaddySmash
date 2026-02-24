#include "SquadCore/ThreatEvaluator.h"

#include "Kismet/GameplayStatics.h"
#include "SquadCore/SquadMemberComponent.h"

void UThreatEvaluator::EvaluateThreats_Implementation(AActor* Source, TArray<FThreatCandidate>& OutThreats) const
{
    OutThreats.Reset();
    if (!Source || !ThreatClass)
    {
        return;
    }

    UWorld* World = Source->GetWorld();
    if (!World)
    {
        return;
    }

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(World, ThreatClass, FoundActors);

    const FVector Origin = Source->GetActorLocation();
    float EffectiveMaxRange = MaxRange;
    if (const USquadMemberComponent* Member = Source->FindComponentByClass<USquadMemberComponent>())
    {
        if (Member->CurrentAggressionRange > 0.f)
        {
            EffectiveMaxRange = Member->CurrentAggressionRange;
        }
    }

    const bool bUseRangeGate = EffectiveMaxRange > 0.f;
    const float MaxRangeSq = bUseRangeGate ? FMath::Square(EffectiveMaxRange) : 0.f;

    for (AActor* Actor : FoundActors)
    {
        if (!Actor || Actor == Source)
        {
            continue;
        }

        const float DistSq = FVector::DistSquared(Origin, Actor->GetActorLocation());
        if (bUseRangeGate && DistSq > MaxRangeSq)
        {
            continue;
        }

        const float Alpha = bUseRangeGate ? (1.f - FMath::Clamp(DistSq / MaxRangeSq, 0.f, 1.f)) : 1.f;

        FThreatCandidate Candidate;
        Candidate.Target = Actor;
        Candidate.Score = Alpha * DistanceWeight;
        OutThreats.Add(Candidate);
    }
}
