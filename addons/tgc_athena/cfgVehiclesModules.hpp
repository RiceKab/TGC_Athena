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

  class ModuleDescription;
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
  isDisposable = 0;
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
/*
class TGC_ModuleTest : TGC_ModuleBase
{
  scope = 2;
  displayName = "Test Module";
  function = "TGC_Editor_fnc_Test";

  class Arguments : ArgumentsBaseUnits
  {
    class Units : Units {}; // Clear Units argument
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
  };
};  // /TGC_Module_Test
*/

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
    class Units : Units {};   // Clear Units argument
    class NVG
    {
      displayName = "Nightvision";  // Argument label
      description = "Add/Remove NVG"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0;};
        class Enabled {name = "Add (If not already owned)";	value = 1; default = 1};
      };
    };

    class NVGType
    {
      displayName = "Nightvision Type";  // Argument label
      description = "Nightvision type (ignored if not added)"; // Tooltip description
      typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class US_Mono
        {
          name = "US - AN/PVS-14 Monocular Night Vision";
          value = "rhsusf_ANPVS_14";
          default = 1;
        };
        class US_Bino
        {
          name = "US - AN/PVS-15 Binocular Night Vision";
          value = "rhsusf_ANPVS_15";
        };
      };
    };

    class Earplugs
    {
      displayName = "Earplugs";  // Argument label
      description = "Add/Remove Earplugs"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0;};
        class Enabled {name = "Add (If not already owned)";	value = 1; default = 1};
      };
    };

    class Flashlight
    {
      displayName = "Flashlight";  // Argument label
      description = "Add/Remove Flashlight"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };

    class FlashlightType
    {
      displayName = "Flashlight Type";  // Argument label
      description = "Flashlight type (ignored if not added)"; // Tooltip description
      typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Flashlight_MX991
        {
          name = "Fulton MX-991";
          value = "ACE_Flashlight_MX991";
          default = 1;
        };
        class Flashlight_KSF1
        {
          name = "KSF1";
          value = "ACE_Flashlight_KSF1";
        };
        class Flashlight_XL50
        {
          name = "Maglite XL50";
          value = "ACE_Flashlight_XL50";
        };
      };
    };

    class CableTie
    {
      displayName = "Cable Ties";  // Argument label
      description = "Add/Remove Cable Ties"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };

    class CableTieAmount
    {
      displayName = "Cable Ties";  // Argument label
      description = "Number of cable ties"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      defaultValue = 0;
    };

    class DAGR
    {
      displayName = "DAGR";  // Argument label
      description = "Add/Remove DAGR"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };

    class MicroDAGR
    {
      displayName = "MicroDAGR";  // Argument label
      description = "Add/Remove MicroDAGR"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };

    class MarksmanGear
    {
      displayName = "Marksman gear";  // Argument label
      description = "Add/Remove Kestrel, AtragX & Range Card"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };

    class MortarGear
    {
      displayName = "Mortar gear";  // Argument label
      description = "Add/Remove Map Tools and 82mm Range Card"; // Tooltip description
      typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
      class values
      {
        class Disabled {name = "Remove"; value = -1;};
        class Nothing {name = "Default (Do nothing)"; value = 0; default = 1;};
        class Enabled {name = "Add (If not already owned)";	value = 1;};
      };
    };
  };

  // Module description. Must inherit from base class, otherwise pre-defined entities won't be available
  class ModuleDescription : ModuleDescription
  {
    description = "Add / Remove some common ACE items"; // Short description, will be formatted as structured text
  };
};  // /TGC_Module_Equipment_ACE_Items
