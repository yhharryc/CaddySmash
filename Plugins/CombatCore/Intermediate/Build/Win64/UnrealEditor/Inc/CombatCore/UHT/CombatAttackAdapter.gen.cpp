// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Combat/CombatAttackAdapter.h"
#include "Combat/AttackTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCombatAttackAdapter() {}

// ********** Begin Cross Module References ********************************************************
COMBATCORE_API UClass* Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister();
COMBATCORE_API UClass* Z_Construct_UClass_UCombatAttackAdapter();
COMBATCORE_API UClass* Z_Construct_UClass_UCombatAttackAdapter_NoRegister();
COMBATCORE_API UScriptStruct* Z_Construct_UScriptStruct_FCombatAttackRequest();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_CombatCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UCombatAttackAdapter Function BeginAttackIntent **********************
struct CombatAttackAdapter_eventBeginAttackIntent_Parms
{
	UAttackOrchestratorComponent* Orchestrator;
	FCombatAttackRequest Request;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	CombatAttackAdapter_eventBeginAttackIntent_Parms()
		: ReturnValue(false)
	{
	}
};
bool ICombatAttackAdapter::BeginAttackIntent(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_BeginAttackIntent instead.");
	CombatAttackAdapter_eventBeginAttackIntent_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UCombatAttackAdapter_BeginAttackIntent = FName(TEXT("BeginAttackIntent"));
bool ICombatAttackAdapter::Execute_BeginAttackIntent(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UCombatAttackAdapter::StaticClass()));
	CombatAttackAdapter_eventBeginAttackIntent_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UCombatAttackAdapter_BeginAttackIntent);
	if (Func)
	{
		Parms.Orchestrator=std::move(Orchestrator);
		Parms.Request=std::move(Request);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (ICombatAttackAdapter*)(O->GetNativeInterfaceAddress(UCombatAttackAdapter::StaticClass())))
	{
		Parms.ReturnValue = I->BeginAttackIntent_Implementation(Orchestrator,Request);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Adapter" },
		{ "ModuleRelativePath", "Public/Combat/CombatAttackAdapter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orchestrator_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginAttackIntent constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Orchestrator;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginAttackIntent constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginAttackIntent Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_Orchestrator = { "Orchestrator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventBeginAttackIntent_Parms, Orchestrator), Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orchestrator_MetaData), NewProp_Orchestrator_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventBeginAttackIntent_Parms, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
void Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CombatAttackAdapter_eventBeginAttackIntent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatAttackAdapter_eventBeginAttackIntent_Parms), &Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_Orchestrator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::PropPointers) < 2048);
// ********** End Function BeginAttackIntent Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatAttackAdapter, nullptr, "BeginAttackIntent", 	Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::PropPointers), 
sizeof(CombatAttackAdapter_eventBeginAttackIntent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(CombatAttackAdapter_eventBeginAttackIntent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ICombatAttackAdapter::execBeginAttackIntent)
{
	P_GET_OBJECT(UAttackOrchestratorComponent,Z_Param_Orchestrator);
	P_GET_STRUCT_REF(FCombatAttackRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BeginAttackIntent_Implementation(Z_Param_Orchestrator,Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Interface UCombatAttackAdapter Function BeginAttackIntent ************************

// ********** Begin Interface UCombatAttackAdapter Function CancelAttack ***************************
struct CombatAttackAdapter_eventCancelAttack_Parms
{
	UAttackOrchestratorComponent* Orchestrator;
	FCombatAttackRequest Request;
};
void ICombatAttackAdapter::CancelAttack(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CancelAttack instead.");
}
static FName NAME_UCombatAttackAdapter_CancelAttack = FName(TEXT("CancelAttack"));
void ICombatAttackAdapter::Execute_CancelAttack(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UCombatAttackAdapter::StaticClass()));
	CombatAttackAdapter_eventCancelAttack_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UCombatAttackAdapter_CancelAttack);
	if (Func)
	{
		Parms.Orchestrator=std::move(Orchestrator);
		Parms.Request=std::move(Request);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (ICombatAttackAdapter*)(O->GetNativeInterfaceAddress(UCombatAttackAdapter::StaticClass())))
	{
		I->CancelAttack_Implementation(Orchestrator,Request);
	}
}
struct Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Adapter" },
		{ "ModuleRelativePath", "Public/Combat/CombatAttackAdapter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orchestrator_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelAttack constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Orchestrator;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelAttack constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelAttack Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::NewProp_Orchestrator = { "Orchestrator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventCancelAttack_Parms, Orchestrator), Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orchestrator_MetaData), NewProp_Orchestrator_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventCancelAttack_Parms, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::NewProp_Orchestrator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::NewProp_Request,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::PropPointers) < 2048);
