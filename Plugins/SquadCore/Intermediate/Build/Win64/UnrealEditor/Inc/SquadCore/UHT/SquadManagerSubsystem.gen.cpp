// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadManagerSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadManagerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
SQUADCORE_API UClass* Z_Construct_UClass_UFormationAsset_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_USquadManagerSubsystem();
SQUADCORE_API UClass* Z_Construct_UClass_USquadManagerSubsystem_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadManagerSubsystem Function GetAssignedSlot **************************
struct Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics
{
	struct SquadManagerSubsystem_eventGetAssignedSlot_Parms
	{
		AActor* Member;
		int32 OutSlotId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAssignedSlot constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Member;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutSlotId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAssignedSlot constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAssignedSlot Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_Member = { "Member", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetAssignedSlot_Parms, Member), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_OutSlotId = { "OutSlotId", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetAssignedSlot_Parms, OutSlotId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SquadManagerSubsystem_eventGetAssignedSlot_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SquadManagerSubsystem_eventGetAssignedSlot_Parms), &Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_Member,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_OutSlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::PropPointers) < 2048);
// ********** End Function GetAssignedSlot Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "GetAssignedSlot", 	Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::SquadManagerSubsystem_eventGetAssignedSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::SquadManagerSubsystem_eventGetAssignedSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execGetAssignedSlot)
{
	P_GET_OBJECT(AActor,Z_Param_Member);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutSlotId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAssignedSlot(Z_Param_Member,Z_Param_Out_OutSlotId);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function GetAssignedSlot ****************************

// ********** Begin Class USquadManagerSubsystem Function GetFormationLeader ***********************
struct Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics
{
	struct SquadManagerSubsystem_eventGetFormationLeader_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFormationLeader constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFormationLeader constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFormationLeader Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetFormationLeader_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::PropPointers) < 2048);
// ********** End Function GetFormationLeader Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "GetFormationLeader", 	Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::SquadManagerSubsystem_eventGetFormationLeader_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::SquadManagerSubsystem_eventGetFormationLeader_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execGetFormationLeader)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetFormationLeader();
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function GetFormationLeader *************************

