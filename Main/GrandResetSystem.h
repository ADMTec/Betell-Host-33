#pragma once

#include "Protocol.h"
#include "Defines.h"

#define	MAX_GR_GROUP		500
#define	MAX_GR_MONEY		1500000000
#define MAX_GR_ITEM			5

struct GR_REQ_USERDATA
{
	PSBMSG_HEAD h;
};

// -------------------------------------------------------------------------------

struct GR_ITEM_DATA
{
	WORD	ID;
	BYTE	MinLevel;
	BYTE	MaxLevel;
	BYTE	MinOption;
	BYTE	MaxOption;
	BYTE	IsLuck;
	BYTE	IsSkill;
	bool	IsExcellent;
	bool	IsAncient;
	bool	IsSocket;
};
// -------------------------------------------------------------------------

struct GR_REWARD_DATA
{
	int		LevelPoint;
	int		GensPoint;
	int		WCoinC;
	int		WCoinP;
	int		GoblinPoint;
	int		Credits;
};
// -------------------------------------------------------------------------

struct GR_GROUP_DATA
{
	int		MinGReset;
	int		MaxGReset;
	int		ReqReset[MAX_ACCOUNT_LEVEL];
	int		ReqLevel;
	int		ReqMoney[MAX_ACCOUNT_LEVEL];
	int		ItemCount;
	GR_ITEM_DATA	ItemData[MAX_GR_ITEM];
	GR_REWARD_DATA	RewardData[7];
};
// -------------------------------------------------------------------------
struct GR_CURRENT_DATA
{
	int MinGReset;
	int MaxGReset;
	int ReqLevel;
	int ReqReset;
	int ItemCount;
	GR_ITEM_DATA		ItemData[MAX_GR_ITEM];
	GR_REWARD_DATA RewardData;
};

// -------------------------------------------------------------------------------

struct GR_ANS_USERDATA
{
	PSBMSG_HEAD h;
	bool		ByDialog;
	int			Reset;
	int			GrandReset;
	int			GResetMoney;
	int			CommandPerGReset;
	int			QuestStat;
	GR_CURRENT_DATA GrData;
	bool		ItemCheck[MAX_GR_ITEM];
};

class GRSystem
{
	public:
			GRSystem();
	virtual ~GRSystem();
	// ----
	void	Init();
	void	Load();
	void	ReadGroupData(char * path);
	// ----
	int		GetResetMoney();
	//int		GetResetGroup();
	bool	CheckAllReq();
	// ----
	void	SetData(GR_ANS_USERDATA * aRecv);
	void	ReqResetFinish();
	void	GetResetResult();
	int		GetRewardPoints(int add);
	// ----
	//int		m_GroupLoadedCount;
	DWORD		GResetMoney;
	int			m_BonusCommand;
	//GR_GROUP_DATA	m_GroupData[MAX_GR_GROUP];
	GR_CURRENT_DATA m_GRData;
}; extern GRSystem gGRSystem;