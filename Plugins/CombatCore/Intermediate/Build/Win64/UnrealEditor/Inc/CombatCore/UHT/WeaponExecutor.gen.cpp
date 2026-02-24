// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/WeaponExecutor.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWeaponExecutor() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponExecutor();
COMBATCORE_API UClass* Z_Construct_UClass_UWeaponExecutor_NoRegister();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackContext();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UWeaponExecutor Function CanExecuteAttack ****************************
struct WeaponExecutor_eventCanExecuteAttack_Parms
{
	FCombatAttackContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	WeaponExecutor_eventCanExecuteAttack_Parms()
		: ReturnValue(false)
	{
	}
};
bool IWeaponExecutor::CanExecuteAttack(FCombatAttackContext& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanExecuteAttack instead.");
	WeaponExecutor_eventCanExecuteAttack_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UWeaponExecutor_CanExecuteAttack = FName(TEXT("CanExecuteAttack"));
bool IWeaponExecutor::Execute_CanExecuteAttack(UObject* O, FCombatAttackContext& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UWeaponExecutor::StaticClass()));
	WeaponExecutor_eventCanExecuteAttack_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UWeaponExecutor_CanExecuteAttack);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
		Context=std::move(Parms.Context);
	}
	else if (auto I = (IWeaponExecutor*)(O->GetNativeInterfaceAddress(UWeaponExecutor::StaticClass())))
	{
		Parms.ReturnValue = I->CanExecuteAttack_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponExecutor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanExecuteAttack constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanExecuteAttack constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanExecuteAttack Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponExecutor_eventCanExecuteAttack_Parms, Context), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(0, nullptr) }; // 829964288
void Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WeaponExecutor_eventCanExecuteAttack_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WeaponExecutor_eventCanExecuteAttack_Parms), &Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::PropPointers) < 2048);
// ********** End Function CanExecuteAttack Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponExecutor, nullptr, "CanExecuteAttack", 	Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::PropPointers), 
sizeof(WeaponExecutor_eventCanExecuteAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(WeaponExecutor_eventCanExecuteAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IWeaponExecutor::execCanExecuteAttack)
{
	P_GET_STRUCT_REF(FCombatAttackContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanExecuteAttack_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UWeaponExecutor Function CanExecuteAttack ******************************

// ********** Begin Interface UWeaponExecutor Function ExecuteAttack *******************************
struct WeaponExecutor_eventExecuteAttack_Parms
{
	FCombatAttackContext Context;
};
void IWeaponExecutor::ExecuteAttack(FCombatAttackContext& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ExecuteAttack instead.");
}
static FName NAME_UWeaponExecutor_ExecuteAttack = FName(TEXT("ExecuteAttack"));
void IWeaponExecutor::Execute_ExecuteAttack(UObject* O, FCombatAttackContext& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UWeaponExecutor::StaticClass()));
	WeaponExecutor_eventExecuteAttack_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UWeaponExecutor_ExecuteAttack);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
		Context=std::move(Parms.Context);
	}
	else if (auto I = (IWeaponExecutor*)(O->GetNativeInterfaceAddress(UWeaponExecutor::StaticClass())))
	{
		I->ExecuteAttack_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Combat/WeaponExecutor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteAttack constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteAttack constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteAttack Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponExecutor_eventExecuteAttack_Parms, Context), Z_Construct_UScriptStruct_FCombatAttackContext, METADATA_PARAMS(0, nullptr) }; // 829964288
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::PropPointers) < 2048);
// ********** End Function ExecuteAttack Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponExecutor, nullptr, "ExecuteAttack", 	Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::PropPointers), 
sizeof(WeaponExecutor_eventExecuteAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(WeaponExecutor_eventExecuteAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IWeaponExecutor::execExecuteAttack)
{
	P_GET_STRUCT_REF(FCombatAttackContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteAttack_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UWeaponExecutor Function ExecuteAttack *********************************

// ********** Begin Interface UWeaponExecutor ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UWeaponExecutor;
UClass* UWeaponExecutor::GetPrivateStaticClass()
{
	using TClass = UWeaponExecutor;
	if (!Z_Registration_Info_UClass_UWeaponExecutor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WeaponExecutor"),
			Z_Registration_Info_UClass_UWeaponExecutor.InnerSingleton,
			StaticRegisterNativesUWeaponExecutor,
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
	return Z_Registration_Info_UClass_UWeaponExecutor.InnerSingleton;
}
UClass* Z_Construct_UClass_UWeaponExecutor_NoRegister()
{
	return UWeaponExecutor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWeaponExecutor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/WeaponExecutor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UWeaponExecutor constinit property declarations **********************
// ********** End Interface UWeaponExecutor constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanExecuteAttack"), .Pointer = &IWeaponExecutor::execCanExecuteAttack },
		{ .NameUTF8 = UTF8TEXT("ExecuteAttack"), .Pointer = &IWeaponExecutor::execExecuteAttack },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWeaponExecutor_CanExecuteAttack, "CanExecuteAttack" }, // 1902627150
		{ &Z_Construct_UFunction_UWeaponExecutor_ExecuteAttack, "ExecuteAttack" }, // 1869000162
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IWeaponExecutor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UWeaponExecutor_Statics
UObject* (*const Z_Construct_UClass_UWeaponExecutor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponExecutor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponExecutor_Statics::ClassParams = {
	&UWeaponExecutor::StaticClass,
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
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponExecutor_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponExecutor_Statics::Class_MetaDataParams)
};
void UWeaponExecutor::StaticRegisterNativesUWeaponExecutor()
{
	UClass* Class = UWeaponExecutor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UWeaponExecutor_Statics::Funcs));
}
UClass* Z_Construct_UClass_UWeaponExecutor()
{
	if (!Z_Registration_Info_UClass_UWeaponExecutor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponExecutor.OuterSingleton, Z_Construct_UClass_UWeaponExecutor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWeaponExecutor.OuterSingleton;
}
UWeaponExecutor::UWeaponExecutor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UWeaponExecutor);
// ********** End Interface UWeaponExecutor ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponExecutor, UWeaponExecutor::StaticClass, TEXT("UWeaponExecutor"), &Z_Registration_Info_UClass_UWeaponExecutor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponExecutor), 315122231U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h__Script_CombatCore_2832106059{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_WeaponExecutor_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
