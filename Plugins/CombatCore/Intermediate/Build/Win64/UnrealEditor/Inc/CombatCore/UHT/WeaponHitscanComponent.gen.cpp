// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/WeaponHitscanComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWeaponHitscanComponent() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponExecutor_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponHitscanComponent();
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponHitscanComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWeaponHitscanComponent **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UWeaponHitscanComponent;
UClass* UWeaponHitscanComponent::GetPrivateStaticClass()
{
	using TClass = UWeaponHitscanComponent;
	if (!Z_Registration_Info_UClass_UWeaponHitscanComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WeaponHitscanComponent"),
			Z_Registration_Info_UClass_UWeaponHitscanComponent.InnerSingleton,
			StaticRegisterNativesUWeaponHitscanComponent,
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
	return Z_Registration_Info_UClass_UWeaponHitscanComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UWeaponHitscanComponent_NoRegister()
{
	return UWeaponHitscanComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWeaponHitscanComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Combat" },
		{ "IncludePath", "Combat/WeaponHitscanComponent.h" },
		{ "ModuleRelativePath", "Public/Combat/WeaponHitscanComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponHitscanComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponHitscanComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannel_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponHitscanComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebug_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponHitscanComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UWeaponHitscanComponent constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Range;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_bDrawDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebug;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UWeaponHitscanComponent constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWeaponHitscanComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UWeaponHitscanComponent_Statics

// ********** Begin Class UWeaponHitscanComponent Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_Range = { "Range", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponHitscanComponent, Range), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Range_MetaData), NewProp_Range_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponHitscanComponent, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponHitscanComponent, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannel_MetaData), NewProp_TraceChannel_MetaData) }; // 838391399
void Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_bDrawDebug_SetBit(void* Obj)
{
	((UWeaponHitscanComponent*)Obj)->bDrawDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_bDrawDebug = { "bDrawDebug", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWeaponHitscanComponent), &Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_bDrawDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawDebug_MetaData), NewProp_bDrawDebug_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWeaponHitscanComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_Range,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponHitscanComponent_Statics::NewProp_bDrawDebug,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponHitscanComponent_Statics::PropPointers) < 2048);
// ********** End Class UWeaponHitscanComponent Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UWeaponHitscanComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponHitscanComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UWeaponExecutor_NoRegister, (int32)VTABLE_OFFSET(UWeaponHitscanComponent, IWeaponExecutor), false },  // 315122231
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponHitscanComponent_Statics::ClassParams = {
	&UWeaponHitscanComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UWeaponHitscanComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponHitscanComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponHitscanComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponHitscanComponent_Statics::Class_MetaDataParams)
};
void UWeaponHitscanComponent::StaticRegisterNativesUWeaponHitscanComponent()
{
}
UClass* Z_Construct_UClass_UWeaponHitscanComponent()
{
	if (!Z_Registration_Info_UClass_UWeaponHitscanComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponHitscanComponent.OuterSingleton, Z_Construct_UClass_UWeaponHitscanComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWeaponHitscanComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UWeaponHitscanComponent);
UWeaponHitscanComponent::~UWeaponHitscanComponent() {}
// ********** End Class UWeaponHitscanComponent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponHitscanComponent, UWeaponHitscanComponent::StaticClass, TEXT("UWeaponHitscanComponent"), &Z_Registration_Info_UClass_UWeaponHitscanComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponHitscanComponent), 1063169997U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h__Script_CombatCore_709069960{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
