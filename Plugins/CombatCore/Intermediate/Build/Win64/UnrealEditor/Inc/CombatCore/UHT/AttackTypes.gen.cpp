// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackTypes() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackExecutionParams();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackRequest();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCombatAttackRequest **********************************************
struct Z_Construct_UScriptStruct_FCombatAttackRequest_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCombatAttackRequest); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCombatAttackRequest); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceObject_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponObject_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCombatAttackRequest constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCombatAttackRequest constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCombatAttackRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCombatAttackRequest_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCombatAttackRequest;
class UScriptStruct* FCombatAttackRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCombatAttackRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCombatAttackRequest, (UObject*)Z_Construct_UPackage__Script_CombatCore(), TEXT("CombatAttackRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FCombatAttackRequest.OuterSingleton;
	}

// ********** Begin ScriptStruct FCombatAttackRequest Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_SourceObject = { "SourceObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, SourceObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceObject_MetaData), NewProp_SourceObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, Profile), Z_Construct_UClass_UAttackProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_WeaponObject = { "WeaponObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, WeaponObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponObject_MetaData), NewProp_WeaponObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackRequest, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_SourceObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_Profile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_WeaponObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewProp_BaseDamage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCombatAttackRequest Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
	nullptr,
	&NewStructOps,
	"CombatAttackRequest",
	Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::PropPointers),
	sizeof(FCombatAttackRequest),
	alignof(FCombatAttackRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCombatAttackRequest.InnerSingleton, Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCombatAttackRequest.InnerSingleton);
}
// ********** End ScriptStruct FCombatAttackRequest ************************************************

// ********** Begin ScriptStruct FCombatAttackExecutionParams **************************************
struct Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCombatAttackExecutionParams); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCombatAttackExecutionParams); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveAttackRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideThrustDistance_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustDistance_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideHitscanRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitscanRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCombatAttackExecutionParams constinit property declarations ******
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EffectiveAttackRange;
	static void NewProp_bOverrideThrustDistance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideThrustDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrustDistance;
	static void NewProp_bOverrideHitscanRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideHitscanRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HitscanRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCombatAttackExecutionParams constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCombatAttackExecutionParams>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams;
class UScriptStruct* FCombatAttackExecutionParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCombatAttackExecutionParams, (UObject*)Z_Construct_UPackage__Script_CombatCore(), TEXT("CombatAttackExecutionParams"));
	}
	return Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.OuterSingleton;
	}

// ********** Begin ScriptStruct FCombatAttackExecutionParams Property Definitions *****************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_EffectiveAttackRange = { "EffectiveAttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackExecutionParams, EffectiveAttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectiveAttackRange_MetaData), NewProp_EffectiveAttackRange_MetaData) };
void Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideThrustDistance_SetBit(void* Obj)
{
	((FCombatAttackExecutionParams*)Obj)->bOverrideThrustDistance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideThrustDistance = { "bOverrideThrustDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCombatAttackExecutionParams), &Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideThrustDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideThrustDistance_MetaData), NewProp_bOverrideThrustDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_ThrustDistance = { "ThrustDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackExecutionParams, ThrustDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustDistance_MetaData), NewProp_ThrustDistance_MetaData) };
void Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideHitscanRange_SetBit(void* Obj)
{
	((FCombatAttackExecutionParams*)Obj)->bOverrideHitscanRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideHitscanRange = { "bOverrideHitscanRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCombatAttackExecutionParams), &Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideHitscanRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideHitscanRange_MetaData), NewProp_bOverrideHitscanRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_HitscanRange = { "HitscanRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackExecutionParams, HitscanRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitscanRange_MetaData), NewProp_HitscanRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_EffectiveAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_ThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_bOverrideHitscanRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewProp_HitscanRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCombatAttackExecutionParams Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
	nullptr,
	&NewStructOps,
	"CombatAttackExecutionParams",
	Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::PropPointers),
	sizeof(FCombatAttackExecutionParams),
	alignof(FCombatAttackExecutionParams),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackExecutionParams()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.InnerSingleton, Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams.InnerSingleton);
}
// ********** End ScriptStruct FCombatAttackExecutionParams ****************************************

// ********** Begin ScriptStruct FCombatAttackContext **********************************************
struct Z_Construct_UScriptStruct_FCombatAttackContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCombatAttackContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCombatAttackContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecutionParams_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCombatAttackContext constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExecutionParams;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCombatAttackContext constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCombatAttackContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCombatAttackContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCombatAttackContext;
class UScriptStruct* FCombatAttackContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCombatAttackContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCombatAttackContext, (UObject*)Z_Construct_UPackage__Script_CombatCore(), TEXT("CombatAttackContext"));
	}
	return Z_Registration_Info_UScriptStruct_FCombatAttackContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FCombatAttackContext Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackContext, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_ExecutionParams = { "ExecutionParams", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackContext, ExecutionParams), Z_Construct_UScriptStruct_FCombatAttackExecutionParams, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecutionParams_MetaData), NewProp_ExecutionParams_MetaData) }; // 2193908537
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCombatAttackContext, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_World_MetaData), NewProp_World_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCombatAttackContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_ExecutionParams,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCombatAttackContext Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCombatAttackContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
	nullptr,
	&NewStructOps,
	"CombatAttackContext",
	Z_Construct_UScriptStruct_FCombatAttackContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackContext_Statics::PropPointers),
	sizeof(FCombatAttackContext),
	alignof(FCombatAttackContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCombatAttackContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCombatAttackContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext()
{
	if (!Z_Registration_Info_UScriptStruct_FCombatAttackContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCombatAttackContext.InnerSingleton, Z_Construct_UScriptStruct_FCombatAttackContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCombatAttackContext.InnerSingleton);
}
// ********** End ScriptStruct FCombatAttackContext ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackTypes_h__Script_CombatCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCombatAttackRequest::StaticStruct, Z_Construct_UScriptStruct_FCombatAttackRequest_Statics::NewStructOps, TEXT("CombatAttackRequest"),&Z_Registration_Info_UScriptStruct_FCombatAttackRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCombatAttackRequest), 3210230800U) },
		{ FCombatAttackExecutionParams::StaticStruct, Z_Construct_UScriptStruct_FCombatAttackExecutionParams_Statics::NewStructOps, TEXT("CombatAttackExecutionParams"),&Z_Registration_Info_UScriptStruct_FCombatAttackExecutionParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCombatAttackExecutionParams), 2193908537U) },
		{ FCombatAttackContext::StaticStruct, Z_Construct_UScriptStruct_FCombatAttackContext_Statics::NewStructOps, TEXT("CombatAttackContext"),&Z_Registration_Info_UScriptStruct_FCombatAttackContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCombatAttackContext), 829964288U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackTypes_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackTypes_h__Script_CombatCore_1317051431{
	TEXT("/Script/CombatCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackTypes_h__Script_CombatCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackTypes_h__Script_CombatCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
