#include "SquadCore/CompliancePolicy.h"

bool UCompliancePolicy::ShouldObeyFormation_Implementation(const FSquadComplianceContext& Context) const
{
    return true;
}

bool UCompliancePolicy_Always::ShouldObeyFormation_Implementation(const FSquadComplianceContext& Context) const
{
    return true;
}
