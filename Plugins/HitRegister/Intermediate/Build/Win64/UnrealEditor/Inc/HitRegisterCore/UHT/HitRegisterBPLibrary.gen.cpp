// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterBPLibrary.h"
#include "Engine/HitResult.h"
#include "HitRegister/HitRegisterTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterBPLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterBPLibrary();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterBPLibrary_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FAttackRequest();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterBPLibrary Function ExecuteHitRegister ************************
struct Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics
{
	struct HitRegisterBPLibrary_eventExecuteHitRegister_Parms
	{
		UObject* WorldContextObject;
		FAttackRequest Attack;
		FHitResult Hit;
		UHitRegisterPipeline* Pipeline;
		FHitRegisterContext OutContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Execute with explicit pipeline (recommended). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute with explicit pipeline (recommended)." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteHitRegister constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteHitRegister constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteHitRegister Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegister_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegister_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegister_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegister_Parms, Pipeline), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_OutContext = { "OutContext", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegister_Parms, OutContext), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
void Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((HitRegisterBPLibrary_eventExecuteHitRegister_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HitRegisterBPLibrary_eventExecuteHitRegister_Parms), &Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Hit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_OutContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::PropPointers) < 2048);
// ********** End Function ExecuteHitRegister Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterBPLibrary, nullptr, "ExecuteHitRegister", 	Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::HitRegisterBPLibrary_eventExecuteHitRegister_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::HitRegisterBPLibrary_eventExecuteHitRegister_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterBPLibrary::execExecuteHitRegister)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_GET_OBJECT(UHitRegisterPipeline,Z_Param_Pipeline);
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_OutContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UHitRegisterBPLibrary::ExecuteHitRegister(Z_Param_WorldContextObject,Z_Param_Out_Attack,Z_Param_Out_Hit,Z_Param_Pipeline,Z_Param_Out_OutContext);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterBPLibrary Function ExecuteHitRegister **************************

// ********** Begin Class UHitRegisterBPLibrary Function ExecuteHitRegisterDefault *****************
struct Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics
{
	struct HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms
	{
		UObject* WorldContextObject;
		FAttackRequest Attack;
		FHitResult Hit;
		FHitRegisterContext OutContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Execute using default pipeline from settings. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute using default pipeline from settings." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteHitRegisterDefault constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteHitRegisterDefault constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteHitRegisterDefault Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_OutContext = { "OutContext", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms, OutContext), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
void Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms), &Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_Hit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_OutContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::PropPointers) < 2048);
// ********** End Function ExecuteHitRegisterDefault Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterBPLibrary, nullptr, "ExecuteHitRegisterDefault", 	Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::HitRegisterBPLibrary_eventExecuteHitRegisterDefault_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterBPLibrary::execExecuteHitRegisterDefault)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_OutContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UHitRegisterBPLibrary::ExecuteHitRegisterDefault(Z_Param_WorldContextObject,Z_Param_Out_Attack,Z_Param_Out_Hit,Z_Param_Out_OutContext);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterBPLibrary Function ExecuteHitRegisterDefault *******************

// ********** Begin Class UHitRegisterBPLibrary Function GetDefaultPipeline ************************
struct Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics
{
	struct HitRegisterBPLibrary_eventGetDefaultPipeline_Parms
	{
		UHitRegisterPipeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Load the default pipeline from settings (returns null if not set or not loaded). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load the default pipeline from settings (returns null if not set or not loaded)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDefaultPipeline constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDefaultPipeline constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDefaultPipeline Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterBPLibrary_eventGetDefaultPipeline_Parms, ReturnValue), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::PropPointers) < 2048);
// ********** End Function GetDefaultPipeline Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterBPLibrary, nullptr, "GetDefaultPipeline", 	Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::HitRegisterBPLibrary_eventGetDefaultPipeline_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::HitRegisterBPLibrary_eventGetDefaultPipeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterBPLibrary::execGetDefaultPipeline)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UHitRegisterPipeline**)Z_Param__Result=UHitRegisterBPLibrary::GetDefaultPipeline();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterBPLibrary Function GetDefaultPipeline **************************

// ********** Begin Class UHitRegisterBPLibrary ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterBPLibrary;
UClass* UHitRegisterBPLibrary::GetPrivateStaticClass()
{
	using TClass = UHitRegisterBPLibrary;
	if (!Z_Registration_Info_UClass_UHitRegisterBPLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterBPLibrary"),
			Z_Registration_Info_UClass_UHitRegisterBPLibrary.InnerSingleton,
			StaticRegisterNativesUHitRegisterBPLibrary,
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
	return Z_Registration_Info_UClass_UHitRegisterBPLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterBPLibrary_NoRegister()
{
	return UHitRegisterBPLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HitRegister/HitRegisterBPLibrary.h" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterBPLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterBPLibrary constinit property declarations ********************
// ********** End Class UHitRegisterBPLibrary constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteHitRegister"), .Pointer = &UHitRegisterBPLibrary::execExecuteHitRegister },
		{ .NameUTF8 = UTF8TEXT("ExecuteHitRegisterDefault"), .Pointer = &UHitRegisterBPLibrary::execExecuteHitRegisterDefault },
		{ .NameUTF8 = UTF8TEXT("GetDefaultPipeline"), .Pointer = &UHitRegisterBPLibrary::execGetDefaultPipeline },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegister, "ExecuteHitRegister" }, // 3560254985
		{ &Z_Construct_UFunction_UHitRegisterBPLibrary_ExecuteHitRegisterDefault, "ExecuteHitRegisterDefault" }, // 2264823335
		{ &Z_Construct_UFunction_UHitRegisterBPLibrary_GetDefaultPipeline, "GetDefaultPipeline" }, // 3461899801
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterBPLibrary_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterBPLibrary_Statics::ClassParams = {
	&UHitRegisterBPLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterBPLibrary_Statics::Class_MetaDataParams)
};
void UHitRegisterBPLibrary::StaticRegisterNativesUHitRegisterBPLibrary()
{
	UClass* Class = UHitRegisterBPLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterBPLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterBPLibrary()
{
	if (!Z_Registration_Info_UClass_UHitRegisterBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterBPLibrary.OuterSingleton, Z_Construct_UClass_UHitRegisterBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterBPLibrary.OuterSingleton;
}
UHitRegisterBPLibrary::UHitRegisterBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterBPLibrary);
UHitRegisterBPLibrary::~UHitRegisterBPLibrary() {}
// ********** End Class UHitRegisterBPLibrary ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterBPLibrary, UHitRegisterBPLibrary::StaticClass, TEXT("UHitRegisterBPLibrary"), &Z_Registration_Info_UClass_UHitRegisterBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterBPLibrary), 4200628265U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h__Script_HitRegisterCore_2856902315{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
