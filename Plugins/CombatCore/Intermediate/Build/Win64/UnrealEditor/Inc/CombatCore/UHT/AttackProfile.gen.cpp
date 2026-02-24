// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackProfile.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackProfile() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAttackProfile ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackProfile;
UClass* UAttackProfile::GetPrivateStaticClass()
{
	using TClass = UAttackProfile;
	if (!Z_Registration_Info_UClass_UAttackProfile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackProfile"),
			Z_Registration_Info_UClass_UAttackProfile.InnerSingleton,
			StaticRegisterNativesUAttackProfile,
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
	return Z_Registration_Info_UClass_UAttackProfile.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackProfile_NoRegister()
{
	return UAttackProfile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Combat/AttackProfile.h" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntentDuration_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommitWindowStart_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommitWindowEnd_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cooldown_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangeModel_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackType_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitConfig_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityClass_MetaData[] = {
		{ "Category", "Combat|Adapter" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Optional adapter-specific attack ability class.\n     * Core does not depend on GAS; adapters interpret this type at runtime.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Combat/AttackProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional adapter-specific attack ability class.\nCore does not depend on GAS; adapters interpret this type at runtime." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackProfile constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IntentDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CommitWindowStart;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CommitWindowEnd;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Cooldown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Range;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangeModel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitConfig;
	static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAttackProfile constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackProfile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackProfile_Statics

// ********** Begin Class UAttackProfile Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_IntentDuration = { "IntentDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, IntentDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntentDuration_MetaData), NewProp_IntentDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_CommitWindowStart = { "CommitWindowStart", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, CommitWindowStart), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommitWindowStart_MetaData), NewProp_CommitWindowStart_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_CommitWindowEnd = { "CommitWindowEnd", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, CommitWindowEnd), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommitWindowEnd_MetaData), NewProp_CommitWindowEnd_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_Cooldown = { "Cooldown", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, Cooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cooldown_MetaData), NewProp_Cooldown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_Range = { "Range", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, Range), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Range_MetaData), NewProp_Range_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_RangeModel = { "RangeModel", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, RangeModel), Z_Construct_UClass_UAttackRangeModel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangeModel_MetaData), NewProp_RangeModel_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_AttackType = { "AttackType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, AttackType), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackType_MetaData), NewProp_AttackType_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_HitConfig = { "HitConfig", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, HitConfig), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitConfig_MetaData), NewProp_HitConfig_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UAttackProfile_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackProfile, AbilityClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityClass_MetaData), NewProp_AbilityClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttackProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_IntentDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_CommitWindowStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_CommitWindowEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_Cooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_Range,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_RangeModel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_AttackType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_HitConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackProfile_Statics::NewProp_AbilityClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackProfile_Statics::PropPointers) < 2048);
// ********** End Class UAttackProfile Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UAttackProfile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackProfile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackProfile_Statics::ClassParams = {
	&UAttackProfile::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAttackProfile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttackProfile_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackProfile_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackProfile_Statics::Class_MetaDataParams)
};
void UAttackProfile::StaticRegisterNativesUAttackProfile()
{
}
UClass* Z_Construct_UClass_UAttackProfile()
{
	if (!Z_Registration_Info_UClass_UAttackProfile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackProfile.OuterSingleton, Z_Construct_UClass_UAttackProfile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackProfile.OuterSingleton;
}
UAttackProfile::UAttackProfile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackProfile);
UAttackProfile::~UAttackProfile() {}
// ********** End Class UAttackProfile *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackProfile, UAttackProfile::StaticClass, TEXT("UAttackProfile"), &Z_Registration_Info_UClass_UAttackProfile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackProfile), 3725370623U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h__Script_CombatCore_2862981731{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
