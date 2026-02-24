// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadDebugWidget.h"
#include "Layout/Margin.h"
#include "SquadCore/SquadDebugComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadDebugWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugWidget();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugWidget_NoRegister();
SQUADCOREDEBUGADAPTER_API UScriptStruct* Z_Construct_UScriptStruct_FSquadDebugSnapshot();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_SquadCoreDebugAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadDebugWidget Function UpdateFromSnapshot ****************************
struct Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics
{
	struct SquadDebugWidget_eventUpdateFromSnapshot_Parms
	{
		FSquadDebugSnapshot InSnapshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSnapshot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateFromSnapshot constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSnapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateFromSnapshot constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateFromSnapshot Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::NewProp_InSnapshot = { "InSnapshot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadDebugWidget_eventUpdateFromSnapshot_Parms, InSnapshot), Z_Construct_UScriptStruct_FSquadDebugSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSnapshot_MetaData), NewProp_InSnapshot_MetaData) }; // 137827514
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::NewProp_InSnapshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::PropPointers) < 2048);
// ********** End Function UpdateFromSnapshot Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadDebugWidget, nullptr, "UpdateFromSnapshot", 	Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::SquadDebugWidget_eventUpdateFromSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::SquadDebugWidget_eventUpdateFromSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadDebugWidget::execUpdateFromSnapshot)
{
	P_GET_STRUCT_REF(FSquadDebugSnapshot,Z_Param_Out_InSnapshot);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateFromSnapshot(Z_Param_Out_InSnapshot);
	P_NATIVE_END;
}
// ********** End Class USquadDebugWidget Function UpdateFromSnapshot ******************************

// ********** Begin Class USquadDebugWidget ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadDebugWidget;
UClass* USquadDebugWidget::GetPrivateStaticClass()
{
	using TClass = USquadDebugWidget;
	if (!Z_Registration_Info_UClass_USquadDebugWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadDebugWidget"),
			Z_Registration_Info_UClass_USquadDebugWidget.InnerSingleton,
			StaticRegisterNativesUSquadDebugWidget,
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
	return Z_Registration_Info_UClass_USquadDebugWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadDebugWidget_NoRegister()
{
	return USquadDebugWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadDebugWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/SquadDebugWidget.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PanelPadding_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowHeader_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBorder_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TaskText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProfileText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeaderText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Snapshot_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadDebugWidget constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BackgroundColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PanelPadding;
	static void NewProp_bShowHeader_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowHeader;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TaskText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThreatText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CooldownText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LootText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProfileText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PressureText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Snapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadDebugWidget constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("UpdateFromSnapshot"), .Pointer = &USquadDebugWidget::execUpdateFromSnapshot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USquadDebugWidget_UpdateFromSnapshot, "UpdateFromSnapshot" }, // 3275748489
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadDebugWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadDebugWidget_Statics

// ********** Begin Class USquadDebugWidget Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, TextColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_BackgroundColor = { "BackgroundColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, BackgroundColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundColor_MetaData), NewProp_BackgroundColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_PanelPadding = { "PanelPadding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, PanelPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PanelPadding_MetaData), NewProp_PanelPadding_MetaData) }; // 4099648758
void Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_bShowHeader_SetBit(void* Obj)
{
	((USquadDebugWidget*)Obj)->bShowHeader = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_bShowHeader = { "bShowHeader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadDebugWidget), &Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_bShowHeader_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowHeader_MetaData), NewProp_bShowHeader_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_RootBorder = { "RootBorder", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, RootBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBorder_MetaData), NewProp_RootBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_RootBox = { "RootBox", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, RootBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootBox_MetaData), NewProp_RootBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_HeaderText = { "HeaderText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, HeaderText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderText_MetaData), NewProp_HeaderText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TaskText = { "TaskText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, TaskText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TaskText_MetaData), NewProp_TaskText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TargetText = { "TargetText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, TargetText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetText_MetaData), NewProp_TargetText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_ThreatText = { "ThreatText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, ThreatText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatText_MetaData), NewProp_ThreatText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_CooldownText = { "CooldownText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, CooldownText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownText_MetaData), NewProp_CooldownText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_SlotText = { "SlotText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, SlotText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotText_MetaData), NewProp_SlotText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_LootText = { "LootText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, LootText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootText_MetaData), NewProp_LootText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_DistanceText = { "DistanceText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, DistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceText_MetaData), NewProp_DistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_ProfileText = { "ProfileText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, ProfileText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProfileText_MetaData), NewProp_ProfileText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_PressureText = { "PressureText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, PressureText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureText_MetaData), NewProp_PressureText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_LeaderText = { "LeaderText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, LeaderText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeaderText_MetaData), NewProp_LeaderText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_Snapshot = { "Snapshot", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadDebugWidget, Snapshot), Z_Construct_UScriptStruct_FSquadDebugSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Snapshot_MetaData), NewProp_Snapshot_MetaData) }; // 137827514
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadDebugWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TextColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_BackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_PanelPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_bShowHeader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_RootBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_RootBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_HeaderText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TaskText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_TargetText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_ThreatText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_CooldownText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_SlotText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_LootText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_DistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_ProfileText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_PressureText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_LeaderText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadDebugWidget_Statics::NewProp_Snapshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugWidget_Statics::PropPointers) < 2048);
// ********** End Class USquadDebugWidget Property Definitions *************************************
UObject* (*const Z_Construct_UClass_USquadDebugWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreDebugAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadDebugWidget_Statics::ClassParams = {
	&USquadDebugWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USquadDebugWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadDebugWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadDebugWidget_Statics::Class_MetaDataParams)
};
void USquadDebugWidget::StaticRegisterNativesUSquadDebugWidget()
{
	UClass* Class = USquadDebugWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USquadDebugWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_USquadDebugWidget()
{
	if (!Z_Registration_Info_UClass_USquadDebugWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadDebugWidget.OuterSingleton, Z_Construct_UClass_USquadDebugWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadDebugWidget.OuterSingleton;
}
USquadDebugWidget::USquadDebugWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadDebugWidget);
USquadDebugWidget::~USquadDebugWidget() {}
// ********** End Class USquadDebugWidget **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h__Script_SquadCoreDebugAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadDebugWidget, USquadDebugWidget::StaticClass, TEXT("USquadDebugWidget"), &Z_Registration_Info_UClass_USquadDebugWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadDebugWidget), 658287414U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h__Script_SquadCoreDebugAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h__Script_SquadCoreDebugAdapter_1323262761{
	TEXT("/Script/SquadCoreDebugAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
