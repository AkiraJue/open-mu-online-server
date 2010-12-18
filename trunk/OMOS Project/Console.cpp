//=======================================================================================
//= Player.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
Logger Console;
DWORD PiD;

//------------------------------------------------------
//- Start
//------------------------------------------------------
void __stdcall LoggerCore(PVOID pVoid)
{
	char title[100];
	sprintf(title,CONSOLETITLE,SERVER_VERSION,SERVER_SEASON);
	AllocConsole();
	system("color f0");
	SetConsoleTitleA(title);
	while(true)
		Sleep(10);
}
void Logger::Init()
{
	CreateThread( 0 , 0 , (LPTHREAD_START_ROUTINE) LoggerCore , 0 , 0 , &PiD ); 
	Sleep(100);
	
	this->Write("//////////////////////////////////////////////////////////////////////////////"							);
	this->Write("// Open Mu Online Server (OMON)"																			);
	this->Write("//////////////////////////////////////////////////////////////////////////////"							);
	this->Write("// Version			: %s"																, SERVER_VERSION				);
	this->Write("// Code Name			: %s"															, SERVER_CODENAME				);
	this->Write("// Season			: %s, Client v%s"													, SERVER_SEASON,SERVER_CLIENT	);
	this->Write("// Web				: %s"																	, SERVER_WEB					);
	this->Write("//////////////////////////////////////////////////////////////////////////////"							);
	this->Write("// Last Edit Date		: 10 / 12 / 2010 "																		);
	this->Write("//////////////////////////////////////////////////////////////////////////////"							);
}
void Logger::Write(const char* Format, ...)
{
	char Message[1024];
	DWORD dwBytesWritten;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	va_list pArguments;
	va_start(pArguments, Format);
	vsprintf(Message,Format, pArguments);
	va_end(pArguments);
	char outputmsg[2048];
	sprintf(outputmsg,"%s\n", Message);
	WriteFile(Handle, outputmsg, strlen(outputmsg), &dwBytesWritten, NULL);

	SYSTEMTIME t;
	GetLocalTime(&t);

	char FileName[255];
	sprintf(FileName,".\\CONSOLE_LOG\\OMON_Console(%02d.%02d.%02d).log", t.wDay, t.wMonth, t.wYear);

	FILE *logfile = fopen(FileName,"a+");
	fputs(outputmsg,logfile);
	fclose(logfile);
}
void Logger::WriteDT(const char* Format, ...)
{
	SYSTEMTIME t;
	GetLocalTime(&t);

	char Message[1024];
	DWORD dwBytesWritten;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	va_list pArguments;
	va_start(pArguments, Format);
	vsprintf(Message,Format, pArguments);
	va_end(pArguments);
	char currdate[11] = {0};
	sprintf(currdate, "%02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);
	char outputmsg[2048];
	sprintf(outputmsg,"%s %s\n", currdate,Message);
	WriteFile(Handle, outputmsg, strlen(outputmsg), &dwBytesWritten, NULL);

	char FileName[255];
	sprintf(FileName,".\\CONSOLE_LOG\\OMON_Console(%02d.%02d.%02d).log", t.wDay, t.wMonth, t.wYear);

	FILE *logfile = fopen(FileName,"a+");
	fputs(outputmsg,logfile);
	fclose(logfile);
}

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern Logger Console;