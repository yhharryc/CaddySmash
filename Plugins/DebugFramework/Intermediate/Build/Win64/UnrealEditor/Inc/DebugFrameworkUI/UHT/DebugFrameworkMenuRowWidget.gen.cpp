// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkMenuRowWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkMenuRowWidget() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UHorizontalBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkMenuRowWidget Function HandleToggleClicked ****************
struct Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleToggleClicked constinit property declarations *******************
// ********** End Function HandleToggleClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkMenuRowWidget, nullptr, "HandleToggleClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkMenuRowWidget::execHandleToggleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleToggleClicked();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkMenuRowWidget Function HandleToggleClicked ******************

// ********** Begin Class UDebugFrameworkMenuRowWidget *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget;
UClass* UDebugFrameworkMenuRowWidget::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkMenuRowWidget;
	if (!Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkMenuRowWidget"),
			Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkMenuRowWidget,
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
	return Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister()
{
	return UDebugFrameworkMenuRowWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootRow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleButtonText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkMenuRowWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkMenuRowWidget constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootRow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleButtonText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkMenuRowWidget constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleToggleClicked"), .Pointer = &UDebugFrameworkMenuRowWidget::execHandleToggleClicked },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkMenuRowWidget_HandleToggleClicked, "HandleToggleClicked" }, // 3169986421
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkMenuRowWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics

// ********** Begin Class UDebugFrameworkMenuRowWidget Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_RootRow = { "RootRow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkMenuRowWidget, RootRow), Z_Construct_UClass_UHorizontalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootRow_MetaData), NewProp_RootRow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkMenuRowWidget, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_ToggleButton = { "ToggleButton", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkMenuRowWidget, ToggleButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleButton_MetaData), NewProp_ToggleButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_ToggleButtonText = { "ToggleButtonText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkMenuRowWidget, ToggleButtonText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleButtonText_MetaData), NewProp_ToggleButtonText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_RootRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_ToggleButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::NewProp_ToggleButtonText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkMenuRowWidget Property Definitions **************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::ClassParams = {
	&UDebugFrameworkMenuRowWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::Class_MetaDataParams)
};
void UDebugFrameworkMenuRowWidget::StaticRegisterNativesUDebugFrameworkMenuRowWidget()
{
	UClass* Class = UDebugFrameworkMenuRowWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.OuterSingleton, Z_Construct_UClass_UDebugFrameworkMenuRowWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget.OuterSingleton;
}
UDebugFrameworkMenuRowWidget::UDebugFrameworkMenuRowWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkMenuRowWidget);
UDebugFrameworkMenuRowWidget::~UDebugFrameworkMenuRowWidget() {}
// ********** End Class UDebugFrameworkMenuRowWidget ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkMenuRowWidget_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkMenuRowWidget, UDebugFrameworkMenuRowWidget::StaticClass, TEXT("UDebugFrameworkMenuRowWidget"), &Z_Registration_Info_UClass_UDebugFrameworkMenuRowWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkMenuRowWidget), 4060904900U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkMenuRowWidget_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkMenuRowWidget_h__Script_DebugFrameworkUI_1535032410{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkMenuRowWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkMenuRowWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
