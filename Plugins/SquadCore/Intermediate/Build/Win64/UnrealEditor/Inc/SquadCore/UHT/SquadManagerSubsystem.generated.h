// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/SquadManagerSubsystem.h"

#ifdef SQUADCORE_SquadManagerSubsystem_generated_h
#error "SquadManagerSubsystem.generated.h already included, missing '#pragma once' in SquadManagerSubsystem.h"
#endif
#define SQUADCORE_SquadManagerSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UFormationAsset;
class USquadSlotAssignmentPolicy;

// ********** Begin Class USquadManagerSubsystem ***************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSlotWorldTransform); \
	DECLARE_FUNCTION(execGetSlotWorldLocation); \
	DECLARE_FUNCTION(execGetAssignedSlot); \
	DECLARE_FUNCTION(execUnregisterMember); \
	DECLARE_FUNCTION(execRegisterMember); \
	DECLARE_FUNCTION(execGetFormationLeader); \
	DECLARE_FUNCTION(execSetFormationLeader); \
	DECLARE_FUNCTION(execSetSlotAssignmentPolicy); \
	DECLARE_FUNCTION(execSetFormationAsset);


struct Z_Construct_UClass_USquadManagerSubsystem_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_USquadManagerSubsystem_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSquadManagerSubsystem(); \
	friend struct ::Z_Construct_UClass_USquadManagerSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_USquadManagerSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(USquadManagerSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_USquadManagerSubsystem_NoRegister) \
	DECLARE_SERIALIZER(USquadManagerSubsystem)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USquadManagerSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USquadManagerSubsystem(USquadManagerSubsystem&&) = delete; \
	USquadManagerSubsystem(const USquadManagerSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USquadManagerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USquadManagerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USquadManagerSubsystem) \
	NO_API virtual ~USquadManagerSubsystem();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_11_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USquadManagerSubsystem;

// ********** End Class USquadManagerSubsystem *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadManagerSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
