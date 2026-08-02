using UnrealBuildTool;

public class DebugFrameworkUI : ModuleRules
{
    public DebugFrameworkUI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UMG",
            "Slate",
            "SlateCore",
            "InputCore",
            "DebugFrameworkCore"
        });
    }
}
