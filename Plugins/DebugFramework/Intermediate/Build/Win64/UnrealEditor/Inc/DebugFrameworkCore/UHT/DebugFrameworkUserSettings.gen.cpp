// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFramework/DebugFrameworkUserSettings.h"
#include "DebugFramework/DebugFrameworkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkUserSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkUserSettings();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkUserSettings_NoRegister();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkUserSettings **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkUserSettings;
UClass* UDebugFrameworkUserSettings::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkUserSettings;
	if (!Z_Registration_Info_UClass_UDebugFrameworkUserSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkUserSettings"),
			Z_Registration_Info_UClass_UDebugFrameworkUserSettings.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkUserSettings,
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
	return Z_Registration_Info_UClass_UDebugFrameworkUserSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkUserSettings_NoRegister()
{
	return UDebugFrameworkUserSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkUserSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFramework/DebugFrameworkUserSettings.h" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkUserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVisible_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkUserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PanelLayouts_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkUserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HiddenPanelIds_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkUserSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkUserSettings constinit property declarations **************
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PanelLayouts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PanelLayouts;
	static const UECodeGen_Private::FNamePropertyParams NewProp_HiddenPanelIds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HiddenPanelIds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkUserSettings constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkUserSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkUserSettings_Statics

// ********** Begin Class UDebugFrameworkUserSettings Property Definitions *************************
void Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((UDebugFrameworkUserSettings*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkUserSettings), &Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVisible_MetaData), NewProp_bVisible_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_PanelLayouts_Inner = { "PanelLayouts", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout, METADATA_PARAMS(0, nullptr) }; // 2498118317
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_PanelLayouts = { "PanelLayouts", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUserSettings, PanelLayouts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PanelLayouts_MetaData), NewProp_PanelLayouts_MetaData) }; // 2498118317
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_HiddenPanelIds_Inner = { "HiddenPanelIds", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_HiddenPanelIds = { "HiddenPanelIds", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUserSettings, HiddenPanelIds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HiddenPanelIds_MetaData), NewProp_HiddenPanelIds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_bVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_PanelLayouts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_PanelLayouts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_HiddenPanelIds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::NewProp_HiddenPanelIds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkUserSettings Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::ClassParams = {
	&UDebugFrameworkUserSettings::StaticClass,
	"GameUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::Class_MetaDataParams)
};
void UDebugFrameworkUserSettings::StaticRegisterNativesUDebugFrameworkUserSettings()
{
}
UClass* Z_Construct_UClass_UDebugFrameworkUserSettings()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkUserSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkUserSettings.OuterSingleton, Z_Construct_UClass_UDebugFrameworkUserSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkUserSettings.OuterSingleton;
}
UDebugFrameworkUserSettings::UDebugFrameworkUserSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkUserSettings);
UDebugFrameworkUserSettings::~UDebugFrameworkUserSettings() {}
// ********** End Class UDebugFrameworkUserSettings ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h__Script_DebugFrameworkCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkUserSettings, UDebugFrameworkUserSettings::StaticClass, TEXT("UDebugFrameworkUserSettings"), &Z_Registration_Info_UClass_UDebugFrameworkUserSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkUserSettings), 2940246975U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h__Script_DebugFrameworkCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h__Script_DebugFrameworkCore_41599735{
	TEXT("/Script/DebugFrameworkCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h__Script_DebugFrameworkCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h__Script_DebugFrameworkCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
