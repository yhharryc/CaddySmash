// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/LootEvaluator.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeLootEvaluator() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SQUADCORE_API UClass* Z_Construct_UClass_ULootEvaluator();
SQUADCORE_API UClass* Z_Construct_UClass_ULootEvaluator_NoRegister();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FLootCandidate();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULootEvaluator Function EvaluateLoot *************************************
struct LootEvaluator_eventEvaluateLoot_Parms
{
	AActor* Source;
	TArray<FLootCandidate> OutLoot;
};
static FName NAME_ULootEvaluator_EvaluateLoot = FName(TEXT("EvaluateLoot"));
void ULootEvaluator::EvaluateLoot(AActor* Source, TArray<FLootCandidate>& OutLoot) const
{
	UFunction* Func = FindFunctionChecked(NAME_ULootEvaluator_EvaluateLoot);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		LootEvaluator_eventEvaluateLoot_Parms Parms;
		Parms.Source=Source;
		Parms.OutLoot=OutLoot;
		const_cast<ULootEvaluator*>(this)->ProcessEvent(Func,&Parms);
		OutLoot=Parms.OutLoot;
	}
	else
	{
		const_cast<ULootEvaluator*>(this)->EvaluateLoot_Implementation(Source, OutLoot);
	}
}
struct Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/LootEvaluator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function EvaluateLoot constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutLoot_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutLoot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EvaluateLoot constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EvaluateLoot Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LootEvaluator_eventEvaluateLoot_Parms, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_OutLoot_Inner = { "OutLoot", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLootCandidate, METADATA_PARAMS(0, nullptr) }; // 4005417798
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_OutLoot = { "OutLoot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LootEvaluator_eventEvaluateLoot_Parms, OutLoot), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4005417798
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_OutLoot_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::NewProp_OutLoot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::PropPointers) < 2048);
// ********** End Function EvaluateLoot Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULootEvaluator, nullptr, "EvaluateLoot", 	Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::PropPointers), 
sizeof(LootEvaluator_eventEvaluateLoot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LootEvaluator_eventEvaluateLoot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULootEvaluator_EvaluateLoot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULootEvaluator_EvaluateLoot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULootEvaluator::execEvaluateLoot)
{
	P_GET_OBJECT(AActor,Z_Param_Source);
	P_GET_TARRAY_REF(FLootCandidate,Z_Param_Out_OutLoot);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EvaluateLoot_Implementation(Z_Param_Source,Z_Param_Out_OutLoot);
	P_NATIVE_END;
}
// ********** End Class ULootEvaluator Function EvaluateLoot ***************************************

// ********** Begin Class ULootEvaluator ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ULootEvaluator;
UClass* ULootEvaluator::GetPrivateStaticClass()
{
	using TClass = ULootEvaluator;
	if (!Z_Registration_Info_UClass_ULootEvaluator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("LootEvaluator"),
			Z_Registration_Info_UClass_ULootEvaluator.InnerSingleton,
			StaticRegisterNativesULootEvaluator,
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
	return Z_Registration_Info_UClass_ULootEvaluator.InnerSingleton;
}
UClass* Z_Construct_UClass_ULootEvaluator_NoRegister()
{
	return ULootEvaluator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULootEvaluator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/LootEvaluator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/LootEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootClass_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/LootEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRange_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/LootEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceWeight_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/LootEvaluator.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ULootEvaluator constinit property declarations ***************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_LootClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceWeight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ULootEvaluator constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EvaluateLoot"), .Pointer = &ULootEvaluator::execEvaluateLoot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULootEvaluator_EvaluateLoot, "EvaluateLoot" }, // 217645054
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULootEvaluator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ULootEvaluator_Statics

// ********** Begin Class ULootEvaluator Property Definitions **************************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULootEvaluator_Statics::NewProp_LootClass = { "LootClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULootEvaluator, LootClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootClass_MetaData), NewProp_LootClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULootEvaluator_Statics::NewProp_MaxRange = { "MaxRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULootEvaluator, MaxRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRange_MetaData), NewProp_MaxRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULootEvaluator_Statics::NewProp_DistanceWeight = { "DistanceWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULootEvaluator, DistanceWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceWeight_MetaData), NewProp_DistanceWeight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULootEvaluator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULootEvaluator_Statics::NewProp_LootClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULootEvaluator_Statics::NewProp_MaxRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULootEvaluator_Statics::NewProp_DistanceWeight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULootEvaluator_Statics::PropPointers) < 2048);
// ********** End Class ULootEvaluator Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_ULootEvaluator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULootEvaluator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULootEvaluator_Statics::ClassParams = {
	&ULootEvaluator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULootEvaluator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULootEvaluator_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULootEvaluator_Statics::Class_MetaDataParams), Z_Construct_UClass_ULootEvaluator_Statics::Class_MetaDataParams)
};
void ULootEvaluator::StaticRegisterNativesULootEvaluator()
{
	UClass* Class = ULootEvaluator::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ULootEvaluator_Statics::Funcs));
}
UClass* Z_Construct_UClass_ULootEvaluator()
{
	if (!Z_Registration_Info_UClass_ULootEvaluator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULootEvaluator.OuterSingleton, Z_Construct_UClass_ULootEvaluator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULootEvaluator.OuterSingleton;
}
ULootEvaluator::ULootEvaluator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ULootEvaluator);
ULootEvaluator::~ULootEvaluator() {}
// ********** End Class ULootEvaluator *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULootEvaluator, ULootEvaluator::StaticClass, TEXT("ULootEvaluator"), &Z_Registration_Info_UClass_ULootEvaluator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULootEvaluator), 2293938932U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h__Script_SquadCore_2307169841{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
