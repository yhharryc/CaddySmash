#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "GameFramework/Pawn.h"
#include "CaddyVehiclePawn.generated.h"

class UAbilitySystemComponent;
class UGameplayAbility;
class UCaddyVehicleCameraComponent;
class UCaddyVehicleAttributeSet;
class UCaddyVehicleFeelComponent;
class UCaddyVehicleHitRegisterDamageableComponent;
class UCaddyVehicleSkillComponent;
class UArcadeVehicleMovementComponent;
class UCaddyVehicleDebugPanelProvider;
class UCaddyVehicleSkillConfigDataAsset;
class UCaddyVehicleTuningDataAsset;
class UCameraComponent;
class UCapsuleComponent;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UStaticMeshComponent;
struct FInputActionValue;

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

    UFUNCTION(BlueprintPure, Category="Vehicle|Components")
    UCaddyVehicleCameraComponent* GetVehicleCameraComponent() const { return VehicleCameraComponent; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Components")
    UCaddyVehicleFeelComponent* GetVehicleFeelComponent() const { return VehicleFeelComponent; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Components")
    UCaddyVehicleSkillComponent* GetVehicleSkillComponent() const { return VehicleSkillComponent; }

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

    UFUNCTION(BlueprintPure, Category="Vehicle|Skill")
    UCaddyVehicleSkillConfigDataAsset* GetSkillConfigDataAsset() const { return SkillConfigDataAsset; }

    UFUNCTION(BlueprintPure, Category="Vehicle|Attributes")
    float GetVehicleHealth() const;

    UFUNCTION(BlueprintPure, Category="Vehicle|Attributes")
    float GetVehicleMaxHealth() const;

    UFUNCTION(BlueprintPure, Category="Vehicle|Attributes")
    float GetVehicleKnockbackResistance() const;

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

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCaddyVehicleCameraComponent> VehicleCameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCaddyVehicleFeelComponent> VehicleFeelComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCaddyVehicleSkillComponent> VehicleSkillComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Components")
    TObjectPtr<UCaddyVehicleHitRegisterDamageableComponent> VehicleDamageableComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Ability")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Vehicle|Ability")
    TObjectPtr<UCaddyVehicleAttributeSet> VehicleAttributeSet;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Attributes", meta=(ClampMin="1.0"))
    float DefaultMaxHealth = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Attributes", meta=(ClampMin="0.0", ClampMax="0.95"))
    float DefaultKnockbackResistance = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle|Debug")
    bool bEnableVehicleDebugPanels = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config")
    TArray<TObjectPtr<UCaddyVehicleTuningDataAsset>> RuntimeTuningPresets;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Config", meta=(ClampMin="-1"))
    int32 ActiveRuntimeTuningPresetIndex = -1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Skill")
    TObjectPtr<UCaddyVehicleSkillConfigDataAsset> SkillConfigDataAsset = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle|Ability")
    TSubclassOf<UGameplayAbility> KnockbackAbilityClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputMappingContext> DefaultInputMappingContext = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced", meta=(ClampMin="0"))
    int32 InputMappingPriority = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputAction> MoveInputAction = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputAction> AccelerateInputAction = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputAction> BrakeReverseInputAction = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputAction> DriftInputAction = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle|Input|Enhanced")
    TObjectPtr<UInputAction> SkillInputAction = nullptr;

private:
    void GrantOrRefreshSkillAbility();
    void ClearGrantedSkillAbility();
    void GrantOrRefreshKnockbackAbility();
    void ClearGrantedKnockbackAbility();
    void InitializeVehicleAttributes();
    bool TryActivateSkillAbility();
    bool IsSkillComboTriggerHeld() const;

    UFUNCTION(Server, Unreliable)
    void ServerSetMoveIntent(FVector2D InMoveIntent);

    UFUNCTION(Server, Unreliable)
    void ServerSetThrottleInput(float InThrottle);

    UFUNCTION(Server, Unreliable)
    void ServerSetBrakeReverseInput(float InBrakeReverse);

    UFUNCTION(Server, Unreliable)
    void ServerSetDriftInput(float InDrift);

    UFUNCTION(Server, Unreliable)
    void ServerSetSkillInputPressed(bool bPressed);

    UFUNCTION(Server, Reliable)
    void ServerApplyRuntimeTuningPresetByIndex(int32 InIndex);

    void InputMoveX(float Value);
    void InputMoveY(float Value);
    void InputAccelerate(float Value);
    void InputBrakeReverse(float Value);
    void InputDrift(float Value);
    void InputMoveAction(const FInputActionValue& Value);
    void InputAccelerateAction(const FInputActionValue& Value);
    void InputBrakeReverseAction(const FInputActionValue& Value);
    void InputDriftAction(const FInputActionValue& Value);
    void InputSkillStartedAction(const FInputActionValue& Value);
    void InputSkillCompletedAction(const FInputActionValue& Value);
    void InitializeEnhancedInputMapping();
    FVector2D ComputeWorldMoveIntent(const FVector2D& InRawMoveInput) const;
    void RegisterDebugProviders();
    void UnregisterDebugProviders();

    FVector2D RawMoveInput = FVector2D::ZeroVector;

    FGameplayAbilitySpecHandle SkillAbilitySpecHandle;
    FGameplayAbilitySpecHandle KnockbackAbilitySpecHandle;

    UPROPERTY(Transient)
    TArray<TObjectPtr<UCaddyVehicleDebugPanelProvider>> DebugPanelProviders;
};
