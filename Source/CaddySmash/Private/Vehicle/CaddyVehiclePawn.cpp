#include "Vehicle/CaddyVehiclePawn.h"

#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Debug/CaddyVehicleDebugPanelProvider.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "Engine/CollisionProfile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HAL/IConsoleManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
#include "Vehicle/CaddyVehicleCameraComponent.h"
#include "Vehicle/CaddyVehicleFeelComponent.h"
#include "Vehicle/Abilities/CaddyVehicleBrakeDashAbility.h"
#include "Vehicle/CaddyVehicleSkillConfigDataAsset.h"
#include "Vehicle/CaddyVehicleSkillComponent.h"
#include "Vehicle/CaddyVehicleTuningDataAsset.h"

namespace CaddyInputNames
{
    static const FName MoveX = TEXT("Caddy_MoveX");
    static const FName MoveY = TEXT("Caddy_MoveY");
    static const FName Accelerate = TEXT("Caddy_Accelerate");
    static const FName BrakeReverse = TEXT("Caddy_BrakeReverse");
    static const FName Drift = TEXT("Caddy_Drift");
}

namespace CaddyVehicleTuningConsole
{
    static ACaddyVehiclePawn* FindLocalVehiclePawnInWorld(UWorld* World)
    {
        if (!World)
        {
            return nullptr;
        }

        for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
        {
            const APlayerController* PlayerController = It->Get();
            if (!PlayerController || !PlayerController->IsLocalController())
            {
                continue;
            }

            if (ACaddyVehiclePawn* Pawn = Cast<ACaddyVehiclePawn>(PlayerController->GetPawn()))
            {
                return Pawn;
            }
        }

        return nullptr;
    }

    static ACaddyVehiclePawn* FindLocalVehiclePawn(UWorld* OptionalWorld)
    {
        if (ACaddyVehiclePawn* Pawn = FindLocalVehiclePawnInWorld(OptionalWorld))
        {
            return Pawn;
        }

        if (!GEngine)
        {
            return nullptr;
        }

        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            if (ACaddyVehiclePawn* Pawn = FindLocalVehiclePawnInWorld(Context.World()))
            {
                return Pawn;
            }
        }

        return nullptr;
    }

    static void CyclePreset(const int32 Step)
    {
        ACaddyVehiclePawn* Pawn = FindLocalVehiclePawn(nullptr);
        if (!Pawn)
        {
            UE_LOG(LogTemp, Warning, TEXT("caddy.vehicle.tuning: no local ACaddyVehiclePawn found."));
            return;
        }

        if (!Pawn->CycleRuntimeTuningPreset(Step))
        {
            UE_LOG(LogTemp, Warning, TEXT("caddy.vehicle.tuning: failed to cycle presets."));
            return;
        }

        UE_LOG(
            LogTemp,
            Display,
            TEXT("caddy.vehicle.tuning: preset %d/%d -> %s"),
            Pawn->GetActiveRuntimeTuningPresetIndex(),
            Pawn->GetRuntimeTuningPresetCount(),
            *Pawn->GetActiveRuntimeTuningPresetName());
    }

    static void SetPresetByArgs(const TArray<FString>& Args)
    {
        ACaddyVehiclePawn* Pawn = FindLocalVehiclePawn(nullptr);
        if (!Pawn)
        {
            UE_LOG(LogTemp, Warning, TEXT("caddy.vehicle.tuning: no local ACaddyVehiclePawn found."));
            return;
        }

        if (Args.Num() < 1)
        {
            UE_LOG(LogTemp, Warning, TEXT("Usage: caddy.vehicle.tuning.set <index>"));
            return;
        }

        const int32 TargetIndex = FCString::Atoi(*Args[0]);
        if (!Pawn->ApplyRuntimeTuningPresetByIndex(TargetIndex))
        {
            UE_LOG(LogTemp, Warning, TEXT("caddy.vehicle.tuning: invalid preset index %d."), TargetIndex);
            return;
        }

        UE_LOG(
            LogTemp,
            Display,
            TEXT("caddy.vehicle.tuning: preset %d/%d -> %s"),
            Pawn->GetActiveRuntimeTuningPresetIndex(),
            Pawn->GetRuntimeTuningPresetCount(),
            *Pawn->GetActiveRuntimeTuningPresetName());
    }

    static FAutoConsoleCommand CCmdVehicleTuningNext(
        TEXT("caddy.vehicle.tuning.next"),
        TEXT("Switch to next runtime vehicle tuning preset."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            CyclePreset(1);
        }));

    static FAutoConsoleCommand CCmdVehicleTuningPrev(
        TEXT("caddy.vehicle.tuning.prev"),
        TEXT("Switch to previous runtime vehicle tuning preset."),
        FConsoleCommandDelegate::CreateStatic([]()
        {
            CyclePreset(-1);
        }));

    static FAutoConsoleCommand CCmdVehicleTuningSet(
        TEXT("caddy.vehicle.tuning.set"),
        TEXT("Set runtime vehicle tuning preset by index. Usage: caddy.vehicle.tuning.set <index>"),
        FConsoleCommandWithArgsDelegate::CreateStatic(&SetPresetByArgs));
}

