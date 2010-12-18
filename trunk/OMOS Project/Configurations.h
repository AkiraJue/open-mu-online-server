//=======================================================================================
//= Configurations.h
//=======================================================================================

//------------------------------------------------------
//- Start
//------------------------------------------------------
class cConfig
{
public:
	void EditMemory();
	//----------------------------------------------------------------
};

//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define EditInt(Offset,Value) *(unsigned int*) (Offset) = (int)(Value)
#define EditChar(Offset,Value) *(unsigned char*) (Offset) = (char)(Value)

//================================================//
//Transformation Rings						      //
//Defines Transformation Ring Monsters            //
//Configurable On GameServer.ini			      //
//================================================//
#define GS_TRANSFORMATIONRING1	(0x004DBCA4+3) // Default 2
#define GS_TRANSFORMATIONRING2	(0x004DBCAD+3) // Default 7
#define GS_TRANSFORMATIONRING3	(0x004DBCB6+3) // Default 14
#define GS_TRANSFORMATIONRING4	(0x004DBCBF+3) // Default 8
#define GS_TRANSFORMATIONRING5	(0x004DBCC8+3) // Default 9
#define GS_TRANSFORMATIONRING6	(0x004DBCD1+3) // Default 41

//================================================//
//Summon Orbs								      //
//Defines Summon Orb Monsters		              //
//Configurable On GameServer.ini			      //
//================================================//
#define GS_SUMMONORB1			(0x004DA297+1) // Default 26
#define GS_SUMMONORB2 			(0x004DA2C8+1) // Default 32
#define GS_SUMMONORB3			(0x004DA2F9+1) // Default 21
#define GS_SUMMONORB4			(0x004DA32A+1) // Default 20
#define GS_SUMMONORB5			(0x004DA35B+1) // Default 10
#define GS_SUMMONORB6			(0x004DA38C+1) // Default 150
#define GS_SUMMONORB7			(0x004DA3C0+1) // Default 151

//================================================//
//Jewel Prices								      //
//Defines How Much Jewels Cost on NPC             //
//Configurable On GameServer.ini			      //
//================================================//
#define GS_BLESS_PRICE			(0x0055219E+3) // Default 6,000,000
#define GS_SOUL_PRICE			(0x005521C0+3) // Default 9,000,000
#define GS_CHAOS_PRICE			(0x005521E1+3) // Default 810,000
#define GS_LIFE_PRICE			(0x00552203+3) // Default 45,000,000
#define GS_CREATION_PRICE		(0x00552225+3) // Default 36,000,000
#define GS_GUARDIAN_PRICE		(0x005522FF+3) // Default 60,000,000
#define GS_FRUITS_PRICE			(0x005522A0+3) // Default 33,000,000
#define GS_MONARCH_PRICE		(0x005522CE+3) // Default 750,000
#define GS_FEATHER_PRICE		(0x005522DE+3) // Default 180,000
#define GS_BLESSPOT_PRICE		(0x00552337+2) // Default 900,000
#define GS_SOULPOT_PRICE		(0x0055235D+2) // Default 450,000

//================================================//
//Chaos Castle									  //
//Defines Min. Player For Chaos Castle			  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_CCPLAYER				(0x00594890+3) // Default 2
#define GS_CCREWARD1			(0x00597D69+3) // Default Jewel of Life
#define GS_CCREWARD2			(0x00597D23+3) // Default Jewel of Bless
#define GS_CCREWARD3			(0x00597C9F+3) // Default Jewel of Creative
#define GS_CCREWARD4			(0x00597C59+3) // Default Jewel of Soul

//================================================//
//Illusion Temple								  //
//Defines Min. Player For Illusion Temple		  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_ITPLAYER				(0x005DE535+6) // Default 4

//================================================//
//Guild Alliance Members						  //
//Defines Member Req. For Alliance				  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_GUILDALLIANCE		(0x00467E0D+2) // Default 20

//================================================//
//GS UDP Port									  //
//Defines GameServer's UDP Port					  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_UDP_PORT				(0x0056A21F+1) // Default 60006

