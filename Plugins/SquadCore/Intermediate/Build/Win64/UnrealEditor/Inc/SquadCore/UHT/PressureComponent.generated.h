// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/PressureComponent.h"

#ifdef SQUADCORE_PressureComponent_generated_h
#error "PressureComponent.generated.h already included, missing '#pragma once' in PressureComponent.h"
#endif
#define SQUADCORE_PressureComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPressureComponent *******************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdatePressure);


struct Z_Construct_UClass_UPressureComponent_Statics;
SQUADCORE_API UClass* Z_Construct_UClass_UPressureComponent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPressureComponent(); \
	friend struct ::Z_Construct_UClass_UPressureComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCORE_API UClass* ::Z_Construct_UClass_UPressureComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPressureComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SquadCore"), Z_Construct_UClass_UPressureComponent_NoRegister) \
	DECLARE_SERIALIZER(UPressureComponent)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPressureComponent(UPressureComponent&&) = delete; \
	UPressureComponent(const UPressureComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPressureComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPressureComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPressureComponent) \
	NO_API virtual ~UPressureComponent();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_9_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPressureComponent;

// ********** End Class UPressureComponent *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_PressureComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