ACaddyVehiclePawn::ACaddyVehiclePawn()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);

    CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitCapsuleSize(50.0f, 35.0f);
    CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
    CollisionComponent->SetSimulatePhysics(false);
    RootComponent = CollisionComponent;

    VehicleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleMeshComponent"));
    VehicleMeshComponent->SetupAttachment(CollisionComponent);
    VehicleMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultVehicleMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (DefaultVehicleMesh.Succeeded())
    {
        VehicleMeshComponent->SetStaticMesh(DefaultVehicleMesh.Object);
        VehicleMeshComponent->SetRelativeScale3D(FVector(1.4f, 0.9f, 0.5f));
        VehicleMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -35.0f));
    }

    CameraBoomComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoomComponent"));
    CameraBoomComponent->SetupAttachment(CollisionComponent);
    CameraBoomComponent->TargetArmLength = 1400.0f;
    CameraBoomComponent->SetRelativeRotation(FRotator(-72.0f, 0.0f, 0.0f));
    CameraBoomComponent->bDoCollisionTest = false;
    CameraBoomComponent->bUsePawnControlRotation = false;
    CameraBoomComponent->SetUsingAbsoluteRotation(true);

    TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCameraComponent"));
    TopDownCameraComponent->SetupAttachment(CameraBoomComponent, USpringArmComponent::SocketName);
    TopDownCameraComponent->bUsePawnControlRotation = false;

    VehicleMovementComponent = CreateDefaultSubobject<UArcadeVehicleMovementComponent>(TEXT("VehicleMovementComponent"));
    VehicleMovementComponent->SetUpdatedComponent(CollisionComponent);

    VehicleFeelComponent = CreateDefaultSubobject<UCaddyVehicleFeelComponent>(TEXT("VehicleFeelComponent"));
    VehicleFeelComponent->BindFeelRig(VehicleMovementComponent, VehicleMeshComponent);

    VehicleSkillComponent = CreateDefaultSubobject<UCaddyVehicleSkillComponent>(TEXT("VehicleSkillComponent"));
    VehicleSkillComponent->BindSkillRig(VehicleMovementComponent);

    VehicleCameraComponent = CreateDefaultSubobject<UCaddyVehicleCameraComponent>(TEXT("VehicleCameraComponent"));
    VehicleCameraComponent->BindCameraRig(VehicleMovementComponent, CameraBoomComponent, TopDownCameraComponent);

    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
}

