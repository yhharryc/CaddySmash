// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
HITREGISTERCORE_API UEnum* Z_Construct_UEnum_HitRegisterCore_EHitNodeResult();
HITREGISTERCORE_API UEnum* Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FAttackRequest();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDamagePacket();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FDamageResult();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHitRegisterStopReason ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitRegisterStopReason;
static UEnum* EHitRegisterStopReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterStopReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitRegisterStopReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("EHitRegisterStopReason"));
	}
	return Z_Registration_Info_UEnum_EHitRegisterStopReason.OuterSingleton;
}
template<> HITREGISTERCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterStopReason>()
{
	return EHitRegisterStopReason_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "InvalidHit.Name", "EHitRegisterStopReason::InvalidHit" },
		{ "Missed.Name", "EHitRegisterStopReason::Missed" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
		{ "NoDamageable.Name", "EHitRegisterStopReason::NoDamageable" },
		{ "None.Name", "EHitRegisterStopReason::None" },
		{ "ReceiverRejected.Name", "EHitRegisterStopReason::ReceiverRejected" },
		{ "StoppedByNode.Name", "EHitRegisterStopReason::StoppedByNode" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitRegisterStopReason::None", (int64)EHitRegisterStopReason::None },
		{ "EHitRegisterStopReason::Missed", (int64)EHitRegisterStopReason::Missed },
		{ "EHitRegisterStopReason::InvalidHit", (int64)EHitRegisterStopReason::InvalidHit },
		{ "EHitRegisterStopReason::ReceiverRejected", (int64)EHitRegisterStopReason::ReceiverRejected },
		{ "EHitRegisterStopReason::NoDamageable", (int64)EHitRegisterStopReason::NoDamageable },
		{ "EHitRegisterStopReason::StoppedByNode", (int64)EHitRegisterStopReason::StoppedByNode },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	"EHitRegisterStopReason",
	"EHitRegisterStopReason",
	Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterStopReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitRegisterStopReason.InnerSingleton, Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitRegisterStopReason.InnerSingleton;
}
// ********** End Enum EHitRegisterStopReason ******************************************************

// ********** Begin Enum EHitNodeResult ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitNodeResult;
static UEnum* EHitNodeResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitNodeResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitNodeResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCore_EHitNodeResult, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("EHitNodeResult"));
	}
	return Z_Registration_Info_UEnum_EHitNodeResult.OuterSingleton;
}
template<> HITREGISTERCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitNodeResult>()
{
	return EHitNodeResult_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Continue.Name", "EHitNodeResult::Continue" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
		{ "Stop.Name", "EHitNodeResult::Stop" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitNodeResult::Continue", (int64)EHitNodeResult::Continue },
		{ "EHitNodeResult::Stop", (int64)EHitNodeResult::Stop },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	"EHitNodeResult",
	"EHitNodeResult",
	Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCore_EHitNodeResult()
{
	if (!Z_Registration_Info_UEnum_EHitNodeResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitNodeResult.InnerSingleton, Z_Construct_UEnum_HitRegisterCore_EHitNodeResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitNodeResult.InnerSingleton;
}
// ********** End Enum EHitNodeResult **************************************************************

// ********** Begin ScriptStruct FAttackRequest ****************************************************
struct Z_Construct_UScriptStruct_FAttackRequest_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAttackRequest); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAttackRequest); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceObject_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attributes_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: attribute snapshot for this attack. Keys are gameplay tags (e.g., Attr.Strength) */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: attribute snapshot for this attack. Keys are gameplay tags (e.g., Attr.Strength)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: tags for damage types / routing */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: tags for damage types / routing" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAttackRequest constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceObject;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Attributes_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attributes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Attributes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAttackRequest constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttackRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAttackRequest_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAttackRequest;
class UScriptStruct* FAttackRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAttackRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAttackRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttackRequest, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("AttackRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FAttackRequest.OuterSingleton;
	}

// ********** Begin ScriptStruct FAttackRequest Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackRequest, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_SourceObject = { "SourceObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackRequest, SourceObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceObject_MetaData), NewProp_SourceObject_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackRequest, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes_ValueProp = { "Attributes", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes_Key_KeyProp = { "Attributes_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes = { "Attributes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackRequest, Attributes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attributes_MetaData), NewProp_Attributes_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackRequest, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttackRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_SourceObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_BaseDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Attributes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackRequest_Statics::NewProp_Tags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackRequest_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAttackRequest Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttackRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	&NewStructOps,
	"AttackRequest",
	Z_Construct_UScriptStruct_FAttackRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackRequest_Statics::PropPointers),
	sizeof(FAttackRequest),
	alignof(FAttackRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAttackRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAttackRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FAttackRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAttackRequest.InnerSingleton, Z_Construct_UScriptStruct_FAttackRequest_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAttackRequest.InnerSingleton);
}
// ********** End ScriptStruct FAttackRequest ******************************************************

