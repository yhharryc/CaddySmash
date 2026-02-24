// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkToolPanelWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkToolPanelWidget() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkToolPanelWidget();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkToolPanelWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UHorizontalBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkToolPanelWidget Function HandleCloseClicked ***************
struct Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseClicked constinit property declarations ********************
// ********** End Function HandleCloseClicked constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkToolPanelWidget, nullptr, "HandleCloseClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkToolPanelWidget::execHandleCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseClicked();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkToolPanelWidget Function HandleCloseClicked *****************

// ********** Begin Class UDebugFrameworkToolPanelWidget Function HandleSearchChanged **************
struct Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics
{
	struct DebugFrameworkToolPanelWidget_eventHandleSearchChanged_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSearchChanged constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSearchChanged constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSearchChanged Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkToolPanelWidget_eventHandleSearchChanged_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleSearchChanged Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkToolPanelWidget, nullptr, "HandleSearchChanged", 	Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::DebugFrameworkToolPanelWidget_eventHandleSearchChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::DebugFrameworkToolPanelWidget_eventHandleSearchChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkToolPanelWidget::execHandleSearchChanged)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSearchChanged(Z_Param_Out_InText);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkToolPanelWidget Function HandleSearchChanged ****************

// ********** Begin Class UDebugFrameworkToolPanelWidget *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget;
UClass* UDebugFrameworkToolPanelWidget::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkToolPanelWidget;
	if (!Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkToolPanelWidget"),
			Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkToolPanelWidget,
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
	return Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkToolPanelWidget_NoRegister()
{
	return UDebugFrameworkToolPanelWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButtonText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListScrollBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowsByPanelId_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkToolPanelWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkToolPanelWidget constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButtonText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SearchBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ListScrollBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowsByPanelId_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RowsByPanelId_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RowsByPanelId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkToolPanelWidget constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleCloseClicked"), .Pointer = &UDebugFrameworkToolPanelWidget::execHandleCloseClicked },
		{ .NameUTF8 = UTF8TEXT("HandleSearchChanged"), .Pointer = &UDebugFrameworkToolPanelWidget::execHandleSearchChanged },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleCloseClicked, "HandleCloseClicked" }, // 1466336608
		{ &Z_Construct_UFunction_UDebugFrameworkToolPanelWidget_HandleSearchChanged, "HandleSearchChanged" }, // 1964079912
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkToolPanelWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics

// ********** Begin Class UDebugFrameworkToolPanelWidget Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RootBorder = { "RootBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, RootBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBorder_MetaData), NewProp_RootBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RootBox = { "RootBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, RootBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBox_MetaData), NewProp_RootBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_HeaderBox = { "HeaderBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, HeaderBox), Z_Construct_UClass_UHorizontalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderBox_MetaData), NewProp_HeaderBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, CloseButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_CloseButtonText = { "CloseButtonText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, CloseButtonText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButtonText_MetaData), NewProp_CloseButtonText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_SearchBox = { "SearchBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, SearchBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchBox_MetaData), NewProp_SearchBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_ListScrollBox = { "ListScrollBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, ListScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListScrollBox_MetaData), NewProp_ListScrollBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId_ValueProp = { "RowsByPanelId", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId_Key_KeyProp = { "RowsByPanelId_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId = { "RowsByPanelId", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkToolPanelWidget, RowsByPanelId), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowsByPanelId_MetaData), NewProp_RowsByPanelId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RootBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RootBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_HeaderBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_CloseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_CloseButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_SearchBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_ListScrollBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::NewProp_RowsByPanelId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkToolPanelWidget Property Definitions ************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::ClassParams = {
	&UDebugFrameworkToolPanelWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::Class_MetaDataParams)
};
void UDebugFrameworkToolPanelWidget::StaticRegisterNativesUDebugFrameworkToolPanelWidget()
{
	UClass* Class = UDebugFrameworkToolPanelWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkToolPanelWidget()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.OuterSingleton, Z_Construct_UClass_UDebugFrameworkToolPanelWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget.OuterSingleton;
}
UDebugFrameworkToolPanelWidget::UDebugFrameworkToolPanelWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkToolPanelWidget);
UDebugFrameworkToolPanelWidget::~UDebugFrameworkToolPanelWidget() {}
// ********** End Class UDebugFrameworkToolPanelWidget *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkToolPanelWidget_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkToolPanelWidget, UDebugFrameworkToolPanelWidget::StaticClass, TEXT("UDebugFrameworkToolPanelWidget"), &Z_Registration_Info_UClass_UDebugFrameworkToolPanelWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkToolPanelWidget), 1979480125U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkToolPanelWidget_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkToolPanelWidget_h__Script_DebugFrameworkUI_615132510{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkToolPanelWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkToolPanelWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
