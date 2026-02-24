// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegister/HitRegisterInterfaces.h"

#ifdef HITREGISTERCORE_HitRegisterInterfaces_generated_h
#error "HitRegisterInterfaces.generated.h already included, missing '#pragma once' in HitRegisterInterfaces.h"
#endif
#define HITREGISTERCORE_HitRegisterInterfaces_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitRegisterContext;

// ********** Begin Interface UHitReceiver *********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnPostDamage_Implementation(FHitRegisterContext const& Context) {}; \
	virtual void OnHitConfirmed_Implementation(FHitRegisterContext const& Context) {}; \
	virtual bool ShouldAcceptHit_Implementation(FHitRegisterContext& Context) { return false; }; \
	DECLARE_FUNCTION(execOnPostDamage); \
	DECLARE_FUNCTION(execOnHitConfirmed); \
	DECLARE_FUNCTION(execShouldAcceptHit);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UHitReceiver_Statics;
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitReceiver_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitReceiver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitReceiver(UHitReceiver&&) = delete; \
	UHitReceiver(const UHitReceiver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitReceiver); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitReceiver) \
	virtual ~UHitReceiver() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUHitReceiver(); \
	friend struct ::Z_Construct_UClass_UHitReceiver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCORE_API UClass* ::Z_Construct_UClass_UHitReceiver_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitReceiver, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/HitRegisterCore"), Z_Construct_UClass_UHitReceiver_NoRegister) \
	DECLARE_SERIALIZER(UHitReceiver)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IHitReceiver() {} \
public: \
	typedef UHitReceiver UClassType; \
	typedef IHitReceiver ThisClass; \
	static void Execute_OnHitConfirmed(UObject* O, FHitRegisterContext const& Context); \
	static void Execute_OnPostDamage(UObject* O, FHitRegisterContext const& Context); \
	static bool Execute_ShouldAcceptHit(UObject* O, FHitRegisterContext& Context); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_11_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitReceiver;

// ********** End Interface UHitReceiver ***********************************************************

// ********** Begin Interface UDamageApplier *******************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ApplyDamage_Implementation(FHitRegisterContext& Context) { return false; }; \
	DECLARE_FUNCTION(execApplyDamage);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDamageApplier_Statics;
HITREGISTERCORE_API UClass* Z_Construct_UClass_UDamageApplier_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDamageApplier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDamageApplier(UDamageApplier&&) = delete; \
	UDamageApplier(const UDamageApplier&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDamageApplier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDamageApplier); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDamageApplier) \
	virtual ~UDamageApplier() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDamageApplier(); \
	friend struct ::Z_Construct_UClass_UDamageApplier_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCORE_API UClass* ::Z_Construct_UClass_UDamageApplier_NoRegister(); \
public: \
	DECLARE_CLASS2(UDamageApplier, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/HitRegisterCore"), Z_Construct_UClass_UDamageApplier_NoRegister) \
	DECLARE_SERIALIZER(UDamageApplier)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDamageApplier() {} \
public: \
	typedef UDamageApplier UClassType; \
	typedef IDamageApplier ThisClass; \
	static bool Execute_ApplyDamage(UObject* O, FHitRegisterContext& Context); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_39_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_47_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h_42_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDamageApplier;

// ********** End Interface UDamageApplier *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
