#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/HitResult.h"
#include "HitRegisterCollisionTypes.generated.h"

class UHitRegisterHitBoxComponent;
class UHitRegisterHurtBoxComponent;

UENUM(BlueprintType)
enum class EHitRegisterHitBoxMode : uint8
{
    WindowSweep,
    ContinuousOverlap,
    Disabled
};

UENUM(BlueprintType)
enum class EHitRegisterDedupePolicy : uint8
{
    None,
    OncePerAttack,
    CooldownPerTarget,
    CooldownPerHurtBox
};

USTRUCT(BlueprintType)
struct HITREGISTERCOLLISION_API FHitRegisterDedupeSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    EHitRegisterDedupePolicy Policy = EHitRegisterDedupePolicy::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float CooldownSeconds = 0.f;
};

USTRUCT(BlueprintType)
struct HITREGISTERCOLLISION_API FHitCandidate
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<AActor> TargetActor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<UPrimitiveComponent> TargetComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<UHitRegisterHitBoxComponent> HitBox = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<UHitRegisterHurtBoxComponent> HurtBox = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FHitResult Hit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FGameplayTagContainer Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    int32 AttackId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float Timestamp = 0.f;
};

USTRUCT(BlueprintType)
struct HITREGISTERCOLLISION_API FHitCandidateBatch
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TArray<FHitCandidate> Candidates;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TArray<FHitCandidate> Rejected;
};

USTRUCT()
struct HITREGISTERCOLLISION_API FHitDedupeKey
{
    GENERATED_BODY()

    UPROPERTY()
    int32 AttackId = 0;

    UPROPERTY()
    TWeakObjectPtr<AActor> Instigator;

    UPROPERTY()
    TWeakObjectPtr<AActor> TargetActor;

    UPROPERTY()
    TWeakObjectPtr<UPrimitiveComponent> HurtComponent;

    bool operator==(const FHitDedupeKey& Other) const
    {
        return AttackId == Other.AttackId
            && Instigator == Other.Instigator
            && TargetActor == Other.TargetActor
            && HurtComponent == Other.HurtComponent;
    }
};

FORCEINLINE uint32 GetTypeHash(const FHitDedupeKey& Key)
{
    const uint32 A = ::GetTypeHash(Key.AttackId);
    const uint32 B = ::PointerHash(Key.Instigator.Get());
    const uint32 C = ::PointerHash(Key.TargetActor.Get());
    const uint32 D = ::PointerHash(Key.HurtComponent.Get());
    return HashCombine(HashCombine(HashCombine(A, B), C), D);
}

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHitCandidatesEvent, const FHitCandidateBatch&, Batch);
