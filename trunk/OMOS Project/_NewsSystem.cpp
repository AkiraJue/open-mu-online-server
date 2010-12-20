//=======================================================================================
//= NewsSystem.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
gNewsSystem NewsSystem;
gNewsList NewsList;

//------------------------------------------------------
//- Start
//------------------------------------------------------
void gNewsSystem::Start()
{
	if(ReadINI.GetInt("NewsSystem","NewsSystemEnabled",INI_NEWS) == 1)
	{
		Tools.FileExist(INI_NEWS);
		_beginthread(News_Manage,0,NULL);
		Console.Write("[NewsSystem] News system has been started!");
	}
}
void News_Manage(void * lpParam)
{
	//--------------------------------------------------------------------------------
	int Sections = ReadINI.GetInt("NewsSystem","SectionCount",INI_NEWS);
	int Time = ReadINI.GetInt("NewsSystem","TimeBetweenNews",INI_NEWS) * 60000;
	//--------------------------------------------------------------------------------
	while(true)
	{
		//--------------------------------------------------------------------------------
		if(Sections > 5 || Sections <= 0)
		{
			//--------------------------------------------------------------------------------
			Console.Write("[NewsSystem_Error] News system selection count is wrong. Max 5, Min 1. Current value %d",Sections);
			//--------------------------------------------------------------------------------
			_endthread();
			//--------------------------------------------------------------------------------
		}
		//--------------------------------------------------------------------------------
		Sleep(Time);
		//--------------------------------------------------------------------------------
		ReadINI.GetString(NewsList.Message_1,"NewsSystem","NewsSection1_Message1",INI_NEWS);
		ReadINI.GetString(NewsList.Message_2,"NewsSystem","NewsSection1_Message2",INI_NEWS);
		ReadINI.GetString(NewsList.Message_3,"NewsSystem","NewsSection1_Message3",INI_NEWS);

		Player.SendAllTextMsg(0,NewsList.Message_1);
		Player.SendAllTextMsg(0,NewsList.Message_2);
		Player.SendAllTextMsg(0,NewsList.Message_3);

		ZeroMemory(NewsList.Message_1,sizeof(NewsList.Message_1));
		ZeroMemory(NewsList.Message_2,sizeof(NewsList.Message_2));
		ZeroMemory(NewsList.Message_3,sizeof(NewsList.Message_3));
		//--------------------------------------------------------------------------------
		if(Sections >= 2)
		{
			//--------------------------------------------------------------------------------
			Sleep(Time);
			//--------------------------------------------------------------------------------
			ReadINI.GetString(NewsList.Message_1,"NewsSystem","NewsSection2_Message1",INI_NEWS);
			ReadINI.GetString(NewsList.Message_2,"NewsSystem","NewsSection2_Message2",INI_NEWS);
			ReadINI.GetString(NewsList.Message_3,"NewsSystem","NewsSection2_Message3",INI_NEWS);

			Player.SendAllTextMsg(0,NewsList.Message_1);
			Player.SendAllTextMsg(0,NewsList.Message_2);
			Player.SendAllTextMsg(0,NewsList.Message_3);

			ZeroMemory(NewsList.Message_1,sizeof(NewsList.Message_1));
			ZeroMemory(NewsList.Message_2,sizeof(NewsList.Message_2));
			ZeroMemory(NewsList.Message_3,sizeof(NewsList.Message_3));
		}
		if(Sections >= 3)
		{
			//--------------------------------------------------------------------------------
			Sleep(Time);
			//--------------------------------------------------------------------------------
			ReadINI.GetString(NewsList.Message_1,"NewsSystem","NewsSection3_Message1",INI_NEWS);
			ReadINI.GetString(NewsList.Message_2,"NewsSystem","NewsSection3_Message2",INI_NEWS);
			ReadINI.GetString(NewsList.Message_3,"NewsSystem","NewsSection3_Message3",INI_NEWS);

			Player.SendAllTextMsg(0,NewsList.Message_1);
			Player.SendAllTextMsg(0,NewsList.Message_2);
			Player.SendAllTextMsg(0,NewsList.Message_3);

			ZeroMemory(NewsList.Message_1,sizeof(NewsList.Message_1));
			ZeroMemory(NewsList.Message_2,sizeof(NewsList.Message_2));
			ZeroMemory(NewsList.Message_3,sizeof(NewsList.Message_3));
		}
		if(Sections >= 4)
		{
			//--------------------------------------------------------------------------------
			Sleep(Time);
			//--------------------------------------------------------------------------------
			ReadINI.GetString(NewsList.Message_1,"NewsSystem","NewsSection4_Message1",INI_NEWS);
			ReadINI.GetString(NewsList.Message_2,"NewsSystem","NewsSection4_Message2",INI_NEWS);
			ReadINI.GetString(NewsList.Message_3,"NewsSystem","NewsSection4_Message3",INI_NEWS);

			Player.SendAllTextMsg(0,NewsList.Message_1);
			Player.SendAllTextMsg(0,NewsList.Message_2);
			Player.SendAllTextMsg(0,NewsList.Message_3);

			ZeroMemory(NewsList.Message_1,sizeof(NewsList.Message_1));
			ZeroMemory(NewsList.Message_2,sizeof(NewsList.Message_2));
			ZeroMemory(NewsList.Message_3,sizeof(NewsList.Message_3));
		}
		if(Sections == 5)
		{
			//--------------------------------------------------------------------------------
			Sleep(Time);
			//--------------------------------------------------------------------------------
			ReadINI.GetString(NewsList.Message_1,"NewsSystem","NewsSection5_Message1",INI_NEWS);
			ReadINI.GetString(NewsList.Message_2,"NewsSystem","NewsSection5_Message2",INI_NEWS);
			ReadINI.GetString(NewsList.Message_3,"NewsSystem","NewsSection5_Message3",INI_NEWS);

			Player.SendAllTextMsg(0,NewsList.Message_1);
			Player.SendAllTextMsg(0,NewsList.Message_2);
			Player.SendAllTextMsg(0,NewsList.Message_3);

			ZeroMemory(NewsList.Message_1,sizeof(NewsList.Message_1));
			ZeroMemory(NewsList.Message_2,sizeof(NewsList.Message_2));
			ZeroMemory(NewsList.Message_3,sizeof(NewsList.Message_3));
		}
	}
	//--------------------------------------------------------------------------------
	_endthread();
	//--------------------------------------------------------------------------------
}
//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern gNewsSystem NewsSystem;