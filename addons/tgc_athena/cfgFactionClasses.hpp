// Defines editor module categories

// Some defaults are:
// Effects, Intel, NO_CATEGORY(Misc), Multiplayer, ...
class CfgFactionClasses
{
  class NO_CATEGORY; // This is the base game's "Misc" category

  class TGC_misc : NO_CATEGORY
  {
    displayName = "TGC Misc";
  };

	class TGC_equipment : NO_CATEGORY
	{
		displayName = "TGC Equipment";
	};
};