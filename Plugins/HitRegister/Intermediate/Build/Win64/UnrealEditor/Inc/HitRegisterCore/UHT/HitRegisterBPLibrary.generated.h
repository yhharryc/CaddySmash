// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegister/HitRegisterBPLibrary.h"

#ifdef HITREGISTERCORE_HitRegisterBPLibrary_generated_h
#error "HitRegisterBPLibrary.generated.h already included, missing '#pragma once' in HitRegisterBPLibrary.h"
#endif
#define HITREGISTERCORE_HitRegisterBPLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHitRegisterPipeline;
class UObject;
struct FAttackRequest;
struct FHitRegisterContext;
struct FHitResult;

// ********** Begin Class UHitRegisterBPLibrary ****************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteHitRegisterDefault); \
	DECLARE_FUNCTION(execExecuteHitRegister); \
	DECLARE_FUNCTION(execGetDefaultPipeline);


struct Z_Construct_UClass_UHitRegisterBPLibrary_Statics;
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterBPLibrary_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterBPLibrary(); \
	friend struct ::Z_Construct_UClass_UHitRegisterBPLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCORE_API UClass* ::Z_Construct_UClass_UHitRegisterBPLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HitRegisterCore"), Z_Construct_UClass_UHitRegisterBPLibrary_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterBPLibrary)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterBPLibrary(UHitRegisterBPLibrary&&) = delete; \
	UHitRegisterBPLibrary(const UHitRegisterBPLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterBPLibrary) \
	NO_API virtual ~UHitRegisterBPLibrary();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_10_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterBPLibrary;

// ********** End Class UHitRegisterBPLibrary ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterBPLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
