// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterSubsystem.h"
#include "Engine/HitResult.h"
#include "HitRegister/HitRegisterTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterSubsystem();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterSubsystem_NoRegister();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FAttackRequest();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterSubsystem Function ExecuteHitRegister ************************
struct Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics
{
	struct HitRegisterSubsystem_eventExecuteHitRegister_Parms
	{
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
		{ "Comment", "/** Execute a hit registration pipeline. Returns false if stopped early (miss/invalid/rejected/failed apply). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute a hit registration pipeline. Returns false if stopped early (miss/invalid/rejected/failed apply)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteHitRegister constinit property declarations ********************
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterSubsystem_eventExecuteHitRegister_Parms, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterSubsystem_eventExecuteHitRegister_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterSubsystem_eventExecuteHitRegister_Parms, Pipeline), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_OutContext = { "OutContext", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterSubsystem_eventExecuteHitRegister_Parms, OutContext), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
void Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((HitRegisterSubsystem_eventExecuteHitRegister_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HitRegisterSubsystem_eventExecuteHitRegister_Parms), &Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Hit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_OutContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::PropPointers) < 2048);
// ********** End Function ExecuteHitRegister Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterSubsystem, nullptr, "ExecuteHitRegister", 	Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::HitRegisterSubsystem_eventExecuteHitRegister_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::HitRegisterSubsystem_eventExecuteHitRegister_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterSubsystem::execExecuteHitRegister)
{
	P_GET_STRUCT_REF(FAttackRequest,Z_Param_Out_Attack);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_GET_OBJECT(UHitRegisterPipeline,Z_Param_Pipeline);
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_OutContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ExecuteHitRegister(Z_Param_Out_Attack,Z_Param_Out_Hit,Z_Param_Pipeline,Z_Param_Out_OutContext);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterSubsystem Function ExecuteHitRegister **************************

// ********** Begin Class UHitRegisterSubsystem ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterSubsystem;
UClass* UHitRegisterSubsystem::GetPrivateStaticClass()
{
	using TClass = UHitRegisterSubsystem;
	if (!Z_Registration_Info_UClass_UHitRegisterSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterSubsystem"),
			Z_Registration_Info_UClass_UHitRegisterSubsystem.InnerSingleton,
			StaticRegisterNativesUHitRegisterSubsystem,
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
	return Z_Registration_Info_UClass_UHitRegisterSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterSubsystem_NoRegister()
{
	return UHitRegisterSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HitRegister/HitRegisterSubsystem.h" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterSubsystem constinit property declarations ********************
// ********** End Class UHitRegisterSubsystem constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteHitRegister"), .Pointer = &UHitRegisterSubsystem::execExecuteHitRegister },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterSubsystem_ExecuteHitRegister, "ExecuteHitRegister" }, // 1379392603
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterSubsystem_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterSubsystem_Statics::ClassParams = {
	&UHitRegisterSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterSubsystem_Statics::Class_MetaDataParams)
};
void UHitRegisterSubsystem::StaticRegisterNativesUHitRegisterSubsystem()
{
	UClass* Class = UHitRegisterSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterSubsystem()
{
	if (!Z_Registration_Info_UClass_UHitRegisterSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterSubsystem.OuterSingleton, Z_Construct_UClass_UHitRegisterSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterSubsystem.OuterSingleton;
}
UHitRegisterSubsystem::UHitRegisterSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterSubsystem);
UHitRegisterSubsystem::~UHitRegisterSubsystem() {}
// ********** End Class UHitRegisterSubsystem ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterSubsystem, UHitRegisterSubsystem::StaticClass, TEXT("UHitRegisterSubsystem"), &Z_Registration_Info_UClass_UHitRegisterSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterSubsystem), 925802687U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h__Script_HitRegisterCore_386716160{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
