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

void SiegeSkillsOnNormalGS()
{
	if(GetPrivateProfileInt("Skill","EnableCastleSiegeSkillOnNormal",0,"./config") == 1)
	{
		*(BYTE*)(0x0057F0A7+1) = 0x2B;
		*(BYTE*)(0x0057F0AC+1) = 0x26;
		*(BYTE*)(0x0057F0B1+1) = 0x21;
		*(BYTE*)(0x0057F0B6+1) = 0x1C;
		*(BYTE*)(0x0057F0BB+1) = 0x17;
		*(BYTE*)(0x0059A9B5+2) = 0x00;
		*(BYTE*)(0x0059A9BB+2) = 0x00;
		*(BYTE*)(0x0059A9C1+2) = 0x00;
		*(BYTE*)(0x0059A9C7+2) = 0x00;
		*(BYTE*)(0x0059A9CD+2) = 0x00;
		*(BYTE*)(0x0059A9D3+2) = 0x00;
		*(BYTE*)(0x00579D0F+1) = 0x33;
		*(BYTE*)(0x00579D14+1) = 0x2E;
		*(BYTE*)(0x00579D19+1) = 0x29;
		*(BYTE*)(0x00579D1E+1) = 0x24;
		*(BYTE*)(0x00579D23+1) = 0x1F;
		*(BYTE*)(0x00579D71+1) = 0x33;
		*(BYTE*)(0x00579D76+1) = 0x2E;
		*(BYTE*)(0x00579D7B+1) = 0x29;
		*(BYTE*)(0x00579D80+1) = 0x24;
		*(BYTE*)(0x00579D85+1) = 0x1F;
		*(BYTE*)(0x00492A98+3) = 0x01;

		*(BYTE*)(0x00579D28) = 0xEB;
		*(BYTE*)(0x0057F0C0) = 0xEB;
		*(BYTE*)(0x00579D8A) = 0xEB; 
	}
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
