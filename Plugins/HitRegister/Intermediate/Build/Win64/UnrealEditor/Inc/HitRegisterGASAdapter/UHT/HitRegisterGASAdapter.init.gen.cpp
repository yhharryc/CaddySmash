// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHitRegisterGASAdapter_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	HITREGISTERGASADAPTER_API UFunction* Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_HitRegisterGASAdapter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_HitRegisterGASAdapter()
	{
		if (!Z_Registration_Info_UPackage__Script_HitRegisterGASAdapter.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_HitRegisterGASAdapter_HitRegisterContextEvent__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/HitRegisterGASAdapter",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xF4D0C342,
			0x383DAB55,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_HitRegisterGASAdapter.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_HitRegisterGASAdapter.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_HitRegisterGASAdapter(Z_Construct_UPackage__Script_HitRegisterGASAdapter, TEXT("/Script/HitRegisterGASAdapter"), Z_Registration_Info_UPackage__Script_HitRegisterGASAdapter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF4D0C342, 0x383DAB55));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
