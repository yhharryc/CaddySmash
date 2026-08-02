#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AttackTypes.h"
#include "Combat/WeaponExecutor.h"
#include "CombatWeaponActor.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UAttackProfile;

UENUM(BlueprintType)
enum class EWeaponMotionType : uint8
{
    None,
    Thrust
};

UCLASS(BlueprintType)
class COMBATCORE_API ACombatWeaponActor : public AActor, public IWeaponExecutor
{
    GENERATED_BODY()

public:
    ACombatWeaponActor();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<USceneComponent> Root = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<USceneComponent> AimRoot = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<USceneComponent> MotionRoot = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
    TObjectPtr<USceneComponent> Tip = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bAttachToOwnerOnBeginPlay = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    FName AttachSocketName = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    EWeaponMotionType MotionType = EWeaponMotionType::Thrust;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool bAutoPlayMotionOnExecute = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    bool bMaintainAimAtTarget = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    bool bAimYawOnly = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    float AimYawOffset = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    float AimInterpSpeed = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    bool bDrawAimDebug = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Aim")
    float AimDebugLength = 120.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Motion")
    float ThrustDistance = 60.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Motion")
    float ThrustDuration = 0.08f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Motion")
    float ReturnDuration = 0.08f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Motion")
    FVector ThrustAxis = FVector::ForwardVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Attack")
    TObjectPtr<UAttackProfile> DefaultAttackProfile = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Attack")
    bool bAutoClearContextOnMotionEnd = false;

    UFUNCTION(BlueprintCallable, Category="Combat|Motion")
    void StartMotion();

    UFUNCTION(BlueprintCallable, Category="Combat|Motion")
    void StopMotion();

    UFUNCTION(BlueprintPure, Category="Combat|Motion")
    bool IsMotionActive() const;

    UFUNCTION(BlueprintCallable, Category="Combat|Aim")
    void AimAtActor(AActor* Target, bool bSnap = true);

    UFUNCTION(BlueprintCallable, Category="Combat|Aim")
    void ClearAimTarget();

    UFUNCTION(BlueprintImplementableEvent, Category="Combat")
    void OnExecuteAttack(const FCombatAttackContext& Context);

    UFUNCTION(BlueprintImplementableEvent, Category="Combat|Motion")
    void OnMotionStarted();

    UFUNCTION(BlueprintImplementableEvent, Category="Combat|Motion")
    void OnMotionEnded();

    UFUNCTION(BlueprintCallable, Category="Combat|Attack")
    bool GetCachedAttackContext(FCombatAttackContext& OutContext) const;

    UFUNCTION(BlueprintCallable, Category="Combat|Attack")
    void ClearCachedAttackContext();

    UFUNCTION(BlueprintPure, Category="Combat|Attack")
    bool HasCachedAttackContext() const { return bHasCachedContext; }

    virtual bool CanExecuteAttack_Implementation(FCombatAttackContext& Context) override { return true; }
    virtual void ExecuteAttack_Implementation(FCombatAttackContext& Context) override;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void HandleMotionEnded();

private:
    enum class EMotionPhase : uint8 { None, Out, Return };

    EMotionPhase MotionPhase = EMotionPhase::None;
    float MotionTime = 0.f;
    float ActiveThrustDistance = -1.f;
    FVector MotionBaseLocation = FVector::ZeroVector;
    FRotator BaseAimRotation = FRotator::ZeroRotator;
    TWeakObjectPtr<AActor> AimTarget;
    bool bPendingAimInterp = false;
    bool bHasCachedContext = false;

    UPROPERTY(Transient)
    FCombatAttackContext CachedContext;

    void UpdateMotion(float DeltaSeconds);
    void UpdateAim(float DeltaSeconds);
    bool ApplyAim(const FVector& TargetLocation, float DeltaSeconds, bool bSnap);
    void UpdateTickEnabled();
    float GetMotionThrustDistance() const;

    void CacheAttackContext(const FCombatAttackContext& Context);
};
