// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/FormationAsset.h"

#ifdef SQUADCORE_FormationAsset_generated_h
#error "FormationAsset.generated.h already included, missing '#pragma once' in FormationAsset.h"
#endif
#define SQUADCORE_FormationAsset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UFormationAsset **********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSlotOffset);


struct Z_Construct_UClass_UFormationAsset_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_UFormationAsset_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFormationAsset(); \
	friend struct ::Z_Construct_UClass_UFormationAsset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_UFormationAsset_NoRegister(); \
public: \
	DECLARE_CLASS2(UFormationAsset, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_UFormationAsset_NoRegister) \
	DECLARE_SERIALIZER(UFormationAsset)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFormationAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UFormationAsset(UFormationAsset&&) = delete; \
	UFormationAsset(const UFormationAsset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFormationAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFormationAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFormationAsset) \
	NO_API virtual ~UFormationAsset();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UFormationAsset;

// ********** End Class UFormationAsset ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
