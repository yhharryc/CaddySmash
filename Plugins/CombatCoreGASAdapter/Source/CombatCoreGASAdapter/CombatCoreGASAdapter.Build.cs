using UnrealBuildTool;

public class CombatCoreGASAdapter : ModuleRules
{
    public CombatCoreGASAdapter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "GameplayAbilities",
            "GameplayTasks",
            "CombatCore"
        });
    }
}
