// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegister/HitRegisterNode.h"

#ifdef HITREGISTERCORE_HitRegisterNode_generated_h
#error "HitRegisterNode.generated.h already included, missing '#pragma once' in HitRegisterNode.h"
#endif
#define HITREGISTERCORE_HitRegisterNode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EHitNodeResult : uint8;
struct FHitRegisterContext;

// ********** Begin Class UHitRegisterNode *********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecute);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UHitRegisterNode_Statics;
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterNode(); \
	friend struct ::Z_Construct_UClass_UHitRegisterNode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCORE_API UClass* ::Z_Construct_UClass_UHitRegisterNode_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterNode, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/HitRegisterCore"), Z_Construct_UClass_UHitRegisterNode_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterNode)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterNode(UHitRegisterNode&&) = delete; \
	UHitRegisterNode(const UHitRegisterNode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterNode); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterNode) \
	NO_API virtual ~UHitRegisterNode();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterNode;

// ********** End Class UHitRegisterNode ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
