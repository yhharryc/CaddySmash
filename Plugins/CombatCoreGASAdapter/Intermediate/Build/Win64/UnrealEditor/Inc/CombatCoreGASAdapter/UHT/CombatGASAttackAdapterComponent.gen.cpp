// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/CombatGASAttackAdapterComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCombatGASAttackAdapterComponent() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UCombatAttackAdapter_NoRegister();
COMBATCOREGASADAPTER_API UClass* Z_Construct_UClass_UCombatGASAttackAdapterComponent();
COMBATCOREGASADAPTER_API UClass* Z_Construct_UClass_UCombatGASAttackAdapterComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_CombatCoreGASAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCombatGASAttackAdapterComponent *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent;
UClass* UCombatGASAttackAdapterComponent::GetPrivateStaticClass()
{
	using TClass = UCombatGASAttackAdapterComponent;
	if (!Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CombatGASAttackAdapterComponent"),
			Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.InnerSingleton,
			StaticRegisterNativesUCombatGASAttackAdapterComponent,
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
	return Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UCombatGASAttackAdapterComponent_NoRegister()
{
	return UCombatGASAttackAdapterComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Combat" },
		{ "IncludePath", "Combat/CombatGASAttackAdapterComponent.h" },
		{ "ModuleRelativePath", "Public/Combat/CombatGASAttackAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGrantAbility_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, grant the profile ability when missing. */" },
#endif
		{ "ModuleRelativePath", "Public/Combat/CombatGASAttackAdapterComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, grant the profile ability when missing." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCombatGASAttackAdapterComponent constinit property declarations *********
	static void NewProp_bAutoGrantAbility_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGrantAbility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCombatGASAttackAdapterComponent constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatGASAttackAdapterComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics

// ********** Begin Class UCombatGASAttackAdapterComponent Property Definitions ********************
void Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::NewProp_bAutoGrantAbility_SetBit(void* Obj)
{
	((UCombatGASAttackAdapterComponent*)Obj)->bAutoGrantAbility = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::NewProp_bAutoGrantAbility = { "bAutoGrantAbility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCombatGASAttackAdapterComponent), &Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::NewProp_bAutoGrantAbility_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGrantAbility_MetaData), NewProp_bAutoGrantAbility_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::NewProp_bAutoGrantAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::PropPointers) < 2048);
// ********** End Class UCombatGASAttackAdapterComponent Property Definitions **********************
UObject* (*const Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCoreGASAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UCombatAttackAdapter_NoRegister, (int32)VTABLE_OFFSET(UCombatGASAttackAdapterComponent, ICombatAttackAdapter), false },  // 2480621142
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::ClassParams = {
	&UCombatGASAttackAdapterComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::Class_MetaDataParams)
};
void UCombatGASAttackAdapterComponent::StaticRegisterNativesUCombatGASAttackAdapterComponent()
{
}
UClass* Z_Construct_UClass_UCombatGASAttackAdapterComponent()
{
	if (!Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.OuterSingleton, Z_Construct_UClass_UCombatGASAttackAdapterComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCombatGASAttackAdapterComponent);
UCombatGASAttackAdapterComponent::~UCombatGASAttackAdapterComponent() {}
// ********** End Class UCombatGASAttackAdapterComponent *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_CombatGASAttackAdapterComponent_h__Script_CombatCoreGASAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCombatGASAttackAdapterComponent, UCombatGASAttackAdapterComponent::StaticClass, TEXT("UCombatGASAttackAdapterComponent"), &Z_Registration_Info_UClass_UCombatGASAttackAdapterComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatGASAttackAdapterComponent), 3342458351U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_CombatGASAttackAdapterComponent_h__Script_CombatCoreGASAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_CombatGASAttackAdapterComponent_h__Script_CombatCoreGASAdapter_2834874393{
	TEXT("/Script/CombatCoreGASAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_CombatGASAttackAdapterComponent_h__Script_CombatCoreGASAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_CombatGASAttackAdapterComponent_h__Script_CombatCoreGASAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
