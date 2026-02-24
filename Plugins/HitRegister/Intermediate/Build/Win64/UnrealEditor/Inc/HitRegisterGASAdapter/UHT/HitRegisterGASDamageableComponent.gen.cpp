// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterGAS/HitRegisterGASDamageableComponent.h"
#include "GameplayTagContainer.h"
#include "HitRegister/HitRegisterTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterGASDamageableComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UDamageApplier_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitReceiver_NoRegister();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
HITREGISTERGASADAPTER_API UClass* Z_Construct_UClass_UHitRegisterGASDamageableComponent();
HITREGISTERGASADAPTER_API UClass* Z_Construct_UClass_UHitRegisterGASDamageableComponent_NoRegister();
HITREGISTERGASADAPTER_API UFunction* Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_HitRegisterGASAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FHitRegisterContextEvent **********************************************
struct Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics
{
	struct _Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms
	{
		FHitRegisterContext Context;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FHitRegisterContextEvent constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FHitRegisterContextEvent constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FHitRegisterContextEvent Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 1092352881
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FHitRegisterContextEvent Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_HitRegisterGASAdapter, nullptr, "HitRegisterContextEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::_Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::_Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FHitRegisterContextEvent_DelegateWrapper(const FMulticastScriptDelegate& HitRegisterContextEvent, FHitRegisterContext const& Context)
{
	struct _Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms
	{
		FHitRegisterContext Context;
	};
	_Script_HitRegisterGASAdapter_eventHitRegisterContextEvent_Parms Parms;
	Parms.Context=Context;
	HitRegisterContextEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FHitRegisterContextEvent ************************************************

// ********** Begin Class UHitRegisterGASDamageableComponent ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent;
UClass* UHitRegisterGASDamageableComponent::GetPrivateStaticClass()
{
	using TClass = UHitRegisterGASDamageableComponent;
	if (!Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterGASDamageableComponent"),
			Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.InnerSingleton,
			StaticRegisterNativesUHitRegisterGASDamageableComponent,
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
	return Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterGASDamageableComponent_NoRegister()
{
	return UHitRegisterGASDamageableComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * GAS adapter: attach to any actor with an AbilitySystemComponent to make it damageable by HitRegisterCore.\n * It applies an Instant GameplayEffect (configured per-project) with a set-by-caller magnitude.\n */" },
#endif
		{ "IncludePath", "HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS adapter: attach to any actor with an AbilitySystemComponent to make it damageable by HitRegisterCore.\nIt applies an Instant GameplayEffect (configured per-project) with a set-by-caller magnitude." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageEffectClass_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** GE to apply to self. Should have an Instant modifier to your Health attribute using SetByCaller. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GE to apply to self. Should have an Instant modifier to your Health attribute using SetByCaller." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageSetByCallerTag_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** SetByCaller tag (defaults from HitRegisterSettings if unset). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SetByCaller tag (defaults from HitRegisterSettings if unset)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CritSetByCallerTag_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional SetByCaller tag used to carry crit flag to downstream damage events. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional SetByCaller tag used to carry crit flag to downstream damage events." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bApplyOnAuthorityOnly_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Apply only on authority by default. If you use prediction, you may enable this. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply only on authority by default. If you use prediction, you may enable this." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFailIfCannotApply_MetaData[] = {
		{ "Category", "HitRegister|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, ApplyDamage returns false when it cannot find ASC or DamageEffectClass is missing. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, ApplyDamage returns false when it cannot find ASC or DamageEffectClass is missing." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHit_MetaData[] = {
		{ "Category", "HitRegister|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when hit is confirmed (even if damage ends up 0). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when hit is confirmed (even if damage ends up 0)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDamaged_MetaData[] = {
		{ "Category", "HitRegister|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired after damage effect is applied (only if damage > 0). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired after damage effect is applied (only if damage > 0)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPostDamageEvent_MetaData[] = {
		{ "Category", "HitRegister|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired after pipeline post-damage hook. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterGAS/HitRegisterGASDamageableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired after pipeline post-damage hook." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterGASDamageableComponent constinit property declarations *******
	static const UECodeGen_Private::FClassPropertyParams NewProp_DamageEffectClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DamageSetByCallerTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CritSetByCallerTag;
	static void NewProp_bApplyOnAuthorityOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bApplyOnAuthorityOnly;
	static void NewProp_bFailIfCannotApply_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFailIfCannotApply;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHit;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDamaged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPostDamageEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterGASDamageableComponent constinit property declarations *********
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterGASDamageableComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics

// ********** Begin Class UHitRegisterGASDamageableComponent Property Definitions ******************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_DamageEffectClass = { "DamageEffectClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, DamageEffectClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageEffectClass_MetaData), NewProp_DamageEffectClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_DamageSetByCallerTag = { "DamageSetByCallerTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, DamageSetByCallerTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageSetByCallerTag_MetaData), NewProp_DamageSetByCallerTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_CritSetByCallerTag = { "CritSetByCallerTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, CritSetByCallerTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CritSetByCallerTag_MetaData), NewProp_CritSetByCallerTag_MetaData) }; // 517357616
void Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bApplyOnAuthorityOnly_SetBit(void* Obj)
{
	((UHitRegisterGASDamageableComponent*)Obj)->bApplyOnAuthorityOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bApplyOnAuthorityOnly = { "bApplyOnAuthorityOnly", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHitRegisterGASDamageableComponent), &Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bApplyOnAuthorityOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bApplyOnAuthorityOnly_MetaData), NewProp_bApplyOnAuthorityOnly_MetaData) };
void Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bFailIfCannotApply_SetBit(void* Obj)
{
	((UHitRegisterGASDamageableComponent*)Obj)->bFailIfCannotApply = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bFailIfCannotApply = { "bFailIfCannotApply", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHitRegisterGASDamageableComponent), &Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bFailIfCannotApply_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFailIfCannotApply_MetaData), NewProp_bFailIfCannotApply_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnHit = { "OnHit", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, OnHit), Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHit_MetaData), NewProp_OnHit_MetaData) }; // 2121649426
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnDamaged = { "OnDamaged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, OnDamaged), Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDamaged_MetaData), NewProp_OnDamaged_MetaData) }; // 2121649426
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnPostDamageEvent = { "OnPostDamageEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterGASDamageableComponent, OnPostDamageEvent), Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPostDamageEvent_MetaData), NewProp_OnPostDamageEvent_MetaData) }; // 2121649426
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_DamageEffectClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_DamageSetByCallerTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_CritSetByCallerTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bApplyOnAuthorityOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_bFailIfCannotApply,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnDamaged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::NewProp_OnPostDamageEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterGASDamageableComponent Property Definitions ********************
UObject* (*const Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterGASAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UDamageApplier_NoRegister, (int32)VTABLE_OFFSET(UHitRegisterGASDamageableComponent, IDamageApplier), false },  // 167600026
	{ Z_Construct_UClass_UHitReceiver_NoRegister, (int32)VTABLE_OFFSET(UHitRegisterGASDamageableComponent, IHitReceiver), false },  // 4143829006
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::ClassParams = {
	&UHitRegisterGASDamageableComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::Class_MetaDataParams)
};
void UHitRegisterGASDamageableComponent::StaticRegisterNativesUHitRegisterGASDamageableComponent()
{
}
UClass* Z_Construct_UClass_UHitRegisterGASDamageableComponent()
{
	if (!Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.OuterSingleton, Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterGASDamageableComponent);
UHitRegisterGASDamageableComponent::~UHitRegisterGASDamageableComponent() {}
// ********** End Class UHitRegisterGASDamageableComponent *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h__Script_HitRegisterGASAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterGASDamageableComponent, UHitRegisterGASDamageableComponent::StaticClass, TEXT("UHitRegisterGASDamageableComponent"), &Z_Registration_Info_UClass_UHitRegisterGASDamageableComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterGASDamageableComponent), 2424739667U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h__Script_HitRegisterGASAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h__Script_HitRegisterGASAdapter_227453151{
	TEXT("/Script/HitRegisterGASAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h__Script_HitRegisterGASAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h__Script_HitRegisterGASAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
