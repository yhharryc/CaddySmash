// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/Nodes/HRN_ValidateHit.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHRN_ValidateHit() {}

// ********** Begin Cross Module References ********************************************************
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_ValidateHit();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_ValidateHit_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHRN_ValidateHit *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHRN_ValidateHit;
UClass* UHRN_ValidateHit::GetPrivateStaticClass()
{
	using TClass = UHRN_ValidateHit;
	if (!Z_Registration_Info_UClass_UHRN_ValidateHit.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HRN_ValidateHit"),
			Z_Registration_Info_UClass_UHRN_ValidateHit.InnerSingleton,
			StaticRegisterNativesUHRN_ValidateHit,
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
	return Z_Registration_Info_UClass_UHRN_ValidateHit.InnerSingleton;
}
UClass* Z_Construct_UClass_UHRN_ValidateHit_NoRegister()
{
	return UHRN_ValidateHit::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHRN_ValidateHit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HitRegister/Nodes/HRN_ValidateHit.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_ValidateHit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireDamageApplier_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, requires a damage applier to be found on the hit actor (actor or any component). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_ValidateHit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, requires a damage applier to be found on the hit actor (actor or any component)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHRN_ValidateHit constinit property declarations *************************
	static void NewProp_bRequireDamageApplier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireDamageApplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHRN_ValidateHit constinit property declarations ***************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHRN_ValidateHit>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHRN_ValidateHit_Statics

// ********** Begin Class UHRN_ValidateHit Property Definitions ************************************
void Z_Construct_UClass_UHRN_ValidateHit_Statics::NewProp_bRequireDamageApplier_SetBit(void* Obj)
{
	((UHRN_ValidateHit*)Obj)->bRequireDamageApplier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHRN_ValidateHit_Statics::NewProp_bRequireDamageApplier = { "bRequireDamageApplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHRN_ValidateHit), &Z_Construct_UClass_UHRN_ValidateHit_Statics::NewProp_bRequireDamageApplier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireDamageApplier_MetaData), NewProp_bRequireDamageApplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHRN_ValidateHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHRN_ValidateHit_Statics::NewProp_bRequireDamageApplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ValidateHit_Statics::PropPointers) < 2048);
// ********** End Class UHRN_ValidateHit Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UHRN_ValidateHit_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHitRegisterNode,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ValidateHit_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHRN_ValidateHit_Statics::ClassParams = {
	&UHRN_ValidateHit::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHRN_ValidateHit_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ValidateHit_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_ValidateHit_Statics::Class_MetaDataParams), Z_Construct_UClass_UHRN_ValidateHit_Statics::Class_MetaDataParams)
};
void UHRN_ValidateHit::StaticRegisterNativesUHRN_ValidateHit()
{
}
UClass* Z_Construct_UClass_UHRN_ValidateHit()
{
	if (!Z_Registration_Info_UClass_UHRN_ValidateHit.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHRN_ValidateHit.OuterSingleton, Z_Construct_UClass_UHRN_ValidateHit_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHRN_ValidateHit.OuterSingleton;
}
UHRN_ValidateHit::UHRN_ValidateHit(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHRN_ValidateHit);
UHRN_ValidateHit::~UHRN_ValidateHit() {}
// ********** End Class UHRN_ValidateHit ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ValidateHit_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHRN_ValidateHit, UHRN_ValidateHit::StaticClass, TEXT("UHRN_ValidateHit"), &Z_Registration_Info_UClass_UHRN_ValidateHit, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHRN_ValidateHit), 1174034374U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ValidateHit_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ValidateHit_h__Script_HitRegisterCore_1267526965{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ValidateHit_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_ValidateHit_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
