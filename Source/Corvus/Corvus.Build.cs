// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Corvus : ModuleRules
{
	public Corvus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "LevelSequence", "MovieScene" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
