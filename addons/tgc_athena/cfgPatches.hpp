class CfgPatches
{
	class TGC_Athena
	{
		name = "TGC Athena";
		author = "RiceKab";
		version = "b0.3";
		versionStr = "b0.3";
		versionAr[] = {0,3,0};
		requiredVersion = 0.1;

		#include "cfgPatchesUnits.hpp"

		weapons[] = {};

		requiredAddons[] =
		{
			"A3_UI_F",
			"A3_UI_F_Curator",
			"A3_Functions_F",
			"A3_Functions_F_Curator",
			"A3_Modules_F",
			"A3_Modules_F_Curator",
			"Ares"
		};
	};

	// TODO: Does TGC_Editor have to go separate?
};
