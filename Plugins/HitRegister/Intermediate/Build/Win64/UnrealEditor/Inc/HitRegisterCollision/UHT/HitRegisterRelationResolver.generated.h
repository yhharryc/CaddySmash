// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HitRegisterCollision/HitRegisterRelationResolver.h"

#ifdef HITREGISTERCOLLISION_HitRegisterRelationResolver_generated_h
#error "HitRegisterRelationResolver.generated.h already included, missing '#pragma once' in HitRegisterRelationResolver.h"
#endif
#define HITREGISTERCOLLISION_HitRegisterRelationResolver_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EHitRegisterRelation : uint8;

// ********** Begin Interface UHitRegisterRelationResolver *****************************************
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual EHitRegisterRelation GetRelation_Implementation(AActor* Source, AActor* Target) const { return (EHitRegisterRelation)0; }; \
	DECLARE_FUNCTION(execGetRelation);


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UHitRegisterRelationResolver_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterRelationResolver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterRelationResolver(UHitRegisterRelationResolver&&) = delete; \
	UHitRegisterRelationResolver(const UHitRegisterRelationResolver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterRelationResolver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterRelationResolver); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterRelationResolver) \
	virtual ~UHitRegisterRelationResolver() = default;


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUHitRegisterRelationResolver(); \
	friend struct ::Z_Construct_UClass_UHitRegisterRelationResolver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterRelationResolver, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterRelationResolver)


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_GENERATED_UINTERFACE_BODY() \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IHitRegisterRelationResolver() {} \
public: \
	typedef UHitRegisterRelationResolver UClassType; \
	typedef IHitRegisterRelationResolver ThisClass; \
	static EHitRegisterRelation Execute_GetRelation(const UObject* O, AActor* Source, AActor* Target); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_17_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_CALLBACK_WRAPPERS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_20_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterRelationResolver;

// ********** End Interface UHitRegisterRelationResolver *******************************************

// ********** Begin Class UHitRegisterRelationResolverAsset ****************************************
struct Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics;
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister();

#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_39_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHitRegisterRelationResolverAsset(); \
	friend struct ::Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HITREGISTERCOLLISION_API UClass* ::Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister(); \
public: \
	DECLARE_CLASS2(UHitRegisterRelationResolverAsset, UDataAsset, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/HitRegisterCollision"), Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister) \
	DECLARE_SERIALIZER(UHitRegisterRelationResolverAsset) \
	virtual UObject* _getUObject() const override { return const_cast<UHitRegisterRelationResolverAsset*>(this); }


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_39_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHitRegisterRelationResolverAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHitRegisterRelationResolverAsset(UHitRegisterRelationResolverAsset&&) = delete; \
	UHitRegisterRelationResolverAsset(const UHitRegisterRelationResolverAsset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHitRegisterRelationResolverAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHitRegisterRelationResolverAsset); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHitRegisterRelationResolverAsset) \
	NO_API virtual ~UHitRegisterRelationResolverAsset();


#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_36_PROLOG
#define FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_39_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_39_INCLASS_NO_PURE_DECLS \
	FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h_39_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHitRegisterRelationResolverAsset;

// ********** End Class UHitRegisterRelationResolverAsset ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h

// ********** Begin Enum EHitRegisterRelation ******************************************************
#define FOREACH_ENUM_EHITREGISTERRELATION(op) \
	op(EHitRegisterRelation::Ally) \
	op(EHitRegisterRelation::Enemy) \
	op(EHitRegisterRelation::Neutral) \
	op(EHitRegisterRelation::Unknown) 

enum class EHitRegisterRelation : uint8;
template<> struct TIsUEnumClass<EHitRegisterRelation> { enum { Value = true }; };
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterRelation>();
// ********** End Enum EHitRegisterRelation ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