void ACaddyVehiclePawn::BeginPlay()
{
    Super::BeginPlay();

    if (VehicleFeelComponent)
    {
        VehicleFeelComponent->BindFeelRig(VehicleMovementComponent, VehicleMeshComponent);
    }

    if (VehicleCameraComponent)
    {
        VehicleCameraComponent->BindCameraRig(VehicleMovementComponent, CameraBoomComponent, TopDownCameraComponent);
    }

    if (VehicleSkillComponent)
    {
        VehicleSkillComponent->BindSkillRig(VehicleMovementComponent);
        if (SkillConfigDataAsset)
        {
            VehicleSkillComponent->SetSkillConfig(SkillConfigDataAsset->BrakeDashConfig, false);
        }
    }

    GrantOrRefreshSkillAbility();

    if (RuntimeTuningPresets.Num() > 0)
    {
        const int32 ClampedInitialIndex = FMath::Clamp(ActiveRuntimeTuningPresetIndex, 0, RuntimeTuningPresets.Num() - 1);
        if (!ApplyRuntimeTuningPresetByIndex(ClampedInitialIndex))
        {
            ActiveRuntimeTuningPresetIndex = -1;
        }
    }

    RegisterDebugProviders();
    InitializeEnhancedInputMapping();
}

void ACaddyVehiclePawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    ClearGrantedSkillAbility();

    if (DefaultInputMappingContext)
    {
        if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
        {
            if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
            {
                if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
                {
                    InputSubsystem->RemoveMappingContext(DefaultInputMappingContext);
                }
            }
        }
    }

    UnregisterDebugProviders();
    Super::EndPlay(EndPlayReason);
}

void ACaddyVehiclePawn::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }

    GrantOrRefreshSkillAbility();
    InitializeEnhancedInputMapping();
}

void ACaddyVehiclePawn::OnRep_Controller()
{
    Super::OnRep_Controller();

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }

    InitializeEnhancedInputMapping();
}

void ACaddyVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent);

    bool bEnhancedMoveBound = false;
    bool bEnhancedAccelerateBound = false;
    bool bEnhancedBrakeBound = false;
    bool bEnhancedDriftBound = false;

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (MoveInputAction)
        {
            EnhancedInput->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ACaddyVehiclePawn::InputMoveAction);
            EnhancedInput->BindAction(MoveInputAction, ETriggerEvent::Completed, this, &ACaddyVehiclePawn::InputMoveAction);
            bEnhancedMoveBound = true;
        }

        if (AccelerateInputAction)
        {
            EnhancedInput->BindAction(AccelerateInputAction, ETriggerEvent::Triggered, this, &ACaddyVehiclePawn::InputAccelerateAction);
            EnhancedInput->BindAction(AccelerateInputAction, ETriggerEvent::Completed, this, &ACaddyVehiclePawn::InputAccelerateAction);
            bEnhancedAccelerateBound = true;
        }

        if (BrakeReverseInputAction)
        {
            EnhancedInput->BindAction(BrakeReverseInputAction, ETriggerEvent::Triggered, this, &ACaddyVehiclePawn::InputBrakeReverseAction);
            EnhancedInput->BindAction(BrakeReverseInputAction, ETriggerEvent::Completed, this, &ACaddyVehiclePawn::InputBrakeReverseAction);
            bEnhancedBrakeBound = true;
        }

        if (DriftInputAction)
        {
            EnhancedInput->BindAction(DriftInputAction, ETriggerEvent::Triggered, this, &ACaddyVehiclePawn::InputDriftAction);
            EnhancedInput->BindAction(DriftInputAction, ETriggerEvent::Completed, this, &ACaddyVehiclePawn::InputDriftAction);
            bEnhancedDriftBound = true;
        }

        if (SkillInputAction)
        {
            EnhancedInput->BindAction(SkillInputAction, ETriggerEvent::Started, this, &ACaddyVehiclePawn::InputSkillStartedAction);
            EnhancedInput->BindAction(SkillInputAction, ETriggerEvent::Completed, this, &ACaddyVehiclePawn::InputSkillCompletedAction);
            EnhancedInput->BindAction(SkillInputAction, ETriggerEvent::Canceled, this, &ACaddyVehiclePawn::InputSkillCompletedAction);
        }
    }

    if (!bEnhancedMoveBound)
    {
        PlayerInputComponent->BindAxis(CaddyInputNames::MoveX, this, &ACaddyVehiclePawn::InputMoveX);
        PlayerInputComponent->BindAxis(CaddyInputNames::MoveY, this, &ACaddyVehiclePawn::InputMoveY);
    }

    if (!bEnhancedAccelerateBound)
    {
        PlayerInputComponent->BindAxis(CaddyInputNames::Accelerate, this, &ACaddyVehiclePawn::InputAccelerate);
    }

    if (!bEnhancedBrakeBound)
    {
        PlayerInputComponent->BindAxis(CaddyInputNames::BrakeReverse, this, &ACaddyVehiclePawn::InputBrakeReverse);
    }

    if (!bEnhancedDriftBound)
    {
        PlayerInputComponent->BindAxis(CaddyInputNames::Drift, this, &ACaddyVehiclePawn::InputDrift);
    }
}

