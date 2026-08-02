#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "CaddyVehicleSkillTargetActor_Trace.generated.h"

class UHitRegisterTargetingProfile;

UCLASS(NotPlaceable, Transient)
class CADDYSMASH_API ACaddyVehicleSkillTargetActor_Trace : public AGameplayAbilityTargetActor
{
    GENERATED_BODY()

public:
    ACaddyVehicleSkillTargetActor_Trace(const FObjectInitializer& ObjectInitializer);

    void Configure(
        float InTraceDistance,
        float InTraceRadius,
        ECollisionChannel InTraceChannel,
        UHitRegisterTargetingProfile* InTargetingProfile,
        bool bInEnableDebugDraw,
        float InDebugPersistSeconds);

    void SetAimDirectionHint2D(const FVector2D& InAimDirectionHint);

    virtual void StartTargeting(UGameplayAbility* Ability) override;
    virtual void ConfirmTargetingAndContinue() override;

private:
    FVector ResolveTraceDirection() const;

    float TraceDistance = 1800.0f;
    float TraceRadius = 120.0f;
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Pawn;
    TObjectPtr<UHitRegisterTargetingProfile> TargetingProfile = nullptr;
    bool bEnableDebugDraw = true;
    float DebugPersistSeconds = 0.0f;
    FVector2D AimDirectionHint = FVector2D::ZeroVector;
};

