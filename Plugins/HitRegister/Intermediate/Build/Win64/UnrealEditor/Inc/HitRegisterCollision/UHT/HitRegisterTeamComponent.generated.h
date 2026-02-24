// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterTeamComponent.h"

#ifdef HITREGISTERCOLLISION_HitRegisterTeamComponent_generated_h
#error "HitRegisterTeamComponent.generated.h already included, missing '#pragma once' in HitRegisterTeamComponent.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterTeamComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UHitRegisterTeamComponent ************************************************
struct Z_Construct_UClass_UHitRegisterTeamComponent_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamComponent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterTeamComponent(); \
	friend struct ::Z_Construct_UClass_UHitRegisterTeamComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterTeamComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterTeamComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterTeamComponent_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterTeamComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UHitRegisterTeamComponent*>(this); }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterTeamComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterTeamComponent(UHitRegisterTeamComponent&&) = delete; \
	UHitRegisterTeamComponent(const UHitRegisterTeamComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterTeamComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterTeamComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterTeamComponent) \
	NO_API virtual ~UHitRegisterTeamComponent();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_9_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterTeamComponent;

// ********** End Class UHitRegisterTeamComponent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
