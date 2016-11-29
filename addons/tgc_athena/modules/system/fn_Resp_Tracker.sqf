params [
  ["_logic", objNull, [objNull]], // Module logic object
  ["_units", [], [[]]], // list of affected units (modified by values in sync[])
  ["_activated", true, [true]]  // true if activated, false if not
];

// EXECUTE
if (_activated) then
{
  /*  TODO: Get target from units
	_allUnits = [];
	{
		if (_x isKindOf "Man") then
		{
			_allUnits pushBack _x;
		};
	} forEach _units;
  */
  _target = _logic getVariable "Target";
	_timeDelayInS = _logic getVariable "Delay";
	_errorMarginInS = _logic getVariable "Interval";
  _respawnMarker = _logic getVariable "RespawnMarker";

	[_target, _timeDelayInS, _errorMarginInS, _respawnMarker] call TGC_fnc_RespawnTracker;
};

true
