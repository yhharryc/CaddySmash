#include "HitRegister/HitRegisterSubsystem.h"

#include "HitRegister/HitRegisterInterfaces.h"

namespace
{
    static UObject* FindInterfaceImplementer(AActor* Actor, UClass* InterfaceClass)
    {
        if (!Actor || !InterfaceClass) return nullptr;

        if (Actor->GetClass()->ImplementsInterface(InterfaceClass))
        {
            return Actor;
        }

        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(InterfaceClass))
            {
                return Comp;
            }
        }
        return nullptr;
    }
}

bool UHitRegisterSubsystem::ExecuteHitRegister(const FAttackRequest& Attack, const FHitResult& Hit, UHitRegisterPipeline* Pipeline, FHitRegisterContext& OutContext)
{
    OutContext = FHitRegisterContext{};
    OutContext.Attack = Attack;
    OutContext.Hit = Hit;

    if (!Pipeline)
    {
        OutContext.Result.StopReason = EHitRegisterStopReason::InvalidHit;
        return false;
    }

    // Base init
    OutContext.Damage.RawDamage = Attack.BaseDamage;
    OutContext.Damage.MitigatedDamage = OutContext.Damage.RawDamage;
    OutContext.Damage.FinalDamage = OutContext.Damage.MitigatedDamage;

    // Optional receiver gate
    if (AActor* Target = OutContext.Hit.GetActor())
    {
        if (UObject* ReceiverObj = FindInterfaceImplementer(Target, UHitReceiver::StaticClass()))
        {
            const FName FnName(TEXT("ShouldAcceptHit"));
            const bool bHasFn = ReceiverObj->FindFunction(FnName) != nullptr;
            const bool bAccept = !bHasFn ? true : IHitReceiver::Execute_ShouldAcceptHit(ReceiverObj, OutContext);
            if (!bAccept)
            {
                OutContext.Result.StopReason = EHitRegisterStopReason::ReceiverRejected;
                return false;
            }
        }
    }

    for (UHitRegisterNode* Node : Pipeline->Nodes)
    {
        if (!Node) continue;
        const EHitNodeResult R = Node->Execute(OutContext);
        if (R == EHitNodeResult::Stop)
        {
            if (OutContext.Result.StopReason == EHitRegisterStopReason::None)
            {
                OutContext.Result.StopReason = EHitRegisterStopReason::StoppedByNode;
            }
            return false;
        }
    }

    return true;
}
