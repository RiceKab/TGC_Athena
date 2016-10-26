/**
 * Custom (Editor) Modules.
*/

class Logic;
class Module_F : Logic
{
  class ArgumentsBaseUnits
  {
    class Units;
  };

  class ModuleDescription
  {
    // Used to determine sync objects
    class Anything;
    class AnyPerson;
    class AnyVehicle;
    class AnyStaticObject;
    class AnyBrain;
    class AnyAI;
    class AnyPlayer;
    class EmptyDetector;
    /*
			Anything - Any object - persons, vehicles, static objects, etc.
			AnyPerson - Any person. Not vehicles or static objects.
			AnyVehicle - Any vehicle. No persons or static objects.
			AnyStaticObject - Any static object. Not persons or vehicles.
			AnyBrain - Any AI or player. Not empty objects
			AnyAI - Any AI unit. Not players or empty objects
			AnyPlayer - Any player. Not AI units or empty objects
			EmptyDetector - Any trigger
		*/
  };
};

class TGC_ModuleBase : Module_F
{
  // Standard object definitions
  scope = 1; // Editor visibility; 2 will show it in the menu, 1 will hide it.
  scopeCurator = 0; // Not Zeus visible

  displayName = "TGC_ModuleBase_DISPLAYNAME"; // Name displayed in the menu
  category = "TGC_misc";		 // Defined in CfgFactionClasses

  // Name of function triggered once conditions are met
  function = "";
  // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
  functionPriority = 3;
  // 0 for server only execution, 1 for global execution, 2 for persistent global execution
  isGlobal = 1;
  // 1 for module waiting until all synced triggers are activated
  isTriggerActivated = 1;
  // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
  isDisposable = 1;
  // 1 to run init function in Eden Editor as well
  // NOTE: (THIS CHANGES PASSED PARAMETERS TO FUNCTION)
  is3DEN = 0;

    // Menu displayed when the module is placed or double-clicked on by Zeus
    // curatorInfoType = "RscDisplayAttributeModuleNuke";

  class ModuleDescription : ModuleDescription
  {
    description = "TGC MODULE BASE DESCRIPTION"; // Short description, will be formatted as structured text
  };
};

/* TEST */
class TGC_ModuleTest : TGC_ModuleBase
{
  scope = 2;
  displayName = "Test Module";
  function = "TGC_Editor_fnc_Test";

  class Arguments : ArgumentsBaseUnits
  {
    // class Units : Units {}; // Clear Units argument
    class BooleanParam
    {
      displayName = "Boolean parameter"
      description = "Pass a boolean parameter"; // Tooltip description
      typeName = "BOOL"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Enabled	  {name = "Enabled";	value = true; default = 1;}; // Listbox item
        class Disabled  {name = "Disabled"; value = false;};
      };
    };
    class NumberParam
    {
      displayName = "Number parameter"; // Tooltip description
      description = "Pass a number parameter"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      defaultValue = 0;
      // class values { ... };  --> wihtout = inputbox
    };
    class StringParam
    {
      displayName = "String parameter"; // Tooltip description
      description = "Pass a string parameter"; // Tooltip description
      typeName = "STRING"; // Default type I think
      class values
      {
        class Nickname
        {
          name = "Nickname";
          value = "NicknameValue";
          default = 1;
        };
        class Role
        {
          name = "Role";
          value = "RoleValue";
        };
        class Cat
        {
          name = "Cat";
          value = "MeowValue";
        };
      };
    };
    class DefaultTypeParam
    {
      displayName = "Default parameter"
      description = "Pass a parameter of default type"; // Tooltip description
      defaultValue = "";
    };
    class DefaultTypeParamTwo
    {
      displayName = "Default parameter 2"
      description = "Pass a parameter of default type"; // Tooltip description
      defaultValue = "";
    };
  };

  class ModuleDescription : ModuleDescription
  {
    description = "Test Module Description"; // Short description, will be formatted as structured text
    sync[] = {"AnyPerson"}; // Array of synced entities (can contain base classes)
    /*
    class LocationArea_F
    {
      description[] = { // Multi-line descriptions are supported
        "First line",
        "Second line"
      };
      position = 1; // Position is taken into effect
      direction = 1; // Direction is taken into effect
      optional = 1; // Synced entity is optional
      duplicate = 1; // Multiple entities of this type can be synced
      synced[] = {"BLUFORunit","AnyBrain"}; // Pre-define entities like "AnyBrain" can be used. See the list --below-- (above)
    };
    class BLUFORunit
    {
      description = "Short description";
      displayName = "Any BLUFOR unit"; // Custom name
      icon = "iconMan"; // Custom icon (can be file path or CfgVehicleIcons entry)
      side = 1; // Custom side (will determine icon color)
    };
    */
  };
};  // /TGC_Module_Test

/* EQUPMENT */
class TGC_ModuleEquipmentBase : TGC_ModuleBase
{
  category = "TGC_equipment";
};

class TGC_ModuleEquipmentACEItems : TGC_ModuleEquipmentBase
{
  scope = 2;
  displayName = "Common ACE Items";
  function = "TGC_Editor_fnc_ACE_Items";

