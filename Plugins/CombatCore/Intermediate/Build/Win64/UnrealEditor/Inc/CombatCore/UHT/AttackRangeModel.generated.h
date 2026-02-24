// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/AttackRangeModel.h"

#ifdef COMBATCORE_AttackRangeModel_generated_h
#error "AttackRangeModel.generated.h already included, missing '#pragma once' in AttackRangeModel.h"
#endif
#define COMBATCORE_AttackRangeModel_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCombatAttackContext;
struct FCombatAttackExecutionParams;

// ********** Begin Class UAttackRangeModel ********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execBuildExecutionParams);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UAttackRangeModel_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UAttackRangeModel_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttackRangeModel(); \
	friend struct ::Z_Construct_UClass_UAttackRangeModel_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UAttackRangeModel_NoRegister(); \
public: \
	DECLARE_CLASS2(UAttackRangeModel, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UAttackRangeModel_NoRegister) \
	DECLARE_SERIALIZER(UAttackRangeModel)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAttackRangeModel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAttackRangeModel(UAttackRangeModel&&) = delete; \
	UAttackRangeModel(const UAttackRangeModel&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttackRangeModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttackRangeModel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAttackRangeModel) \
	NO_API virtual ~UAttackRangeModel();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_10_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAttackRangeModel;

// ********** End Class UAttackRangeModel **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackRangeModel_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
