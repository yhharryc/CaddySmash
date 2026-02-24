// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterCollisionSubsystem.h"

#ifdef HITREGISTERCOLLISION_HitRegisterCollisionSubsystem_generated_h
#error "HitRegisterCollisionSubsystem.generated.h already included, missing '#pragma once' in HitRegisterCollisionSubsystem.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterCollisionSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UHitRegisterPipeline;
class UHitRegisterTargetingProfile;
struct FAttackRequest;
struct FHitCandidateBatch;
struct FHitRegisterContext;
struct FHitRegisterDedupeSettings;

// ********** Begin Class UHitRegisterCollisionSubsystem *******************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearAllDedupe); \
	DECLARE_FUNCTION(execClearDedupeForAttack); \
	DECLARE_FUNCTION(execFilterAndExecuteCandidates); \
	DECLARE_FUNCTION(execExecuteForCandidates); \
	DECLARE_FUNCTION(execFilterCandidatesSimple); \
	DECLARE_FUNCTION(execFilterCandidates);


struct Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterCollisionSubsystem_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterCollisionSubsystem(); \
	friend struct ::Z_Construct_UClass_UHitRegisterCollisionSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterCollisionSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterCollisionSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterCollisionSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterCollisionSubsystem)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterCollisionSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterCollisionSubsystem(UHitRegisterCollisionSubsystem&&) = delete; \
	UHitRegisterCollisionSubsystem(const UHitRegisterCollisionSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterCollisionSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterCollisionSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHitRegisterCollisionSubsystem) \
	NO_API virtual ~UHitRegisterCollisionSubsystem();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_13_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterCollisionSubsystem;

// ********** End Class UHitRegisterCollisionSubsystem *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterCollisionSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
