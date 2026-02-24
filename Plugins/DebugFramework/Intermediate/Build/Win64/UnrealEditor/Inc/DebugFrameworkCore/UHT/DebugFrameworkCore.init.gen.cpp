// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDebugFrameworkCore_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DebugFrameworkCore;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DebugFrameworkCore()
	{
		if (!Z_Registration_Info_UPackage__Script_DebugFrameworkCore.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/DebugFrameworkCore",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x51DFB2A3,
			0x3715E62E,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DebugFrameworkCore.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_DebugFrameworkCore.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DebugFrameworkCore(Z_Construct_UPackage__Script_DebugFrameworkCore, TEXT("/Script/DebugFrameworkCore"), Z_Registration_Info_UPackage__Script_DebugFrameworkCore, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x51DFB2A3, 0x3715E62E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
