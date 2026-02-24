using UnrealBuildTool;

public class SquadCore : ModuleRules
{
    public SquadCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
                "AIModule",
                "CombatCore"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GameplayTasks"
            }
        );
    }
}
