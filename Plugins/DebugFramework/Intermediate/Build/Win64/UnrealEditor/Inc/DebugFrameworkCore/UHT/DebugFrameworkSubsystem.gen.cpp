// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFramework/DebugFrameworkSubsystem.h"
#include "DebugFramework/DebugFrameworkSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSubsystem();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSubsystem_NoRegister();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkInputChord();
ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDebugFrameworkSubsystem Function GetToggleVisibilityChord ***************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics
{
	struct DebugFrameworkSubsystem_eventGetToggleVisibilityChord_Parms
	{
		FDebugFrameworkInputChord ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework|Input" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetToggleVisibilityChord constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetToggleVisibilityChord constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetToggleVisibilityChord Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventGetToggleVisibilityChord_Parms, ReturnValue), Z_Construct_UScriptStruct_FDebugFrameworkInputChord, METADATA_PARAMS(0, nullptr) }; // 2569066584
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::PropPointers) < 2048);
// ********** End Function GetToggleVisibilityChord Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "GetToggleVisibilityChord", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::DebugFrameworkSubsystem_eventGetToggleVisibilityChord_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::DebugFrameworkSubsystem_eventGetToggleVisibilityChord_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execGetToggleVisibilityChord)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDebugFrameworkInputChord*)Z_Param__Result=P_THIS->GetToggleVisibilityChord();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function GetToggleVisibilityChord *****************

