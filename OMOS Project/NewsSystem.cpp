//=======================================================================================
//= NewsSystem.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
gNewsSystem NewsSystem;
xNewsList NewsList[255];

//------------------------------------------------------
//- Start
//------------------------------------------------------
void gNewsSystem::Load()
{
	//--------------------------------------------------------------------------------
	FILE *fp;
	char sLineTxt[255] = {0};
	//--------------------------------------------------------------------------------
	this->Count = 0;
	//--------------------------------------------------------------------------------
	fp = fopen(INI_NEWS,"r");
	//--------------------------------------------------------------------------------
	if(!fp)
	{
		Tools.FileExist(INI_NEWS);
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
		sscanf(sLineTxt, "%d %d %d %d %d %d %s",&this->Value[0],&this->Value[1],&this->Value[2],&this->Value[3],&this->Value[4],&this->Value[5],&this->String);
		//--------------------------------------------------------------------------------
		NewsList[this->Count].News_Day		= this->Value[0];
		NewsList[this->Count].News_Month	= this->Value[1];
		NewsList[this->Count].News_Year		= this->Value[2];
		NewsList[this->Count].News_Hour		= this->Value[3];
		NewsList[this->Count].News_Minute	= this->Value[4];
		NewsList[this->Count].News_Type		= this->Value[5];
		sprintf(NewsList[this->Count].News_Line,"%s",this->String);
		//--------------------------------------------------------------------------------
		this->Count++;
		//--------------------------------------------------------------------------------
		ZeroMemory(this->String,sizeof(this->String));
		//--------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------
	rewind(fp);
	fclose(fp);
	//--------------------------------------------------------------------------------
	Console.Write("[File] File %s loaded!",INI_NEWS);
	//--------------------------------------------------------------------------------
}
void Manage(void * lpParam)
{
	Console.Write("[NewsSystem] News system thread has been started!");
	//--------------------------------------------------------------------------------
	while(true)
	{
		//--------------------------------------------------------------------------------
		Sleep(1);
		//--------------------------------------------------------------------------------
		SYSTEMTIME t;
		GetLocalTime(&t);
		//--------------------------------------------------------------------------------
		for(int x=0;x < NewsSystem.Count;x++)
		{
			//--------------------------------------------------------------------------------
			DWORD CurrentTime = MAKELONG(t.wHour,t.wMinute);
			DWORD MessageTime = MAKELONG(NewsList[x].News_Hour, NewsList[x].News_Minute);
			//--------------------------------------------------------------------------------
			if(MessageTime == CurrentTime)
			{
				if(NewsList[x].News_Day == t.wDay && NewsList[x].News_Month == t.wMonth && NewsList[x].News_Year == t.wYear)
				{
					//--------------------------------------------------------------------------------
					NewsSystem.SendMsg(NewsList[x].News_Type,NewsList[x].News_Line);
					//--------------------------------------------------------------------------------
				}
				//--------------------------------------------------------------------------------
				Sleep(60000); //Sleep 1min to prevent message to repeat it self!
				//--------------------------------------------------------------------------------
			}
			//--------------------------------------------------------------------------------
		}
		//--------------------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------
	_endthread();
	//--------------------------------------------------------------------------------
}
void gNewsSystem::Start()
{
	if(ReadINI.GetInt("Main","NewsSystemEnabled",INI) == 1)
	{
		this->Load();
		Launch(Manage);
	}
}
void gNewsSystem::SendMsg(int Type,char * Text, ...)
{
	char szBuffer[1024];
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
	//--------------------------------------------------------------------------------
	Console.Write("[NewsAncounce] Send Message: %s",szBuffer);
	//--------------------------------------------------------------------------------
	ZeroMemory(szBuffer,sizeof(szBuffer));
}
//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern gNewsSystem NewsSystem;