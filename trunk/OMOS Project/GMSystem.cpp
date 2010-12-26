//=======================================================================================
//= GMSystem.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
gGMSystem GMSystem;
xGMCommandList GMCommandList[255];

//------------------------------------------------------
//- Start
//------------------------------------------------------
void gGMSystem::Load()
{
	//--------------------------------------------------------------------------------
	FILE *fp;
	char sLineTxt[255] = {0};
	//--------------------------------------------------------------------------------
	this->Count = 0;
	//--------------------------------------------------------------------------------
	fp = fopen(INI_GMSYS,"r");
	//--------------------------------------------------------------------------------
	if(!fp)
	{
		Tools.FileExist(INI_GMSYS);
	}
	//--------------------------------------------------------------------------------
	rewind(fp);
	//--------------------------------------------------------------------------------
	while(fgets(sLineTxt, 255, fp) != NULL)
	{
		//--------------------------------------------------------------------------------
		if(sLineTxt[0] == '/')continue;
		if(sLineTxt[0] == ';')continue;
		//--------------------------------------------------------------------------------
		sscanf(sLineTxt, "%s %d %d %d %d", &this->Name,&this->Value[0],&this->Value[1],&this->Value[2],&this->Value[3]);
		//--------------------------------------------------------------------------------
		sprintf(GMCommandList[this->Count].Name,"%s",this->Name);
		GMCommandList[this->Count].Gg		= this->Value[0];
		GMCommandList[this->Count].Drop		= this->Value[1];
		GMCommandList[this->Count].Gmove	= this->Value[2];
		GMCommandList[this->Count].Reload	= this->Value[3];
		//--------------------------------------------------------------------------------
		this->Count++;
		//--------------------------------------------------------------------------------
		Console.Write("[GMSystem] GameMaster %s has been loaded!", this->Name);
		//--------------------------------------------------------------------------------
		ZeroMemory(this->Name,sizeof(this->Name));
		//--------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------
	rewind(fp);
	fclose(fp);
	//--------------------------------------------------------------------------------
	Console.Write("[File] File %s loaded!",INI_GMSYS);
	//--------------------------------------------------------------------------------
}
int gGMSystem::CheckCommand(char* GMName, char* Command)
{
		for(int x=1;x < this->Count;x++)
		{
			if(!strcmp(GMCommandList[x].Name,GMName))
			{
				if(Command == "/gg")
				{
					return GMCommandList[x].Gg;
				}
				else if(Command == "/drop")
				{
					return GMCommandList[x].Drop;
				}
				else if(Command == "/gmove")
				{
					return GMCommandList[x].Gmove;
				}
				else if(Command == "/reload")
				{
					return GMCommandList[x].Reload;
				}
				else
				{
					return 2;
				}
			}
		}
		return 3;
}
//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern gGMSystem GMSystem;