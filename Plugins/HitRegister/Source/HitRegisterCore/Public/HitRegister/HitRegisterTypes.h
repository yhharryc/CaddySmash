#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HitRegisterTypes.generated.h"

UENUM(BlueprintType)
enum class EHitRegisterStopReason : uint8
{
    None,
    Missed,
    InvalidHit,
    ReceiverRejected,
    NoDamageable,
    StoppedByNode
};

UENUM(BlueprintType)
enum class EHitNodeResult : uint8
{
    Continue,
    Stop
};

USTRUCT(BlueprintType)
struct HITREGISTERCORE_API FAttackRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<AActor> Instigator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<UObject> SourceObject = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float BaseDamage = 10.f;

    /** Optional: attribute snapshot for this attack. Keys are gameplay tags (e.g., Attr.Strength) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TMap<FGameplayTag, float> Attributes;

    /** Optional: tags for damage types / routing */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FGameplayTagContainer Tags;
};

USTRUCT(BlueprintType)
struct HITREGISTERCORE_API FDamagePacket
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float RawDamage = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float MitigatedDamage = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float FinalDamage = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bIsCrit = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bIsWeakPoint = false;
};

USTRUCT(BlueprintType)
struct HITREGISTERCORE_API FDamageResult
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float AppliedToShield = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float AppliedToHealth = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bKilled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    EHitRegisterStopReason StopReason = EHitRegisterStopReason::None;
};

USTRUCT(BlueprintType)
struct HITREGISTERCORE_API FHitRegisterContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FAttackRequest Attack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FHitResult Hit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FDamagePacket Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FDamageResult Result;
};
