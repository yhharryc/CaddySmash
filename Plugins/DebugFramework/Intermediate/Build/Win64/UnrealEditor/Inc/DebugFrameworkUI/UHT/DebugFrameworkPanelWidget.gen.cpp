// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkPanelWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkPanelWidget() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkPanelWidget();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkPanelWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UHorizontalBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkPanelWidget Function HandleCloseClicked *******************
struct Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseClicked constinit property declarations ********************
// ********** End Function HandleCloseClicked constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkPanelWidget, nullptr, "HandleCloseClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkPanelWidget::execHandleCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseClicked();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkPanelWidget Function HandleCloseClicked *********************

// ********** Begin Class UDebugFrameworkPanelWidget ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkPanelWidget;
UClass* UDebugFrameworkPanelWidget::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkPanelWidget;
	if (!Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkPanelWidget"),
			Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkPanelWidget,
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
	return Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkPanelWidget_NoRegister()
{
	return UDebugFrameworkPanelWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionBarBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButtonText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowsScrollBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowsBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowTextBlocks_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoAdjustHeightToContent_MetaData[] = {
		{ "Category", "DebugFramework|Layout" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoRowHeight_MetaData[] = {
		{ "Category", "DebugFramework|Layout" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoBaseHeight_MetaData[] = {
		{ "Category", "DebugFramework|Layout" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAutoRowsBeforeScroll_MetaData[] = {
		{ "Category", "DebugFramework|Layout" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkPanelWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkPanelWidget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ContentBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionBarBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButtonText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowsScrollBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowsBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowTextBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RowTextBlocks;
	static void NewProp_bAutoAdjustHeightToContent_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoAdjustHeightToContent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoRowHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoBaseHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAutoRowsBeforeScroll;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkPanelWidget constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleCloseClicked"), .Pointer = &UDebugFrameworkPanelWidget::execHandleCloseClicked },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkPanelWidget_HandleCloseClicked, "HandleCloseClicked" }, // 1434239713
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkPanelWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics

// ********** Begin Class UDebugFrameworkPanelWidget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RootBorder = { "RootBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, RootBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBorder_MetaData), NewProp_RootBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_ContentBox = { "ContentBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, ContentBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentBox_MetaData), NewProp_ContentBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_ActionBarBorder = { "ActionBarBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, ActionBarBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionBarBorder_MetaData), NewProp_ActionBarBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_HeaderBorder = { "HeaderBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, HeaderBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderBorder_MetaData), NewProp_HeaderBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_HeaderBox = { "HeaderBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, HeaderBox), Z_Construct_UClass_UHorizontalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderBox_MetaData), NewProp_HeaderBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, CloseButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_CloseButtonText = { "CloseButtonText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, CloseButtonText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButtonText_MetaData), NewProp_CloseButtonText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowsScrollBox = { "RowsScrollBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, RowsScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowsScrollBox_MetaData), NewProp_RowsScrollBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowsBox = { "RowsBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, RowsBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowsBox_MetaData), NewProp_RowsBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowTextBlocks_Inner = { "RowTextBlocks", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowTextBlocks = { "RowTextBlocks", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, RowTextBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowTextBlocks_MetaData), NewProp_RowTextBlocks_MetaData) };
void Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_bAutoAdjustHeightToContent_SetBit(void* Obj)
{
	((UDebugFrameworkPanelWidget*)Obj)->bAutoAdjustHeightToContent = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_bAutoAdjustHeightToContent = { "bAutoAdjustHeightToContent", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkPanelWidget), &Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_bAutoAdjustHeightToContent_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoAdjustHeightToContent_MetaData), NewProp_bAutoAdjustHeightToContent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_AutoRowHeight = { "AutoRowHeight", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, AutoRowHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoRowHeight_MetaData), NewProp_AutoRowHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_AutoBaseHeight = { "AutoBaseHeight", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, AutoBaseHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoBaseHeight_MetaData), NewProp_AutoBaseHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_MaxAutoRowsBeforeScroll = { "MaxAutoRowsBeforeScroll", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkPanelWidget, MaxAutoRowsBeforeScroll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAutoRowsBeforeScroll_MetaData), NewProp_MaxAutoRowsBeforeScroll_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RootBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_ContentBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_ActionBarBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_HeaderBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_HeaderBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_CloseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_CloseButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowsScrollBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowsBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowTextBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_RowTextBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_bAutoAdjustHeightToContent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_AutoRowHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_AutoBaseHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::NewProp_MaxAutoRowsBeforeScroll,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkPanelWidget Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::ClassParams = {
	&UDebugFrameworkPanelWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::Class_MetaDataParams)
};
void UDebugFrameworkPanelWidget::StaticRegisterNativesUDebugFrameworkPanelWidget()
{
	UClass* Class = UDebugFrameworkPanelWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkPanelWidget()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.OuterSingleton, Z_Construct_UClass_UDebugFrameworkPanelWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkPanelWidget.OuterSingleton;
}
UDebugFrameworkPanelWidget::UDebugFrameworkPanelWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkPanelWidget);
UDebugFrameworkPanelWidget::~UDebugFrameworkPanelWidget() {}
// ********** End Class UDebugFrameworkPanelWidget *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkPanelWidget_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkPanelWidget, UDebugFrameworkPanelWidget::StaticClass, TEXT("UDebugFrameworkPanelWidget"), &Z_Registration_Info_UClass_UDebugFrameworkPanelWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkPanelWidget), 2994457863U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkPanelWidget_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkPanelWidget_h__Script_DebugFrameworkUI_2460636701{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkPanelWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkPanelWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
