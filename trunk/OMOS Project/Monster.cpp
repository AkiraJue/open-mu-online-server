//=======================================================================================
//= Monster.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
SummonMonsterCf SmnMstrCfg[255];
int SummonCount;

//------------------------------------------------------
//- Start
//------------------------------------------------------
void gObjMonsterCallPet(DWORD aIndex,int MonsterID)
{
	//----------------------------------------------------------------
	Player.SetIndex(aIndex);
	//----------------------------------------------------------------
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	OBJECTSTRUCT *mObj = (OBJECTSTRUCT*)OBJECT_POINTER(MonsterID);
	//----------------------------------------------------------------
	int Radius = 3;
	//----------------------------------------------------------------
	if(gObj->Level > 1 && gObj->Level < 50)
	{
		Radius;
	}
	else if(gObj->Level > 50 && gObj->Level < 100)
	{
		Radius += 1;
	}
	else if(gObj->Level > 100 && gObj->Level < 150)
	{
		Radius += 2;
	}
	else if(gObj->Level > 150 && gObj->Level < 200)
	{
		Radius += 3;
	}
	else if(gObj->Level > 200 && gObj->Level < 250)
	{
		Radius += 4;
	}
	else if(gObj->Level > 250 && gObj->Level < 300)
	{
		Radius += 5;
	}
	else if(gObj->Level > 300 && gObj->Level < 350)
	{
		Radius += 6;
	}
	else if(gObj->Level > 350 && gObj->Level < 400)
	{
		Radius += 7;
	}
	//----------------------------------------------------------------
	mObj->m_AttackDamageMax = (gObj->Dexterity + gObj->Strength + gObj->Vitality + gObj->Energy) / 25;
	mObj->m_AttackDamageMin = (gObj->Dexterity + gObj->Strength + gObj->Vitality + gObj->Energy) / 30;
	mObj->m_Defense = gObj->m_Defense;
	mObj->MaxLife = gObj->MaxLife * 2;
	mObj->m_MoveRange = Radius;
	mObj->TargetNumber = -1;
	//----------------------------------------------------------------
	gObjMonsterCall(aIndex,MonsterID,gObj->X+1,gObj->Y+1);
	//----------------------------------------------------------------
	Console.Write("[PetSystem](Account: %s,Char: %s)[Monster %d,AttackDMGMin %d,AttackDMGMax %d,Defence %d,Life %d,MoveRange %d] Monster has been summoned!",gObj->AccountID,gObj->Name,MonsterID,mObj->m_AttackDamageMin,mObj->m_AttackDamageMax,mObj->m_Defense,mObj->MaxLife,Radius);
	return;
}
