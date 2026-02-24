// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterCollisionSubsystem.h"
#include "HitRegister/HitRegisterTypes.h"
#include "HitRegisterCollision/HitRegisterCollisionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterCollisionSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterCollisionSubsystem();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterCollisionSubsystem_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitCandidateBatch();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterDedupeSettings();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FAttackRequest();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterCollisionSubsystem Function ClearAllDedupe *******************
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearAllDedupe constinit property declarations ************************
// ********** End Function ClearAllDedupe constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "ClearAllDedupe", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execClearAllDedupe)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAllDedupe();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function ClearAllDedupe *********************

// ********** Begin Class UHitRegisterCollisionSubsystem Function ClearDedupeForAttack *************
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics
{
	struct HitRegisterCollisionSubsystem_eventClearDedupeForAttack_Parms
	{
		int32 AttackId;
		AActor* Instigator;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearDedupeForAttack constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ClearDedupeForAttack constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ClearDedupeForAttack Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::NewProp_AttackId = { "AttackId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventClearDedupeForAttack_Parms, AttackId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventClearDedupeForAttack_Parms, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::NewProp_AttackId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::NewProp_Instigator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::PropPointers) < 2048);
// ********** End Function ClearDedupeForAttack Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "ClearDedupeForAttack", 	Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::HitRegisterCollisionSubsystem_eventClearDedupeForAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::HitRegisterCollisionSubsystem_eventClearDedupeForAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execClearDedupeForAttack)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_AttackId);
	P_GET_OBJECT(AActor,Z_Param_Instigator);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDedupeForAttack(Z_Param_AttackId,Z_Param_Instigator);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function ClearDedupeForAttack ***************

// ********** Begin Class UHitRegisterCollisionSubsystem Function ExecuteForCandidates *************
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics
{
	struct HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms
	{
		FAttackRequest Attack;
		UHitRegisterPipeline* Pipeline;
		FHitCandidateBatch Batch;
		TArray<FHitRegisterContext> OutContexts;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Execute pipeline for every candidate that passed filtering.\n     * OutContexts includes both success and stopped results so callers can drive UI/telemetry from one stream.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute pipeline for every candidate that passed filtering.\nOutContexts includes both success and stopped results so callers can drive UI/telemetry from one stream." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Batch_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteForCandidates constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Batch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutContexts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteForCandidates constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteForCandidates Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms, Pipeline), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Batch = { "Batch", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms, Batch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Batch_MetaData), NewProp_Batch_MetaData) }; // 3388551831
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_OutContexts_Inner = { "OutContexts", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_OutContexts = { "OutContexts", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms, OutContexts), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1092352881
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_Batch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_OutContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::NewProp_OutContexts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::PropPointers) < 2048);
// ********** End Function ExecuteForCandidates Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "ExecuteForCandidates", 	Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::HitRegisterCollisionSubsystem_eventExecuteForCandidates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execExecuteForCandidates)
{
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_OBJECT(UHitRegisterPipeline,Z_Param_Pipeline);
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_Batch);
	P_GET_TARRAY_REF(FHitRegisterContext,Z_Param_Out_OutContexts);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteForCandidates(Z_Param_Out_Attack,Z_Param_Pipeline,Z_Param_Out_Batch,Z_Param_Out_OutContexts);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function ExecuteForCandidates ***************

// ********** Begin Class UHitRegisterCollisionSubsystem Function FilterAndExecuteCandidates *******
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics
{
	struct HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms
	{
		FAttackRequest Attack;
		FHitCandidateBatch InBatch;
		const UHitRegisterTargetingProfile* TargetingProfile;
		FHitRegisterDedupeSettings Settings;
		UHitRegisterPipeline* Pipeline;
		TArray<FHitRegisterContext> OutContexts;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Convenience: filter (targeting + dedupe) then execute in one call. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convenience: filter (targeting + dedupe) then execute in one call." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBatch_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingProfile_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FilterAndExecuteCandidates constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBatch;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingProfile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutContexts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FilterAndExecuteCandidates constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FilterAndExecuteCandidates Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_InBatch = { "InBatch", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, InBatch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBatch_MetaData), NewProp_InBatch_MetaData) }; // 3388551831
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_TargetingProfile = { "TargetingProfile", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, TargetingProfile), Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingProfile_MetaData), NewProp_TargetingProfile_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, Settings), Z_Construct_UScriptStruct_FHitRegisterDedupeSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 2711719327
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, Pipeline), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_OutContexts_Inner = { "OutContexts", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_OutContexts = { "OutContexts", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms, OutContexts), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1092352881
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_InBatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_TargetingProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Settings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_OutContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::NewProp_OutContexts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::PropPointers) < 2048);
// ********** End Function FilterAndExecuteCandidates Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "FilterAndExecuteCandidates", 	Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::HitRegisterCollisionSubsystem_eventFilterAndExecuteCandidates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execFilterAndExecuteCandidates)
{
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_InBatch);
	P_GET_OBJECT(UHitRegisterTargetingProfile,Z_Param_TargetingProfile);
	P_GET_STRUCT_REF(FHitRegisterDedupeSettings,Z_Param_Out_Settings);
	P_GET_OBJECT(UHitRegisterPipeline,Z_Param_Pipeline);
	P_GET_TARRAY_REF(FHitRegisterContext,Z_Param_Out_OutContexts);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FilterAndExecuteCandidates(Z_Param_Out_Attack,Z_Param_Out_InBatch,Z_Param_TargetingProfile,Z_Param_Out_Settings,Z_Param_Pipeline,Z_Param_Out_OutContexts);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function FilterAndExecuteCandidates *********

// ********** Begin Class UHitRegisterCollisionSubsystem Function FilterCandidates *****************
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics
{
	struct HitRegisterCollisionSubsystem_eventFilterCandidates_Parms
	{
		FAttackRequest Attack;
		FHitCandidateBatch InBatch;
		const UHitRegisterTargetingProfile* TargetingProfile;
		FHitRegisterDedupeSettings Settings;
		FHitCandidateBatch OutBatch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBatch_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingProfile_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FilterCandidates constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBatch;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingProfile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutBatch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FilterCandidates constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FilterCandidates Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidates_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_InBatch = { "InBatch", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidates_Parms, InBatch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBatch_MetaData), NewProp_InBatch_MetaData) }; // 3388551831
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_TargetingProfile = { "TargetingProfile", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidates_Parms, TargetingProfile), Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingProfile_MetaData), NewProp_TargetingProfile_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidates_Parms, Settings), Z_Construct_UScriptStruct_FHitRegisterDedupeSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 2711719327
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_OutBatch = { "OutBatch", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidates_Parms, OutBatch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(0, nullptr) }; // 3388551831
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_InBatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_TargetingProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_Settings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::NewProp_OutBatch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::PropPointers) < 2048);
// ********** End Function FilterCandidates Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "FilterCandidates", 	Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::HitRegisterCollisionSubsystem_eventFilterCandidates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::HitRegisterCollisionSubsystem_eventFilterCandidates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execFilterCandidates)
{
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_InBatch);
	P_GET_OBJECT(UHitRegisterTargetingProfile,Z_Param_TargetingProfile);
	P_GET_STRUCT_REF(FHitRegisterDedupeSettings,Z_Param_Out_Settings);
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_OutBatch);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FilterCandidates(Z_Param_Out_Attack,Z_Param_Out_InBatch,Z_Param_TargetingProfile,Z_Param_Out_Settings,Z_Param_Out_OutBatch);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function FilterCandidates *******************

