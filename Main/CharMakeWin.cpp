#include "StdAfx.h"
#include "Util.h"
//#include "_struct.h"
#include "UIControl.h"
#include "CharMakeWin.h"

CCharMakeWin g_CharMakeWin;
CHARACTER_ENABLE g_CharCardEnable;
int btn_classname[11] = {20, 21, 22, 23, 24, 1687, 3150, 3175, 3179, 3193, 3200};
int Desc_classname[11] = {1705, 1706, 1707, 1708, 1709, 1690, 3152, 3178, 3180, 3193, 3200};
char m_aszJobDesc[CMW_DESC_LINE_MAX][CMW_DESC_ROW_MAX];

char* apsStat[11][4] =
{
	"18", "18", "15", "30", // 흑마법사.
	"28", "20", "25", "10", // 흑기사.
	"22", "25", "20", "15", // 요정.
	"26", "26", "26", "26", // 마검사.
	"26", "20", "20", "15", // 다크로드.
	"21", "21", "18", "23", // 소환술사.
	"32", "27", "25", "20", //-- RF
	"30", "30", "25", "24", //-- GrowLancer
	"13", "18", "14", "40", //-- RunerWizzard
	"28", "30", "15", "10", //-- Slayer
	"22", "18", "20", "25", //-- Gun Crasher
};

CCharMakeWin::CCharMakeWin( )
{
}


CCharMakeWin::~CCharMakeWin( )
{
}

