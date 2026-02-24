// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/FormationAsset.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeFormationAsset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SQUADCORE_API UClass* Z_Construct_UClass_UFormationAsset();
SQUADCORE_API UClass* Z_Construct_UClass_UFormationAsset_NoRegister();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FSquadSlot();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UFormationAsset Function GetSlotOffset ***********************************
struct Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics
{
	struct FormationAsset_eventGetSlotOffset_Parms
	{
		int32 SlotIndex;
		FVector OutOffset;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/FormationAsset.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlotOffset constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutOffset;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlotOffset constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlotOffset Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FormationAsset_eventGetSlotOffset_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_OutOffset = { "OutOffset", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FormationAsset_eventGetSlotOffset_Parms, OutOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FormationAsset_eventGetSlotOffset_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FormationAsset_eventGetSlotOffset_Parms), &Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_OutOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::PropPointers) < 2048);
// ********** End Function GetSlotOffset Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFormationAsset, nullptr, "GetSlotOffset", 	Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::FormationAsset_eventGetSlotOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::FormationAsset_eventGetSlotOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFormationAsset_GetSlotOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFormationAsset_GetSlotOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFormationAsset::execGetSlotOffset)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSlotOffset(Z_Param_SlotIndex,Z_Param_Out_OutOffset);
	P_NATIVE_END;
}
// ********** End Class UFormationAsset Function GetSlotOffset *************************************

// ********** Begin Class UFormationAsset **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UFormationAsset;
UClass* UFormationAsset::GetPrivateStaticClass()
{
	using TClass = UFormationAsset;
	if (!Z_Registration_Info_UClass_UFormationAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("FormationAsset"),
			Z_Registration_Info_UClass_UFormationAsset.InnerSingleton,
			StaticRegisterNativesUFormationAsset,
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
	return Z_Registration_Info_UClass_UFormationAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UFormationAsset_NoRegister()
{
	return UFormationAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UFormationAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/FormationAsset.h" },
		{ "ModuleRelativePath", "Public/SquadCore/FormationAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slots_MetaData[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/FormationAsset.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UFormationAsset constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Slots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UFormationAsset constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSlotOffset"), .Pointer = &UFormationAsset::execGetSlotOffset },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFormationAsset_GetSlotOffset, "GetSlotOffset" }, // 290812229
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFormationAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UFormationAsset_Statics

// ********** Begin Class UFormationAsset Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFormationAsset_Statics::NewProp_Slots_Inner = { "Slots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSquadSlot, METADATA_PARAMS(0, nullptr) }; // 3011450254
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFormationAsset_Statics::NewProp_Slots = { "Slots", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFormationAsset, Slots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slots_MetaData), NewProp_Slots_MetaData) }; // 3011450254
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFormationAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFormationAsset_Statics::NewProp_Slots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFormationAsset_Statics::NewProp_Slots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFormationAsset_Statics::PropPointers) < 2048);
// ********** End Class UFormationAsset Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_UFormationAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFormationAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFormationAsset_Statics::ClassParams = {
	&UFormationAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFormationAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFormationAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFormationAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UFormationAsset_Statics::Class_MetaDataParams)
};
void UFormationAsset::StaticRegisterNativesUFormationAsset()
{
	UClass* Class = UFormationAsset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UFormationAsset_Statics::Funcs));
}
UClass* Z_Construct_UClass_UFormationAsset()
{
	if (!Z_Registration_Info_UClass_UFormationAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFormationAsset.OuterSingleton, Z_Construct_UClass_UFormationAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFormationAsset.OuterSingleton;
}
UFormationAsset::UFormationAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UFormationAsset);
UFormationAsset::~UFormationAsset() {}
// ********** End Class UFormationAsset ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFormationAsset, UFormationAsset::StaticClass, TEXT("UFormationAsset"), &Z_Registration_Info_UClass_UFormationAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFormationAsset), 3231276771U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h__Script_SquadCore_788182525{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_FormationAsset_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
