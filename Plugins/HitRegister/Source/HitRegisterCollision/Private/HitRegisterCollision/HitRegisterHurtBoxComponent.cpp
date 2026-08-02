#include "HitRegisterCollision/HitRegisterHurtBoxComponent.h"

UHitRegisterHurtBoxComponent::UHitRegisterHurtBoxComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetCanEverAffectNavigation(false);
    SetGenerateOverlapEvents(true);
    SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}
