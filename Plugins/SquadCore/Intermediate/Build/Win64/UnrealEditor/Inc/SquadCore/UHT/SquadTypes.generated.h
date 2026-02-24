// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/SquadTypes.h"

#ifdef SQUADCORE_SquadTypes_generated_h
#error "SquadTypes.generated.h already included, missing '#pragma once' in SquadTypes.h"
#endif
#define SQUADCORE_SquadTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FSquadSlot ********************************************************
struct Z_Construct_UScriptStruct_FSquadSlot_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h_18_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSquadSlot_Statics; \
	static class UScriptStruct* StaticStruct();


struct FSquadSlot;
// ********** End ScriptStruct FSquadSlot **********************************************************

// ********** Begin ScriptStruct FThreatCandidate **************************************************
struct Z_Construct_UScriptStruct_FThreatCandidate_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h_33_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FThreatCandidate_Statics; \
	static class UScriptStruct* StaticStruct();


struct FThreatCandidate;
// ********** End ScriptStruct FThreatCandidate ****************************************************

// ********** Begin ScriptStruct FLootCandidate ****************************************************
struct Z_Construct_UScriptStruct_FLootCandidate_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h_48_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FLootCandidate_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLootCandidate;
// ********** End ScriptStruct FLootCandidate ******************************************************

// ********** Begin ScriptStruct FSquadComplianceContext *******************************************
struct Z_Construct_UScriptStruct_FSquadComplianceContext_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h_63_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSquadComplianceContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FSquadComplianceContext;
// ********** End ScriptStruct FSquadComplianceContext *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadTypes_h

// ********** Begin Enum ELootPolicy ***************************************************************
#define FOREACH_ENUM_ELOOTPOLICY(op) \
	op(ELootPolicy::Never) \
	op(ELootPolicy::OnlySafe) \
	op(ELootPolicy::Interruptible) 

enum class ELootPolicy : uint8;
template<> struct TIsUEnumClass<ELootPolicy> { enum { Value = true }; };
template<> SQUADCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<ELootPolicy>();
// ********** End Enum ELootPolicy *****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
