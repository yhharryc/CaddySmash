// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadMemberComponent.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadMemberComponent() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_ULootEvaluator_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_USquadMemberComponent();
SQUADCORE_API UClass* Z_Construct_UClass_USquadMemberComponent_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_UThreatEvaluator_NoRegister();
SQUADCORE_API UEnum* Z_Construct_UEnum_SquadCore_ELootPolicy();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FLootCandidate();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FThreatCandidate();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadMemberComponent ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadMemberComponent;
UClass* USquadMemberComponent::GetPrivateStaticClass()
{
	using TClass = USquadMemberComponent;
	if (!Z_Registration_Info_UClass_USquadMemberComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadMemberComponent"),
			Z_Registration_Info_UClass_USquadMemberComponent.InnerSingleton,
			StaticRegisterNativesUSquadMemberComponent,
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
	return Z_Registration_Info_UClass_USquadMemberComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadMemberComponent_NoRegister()
{
	return USquadMemberComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadMemberComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Squad" },
		{ "IncludePath", "SquadCore/SquadMemberComponent.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompliancePolicy_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatEvaluator_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootEvaluator_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootPolicy_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotId_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotWorldPos_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldObeyFormation_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTemporarilyOutOfFormation_MetaData[] = {
		{ "Category", "Squad|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True while AI is temporarily leaving formation to improve attack position. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True while AI is temporarily leaving formation to improve attack position." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureValue_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreatList_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BestTarget_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootCandidate_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastAttackProfile_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextAttackTime_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAttackRange_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAggressionRange_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDesiredAttackDistance_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceToBestTarget_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBestTargetInAttackRange_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBestTargetInAggressionRange_MetaData[] = {
		{ "Category", "Squad|Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugAI_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowStateTreeWhenLeader_MetaData[] = {
		{ "Category", "Squad|AI" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugLastTask_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadMemberComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadMemberComponent constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CompliancePolicy;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThreatEvaluator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LootEvaluator;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LootPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LootPolicy;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotWorldPos;
	static void NewProp_bShouldObeyFormation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldObeyFormation;
	static void NewProp_bIsTemporarilyOutOfFormation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTemporarilyOutOfFormation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressureValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ThreatList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ThreatList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BestTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LootCandidate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastAttackProfile;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NextAttackTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentAttackRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentAggressionRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentDesiredAttackDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceToBestTarget;
	static void NewProp_bBestTargetInAttackRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBestTargetInAttackRange;
	static void NewProp_bBestTargetInAggressionRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBestTargetInAggressionRange;
	static void NewProp_bDebugAI_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugAI;
	static void NewProp_bAllowStateTreeWhenLeader_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowStateTreeWhenLeader;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DebugLastTask;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadMemberComponent constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadMemberComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadMemberComponent_Statics

// ********** Begin Class USquadMemberComponent Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CompliancePolicy = { "CompliancePolicy", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, CompliancePolicy), Z_Construct_UClass_UCompliancePolicy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompliancePolicy_MetaData), NewProp_CompliancePolicy_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatEvaluator = { "ThreatEvaluator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, ThreatEvaluator), Z_Construct_UClass_UThreatEvaluator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatEvaluator_MetaData), NewProp_ThreatEvaluator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootEvaluator = { "LootEvaluator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, LootEvaluator), Z_Construct_UClass_ULootEvaluator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootEvaluator_MetaData), NewProp_LootEvaluator_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootPolicy = { "LootPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, LootPolicy), Z_Construct_UEnum_SquadCore_ELootPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootPolicy_MetaData), NewProp_LootPolicy_MetaData) }; // 932092389
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, SlotId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotId_MetaData), NewProp_SlotId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_SlotWorldPos = { "SlotWorldPos", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, SlotWorldPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotWorldPos_MetaData), NewProp_SlotWorldPos_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bShouldObeyFormation_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bShouldObeyFormation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bShouldObeyFormation = { "bShouldObeyFormation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bShouldObeyFormation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldObeyFormation_MetaData), NewProp_bShouldObeyFormation_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bIsTemporarilyOutOfFormation_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bIsTemporarilyOutOfFormation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bIsTemporarilyOutOfFormation = { "bIsTemporarilyOutOfFormation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bIsTemporarilyOutOfFormation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTemporarilyOutOfFormation_MetaData), NewProp_bIsTemporarilyOutOfFormation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_PressureValue = { "PressureValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, PressureValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureValue_MetaData), NewProp_PressureValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatList_Inner = { "ThreatList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FThreatCandidate, METADATA_PARAMS(0, nullptr) }; // 730226818
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatList = { "ThreatList", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, ThreatList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreatList_MetaData), NewProp_ThreatList_MetaData) }; // 730226818
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_BestTarget = { "BestTarget", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, BestTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BestTarget_MetaData), NewProp_BestTarget_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootCandidate = { "LootCandidate", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, LootCandidate), Z_Construct_UScriptStruct_FLootCandidate, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootCandidate_MetaData), NewProp_LootCandidate_MetaData) }; // 4005417798
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LastAttackProfile = { "LastAttackProfile", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, LastAttackProfile), Z_Construct_UClass_UAttackProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastAttackProfile_MetaData), NewProp_LastAttackProfile_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_NextAttackTime = { "NextAttackTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, NextAttackTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextAttackTime_MetaData), NewProp_NextAttackTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentAttackRange = { "CurrentAttackRange", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, CurrentAttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAttackRange_MetaData), NewProp_CurrentAttackRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentAggressionRange = { "CurrentAggressionRange", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, CurrentAggressionRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAggressionRange_MetaData), NewProp_CurrentAggressionRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentDesiredAttackDistance = { "CurrentDesiredAttackDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, CurrentDesiredAttackDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDesiredAttackDistance_MetaData), NewProp_CurrentDesiredAttackDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_DistanceToBestTarget = { "DistanceToBestTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, DistanceToBestTarget), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceToBestTarget_MetaData), NewProp_DistanceToBestTarget_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAttackRange_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bBestTargetInAttackRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAttackRange = { "bBestTargetInAttackRange", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAttackRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBestTargetInAttackRange_MetaData), NewProp_bBestTargetInAttackRange_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAggressionRange_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bBestTargetInAggressionRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAggressionRange = { "bBestTargetInAggressionRange", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAggressionRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBestTargetInAggressionRange_MetaData), NewProp_bBestTargetInAggressionRange_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bDebugAI_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bDebugAI = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bDebugAI = { "bDebugAI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bDebugAI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugAI_MetaData), NewProp_bDebugAI_MetaData) };
void Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bAllowStateTreeWhenLeader_SetBit(void* Obj)
{
	((USquadMemberComponent*)Obj)->bAllowStateTreeWhenLeader = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bAllowStateTreeWhenLeader = { "bAllowStateTreeWhenLeader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadMemberComponent), &Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bAllowStateTreeWhenLeader_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowStateTreeWhenLeader_MetaData), NewProp_bAllowStateTreeWhenLeader_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_DebugLastTask = { "DebugLastTask", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadMemberComponent, DebugLastTask), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugLastTask_MetaData), NewProp_DebugLastTask_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadMemberComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CompliancePolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatEvaluator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootEvaluator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_SlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_SlotWorldPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bShouldObeyFormation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bIsTemporarilyOutOfFormation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_PressureValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_ThreatList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_BestTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LootCandidate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_LastAttackProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_NextAttackTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentAggressionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_CurrentDesiredAttackDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_DistanceToBestTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bBestTargetInAggressionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bDebugAI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_bAllowStateTreeWhenLeader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadMemberComponent_Statics::NewProp_DebugLastTask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadMemberComponent_Statics::PropPointers) < 2048);
// ********** End Class USquadMemberComponent Property Definitions *********************************
UObject* (*const Z_Construct_UClass_USquadMemberComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadMemberComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadMemberComponent_Statics::ClassParams = {
	&USquadMemberComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadMemberComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadMemberComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadMemberComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadMemberComponent_Statics::Class_MetaDataParams)
};
void USquadMemberComponent::StaticRegisterNativesUSquadMemberComponent()
{
}
UClass* Z_Construct_UClass_USquadMemberComponent()
{
	if (!Z_Registration_Info_UClass_USquadMemberComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadMemberComponent.OuterSingleton, Z_Construct_UClass_USquadMemberComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadMemberComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadMemberComponent);
USquadMemberComponent::~USquadMemberComponent() {}
// ********** End Class USquadMemberComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadMemberComponent_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadMemberComponent, USquadMemberComponent::StaticClass, TEXT("USquadMemberComponent"), &Z_Registration_Info_UClass_USquadMemberComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadMemberComponent), 2461416016U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadMemberComponent_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadMemberComponent_h__Script_SquadCore_2619294010{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadMemberComponent_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadMemberComponent_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
