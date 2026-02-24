// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DebugFramework/DebugFrameworkSettings.h"

#ifdef DEBUGFRAMEWORKCORE_DebugFrameworkSettings_generated_h
#error "DebugFrameworkSettings.generated.h already included, missing '#pragma once' in DebugFrameworkSettings.h"
#endif
#define DEBUGFRAMEWORKCORE_DebugFrameworkSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDebugFrameworkSettings;

// ********** Begin ScriptStruct FDebugFrameworkInputChord *****************************************
struct Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_11_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDebugFrameworkInputChord_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDebugFrameworkInputChord;
// ********** End ScriptStruct FDebugFrameworkInputChord *******************************************

// ********** Begin Class UDebugFrameworkSettings **************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGet);


struct Z_Construct_UClass_UDebugFrameworkSettings_Statics;
DEBUGFRAMEWORKCORE_API UClass* Z_Construct_UClass_UDebugFrameworkSettings_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDebugFrameworkSettings(); \
	friend struct ::Z_Construct_UClass_UDebugFrameworkSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DEBUGFRAMEWORKCORE_API UClass* ::Z_Construct_UClass_UDebugFrameworkSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UDebugFrameworkSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/DebugFrameworkCore"), Z_Construct_UClass_UDebugFrameworkSettings_NoRegister) \
	DECLARE_SERIALIZER(UDebugFrameworkSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDebugFrameworkSettings(UDebugFrameworkSettings&&) = delete; \
	UDebugFrameworkSettings(const UDebugFrameworkSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDebugFrameworkSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDebugFrameworkSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDebugFrameworkSettings) \
	NO_API virtual ~UDebugFrameworkSettings();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_42_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDebugFrameworkSettings;

// ********** End Class UDebugFrameworkSettings ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_DebugFramework_Source_DebugFrameworkCore_Public_DebugFramework_DebugFrameworkSettings_h

// ********** Begin Enum EDebugFrameworkPlayerControllerPolicy *************************************
#define FOREACH_ENUM_EDEBUGFRAMEWORKPLAYERCONTROLLERPOLICY(op) \
	op(EDebugFrameworkPlayerControllerPolicy::FirstLocal) \
	op(EDebugFrameworkPlayerControllerPolicy::PrimaryLocalPlayer) \
	op(EDebugFrameworkPlayerControllerPolicy::ExplicitLocalPlayerIndex) 

enum class EDebugFrameworkPlayerControllerPolicy : uint8;
template<> struct TIsUEnumClass<EDebugFrameworkPlayerControllerPolicy> { enum { Value = true }; };
template<> DEBUGFRAMEWORKCORE_NON_ATTRIBUTED_API UEnum* StaticEnum<EDebugFrameworkPlayerControllerPolicy>();
// ********** End Enum EDebugFrameworkPlayerControllerPolicy ***************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