UPawnMovementComponent* ACaddyVehiclePawn::GetMovementComponent() const
{
    return VehicleMovementComponent;
}

UAbilitySystemComponent* ACaddyVehiclePawn::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ACaddyVehiclePawn::GrantOrRefreshSkillAbility()
{
    if (!HasAuthority() || !AbilitySystemComponent)
    {
        return;
    }

    if (SkillAbilitySpecHandle.IsValid())
    {
        AbilitySystemComponent->ClearAbility(SkillAbilitySpecHandle);
        SkillAbilitySpecHandle = FGameplayAbilitySpecHandle();
    }

    TSubclassOf<UGameplayAbility> SkillAbilityClass = nullptr;
    if (SkillConfigDataAsset && SkillConfigDataAsset->SkillAbilityClass)
    {
        SkillAbilityClass = SkillConfigDataAsset->SkillAbilityClass;
    }

    if (!SkillAbilityClass)
    {
        SkillAbilityClass = UCaddyVehicleBrakeDashAbility::StaticClass();
    }

    if (!SkillAbilityClass)
    {
        return;
    }

    FGameplayAbilitySpec SkillSpec(SkillAbilityClass, 1, INDEX_NONE, this);
    SkillAbilitySpecHandle = AbilitySystemComponent->GiveAbility(SkillSpec);
}

void ACaddyVehiclePawn::ClearGrantedSkillAbility()
{
    if (!HasAuthority() || !AbilitySystemComponent || !SkillAbilitySpecHandle.IsValid())
    {
        return;
    }

    AbilitySystemComponent->ClearAbility(SkillAbilitySpecHandle);
    SkillAbilitySpecHandle = FGameplayAbilitySpecHandle();
}

bool ACaddyVehiclePawn::TryActivateSkillAbility()
{
    if (!AbilitySystemComponent || !VehicleSkillComponent || !VehicleSkillComponent->bUseGASAbilityStateMachine)
    {
        return false;
    }

    if (SkillAbilitySpecHandle.IsValid())
    {
        return AbilitySystemComponent->TryActivateAbility(SkillAbilitySpecHandle, false);
    }

    TSubclassOf<UGameplayAbility> SkillAbilityClass = nullptr;
    if (SkillConfigDataAsset && SkillConfigDataAsset->SkillAbilityClass)
    {
        SkillAbilityClass = SkillConfigDataAsset->SkillAbilityClass;
    }
    if (!SkillAbilityClass)
    {
        SkillAbilityClass = UCaddyVehicleBrakeDashAbility::StaticClass();
    }

    return SkillAbilityClass ? AbilitySystemComponent->TryActivateAbilityByClass(SkillAbilityClass, false) : false;
}

bool ACaddyVehiclePawn::IsSkillComboTriggerHeld() const
{
    if (!VehicleSkillComponent || !VehicleMovementComponent)
    {
        return false;
    }

    if (VehicleSkillComponent->BrakeDashConfig.TriggerMode != ECaddyVehicleSkillTriggerMode::BrakeThrottleCombo)
    {
        return false;
    }

    return VehicleMovementComponent->GetThrottleInput() >= VehicleSkillComponent->BrakeDashConfig.TriggerThrottleThreshold
        && VehicleMovementComponent->GetBrakeReverseInput() >= VehicleSkillComponent->BrakeDashConfig.TriggerBrakeThreshold;
}

