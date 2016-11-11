params [
  ["_logic", objNull, [objNull]], // Module logic object
  ["_units", [], [[]]], // list of affected units (modified by values in sync[])
  ["_activated", true, [true]]  // true if activated, false if not
];

// EXECUTE
if (_activated) then
{
	sleep 2;	// Wait for other scripts
	_allUnits = [];

	_enable = _logic getVariable "Status";

	[_enable] call TGC_Snowstorm;
};

true
