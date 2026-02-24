// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/AttackAbility.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAttackAbility() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext();
COMBATCOREGASADAPTER_API UClass* Z_Construct_UClass_UAttackAbility();
COMBATCOREGASADAPTER_API UClass* Z_Construct_UClass_UAttackAbility_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_CombatCoreGASAdapter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAttackAbility Function GetAttackContext *********************************
struct Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics
{
	struct AttackAbility_eventGetAttackContext_Parms
	{
		FCombatAttackContext OutContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAttackContext constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAttackContext constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAttackContext Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_OutContext = { "OutContext", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackAbility_eventGetAttackContext_Parms, OutContext), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(0, nullptr) }; // 829964288
void Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AttackAbility_eventGetAttackContext_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AttackAbility_eventGetAttackContext_Parms), &Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_OutContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::PropPointers) < 2048);
// ********** End Function GetAttackContext Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackAbility, nullptr, "GetAttackContext", 	Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::AttackAbility_eventGetAttackContext_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::AttackAbility_eventGetAttackContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackAbility_GetAttackContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackAbility_GetAttackContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackAbility::execGetAttackContext)
{
	P_GET_STRUCT_REF(FCombatAttackContext,Z_Param_Out_OutContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAttackContext(Z_Param_Out_OutContext);
	P_NATIVE_END;
}
// ********** End Class UAttackAbility Function GetAttackContext ***********************************

// ********** Begin Class UAttackAbility Function HandleCancel *************************************
struct Z_Construct_UFunction_UAttackAbility_HandleCancel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCancel constinit property declarations **************************
// ********** End Function HandleCancel constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackAbility_HandleCancel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackAbility, nullptr, "HandleCancel", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_HandleCancel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackAbility_HandleCancel_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackAbility_HandleCancel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackAbility_HandleCancel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackAbility::execHandleCancel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCancel();
	P_NATIVE_END;
}
// ********** End Class UAttackAbility Function HandleCancel ***************************************

// ********** Begin Class UAttackAbility Function HandleConfirm ************************************
struct Z_Construct_UFunction_UAttackAbility_HandleConfirm_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleConfirm constinit property declarations *************************
// ********** End Function HandleConfirm constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackAbility_HandleConfirm_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackAbility, nullptr, "HandleConfirm", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_HandleConfirm_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackAbility_HandleConfirm_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UAttackAbility_HandleConfirm()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackAbility_HandleConfirm_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackAbility::execHandleConfirm)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleConfirm();
	P_NATIVE_END;
}
// ********** End Class UAttackAbility Function HandleConfirm **************************************

