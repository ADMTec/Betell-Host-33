#include "stdafx.h"
#include "Interface.h"
#include "User.h"
#include "NewBank.h"
#include "Defines.h"
#include "Protocol.h"
#include "CustomFont.h"
#include "Central.h"
#include "Object.h"
#include "Controller.h"
#include "post_item.h"
#include "Util.h"
#include <string>
#include "postInterface.h"
#include "WindowsStruct.h"

DWORD EventPushMan;
int aperturarInv;
//======================================================================================================================================================================
//======================================================================================================================================================================
//======================================================================================================================================================================
DWORD CloseClick = 0;

float CuaSoW = 230;
float CuaSoH = 330;

JewelsBank gJewelsBank;

JewelsBank::JewelsBank() // OK
{
	this->JewelsBankLoad();
}
void JewelsBank::JewelsBankLoad()
{
	this->Active = false;
	this->Jewelrypage = 0;
	this->ViTriMouse = false;
	ZeroMemory(&this->BankJewelry, sizeof(BankJewelry));
}
void JewelsBank::JewelsBankDraw()
{

	if ( /*gInterface.CheckWindow(ObjWindow::ChatWindow) ||*/ gInterface.CheckWindow(::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap) || gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::MoveList) /*|| gObjUser.m_MapNumber == 34 || gObjUser.m_MapNumber == 30*/)
	{
		this->Active = false;
		return;
	}
	
	if (gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)) //-- 76
	{
		this->Active = false;
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ChatWindow)
		|| gInterface.CheckWindow(MuHelper))
	{
		this->Active = false;
		return;
	}


	if (this->Active == false)
	{
		this->ViTriMouse = false;
		return;
	}

	if (pCheckWindow(pWindowThis(), Inventory) == false)
	{
		pOpenWindow(pWindowThis(), Inventory);
	}
	pDrawMessage("", 1); // Không Cho Hiện Thông Báo Trên Màn Hình
	this->JCBackgroundJewelry();
	this->JCPanelJewelry();

}


void JewelsBank::JCBackgroundJewelry() //Nen Cua SO
{
	float v4; // ST34_4@1
	int v14; // [sp+24h] [bp-10h]@1
	signed int i; // [sp+28h] [bp-Ch]@1
	float v16; // [sp+2Ch] [bp-8h]@1
	//--
	int JCWinWidth;

	v14 = *(DWORD *)(GetInstance() + 160);

	if (pCheckWindow(pWindowThis(), Inventory))
	{
		*(signed int *)(v14 + 16) = 640 - (200 + CuaSoW);
	}
	if (pCheckWindow(pWindowThis(), Inventory) && pCheckWindow(pWindowThis(), ExpandInventory))
	{
		*(signed int *)(v14 + 16) = 640 - (200 + (CuaSoW) + 190);
	}

	v16 = (double)*(signed int *)(v14 + 16);
	v4 = (double)*(signed int *)(v14 + 20)-35;


	gCentral.PrintDropBox(v16, v4, CuaSoW, CuaSoH, 0, 0);

	//=== KIem tra vi tri chuot
	if (pCheckMouseOver(v16, v4, CuaSoW, CuaSoH))
	{
		this->ViTriMouse = true;
		pSetCursorFocus = true;
	}
	else  {
		this->ViTriMouse = false;
	}
	//============Nut Close ===========//
	pDrawGUI(0x7EC5, v16 + (CuaSoW - 35), v4, 36, 29);

	if (pCheckMouseOver(v16 + (CuaSoW-35), v4, v16 + 200 + 25, v4 + 25))
	{
		if (*(BYTE*)0x8793386 && (GetTickCount() - CloseClick) > 300)
		{
			CloseClick = GetTickCount();
			this->Active = false;
			//pSetCursorFocus = false;
		}
		//pSetCursorFocus = true;
		pDrawColorButton(0x7EC5, v16 + (CuaSoW - 35), v4, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
	}
	//============Nut Close ===========//

	if (this->Jewelrypage > 0) {
		if (pCheckMouseOver((int)v16 + 20, (int)v4 + (CuaSoH - 35), 20, 23))
		{
			if (*(BYTE*)0x8793386 && GetTickCount() >= EventPushMan + 300)
			{
				this->Jewelrypage -= 1;
				pDrawButton(32342, v16 + 20, v4 + (CuaSoH - 35), 20, 23, 0.0, 46.0);
				EventPushMan = GetTickCount();
			}
			else
			{
				pDrawButton(32342, v16 + 20, v4 + (CuaSoH - 35), 20, 23, 0.0, 23.0);
			}
		}
		else
		{
			pDrawButton(32342, v16 + 20, v4 + (CuaSoH - 35), 20, 23, 0.0, 0.0);
		}
	}
	//==== 
	if (this->Jewelrypage < MAX_JEWEL_PAGE) {
		if (pCheckMouseOver((int)v16 + (CuaSoW - 45), (int)v4 + (CuaSoH - 35), 20, 23))
		{
			if (*(BYTE*)0x8793386 && GetTickCount() >= EventPushMan + 300)
			{
				this->Jewelrypage += 1;
				pDrawButton(32343, v16 + (CuaSoW - 45), v4 + (CuaSoH - 35), 20, 23, 0.0, 46.0);
				EventPushMan = GetTickCount();
			}
			else
			{
				pDrawButton(32343, v16 + (CuaSoW - 45), v4 + (CuaSoH - 35), 20, 23, 0.0, 23.0);
			}
		}
		else
		{
			pDrawButton(32343, v16 + (CuaSoW - 45), v4 + (CuaSoH - 35), 20, 23, 0.0, 0.0);
		}
	}
	//===
	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 172, 255, 56, 0xFF);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pDrawText(pTextThis(), v16, v4 + (CuaSoH-30), "1,10,20,30,(-) Plug out, (+) Gui Vao", CuaSoW, 0, (LPINT)3, 0);
	pSetFont(pTextThis(), (int)pFontNormal);

	//sub_7798F0(v14 + 24, 0);
}

