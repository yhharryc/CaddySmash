#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Pawn.h"
#include "CaddyVehiclePawn.generated.h"

class UAbilitySystemComponent;
class UArcadeVehicleMovementComponent;
class UCaddyVehicleDebugPanelProvider;
class UCaddyVehicleTuningDataAsset;
class UCameraComponent;
class UCapsuleComponent;
class USpringArmComponent;
class UStaticMeshComponent;

UCLASS()
class CADDYSMASH_API ACaddyVehiclePawn : public APawn, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    ACaddyVehiclePawn();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void PossessedBy(AController* NewController) override;
    virtual void OnRep_Controller() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual UPawnMovementComponent* GetMovementComponent() const override;
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetMoveIntentInput(const FVector2D& InMoveIntentInput);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetThrottleInput(float InThrottle);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetBrakeReverseInput(float InBrakeReverse);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Input")
    void SetDriftInput(float InDrift);

    UFUNCTION(BlueprintPure, Category="Vehicle|Input")
    FVector2D GetRawMoveInput() const { return RawMoveInput; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Components")
    UArcadeVehicleMovementComponent* GetVehicleMovementComponent() const { return VehicleMovementComponent; }

    UFUNCTION(BlueprintCallable, Category="Vehicle|Config")
    bool ApplyRuntimeTuningPresetByIndex(int32 InIndex);

    UFUNCTION(BlueprintCallable, Category="Vehicle|Config")
    bool CycleRuntimeTuningPreset(int32 Step = 1);

    UFUNCTION(BlueprintPure, Category="Vehicle|Config")
    int32 GetRuntimeTuningPresetCount() const { return RuntimeTuningPresets.Num(); }

    UFUNCTION(BlueprintPure, Category="Vehicle|Config")
    int32 GetActiveRuntimeTuningPresetIndex() const { return ActiveRuntimeTuningPresetIndex; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Config")
    FString GetActiveRuntimeTuningPresetName() const;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCapsuleComponent> CollisionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UStaticMeshComponent> VehicleMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<USpringArmComponent> CameraBoomComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCameraComponent> TopDownCameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UArcadeVehicleMovementComponent> VehicleMovementComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Ability")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug")
    bool bEnableVehicleDebugPanels = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config")
    TArray<TObjectPtr<UCaddyVehicleTuningDataAsset>> RuntimeTuningPresets;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config", meta=(ClampMin="-1"))
    int32 ActiveRuntimeTuningPresetIndex = -1;

private:
    UFUNCTION(Server, Unreliable)
    void ServerSetMoveIntent(FVector2D InMoveIntent);

    UFUNCTION(Server, Unreliable)
    void ServerSetThrottleInput(float InThrottle);

    UFUNCTION(Server, Unreliable)
    void ServerSetBrakeReverseInput(float InBrakeReverse);

    UFUNCTION(Server, Unreliable)
    void ServerSetDriftInput(float InDrift);

    UFUNCTION(Server, Reliable)
    void ServerApplyRuntimeTuningPresetByIndex(int32 InIndex);

    void InputMoveX(float Value);
    void InputMoveY(float Value);
    void InputAccelerate(float Value);
    void InputBrakeReverse(float Value);
    void InputDrift(float Value);
    FVector2D ComputeWorldMoveIntent(const FVector2D& InRawMoveInput) const;
    void RegisterDebugProviders();
    void UnregisterDebugProviders();

    FVector2D RawMoveInput = FVector2D::ZeroVector;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UCaddyVehicleDebugPanelProvider>> DebugPanelProviders;
};
