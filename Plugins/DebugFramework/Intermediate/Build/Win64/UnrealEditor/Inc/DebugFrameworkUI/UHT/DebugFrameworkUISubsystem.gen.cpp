// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkUISubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkUISubsystem() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkControlMenuWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkOverlayWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkPanelWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkToolPanelWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkUISubsystem();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkUISubsystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkUISubsystem ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkUISubsystem;
UClass* UDebugFrameworkUISubsystem::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkUISubsystem;
	if (!Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkUISubsystem"),
			Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkUISubsystem,
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
	return Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkUISubsystem_NoRegister()
{
	return UDebugFrameworkUISubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlayWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlMenuWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PanelWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolPanels_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkUISubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkUISubsystem constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlayWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlMenuWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PanelWidgets_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PanelWidgets_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PanelWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolPanels_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ToolPanels_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ToolPanels;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkUISubsystem constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkUISubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics

// ********** Begin Class UDebugFrameworkUISubsystem Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_OverlayWidget = { "OverlayWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUISubsystem, OverlayWidget), Z_Construct_UClass_UDebugFrameworkOverlayWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlayWidget_MetaData), NewProp_OverlayWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ControlMenuWidget = { "ControlMenuWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUISubsystem, ControlMenuWidget), Z_Construct_UClass_UDebugFrameworkControlMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlMenuWidget_MetaData), NewProp_ControlMenuWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets_ValueProp = { "PanelWidgets", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDebugFrameworkPanelWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets_Key_KeyProp = { "PanelWidgets_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets = { "PanelWidgets", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUISubsystem, PanelWidgets), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PanelWidgets_MetaData), NewProp_PanelWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels_ValueProp = { "ToolPanels", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDebugFrameworkToolPanelWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels_Key_KeyProp = { "ToolPanels_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels = { "ToolPanels", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkUISubsystem, ToolPanels), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolPanels_MetaData), NewProp_ToolPanels_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_OverlayWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ControlMenuWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_PanelWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::NewProp_ToolPanels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkUISubsystem Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTickableWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::ClassParams = {
	&UDebugFrameworkUISubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::Class_MetaDataParams)
};
void UDebugFrameworkUISubsystem::StaticRegisterNativesUDebugFrameworkUISubsystem()
{
}
UClass* Z_Construct_UClass_UDebugFrameworkUISubsystem()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.OuterSingleton, Z_Construct_UClass_UDebugFrameworkUISubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkUISubsystem.OuterSingleton;
}
UDebugFrameworkUISubsystem::UDebugFrameworkUISubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkUISubsystem);
UDebugFrameworkUISubsystem::~UDebugFrameworkUISubsystem() {}
// ********** End Class UDebugFrameworkUISubsystem *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkUISubsystem_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkUISubsystem, UDebugFrameworkUISubsystem::StaticClass, TEXT("UDebugFrameworkUISubsystem"), &Z_Registration_Info_UClass_UDebugFrameworkUISubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkUISubsystem), 1835515500U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkUISubsystem_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkUISubsystem_h__Script_DebugFrameworkUI_47503606{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkUISubsystem_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkUISubsystem_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