int EvtSubJewel;

void JewelsBank::JCLineBack(int m, int Item, float x, float y, float w, float h, char * count)
{

	
	//v17 = (const char *)sub_402320(dword_8128ADC, a1, a2, a3, 115);
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(Item);
	//fix BoxKundun
	char NameItem[40] = { 0 };
	sprintf(NameItem, "%s ", this->mItemName[m + MAX_JEWEL_SHOW * this->Jewelrypage]);
	int Level = 0;
	if (Item == 7179)
	{
		Level = this->mItemLevel[m + MAX_JEWEL_SHOW * this->Jewelrypage] << 3;
	}
	else
	{
		Level = this->mItemLevel[m + MAX_JEWEL_SHOW * this->Jewelrypage];
	}
	gInterface.DrawItem2(x, y + 5, w, h, Item, Level, 0, 0, 0);
	pDrawText(pTextThis(), x, y + 5, NameItem, 0, 0, (LPINT)1, 0);

	pDrawText(pTextThis(), x + w + 5, y+ 10 +  (h / 2), count, 0, 0, (LPINT)1, 0);

	pGLSwitch();

	for (int k = 0; k < 6; k++)
	{
		pDrawGUI(31743, x + (k * 18) + 100, y + 10, 16, 32);
		pGLSwitch();

		if (pCheckMouseOver((int)(x + (k * 18) + 100), (int)(y + 26), 16, 16))
		{
			pDrawColorButton(31743, x + (k * 18) + 100, y + 10, 16, 32, 0, 0, pMakeColor(255, 204, 20, 130));
			if (*(BYTE*)0x8793386 && GetTickCount() >= EvtSubJewel + 400)
			{

				//if (this->BankJewelry[m + MAX_JEWEL_SHOW * this->Jewelrypage] > 0) //Neu < 0 thi ko bam dc
				{
					//=====RUt Ngoc
					PMSG_JEWELBANK_SUB pMsg;
					pMsg.h.set(0xF3, 0xDA, sizeof(pMsg)); //F1

					pMsg.Type = (int)(m + MAX_JEWEL_SHOW * this->Jewelrypage);
					pMsg.Mode = k;

					DataSend((LPBYTE)&pMsg, pMsg.h.size);
					EvtSubJewel = GetTickCount();
					//====Debug===//
					//char DebugTExt[65] = {0};
					//sprintf(DebugTExt, "Type [%d], Mode [%d]", pMsg.Type,pMsg.Mode);
					//pDrawMessage(DebugTExt, 1); // Không Cho Hiện Thông Báo Trên Màn Hình
				}
				pDrawColorButton(31743, x + (k * 18) + 100, y + 10, 16, 32, 0, 0, pMakeColor(255, 0, 20, 130));
			}
			
		}

		if (k == 0)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "01", 17, 0, (LPINT)3, 0);
		}
		else if (k == 1)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "10", 17, 0, (LPINT)3, 0);
		}
		else if (k == 2)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "20", 17, 0, (LPINT)3, 0);
		}
		else if (k == 3)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "30", 17, 0, (LPINT)3, 0);
		}
		else if (k == 4)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "(-)", 17, 0, (LPINT)3, 0); //Rut All
		}
		else if (k == 5)
		{
			pDrawText(pTextThis(), x + (k * 18) + 100, y + 14, "(+)", 17, 0, (LPINT)3, 0); //Gui All
		}
	}
}

