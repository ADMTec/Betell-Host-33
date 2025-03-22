#pragma once
#include "Object.h"
#include "Protocol.h"
#include "Defines.h"
#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};
struct PMSG_UPD_CAPNHAT_INFO
{
	PSBMSG_HEAD	h;
	int CAPNHAT1;
	int CAPNHAT2;
	int CAPNHAT3;
	int CAPNHAT4;
	int CAPNHAT5;
	int CAPNHAT6;
	int CAPNHAT7;
	int CAPNHAT8;
	int CAPNHAT9;
};

class User
{
public:
	int CoordenadaX;
	int CoordenadaY;
	int getLevel;
	int getReset;
	char getName[11];
	//-- post item
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemHarmony;
	int				PostItem380;
	char*			PostItemSocket;
	int				PostItemX;
	int				PostItemY;
	int				GetPet;
	//--
	void			Load();
	void			Refresh();	
	bool			GetTarget();
	lpCharObj		lpPlayer;
	lpViewObj		lpViewPlayer;
	lpViewObj		lpViewTarget;
	BYTE			m_TargetType;	//1 - npc, 2 - attack
	int				m_MapNumber;
	int				m_CursorX;
	int				MagickAttack;
	int				m_CursorY;
	DWORD			m_TargetUpdateTick;
	short		m_MasterLevel;
	short		m_MasterPoint;
	__int64		m_MasterExp;
	__int64		m_MasterNextExp;
	int			m_QuestStat;
	bool InSafeZone;
	static void	AllInOne();
	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	CUSTOM_LOGO m_Logo[400];
	static char* GetMapName(signed int MapNumber);
	static void ChangeCharInfo(LPVOID This);
	int GetResetPointPriceWC(int AccountLevel);
	int GetResetPointPriceZen(int AccountLevel);
	int GetResetMasterSkillPriceWC(int AccountLevel);
	int GetResetMasterSkillPriceZen(int AccountLevel);
	int GetMaxStatPoint(int AccountLevel);
	int m_CustomResetPointPriceWC[MAX_ACCOUNT_LEVEL];
	int m_CustomResetPointPriceZen[MAX_ACCOUNT_LEVEL];
	int m_CustomMasterSkillPriceWC[MAX_ACCOUNT_LEVEL];
	int m_CustomMasterSkillPriceZen[MAX_ACCOUNT_LEVEL];
	int m_MaxStatPoint[MAX_ACCOUNT_LEVEL];
	void RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size);

	BYTE TitleBarSwitch;
	BYTE PlayerHPBarSwitch;
	BYTE SDByPass;
	//default class point
	int	d_Strength;
	int	d_Dexterity;
	int	d_Vitality;
	int	d_Energy;
	int	d_Leadership;

	// Fruit System
	int FStrength;
	int FDexterity;
	int FVitality;
	int FEnergy;
	int FLeadership;
	int FMaxPoint;


	int VipNhanVat;

	//abcd
	int	m_CAPNHAT1;
	int	m_CAPNHAT2;
	int	m_CAPNHAT3;
	int	m_CAPNHAT4;
	int	m_CAPNHAT5;
	int	m_CAPNHAT6;
	int	m_CAPNHAT7;
	int	m_CAPNHAT8;
	int	m_CAPNHAT9;
	void RecvCustomCAPNHATMu(PMSG_UPD_CAPNHAT_INFO * aRecv);//ok	
	#if(AUTOMOVE==1)
	//Auto Sendmove
	DWORD		IsSendMove;
	DWORD			MoveToX;
	DWORD			MoveToY;
	BYTE		KhongDiDuoc;
	int				m_MaxWarehouse;
	int				m_WarehouseNumber;
#endif
	

	BYTE		m_ResetItemCheck[5];
};
extern User gObjUser;