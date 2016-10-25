class CfgPatches
{
	class TGC_Athena
	{
		weapons[] = {};
		requiredVersion = 0.1;
		author[] = { "RiceKab" };
		version = 1;
		versionStr = "b0.1";
		versionAr[] = {0,1,0};

		#include "cfgPatchesUnits.hpp"

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