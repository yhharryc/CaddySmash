// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/PressureComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePressureComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
SQUADCORE_API UClass* Z_Construct_UClass_UPressureComponent();
SQUADCORE_API UClass* Z_Construct_UClass_UPressureComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPressureComponent Function UpdatePressure *******************************
struct Z_Construct_UFunction_UPressureComponent_UpdatePressure_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdatePressure constinit property declarations ************************
// ********** End Function UpdatePressure constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPressureComponent_UpdatePressure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPressureComponent, nullptr, "UpdatePressure", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPressureComponent_UpdatePressure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPressureComponent_UpdatePressure_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPressureComponent_UpdatePressure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPressureComponent_UpdatePressure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPressureComponent::execUpdatePressure)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdatePressure();
	P_NATIVE_END;
}
// ********** End Class UPressureComponent Function UpdatePressure *********************************

// ********** Begin Class UPressureComponent *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPressureComponent;
UClass* UPressureComponent::GetPrivateStaticClass()
{
	using TClass = UPressureComponent;
	if (!Z_Registration_Info_UClass_UPressureComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PressureComponent"),
			Z_Registration_Info_UClass_UPressureComponent.InnerSingleton,
			StaticRegisterNativesUPressureComponent,
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
	return Z_Registration_Info_UClass_UPressureComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPressureComponent_NoRegister()
{
	return UPressureComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPressureComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Squad" },
		{ "IncludePath", "SquadCore/PressureComponent.h" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QueryRadius_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatWeight_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPressure_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatClass_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoUpdate_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureValue_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/PressureComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPressureComponent constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_QueryRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThreatWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxPressure;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ThreatClass;
	static void NewProp_bAutoUpdate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoUpdate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressureValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPressureComponent constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("UpdatePressure"), .Pointer = &UPressureComponent::execUpdatePressure },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPressureComponent_UpdatePressure, "UpdatePressure" }, // 317170484
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPressureComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPressureComponent_Statics

// ********** Begin Class UPressureComponent Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_QueryRadius = { "QueryRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, QueryRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QueryRadius_MetaData), NewProp_QueryRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_ThreatWeight = { "ThreatWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, ThreatWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatWeight_MetaData), NewProp_ThreatWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_MaxPressure = { "MaxPressure", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, MaxPressure), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPressure_MetaData), NewProp_MaxPressure_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_ThreatClass = { "ThreatClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, ThreatClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatClass_MetaData), NewProp_ThreatClass_MetaData) };
void Z_Construct_UClass_UPressureComponent_Statics::NewProp_bAutoUpdate_SetBit(void* Obj)
{
	((UPressureComponent*)Obj)->bAutoUpdate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_bAutoUpdate = { "bAutoUpdate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPressureComponent), &Z_Construct_UClass_UPressureComponent_Statics::NewProp_bAutoUpdate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoUpdate_MetaData), NewProp_bAutoUpdate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPressureComponent_Statics::NewProp_PressureValue = { "PressureValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPressureComponent, PressureValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureValue_MetaData), NewProp_PressureValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPressureComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_QueryRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_ThreatWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_MaxPressure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_ThreatClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_bAutoUpdate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPressureComponent_Statics::NewProp_PressureValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPressureComponent_Statics::PropPointers) < 2048);
// ********** End Class UPressureComponent Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UPressureComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPressureComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPressureComponent_Statics::ClassParams = {
	&UPressureComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPressureComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPressureComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPressureComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPressureComponent_Statics::Class_MetaDataParams)
};
void UPressureComponent::StaticRegisterNativesUPressureComponent()
{
	UClass* Class = UPressureComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPressureComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPressureComponent()
{
	if (!Z_Registration_Info_UClass_UPressureComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPressureComponent.OuterSingleton, Z_Construct_UClass_UPressureComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPressureComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPressureComponent);
UPressureComponent::~UPressureComponent() {}
// ********** End Class UPressureComponent *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPressureComponent, UPressureComponent::StaticClass, TEXT("UPressureComponent"), &Z_Registration_Info_UClass_UPressureComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPressureComponent), 3102958294U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h__Script_SquadCore_3348864491{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
