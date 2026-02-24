// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackOrchestratorComponent.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackOrchestratorComponent() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackOrchestratorComponent();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister();
COMBATCORE_API UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature();
COMBATCORE_API UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackRequest();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FAttackRequestEvent ***************************************************
struct Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics
{
	struct _Script_CombatCore_eventAttackRequestEvent_Parms
	{
		FCombatAttackRequest Request;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAttackRequestEvent constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FAttackRequestEvent constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FAttackRequestEvent Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_CombatCore_eventAttackRequestEvent_Parms, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::NewProp_Request,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FAttackRequestEvent Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CombatCore, nullptr, "AttackRequestEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::_Script_CombatCore_eventAttackRequestEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::_Script_CombatCore_eventAttackRequestEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAttackRequestEvent_DelegateWrapper(const FMulticastScriptDelegate& AttackRequestEvent, FCombatAttackRequest const& Request)
{
	struct _Script_CombatCore_eventAttackRequestEvent_Parms
	{
		FCombatAttackRequest Request;
	};
	_Script_CombatCore_eventAttackRequestEvent_Parms Parms;
	Parms.Request=Request;
	AttackRequestEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FAttackRequestEvent *****************************************************

// ********** Begin Delegate FAttackSimpleEvent ****************************************************
struct Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FAttackSimpleEvent constinit property declarations ********************
// ********** End Delegate FAttackSimpleEvent constinit property declarations **********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_CombatCore, nullptr, "AttackSimpleEvent__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FAttackSimpleEvent_DelegateWrapper(const FMulticastScriptDelegate& AttackSimpleEvent)
{
	AttackSimpleEvent.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FAttackSimpleEvent ******************************************************

// ********** Begin Class UAttackOrchestratorComponent Function BeginAttackIntent ******************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics
{
	struct AttackOrchestratorComponent_eventBeginAttackIntent_Parms
	{
		FCombatAttackRequest Request;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginAttackIntent constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginAttackIntent constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginAttackIntent Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackOrchestratorComponent_eventBeginAttackIntent_Parms, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
void Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AttackOrchestratorComponent_eventBeginAttackIntent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AttackOrchestratorComponent_eventBeginAttackIntent_Parms), &Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::PropPointers) < 2048);
// ********** End Function BeginAttackIntent Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "BeginAttackIntent", 	Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::AttackOrchestratorComponent_eventBeginAttackIntent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::AttackOrchestratorComponent_eventBeginAttackIntent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execBeginAttackIntent)
{
	P_GET_STRUCT_REF(FCombatAttackRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BeginAttackIntent(Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function BeginAttackIntent ********************

// ********** Begin Class UAttackOrchestratorComponent Function CancelAttack ***********************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelAttack constinit property declarations **************************
// ********** End Function CancelAttack constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "CancelAttack", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execCancelAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelAttack();
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function CancelAttack *************************

// ********** Begin Class UAttackOrchestratorComponent Function ClearPendingRequest ****************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearPendingRequest constinit property declarations *******************
// ********** End Function ClearPendingRequest constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "ClearPendingRequest", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execClearPendingRequest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearPendingRequest();
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function ClearPendingRequest ******************

// ********** Begin Class UAttackOrchestratorComponent Function CommitAttack ***********************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CommitAttack constinit property declarations **************************
// ********** End Function CommitAttack constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "CommitAttack", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execCommitAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CommitAttack();
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function CommitAttack *************************

// ********** Begin Class UAttackOrchestratorComponent Function ConsumePendingRequest **************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics
{
	struct AttackOrchestratorComponent_eventConsumePendingRequest_Parms
	{
		FCombatAttackRequest OutRequest;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConsumePendingRequest constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRequest;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConsumePendingRequest constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConsumePendingRequest Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_OutRequest = { "OutRequest", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackOrchestratorComponent_eventConsumePendingRequest_Parms, OutRequest), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(0, nullptr) }; // 3210230800
void Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AttackOrchestratorComponent_eventConsumePendingRequest_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AttackOrchestratorComponent_eventConsumePendingRequest_Parms), &Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_OutRequest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::PropPointers) < 2048);
// ********** End Function ConsumePendingRequest Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "ConsumePendingRequest", 	Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::AttackOrchestratorComponent_eventConsumePendingRequest_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::AttackOrchestratorComponent_eventConsumePendingRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execConsumePendingRequest)
{
	P_GET_STRUCT_REF(FCombatAttackRequest,Z_Param_Out_OutRequest);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ConsumePendingRequest(Z_Param_Out_OutRequest);
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function ConsumePendingRequest ****************

// ********** Begin Class UAttackOrchestratorComponent Function TryCommitAttack ********************
struct Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics
{
	struct AttackOrchestratorComponent_eventTryCommitAttack_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attempts to send confirm only when the profile ability is active (or can be activated now). */" },
#endif
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attempts to send confirm only when the profile ability is active (or can be activated now)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TryCommitAttack constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryCommitAttack constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryCommitAttack Property Definitions **********************************
void Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AttackOrchestratorComponent_eventTryCommitAttack_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AttackOrchestratorComponent_eventTryCommitAttack_Parms), &Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::PropPointers) < 2048);
// ********** End Function TryCommitAttack Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackOrchestratorComponent, nullptr, "TryCommitAttack", 	Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::AttackOrchestratorComponent_eventTryCommitAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::AttackOrchestratorComponent_eventTryCommitAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackOrchestratorComponent::execTryCommitAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryCommitAttack();
	P_NATIVE_END;
}
// ********** End Class UAttackOrchestratorComponent Function TryCommitAttack **********************

// ********** Begin Class UAttackOrchestratorComponent *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackOrchestratorComponent;
UClass* UAttackOrchestratorComponent::GetPrivateStaticClass()
{
	using TClass = UAttackOrchestratorComponent;
	if (!Z_Registration_Info_UClass_UAttackOrchestratorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackOrchestratorComponent"),
			Z_Registration_Info_UClass_UAttackOrchestratorComponent.InnerSingleton,
			StaticRegisterNativesUAttackOrchestratorComponent,
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
	return Z_Registration_Info_UClass_UAttackOrchestratorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister()
{
	return UAttackOrchestratorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackOrchestratorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Combat" },
		{ "IncludePath", "Combat/AttackOrchestratorComponent.h" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnIntentStarted_MetaData[] = {
		{ "Category", "Combat|Events" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCommitRequested_MetaData[] = {
		{ "Category", "Combat|Events" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCancelled_MetaData[] = {
		{ "Category", "Combat|Events" },
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGrantAbility_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, grant the ability on first use when missing. */" },
#endif
		{ "ModuleRelativePath", "Public/Combat/AttackOrchestratorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, grant the ability on first use when missing." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackOrchestratorComponent constinit property declarations *************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnIntentStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCommitRequested;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCancelled;
	static void NewProp_bAutoGrantAbility_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGrantAbility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAttackOrchestratorComponent constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginAttackIntent"), .Pointer = &UAttackOrchestratorComponent::execBeginAttackIntent },
		{ .NameUTF8 = UTF8TEXT("CancelAttack"), .Pointer = &UAttackOrchestratorComponent::execCancelAttack },
		{ .NameUTF8 = UTF8TEXT("ClearPendingRequest"), .Pointer = &UAttackOrchestratorComponent::execClearPendingRequest },
		{ .NameUTF8 = UTF8TEXT("CommitAttack"), .Pointer = &UAttackOrchestratorComponent::execCommitAttack },
		{ .NameUTF8 = UTF8TEXT("ConsumePendingRequest"), .Pointer = &UAttackOrchestratorComponent::execConsumePendingRequest },
		{ .NameUTF8 = UTF8TEXT("TryCommitAttack"), .Pointer = &UAttackOrchestratorComponent::execTryCommitAttack },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_BeginAttackIntent, "BeginAttackIntent" }, // 843391212
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_CancelAttack, "CancelAttack" }, // 2395326687
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_ClearPendingRequest, "ClearPendingRequest" }, // 919392035
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_CommitAttack, "CommitAttack" }, // 2669846046
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_ConsumePendingRequest, "ConsumePendingRequest" }, // 4271495798
		{ &Z_Construct_UFunction_UAttackOrchestratorComponent_TryCommitAttack, "TryCommitAttack" }, // 4115358778
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackOrchestratorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackOrchestratorComponent_Statics

// ********** Begin Class UAttackOrchestratorComponent Property Definitions ************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnIntentStarted = { "OnIntentStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackOrchestratorComponent, OnIntentStarted), Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnIntentStarted_MetaData), NewProp_OnIntentStarted_MetaData) }; // 4121320215
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnCommitRequested = { "OnCommitRequested", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackOrchestratorComponent, OnCommitRequested), Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCommitRequested_MetaData), NewProp_OnCommitRequested_MetaData) }; // 956098553
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnCancelled = { "OnCancelled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackOrchestratorComponent, OnCancelled), Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCancelled_MetaData), NewProp_OnCancelled_MetaData) }; // 956098553
void Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_bAutoGrantAbility_SetBit(void* Obj)
{
	((UAttackOrchestratorComponent*)Obj)->bAutoGrantAbility = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_bAutoGrantAbility = { "bAutoGrantAbility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAttackOrchestratorComponent), &Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_bAutoGrantAbility_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGrantAbility_MetaData), NewProp_bAutoGrantAbility_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttackOrchestratorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnIntentStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnCommitRequested,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_OnCancelled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackOrchestratorComponent_Statics::NewProp_bAutoGrantAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackOrchestratorComponent_Statics::PropPointers) < 2048);
// ********** End Class UAttackOrchestratorComponent Property Definitions **************************
UObject* (*const Z_Construct_UClass_UAttackOrchestratorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackOrchestratorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackOrchestratorComponent_Statics::ClassParams = {
	&UAttackOrchestratorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAttackOrchestratorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttackOrchestratorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackOrchestratorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackOrchestratorComponent_Statics::Class_MetaDataParams)
};
void UAttackOrchestratorComponent::StaticRegisterNativesUAttackOrchestratorComponent()
{
	UClass* Class = UAttackOrchestratorComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAttackOrchestratorComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAttackOrchestratorComponent()
{
	if (!Z_Registration_Info_UClass_UAttackOrchestratorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackOrchestratorComponent.OuterSingleton, Z_Construct_UClass_UAttackOrchestratorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackOrchestratorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackOrchestratorComponent);
UAttackOrchestratorComponent::~UAttackOrchestratorComponent() {}
// ********** End Class UAttackOrchestratorComponent ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackOrchestratorComponent, UAttackOrchestratorComponent::StaticClass, TEXT("UAttackOrchestratorComponent"), &Z_Registration_Info_UClass_UAttackOrchestratorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackOrchestratorComponent), 429263518U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h__Script_CombatCore_335714243{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
