/**
TGC_fnc_AAAFireContinuous

Description:
	AAA unit shoots to a random position generated within the given bounds.
	If atmosOnly is set to true, the AAA will only fire as part of this script.
	Otherwise it will acquire (and prioritize) live targets in its duties.

	Notes:
		- This script also feeds the vehicle with infinite ammo.
		- Atmospheric only relies on disabling of ai components TARGET & AUTOTARGET.
		- Not tested with missile units. Will most likely not work due to multiple fast fire calls.

Parameters:
	1 aaUnit - Vehicle - AAA unit (mobile or static)
	2 posBounds - Array (size 3 - Arrays) - X, Y and Z bounds (min and max can be in either order)
	              ie. [[x1, x2], [y1, y2], [z1, z2]]
								OR
								Array (size 2 - [Number, Array]) - Radius around the unit and Z bounds
								ie. [r, [z1, z2]]
		Default: 500m radius with 250 - 750 height --> [500, [250, 750]]
	3 timeBetweenTargets - Number - Delay between firing at (generated) targets
		Default: 30
	4 salvosPerTarget - Number - Number of salvos to fire at a target
		Default: 5
	5 shotsPerSalvo - Number - Amount of shots per salvo
		Default: 10
	6 atmosOnly - Boolean - Whether the artillery is atmospheric only
		Default: true

Returns:
	true (Best practice) - Only after(!) it ends. It will run the loop until unit death.

Examples:
	Shortest: [aaa1] spawn TGC_fnc_AAAFireContinuous;

	[aaa1, [[3000, 5000], [3000, 5000], [400, 1200]], 30, 5, 10, false] spawn TGC_fnc_AAAFireContinuous;

	In this example the guns will fire at a position with X & Y between 3000-5000 and Z between 400-1200.
	There will be 30s between targets, 8 salvos fired and 10 shots per salvo.
	He will engage live targets in between salvos.
*/

/*
TGC_AAAFireSingleHelper

Description:
	Helper function - Performs a single fire mission for a given unit.

Usage: See above.
*/
if (isNil "TGC_AAAFireSingleHelper") then
{
	TGC_AAAFireSingleHelper =
	{
		params ["_unit", "_targetPos", "_numberOfSalvos", "_shotsPerSalvo"];
		// Targetting is disabled for atmosOnly units
		if (alive gunner _unit && isNull assignedTarget _unit) then {
			_unit doWatch _targetPos;
			sleep 2;						// Time to acquire target
			for "_i" from 1 to _numberOfSalvos do {
				sleep random 2.5;		// Delay between salvos
				if (alive gunner _unit) then		// Extra check in case the vehicle gets decrewed.
				{
					for "_j" from 1 to _shotsPerSalvo do {
						_unit fire (_unit weaponsTurret [0] select 0);
						sleep 0.06;			// Delay between shots
					};
				};
			};
			_unit setVehicleAmmo 1;
		};
	};
	publicVariable "TGC_AAAFireSingleHelper";
};

/*
TGC_AAAFireGeneratePos

Description:
	Helper function - Generates a random target position.

Returns: Position array (objNull if arguments are wrong)
*/
if (isNil "TGC_AAAFireGeneratePos") then
{
	TGC_AAAFireGeneratePos =
	{
		params ["_unit", "_posBounds"];

		_targetPos = objNull;

		if (count _posBounds == 2) then		// Radius around unit
		{
			_radius = _posBounds select 0;
			_z1 = _posBounds select 1 select 0;
			_z2 = _posBounds select 1 select 1;

			_range = random _radius;
			_dir = random 360;
			_unitX = getPos _unit select 0;
			_unitY = getPos _unit select 1;

			_targetPos = [_unitX - ((cos _dir) * _range),
										_unitY - ((sin _dir) * _range),
										(_z1 - random(_z1 - _z2))
									 ];
		};
		if (count _posBounds == 3) then		// Target area
		{
			_x1 = _posBounds select 0 select 0;
			_x2 = _posBounds select 0 select 1;
			_y1 = _posBounds select 1 select 0;
			_y2 = _posBounds select 1 select 1;
			_z1 = _posBounds select 2 select 0;
			_z2 = _posBounds select 2 select 1;

			_targetPos = [(_x1 - random(_x1 - _x2)),
										(_y1 - random(_y1 - _y2)),
										(_z1 - random(_z1 - _z2))
									 ];
		};

		_targetPos
	};
	publicVariable "TGC_AAAFireGeneratePos";
};

params ["_aaUnit",
				["_posBounds", [500, [250, 750]]],
				["_timeBetweenTargets", 30],
				["_salvosPerTarget", 5],
				["_shotsPerSalvo", 10],
				["_atmosOnly", true]
			 ];

_aaUnit setVariable ["TGC_AAAFireContinuous_enabled", true, false];		// Local client variable (Last arg = isPublic)
_unitEnabled = true;

if(_atmosOnly) then {
	_aaUnit disableAI "TARGET";
	_aaUnit disableAI "AUTOTARGET";
	_aaUnit setVariable ["TGC_AAAFireContinuous_atmosOnly", _atmosOnly, false];	// Local client
};

while {(alive gunner _aaUnit) && _unitEnabled} do {
	// Generate random position
	_targetPos = [_aaUnit, _posBounds] call TGC_AAAFireGeneratePos;
	// Fire mission to unit
	[_aaUnit, _targetPos, _salvosPerTarget, _shotsPerSalvo] call TGC_AAAFireSingleHelper;

	sleep _timeBetweenTargets;

	_unitEnabled = _aaUnit getVariable ["TGC_AAAFireContinuous_enabled", false];
};

true
