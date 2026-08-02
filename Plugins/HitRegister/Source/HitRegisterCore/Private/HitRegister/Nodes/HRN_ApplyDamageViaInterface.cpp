#include "HitRegister/Nodes/HRN_ApplyDamageViaInterface.h"

#include "HitRegister/HitRegisterInterfaces.h"

namespace
{
    static UObject* FindDamageApplier(AActor* Actor)
    {
        if (!Actor) return nullptr;
        if (Actor->GetClass()->ImplementsInterface(UDamageApplier::StaticClass()))
        {
            return Actor;
        }
        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UDamageApplier::StaticClass()))
            {
                return Comp;
            }
        }
        return nullptr;
    }

    static void NotifyPostDamage(AActor* Actor, const FHitRegisterContext& Context)
    {
        if (!Actor) return;
        if (Actor->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()))
        {
            IHitReceiver::Execute_OnPostDamage(Actor, Context);
            return;
        }
        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()))
            {
                IHitReceiver::Execute_OnPostDamage(Comp, Context);
                return;
            }
        }
    }
}

EHitNodeResult UHRN_ApplyDamageViaInterface::Execute_Implementation(FHitRegisterContext& Context)
{
    AActor* Target = Context.Hit.GetActor();
    if (!Target)
    {
        Context.Result.StopReason = EHitRegisterStopReason::InvalidHit;
        return EHitNodeResult::Stop;
    }

    UObject* ApplierObj = FindDamageApplier(Target);
    if (!ApplierObj)
    {
        if (bStopIfNoApplier)
        {
            Context.Result.StopReason = EHitRegisterStopReason::NoDamageable;
            return EHitNodeResult::Stop;
        }
        return EHitNodeResult::Continue;
    }

    const bool bOk = IDamageApplier::Execute_ApplyDamage(ApplierObj, Context);
    if (!bOk)
    {
        Context.Result.StopReason = EHitRegisterStopReason::StoppedByNode;
        return EHitNodeResult::Stop;
    }

    NotifyPostDamage(Target, Context);
    return EHitNodeResult::Continue;
}
