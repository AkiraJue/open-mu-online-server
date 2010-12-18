//=======================================================================================
//= Monster.h
//=======================================================================================

//------------------------------------------------------
//- Start
//------------------------------------------------------
void gObjMonsterCallPet(DWORD aIndex,int Class,int MonsterID,int MoneyNeed,int LevelMin,int LevelMax);

//------------------------------------------------------
//- Structures
//------------------------------------------------------
typedef struct SummonMonsterCfg
{
	char MonsterName[255];
	int PlayerClass;
	int MonsterID;
	int MoneyNeed;
	int LevelMin;
	int LevelMax;
}SummonMonsterCf;

//------------------------------------------------------
//- Variables
//------------------------------------------------------
extern SummonMonsterCf SmnMstrCfg[255];
extern int SummonCount;

//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define gObjMonsterCall	((int(*)(DWORD Index, DWORD MonsterID, DWORD x, DWORD y)) 0x005395C0)
#define gObjMonsterCallKill ((void(*)(DWORD Index)) 0x00539980)