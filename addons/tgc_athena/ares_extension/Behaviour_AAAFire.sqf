[
	"TGC Behaviour",
	"AAA Cannon Fire",
	{
		_unitUnderCursor = _this select 1;
		if (isNull _unitUnderCursor) then
		{
			["Must be placed on a unit"] call Ares_fnc_ShowZeusMessage;
		}	else
		{
			_dialogResult = [
				"Atmospheric AAA Fire",
				[
					["Set behaviour to:", ["Enabled", "Disabled"]]
				]
			] call Ares_fnc_ShowChooseDialog;

			if (count _dialogResult > 0) then	// Not cancelled
			{
				_enable = _dialogResult select 0 == 0;	// Enabled selected
				if(_enable) then
				{
					[_unitUnderCursor] spawn TGC_fnc_AAAFireContinuous;
				} else {
					if(_unitUnderCursor getVariable ["TGC_AAAFireContinuous_enabled", false]) then
					{
						_unitUnderCursor setVariable ["TGC_AAAFireContinuous_enabled", false, false];
						if(_unitUnderCursor getVariable ["TGC_AAAFireContinuous_atmosOnly", false]) then
						{
							_unitUnderCursor enableAI "TARGET";
							_unitUnderCursor enableAI "AUTOTARGET";
						};
					};
				};
			};
		};
	}
] call Ares_fnc_RegisterCustomModule;
