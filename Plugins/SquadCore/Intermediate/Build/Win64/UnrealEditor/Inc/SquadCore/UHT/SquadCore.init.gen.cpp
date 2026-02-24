// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSquadCore_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SquadCore;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SquadCore()
	{
		if (!Z_Registration_Info_UPackage__Script_SquadCore.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/SquadCore",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0xC88508D5,
			0x8CD98248,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SquadCore.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_SquadCore.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SquadCore(Z_Construct_UPackage__Script_SquadCore, TEXT("/Script/SquadCore"), Z_Registration_Info_UPackage__Script_SquadCore, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC88508D5, 0x8CD98248));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
