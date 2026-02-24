// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/AttackAbility.h"

#ifdef COMBATCOREGASADAPTER_AttackAbility_generated_h
#error "AttackAbility.generated.h already included, missing '#pragma once' in AttackAbility.h"
#endif
#define COMBATCOREGASADAPTER_AttackAbility_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCombatAttackContext;

// ********** Begin Class UAttackAbility ***********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleCancel); \
	DECLARE_FUNCTION(execHandleConfirm); \
	DECLARE_FUNCTION(execGetAttackContext); \
	DECLARE_FUNCTION(execRequestCommitFromOrchestrator);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UAttackAbility_Statics;
COMBATCOREGASADAPTER_API UClass* Z_Construct_UClass_UAttackAbility_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttackAbility(); \
	friend struct ::Z_Construct_UClass_UAttackAbility_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCOREGASADAPTER_API UClass* ::Z_Construct_UClass_UAttackAbility_NoRegister(); \
public: \
	DECLARE_CLASS2(UAttackAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatCoreGASAdapter"), Z_Construct_UClass_UAttackAbility_NoRegister) \
	DECLARE_SERIALIZER(UAttackAbility)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAttackAbility(UAttackAbility&&) = delete; \
	UAttackAbility(const UAttackAbility&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttackAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttackAbility); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAttackAbility) \
	NO_API virtual ~UAttackAbility();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAttackAbility;

// ********** End Class UAttackAbility *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
