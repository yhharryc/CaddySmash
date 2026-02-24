// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
SQUADCORE_API UEnum* Z_Construct_UEnum_SquadCore_ELootPolicy();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FLootCandidate();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FSquadComplianceContext();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FSquadSlot();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FThreatCandidate();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ELootPolicy ***************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELootPolicy;
static UEnum* ELootPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ELootPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ELootPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SquadCore_ELootPolicy, (UObject*)Z_Construct_UPackage__Script_SquadCore(), TEXT("ELootPolicy"));
	}
	return Z_Registration_Info_UEnum_ELootPolicy.OuterSingleton;
}
template<> SQUADCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<ELootPolicy>()
{
	return ELootPolicy_StaticEnum();
}
struct Z_Construct_UEnum_SquadCore_ELootPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Interruptible.Name", "ELootPolicy::Interruptible" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
		{ "Never.Name", "ELootPolicy::Never" },
		{ "OnlySafe.Name", "ELootPolicy::OnlySafe" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ELootPolicy::Never", (int64)ELootPolicy::Never },
		{ "ELootPolicy::OnlySafe", (int64)ELootPolicy::OnlySafe },
		{ "ELootPolicy::Interruptible", (int64)ELootPolicy::Interruptible },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_SquadCore_ELootPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SquadCore,
	nullptr,
	"ELootPolicy",
	"ELootPolicy",
	Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SquadCore_ELootPolicy()
{
	if (!Z_Registration_Info_UEnum_ELootPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELootPolicy.InnerSingleton, Z_Construct_UEnum_SquadCore_ELootPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ELootPolicy.InnerSingleton;
}
// ********** End Enum ELootPolicy *****************************************************************

// ********** Begin ScriptStruct FSquadSlot ********************************************************
struct Z_Construct_UScriptStruct_FSquadSlot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSquadSlot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSquadSlot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotId_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoleTag_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSquadSlot constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoleTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSquadSlot constinit property declarations **************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSquadSlot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSquadSlot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSquadSlot;
class UScriptStruct* FSquadSlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadSlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSquadSlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSquadSlot, (UObject*)Z_Construct_UPackage__Script_SquadCore(), TEXT("SquadSlot"));
	}
	return Z_Registration_Info_UScriptStruct_FSquadSlot.OuterSingleton;
	}

// ********** Begin ScriptStruct FSquadSlot Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadSlot, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadSlot, SlotId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotId_MetaData), NewProp_SlotId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_RoleTag = { "RoleTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadSlot, RoleTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoleTag_MetaData), NewProp_RoleTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSquadSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_SlotId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadSlot_Statics::NewProp_RoleTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadSlot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSquadSlot Property Definitions *************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSquadSlot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
	nullptr,
	&NewStructOps,
	"SquadSlot",
	Z_Construct_UScriptStruct_FSquadSlot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadSlot_Statics::PropPointers),
	sizeof(FSquadSlot),
	alignof(FSquadSlot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadSlot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSquadSlot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSquadSlot()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadSlot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSquadSlot.InnerSingleton, Z_Construct_UScriptStruct_FSquadSlot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSquadSlot.InnerSingleton);
}
// ********** End ScriptStruct FSquadSlot **********************************************************

// ********** Begin ScriptStruct FThreatCandidate **************************************************
struct Z_Construct_UScriptStruct_FThreatCandidate_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FThreatCandidate); }
	static inline consteval int16 GetStructAlignment() { return alignof(FThreatCandidate); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FThreatCandidate constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Score;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FThreatCandidate constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FThreatCandidate>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FThreatCandidate_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FThreatCandidate;
class UScriptStruct* FThreatCandidate::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FThreatCandidate.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FThreatCandidate.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FThreatCandidate, (UObject*)Z_Construct_UPackage__Script_SquadCore(), TEXT("ThreatCandidate"));
	}
	return Z_Registration_Info_UScriptStruct_FThreatCandidate.OuterSingleton;
	}

// ********** Begin ScriptStruct FThreatCandidate Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FThreatCandidate, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FThreatCandidate, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FThreatCandidate, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FThreatCandidate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewProp_Tags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FThreatCandidate_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FThreatCandidate Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FThreatCandidate_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
	nullptr,
	&NewStructOps,
	"ThreatCandidate",
	Z_Construct_UScriptStruct_FThreatCandidate_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FThreatCandidate_Statics::PropPointers),
	sizeof(FThreatCandidate),
	alignof(FThreatCandidate),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FThreatCandidate_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FThreatCandidate_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FThreatCandidate()
{
	if (!Z_Registration_Info_UScriptStruct_FThreatCandidate.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FThreatCandidate.InnerSingleton, Z_Construct_UScriptStruct_FThreatCandidate_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FThreatCandidate.InnerSingleton);
}
// ********** End ScriptStruct FThreatCandidate ****************************************************

