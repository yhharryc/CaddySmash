// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegister/HitRegisterTypes.h"

#ifdef HITREGISTERCORE_HitRegisterTypes_generated_h
#error "HitRegisterTypes.generated.h already included, missing '#pragma once' in HitRegisterTypes.h"
#endif
#define HITREGISTERCORE_HitRegisterTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FAttackRequest ****************************************************
struct Z_Construct_UScriptStruct_FAttackRequest_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h_28_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FAttackRequest_Statics; \
	static class UScriptStruct* StaticStruct();


struct FAttackRequest;
// ********** End ScriptStruct FAttackRequest ******************************************************

// ********** Begin ScriptStruct FDamagePacket *****************************************************
struct Z_Construct_UScriptStruct_FDamagePacket_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h_51_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDamagePacket_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDamagePacket;
// ********** End ScriptStruct FDamagePacket *******************************************************

// ********** Begin ScriptStruct FDamageResult *****************************************************
struct Z_Construct_UScriptStruct_FDamageResult_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h_72_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDamageResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDamageResult;
// ********** End ScriptStruct FDamageResult *******************************************************

// ********** Begin ScriptStruct FHitRegisterContext ***********************************************
struct Z_Construct_UScriptStruct_FHitRegisterContext_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h_90_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitRegisterContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitRegisterContext;
// ********** End ScriptStruct FHitRegisterContext *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterTypes_h

// ********** Begin Enum EHitRegisterStopReason ****************************************************
#define FOREACH_ENUM_EHITREGISTERSTOPREASON(op) \
	op(EHitRegisterStopReason::None) \
	op(EHitRegisterStopReason::Missed) \
	op(EHitRegisterStopReason::InvalidHit) \
	op(EHitRegisterStopReason::ReceiverRejected) \
	op(EHitRegisterStopReason::NoDamageable) \
	op(EHitRegisterStopReason::StoppedByNode) 

enum class EHitRegisterStopReason : uint8;
template<> struct TIsUEnumClass<EHitRegisterStopReason> { enum { Value = true }; };
template<> HITREGISTERCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterStopReason>();
// ********** End Enum EHitRegisterStopReason ******************************************************

// ********** Begin Enum EHitNodeResult ************************************************************
#define FOREACH_ENUM_EHITNODERESULT(op) \
	op(EHitNodeResult::Continue) \
	op(EHitNodeResult::Stop) 

enum class EHitNodeResult : uint8;
template<> struct TIsUEnumClass<EHitNodeResult> { enum { Value = true }; };
template<> HITREGISTERCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitNodeResult>();
// ********** End Enum EHitNodeResult **************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