__declspec(naked) void CharMakeWin_ClassDescrip()
{
	static DWORD var_addr = 0x0040385E;
	static DWORD CharSts = (DWORD)&Desc_classname;

	_asm
	{
		mov      ecx, CharSts
		mov      eax, dword ptr ss:[ebp-0x20]
		mov      eax, dword ptr ds:[eax+0xA50]
		mov      edx, dword ptr ss:[ecx+eax*4]
		mov      dword ptr ss:[ebp-0x14], edx
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_RenderDescrip()
{
	static DWORD var_addr = 0x004043C3;
	static DWORD CharSts = (DWORD)&m_aszJobDesc;

	_asm
	{
		mov      eax, CharSts
		lea      ecx, [eax + edx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_ClassStats()
{
	static DWORD var_addr = 0x004041A1;
	static DWORD CharSts = (DWORD)&apsStat;

	_asm
	{
		mov      edx, CharSts
		lea      edx, [edx + ecx]
		mov      eax, dword ptr ss:[ebp-0x4]
		mov      ecx, [edx + eax*4]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_ClassText()
{
	static DWORD var_addr = 0x00403176;
	static DWORD CharTxt = (DWORD)&btn_classname[0];

	_asm
	{
		mov      edx, CharTxt
		mov      eax, dword ptr ss:[ebp-0x10]
		mov      ecx, dword ptr ss:[edx + eax*4]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnSetText()
{
	static DWORD var_addr = 0x00403121;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnCreate1()
{
	static DWORD var_addr = 0x004031A2;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnCreate2()
{
	static DWORD var_addr = 0x004031BD;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		lea      edx, [ecx + eax]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnGetHeigth()
{
	static DWORD var_addr = 0x0040337C;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnSetLocation1()
{
	static DWORD var_addr = 0x004033C0;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnSetLocation2()
{
	static DWORD var_addr = 0x004033E0;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		add      ecx, 1120
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnSetLocation3()
{
	static DWORD var_addr = 0x00403404;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		add      ecx, 1344
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWin_BtnSetLocation4()
{
	static DWORD var_addr = 0x00403441;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      eax, CharBtn
		lea      ecx, [eax + edx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnReset( )
{
	static DWORD var_addr = 0x0040359A;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		lea      ecx, [ecx + eax]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnSelect( )
{
	static DWORD var_addr = 0x00402ED3;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		lea      ecx, [ecx + eax]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnShow( )
{
	static DWORD var_addr = 0x0040359A;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnUpdateCheck( )
{
	static DWORD var_addr = 0x00403920;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn;

	_asm
	{
		mov      ecx, CharBtn
		lea      ecx, [ecx + eax]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnUpdateReset( )
{
	static DWORD var_addr = 0x00403960;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn;

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnUpdateSelect( )
{
	static DWORD var_addr = 0x0040397F;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn;

	_asm
	{
		mov      ecx, CharBtn
		lea      ecx, [ecx + eax]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnEnable( )
{
	static DWORD var_addr = 0x0040375A;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnDisable( )
{
	static DWORD var_addr = 0x0040379C;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      edx, CharBtn
		lea      ecx, [edx + ecx]
		jmp      [var_addr]
	}
}

__declspec(naked) void CharMakeWinBtnBlocked( )
{
	static DWORD var_addr = 0x004037E1;
	static DWORD CharBtn = (DWORD)&g_CharMakeWin.m_CharBtn[0];

	_asm
	{
		mov      ecx, CharBtn
		lea      ecx, [ecx + eax]
		jmp      [var_addr]
	}
}

void RenderLogoCharacter(int x, int y, int width, int height)
{
	if ( *(BYTE*)0x7BD0483 )
	{
		switch ( *(BYTE*)0x7BD0483 )
		{
			case 7:
				*((float *)&*(LPVOID*)0x7BD0778 + 66) = 8.0;
				*((float *)&*(LPVOID*)0x7BD0778 + 67) = 0.0;
				*((float *)&*(LPVOID*)0x7BD0778 + 68) = -2.0;
				*((float *)&*(LPVOID*)0x7BD0778 + 24) = 8.8000002;
				*(float*)0x7BD0874 = *(float*)0x7BD0874 + 4.400000190734863;
				*(float*)0x7BD087C = *(float*)0x7BD087C - 2.0;
				break;
		}
	}
	CRenderBeginOpengl(x, y, width, height);
}

void CCharMakeWin::SetLocationRF(BYTE * CButton, int cx, int cy, int eChangedPram)
{
	int H = SpiriteGetHeight(g_CharMakeWin.m_CharBtn[0]);
	SpiriteSetPosition(g_CharMakeWin.m_CharBtn[6], cx, cy, eChangedPram);
#if(SYSTEM_CLASS >= 8)
	SpiriteSetPosition(g_CharMakeWin.m_CharBtn[7], cx, cy + (H * 3), eChangedPram);
#endif
}

void ReceiveCharacterCard_New(BYTE* ReceiveBuffer)
{
	int a1 = (int)ReceiveBuffer;
	g_CharCardEnable.bCharacterEnable[0] = false;
	g_CharCardEnable.bCharacterEnable[1] = false;
	g_CharCardEnable.bCharacterEnable[2] = false;
	g_CharCardEnable.bCharacterEnable[3] = false;
#if(SYSTEM_CLASS >= 8)
	g_CharCardEnable.bCharacterEnable[4] = false;
#endif

	if ( *(BYTE *)(a1 + 4) & 4 )
		g_CharCardEnable.bCharacterEnable[0] = true;
	if ( *(BYTE *)(a1 + 4) & 2 )
		g_CharCardEnable.bCharacterEnable[1] = true;
	if ( *(BYTE *)(a1 + 4) & 1 )
		g_CharCardEnable.bCharacterEnable[2] = true;
	if ( *(BYTE *)(a1 + 4) & 8 )
		g_CharCardEnable.bCharacterEnable[3] = true;
#if(SYSTEM_CLASS >= 8)
	if ( *(BYTE *)(a1 + 4) & 16 )
		g_CharCardEnable.bCharacterEnable[4] = true;
#endif
}

int SeparateClassDescripcion(const char *lpszText, char *lpszSeparated, int iMaxLine, int iLineSize)
{
	return SeparateTextIntoLines(lpszText, m_aszJobDesc[0], iMaxLine, iLineSize);
}

void * MemSetDescripcion(void * _Dst, int _Val, size_t _Size)
{
	return ::memset(m_aszJobDesc, 0,
		sizeof(char) * CMW_DESC_LINE_MAX * CMW_DESC_ROW_MAX);
}

void CCharMakeWin::Init()
{
	//SetByte(0x004030D1 + 0x3, SYSTEM_CLASS); //-- Create Btn
	SetByte(0x00402E96 + 0x3, SYSTEM_CLASS); //-- Reset Button
	SetByte(0x0040357C + 0x3, SYSTEM_CLASS); //-- Show Button
	SetByte(0x00403900 + 0x3, SYSTEM_CLASS); //-- Evento Button
	SetByte(0x00403942 + 0x3, SYSTEM_CLASS); //-- Evento Button
	SetByte(0x0040373F + 0x3, SYSTEM_CLASS); //-- Update Display
	SetDword(0x00631486 + 3, SYSTEM_CLASS);  //-- Load Logo Class BMD
	SetDword(0x0056FAEA + 3, (168 + SYSTEM_CLASS)); //-- Create Logo Class
	SetDword(0x0057DF7A + 3, (168 + SYSTEM_CLASS)); //-- Create Logo Class
	SetDword(0x005E10C1 + 3, (168 + SYSTEM_CLASS)); //-- Create Logo Class
	//--
	SetByte(0x00403860 + 1, CMW_DESC_LINE_MAX); //-- Separate text in 3 line
	SetByte(0x0040385E + 1, CMW_DESC_ROW_MAX); //-- line containe max 50 char
	SetByte(0x004043B6 + 2, CMW_DESC_ROW_MAX); //-- line containe max 50 char
	SetByte(0x0040301A + 1, 76); //-- Size Bar Descripcion
	
	SetCompleteHook(0xE8, 0x00403257, &MemSetDescripcion);
	SetCompleteHook(0xE9, 0x0040381E, &CharMakeWin_ClassDescrip);
	SetCompleteHook(0xE9, 0x004043B9, &CharMakeWin_RenderDescrip);
	SetCompleteHook(0xE8, 0x0040387B, &SeparateClassDescripcion);
	//--
	SetCompleteHook(0xE9, 0x00404197, &CharMakeWin_ClassStats);
	SetCompleteHook(0xE9, 0x00403126, &CharMakeWin_ClassText);
	SetCompleteHook(0xE9, 0x00403114, &CharMakeWin_BtnSetText);
	SetCompleteHook(0xE9, 0x00403195, &CharMakeWin_BtnCreate1);
	SetCompleteHook(0xE9, 0x004031B0, &CharMakeWin_BtnCreate2);
	//--
#if(SYSTEM_CLASS == 8)
	SetByte(0x00403352 + 0x2, 4); //-- PosicionY Stats info
	SetDword(0x0040336B + 0x1, 105); //-- Posicion Y Button pack1
	SetDword(0x004033E8 + 0x2, 220); //-- Posicion Y Button pack2
#endif
	SetCompleteHook(0xE9, 0x00403373, &CharMakeWin_BtnGetHeigth);
	SetCompleteHook(0xE9, 0x004033B6, &CharMakeWin_BtnSetLocation1); //-- dw - elf
	SetCompleteHook(0xE9, 0x004033D7, &CharMakeWin_BtnSetLocation2); //-- summoner
	SetCompleteHook(0xE8, 0x00403404, &CCharMakeWin::SetLocationRF); //-- rf - resting class
	SetCompleteHook(0xE9, 0x00403437, &CharMakeWin_BtnSetLocation4); //-- mg - dl
	//--
	SetCompleteHook(0xE9, 0x00402EA7, &CharMakeWinBtnReset);
	SetCompleteHook(0xE9, 0x00402EC9, &CharMakeWinBtnSelect);
	SetCompleteHook(0xE9, 0x00403590, &CharMakeWinBtnShow);
	SetCompleteHook(0xE9, 0x00403913, &CharMakeWinBtnUpdateCheck);
	SetCompleteHook(0xE9, 0x00403953, &CharMakeWinBtnUpdateReset);
	SetCompleteHook(0xE9, 0x00403972, &CharMakeWinBtnUpdateSelect);
	//--
	SetCompleteHook(0xE9, 0x00403750, &CharMakeWinBtnEnable);
	SetCompleteHook(0xE9, 0x00403792, &CharMakeWinBtnDisable);
	SetCompleteHook(0xE9, 0x004037D7, &CharMakeWinBtnBlocked);
	//--
	SetCompleteHook(0xE8, 0x0040464E, &RenderLogoCharacter);
	SetByte(0x004037B5 + 0x3, (SYSTEM_CLASS - 3)); //-- Crear personaje
	SetCompleteHook(0xE8, 0x006657B0, &ReceiveCharacterCard_New);
	SetDword(0x004037BE + 0x3, (DWORD)&g_CharCardEnable.bCharacterEnable);
	//--
	//SetDword(0x00631319 + 1, (DWORD)"Interface\\GFx\\none.tga");
	//SetDword(0x006312F9 + 1, (DWORD)"Interface\\GFx\\CharacterSelect_I1.tga");
}