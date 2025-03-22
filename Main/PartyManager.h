#pragma once
#define MAX_PARTYS   7
#define MAX_ID_SIZE   10

typedef struct {
	BYTE         ID[MAX_ID_SIZE];
	BYTE         Number;
	BYTE         Map;
	BYTE         x;
	BYTE         y;
	int          currHP;
	int          maxHP;
} PRECEIVE_PARTY_LIST, * LPPRECEIVE_PARTY_LIST;

typedef struct {
	BYTE         stepLife;
	BYTE         stepMana;
	char         ID[MAX_ID_SIZE + 1];
} PRECEIVE_PARTY_INFO, * LPPRECEIVE_PARTY_INFO;

typedef struct {
	BYTE         Header[3];
	BYTE         Result;
	BYTE         Count;
} PRECEIVE_PARTY_LISTS, * LPPRECEIVE_PARTY_LISTS;

typedef struct {
	BYTE         Header[3];
	BYTE         Count;
} PRECEIVE_PARTY_INFOS, * LPPRECEIVE_PARTY_INFOS;


typedef struct
{
#pragma pack(1)
	BYTE Effect;
	DWORD count;
#pragma pack()
} PRECEIVE_PARTY_EFFECT_LIST, * LPPRECEIVE_PARTY_EFFECT_LIST;

typedef struct {
	BYTE         Header[3];
	char         ID[11];
	BYTE         Count;
} PRECEIVE_PARTY_EFFECT_INFOS, * LPPRECEIVE_PARTY_EFFECT_INFOS;

typedef struct //-- (size: 32)
{
	/*0*/	char    Name[11];
	int     Count;
	/*11*/	BYTE    Effect[16];
	/*12*/	DWORD   count[16];
} PARTY_BUFFS_DATA;

typedef struct //-- (size: 32)
{
	/*0*/	char    Name[11];
	/*11*/	BYTE    Number;
	/*12*/	BYTE    Map;
	/*13*/	BYTE    x;
	/*14*/	BYTE    y;
	/*16*/	int     currHP;
	/*20*/	int     maxHP;
	/*24*/	BYTE    stepHP;
	/*28*/	int     index;
} PARTY_D;

#define PartyNumber							*(DWORD*)0x81F6B6C
#define LeaveParty							((bool(__thiscall*)(DWORD thisa, int iIndex)) 0x0084B0B0)
#define PartyListWindow_Create				((bool(__thiscall*)(DWORD* pNewUIMng, int x, int y)) 0x0084B790)
#define PartyInfoWindow_BtnProcess			((bool(__thiscall*)(DWORD This)) 0x0084A270)
#define RenderMember_Statue					((void(__thiscall*)(DWORD *This, int iIndex, int pMember, bool bExitBtnRender)) 0x0084AD10)

#define UpdateBtnMouseEvent					((bool(__thiscall*)(BYTE *thisa)) 0x00779860)

#define ChangeBtnInfo						((void(__thiscall*)(BYTE *thisa, int x, int y, int sx, int sy)) 0x00779410)
#define ChangeBtnImgState					((void(__thiscall*)(BYTE *thisa, bool imgregister, int imgindex, bool overflg, bool isimgwidth, bool bClickEffect)) 0x00779350)


class CPartyManager
{
private:
	enum PARTY_BG_COLOR
	{
		PARTY_LIST_BGCOLOR_DEFAULT = 0,
		PARTY_LIST_BGCOLOR_RED,
		PARTY_LIST_BGCOLOR_GREEN
	};
public:
	CPartyManager(void);
	virtual ~CPartyManager(void);

	void Init();
	static void __thiscall SetListBGColor(DWORD* This);
	static bool __thiscall BtnProcess(DWORD This);
	static void LoadImages();
	void ReceivePartyBuff(BYTE* ReceiveBuffer);
	static void __thiscall RenderMemberStatue(DWORD* This, int iIndex, int pMember, bool bExitBtnRender);

	int pbyPagekey;
	BYTE BtnPartyExit[MAX_PARTYS][172];
	int iPartyListBGColor[MAX_PARTYS];
	bool bPartyMemberoutofSight[MAX_PARTYS];
};
extern BYTE PartyArray[32 * MAX_PARTYS];
extern CPartyManager g_pPartyManager;