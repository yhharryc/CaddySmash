// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/CombatWeaponActor.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCombatWeaponActor() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_ACombatWeaponActor();
COMBATCORE_API UClass* Z_Construct_UClass_ACombatWeaponActor_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponExecutor_NoRegister();
COMBATCORE_API UEnum* Z_Construct_UEnum_CombatCore_EWeaponMotionType();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EWeaponMotionType *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EWeaponMotionType;
static UEnum* EWeaponMotionType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EWeaponMotionType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EWeaponMotionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CombatCore_EWeaponMotionType, (UObject*)Z_Construct_UPackage__Script_CombatCore(), TEXT("EWeaponMotionType"));
	}
	return Z_Registration_Info_UEnum_EWeaponMotionType.OuterSingleton;
}
template<> COMBATCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EWeaponMotionType>()
{
	return EWeaponMotionType_StaticEnum();
}
struct Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
		{ "None.Name", "EWeaponMotionType::None" },
		{ "Thrust.Name", "EWeaponMotionType::Thrust" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EWeaponMotionType::None", (int64)EWeaponMotionType::None },
		{ "EWeaponMotionType::Thrust", (int64)EWeaponMotionType::Thrust },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CombatCore,
	nullptr,
	"EWeaponMotionType",
	"EWeaponMotionType",
	Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CombatCore_EWeaponMotionType()
{
	if (!Z_Registration_Info_UEnum_EWeaponMotionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EWeaponMotionType.InnerSingleton, Z_Construct_UEnum_CombatCore_EWeaponMotionType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EWeaponMotionType.InnerSingleton;
}
// ********** End Enum EWeaponMotionType ***********************************************************

// ********** Begin Class ACombatWeaponActor Function AimAtActor ***********************************
struct Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics
{
	struct CombatWeaponActor_eventAimAtActor_Parms
	{
		AActor* Target;
		bool bSnap;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Aim" },
		{ "CPP_Default_bSnap", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AimAtActor constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static void NewProp_bSnap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AimAtActor constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AimAtActor Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatWeaponActor_eventAimAtActor_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_bSnap_SetBit(void* Obj)
{
	((CombatWeaponActor_eventAimAtActor_Parms*)Obj)->bSnap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_bSnap = { "bSnap", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatWeaponActor_eventAimAtActor_Parms), &Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_bSnap_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::NewProp_bSnap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::PropPointers) < 2048);
// ********** End Function AimAtActor Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "AimAtActor", 	Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::CombatWeaponActor_eventAimAtActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::CombatWeaponActor_eventAimAtActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACombatWeaponActor_AimAtActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_AimAtActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execAimAtActor)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_GET_UBOOL(Z_Param_bSnap);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AimAtActor(Z_Param_Target,Z_Param_bSnap);
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function AimAtActor *************************************

// ********** Begin Class ACombatWeaponActor Function ClearAimTarget *******************************
struct Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearAimTarget constinit property declarations ************************
// ********** End Function ClearAimTarget constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "ClearAimTarget", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execClearAimTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAimTarget();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function ClearAimTarget *********************************

// ********** Begin Class ACombatWeaponActor Function ClearCachedAttackContext *********************
struct Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearCachedAttackContext constinit property declarations **************
// ********** End Function ClearCachedAttackContext constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "ClearCachedAttackContext", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execClearCachedAttackContext)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearCachedAttackContext();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function ClearCachedAttackContext ***********************

// ********** Begin Class ACombatWeaponActor Function GetCachedAttackContext ***********************
struct Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics
{
	struct CombatWeaponActor_eventGetCachedAttackContext_Parms
	{
		FCombatAttackContext OutContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCachedAttackContext constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCachedAttackContext constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCachedAttackContext Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_OutContext = { "OutContext", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatWeaponActor_eventGetCachedAttackContext_Parms, OutContext), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(0, nullptr) }; // 829964288
void Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CombatWeaponActor_eventGetCachedAttackContext_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatWeaponActor_eventGetCachedAttackContext_Parms), &Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_OutContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::PropPointers) < 2048);
// ********** End Function GetCachedAttackContext Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "GetCachedAttackContext", 	Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::CombatWeaponActor_eventGetCachedAttackContext_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::CombatWeaponActor_eventGetCachedAttackContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execGetCachedAttackContext)
{
	P_GET_STRUCT_REF(FCombatAttackContext,Z_Param_Out_OutContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetCachedAttackContext(Z_Param_Out_OutContext);
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function GetCachedAttackContext *************************

// ********** Begin Class ACombatWeaponActor Function HasCachedAttackContext ***********************
struct Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics
{
	struct CombatWeaponActor_eventHasCachedAttackContext_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasCachedAttackContext constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasCachedAttackContext constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasCachedAttackContext Property Definitions ***************************
void Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CombatWeaponActor_eventHasCachedAttackContext_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatWeaponActor_eventHasCachedAttackContext_Parms), &Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::PropPointers) < 2048);
// ********** End Function HasCachedAttackContext Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "HasCachedAttackContext", 	Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::CombatWeaponActor_eventHasCachedAttackContext_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::CombatWeaponActor_eventHasCachedAttackContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execHasCachedAttackContext)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasCachedAttackContext();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function HasCachedAttackContext *************************

// ********** Begin Class ACombatWeaponActor Function IsMotionActive *******************************
struct Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics
{
	struct CombatWeaponActor_eventIsMotionActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsMotionActive constinit property declarations ************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMotionActive constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMotionActive Property Definitions ***********************************
void Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CombatWeaponActor_eventIsMotionActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatWeaponActor_eventIsMotionActive_Parms), &Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::PropPointers) < 2048);
// ********** End Function IsMotionActive Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "IsMotionActive", 	Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::CombatWeaponActor_eventIsMotionActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::CombatWeaponActor_eventIsMotionActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execIsMotionActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsMotionActive();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function IsMotionActive *********************************

