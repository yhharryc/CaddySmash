#include "HitRegisterCollision/HitRegisterCollisionSettings.h"

#include "HitRegisterCollision/HitRegisterRelationResolver.h"

bool UHitRegisterCollisionSettings::ValidateSettings(FString* OutError) const
{
    if (RelationResolver.IsNull())
    {
        return true;
    }

    UHitRegisterRelationResolverAsset* LoadedResolver = RelationResolver.LoadSynchronous();
    if (!LoadedResolver)
    {
        const FString Error = FString::Printf(TEXT("HitRegisterCollisionSettings failed to load RelationResolver '%s'."), *RelationResolver.ToString());
        if (OutError)
        {
            *OutError = Error;
        }
        return false;
    }

    if (!LoadedResolver->GetClass()->ImplementsInterface(UHitRegisterRelationResolver::StaticClass()))
    {
        const FString Error = FString::Printf(TEXT("RelationResolver '%s' does not implement HitRegisterRelationResolver interface."), *GetNameSafe(LoadedResolver));
        if (OutError)
        {
            *OutError = Error;
        }
        return false;
    }

    return true;
}

