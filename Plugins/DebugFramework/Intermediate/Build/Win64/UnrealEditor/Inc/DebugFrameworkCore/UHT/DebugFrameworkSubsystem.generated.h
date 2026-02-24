// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DebugFramework/DebugFrameworkSubsystem.h"

#ifdef DEBUGFRAMEWORKCORE_DebugFrameworkSubsystem_generated_h
#error "DebugFrameworkSubsystem.generated.h already included, missing '#pragma once' in DebugFrameworkSubsystem.h"
#endif
#define DEBUGFRAMEWORKCORE_DebugFrameworkSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FDebugFrameworkInputChord;

// ********** Begin Class UDebugFrameworkSubsystem *************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShowAllPanels); \
	DECLARE_FUNCTION(execIsPanelVisible); \
	DECLARE_FUNCTION(execSetPanelVisible); \
	DECLARE_FUNCTION(execResetPanelLayouts); \
	DECLARE_FUNCTION(execGetToggleVisibilityChord); \
	DECLARE_FUNCTION(execSetToggleVisibilityChord); \
	DECLARE_FUNCTION(execIsVisible); \
	DECLARE_FUNCTION(execToggleVisible); \
	DECLARE_FUNCTION(execSetVisible); \
	DECLARE_FUNCTION(execUnregisterProvider); \
	DECLARE_FUNCTION(execRegisterProvider);


struct Z_Construct_UClass_UDebugFrameworkSubsystem_Statics;
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSubsystem_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDebugFrameworkSubsystem(); \
	friend struct ::Z_Construct_UClass_UDebugFrameworkSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DEBUGFRAMEWORKCORE_API UClass* ::Z_Construct_UClass_UDebugFrameworkSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UDebugFrameworkSubsystem, UTickableWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DebugFrameworkCore"), Z_Construct_UClass_UDebugFrameworkSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UDebugFrameworkSubsystem)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDebugFrameworkSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDebugFrameworkSubsystem(UDebugFrameworkSubsystem&&) = delete; \
	UDebugFrameworkSubsystem(const UDebugFrameworkSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDebugFrameworkSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDebugFrameworkSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDebugFrameworkSubsystem) \
	NO_API virtual ~UDebugFrameworkSubsystem();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_14_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDebugFrameworkSubsystem;

// ********** End Class UDebugFrameworkSubsystem ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
