#pragma once
#define pGetItemBmdStruct(ItemId)   (ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)
#define SET_ITEMOPT_LEVEL(x)  (x << 3)
#include "stdafx.h"
#include "protocol.h"
//===
#define MAX_JEWEL_SHOW 6
#define MAX_JEWEL_PAGE  4
#define MAX_ITEM_BANK   25
//====NEw
struct PMSG_JEWELBANK_SUB
{
	PSBMSG_HEAD h;
	BYTE Type;
	BYTE Mode;
};
struct PMSG_JEWELBANK_NEW
{
	PSBMSG_HEAD h;
	BYTE sFlag;
	BYTE tFlag;
	BYTE Source;
	BYTE Target;
};
//===========NEW BANK
struct PMSG_NEW_RECV
{
	PSWMSG_HEAD header; // C2:F3:E8
	BYTE count;
};

struct INFO_BANK_SEND
{
	char	sItemName[60];
	int		sItemCode;
	int		sItemLevel;
};

class JewelsBank
{
public:
	JewelsBank();
	bool Active;
	void JewelsBankLoad();
	void JewelsBankDraw();
	int BankJewelry[MAX_ITEM_BANK];
	int Jewelrypage;
	void JCPanelJewelry(); //Ve Cua So
	void JCBackgroundJewelry();
	void JCLineBack(int m, int Item, float x, float y, float w, float h, char * count);
	bool ViTriMouse;
	void SetInfoBank(PMSG_NEW_RECV* lpMsg); // OK
	char	mItemName[MAX_ITEM_BANK][60];
	int		mItemCode[MAX_ITEM_BANK];
	int		mItemLevel[MAX_ITEM_BANK];

};
extern JewelsBank gJewelsBank;

