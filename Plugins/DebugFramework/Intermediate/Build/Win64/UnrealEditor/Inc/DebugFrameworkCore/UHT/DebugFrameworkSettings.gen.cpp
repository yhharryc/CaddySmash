// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DebugFramework/DebugFrameworkSettings.h"
#include "InputCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSettings();
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSettings_NoRegister();
DEBUGFRAMEWORKCORE_API UEnum* Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy();
DEBUGFRAMEWORKCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkInputChord();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FDebugFrameworkInputChord *****************************************
struct Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDebugFrameworkInputChord); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDebugFrameworkInputChord); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCtrl_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAlt_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShift_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCmd_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireExactModifiers_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDebugFrameworkInputChord constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Key;
	static void NewProp_bCtrl_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCtrl;
	static void NewProp_bAlt_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlt;
	static void NewProp_bShift_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShift;
	static void NewProp_bCmd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCmd;
	static void NewProp_bRequireExactModifiers_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireExactModifiers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDebugFrameworkInputChord constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDebugFrameworkInputChord>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord;
class UScriptStruct* FDebugFrameworkInputChord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDebugFrameworkInputChord, (UObject*)Z_Construct_UPackage__Script_DebugFrameworkCore(), TEXT("DebugFrameworkInputChord"));
	}
	return Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.OuterSingleton;
	}

// ********** Begin ScriptStruct FDebugFrameworkInputChord Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDebugFrameworkInputChord, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Key_MetaData), NewProp_Key_MetaData) }; // 2693575693
void Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCtrl_SetBit(void* Obj)
{
	((FDebugFrameworkInputChord*)Obj)->bCtrl = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCtrl = { "bCtrl", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDebugFrameworkInputChord), &Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCtrl_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCtrl_MetaData), NewProp_bCtrl_MetaData) };
void Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bAlt_SetBit(void* Obj)
{
	((FDebugFrameworkInputChord*)Obj)->bAlt = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bAlt = { "bAlt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDebugFrameworkInputChord), &Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bAlt_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAlt_MetaData), NewProp_bAlt_MetaData) };
void Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bShift_SetBit(void* Obj)
{
	((FDebugFrameworkInputChord*)Obj)->bShift = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bShift = { "bShift", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDebugFrameworkInputChord), &Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bShift_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShift_MetaData), NewProp_bShift_MetaData) };
void Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCmd_SetBit(void* Obj)
{
	((FDebugFrameworkInputChord*)Obj)->bCmd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCmd = { "bCmd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDebugFrameworkInputChord), &Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCmd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCmd_MetaData), NewProp_bCmd_MetaData) };
void Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bRequireExactModifiers_SetBit(void* Obj)
{
	((FDebugFrameworkInputChord*)Obj)->bRequireExactModifiers = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bRequireExactModifiers = { "bRequireExactModifiers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDebugFrameworkInputChord), &Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bRequireExactModifiers_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireExactModifiers_MetaData), NewProp_bRequireExactModifiers_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCtrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bAlt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bCmd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewProp_bRequireExactModifiers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDebugFrameworkInputChord Property Definitions **********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
	nullptr,
	&NewStructOps,
	"DebugFrameworkInputChord",
	Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::PropPointers),
	sizeof(FDebugFrameworkInputChord),
	alignof(FDebugFrameworkInputChord),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDebugFrameworkInputChord()
{
	if (!Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.InnerSingleton, Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord.InnerSingleton);
}
// ********** End ScriptStruct FDebugFrameworkInputChord *******************************************

// ********** Begin Enum EDebugFrameworkPlayerControllerPolicy *************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy;
static UEnum* EDebugFrameworkPlayerControllerPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy, (UObject*)Z_Construct_UPackage__Script_DebugFrameworkCore(), TEXT("EDebugFrameworkPlayerControllerPolicy"));
	}
	return Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.OuterSingleton;
}
template<> DEBUGFRAMEWORKCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EDebugFrameworkPlayerControllerPolicy>()
{
	return EDebugFrameworkPlayerControllerPolicy_StaticEnum();
}
struct Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ExplicitLocalPlayerIndex.Name", "EDebugFrameworkPlayerControllerPolicy::ExplicitLocalPlayerIndex" },
		{ "FirstLocal.Name", "EDebugFrameworkPlayerControllerPolicy::FirstLocal" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
		{ "PrimaryLocalPlayer.Name", "EDebugFrameworkPlayerControllerPolicy::PrimaryLocalPlayer" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDebugFrameworkPlayerControllerPolicy::FirstLocal", (int64)EDebugFrameworkPlayerControllerPolicy::FirstLocal },
		{ "EDebugFrameworkPlayerControllerPolicy::PrimaryLocalPlayer", (int64)EDebugFrameworkPlayerControllerPolicy::PrimaryLocalPlayer },
		{ "EDebugFrameworkPlayerControllerPolicy::ExplicitLocalPlayerIndex", (int64)EDebugFrameworkPlayerControllerPolicy::ExplicitLocalPlayerIndex },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
	nullptr,
	"EDebugFrameworkPlayerControllerPolicy",
	"EDebugFrameworkPlayerControllerPolicy",
	Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy()
{
	if (!Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.InnerSingleton, Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy.InnerSingleton;
}
// ********** End Enum EDebugFrameworkPlayerControllerPolicy ***************************************

// ********** Begin Class UDebugFrameworkSettings Function Get *************************************
struct Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics
{
	struct DebugFrameworkSettings_eventGet_Parms
	{
		const UDebugFrameworkSettings* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Get constinit property declarations ***********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Get constinit property declarations *************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Get Property Definitions **********************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DebugFrameworkSettings_eventGet_Parms, ReturnValue), Z_Construct_UClass_UDebugFrameworkSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::PropPointers) < 2048);
// ********** End Function Get Property Definitions ************************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDebugFrameworkSettings, nullptr, "Get", 	Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::DebugFrameworkSettings_eventGet_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::DebugFrameworkSettings_eventGet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDebugFrameworkSettings_Get()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugFrameworkSettings_Get_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDebugFrameworkSettings::execGet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UDebugFrameworkSettings**)Z_Param__Result=UDebugFrameworkSettings::Get();
	P_NATIVE_END;
}
// ********** End Class UDebugFrameworkSettings Function Get ***************************************

// ********** Begin Class UDebugFrameworkSettings **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDebugFrameworkSettings;
UClass* UDebugFrameworkSettings::GetPrivateStaticClass()
{
	using TClass = UDebugFrameworkSettings;
	if (!Z_Registration_Info_UClass_UDebugFrameworkSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DebugFrameworkSettings"),
			Z_Registration_Info_UClass_UDebugFrameworkSettings.InnerSingleton,
			StaticRegisterNativesUDebugFrameworkSettings,
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
	return Z_Registration_Info_UClass_UDebugFrameworkSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UDebugFrameworkSettings_NoRegister()
{
	return UDebugFrameworkSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDebugFrameworkSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DebugFramework/DebugFrameworkSettings.h" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabledByDefault_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceVisibleInEditor_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceVisibleInNonShipping_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAlwaysShowControlMenuInEditor_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAlwaysShowControlMenuInNonShipping_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bControlMenuFollowsOverlay_MetaData[] = {
		{ "Category", "DebugFramework" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleVisibilityChord_MetaData[] = {
		{ "Category", "DebugFramework|Input" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerControllerPolicy_MetaData[] = {
		{ "Category", "DebugFramework|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Policy for selecting which local player controller owns debug input and UI. */" },
#endif
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Policy for selecting which local player controller owns debug input and UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplicitLocalPlayerIndex_MetaData[] = {
		{ "Category", "DebugFramework|Input" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Used when policy is ExplicitLocalPlayerIndex. */" },
#endif
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used when policy is ExplicitLocalPlayerIndex." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleVisibilityKey_MetaData[] = {
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use ToggleVisibilityChord" },
		{ "DisplayName", "Toggle Visibility Key (Deprecated)" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataRefreshInterval_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.02" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPanelPosition_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPanelSize_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinPanelSize_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPanelSize_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseWheelResizeStep_MetaData[] = {
		{ "Category", "DebugFramework|Panels" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveThrottleSeconds_MetaData[] = {
		{ "Category", "DebugFramework|Persistence" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/DebugFramework/DebugFrameworkSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDebugFrameworkSettings constinit property declarations ******************
	static void NewProp_bEnabledByDefault_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabledByDefault;
	static void NewProp_bForceVisibleInEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceVisibleInEditor;
	static void NewProp_bForceVisibleInNonShipping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceVisibleInNonShipping;
	static void NewProp_bAlwaysShowControlMenuInEditor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlwaysShowControlMenuInEditor;
	static void NewProp_bAlwaysShowControlMenuInNonShipping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlwaysShowControlMenuInNonShipping;
	static void NewProp_bControlMenuFollowsOverlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bControlMenuFollowsOverlay;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ToggleVisibilityChord;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlayerControllerPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlayerControllerPolicy;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExplicitLocalPlayerIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ToggleVisibilityKey;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DataRefreshInterval;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultPanelPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultPanelSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinPanelSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxPanelSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseWheelResizeStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SaveThrottleSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDebugFrameworkSettings constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Get"), .Pointer = &UDebugFrameworkSettings::execGet },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugFrameworkSettings_Get, "Get" }, // 2636252543
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugFrameworkSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDebugFrameworkSettings_Statics

// ********** Begin Class UDebugFrameworkSettings Property Definitions *****************************
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bEnabledByDefault_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bEnabledByDefault = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bEnabledByDefault = { "bEnabledByDefault", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bEnabledByDefault_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabledByDefault_MetaData), NewProp_bEnabledByDefault_MetaData) };
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInEditor_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bForceVisibleInEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInEditor = { "bForceVisibleInEditor", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceVisibleInEditor_MetaData), NewProp_bForceVisibleInEditor_MetaData) };
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInNonShipping_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bForceVisibleInNonShipping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInNonShipping = { "bForceVisibleInNonShipping", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInNonShipping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceVisibleInNonShipping_MetaData), NewProp_bForceVisibleInNonShipping_MetaData) };
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInEditor_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bAlwaysShowControlMenuInEditor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInEditor = { "bAlwaysShowControlMenuInEditor", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInEditor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAlwaysShowControlMenuInEditor_MetaData), NewProp_bAlwaysShowControlMenuInEditor_MetaData) };
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInNonShipping_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bAlwaysShowControlMenuInNonShipping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInNonShipping = { "bAlwaysShowControlMenuInNonShipping", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInNonShipping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAlwaysShowControlMenuInNonShipping_MetaData), NewProp_bAlwaysShowControlMenuInNonShipping_MetaData) };
void Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bControlMenuFollowsOverlay_SetBit(void* Obj)
{
	((UDebugFrameworkSettings*)Obj)->bControlMenuFollowsOverlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bControlMenuFollowsOverlay = { "bControlMenuFollowsOverlay", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDebugFrameworkSettings), &Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bControlMenuFollowsOverlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bControlMenuFollowsOverlay_MetaData), NewProp_bControlMenuFollowsOverlay_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ToggleVisibilityChord = { "ToggleVisibilityChord", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, ToggleVisibilityChord), Z_Construct_UScriptStruct_FDebugFrameworkInputChord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleVisibilityChord_MetaData), NewProp_ToggleVisibilityChord_MetaData) }; // 2569066584
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_PlayerControllerPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_PlayerControllerPolicy = { "PlayerControllerPolicy", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, PlayerControllerPolicy), Z_Construct_UEnum_DebugFrameworkCore_EDebugFrameworkPlayerControllerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerControllerPolicy_MetaData), NewProp_PlayerControllerPolicy_MetaData) }; // 1364335605
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ExplicitLocalPlayerIndex = { "ExplicitLocalPlayerIndex", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, ExplicitLocalPlayerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplicitLocalPlayerIndex_MetaData), NewProp_ExplicitLocalPlayerIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ToggleVisibilityKey = { "ToggleVisibilityKey", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, ToggleVisibilityKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleVisibilityKey_MetaData), NewProp_ToggleVisibilityKey_MetaData) }; // 2693575693
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DataRefreshInterval = { "DataRefreshInterval", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, DataRefreshInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataRefreshInterval_MetaData), NewProp_DataRefreshInterval_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DefaultPanelPosition = { "DefaultPanelPosition", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, DefaultPanelPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPanelPosition_MetaData), NewProp_DefaultPanelPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DefaultPanelSize = { "DefaultPanelSize", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, DefaultPanelSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPanelSize_MetaData), NewProp_DefaultPanelSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MinPanelSize = { "MinPanelSize", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, MinPanelSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinPanelSize_MetaData), NewProp_MinPanelSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MaxPanelSize = { "MaxPanelSize", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, MaxPanelSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPanelSize_MetaData), NewProp_MaxPanelSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MouseWheelResizeStep = { "MouseWheelResizeStep", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, MouseWheelResizeStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseWheelResizeStep_MetaData), NewProp_MouseWheelResizeStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_SaveThrottleSeconds = { "SaveThrottleSeconds", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDebugFrameworkSettings, SaveThrottleSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveThrottleSeconds_MetaData), NewProp_SaveThrottleSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDebugFrameworkSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bEnabledByDefault,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bForceVisibleInNonShipping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInEditor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bAlwaysShowControlMenuInNonShipping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_bControlMenuFollowsOverlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ToggleVisibilityChord,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_PlayerControllerPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_PlayerControllerPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ExplicitLocalPlayerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_ToggleVisibilityKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DataRefreshInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DefaultPanelPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_DefaultPanelSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MinPanelSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MaxPanelSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_MouseWheelResizeStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDebugFrameworkSettings_Statics::NewProp_SaveThrottleSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSettings_Statics::PropPointers) < 2048);
// ********** End Class UDebugFrameworkSettings Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UDebugFrameworkSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_DebugFrameworkCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugFrameworkSettings_Statics::ClassParams = {
	&UDebugFrameworkSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDebugFrameworkSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDebugFrameworkSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDebugFrameworkSettings_Statics::Class_MetaDataParams)
};
void UDebugFrameworkSettings::StaticRegisterNativesUDebugFrameworkSettings()
{
	UClass* Class = UDebugFrameworkSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDebugFrameworkSettings_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDebugFrameworkSettings()
{
	if (!Z_Registration_Info_UClass_UDebugFrameworkSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugFrameworkSettings.OuterSingleton, Z_Construct_UClass_UDebugFrameworkSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDebugFrameworkSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDebugFrameworkSettings);
UDebugFrameworkSettings::~UDebugFrameworkSettings() {}
// ********** End Class UDebugFrameworkSettings ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDebugFrameworkPlayerControllerPolicy_StaticEnum, TEXT("EDebugFrameworkPlayerControllerPolicy"), &Z_Registration_Info_UEnum_EDebugFrameworkPlayerControllerPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1364335605U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDebugFrameworkInputChord::StaticStruct, Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics::NewStructOps, TEXT("DebugFrameworkInputChord"),&Z_Registration_Info_UScriptStruct_FDebugFrameworkInputChord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDebugFrameworkInputChord), 2569066584U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDebugFrameworkSettings, UDebugFrameworkSettings::StaticClass, TEXT("UDebugFrameworkSettings"), &Z_Registration_Info_UClass_UDebugFrameworkSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugFrameworkSettings), 1901743146U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_400940355{
	TEXT("/Script/DebugFrameworkCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h__Script_DebugFrameworkCore_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