// ********** Begin Class UHitRegisterCollisionSubsystem Function FilterCandidatesSimple ***********
struct Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics
{
	struct HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms
	{
		FHitCandidateBatch InBatch;
		FHitRegisterDedupeSettings Settings;
		FHitCandidateBatch OutBatch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBatch_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FilterCandidatesSimple constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBatch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutBatch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FilterCandidatesSimple constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FilterCandidatesSimple Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_InBatch = { "InBatch", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms, InBatch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBatch_MetaData), NewProp_InBatch_MetaData) }; // 3388551831
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms, Settings), Z_Construct_UScriptStruct_FHitRegisterDedupeSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 2711719327
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_OutBatch = { "OutBatch", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms, OutBatch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(0, nullptr) }; // 3388551831
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_InBatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_Settings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::NewProp_OutBatch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::PropPointers) < 2048);
// ********** End Function FilterCandidatesSimple Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSubsystem, nullptr, "FilterCandidatesSimple", 	Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::HitRegisterCollisionSubsystem_eventFilterCandidatesSimple_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSubsystem::execFilterCandidatesSimple)
{
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_InBatch);
	P_GET_STRUCT_REF(FHitRegisterDedupeSettings,Z_Param_Out_Settings);
	P_GET_STRUCT_REF(FHitCandidateBatch,Z_Param_Out_OutBatch);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FilterCandidatesSimple(Z_Param_Out_InBatch,Z_Param_Out_Settings,Z_Param_Out_OutBatch);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSubsystem Function FilterCandidatesSimple *************

