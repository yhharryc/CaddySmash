// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/AttackOrchestratorComponent.h"

#ifdef COMBATCORE_AttackOrchestratorComponent_generated_h
#error "AttackOrchestratorComponent.generated.h already included, missing '#pragma once' in AttackOrchestratorComponent.h"
#endif
#define COMBATCORE_AttackOrchestratorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCombatAttackRequest;

// ********** Begin Delegate FAttackRequestEvent ***************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_10_DELEGATE \
COMBATCORE_API void FAttackRequestEvent_DelegateWrapper(const FMulticastScriptDelegate& AttackRequestEvent, FCombatAttackRequest const& Request);


// ********** End Delegate FAttackRequestEvent *****************************************************

// ********** Begin Delegate FAttackSimpleEvent ****************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_11_DELEGATE \
COMBATCORE_API void FAttackSimpleEvent_DelegateWrapper(const FMulticastScriptDelegate& AttackSimpleEvent);


// ********** End Delegate FAttackSimpleEvent ******************************************************

// ********** Begin Class UAttackOrchestratorComponent *********************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearPendingRequest); \
	DECLARE_FUNCTION(execConsumePendingRequest); \
	DECLARE_FUNCTION(execCancelAttack); \
	DECLARE_FUNCTION(execTryCommitAttack); \
	DECLARE_FUNCTION(execCommitAttack); \
	DECLARE_FUNCTION(execBeginAttackIntent);


struct Z_Construct_UClass_UAttackOrchestratorComponent_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttackOrchestratorComponent(); \
	friend struct ::Z_Construct_UClass_UAttackOrchestratorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UAttackOrchestratorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister) \
	DECLARE_SERIALIZER(UAttackOrchestratorComponent)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAttackOrchestratorComponent(UAttackOrchestratorComponent&&) = delete; \
	UAttackOrchestratorComponent(const UAttackOrchestratorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttackOrchestratorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttackOrchestratorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAttackOrchestratorComponent) \
	NO_API virtual ~UAttackOrchestratorComponent();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_13_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAttackOrchestratorComponent;

// ********** End Class UAttackOrchestratorComponent ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_AttackOrchestratorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
