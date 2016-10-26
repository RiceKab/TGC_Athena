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
	};
};
