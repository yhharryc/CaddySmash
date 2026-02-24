// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkOverlayWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkOverlayWidget() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkOverlayWidget();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkOverlayWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCanvasPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkOverlayWidget *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget;
UClass* UDebugFrameworkOverlayWidget::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkOverlayWidget;
	if (!Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkOverlayWidget"),
			Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkOverlayWidget,
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
	return Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkOverlayWidget_NoRegister()
{
	return UDebugFrameworkOverlayWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkOverlayWidget.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkOverlayWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootCanvas_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkOverlayWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkOverlayWidget constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootCanvas;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkOverlayWidget constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkOverlayWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics

// ********** Begin Class UDebugFrameworkOverlayWidget Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::NewProp_RootCanvas = { "RootCanvas", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkOverlayWidget, RootCanvas), Z_Construct_UClass_UCanvasPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootCanvas_MetaData), NewProp_RootCanvas_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::NewProp_RootCanvas,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkOverlayWidget Property Definitions **************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::ClassParams = {
	&UDebugFrameworkOverlayWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::Class_MetaDataParams)
};
void UDebugFrameworkOverlayWidget::StaticRegisterNativesUDebugFrameworkOverlayWidget()
{
}
UClass* Z_Construct_UClass_UDebugFrameworkOverlayWidget()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.OuterSingleton, Z_Construct_UClass_UDebugFrameworkOverlayWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget.OuterSingleton;
}
UDebugFrameworkOverlayWidget::UDebugFrameworkOverlayWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkOverlayWidget);
UDebugFrameworkOverlayWidget::~UDebugFrameworkOverlayWidget() {}
// ********** End Class UDebugFrameworkOverlayWidget ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkOverlayWidget_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkOverlayWidget, UDebugFrameworkOverlayWidget::StaticClass, TEXT("UDebugFrameworkOverlayWidget"), &Z_Registration_Info_UClass_UDebugFrameworkOverlayWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkOverlayWidget), 2097610699U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkOverlayWidget_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkOverlayWidget_h__Script_DebugFrameworkUI_359702927{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkOverlayWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkOverlayWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
