_scriptFiles = [
		"Test_Hint",
		"Behaviour_DisableAI",
		"Behaviour_AAAFire"
	];
{
	call compile preprocessFileLineNumbers ("\tgc_athena\ares_extension\" + _x + ".sqf");
} forEach _scriptFiles;
