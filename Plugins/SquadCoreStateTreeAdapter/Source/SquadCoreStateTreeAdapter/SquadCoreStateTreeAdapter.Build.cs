using UnrealBuildTool;

public class SquadCoreStateTreeAdapter : ModuleRules
{
    public SquadCoreStateTreeAdapter(ReadOnlyTargetRules Target) : base(Target)
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
                "StateTreeModule",
                "SquadCore",
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
