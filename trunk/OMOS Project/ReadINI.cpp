//=======================================================================================
//= ReadINI.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
cReadINI ReadINI;

//------------------------------------------------------
//- Start
//------------------------------------------------------
int cReadINI::GetInt(char* Selection,char* Key,char* File)
{
	Tools.FileExist(File);
	return GetPrivateProfileInt(Selection,Key,0,File);
}
void cReadINI::GetString(char* Dest,char* Selection,char* Key,char* File)
{
	Tools.FileExist(File);
	GetPrivateProfileStringA(Selection,Key,0,this->String,sizeof(this->String),File);
	memcpy(Dest,this->String,sizeof(this->String));
	ZeroMemory(this->String,sizeof(this->String));
}
//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern cReadINI ReadINI;