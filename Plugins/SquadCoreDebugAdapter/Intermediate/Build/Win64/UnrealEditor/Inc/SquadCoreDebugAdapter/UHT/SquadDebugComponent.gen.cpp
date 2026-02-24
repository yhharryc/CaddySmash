// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadDebugComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadDebugComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkProvider_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugComponent();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugComponent_NoRegister();
SQUADCOREDEBUGADAPTER_API UScriptStruct* Z_Construct_UScriptStruct_FSquadDebugSnapshot();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_SquadCoreDebugAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSquadDebugSnapshot ***********************************************
struct Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSquadDebugSnapshot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSquadDebugSnapshot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugLastTask_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotId_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotWorldPos_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldObeyFormation_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTemporarilyOutOfFormation_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureValue_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BestTarget_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatCount_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootScore_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootActor_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackProfile_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggressionRange_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInAttackRange_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInAggressionRange_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextAttackTime_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownRemaining_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceToLeader_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceToTarget_MetaData[] = {
		{ "Category", "SquadDebugSnapshot" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSquadDebugSnapshot constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DebugLastTask;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotWorldPos;
	static void NewProp_bShouldObeyFormation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldObeyFormation;
	static void NewProp_bTemporarilyOutOfFormation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTemporarilyOutOfFormation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressureValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BestTarget;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ThreatCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LootScore;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LootActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackProfile;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggressionRange;
	static void NewProp_bInAttackRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInAttackRange;
	static void NewProp_bInAggressionRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInAggressionRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NextAttackTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownRemaining;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceToLeader;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceToTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSquadDebugSnapshot constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSquadDebugSnapshot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot;
class UScriptStruct* FSquadDebugSnapshot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSquadDebugSnapshot, (UObject*)Z_Construct_UPackage__Script_SquadCoreDebugAdapter(), TEXT("SquadDebugSnapshot"));
	}
	return Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.OuterSingleton;
	}

// ********** Begin ScriptStruct FSquadDebugSnapshot Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, Owner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Owner_MetaData), NewProp_Owner_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DebugLastTask = { "DebugLastTask", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, DebugLastTask), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugLastTask_MetaData), NewProp_DebugLastTask_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, SlotId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotId_MetaData), NewProp_SlotId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_SlotWorldPos = { "SlotWorldPos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, SlotWorldPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotWorldPos_MetaData), NewProp_SlotWorldPos_MetaData) };
void Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bShouldObeyFormation_SetBit(void* Obj)
{
	((FSquadDebugSnapshot*)Obj)->bShouldObeyFormation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bShouldObeyFormation = { "bShouldObeyFormation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSquadDebugSnapshot), &Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bShouldObeyFormation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldObeyFormation_MetaData), NewProp_bShouldObeyFormation_MetaData) };
void Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bTemporarilyOutOfFormation_SetBit(void* Obj)
{
	((FSquadDebugSnapshot*)Obj)->bTemporarilyOutOfFormation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bTemporarilyOutOfFormation = { "bTemporarilyOutOfFormation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSquadDebugSnapshot), &Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bTemporarilyOutOfFormation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTemporarilyOutOfFormation_MetaData), NewProp_bTemporarilyOutOfFormation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_PressureValue = { "PressureValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, PressureValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureValue_MetaData), NewProp_PressureValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_BestTarget = { "BestTarget", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, BestTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BestTarget_MetaData), NewProp_BestTarget_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_ThreatCount = { "ThreatCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, ThreatCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatCount_MetaData), NewProp_ThreatCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_LootScore = { "LootScore", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, LootScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootScore_MetaData), NewProp_LootScore_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_LootActor = { "LootActor", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, LootActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootActor_MetaData), NewProp_LootActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AttackProfile = { "AttackProfile", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, AttackProfile), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackProfile_MetaData), NewProp_AttackProfile_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AggressionRange = { "AggressionRange", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, AggressionRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggressionRange_MetaData), NewProp_AggressionRange_MetaData) };
void Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAttackRange_SetBit(void* Obj)
{
	((FSquadDebugSnapshot*)Obj)->bInAttackRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAttackRange = { "bInAttackRange", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSquadDebugSnapshot), &Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAttackRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInAttackRange_MetaData), NewProp_bInAttackRange_MetaData) };
void Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAggressionRange_SetBit(void* Obj)
{
	((FSquadDebugSnapshot*)Obj)->bInAggressionRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAggressionRange = { "bInAggressionRange", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSquadDebugSnapshot), &Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAggressionRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInAggressionRange_MetaData), NewProp_bInAggressionRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_NextAttackTime = { "NextAttackTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, NextAttackTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextAttackTime_MetaData), NewProp_NextAttackTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_CooldownRemaining = { "CooldownRemaining", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, CooldownRemaining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownRemaining_MetaData), NewProp_CooldownRemaining_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DistanceToLeader = { "DistanceToLeader", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, DistanceToLeader), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceToLeader_MetaData), NewProp_DistanceToLeader_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DistanceToTarget = { "DistanceToTarget", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadDebugSnapshot, DistanceToTarget), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceToTarget_MetaData), NewProp_DistanceToTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_Owner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DebugLastTask,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_SlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_SlotWorldPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bShouldObeyFormation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bTemporarilyOutOfFormation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_PressureValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_BestTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_ThreatCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_LootScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_LootActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AttackProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_AggressionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_bInAggressionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_NextAttackTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_CooldownRemaining,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DistanceToLeader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewProp_DistanceToTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSquadDebugSnapshot Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreDebugAdapter,
	nullptr,
	&NewStructOps,
	"SquadDebugSnapshot",
	Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::PropPointers),
	sizeof(FSquadDebugSnapshot),
	alignof(FSquadDebugSnapshot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSquadDebugSnapshot()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.InnerSingleton, Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot.InnerSingleton);
}
// ********** End ScriptStruct FSquadDebugSnapshot *************************************************

// ********** Begin Class USquadDebugComponent Function GetSnapshot ********************************
struct Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics
{
	struct SquadDebugComponent_eventGetSnapshot_Parms
	{
		FSquadDebugSnapshot ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSnapshot constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSnapshot constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSnapshot Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadDebugComponent_eventGetSnapshot_Parms, ReturnValue), Z_Construct_UScriptStruct_FSquadDebugSnapshot, METADATA_PARAMS(0, nullptr) }; // 137827514
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::PropPointers) < 2048);
// ********** End Function GetSnapshot Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadDebugComponent, nullptr, "GetSnapshot", 	Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::SquadDebugComponent_eventGetSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::SquadDebugComponent_eventGetSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadDebugComponent_GetSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadDebugComponent_GetSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadDebugComponent::execGetSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSquadDebugSnapshot*)Z_Param__Result=P_THIS->GetSnapshot();
	P_NATIVE_END;
}
// ********** End Class USquadDebugComponent Function GetSnapshot **********************************

