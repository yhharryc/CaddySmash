// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterTargetingProfile.h"

#ifdef HITREGISTERCOLLISION_HitRegisterTargetingProfile_generated_h
#error "HitRegisterTargetingProfile.generated.h already included, missing '#pragma once' in HitRegisterTargetingProfile.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterTargetingProfile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UHitRegisterTargetingProfile *********************************************
struct Z_Construct_UClass_UHitRegisterTargetingProfile_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterTargetingProfile(); \
	friend struct ::Z_Construct_UClass_UHitRegisterTargetingProfile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterTargetingProfile, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterTargetingProfile)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterTargetingProfile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterTargetingProfile(UHitRegisterTargetingProfile&&) = delete; \
	UHitRegisterTargetingProfile(const UHitRegisterTargetingProfile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterTargetingProfile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterTargetingProfile); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterTargetingProfile) \
	NO_API virtual ~UHitRegisterTargetingProfile();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_25_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_28_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterTargetingProfile;

// ********** End Class UHitRegisterTargetingProfile ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTargetingProfile_h

// ********** Begin Enum EHitTargetMode ************************************************************
#define FOREACH_ENUM_EHITTARGETMODE(op) \
	op(EHitTargetMode::All) \
	op(EHitTargetMode::AllExceptSelf) \
	op(EHitTargetMode::AlliesOnly) \
	op(EHitTargetMode::EnemiesOnly) \
	op(EHitTargetMode::AlliesExceptSelf) \
	op(EHitTargetMode::SelfOnly) 

enum class EHitTargetMode : uint8;
template<> struct TIsUEnumClass<EHitTargetMode> { enum { Value = true }; };
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitTargetMode>();
// ********** End Enum EHitTargetMode **************************************************************

// ********** Begin Enum EHitTargetUnknownPolicy ***************************************************
#define FOREACH_ENUM_EHITTARGETUNKNOWNPOLICY(op) \
	op(EHitTargetUnknownPolicy::Allow) \
	op(EHitTargetUnknownPolicy::Reject) 

enum class EHitTargetUnknownPolicy : uint8;
template<> struct TIsUEnumClass<EHitTargetUnknownPolicy> { enum { Value = true }; };
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitTargetUnknownPolicy>();
// ********** End Enum EHitTargetUnknownPolicy *****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
