//=======================================================================================
//= Player.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
CPlayer Player; // Players Class
CQuery Sql;
//------------------------------------------------------
//- Start
//------------------------------------------------------
void CPlayer::SetIndex(DWORD Index)
{
	this->aIndex = Index;
}
void CPlayer::SendTextMsg(int Type,char * Text, ...)
{
	char szBuffer[1024];
	char Nickn[11];
	va_list pArguments;
	va_start(pArguments,Text);
	vsprintf(szBuffer,Text,pArguments);
	va_end(pArguments);

	GCServerMsgStringSend(szBuffer,this->aIndex,Type);
	this->GetName(Nickn);
	Console.Write("[SendTextMsg][Index: %d][Nick: %s] %s",this->aIndex,Nickn,szBuffer);
}

void CPlayer::SendAllTextMsg(int Type,char * Text, ...)
{
	char szBuffer[1024];
	char Nickn[11];
	va_list pArguments;
	va_start(pArguments,Text);
	vsprintf(szBuffer,Text,pArguments);
	va_end(pArguments);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
		if(gObj->Connected == PLAYER_PLAYING)
		GCServerMsgStringSend(szBuffer,i,Type);
	}

	this->GetName(Nickn);
	Console.Write("[SendAllTextMsg][Index: %d][Nick: %s] %s",this->aIndex,Nickn,szBuffer);
}
void CPlayer::Disconnect()
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	//------------------------------------------------------
	char Nickn[11];
	//------------------------------------------------------
	if(gObj->PetActived = true)
	{
		gObj->PetActived = false;
	}
	//------------------------------------------------------
	CloseClient(aIndex);
	//------------------------------------------------------
	this->GetName(Nickn);
	//------------------------------------------------------
	Console.Write("[Disconnect][Index: %d][Nick: %s] Player Disconnected",this->aIndex,Nickn);
}
void CPlayer::Teleport(int Map,int X, int Y)
{	
	char Nickn[11];
	gObjTeleport(this->aIndex,Map,X,Y);
	this->GetName(Nickn);
	Console.Write("[Teleport][Index: %d][Nick: %s] Map %d, X %d, Y %d",this->aIndex,Nickn,Map,X,Y);
}
bool CPlayer::IsGameMaster()
{
	if(*(short int*)(this->aIndex * gObjSize + gObjOffset + gObjCtl) == 34 || *(short int*)(this->aIndex * gObjSize + gObjOffset + gObjCtl) == 8 || *(short int*)(this->aIndex * gObjSize + gObjOffset + gObjCtl) == 32)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
bool CPlayer::CanUseCommand(char* Command)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	//------------------------------------------------------
	char query[100];
	int CanUse;
	//------------------------------------------------------
	if(Command == "/gg")
	{
		//------------------------------------------------------
		wsprintf(query, "SELECT Gg FROM GM_Commands WHERE Name ='%s'", gObj->Name);
		//------------------------------------------------------
	}
	else if(Command == "/drop")
	{
		//------------------------------------------------------
		wsprintf(query, "SELECT Dropp FROM GM_Commands WHERE Name ='%s'", gObj->Name);
		//------------------------------------------------------
	}
	else if(Command == "/gmove")
	{
		//------------------------------------------------------
		wsprintf(query, "SELECT Gmove FROM GM_Commands WHERE Name ='%s'", gObj->Name);
		//------------------------------------------------------
	}
	else if(Command == "/reload")
	{
		//------------------------------------------------------
		wsprintf(query, "SELECT Reload FROM GM_Commands WHERE Name ='%s'", gObj->Name);
		//------------------------------------------------------
	}
	//------------------------------------------------------
	Sql.Exec(query);
	Sql.Fetch();
	//------------------------------------------------------
	if(Command == "/gg")
	{
		//------------------------------------------------------
		CanUse = Sql.GetInt("Gg");
		//------------------------------------------------------
	}
	else if(Command == "/drop")
	{
		//------------------------------------------------------
		CanUse = Sql.GetInt("Dropp");
		//------------------------------------------------------
	}
	else if(Command == "/gmove")
	{
		//------------------------------------------------------
		CanUse = Sql.GetInt("Gmove");
		//------------------------------------------------------
	}
	else if(Command == "/reload")
	{
		//------------------------------------------------------
		CanUse = Sql.GetInt("Reload");
		//------------------------------------------------------
	}
	//------------------------------------------------------
	Sql.Clear();
	//------------------------------------------------------
	if(CanUse == 1)
	{
		//------------------------------------------------------
		return true;
		//------------------------------------------------------
	}
	else
	{
		//------------------------------------------------------
		return false;
		//------------------------------------------------------
	}
}
bool CPlayer::isOnline()
{
	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
			if(gObj->Connected == PLAYER_PLAYING)
			{
				return true;
			}
			else
			{
				return false;
			}
	}
	return false;
}
int CPlayer::GetLevel()
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	return gObj->Level;

}
void CPlayer::GetName(char* string)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	strcpy(string,gObj->Name);
}
void CPlayer::GetAccount(char* string)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	strcpy(string,gObj->AccountID);
}
void CPlayer::GetIP(char* string)
{
	memcpy (string,(char*)(gObjOffset+(gObjSize*this->aIndex)+this->aIndex),16);
}
int CPlayer::GetMoney()
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	return gObj->Money;
}
int CPlayer::AddMoney(int Count)
{	
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	gObj->Money = gObj->Money + (int)Count;
	GCMoneySend(aIndex,gObj->Money);
	return 0;
}
int CPlayer::RemoveMoney(int Count)
{	
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(this->aIndex);
	gObj->Money -= Count;
	GCMoneySend(aIndex,gObj->Money);
	return 0;
}

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern CPlayer Player;