// ********** Begin Class ACombatWeaponActor Function OnExecuteAttack ******************************
struct CombatWeaponActor_eventOnExecuteAttack_Parms
{
	FCombatAttackContext Context;
};
static FName NAME_ACombatWeaponActor_OnExecuteAttack = FName(TEXT("OnExecuteAttack"));
void ACombatWeaponActor::OnExecuteAttack(FCombatAttackContext const& Context)
{
	CombatWeaponActor_eventOnExecuteAttack_Parms Parms;
	Parms.Context=Context;
	UFunction* Func = FindFunctionChecked(NAME_ACombatWeaponActor_OnExecuteAttack);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnExecuteAttack constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnExecuteAttack constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnExecuteAttack Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatWeaponActor_eventOnExecuteAttack_Parms, Context), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 829964288
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::PropPointers) < 2048);
// ********** End Function OnExecuteAttack Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "OnExecuteAttack", 	Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::PropPointers), 
sizeof(CombatWeaponActor_eventOnExecuteAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(CombatWeaponActor_eventOnExecuteAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ACombatWeaponActor Function OnExecuteAttack ********************************

// ********** Begin Class ACombatWeaponActor Function OnMotionEnded ********************************
static FName NAME_ACombatWeaponActor_OnMotionEnded = FName(TEXT("OnMotionEnded"));
void ACombatWeaponActor::OnMotionEnded()
{
	UFunction* Func = FindFunctionChecked(NAME_ACombatWeaponActor_OnMotionEnded);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnMotionEnded constinit property declarations *************************
// ********** End Function OnMotionEnded constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "OnMotionEnded", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ACombatWeaponActor Function OnMotionEnded **********************************

// ********** Begin Class ACombatWeaponActor Function OnMotionStarted ******************************
static FName NAME_ACombatWeaponActor_OnMotionStarted = FName(TEXT("OnMotionStarted"));
void ACombatWeaponActor::OnMotionStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_ACombatWeaponActor_OnMotionStarted);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnMotionStarted constinit property declarations ***********************
// ********** End Function OnMotionStarted constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "OnMotionStarted", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ACombatWeaponActor Function OnMotionStarted ********************************

// ********** Begin Class ACombatWeaponActor Function StartMotion **********************************
struct Z_Construct_UFunction_ACombatWeaponActor_StartMotion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartMotion constinit property declarations ***************************
// ********** End Function StartMotion constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_StartMotion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "StartMotion", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_StartMotion_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_StartMotion_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_StartMotion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_StartMotion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execStartMotion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartMotion();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function StartMotion ************************************

// ********** Begin Class ACombatWeaponActor Function StopMotion ***********************************
struct Z_Construct_UFunction_ACombatWeaponActor_StopMotion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopMotion constinit property declarations ****************************
// ********** End Function StopMotion constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatWeaponActor_StopMotion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACombatWeaponActor, nullptr, "StopMotion", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatWeaponActor_StopMotion_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACombatWeaponActor_StopMotion_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACombatWeaponActor_StopMotion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACombatWeaponActor_StopMotion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACombatWeaponActor::execStopMotion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopMotion();
	P_NATIVE_END;
}
// ********** End Class ACombatWeaponActor Function StopMotion *************************************

// ********** Begin Class ACombatWeaponActor *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACombatWeaponActor;
UClass* ACombatWeaponActor::GetPrivateStaticClass()
{
	using TClass = ACombatWeaponActor;
	if (!Z_Registration_Info_UClass_ACombatWeaponActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CombatWeaponActor"),
			Z_Registration_Info_UClass_ACombatWeaponActor.InnerSingleton,
			StaticRegisterNativesACombatWeaponActor,
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
	return Z_Registration_Info_UClass_ACombatWeaponActor.InnerSingleton;
}
UClass* Z_Construct_UClass_ACombatWeaponActor_NoRegister()
{
	return ACombatWeaponActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACombatWeaponActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Combat/CombatWeaponActor.h" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimRoot_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionRoot_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tip_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttachToOwnerOnBeginPlay_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttachSocketName_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionType_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoPlayMotionOnExecute_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMaintainAimAtTarget_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAimYawOnly_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimYawOffset_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimInterpSpeed_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawAimDebug_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimDebugLength_MetaData[] = {
		{ "Category", "Combat|Aim" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustDistance_MetaData[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustDuration_MetaData[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnDuration_MetaData[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustAxis_MetaData[] = {
		{ "Category", "Combat|Motion" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAttackProfile_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoClearContextOnMotionEnd_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/Combat/CombatWeaponActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ACombatWeaponActor constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AimRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Tip;
	static void NewProp_bAttachToOwnerOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttachToOwnerOnBeginPlay;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AttachSocketName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MotionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MotionType;
	static void NewProp_bAutoPlayMotionOnExecute_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoPlayMotionOnExecute;
	static void NewProp_bMaintainAimAtTarget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaintainAimAtTarget;
	static void NewProp_bAimYawOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAimYawOnly;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimYawOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimInterpSpeed;
	static void NewProp_bDrawAimDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawAimDebug;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimDebugLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrustDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrustDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnDuration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ThrustAxis;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultAttackProfile;
	static void NewProp_bAutoClearContextOnMotionEnd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoClearContextOnMotionEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ACombatWeaponActor constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AimAtActor"), .Pointer = &ACombatWeaponActor::execAimAtActor },
		{ .NameUTF8 = UTF8TEXT("ClearAimTarget"), .Pointer = &ACombatWeaponActor::execClearAimTarget },
		{ .NameUTF8 = UTF8TEXT("ClearCachedAttackContext"), .Pointer = &ACombatWeaponActor::execClearCachedAttackContext },
		{ .NameUTF8 = UTF8TEXT("GetCachedAttackContext"), .Pointer = &ACombatWeaponActor::execGetCachedAttackContext },
		{ .NameUTF8 = UTF8TEXT("HasCachedAttackContext"), .Pointer = &ACombatWeaponActor::execHasCachedAttackContext },
		{ .NameUTF8 = UTF8TEXT("IsMotionActive"), .Pointer = &ACombatWeaponActor::execIsMotionActive },
		{ .NameUTF8 = UTF8TEXT("StartMotion"), .Pointer = &ACombatWeaponActor::execStartMotion },
		{ .NameUTF8 = UTF8TEXT("StopMotion"), .Pointer = &ACombatWeaponActor::execStopMotion },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACombatWeaponActor_AimAtActor, "AimAtActor" }, // 497457308
		{ &Z_Construct_UFunction_ACombatWeaponActor_ClearAimTarget, "ClearAimTarget" }, // 1529549325
		{ &Z_Construct_UFunction_ACombatWeaponActor_ClearCachedAttackContext, "ClearCachedAttackContext" }, // 537654199
		{ &Z_Construct_UFunction_ACombatWeaponActor_GetCachedAttackContext, "GetCachedAttackContext" }, // 519146858
		{ &Z_Construct_UFunction_ACombatWeaponActor_HasCachedAttackContext, "HasCachedAttackContext" }, // 752900253
		{ &Z_Construct_UFunction_ACombatWeaponActor_IsMotionActive, "IsMotionActive" }, // 393927172
		{ &Z_Construct_UFunction_ACombatWeaponActor_OnExecuteAttack, "OnExecuteAttack" }, // 960643517
		{ &Z_Construct_UFunction_ACombatWeaponActor_OnMotionEnded, "OnMotionEnded" }, // 2121549548
		{ &Z_Construct_UFunction_ACombatWeaponActor_OnMotionStarted, "OnMotionStarted" }, // 2332127853
		{ &Z_Construct_UFunction_ACombatWeaponActor_StartMotion, "StartMotion" }, // 1384955982
		{ &Z_Construct_UFunction_ACombatWeaponActor_StopMotion, "StopMotion" }, // 4015539961
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACombatWeaponActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACombatWeaponActor_Statics

// ********** Begin Class ACombatWeaponActor Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimRoot = { "AimRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, AimRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimRoot_MetaData), NewProp_AimRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionRoot = { "MotionRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, MotionRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionRoot_MetaData), NewProp_MotionRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Tip = { "Tip", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, Tip), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tip_MetaData), NewProp_Tip_MetaData) };
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAttachToOwnerOnBeginPlay_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bAttachToOwnerOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAttachToOwnerOnBeginPlay = { "bAttachToOwnerOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAttachToOwnerOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttachToOwnerOnBeginPlay_MetaData), NewProp_bAttachToOwnerOnBeginPlay_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AttachSocketName = { "AttachSocketName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, AttachSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttachSocketName_MetaData), NewProp_AttachSocketName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionType = { "MotionType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, MotionType), Z_Construct_UEnum_CombatCore_EWeaponMotionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionType_MetaData), NewProp_MotionType_MetaData) }; // 1072785743
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoPlayMotionOnExecute_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bAutoPlayMotionOnExecute = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoPlayMotionOnExecute = { "bAutoPlayMotionOnExecute", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoPlayMotionOnExecute_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoPlayMotionOnExecute_MetaData), NewProp_bAutoPlayMotionOnExecute_MetaData) };
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bMaintainAimAtTarget_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bMaintainAimAtTarget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bMaintainAimAtTarget = { "bMaintainAimAtTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bMaintainAimAtTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMaintainAimAtTarget_MetaData), NewProp_bMaintainAimAtTarget_MetaData) };
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAimYawOnly_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bAimYawOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAimYawOnly = { "bAimYawOnly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAimYawOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAimYawOnly_MetaData), NewProp_bAimYawOnly_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimYawOffset = { "AimYawOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, AimYawOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimYawOffset_MetaData), NewProp_AimYawOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimInterpSpeed = { "AimInterpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, AimInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimInterpSpeed_MetaData), NewProp_AimInterpSpeed_MetaData) };
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bDrawAimDebug_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bDrawAimDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bDrawAimDebug = { "bDrawAimDebug", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bDrawAimDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawAimDebug_MetaData), NewProp_bDrawAimDebug_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimDebugLength = { "AimDebugLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, AimDebugLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimDebugLength_MetaData), NewProp_AimDebugLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustDistance = { "ThrustDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, ThrustDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustDistance_MetaData), NewProp_ThrustDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustDuration = { "ThrustDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, ThrustDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustDuration_MetaData), NewProp_ThrustDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ReturnDuration = { "ReturnDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, ReturnDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnDuration_MetaData), NewProp_ReturnDuration_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustAxis = { "ThrustAxis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, ThrustAxis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustAxis_MetaData), NewProp_ThrustAxis_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_DefaultAttackProfile = { "DefaultAttackProfile", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, DefaultAttackProfile), Z_Construct_UClass_UAttackProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultAttackProfile_MetaData), NewProp_DefaultAttackProfile_MetaData) };
void Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoClearContextOnMotionEnd_SetBit(void* Obj)
{
	((ACombatWeaponActor*)Obj)->bAutoClearContextOnMotionEnd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoClearContextOnMotionEnd = { "bAutoClearContextOnMotionEnd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACombatWeaponActor), &Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoClearContextOnMotionEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoClearContextOnMotionEnd_MetaData), NewProp_bAutoClearContextOnMotionEnd_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_CachedContext = { "CachedContext", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACombatWeaponActor, CachedContext), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedContext_MetaData), NewProp_CachedContext_MetaData) }; // 829964288
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACombatWeaponActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_Tip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAttachToOwnerOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AttachSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_MotionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoPlayMotionOnExecute,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bMaintainAimAtTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAimYawOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimYawOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bDrawAimDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_AimDebugLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ReturnDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_ThrustAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_DefaultAttackProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_bAutoClearContextOnMotionEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatWeaponActor_Statics::NewProp_CachedContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACombatWeaponActor_Statics::PropPointers) < 2048);
// ********** End Class ACombatWeaponActor Property Definitions ************************************
UObject* (*const Z_Construct_UClass_ACombatWeaponActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACombatWeaponActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACombatWeaponActor_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UWeaponExecutor_NoRegister, (int32)VTABLE_OFFSET(ACombatWeaponActor, IWeaponExecutor), false },  // 315122231
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACombatWeaponActor_Statics::ClassParams = {
	&ACombatWeaponActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACombatWeaponActor_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACombatWeaponActor_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACombatWeaponActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ACombatWeaponActor_Statics::Class_MetaDataParams)
};
void ACombatWeaponActor::StaticRegisterNativesACombatWeaponActor()
{
	UClass* Class = ACombatWeaponActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ACombatWeaponActor_Statics::Funcs));
}
UClass* Z_Construct_UClass_ACombatWeaponActor()
{
	if (!Z_Registration_Info_UClass_ACombatWeaponActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACombatWeaponActor.OuterSingleton, Z_Construct_UClass_ACombatWeaponActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACombatWeaponActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACombatWeaponActor);
ACombatWeaponActor::~ACombatWeaponActor() {}
// ********** End Class ACombatWeaponActor *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EWeaponMotionType_StaticEnum, TEXT("EWeaponMotionType"), &Z_Registration_Info_UEnum_EWeaponMotionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1072785743U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACombatWeaponActor, ACombatWeaponActor::StaticClass, TEXT("ACombatWeaponActor"), &Z_Registration_Info_UClass_ACombatWeaponActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACombatWeaponActor), 897560808U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_2726524925{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h__Script_CombatCore_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
