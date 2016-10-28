// HELPER FUNCTIONS
if (isNil "TGC_ACE_Items_Helper_AddItems") then
{
	TGC_ACE_Items_Helper_AddItems =
	{
		params ["_unitArray", "_itemClassName", "_amount"];
		{
			_unit = _x;
			// Count number of given item already in inventory
			_count = 0;
			{
				if (_x isKindOf [_itemClassName, configFile >> "CfgWeapons"]) then
				{
					_count = _count + 1
				};
			} forEach (items _unit);

			// Add up to given amount
			for [{_idx = _count}, {_idx < _amount}, {_idx = _idx + 1}] do
			{
				_unit addItem _itemClassName;
			};
		} forEach _unitArray;
	};
	publicVariable "TGC_ACE_Items_Helper_AddItems";
};

if (isNil "TGC_ACE_Items_Helper_RemoveItems") then
{
	TGC_ACE_Items_Helper_RemoveItems =
	{
		params ["_unitArray", "_itemClassName"];
		{
			_x removeItems _itemClassName;
		} forEach _unitArray;
	};
	publicVariable "TGC_ACE_Items_Helper_RemoveItems";
};

if (isNil "TGC_ACE_Items_Helper_ProcessItems") then
{
	TGC_ACE_Items_Helper_ProcessItems =
	{
		params ["_statusCode", "_unitArray", "_itemClassName", ["_amount", 1]];
		if (_statusCode < 0) then		// REMOVE FROM ALL
		{
			[_unitArray, _itemClassName] call TGC_ACE_Items_Helper_RemoveItems;
		};
		if (_statusCode == 1) then	// ADD TO ALL
		{
			[_unitArray, _itemClassName, _amount] call TGC_ACE_Items_Helper_AddItems;
		};
	};
	publicVariable "TGC_ACE_Items_Helper_ProcessItems";
};

if (isNil "TGC_ACE_Items_Helper_ProcessNVG") then
{
	TGC_ACE_Items_Helper_ProcessNVG =
	{
		params ["_statusCode", "_unitArray", "_nvgClassName"];
		if (_statusCode < 0) then		// REMOVE FROM ALL
		{
			{
				_unit = _x;
				{
					if (_x isKindOf ["NVGoggles", configFile >> "CfgWeapons"]) then {
							_unit removeItem _x;
					};
				} forEach (items _unit);
				{
					if (_x isKindOf ["NVGoggles", configFile >> "CfgWeapons"]) then {
							_unit unlinkItem _x;
					};
				} forEach (assignedItems _unit);
			} forEach _unitArray;
		};
		if (_statusCode == 1) then	// ADD TO ALL
		{
			// Check if unit already owns a NVG
			{
				_unit = _x;
				_hasNVG = false;
				{
					if (_x isKindOf ["NVGoggles", configFile >> "CfgWeapons"]) exitWith { _hasNVG = true; };
				} forEach (items _unit);

				if (! _hasNVG) then
				{
					{
						if (_x isKindOf ["NVGoggles", configFile >> "CfgWeapons"]) exitWith {_hasNVG = true;};
					} forEach (assignedItems _unit);
				};
				if(! _hasNVG) then		// Not in inventory or linked
				{
					_unit linkItem _nvgClassName;
				};
			} forEach _unitArray;
		};
	};
	publicVariable "TGC_ACE_Items_Helper_ProcessNVG";
};

params [
  ["_logic", objNull, [objNull]], // Module logic object
  ["_units", [], [[]]], // list of affected units (modified by values in sync[])
  ["_activated", true, [true]]  // true if activated, false if not
];

// EXECUTE
if (_activated) then
{
	// Filter out vehicles from the passed units
	_allUnits = [];
	{
		if (_x isKindOf "Man") then
		{
			_allUnits pushBack _x;
		};
	} forEach _units;

  _nvg = _logic getVariable "NVG";
	_nvgType = _logic getVariable "NVGType"; 		// STRING = classname
  _earplugs = _logic getVariable "Earplugs";
  _flashlight = _logic getVariable "Flashlight";
  _flashlightType = _logic getVariable "FlashlightType";  // STRING = classname
  _cabletie = _logic getVariable "CableTie";
  _cabletieAmount = _logic getVariable "CableTieAmount";  // NUMBER
  _dagr = _logic getVariable "DAGR";
  _microDagr = _logic getVariable "MicroDAGR";
  _marksmanGear = _logic getVariable "MarksmanGear";

	// NVG needs a seperate check
	[_nvg, _allUnits, _nvgType] call TGC_ACE_Items_Helper_ProcessNVG;
	[_earplugs, _allUnits, "ACE_Earplugs"] call TGC_ACE_Items_Helper_ProcessItems;
	[_flashlight, _allUnits, _flashlightType] call TGC_ACE_Items_Helper_ProcessItems;
	[_cabletie, _allUnits, "ACE_CableTie", _cabletieAmount] call TGC_ACE_Items_Helper_ProcessItems;
	[_dagr, _allUnits, "ACE_DAGR"] call TGC_ACE_Items_Helper_ProcessItems;
	[_microDagr, _allUnits, "ACE_microDAGR"] call TGC_ACE_Items_Helper_ProcessItems;
	// Marksman gear share status code
	[_marksmanGear, _allUnits, "ACE_ATragMX"] call TGC_ACE_Items_Helper_ProcessItems;
	[_marksmanGear, _allUnits, "ACE_Kestrel4500"] call TGC_ACE_Items_Helper_ProcessItems;
	[_marksmanGear, _allUnits, "ACE_RangeCard"] call TGC_ACE_Items_Helper_ProcessItems;
};

true
