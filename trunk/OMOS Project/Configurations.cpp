//=======================================================================================
//= Configurations.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
cConfig Config;
char ConnectMessage[255];

//------------------------------------------------------
//- Start
//------------------------------------------------------
void cConfig::EditMemory()
{
	//================================================//
	// Transformation Rings							  //
	//================================================//
	*(unsigned int*) GS_TRANSFORMATIONRING1 = GetPrivateProfileInt("Common","TransformRing1",2,INI_COMMON);
	*(unsigned int*) GS_TRANSFORMATIONRING2 = GetPrivateProfileInt("Common","TransformRing2",7,INI_COMMON);
	*(unsigned int*) GS_TRANSFORMATIONRING3 = GetPrivateProfileInt("Common","TransformRing3",14,INI_COMMON);
	*(unsigned int*) GS_TRANSFORMATIONRING4 = GetPrivateProfileInt("Common","TransformRing4",8,INI_COMMON);
	*(unsigned int*) GS_TRANSFORMATIONRING5 = GetPrivateProfileInt("Common","TransformRing5",9,INI_COMMON); 
	*(unsigned int*) GS_TRANSFORMATIONRING6 = GetPrivateProfileInt("Common","TransformRing6",41,INI_COMMON);
	//================================================//
	// Summon Orbs									  //
	//================================================//
	*(unsigned char*) GS_SUMMONORB1 = (BYTE)GetPrivateProfileInt("Common","OrbSummon1",26,INI_COMMON);
	*(unsigned char*) GS_SUMMONORB2 = (BYTE)GetPrivateProfileInt("Common","OrbSummon2",32,INI_COMMON);
	*(unsigned char*) GS_SUMMONORB3 = (BYTE)GetPrivateProfileInt("Common","OrbSummon3",21,INI_COMMON);
	*(unsigned char*) GS_SUMMONORB4 = (BYTE)GetPrivateProfileInt("Common","OrbSummon4",20,INI_COMMON);
	*(unsigned char*) GS_SUMMONORB5 = (BYTE)GetPrivateProfileInt("Common","OrbSummon5",10,INI_COMMON);
	*(unsigned char*) GS_SUMMONORB6 = (BYTE)GetPrivateProfileInt("Common","OrbSummon6",150,INI_COMMON); 
	*(unsigned char*) GS_SUMMONORB7 = (BYTE)GetPrivateProfileInt("Common","OrbSummon7",151,INI_COMMON);
	//================================================//
	// Jewel Prices									  //
	//================================================//
	*(unsigned int*) GS_BLESS_PRICE		= (DWORD)GetPrivateProfileInt("Common","JewelOfBlessPrice",6000000,INI_COMMON);
	*(unsigned int*) GS_SOUL_PRICE		= (DWORD)GetPrivateProfileInt("Common","JewelOfSoulPrice",9000000,INI_COMMON);
	*(unsigned int*) GS_CHAOS_PRICE		= (DWORD)GetPrivateProfileInt("Common","JewelOfChaosPrice",810000,INI_COMMON); 
	*(unsigned int*) GS_LIFE_PRICE		= (DWORD)GetPrivateProfileInt("Common","JewelOfLifePrice",45000000,INI_COMMON);
	*(unsigned int*) GS_CREATION_PRICE	= (DWORD)GetPrivateProfileInt("Common","JewelOfCreationPrice",36000000,INI_COMMON);
	*(unsigned int*) GS_GUARDIAN_PRICE	= (DWORD)GetPrivateProfileInt("Common","JewelOfGuardianPrice",60000000,INI_COMMON);;
	*(unsigned int*) GS_FRUITS_PRICE	= (DWORD)GetPrivateProfileInt("Common","FruitPrice",33000000,INI_COMMON);
	*(unsigned int*) GS_MONARCH_PRICE	= (DWORD)GetPrivateProfileInt("Common","CrestOfMonarchPrice",750000,INI_COMMON);
	*(unsigned int*) GS_FEATHER_PRICE	= (DWORD)GetPrivateProfileInt("Common","LochsFeatherPrice",180000,INI_COMMON);
	*(unsigned int*) GS_BLESSPOT_PRICE	= (DWORD)GetPrivateProfileInt("Common","PotionOfBlessPrice",900000,INI_COMMON);
	*(unsigned int*) GS_SOULPOT_PRICE	= (DWORD)GetPrivateProfileInt("Common","PotionOfSoulPrice",450000,INI_COMMON);
	//================================================//
	// Chaos Castle Rewards							  //
	//================================================//
	BYTE ItemGroup;
	BYTE ItemID;
	ItemGroup = GetPrivateProfileInt("Common","ChaosCastleRewardType1IndexID",14,INI_COMMON);
	ItemID = GetPrivateProfileInt("Common","ChaosCastleRewardType1GroupID",16,INI_COMMON);
	*(unsigned char*) GS_CCREWARD1 = ItemGroup * 512 + ItemID;
	
	ItemGroup = GetPrivateProfileInt("Common","ChaosCastleRewardType2IndexID",14,INI_COMMON);
	ItemID = GetPrivateProfileInt("Common","ChaosCastleRewardType2GroupID",13,INI_COMMON);
	*(unsigned char*) GS_CCREWARD2 = ItemGroup * 512 + ItemID;

	ItemGroup = GetPrivateProfileInt("Common","ChaosCastleRewardType3IndexID",14,INI_COMMON);
	ItemID = GetPrivateProfileInt("Common","ChaosCastleRewardType3GroupID",22,INI_COMMON);
	*(unsigned char*) GS_CCREWARD3 = ItemGroup * 512 + ItemID;

	ItemGroup = GetPrivateProfileInt("Common","ChaosCastleRewardType4IndexID",14,INI_COMMON);
	ItemID = GetPrivateProfileInt("Common","ChaosCastleRewardType4GroupID",14,INI_COMMON);
	*(unsigned char*) GS_CCREWARD4 = ItemGroup * 512 + ItemID;
	//================================================//
	// Chaos Castle Players							  //
	//================================================// 
	*(unsigned char*) GS_CCPLAYER = (BYTE)GetPrivateProfileInt("Common","ChaosCastleMinPlayers",2,INI_COMMON);
	//================================================//
	// Illusion Temple Players						  //
	//================================================//
	*(unsigned char*) GS_ITPLAYER = (BYTE)GetPrivateProfileInt("Common","IllusionTempleMinPlayers",4,INI_COMMON);
	//================================================//
	// Guild Alliance Members						  //
	//================================================//
	*(unsigned char*) GS_GUILDALLIANCE = (BYTE)GetPrivateProfileInt("Common","GuildAllianceMinPlayers",20,INI_COMMON);
	//================================================//
	// UDP Port										  //
	//================================================//
	*(unsigned int*) GS_UDP_PORT = (DWORD)GetPrivateProfileInt("Common","UDP-Port",60006,INI_COMMON);
	//================================================//
	// Jewel Success Rates							  //
	//================================================//
	*(unsigned char*) GS_SOUL_RATE_NORMAL	= (BYTE)GetPrivateProfileInt("Common","SoulSuccessRateNormal",60,INI_COMMON);
	*(unsigned char*) GS_SOUL_RATE_SPECIAL	= (BYTE)GetPrivateProfileInt("Common","SoulSuccessRateSpecial",50,INI_COMMON);
	*(unsigned char*) GS_SOUL_RATE_SOCKET	= (BYTE)GetPrivateProfileInt("Common","SoulSuccessRateSocket",40,INI_COMMON);
	*(unsigned char*) GS_SOUL_LUCK_ADD		= (BYTE)GetPrivateProfileInt("Common","SoulSuccessRateIncreaseWithLuck",20,INI_COMMON);
	*(unsigned char*) GS_JOL_FAIL_RATE		= (BYTE)GetPrivateProfileInt("Common","LifeFailRate",50,INI_COMMON);
	//================================================//
	// Blood Castle Reward							  //
	//================================================//
	*(unsigned char*) GS_BC_DROP_ID		= (BYTE)GetPrivateProfileInt("Common","BCItemDropIndexID",12,INI_COMMON);
	*(unsigned char*) GS_BC_DROP_GROUP	= (BYTE)GetPrivateProfileInt("Common","BCItemDropGroupID",15,INI_COMMON);
	//================================================//
	// Party Exp Scale								  //
	//================================================//
	*(unsigned int *) GS_PARTYEXP_2_NORMAL  = (DWORD)GetPrivateProfileIntA("Common","NormalParty2Exp",160,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_3_NORMAL  = (DWORD)GetPrivateProfileIntA("Common","NormalParty3Exp",180,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_4_NORMAL  = (DWORD)GetPrivateProfileIntA("Common","NormalParty4Exp",200,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_5_NORMAL  = (DWORD)GetPrivateProfileIntA("Common","NormalParty5Exp",220,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_3_SET		= (DWORD)GetPrivateProfileIntA("Common","SetParty3Exp",230,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_4_SET		= (DWORD)GetPrivateProfileIntA("Common","SetParty4Exp",270,INI_COMMON);
	*(unsigned int *) GS_PARTYEXP_5_SET		= (DWORD)GetPrivateProfileIntA("Common","SetParty5Exp",300,INI_COMMON);
	//================================================//
	// Chaos Machine Mixes							  //
	//================================================//
	*(unsigned char*) GS_WINGLVL1MIX	= (BYTE)GetPrivateProfileInt("Common","WingMixLvl1SuccessRate",90,INI_COMMON);
	*(unsigned char*) GS_WINGLVL2MIX	= (BYTE)GetPrivateProfileInt("Common","WingMixLvl2SuccessRate",90,INI_COMMON);
	*(unsigned char*) GS_WINGLVL3MIX21	= (BYTE)GetPrivateProfileInt("Common","WingMixLvl3SuccessRate",40,INI_COMMON);
	*(unsigned char*) GS_WINGLVL3MIX22	= (BYTE)GetPrivateProfileInt("Common","WingMixLvl3SuccessRate",40,INI_COMMON);
	*(unsigned char*) GS_WINGLVL3MIX11	= (BYTE)GetPrivateProfileInt("Common","CondorMixSuccessRate",35,INI_COMMON);
	*(unsigned char*) GS_WINGLVL3MIX12	= (BYTE)GetPrivateProfileInt("Common","CondorMixSuccessRate",35,INI_COMMON);
	*(unsigned char*) GS_SETITEMMIX1	= (BYTE)GetPrivateProfileInt("Common","380LevelMixSuccessRate",80,INI_COMMON);
	*(unsigned char*) GS_SETITEMMIX2	= (BYTE)GetPrivateProfileInt("Common","380LevelMixSuccessRate",80,INI_COMMON);
	*(unsigned int*) GS_DINO_MIX		= (BYTE)GetPrivateProfileInt("Common","DinorantMixSuccessRate",70,INI_COMMON);
	//================================================//
	// White Wizard Reward							  //
	//================================================//
	*(unsigned char*) GS_RING_ID	= (BYTE)GetPrivateProfileInt("Common","WWItemDropIndexID",13,INI_COMMON);
	*(unsigned char*) GS_RING_GROUP = (BYTE)GetPrivateProfileInt("Common","WWItemDropGroupID",20,INI_COMMON);
	//================================================//
	// Maximum Zen									  //
	//================================================//
	*(unsigned int*) GS_MAX_INVENTORY	= (DWORD)GetPrivateProfileInt("Common","MaxZenInBag",2000000000,INI_COMMON);
	*(unsigned int*) GS_MAX_VAULT		= (DWORD)GetPrivateProfileInt("Common","MaxZenInVault",100000000,INI_COMMON);
	//================================================//
	// Level Up Points								  //
	//================================================//
	*(unsigned char*) GS_LVL_UP_DL1		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDL",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_DL2		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDL",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_DL3		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDL",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_DL4		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDL",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_DL5		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDL",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_MG1		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForMG",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_MG2		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForMG",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_MG3		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForMG",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_MG4		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForMG",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_MG5		= (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForMG",7,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_NORMAL1 = (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDK-ELF-DW-SUM",5,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_NORMAL2 = (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDK-ELF-DW-SUM",5,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_NORMAL3 = (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDK-ELF-DW-SUM",5,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_NORMAL4 = (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDK-ELF-DW-SUM",5,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_NORMAL5 = (BYTE)GetPrivateProfileInt("Common","LevelUpPointsForDK-ELF-DW-SUM",5,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_QUEST1	= (BYTE)GetPrivateProfileInt("Common","ExtraPointsAfterMarlonQuest",1,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_QUEST2	= (BYTE)GetPrivateProfileInt("Common","ExtraPointsAfterMarlonQuest",1,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_QUEST3	= (BYTE)GetPrivateProfileInt("Common","ExtraPointsAfterMarlonQuest",1,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_QUEST4	= (BYTE)GetPrivateProfileInt("Common","ExtraPointsAfterMarlonQuest",1,INI_COMMON);
	*(unsigned char*) GS_LVL_UP_QUEST5	= (BYTE)GetPrivateProfileInt("Common","ExtraPointsAfterMarlonQuest",1,INI_COMMON);
	//================================================//
	// Item Drop Rates								  //
	//================================================//
	*(unsigned int*) GS_EXC_DROP_RATE	= (DWORD)GetPrivateProfileInt("Common","ExcDropRate",2000,INI_COMMON);
	*(unsigned int*) GS_EXC_SKILL_RATE	= (DWORD)GetPrivateProfileInt("Common","ExcSkillDropRate",100,INI_COMMON);
	*(unsigned int*) GS_EXC_LUCK_RATE	= (DWORD)GetPrivateProfileInt("Common","ExcLuckDropRate",1,INI_COMMON);
	*(unsigned int*) GS_SKILL_RATE		= (DWORD)GetPrivateProfileInt("Common","NormalSkillDropRate",6,INI_COMMON);
	*(unsigned int*) GS_LUCK_RATE		= (DWORD)GetPrivateProfileInt("Common","NormalLuckDropRate",4,INI_COMMON);
	//================================================//
	// Dark Lord Pet Rates							  //
	//================================================//
	*(unsigned int*) GS_DARK_HORSE			= (DWORD)GetPrivateProfileInt("Common","DarkHorseMixSuccessRate",60,INI_COMMON);
	*(unsigned int*) GS_DARK_HORSE_PRICE	= (DWORD)GetPrivateProfileInt("Common","DarkHorseMixPrice",5000000,INI_COMMON); 
	*(unsigned int*) GS_DARK_SPIRIT			= (DWORD)GetPrivateProfileInt("Common","DarkSpiritMixSuccessRate",60,INI_COMMON);
	*(unsigned int*) GS_DARK_SPIRIT_PRICE	= (DWORD)GetPrivateProfileInt("Common","DarkSpiritMixPrice",1000000,INI_COMMON);
	//================================================//
	// Chaos Machine Rates							  //
	//================================================//
	*(unsigned char*) GS_CM_MIX_10_NORMAL		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+10RateNormal",60,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_10_SPECIAL		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+10RateSpecial",50,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_10_SOCKET		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+10RateSocket",40,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_11_12_NORMAL	= (BYTE)GetPrivateProfileInt("Common","ChaosMix+11-12RateNormal",60,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_11_12_SPECIAL	= (BYTE)GetPrivateProfileInt("Common","ChaosMix+11-12RateSpecial",50,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_11_12_SOCKET	= (BYTE)GetPrivateProfileInt("Common","ChaosMix+11-12RateSocket",40,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_13_NORMAL		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+13RateNormal",55,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_13_SPECIAL		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+13RateSpecial",45,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_13_SOCKET		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+13RateSocket",35,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_10_LUCK			= (BYTE)GetPrivateProfileInt("Common","ChaosMix+10RateWithLuck",75,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_11_13_LUCK		= (BYTE)GetPrivateProfileInt("Common","ChaosMix+11-13RateWithLuck",75,INI_COMMON);
	*(unsigned char*) GS_CM_MIX_LUCK_ADD		= (BYTE)GetPrivateProfileInt("Common","ChaosMixRateIncreaseWithLuck",20,INI_COMMON);
	//================================================//
	// Character Skill								  //
	//================================================//
	*(unsigned int *) GS_TWISTINGSLASH_USELV	= (DWORD)GetPrivateProfileIntA("Common", "TwistingSlashMinLevel",80, INI_COMMON);
	*(unsigned int *) GS_RAGEFULBLOW_USELV		= (DWORD)GetPrivateProfileIntA("Common", "RagefulBlowMinLevel",170, INI_COMMON);
	*(unsigned int *) GS_DEATHSTAB_USELV		= (DWORD)GetPrivateProfileIntA("Common", "DeathStabMinLevel",160, INI_COMMON);
	*(unsigned int *) GS_IMPALE_USELV			= (DWORD)GetPrivateProfileIntA("Common", "ImpaleMinLevel",25, INI_COMMON);
	*(unsigned int *) GS_INNERSTRENGTH_USELV	= (DWORD)GetPrivateProfileIntA("Common", "GreaterFortitudeMinLevel",120, INI_COMMON);
	*(unsigned int *) GS_PENETRATION_USELV		= (DWORD)GetPrivateProfileIntA("Common", "PenetrationMinLevel",130, INI_COMMON);
	*(unsigned int *) GS_MSNORMAL01 = (DWORD)GetPrivateProfileIntA("Common", "ManaShieldAgiDiv",50, INI_COMMON);
	*(unsigned int *) GS_MSMASTER01 = (DWORD)GetPrivateProfileIntA("Common", "ManaShieldAgiDiv",50, INI_COMMON);
	*(unsigned int *) GS_MSNORMAL02 = (DWORD)GetPrivateProfileIntA("Common", "ManaShieldEneDiv",200, INI_COMMON);
	*(unsigned int *) GS_MSMASTER02 = (DWORD)GetPrivateProfileIntA("Common", "ManaShieldEneDiv",200, INI_COMMON);
	*(unsigned int *) GS_GFNORMAL01 = (DWORD)GetPrivateProfileIntA("Common", "GreatFortitudeAgiDiv",100, INI_COMMON);
	*(unsigned int *) GS_GFMASTER01 = (DWORD)GetPrivateProfileIntA("Common", "GreatFortitudeAgiDiv",100, INI_COMMON);
	*(unsigned int *) GS_GFNORMAL02 = (DWORD)GetPrivateProfileIntA("Common", "GreatFortitudeEneDiv",20, INI_COMMON);
	*(unsigned int *) GS_GFMASTER02 = (DWORD)GetPrivateProfileIntA("Common", "GreatFortitudeEneDiv",20, INI_COMMON);
	*(unsigned int *) GS_SUM_REFLECT_01 = (DWORD)GetPrivateProfileIntA("Common", "SumReflectSkillParam1",20, INI_COMMON);
	*(unsigned int *) GS_SUM_REFLECT_02 = (DWORD)GetPrivateProfileIntA("Common", "SumReflectSkillParam2",20, INI_COMMON);
	//================================================//
	// Use CS Skill on all maps						  //
	//================================================//
	if(GetPrivateProfileIntA("Common", "EnableCSSkillOnAllMap",1, INI_COMMON) == 1)
	{
		Tools.SetByte(0x004E0D09,0xEB);
		Tools.SetByte(0x004E0D19,0xEB);
		Tools.SetByte(0x004E0C09,0xEB);
		Tools.SetByte(0x004E0C19,0xEB);
		Tools.SetByte(0x004E0E26,0xEB);
		Tools.SetByte(0x004E0E36,0xEB);
		Tools.SetByte(0x004E0F29,0xEB);
		Tools.SetByte(0x004E0F19,0xEB);
		Tools.SetByte(0x004E1039,0xEB);
		Tools.SetByte(0x004E1049,0xEB);
		Tools.SetByte(0x004E1136,0xEB);
		Tools.SetByte(0x004E1146,0xEB);
	}
	//================================================//
	// Character Stats								  //
	//================================================//
	if(GetPrivateProfileIntA("Common", "CharacterMaxStats65000",0, INI_COMMON) == 1)
	{
		Tools.SetByte(0x004567F3+1,0xB7);
		Tools.SetByte(0x004592A2+1,0xB7);
		Tools.SetByte(0x0045CBB1+1,0xB7);
		Tools.SetByte(0x004AD9A7+1,0xB7);
		Tools.SetByte(0x004CF77C+1,0xB7);
		Tools.SetByte(0x004CFD34+1,0xB7);
		Tools.SetByte(0x004CFD9C+1,0xB7);
		Tools.SetByte(0x004CFE05+1,0xB7);
		Tools.SetByte(0x004CFE5A+1,0xB7);
		Tools.SetByte(0x004D27D6+1,0xB7);
		Tools.SetByte(0x004D43E4+1,0xB7);
		Tools.SetByte(0x004D4485+1,0xB7);
		Tools.SetByte(0x004D44FF+1,0xB7);
		Tools.SetByte(0x004D4FCB+1,0xB7);
		Tools.SetByte(0x004D62FF+1,0xB7);
		Tools.SetByte(0x004D633A+1,0xB7);
		Tools.SetByte(0x004D7536+1,0xB7);
		Tools.SetByte(0x004D75C9+1,0xB7);
		Tools.SetByte(0x004E8F32+1,0xB7);
		Tools.SetByte(0x004E8FC4+1,0xB7);
		Tools.SetByte(0x004EE5D2+1,0xB7);
		Tools.SetByte(0x004EEF9C+1,0xB7);
		Tools.SetByte(0x004EF1C3+1,0xB7);
		Tools.SetByte(0x004F0A8E+1,0xB7);
		Tools.SetByte(0x004F9680+1,0xB7);
		Tools.SetByte(0x00502B48+1,0xB7);
		Tools.SetByte(0x00506051+1,0xB7);
		Tools.SetByte(0x0051CB84+1,0xB7);
		Tools.SetByte(0x0053AEFB+1,0xB7);
		Tools.SetByte(0x0053B1E0+1,0xB7);
		Tools.SetByte(0x0053B440+1,0xB7);
		Tools.SetByte(0x0053CB58+1,0xB7);
		Tools.SetByte(0x0053D760+1,0xB7);
		Tools.SetByte(0x0053D90B+1,0xB7);
		Tools.SetByte(0x00547BA7+1,0xB7);
		Tools.SetByte(0x005650B7+1,0xB7);
		Tools.SetByte(0x0058E7C9+1,0xB7);
		Tools.SetByte(0x0058EA18+1,0xB7);
		Tools.SetByte(0x0058ECB7+1,0xB7);
		Tools.SetByte(0x005D473C+1,0xB7);

		Tools.SetByte(0x0045680D+1,0xB7);
		Tools.SetByte(0x0045CC3A+1,0xB7);
		Tools.SetByte(0x004CF795+1,0xB7);
		Tools.SetByte(0x004CFABA+1,0xB7);
		Tools.SetByte(0x004CFD48+1,0xB7);
		Tools.SetByte(0x004CFDB0+1,0xB7);
		Tools.SetByte(0x004CFE19+1,0xB7);
		Tools.SetByte(0x004CFE6E+1,0xB7);
		Tools.SetByte(0x004D6315+1,0xB7);
		Tools.SetByte(0x004D6350+1,0xB7);
		Tools.SetByte(0x004D7516+1,0xB7);
		Tools.SetByte(0x004D75A9+1,0xB7);
		Tools.SetByte(0x004D79AC+1,0xB7);
		Tools.SetByte(0x004D79E8+1,0xB7);
		Tools.SetByte(0x004D7A1A+1,0xB7);
		Tools.SetByte(0x004D7A56+1,0xB7);
		Tools.SetByte(0x004D7A8E+1,0xB7);
		Tools.SetByte(0x004D7ABD+1,0xB7);
		Tools.SetByte(0x004D7B07+1,0xB7);
		Tools.SetByte(0x004D7B3B+1,0xB7);
		Tools.SetByte(0x004D7B6F+1,0xB7);
		Tools.SetByte(0x004D7BA6+1,0xB7);
		Tools.SetByte(0x004D7BDA+1,0xB7);
		Tools.SetByte(0x004D7C0F+1,0xB7);
		Tools.SetByte(0x004DB029+1,0xB7);
		Tools.SetByte(0x004E4AF6+1,0xB7);
		Tools.SetByte(0x004E8F4B+1,0xB7);
		Tools.SetByte(0x004E8FAE+1,0xB7);
		Tools.SetByte(0x004EE59C+1,0xB7);
		Tools.SetByte(0x004EE63E+1,0xB7);
		Tools.SetByte(0x004EEFE1+1,0xB7);
		Tools.SetByte(0x004EF1D9+1,0xB7);
		Tools.SetByte(0x004F0AA7+1,0xB7);
		Tools.SetByte(0x004F279C+1,0xB7);
		Tools.SetByte(0x004F27D8+1,0xB7);
		Tools.SetByte(0x004F280A+1,0xB7);
		Tools.SetByte(0x004F2846+1,0xB7);
		Tools.SetByte(0x004F287E+1,0xB7);
		Tools.SetByte(0x004F28AD+1,0xB7);
		Tools.SetByte(0x004F28F7+1,0xB7);
		Tools.SetByte(0x004F292B+1,0xB7);
		Tools.SetByte(0x004F295F+1,0xB7);
		Tools.SetByte(0x004F2996+1,0xB7);
		Tools.SetByte(0x004F29CA+1,0xB7);
		Tools.SetByte(0x004F29FF+1,0xB7);
		Tools.SetByte(0x004F96A5+1,0xB7);
		Tools.SetByte(0x004FAA86+1,0xB7);
		Tools.SetByte(0x00502B7B+1,0xB7);
		Tools.SetByte(0x00506046+1,0xB7);
		Tools.SetByte(0x00502B7B+1,0xB7);
		Tools.SetByte(0x00506046+1,0xB7);
		Tools.SetByte(0x0051CBBC+1,0xB7);
		Tools.SetByte(0x0053AF05+1,0xB7);
		Tools.SetByte(0x0053B1EA+1,0xB7);
		Tools.SetByte(0x0053B44A+1,0xB7);
		Tools.SetByte(0x0053CB0F+1,0xB7);
		Tools.SetByte(0x0053D78C+1,0xB7);
		Tools.SetByte(0x0053D8CD+1,0xB7);
		Tools.SetByte(0x00547BEF+1,0xB7);
		Tools.SetByte(0x005650A0+1,0xB7);
		Tools.SetByte(0x0058E7AE+1,0xB7);
		Tools.SetByte(0x0058E9FD+1,0xB7);
		Tools.SetByte(0x0058EC9C+1,0xB7);
		Tools.SetByte(0x005D4724+1,0xB7);

		Tools.SetByte(0x004CF7AE+1,0xB7);
		Tools.SetByte(0x004CFD5C+1,0xB7);
		Tools.SetByte(0x004CFDC4+1,0xB7);
		Tools.SetByte(0x004CFE2D+1,0xB7);
		Tools.SetByte(0x004CFE82+1,0xB7);
		Tools.SetByte(0x004DAD53+1,0xB7);
		Tools.SetByte(0x004E8F64+1,0xB7);
		Tools.SetByte(0x004E9031+1,0xB7);
		Tools.SetByte(0x004EE674+1,0xB7);
		Tools.SetByte(0x004EF0D9+1,0xB7);
		Tools.SetByte(0x004EF1F1+1,0xB7);
		Tools.SetByte(0x004F0AC0+1,0xB7);
		Tools.SetByte(0x004F8142+1,0xB7);
		Tools.SetByte(0x004FB3F1+1,0xB7);
		Tools.SetByte(0x00502BAD+1,0xB7);
		Tools.SetByte(0x00504249+1,0xB7);
		Tools.SetByte(0x0050603B+1,0xB7);
		Tools.SetByte(0x0051CC2B+1,0xB7);
		Tools.SetByte(0x0053AF11+1,0xB7);
		Tools.SetByte(0x0053B1F6+1,0xB7);
		Tools.SetByte(0x0053B456+1,0xB7);
		Tools.SetByte(0x0053CAC6+1,0xB7);
		Tools.SetByte(0x0053D7B5+1,0xB7);
		Tools.SetByte(0x0053D88C+1,0xB7);
		Tools.SetByte(0x0053E628+1,0xB7);
		Tools.SetByte(0x0053E644+1,0xB7);
		Tools.SetByte(0x0053E660+1,0xB7);
		Tools.SetByte(0x0053E67C+1,0xB7);
		Tools.SetByte(0x00547C37+1,0xB7); 
		Tools.SetByte(0x00565089+1,0xB7);
		Tools.SetByte(0x0058E793+1,0xB7);
		Tools.SetByte(0x0058E9E2+1,0xB7);
		Tools.SetByte(0x0058EC81+1,0xB7); 
		Tools.SetByte(0x005D470C+1,0xB7);

		Tools.SetByte(0x004567D9+1,0xB7);
		Tools.SetByte(0x004CF7C7+1,0xB7);
		Tools.SetByte(0x004CFD70+1,0xB7);
		Tools.SetByte(0x004CFDD8+1,0xB7);
		Tools.SetByte(0x004CFE41+1,0xB7);
		Tools.SetByte(0x004CFE96+1,0xB7);
		Tools.SetByte(0x004D0BE5+1,0xB7);
		Tools.SetByte(0x004D0CD0+1,0xB7);
		Tools.SetByte(0x004D0D37+1,0xB7);
		Tools.SetByte(0x004D0ED1+1,0xB7);
		Tools.SetByte(0x004D0F10+1,0xB7);
		Tools.SetByte(0x004D0F8F+1,0xB7);
		Tools.SetByte(0x004D0FD0+1,0xB7);
		Tools.SetByte(0x004D10BD+1,0xB7);
		Tools.SetByte(0x004D10FC+1,0xB7);
		Tools.SetByte(0x004D1170+1,0xB7);
		Tools.SetByte(0x004D118C+1,0xB7);
		Tools.SetByte(0x004D11A7+1,0xB7);
		Tools.SetByte(0x004D11F5+1,0xB7);
		Tools.SetByte(0x004D1210+1,0xB7);
		Tools.SetByte(0x004D122B+1,0xB7);
		Tools.SetByte(0x004D133B+1,0xB7);
		Tools.SetByte(0x004D137A+1,0xB7);
		Tools.SetByte(0x004D13EE+1,0xB7);
		Tools.SetByte(0x004D140A+1,0xB7);
		Tools.SetByte(0x004D1425+1,0xB7);
		Tools.SetByte(0x004D1473+1,0xB7);
		Tools.SetByte(0x004D148E+1,0xB7);
		Tools.SetByte(0x004D14A9+1,0xB7);
		Tools.SetByte(0x004D17DF+1,0xB7);
		Tools.SetByte(0x004D1818+1,0xB7);
		Tools.SetByte(0x004D18BC+1,0xB7);
		Tools.SetByte(0x004D44A5+1,0xB7);
		Tools.SetByte(0x004D451F+1,0xB7);
		Tools.SetByte(0x004D5B70+1,0xB7);
		Tools.SetByte(0x004D5BA7+1,0xB7);
		Tools.SetByte(0x004D5D17+1,0xB7);
		Tools.SetByte(0x004D5D4A+1,0xB7);
		Tools.SetByte(0x004DAD73+1,0xB7);
		Tools.SetByte(0x004DAD9D+1,0xB7);
		Tools.SetByte(0x004DB049+1,0xB7);
		Tools.SetByte(0x004DB06E+1,0xB7);
		Tools.SetByte(0x004DB218+1,0xB7);
		Tools.SetByte(0x004DB519+1,0xB7);
		Tools.SetByte(0x004DC333+1,0xB7);
		Tools.SetByte(0x004DC477+1,0xB7);
		Tools.SetByte(0x004DFA4F+1,0xB7);
		Tools.SetByte(0x004DFA72+1,0xB7);
		Tools.SetByte(0x004E430B+1,0xB7);
		Tools.SetByte(0x004E4323+1,0xB7);
		Tools.SetByte(0x004E44BD+1,0xB7);
		Tools.SetByte(0x004E44D5+1,0xB7);
		Tools.SetByte(0x004E4ABB+1,0xB7);
		Tools.SetByte(0x004E4B10+1,0xB7);
		Tools.SetByte(0x004E4D7C+1,0xB7);
		Tools.SetByte(0x004E4DB5+1,0xB7);
		Tools.SetByte(0x004E4E0C+1,0xB7);
		Tools.SetByte(0x004E5AFE+1,0xB7);
		Tools.SetByte(0x004E5B16+1,0xB7);
		Tools.SetByte(0x004E5B2B+1,0xB7);
		Tools.SetByte(0x004E6F71+1,0xB7);
		Tools.SetByte(0x004E70BF+1,0xB7);
		Tools.SetByte(0x004E7229+1,0xB7);
		Tools.SetByte(0x004E8F7D+1,0xB7);
		Tools.SetByte(0x004E901B+1,0xB7);
		Tools.SetByte(0x004EE608+1,0xB7);
		Tools.SetByte(0x004EF026+1,0xB7);
		Tools.SetByte(0x004EF209+1,0xB7);
		Tools.SetByte(0x004F0AD9+1,0xB7);
		Tools.SetByte(0x004F8214+1,0xB7);
		Tools.SetByte(0x004FA007+1,0xB7);
		Tools.SetByte(0x004FAAA6+1,0xB7);
		Tools.SetByte(0x004FAB01+1,0xB7);
		Tools.SetByte(0x004FAC94+1,0xB7);
		Tools.SetByte(0x004FAE11+1,0xB7);
		Tools.SetByte(0x004FB411+1,0xB7);
		Tools.SetByte(0x004FB43E+1,0xB7);
		Tools.SetByte(0x004FCF73+1,0xB7);
		Tools.SetByte(0x004FD2A7+1,0xB7);
		Tools.SetByte(0x00502BDF+1,0xB7);
		Tools.SetByte(0x005042F3+1,0xB7);
		Tools.SetByte(0x00506030+1,0xB7);
		Tools.SetByte(0x0051CC55+1,0xB7);
		Tools.SetByte(0x00535B4D+1,0xB7);
		Tools.SetByte(0x00536074+1,0xB7);
		Tools.SetByte(0x005366A3+1,0xB7);
		Tools.SetByte(0x0053AF1D+1,0xB7);
		Tools.SetByte(0x0053B202+1,0xB7);
		Tools.SetByte(0x0053B462+1,0xB7);
		Tools.SetByte(0x0053CA7D+1,0xB7);
		Tools.SetByte(0x0053D7DE+1,0xB7);
		Tools.SetByte(0x0053D84B+1,0xB7);
		Tools.SetByte(0x00547C7C+1,0xB7);
		Tools.SetByte(0x00565072+1,0xB7);
		Tools.SetByte(0x0058E778+1,0xB7);
		Tools.SetByte(0x0058E9C7+1,0xB7);
		Tools.SetByte(0x0058EC66+1,0xB7);
		Tools.SetByte(0x005D46F4+1,0xB7);
	}

	ReadINI.GetString(ConnectMessage,"Main","ConnectionMessage",INI);

	Console.Write("[Config] GameServer Memory Patch Sucessfull!");
}

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cConfig Config;