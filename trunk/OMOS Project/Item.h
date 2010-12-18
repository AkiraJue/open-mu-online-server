//=======================================================================================
//= Item.h
//=======================================================================================

//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define SLOT_EMPTY -1
#define MAX_ITEM_INFO 12
#define SET_NUMBERH(x) ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x) ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )
#define SET_NUMBERHDW(x) ( (DWORD)((unsigned __int64)(x)>>(DWORD)32) )
#define SET_NUMBERLDW(x) ( (DWORD)((unsigned __int64)(x) & 0xFFFFFFFF) )

//------------------------------------------------------
//- Structures
//------------------------------------------------------
enum PLAYER_WARDROBE
{
	WEAPON_01	= 0,
	WEAPON_02	= 1,
	HELMET		= 2,
	ARMOR		= 3,
	PANTS		= 4,
	GLOVES		= 5,
	BOOTS		= 6,
	WINGS		= 7,
	GUARDIAN	= 8,
	PENDANT		= 9,
	RING_01		= 10,
	RING_02		= 11,
};

//------------------------------------------------------
//- Structures
//------------------------------------------------------
struct PSBMSG_HEAD_Le
{
    BYTE type;
	BYTE size;
	BYTE head;
	BYTE subh;
};

struct PMSG_ITEM_MODIFY_SEND 
{
    PSBMSG_HEAD_Le header; //C1:F3:14
    BYTE slot;
    BYTE ItemInfo[MAX_ITEM_INFO];
};



struct PBMSG_HEAD	// Packet - Word Type
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};
struct PWMSG_HEAD	// Packet - Word Type
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};
struct PMSG_USEITEM
{
	PWMSG_HEAD h;
	BYTE inventoryPos;	// 3
	BYTE invenrotyTarget;	// 4
	BYTE btItemUseType;	// 5
};


//------------------------------------------------------
//- Start
//------------------------------------------------------
void CGUseItemRecv(PMSG_USEITEM* lpMsg,int aIndex);
void DeleteItem(int aIndex, int Slot);
int GetItem(int Group,int ID);
void DropItem(DWORD aIndex,char* msg);

//------------------------------------------------------
//- Defines
//------------------------------------------------------
#define GCInventoryItemOneSend ((void(*) (int, int)) 0x0043C210) 
#define gObjInventoryDeleteItem ((void(*)(int,int)) 0x00402464)
#define GCInventoryItemDeleteSend ((void(*)(int,int,unsigned char)) 0x00403AE9)
#define ItemSerialCreateSend ((int(*)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD)) 0x00407004)

