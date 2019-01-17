

using UnrealBuildTool;
using System.Collections.Generic;

public class ExperemTwinStickTarget : TargetRules
{
	public ExperemTwinStickTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ExperemTwinStick" } );
	}
}
