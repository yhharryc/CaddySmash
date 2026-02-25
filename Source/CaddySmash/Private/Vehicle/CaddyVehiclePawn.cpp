#include "Vehicle/CaddyVehiclePawn.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Debug/CaddyVehicleDebugPanelProvider.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "Engine/CollisionProfile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HAL/IConsoleManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Vehicle/ArcadeVehicleMovementComponent.h"
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

    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
}

void ACaddyVehiclePawn::BeginPlay()
{
    Super::BeginPlay();

    if (RuntimeTuningPresets.Num() > 0)
    {
        const int32 ClampedInitialIndex = FMath::Clamp(ActiveRuntimeTuningPresetIndex, 0, RuntimeTuningPresets.Num() - 1);
        if (!ApplyRuntimeTuningPresetByIndex(ClampedInitialIndex))
        {
            ActiveRuntimeTuningPresetIndex = -1;
        }
    }

    RegisterDebugProviders();
}

void ACaddyVehiclePawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
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
}

void ACaddyVehiclePawn::OnRep_Controller()
{
    Super::OnRep_Controller();

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}

void ACaddyVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis(CaddyInputNames::MoveX, this, &ACaddyVehiclePawn::InputMoveX);
    PlayerInputComponent->BindAxis(CaddyInputNames::MoveY, this, &ACaddyVehiclePawn::InputMoveY);
    PlayerInputComponent->BindAxis(CaddyInputNames::Accelerate, this, &ACaddyVehiclePawn::InputAccelerate);
    PlayerInputComponent->BindAxis(CaddyInputNames::BrakeReverse, this, &ACaddyVehiclePawn::InputBrakeReverse);
    PlayerInputComponent->BindAxis(CaddyInputNames::Drift, this, &ACaddyVehiclePawn::InputDrift);
}

UPawnMovementComponent* ACaddyVehiclePawn::GetMovementComponent() const
{
    return VehicleMovementComponent;
}

UAbilitySystemComponent* ACaddyVehiclePawn::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
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
    }
}

void ACaddyVehiclePawn::ServerSetDriftInput_Implementation(float InDrift)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetDriftInput(InDrift);
    }
}

void ACaddyVehiclePawn::ServerSetBrakeReverseInput_Implementation(float InBrakeReverse)
{
    if (VehicleMovementComponent)
    {
        VehicleMovementComponent->SetBrakeReverseInput(InBrakeReverse);
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
    AddProvider(TEXT("Vehicle.Collision"), NSLOCTEXT("CaddyVehicleDebug", "CollisionPanelTitle", "Collision"), 40, ECaddyVehicleDebugPanelType::Collision);
    AddProvider(TEXT("Vehicle.DebugDraw"), NSLOCTEXT("CaddyVehicleDebug", "DebugDrawPanelTitle", "Debug Draw"), 50, ECaddyVehicleDebugPanelType::DebugDraw);
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
