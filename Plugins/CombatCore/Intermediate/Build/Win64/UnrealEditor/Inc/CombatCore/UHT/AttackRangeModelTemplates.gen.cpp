// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackRangeModelTemplates.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackRangeModelTemplates() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_MeleeThrust();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_MeleeThrust_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_RangedHitscan();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_RangedHitscan_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAttackRangeModel_MeleeThrust ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust;
UClass* UAttackRangeModel_MeleeThrust::GetPrivateStaticClass()
{
	using TClass = UAttackRangeModel_MeleeThrust;
	if (!Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackRangeModel_MeleeThrust"),
			Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.InnerSingleton,
			StaticRegisterNativesUAttackRangeModel_MeleeThrust,
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
	return Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackRangeModel_MeleeThrust_NoRegister()
{
	return UAttackRangeModel_MeleeThrust::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Combat/AttackRangeModelTemplates.h" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModelTemplates.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackRangeModel_MeleeThrust constinit property declarations ************
// ********** End Class UAttackRangeModel_MeleeThrust constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackRangeModel_MeleeThrust>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics
UObject* (*const Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttackRangeModel,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::ClassParams = {
	&UAttackRangeModel_MeleeThrust::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::Class_MetaDataParams)
};
void UAttackRangeModel_MeleeThrust::StaticRegisterNativesUAttackRangeModel_MeleeThrust()
{
}
UClass* Z_Construct_UClass_UAttackRangeModel_MeleeThrust()
{
	if (!Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.OuterSingleton, Z_Construct_UClass_UAttackRangeModel_MeleeThrust_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackRangeModel_MeleeThrust);
UAttackRangeModel_MeleeThrust::~UAttackRangeModel_MeleeThrust() {}
// ********** End Class UAttackRangeModel_MeleeThrust **********************************************

// ********** Begin Class UAttackRangeModel_RangedHitscan ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan;
UClass* UAttackRangeModel_RangedHitscan::GetPrivateStaticClass()
{
	using TClass = UAttackRangeModel_RangedHitscan;
	if (!Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackRangeModel_RangedHitscan"),
			Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.InnerSingleton,
			StaticRegisterNativesUAttackRangeModel_RangedHitscan,
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
	return Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackRangeModel_RangedHitscan_NoRegister()
{
	return UAttackRangeModel_RangedHitscan::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Combat/AttackRangeModelTemplates.h" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModelTemplates.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackRangeModel_RangedHitscan constinit property declarations **********
// ********** End Class UAttackRangeModel_RangedHitscan constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackRangeModel_RangedHitscan>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics
UObject* (*const Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttackRangeModel,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::ClassParams = {
	&UAttackRangeModel_RangedHitscan::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::Class_MetaDataParams)
};
void UAttackRangeModel_RangedHitscan::StaticRegisterNativesUAttackRangeModel_RangedHitscan()
{
}
UClass* Z_Construct_UClass_UAttackRangeModel_RangedHitscan()
{
	if (!Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.OuterSingleton, Z_Construct_UClass_UAttackRangeModel_RangedHitscan_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackRangeModel_RangedHitscan);
UAttackRangeModel_RangedHitscan::~UAttackRangeModel_RangedHitscan() {}
// ********** End Class UAttackRangeModel_RangedHitscan ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModelTemplates_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackRangeModel_MeleeThrust, UAttackRangeModel_MeleeThrust::StaticClass, TEXT("UAttackRangeModel_MeleeThrust"), &Z_Registration_Info_UClass_UAttackRangeModel_MeleeThrust, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackRangeModel_MeleeThrust), 2390282376U) },
		{ Z_Construct_UClass_UAttackRangeModel_RangedHitscan, UAttackRangeModel_RangedHitscan::StaticClass, TEXT("UAttackRangeModel_RangedHitscan"), &Z_Registration_Info_UClass_UAttackRangeModel_RangedHitscan, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackRangeModel_RangedHitscan), 3112361703U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModelTemplates_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModelTemplates_h__Script_CombatCore_4240930894{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModelTemplates_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModelTemplates_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
