// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterCollisionTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterCollisionTypes() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHitBoxComponent_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHurtBoxComponent_NoRegister();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode();
HITREGISTERCOLLISION_API UFunction* Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitCandidate();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitCandidateBatch();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitDedupeKey();
HITREGISTERCOLLISION_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterDedupeSettings();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHitRegisterHitBoxMode ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitRegisterHitBoxMode;
static UEnum* EHitRegisterHitBoxMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("EHitRegisterHitBoxMode"));
	}
	return Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.OuterSingleton;
}
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterHitBoxMode>()
{
	return EHitRegisterHitBoxMode_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ContinuousOverlap.Name", "EHitRegisterHitBoxMode::ContinuousOverlap" },
		{ "Disabled.Name", "EHitRegisterHitBoxMode::Disabled" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
		{ "WindowSweep.Name", "EHitRegisterHitBoxMode::WindowSweep" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitRegisterHitBoxMode::WindowSweep", (int64)EHitRegisterHitBoxMode::WindowSweep },
		{ "EHitRegisterHitBoxMode::ContinuousOverlap", (int64)EHitRegisterHitBoxMode::ContinuousOverlap },
		{ "EHitRegisterHitBoxMode::Disabled", (int64)EHitRegisterHitBoxMode::Disabled },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	"EHitRegisterHitBoxMode",
	"EHitRegisterHitBoxMode",
	Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.InnerSingleton, Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitRegisterHitBoxMode.InnerSingleton;
}
// ********** End Enum EHitRegisterHitBoxMode ******************************************************

// ********** Begin Enum EHitRegisterDedupePolicy **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitRegisterDedupePolicy;
static UEnum* EHitRegisterDedupePolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("EHitRegisterDedupePolicy"));
	}
	return Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.OuterSingleton;
}
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterDedupePolicy>()
{
	return EHitRegisterDedupePolicy_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CooldownPerHurtBox.Name", "EHitRegisterDedupePolicy::CooldownPerHurtBox" },
		{ "CooldownPerTarget.Name", "EHitRegisterDedupePolicy::CooldownPerTarget" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
		{ "None.Name", "EHitRegisterDedupePolicy::None" },
		{ "OncePerAttack.Name", "EHitRegisterDedupePolicy::OncePerAttack" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitRegisterDedupePolicy::None", (int64)EHitRegisterDedupePolicy::None },
		{ "EHitRegisterDedupePolicy::OncePerAttack", (int64)EHitRegisterDedupePolicy::OncePerAttack },
		{ "EHitRegisterDedupePolicy::CooldownPerTarget", (int64)EHitRegisterDedupePolicy::CooldownPerTarget },
		{ "EHitRegisterDedupePolicy::CooldownPerHurtBox", (int64)EHitRegisterDedupePolicy::CooldownPerHurtBox },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	"EHitRegisterDedupePolicy",
	"EHitRegisterDedupePolicy",
	Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.InnerSingleton, Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitRegisterDedupePolicy.InnerSingleton;
}
// ********** End Enum EHitRegisterDedupePolicy ****************************************************

// ********** Begin ScriptStruct FHitRegisterDedupeSettings ****************************************
struct Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitRegisterDedupeSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitRegisterDedupeSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Policy_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownSeconds_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitRegisterDedupeSettings constinit property declarations ********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Policy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Policy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitRegisterDedupeSettings constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitRegisterDedupeSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings;
class UScriptStruct* FHitRegisterDedupeSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitRegisterDedupeSettings, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("HitRegisterDedupeSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitRegisterDedupeSettings Property Definitions *******************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_Policy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_Policy = { "Policy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterDedupeSettings, Policy), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterDedupePolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Policy_MetaData), NewProp_Policy_MetaData) }; // 1832408967
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_CooldownSeconds = { "CooldownSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitRegisterDedupeSettings, CooldownSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownSeconds_MetaData), NewProp_CooldownSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_Policy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_Policy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewProp_CooldownSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitRegisterDedupeSettings Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	&NewStructOps,
	"HitRegisterDedupeSettings",
	Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::PropPointers),
	sizeof(FHitRegisterDedupeSettings),
	alignof(FHitRegisterDedupeSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterDedupeSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.InnerSingleton, Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings.InnerSingleton);
}
// ********** End ScriptStruct FHitRegisterDedupeSettings ******************************************

