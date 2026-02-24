// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterTargetingProfile.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterTargetingProfile() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTargetingProfile();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHitTargetMode ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitTargetMode;
static UEnum* EHitTargetMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitTargetMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitTargetMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("EHitTargetMode"));
	}
	return Z_Registration_Info_UEnum_EHitTargetMode.OuterSingleton;
}
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitTargetMode>()
{
	return EHitTargetMode_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "All.Name", "EHitTargetMode::All" },
		{ "AllExceptSelf.Name", "EHitTargetMode::AllExceptSelf" },
		{ "AlliesExceptSelf.Name", "EHitTargetMode::AlliesExceptSelf" },
		{ "AlliesOnly.Name", "EHitTargetMode::AlliesOnly" },
		{ "BlueprintType", "true" },
		{ "EnemiesOnly.Name", "EHitTargetMode::EnemiesOnly" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTargetingProfile.h" },
		{ "SelfOnly.Name", "EHitTargetMode::SelfOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitTargetMode::All", (int64)EHitTargetMode::All },
		{ "EHitTargetMode::AllExceptSelf", (int64)EHitTargetMode::AllExceptSelf },
		{ "EHitTargetMode::AlliesOnly", (int64)EHitTargetMode::AlliesOnly },
		{ "EHitTargetMode::EnemiesOnly", (int64)EHitTargetMode::EnemiesOnly },
		{ "EHitTargetMode::AlliesExceptSelf", (int64)EHitTargetMode::AlliesExceptSelf },
		{ "EHitTargetMode::SelfOnly", (int64)EHitTargetMode::SelfOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	"EHitTargetMode",
	"EHitTargetMode",
	Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode()
{
	if (!Z_Registration_Info_UEnum_EHitTargetMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitTargetMode.InnerSingleton, Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitTargetMode.InnerSingleton;
}
// ********** End Enum EHitTargetMode **************************************************************

// ********** Begin Enum EHitTargetUnknownPolicy ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitTargetUnknownPolicy;
static UEnum* EHitTargetUnknownPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("EHitTargetUnknownPolicy"));
	}
	return Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.OuterSingleton;
}
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitTargetUnknownPolicy>()
{
	return EHitTargetUnknownPolicy_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Allow.Name", "EHitTargetUnknownPolicy::Allow" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTargetingProfile.h" },
		{ "Reject.Name", "EHitTargetUnknownPolicy::Reject" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitTargetUnknownPolicy::Allow", (int64)EHitTargetUnknownPolicy::Allow },
		{ "EHitTargetUnknownPolicy::Reject", (int64)EHitTargetUnknownPolicy::Reject },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	"EHitTargetUnknownPolicy",
	"EHitTargetUnknownPolicy",
	Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy()
{
	if (!Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.InnerSingleton, Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitTargetUnknownPolicy.InnerSingleton;
}
// ********** End Enum EHitTargetUnknownPolicy *****************************************************

// ********** Begin Class UHitRegisterTargetingProfile *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterTargetingProfile;
UClass* UHitRegisterTargetingProfile::GetPrivateStaticClass()
{
	using TClass = UHitRegisterTargetingProfile;
	if (!Z_Registration_Info_UClass_UHitRegisterTargetingProfile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterTargetingProfile"),
			Z_Registration_Info_UClass_UHitRegisterTargetingProfile.InnerSingleton,
			StaticRegisterNativesUHitRegisterTargetingProfile,
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
	return Z_Registration_Info_UClass_UHitRegisterTargetingProfile.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister()
{
	return UHitRegisterTargetingProfile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterTargetingProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HitRegisterCollision/HitRegisterTargetingProfile.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTargetingProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target selection mode. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTargetingProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target selection mode." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnknownTeamPolicy_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Behavior when team info is missing on either source or target. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTargetingProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Behavior when team info is missing on either source or target." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterTargetingProfile constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UnknownTeamPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UnknownTeamPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterTargetingProfile constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterTargetingProfile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterTargetingProfile_Statics

// ********** Begin Class UHitRegisterTargetingProfile Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterTargetingProfile, Mode), Z_Construct_UEnum_HitRegisterCollision_EHitTargetMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) }; // 42904243
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_UnknownTeamPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_UnknownTeamPolicy = { "UnknownTeamPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterTargetingProfile, UnknownTeamPolicy), Z_Construct_UEnum_HitRegisterCollision_EHitTargetUnknownPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnknownTeamPolicy_MetaData), NewProp_UnknownTeamPolicy_MetaData) }; // 2844014979
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_UnknownTeamPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::NewProp_UnknownTeamPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterTargetingProfile Property Definitions **************************
UObject* (*const Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::ClassParams = {
	&UHitRegisterTargetingProfile::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::Class_MetaDataParams)
};
void UHitRegisterTargetingProfile::StaticRegisterNativesUHitRegisterTargetingProfile()
{
}
UClass* Z_Construct_UClass_UHitRegisterTargetingProfile()
{
	if (!Z_Registration_Info_UClass_UHitRegisterTargetingProfile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterTargetingProfile.OuterSingleton, Z_Construct_UClass_UHitRegisterTargetingProfile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterTargetingProfile.OuterSingleton;
}
UHitRegisterTargetingProfile::UHitRegisterTargetingProfile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterTargetingProfile);
UHitRegisterTargetingProfile::~UHitRegisterTargetingProfile() {}
// ********** End Class UHitRegisterTargetingProfile ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHitTargetMode_StaticEnum, TEXT("EHitTargetMode"), &Z_Registration_Info_UEnum_EHitTargetMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 42904243U) },
		{ EHitTargetUnknownPolicy_StaticEnum, TEXT("EHitTargetUnknownPolicy"), &Z_Registration_Info_UEnum_EHitTargetUnknownPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2844014979U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterTargetingProfile, UHitRegisterTargetingProfile::StaticClass, TEXT("UHitRegisterTargetingProfile"), &Z_Registration_Info_UClass_UHitRegisterTargetingProfile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterTargetingProfile), 3632218600U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_2991975326{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h__Script_HitRegisterCollision_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
