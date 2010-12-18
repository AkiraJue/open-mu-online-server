//=======================================================================================
//= Tools.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
cTools Tools;

//------------------------------------------------------
//- Start
//------------------------------------------------------
void cTools::MessageBoxShow(char* Title,const char* Format, ...)
{
	va_list pArguments;
	va_start(pArguments, Format);
	vsprintf(this->Message,Format, pArguments);
	va_end(pArguments);
	//----------------------------------------------------------------
	MessageBoxA(NULL,this->Message,Title,MB_OK);
	//----------------------------------------------------------------
}
void cTools::HookThis(DWORD FuncOffset,DWORD JmpOffset)
{
	//----------------------------------------------------------------
	*(DWORD*)(JmpOffset+1) = FuncOffset - (JmpOffset+5);
	//----------------------------------------------------------------
}
void cTools::SetNop(DWORD Offset,int Size)
{
	for(int n=0;n<Size; n++)
	{
		//----------------------------------------------------------------
		*(BYTE*)(Offset+n) = 0x90;
		//----------------------------------------------------------------
	}
}
void cTools::SetRetn(DWORD Offset)
{
	//----------------------------------------------------------------
	*(BYTE*)(Offset) = 0xC3;
	//----------------------------------------------------------------
}
void cTools::SetByte(DWORD Offset,BYTE Value)
{
	//----------------------------------------------------------------
	*(BYTE*)(Offset) = Value;
	//----------------------------------------------------------------
}
void cTools::FileExist(char* File)
{
	WIN32_FIND_DATAA wfd;
	if (FindFirstFileA(File,&wfd)==INVALID_HANDLE_VALUE)
	{
		this->MessageBoxShow(MB_OK,"File Read Error","Unable to locate %s - File not found.",File);
		Exit;
	}
}

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cTools Tools;