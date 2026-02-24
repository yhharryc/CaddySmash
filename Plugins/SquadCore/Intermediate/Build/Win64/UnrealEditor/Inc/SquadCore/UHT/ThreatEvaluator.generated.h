// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/ThreatEvaluator.h"

#ifdef SQUADCORE_ThreatEvaluator_generated_h
#error "ThreatEvaluator.generated.h already included, missing '#pragma once' in ThreatEvaluator.h"
#endif
#define SQUADCORE_ThreatEvaluator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FThreatCandidate;

// ********** Begin Class UThreatEvaluator *********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEvaluateThreats);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UThreatEvaluator_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_UThreatEvaluator_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUThreatEvaluator(); \
	friend struct ::Z_Construct_UClass_UThreatEvaluator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_UThreatEvaluator_NoRegister(); \
public: \
	DECLARE_CLASS2(UThreatEvaluator, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_UThreatEvaluator_NoRegister) \
	DECLARE_SERIALIZER(UThreatEvaluator)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UThreatEvaluator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UThreatEvaluator(UThreatEvaluator&&) = delete; \
	UThreatEvaluator(const UThreatEvaluator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UThreatEvaluator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UThreatEvaluator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UThreatEvaluator) \
	NO_API virtual ~UThreatEvaluator();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UThreatEvaluator;

// ********** End Class UThreatEvaluator ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_ThreatEvaluator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
