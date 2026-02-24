// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterPipeline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterPipeline() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterPipeline *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterPipeline;
UClass* UHitRegisterPipeline::GetPrivateStaticClass()
{
	using TClass = UHitRegisterPipeline;
	if (!Z_Registration_Info_UClass_UHitRegisterPipeline.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterPipeline"),
			Z_Registration_Info_UClass_UHitRegisterPipeline.InnerSingleton,
			StaticRegisterNativesUHitRegisterPipeline,
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
	return Z_Registration_Info_UClass_UHitRegisterPipeline.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister()
{
	return UHitRegisterPipeline::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterPipeline_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Data-driven hit registration pipeline. Nodes are instanced so each asset can hold per-node tuning.\n */" },
#endif
		{ "IncludePath", "HitRegister/HitRegisterPipeline.h" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterPipeline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Data-driven hit registration pipeline. Nodes are instanced so each asset can hold per-node tuning." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nodes_Inner_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterPipeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Nodes_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterPipeline.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterPipeline constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Nodes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Nodes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterPipeline constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterPipeline>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterPipeline_Statics

// ********** Begin Class UHitRegisterPipeline Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHitRegisterPipeline_Statics::NewProp_Nodes_Inner = { "Nodes", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UHitRegisterNode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_Inner_MetaData), NewProp_Nodes_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UHitRegisterPipeline_Statics::NewProp_Nodes = { "Nodes", nullptr, (EPropertyFlags)0x011400800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterPipeline, Nodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Nodes_MetaData), NewProp_Nodes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterPipeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterPipeline_Statics::NewProp_Nodes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterPipeline_Statics::NewProp_Nodes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterPipeline_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterPipeline Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UHitRegisterPipeline_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterPipeline_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterPipeline_Statics::ClassParams = {
	&UHitRegisterPipeline::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHitRegisterPipeline_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterPipeline_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterPipeline_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterPipeline_Statics::Class_MetaDataParams)
};
void UHitRegisterPipeline::StaticRegisterNativesUHitRegisterPipeline()
{
}
UClass* Z_Construct_UClass_UHitRegisterPipeline()
{
	if (!Z_Registration_Info_UClass_UHitRegisterPipeline.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterPipeline.OuterSingleton, Z_Construct_UClass_UHitRegisterPipeline_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterPipeline.OuterSingleton;
}
UHitRegisterPipeline::UHitRegisterPipeline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterPipeline);
UHitRegisterPipeline::~UHitRegisterPipeline() {}
// ********** End Class UHitRegisterPipeline *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterPipeline_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterPipeline, UHitRegisterPipeline::StaticClass, TEXT("UHitRegisterPipeline"), &Z_Registration_Info_UClass_UHitRegisterPipeline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterPipeline), 2992583917U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterPipeline_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterPipeline_h__Script_HitRegisterCore_1390584007{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterPipeline_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterPipeline_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
