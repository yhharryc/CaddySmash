using UnrealBuildTool;

public class HitRegisterGASAdapter : ModuleRules
{
    public HitRegisterGASAdapter(ReadOnlyTargetRules Target) : base(Target)
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
            "HitRegisterCore"
        });
    }
}
