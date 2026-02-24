// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterTeamInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterTeamInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamAgent();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UHitRegisterTeamAgent Function GetTeamId *****************************
struct HitRegisterTeamAgent_eventGetTeamId_Parms
{
	int32 ReturnValue;

	/** Constructor, initializes return property only **/
	HitRegisterTeamAgent_eventGetTeamId_Parms()
		: ReturnValue(0)
	{
	}
};
int32 IHitRegisterTeamAgent::GetTeamId() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetTeamId instead.");
	HitRegisterTeamAgent_eventGetTeamId_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UHitRegisterTeamAgent_GetTeamId = FName(TEXT("GetTeamId"));
int32 IHitRegisterTeamAgent::Execute_GetTeamId(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UHitRegisterTeamAgent::StaticClass()));
	HitRegisterTeamAgent_eventGetTeamId_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UHitRegisterTeamAgent_GetTeamId);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IHitRegisterTeamAgent*)(O->GetNativeInterfaceAddress(UHitRegisterTeamAgent::StaticClass())))
	{
		Parms.ReturnValue = I->GetTeamId_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return a stable team/faction id. Use INDEX_NONE for unassigned. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTeamInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return a stable team/faction id. Use INDEX_NONE for unassigned." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTeamId constinit property declarations *****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTeamId constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTeamId Property Definitions ****************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterTeamAgent_eventGetTeamId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::PropPointers) < 2048);
// ********** End Function GetTeamId Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterTeamAgent, nullptr, "GetTeamId", 	Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::PropPointers), 
sizeof(HitRegisterTeamAgent_eventGetTeamId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitRegisterTeamAgent_eventGetTeamId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IHitRegisterTeamAgent::execGetTeamId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetTeamId_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UHitRegisterTeamAgent Function GetTeamId *******************************

// ********** Begin Interface UHitRegisterTeamAgent ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterTeamAgent;
UClass* UHitRegisterTeamAgent::GetPrivateStaticClass()
{
	using TClass = UHitRegisterTeamAgent;
	if (!Z_Registration_Info_UClass_UHitRegisterTeamAgent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterTeamAgent"),
			Z_Registration_Info_UClass_UHitRegisterTeamAgent.InnerSingleton,
			StaticRegisterNativesUHitRegisterTeamAgent,
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
	return Z_Registration_Info_UClass_UHitRegisterTeamAgent.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterTeamAgent_NoRegister()
{
	return UHitRegisterTeamAgent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterTeamAgent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterTeamInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UHitRegisterTeamAgent constinit property declarations ****************
// ********** End Interface UHitRegisterTeamAgent constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetTeamId"), .Pointer = &IHitRegisterTeamAgent::execGetTeamId },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterTeamAgent_GetTeamId, "GetTeamId" }, // 912067086
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IHitRegisterTeamAgent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterTeamAgent_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterTeamAgent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamAgent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterTeamAgent_Statics::ClassParams = {
	&UHitRegisterTeamAgent::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterTeamAgent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterTeamAgent_Statics::Class_MetaDataParams)
};
void UHitRegisterTeamAgent::StaticRegisterNativesUHitRegisterTeamAgent()
{
	UClass* Class = UHitRegisterTeamAgent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterTeamAgent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterTeamAgent()
{
	if (!Z_Registration_Info_UClass_UHitRegisterTeamAgent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterTeamAgent.OuterSingleton, Z_Construct_UClass_UHitRegisterTeamAgent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterTeamAgent.OuterSingleton;
}
UHitRegisterTeamAgent::UHitRegisterTeamAgent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterTeamAgent);
// ********** End Interface UHitRegisterTeamAgent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterTeamAgent, UHitRegisterTeamAgent::StaticClass, TEXT("UHitRegisterTeamAgent"), &Z_Registration_Info_UClass_UHitRegisterTeamAgent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterTeamAgent), 700600486U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h__Script_HitRegisterCollision_4231166841{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterTeamInterface_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
