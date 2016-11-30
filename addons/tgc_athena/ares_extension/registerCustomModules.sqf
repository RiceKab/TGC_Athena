_scriptFiles = [
		// "Test_Hint",
		"Behaviour_DisableAI",
		"Behaviour_AAAFire",
		"Effect_SnowStorm"
		/* Add modules here */
];

{
	call compile preprocessFileLineNumbers ("\tgc_athena\ares_extension\" + _x + ".sqf");
} forEach _scriptFiles;
