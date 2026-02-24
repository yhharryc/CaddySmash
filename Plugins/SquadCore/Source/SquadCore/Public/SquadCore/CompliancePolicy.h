#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SquadCore/SquadTypes.h"
#include "CompliancePolicy.generated.h"

UCLASS(BlueprintType, Abstract)
class SQUADCORE_API UCompliancePolicy : public UDataAsset
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category="Squad")
    bool ShouldObeyFormation(const FSquadComplianceContext& Context) const;
    virtual bool ShouldObeyFormation_Implementation(const FSquadComplianceContext& Context) const;
};

UCLASS(BlueprintType)
class SQUADCORE_API UCompliancePolicy_Always : public UCompliancePolicy
{
    GENERATED_BODY()

public:
    virtual bool ShouldObeyFormation_Implementation(const FSquadComplianceContext& Context) const override;
};