void ACaddyVehiclePawn::SetMoveIntentInput(const FVector2D& InMoveIntentInput)
{
    if (!VehicleMovementComponent)
    {
        return;
    }

    const FVector2D WorldIntent = ComputeWorldMoveIntent(InMoveIntentInput);
    VehicleMovementComponent->SetMoveIntent(WorldIntent);

    if (!HasAuthority())
    {
        ServerSetMoveIntent(WorldIntent);
    }
}

void ACaddyVehiclePawn::SetThrottleInput(float InThrottle)
{
    if (!VehicleMovementComponent)
    {
        return;
    }

    VehicleMovementComponent->SetThrottleInput(InThrottle);
    if (IsSkillComboTriggerHeld())
    {
        TryActivateSkillAbility();
    }

    if (!HasAuthority())
    {
        ServerSetThrottleInput(InThrottle);
    }
}

void ACaddyVehiclePawn::SetDriftInput(float InDrift)
{
    if (!VehicleMovementComponent)
    {
        return;
    }

    VehicleMovementComponent->SetDriftInput(InDrift);
    if (!HasAuthority())
    {
        ServerSetDriftInput(InDrift);
    }
}

void ACaddyVehiclePawn::SetBrakeReverseInput(float InBrakeReverse)
{
    if (!VehicleMovementComponent)
    {
        return;
    }

    VehicleMovementComponent->SetBrakeReverseInput(InBrakeReverse);
    if (IsSkillComboTriggerHeld())
    {
        TryActivateSkillAbility();
    }

    if (!HasAuthority())
    {
        ServerSetBrakeReverseInput(InBrakeReverse);
    }
}

bool ACaddyVehiclePawn::ApplyRuntimeTuningPresetByIndex(int32 InIndex)
{
    if (!VehicleMovementComponent || !RuntimeTuningPresets.IsValidIndex(InIndex))
    {
        return false;
    }

    UCaddyVehicleTuningDataAsset* TargetPreset = RuntimeTuningPresets[InIndex];
    if (!TargetPreset)
    {
        return false;
    }

    VehicleMovementComponent->SetTuningDataAsset(TargetPreset, true);
    if (VehicleCameraComponent)
    {
        VehicleCameraComponent->SetCameraConfig(TargetPreset->CameraConfig, false);
    }
    if (VehicleFeelComponent)
    {
        VehicleFeelComponent->SetFeelConfig(TargetPreset->FeelConfig, false);
    }
    ActiveRuntimeTuningPresetIndex = InIndex;

    if (!HasAuthority())
    {
        ServerApplyRuntimeTuningPresetByIndex(InIndex);
    }

    return true;
}

bool ACaddyVehiclePawn::CycleRuntimeTuningPreset(int32 Step)
{
    if (RuntimeTuningPresets.Num() == 0)
    {
        return false;
    }

    const int32 NormalizedStep = (Step == 0) ? 1 : Step;
    int32 CurrentIndex = ActiveRuntimeTuningPresetIndex;
    if (!RuntimeTuningPresets.IsValidIndex(CurrentIndex))
    {
        CurrentIndex = 0;
    }

    int32 NextIndex = (CurrentIndex + NormalizedStep) % RuntimeTuningPresets.Num();
    if (NextIndex < 0)
    {
        NextIndex += RuntimeTuningPresets.Num();
    }

    return ApplyRuntimeTuningPresetByIndex(NextIndex);
}

FString ACaddyVehiclePawn::GetActiveRuntimeTuningPresetName() const
{
    if (!RuntimeTuningPresets.IsValidIndex(ActiveRuntimeTuningPresetIndex))
    {
        return TEXT("None");
    }

    const UCaddyVehicleTuningDataAsset* Preset = RuntimeTuningPresets[ActiveRuntimeTuningPresetIndex];
    return Preset ? Preset->GetName() : TEXT("None");
}

void ACaddyVehiclePawn::ServerSetMoveIntent_Implementation(FVector2D InMoveIntent)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetMoveIntent(InMoveIntent);
    }
}

void ACaddyVehiclePawn::ServerSetThrottleInput_Implementation(float InThrottle)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetThrottleInput(InThrottle);
        if (IsSkillComboTriggerHeld())
        {
            TryActivateSkillAbility();
        }
    }
}

