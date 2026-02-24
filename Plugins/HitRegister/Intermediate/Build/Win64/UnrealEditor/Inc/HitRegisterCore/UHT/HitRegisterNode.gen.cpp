// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegister/HitRegisterNode.h"
#include "HitRegister/HitRegisterTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterNode() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode();
HITREGISTERCORE_API UClass* Z_Construct_UClass_UHitRegisterNode_NoRegister();
HITREGISTERCORE_API UEnum* Z_Construct_UEnum_HitRegisterCore_EHitNodeResult();
HITREGISTERCORE_API UScriptStruct* Z_Construct_UScriptStruct_FHitRegisterContext();
UPackage* Z_Construct_UPackage__Script_HitRegisterCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterNode Function Execute ****************************************
struct HitRegisterNode_eventExecute_Parms
{
	FHitRegisterContext Context;
	EHitNodeResult ReturnValue;

	/** Constructor, initializes return property only **/
	HitRegisterNode_eventExecute_Parms()
		: ReturnValue((EHitNodeResult)0)
	{
	}
};
static FName NAME_UHitRegisterNode_Execute = FName(TEXT("Execute"));
EHitNodeResult UHitRegisterNode::Execute(FHitRegisterContext& Context)
{
	UFunction* Func = FindFunctionChecked(NAME_UHitRegisterNode_Execute);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		HitRegisterNode_eventExecute_Parms Parms;
		Parms.Context=Context;
	ProcessEvent(Func,&Parms);
		Context=Parms.Context;
		return Parms.ReturnValue;
	}
	else
	{
		return Execute_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UHitRegisterNode_Execute_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return Continue/Stop to gate the pipeline. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterNode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return Continue/Stop to gate the pipeline." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Execute constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Execute constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Execute Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterNode_eventExecute_Parms, Context), Z_Construct_UScriptStruct_FHitRegisterContext, METADATA_PARAMS(0, nullptr) }; // 1092352881
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterNode_eventExecute_Parms, ReturnValue), Z_Construct_UEnum_HitRegisterCore_EHitNodeResult, METADATA_PARAMS(0, nullptr) }; // 4257870574
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::PropPointers) < 2048);
// ********** End Function Execute Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterNode, nullptr, "Execute", 	Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::PropPointers), 
sizeof(HitRegisterNode_eventExecute_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitRegisterNode_eventExecute_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterNode_Execute()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterNode_Execute_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterNode::execExecute)
{
	P_GET_STRUCT_REF(FHitRegisterContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EHitNodeResult*)Z_Param__Result=P_THIS->Execute_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterNode Function Execute ******************************************

// ********** Begin Class UHitRegisterNode *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterNode;
UClass* UHitRegisterNode::GetPrivateStaticClass()
{
	using TClass = UHitRegisterNode;
	if (!Z_Registration_Info_UClass_UHitRegisterNode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterNode"),
			Z_Registration_Info_UClass_UHitRegisterNode.InnerSingleton,
			StaticRegisterNativesUHitRegisterNode,
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
	return Z_Registration_Info_UClass_UHitRegisterNode.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterNode_NoRegister()
{
	return UHitRegisterNode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HitRegister/HitRegisterNode.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HitRegister/HitRegisterNode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterNode constinit property declarations *************************
// ********** End Class UHitRegisterNode constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Execute"), .Pointer = &UHitRegisterNode::execExecute },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterNode_Execute, "Execute" }, // 538871962
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterNode_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterNode_Statics::ClassParams = {
	&UHitRegisterNode::StaticClass,
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
	0x003010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterNode_Statics::Class_MetaDataParams)
};
void UHitRegisterNode::StaticRegisterNativesUHitRegisterNode()
{
	UClass* Class = UHitRegisterNode::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterNode_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterNode()
{
	if (!Z_Registration_Info_UClass_UHitRegisterNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterNode.OuterSingleton, Z_Construct_UClass_UHitRegisterNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterNode.OuterSingleton;
}
UHitRegisterNode::UHitRegisterNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterNode);
UHitRegisterNode::~UHitRegisterNode() {}
// ********** End Class UHitRegisterNode ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h__Script_HitRegisterCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterNode, UHitRegisterNode::StaticClass, TEXT("UHitRegisterNode"), &Z_Registration_Info_UClass_UHitRegisterNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterNode), 1801593445U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h__Script_HitRegisterCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h__Script_HitRegisterCore_250401757{
	TEXT("/Script/HitRegisterCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h__Script_HitRegisterCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCore_Public_HitRegister_HitRegisterNode_h__Script_HitRegisterCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
