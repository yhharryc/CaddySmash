// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HitRegisterCollision/HitRegisterHitBoxComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHitRegisterHitBoxComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHitBoxComponent();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterHitBoxComponent_NoRegister();
HITREGISTERCOLLISION_API UClass* Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister();
HITREGISTERCOLLISION_API UEnum* Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode();
HITREGISTERCOLLISION_API UFunction* Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_HitRegisterCollision();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHitRegisterHitBoxComponent Function BeginHitWindow **********************
struct Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics
{
	struct HitRegisterHitBoxComponent_eventBeginHitWindow_Parms
	{
		int32 AttackId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginHitWindow constinit property declarations ************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginHitWindow constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginHitWindow Property Definitions ***********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::NewProp_AttackId = { "AttackId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterHitBoxComponent_eventBeginHitWindow_Parms, AttackId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::NewProp_AttackId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::PropPointers) < 2048);
// ********** End Function BeginHitWindow Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterHitBoxComponent, nullptr, "BeginHitWindow", 	Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::HitRegisterHitBoxComponent_eventBeginHitWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::HitRegisterHitBoxComponent_eventBeginHitWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterHitBoxComponent::execBeginHitWindow)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_AttackId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginHitWindow(Z_Param_AttackId);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterHitBoxComponent Function BeginHitWindow ************************

// ********** Begin Class UHitRegisterHitBoxComponent Function EndHitWindow ************************
struct Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function EndHitWindow constinit property declarations **************************
// ********** End Function EndHitWindow constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterHitBoxComponent, nullptr, "EndHitWindow", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterHitBoxComponent::execEndHitWindow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndHitWindow();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterHitBoxComponent Function EndHitWindow **************************

// ********** Begin Class UHitRegisterHitBoxComponent Function StartContinuous *********************
struct Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics
{
	struct HitRegisterHitBoxComponent_eventStartContinuous_Parms
	{
		int32 AttackId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartContinuous constinit property declarations ***********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartContinuous constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartContinuous Property Definitions **********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::NewProp_AttackId = { "AttackId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HitRegisterHitBoxComponent_eventStartContinuous_Parms, AttackId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::NewProp_AttackId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::PropPointers) < 2048);
// ********** End Function StartContinuous Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterHitBoxComponent, nullptr, "StartContinuous", 	Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::HitRegisterHitBoxComponent_eventStartContinuous_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::HitRegisterHitBoxComponent_eventStartContinuous_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterHitBoxComponent::execStartContinuous)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_AttackId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartContinuous(Z_Param_AttackId);
	P_NATIVE_END;
}
// ********** End Class UHitRegisterHitBoxComponent Function StartContinuous ***********************

// ********** Begin Class UHitRegisterHitBoxComponent Function StopContinuous **********************
struct Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopContinuous constinit property declarations ************************
// ********** End Function StopContinuous constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UHitRegisterHitBoxComponent, nullptr, "StopContinuous", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UHitRegisterHitBoxComponent::execStopContinuous)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopContinuous();
	P_NATIVE_END;
}
// ********** End Class UHitRegisterHitBoxComponent Function StopContinuous ************************

// ********** Begin Class UHitRegisterHitBoxComponent **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHitRegisterHitBoxComponent;
UClass* UHitRegisterHitBoxComponent::GetPrivateStaticClass()
{
	using TClass = UHitRegisterHitBoxComponent;
	if (!Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HitRegisterHitBoxComponent"),
			Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.InnerSingleton,
			StaticRegisterNativesUHitRegisterHitBoxComponent,
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
	return Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UHitRegisterHitBoxComponent_NoRegister()
{
	return UHitRegisterHitBoxComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "HitRegister" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger VirtualTexture" },
		{ "IncludePath", "HitRegisterCollision/HitRegisterHitBoxComponent.h" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QueryInterval_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannel_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitBoxId_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingProfile_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreOwner_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bActive_MetaData[] = {
		{ "Category", "HitRegister" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCandidatesGenerated_MetaData[] = {
		{ "Category", "HitRegister|Events" },
		{ "ModuleRelativePath", "Public/HitRegisterCollision/HitRegisterHitBoxComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHitRegisterHitBoxComponent constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_QueryInterval;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
	static const UECodeGen_Private::FNamePropertyParams NewProp_HitBoxId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingProfile;
	static void NewProp_bIgnoreOwner_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreOwner;
	static void NewProp_bActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bActive;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCandidatesGenerated;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHitRegisterHitBoxComponent constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginHitWindow"), .Pointer = &UHitRegisterHitBoxComponent::execBeginHitWindow },
		{ .NameUTF8 = UTF8TEXT("EndHitWindow"), .Pointer = &UHitRegisterHitBoxComponent::execEndHitWindow },
		{ .NameUTF8 = UTF8TEXT("StartContinuous"), .Pointer = &UHitRegisterHitBoxComponent::execStartContinuous },
		{ .NameUTF8 = UTF8TEXT("StopContinuous"), .Pointer = &UHitRegisterHitBoxComponent::execStopContinuous },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UHitRegisterHitBoxComponent_BeginHitWindow, "BeginHitWindow" }, // 2580511917
		{ &Z_Construct_UFunction_UHitRegisterHitBoxComponent_EndHitWindow, "EndHitWindow" }, // 2919722239
		{ &Z_Construct_UFunction_UHitRegisterHitBoxComponent_StartContinuous, "StartContinuous" }, // 1404165196
		{ &Z_Construct_UFunction_UHitRegisterHitBoxComponent_StopContinuous, "StopContinuous" }, // 1058506074
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHitRegisterHitBoxComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics

// ********** Begin Class UHitRegisterHitBoxComponent Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, Mode), Z_Construct_UEnum_HitRegisterCollision_EHitRegisterHitBoxMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) }; // 1369471840
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_QueryInterval = { "QueryInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, QueryInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QueryInterval_MetaData), NewProp_QueryInterval_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannel_MetaData), NewProp_TraceChannel_MetaData) }; // 838391399
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tags_MetaData), NewProp_Tags_MetaData) }; // 3438578166
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_HitBoxId = { "HitBoxId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, HitBoxId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitBoxId_MetaData), NewProp_HitBoxId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_TargetingProfile = { "TargetingProfile", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, TargetingProfile), Z_Construct_UClass_UHitRegisterTargetingProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingProfile_MetaData), NewProp_TargetingProfile_MetaData) };
void Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bIgnoreOwner_SetBit(void* Obj)
{
	((UHitRegisterHitBoxComponent*)Obj)->bIgnoreOwner = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bIgnoreOwner = { "bIgnoreOwner", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHitRegisterHitBoxComponent), &Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bIgnoreOwner_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIgnoreOwner_MetaData), NewProp_bIgnoreOwner_MetaData) };
void Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bActive_SetBit(void* Obj)
{
	((UHitRegisterHitBoxComponent*)Obj)->bActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bActive = { "bActive", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHitRegisterHitBoxComponent), &Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bActive_MetaData), NewProp_bActive_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_OnCandidatesGenerated = { "OnCandidatesGenerated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHitRegisterHitBoxComponent, OnCandidatesGenerated), Z_Construct_UDelegateFunction_HitRegisterCollision_HitCandidatesEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCandidatesGenerated_MetaData), NewProp_OnCandidatesGenerated_MetaData) }; // 2308320955
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_QueryInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_Tags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_HitBoxId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_TargetingProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bIgnoreOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_bActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::NewProp_OnCandidatesGenerated,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::PropPointers) < 2048);
// ********** End Class UHitRegisterHitBoxComponent Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBoxComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_HitRegisterCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::ClassParams = {
	&UHitRegisterHitBoxComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::Class_MetaDataParams)
};
void UHitRegisterHitBoxComponent::StaticRegisterNativesUHitRegisterHitBoxComponent()
{
	UClass* Class = UHitRegisterHitBoxComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UHitRegisterHitBoxComponent()
{
	if (!Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.OuterSingleton, Z_Construct_UClass_UHitRegisterHitBoxComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHitRegisterHitBoxComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHitRegisterHitBoxComponent);
UHitRegisterHitBoxComponent::~UHitRegisterHitBoxComponent() {}
// ********** End Class UHitRegisterHitBoxComponent ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHitBoxComponent_h__Script_HitRegisterCollision_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHitRegisterHitBoxComponent, UHitRegisterHitBoxComponent::StaticClass, TEXT("UHitRegisterHitBoxComponent"), &Z_Registration_Info_UClass_UHitRegisterHitBoxComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHitRegisterHitBoxComponent), 314494755U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHitBoxComponent_h__Script_HitRegisterCollision_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHitBoxComponent_h__Script_HitRegisterCollision_4058731501{
	TEXT("/Script/HitRegisterCollision"),
	Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHitBoxComponent_h__Script_HitRegisterCollision_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLibrary_CaddySmash_5_7_Plugins_HitRegister_Source_HitRegisterCollision_Public_HitRegisterCollision_HitRegisterHitBoxComponent_h__Script_HitRegisterCollision_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