  // Module arguments
  class Arguments : ArgumentsBaseUnits
  {
    // Arguments shared by specific module type (have to be mentioned in order to be placed on top)
    // class Units : Units {};   // Clear Units argument
    class NVG
    {
      displayName = "Nightvision";  // Argument label
      description = "Add/Remove NVG"; // Tooltip description
      typeName = "BOOL"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Enabled	  {name = "Enabled";	value = true; default = 1;}; // Listbox item
        class Disabled  {name = "Disabled"; value = false;};
      };
    };
    class Earplugs
    {
      displayName = "Earplugs";  // Argument label
      description = "Add/Remove Earplugs"; // Tooltip description
      typeName = "BOOL"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Enabled	  {name = "Enabled";	value = true; default = 1;}; // Listbox item
        class Disabled  {name = "Disabled"; value = false;};
      };
    };
  };

  // Module description. Must inherit from base class, otherwise pre-defined entities won't be available
  class ModuleDescription : ModuleDescription
  {
    description = "Add / Remove some common items"; // Short description, will be formatted as structured text
    sync[] = {"AnyPerson"}; // Array of synced entities (can contain base classes)
  };
};  // /TGC_Module_Equipment_ACE_Items


// REFERENCE CLASSES

/*
class ModuleWeather_F : Module_F {
	author = "Bohemia Interactive";
	class SimpleObject {
		animate[] = {{"animationName1", 1}, {"animationName2", 2}};
		hide[] = {"animationSelection1", "animationSelection2"};
		verticalOffset = 0;
	};
	_generalMacro = "ModuleWeather_F";
	scope = 2;
	scopeCurator = 2;
	curatorInfoType = "RscDisplayAttributesModuleWeather";
	portrait = "\a3\Modules_F_Curator\Data\portraitWeather_ca.paa";
	displayName = "Weather";
	category = "Environment";
	function = "BIS_fnc_moduleWeather";
	isGlobal = 1;
	isTriggerActivated = 1;
	class Arguments {
	class Delay {
		displayName = "Delay";
		description = "How long it takes to change the weather in seconds. It takes at least 10 min for overcast to change.";
		typeName = "NUMBER";
		defaultValue = 0;
	};
	class Overcast {
		displayName = "Overcast";
		description = "Values are between 0 and 1, no change = -1.";
		typeName = "NUMBER";
		defaultValue = -1;
	};
	class Rain {
		displayName = "Rain";
		description = "Values are between 0 and 1, no change = -1.";
		typeName = "NUMBER";
		defaultValue = -1;
	};
	class Fog {
		displayName = "Fog:";
		description = "Values are between 0 and 1, no change = -1.";
		typeName = "NUMBER";
		defaultValue = -1;
	};
	};
	class ModuleDescription : ModuleDescription {
			description = "Set mission weather. Certain changes can take some time to appear.";
	};
};

class ModuleRespawnPosition_F : Module_F {
		author = "Bohemia Interactive";
		class SimpleObject {
				animate[] = {{"animationName1", 1}, {"animationName2", 2}};
				hide[] = {"animationSelection1", "animationSelection2"};
				verticalOffset = 0;
		};
		_generalMacro = "ModuleRespawnPosition_F";
		scope = 2;
		displayName = "Respawn Position";
		category = "Multiplayer";
		icon = "\a3\Modules_f\data\iconRespawn_ca.paa";
		portrait = "\a3\Modules_f\data\portraitRespawn_ca.paa";
		function = "BIS_fnc_moduleRespawnPosition";
		isGlobal = 0;
		isTriggerActivated = 1;
		class Arguments {
				class Name {
						displayName = "Name";
						description = "Respawn name visible in the respawn menu and on a map";
						defaultValue = "";
				};
				class Type {
						displayName = "Type";
						description = "What will be respawned at the position";
						class values {
								class Inf {
										name = "Infantry";
										value = 0;
										default = 1;
								};
								class Vehicles {
										name = "Vehicles (All)";
										value = 1;
								};
								class Motor {
										name = "Vehicles (Wheeled)";
										value = 2;
								};
								class Armor {
										name = "Vehicles (Tracked)";
										value = 3;
								};
								class Air {
										name = "Vehicles (Helicopters)";
										value = 4;
								};
								class Plane {
										name = "Vehicles (Planes)";
										value = 5;
								};
								class Naval {
										name = "Vehicles (Naval)";
										value = 6;
								};
						};
				};
				class Side {
						displayName = "Side";
						description = "Units of which side will be respawned at the position";
						class values {
								class Leader {
										name = "Leading Side";
										value = -1;
										default = 1;
								};
								class BLUFOR {
										name = "BLUFOR";
										value = 1;
								};
								class OPFOR {
										name = "OPFOR";
										value = 0;
								};
								class Independent {
										name = "Independent";
										value = 2;
								};
								class Civilian {
										name = "Civilian";
										value = 3;
								};
						};
				};
				class Marker {
						displayName = "Show to";
						description = "Set who will see the respawn marker";
						class values {
								class All {
										name = "Everyone";
										value = 0;
										default = 1;
								};
								class SideAllies {
										name = "The side and its allies";
										value = 1;
								};
								class Side {
										name = "Only the side";
										value = 2;
								};
						};
				};
				class ShowNotification {
						displayName = "Notification";
						description = "Show notification when the vehicle respawns.";
						class values {
								class Enabled {
										name = "Enabled";
										value = 1;
										default = 1;
								};
								class Disabled {
										name = "Disabled";
										value = 0;
								};
						};
				};
		};
		class ModuleDescription : ModuleDescription {
				description = "Add a respawn position.";
				position = 1;
				direction = 1;
				sync[] = {"AnyVehicle"};
				class AnyVehicle : AnyVehicle {
						optional = 1;
				};
		};
};
class ModuleRespawnVehicle_F : Module_F {
	author = "Bohemia Interactive";
	class SimpleObject {
			animate[] = {{"animationName1", 1}, {"animationName2", 2}};
			hide[] = {"animationSelection1", "animationSelection2"};
			verticalOffset = 0;
	};
	_generalMacro = "ModuleRespawnVehicle_F";
	scope = 2;
	displayName = "Vehicle Respawn";
	category = "Multiplayer";
	icon = "\a3\Modules_f\data\iconRespawn_ca.paa";
	portrait = "\a3\Modules_f\data\portraitRespawn_ca.paa";
	function = "BIS_fnc_moduleRespawnVehicle";
	functionPriority = 1;
	isGlobal = 0;
	isTriggerActivated = 1;
	class Arguments {
			class Delay {
					displayName = "Delay";
					description = "Delay in seconds before the vehicle is respawned (Description.ext delay used when left empty)";
					defaultValue = "";
			};
			class DesertedDistance {
					displayName = "Deserted Distance";
					description = "When the vehicle is abandoned, force respawn after no player is in the given distance [m]. Ignored when the field is left blank.";
					defaultValue = "";
			};
			class RespawnCount {
					displayName = "Tickets";
					description = "Number of respawn tickets, i.e., how many times can the vehicle respawn";
					defaultValue = "";
			};
			class Init {
					displayName = "Expression";
					description = "Code executed when the vehicle respawns (passed arguments are [<newVehicle>,<oldVehicle>])";
					defaultValue = "";
			};
			class Position {
					displayName = "Position";
					description = "Where will the vehicle respawn";
					class values {
							class Start {
									name = "Starting position";
									value = 0;
									default = 1;
							};
							class Death {
									name = "Where it was destroyed";
									value = 1;
							};
							class MarkerDefault {
									name = "Default respawn marker";
									value = 2;
							};
							class MarkerWEST {
									name = "BLUFOR respawn marker";
									value = 4;
							};
							class MarkerEAST {
									name = "OPFOR respawn marker";
									value = 3;
							};
							class MarkerGUER {
									name = "Independent respawn marker";
									value = 5;
							};
							class MarkerCIV {
									name = "Civilian respawn marker";
									value = 6;
							};
							class MarkerKiller {
									name = "Side respawn marker of whoever destroyed the vehicle";
									value = 7;
							};
							class Synced {
									name = "Respawn positions synchronized to the vehicle";
									value = 8;
							};
					};
			};
			class PositionType {
					displayName = "Position selection";
					description = "When multiple respawn positions are available, set which one should be selected";
					class values {
							class Random {
									name = "Random";
									value = 0;
									default = 1;
							};
							class Newest {
									name = "Newest";
									value = 1;
							};
							class Oldest {
									name = "Oldest";
									value = 2;
							};
					};
			};
			class Wreck {
					displayName = "Wreck";
					description = "What will happen to the destroyed vehicle";
					class values {
							class Preserve {
									name = "Preserve";
									value = 0;
							};
							class Delete {
									name = "Delete";
									value = 1;
							};
							class DeleteEffect {
									name = "Delete with an explosion effect";
									value = 2;
									default = 1;
							};
					};
			};
			class ShowNotification {
					displayName = "Notification";
					description = "Show notification when the vehicle respawns.";
					class values {
							class Enabled {
									name = "Enabled";
									value = 1;
									default = 1;
							};
							class Disabled {
									name = "Disabled";
									value = 0;
							};
					};
			};
			class ForcedRespawn {
					displayName = "Forced respawn";
					description = "Respawn all synchronized vehicles when the module is activated (delay and tickets are ignored)";
					class values {
							class Enabled {
									name = "Enabled";
									value = 1;
							};
							class Disabled {
									name = "Disabled";
									value = 0;
									default = 1;
							};
					};
			};
			class RespawnWhenDisabled {
					displayName = "Respawn when disabled";
					description = "Controls whether vehicles should respawn after becoming immobilized.";
					typeName = "BOOL";
					defaultValue = 0;
			};
	};
	class ModuleDescription : ModuleDescription {
			description = "Set vehicle respawn parameters.";
			position = 1;
			sync[] = {"AnyVehicle"};
	};
};
*/
