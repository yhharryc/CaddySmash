// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat/CombatWeaponActor.h"

#ifdef COMBATCORE_CombatWeaponActor_generated_h
#error "CombatWeaponActor.generated.h already included, missing '#pragma once' in CombatWeaponActor.h"
#endif
#define COMBATCORE_CombatWeaponActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FCombatAttackContext;

// ********** Begin Class ACombatWeaponActor *******************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHasCachedAttackContext); \
	DECLARE_FUNCTION(execClearCachedAttackContext); \
	DECLARE_FUNCTION(execGetCachedAttackContext); \
	DECLARE_FUNCTION(execClearAimTarget); \
	DECLARE_FUNCTION(execAimAtActor); \
	DECLARE_FUNCTION(execIsMotionActive); \
	DECLARE_FUNCTION(execStopMotion); \
	DECLARE_FUNCTION(execStartMotion);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ACombatWeaponActor_Statics;
COMBATCORE_API UClass* Z_Construct_UClass_ACombatWeaponActor_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACombatWeaponActor(); \
	friend struct ::Z_Construct_UClass_ACombatWeaponActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMBATCORE_API UClass* ::Z_Construct_UClass_ACombatWeaponActor_NoRegister(); \
public: \
	DECLARE_CLASS2(ACombatWeaponActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CombatCore"), Z_Construct_UClass_ACombatWeaponActor_NoRegister) \
	DECLARE_SERIALIZER(ACombatWeaponActor) \
	virtual UObject* _getUObject() const override { return const_cast<ACombatWeaponActor*>(this); }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACombatWeaponActor(ACombatWeaponActor&&) = delete; \
	ACombatWeaponActor(const ACombatWeaponActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACombatWeaponActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACombatWeaponActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACombatWeaponActor) \
	NO_API virtual ~ACombatWeaponActor();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_20_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACombatWeaponActor;

// ********** End Class ACombatWeaponActor *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatWeaponActor_h

// ********** Begin Enum EWeaponMotionType *********************************************************
#define FOREACH_ENUM_EWEAPONMOTIONTYPE(op) \
	op(EWeaponMotionType::None) \
	op(EWeaponMotionType::Thrust) 

enum class EWeaponMotionType : uint8;
template<> struct TIsUEnumClass<EWeaponMotionType> { enum { Value = true }; };
template<> COMBATCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EWeaponMotionType>();
// ********** End Enum EWeaponMotionType ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
