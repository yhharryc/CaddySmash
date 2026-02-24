// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/CombatAttackAdapter.h"

#ifdef COMBATCORE_CombatAttackAdapter_generated_h
#error "CombatAttackAdapter.generated.h already included, missing '#pragma once' in CombatAttackAdapter.h"
#endif
#define COMBATCORE_CombatAttackAdapter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAttackOrchestratorComponent;
struct FCombatAttackRequest;

// ********** Begin Interface UCombatAttackAdapter *************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void CancelAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request) {}; \
	virtual bool TryCommitAttack_Implementation(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request) { return false; }; \
	virtual bool BeginAttackIntent_Implementation(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request) { return false; }; \
	DECLARE_FUNCTION(execCancelAttack); \
	DECLARE_FUNCTION(execTryCommitAttack); \
	DECLARE_FUNCTION(execBeginAttackIntent);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UCombatAttackAdapter_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UCombatAttackAdapter_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCombatAttackAdapter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCombatAttackAdapter(UCombatAttackAdapter&&) = delete; \
	UCombatAttackAdapter(const UCombatAttackAdapter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatAttackAdapter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatAttackAdapter); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatAttackAdapter) \
	virtual ~UCombatAttackAdapter() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUCombatAttackAdapter(); \
	friend struct ::Z_Construct_UClass_UCombatAttackAdapter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UCombatAttackAdapter_NoRegister(); \
public: \
	DECLARE_CLASS2(UCombatAttackAdapter, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UCombatAttackAdapter_NoRegister) \
	DECLARE_SERIALIZER(UCombatAttackAdapter)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ICombatAttackAdapter() {} \
public: \
	typedef UCombatAttackAdapter UClassType; \
	typedef ICombatAttackAdapter ThisClass; \
	static bool Execute_BeginAttackIntent(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request); \
	static void Execute_CancelAttack(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request); \
	static bool Execute_TryCommitAttack(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_10_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCombatAttackAdapter;

// ********** End Interface UCombatAttackAdapter ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
