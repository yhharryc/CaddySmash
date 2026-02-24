// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterGAS/HitRegisterGASDamageableComponent.h"

#ifdef HITREGISTERGASADAPTER_HitRegisterGASDamageableComponent_generated_h
#error "HitRegisterGASDamageableComponent.generated.h already included, missing '#pragma once' in HitRegisterGASDamageableComponent.h"
#endif
#define HITREGISTERGASADAPTER_HitRegisterGASDamageableComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitRegisterContext;

// ********** Begin Delegate FHitRegisterContextEvent **********************************************
#define FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_11_DELEGATE \
HITREGISTERGASADAPTER_API void FHitRegisterContextEvent_DelegateWrapper(const FMulticastScriptDelegate& HitRegisterContextEvent, FHitRegisterContext const& Context);


// ********** End Delegate FHitRegisterContextEvent ************************************************

// ********** Begin Class UHitRegisterGASDamageableComponent ***************************************
struct Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics;
HITREGISTERGASADAPTER_API UClass* Z_Construct_UClass_UHitRegisterGASDamageableComponent_NoRegister();

#define FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterGASDamageableComponent(); \
	friend struct ::Z_Construct_UClass_UHitRegisterGASDamageableComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERGASADAPTER_API UClass* ::Z_Construct_UClass_UHitRegisterGASDamageableComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterGASDamageableComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HitRegisterGASAdapter"), Z_Construct_UClass_UHitRegisterGASDamageableComponent_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterGASDamageableComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UHitRegisterGASDamageableComponent*>(this); }


#define FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterGASDamageableComponent(UHitRegisterGASDamageableComponent&&) = delete; \
	UHitRegisterGASDamageableComponent(const UHitRegisterGASDamageableComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterGASDamageableComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterGASDamageableComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHitRegisterGASDamageableComponent) \
	NO_API virtual ~UHitRegisterGASDamageableComponent();


#define FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_17_PROLOG
#define FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_20_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterGASDamageableComponent;

// ********** End Class UHitRegisterGASDamageableComponent *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_GroupSurvivor_Plugins_HitRegister_Source_HitRegisterGASAdapter_Public_HitRegisterGAS_HitRegisterGASDamageableComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
