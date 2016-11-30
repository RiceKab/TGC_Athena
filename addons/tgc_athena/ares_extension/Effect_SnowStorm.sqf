[
	"TGC Effects",
	"Enable/Disable snowstorm",
	{
    _dialogResult = [
      "Snowstorm",
      [
        ["Set to:", ["Enabled", "Disabled"]]
      ]
    ] call Ares_fnc_ShowChooseDialog;

    if (count _dialogResult > 0) then	// Not cancelled
    {
      _enable = _dialogResult select 0 == 0;	// Enabled selected = true
      [_enable] call TGC_fnc_Snowstorm;
    };
  }
] call Ares_fnc_RegisterCustomModule;
