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
	PROTECT_CHECK_START
		Console.Init();
		Tools.HookThis((DWORD)&ProtocolCore,0x004038BE);
		Config.EditMemory();
		Fixes.EditMemory();
		LoadIPBlock();
	PROTECT_CHECK_ELSE
		Tools.MessageBoxShow(MB_OK,"Error","Cant load GameServer.dll!");
		Exit;
	PROTECT_CHECK_END
}
