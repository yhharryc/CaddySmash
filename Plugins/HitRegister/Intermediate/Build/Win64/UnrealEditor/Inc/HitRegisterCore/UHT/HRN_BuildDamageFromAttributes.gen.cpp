// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/Nodes/HRN_BuildDamageFromAttributes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHRN_BuildDamageFromAttributes() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_BuildDamageFromAttributes();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHRN_BuildDamageFromAttributes_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHRN_BuildDamageFromAttributes *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes;
UClass* UHRN_BuildDamageFromAttributes::GetPrivateStaticClass()
{
	using TClass = UHRN_BuildDamageFromAttributes;
	if (!Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HRN_BuildDamageFromAttributes"),
			Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.InnerSingleton,
			StaticRegisterNativesUHRN_BuildDamageFromAttributes,
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
	return Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.InnerSingleton;
}
UClass* Z_Construct_UClass_UHRN_BuildDamageFromAttributes_NoRegister()
{
	return UHRN_BuildDamageFromAttributes::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Simple damage builder: RawDamage = BaseDamage + FlatBonus ; then * (1+PercentBonus).\n * All bonuses are read from Attack.Attributes using the configured tags.\n */" },
#endif
		{ "IncludePath", "HitRegister/Nodes/HRN_BuildDamageFromAttributes.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_BuildDamageFromAttributes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple damage builder: RawDamage = BaseDamage + FlatBonus ; then * (1+PercentBonus).\nAll bonuses are read from Attack.Attributes using the configured tags." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlatBonusTag_MetaData[] = {
		{ "Category", "HitRegister|Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Added directly to base damage. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_BuildDamageFromAttributes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Added directly to base damage." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PercentBonusTag_MetaData[] = {
		{ "Category", "HitRegister|Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Percentage bonus, expected 0.2 for +20%. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_BuildDamageFromAttributes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Percentage bonus, expected 0.2 for +20%." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MultiplierTag_MetaData[] = {
		{ "Category", "HitRegister|Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional multiplier applied at end, expected 1.5 for +50%. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/Nodes/HRN_BuildDamageFromAttributes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional multiplier applied at end, expected 1.5 for +50%." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHRN_BuildDamageFromAttributes constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlatBonusTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PercentBonusTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MultiplierTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHRN_BuildDamageFromAttributes constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHRN_BuildDamageFromAttributes>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics

// ********** Begin Class UHRN_BuildDamageFromAttributes Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_FlatBonusTag = { "FlatBonusTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHRN_BuildDamageFromAttributes, FlatBonusTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlatBonusTag_MetaData), NewProp_FlatBonusTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_PercentBonusTag = { "PercentBonusTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHRN_BuildDamageFromAttributes, PercentBonusTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PercentBonusTag_MetaData), NewProp_PercentBonusTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_MultiplierTag = { "MultiplierTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHRN_BuildDamageFromAttributes, MultiplierTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MultiplierTag_MetaData), NewProp_MultiplierTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_FlatBonusTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_PercentBonusTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::NewProp_MultiplierTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::PropPointers) < 2048);
// ********** End Class UHRN_BuildDamageFromAttributes Property Definitions ************************
UObject* (*const Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHitRegisterNode,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::ClassParams = {
	&UHRN_BuildDamageFromAttributes::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::Class_MetaDataParams), Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::Class_MetaDataParams)
};
void UHRN_BuildDamageFromAttributes::StaticRegisterNativesUHRN_BuildDamageFromAttributes()
{
}
UClass* Z_Construct_UClass_UHRN_BuildDamageFromAttributes()
{
	if (!Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.OuterSingleton, Z_Construct_UClass_UHRN_BuildDamageFromAttributes_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHRN_BuildDamageFromAttributes);
UHRN_BuildDamageFromAttributes::~UHRN_BuildDamageFromAttributes() {}
// ********** End Class UHRN_BuildDamageFromAttributes *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_BuildDamageFromAttributes_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHRN_BuildDamageFromAttributes, UHRN_BuildDamageFromAttributes::StaticClass, TEXT("UHRN_BuildDamageFromAttributes"), &Z_Registration_Info_UClass_UHRN_BuildDamageFromAttributes, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHRN_BuildDamageFromAttributes), 299632262U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_BuildDamageFromAttributes_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_BuildDamageFromAttributes_h__Script_HitRegisterCore_3897807091{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_BuildDamageFromAttributes_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_Nodes_HRN_BuildDamageFromAttributes_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