// ********** Begin ScriptStruct FLootCandidate ****************************************************
struct Z_Construct_UScriptStruct_FLootCandidate_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FLootCandidate); }
	static inline consteval int16 GetStructAlignment() { return alignof(FLootCandidate); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootActor_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FLootCandidate constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LootActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Score;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FLootCandidate constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLootCandidate>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FLootCandidate_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLootCandidate;
class UScriptStruct* FLootCandidate::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLootCandidate.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLootCandidate.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLootCandidate, (UObject*)Z_Construct_UPackage__Script_SquadCore(), TEXT("LootCandidate"));
	}
	return Z_Registration_Info_UScriptStruct_FLootCandidate.OuterSingleton;
	}

// ********** Begin ScriptStruct FLootCandidate Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_LootActor = { "LootActor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLootCandidate, LootActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootActor_MetaData), NewProp_LootActor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLootCandidate, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLootCandidate, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLootCandidate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_LootActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLootCandidate_Statics::NewProp_Tags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLootCandidate_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FLootCandidate Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLootCandidate_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
	nullptr,
	&NewStructOps,
	"LootCandidate",
	Z_Construct_UScriptStruct_FLootCandidate_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLootCandidate_Statics::PropPointers),
	sizeof(FLootCandidate),
	alignof(FLootCandidate),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLootCandidate_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLootCandidate_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLootCandidate()
{
	if (!Z_Registration_Info_UScriptStruct_FLootCandidate.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLootCandidate.InnerSingleton, Z_Construct_UScriptStruct_FLootCandidate_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FLootCandidate.InnerSingleton);
}
// ********** End ScriptStruct FLootCandidate ******************************************************

// ********** Begin ScriptStruct FSquadComplianceContext *******************************************
struct Z_Construct_UScriptStruct_FSquadComplianceContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSquadComplianceContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSquadComplianceContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureValue_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthRatio_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceToLeader_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInCombat_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSquadComplianceContext constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressureValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthRatio;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceToLeader;
	static void NewProp_bInCombat_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInCombat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSquadComplianceContext constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSquadComplianceContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSquadComplianceContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSquadComplianceContext;
class UScriptStruct* FSquadComplianceContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadComplianceContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSquadComplianceContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSquadComplianceContext, (UObject*)Z_Construct_UPackage__Script_SquadCore(), TEXT("SquadComplianceContext"));
	}
	return Z_Registration_Info_UScriptStruct_FSquadComplianceContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FSquadComplianceContext Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_PressureValue = { "PressureValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadComplianceContext, PressureValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureValue_MetaData), NewProp_PressureValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_HealthRatio = { "HealthRatio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadComplianceContext, HealthRatio), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthRatio_MetaData), NewProp_HealthRatio_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_DistanceToLeader = { "DistanceToLeader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSquadComplianceContext, DistanceToLeader), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceToLeader_MetaData), NewProp_DistanceToLeader_MetaData) };
void Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_bInCombat_SetBit(void* Obj)
{
	((FSquadComplianceContext*)Obj)->bInCombat = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_bInCombat = { "bInCombat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSquadComplianceContext), &Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_bInCombat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInCombat_MetaData), NewProp_bInCombat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_PressureValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_HealthRatio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_DistanceToLeader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewProp_bInCombat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSquadComplianceContext Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
	nullptr,
	&NewStructOps,
	"SquadComplianceContext",
	Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::PropPointers),
	sizeof(FSquadComplianceContext),
	alignof(FSquadComplianceContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSquadComplianceContext()
{
	if (!Z_Registration_Info_UScriptStruct_FSquadComplianceContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSquadComplianceContext.InnerSingleton, Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSquadComplianceContext.InnerSingleton);
}
// ********** End ScriptStruct FSquadComplianceContext *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ELootPolicy_StaticEnum, TEXT("ELootPolicy"), &Z_Registration_Info_UEnum_ELootPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 932092389U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSquadSlot::StaticStruct, Z_Construct_UScriptStruct_FSquadSlot_Statics::NewStructOps, TEXT("SquadSlot"),&Z_Registration_Info_UScriptStruct_FSquadSlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSquadSlot), 3011450254U) },
		{ FThreatCandidate::StaticStruct, Z_Construct_UScriptStruct_FThreatCandidate_Statics::NewStructOps, TEXT("ThreatCandidate"),&Z_Registration_Info_UScriptStruct_FThreatCandidate, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FThreatCandidate), 730226818U) },
		{ FLootCandidate::StaticStruct, Z_Construct_UScriptStruct_FLootCandidate_Statics::NewStructOps, TEXT("LootCandidate"),&Z_Registration_Info_UScriptStruct_FLootCandidate, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLootCandidate), 4005417798U) },
		{ FSquadComplianceContext::StaticStruct, Z_Construct_UScriptStruct_FSquadComplianceContext_Statics::NewStructOps, TEXT("SquadComplianceContext"),&Z_Registration_Info_UScriptStruct_FSquadComplianceContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSquadComplianceContext), 2047008771U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_2841495364{
	TEXT("/Script/SquadCore"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h__Script_SquadCore_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
