//=======================================================================================
//= Item.cpp
//=======================================================================================
#include "StdAfx.h"

//------------------------------------------------------
//- Variables
//------------------------------------------------------
#define MAX_SUBTYPE_ITEMS 512
#define ITEMGET(x,y) ( (x)*MAX_SUBTYPE_ITEMS + (y))

//------------------------------------------------------
//- Start
//------------------------------------------------------
void CGUseItemRecv(PMSG_USEITEM* lpMsg,int aIndex)
{	
	Player.SetIndex(aIndex);
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	//---------------------------------------------------------------------------------------------------
	CItem* SourceItem	= &gObj->pInventory[lpMsg->btItemUseType];
	CItem* TargetItem	= &gObj->pInventory[lpMsg->invenrotyTarget];
	//---------------------------------------------------------------------------------------------------
	//if(SourceItem->m_Type == GetItem(14,184)) //Jewel of Skill
	//{	
	//	if(TargetItem->m_Option1==1)
	//	{
	//		GCServerMsgStringSend("Can't use Jewel of Skill on item which already have skill!",aIndex,1);
	//		return;
	//	}
	//	//---------------------------------------------------------------------------------------------------
	//	TargetItem->m_Option1=1;
	//	DeleteItem(aIndex, lpMsg->SourceSlot);
	//	GCInventoryItemOneSend(aIndex, lpMsg->TargetSlot);		
	//	//---------------------------------------------------------------------------------------------------
	//	Console.Write("[Jewel Of Skill](Account: %s, Char: %s) used jewel of skill!",gObj->AccountID,gObj->Name);
	//}
	//else if(SourceItem->m_Type == GetItem(14,21)) //Jewel of Luck
	//{	
	//	if(TargetItem->m_Option2==1)
	//	{
	//		GCServerMsgStringSend("Can't use Jewel of Luck on item which already have luck!",aIndex,1);
	//		return;
	//	}
	//	//---------------------------------------------------------------------------------------------------
	//	TargetItem->m_Option2=1;
	//	DeleteItem(aIndex, lpMsg->SourceSlot);
	//	GCInventoryItemOneSend(aIndex, lpMsg->TargetSlot);	
	//	//---------------------------------------------------------------------------------------------------
	//	Console.Write("[Jewel Of Luck](Account: %s, Char: %s) used jewel of luck!",gObj->AccountID,gObj->Name);
	//}
}
void DeleteItem(int aIndex, int Slot)
{		
		gObjInventoryDeleteItem(aIndex, Slot);
		GCInventoryItemDeleteSend(aIndex, Slot, 1);
}

int GetItem(int Group,int ID)
{
	return ((Group*512) +ID);
}