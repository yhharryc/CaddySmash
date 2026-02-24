// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/SquadDebugWidget.h"

#ifdef SQUADCOREDEBUGADAPTER_SquadDebugWidget_generated_h
#error "SquadDebugWidget.generated.h already included, missing '#pragma once' in SquadDebugWidget.h"
#endif
#define SQUADCOREDEBUGADAPTER_SquadDebugWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSquadDebugSnapshot;

// ********** Begin Class USquadDebugWidget ********************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateFromSnapshot);


struct Z_Construct_UClass_USquadDebugWidget_Statics;
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugWidget_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSquadDebugWidget(); \
	friend struct ::Z_Construct_UClass_USquadDebugWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCOREDEBUGADAPTER_API UClass* ::Z_Construct_UClass_USquadDebugWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(USquadDebugWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SquadCoreDebugAdapter"), Z_Construct_UClass_USquadDebugWidget_NoRegister) \
	DECLARE_SERIALIZER(USquadDebugWidget)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USquadDebugWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USquadDebugWidget(USquadDebugWidget&&) = delete; \
	USquadDebugWidget(const USquadDebugWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USquadDebugWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USquadDebugWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USquadDebugWidget) \
	NO_API virtual ~USquadDebugWidget();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_12_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USquadDebugWidget;

// ********** End Class USquadDebugWidget **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
