// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFramework/DebugFrameworkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelData();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelRow();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FDebugFrameworkPanelRow *******************************************
struct Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDebugFrameworkPanelRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDebugFrameworkPanelRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDebugFrameworkPanelRow constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDebugFrameworkPanelRow constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDebugFrameworkPanelRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow;
class UScriptStruct* FDebugFrameworkPanelRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDebugFrameworkPanelRow, (UObject*)Z_Construct_UPackage__Script_DebugFrameworkCore(), TEXT("DebugFrameworkPanelRow"));
	}
	return Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FDebugFrameworkPanelRow Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelRow, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelRow, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelRow, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDebugFrameworkPanelRow Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
	nullptr,
	&NewStructOps,
	"DebugFrameworkPanelRow",
	Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::PropPointers),
	sizeof(FDebugFrameworkPanelRow),
	alignof(FDebugFrameworkPanelRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelRow()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.InnerSingleton, Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow.InnerSingleton);
}
// ********** End ScriptStruct FDebugFrameworkPanelRow *********************************************

// ********** Begin ScriptStruct FDebugFrameworkPanelData ******************************************
struct Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDebugFrameworkPanelData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDebugFrameworkPanelData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PanelId_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolId_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolTitle_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortOrder_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rows_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDebugFrameworkPanelData constinit property declarations **********
	static const UECodeGen_Private::FNamePropertyParams NewProp_PanelId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ToolId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ToolTitle;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SortOrder;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rows_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rows;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDebugFrameworkPanelData constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDebugFrameworkPanelData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData;
class UScriptStruct* FDebugFrameworkPanelData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDebugFrameworkPanelData, (UObject*)Z_Construct_UPackage__Script_DebugFrameworkCore(), TEXT("DebugFrameworkPanelData"));
	}
	return Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.OuterSingleton;
	}

// ********** Begin ScriptStruct FDebugFrameworkPanelData Property Definitions *********************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_PanelId = { "PanelId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, PanelId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PanelId_MetaData), NewProp_PanelId_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_ToolId = { "ToolId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, ToolId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolId_MetaData), NewProp_ToolId_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_ToolTitle = { "ToolTitle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, ToolTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolTitle_MetaData), NewProp_ToolTitle_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_SortOrder = { "SortOrder", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, SortOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortOrder_MetaData), NewProp_SortOrder_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Rows_Inner = { "Rows", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDebugFrameworkPanelRow, METADATA_PARAMS(0, nullptr) }; // 122517214
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Rows = { "Rows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelData, Rows), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rows_MetaData), NewProp_Rows_MetaData) }; // 122517214
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_PanelId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_ToolId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_ToolTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_SortOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Rows_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewProp_Rows,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDebugFrameworkPanelData Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
	nullptr,
	&NewStructOps,
	"DebugFrameworkPanelData",
	Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::PropPointers),
	sizeof(FDebugFrameworkPanelData),
	alignof(FDebugFrameworkPanelData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelData()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.InnerSingleton, Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData.InnerSingleton);
}
// ********** End ScriptStruct FDebugFrameworkPanelData ********************************************

// ********** Begin ScriptStruct FDebugFrameworkPanelLayout ****************************************
struct Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDebugFrameworkPanelLayout); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDebugFrameworkPanelLayout); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PanelId_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDebugFrameworkPanelLayout constinit property declarations ********
	static const UECodeGen_Private::FNamePropertyParams NewProp_PanelId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDebugFrameworkPanelLayout constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDebugFrameworkPanelLayout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout;
class UScriptStruct* FDebugFrameworkPanelLayout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout, (UObject*)Z_Construct_UPackage__Script_DebugFrameworkCore(), TEXT("DebugFrameworkPanelLayout"));
	}
	return Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.OuterSingleton;
	}

// ********** Begin ScriptStruct FDebugFrameworkPanelLayout Property Definitions *******************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_PanelId = { "PanelId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelLayout, PanelId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PanelId_MetaData), NewProp_PanelId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelLayout, Position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkPanelLayout, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_PanelId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewProp_Size,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDebugFrameworkPanelLayout Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
	nullptr,
	&NewStructOps,
	"DebugFrameworkPanelLayout",
	Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::PropPointers),
	sizeof(FDebugFrameworkPanelLayout),
	alignof(FDebugFrameworkPanelLayout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.InnerSingleton, Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout.InnerSingleton);
}
// ********** End ScriptStruct FDebugFrameworkPanelLayout ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkTypes_h__Script_DebugFrameworkCore_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDebugFrameworkPanelRow::StaticStruct, Z_Construct_UScriptStruct_FDebugFrameworkPanelRow_Statics::NewStructOps, TEXT("DebugFrameworkPanelRow"),&Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDebugFrameworkPanelRow), 122517214U) },
		{ FDebugFrameworkPanelData::StaticStruct, Z_Construct_UScriptStruct_FDebugFrameworkPanelData_Statics::NewStructOps, TEXT("DebugFrameworkPanelData"),&Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDebugFrameworkPanelData), 592172877U) },
		{ FDebugFrameworkPanelLayout::StaticStruct, Z_Construct_UScriptStruct_FDebugFrameworkPanelLayout_Statics::NewStructOps, TEXT("DebugFrameworkPanelLayout"),&Z_Registration_Info_UScriptStruct_FDebugFrameworkPanelLayout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDebugFrameworkPanelLayout), 2498118317U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkTypes_h__Script_DebugFrameworkCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkTypes_h__Script_DebugFrameworkCore_927917489{
	TEXT("/Script/DebugFrameworkCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkTypes_h__Script_DebugFrameworkCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkTypes_h__Script_DebugFrameworkCore_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
