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
#define PROTECT_CHECK_START if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect)){
#define PROTECT_CHECK_END }
#define PROTECT_CHECK_ELSE }else{
#define Exit ExitProcess(0)
#define COMMAND_NAME(CommandName) !memcmp(&aRecv[13],CommandName,strlen(CommandName))
#define PGetNPC_ID aRecv[4] + aRecv[3] * 256
#define INI				".//Data//Main.ini"
#define INI_COMMANDS	".//Data//Command.ini"
#define INI_FIXES		".//Data//Fixes.ini"
#define INI_COMMON		".//Data//Common.ini"
#define INI_BLOCKED_IP	".//Data//Script//BlockedIPList.script"
#define INI_NEWS		".//Data//Script//NewsSystem.script"
#define INI_NPC			".//Data//CostumNPC.ini"
#define INI_GMSYS		".//Data//Script//GMSystem.script"
//------------------------------------------------------
//- Version
//------------------------------------------------------
#define SERVER_VERSION "1.03"
#define SERVER_SEASON "IV"
#define SERVER_CLIENT "1.03K JPN"
#define SERVER_WEB "tinyurl.com/omon11"
#define SERVER_CREDITS "System32"
#define SERVER_CODENAME "Thunder"