//================================================//
//Jewel Rates									  //
//Defines Jewel Success Rates					  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_SOUL_RATE_NORMAL		(0x005370C3+3) // Default 60%
#define GS_SOUL_RATE_SPECIAL	(0x00537082+3) // Default 50%
#define GS_SOUL_RATE_SOCKET		(0x005370B7+3) // Default 40%
#define GS_SOUL_LUCK_ADD		(0x0053701C+2) // Default 20%
#define GS_JOL_FAIL_RATE		(0x005378D7+3) // Default 50%

//================================================//
//Blood Castle Reward                             //
//Defines Blood Castles Reward					  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_BC_DROP_ID			(0x0058810D+1) // Default 12 (Reward Jewel of Chaos)
#define GS_BC_DROP_GROUP		(0x0058810B+1) // Default 15 (Reward Jewel of Chaos)

//================================================//
//Chaos Machine Rates						      //
//Defines Rates Of Chaos Machine				  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_CM_MIX_10_NORMAL		(0x005EB63F+6) // Default 60%
#define GS_CM_MIX_10_SPECIAL	(0x005EB65B+6) // Default 50%
#define GS_CM_MIX_10_SOCKET		(0x005EB678+6) // Default 40%
#define GS_CM_MIX_11_12_NORMAL	(0x005EB6CF+6) // Default 60%
#define GS_CM_MIX_11_12_SPECIAL	(0x005EB6EC+6) // Default 50%
#define GS_CM_MIX_11_12_SOCKET	(0x005EB709+6) // Default 40%
#define GS_CM_MIX_13_NORMAL		(0x005EB761+6) // Default 55%
#define GS_CM_MIX_13_SPECIAL	(0x005EB77E+6) // Default 45%
#define GS_CM_MIX_13_SOCKET		(0x005EB79A+6) // Default 35%
#define GS_CM_MIX_10_LUCK		(0x005EB7E7+6) // Default 75%
#define GS_CM_MIX_11_13_LUCK	(0x005EB7F3+6) // Default 75%
#define GS_CM_MIX_LUCK_ADD		(0x005EB7D8+2) // Default 20%

//================================================//
//Dark Lord Pet Rates							  //
//Defines Success Rate Of DL Pet Creations        //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_DARK_HORSE			(0x005EDE9C+6) // Default 60%
#define GS_DARK_HORSE_PRICE		(0x005EDEBB+3) // Default 5,000,000
#define GS_DARK_SPIRIT			(0x005EE59D+6) // Default 60%
#define GS_DARK_SPIRIT_PRICE	(0x005EE5BC+3) // Default 1,000,000

//================================================//
//Item Drop Rates								  //
//Defines Drop Rate Of Items					  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_EXC_DROP_RATE		(0x0041F03E+2) // Default 2000
#define GS_EXC_SKILL_RATE		(0x0041F4EA+6) // Default 100
#define GS_EXC_LUCK_RATE		(0x0041F4F4+6) // Default 1
#define GS_SKILL_RATE			(0x0041F543+6) // Default 6
#define GS_LUCK_RATE			(0x0041F54D+6) // Default 4

//================================================//
//Level Up Points							      //
//Defines Level Up Points For Each Class		  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_LVL_UP_DL1			(0x0050D3BB+2) // Default 7
#define GS_LVL_UP_DL2			(0x00582DF4+2) // Default 7
#define GS_LVL_UP_DL3			(0x00593A74+2) // Default 7
#define GS_LVL_UP_DL4			(0x005C2976+2) // Default 7
#define GS_LVL_UP_DL5			(0x005E7102+2) // Default 7
#define GS_LVL_UP_MG1			(0x0050D3E3+2) // Default 7
#define GS_LVL_UP_MG2			(0x00582DF4+2) // Default 7
#define GS_LVL_UP_MG3			(0x00593A74+2) // Default 7
#define GS_LVL_UP_MG4			(0x005C2976+2) // Default 7
#define GS_LVL_UP_MG5			(0x005E7102+2) // Default 7
#define GS_LVL_UP_NORMAL1		(0x0050D3FA+2) // Default 5
#define GS_LVL_UP_NORMAL2		(0x00582E25+2) // Default 5
#define GS_LVL_UP_NORMAL3		(0x00593AA5+2) // Default 5
#define GS_LVL_UP_NORMAL4		(0x005C29A7+2) // Default 5
#define GS_LVL_UP_NORMAL5		(0x005E7132+2) // Default 5
#define GS_LVL_UP_QUEST1		(0x0050D41E+2) // Default 1
#define GS_LVL_UP_QUEST2		(0x00582E6E+2) // Default 1
#define GS_LVL_UP_QUEST3		(0x00593AEE+2) // Default 1
#define GS_LVL_UP_QUEST4		(0x005C29F0+2) // Default 1
#define GS_LVL_UP_QUEST5		(0x005E717C+2) // Default 1