void ACaddyVehiclePawn::ServerSetDriftInput_Implementation(float InDrift)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetDriftInput(InDrift);
    }
}

void ACaddyVehiclePawn::ServerSetSkillInputPressed_Implementation(bool bPressed)
{
    if (VehicleSkillComponent)
    {
        VehicleSkillComponent->SetSkillInputPressed(bPressed);
        if (bPressed)
        {
            TryActivateSkillAbility();
        }
    }
}

void ACaddyVehiclePawn::ServerSetBrakeReverseInput_Implementation(float InBrakeReverse)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetBrakeReverseInput(InBrakeReverse);
        if (IsSkillComboTriggerHeld())
        {
            TryActivateSkillAbility();
        }
    }
}

void ACaddyVehiclePawn::ServerApplyRuntimeTuningPresetByIndex_Implementation(int32 InIndex)
{
    ApplyRuntimeTuningPresetByIndex(InIndex);
}

void ACaddyVehiclePawn::InputMoveX(float Value)
{
    RawMoveInput.X = FMath::Clamp(Value, -1.0f, 1.0f);
    SetMoveIntentInput(RawMoveInput);
}

void ACaddyVehiclePawn::InputMoveY(float Value)
{
    RawMoveInput.Y = FMath::Clamp(Value, -1.0f, 1.0f);
    SetMoveIntentInput(RawMoveInput);
}

