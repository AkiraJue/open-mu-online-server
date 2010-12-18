//=======================================================================================
//= Fixes.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
cFixes Fixes;

//------------------------------------------------------
//- Start
//------------------------------------------------------
void cFixes::EditMemory()
{
	if (ReadINI.GetInt("Fixes","DisableGameServerCheckSum",INI_FIXES) == 1)
	{
		Tools.SetByte(0x00438D3A,0x74);		// Checksum
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","DisablePersonalIDCheck",INI_FIXES) == 0)
	{
		Tools.SetNop(0x0043B9D6,5);			// Personal ID Fix
		Tools.SetNop(0x004504E9,2);			// Guild ID Fix
		Tools.SetNop(0x00450376,6);			// Guild ID Fix
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableOldGoldenEvent",INI_FIXES) == 1)
	{
		BYTE FixGoldenBudgeDragonDrop[7]={0xC7, 0x45, 0xEC, 0x00, 0x00, 0x00, 0x00};
		memcpy((int*)0x0041E8A6,FixGoldenBudgeDragonDrop,sizeof(FixGoldenBudgeDragonDrop));
		BYTE GoldenTitanFix[7]={0x0F, 0x84, 0xE1, 0x00, 0x00, 0x00, 0x90};
		memcpy((int*)0x0041E92A,GoldenTitanFix,sizeof(GoldenTitanFix));
		BYTE GoldenSoldierFix[6]={0xE9, 0x97, 0x00, 0x00, 0x00, 0x90};
		memcpy((int*)0x0041E93B,GoldenSoldierFix,sizeof(GoldenSoldierFix));
		BYTE LizardKingFix[7]={0x0F, 0x84, 0xC9, 0x01, 0x00, 0x00, 0x90};
		memcpy((int*)0x0041E9E6,LizardKingFix,sizeof(LizardKingFix));
		BYTE GoldenTantalosFix[7]={0x0F, 0x84, 0xBA, 0x01, 0x00, 0x00, 0x90};
		memcpy((int*)0x0041EAB6,GoldenTantalosFix,sizeof(GoldenTantalosFix));
		Tools.SetNop(0x0041E9F7,2); //Golden Vepar FIX
		Tools.SetNop(0x0041EAC7,2); //Golden Wheel FIX
		Tools.SetNop(0x0041EADA,2); //Golden Golem FIX
		BYTE FixGoldenInvMsg[3] = { 0xEB, 0x51, 0x90 };
		memcpy((int*)0x0048018A,FixGoldenInvMsg,sizeof(FixGoldenInvMsg));                                    
		BYTE FixGoldenInvMsg1[15] = { 0x00, 0x00, 0x83, 0xC4, 0x08, 0x50, 0xE8, 0xED, 0x3F, 0xF8, 0xFF, 0xEB, 0xA5, 0x00, 0x00 };
		memcpy((int*)0x004801DB,FixGoldenInvMsg1,sizeof(FixGoldenInvMsg1));
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnablePartyZenBugFix",INI_FIXES) == 1)
	{
		BYTE cFixPartyZen[31] = {0x8B,0x4D,0xE4,0x8B,0x55,0x0C,0x03,0xC9,0x03,0xC9,0x03,0xC9,0x03,0xC9,0x81,0xC1,0x00,0x24,0x00,0x00,0x89,0x8A,0xD8,0x00,0x00,0x00,0xE9,0x83,0xFC,0xFF,0xFF};
		memcpy((int*)0x005174E7,cFixPartyZen,sizeof(cFixPartyZen));
		BYTE cFixPartyZen2[12] = {0xE9,0x65,0x03,0x00,0x00,0x90,0x90,0x90,0x90,0x90 ,0x90,0x90};
		memcpy((int*)0x0051717D,cFixPartyZen2,sizeof(cFixPartyZen2));
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnablePKPartyMove",INI_FIXES) == 1)
	{
		BYTE ppm[3] = {0x83, 0xF8, 0x08};
		memcpy((int*)0x00560C66,ppm,sizeof(ppm)); //Party Move
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnablePKPartyKill",INI_FIXES) == 1)
	{
		BYTE ppk[6] = {0xE9, 0x1D, 0x01, 0x00, 0x00, 0x90};
		memcpy((int*)0x004D6D56,ppk,sizeof(ppk));	//Party Kill
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnablePKKill",INI_FIXES) == 1)
	{
		Tools.SetByte(0x004D69C1,0x7);	//PK Kill
		Tools.SetByte(0x004D6DA0,0x7);
		Tools.SetByte(0x004D6E31,0x7);
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnablePKUseShops",INI_FIXES) == 1)
	{
		Tools.SetByte(0x004450EE, 0xEB);	//Party PK IN Shop
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableGMUseKey",INI_FIXES) == 1)
	{
	Tools.SetByte(0x005609DB,0xE9);	// GM Move M key
	Tools.SetByte(0x005609DC,0xF5);	// GM Move M key
	Tools.SetByte(0x005609DD,0x00);	// GM Move M key
	Tools.SetByte(0x005609E0,0x90);	// GM Move M key
	Tools.SetByte(0x005609E1,0x8B);	// GM Move M key
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableExcellentItemAncOpt",INI_FIXES) == 1)
	{
		Tools.SetByte(0x0054EFC6,0xEB);	//Allow Excellent Anc
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableJOHItemAncOpt",INI_FIXES) == 1)
	{
		Tools.SetByte(0x005C600A,0xEB);	//Allow Joh Anc
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableExcellentItemSocketOpt",INI_FIXES) == 1)
	{
		Tools.SetByte(0x0054F06F,0xEB);	//Allow Exc Socket
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","Enable255PotionInShops",INI_FIXES) == 1)
	{
		Tools.SetNop(0x0042F650,8);		//Poitions 255
		Tools.SetNop(0x00502243,8);		//Poitions 255
		Tools.SetByte(0x005023D9,0xEB);	//Poitions 255
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableLife+28",INI_FIXES) == 1)
	{
		Tools.SetNop(0x0042F2F4,2);		// Life +28
		Tools.SetNop(0x005573C4,2);		// Life +28
		Tools.SetByte(0x00501F89,0x07);	// Life +28
		Tools.SetByte(0x005378D0,0x07);	// Life +28
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableItems+15",INI_FIXES) == 1)
	{
		Tools.SetByte(0x0042F290+2,0x0F);		//+ 15 Items
		Tools.SetByte(0x00501EE2+2,0x0F);		//+ 15 Items
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableArenaPVP",INI_FIXES) == 1)
	{
		Tools.SetByte(0x004D6b46,0x3F);	// Arena cannot pvp
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableAllInCC",INI_FIXES) == 1)
	{
		Tools.SetByte(0x00460B1C+2, 0x07); // All in CC
		Tools.SetByte(0x0046303A+2, 0x07);
		Tools.SetByte(0x004632A3+2, 0x07);
		Tools.SetByte(0x0046327B+2, 0x07); 
	}
	//----------------------------------------------------------------
	if (ReadINI.GetInt("Fixes","EnableRakionBossRespawnIn24h",INI_FIXES) == 1)
	{
		Tools.SetByte(0x0061018E, 0x81);	//RakionEventBossRespawnTime24h
		Tools.SetByte(0x0061018F, 0x51); 
	}
	//----------------------------------------------------------------
	//GM can kill, Enter (w7 fix)
	BYTE FixGMEnter[2] = { 0xEB, 0x42 };
	memcpy((int*)0x0050514B,FixGMEnter,sizeof(FixGMEnter));
	//----------------------------------------------------------------
	//Fix Summoner Berserker 65k+ Damage
	BYTE FixBerserker[] = { 0x68, 0xBC, 0x02, 0x00, 0x00 };
	memcpy((int*)0x004E5B45,FixBerserker,sizeof(FixBerserker));
	//----------------------------------------------------------------
	//Fix Mana Shield 32k+ Stats
	BYTE FixMShield1[] = { 0xB9, 0xBC, 0x02, 0x00, 0x00 };
	memcpy((int*)0x004DB03D,FixMShield1,sizeof(FixMShield1));
	memcpy((int*)0x004FAA9A,FixMShield1,sizeof(FixMShield1));	
	BYTE FixMShield2[] = { 0xBE, 0x20, 0x03, 0x00, 0x00 };
	memcpy((int*)0x004DB05D,FixMShield2,sizeof(FixMShield2));
	memcpy((int*)0x004FAABA,FixMShield2,sizeof(FixMShield2));
	//----------------------------------------------------------------
	Tools.SetByte(0x004C7041,0xE9);	// Fix Crash Dump File
	Tools.SetByte(0x004C7042,0x2E);	// Fix Crash Dump File
	Tools.SetByte(0x004C7043,0x01);	// Fix Crash Dump File
	Tools.SetByte(0x004C7044,0x00);	// Fix Crash Dump File
	Tools.SetByte(0x004C7046,0x90);	// Fix Crash Dump File
	//----------------------------------------------------------------
	Tools.SetByte(0x0041E8A9,0x08);	// BOX + 1
	Tools.SetByte(0x0041E965,0x08);	// BOX + 1
	Tools.SetByte(0x0041EA47,0x09);	// BOX + 2
	Tools.SetByte(0x0041EB2A,0x0c);	// BOX + 3
	Tools.SetByte(0x0041EBEB,0x0C);	// BOX + 4
	Tools.SetByte(0x0041ECAC,0x0C);	// BOX + 5
	//----------------------------------------------------------------
	Tools.SetRetn(0x00403233);		// Destroy Giocp
	//----------------------------------------------------------------
	Tools.SetRetn(0x004069AB);		// Serial 0x00000000 fix
	//----------------------------------------------------------------
	Tools.SetRetn(0x00404584);		// HACK TOOL DC Fix
	//----------------------------------------------------------------
	Tools.SetByte(0x004369B7,0xEB);	// Socket Serial
	//----------------------------------------------------------------
	Tools.SetByte(0x0043880E,0x90);	// Hack reporting FIX
	Tools.SetByte(0x0043880F,0x90);	//
	Tools.SetByte(0x00438830,0xE9);	//
	Tools.SetByte(0x00438831,0x74);	//
	Tools.SetByte(0x00438832,0x01);	//
	Tools.SetByte(0x00438833,0x00);	//
	Tools.SetByte(0x00438835,0x90);	//
	//----------------------------------------------------------------
	Tools.SetNop(0x00458612,27);	// Protocol Error FIX
	//----------------------------------------------------------------
	Tools.SetByte(0x00460396,0xEB);	// DevilSquare Master FIX
	//----------------------------------------------------------------
	Tools.SetNop(0x004B33DE,6);		// error-L2 : Index(%d) %x %x %x FIX
	//----------------------------------------------------------------
	Tools.SetByte(0x004B409F,0x90);	// Invalid Socket FIX
	Tools.SetByte(0x004B40A0,0x90);	//
	Tools.SetByte(0x004B41CF,0xEB);	//
	//----------------------------------------------------------------
	Tools.SetNop(0x0056D6F3,5);		// ggauth.dll Unload
	Tools.SetByte(0x0056D708,0xEB);	//
	//----------------------------------------------------------------
	Tools.SetByte(0x0057FDB3,0x33);	// BC Master Enter FIX
	Tools.SetByte(0x0057FDB4,0xC0);	//
	Tools.SetByte(0x0057FDB5,0x90);	//
	Tools.SetByte(0x0057FE6D,0x33);	//
	Tools.SetByte(0x0057FE6E,0xC0);	//
	Tools.SetByte(0x0057FE6F,0x90);	//
	//----------------------------------------------------------------
	Tools.SetByte(0x005B031C,0xFF);	// AiElement Error
	//----------------------------------------------------------------
	Tools.SetByte(0x005D945C,0x07); //IT Enter
	Tools.SetByte(0x005DAA33,0x07); //IT NPC
	//----------------------------------------------------------------
	Tools.SetByte(0x0061018E,0x81);	// Raklion Fix
	Tools.SetByte(0x0061018F,0x51);	//
	Tools.SetByte(0x00610190,0x01);	//
	//----------------------------------------------------------------
	Tools.SetNop(0x004A17D0,7);		// Drop W/ luck Fix
	//----------------------------------------------------------------
	Tools.SetNop(0x0053F5CE,7); //Kun Dun Drop ANC + Luck Fix
	Tools.SetNop(0x0049E008,7); // Fix Maya Hand Drop Luck
	Tools.SetNop(0x0049E378,7); // Fix NightMare Drop Luck
	Tools.SetNop(0x0049DC81,7); // Fix Balgas Drop Luck
	Tools.SetNop(0x0049D881,7); // Fix Dark Elf Crywolf Drop Luck
	Tools.SetNop(0x0049AA55,7); // Fix Green Ribbon Box Drop Luck
	Tools.SetNop(0x0049AF25,7); // Fix Blue Ribbon Box Drop Luck
	Tools.SetNop(0x0049B875,7); // Red Chocolate Box Drop Luck Fix
	Tools.SetNop(0x0049BD45,7); // Blue Chocolate Box Drop Luck Fix
	Tools.SetNop(0x0049C695,7); // Vermilion Box Drop Luck Fix
	Tools.SetNop(0x0049CB65,7); // Deep Blue Box Drop Luck Fix
	Tools.SetNop(0x004A00A1,7); // GM Box Drop Luck Fix
	Tools.SetNop(0x004A054D,7); // Green Chaos Box Drop Luck Fix
	Tools.SetNop(0x004A09DD,7); // Red Chaos Box Drop Luck Fix
	Tools.SetNop(0x004A0E6D,7); // Puple Chaos Box Drop Luck Fix
	//----------------------------------------------------------------
	Tools.SetByte(0x005044B8,0xEB); //Marlon Quest
	Tools.SetByte(0x00504519,0xEB); //
	this->InvalidSocketFix();
	//----------------------------------------------------------------
	this->SpeedHackFixInit();
	//----------------------------------------------------------------
	this->ResistanceFixInit();
	//----------------------------------------------------------------
	Console.Write("[Fixes] GameServer Memory Patch Sucessfull!");
}
void __declspec(naked) GetQueComplStatusFix()
{
    _asm
	{
		CMP DWORD PTR SS:[EBP-0x30],0x3E3
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x30],0x79
		JE Allow;
		mov edi, 0x004B1DA7;
		jmp edi;
		Allow:
		mov edi, 0x004B1DD9;
		jmp edi;
	}
}
bool FakeCheckSpeedHack(int aIndex)
{
	return true;
}
int ResistanceFix(LPOBJ lpObj, int Resistance_Type)
{
	BYTE r = lpObj->m_Resistance[Resistance_Type];
	if(r == 0xFF)
		return 1;
	if (r == 0)
		return 0;	
	if ((rand()%(r+1)) == 0 && (Resistance_Type == 2 || Resistance_Type == 0 )) // fixed a simple
		return 0;
	if(Resistance_Type == 1)
	{
		DWORD dwRand ;
		srand(static_cast<int>(time(NULL)));
		dwRand = (DWORD) rand()%0xFF;
		if(dwRand > r)
			return 0;
	}
	return 1;
}
void cFixes::ResistanceFixInit()
{
	Tools.HookThis((DWORD)&ResistanceFix,0x00405D26);	
}
void cFixes::SpeedHackFixInit()
{
	Tools.HookThis((DWORD)&FakeCheckSpeedHack, 0x00407446);
}
void cFixes::InvalidSocketFix()
{
	BYTE QueCompletionStat[9] = { 0xFF, 0x25, 0x00, 0xB5, 0x71, 0x00, 0x90, 0x90, 0x90 };
	memcpy((int*)0x004B1D9E,QueCompletionStat,sizeof(QueCompletionStat));
	//----------------------------------------------------------------
	*(DWORD*)0x0071B500 = (DWORD)GetQueComplStatusFix;
}

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cFixes Fixes;