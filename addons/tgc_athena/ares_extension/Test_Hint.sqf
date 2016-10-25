[
	"TGC Test",
	"Hint unit at cursor",
	{
		_unitUnderCursor = _this select 1;
		if (isNull _unitUnderCursor) then
		{
			["No unit under cursor"] call Ares_fnc_ShowZeusMessage;
		}
		else
		{

			["Unit under cursor: " + (typeOf _unitUnderCursor)] call Ares_fnc_ShowZeusMessage;
		};
	}
] call Ares_fnc_RegisterCustomModule;
