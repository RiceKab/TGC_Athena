[
	"TGC Behaviour",
	"Disable/Enable AI Behaviours",
	{
		_unitUnderCursor = _this select 1;
		if (isNull _unitUnderCursor) then
		{
			["Must be placed on a unit"] call Ares_fnc_ShowZeusMessage;
		}	else
		{
			_behaviourArray = ["TARGET", "AUTOTARGET", "MOVE", "ANIM", "AUTOCOMBAT", "PATH", "ALL"];

			_dialogResult = [
				"Disable/Enable AI",
				[
					["Change behaviour", _behaviourArray],
					["Set behaviour to:", ["Enabled", "Disabled"], 1],
					["Change behaviour for:", ["This unit only", "This unit's group"]]
				]
			] call Ares_fnc_ShowChooseDialog;

			if (count _dialogResult > 0) then
			{
				_aiType = _behaviourArray select (_dialogResult select 0);
				_enable = false;

				if ((_dialogResult select 1) == 0) then
				{
					_enable = true;
				};

				switch (_dialogResult select 2) do		// Unit or entire group
				{
					case 0: // Unit only
					{
						if(_enable) then {
							_unitUnderCursor enableAI _aiType;
						} else {
							_unitUnderCursor disableAI _aiType;
						};
					};
					case 1: // Entire group
					{
						if(_enable) then {
							{
								_x enableAI _aiType
							} forEach (units group _unitUnderCursor);
						} else {
							{
								_x disableAI _aiType
							} forEach (units group _unitUnderCursor); ;
						};
					};
				};	// End switch
			};
			["Behaviour change: Done"] call Ares_fnc_ShowZeusMessage;
		};
	}
] call Ares_fnc_RegisterCustomModule;
