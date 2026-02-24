// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatCore_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	COMBATCORE_API UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature();
	COMBATCORE_API UFunction* Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CombatCore;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CombatCore()
	{
		if (!Z_Registration_Info_UPackage__Script_CombatCore.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_CombatCore_AttackRequestEvent__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_CombatCore_AttackSimpleEvent__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/CombatCore",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x31C5EF16,
			0x74E1ECA8,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CombatCore.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_CombatCore.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CombatCore(Z_Construct_UPackage__Script_CombatCore, TEXT("/Script/CombatCore"), Z_Registration_Info_UPackage__Script_CombatCore, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x31C5EF16, 0x74E1ECA8));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
