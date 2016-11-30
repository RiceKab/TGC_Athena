class CfgPatches
{
	class TGC_Athena
	{
		name = "TGC Athena";
		author = "RiceKab";
		version = "v5";
		versionStr = "v5";
		versionAr[] = {0,5,0};
		requiredVersion = 1.64;

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
};
