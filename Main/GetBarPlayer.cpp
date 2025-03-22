#include "StdAfx.h"
#include "GetBarPlayer.h"
#include "Util.h"
#include "Import.h"
#include "Protect.h"
#include "TMemory.h"
#include "User.h"

GetBarPlayer JumPlayer;

GetBarPlayer::GetBarPlayer()
{
}


GetBarPlayer::~GetBarPlayer()
{
}

__declspec(naked) void PlayerInfoCheckDelect()
{
	static DWORD Addr_JMP = 0x00842869;
	_asm
	{
		JMP[Addr_JMP]
	}
}

int valor = 0;

void GensLogoPlayer(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
{
	gObjUser.Refresh();
	RenderBitmap(a1, a2 - valor, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

void PlayerGuildLogo(int a1, int a2, char *a3)
{
	gObjUser.Refresh();

	int result = *(DWORD *)(a3 + 668);

	if ( (*(WORD *)(result + 124) == 0))
	{
		valor = 15;
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 18, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}
	
	if ( !(*(WORD *)(result + 124) == 0))
	{
		valor = 0;
		CreateGuildMark(*(WORD *)(result + 124), 1999);
		RenderBitmap(31740, a1 - 8000, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	RenderBoolean(a1,a2,a3);
}

void GetBarPlayer::Load()
{
	
	SetCompleteHook(0xE8, 0x005BAFAB, &PlayerGuildLogo);

	SetCompleteHook(0xE8,0x007C5DB0, &GensLogoPlayer);

	SetCompleteHook(0xE9, 0x00842859, &PlayerInfoCheckDelect);

	if(gProtect.m_MainInfo.AlwaysnameShowType == 1)
	{
		SetByte(0x81C03FA, 0x01);
	}
	
}