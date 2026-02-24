// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DebugFramework/DebugFrameworkUserSettings.h"

#ifdef DEBUGFRAMEWORKCORE_DebugFrameworkUserSettings_generated_h
#error "DebugFrameworkUserSettings.generated.h already included, missing '#pragma once' in DebugFrameworkUserSettings.h"
#endif
#define DEBUGFRAMEWORKCORE_DebugFrameworkUserSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDebugFrameworkUserSettings **********************************************
struct Z_Construct_UClass_UDebugFrameworkUserSettings_Statics;
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkUserSettings_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDebugFrameworkUserSettings(); \
	friend struct ::Z_Construct_UClass_UDebugFrameworkUserSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DEBUGFRAMEWORKCORE_API UClass* ::Z_Construct_UClass_UDebugFrameworkUserSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UDebugFrameworkUserSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/DebugFrameworkCore"), Z_Construct_UClass_UDebugFrameworkUserSettings_NoRegister) \
	DECLARE_SERIALIZER(UDebugFrameworkUserSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("GameUserSettings");} \



#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDebugFrameworkUserSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDebugFrameworkUserSettings(UDebugFrameworkUserSettings&&) = delete; \
	UDebugFrameworkUserSettings(const UDebugFrameworkUserSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDebugFrameworkUserSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDebugFrameworkUserSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDebugFrameworkUserSettings) \
	NO_API virtual ~UDebugFrameworkUserSettings();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_8_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDebugFrameworkUserSettings;

// ********** End Class UDebugFrameworkUserSettings ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkUserSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
