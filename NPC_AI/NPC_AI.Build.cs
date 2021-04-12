// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NPC_AI : ModuleRules
{
	public NPC_AI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject",
			"Engine",
			"InputCore", 
			"HeadMountedDisplay",
			"AIModule",
			"GameplayTasks",
			"NavigationSystem"
		});
	}
}
