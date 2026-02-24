// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/LootEvaluator.h"

#ifdef SQUADCORE_LootEvaluator_generated_h
#error "LootEvaluator.generated.h already included, missing '#pragma once' in LootEvaluator.h"
#endif
#define SQUADCORE_LootEvaluator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FLootCandidate;

// ********** Begin Class ULootEvaluator ***********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEvaluateLoot);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ULootEvaluator_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_ULootEvaluator_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULootEvaluator(); \
	friend struct ::Z_Construct_UClass_ULootEvaluator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_ULootEvaluator_NoRegister(); \
public: \
	DECLARE_CLASS2(ULootEvaluator, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_ULootEvaluator_NoRegister) \
	DECLARE_SERIALIZER(ULootEvaluator)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULootEvaluator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULootEvaluator(ULootEvaluator&&) = delete; \
	ULootEvaluator(const ULootEvaluator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULootEvaluator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULootEvaluator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULootEvaluator) \
	NO_API virtual ~ULootEvaluator();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULootEvaluator;

// ********** End Class ULootEvaluator *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_LootEvaluator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
