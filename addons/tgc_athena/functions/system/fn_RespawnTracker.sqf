/*
TGC_fnc_RespawnTracker.sqf

Description:
	Creates a tracking respawn on

Parameters:
	1 target - Unit or Vehicle: Target that is being tracked (position)
  2 delay (Optional) - Number: Target's position delayed by given amount of time in seconds.
    default: 180
  3 errorMargin (Optional) - Number: Fidelity of the tracking information. Lower margin means more tracking information.
    default: 30
  4 respawnMarker (Optional) - String: Respawn marker to be used (will be created if it doesn't exist).
    default: "respawn_west_tracker"

Examples:
	[squadleader] spawn TGC_fnc_RespawnTracker;
  [jeep, 300, 30, "respawn_east_jeep"] spawn TGC_fnc_RespawnTracker;
*/
params [
    "_trackingTarget",
    ["_delay", 180],
    ["_errorMargin", 30],
    ["_respawnMarker", "respawn_west_tracker"]
];

// PROCESS INPUTS
_numberOfMarkers = ceil(_delay / _errorMargin);
_timeBetweenUpdate = _delay / _numberOfMarkers;

// Callback to update track target -- Server only
TGC_cb_RESP_TRACKER_TARGET_ONRESPAWN = {
	params ["_newTarget"];
	TGC_RESP_TRACKER_TARGET = _newTarget;
	publicVariable "TGC_RESP_TRACKER_TARGET";
};

// TRACKING MARKER UPDATER -- Server only
[_trackingTarget, _numberOfMarkers, _timeBetweenUpdate] spawn {
  // Creation / setup
	params ["_target", "_numberOfMarkers", "_sleepTime"];
	TGC_RESP_TRACKER_TARGET = _target;
	_target addMPEventHandler ["MPRespawn", TGC_cb_RESP_TRACKER_TARGET_ONRESPAWN];
	_trackingMarkerBaseString = "respawn_tracker_";
	_trackingMarkerIndex = 0;
	// Create markers
	for [{_i = 0}, {_i < _numberOfMarkers}, {_i = _i+1}] do {
		_name = _trackingMarkerBaseString + str(_i);
		createMarker [_name, getPos _target];
		_name setMarkerType "mil_dot";	// TODO:  DELETE THIS
	};
	// Update positions
	while {true} do {
		if (alive TGC_RESP_TRACKER_TARGET) then {
			// hint str(getPos TGC_RESP_TRACKER_TARGET);
			_current = _trackingMarkerBaseString + str(_trackingMarkerIndex);
			_current setMarkerPos (getPos TGC_RESP_TRACKER_TARGET);
			_trackingMarkerIndex = (_trackingMarkerIndex + 1) % _numberOfMarkers;
			TGC_RESP_TRACKER_MARKER = _trackingMarkerBaseString + str(_trackingMarkerIndex);
			publicVariable "TGC_RESP_TRACKER_MARKER";
		};
		sleep _sleepTime;
	};
};

TGC_RESP_TRACKER_LOCKED = false;
publicVariable "TGC_RESP_TRACKER_LOCKED";

TGC_RESP_RESPAWN_MARKER = _respawnMarker;
publicVariable "TGC_RESP_RESPAWN_MARKER";
if(isNil TGC_RESP_RESPAWN_MARKER) then {
  createMarker [TGC_RESP_RESPAWN_MARKER, getPos _trackingTarget];
} else{
  TGC_RESP_RESPAWN_MARKER setMarkerPos (getPos _trackingTarget);
};

// KILLED CALLBACK -- players
TGC_cb_RESP_TRACKER_ONKILLED = {
	if(TGC_RESP_TRACKER_LOCKED) exitWith {true};
	TGC_RESP_TRACKER_LOCKED = true;
	publicVariable "TGC_RESP_TRACKER_LOCKED";
	TGC_RESP_RESPAWN_MARKER setMarkerPos (getMarkerPos TGC_RESP_TRACKER_MARKER);
	// hint "TRACKER LOCKED";
};
publicVariable "TGC_cb_RESP_TRACKER_ONKILLED";

// RESPAWN CALLBACK -- players
TGC_cb_RESP_TRACKER_ONRESPAWN = {
	[] spawn {
		sleep 2;	// Wait a little bit before unlocking.
		if(!TGC_RESP_TRACKER_LOCKED) exitWith {true};
		TGC_RESP_TRACKER_LOCKED = false;
		publicVariable "TGC_RESP_TRACKER_LOCKED";
		// hint "TRACKER UNLOCKED";
	};
};
publicVariable "TGC_cb_RESP_TRACKER_ONRESPAWN";

// TODO: Move this to initPlayerServer.sqf for jip?
{
	_x addMPEventHandler ["MPKilled", TGC_cb_RESP_TRACKER_ONKILLED];
	_x addMPEventHandler ["MPRespawn", TGC_cb_RESP_TRACKER_ONRESPAWN];
} forEach playableUnits;
