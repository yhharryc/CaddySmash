// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterCollisionSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterCollisionSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterCollisionSettings();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterCollisionSettings_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterCollisionSettings Function Get *******************************
struct Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics
{
	struct HitRegisterCollisionSettings_eventGet_Parms
	{
		const UHitRegisterCollisionSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Get constinit property declarations ***********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Get constinit property declarations *************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Get Property Definitions **********************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterCollisionSettings_eventGet_Parms, ReturnValue), Z_Construct_UClass_UHitRegisterCollisionSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::PropPointers) < 2048);
// ********** End Function Get Property Definitions ************************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterCollisionSettings, nullptr, "Get", 	Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::HitRegisterCollisionSettings_eventGet_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::HitRegisterCollisionSettings_eventGet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterCollisionSettings_Get()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterCollisionSettings_Get_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterCollisionSettings::execGet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UHitRegisterCollisionSettings**)Z_Param__Result=UHitRegisterCollisionSettings::Get();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterCollisionSettings Function Get *********************************

// ********** Begin Class UHitRegisterCollisionSettings ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterCollisionSettings;
UClass* UHitRegisterCollisionSettings::GetPrivateStaticClass()
{
	using TClass = UHitRegisterCollisionSettings;
	if (!Z_Registration_Info_UClass_UHitRegisterCollisionSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterCollisionSettings"),
			Z_Registration_Info_UClass_UHitRegisterCollisionSettings.InnerSingleton,
			StaticRegisterNativesUHitRegisterCollisionSettings,
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
	return Z_Registration_Info_UClass_UHitRegisterCollisionSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterCollisionSettings_NoRegister()
{
	return UHitRegisterCollisionSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterCollisionSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HitRegisterCollision/HitRegisterCollisionSettings.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelationResolver_MetaData[] = {
		{ "Category", "HitRegister|Team" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional relation resolver asset with strong type constraints. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional relation resolver asset with strong type constraints." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterCollisionSettings constinit property declarations ************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RelationResolver;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterCollisionSettings constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Get"), .Pointer = &UHitRegisterCollisionSettings::execGet },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterCollisionSettings_Get, "Get" }, // 3582866831
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterCollisionSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterCollisionSettings_Statics

// ********** Begin Class UHitRegisterCollisionSettings Property Definitions ***********************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::NewProp_RelationResolver = { "RelationResolver", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterCollisionSettings, RelationResolver), Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelationResolver_MetaData), NewProp_RelationResolver_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::NewProp_RelationResolver,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterCollisionSettings Property Definitions *************************
UObject* (*const Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::ClassParams = {
	&UHitRegisterCollisionSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::Class_MetaDataParams)
};
void UHitRegisterCollisionSettings::StaticRegisterNativesUHitRegisterCollisionSettings()
{
	UClass* Class = UHitRegisterCollisionSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterCollisionSettings()
{
	if (!Z_Registration_Info_UClass_UHitRegisterCollisionSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterCollisionSettings.OuterSingleton, Z_Construct_UClass_UHitRegisterCollisionSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterCollisionSettings.OuterSingleton;
}
UHitRegisterCollisionSettings::UHitRegisterCollisionSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterCollisionSettings);
UHitRegisterCollisionSettings::~UHitRegisterCollisionSettings() {}
// ********** End Class UHitRegisterCollisionSettings **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSettings_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterCollisionSettings, UHitRegisterCollisionSettings::StaticClass, TEXT("UHitRegisterCollisionSettings"), &Z_Registration_Info_UClass_UHitRegisterCollisionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterCollisionSettings), 2820021920U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSettings_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSettings_h__Script_HitRegisterCollision_2304569910{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSettings_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSettings_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