// ********** Begin Class UHitRegisterCollisionSubsystem *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem;
UClass* UHitRegisterCollisionSubsystem::GetPrivateStaticClass()
{
	using TClass = UHitRegisterCollisionSubsystem;
	if (!Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterCollisionSubsystem"),
			Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.InnerSingleton,
			StaticRegisterNativesUHitRegisterCollisionSubsystem,
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
	return Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterCollisionSubsystem_NoRegister()
{
	return UHitRegisterCollisionSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterCollisionSubsystem constinit property declarations ***********
// ********** End Class UHitRegisterCollisionSubsystem constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClearAllDedupe"), .Pointer = &UHitRegisterCollisionSubsystem::execClearAllDedupe },
		{ .NameUTF8 = UTF8TEXT("ClearDedupeForAttack"), .Pointer = &UHitRegisterCollisionSubsystem::execClearDedupeForAttack },
		{ .NameUTF8 = UTF8TEXT("ExecuteForCandidates"), .Pointer = &UHitRegisterCollisionSubsystem::execExecuteForCandidates },
		{ .NameUTF8 = UTF8TEXT("FilterAndExecuteCandidates"), .Pointer = &UHitRegisterCollisionSubsystem::execFilterAndExecuteCandidates },
		{ .NameUTF8 = UTF8TEXT("FilterCandidates"), .Pointer = &UHitRegisterCollisionSubsystem::execFilterCandidates },
		{ .NameUTF8 = UTF8TEXT("FilterCandidatesSimple"), .Pointer = &UHitRegisterCollisionSubsystem::execFilterCandidatesSimple },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearAllDedupe, "ClearAllDedupe" }, // 3325971375
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ClearDedupeForAttack, "ClearDedupeForAttack" }, // 2198785688
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_ExecuteForCandidates, "ExecuteForCandidates" }, // 2616506209
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterAndExecuteCandidates, "FilterAndExecuteCandidates" }, // 264174708
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidates, "FilterCandidates" }, // 3566850126
		{ &Z_Construct_UFunction_UHitRegisterCollisionSubsystem_FilterCandidatesSimple, "FilterCandidatesSimple" }, // 2878564805
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterCollisionSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::ClassParams = {
	&UHitRegisterCollisionSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::Class_MetaDataParams)
};
void UHitRegisterCollisionSubsystem::StaticRegisterNativesUHitRegisterCollisionSubsystem()
{
	UClass* Class = UHitRegisterCollisionSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterCollisionSubsystem()
{
	if (!Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.OuterSingleton, Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem.OuterSingleton;
}
UHitRegisterCollisionSubsystem::UHitRegisterCollisionSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterCollisionSubsystem);
UHitRegisterCollisionSubsystem::~UHitRegisterCollisionSubsystem() {}
// ********** End Class UHitRegisterCollisionSubsystem *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterCollisionSubsystem, UHitRegisterCollisionSubsystem::StaticClass, TEXT("UHitRegisterCollisionSubsystem"), &Z_Registration_Info_UClass_UHitRegisterCollisionSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterCollisionSubsystem), 3991604013U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h__Script_HitRegisterCollision_2941475485{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
