#include "HitRegisterTeamUtils.h"

#include "HitRegisterCollision/HitRegisterTeamInterface.h"

namespace
{
    static UObject* FindTeamAgent(AActor* Actor)
    {
        if (!Actor) return nullptr;
        if (Actor->GetClass()->ImplementsInterface(UHitRegisterTeamAgent::StaticClass()))
        {
            return Actor;
        }
        TArray<UActorComponent*> Comps;
        Actor->GetComponents(Comps);
        for (UActorComponent* Comp : Comps)
        {
            if (Comp && Comp->GetClass()->ImplementsInterface(UHitRegisterTeamAgent::StaticClass()))
            {
                return Comp;
            }
        }
        return nullptr;
    }
}

bool HitRegisterTeamUtils::TryGetTeamId(AActor* Actor, int32& OutTeamId)
{
    OutTeamId = INDEX_NONE;
    if (!Actor) return false;
    if (UObject* Obj = FindTeamAgent(Actor))
    {
        OutTeamId = IHitRegisterTeamAgent::Execute_GetTeamId(Obj);
        return OutTeamId != INDEX_NONE;
    }
    return false;
}
