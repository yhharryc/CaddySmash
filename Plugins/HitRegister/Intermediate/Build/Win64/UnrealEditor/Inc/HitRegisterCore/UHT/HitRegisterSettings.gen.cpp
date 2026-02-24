// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterSettings.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterPipeline_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterSettings();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterSettings Function Get ****************************************
struct Z_Construct_UFunction_UHitRegisterSettings_Get_Statics
{
	struct HitRegisterSettings_eventGet_Parms
	{
		const UHitRegisterSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Convenience: returns settings singleton. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convenience: returns settings singleton." },
#endif
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterSettings_eventGet_Parms, ReturnValue), Z_Construct_UClass_UHitRegisterSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::PropPointers) < 2048);
// ********** End Function Get Property Definitions ************************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterSettings, nullptr, "Get", 	Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::HitRegisterSettings_eventGet_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::HitRegisterSettings_eventGet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterSettings_Get()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterSettings_Get_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterSettings::execGet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UHitRegisterSettings**)Z_Param__Result=UHitRegisterSettings::Get();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterSettings Function Get ******************************************

// ********** Begin Class UHitRegisterSettings *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterSettings;
UClass* UHitRegisterSettings::GetPrivateStaticClass()
{
	using TClass = UHitRegisterSettings;
	if (!Z_Registration_Info_UClass_UHitRegisterSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterSettings"),
			Z_Registration_Info_UClass_UHitRegisterSettings.InnerSingleton,
			StaticRegisterNativesUHitRegisterSettings,
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
	return Z_Registration_Info_UClass_UHitRegisterSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterSettings_NoRegister()
{
	return UHitRegisterSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HitRegister/HitRegisterSettings.h" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPipeline_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default pipeline used by helper functions if none is provided. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default pipeline used by helper functions if none is provided." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageSetByCallerTag_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default set-by-caller tag used by GAS adapter (can be overridden per component). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default set-by-caller tag used by GAS adapter (can be overridden per component)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterSettings constinit property declarations *********************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultPipeline;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DamageSetByCallerTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterSettings constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Get"), .Pointer = &UHitRegisterSettings::execGet },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterSettings_Get, "Get" }, // 681364096
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterSettings_Statics

// ********** Begin Class UHitRegisterSettings Property Definitions ********************************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UHitRegisterSettings_Statics::NewProp_DefaultPipeline = { "DefaultPipeline", nullptr, (EPropertyFlags)0x0014000000004015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterSettings, DefaultPipeline), Z_Construct_UClass_UHitRegisterPipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPipeline_MetaData), NewProp_DefaultPipeline_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHitRegisterSettings_Statics::NewProp_DamageSetByCallerTag = { "DamageSetByCallerTag", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterSettings, DamageSetByCallerTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageSetByCallerTag_MetaData), NewProp_DamageSetByCallerTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterSettings_Statics::NewProp_DefaultPipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterSettings_Statics::NewProp_DamageSetByCallerTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSettings_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterSettings Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UHitRegisterSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterSettings_Statics::ClassParams = {
	&UHitRegisterSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UHitRegisterSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterSettings_Statics::Class_MetaDataParams)
};
void UHitRegisterSettings::StaticRegisterNativesUHitRegisterSettings()
{
	UClass* Class = UHitRegisterSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterSettings_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterSettings()
{
	if (!Z_Registration_Info_UClass_UHitRegisterSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterSettings.OuterSingleton, Z_Construct_UClass_UHitRegisterSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterSettings);
UHitRegisterSettings::~UHitRegisterSettings() {}
// ********** End Class UHitRegisterSettings *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSettings_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterSettings, UHitRegisterSettings::StaticClass, TEXT("UHitRegisterSettings"), &Z_Registration_Info_UClass_UHitRegisterSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterSettings), 1946807178U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSettings_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSettings_h__Script_HitRegisterCore_288459153{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSettings_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSettings_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
