//=======================================================================================
//= Main.cpp
//=======================================================================================
#include "StdAfx.h"

char IP[100];

DWORD *MainIP1 = (DWORD*)0x008C2EFC;
DWORD *MainIP2 = (DWORD*)0x008C2FC4;
DWORD *MainIP3 = (DWORD*)0x008C2F2C+2;
DWORD *MainIP4 = (DWORD*)0x008C2FF4+2;
DWORD *MainIP5 = (DWORD*)0x008C2F8C+6;

void ChangeIP()
{
	GetPrivateProfileStringA("Conn","ServIP","192.168.0.101",IP,100,"./config.ini");

	memcpy(&MainIP1[0],IP,strlen(IP));
	memcpy(&MainIP2[0],IP,strlen(IP));
	memcpy(&MainIP3[0],IP,strlen(IP));
	memcpy(&MainIP4[0],IP,strlen(IP));
	memcpy(&MainIP5[0],IP,strlen(IP));
}

int APIENTRY DllMain (HINSTANCE hInst, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH:
			ChangeIP();
		break;
	}
	return true;
}
