#include "\ares_zeusExtensions\module_header.hpp"

if(isNil "TGC_cb_AAAFire") then 		// Code block not defined
{	
	TGC_cb_AAAFire = 
	{
		
	};
	publicVariable "TGC_cb_AAAFire";
};

_unitUnderCursor = [_logic, true] call Ares_fnc_GetUnitUnderCursor;

if(isNull _unitUnderCursor) then {
	[objnull, "Select an AAA unit"] call bis_fnc_showCuratorFeedbackMessage;
} else {
	
	// DIALOG ASKING FOR PARAMETERS
	
	// Radius
	
	// pos x +- r
	// [_unitUnderCursor, [[x-r, x+r], [y-r, y+r], [z1, z2]], timeBetweenTargets, 8, 10, true] spawn TGC_fnc_AAAFireContinuous;
	
	hint ("unit: " + typeOf _unitUnderCursor);
	[objnull, format ["Unit under cursor: '%1' (CuratorFeedbackMsg)", (typeOf _unitUnderCursor)]] call bis_fnc_showCuratorFeedbackMessage;
};

#include "\ares_zeusExtensions\module_footer.hpp"