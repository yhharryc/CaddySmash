// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterHurtBoxComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterHurtBoxComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHurtBoxComponent();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHurtBoxComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterHurtBoxComponent *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent;
UClass* UHitRegisterHurtBoxComponent::GetPrivateStaticClass()
{
	using TClass = UHitRegisterHurtBoxComponent;
	if (!Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterHurtBoxComponent"),
			Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.InnerSingleton,
			StaticRegisterNativesUHitRegisterHurtBoxComponent,
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
	return Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterHurtBoxComponent_NoRegister()
{
	return UHitRegisterHurtBoxComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "HitRegister" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger VirtualTexture" },
		{ "IncludePath", "HitRegisterCollision/HitRegisterHurtBoxComponent.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHurtBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtBoxId_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHurtBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHurtBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageMultiplier_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHurtBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterHurtBoxComponent constinit property declarations *************
	static const UECodeGen_Private::FNamePropertyParams NewProp_HurtBoxId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterHurtBoxComponent constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterHurtBoxComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics

// ********** Begin Class UHitRegisterHurtBoxComponent Property Definitions ************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_HurtBoxId = { "HurtBoxId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHurtBoxComponent, HurtBoxId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtBoxId_MetaData), NewProp_HurtBoxId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHurtBoxComponent, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_DamageMultiplier = { "DamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHurtBoxComponent, DamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMultiplier_MetaData), NewProp_DamageMultiplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_HurtBoxId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_Tags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::NewProp_DamageMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterHurtBoxComponent Property Definitions **************************
UObject* (*const Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBoxComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::ClassParams = {
	&UHitRegisterHurtBoxComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::Class_MetaDataParams)
};
void UHitRegisterHurtBoxComponent::StaticRegisterNativesUHitRegisterHurtBoxComponent()
{
}
UClass* Z_Construct_UClass_UHitRegisterHurtBoxComponent()
{
	if (!Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.OuterSingleton, Z_Construct_UClass_UHitRegisterHurtBoxComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterHurtBoxComponent);
UHitRegisterHurtBoxComponent::~UHitRegisterHurtBoxComponent() {}
// ********** End Class UHitRegisterHurtBoxComponent ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHurtBoxComponent_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterHurtBoxComponent, UHitRegisterHurtBoxComponent::StaticClass, TEXT("UHitRegisterHurtBoxComponent"), &Z_Registration_Info_UClass_UHitRegisterHurtBoxComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterHurtBoxComponent), 3599286225U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHurtBoxComponent_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHurtBoxComponent_h__Script_HitRegisterCollision_64252619{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHurtBoxComponent_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHurtBoxComponent_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