// ********** Begin ScriptStruct FDamagePacket *****************************************************
struct Z_Construct_UScriptStruct_FDamagePacket_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDamagePacket); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDamagePacket); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawDamage_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MitigatedDamage_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalDamage_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCrit_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsWeakPoint_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDamagePacket constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MitigatedDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FinalDamage;
	static void NewProp_bIsCrit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCrit;
	static void NewProp_bIsWeakPoint_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsWeakPoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDamagePacket constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDamagePacket>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDamagePacket_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDamagePacket;
class UScriptStruct* FDamagePacket::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDamagePacket.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDamagePacket.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDamagePacket, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("DamagePacket"));
	}
	return Z_Registration_Info_UScriptStruct_FDamagePacket.OuterSingleton;
	}

// ********** Begin ScriptStruct FDamagePacket Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_RawDamage = { "RawDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamagePacket, RawDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawDamage_MetaData), NewProp_RawDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_MitigatedDamage = { "MitigatedDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamagePacket, MitigatedDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MitigatedDamage_MetaData), NewProp_MitigatedDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_FinalDamage = { "FinalDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamagePacket, FinalDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalDamage_MetaData), NewProp_FinalDamage_MetaData) };
void Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsCrit_SetBit(void* Obj)
{
	((FDamagePacket*)Obj)->bIsCrit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsCrit = { "bIsCrit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDamagePacket), &Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsCrit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCrit_MetaData), NewProp_bIsCrit_MetaData) };
void Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsWeakPoint_SetBit(void* Obj)
{
	((FDamagePacket*)Obj)->bIsWeakPoint = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsWeakPoint = { "bIsWeakPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDamagePacket), &Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsWeakPoint_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsWeakPoint_MetaData), NewProp_bIsWeakPoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDamagePacket_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_RawDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_MitigatedDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_FinalDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsCrit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamagePacket_Statics::NewProp_bIsWeakPoint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamagePacket_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDamagePacket Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDamagePacket_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	&NewStructOps,
	"DamagePacket",
	Z_Construct_UScriptStruct_FDamagePacket_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamagePacket_Statics::PropPointers),
	sizeof(FDamagePacket),
	alignof(FDamagePacket),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamagePacket_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDamagePacket_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDamagePacket()
{
	if (!Z_Registration_Info_UScriptStruct_FDamagePacket.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDamagePacket.InnerSingleton, Z_Construct_UScriptStruct_FDamagePacket_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDamagePacket.InnerSingleton);
}
// ********** End ScriptStruct FDamagePacket *******************************************************

// ********** Begin ScriptStruct FDamageResult *****************************************************
struct Z_Construct_UScriptStruct_FDamageResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDamageResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDamageResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppliedToShield_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppliedToHealth_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bKilled_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StopReason_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDamageResult constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AppliedToShield;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AppliedToHealth;
	static void NewProp_bKilled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bKilled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StopReason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StopReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDamageResult constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDamageResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDamageResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDamageResult;
class UScriptStruct* FDamageResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDamageResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDamageResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDamageResult, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("DamageResult"));
	}
	return Z_Registration_Info_UScriptStruct_FDamageResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FDamageResult Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_AppliedToShield = { "AppliedToShield", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageResult, AppliedToShield), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppliedToShield_MetaData), NewProp_AppliedToShield_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_AppliedToHealth = { "AppliedToHealth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageResult, AppliedToHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppliedToHealth_MetaData), NewProp_AppliedToHealth_MetaData) };
void Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_bKilled_SetBit(void* Obj)
{
	((FDamageResult*)Obj)->bKilled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_bKilled = { "bKilled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDamageResult), &Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_bKilled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bKilled_MetaData), NewProp_bKilled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_StopReason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_StopReason = { "StopReason", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageResult, StopReason), Z_Construct_UEnum_HitRegisterCore_EHitRegisterStopReason, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopReason_MetaData), NewProp_StopReason_MetaData) }; // 2941606891
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDamageResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_AppliedToShield,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_AppliedToHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_bKilled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_StopReason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageResult_Statics::NewProp_StopReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDamageResult Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDamageResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	&NewStructOps,
	"DamageResult",
	Z_Construct_UScriptStruct_FDamageResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageResult_Statics::PropPointers),
	sizeof(FDamageResult),
	alignof(FDamageResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDamageResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDamageResult()
{
	if (!Z_Registration_Info_UScriptStruct_FDamageResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDamageResult.InnerSingleton, Z_Construct_UScriptStruct_FDamageResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDamageResult.InnerSingleton);
}
// ********** End ScriptStruct FDamageResult *******************************************************

// ********** Begin ScriptStruct FHitRegisterContext ***********************************************
struct Z_Construct_UScriptStruct_FHitRegisterContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitRegisterContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitRegisterContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitRegisterContext constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitRegisterContext constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitRegisterContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitRegisterContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitRegisterContext;
class UScriptStruct* FHitRegisterContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitRegisterContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitRegisterContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitRegisterContext, (UObject*)Z_Construct_UPackage__Script_HitRegisterCore(), TEXT("HitRegisterContext"));
	}
	return Z_Registration_Info_UScriptStruct_FHitRegisterContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitRegisterContext Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterContext, Attack), Z_Construct_UScriptStruct_FAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attack_MetaData), NewProp_Attack_MetaData) }; // 3582829048
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterContext, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterContext, Damage), Z_Construct_UScriptStruct_FDamagePacket, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) }; // 3009109696
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterContext, Result), Z_Construct_UScriptStruct_FDamageResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 2147314720
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitRegisterContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Hit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitRegisterContext Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitRegisterContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
	nullptr,
	&NewStructOps,
	"HitRegisterContext",
	Z_Construct_UScriptStruct_FHitRegisterContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterContext_Statics::PropPointers),
	sizeof(FHitRegisterContext),
	alignof(FHitRegisterContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitRegisterContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext()
{
	if (!Z_Registration_Info_UScriptStruct_FHitRegisterContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitRegisterContext.InnerSingleton, Z_Construct_UScriptStruct_FHitRegisterContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitRegisterContext.InnerSingleton);
}
// ********** End ScriptStruct FHitRegisterContext *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHitRegisterStopReason_StaticEnum, TEXT("EHitRegisterStopReason"), &Z_Registration_Info_UEnum_EHitRegisterStopReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2941606891U) },
		{ EHitNodeResult_StaticEnum, TEXT("EHitNodeResult"), &Z_Registration_Info_UEnum_EHitNodeResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4257870574U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAttackRequest::StaticStruct, Z_Construct_UScriptStruct_FAttackRequest_Statics::NewStructOps, TEXT("AttackRequest"),&Z_Registration_Info_UScriptStruct_FAttackRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttackRequest), 3582829048U) },
		{ FDamagePacket::StaticStruct, Z_Construct_UScriptStruct_FDamagePacket_Statics::NewStructOps, TEXT("DamagePacket"),&Z_Registration_Info_UScriptStruct_FDamagePacket, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDamagePacket), 3009109696U) },
		{ FDamageResult::StaticStruct, Z_Construct_UScriptStruct_FDamageResult_Statics::NewStructOps, TEXT("DamageResult"),&Z_Registration_Info_UScriptStruct_FDamageResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDamageResult), 2147314720U) },
		{ FHitRegisterContext::StaticStruct, Z_Construct_UScriptStruct_FHitRegisterContext_Statics::NewStructOps, TEXT("HitRegisterContext"),&Z_Registration_Info_UScriptStruct_FHitRegisterContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitRegisterContext), 1092352881U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_2412523252{
	TEXT("/Script/HitRegisterCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h__Script_HitRegisterCore_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
