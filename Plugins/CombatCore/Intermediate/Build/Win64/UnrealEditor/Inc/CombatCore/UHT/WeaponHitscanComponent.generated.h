// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/WeaponHitscanComponent.h"

#ifdef COMBATCORE_WeaponHitscanComponent_generated_h
#error "WeaponHitscanComponent.generated.h already included, missing '#pragma once' in WeaponHitscanComponent.h"
#endif
#define COMBATCORE_WeaponHitscanComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UWeaponHitscanComponent **************************************************
struct Z_Construct_UClass_UWeaponHitscanComponent_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponHitscanComponent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWeaponHitscanComponent(); \
	friend struct ::Z_Construct_UClass_UWeaponHitscanComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_UWeaponHitscanComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UWeaponHitscanComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_UWeaponHitscanComponent_NoRegister) \
	DECLARE_SERIALIZER(UWeaponHitscanComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UWeaponHitscanComponent*>(this); }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_11_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWeaponHitscanComponent(UWeaponHitscanComponent&&) = delete; \
	UWeaponHitscanComponent(const UWeaponHitscanComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponHitscanComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponHitscanComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWeaponHitscanComponent) \
	NO_API virtual ~UWeaponHitscanComponent();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWeaponHitscanComponent;

// ********** End Class UWeaponHitscanComponent ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponHitscanComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
