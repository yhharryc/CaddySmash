// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegister/HitRegisterSubsystem.h"

#ifdef HITREGISTERCORE_HitRegisterSubsystem_generated_h
#error "HitRegisterSubsystem.generated.h already included, missing '#pragma once' in HitRegisterSubsystem.h"
#endif
#define HITREGISTERCORE_HitRegisterSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHitRegisterPipeline;
struct FAttackRequest;
struct FHitRegisterContext;
struct FHitResult;

// ********** Begin Class UHitRegisterSubsystem ****************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteHitRegister);


struct Z_Construct_UClass_UHitRegisterSubsystem_Statics;
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterSubsystem_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterSubsystem(); \
	friend struct ::Z_Construct_UClass_UHitRegisterSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCORE_API UClass* ::Z_Construct_UClass_UHitRegisterSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HitRegisterCore"), Z_Construct_UClass_UHitRegisterSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterSubsystem)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterSubsystem(UHitRegisterSubsystem&&) = delete; \
	UHitRegisterSubsystem(const UHitRegisterSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHitRegisterSubsystem) \
	NO_API virtual ~UHitRegisterSubsystem();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_9_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterSubsystem;

// ********** End Class UHitRegisterSubsystem ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
