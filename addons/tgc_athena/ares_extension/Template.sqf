[
	"CategoryName",
	"ModuleName",
	{
		_modulePos = _this select 0;				// [Pos array]
		_unitUnderCursor = _this select 1;	// Object under cursor (objNull if none)
		if (isNull _unitUnderCursor) then
		{
			["Template block, no unit"] call Ares_fnc_ShowZeusMessage;
		}
		else
		{
			["Template block, with unit"] call Ares_fnc_ShowZeusMessage;
		};
	}
] call Ares_fnc_RegisterCustomModule;