// ********** Begin ScriptStruct FHitCandidate *****************************************************
struct Z_Construct_UScriptStruct_FHitCandidate_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitCandidate); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitCandidate); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetComponent_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitBox_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtBox_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackId_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitCandidate constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HurtBox;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Timestamp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitCandidate constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitCandidate>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitCandidate_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitCandidate;
class UScriptStruct* FHitCandidate::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitCandidate.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitCandidate.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitCandidate, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("HitCandidate"));
	}
	return Z_Registration_Info_UScriptStruct_FHitCandidate.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitCandidate Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_TargetComponent = { "TargetComponent", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, TargetComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetComponent_MetaData), NewProp_TargetComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_HitBox = { "HitBox", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, HitBox), Z_Construct_UClass_UHitRegisterHitBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitBox_MetaData), NewProp_HitBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_HurtBox = { "HurtBox", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, HurtBox), Z_Construct_UClass_UHitRegisterHurtBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtBox_MetaData), NewProp_HurtBox_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_AttackId = { "AttackId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, AttackId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackId_MetaData), NewProp_AttackId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidate, Timestamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timestamp_MetaData), NewProp_Timestamp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitCandidate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_TargetComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_HitBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_HurtBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Hit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Tags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_AttackId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidate_Statics::NewProp_Timestamp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidate_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitCandidate Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitCandidate_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	&NewStructOps,
	"HitCandidate",
	Z_Construct_UScriptStruct_FHitCandidate_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidate_Statics::PropPointers),
	sizeof(FHitCandidate),
	alignof(FHitCandidate),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidate_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitCandidate_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitCandidate()
{
	if (!Z_Registration_Info_UScriptStruct_FHitCandidate.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitCandidate.InnerSingleton, Z_Construct_UScriptStruct_FHitCandidate_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitCandidate.InnerSingleton);
}
// ********** End ScriptStruct FHitCandidate *******************************************************

// ********** Begin ScriptStruct FHitCandidateBatch ************************************************
struct Z_Construct_UScriptStruct_FHitCandidateBatch_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitCandidateBatch); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitCandidateBatch); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Candidates_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rejected_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitCandidateBatch constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Candidates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Candidates;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rejected_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rejected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitCandidateBatch constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitCandidateBatch>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitCandidateBatch_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitCandidateBatch;
class UScriptStruct* FHitCandidateBatch::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitCandidateBatch.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitCandidateBatch.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitCandidateBatch, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("HitCandidateBatch"));
	}
	return Z_Registration_Info_UScriptStruct_FHitCandidateBatch.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitCandidateBatch Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Candidates_Inner = { "Candidates", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitCandidate, METADATA_PARAMS(0, nullptr) }; // 2771630274
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Candidates = { "Candidates", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidateBatch, Candidates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Candidates_MetaData), NewProp_Candidates_MetaData) }; // 2771630274
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Rejected_Inner = { "Rejected", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitCandidate, METADATA_PARAMS(0, nullptr) }; // 2771630274
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Rejected = { "Rejected", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitCandidateBatch, Rejected), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rejected_MetaData), NewProp_Rejected_MetaData) }; // 2771630274
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Candidates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Candidates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Rejected_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewProp_Rejected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitCandidateBatch Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	&NewStructOps,
	"HitCandidateBatch",
	Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::PropPointers),
	sizeof(FHitCandidateBatch),
	alignof(FHitCandidateBatch),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitCandidateBatch()
{
	if (!Z_Registration_Info_UScriptStruct_FHitCandidateBatch.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitCandidateBatch.InnerSingleton, Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitCandidateBatch.InnerSingleton);
}
// ********** End ScriptStruct FHitCandidateBatch **************************************************

// ********** Begin ScriptStruct FHitDedupeKey *****************************************************
struct Z_Construct_UScriptStruct_FHitDedupeKey_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHitDedupeKey); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHitDedupeKey); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackId_MetaData[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtComponent_MetaData[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHitDedupeKey constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackId;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_HurtComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHitDedupeKey constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHitDedupeKey>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHitDedupeKey_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHitDedupeKey;
class UScriptStruct* FHitDedupeKey::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHitDedupeKey.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHitDedupeKey.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHitDedupeKey, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("HitDedupeKey"));
	}
	return Z_Registration_Info_UScriptStruct_FHitDedupeKey.OuterSingleton;
	}

