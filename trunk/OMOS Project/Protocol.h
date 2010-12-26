//=======================================================================================
//= Fixes.cpp
//=======================================================================================

//------------------------------------------------------
//- Start
//------------------------------------------------------
bool ProtocolCore (BYTE protoNum,LPBYTE aRecv,int aLen,int aIndex,DWORD Encrypt,DWORD Serial);
BOOL gObjSetMonsterEx(int aIndex, int MonsterClass);

//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define DataRecv ((void(*) (BYTE,PBYTE,DWORD,DWORD,...)) 0x004368E0)
#define ShopDataLoad ((void(*)()) 0x00406B6D)
#define gObjSetMonster ((BOOL(*) (int,int)) 0x00506CA0)
#define gObjDel ((void(*)(int aIndex))0x00403AE4)
