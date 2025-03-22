#pragma once
#include "Protocol.h"
#include <vector>
typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);
#define pIsKeyRelease			((bool(__cdecl*)(int)) 0x791050)

struct PMSG_RENT_SKIN_SEND
{
	PBMSG_HEAD2 h;
	BYTE Type;
	int  Value;
};

struct RENT_SKIN_DATA
{
	int		Id;
	int		Skin;
	int		Price;
	int		Value1;
	int		Value2;
	int		Value3;
	int		Value4;
};

struct PMSG_SENT_SKIN_RECV
{
	PBMSG_HEAD2 h;
	int				Skin;
	RENT_SKIN_DATA	Data;
};

class cRentSkin
{
public:
	cRentSkin();
	~cRentSkin();
	void SetRect(float a1, float a2, float a3, float a4);
	bool CheckRect();
	void Init();
	void Draw();
	void SendRequest(BYTE type, int value);
	void RecvData(BYTE* a);
	void Clear();
	RENT_SKIN_DATA* FindSkin(int id);
	RENT_SKIN_DATA* FindId(int id);
	static void BuyAction(LPVOID pClass);
	static void NextAction(LPVOID pClass);
	static void PrevAction(LPVOID pClass);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);

	float x;
	float y;
	float w;
	float h;
	bool Drawing;
	int	Skin;
	int Selected;
	DWORD TickCount;
	std::vector<RENT_SKIN_DATA> m_Data;
};

extern cRentSkin RentSkin;