void JewelsBank::JCPanelJewelry() //Ve Cua So
{
	int v8; // [sp+0h] [bp-18h]@1
	float v9; // [sp+10h] [bp-8h]@21
	float v10; // [sp+14h] [bp-4h]@13
	float v11; // [sp+10h] [bp-8h]@21
	float v12; // [sp+54h] [bp-14h]@3
	float v13; // [sp+58h] [bp-10h]@3
	float v14; // [sp+58h] [bp-10h]@3
	//char v12[256]; // [sp+10h] [bp-8h]@21
	int JCItemStruct; // [sp+5Ch] [bp-Ch]@3
	char count[256]; // [sp+10h] [bp-8h]@21


	v8 = *(DWORD *)(GetInstance() + 160);
	v11 = (double)*(signed int *)(v8 + 16);
	v10 = (double)*(signed int *)(v8 + 20)-35;

	pSetFont(pTextThis(), (int)pFontBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);

	pDrawText(pTextThis(), v11, v10 + 10, "Jewel Bank", CuaSoW, 0, (LPINT)3, 0);

	int Item;

	for (int i = 0; i < MAX_JEWEL_SHOW; i++)
	{
		Item = this->mItemCode[i + MAX_JEWEL_SHOW * this->Jewelrypage];
		if (Item == 0) {
			continue;
		}
		//JCItemStruct = sub_4E10D0( Item );

		v9 = (double)(20 * 1);
		v14 = (double)(20 * 1) + 20;

		v12 = (double)((v11 + 25) - v9 / 2);
		v13 = (double)((v10 + (i * v14) + (CuaSoH / MAX_JEWEL_SHOW)) - v14 / 2);

		ZeroMemory(count, sizeof(count));

		wsprintf(count, "%d", this->BankJewelry[i + MAX_JEWEL_SHOW * this->Jewelrypage]);
		JCLineBack(i, Item, v12, v13, v9, v14, count);
	}

	pSetFont(pTextThis(), (int)pFontNormal);
}
void JewelsBank::SetInfoBank(PMSG_NEW_RECV* lpMsg) // OK
{
	ZeroMemory(&this->mItemName, sizeof(this->mItemName));
	ZeroMemory(&this->mItemCode, sizeof(this->mItemCode));
	ZeroMemory(&this->mItemLevel, sizeof(this->mItemLevel));


	for (int i = 0; i < lpMsg->count; i++)
	{
		INFO_BANK_SEND* lpInfo = (INFO_BANK_SEND*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_RECV) + (sizeof(INFO_BANK_SEND)*i));

		memcpy(this->mItemName[i], lpInfo->sItemName, sizeof(this->mItemName[i]));
		this->mItemCode[i] = lpInfo->sItemCode;
		this->mItemLevel[i] = lpInfo->sItemLevel;
	}
}