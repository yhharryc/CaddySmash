// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFramework/DebugFrameworkProvider.h"
#include "DebugFramework/DebugFrameworkTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkProvider() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkProvider();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkProvider_NoRegister();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkPanelRow();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UDebugFrameworkProvider Function GatherDebugRows *********************
struct DebugFrameworkProvider_eventGatherDebugRows_Parms
{
	TArray<FDebugFrameworkPanelRow> OutRows;
};
void IDebugFrameworkProvider::GatherDebugRows(TArray<FDebugFrameworkPanelRow>& OutRows) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GatherDebugRows instead.");
}
static FName NAME_UDebugFrameworkProvider_GatherDebugRows = FName(TEXT("GatherDebugRows"));
void IDebugFrameworkProvider::Execute_GatherDebugRows(const UObject* O, TArray<FDebugFrameworkPanelRow>& OutRows)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGatherDebugRows_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GatherDebugRows);
	if (Func)
	{
		Parms.OutRows=std::move(OutRows);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		OutRows=std::move(Parms.OutRows);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		I->GatherDebugRows_Implementation(OutRows);
	}
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GatherDebugRows constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRows_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutRows;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GatherDebugRows constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GatherDebugRows Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::NewProp_OutRows_Inner = { "OutRows", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDebugFrameworkPanelRow, METADATA_PARAMS(0, nullptr) }; // 122517214
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::NewProp_OutRows = { "OutRows", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGatherDebugRows_Parms, OutRows), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 122517214
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::NewProp_OutRows_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::NewProp_OutRows,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::PropPointers) < 2048);
// ********** End Function GatherDebugRows Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GatherDebugRows", 	Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGatherDebugRows_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGatherDebugRows_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGatherDebugRows)
{
	P_GET_TARRAY_REF(FDebugFrameworkPanelRow,Z_Param_Out_OutRows);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GatherDebugRows_Implementation(Z_Param_Out_OutRows);
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GatherDebugRows ***********************

// ********** Begin Interface UDebugFrameworkProvider Function GetDebugPanelId *********************
struct DebugFrameworkProvider_eventGetDebugPanelId_Parms
{
	FName ReturnValue;
};
FName IDebugFrameworkProvider::GetDebugPanelId() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDebugPanelId instead.");
	DebugFrameworkProvider_eventGetDebugPanelId_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDebugFrameworkProvider_GetDebugPanelId = FName(TEXT("GetDebugPanelId"));
FName IDebugFrameworkProvider::Execute_GetDebugPanelId(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGetDebugPanelId_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GetDebugPanelId);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		Parms.ReturnValue = I->GetDebugPanelId_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDebugPanelId constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDebugPanelId constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDebugPanelId Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGetDebugPanelId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::PropPointers) < 2048);
// ********** End Function GetDebugPanelId Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GetDebugPanelId", 	Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGetDebugPanelId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGetDebugPanelId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGetDebugPanelId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetDebugPanelId_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GetDebugPanelId ***********************

// ********** Begin Interface UDebugFrameworkProvider Function GetDebugPanelTitle ******************
struct DebugFrameworkProvider_eventGetDebugPanelTitle_Parms
{
	FText ReturnValue;
};
FText IDebugFrameworkProvider::GetDebugPanelTitle() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDebugPanelTitle instead.");
	DebugFrameworkProvider_eventGetDebugPanelTitle_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDebugFrameworkProvider_GetDebugPanelTitle = FName(TEXT("GetDebugPanelTitle"));
FText IDebugFrameworkProvider::Execute_GetDebugPanelTitle(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGetDebugPanelTitle_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GetDebugPanelTitle);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		Parms.ReturnValue = I->GetDebugPanelTitle_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDebugPanelTitle constinit property declarations ********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDebugPanelTitle constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDebugPanelTitle Property Definitions *******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGetDebugPanelTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::PropPointers) < 2048);
// ********** End Function GetDebugPanelTitle Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GetDebugPanelTitle", 	Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGetDebugPanelTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGetDebugPanelTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGetDebugPanelTitle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDebugPanelTitle_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GetDebugPanelTitle ********************

// ********** Begin Interface UDebugFrameworkProvider Function GetDebugSortOrder *******************
struct DebugFrameworkProvider_eventGetDebugSortOrder_Parms
{
	int32 ReturnValue;

	/** Constructor, initializes return property only **/
	DebugFrameworkProvider_eventGetDebugSortOrder_Parms()
		: ReturnValue(0)
	{
	}
};
int32 IDebugFrameworkProvider::GetDebugSortOrder() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDebugSortOrder instead.");
	DebugFrameworkProvider_eventGetDebugSortOrder_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDebugFrameworkProvider_GetDebugSortOrder = FName(TEXT("GetDebugSortOrder"));
int32 IDebugFrameworkProvider::Execute_GetDebugSortOrder(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGetDebugSortOrder_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GetDebugSortOrder);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		Parms.ReturnValue = I->GetDebugSortOrder_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDebugSortOrder constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDebugSortOrder constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDebugSortOrder Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGetDebugSortOrder_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::PropPointers) < 2048);
// ********** End Function GetDebugSortOrder Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GetDebugSortOrder", 	Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGetDebugSortOrder_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGetDebugSortOrder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGetDebugSortOrder)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetDebugSortOrder_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GetDebugSortOrder *********************

// ********** Begin Interface UDebugFrameworkProvider Function GetDebugToolId **********************
struct DebugFrameworkProvider_eventGetDebugToolId_Parms
{
	FName ReturnValue;
};
FName IDebugFrameworkProvider::GetDebugToolId() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDebugToolId instead.");
	DebugFrameworkProvider_eventGetDebugToolId_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDebugFrameworkProvider_GetDebugToolId = FName(TEXT("GetDebugToolId"));
