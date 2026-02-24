// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterTeamInterface.h"

#ifdef HITREGISTERCOLLISION_HitRegisterTeamInterface_generated_h
#error "HitRegisterTeamInterface.generated.h already included, missing '#pragma once' in HitRegisterTeamInterface.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterTeamInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface UHitRegisterTeamAgent ************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual int32 GetTeamId_Implementation() const { return 0; }; \
	DECLARE_FUNCTION(execGetTeamId);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UHitRegisterTeamAgent_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterTeamAgent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterTeamAgent(UHitRegisterTeamAgent&&) = delete; \
	UHitRegisterTeamAgent(const UHitRegisterTeamAgent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterTeamAgent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterTeamAgent); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterTeamAgent) \
	virtual ~UHitRegisterTeamAgent() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUHitRegisterTeamAgent(); \
	friend struct ::Z_Construct_UClass_UHitRegisterTeamAgent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterTeamAgent, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterTeamAgent)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IHitRegisterTeamAgent() {} \
public: \
	typedef UHitRegisterTeamAgent UClassType; \
	typedef IHitRegisterTeamAgent ThisClass; \
	static int32 Execute_GetTeamId(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_7_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h_10_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterTeamAgent;

// ********** End Interface UHitRegisterTeamAgent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
