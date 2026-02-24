// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/StateTree/SquadStateTreeConditions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadStateTreeConditions() {}

// ********** Begin Cross Module References ********************************************************
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_AllowStateTreeControl();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_AllowStateTreeControl_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_AttackReady();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_AttackReady_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_HasBestTarget();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_HasBestTarget_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_NoBestTarget();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_NoBestTarget_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_TargetInAttackRange();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_TargetInAttackRange_NoRegister();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_TargetOutOfAttackRange();
SQUADCORESTATETREEADAPTER_API UClass* Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_NoRegister();
STATETREEMODULE_API UClass* Z_Construct_UClass_UStateTreeConditionBlueprintBase();
UPackage* Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadCond_HasBestTarget *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_HasBestTarget;
UClass* USquadCond_HasBestTarget::GetPrivateStaticClass()
{
	using TClass = USquadCond_HasBestTarget;
	if (!Z_Registration_Info_UClass_USquadCond_HasBestTarget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_HasBestTarget"),
			Z_Registration_Info_UClass_USquadCond_HasBestTarget.InnerSingleton,
			StaticRegisterNativesUSquadCond_HasBestTarget,
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
	return Z_Registration_Info_UClass_USquadCond_HasBestTarget.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_HasBestTarget_NoRegister()
{
	return USquadCond_HasBestTarget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_HasBestTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_HasBestTarget constinit property declarations *****************
// ********** End Class USquadCond_HasBestTarget constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_HasBestTarget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_HasBestTarget_Statics
UObject* (*const Z_Construct_UClass_USquadCond_HasBestTarget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_HasBestTarget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_HasBestTarget_Statics::ClassParams = {
	&USquadCond_HasBestTarget::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_HasBestTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_HasBestTarget_Statics::Class_MetaDataParams)
};
void USquadCond_HasBestTarget::StaticRegisterNativesUSquadCond_HasBestTarget()
{
}
UClass* Z_Construct_UClass_USquadCond_HasBestTarget()
{
	if (!Z_Registration_Info_UClass_USquadCond_HasBestTarget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_HasBestTarget.OuterSingleton, Z_Construct_UClass_USquadCond_HasBestTarget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_HasBestTarget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_HasBestTarget);
USquadCond_HasBestTarget::~USquadCond_HasBestTarget() {}
// ********** End Class USquadCond_HasBestTarget ***************************************************

// ********** Begin Class USquadCond_NoBestTarget **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_NoBestTarget;
UClass* USquadCond_NoBestTarget::GetPrivateStaticClass()
{
	using TClass = USquadCond_NoBestTarget;
	if (!Z_Registration_Info_UClass_USquadCond_NoBestTarget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_NoBestTarget"),
			Z_Registration_Info_UClass_USquadCond_NoBestTarget.InnerSingleton,
			StaticRegisterNativesUSquadCond_NoBestTarget,
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
	return Z_Registration_Info_UClass_USquadCond_NoBestTarget.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_NoBestTarget_NoRegister()
{
	return USquadCond_NoBestTarget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_NoBestTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_NoBestTarget constinit property declarations ******************
// ********** End Class USquadCond_NoBestTarget constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_NoBestTarget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_NoBestTarget_Statics
UObject* (*const Z_Construct_UClass_USquadCond_NoBestTarget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_NoBestTarget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_NoBestTarget_Statics::ClassParams = {
	&USquadCond_NoBestTarget::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_NoBestTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_NoBestTarget_Statics::Class_MetaDataParams)
};
void USquadCond_NoBestTarget::StaticRegisterNativesUSquadCond_NoBestTarget()
{
}
UClass* Z_Construct_UClass_USquadCond_NoBestTarget()
{
	if (!Z_Registration_Info_UClass_USquadCond_NoBestTarget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_NoBestTarget.OuterSingleton, Z_Construct_UClass_USquadCond_NoBestTarget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_NoBestTarget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_NoBestTarget);
USquadCond_NoBestTarget::~USquadCond_NoBestTarget() {}
// ********** End Class USquadCond_NoBestTarget ****************************************************

// ********** Begin Class USquadCond_AllowStateTreeControl *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl;
UClass* USquadCond_AllowStateTreeControl::GetPrivateStaticClass()
{
	using TClass = USquadCond_AllowStateTreeControl;
	if (!Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_AllowStateTreeControl"),
			Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.InnerSingleton,
			StaticRegisterNativesUSquadCond_AllowStateTreeControl,
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
	return Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_AllowStateTreeControl_NoRegister()
{
	return USquadCond_AllowStateTreeControl::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowLeader_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_AllowStateTreeControl constinit property declarations *********
	static void NewProp_bAllowLeader_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowLeader;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USquadCond_AllowStateTreeControl constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_AllowStateTreeControl>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics

// ********** Begin Class USquadCond_AllowStateTreeControl Property Definitions ********************
void Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::NewProp_bAllowLeader_SetBit(void* Obj)
{
	((USquadCond_AllowStateTreeControl*)Obj)->bAllowLeader = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::NewProp_bAllowLeader = { "bAllowLeader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USquadCond_AllowStateTreeControl), &Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::NewProp_bAllowLeader_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowLeader_MetaData), NewProp_bAllowLeader_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::NewProp_bAllowLeader,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::PropPointers) < 2048);
// ********** End Class USquadCond_AllowStateTreeControl Property Definitions **********************
UObject* (*const Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::ClassParams = {
	&USquadCond_AllowStateTreeControl::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::Class_MetaDataParams)
};
void USquadCond_AllowStateTreeControl::StaticRegisterNativesUSquadCond_AllowStateTreeControl()
{
}
UClass* Z_Construct_UClass_USquadCond_AllowStateTreeControl()
{
	if (!Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.OuterSingleton, Z_Construct_UClass_USquadCond_AllowStateTreeControl_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_AllowStateTreeControl);
USquadCond_AllowStateTreeControl::~USquadCond_AllowStateTreeControl() {}
// ********** End Class USquadCond_AllowStateTreeControl *******************************************

// ********** Begin Class USquadCond_AttackReady ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_AttackReady;
UClass* USquadCond_AttackReady::GetPrivateStaticClass()
{
	using TClass = USquadCond_AttackReady;
	if (!Z_Registration_Info_UClass_USquadCond_AttackReady.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_AttackReady"),
			Z_Registration_Info_UClass_USquadCond_AttackReady.InnerSingleton,
			StaticRegisterNativesUSquadCond_AttackReady,
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
	return Z_Registration_Info_UClass_USquadCond_AttackReady.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_AttackReady_NoRegister()
{
	return USquadCond_AttackReady::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_AttackReady_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_AttackReady constinit property declarations *******************
// ********** End Class USquadCond_AttackReady constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_AttackReady>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_AttackReady_Statics
UObject* (*const Z_Construct_UClass_USquadCond_AttackReady_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AttackReady_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_AttackReady_Statics::ClassParams = {
	&USquadCond_AttackReady::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_AttackReady_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_AttackReady_Statics::Class_MetaDataParams)
};
void USquadCond_AttackReady::StaticRegisterNativesUSquadCond_AttackReady()
{
}
UClass* Z_Construct_UClass_USquadCond_AttackReady()
{
	if (!Z_Registration_Info_UClass_USquadCond_AttackReady.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_AttackReady.OuterSingleton, Z_Construct_UClass_USquadCond_AttackReady_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_AttackReady.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_AttackReady);
USquadCond_AttackReady::~USquadCond_AttackReady() {}
// ********** End Class USquadCond_AttackReady *****************************************************

// ********** Begin Class USquadCond_TargetInAttackRange *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_TargetInAttackRange;
UClass* USquadCond_TargetInAttackRange::GetPrivateStaticClass()
{
	using TClass = USquadCond_TargetInAttackRange;
	if (!Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_TargetInAttackRange"),
			Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.InnerSingleton,
			StaticRegisterNativesUSquadCond_TargetInAttackRange,
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
	return Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_TargetInAttackRange_NoRegister()
{
	return USquadCond_TargetInAttackRange::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_TargetInAttackRange constinit property declarations ***********
// ********** End Class USquadCond_TargetInAttackRange constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_TargetInAttackRange>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics
UObject* (*const Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::ClassParams = {
	&USquadCond_TargetInAttackRange::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::Class_MetaDataParams)
};
void USquadCond_TargetInAttackRange::StaticRegisterNativesUSquadCond_TargetInAttackRange()
{
}
UClass* Z_Construct_UClass_USquadCond_TargetInAttackRange()
{
	if (!Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.OuterSingleton, Z_Construct_UClass_USquadCond_TargetInAttackRange_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_TargetInAttackRange.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_TargetInAttackRange);
USquadCond_TargetInAttackRange::~USquadCond_TargetInAttackRange() {}
// ********** End Class USquadCond_TargetInAttackRange *********************************************

// ********** Begin Class USquadCond_TargetOutOfAttackRange ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange;
UClass* USquadCond_TargetOutOfAttackRange::GetPrivateStaticClass()
{
	using TClass = USquadCond_TargetOutOfAttackRange;
	if (!Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadCond_TargetOutOfAttackRange"),
			Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.InnerSingleton,
			StaticRegisterNativesUSquadCond_TargetOutOfAttackRange,
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
	return Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_NoRegister()
{
	return USquadCond_TargetOutOfAttackRange::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ModuleRelativePath", "Public/SquadCore/StateTree/SquadStateTreeConditions.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadCond_TargetOutOfAttackRange constinit property declarations ********
// ********** End Class USquadCond_TargetOutOfAttackRange constinit property declarations **********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadCond_TargetOutOfAttackRange>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics
UObject* (*const Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStateTreeConditionBlueprintBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreStateTreeAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::ClassParams = {
	&USquadCond_TargetOutOfAttackRange::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::Class_MetaDataParams)
};
void USquadCond_TargetOutOfAttackRange::StaticRegisterNativesUSquadCond_TargetOutOfAttackRange()
{
}
UClass* Z_Construct_UClass_USquadCond_TargetOutOfAttackRange()
{
	if (!Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.OuterSingleton, Z_Construct_UClass_USquadCond_TargetOutOfAttackRange_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadCond_TargetOutOfAttackRange);
USquadCond_TargetOutOfAttackRange::~USquadCond_TargetOutOfAttackRange() {}
// ********** End Class USquadCond_TargetOutOfAttackRange ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeConditions_h__Script_SquadCoreStateTreeAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadCond_HasBestTarget, USquadCond_HasBestTarget::StaticClass, TEXT("USquadCond_HasBestTarget"), &Z_Registration_Info_UClass_USquadCond_HasBestTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_HasBestTarget), 3253691398U) },
		{ Z_Construct_UClass_USquadCond_NoBestTarget, USquadCond_NoBestTarget::StaticClass, TEXT("USquadCond_NoBestTarget"), &Z_Registration_Info_UClass_USquadCond_NoBestTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_NoBestTarget), 3115842131U) },
		{ Z_Construct_UClass_USquadCond_AllowStateTreeControl, USquadCond_AllowStateTreeControl::StaticClass, TEXT("USquadCond_AllowStateTreeControl"), &Z_Registration_Info_UClass_USquadCond_AllowStateTreeControl, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_AllowStateTreeControl), 3509895561U) },
		{ Z_Construct_UClass_USquadCond_AttackReady, USquadCond_AttackReady::StaticClass, TEXT("USquadCond_AttackReady"), &Z_Registration_Info_UClass_USquadCond_AttackReady, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_AttackReady), 624060714U) },
		{ Z_Construct_UClass_USquadCond_TargetInAttackRange, USquadCond_TargetInAttackRange::StaticClass, TEXT("USquadCond_TargetInAttackRange"), &Z_Registration_Info_UClass_USquadCond_TargetInAttackRange, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_TargetInAttackRange), 2567574227U) },
		{ Z_Construct_UClass_USquadCond_TargetOutOfAttackRange, USquadCond_TargetOutOfAttackRange::StaticClass, TEXT("USquadCond_TargetOutOfAttackRange"), &Z_Registration_Info_UClass_USquadCond_TargetOutOfAttackRange, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadCond_TargetOutOfAttackRange), 4069956628U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeConditions_h__Script_SquadCoreStateTreeAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeConditions_h__Script_SquadCoreStateTreeAdapter_501453948{
	TEXT("/Script/SquadCoreStateTreeAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeConditions_h__Script_SquadCoreStateTreeAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreStateTreeAdapter_Source_SquadCoreStateTreeAdapter_Public_SquadCore_StateTree_SquadStateTreeConditions_h__Script_SquadCoreStateTreeAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
