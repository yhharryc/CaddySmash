using UnrealBuildTool;

public class SquadCoreDebugAdapter : ModuleRules
{
    public SquadCoreDebugAdapter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "SquadCore",
                "CombatCore",
                "DebugFrameworkCore",
                "UMG",
                "Slate",
                "SlateCore"
            }
        );
    }
}
