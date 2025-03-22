#pragma once

#define MAX_ITEM_SECTION 16
#define MAX_ITEM_TYPE 512
#define MAX_ITEM2 8192
#define MAX_ITEM_INFO 12
#define MAX_RESISTANCE_TYPE 7
#define MAX_CLASS 8

struct ITEM_INFO
{
	int Index;
	int ItemIndex;
	int Slot;
	int Skill;
	int Width;
	int Height;
	int HaveSerial;
	int HaveOption;
	int DropItem;
	char Name[32];
	int Level;
	int DamageMin;
	int DamageMax;
	int MagicDamageRate;
	int TwoHand;
	int Defense;
	int MagicDefense;
	int DefenseSuccessRate;
	int AttackSpeed;
	int WalkSpeed;
	int Durability;
	int MagicDurability;
	int Value;
	int BuyMoney;
	int Resistance[7];
	int RequireLevel;
	int RequireStrength;
	int RequireDexterity;
	int RequireEnergy;
	int RequireVitality;
	int RequireLeadership;
	int RequireClass[8];
};

class CItemManager
{
public:
	CItemManager();
	virtual ~CItemManager();
	void Load(ITEM_INFO* ItemInfo);
	ITEM_INFO * JCGetItemInfo(int ItemIndex); // OK
public:

	std::map<int,ITEM_INFO> m_ItemInfo;
};
extern CItemManager gItemManager;
