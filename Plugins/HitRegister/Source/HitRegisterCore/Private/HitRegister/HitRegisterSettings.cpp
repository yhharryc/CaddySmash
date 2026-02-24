#include "HitRegister/HitRegisterSettings.h"
#include "GameplayTagsManager.h"

UHitRegisterSettings::UHitRegisterSettings()
{
    // Soft default: Data.Damage (common convention for SetByCaller)
    DamageSetByCallerTag = FGameplayTag::RequestGameplayTag(FName("Data.Damage"), false);
}
