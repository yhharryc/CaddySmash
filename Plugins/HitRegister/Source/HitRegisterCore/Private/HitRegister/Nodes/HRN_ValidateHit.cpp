#include "HitRegister/Nodes/HRN_ValidateHit.h"

#include "HitRegister/HitRegisterInterfaces.h"

namespace
{
    static bool HasDamageApplier(AActor* Actor)
    {
        if (!Actor) return false;
        if (Actor->GetClass()->ImplementsInterface(UDamageApplier::StaticClass()))
        {
            return true;
        }
        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UDamageApplier::StaticClass()))
            {
                return true;
            }
        }
        return false;
    }
}

EHitNodeResult UHRN_ValidateHit::Execute_Implementation(FHitRegisterContext& Context)
{
    if (!Context.Hit.bBlockingHit || !Context.Hit.GetActor())
    {
        Context.Result.StopReason = EHitRegisterStopReason::Missed;
        return EHitNodeResult::Stop;
    }

    if (bRequireDamageApplier && !HasDamageApplier(Context.Hit.GetActor()))
    {
        Context.Result.StopReason = EHitRegisterStopReason::NoDamageable;
        return EHitNodeResult::Stop;
    }

    // Notify receiver that hit is confirmed
    if (UObject* ReceiverObj = Context.Hit.GetActor(); ReceiverObj && ReceiverObj->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()))
    {
        IHitReceiver::Execute_OnHitConfirmed(ReceiverObj, Context);
    }
    else
    {
        // Check components
        TArray<UActorComponent*> Comps;
        Context.Hit.GetActor()->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()))
            {
                IHitReceiver::Execute_OnHitConfirmed(Comp, Context);
                break;
            }
        }
    }

    return EHitNodeResult::Continue;
}
