

using UnrealBuildTool;
using System.Collections.Generic;

public class ExperemTwinStickEditorTarget : TargetRules
{
	public ExperemTwinStickEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "ExperemTwinStick" } );
	}
}