// ********** Begin Class USquadManagerSubsystem Function GetSlotWorldLocation *********************
struct Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics
{
	struct SquadManagerSubsystem_eventGetSlotWorldLocation_Parms
	{
		int32 SlotId;
		FVector OutLocation;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlotWorldLocation constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutLocation;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlotWorldLocation constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlotWorldLocation Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetSlotWorldLocation_Parms, SlotId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_OutLocation = { "OutLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetSlotWorldLocation_Parms, OutLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SquadManagerSubsystem_eventGetSlotWorldLocation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SquadManagerSubsystem_eventGetSlotWorldLocation_Parms), &Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_SlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_OutLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::PropPointers) < 2048);
// ********** End Function GetSlotWorldLocation Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "GetSlotWorldLocation", 	Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::SquadManagerSubsystem_eventGetSlotWorldLocation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::SquadManagerSubsystem_eventGetSlotWorldLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execGetSlotWorldLocation)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSlotWorldLocation(Z_Param_SlotId,Z_Param_Out_OutLocation);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function GetSlotWorldLocation ***********************

// ********** Begin Class USquadManagerSubsystem Function GetSlotWorldTransform ********************
struct Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics
{
	struct SquadManagerSubsystem_eventGetSlotWorldTransform_Parms
	{
		int32 SlotId;
		FTransform OutTransform;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlotWorldTransform constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransform;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlotWorldTransform constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlotWorldTransform Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetSlotWorldTransform_Parms, SlotId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_OutTransform = { "OutTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventGetSlotWorldTransform_Parms, OutTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SquadManagerSubsystem_eventGetSlotWorldTransform_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SquadManagerSubsystem_eventGetSlotWorldTransform_Parms), &Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_SlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_OutTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::PropPointers) < 2048);
// ********** End Function GetSlotWorldTransform Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "GetSlotWorldTransform", 	Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::SquadManagerSubsystem_eventGetSlotWorldTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::SquadManagerSubsystem_eventGetSlotWorldTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execGetSlotWorldTransform)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTransform);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSlotWorldTransform(Z_Param_SlotId,Z_Param_Out_OutTransform);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function GetSlotWorldTransform **********************

// ********** Begin Class USquadManagerSubsystem Function RegisterMember ***************************
struct Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics
{
	struct SquadManagerSubsystem_eventRegisterMember_Parms
	{
		AActor* Member;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterMember constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Member;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterMember constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterMember Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::NewProp_Member = { "Member", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventRegisterMember_Parms, Member), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventRegisterMember_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::NewProp_Member,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::PropPointers) < 2048);
// ********** End Function RegisterMember Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "RegisterMember", 	Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::SquadManagerSubsystem_eventRegisterMember_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::SquadManagerSubsystem_eventRegisterMember_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execRegisterMember)
{
	P_GET_OBJECT(AActor,Z_Param_Member);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->RegisterMember(Z_Param_Member);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function RegisterMember *****************************

// ********** Begin Class USquadManagerSubsystem Function SetFormationAsset ************************
struct Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics
{
	struct SquadManagerSubsystem_eventSetFormationAsset_Parms
	{
		UFormationAsset* InFormation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFormationAsset constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InFormation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFormationAsset constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFormationAsset Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::NewProp_InFormation = { "InFormation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventSetFormationAsset_Parms, InFormation), Z_Construct_UClass_UFormationAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::NewProp_InFormation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::PropPointers) < 2048);
// ********** End Function SetFormationAsset Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "SetFormationAsset", 	Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::SquadManagerSubsystem_eventSetFormationAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::SquadManagerSubsystem_eventSetFormationAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execSetFormationAsset)
{
	P_GET_OBJECT(UFormationAsset,Z_Param_InFormation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFormationAsset(Z_Param_InFormation);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function SetFormationAsset **************************

// ********** Begin Class USquadManagerSubsystem Function SetFormationLeader ***********************
struct Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics
{
	struct SquadManagerSubsystem_eventSetFormationLeader_Parms
	{
		AActor* InLeader;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFormationLeader constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InLeader;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFormationLeader constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFormationLeader Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::NewProp_InLeader = { "InLeader", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventSetFormationLeader_Parms, InLeader), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::NewProp_InLeader,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::PropPointers) < 2048);
// ********** End Function SetFormationLeader Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "SetFormationLeader", 	Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::SquadManagerSubsystem_eventSetFormationLeader_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::SquadManagerSubsystem_eventSetFormationLeader_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execSetFormationLeader)
{
	P_GET_OBJECT(AActor,Z_Param_InLeader);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFormationLeader(Z_Param_InLeader);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function SetFormationLeader *************************

// ********** Begin Class USquadManagerSubsystem Function SetSlotAssignmentPolicy ******************
struct Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics
{
	struct SquadManagerSubsystem_eventSetSlotAssignmentPolicy_Parms
	{
		USquadSlotAssignmentPolicy* InPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSlotAssignmentPolicy constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSlotAssignmentPolicy constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSlotAssignmentPolicy Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::NewProp_InPolicy = { "InPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventSetSlotAssignmentPolicy_Parms, InPolicy), Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::NewProp_InPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetSlotAssignmentPolicy Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "SetSlotAssignmentPolicy", 	Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::SquadManagerSubsystem_eventSetSlotAssignmentPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::SquadManagerSubsystem_eventSetSlotAssignmentPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execSetSlotAssignmentPolicy)
{
	P_GET_OBJECT(USquadSlotAssignmentPolicy,Z_Param_InPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSlotAssignmentPolicy(Z_Param_InPolicy);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function SetSlotAssignmentPolicy ********************

// ********** Begin Class USquadManagerSubsystem Function UnregisterMember *************************
struct Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics
{
	struct SquadManagerSubsystem_eventUnregisterMember_Parms
	{
		AActor* Member;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterMember constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Member;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnregisterMember constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnregisterMember Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::NewProp_Member = { "Member", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadManagerSubsystem_eventUnregisterMember_Parms, Member), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::NewProp_Member,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::PropPointers) < 2048);
// ********** End Function UnregisterMember Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadManagerSubsystem, nullptr, "UnregisterMember", 	Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::SquadManagerSubsystem_eventUnregisterMember_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::SquadManagerSubsystem_eventUnregisterMember_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadManagerSubsystem::execUnregisterMember)
{
	P_GET_OBJECT(AActor,Z_Param_Member);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnregisterMember(Z_Param_Member);
	P_NATIVE_END;
}
// ********** End Class USquadManagerSubsystem Function UnregisterMember ***************************

// ********** Begin Class USquadManagerSubsystem ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadManagerSubsystem;
UClass* USquadManagerSubsystem::GetPrivateStaticClass()
{
	using TClass = USquadManagerSubsystem;
	if (!Z_Registration_Info_UClass_USquadManagerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadManagerSubsystem"),
			Z_Registration_Info_UClass_USquadManagerSubsystem.InnerSingleton,
			StaticRegisterNativesUSquadManagerSubsystem,
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
	return Z_Registration_Info_UClass_USquadManagerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadManagerSubsystem_NoRegister()
{
	return USquadManagerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadManagerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SquadCore/SquadManagerSubsystem.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Formation_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotAssignmentPolicy_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FormationLeader_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/SquadManagerSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadManagerSubsystem constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Formation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotAssignmentPolicy;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_FormationLeader;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadManagerSubsystem constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAssignedSlot"), .Pointer = &USquadManagerSubsystem::execGetAssignedSlot },
		{ .NameUTF8 = UTF8TEXT("GetFormationLeader"), .Pointer = &USquadManagerSubsystem::execGetFormationLeader },
		{ .NameUTF8 = UTF8TEXT("GetSlotWorldLocation"), .Pointer = &USquadManagerSubsystem::execGetSlotWorldLocation },
		{ .NameUTF8 = UTF8TEXT("GetSlotWorldTransform"), .Pointer = &USquadManagerSubsystem::execGetSlotWorldTransform },
		{ .NameUTF8 = UTF8TEXT("RegisterMember"), .Pointer = &USquadManagerSubsystem::execRegisterMember },
		{ .NameUTF8 = UTF8TEXT("SetFormationAsset"), .Pointer = &USquadManagerSubsystem::execSetFormationAsset },
		{ .NameUTF8 = UTF8TEXT("SetFormationLeader"), .Pointer = &USquadManagerSubsystem::execSetFormationLeader },
		{ .NameUTF8 = UTF8TEXT("SetSlotAssignmentPolicy"), .Pointer = &USquadManagerSubsystem::execSetSlotAssignmentPolicy },
		{ .NameUTF8 = UTF8TEXT("UnregisterMember"), .Pointer = &USquadManagerSubsystem::execUnregisterMember },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USquadManagerSubsystem_GetAssignedSlot, "GetAssignedSlot" }, // 460776221
		{ &Z_Construct_UFunction_USquadManagerSubsystem_GetFormationLeader, "GetFormationLeader" }, // 3698573070
		{ &Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldLocation, "GetSlotWorldLocation" }, // 3711833321
		{ &Z_Construct_UFunction_USquadManagerSubsystem_GetSlotWorldTransform, "GetSlotWorldTransform" }, // 1865341027
		{ &Z_Construct_UFunction_USquadManagerSubsystem_RegisterMember, "RegisterMember" }, // 841865557
		{ &Z_Construct_UFunction_USquadManagerSubsystem_SetFormationAsset, "SetFormationAsset" }, // 4294662911
		{ &Z_Construct_UFunction_USquadManagerSubsystem_SetFormationLeader, "SetFormationLeader" }, // 498574828
		{ &Z_Construct_UFunction_USquadManagerSubsystem_SetSlotAssignmentPolicy, "SetSlotAssignmentPolicy" }, // 2214735418
		{ &Z_Construct_UFunction_USquadManagerSubsystem_UnregisterMember, "UnregisterMember" }, // 1101498790
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadManagerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadManagerSubsystem_Statics

// ********** Begin Class USquadManagerSubsystem Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_Formation = { "Formation", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadManagerSubsystem, Formation), Z_Construct_UClass_UFormationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Formation_MetaData), NewProp_Formation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_SlotAssignmentPolicy = { "SlotAssignmentPolicy", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadManagerSubsystem, SlotAssignmentPolicy), Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotAssignmentPolicy_MetaData), NewProp_SlotAssignmentPolicy_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_FormationLeader = { "FormationLeader", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadManagerSubsystem, FormationLeader), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FormationLeader_MetaData), NewProp_FormationLeader_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadManagerSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_Formation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_SlotAssignmentPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadManagerSubsystem_Statics::NewProp_FormationLeader,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadManagerSubsystem_Statics::PropPointers) < 2048);
// ********** End Class USquadManagerSubsystem Property Definitions ********************************
UObject* (*const Z_Construct_UClass_USquadManagerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadManagerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadManagerSubsystem_Statics::ClassParams = {
	&USquadManagerSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USquadManagerSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadManagerSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadManagerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadManagerSubsystem_Statics::Class_MetaDataParams)
};
void USquadManagerSubsystem::StaticRegisterNativesUSquadManagerSubsystem()
{
	UClass* Class = USquadManagerSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USquadManagerSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_USquadManagerSubsystem()
{
	if (!Z_Registration_Info_UClass_USquadManagerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadManagerSubsystem.OuterSingleton, Z_Construct_UClass_USquadManagerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadManagerSubsystem.OuterSingleton;
}
USquadManagerSubsystem::USquadManagerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadManagerSubsystem);
USquadManagerSubsystem::~USquadManagerSubsystem() {}
// ********** End Class USquadManagerSubsystem *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadManagerSubsystem, USquadManagerSubsystem::StaticClass, TEXT("USquadManagerSubsystem"), &Z_Registration_Info_UClass_USquadManagerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadManagerSubsystem), 1271664452U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h__Script_SquadCore_2496770072{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
