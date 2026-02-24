// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterCollisionTypes.h"

#ifdef HITREGISTERCOLLISION_HitRegisterCollisionTypes_generated_h
#error "HitRegisterCollisionTypes.generated.h already included, missing '#pragma once' in HitRegisterCollisionTypes.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterCollisionTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitCandidateBatch;

// ********** Begin ScriptStruct FHitRegisterDedupeSettings ****************************************
struct Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h_31_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitRegisterDedupeSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitRegisterDedupeSettings;
// ********** End ScriptStruct FHitRegisterDedupeSettings ******************************************

// ********** Begin ScriptStruct FHitCandidate *****************************************************
struct Z_Construct_UScriptStruct_FHitCandidate_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h_43_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitCandidate_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitCandidate;
// ********** End ScriptStruct FHitCandidate *******************************************************

// ********** Begin ScriptStruct FHitCandidateBatch ************************************************
struct Z_Construct_UScriptStruct_FHitCandidateBatch_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h_73_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitCandidateBatch_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitCandidateBatch;
// ********** End ScriptStruct FHitCandidateBatch **************************************************

// ********** Begin ScriptStruct FHitDedupeKey *****************************************************
struct Z_Construct_UScriptStruct_FHitDedupeKey_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h_85_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FHitDedupeKey_Statics; \
	static class UScriptStruct* StaticStruct();


struct FHitDedupeKey;
// ********** End ScriptStruct FHitDedupeKey *******************************************************

// ********** Begin Delegate FHitCandidatesEvent ***************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h_117_DELEGATE \
HITREGISTERCOLLISION_API void FHitCandidatesEvent_DelegateWrapper(const FMulticastScriptDelegate& HitCandidatesEvent, FHitCandidateBatch const& Batch);


// ********** End Delegate FHitCandidatesEvent *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionTypes_h

// ********** Begin Enum EHitRegisterHitBoxMode ****************************************************
#define FOREACH_ENUM_EHITREGISTERHITBOXMODE(op) \
	op(EHitRegisterHitBoxMode::WindowSweep) \
	op(EHitRegisterHitBoxMode::ContinuousOverlap) \
	op(EHitRegisterHitBoxMode::Disabled) 

enum class EHitRegisterHitBoxMode : uint8;
template<> struct TIsUEnumClass<EHitRegisterHitBoxMode> { enum { Value = true }; };
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterHitBoxMode>();
// ********** End Enum EHitRegisterHitBoxMode ******************************************************

// ********** Begin Enum EHitRegisterDedupePolicy **************************************************
#define FOREACH_ENUM_EHITREGISTERDEDUPEPOLICY(op) \
	op(EHitRegisterDedupePolicy::None) \
	op(EHitRegisterDedupePolicy::OncePerAttack) \
	op(EHitRegisterDedupePolicy::CooldownPerTarget) \
	op(EHitRegisterDedupePolicy::CooldownPerHurtBox) 

enum class EHitRegisterDedupePolicy : uint8;
template<> struct TIsUEnumClass<EHitRegisterDedupePolicy> { enum { Value = true }; };
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterDedupePolicy>();
// ********** End Enum EHitRegisterDedupePolicy ****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
