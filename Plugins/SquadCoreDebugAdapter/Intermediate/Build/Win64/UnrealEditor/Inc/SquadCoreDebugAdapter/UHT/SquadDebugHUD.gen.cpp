// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadDebugHUD.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadDebugHUD() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_ASquadDebugHUD();
SQUADCOREDEBUGADAPTER_API UClass* Z_Construct_UClass_ASquadDebugHUD_NoRegister();
UPackage* Z_Construct_UPackage__Script_SquadCoreDebugAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASquadDebugHUD ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASquadDebugHUD;
UClass* ASquadDebugHUD::GetPrivateStaticClass()
{
	using TClass = ASquadDebugHUD;
	if (!Z_Registration_Info_UClass_ASquadDebugHUD.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadDebugHUD"),
			Z_Registration_Info_UClass_ASquadDebugHUD.InnerSingleton,
			StaticRegisterNativesASquadDebugHUD,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASquadDebugHUD.InnerSingleton;
}
UClass* Z_Construct_UClass_ASquadDebugHUD_NoRegister()
{
	return ASquadDebugHUD::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASquadDebugHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "SquadCore/SquadDebugHUD.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxEntries_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineHeight_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "Category", "Squad|Debug" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadDebugHUD.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ASquadDebugHUD constinit property declarations ***************************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxEntries;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineHeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASquadDebugHUD constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASquadDebugHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASquadDebugHUD_Statics

// ********** Begin Class ASquadDebugHUD Property Definitions **************************************
void Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((ASquadDebugHUD*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASquadDebugHUD), &Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_MaxEntries = { "MaxEntries", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASquadDebugHUD, MaxEntries), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxEntries_MetaData), NewProp_MaxEntries_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_LineHeight = { "LineHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASquadDebugHUD, LineHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineHeight_MetaData), NewProp_LineHeight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASquadDebugHUD, TextColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASquadDebugHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_MaxEntries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_LineHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASquadDebugHUD_Statics::NewProp_TextColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASquadDebugHUD_Statics::PropPointers) < 2048);
// ********** End Class ASquadDebugHUD Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_ASquadDebugHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCoreDebugAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASquadDebugHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASquadDebugHUD_Statics::ClassParams = {
	&ASquadDebugHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASquadDebugHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASquadDebugHUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASquadDebugHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_ASquadDebugHUD_Statics::Class_MetaDataParams)
};
void ASquadDebugHUD::StaticRegisterNativesASquadDebugHUD()
{
}
UClass* Z_Construct_UClass_ASquadDebugHUD()
{
	if (!Z_Registration_Info_UClass_ASquadDebugHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASquadDebugHUD.OuterSingleton, Z_Construct_UClass_ASquadDebugHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASquadDebugHUD.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASquadDebugHUD);
ASquadDebugHUD::~ASquadDebugHUD() {}
// ********** End Class ASquadDebugHUD *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugHUD_h__Script_SquadCoreDebugAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASquadDebugHUD, ASquadDebugHUD::StaticClass, TEXT("ASquadDebugHUD"), &Z_Registration_Info_UClass_ASquadDebugHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASquadDebugHUD), 60227776U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugHUD_h__Script_SquadCoreDebugAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugHUD_h__Script_SquadCoreDebugAdapter_1356188814{
	TEXT("/Script/SquadCoreDebugAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugHUD_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCoreDebugAdapter_Source_SquadCoreDebugAdapter_Public_SquadCore_SquadDebugHUD_h__Script_SquadCoreDebugAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