// ********** End Function CancelAttack Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatAttackAdapter, nullptr, "CancelAttack", 	Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::PropPointers), 
sizeof(CombatAttackAdapter_eventCancelAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(CombatAttackAdapter_eventCancelAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ICombatAttackAdapter::execCancelAttack)
{
	P_GET_OBJECT(UAttackOrchestratorComponent,Z_Param_Orchestrator);
	P_GET_STRUCT_REF(FCombatAttackRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelAttack_Implementation(Z_Param_Orchestrator,Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Interface UCombatAttackAdapter Function CancelAttack *****************************

// ********** Begin Interface UCombatAttackAdapter Function TryCommitAttack ************************
struct CombatAttackAdapter_eventTryCommitAttack_Parms
{
	UAttackOrchestratorComponent* Orchestrator;
	FCombatAttackRequest Request;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	CombatAttackAdapter_eventTryCommitAttack_Parms()
		: ReturnValue(false)
	{
	}
};
bool ICombatAttackAdapter::TryCommitAttack(UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_TryCommitAttack instead.");
	CombatAttackAdapter_eventTryCommitAttack_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UCombatAttackAdapter_TryCommitAttack = FName(TEXT("TryCommitAttack"));
bool ICombatAttackAdapter::Execute_TryCommitAttack(UObject* O, UAttackOrchestratorComponent* Orchestrator, FCombatAttackRequest const& Request)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UCombatAttackAdapter::StaticClass()));
	CombatAttackAdapter_eventTryCommitAttack_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UCombatAttackAdapter_TryCommitAttack);
	if (Func)
	{
		Parms.Orchestrator=std::move(Orchestrator);
		Parms.Request=std::move(Request);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (ICombatAttackAdapter*)(O->GetNativeInterfaceAddress(UCombatAttackAdapter::StaticClass())))
	{
		Parms.ReturnValue = I->TryCommitAttack_Implementation(Orchestrator,Request);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Adapter" },
		{ "ModuleRelativePath", "Public/Combat/CombatAttackAdapter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orchestrator_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryCommitAttack constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Orchestrator;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryCommitAttack constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryCommitAttack Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_Orchestrator = { "Orchestrator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventTryCommitAttack_Parms, Orchestrator), Z_Construct_UClass_UAttackOrchestratorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orchestrator_MetaData), NewProp_Orchestrator_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatAttackAdapter_eventTryCommitAttack_Parms, Request), Z_Construct_UScriptStruct_FCombatAttackRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3210230800
void Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CombatAttackAdapter_eventTryCommitAttack_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CombatAttackAdapter_eventTryCommitAttack_Parms), &Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_Orchestrator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::PropPointers) < 2048);
// ********** End Function TryCommitAttack Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatAttackAdapter, nullptr, "TryCommitAttack", 	Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::PropPointers), 
sizeof(CombatAttackAdapter_eventTryCommitAttack_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(CombatAttackAdapter_eventTryCommitAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ICombatAttackAdapter::execTryCommitAttack)
{
	P_GET_OBJECT(UAttackOrchestratorComponent,Z_Param_Orchestrator);
	P_GET_STRUCT_REF(FCombatAttackRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryCommitAttack_Implementation(Z_Param_Orchestrator,Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Interface UCombatAttackAdapter Function TryCommitAttack **************************

// ********** Begin Interface UCombatAttackAdapter *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCombatAttackAdapter;
UClass* UCombatAttackAdapter::GetPrivateStaticClass()
{
	using TClass = UCombatAttackAdapter;
	if (!Z_Registration_Info_UClass_UCombatAttackAdapter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CombatAttackAdapter"),
			Z_Registration_Info_UClass_UCombatAttackAdapter.InnerSingleton,
			StaticRegisterNativesUCombatAttackAdapter,
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
	return Z_Registration_Info_UClass_UCombatAttackAdapter.InnerSingleton;
}
UClass* Z_Construct_UClass_UCombatAttackAdapter_NoRegister()
{
	return UCombatAttackAdapter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCombatAttackAdapter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Combat/CombatAttackAdapter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UCombatAttackAdapter constinit property declarations *****************
// ********** End Interface UCombatAttackAdapter constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginAttackIntent"), .Pointer = &ICombatAttackAdapter::execBeginAttackIntent },
		{ .NameUTF8 = UTF8TEXT("CancelAttack"), .Pointer = &ICombatAttackAdapter::execCancelAttack },
		{ .NameUTF8 = UTF8TEXT("TryCommitAttack"), .Pointer = &ICombatAttackAdapter::execTryCommitAttack },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatAttackAdapter_BeginAttackIntent, "BeginAttackIntent" }, // 123356529
		{ &Z_Construct_UFunction_UCombatAttackAdapter_CancelAttack, "CancelAttack" }, // 4118120326
		{ &Z_Construct_UFunction_UCombatAttackAdapter_TryCommitAttack, "TryCommitAttack" }, // 2263456109
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ICombatAttackAdapter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCombatAttackAdapter_Statics
UObject* (*const Z_Construct_UClass_UCombatAttackAdapter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatAttackAdapter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatAttackAdapter_Statics::ClassParams = {
	&UCombatAttackAdapter::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatAttackAdapter_Statics::Class_MetaDataParams), Z_Construct_UClass_UCombatAttackAdapter_Statics::Class_MetaDataParams)
};
void UCombatAttackAdapter::StaticRegisterNativesUCombatAttackAdapter()
{
	UClass* Class = UCombatAttackAdapter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCombatAttackAdapter_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCombatAttackAdapter()
{
	if (!Z_Registration_Info_UClass_UCombatAttackAdapter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatAttackAdapter.OuterSingleton, Z_Construct_UClass_UCombatAttackAdapter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCombatAttackAdapter.OuterSingleton;
}
UCombatAttackAdapter::UCombatAttackAdapter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCombatAttackAdapter);
// ********** End Interface UCombatAttackAdapter ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h__Script_CombatCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCombatAttackAdapter, UCombatAttackAdapter::StaticClass, TEXT("UCombatAttackAdapter"), &Z_Registration_Info_UClass_UCombatAttackAdapter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatAttackAdapter), 2480621142U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h__Script_CombatCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h__Script_CombatCore_1631465244{
	TEXT("/Script/CombatCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h__Script_CombatCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_CombatCore_Source_CombatCore_Public_Combat_CombatAttackAdapter_h__Script_CombatCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
