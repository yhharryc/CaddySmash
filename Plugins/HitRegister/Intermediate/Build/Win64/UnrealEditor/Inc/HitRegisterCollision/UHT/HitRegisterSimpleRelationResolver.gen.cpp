// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterSimpleRelationResolver.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterSimpleRelationResolver() {}

// ********** Begin Cross Module References ********************************************************
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterSimpleRelationResolver();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterSimpleRelationResolver_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterSimpleRelationResolver ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver;
UClass* UHitRegisterSimpleRelationResolver::GetPrivateStaticClass()
{
	using TClass = UHitRegisterSimpleRelationResolver;
	if (!Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterSimpleRelationResolver"),
			Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.InnerSingleton,
			StaticRegisterNativesUHitRegisterSimpleRelationResolver,
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
	return Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterSimpleRelationResolver_NoRegister()
{
	return UHitRegisterSimpleRelationResolver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default resolver: same TeamId => Ally, different => Enemy, missing => Unknown. */" },
#endif
		{ "IncludePath", "HitRegisterCollision/HitRegisterSimpleRelationResolver.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterSimpleRelationResolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default resolver: same TeamId => Ally, different => Enemy, missing => Unknown." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterSimpleRelationResolver constinit property declarations *******
// ********** End Class UHitRegisterSimpleRelationResolver constinit property declarations *********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterSimpleRelationResolver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHitRegisterRelationResolverAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::ClassParams = {
	&UHitRegisterSimpleRelationResolver::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::Class_MetaDataParams)
};
void UHitRegisterSimpleRelationResolver::StaticRegisterNativesUHitRegisterSimpleRelationResolver()
{
}
UClass* Z_Construct_UClass_UHitRegisterSimpleRelationResolver()
{
	if (!Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.OuterSingleton, Z_Construct_UClass_UHitRegisterSimpleRelationResolver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver.OuterSingleton;
}
UHitRegisterSimpleRelationResolver::UHitRegisterSimpleRelationResolver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterSimpleRelationResolver);
UHitRegisterSimpleRelationResolver::~UHitRegisterSimpleRelationResolver() {}
// ********** End Class UHitRegisterSimpleRelationResolver *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterSimpleRelationResolver_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterSimpleRelationResolver, UHitRegisterSimpleRelationResolver::StaticClass, TEXT("UHitRegisterSimpleRelationResolver"), &Z_Registration_Info_UClass_UHitRegisterSimpleRelationResolver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterSimpleRelationResolver), 203040893U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterSimpleRelationResolver_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterSimpleRelationResolver_h__Script_HitRegisterCollision_2624612270{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterSimpleRelationResolver_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterSimpleRelationResolver_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
