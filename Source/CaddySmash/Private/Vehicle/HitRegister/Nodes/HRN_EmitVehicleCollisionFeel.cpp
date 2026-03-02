#include "Vehicle/HitRegister/Nodes/HRN_EmitVehicleCollisionFeel.h"

#include "Containers/Array.h"
#include "GameFramework/Actor.h"
#include "Vehicle/CaddyVehiclePawn.h"

namespace
{
    static float GetCollisionFeelAttrValue(const TMap<FGameplayTag, float>& Attributes, const FGameplayTag& Tag, const float DefaultValue = 0.0f)
    {
        if (!Tag.IsValid())
        {
            return DefaultValue;
        }

        if (const float* Value = Attributes.Find(Tag))
        {
            return *Value;
        }
        return DefaultValue;
    }

    static void SetAttrValue(TMap<FGameplayTag, float>& Attributes, const FGameplayTag& Tag, const float Value)
    {
        if (Tag.IsValid())
        {
            Attributes.FindOrAdd(Tag) = Value;
        }
    }
}

UHRN_EmitVehicleCollisionFeel::UHRN_EmitVehicleCollisionFeel()
{
    NormalImpactSpeedTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.NormalImpactSpeed"), false);
    ImpactTierTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.ImpactTier"), false);
    FeelRecipientCountOutputTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.Debug.FeelRecipientCount"), false);
    FeelExecutedOutputTag = FGameplayTag::RequestGameplayTag(FName("Attr.Collision.Debug.FeelExecuted"), false);

    LightImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Light"), false);
    MediumImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Medium"), false);
    HeavyImpactTag = FGameplayTag::RequestGameplayTag(FName("Hit.Collision.Impact.Heavy"), false);
}

EHitNodeResult UHRN_EmitVehicleCollisionFeel::Execute_Implementation(FHitRegisterContext& Context)
{
    SetAttrValue(Context.Attack.Attributes, FeelExecutedOutputTag, 0.0f);
    SetAttrValue(Context.Attack.Attributes, FeelRecipientCountOutputTag, 0.0f);

    if (bRequireBlockingHit && !Context.Hit.bBlockingHit)
    {
        return EHitNodeResult::Continue;
    }

    AActor* TargetActor = Context.Hit.GetActor();
    if (!TargetActor)
    {
        return EHitNodeResult::Continue;
    }

    if (bEmitOnAuthorityOnly && !TargetActor->HasAuthority())
    {
        return EHitNodeResult::Continue;
    }

    ACaddyVehiclePawn* TargetVehicle = Cast<ACaddyVehiclePawn>(TargetActor);
    ACaddyVehiclePawn* InstigatorVehicle = Cast<ACaddyVehiclePawn>(Context.Attack.Instigator.Get());

    const float NormalImpactSpeed = GetCollisionFeelAttrValue(Context.Attack.Attributes, NormalImpactSpeedTag, 0.0f);
    if (NormalImpactSpeed < MinNormalImpactSpeed)
    {
        return EHitNodeResult::Continue;
    }

    float ImpactTierValue = GetCollisionFeelAttrValue(Context.Attack.Attributes, ImpactTierTag, 0.0f);
    if (ImpactTierValue <= 0.0f)
    {
        if (HeavyImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(HeavyImpactTag))
        {
            ImpactTierValue = 3.0f;
        }
        else if (MediumImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(MediumImpactTag))
        {
            ImpactTierValue = 2.0f;
        }
        else if (LightImpactTag.IsValid() && Context.Attack.Tags.HasTagExact(LightImpactTag))
        {
            ImpactTierValue = 1.0f;
        }
    }
    const uint8 ImpactTier = static_cast<uint8>(FMath::Clamp(FMath::RoundToInt(ImpactTierValue), 0, 3));

    // Build target-surface outward direction first.
    FVector SurfaceOutwardNormal = Context.Hit.Normal.GetSafeNormal2D();
    if (TargetVehicle && !Context.Hit.ImpactPoint.IsNearlyZero())
    {
        const FVector FromTargetCenter = (Context.Hit.ImpactPoint - TargetActor->GetActorLocation()).GetSafeNormal2D();
        if (!FromTargetCenter.IsNearlyZero())
        {
            SurfaceOutwardNormal = FromTargetCenter;
        }
    }

    if (SurfaceOutwardNormal.IsNearlyZero())
    {
        if (const AActor* SourceActor = Context.Attack.Instigator.Get())
        {
            SurfaceOutwardNormal = (SourceActor->GetActorLocation() - TargetActor->GetActorLocation()).GetSafeNormal2D();
        }
    }

    if (SurfaceOutwardNormal.IsNearlyZero())
    {
        SurfaceOutwardNormal = TargetActor->GetActorForwardVector().GetSafeNormal2D();
    }

    // "Incoming side" for target should represent the side being hit (target -> source),
    // which is more intuitive for left/right roll presentation than force direction.
    FVector IncomingSideDirectionForTarget = FVector::ZeroVector;
    if (const AActor* SourceActor = Context.Attack.Instigator.Get())
    {
        IncomingSideDirectionForTarget = (SourceActor->GetActorLocation() - TargetActor->GetActorLocation()).GetSafeNormal2D();
    }
    if (IncomingSideDirectionForTarget.IsNearlyZero() && !Context.Hit.ImpactPoint.IsNearlyZero())
    {
        IncomingSideDirectionForTarget = (Context.Hit.ImpactPoint - TargetActor->GetActorLocation()).GetSafeNormal2D();
    }
    if (IncomingSideDirectionForTarget.IsNearlyZero())
    {
        IncomingSideDirectionForTarget = SurfaceOutwardNormal;
    }
    if (IncomingSideDirectionForTarget.IsNearlyZero())
    {
        IncomingSideDirectionForTarget = TargetActor->GetActorForwardVector().GetSafeNormal2D();
    }

    TArray<ACaddyVehiclePawn*> Recipients;
    if (bEmitToTargetVehicle && TargetVehicle)
    {
        Recipients.Add(TargetVehicle);
    }

    if (bEmitToInstigatorVehicle && InstigatorVehicle && !Recipients.Contains(InstigatorVehicle))
    {
        Recipients.Add(InstigatorVehicle);
    }

    if (Recipients.Num() == 0)
    {
        if (bRequireVehiclePawnTarget)
        {
            return EHitNodeResult::Continue;
        }
        return EHitNodeResult::Continue;
    }

    int32 EmittedCount = 0;
    for (ACaddyVehiclePawn* Recipient : Recipients)
    {
        if (!Recipient)
        {
            continue;
        }
        if (bEmitOnAuthorityOnly && !Recipient->HasAuthority())
        {
            continue;
        }

        FVector RecipientNormal = IncomingSideDirectionForTarget;
        if (Recipient == InstigatorVehicle && bInvertImpactNormalForInstigator)
        {
            RecipientNormal *= -1.0f;
        }
        if (RecipientNormal.IsNearlyZero())
        {
            RecipientNormal = Recipient->GetActorForwardVector().GetSafeNormal2D();
        }

        Recipient->Multicast_PlayCollisionFeel(NormalImpactSpeed, ImpactTier, RecipientNormal);
        ++EmittedCount;
    }

    SetAttrValue(Context.Attack.Attributes, FeelRecipientCountOutputTag, static_cast<float>(EmittedCount));
    SetAttrValue(Context.Attack.Attributes, FeelExecutedOutputTag, EmittedCount > 0 ? 1.0f : 0.0f);
    return EHitNodeResult::Continue;
}
