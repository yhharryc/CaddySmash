// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/ThreatEvaluator.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeThreatEvaluator() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SQUADCORE_API UClass* Z_Construct_UClass_UThreatEvaluator();
SQUADCORE_API UClass* Z_Construct_UClass_UThreatEvaluator_NoRegister();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FThreatCandidate();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UThreatEvaluator Function EvaluateThreats ********************************
struct ThreatEvaluator_eventEvaluateThreats_Parms
{
	AActor* Source;
	TArray<FThreatCandidate> OutThreats;
};
static FName NAME_UThreatEvaluator_EvaluateThreats = FName(TEXT("EvaluateThreats"));
void UThreatEvaluator::EvaluateThreats(AActor* Source, TArray<FThreatCandidate>& OutThreats) const
{
	UFunction* Func = FindFunctionChecked(NAME_UThreatEvaluator_EvaluateThreats);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ThreatEvaluator_eventEvaluateThreats_Parms Parms;
		Parms.Source=Source;
		Parms.OutThreats=OutThreats;
		const_cast<UThreatEvaluator*>(this)->ProcessEvent(Func,&Parms);
		OutThreats=Parms.OutThreats;
	}
	else
	{
		const_cast<UThreatEvaluator*>(this)->EvaluateThreats_Implementation(Source, OutThreats);
	}
}
struct Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/ThreatEvaluator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function EvaluateThreats constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutThreats_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutThreats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EvaluateThreats constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EvaluateThreats Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ThreatEvaluator_eventEvaluateThreats_Parms, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_OutThreats_Inner = { "OutThreats", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FThreatCandidate, METADATA_PARAMS(0, nullptr) }; // 730226818
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_OutThreats = { "OutThreats", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ThreatEvaluator_eventEvaluateThreats_Parms, OutThreats), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 730226818
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_OutThreats_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::NewProp_OutThreats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::PropPointers) < 2048);
// ********** End Function EvaluateThreats Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UThreatEvaluator, nullptr, "EvaluateThreats", 	Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::PropPointers), 
sizeof(ThreatEvaluator_eventEvaluateThreats_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ThreatEvaluator_eventEvaluateThreats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UThreatEvaluator::execEvaluateThreats)
{
	P_GET_OBJECT(AActor,Z_Param_Source);
	P_GET_TARRAY_REF(FThreatCandidate,Z_Param_Out_OutThreats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EvaluateThreats_Implementation(Z_Param_Source,Z_Param_Out_OutThreats);
	P_NATIVE_END;
}
// ********** End Class UThreatEvaluator Function EvaluateThreats **********************************

// ********** Begin Class UThreatEvaluator *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UThreatEvaluator;
UClass* UThreatEvaluator::GetPrivateStaticClass()
{
	using TClass = UThreatEvaluator;
	if (!Z_Registration_Info_UClass_UThreatEvaluator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ThreatEvaluator"),
			Z_Registration_Info_UClass_UThreatEvaluator.InnerSingleton,
			StaticRegisterNativesUThreatEvaluator,
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
	return Z_Registration_Info_UClass_UThreatEvaluator.InnerSingleton;
}
UClass* Z_Construct_UClass_UThreatEvaluator_NoRegister()
{
	return UThreatEvaluator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UThreatEvaluator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/ThreatEvaluator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/ThreatEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatClass_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/ThreatEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRange_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/ThreatEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceWeight_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/ThreatEvaluator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UThreatEvaluator constinit property declarations *************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_ThreatClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceWeight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UThreatEvaluator constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EvaluateThreats"), .Pointer = &UThreatEvaluator::execEvaluateThreats },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UThreatEvaluator_EvaluateThreats, "EvaluateThreats" }, // 3845564425
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UThreatEvaluator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UThreatEvaluator_Statics

// ********** Begin Class UThreatEvaluator Property Definitions ************************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_ThreatClass = { "ThreatClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UThreatEvaluator, ThreatClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatClass_MetaData), NewProp_ThreatClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_MaxRange = { "MaxRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UThreatEvaluator, MaxRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRange_MetaData), NewProp_MaxRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_DistanceWeight = { "DistanceWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UThreatEvaluator, DistanceWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceWeight_MetaData), NewProp_DistanceWeight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UThreatEvaluator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_ThreatClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_MaxRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UThreatEvaluator_Statics::NewProp_DistanceWeight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UThreatEvaluator_Statics::PropPointers) < 2048);
// ********** End Class UThreatEvaluator Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UThreatEvaluator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UThreatEvaluator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UThreatEvaluator_Statics::ClassParams = {
	&UThreatEvaluator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UThreatEvaluator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UThreatEvaluator_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UThreatEvaluator_Statics::Class_MetaDataParams), Z_Construct_UClass_UThreatEvaluator_Statics::Class_MetaDataParams)
};
void UThreatEvaluator::StaticRegisterNativesUThreatEvaluator()
{
	UClass* Class = UThreatEvaluator::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UThreatEvaluator_Statics::Funcs));
}
UClass* Z_Construct_UClass_UThreatEvaluator()
{
	if (!Z_Registration_Info_UClass_UThreatEvaluator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UThreatEvaluator.OuterSingleton, Z_Construct_UClass_UThreatEvaluator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UThreatEvaluator.OuterSingleton;
}
UThreatEvaluator::UThreatEvaluator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UThreatEvaluator);
UThreatEvaluator::~UThreatEvaluator() {}
// ********** End Class UThreatEvaluator ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UThreatEvaluator, UThreatEvaluator::StaticClass, TEXT("UThreatEvaluator"), &Z_Registration_Info_UClass_UThreatEvaluator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UThreatEvaluator), 243450028U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h__Script_SquadCore_4196307503{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
