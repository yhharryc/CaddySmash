// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterInterfaces.h"
#include "HitRegister/HitRegisterTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterInterfaces() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UDamageApplier();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UDamageApplier_NoRegister();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitReceiver();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitReceiver_NoRegister();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UHitReceiver Function OnHitConfirmed *********************************
struct HitReceiver_eventOnHitConfirmed_Parms
{
	FHitRegisterContext Context;
};
void IHitReceiver::OnHitConfirmed(FHitRegisterContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnHitConfirmed instead.");
}
static FName NAME_UHitReceiver_OnHitConfirmed = FName(TEXT("OnHitConfirmed"));
void IHitReceiver::Execute_OnHitConfirmed(UObject* O, FHitRegisterContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()));
	HitReceiver_eventOnHitConfirmed_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UHitReceiver_OnHitConfirmed);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IHitReceiver*)(O->GetNativeInterfaceAddress(UHitReceiver::StaticClass())))
	{
		I->OnHitConfirmed_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Always called when a hit is confirmed (after validation). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Always called when a hit is confirmed (after validation)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnHitConfirmed constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnHitConfirmed constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnHitConfirmed Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitReceiver_eventOnHitConfirmed_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 1092352881
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::PropPointers) < 2048);
// ********** End Function OnHitConfirmed Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitReceiver, nullptr, "OnHitConfirmed", 	Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::PropPointers), 
sizeof(HitReceiver_eventOnHitConfirmed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitReceiver_eventOnHitConfirmed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitReceiver_OnHitConfirmed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitReceiver_OnHitConfirmed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IHitReceiver::execOnHitConfirmed)
{
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHitConfirmed_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UHitReceiver Function OnHitConfirmed ***********************************

// ********** Begin Interface UHitReceiver Function OnPostDamage ***********************************
struct HitReceiver_eventOnPostDamage_Parms
{
	FHitRegisterContext Context;
};
void IHitReceiver::OnPostDamage(FHitRegisterContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnPostDamage instead.");
}
static FName NAME_UHitReceiver_OnPostDamage = FName(TEXT("OnPostDamage"));
void IHitReceiver::Execute_OnPostDamage(UObject* O, FHitRegisterContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()));
	HitReceiver_eventOnPostDamage_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UHitReceiver_OnPostDamage);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IHitReceiver*)(O->GetNativeInterfaceAddress(UHitReceiver::StaticClass())))
	{
		I->OnPostDamage_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called after damage was applied (even if 0, you decide in adapter). */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called after damage was applied (even if 0, you decide in adapter)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPostDamage constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnPostDamage constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnPostDamage Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitReceiver_eventOnPostDamage_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 1092352881
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::PropPointers) < 2048);
// ********** End Function OnPostDamage Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitReceiver, nullptr, "OnPostDamage", 	Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::PropPointers), 
sizeof(HitReceiver_eventOnPostDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitReceiver_eventOnPostDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitReceiver_OnPostDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitReceiver_OnPostDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IHitReceiver::execOnPostDamage)
{
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPostDamage_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UHitReceiver Function OnPostDamage *************************************

// ********** Begin Interface UHitReceiver Function ShouldAcceptHit ********************************
struct HitReceiver_eventShouldAcceptHit_Parms
{
	FHitRegisterContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	HitReceiver_eventShouldAcceptHit_Parms()
		: ReturnValue(false)
	{
	}
};
bool IHitReceiver::ShouldAcceptHit(FHitRegisterContext& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ShouldAcceptHit instead.");
	HitReceiver_eventShouldAcceptHit_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UHitReceiver_ShouldAcceptHit = FName(TEXT("ShouldAcceptHit"));
bool IHitReceiver::Execute_ShouldAcceptHit(UObject* O, FHitRegisterContext& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UHitReceiver::StaticClass()));
	HitReceiver_eventShouldAcceptHit_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UHitReceiver_ShouldAcceptHit);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
		Context=std::move(Parms.Context);
	}
	else if (auto I = (IHitReceiver*)(O->GetNativeInterfaceAddress(UHitReceiver::StaticClass())))
	{
		Parms.ReturnValue = I->ShouldAcceptHit_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return false to reject the hit and stop the pipeline. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return false to reject the hit and stop the pipeline." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ShouldAcceptHit constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShouldAcceptHit constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShouldAcceptHit Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitReceiver_eventShouldAcceptHit_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
void Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((HitReceiver_eventShouldAcceptHit_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HitReceiver_eventShouldAcceptHit_Parms), &Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::PropPointers) < 2048);
// ********** End Function ShouldAcceptHit Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitReceiver, nullptr, "ShouldAcceptHit", 	Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::PropPointers), 
sizeof(HitReceiver_eventShouldAcceptHit_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitReceiver_eventShouldAcceptHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IHitReceiver::execShouldAcceptHit)
{
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldAcceptHit_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UHitReceiver Function ShouldAcceptHit **********************************

// ********** Begin Interface UHitReceiver *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitReceiver;
UClass* UHitReceiver::GetPrivateStaticClass()
{
	using TClass = UHitReceiver;
	if (!Z_Registration_Info_UClass_UHitReceiver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitReceiver"),
			Z_Registration_Info_UClass_UHitReceiver.InnerSingleton,
			StaticRegisterNativesUHitReceiver,
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
	return Z_Registration_Info_UClass_UHitReceiver.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitReceiver_NoRegister()
{
	return UHitReceiver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UHitReceiver constinit property declarations *************************
// ********** End Interface UHitReceiver constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnHitConfirmed"), .Pointer = &IHitReceiver::execOnHitConfirmed },
		{ .NameUTF8 = UTF8TEXT("OnPostDamage"), .Pointer = &IHitReceiver::execOnPostDamage },
		{ .NameUTF8 = UTF8TEXT("ShouldAcceptHit"), .Pointer = &IHitReceiver::execShouldAcceptHit },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitReceiver_OnHitConfirmed, "OnHitConfirmed" }, // 3433737534
		{ &Z_Construct_UFunction_UHitReceiver_OnPostDamage, "OnPostDamage" }, // 2143295597
		{ &Z_Construct_UFunction_UHitReceiver_ShouldAcceptHit, "ShouldAcceptHit" }, // 3133552870
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IHitReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitReceiver_Statics
UObject* (*const Z_Construct_UClass_UHitReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitReceiver_Statics::ClassParams = {
	&UHitReceiver::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitReceiver_Statics::Class_MetaDataParams)
};
void UHitReceiver::StaticRegisterNativesUHitReceiver()
{
	UClass* Class = UHitReceiver::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitReceiver_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitReceiver()
{
	if (!Z_Registration_Info_UClass_UHitReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitReceiver.OuterSingleton, Z_Construct_UClass_UHitReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitReceiver.OuterSingleton;
}
UHitReceiver::UHitReceiver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitReceiver);
// ********** End Interface UHitReceiver ***********************************************************

// ********** Begin Interface UDamageApplier Function ApplyDamage **********************************
struct DamageApplier_eventApplyDamage_Parms
{
	FHitRegisterContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	DamageApplier_eventApplyDamage_Parms()
		: ReturnValue(false)
	{
	}
};
bool IDamageApplier::ApplyDamage(FHitRegisterContext& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ApplyDamage instead.");
	DamageApplier_eventApplyDamage_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UDamageApplier_ApplyDamage = FName(TEXT("ApplyDamage"));
bool IDamageApplier::Execute_ApplyDamage(UObject* O, FHitRegisterContext& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UDamageApplier::StaticClass()));
	DamageApplier_eventApplyDamage_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UDamageApplier_ApplyDamage);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
		Context=std::move(Parms.Context);
	}
	else if (auto I = (IDamageApplier*)(O->GetNativeInterfaceAddress(UDamageApplier::StaticClass())))
	{
		Parms.ReturnValue = I->ApplyDamage_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return true if damage application succeeded. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return true if damage application succeeded." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyDamage constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyDamage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyDamage Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DamageApplier_eventApplyDamage_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
void Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DamageApplier_eventApplyDamage_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DamageApplier_eventApplyDamage_Parms), &Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::PropPointers) < 2048);
// ********** End Function ApplyDamage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDamageApplier, nullptr, "ApplyDamage", 	Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::PropPointers), 
sizeof(DamageApplier_eventApplyDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DamageApplier_eventApplyDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDamageApplier_ApplyDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDamageApplier_ApplyDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IDamageApplier::execApplyDamage)
{
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ApplyDamage_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UDamageApplier Function ApplyDamage ************************************

// ********** Begin Interface UDamageApplier *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDamageApplier;
UClass* UDamageApplier::GetPrivateStaticClass()
{
	using TClass = UDamageApplier;
	if (!Z_Registration_Info_UClass_UDamageApplier.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DamageApplier"),
			Z_Registration_Info_UClass_UDamageApplier.InnerSingleton,
			StaticRegisterNativesUDamageApplier,
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
	return Z_Registration_Info_UClass_UDamageApplier.InnerSingleton;
}
UClass* Z_Construct_UClass_UDamageApplier_NoRegister()
{
	return UDamageApplier::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDamageApplier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterInterfaces.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UDamageApplier constinit property declarations ***********************
// ********** End Interface UDamageApplier constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyDamage"), .Pointer = &IDamageApplier::execApplyDamage },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDamageApplier_ApplyDamage, "ApplyDamage" }, // 2523113556
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDamageApplier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDamageApplier_Statics
UObject* (*const Z_Construct_UClass_UDamageApplier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageApplier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDamageApplier_Statics::ClassParams = {
	&UDamageApplier::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageApplier_Statics::Class_MetaDataParams), Z_Construct_UClass_UDamageApplier_Statics::Class_MetaDataParams)
};
void UDamageApplier::StaticRegisterNativesUDamageApplier()
{
	UClass* Class = UDamageApplier::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDamageApplier_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDamageApplier()
{
	if (!Z_Registration_Info_UClass_UDamageApplier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDamageApplier.OuterSingleton, Z_Construct_UClass_UDamageApplier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDamageApplier.OuterSingleton;
}
UDamageApplier::UDamageApplier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDamageApplier);
// ********** End Interface UDamageApplier *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitReceiver, UHitReceiver::StaticClass, TEXT("UHitReceiver"), &Z_Registration_Info_UClass_UHitReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitReceiver), 4143829006U) },
		{ Z_Construct_UClass_UDamageApplier, UDamageApplier::StaticClass, TEXT("UDamageApplier"), &Z_Registration_Info_UClass_UDamageApplier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDamageApplier), 167600026U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h__Script_HitRegisterCore_1130492498{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterInterfaces_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
