// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/Nodes/HRN_ApplyDamageViaInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHRN_ApplyDamageViaInterface() {}

// ********** Begin Cross Module References ********************************************************
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_ApplyDamageViaInterface();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_ApplyDamageViaInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHRN_ApplyDamageViaInterface *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface;
UClass* UHRN_ApplyDamageViaInterface::GetPrivateStaticClass()
{
	using TClass = UHRN_ApplyDamageViaInterface;
	if (!Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HRN_ApplyDamageViaInterface"),
			Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.InnerSingleton,
			StaticRegisterNativesUHRN_ApplyDamageViaInterface,
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
	return Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UHRN_ApplyDamageViaInterface_NoRegister()
{
	return UHRN_ApplyDamageViaInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Calls IDamageApplier::ApplyDamage on the hit actor (or any of its components).\n */" },
#endif
		{ "IncludePath", "HitRegister/Nodes/HRN_ApplyDamageViaInterface.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_ApplyDamageViaInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calls IDamageApplier::ApplyDamage on the hit actor (or any of its components)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopIfNoApplier_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, Stop when no applier found; otherwise just Continue. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_ApplyDamageViaInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, Stop when no applier found; otherwise just Continue." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHRN_ApplyDamageViaInterface constinit property declarations *************
	static void NewProp_bStopIfNoApplier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopIfNoApplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHRN_ApplyDamageViaInterface constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHRN_ApplyDamageViaInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics

// ********** Begin Class UHRN_ApplyDamageViaInterface Property Definitions ************************
void Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::NewProp_bStopIfNoApplier_SetBit(void* Obj)
{
	((UHRN_ApplyDamageViaInterface*)Obj)->bStopIfNoApplier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::NewProp_bStopIfNoApplier = { "bStopIfNoApplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHRN_ApplyDamageViaInterface), &Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::NewProp_bStopIfNoApplier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopIfNoApplier_MetaData), NewProp_bStopIfNoApplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::NewProp_bStopIfNoApplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::PropPointers) < 2048);
// ********** End Class UHRN_ApplyDamageViaInterface Property Definitions **************************
UObject* (*const Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHitRegisterNode,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::ClassParams = {
	&UHRN_ApplyDamageViaInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::Class_MetaDataParams)
};
void UHRN_ApplyDamageViaInterface::StaticRegisterNativesUHRN_ApplyDamageViaInterface()
{
}
UClass* Z_Construct_UClass_UHRN_ApplyDamageViaInterface()
{
	if (!Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.OuterSingleton, Z_Construct_UClass_UHRN_ApplyDamageViaInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface.OuterSingleton;
}
UHRN_ApplyDamageViaInterface::UHRN_ApplyDamageViaInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHRN_ApplyDamageViaInterface);
UHRN_ApplyDamageViaInterface::~UHRN_ApplyDamageViaInterface() {}
// ********** End Class UHRN_ApplyDamageViaInterface ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ApplyDamageViaInterface_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHRN_ApplyDamageViaInterface, UHRN_ApplyDamageViaInterface::StaticClass, TEXT("UHRN_ApplyDamageViaInterface"), &Z_Registration_Info_UClass_UHRN_ApplyDamageViaInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHRN_ApplyDamageViaInterface), 3425659793U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ApplyDamageViaInterface_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ApplyDamageViaInterface_h__Script_HitRegisterCore_1522133234{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ApplyDamageViaInterface_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ApplyDamageViaInterface_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