// ********** Begin Class USquadDebugComponent *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadDebugComponent;
UClass* USquadDebugComponent::GetPrivateStaticClass()
{
	using TClass = USquadDebugComponent;
	if (!Z_Registration_Info_UClass_USquadDebugComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadDebugComponent"),
			Z_Registration_Info_UClass_USquadDebugComponent.InnerSingleton,
			StaticRegisterNativesUSquadDebugComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_USquadDebugComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadDebugComponent_NoRegister()
{
	return USquadDebugComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadDebugComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Squad" },
		{ "IncludePath", "SquadCore/SquadDebugComponent.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawWorld_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawText3D_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseWidget_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetClass_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetDrawSize_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetOffset_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWidgetDrawAtDesiredSize_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWidgetScreenSpace_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawFormation_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawTargeting_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawAttackRange_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawLeaderLine_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextVerticalOffset_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineThickness_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FormationColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeaderColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Snapshot_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugWidgetComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadDebugComponent constinit property declarations *********************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static void NewProp_bDrawWorld_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawWorld;
	static void NewProp_bDrawText3D_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawText3D;
	static void NewProp_bUseWidget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WidgetDrawSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WidgetOffset;
	static void NewProp_bWidgetDrawAtDesiredSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWidgetDrawAtDesiredSize;
	static void NewProp_bWidgetScreenSpace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWidgetScreenSpace;
	static void NewProp_bDrawFormation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawFormation;
	static void NewProp_bDrawTargeting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawTargeting;
	static void NewProp_bDrawAttackRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawAttackRange;
	static void NewProp_bDrawLeaderLine_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawLeaderLine;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TextVerticalOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineThickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FormationColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LeaderColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Snapshot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugWidgetComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadDebugComponent constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSnapshot"), .Pointer = &USquadDebugComponent::execGetSnapshot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USquadDebugComponent_GetSnapshot, "GetSnapshot" }, // 2229018741
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadDebugComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadDebugComponent_Statics

// ********** Begin Class USquadDebugComponent Property Definitions ********************************
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawWorld_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawWorld = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawWorld = { "bDrawWorld", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawWorld_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawWorld_MetaData), NewProp_bDrawWorld_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawText3D_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawText3D = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawText3D = { "bDrawText3D", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawText3D_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawText3D_MetaData), NewProp_bDrawText3D_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bUseWidget_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bUseWidget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bUseWidget = { "bUseWidget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bUseWidget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseWidget_MetaData), NewProp_bUseWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetClass = { "WidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, WidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetClass_MetaData), NewProp_WidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetDrawSize = { "WidgetDrawSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, WidgetDrawSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetDrawSize_MetaData), NewProp_WidgetDrawSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetOffset = { "WidgetOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, WidgetOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetOffset_MetaData), NewProp_WidgetOffset_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetDrawAtDesiredSize_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bWidgetDrawAtDesiredSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetDrawAtDesiredSize = { "bWidgetDrawAtDesiredSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetDrawAtDesiredSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWidgetDrawAtDesiredSize_MetaData), NewProp_bWidgetDrawAtDesiredSize_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetScreenSpace_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bWidgetScreenSpace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetScreenSpace = { "bWidgetScreenSpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetScreenSpace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWidgetScreenSpace_MetaData), NewProp_bWidgetScreenSpace_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawFormation_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawFormation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawFormation = { "bDrawFormation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawFormation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawFormation_MetaData), NewProp_bDrawFormation_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawTargeting_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawTargeting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawTargeting = { "bDrawTargeting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawTargeting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawTargeting_MetaData), NewProp_bDrawTargeting_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawAttackRange_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawAttackRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawAttackRange = { "bDrawAttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawAttackRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawAttackRange_MetaData), NewProp_bDrawAttackRange_MetaData) };
void Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawLeaderLine_SetBit(void* Obj)
{
	((USquadDebugComponent*)Obj)->bDrawLeaderLine = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawLeaderLine = { "bDrawLeaderLine", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugComponent), &Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawLeaderLine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawLeaderLine_MetaData), NewProp_bDrawLeaderLine_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TextVerticalOffset = { "TextVerticalOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, TextVerticalOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextVerticalOffset_MetaData), NewProp_TextVerticalOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, LineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineThickness_MetaData), NewProp_LineThickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_FormationColor = { "FormationColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, FormationColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FormationColor_MetaData), NewProp_FormationColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TargetColor = { "TargetColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, TargetColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetColor_MetaData), NewProp_TargetColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_LeaderColor = { "LeaderColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, LeaderColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeaderColor_MetaData), NewProp_LeaderColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, TextColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_Snapshot = { "Snapshot", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, Snapshot), Z_Construct_UScriptStruct_FSquadDebugSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Snapshot_MetaData), NewProp_Snapshot_MetaData) }; // 137827514
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_DebugWidgetComponent = { "DebugWidgetComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugComponent, DebugWidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugWidgetComponent_MetaData), NewProp_DebugWidgetComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadDebugComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawWorld,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawText3D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bUseWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetDrawSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_WidgetOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetDrawAtDesiredSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bWidgetScreenSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawFormation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawTargeting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_bDrawLeaderLine,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TextVerticalOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_LineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_FormationColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TargetColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_LeaderColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_TextColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_Snapshot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugComponent_Statics::NewProp_DebugWidgetComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugComponent_Statics::PropPointers) < 2048);
// ********** End Class USquadDebugComponent Property Definitions **********************************
UObject* (*const Z_Construct_UClass_USquadDebugComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreDebugAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USquadDebugComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UDebugFrameworkProvider_NoRegister, (int32)VTABLE_OFFSET(USquadDebugComponent, IDebugFrameworkProvider), false },  // 825384405
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadDebugComponent_Statics::ClassParams = {
	&USquadDebugComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USquadDebugComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadDebugComponent_Statics::Class_MetaDataParams)
};
void USquadDebugComponent::StaticRegisterNativesUSquadDebugComponent()
{
	UClass* Class = USquadDebugComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USquadDebugComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_USquadDebugComponent()
{
	if (!Z_Registration_Info_UClass_USquadDebugComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadDebugComponent.OuterSingleton, Z_Construct_UClass_USquadDebugComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadDebugComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadDebugComponent);
USquadDebugComponent::~USquadDebugComponent() {}
// ********** End Class USquadDebugComponent *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSquadDebugSnapshot::StaticStruct, Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics::NewStructOps, TEXT("SquadDebugSnapshot"),&Z_Registration_Info_UScriptStruct_FSquadDebugSnapshot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSquadDebugSnapshot), 137827514U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadDebugComponent, USquadDebugComponent::StaticClass, TEXT("USquadDebugComponent"), &Z_Registration_Info_UClass_USquadDebugComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadDebugComponent), 123478374U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_2366948682{
	TEXT("/Script/SquadCoreDebugAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h__Script_SquadCoreDebugAdapter_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
