// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/WeaponExecutor.h"

#ifdef COMBATCORE_WeaponExecutor_generated_h
#error "WeaponExecutor.generated.h already included, missing '#pragma once' in WeaponExecutor.h"
#endif
#define COMBATCORE_WeaponExecutor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCombatAttackContext;

// ********** Begin Interface UWeaponExecutor ******************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ExecuteAttack_Implementation(FCombatAttackContext& Context) {}; \
	virtual bool CanExecuteAttack_Implementation(FCombatAttackContext& Context) { return false; }; \
	DECLARE_FUNCTION(execExecuteAttack); \
	DECLARE_FUNCTION(execCanExecuteAttack);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UWeaponExecutor_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponExecutor_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWeaponExecutor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWeaponExecutor(UWeaponExecutor&&) = delete; \
	UWeaponExecutor(const UWeaponExecutor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponExecutor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponExecutor); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWeaponExecutor) \
	virtual ~UWeaponExecutor() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUWeaponExecutor(); \
	friend struct ::Z_Construct_UClass_UWeaponExecutor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UWeaponExecutor_NoRegister(); \
public: \
	DECLARE_CLASS2(UWeaponExecutor, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UWeaponExecutor_NoRegister) \
	DECLARE_SERIALIZER(UWeaponExecutor)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IWeaponExecutor() {} \
public: \
	typedef UWeaponExecutor UClassType; \
	typedef IWeaponExecutor ThisClass; \
	static bool Execute_CanExecuteAttack(UObject* O, FCombatAttackContext& Context); \
	static void Execute_ExecuteAttack(UObject* O, FCombatAttackContext& Context); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWeaponExecutor;

// ********** End Interface UWeaponExecutor ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
