// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackRangeModel.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackRangeModel() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel();
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_NoRegister();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackExecutionParams();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAttackRangeModel Function BuildExecutionParams **************************
struct AttackRangeModel_eventBuildExecutionParams_Parms
{
	FCombatAttackContext Context;
	float DistanceToTarget;
	FCombatAttackExecutionParams InOutParams;
};
static FName NAME_UAttackRangeModel_BuildExecutionParams = FName(TEXT("BuildExecutionParams"));
void UAttackRangeModel::BuildExecutionParams(FCombatAttackContext const& Context, float DistanceToTarget, FCombatAttackExecutionParams& InOutParams) const
{
	UFunction* Func = FindFunctionChecked(NAME_UAttackRangeModel_BuildExecutionParams);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		AttackRangeModel_eventBuildExecutionParams_Parms Parms;
		Parms.Context=Context;
		Parms.DistanceToTarget=DistanceToTarget;
		Parms.InOutParams=InOutParams;
		const_cast<UAttackRangeModel*>(this)->ProcessEvent(Func,&Parms);
		InOutParams=Parms.InOutParams;
	}
	else
	{
		const_cast<UAttackRangeModel*>(this)->BuildExecutionParams_Implementation(Context, DistanceToTarget, InOutParams);
	}
}
struct Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BuildExecutionParams constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceToTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InOutParams;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BuildExecutionParams constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BuildExecutionParams Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackRangeModel_eventBuildExecutionParams_Parms, Context), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 829964288
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_DistanceToTarget = { "DistanceToTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackRangeModel_eventBuildExecutionParams_Parms, DistanceToTarget), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_InOutParams = { "InOutParams", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackRangeModel_eventBuildExecutionParams_Parms, InOutParams), Z_Construct_UScriptStruct_FCombatAttackExecutionParams, METADATA_PARAMS(0, nullptr) }; // 2193908537
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_DistanceToTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::NewProp_InOutParams,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::PropPointers) < 2048);
// ********** End Function BuildExecutionParams Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackRangeModel, nullptr, "BuildExecutionParams", 	Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::PropPointers), 
sizeof(AttackRangeModel_eventBuildExecutionParams_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(AttackRangeModel_eventBuildExecutionParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackRangeModel::execBuildExecutionParams)
{
	P_GET_STRUCT_REF(FCombatAttackContext,Z_Param_Out_Context);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DistanceToTarget);
	P_GET_STRUCT_REF(FCombatAttackExecutionParams,Z_Param_Out_InOutParams);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BuildExecutionParams_Implementation(Z_Param_Out_Context,Z_Param_DistanceToTarget,Z_Param_Out_InOutParams);
	P_NATIVE_END;
}
// ********** End Class UAttackRangeModel Function BuildExecutionParams ****************************

