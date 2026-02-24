// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/AttackProfile.h"

#ifdef COMBATCORE_AttackProfile_generated_h
#error "AttackProfile.generated.h already included, missing '#pragma once' in AttackProfile.h"
#endif
#define COMBATCORE_AttackProfile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UAttackProfile ***********************************************************
struct Z_Construct_UClass_UAttackProfile_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UAttackProfile_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttackProfile(); \
	friend struct ::Z_Construct_UClass_UAttackProfile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UAttackProfile_NoRegister(); \
public: \
	DECLARE_CLASS2(UAttackProfile, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UAttackProfile_NoRegister) \
	DECLARE_SERIALIZER(UAttackProfile)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAttackProfile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAttackProfile(UAttackProfile&&) = delete; \
	UAttackProfile(const UAttackProfile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttackProfile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttackProfile); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAttackProfile) \
	NO_API virtual ~UAttackProfile();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_10_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_13_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAttackProfile;

// ********** End Class UAttackProfile *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackProfile_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