//================================================//
//Maximum Zen									  //
//Defines Max. Zen On Bank & Inventory		      //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_MAX_INVENTORY		(0x0053F2F7+3) // Default 2,000,000,000
#define GS_MAX_VAULT			(0x00452F4F+2) // Default 100,000,000

//================================================//
//White Wizard Event Reward						  //
//Defines WW Event Reward Drop					  //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_RING_ID				(0x00483628+1) // Default 13 (Reward Ring of Wizardry)
#define GS_RING_GROUP			(0x0048362A+1) // Default 20 (Reward Ring of Wizardry)

//================================================//
//Chaos Machine Mixes							  //
//Defines The Success Rate of CM Mixes		      //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_WINGLVL1MIX			(0x005ED2EA+6) // Default 90% 1st Wing Mix
#define GS_WINGLVL2MIX			(0x005ED2F6+6) // Default 90% 2nd Wing Mix
#define GS_WINGLVL3MIX21		(0x005F2EB2+6) // Default 40% 3rd Wing Mix
#define GS_WINGLVL3MIX22		(0x005F2EBE+6) // Default 40% 3rd Wing Mix
#define GS_WINGLVL3MIX11		(0x005F27B0+6) // Default 60% Condor Mix
#define GS_WINGLVL3MIX12		(0x005F27BC+6) // Default 60% Condor Mix
#define GS_SETITEMMIX1			(0x005F3C7B+6) // Default 80% 380 Level Mix
#define GS_SETITEMMIX2			(0x005F3C87+6) // Default 80% 380 Level Mix
#define GS_DINO_MIX				(0x005EC455+6) // Default 70% Dinorant Mix

//================================================//
//Party Exp										  //
//Defines The Party Exp Scale				      //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_PARTYEXP_2_NORMAL	(0x0051701E+3) // Default 160
#define GS_PARTYEXP_3_NORMAL	(0x0051702D+3) // Default 180
#define GS_PARTYEXP_4_NORMAL	(0x0051703C+3) // Default 200
#define GS_PARTYEXP_5_NORMAL	(0x0051704B+3) // Default 220
#define GS_PARTYEXP_3_SET		(0x00516FE8+3) // Default 230
#define GS_PARTYEXP_4_SET		(0x00516FF7+3) // Default 270
#define GS_PARTYEXP_5_SET		(0x00517006+3) // Default 300

//================================================//
//Map Explorer									  //
//Defines The Max Number of Maps			      //
//Configurable On GameServer.ini				  //
//================================================//
#define GS_MAPEXPLORER			(0x0057A4ED+7) // Default 22

#define GS_TWISTINGSLASH_USELV      (0x004A806B+7)
#define GS_RAGEFULBLOW_USELV        (0x004A8084+7)
#define GS_DEATHSTAB_USELV          (0x004A809D+7)
#define GS_IMPALE_USELV             (0x004A80B6+7)
#define GS_INNERSTRENGTH_USELV      (0x004A80CF+7)
#define GS_PENETRATION_USELV        (0x004A80E8+7)

#define GS_MSNORMAL01				(0x004DB03D+1)
#define GS_MSNORMAL02				(0x004DB05D+1)
#define GS_MSMASTER01				(0x004FAA9A+1)
#define GS_MSMASTER02				(0x004FAABA+1)

#define GS_GFNORMAL01				(0x004DAD67+1)
#define GS_GFNORMAL02				(0x004DAD87+1)
#define GS_GFMASTER01				(0x004FB405+1)
#define GS_GFMASTER02				(0x004FB425+1)

#define GS_SUM_REFLECT_01      (0x004E4313+1) // Summoner Reflect Skill 1-st parametr [default - 2A]
#define GS_SUM_REFLECT_02      (0x004E431A+2) // Summoner Reflect Skill 2-nd parametr [default - 1E]

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cConfig Config;
extern char ConnectMessage[255];