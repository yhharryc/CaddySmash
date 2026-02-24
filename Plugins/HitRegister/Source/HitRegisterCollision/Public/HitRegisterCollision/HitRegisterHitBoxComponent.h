#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "HitRegisterCollisionTypes.h"
#include "HitRegisterTargetingProfile.h"
#include "HitRegisterHitBoxComponent.generated.h"

UCLASS(ClassGroup=(HitRegister), meta=(BlueprintSpawnableComponent))
class HITREGISTERCOLLISION_API UHitRegisterHitBoxComponent : public UBoxComponent
{
    GENERATED_BODY()

public:
    UHitRegisterHitBoxComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    EHitRegisterHitBoxMode Mode = EHitRegisterHitBoxMode::ContinuousOverlap;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    float QueryInterval = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Pawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FGameplayTagContainer Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    FName HitBoxId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    TObjectPtr<UHitRegisterTargetingProfile> TargetingProfile = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitRegister")
    bool bIgnoreOwner = true;

    UPROPERTY(BlueprintReadOnly, Category="HitRegister")
    bool bActive = false;

    UPROPERTY(BlueprintAssignable, Category="HitRegister|Events")
    FHitCandidatesEvent OnCandidatesGenerated;

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void BeginHitWindow(int32 AttackId);

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void EndHitWindow();

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void StartContinuous(int32 AttackId);

    UFUNCTION(BlueprintCallable, Category="HitRegister")
    void StopContinuous();

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void GenerateSweepCandidates();
    void GenerateOverlapCandidates();
    void EmitCandidates(const TArray<FHitResult>& Hits);

    int32 ActiveAttackId = 0;
    float LastQueryTime = 0.f;
    FTransform LastSweepTransform;
};
