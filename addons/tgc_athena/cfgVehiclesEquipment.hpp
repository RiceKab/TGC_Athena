/**
* Custom Equipment boxes, etc...
*/
class rhsusf_ammo_crate : Box_NATO_Ammo_F {
	dlc = "TGC_Athena";
	displayName = "Empty crate with init event handler";
	scope = 2;
	icon = "iconCrateLarge";
	transportMaxWeapons = 40;
	transportMaxMagazines = 20;
	class EventHandlers {
			init = "[_this select 0,1] call rhs_fnc_virtualAmmoBoxUSA;";
	};
	class TransportWeapons {
	};
	class TransportMagazines {
	};
	class TransportItems {
	};
};

class rhsusf_mags_crate : Box_NATO_Wps_F {
	dlc = "TGC_Athena";
	displayName = "Crate filled with stuff";
	scope = 2;
	model = "\rhsusf\addons\rhsusf_weapons2\ammoboxes2\rhsusf_pallet.p3d";
	icon = "iconCrateLarge";
	transportMaxWeapons = 10;
	transportMaxMagazines = 200;
	class TransportWeapons {
	};
	class TransportMagazines {
			class _xx_rhsusf_mag_7x45acp_MHP {   // Not sure what the _xx_ is for
					count = 20;
					magazine = "rhsusf_mag_7x45acp_MHP";
			};
			class _xx_rhsusf_mag_17Rnd_9x19_JHP {
					count = 20;
					magazine = "rhsusf_mag_17Rnd_9x19_JHP";
			};
			class _xx_rhsusf_mag_17Rnd_9x19_FMJ {
					count = 20;
					magazine = "rhsusf_mag_17Rnd_9x19_FMJ";
			};
			class _xx_rhsusf_5Rnd_00Buck {
					count = 20;
					magazine = "rhsusf_5Rnd_00Buck";
			};
			class _xx_rhsusf_8Rnd_00Buck {
					count = 20;
					magazine = "rhsusf_8Rnd_00Buck";
			};
			class _xx_rhsusf_5Rnd_Slug {
					count = 20;
					magazine = "rhsusf_5Rnd_Slug";
			};
			class _xx_rhsusf_8Rnd_Slug {
					count = 20;
					magazine = "rhsusf_8Rnd_Slug";
			};
			class _xx_rhsusf_5Rnd_HE {
					count = 20;
					magazine = "rhsusf_5Rnd_HE";
			};
			class _xx_rhsusf_8Rnd_HE {
					count = 20;
					magazine = "rhsusf_8Rnd_HE";
			};
			class _xx_rhsusf_5Rnd_FRAG {
					count = 20;
					magazine = "rhsusf_5Rnd_FRAG";
			};
			class _xx_rhsusf_8Rnd_FRAG {
					count = 20;
					magazine = "rhsusf_8Rnd_FRAG";
			};
			class _xx_rhs_mag_30Rnd_556x45_Mk318_Stanag {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_Mk318_Stanag";
			};
			class _xx_rhs_mag_30Rnd_556x45_Mk262_Stanag {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_Mk262_Stanag";
			};
			class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag";
			};
			class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer";
			};
			class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red";
			};
			class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green";
			};
			class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow";
			};
			class _xx_rhs_mag_30Rnd_556x45_M200_Stanag {
					count = 20;
					magazine = "rhs_mag_30Rnd_556x45_M200_Stanag";
			};
			class _xx_rhsusf_100Rnd_556x45_soft_pouch {
					count = 20;
					magazine = "rhsusf_100Rnd_556x45_soft_pouch";
			};
			class _xx_rhsusf_100Rnd_556x45_M200_soft_pouch {
					count = 20;
					magazine = "rhsusf_100Rnd_556x45_M200_soft_pouch";
			};
			class _xx_rhsusf_200Rnd_556x45_soft_pouch {
					count = 20;
					magazine = "rhsusf_200Rnd_556x45_soft_pouch";
			};
			class _xx_rhsusf_50Rnd_762x51 {
					count = 20;
					magazine = "rhsusf_50Rnd_762x51";
			};
			class _xx_rhsusf_50Rnd_762x51_m61_ap {
					count = 20;
					magazine = "rhsusf_50Rnd_762x51_m61_ap";
			};
			class _xx_rhsusf_50Rnd_762x51_m62_tracer {
					count = 20;
					magazine = "rhsusf_50Rnd_762x51_m62_tracer";
			};
			class _xx_rhsusf_50Rnd_762x51_m80a1epr {
					count = 20;
					magazine = "rhsusf_50Rnd_762x51_m80a1epr";
			};
			class _xx_rhsusf_50Rnd_762x51_m82_blank {
					count = 20;
					magazine = "rhsusf_50Rnd_762x51_m82_blank";
			};
			class _xx_rhsusf_100Rnd_762x51 {
					count = 20;
					magazine = "rhsusf_100Rnd_762x51";
			};
			class _xx_rhsusf_100Rnd_762x51_m61_ap {
					count = 20;
					magazine = "rhsusf_100Rnd_762x51_m61_ap";
			};
			class _xx_rhsusf_100Rnd_762x51_m62_tracer {
					count = 20;
					magazine = "rhsusf_100Rnd_762x51_m62_tracer";
			};
			class _xx_rhsusf_100Rnd_762x51_m80a1epr {
					count = 20;
					magazine = "rhsusf_100Rnd_762x51_m80a1epr";
			};
			class _xx_rhsusf_100Rnd_762x51_m82_blank {
					count = 20;
					magazine = "rhsusf_100Rnd_762x51_m82_blank";
			};
			class _xx_rhsusf_20Rnd_762x51_m118_special_Mag {
					count = 20;
					magazine = "rhsusf_20Rnd_762x51_m118_special_Mag";
			};
			class _xx_rhsusf_20Rnd_762x51_m993_Mag {
					count = 20;
					magazine = "rhsusf_20Rnd_762x51_m993_Mag";
			};
			class _xx_rhsusf_5Rnd_300winmag_xm2010 {
					count = 20;
					magazine = "rhsusf_5Rnd_300winmag_xm2010";
			};
			class _xx_rhs_mag_M441_HE {
					count = 20;
					magazine = "rhs_mag_M441_HE";
			};
			class _xx_rhs_mag_M433_HEDP {
					count = 20;
					magazine = "rhs_mag_M433_HEDP";
			};
			class _xx_rhs_mag_M781_Practice {
					count = 20;
					magazine = "rhs_mag_M781_Practice";
			};
			class _xx_rhs_mag_M4009 {
					count = 20;
					magazine = "rhs_mag_M4009";
			};
			class _xx_rhs_mag_m576 {
					count = 20;
					magazine = "rhs_mag_m576";
			};
			class _xx_rhs_mag_M585_white {
					count = 20;
					magazine = "rhs_mag_M585_white";
			};
			class _xx_rhs_mag_M661_green {
					count = 20;
					magazine = "rhs_mag_M661_green";
			};
			class _xx_rhs_mag_M662_red {
					count = 20;
					magazine = "rhs_mag_M662_red";
			};
			class _xx_rhs_mag_M713_red {
					count = 20;
					magazine = "rhs_mag_M713_red";
			};
			class _xx_rhs_mag_M714_white {
					count = 20;
					magazine = "rhs_mag_M714_white";
			};
			class _xx_rhs_mag_M715_green {
					count = 20;
					magazine = "rhs_mag_M715_green";
			};
			class _xx_rhs_mag_M716_yellow {
					count = 20;
					magazine = "rhs_mag_M716_yellow";
			};
			class _xx_rhsusf_mag_6Rnd_M433_HEDP {
					count = 20;
					magazine = "rhsusf_mag_6Rnd_M433_HEDP";
			};
			class _xx_rhsusf_mag_6Rnd_M781_Practice {
					count = 20;
					magazine = "rhsusf_mag_6Rnd_M781_Practice";
			};
			class _xx_rhsusf_mag_6Rnd_M576_Buckshot {
					count = 20;
					magazine = "rhsusf_mag_6Rnd_M576_Buckshot";
			};
			class _xx_rhsusf_mag_6Rnd_M441_HE {
					count = 20;
					magazine = "rhsusf_mag_6Rnd_M441_HE";
			};
			class _xx_rhs_mag_m67 {
					count = 20;
					magazine = "rhs_mag_m67";
			};
			class _xx_rhs_mag_m69 {
					count = 20;
					magazine = "rhs_mag_m69";
			};
			class _xx_rhs_mag_mk84 {
					count = 20;
					magazine = "rhs_mag_mk84";
			};
			class _xx_rhs_mag_an_m8hc {
					count = 20;
					magazine = "rhs_mag_an_m8hc";
			};
			class _xx_rhs_mag_an_m14_th3 {
					count = 20;
					magazine = "rhs_mag_an_m14_th3";
			};
			class _xx_rhs_mag_m7a3_cs {
					count = 20;
					magazine = "rhs_mag_m7a3_cs";
			};
			class _xx_rhs_mag_mk3a2 {
					count = 20;
					magazine = "rhs_mag_mk3a2";
			};
			class _xx_rhs_mag_m18_green {
					count = 20;
					magazine = "rhs_mag_m18_green";
			};
			class _xx_rhs_mag_m18_purple {
					count = 20;
					magazine = "rhs_mag_m18_purple";
			};
			class _xx_rhs_mag_m18_red {
					count = 20;
					magazine = "rhs_mag_m18_red";
			};
			class _xx_rhs_mag_m18_yellow {
					count = 20;
					magazine = "rhs_mag_m18_yellow";
			};
			class _xx_Chemlight_green {
					count = 20;
					magazine = "Chemlight_green";
			};
			class _xx_Chemlight_red {
					count = 20;
					magazine = "Chemlight_red";
			};
			class _xx_Chemlight_yellow {
					count = 20;
					magazine = "Chemlight_yellow";
			};
			class _xx_Chemlight_blue {
					count = 20;
					magazine = "Chemlight_blue";
			};
	};
	class TransportItems {
	};
