#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SquadTypes.generated.h"

UENUM(BlueprintType)
enum class ELootPolicy : uint8
{
    Never,
    OnlySafe,
    Interruptible
};

USTRUCT(BlueprintType)
struct SQUADCORE_API FSquadSlot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    FVector Offset = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    FName SlotId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    FGameplayTag RoleTag;
};

USTRUCT(BlueprintType)
struct SQUADCORE_API FThreatCandidate
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<AActor> Target = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float Score = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    FGameplayTagContainer Tags;
};

USTRUCT(BlueprintType)
struct SQUADCORE_API FLootCandidate
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    TObjectPtr<AActor> LootActor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float Score = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    FGameplayTagContainer Tags;
};

USTRUCT(BlueprintType)
struct SQUADCORE_API FSquadComplianceContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float PressureValue = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float HealthRatio = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    float DistanceToLeader = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Squad")
    bool bInCombat = false;
};
