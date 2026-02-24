// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterRelationResolver.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterRelationResolver() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolver();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHitRegisterRelation ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHitRegisterRelation;
static UEnum* EHitRegisterRelation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterRelation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHitRegisterRelation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation, (UObject*)Z_Construct_UPackage__Script_HitRegisterCollision(), TEXT("EHitRegisterRelation"));
	}
	return Z_Registration_Info_UEnum_EHitRegisterRelation.OuterSingleton;
}
template<> HITREGISTERCOLLISION_NON_ATTRIBUTED_API UEnum* StaticEnum<EHitRegisterRelation>()
{
	return EHitRegisterRelation_StaticEnum();
}
struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Ally.Name", "EHitRegisterRelation::Ally" },
		{ "BlueprintType", "true" },
		{ "Enemy.Name", "EHitRegisterRelation::Enemy" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterRelationResolver.h" },
		{ "Neutral.Name", "EHitRegisterRelation::Neutral" },
		{ "Unknown.Name", "EHitRegisterRelation::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHitRegisterRelation::Ally", (int64)EHitRegisterRelation::Ally },
		{ "EHitRegisterRelation::Enemy", (int64)EHitRegisterRelation::Enemy },
		{ "EHitRegisterRelation::Neutral", (int64)EHitRegisterRelation::Neutral },
		{ "EHitRegisterRelation::Unknown", (int64)EHitRegisterRelation::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HitRegisterCollision,
	nullptr,
	"EHitRegisterRelation",
	"EHitRegisterRelation",
	Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation()
{
	if (!Z_Registration_Info_UEnum_EHitRegisterRelation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHitRegisterRelation.InnerSingleton, Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHitRegisterRelation.InnerSingleton;
}
// ********** End Enum EHitRegisterRelation ********************************************************

// ********** Begin Interface UHitRegisterRelationResolver Function GetRelation ********************
struct HitRegisterRelationResolver_eventGetRelation_Parms
{
	AActor* Source;
	AActor* Target;
	EHitRegisterRelation ReturnValue;

	/** Constructor, initializes return property only **/
	HitRegisterRelationResolver_eventGetRelation_Parms()
		: ReturnValue((EHitRegisterRelation)0)
	{
	}
};
EHitRegisterRelation IHitRegisterRelationResolver::GetRelation(AActor* Source, AActor* Target) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetRelation instead.");
	HitRegisterRelationResolver_eventGetRelation_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UHitRegisterRelationResolver_GetRelation = FName(TEXT("GetRelation"));
EHitRegisterRelation IHitRegisterRelationResolver::Execute_GetRelation(const UObject* O, AActor* Source, AActor* Target)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UHitRegisterRelationResolver::StaticClass()));
	HitRegisterRelationResolver_eventGetRelation_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UHitRegisterRelationResolver_GetRelation);
	if (Func)
	{
		Parms.Source=std::move(Source);
		Parms.Target=std::move(Target);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IHitRegisterRelationResolver*)(O->GetNativeInterfaceAddress(UHitRegisterRelationResolver::StaticClass())))
	{
		Parms.ReturnValue = I->GetRelation_Implementation(Source,Target);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return relation between source and target. */" },
#endif
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterRelationResolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return relation between source and target." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetRelation constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRelation constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRelation Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterRelationResolver_eventGetRelation_Parms, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterRelationResolver_eventGetRelation_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterRelationResolver_eventGetRelation_Parms, ReturnValue), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterRelation, METADATA_PARAMS(0, nullptr) }; // 2666737298
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::PropPointers) < 2048);
// ********** End Function GetRelation Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterRelationResolver, nullptr, "GetRelation", 	Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::PropPointers), 
sizeof(HitRegisterRelationResolver_eventGetRelation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(HitRegisterRelationResolver_eventGetRelation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IHitRegisterRelationResolver::execGetRelation)
{
	P_GET_OBJECT(AActor,Z_Param_Source);
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EHitRegisterRelation*)Z_Param__Result=P_THIS->GetRelation_Implementation(Z_Param_Source,Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Interface UHitRegisterRelationResolver Function GetRelation **********************

// ********** Begin Interface UHitRegisterRelationResolver *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterRelationResolver;
UClass* UHitRegisterRelationResolver::GetPrivateStaticClass()
{
	using TClass = UHitRegisterRelationResolver;
	if (!Z_Registration_Info_UClass_UHitRegisterRelationResolver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterRelationResolver"),
			Z_Registration_Info_UClass_UHitRegisterRelationResolver.InnerSingleton,
			StaticRegisterNativesUHitRegisterRelationResolver,
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
	return Z_Registration_Info_UClass_UHitRegisterRelationResolver.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister()
{
	return UHitRegisterRelationResolver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterRelationResolver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterRelationResolver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UHitRegisterRelationResolver constinit property declarations *********
// ********** End Interface UHitRegisterRelationResolver constinit property declarations ***********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetRelation"), .Pointer = &IHitRegisterRelationResolver::execGetRelation },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterRelationResolver_GetRelation, "GetRelation" }, // 465683152
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IHitRegisterRelationResolver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterRelationResolver_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterRelationResolver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterRelationResolver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterRelationResolver_Statics::ClassParams = {
	&UHitRegisterRelationResolver::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterRelationResolver_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterRelationResolver_Statics::Class_MetaDataParams)
};
void UHitRegisterRelationResolver::StaticRegisterNativesUHitRegisterRelationResolver()
{
	UClass* Class = UHitRegisterRelationResolver::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterRelationResolver_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterRelationResolver()
{
	if (!Z_Registration_Info_UClass_UHitRegisterRelationResolver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterRelationResolver.OuterSingleton, Z_Construct_UClass_UHitRegisterRelationResolver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterRelationResolver.OuterSingleton;
}
UHitRegisterRelationResolver::UHitRegisterRelationResolver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterRelationResolver);
// ********** End Interface UHitRegisterRelationResolver *******************************************

// ********** Begin Class UHitRegisterRelationResolverAsset ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset;
UClass* UHitRegisterRelationResolverAsset::GetPrivateStaticClass()
{
	using TClass = UHitRegisterRelationResolverAsset;
	if (!Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterRelationResolverAsset"),
			Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.InnerSingleton,
			StaticRegisterNativesUHitRegisterRelationResolverAsset,
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
	return Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset_NoRegister()
{
	return UHitRegisterRelationResolverAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Strongly-typed resolver asset base class for collision settings binding.\n */" },
#endif
		{ "IncludePath", "HitRegisterCollision/HitRegisterRelationResolver.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterRelationResolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Strongly-typed resolver asset base class for collision settings binding." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterRelationResolverAsset constinit property declarations ********
// ********** End Class UHitRegisterRelationResolverAsset constinit property declarations **********
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterRelationResolverAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics
UObject* (*const Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UHitRegisterRelationResolver_NoRegister, (int32)VTABLE_OFFSET(UHitRegisterRelationResolverAsset, IHitRegisterRelationResolver), false },  // 1136313711
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::ClassParams = {
	&UHitRegisterRelationResolverAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::Class_MetaDataParams)
};
void UHitRegisterRelationResolverAsset::StaticRegisterNativesUHitRegisterRelationResolverAsset()
{
}
UClass* Z_Construct_UClass_UHitRegisterRelationResolverAsset()
{
	if (!Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.OuterSingleton, Z_Construct_UClass_UHitRegisterRelationResolverAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset.OuterSingleton;
}
UHitRegisterRelationResolverAsset::UHitRegisterRelationResolverAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterRelationResolverAsset);
UHitRegisterRelationResolverAsset::~UHitRegisterRelationResolverAsset() {}
// ********** End Class UHitRegisterRelationResolverAsset ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHitRegisterRelation_StaticEnum, TEXT("EHitRegisterRelation"), &Z_Registration_Info_UEnum_EHitRegisterRelation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2666737298U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterRelationResolver, UHitRegisterRelationResolver::StaticClass, TEXT("UHitRegisterRelationResolver"), &Z_Registration_Info_UClass_UHitRegisterRelationResolver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterRelationResolver), 1136313711U) },
		{ Z_Construct_UClass_UHitRegisterRelationResolverAsset, UHitRegisterRelationResolverAsset::StaticClass, TEXT("UHitRegisterRelationResolverAsset"), &Z_Registration_Info_UClass_UHitRegisterRelationResolverAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterRelationResolverAsset), 2819001564U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_3724415683{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterRelationResolver_h__Script_HitRegisterCollision_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
