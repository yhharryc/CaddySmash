// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/CompliancePolicy.h"

#ifdef SQUADCORE_CompliancePolicy_generated_h
#error "CompliancePolicy.generated.h already included, missing '#pragma once' in CompliancePolicy.h"
#endif
#define SQUADCORE_CompliancePolicy_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSquadComplianceContext;

// ********** Begin Class UCompliancePolicy ********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShouldObeyFormation);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UCompliancePolicy_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCompliancePolicy(); \
	friend struct ::Z_Construct_UClass_UCompliancePolicy_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_UCompliancePolicy_NoRegister(); \
public: \
	DECLARE_CLASS2(UCompliancePolicy, UDataAsset, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_UCompliancePolicy_NoRegister) \
	DECLARE_SERIALIZER(UCompliancePolicy)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompliancePolicy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCompliancePolicy(UCompliancePolicy&&) = delete; \
	UCompliancePolicy(const UCompliancePolicy&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompliancePolicy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompliancePolicy); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompliancePolicy) \
	NO_API virtual ~UCompliancePolicy();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCompliancePolicy;

// ********** End Class UCompliancePolicy **********************************************************

// ********** Begin Class UCompliancePolicy_Always *************************************************
struct Z_Construct_UClass_UCompliancePolicy_Always_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_UCompliancePolicy_Always_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCompliancePolicy_Always(); \
	friend struct ::Z_Construct_UClass_UCompliancePolicy_Always_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_UCompliancePolicy_Always_NoRegister(); \
public: \
	DECLARE_CLASS2(UCompliancePolicy_Always, UCompliancePolicy, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_UCompliancePolicy_Always_NoRegister) \
	DECLARE_SERIALIZER(UCompliancePolicy_Always)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompliancePolicy_Always(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCompliancePolicy_Always(UCompliancePolicy_Always&&) = delete; \
	UCompliancePolicy_Always(const UCompliancePolicy_Always&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompliancePolicy_Always); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompliancePolicy_Always); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompliancePolicy_Always) \
	NO_API virtual ~UCompliancePolicy_Always();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_19_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_22_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCompliancePolicy_Always;

// ********** End Class UCompliancePolicy_Always ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_CompliancePolicy_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
