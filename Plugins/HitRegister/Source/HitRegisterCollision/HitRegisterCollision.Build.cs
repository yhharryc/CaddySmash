using UnrealBuildTool;

public class HitRegisterCollision : ModuleRules
{
    public HitRegisterCollision(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "HitRegisterCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "DeveloperSettings"
        });
    }
}
