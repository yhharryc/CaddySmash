#include "SquadCore/PressureComponent.h"

#include "Kismet/GameplayStatics.h"
#include "SquadCore/SquadMemberComponent.h"

UPressureComponent::UPressureComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UPressureComponent::BeginPlay()
{
    Super::BeginPlay();

    if (bAutoUpdate && UpdateInterval > 0.f)
    {
        GetWorld()->GetTimerManager().SetTimer(UpdateTimerHandle, this, &UPressureComponent::UpdatePressureInternal, UpdateInterval, true);
    }
}

void UPressureComponent::UpdatePressure()
{
    UpdatePressureInternal();
}

void UPressureComponent::UpdatePressureInternal()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    if (!ThreatClass)
    {
        PressureValue = 0.f;
        return;
    }

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(World, ThreatClass, FoundActors);

    float Count = 0.f;
    if (QueryRadius <= 0.f)
    {
        Count = static_cast<float>(FoundActors.Num());
    }
    else
    {
        const FVector Origin = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
        for (AActor* Actor : FoundActors)
        {
            if (!Actor)
            {
                continue;
            }
            if (FVector::DistSquared(Origin, Actor->GetActorLocation()) <= FMath::Square(QueryRadius))
            {
                Count += 1.f;
            }
        }
    }

    PressureValue = FMath::Clamp(Count * ThreatWeight, 0.f, MaxPressure);

    if (USquadMemberComponent* Member = GetOwner()->FindComponentByClass<USquadMemberComponent>())
    {
        Member->PressureValue = PressureValue;
    }
}
