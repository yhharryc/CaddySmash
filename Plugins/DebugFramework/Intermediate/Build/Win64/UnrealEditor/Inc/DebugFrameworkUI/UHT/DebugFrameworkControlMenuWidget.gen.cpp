// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFrameworkUI/DebugFrameworkControlMenuWidget.h"
#include "DebugFramework/DebugFrameworkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkControlMenuWidget() {}

// ********** Begin Cross Module References ********************************************************
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelData();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkControlMenuWidget();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkControlMenuWidget_NoRegister();
DEBUGFRAMEWORKUI_API UClass* Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UHorizontalBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_USpacer_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkControlMenuWidget Function HandleSearchChanged ************
struct Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics
{
	struct DebugFrameworkControlMenuWidget_eventHandleSearchChanged_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
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
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkControlMenuWidget_eventHandleSearchChanged_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleSearchChanged Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkControlMenuWidget, nullptr, "HandleSearchChanged", 	Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::DebugFrameworkControlMenuWidget_eventHandleSearchChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::DebugFrameworkControlMenuWidget_eventHandleSearchChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkControlMenuWidget::execHandleSearchChanged)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSearchChanged(Z_Param_Out_InText);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkControlMenuWidget Function HandleSearchChanged **************

// ********** Begin Class UDebugFrameworkControlMenuWidget Function HandleShowAllClicked ***********
struct Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleShowAllClicked constinit property declarations ******************
// ********** End Function HandleShowAllClicked constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkControlMenuWidget, nullptr, "HandleShowAllClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkControlMenuWidget::execHandleShowAllClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleShowAllClicked();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkControlMenuWidget Function HandleShowAllClicked *************

// ********** Begin Class UDebugFrameworkControlMenuWidget *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget;
UClass* UDebugFrameworkControlMenuWidget::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkControlMenuWidget;
	if (!Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkControlMenuWidget"),
			Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkControlMenuWidget,
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
	return Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkControlMenuWidget_NoRegister()
{
	return UDebugFrameworkControlMenuWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopBarSpacer_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShowAllButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShowAllButtonText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListScrollBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowsByPanelId_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPanels_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugFrameworkUI/DebugFrameworkControlMenuWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkControlMenuWidget constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TopBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TopBarSpacer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShowAllButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShowAllButtonText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SearchBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ListScrollBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowsByPanelId_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RowsByPanelId_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RowsByPanelId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedPanels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CachedPanels;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkControlMenuWidget constinit property declarations ***********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleSearchChanged"), .Pointer = &UDebugFrameworkControlMenuWidget::execHandleSearchChanged },
		{ .NameUTF8 = UTF8TEXT("HandleShowAllClicked"), .Pointer = &UDebugFrameworkControlMenuWidget::execHandleShowAllClicked },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleSearchChanged, "HandleSearchChanged" }, // 1052564445
		{ &Z_Construct_UFunction_UDebugFrameworkControlMenuWidget_HandleShowAllClicked, "HandleShowAllClicked" }, // 47932743
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkControlMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics

// ********** Begin Class UDebugFrameworkControlMenuWidget Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RootBorder = { "RootBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, RootBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBorder_MetaData), NewProp_RootBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RootBox = { "RootBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, RootBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBox_MetaData), NewProp_RootBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TopBar = { "TopBar", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, TopBar), Z_Construct_UClass_UHorizontalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopBar_MetaData), NewProp_TopBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TopBarSpacer = { "TopBarSpacer", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, TopBarSpacer), Z_Construct_UClass_USpacer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopBarSpacer_MetaData), NewProp_TopBarSpacer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ShowAllButton = { "ShowAllButton", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, ShowAllButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShowAllButton_MetaData), NewProp_ShowAllButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ShowAllButtonText = { "ShowAllButtonText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, ShowAllButtonText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShowAllButtonText_MetaData), NewProp_ShowAllButtonText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_SearchBox = { "SearchBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, SearchBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchBox_MetaData), NewProp_SearchBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ListScrollBox = { "ListScrollBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, ListScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListScrollBox_MetaData), NewProp_ListScrollBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId_ValueProp = { "RowsByPanelId", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDebugFrameworkMenuRowWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId_Key_KeyProp = { "RowsByPanelId_Key", nullptr, (EPropertyFlags)0x0100000000080008, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId = { "RowsByPanelId", nullptr, (EPropertyFlags)0x0144008000002008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, RowsByPanelId), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowsByPanelId_MetaData), NewProp_RowsByPanelId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_CachedPanels_Inner = { "CachedPanels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDebugFrameworkPanelData, METADATA_PARAMS(0, nullptr) }; // 592172877
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_CachedPanels = { "CachedPanels", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkControlMenuWidget, CachedPanels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPanels_MetaData), NewProp_CachedPanels_MetaData) }; // 592172877
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RootBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RootBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TopBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_TopBarSpacer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ShowAllButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ShowAllButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_SearchBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_ListScrollBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_RowsByPanelId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_CachedPanels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::NewProp_CachedPanels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkControlMenuWidget Property Definitions **********************
UObject* (*const Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::ClassParams = {
	&UDebugFrameworkControlMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::Class_MetaDataParams)
};
void UDebugFrameworkControlMenuWidget::StaticRegisterNativesUDebugFrameworkControlMenuWidget()
{
	UClass* Class = UDebugFrameworkControlMenuWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkControlMenuWidget()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.OuterSingleton, Z_Construct_UClass_UDebugFrameworkControlMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget.OuterSingleton;
}
UDebugFrameworkControlMenuWidget::UDebugFrameworkControlMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkControlMenuWidget);
UDebugFrameworkControlMenuWidget::~UDebugFrameworkControlMenuWidget() {}
// ********** End Class UDebugFrameworkControlMenuWidget *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkControlMenuWidget_h__Script_DebugFrameworkUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkControlMenuWidget, UDebugFrameworkControlMenuWidget::StaticClass, TEXT("UDebugFrameworkControlMenuWidget"), &Z_Registration_Info_UClass_UDebugFrameworkControlMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkControlMenuWidget), 2261186473U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkControlMenuWidget_h__Script_DebugFrameworkUI_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkControlMenuWidget_h__Script_DebugFrameworkUI_802806099{
	TEXT("/Script/DebugFrameworkUI"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkControlMenuWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkUI_Public_DebugFrameworkUI_DebugFrameworkControlMenuWidget_h__Script_DebugFrameworkUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