// ********** Begin Class UAttackRangeModel ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackRangeModel;
UClass* UAttackRangeModel::GetPrivateStaticClass()
{
	using TClass = UAttackRangeModel;
	if (!Z_Registration_Info_UClass_UAttackRangeModel.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackRangeModel"),
			Z_Registration_Info_UClass_UAttackRangeModel.InnerSingleton,
			StaticRegisterNativesUAttackRangeModel,
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
	return Z_Registration_Info_UClass_UAttackRangeModel.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackRangeModel_NoRegister()
{
	return UAttackRangeModel::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackRangeModel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Combat/AttackRangeModel.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAffectThrustDistance_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAffectHitscanRange_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangeInputMin_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangeInputMax_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinThrustDistance_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxThrustDistance_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceCompensationBias_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticReach_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitSlack_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitscanRangeScale_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseDistanceCompensation_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangeToDistanceCurve_MetaData[] = {
		{ "Category", "Combat|Range" },
		{ "ModuleRelativePath", "Public/Combat/AttackRangeModel.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackRangeModel constinit property declarations ************************
	static void NewProp_bAffectThrustDistance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAffectThrustDistance;
	static void NewProp_bAffectHitscanRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAffectHitscanRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RangeInputMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RangeInputMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinThrustDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxThrustDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceCompensationBias;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StaticReach;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HitSlack;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HitscanRangeScale;
	static void NewProp_bUseDistanceCompensation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDistanceCompensation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangeToDistanceCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAttackRangeModel constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BuildExecutionParams"), .Pointer = &UAttackRangeModel::execBuildExecutionParams },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttackRangeModel_BuildExecutionParams, "BuildExecutionParams" }, // 1633894167
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackRangeModel>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackRangeModel_Statics

// ********** Begin Class UAttackRangeModel Property Definitions ***********************************
void Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectThrustDistance_SetBit(void* Obj)
{
	((UAttackRangeModel*)Obj)->bAffectThrustDistance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectThrustDistance = { "bAffectThrustDistance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAttackRangeModel), &Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectThrustDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAffectThrustDistance_MetaData), NewProp_bAffectThrustDistance_MetaData) };
void Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectHitscanRange_SetBit(void* Obj)
{
	((UAttackRangeModel*)Obj)->bAffectHitscanRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectHitscanRange = { "bAffectHitscanRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAttackRangeModel), &Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectHitscanRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAffectHitscanRange_MetaData), NewProp_bAffectHitscanRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeInputMin = { "RangeInputMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, RangeInputMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangeInputMin_MetaData), NewProp_RangeInputMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeInputMax = { "RangeInputMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, RangeInputMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangeInputMax_MetaData), NewProp_RangeInputMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_MinThrustDistance = { "MinThrustDistance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, MinThrustDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinThrustDistance_MetaData), NewProp_MinThrustDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_MaxThrustDistance = { "MaxThrustDistance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, MaxThrustDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxThrustDistance_MetaData), NewProp_MaxThrustDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_DistanceCompensationBias = { "DistanceCompensationBias", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, DistanceCompensationBias), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceCompensationBias_MetaData), NewProp_DistanceCompensationBias_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_StaticReach = { "StaticReach", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, StaticReach), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticReach_MetaData), NewProp_StaticReach_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_HitSlack = { "HitSlack", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, HitSlack), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitSlack_MetaData), NewProp_HitSlack_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_HitscanRangeScale = { "HitscanRangeScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, HitscanRangeScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitscanRangeScale_MetaData), NewProp_HitscanRangeScale_MetaData) };
void Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bUseDistanceCompensation_SetBit(void* Obj)
{
	((UAttackRangeModel*)Obj)->bUseDistanceCompensation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bUseDistanceCompensation = { "bUseDistanceCompensation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAttackRangeModel), &Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bUseDistanceCompensation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseDistanceCompensation_MetaData), NewProp_bUseDistanceCompensation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeToDistanceCurve = { "RangeToDistanceCurve", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackRangeModel, RangeToDistanceCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangeToDistanceCurve_MetaData), NewProp_RangeToDistanceCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttackRangeModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bAffectHitscanRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeInputMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeInputMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_MinThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_MaxThrustDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_DistanceCompensationBias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_StaticReach,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_HitSlack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_HitscanRangeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_bUseDistanceCompensation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackRangeModel_Statics::NewProp_RangeToDistanceCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_Statics::PropPointers) < 2048);
// ********** End Class UAttackRangeModel Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UAttackRangeModel_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackRangeModel_Statics::ClassParams = {
	&UAttackRangeModel::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAttackRangeModel_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackRangeModel_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackRangeModel_Statics::Class_MetaDataParams)
};
void UAttackRangeModel::StaticRegisterNativesUAttackRangeModel()
{
	UClass* Class = UAttackRangeModel::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAttackRangeModel_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAttackRangeModel()
{
	if (!Z_Registration_Info_UClass_UAttackRangeModel.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackRangeModel.OuterSingleton, Z_Construct_UClass_UAttackRangeModel_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackRangeModel.OuterSingleton;
}
UAttackRangeModel::UAttackRangeModel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackRangeModel);
UAttackRangeModel::~UAttackRangeModel() {}
// ********** End Class UAttackRangeModel **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackRangeModel, UAttackRangeModel::StaticClass, TEXT("UAttackRangeModel"), &Z_Registration_Info_UClass_UAttackRangeModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackRangeModel), 790758105U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h__Script_CombatCore_1108401560{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
