// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/StateTree/SquadStateTreeTasks.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadStateTreeTasks() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_ULootEvaluator_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_UThreatEvaluator_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_AimAtBestTarget();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_AimAtBestTarget_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_AssignSlot();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_AssignSlot_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_BeginAttackIntent();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_BeginAttackIntent_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_CommitAttack();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_CommitAttack_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_ComputeCompliance();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_ComputeCompliance_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_EvaluateLoot();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_EvaluateLoot_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_EvaluateThreats();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_EvaluateThreats_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_MoveToSlot();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_MoveToSlot_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_UpdateSlotWorldPos();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_NoRegister();
STATETREEMODULE_API UClass* Z_Construct_UClass_UStateTreeTaskBlueprintBase();
UPackage* Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadTask_AssignSlot ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_AssignSlot;
UClass* USquadTask_AssignSlot::GetPrivateStaticClass()
{
	using TClass = USquadTask_AssignSlot;
	if (!Z_Registration_Info_UClass_USquadTask_AssignSlot.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_AssignSlot"),
			Z_Registration_Info_UClass_USquadTask_AssignSlot.InnerSingleton,
			StaticRegisterNativesUSquadTask_AssignSlot,
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
	return Z_Registration_Info_UClass_USquadTask_AssignSlot.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_AssignSlot_NoRegister()
{
	return USquadTask_AssignSlot::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_AssignSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_AssignSlot constinit property declarations ********************
// ********** End Class USquadTask_AssignSlot constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_AssignSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_AssignSlot_Statics
UObject* (*const Z_Construct_UClass_USquadTask_AssignSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AssignSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_AssignSlot_Statics::ClassParams = {
	&USquadTask_AssignSlot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AssignSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_AssignSlot_Statics::Class_MetaDataParams)
};
void USquadTask_AssignSlot::StaticRegisterNativesUSquadTask_AssignSlot()
{
}
UClass* Z_Construct_UClass_USquadTask_AssignSlot()
{
	if (!Z_Registration_Info_UClass_USquadTask_AssignSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_AssignSlot.OuterSingleton, Z_Construct_UClass_USquadTask_AssignSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_AssignSlot.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_AssignSlot);
USquadTask_AssignSlot::~USquadTask_AssignSlot() {}
// ********** End Class USquadTask_AssignSlot ******************************************************

// ********** Begin Class USquadTask_UpdateSlotWorldPos ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos;
UClass* USquadTask_UpdateSlotWorldPos::GetPrivateStaticClass()
{
	using TClass = USquadTask_UpdateSlotWorldPos;
	if (!Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_UpdateSlotWorldPos"),
			Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.InnerSingleton,
			StaticRegisterNativesUSquadTask_UpdateSlotWorldPos,
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
	return Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_NoRegister()
{
	return USquadTask_UpdateSlotWorldPos::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOnlyWhenObeying_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_UpdateSlotWorldPos constinit property declarations ************
	static void NewProp_bOnlyWhenObeying_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnlyWhenObeying;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_UpdateSlotWorldPos constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_UpdateSlotWorldPos>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics

// ********** Begin Class USquadTask_UpdateSlotWorldPos Property Definitions ***********************
void Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::NewProp_bOnlyWhenObeying_SetBit(void* Obj)
{
	((USquadTask_UpdateSlotWorldPos*)Obj)->bOnlyWhenObeying = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::NewProp_bOnlyWhenObeying = { "bOnlyWhenObeying", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_UpdateSlotWorldPos), &Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::NewProp_bOnlyWhenObeying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOnlyWhenObeying_MetaData), NewProp_bOnlyWhenObeying_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::NewProp_bOnlyWhenObeying,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_UpdateSlotWorldPos Property Definitions *************************
UObject* (*const Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::ClassParams = {
	&USquadTask_UpdateSlotWorldPos::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::Class_MetaDataParams)
};
void USquadTask_UpdateSlotWorldPos::StaticRegisterNativesUSquadTask_UpdateSlotWorldPos()
{
}
UClass* Z_Construct_UClass_USquadTask_UpdateSlotWorldPos()
{
	if (!Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.OuterSingleton, Z_Construct_UClass_USquadTask_UpdateSlotWorldPos_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_UpdateSlotWorldPos);
USquadTask_UpdateSlotWorldPos::~USquadTask_UpdateSlotWorldPos() {}
// ********** End Class USquadTask_UpdateSlotWorldPos **********************************************

// ********** Begin Class USquadTask_ComputeCompliance *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_ComputeCompliance;
UClass* USquadTask_ComputeCompliance::GetPrivateStaticClass()
{
	using TClass = USquadTask_ComputeCompliance;
	if (!Z_Registration_Info_UClass_USquadTask_ComputeCompliance.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_ComputeCompliance"),
			Z_Registration_Info_UClass_USquadTask_ComputeCompliance.InnerSingleton,
			StaticRegisterNativesUSquadTask_ComputeCompliance,
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
	return Z_Registration_Info_UClass_USquadTask_ComputeCompliance.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_ComputeCompliance_NoRegister()
{
	return USquadTask_ComputeCompliance::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_ComputeCompliance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PolicyOverride_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthRatioOverride_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_ComputeCompliance constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PolicyOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthRatioOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_ComputeCompliance constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_ComputeCompliance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_ComputeCompliance_Statics

// ********** Begin Class USquadTask_ComputeCompliance Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::NewProp_PolicyOverride = { "PolicyOverride", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_ComputeCompliance, PolicyOverride), Z_Construct_UClass_UCompliancePolicy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PolicyOverride_MetaData), NewProp_PolicyOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::NewProp_HealthRatioOverride = { "HealthRatioOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_ComputeCompliance, HealthRatioOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthRatioOverride_MetaData), NewProp_HealthRatioOverride_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::NewProp_PolicyOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::NewProp_HealthRatioOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_ComputeCompliance Property Definitions **************************
UObject* (*const Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::ClassParams = {
	&USquadTask_ComputeCompliance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::Class_MetaDataParams)
};
void USquadTask_ComputeCompliance::StaticRegisterNativesUSquadTask_ComputeCompliance()
{
}
UClass* Z_Construct_UClass_USquadTask_ComputeCompliance()
{
	if (!Z_Registration_Info_UClass_USquadTask_ComputeCompliance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_ComputeCompliance.OuterSingleton, Z_Construct_UClass_USquadTask_ComputeCompliance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_ComputeCompliance.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_ComputeCompliance);
USquadTask_ComputeCompliance::~USquadTask_ComputeCompliance() {}
// ********** End Class USquadTask_ComputeCompliance ***********************************************

// ********** Begin Class USquadTask_EvaluateThreats ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_EvaluateThreats;
UClass* USquadTask_EvaluateThreats::GetPrivateStaticClass()
{
	using TClass = USquadTask_EvaluateThreats;
	if (!Z_Registration_Info_UClass_USquadTask_EvaluateThreats.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_EvaluateThreats"),
			Z_Registration_Info_UClass_USquadTask_EvaluateThreats.InnerSingleton,
			StaticRegisterNativesUSquadTask_EvaluateThreats,
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
	return Z_Registration_Info_UClass_USquadTask_EvaluateThreats.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_EvaluateThreats_NoRegister()
{
	return USquadTask_EvaluateThreats::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_EvaluateThreats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EvaluatorOverride_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BestTargetGraceTime_MetaData[] = {
		{ "Category", "Squad" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grace period to keep the last BestTarget when evaluations temporarily return none. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grace period to keep the last BestTarget when evaluations temporarily return none." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggressionRangeOverride_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If >=0, use this as aggression range instead of deriving from attack range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If >=0, use this as aggression range instead of deriving from attack range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggressionRangeMultiplier_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Aggression range = AttackRange * Multiplier (when no override). */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Aggression range = AttackRange * Multiplier (when no override)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinAggressionRange_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lower bound for aggression range when attack range is small or unavailable. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lower bound for aggression range when attack range is small or unavailable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRangeHysteresis_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hysteresis used when determining whether target is in attack range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hysteresis used when determining whether target is in attack range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggressionRangeHysteresis_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hysteresis used when determining whether target is in aggression range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hysteresis used when determining whether target is in aggression range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DesiredAttackBuffer_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Desired distance to hold from target once in combat. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Desired distance to hold from target once in combat." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastUpdateTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastBestTargetTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_EvaluateThreats constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EvaluatorOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BestTargetGraceTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggressionRangeOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggressionRangeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAggressionRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRangeHysteresis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AggressionRangeHysteresis;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredAttackBuffer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastUpdateTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastBestTargetTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_EvaluateThreats constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_EvaluateThreats>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_EvaluateThreats_Statics

// ********** Begin Class USquadTask_EvaluateThreats Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_EvaluatorOverride = { "EvaluatorOverride", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, EvaluatorOverride), Z_Construct_UClass_UThreatEvaluator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EvaluatorOverride_MetaData), NewProp_EvaluatorOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_BestTargetGraceTime = { "BestTargetGraceTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, BestTargetGraceTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BestTargetGraceTime_MetaData), NewProp_BestTargetGraceTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeOverride = { "AggressionRangeOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, AggressionRangeOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggressionRangeOverride_MetaData), NewProp_AggressionRangeOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeMultiplier = { "AggressionRangeMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, AggressionRangeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggressionRangeMultiplier_MetaData), NewProp_AggressionRangeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_MinAggressionRange = { "MinAggressionRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, MinAggressionRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinAggressionRange_MetaData), NewProp_MinAggressionRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AttackRangeHysteresis = { "AttackRangeHysteresis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, AttackRangeHysteresis), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRangeHysteresis_MetaData), NewProp_AttackRangeHysteresis_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeHysteresis = { "AggressionRangeHysteresis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, AggressionRangeHysteresis), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggressionRangeHysteresis_MetaData), NewProp_AggressionRangeHysteresis_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_DesiredAttackBuffer = { "DesiredAttackBuffer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, DesiredAttackBuffer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DesiredAttackBuffer_MetaData), NewProp_DesiredAttackBuffer_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_LastUpdateTime = { "LastUpdateTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, LastUpdateTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastUpdateTime_MetaData), NewProp_LastUpdateTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_LastBestTargetTime = { "LastBestTargetTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateThreats, LastBestTargetTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastBestTargetTime_MetaData), NewProp_LastBestTargetTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_EvaluatorOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_BestTargetGraceTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_MinAggressionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AttackRangeHysteresis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_AggressionRangeHysteresis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_DesiredAttackBuffer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_LastUpdateTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::NewProp_LastBestTargetTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_EvaluateThreats Property Definitions ****************************
UObject* (*const Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::ClassParams = {
	&USquadTask_EvaluateThreats::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::Class_MetaDataParams)
};
void USquadTask_EvaluateThreats::StaticRegisterNativesUSquadTask_EvaluateThreats()
{
}
UClass* Z_Construct_UClass_USquadTask_EvaluateThreats()
{
	if (!Z_Registration_Info_UClass_USquadTask_EvaluateThreats.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_EvaluateThreats.OuterSingleton, Z_Construct_UClass_USquadTask_EvaluateThreats_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_EvaluateThreats.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_EvaluateThreats);
USquadTask_EvaluateThreats::~USquadTask_EvaluateThreats() {}
// ********** End Class USquadTask_EvaluateThreats *************************************************

// ********** Begin Class USquadTask_EvaluateLoot **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_EvaluateLoot;
UClass* USquadTask_EvaluateLoot::GetPrivateStaticClass()
{
	using TClass = USquadTask_EvaluateLoot;
	if (!Z_Registration_Info_UClass_USquadTask_EvaluateLoot.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_EvaluateLoot"),
			Z_Registration_Info_UClass_USquadTask_EvaluateLoot.InnerSingleton,
			StaticRegisterNativesUSquadTask_EvaluateLoot,
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
	return Z_Registration_Info_UClass_USquadTask_EvaluateLoot.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_EvaluateLoot_NoRegister()
{
	return USquadTask_EvaluateLoot::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_EvaluateLoot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EvaluatorOverride_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastUpdateTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_EvaluateLoot constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EvaluatorOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastUpdateTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_EvaluateLoot constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_EvaluateLoot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_EvaluateLoot_Statics

// ********** Begin Class USquadTask_EvaluateLoot Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_EvaluatorOverride = { "EvaluatorOverride", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateLoot, EvaluatorOverride), Z_Construct_UClass_ULootEvaluator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EvaluatorOverride_MetaData), NewProp_EvaluatorOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateLoot, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_LastUpdateTime = { "LastUpdateTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_EvaluateLoot, LastUpdateTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastUpdateTime_MetaData), NewProp_LastUpdateTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_EvaluatorOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::NewProp_LastUpdateTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_EvaluateLoot Property Definitions *******************************
UObject* (*const Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::ClassParams = {
	&USquadTask_EvaluateLoot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::Class_MetaDataParams)
};
void USquadTask_EvaluateLoot::StaticRegisterNativesUSquadTask_EvaluateLoot()
{
}
UClass* Z_Construct_UClass_USquadTask_EvaluateLoot()
{
	if (!Z_Registration_Info_UClass_USquadTask_EvaluateLoot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_EvaluateLoot.OuterSingleton, Z_Construct_UClass_USquadTask_EvaluateLoot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_EvaluateLoot.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_EvaluateLoot);
USquadTask_EvaluateLoot::~USquadTask_EvaluateLoot() {}
// ********** End Class USquadTask_EvaluateLoot ****************************************************

// ********** Begin Class USquadTask_BeginAttackIntent *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_BeginAttackIntent;
UClass* USquadTask_BeginAttackIntent::GetPrivateStaticClass()
{
	using TClass = USquadTask_BeginAttackIntent;
	if (!Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_BeginAttackIntent"),
			Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.InnerSingleton,
			StaticRegisterNativesUSquadTask_BeginAttackIntent,
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
	return Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_BeginAttackIntent_NoRegister()
{
	return USquadTask_BeginAttackIntent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackProfileOverride_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_BeginAttackIntent constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackProfileOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_BeginAttackIntent constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_BeginAttackIntent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics

// ********** Begin Class USquadTask_BeginAttackIntent Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::NewProp_AttackProfileOverride = { "AttackProfileOverride", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_BeginAttackIntent, AttackProfileOverride), Z_Construct_UClass_UAttackProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackProfileOverride_MetaData), NewProp_AttackProfileOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_BeginAttackIntent, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::NewProp_AttackProfileOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::NewProp_BaseDamage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_BeginAttackIntent Property Definitions **************************
UObject* (*const Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::ClassParams = {
	&USquadTask_BeginAttackIntent::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::Class_MetaDataParams)
};
void USquadTask_BeginAttackIntent::StaticRegisterNativesUSquadTask_BeginAttackIntent()
{
}
UClass* Z_Construct_UClass_USquadTask_BeginAttackIntent()
{
	if (!Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.OuterSingleton, Z_Construct_UClass_USquadTask_BeginAttackIntent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_BeginAttackIntent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_BeginAttackIntent);
USquadTask_BeginAttackIntent::~USquadTask_BeginAttackIntent() {}
// ********** End Class USquadTask_BeginAttackIntent ***********************************************

// ********** Begin Class USquadTask_CommitAttack **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_CommitAttack;
UClass* USquadTask_CommitAttack::GetPrivateStaticClass()
{
	using TClass = USquadTask_CommitAttack;
	if (!Z_Registration_Info_UClass_USquadTask_CommitAttack.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_CommitAttack"),
			Z_Registration_Info_UClass_USquadTask_CommitAttack.InnerSingleton,
			StaticRegisterNativesUSquadTask_CommitAttack,
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
	return Z_Registration_Info_UClass_USquadTask_CommitAttack.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_CommitAttack_NoRegister()
{
	return USquadTask_CommitAttack::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_CommitAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommitDelay_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinPostCommitHold_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keep task alive for at least this long after sending commit to avoid same-frame complete/re-enter loops. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keep task alive for at least this long after sending commit to avoid same-frame complete/re-enter loops." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownOverride_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If >= 0, overrides AttackProfile cooldown. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If >= 0, overrides AttackProfile cooldown." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWaitForCooldownBeforeSucceed_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deprecated compatibility flag: task now always waits until cooldown end to avoid re-entry spam. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deprecated compatibility flag: task now always waits until cooldown end to avoid re-entry spam." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireTargetInAttackRange_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, attack commit waits until target is inside the effective attack range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, attack commit waits until target is inside the effective attack range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRangeTolerance_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extra tolerance to avoid edge jitter when checking attack range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extra tolerance to avoid edge jitter when checking attack range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCommitted_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackEndTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownEndTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_CommitAttack constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CommitDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinPostCommitHold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownOverride;
	static void NewProp_bWaitForCooldownBeforeSucceed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWaitForCooldownBeforeSucceed;
	static void NewProp_bRequireTargetInAttackRange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireTargetInAttackRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRangeTolerance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTime;
	static void NewProp_bCommitted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCommitted;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackEndTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownEndTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_CommitAttack constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_CommitAttack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_CommitAttack_Statics

// ********** Begin Class USquadTask_CommitAttack Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CommitDelay = { "CommitDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, CommitDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommitDelay_MetaData), NewProp_CommitDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_MinPostCommitHold = { "MinPostCommitHold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, MinPostCommitHold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinPostCommitHold_MetaData), NewProp_MinPostCommitHold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CooldownOverride = { "CooldownOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, CooldownOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownOverride_MetaData), NewProp_CooldownOverride_MetaData) };
void Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bWaitForCooldownBeforeSucceed_SetBit(void* Obj)
{
	((USquadTask_CommitAttack*)Obj)->bWaitForCooldownBeforeSucceed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bWaitForCooldownBeforeSucceed = { "bWaitForCooldownBeforeSucceed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_CommitAttack), &Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bWaitForCooldownBeforeSucceed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWaitForCooldownBeforeSucceed_MetaData), NewProp_bWaitForCooldownBeforeSucceed_MetaData) };
void Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bRequireTargetInAttackRange_SetBit(void* Obj)
{
	((USquadTask_CommitAttack*)Obj)->bRequireTargetInAttackRange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bRequireTargetInAttackRange = { "bRequireTargetInAttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_CommitAttack), &Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bRequireTargetInAttackRange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireTargetInAttackRange_MetaData), NewProp_bRequireTargetInAttackRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_AttackRangeTolerance = { "AttackRangeTolerance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, AttackRangeTolerance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRangeTolerance_MetaData), NewProp_AttackRangeTolerance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, StartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTime_MetaData), NewProp_StartTime_MetaData) };
void Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bCommitted_SetBit(void* Obj)
{
	((USquadTask_CommitAttack*)Obj)->bCommitted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bCommitted = { "bCommitted", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_CommitAttack), &Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bCommitted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCommitted_MetaData), NewProp_bCommitted_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_AttackEndTime = { "AttackEndTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, AttackEndTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackEndTime_MetaData), NewProp_AttackEndTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CooldownEndTime = { "CooldownEndTime", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_CommitAttack, CooldownEndTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownEndTime_MetaData), NewProp_CooldownEndTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_CommitAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CommitDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_MinPostCommitHold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CooldownOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bWaitForCooldownBeforeSucceed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bRequireTargetInAttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_AttackRangeTolerance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_bCommitted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_AttackEndTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_CommitAttack_Statics::NewProp_CooldownEndTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_CommitAttack_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_CommitAttack Property Definitions *******************************
UObject* (*const Z_Construct_UClass_USquadTask_CommitAttack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_CommitAttack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_CommitAttack_Statics::ClassParams = {
	&USquadTask_CommitAttack::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_CommitAttack_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_CommitAttack_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_CommitAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_CommitAttack_Statics::Class_MetaDataParams)
};
void USquadTask_CommitAttack::StaticRegisterNativesUSquadTask_CommitAttack()
{
}
UClass* Z_Construct_UClass_USquadTask_CommitAttack()
{
	if (!Z_Registration_Info_UClass_USquadTask_CommitAttack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_CommitAttack.OuterSingleton, Z_Construct_UClass_USquadTask_CommitAttack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_CommitAttack.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_CommitAttack);
USquadTask_CommitAttack::~USquadTask_CommitAttack() {}
// ********** End Class USquadTask_CommitAttack ****************************************************

// ********** Begin Class USquadTask_AimAtBestTarget ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_AimAtBestTarget;
UClass* USquadTask_AimAtBestTarget::GetPrivateStaticClass()
{
	using TClass = USquadTask_AimAtBestTarget;
	if (!Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_AimAtBestTarget"),
			Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.InnerSingleton,
			StaticRegisterNativesUSquadTask_AimAtBestTarget,
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
	return Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_AimAtBestTarget_NoRegister()
{
	return USquadTask_AimAtBestTarget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnap_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_AimAtBestTarget constinit property declarations ***************
	static void NewProp_bSnap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_AimAtBestTarget constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_AimAtBestTarget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics

// ********** Begin Class USquadTask_AimAtBestTarget Property Definitions **************************
void Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::NewProp_bSnap_SetBit(void* Obj)
{
	((USquadTask_AimAtBestTarget*)Obj)->bSnap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::NewProp_bSnap = { "bSnap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_AimAtBestTarget), &Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::NewProp_bSnap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnap_MetaData), NewProp_bSnap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::NewProp_bSnap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_AimAtBestTarget Property Definitions ****************************
UObject* (*const Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::ClassParams = {
	&USquadTask_AimAtBestTarget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::Class_MetaDataParams)
};
void USquadTask_AimAtBestTarget::StaticRegisterNativesUSquadTask_AimAtBestTarget()
{
}
UClass* Z_Construct_UClass_USquadTask_AimAtBestTarget()
{
	if (!Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.OuterSingleton, Z_Construct_UClass_USquadTask_AimAtBestTarget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_AimAtBestTarget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_AimAtBestTarget);
USquadTask_AimAtBestTarget::~USquadTask_AimAtBestTarget() {}
// ********** End Class USquadTask_AimAtBestTarget *************************************************

// ********** Begin Class USquadTask_MoveToSlot ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadTask_MoveToSlot;
UClass* USquadTask_MoveToSlot::GetPrivateStaticClass()
{
	using TClass = USquadTask_MoveToSlot;
	if (!Z_Registration_Info_UClass_USquadTask_MoveToSlot.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadTask_MoveToSlot"),
			Z_Registration_Info_UClass_USquadTask_MoveToSlot.InnerSingleton,
			StaticRegisterNativesUSquadTask_MoveToSlot,
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
	return Z_Registration_Info_UClass_USquadTask_MoveToSlot.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadTask_MoveToSlot_NoRegister()
{
	return USquadTask_MoveToSlot::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadTask_MoveToSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AcceptanceRadius_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireObey_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowOutOfWayWhenAttacking_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allow temporary movement away from slot while trying to enter attack range. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allow temporary movement away from slot while trying to enter attack range." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxOutOfWayDistance_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum distance AI can deviate from current slot while going out-of-way. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance AI can deviate from current slot while going out-of-way." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRangeBuffer_MetaData[] = {
		{ "Category", "Squad|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Small buffer to avoid stepping to exact attack range edge every tick. */" },
#endif
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeTasks.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Small buffer to avoid stepping to exact attack range edge every tick." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USquadTask_MoveToSlot constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AcceptanceRadius;
	static void NewProp_bRequireObey_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireObey;
	static void NewProp_bAllowOutOfWayWhenAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowOutOfWayWhenAttacking;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxOutOfWayDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRangeBuffer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadTask_MoveToSlot constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadTask_MoveToSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadTask_MoveToSlot_Statics

// ********** Begin Class USquadTask_MoveToSlot Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_AcceptanceRadius = { "AcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_MoveToSlot, AcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AcceptanceRadius_MetaData), NewProp_AcceptanceRadius_MetaData) };
void Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bRequireObey_SetBit(void* Obj)
{
	((USquadTask_MoveToSlot*)Obj)->bRequireObey = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bRequireObey = { "bRequireObey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_MoveToSlot), &Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bRequireObey_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireObey_MetaData), NewProp_bRequireObey_MetaData) };
void Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bAllowOutOfWayWhenAttacking_SetBit(void* Obj)
{
	((USquadTask_MoveToSlot*)Obj)->bAllowOutOfWayWhenAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bAllowOutOfWayWhenAttacking = { "bAllowOutOfWayWhenAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadTask_MoveToSlot), &Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bAllowOutOfWayWhenAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowOutOfWayWhenAttacking_MetaData), NewProp_bAllowOutOfWayWhenAttacking_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_MaxOutOfWayDistance = { "MaxOutOfWayDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_MoveToSlot, MaxOutOfWayDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxOutOfWayDistance_MetaData), NewProp_MaxOutOfWayDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_AttackRangeBuffer = { "AttackRangeBuffer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USquadTask_MoveToSlot, AttackRangeBuffer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRangeBuffer_MetaData), NewProp_AttackRangeBuffer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadTask_MoveToSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_AcceptanceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bRequireObey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_bAllowOutOfWayWhenAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_MaxOutOfWayDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadTask_MoveToSlot_Statics::NewProp_AttackRangeBuffer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_MoveToSlot_Statics::PropPointers) < 2048);
// ********** End Class USquadTask_MoveToSlot Property Definitions *********************************
UObject* (*const Z_Construct_UClass_USquadTask_MoveToSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeTaskBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_MoveToSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadTask_MoveToSlot_Statics::ClassParams = {
	&USquadTask_MoveToSlot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadTask_MoveToSlot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_MoveToSlot_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadTask_MoveToSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadTask_MoveToSlot_Statics::Class_MetaDataParams)
};
void USquadTask_MoveToSlot::StaticRegisterNativesUSquadTask_MoveToSlot()
{
}
UClass* Z_Construct_UClass_USquadTask_MoveToSlot()
{
	if (!Z_Registration_Info_UClass_USquadTask_MoveToSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadTask_MoveToSlot.OuterSingleton, Z_Construct_UClass_USquadTask_MoveToSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadTask_MoveToSlot.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadTask_MoveToSlot);
USquadTask_MoveToSlot::~USquadTask_MoveToSlot() {}
// ********** End Class USquadTask_MoveToSlot ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeTasks_h__Script_SquadCoreStateTreeAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadTask_AssignSlot, USquadTask_AssignSlot::StaticClass, TEXT("USquadTask_AssignSlot"), &Z_Registration_Info_UClass_USquadTask_AssignSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_AssignSlot), 1775145009U) },
		{ Z_Construct_UClass_USquadTask_UpdateSlotWorldPos, USquadTask_UpdateSlotWorldPos::StaticClass, TEXT("USquadTask_UpdateSlotWorldPos"), &Z_Registration_Info_UClass_USquadTask_UpdateSlotWorldPos, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_UpdateSlotWorldPos), 4152551301U) },
		{ Z_Construct_UClass_USquadTask_ComputeCompliance, USquadTask_ComputeCompliance::StaticClass, TEXT("USquadTask_ComputeCompliance"), &Z_Registration_Info_UClass_USquadTask_ComputeCompliance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_ComputeCompliance), 637898905U) },
		{ Z_Construct_UClass_USquadTask_EvaluateThreats, USquadTask_EvaluateThreats::StaticClass, TEXT("USquadTask_EvaluateThreats"), &Z_Registration_Info_UClass_USquadTask_EvaluateThreats, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_EvaluateThreats), 1003019393U) },
		{ Z_Construct_UClass_USquadTask_EvaluateLoot, USquadTask_EvaluateLoot::StaticClass, TEXT("USquadTask_EvaluateLoot"), &Z_Registration_Info_UClass_USquadTask_EvaluateLoot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_EvaluateLoot), 2180528370U) },
		{ Z_Construct_UClass_USquadTask_BeginAttackIntent, USquadTask_BeginAttackIntent::StaticClass, TEXT("USquadTask_BeginAttackIntent"), &Z_Registration_Info_UClass_USquadTask_BeginAttackIntent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_BeginAttackIntent), 479131883U) },
		{ Z_Construct_UClass_USquadTask_CommitAttack, USquadTask_CommitAttack::StaticClass, TEXT("USquadTask_CommitAttack"), &Z_Registration_Info_UClass_USquadTask_CommitAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_CommitAttack), 2226788621U) },
		{ Z_Construct_UClass_USquadTask_AimAtBestTarget, USquadTask_AimAtBestTarget::StaticClass, TEXT("USquadTask_AimAtBestTarget"), &Z_Registration_Info_UClass_USquadTask_AimAtBestTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_AimAtBestTarget), 1523295035U) },
		{ Z_Construct_UClass_USquadTask_MoveToSlot, USquadTask_MoveToSlot::StaticClass, TEXT("USquadTask_MoveToSlot"), &Z_Registration_Info_UClass_USquadTask_MoveToSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadTask_MoveToSlot), 3361158786U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeTasks_h__Script_SquadCoreStateTreeAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeTasks_h__Script_SquadCoreStateTreeAdapter_3183365451{
	TEXT("/Script/SquadCoreStateTreeAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeTasks_h__Script_SquadCoreStateTreeAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeTasks_h__Script_SquadCoreStateTreeAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
