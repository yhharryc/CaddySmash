#include "HitRegister/HitRegisterBPLibrary.h"

#include "HitRegister/HitRegisterSettings.h"
#include "HitRegister/HitRegisterSubsystem.h"
#include "HitRegister/HitRegisterPipeline.h"

UHitRegisterPipeline* UHitRegisterBPLibrary::GetDefaultPipeline()
{
    const UHitRegisterSettings* Settings = UHitRegisterSettings::Get();
    if (!Settings) return nullptr;
    return Settings->DefaultPipeline.LoadSynchronous();
}

bool UHitRegisterBPLibrary::ExecuteHitRegister(UObject* WorldContextObject, const FAttackRequest& Attack, const FHitResult& Hit, UHitRegisterPipeline* Pipeline, FHitRegisterContext& OutContext)
{
    if (!WorldContextObject) return false;
    UWorld* World = WorldContextObject->GetWorld();
    if (!World) return false;

    UHitRegisterSubsystem* Subsys = World->GetSubsystem<UHitRegisterSubsystem>();
    if (!Subsys) return false;

    return Subsys->ExecuteHitRegister(Attack, Hit, Pipeline, OutContext);
}

bool UHitRegisterBPLibrary::ExecuteHitRegisterDefault(UObject* WorldContextObject, const FAttackRequest& Attack, const FHitResult& Hit, FHitRegisterContext& OutContext)
{
    return ExecuteHitRegister(WorldContextObject, Attack, Hit, GetDefaultPipeline(), OutContext);
}