//------------------------------------------------------
//- Start
//------------------------------------------------------
class CItem 
{
public:
  /*<thisrel this+0x0>*/ /*|0x4|*/ unsigned long m_Number;
  /*<thisrel this+0x4>*/ /*|0x1|*/ char m_serial;
  /*<thisrel this+0x6>*/ /*|0x2|*/ short m_Type;
  /*<thisrel this+0x8>*/ /*|0x2|*/ short m_Level;
  /*<thisrel this+0xa>*/ /*|0x1|*/ unsigned char m_Part;
  /*<thisrel this+0xb>*/ /*|0x1|*/ unsigned char m_Class;
  /*<thisrel this+0xc>*/ /*|0x1|*/ unsigned char m_TwoHand;
  /*<thisrel this+0xd>*/ /*|0x1|*/ unsigned char m_AttackSpeed;
  /*<thisrel this+0xe>*/ /*|0x1|*/ unsigned char m_WalkSpeed;
  /*<thisrel this+0x10>*/ /*|0x2|*/ unsigned short m_DamageMin;
  /*<thisrel this+0x12>*/ /*|0x2|*/ unsigned short m_DamageMax;
  /*<thisrel this+0x14>*/ /*|0x1|*/ unsigned char m_SuccessfulBlocking;
  /*<thisrel this+0x16>*/ /*|0x2|*/ unsigned short m_Defense;
  /*<thisrel this+0x18>*/ /*|0x2|*/ unsigned short m_MagicDefense;
  /*<thisrel this+0x1a>*/ /*|0x1|*/ unsigned char m_Speed;
  /*<thisrel this+0x1c>*/ /*|0x2|*/ unsigned short m_DamageMinOrigin;
  /*<thisrel this+0x1e>*/ /*|0x2|*/ unsigned short m_DefenseOrigin;
  /*<thisrel this+0x20>*/ /*|0x2|*/ unsigned short m_Magic;
  /*<thisrel this+0x24>*/ /*|0x4|*/ float m_Durability;
  /*<thisrel this+0x28>*/ /*|0x2|*/ unsigned short m_DurabilitySmall;
  /*<thisrel this+0x2c>*/ /*|0x4|*/ float m_BaseDurability;
  /*<thisrel this+0x30>*/ /*|0x1|*/ unsigned char m_SpecialNum;
  /*<thisrel this+0x31>*/ /*|0x8|*/ unsigned char m_Special[8];
  /*<thisrel this+0x39>*/ /*|0x8|*/ unsigned char m_SpecialValue[8];
  /*<thisrel this+0x42>*/ /*|0x2|*/ unsigned short m_RequireStrength;
  /*<thisrel this+0x44>*/ /*|0x2|*/ unsigned short m_RequireDexterity;
  /*<thisrel this+0x46>*/ /*|0x2|*/ unsigned short m_RequireEnergy;
  /*<thisrel this+0x48>*/ /*|0x2|*/ unsigned short m_RequireLevel;
  /*<thisrel this+0x4a>*/ /*|0x2|*/ unsigned short m_RequireVitality;
  /*<thisrel this+0x4c>*/ /*|0x2|*/ unsigned short m_RequireLeaderShip;
  /*<thisrel this+0x4e>*/ /*|0x2|*/ unsigned short m_Leadership;
  /*<thisrel this+0x50>*/ /*|0x6|*/ unsigned char m_RequireClass[6];
  /*<thisrel this+0x56>*/ /*|0x7|*/ unsigned char m_Resistance[7];
  /*<thisrel this+0x60>*/ /*|0x4|*/ int m_Value;
  /*<thisrel this+0x64>*/ /*|0x4|*/ unsigned long m_SellMoney;
  /*<thisrel this+0x68>*/ /*|0x4|*/ unsigned long m_BuyMoney;
  /*<thisrel this+0x6c>*/ /*|0x4|*/ int m_iPShopValue;
  /*<thisrel this+0x70>*/ /*|0x1|*/ unsigned char m_bItemExist;
  /*<thisrel this+0x74>*/ /*|0x4|*/ int m_OldSellMoney;
  /*<thisrel this+0x78>*/ /*|0x4|*/ int m_OldBuyMoney;
  /*<thisrel this+0x7c>*/ /*|0x1|*/ unsigned char m_Option1;
  /*<thisrel this+0x7d>*/ /*|0x1|*/ unsigned char m_Option2;
  /*<thisrel this+0x7e>*/ /*|0x1|*/ unsigned char m_Option3;
  /*<thisrel this+0x7f>*/ /*|0x1|*/ unsigned char m_NewOption;
  /*<thisrel this+0x80>*/ /*|0x10|*/ float m_DurabilityState[4];
  /*<thisrel this+0x90>*/ /*|0x4|*/ float m_CurrentDurabilityState;
  /*<thisrel this+0x94>*/ /*|0x1|*/ unsigned char m_SkillChange;
  /*<thisrel this+0x95>*/ /*|0x1|*/ unsigned char m_QuestItem;
  /*<thisrel this+0x96>*/ /*|0x1|*/ unsigned char m_SetOption;
  /*<thisrel this+0x97>*/ /*|0x1|*/ unsigned char m_SetAddStat;
  /*<thisrel this+0x98>*/ /*|0x1|*/ unsigned char m_IsValidItem;
  /*<thisrel this+0x99>*/ /*|0x7|*/ unsigned char m_SkillResistance[7];
  /*<thisrel this+0xa0>*/ /*|0x4|*/ int m_IsLoadPetItemInfo;
  /*<thisrel this+0xa4>*/ /*|0x4|*/ int m_PetItem_Level;
  /*<thisrel this+0xa8>*/ /*|0x4|*/ int m_PetItem_Exp;
  /*<thisrel this+0xac>*/ /*|0x1|*/ unsigned char m_JewelOfHarmonyOption;
  /*<thisrel this+0xae>*/ /*|0x2|*/ unsigned short m_HJOpStrength;
  /*<thisrel this+0xb0>*/ /*|0x2|*/ unsigned short m_HJOpDexterity;
  /*<thisrel this+0xb2>*/ /*|0x1|*/ unsigned char m_ItemOptionEx;
  /*<thisrel this+0xb3>*/ /*|0x1|*/ unsigned char m_OptionIndex;
  /*<thisrel this+0xb4>*/ /*|0x5|*/ unsigned char m_SocketOption[5];
  /*<thisrel this+0xb9>*/ /*|0x1|*/ unsigned char m_UknB9;
};