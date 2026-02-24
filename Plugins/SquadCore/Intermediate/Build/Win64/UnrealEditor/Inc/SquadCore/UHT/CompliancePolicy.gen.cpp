// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/CompliancePolicy.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCompliancePolicy() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_Always();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_Always_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_NoRegister();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FSquadComplianceContext();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCompliancePolicy Function ShouldObeyFormation ***************************
struct CompliancePolicy_eventShouldObeyFormation_Parms
{
	FSquadComplianceContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	CompliancePolicy_eventShouldObeyFormation_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UCompliancePolicy_ShouldObeyFormation = FName(TEXT("ShouldObeyFormation"));
bool UCompliancePolicy::ShouldObeyFormation(FSquadComplianceContext const& Context) const
{
	UFunction* Func = FindFunctionChecked(NAME_UCompliancePolicy_ShouldObeyFormation);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		CompliancePolicy_eventShouldObeyFormation_Parms Parms;
		Parms.Context=Context;
		const_cast<UCompliancePolicy*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UCompliancePolicy*>(this)->ShouldObeyFormation_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/CompliancePolicy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShouldObeyFormation constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShouldObeyFormation constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShouldObeyFormation Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CompliancePolicy_eventShouldObeyFormation_Parms, Context), Z_Construct_UScriptStruct_FSquadComplianceContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 2047008771
void Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CompliancePolicy_eventShouldObeyFormation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CompliancePolicy_eventShouldObeyFormation_Parms), &Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::PropPointers) < 2048);
// ********** End Function ShouldObeyFormation Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCompliancePolicy, nullptr, "ShouldObeyFormation", 	Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::PropPointers), 
sizeof(CompliancePolicy_eventShouldObeyFormation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(CompliancePolicy_eventShouldObeyFormation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCompliancePolicy::execShouldObeyFormation)
{
	P_GET_STRUCT_REF(FSquadComplianceContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldObeyFormation_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UCompliancePolicy Function ShouldObeyFormation *****************************

// ********** Begin Class UCompliancePolicy ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCompliancePolicy;
UClass* UCompliancePolicy::GetPrivateStaticClass()
{
	using TClass = UCompliancePolicy;
	if (!Z_Registration_Info_UClass_UCompliancePolicy.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CompliancePolicy"),
			Z_Registration_Info_UClass_UCompliancePolicy.InnerSingleton,
			StaticRegisterNativesUCompliancePolicy,
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
	return Z_Registration_Info_UClass_UCompliancePolicy.InnerSingleton;
}
UClass* Z_Construct_UClass_UCompliancePolicy_NoRegister()
{
	return UCompliancePolicy::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCompliancePolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/CompliancePolicy.h" },
		{ "ModuleRelativePath", "Public/SquadCore/CompliancePolicy.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCompliancePolicy constinit property declarations ************************
// ********** End Class UCompliancePolicy constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ShouldObeyFormation"), .Pointer = &UCompliancePolicy::execShouldObeyFormation },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCompliancePolicy_ShouldObeyFormation, "ShouldObeyFormation" }, // 486933078
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCompliancePolicy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCompliancePolicy_Statics
UObject* (*const Z_Construct_UClass_UCompliancePolicy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCompliancePolicy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCompliancePolicy_Statics::ClassParams = {
	&UCompliancePolicy::StaticClass,
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
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCompliancePolicy_Statics::Class_MetaDataParams), Z_Construct_UClass_UCompliancePolicy_Statics::Class_MetaDataParams)
};
void UCompliancePolicy::StaticRegisterNativesUCompliancePolicy()
{
	UClass* Class = UCompliancePolicy::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCompliancePolicy_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCompliancePolicy()
{
	if (!Z_Registration_Info_UClass_UCompliancePolicy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCompliancePolicy.OuterSingleton, Z_Construct_UClass_UCompliancePolicy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCompliancePolicy.OuterSingleton;
}
UCompliancePolicy::UCompliancePolicy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCompliancePolicy);
UCompliancePolicy::~UCompliancePolicy() {}
// ********** End Class UCompliancePolicy **********************************************************

// ********** Begin Class UCompliancePolicy_Always *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCompliancePolicy_Always;
UClass* UCompliancePolicy_Always::GetPrivateStaticClass()
{
	using TClass = UCompliancePolicy_Always;
	if (!Z_Registration_Info_UClass_UCompliancePolicy_Always.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CompliancePolicy_Always"),
			Z_Registration_Info_UClass_UCompliancePolicy_Always.InnerSingleton,
			StaticRegisterNativesUCompliancePolicy_Always,
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
	return Z_Registration_Info_UClass_UCompliancePolicy_Always.InnerSingleton;
}
UClass* Z_Construct_UClass_UCompliancePolicy_Always_NoRegister()
{
	return UCompliancePolicy_Always::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCompliancePolicy_Always_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/CompliancePolicy.h" },
		{ "ModuleRelativePath", "Public/SquadCore/CompliancePolicy.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCompliancePolicy_Always constinit property declarations *****************
// ********** End Class UCompliancePolicy_Always constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCompliancePolicy_Always>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCompliancePolicy_Always_Statics
UObject* (*const Z_Construct_UClass_UCompliancePolicy_Always_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCompliancePolicy,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCompliancePolicy_Always_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCompliancePolicy_Always_Statics::ClassParams = {
	&UCompliancePolicy_Always::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCompliancePolicy_Always_Statics::Class_MetaDataParams), Z_Construct_UClass_UCompliancePolicy_Always_Statics::Class_MetaDataParams)
};
void UCompliancePolicy_Always::StaticRegisterNativesUCompliancePolicy_Always()
{
}
UClass* Z_Construct_UClass_UCompliancePolicy_Always()
{
	if (!Z_Registration_Info_UClass_UCompliancePolicy_Always.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCompliancePolicy_Always.OuterSingleton, Z_Construct_UClass_UCompliancePolicy_Always_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCompliancePolicy_Always.OuterSingleton;
}
UCompliancePolicy_Always::UCompliancePolicy_Always(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCompliancePolicy_Always);
UCompliancePolicy_Always::~UCompliancePolicy_Always() {}
// ********** End Class UCompliancePolicy_Always ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCompliancePolicy, UCompliancePolicy::StaticClass, TEXT("UCompliancePolicy"), &Z_Registration_Info_UClass_UCompliancePolicy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCompliancePolicy), 1652009326U) },
		{ Z_Construct_UClass_UCompliancePolicy_Always, UCompliancePolicy_Always::StaticClass, TEXT("UCompliancePolicy_Always"), &Z_Registration_Info_UClass_UCompliancePolicy_Always, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCompliancePolicy_Always), 1706868263U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h__Script_SquadCore_3051502086{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
