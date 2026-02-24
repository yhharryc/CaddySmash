// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DebugFramework/DebugFrameworkProvider.h"

#ifdef DEBUGFRAMEWORKCORE_DebugFrameworkProvider_generated_h
#error "DebugFrameworkProvider.generated.h already included, missing '#pragma once' in DebugFrameworkProvider.h"
#endif
#define DEBUGFRAMEWORKCORE_DebugFrameworkProvider_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDebugFrameworkPanelRow;

// ********** Begin Interface UDebugFrameworkProvider **********************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GatherDebugRows_Implementation(TArray<FDebugFrameworkPanelRow>& OutRows) const {}; \
	virtual int32 GetDebugSortOrder_Implementation() const { return 0; }; \
	virtual FText GetDebugPanelTitle_Implementation() const { return FText::GetEmpty(); }; \
	virtual FName GetDebugPanelId_Implementation() const { return NAME_None; }; \
	DECLARE_FUNCTION(execGatherDebugRows); \
	DECLARE_FUNCTION(execGetDebugSortOrder); \
	DECLARE_FUNCTION(execGetDebugToolTitle); \
	DECLARE_FUNCTION(execGetDebugToolId); \
	DECLARE_FUNCTION(execGetDebugPanelTitle); \
	DECLARE_FUNCTION(execGetDebugPanelId);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDebugFrameworkProvider_Statics;
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkProvider_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDebugFrameworkProvider(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDebugFrameworkProvider(UDebugFrameworkProvider&&) = delete; \
	UDebugFrameworkProvider(const UDebugFrameworkProvider&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDebugFrameworkProvider); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDebugFrameworkProvider); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDebugFrameworkProvider) \
	virtual ~UDebugFrameworkProvider() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDebugFrameworkProvider(); \
	friend struct ::Z_Construct_UClass_UDebugFrameworkProvider_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DEBUGFRAMEWORKCORE_API UClass* ::Z_Construct_UClass_UDebugFrameworkProvider_NoRegister(); \
public: \
	DECLARE_CLASS2(UDebugFrameworkProvider, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/DebugFrameworkCore"), Z_Construct_UClass_UDebugFrameworkProvider_NoRegister) \
	DECLARE_SERIALIZER(UDebugFrameworkProvider)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDebugFrameworkProvider() {} \
public: \
	typedef UDebugFrameworkProvider UClassType; \
	typedef IDebugFrameworkProvider ThisClass; \
	static void Execute_GatherDebugRows(const UObject* O, TArray<FDebugFrameworkPanelRow>& OutRows); \
	static FName Execute_GetDebugPanelId(const UObject* O); \
	static FText Execute_GetDebugPanelTitle(const UObject* O); \
	static int32 Execute_GetDebugSortOrder(const UObject* O); \
	static FName Execute_GetDebugToolId(const UObject* O); \
	static FText Execute_GetDebugToolTitle(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDebugFrameworkProvider;

// ********** End Interface UDebugFrameworkProvider ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkProvider_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