// ********** Begin Class UAttackAbility Function OnAttackContextReady *****************************
struct AttackAbility_eventOnAttackContextReady_Parms
{
	FCombatAttackContext Context;
};
static FName NAME_UAttackAbility_OnAttackContextReady = FName(TEXT("OnAttackContextReady"));
void UAttackAbility::OnAttackContextReady(FCombatAttackContext const& Context)
{
	AttackAbility_eventOnAttackContextReady_Parms Parms;
	Parms.Context=Context;
	UFunction* Func = FindFunctionChecked(NAME_UAttackAbility_OnAttackContextReady);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnAttackContextReady constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnAttackContextReady constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnAttackContextReady Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttackAbility_eventOnAttackContextReady_Parms, Context), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 829964288
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::PropPointers) < 2048);
// ********** End Function OnAttackContextReady Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackAbility, nullptr, "OnAttackContextReady", 	Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::PropPointers), 
sizeof(AttackAbility_eventOnAttackContextReady_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(AttackAbility_eventOnAttackContextReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackAbility_OnAttackContextReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackAbility_OnAttackContextReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UAttackAbility Function OnAttackContextReady *******************************

// ********** Begin Class UAttackAbility Function RequestCommitFromOrchestrator ********************
struct Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics
{
	struct AttackAbility_eventRequestCommitFromOrchestrator_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** For AI/state-tree flow: commit the currently active attack ability instance immediately. */" },
#endif
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For AI/state-tree flow: commit the currently active attack ability instance immediately." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestCommitFromOrchestrator constinit property declarations *********
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestCommitFromOrchestrator constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestCommitFromOrchestrator Property Definitions ********************
void Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((AttackAbility_eventRequestCommitFromOrchestrator_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AttackAbility_eventRequestCommitFromOrchestrator_Parms), &Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::PropPointers) < 2048);
// ********** End Function RequestCommitFromOrchestrator Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAttackAbility, nullptr, "RequestCommitFromOrchestrator", 	Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::AttackAbility_eventRequestCommitFromOrchestrator_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::AttackAbility_eventRequestCommitFromOrchestrator_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttackAbility::execRequestCommitFromOrchestrator)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RequestCommitFromOrchestrator();
	P_NATIVE_END;
}
// ********** End Class UAttackAbility Function RequestCommitFromOrchestrator **********************

// ********** Begin Class UAttackAbility ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAttackAbility;
UClass* UAttackAbility::GetPrivateStaticClass()
{
	using TClass = UAttackAbility;
	if (!Z_Registration_Info_UClass_UAttackAbility.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AttackAbility"),
			Z_Registration_Info_UClass_UAttackAbility.InnerSingleton,
			StaticRegisterNativesUAttackAbility,
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
	return Z_Registration_Info_UClass_UAttackAbility.InnerSingleton;
}
UClass* Z_Construct_UClass_UAttackAbility_NoRegister()
{
	return UAttackAbility::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAttackAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Combat/AttackAbility.h" },
		{ "ModuleRelativePath", "Public/Combat/AttackAbility.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAttackAbility constinit property declarations ***************************
// ********** End Class UAttackAbility constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAttackContext"), .Pointer = &UAttackAbility::execGetAttackContext },
		{ .NameUTF8 = UTF8TEXT("HandleCancel"), .Pointer = &UAttackAbility::execHandleCancel },
		{ .NameUTF8 = UTF8TEXT("HandleConfirm"), .Pointer = &UAttackAbility::execHandleConfirm },
		{ .NameUTF8 = UTF8TEXT("RequestCommitFromOrchestrator"), .Pointer = &UAttackAbility::execRequestCommitFromOrchestrator },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttackAbility_GetAttackContext, "GetAttackContext" }, // 3943597105
		{ &Z_Construct_UFunction_UAttackAbility_HandleCancel, "HandleCancel" }, // 4164418692
		{ &Z_Construct_UFunction_UAttackAbility_HandleConfirm, "HandleConfirm" }, // 2503419867
		{ &Z_Construct_UFunction_UAttackAbility_OnAttackContextReady, "OnAttackContextReady" }, // 284410555
		{ &Z_Construct_UFunction_UAttackAbility_RequestCommitFromOrchestrator, "RequestCommitFromOrchestrator" }, // 2334674151
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAttackAbility_Statics
UObject* (*const Z_Construct_UClass_UAttackAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCoreGASAdapter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackAbility_Statics::ClassParams = {
	&UAttackAbility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackAbility_Statics::Class_MetaDataParams)
};
void UAttackAbility::StaticRegisterNativesUAttackAbility()
{
	UClass* Class = UAttackAbility::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAttackAbility_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAttackAbility()
{
	if (!Z_Registration_Info_UClass_UAttackAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackAbility.OuterSingleton, Z_Construct_UClass_UAttackAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttackAbility.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAttackAbility);
UAttackAbility::~UAttackAbility() {}
// ********** End Class UAttackAbility *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h__Script_CombatCoreGASAdapter_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttackAbility, UAttackAbility::StaticClass, TEXT("UAttackAbility"), &Z_Registration_Info_UClass_UAttackAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackAbility), 3693573685U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h__Script_CombatCoreGASAdapter_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h__Script_CombatCoreGASAdapter_4188478698{
	TEXT("/Script/CombatCoreGASAdapter"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h__Script_CombatCoreGASAdapter_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCoreGASAdapter_Source_CombatCoreGASAdapter_Public_Combat_AttackAbility_h__Script_CombatCoreGASAdapter_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
