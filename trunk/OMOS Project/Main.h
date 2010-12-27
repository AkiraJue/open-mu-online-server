//=======================================================================================
//= Main.h
//=======================================================================================

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern DWORD OldProtect;
//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define MU_API extern "C" __declspec (dllexport) void __cdecl 
#define Exit ExitProcess(0)
#define COMMAND_NAME(CommandName) !memcmp(&aRecv[13],CommandName,strlen(CommandName))
#define COMMAND_PARAMS(CommandName) aRecv+13+strlen(CommandName)
#define PGetNPC_ID aRecv[4] + aRecv[3] * 256
#define Launch(Void) _beginthread(Void,0,NULL)
#define INI				".//Data//Main.ini"
#define INI_COMMANDS	".//Data//Command.ini"
#define INI_FIXES		".//Data//Fixes.ini"
#define INI_COMMON		".//Data//Common.ini"
#define INI_BLOCKED_IP	".//Data//BlockedIPList.script"
#define INI_NEWS		".//Data//NewsSystem.script"
#define INI_NPC			".//Data//CostumNPC.ini"
#define INI_GMSYS		".//Data//GMSystem.script"
#define INI_EVENT_MAN	".//Data//EventManager.script"
#define INI_EVENTS		".//Data//CostumEvents.ini"
//------------------------------------------------------
//- Version
//------------------------------------------------------
#define SERVER_VERSION "1.04"
#define SERVER_SEASON "IV"
#define SERVER_CLIENT "1.03K JPN"
#define SERVER_WEB "http://tinyurl.com/omon11/"
#define SERVER_CREDITS "System32"
#define SERVER_CODENAME "Thunder"
#define SERVER_DATE "25 / 12 / 2010"