class CfgFunctions
{
	// Inits ares extensions
	class TGC_Athena_Init
	{
		class init
		{
			file = "\tgc_athena\functions\init";

			class InitAthena { preInit = 1 };
		};
	};

	class TGC
	{
		class behaviour
		{
			file = "\tgc_athena\functions\behaviour";

			class AAAFireContinuous;
		}

		class effects
		{
			file = "\tgc_athena\functions\effects";

			class Snowstorm;
		};

		class system
		{
			file = "\tgc_athena\functions\system";

			class RespawnTracker;
		};
	};

	class TGC_Editor
	{
		class base
		{
			file = "\tgc_athena\modules";

			class Test;
		};
/*
		class behaviour
		{
			file = "\tgc_athena\modules\behaviour";

			//class AAAFire;
		};
*/
		class equipment
		{
			file = "\tgc_athena\modules\equipment";

			class ACE_Items;
		};

		class effects
		{
			file = "\tgc_athena\modules\effects";

			class setSnowstorm;
		};

		class system
		{
			file = "\tgc_athena\modules\system";

			class Resp_Tracker;
		};
	};
};
