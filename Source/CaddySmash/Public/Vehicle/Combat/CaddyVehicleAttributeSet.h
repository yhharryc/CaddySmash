#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CaddyVehicleAttributeSet.generated.h"

#define CADDY_VEHICLE_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class CADDYSMASH_API UCaddyVehicleAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UCaddyVehicleAttributeSet();

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vehicle|Attributes")
    FGameplayAttributeData Health;
    CADDY_VEHICLE_ATTRIBUTE_ACCESSORS(UCaddyVehicleAttributeSet, Health)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Vehicle|Attributes")
    FGameplayAttributeData MaxHealth;
    CADDY_VEHICLE_ATTRIBUTE_ACCESSORS(UCaddyVehicleAttributeSet, MaxHealth)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IncomingDamage, Category="Vehicle|Attributes")
    FGameplayAttributeData IncomingDamage;
    CADDY_VEHICLE_ATTRIBUTE_ACCESSORS(UCaddyVehicleAttributeSet, IncomingDamage)

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_KnockbackResistance, Category="Vehicle|Attributes")
    FGameplayAttributeData KnockbackResistance;
    CADDY_VEHICLE_ATTRIBUTE_ACCESSORS(UCaddyVehicleAttributeSet, KnockbackResistance)

    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_IncomingDamage(const FGameplayAttributeData& OldValue);

    UFUNCTION()
    void OnRep_KnockbackResistance(const FGameplayAttributeData& OldValue);
};

