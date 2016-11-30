diag_log format ["%1: %2", "Test - ArgCount: ", (count _this)];

if (count _this != 3) exitWith {
  diag_log "Test - Count not 3, exiting";
};

params [
  ["_logic", objNull, [objNull]], // Module logic object
  ["_units", [], [[]]], // list of affected units (modified by values in sync[])
  ["_activated", true, [true]]  // true if activated, false if not
];

// Arguments are retrieved out of the logic object
// _logic getVariable "ArgumentClassName"

if (_activated) then
{
  _booleanParam = _logic getVariable ["BooleanParam", false];
  _numberParam = _logic getVariable ["NumberParam", -1];
  _stringParam = _logic getVariable ["StringParam", "DefaultString"];
  _defaultParam = _logic getVariable ["DefaultTypeParam", "DefaultTypeString"];
  _defaultParamTwo = _logic getVariable ["DefaultTypeParamTwo", -1];

  // Write to log
  diag_log "Module function called. (Code: TEST123)";
  diag_log format ["%1: %2", "Test - Units passed", _units];
  diag_log format ["%1: %2", "Test - Boolean Parameter", _booleanParam];
  diag_log format ["%1: %2", "Test - Number Parameter", _numberParam];
  diag_log format ["%1: %2", "Test - String Parameter", _stringParam];
  diag_log format ["%1: %2", "Test - Default Parameter", _defaultParam];
  diag_log format ["%1: %2", "Test - Default Parameter", _defaultParamTwo];
};

true