// ********** Begin ScriptStruct FHitDedupeKey Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_AttackId = { "AttackId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitDedupeKey, AttackId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackId_MetaData), NewProp_AttackId_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitDedupeKey, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitDedupeKey, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_HurtComponent = { "HurtComponent", nullptr, (EPropertyFlags)0x0014000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHitDedupeKey, HurtComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtComponent_MetaData), NewProp_HurtComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHitDedupeKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_AttackId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewProp_HurtComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitDedupeKey_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHitDedupeKey Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHitDedupeKey_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	&NewStructOps,
	"HitDedupeKey",
	Z_Construct_UScriptStruct_FHitDedupeKey_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitDedupeKey_Statics::PropPointers),
	sizeof(FHitDedupeKey),
	alignof(FHitDedupeKey),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHitDedupeKey_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHitDedupeKey_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHitDedupeKey()
{
	if (!Z_Registration_Info_UScriptStruct_FHitDedupeKey.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHitDedupeKey.InnerSingleton, Z_Construct_UScriptStruct_FHitDedupeKey_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHitDedupeKey.InnerSingleton);
}
// ********** End ScriptStruct FHitDedupeKey *******************************************************

// ********** Begin Delegate FHitCandidatesEvent ***************************************************
struct Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics
{
	struct _Script_HitRegisterCollision_eventHitCandidatesEvent_Parms
	{
		FHitCandidateBatch Batch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterCollisionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Batch_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FHitCandidatesEvent constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Batch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FHitCandidatesEvent constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FHitCandidatesEvent Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::NewProp_Batch = { "Batch", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_HitRegisterCollision_eventHitCandidatesEvent_Parms, Batch), Z_Construct_UScriptStruct_FHitCandidateBatch, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Batch_MetaData), NewProp_Batch_MetaData) }; // 3388551831
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::NewProp_Batch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FHitCandidatesEvent Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision, nullptr, "HitCandidatesEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::_Script_HitRegisterCollision_eventHitCandidatesEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::_Script_HitRegisterCollision_eventHitCandidatesEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FHitCandidatesEvent_DelegateWrapper(const FMulticastScriptDelegate& HitCandidatesEvent, FHitCandidateBatch const& Batch)
{
	struct _Script_HitRegisterCollision_eventHitCandidatesEvent_Parms
	{
		FHitCandidateBatch Batch;
	};
	_Script_HitRegisterCollision_eventHitCandidatesEvent_Parms Parms;
	Parms.Batch=Batch;
	HitCandidatesEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FHitCandidatesEvent *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHitRegisterHitBoxMode_StaticEnum, TEXT("EHitRegisterHitBoxMode"), &Z_Registration_Info_UEnum_EHitRegisterHitBoxMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1369471840U) },
		{ EHitRegisterDedupePolicy_StaticEnum, TEXT("EHitRegisterDedupePolicy"), &Z_Registration_Info_UEnum_EHitRegisterDedupePolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1832408967U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FHitRegisterDedupeSettings::StaticStruct, Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics::NewStructOps, TEXT("HitRegisterDedupeSettings"),&Z_Registration_Info_UScriptStruct_FHitRegisterDedupeSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitRegisterDedupeSettings), 2711719327U) },
		{ FHitCandidate::StaticStruct, Z_Construct_UScriptStruct_FHitCandidate_Statics::NewStructOps, TEXT("HitCandidate"),&Z_Registration_Info_UScriptStruct_FHitCandidate, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitCandidate), 2771630274U) },
		{ FHitCandidateBatch::StaticStruct, Z_Construct_UScriptStruct_FHitCandidateBatch_Statics::NewStructOps, TEXT("HitCandidateBatch"),&Z_Registration_Info_UScriptStruct_FHitCandidateBatch, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitCandidateBatch), 3388551831U) },
		{ FHitDedupeKey::StaticStruct, Z_Construct_UScriptStruct_FHitDedupeKey_Statics::NewStructOps, TEXT("HitDedupeKey"),&Z_Registration_Info_UScriptStruct_FHitDedupeKey, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHitDedupeKey), 3700340100U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_3079348667{
	TEXT("/Script/HitRegisterCollision"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h__Script_HitRegisterCollision_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
