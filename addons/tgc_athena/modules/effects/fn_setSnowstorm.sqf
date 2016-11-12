params [
  ["_logic", objNull, [objNull]], // Module logic object
  ["_units", [], [[]]], // list of affected units (modified by values in sync[])
  ["_activated", true, [true]]  // true if activated, false if not
];

// EXECUTE
if (_activated) then
{
  [true] call TGC_fnc_Snowstorm;
};

true
