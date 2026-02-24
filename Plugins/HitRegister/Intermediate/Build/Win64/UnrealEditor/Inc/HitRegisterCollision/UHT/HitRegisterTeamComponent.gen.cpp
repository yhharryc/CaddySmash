// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterTeamComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterTeamComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamComponent();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterTeamComponent ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterTeamComponent;
UClass* UHitRegisterTeamComponent::GetPrivateStaticClass()
{
	using TClass = UHitRegisterTeamComponent;
	if (!Z_Registration_Info_UClass_UHitRegisterTeamComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterTeamComponent"),
			Z_Registration_Info_UClass_UHitRegisterTeamComponent.InnerSingleton,
			StaticRegisterNativesUHitRegisterTeamComponent,
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
	return Z_Registration_Info_UClass_UHitRegisterTeamComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterTeamComponent_NoRegister()
{
	return UHitRegisterTeamComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterTeamComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Simple team component for projects without a custom team system. */" },
#endif
		{ "IncludePath", "HitRegisterCollision/HitRegisterTeamComponent.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTeamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple team component for projects without a custom team system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TeamId_MetaData[] = {
		{ "Category", "HitRegister|Team" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTeamComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterTeamComponent constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_TeamId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterTeamComponent constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterTeamComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterTeamComponent_Statics

// ********** Begin Class UHitRegisterTeamComponent Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UHitRegisterTeamComponent_Statics::NewProp_TeamId = { "TeamId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterTeamComponent, TeamId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TeamId_MetaData), NewProp_TeamId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterTeamComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterTeamComponent_Statics::NewProp_TeamId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamComponent_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterTeamComponent Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UHitRegisterTeamComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UHitRegisterTeamComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister, (int32)VTABLE_OFFSET(UHitRegisterTeamComponent, IHitRegisterTeamAgent), false },  // 700600486
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterTeamComponent_Statics::ClassParams = {
	&UHitRegisterTeamComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHitRegisterTeamComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterTeamComponent_Statics::Class_MetaDataParams)
};
void UHitRegisterTeamComponent::StaticRegisterNativesUHitRegisterTeamComponent()
{
}
UClass* Z_Construct_UClass_UHitRegisterTeamComponent()
{
	if (!Z_Registration_Info_UClass_UHitRegisterTeamComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterTeamComponent.OuterSingleton, Z_Construct_UClass_UHitRegisterTeamComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterTeamComponent.OuterSingleton;
}
UHitRegisterTeamComponent::UHitRegisterTeamComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterTeamComponent);
UHitRegisterTeamComponent::~UHitRegisterTeamComponent() {}
// ********** End Class UHitRegisterTeamComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterTeamComponent, UHitRegisterTeamComponent::StaticClass, TEXT("UHitRegisterTeamComponent"), &Z_Registration_Info_UClass_UHitRegisterTeamComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterTeamComponent), 3171920977U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h__Script_HitRegisterCollision_1291839650{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
