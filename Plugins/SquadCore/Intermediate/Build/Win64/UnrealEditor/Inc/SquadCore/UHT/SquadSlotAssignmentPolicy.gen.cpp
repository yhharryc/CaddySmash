// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SquadCore/SquadSlotAssignmentPolicy.h"
#include "SquadCore/SquadTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSquadSlotAssignmentPolicy() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy();
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree();
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_NoRegister();
SQUADCORE_API UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister();
SQUADCORE_API UScriptStruct* Z_Construct_UScriptStruct_FSquadSlot();
UPackage* Z_Construct_UPackage__Script_SquadCore();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USquadSlotAssignmentPolicy Function SelectSlot ***************************
struct SquadSlotAssignmentPolicy_eventSelectSlot_Parms
{
	AActor* Member;
	TArray<FSquadSlot> Slots;
	TArray<int32> OccupiedSlots;
	int32 ReturnValue;

	/** Constructor, initializes return property only **/
	SquadSlotAssignmentPolicy_eventSelectSlot_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_USquadSlotAssignmentPolicy_SelectSlot = FName(TEXT("SelectSlot"));
int32 USquadSlotAssignmentPolicy::SelectSlot(AActor* Member, TArray<FSquadSlot> const& Slots, TArray<int32> const& OccupiedSlots) const
{
	UFunction* Func = FindFunctionChecked(NAME_USquadSlotAssignmentPolicy_SelectSlot);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		SquadSlotAssignmentPolicy_eventSelectSlot_Parms Parms;
		Parms.Member=Member;
		Parms.Slots=Slots;
		Parms.OccupiedSlots=OccupiedSlots;
		const_cast<USquadSlotAssignmentPolicy*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<USquadSlotAssignmentPolicy*>(this)->SelectSlot_Implementation(Member, Slots, OccupiedSlots);
	}
}
struct Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Squad" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadSlotAssignmentPolicy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slots_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OccupiedSlots_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectSlot constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Member;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Slots;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OccupiedSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OccupiedSlots;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectSlot constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectSlot Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Member = { "Member", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadSlotAssignmentPolicy_eventSelectSlot_Parms, Member), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Slots_Inner = { "Slots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSquadSlot, METADATA_PARAMS(0, nullptr) }; // 3011450254
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Slots = { "Slots", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadSlotAssignmentPolicy_eventSelectSlot_Parms, Slots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slots_MetaData), NewProp_Slots_MetaData) }; // 3011450254
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_OccupiedSlots_Inner = { "OccupiedSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_OccupiedSlots = { "OccupiedSlots", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadSlotAssignmentPolicy_eventSelectSlot_Parms, OccupiedSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OccupiedSlots_MetaData), NewProp_OccupiedSlots_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SquadSlotAssignmentPolicy_eventSelectSlot_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Member,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Slots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_Slots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_OccupiedSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_OccupiedSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::PropPointers) < 2048);
// ********** End Function SelectSlot Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USquadSlotAssignmentPolicy, nullptr, "SelectSlot", 	Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::PropPointers), 
sizeof(SquadSlotAssignmentPolicy_eventSelectSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SquadSlotAssignmentPolicy_eventSelectSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USquadSlotAssignmentPolicy::execSelectSlot)
{
	P_GET_OBJECT(AActor,Z_Param_Member);
	P_GET_TARRAY_REF(FSquadSlot,Z_Param_Out_Slots);
	P_GET_TARRAY_REF(int32,Z_Param_Out_OccupiedSlots);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->SelectSlot_Implementation(Z_Param_Member,Z_Param_Out_Slots,Z_Param_Out_OccupiedSlots);
	P_NATIVE_END;
}
// ********** End Class USquadSlotAssignmentPolicy Function SelectSlot *****************************

// ********** Begin Class USquadSlotAssignmentPolicy ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadSlotAssignmentPolicy;
UClass* USquadSlotAssignmentPolicy::GetPrivateStaticClass()
{
	using TClass = USquadSlotAssignmentPolicy;
	if (!Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadSlotAssignmentPolicy"),
			Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.InnerSingleton,
			StaticRegisterNativesUSquadSlotAssignmentPolicy,
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
	return Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_NoRegister()
{
	return USquadSlotAssignmentPolicy::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/SquadSlotAssignmentPolicy.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadSlotAssignmentPolicy.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadSlotAssignmentPolicy constinit property declarations ***************
// ********** End Class USquadSlotAssignmentPolicy constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SelectSlot"), .Pointer = &USquadSlotAssignmentPolicy::execSelectSlot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USquadSlotAssignmentPolicy_SelectSlot, "SelectSlot" }, // 3548251989
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadSlotAssignmentPolicy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics
UObject* (*const Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::ClassParams = {
	&USquadSlotAssignmentPolicy::StaticClass,
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
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::Class_MetaDataParams)
};
void USquadSlotAssignmentPolicy::StaticRegisterNativesUSquadSlotAssignmentPolicy()
{
	UClass* Class = USquadSlotAssignmentPolicy::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::Funcs));
}
UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy()
{
	if (!Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.OuterSingleton, Z_Construct_UClass_USquadSlotAssignmentPolicy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadSlotAssignmentPolicy.OuterSingleton;
}
USquadSlotAssignmentPolicy::USquadSlotAssignmentPolicy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadSlotAssignmentPolicy);
USquadSlotAssignmentPolicy::~USquadSlotAssignmentPolicy() {}
// ********** End Class USquadSlotAssignmentPolicy *************************************************

// ********** Begin Class USquadSlotAssignmentPolicy_FirstFree *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree;
UClass* USquadSlotAssignmentPolicy_FirstFree::GetPrivateStaticClass()
{
	using TClass = USquadSlotAssignmentPolicy_FirstFree;
	if (!Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SquadSlotAssignmentPolicy_FirstFree"),
			Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.InnerSingleton,
			StaticRegisterNativesUSquadSlotAssignmentPolicy_FirstFree,
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
	return Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.InnerSingleton;
}
UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_NoRegister()
{
	return USquadSlotAssignmentPolicy_FirstFree::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SquadCore/SquadSlotAssignmentPolicy.h" },
		{ "ModuleRelativePath", "Public/SquadCore/SquadSlotAssignmentPolicy.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USquadSlotAssignmentPolicy_FirstFree constinit property declarations *****
// ********** End Class USquadSlotAssignmentPolicy_FirstFree constinit property declarations *******
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USquadSlotAssignmentPolicy_FirstFree>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics
UObject* (*const Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USquadSlotAssignmentPolicy,
	(UObject* (*)())Z_Construct_UPackage__Script_SquadCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::ClassParams = {
	&USquadSlotAssignmentPolicy_FirstFree::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::Class_MetaDataParams), Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::Class_MetaDataParams)
};
void USquadSlotAssignmentPolicy_FirstFree::StaticRegisterNativesUSquadSlotAssignmentPolicy_FirstFree()
{
}
UClass* Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree()
{
	if (!Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.OuterSingleton, Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree.OuterSingleton;
}
USquadSlotAssignmentPolicy_FirstFree::USquadSlotAssignmentPolicy_FirstFree(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USquadSlotAssignmentPolicy_FirstFree);
USquadSlotAssignmentPolicy_FirstFree::~USquadSlotAssignmentPolicy_FirstFree() {}
// ********** End Class USquadSlotAssignmentPolicy_FirstFree ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h__Script_SquadCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USquadSlotAssignmentPolicy, USquadSlotAssignmentPolicy::StaticClass, TEXT("USquadSlotAssignmentPolicy"), &Z_Registration_Info_UClass_USquadSlotAssignmentPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadSlotAssignmentPolicy), 1628153306U) },
		{ Z_Construct_UClass_USquadSlotAssignmentPolicy_FirstFree, USquadSlotAssignmentPolicy_FirstFree::StaticClass, TEXT("USquadSlotAssignmentPolicy_FirstFree"), &Z_Registration_Info_UClass_USquadSlotAssignmentPolicy_FirstFree, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USquadSlotAssignmentPolicy_FirstFree), 986718695U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h__Script_SquadCore_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h__Script_SquadCore_510473280{
	TEXT("/Script/SquadCore"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h__Script_SquadCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_SquadCore_Source_SquadCore_Public_SquadCore_SquadSlotAssignmentPolicy_h__Script_SquadCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
