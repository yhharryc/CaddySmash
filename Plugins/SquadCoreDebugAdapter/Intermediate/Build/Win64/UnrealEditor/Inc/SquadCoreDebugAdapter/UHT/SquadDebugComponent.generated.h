// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SquadCore/SquadDebugComponent.h"

#ifdef SQUADCOREDEBUGADAPTER_SquadDebugComponent_generated_h
#error "SquadDebugComponent.generated.h already included, missing '#pragma once' in SquadDebugComponent.h"
#endif
#define SQUADCOREDEBUGADAPTER_SquadDebugComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSquadDebugSnapshot;

// ********** Begin ScriptStruct FSquadDebugSnapshot ***********************************************
struct Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics;
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_15_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSquadDebugSnapshot_Statics; \
	SQUADCOREDEBUGADAPTER_API static class UScriptStruct* StaticStruct();


struct FSquadDebugSnapshot;
// ********** End ScriptStruct FSquadDebugSnapshot *************************************************

// ********** Begin Class USquadDebugComponent *****************************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSnapshot);


struct Z_Construct_UClass_USquadDebugComponent_Statics;
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_USquadDebugComponent_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSquadDebugComponent(); \
	friend struct ::Z_Construct_UClass_USquadDebugComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SQUADCOREDEBUGADAPTER_API UClass* ::Z_Construct_UClass_USquadDebugComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(USquadDebugComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SquadCoreDebugAdapter"), Z_Construct_UClass_USquadDebugComponent_NoRegister) \
	DECLARE_SERIALIZER(USquadDebugComponent) \
	virtual UObject* _getUObject() const override { return const_cast<USquadDebugComponent*>(this); }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	USquadDebugComponent(USquadDebugComponent&&) = delete; \
	USquadDebugComponent(const USquadDebugComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USquadDebugComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USquadDebugComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USquadDebugComponent) \
	NO_API virtual ~USquadDebugComponent();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_78_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h_81_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USquadDebugComponent;

// ********** End Class USquadDebugComponent *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
