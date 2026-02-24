// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/SquadSlotAssignmentPolicy.h"

#ifdef SQUADCORE_SquadSlotAssignmentPolicy_generated_h
#error "SquadSlotAssignmentPolicy.generated.h already included, missing '#pragma once' in SquadSlotAssignmentPolicy.h"
#endif
#define SQUADCORE_SquadSlotAssignmentPolicy_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FSquadSlot;

// ********** Begin Class USquadSlotAssignmentPolicy ***********************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSelectSlot);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSquadSlotAssignmentPolicy(); \
	friend struct ::Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister(); \
public: \
	DECLARE_CLASS2(USquadSlotAssignmentPolicy, UDataAsset, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister) \
	DECLARE_SERIALIZER(USquadSlotAssignmentPolicy)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USquadSlotAssignmentPolicy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USquadSlotAssignmentPolicy(USquadSlotAssignmentPolicy&&) = delete; \
	USquadSlotAssignmentPolicy(const USquadSlotAssignmentPolicy&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USquadSlotAssignmentPolicy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USquadSlotAssignmentPolicy); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USquadSlotAssignmentPolicy) \
	NO_API virtual ~USquadSlotAssignmentPolicy();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USquadSlotAssignmentPolicy;

// ********** End Class USquadSlotAssignmentPolicy *************************************************

// ********** Begin Class USquadSlotAssignmentPolicy_FirstFree *************************************
struct Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSquadSlotAssignmentPolicy_FirstFree(); \
	friend struct ::Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_NoRegister(); \
public: \
	DECLARE_CLASS2(USquadSlotAssignmentPolicy_FirstFree, USquadSlotAssignmentPolicy, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_NoRegister) \
	DECLARE_SERIALIZER(USquadSlotAssignmentPolicy_FirstFree)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USquadSlotAssignmentPolicy_FirstFree(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USquadSlotAssignmentPolicy_FirstFree(USquadSlotAssignmentPolicy_FirstFree&&) = delete; \
	USquadSlotAssignmentPolicy_FirstFree(const USquadSlotAssignmentPolicy_FirstFree&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USquadSlotAssignmentPolicy_FirstFree); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USquadSlotAssignmentPolicy_FirstFree); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USquadSlotAssignmentPolicy_FirstFree) \
	NO_API virtual ~USquadSlotAssignmentPolicy_FirstFree();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_19_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_22_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USquadSlotAssignmentPolicy_FirstFree;

// ********** End Class USquadSlotAssignmentPolicy_FirstFree ***************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
