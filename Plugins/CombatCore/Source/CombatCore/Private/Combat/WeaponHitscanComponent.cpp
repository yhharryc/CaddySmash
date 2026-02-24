#include "Combat/WeaponHitscanComponent.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

UWeaponHitscanComponent::UWeaponHitscanComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponHitscanComponent::ExecuteAttack_Implementation(FCombatAttackContext& Context)
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return;
    }

    FVector EyeLoc;
    FRotator EyeRot;
    Owner->GetActorEyesViewPoint(EyeLoc, EyeRot);

    float EffectiveRange = Range;
    if (Context.ExecutionParams.bOverrideHitscanRange)
    {
        EffectiveRange = Context.ExecutionParams.HitscanRange;
    }
    else if (Context.ExecutionParams.EffectiveAttackRange > 0.f)
    {
        EffectiveRange = Context.ExecutionParams.EffectiveAttackRange;
    }

    const FVector Start = EyeLoc;
    const FVector End = Start + (EyeRot.Vector() * FMath::Max(0.f, EffectiveRange));

    FHitResult Hit;
    FCollisionQueryParams Params(SCENE_QUERY_STAT(WeaponHitscan), false, Owner);
    Params.AddIgnoredActor(Owner);

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    const bool bHit = World->LineTraceSingleByChannel(Hit, Start, End, TraceChannel, Params);

    if (bDrawDebug)
    {
        const FColor Color = bHit ? FColor::Red : FColor::Green;
        DrawDebugLine(World, Start, End, Color, false, 1.0f, 0, 1.0f);
    }

    if (bHit && Hit.GetActor())
    {
        AActor* InstigatorActor = Context.Request.Instigator.Get();
        AController* InstigatorController = InstigatorActor ? InstigatorActor->GetInstigatorController() : nullptr;

        const float FinalDamage = Context.Request.BaseDamage > 0.f ? Context.Request.BaseDamage : Damage;
        UGameplayStatics::ApplyPointDamage(Hit.GetActor(), FinalDamage, EyeRot.Vector(), Hit, InstigatorController, Owner, UDamageType::StaticClass());
    }
}
