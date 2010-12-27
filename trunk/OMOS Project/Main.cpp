//=======================================================================================
//= Main.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
DWORD OldProtect;

//------------------------------------------------------
//- Start
//------------------------------------------------------
MU_API Main()
{
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		Console.Init();
		Tools.FileExist(INI_NPC);
		Tools.HookThis((DWORD)&ProtocolCore,0x004038BE);
		Tools.HookThis((DWORD)&gObjSetMonsterEx,0x0056BDF9);
		Config.EditMemory();
		Fixes.EditMemory();
		LoadIPBlock();
		NewsSystem.Start();
		GMSystem.Load();
		EventManager.Load();
	}
	else
	{
		Tools.MessageBoxShow(MB_OK,"Error","Cant load OMOS_Server.dll!");
		Exit;
	}
}