// ********** Begin Class UDebugFrameworkSubsystem Function IsPanelVisible *************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics
{
	struct DebugFrameworkSubsystem_eventIsPanelVisible_Parms
	{
		FName PanelId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPanelVisible constinit property declarations ************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_PanelId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPanelVisible constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPanelVisible Property Definitions ***********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_PanelId = { "PanelId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventIsPanelVisible_Parms, PanelId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DebugFrameworkSubsystem_eventIsPanelVisible_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DebugFrameworkSubsystem_eventIsPanelVisible_Parms), &Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_PanelId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::PropPointers) < 2048);
// ********** End Function IsPanelVisible Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "IsPanelVisible", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::DebugFrameworkSubsystem_eventIsPanelVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::DebugFrameworkSubsystem_eventIsPanelVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execIsPanelVisible)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_PanelId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPanelVisible(Z_Param_PanelId);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function IsPanelVisible ***************************

// ********** Begin Class UDebugFrameworkSubsystem Function IsVisible ******************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics
{
	struct DebugFrameworkSubsystem_eventIsVisible_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsVisible constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsVisible constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsVisible Property Definitions ****************************************
void Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DebugFrameworkSubsystem_eventIsVisible_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DebugFrameworkSubsystem_eventIsVisible_Parms), &Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::PropPointers) < 2048);
// ********** End Function IsVisible Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "IsVisible", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::DebugFrameworkSubsystem_eventIsVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::DebugFrameworkSubsystem_eventIsVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execIsVisible)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsVisible();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function IsVisible ********************************

// ********** Begin Class UDebugFrameworkSubsystem Function RegisterProvider ***********************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics
{
	struct DebugFrameworkSubsystem_eventRegisterProvider_Parms
	{
		UObject* ProviderObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterProvider constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProviderObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterProvider constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterProvider Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::NewProp_ProviderObject = { "ProviderObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventRegisterProvider_Parms, ProviderObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::NewProp_ProviderObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::PropPointers) < 2048);
// ********** End Function RegisterProvider Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "RegisterProvider", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::DebugFrameworkSubsystem_eventRegisterProvider_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::DebugFrameworkSubsystem_eventRegisterProvider_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execRegisterProvider)
{
	P_GET_OBJECT(UObject,Z_Param_ProviderObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterProvider(Z_Param_ProviderObject);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function RegisterProvider *************************

// ********** Begin Class UDebugFrameworkSubsystem Function ResetPanelLayouts **********************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetPanelLayouts constinit property declarations *********************
// ********** End Function ResetPanelLayouts constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "ResetPanelLayouts", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execResetPanelLayouts)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetPanelLayouts();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function ResetPanelLayouts ************************

// ********** Begin Class UDebugFrameworkSubsystem Function SetPanelVisible ************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics
{
	struct DebugFrameworkSubsystem_eventSetPanelVisible_Parms
	{
		FName PanelId;
		bool bInVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPanelVisible constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_PanelId;
	static void NewProp_bInVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPanelVisible constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPanelVisible Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_PanelId = { "PanelId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventSetPanelVisible_Parms, PanelId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_bInVisible_SetBit(void* Obj)
{
	((DebugFrameworkSubsystem_eventSetPanelVisible_Parms*)Obj)->bInVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_bInVisible = { "bInVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DebugFrameworkSubsystem_eventSetPanelVisible_Parms), &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_bInVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_PanelId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::NewProp_bInVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::PropPointers) < 2048);
// ********** End Function SetPanelVisible Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "SetPanelVisible", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::DebugFrameworkSubsystem_eventSetPanelVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::DebugFrameworkSubsystem_eventSetPanelVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execSetPanelVisible)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_PanelId);
	P_GET_UBOOL(Z_Param_bInVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPanelVisible(Z_Param_PanelId,Z_Param_bInVisible);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function SetPanelVisible **************************

// ********** Begin Class UDebugFrameworkSubsystem Function SetToggleVisibilityChord ***************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics
{
	struct DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms
	{
		FDebugFrameworkInputChord InChord;
		bool bSaveConfig;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework|Input" },
		{ "CPP_Default_bSaveConfig", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InChord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetToggleVisibilityChord constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InChord;
	static void NewProp_bSaveConfig_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetToggleVisibilityChord constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetToggleVisibilityChord Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_InChord = { "InChord", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms, InChord), Z_Construct_UScriptStruct_FDebugFrameworkInputChord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InChord_MetaData), NewProp_InChord_MetaData) }; // 2569066584
void Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_bSaveConfig_SetBit(void* Obj)
{
	((DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms*)Obj)->bSaveConfig = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_bSaveConfig = { "bSaveConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms), &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_bSaveConfig_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_InChord,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::NewProp_bSaveConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::PropPointers) < 2048);
// ********** End Function SetToggleVisibilityChord Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "SetToggleVisibilityChord", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::DebugFrameworkSubsystem_eventSetToggleVisibilityChord_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execSetToggleVisibilityChord)
{
	P_GET_STRUCT_REF(FDebugFrameworkInputChord,Z_Param_Out_InChord);
	P_GET_UBOOL(Z_Param_bSaveConfig);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetToggleVisibilityChord(Z_Param_Out_InChord,Z_Param_bSaveConfig);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function SetToggleVisibilityChord *****************

// ********** Begin Class UDebugFrameworkSubsystem Function SetVisible *****************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics
{
	struct DebugFrameworkSubsystem_eventSetVisible_Parms
	{
		bool bInVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVisible constinit property declarations ****************************
	static void NewProp_bInVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVisible constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVisible Property Definitions ***************************************
void Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::NewProp_bInVisible_SetBit(void* Obj)
{
	((DebugFrameworkSubsystem_eventSetVisible_Parms*)Obj)->bInVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::NewProp_bInVisible = { "bInVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DebugFrameworkSubsystem_eventSetVisible_Parms), &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::NewProp_bInVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::NewProp_bInVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::PropPointers) < 2048);
// ********** End Function SetVisible Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "SetVisible", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::DebugFrameworkSubsystem_eventSetVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::DebugFrameworkSubsystem_eventSetVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execSetVisible)
{
	P_GET_UBOOL(Z_Param_bInVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVisible(Z_Param_bInVisible);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function SetVisible *******************************

// ********** Begin Class UDebugFrameworkSubsystem Function ShowAllPanels **************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowAllPanels constinit property declarations *************************
// ********** End Function ShowAllPanels constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "ShowAllPanels", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execShowAllPanels)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowAllPanels();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function ShowAllPanels ****************************

// ********** Begin Class UDebugFrameworkSubsystem Function ToggleVisible **************************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleVisible constinit property declarations *************************
// ********** End Function ToggleVisible constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "ToggleVisible", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execToggleVisible)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleVisible();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function ToggleVisible ****************************

// ********** Begin Class UDebugFrameworkSubsystem Function UnregisterProvider *********************
struct Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics
{
	struct DebugFrameworkSubsystem_eventUnregisterProvider_Parms
	{
		UObject* ProviderObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterProvider constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProviderObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnregisterProvider constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnregisterProvider Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::NewProp_ProviderObject = { "ProviderObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSubsystem_eventUnregisterProvider_Parms, ProviderObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::NewProp_ProviderObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::PropPointers) < 2048);
// ********** End Function UnregisterProvider Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSubsystem, nullptr, "UnregisterProvider", 	Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::DebugFrameworkSubsystem_eventUnregisterProvider_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::DebugFrameworkSubsystem_eventUnregisterProvider_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSubsystem::execUnregisterProvider)
{
	P_GET_OBJECT(UObject,Z_Param_ProviderObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnregisterProvider(Z_Param_ProviderObject);
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSubsystem Function UnregisterProvider ***********************

// ********** Begin Class UDebugFrameworkSubsystem *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkSubsystem;
UClass* UDebugFrameworkSubsystem::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkSubsystem;
	if (!Z_Registration_Info_UClass_UDebugFrameworkSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkSubsystem"),
			Z_Registration_Info_UClass_UDebugFrameworkSubsystem.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkSubsystem,
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
	return Z_Registration_Info_UClass_UDebugFrameworkSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkSubsystem_NoRegister()
{
	return UDebugFrameworkSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DebugFramework/DebugFrameworkSubsystem.h" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkSubsystem constinit property declarations *****************
// ********** End Class UDebugFrameworkSubsystem constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetToggleVisibilityChord"), .Pointer = &UDebugFrameworkSubsystem::execGetToggleVisibilityChord },
		{ .NameUTF8 = UTF8TEXT("IsPanelVisible"), .Pointer = &UDebugFrameworkSubsystem::execIsPanelVisible },
		{ .NameUTF8 = UTF8TEXT("IsVisible"), .Pointer = &UDebugFrameworkSubsystem::execIsVisible },
		{ .NameUTF8 = UTF8TEXT("RegisterProvider"), .Pointer = &UDebugFrameworkSubsystem::execRegisterProvider },
		{ .NameUTF8 = UTF8TEXT("ResetPanelLayouts"), .Pointer = &UDebugFrameworkSubsystem::execResetPanelLayouts },
		{ .NameUTF8 = UTF8TEXT("SetPanelVisible"), .Pointer = &UDebugFrameworkSubsystem::execSetPanelVisible },
		{ .NameUTF8 = UTF8TEXT("SetToggleVisibilityChord"), .Pointer = &UDebugFrameworkSubsystem::execSetToggleVisibilityChord },
		{ .NameUTF8 = UTF8TEXT("SetVisible"), .Pointer = &UDebugFrameworkSubsystem::execSetVisible },
		{ .NameUTF8 = UTF8TEXT("ShowAllPanels"), .Pointer = &UDebugFrameworkSubsystem::execShowAllPanels },
		{ .NameUTF8 = UTF8TEXT("ToggleVisible"), .Pointer = &UDebugFrameworkSubsystem::execToggleVisible },
		{ .NameUTF8 = UTF8TEXT("UnregisterProvider"), .Pointer = &UDebugFrameworkSubsystem::execUnregisterProvider },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_GetToggleVisibilityChord, "GetToggleVisibilityChord" }, // 4285090989
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_IsPanelVisible, "IsPanelVisible" }, // 1132921820
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_IsVisible, "IsVisible" }, // 1219260565
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_RegisterProvider, "RegisterProvider" }, // 3462373267
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_ResetPanelLayouts, "ResetPanelLayouts" }, // 1171800231
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetPanelVisible, "SetPanelVisible" }, // 2179559885
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetToggleVisibilityChord, "SetToggleVisibilityChord" }, // 916081150
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_SetVisible, "SetVisible" }, // 1327744442
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_ShowAllPanels, "ShowAllPanels" }, // 2113506044
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_ToggleVisible, "ToggleVisible" }, // 3387296807
		{ &Z_Construct_UFunction_UDebugFrameworkSubsystem_UnregisterProvider, "UnregisterProvider" }, // 4212286776
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkSubsystem_Statics
UObject* (*const Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTickableWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::ClassParams = {
	&UDebugFrameworkSubsystem::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::Class_MetaDataParams)
};
void UDebugFrameworkSubsystem::StaticRegisterNativesUDebugFrameworkSubsystem()
{
	UClass* Class = UDebugFrameworkSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkSubsystem()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkSubsystem.OuterSingleton, Z_Construct_UClass_UDebugFrameworkSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkSubsystem.OuterSingleton;
}
UDebugFrameworkSubsystem::UDebugFrameworkSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkSubsystem);
UDebugFrameworkSubsystem::~UDebugFrameworkSubsystem() {}
// ********** End Class UDebugFrameworkSubsystem ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h__Script_DebugFrameworkCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkSubsystem, UDebugFrameworkSubsystem::StaticClass, TEXT("UDebugFrameworkSubsystem"), &Z_Registration_Info_UClass_UDebugFrameworkSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkSubsystem), 427609922U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h__Script_DebugFrameworkCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h__Script_DebugFrameworkCore_836796729{
	TEXT("/Script/DebugFrameworkCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h__Script_DebugFrameworkCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h__Script_DebugFrameworkCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