void ACaddyVehiclePawn::InputAccelerate(float Value)
{
    SetThrottleInput(FMath::Clamp(Value, 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputBrakeReverse(float Value)
{
    SetBrakeReverseInput(FMath::Clamp(Value, 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputDrift(float Value)
{
    SetDriftInput(FMath::Clamp(Value, 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputMoveAction(const FInputActionValue& Value)
{
    const FVector2D MoveValue = Value.Get<FVector2D>();
    RawMoveInput = FVector2D(
        FMath::Clamp(MoveValue.X, -1.0f, 1.0f),
        FMath::Clamp(MoveValue.Y, -1.0f, 1.0f));
    SetMoveIntentInput(RawMoveInput);
}

void ACaddyVehiclePawn::InputAccelerateAction(const FInputActionValue& Value)
{
    SetThrottleInput(FMath::Clamp(Value.Get<float>(), 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputBrakeReverseAction(const FInputActionValue& Value)
{
    SetBrakeReverseInput(FMath::Clamp(Value.Get<float>(), 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputDriftAction(const FInputActionValue& Value)
{
    SetDriftInput(FMath::Clamp(Value.Get<float>(), 0.0f, 1.0f));
}

void ACaddyVehiclePawn::InputSkillStartedAction(const FInputActionValue& Value)
{
    (void)Value;
    if (VehicleSkillComponent)
    {
        VehicleSkillComponent->SetSkillInputPressed(true);
        TryActivateSkillAbility();
        if (!HasAuthority())
        {
            ServerSetSkillInputPressed(true);
        }
    }
}

void ACaddyVehiclePawn::InputSkillCompletedAction(const FInputActionValue& Value)
{
    (void)Value;
    if (VehicleSkillComponent)
    {
        VehicleSkillComponent->SetSkillInputPressed(false);
        if (!HasAuthority())
        {
            ServerSetSkillInputPressed(false);
        }
    }
}

void ACaddyVehiclePawn::InitializeEnhancedInputMapping()
{
    APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (!PlayerController || !PlayerController->IsLocalController() || !DefaultInputMappingContext)
    {
        return;
    }

    ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
    if (!LocalPlayer)
    {
        return;
    }

    UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    if (!InputSubsystem)
    {
        return;
    }

    InputSubsystem->RemoveMappingContext(DefaultInputMappingContext);
    InputSubsystem->AddMappingContext(DefaultInputMappingContext, InputMappingPriority);
}

FVector2D ACaddyVehiclePawn::ComputeWorldMoveIntent(const FVector2D& InRawMoveInput) const
{
    if (InRawMoveInput.IsNearlyZero())
    {
        return FVector2D::ZeroVector;
    }

    // Move intent follows camera yaw so keyboard and gamepad match the top-down view.
    const float CameraYaw = TopDownCameraComponent ? TopDownCameraComponent->GetComponentRotation().Yaw : 0.0f;
    const FRotator YawRot(0.0f, CameraYaw, 0.0f);
    const FVector WorldForward = YawRot.RotateVector(FVector::ForwardVector);
    const FVector WorldRight = YawRot.RotateVector(FVector::RightVector);
    const FVector WorldDir = (WorldForward * InRawMoveInput.Y) + (WorldRight * InRawMoveInput.X);
    return FVector2D(WorldDir.X, WorldDir.Y).GetSafeNormal();
}

void ACaddyVehiclePawn::RegisterDebugProviders()
{
    if (!bEnableVehicleDebugPanels || DebugPanelProviders.Num() > 0)
    {
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    UDebugFrameworkSubsystem* DebugSubsystem = World->GetSubsystem<UDebugFrameworkSubsystem>();
    if (!DebugSubsystem)
    {
        return;
    }

    auto AddProvider = [this, DebugSubsystem](
        const FName PanelId,
        const FText& PanelTitle,
        const int32 SortOrder,
        const ECaddyVehicleDebugPanelType PanelType)
    {
        UCaddyVehicleDebugPanelProvider* Provider = NewObject<UCaddyVehicleDebugPanelProvider>(this);
        if (!Provider)
        {
            return;
        }

        Provider->Initialize(
            this,
            PanelId,
            PanelTitle,
            TEXT("Vehicle"),
            NSLOCTEXT("CaddyVehicleDebug", "VehicleToolTitle", "Vehicle"),
            SortOrder,
            PanelType);

        DebugPanelProviders.Add(Provider);
        DebugSubsystem->RegisterProvider(Provider);
    };

    AddProvider(TEXT("Vehicle.Core"), NSLOCTEXT("CaddyVehicleDebug", "CorePanelTitle", "Core"), 10, ECaddyVehicleDebugPanelType::Core);
    AddProvider(TEXT("Vehicle.Input"), NSLOCTEXT("CaddyVehicleDebug", "InputPanelTitle", "Input"), 20, ECaddyVehicleDebugPanelType::Input);
    AddProvider(TEXT("Vehicle.Tuning"), NSLOCTEXT("CaddyVehicleDebug", "TuningPanelTitle", "Tuning"), 30, ECaddyVehicleDebugPanelType::Tuning);
    AddProvider(TEXT("Vehicle.Feel"), NSLOCTEXT("CaddyVehicleDebug", "FeelPanelTitle", "Feel"), 40, ECaddyVehicleDebugPanelType::Feel);
    AddProvider(TEXT("Vehicle.Skill"), NSLOCTEXT("CaddyVehicleDebug", "SkillPanelTitle", "Skill"), 50, ECaddyVehicleDebugPanelType::Skill);
    AddProvider(TEXT("Vehicle.Camera"), NSLOCTEXT("CaddyVehicleDebug", "CameraPanelTitle", "Camera"), 60, ECaddyVehicleDebugPanelType::Camera);
    AddProvider(TEXT("Vehicle.Collision"), NSLOCTEXT("CaddyVehicleDebug", "CollisionPanelTitle", "Collision"), 70, ECaddyVehicleDebugPanelType::Collision);
    AddProvider(TEXT("Vehicle.DebugDraw"), NSLOCTEXT("CaddyVehicleDebug", "DebugDrawPanelTitle", "Debug Draw"), 80, ECaddyVehicleDebugPanelType::DebugDraw);
}

void ACaddyVehiclePawn::UnregisterDebugProviders()
{
    UWorld* World = GetWorld();
    UDebugFrameworkSubsystem* DebugSubsystem = World ? World->GetSubsystem<UDebugFrameworkSubsystem>() : nullptr;

    if (DebugSubsystem)
    {
        for (UCaddyVehicleDebugPanelProvider* Provider : DebugPanelProviders)
        {
            if (Provider)
            {
                DebugSubsystem->UnregisterProvider(Provider);
            }
        }
    }

    DebugPanelProviders.Reset();
}