FName IDebugFrameworkProvider::Execute_GetDebugToolId(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGetDebugToolId_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GetDebugToolId);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		Parms.ReturnValue = I->GetDebugToolId_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDebugToolId constinit property declarations ************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDebugToolId constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDebugToolId Property Definitions ***********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGetDebugToolId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::PropPointers) < 2048);
// ********** End Function GetDebugToolId Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GetDebugToolId", 	Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGetDebugToolId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGetDebugToolId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGetDebugToolId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetDebugToolId_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GetDebugToolId ************************

// ********** Begin Interface UDebugFrameworkProvider Function GetDebugToolTitle *******************
struct DebugFrameworkProvider_eventGetDebugToolTitle_Parms
{
	FText ReturnValue;
};
FText IDebugFrameworkProvider::GetDebugToolTitle() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDebugToolTitle instead.");
	DebugFrameworkProvider_eventGetDebugToolTitle_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDebugFrameworkProvider_GetDebugToolTitle = FName(TEXT("GetDebugToolTitle"));
FText IDebugFrameworkProvider::Execute_GetDebugToolTitle(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDebugFrameworkProvider::StaticClass()));
	DebugFrameworkProvider_eventGetDebugToolTitle_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDebugFrameworkProvider_GetDebugToolTitle);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IDebugFrameworkProvider*)(O->GetNativeInterfaceAddress(UDebugFrameworkProvider::StaticClass())))
	{
		Parms.ReturnValue = I->GetDebugToolTitle_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDebugToolTitle constinit property declarations *********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDebugToolTitle constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDebugToolTitle Property Definitions ********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkProvider_eventGetDebugToolTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::PropPointers) < 2048);
// ********** End Function GetDebugToolTitle Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkProvider, nullptr, "GetDebugToolTitle", 	Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::PropPointers), 
sizeof(DebugFrameworkProvider_eventGetDebugToolTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DebugFrameworkProvider_eventGetDebugToolTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDebugFrameworkProvider::execGetDebugToolTitle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDebugToolTitle_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UDebugFrameworkProvider Function GetDebugToolTitle *********************

// ********** Begin Interface UDebugFrameworkProvider **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkProvider;
UClass* UDebugFrameworkProvider::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkProvider;
	if (!Z_Registration_Info_UClass_UDebugFrameworkProvider.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkProvider"),
			Z_Registration_Info_UClass_UDebugFrameworkProvider.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkProvider,
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
	return Z_Registration_Info_UClass_UDebugFrameworkProvider.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkProvider_NoRegister()
{
	return UDebugFrameworkProvider::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkProvider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UDebugFrameworkProvider constinit property declarations **************
// ********** End Interface UDebugFrameworkProvider constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GatherDebugRows"), .Pointer = &IDebugFrameworkProvider::execGatherDebugRows },
		{ .NameUTF8 = UTF8TEXT("GetDebugPanelId"), .Pointer = &IDebugFrameworkProvider::execGetDebugPanelId },
		{ .NameUTF8 = UTF8TEXT("GetDebugPanelTitle"), .Pointer = &IDebugFrameworkProvider::execGetDebugPanelTitle },
		{ .NameUTF8 = UTF8TEXT("GetDebugSortOrder"), .Pointer = &IDebugFrameworkProvider::execGetDebugSortOrder },
		{ .NameUTF8 = UTF8TEXT("GetDebugToolId"), .Pointer = &IDebugFrameworkProvider::execGetDebugToolId },
		{ .NameUTF8 = UTF8TEXT("GetDebugToolTitle"), .Pointer = &IDebugFrameworkProvider::execGetDebugToolTitle },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GatherDebugRows, "GatherDebugRows" }, // 1448838062
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelId, "GetDebugPanelId" }, // 2675355157
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugPanelTitle, "GetDebugPanelTitle" }, // 378294326
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugSortOrder, "GetDebugSortOrder" }, // 701647771
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolId, "GetDebugToolId" }, // 4121348904
		{ &Z_Construct_UFunction_UDebugFrameworkProvider_GetDebugToolTitle, "GetDebugToolTitle" }, // 201768312
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDebugFrameworkProvider>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkProvider_Statics
UObject* (*const Z_Construct_UClass_UDebugFrameworkProvider_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkProvider_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkProvider_Statics::ClassParams = {
	&UDebugFrameworkProvider::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkProvider_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkProvider_Statics::Class_MetaDataParams)
};
void UDebugFrameworkProvider::StaticRegisterNativesUDebugFrameworkProvider()
{
	UClass* Class = UDebugFrameworkProvider::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkProvider_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkProvider()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkProvider.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkProvider.OuterSingleton, Z_Construct_UClass_UDebugFrameworkProvider_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkProvider.OuterSingleton;
}
UDebugFrameworkProvider::UDebugFrameworkProvider(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkProvider);
// ********** End Interface UDebugFrameworkProvider ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h__Script_DebugFrameworkCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkProvider, UDebugFrameworkProvider::StaticClass, TEXT("UDebugFrameworkProvider"), &Z_Registration_Info_UClass_UDebugFrameworkProvider, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkProvider), 825384405U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h__Script_DebugFrameworkCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h__Script_DebugFrameworkCore_2585593591{
	TEXT("/Script/DebugFrameworkCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h__Script_DebugFrameworkCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h__Script_DebugFrameworkCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
