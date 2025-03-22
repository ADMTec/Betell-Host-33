#pragma once
#define	CMW_SPR_MAX							3
#define	CMW_SPR_STAT						1
#define CMW_CHAR_I1							0x791A
#define	CMW_DESC_LINE_MAX					3
#define	CMW_DESC_ROW_MAX					75
#define SYSTEM_CLASS						8

typedef struct
{
	bool bCharacterEnable[SYSTEM_CLASS - 3];
}CHARACTER_ENABLE, *LPCHARACTER_ENABLE;


#define CharMakeWinCreate						((void(__thiscall*)(BYTE * thisa)) 0x00402F20)
#define RenderCreateCharacter					((void(__thiscall*)(int thisa)) 0x00404570)

//--
#define CSpriteRender							((void(__thiscall*)(BYTE * Sprite)) 0x00416C40)
#define CRenderButtons							((void(__thiscall*)(BYTE * thisa)) 0x004AC520)
#define SpiriteSetPosition						((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define CButtonCreate							((void(__thiscall*)(BYTE * CButton, int iWidth, int iHeigth, int iTexture, int nMaxFrame, int nDownFrame, int nActiveFrame, int nDisableFrame, int nCheckUpFrame, int nCheckDownFrame, int nCheckActiveFrame, int nCheckDisableFrame)) 0x00401370)
#define CButtonSetText							((void(__thiscall*)(BYTE * thisa,const char* pszText, DWORD* adwColor)) 0x00401AE0)
#define CButtonEnable							((bool(__thiscall*)(BYTE * CButton)) 0x00416120)
#define CRenderBeginOpengl						((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x00636480)


#define CreateCharacterPointer					((int(__cdecl*)(int a3, int a4, char a5, char a6, float a7)) 0x0057DD40)
#define SetAction								((void(__cdecl*)(int o, int Action, bool bBlending)) 0x00542310) 
#define RegisterButton							((void(__thiscall*)(BYTE * thisa, BYTE * CButton)) 0x004AC500)
#define g_fScreenRate_x							*(float*)0x00E7C3D4
#define g_fScreenRate_y							*(float*)0x00E7C3D8
#define RenderInputText							((void (__thiscall*)(int a3, int a4, int a5)) 0x00596EF0)
#define InputText								*(int*)0xE8C544
#define g_iChatInputType						*(int*)0xE60960
#define SingleTextInputBox						((int(__thiscall*)(int thisa, int x, int y)) 0x00417EC0)
#define CheckMouseIn							((bool(__cdecl*)(int x, int y, int w, int h)) 0x00790B10)
#define EnableAlphaTest							((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define CRenderBitmaps							((void(__cdecl*)(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)) 0x00637C60)
#define SeparateTextIntoLines					((int(__cdecl*)( const char *lpszText, char *lpszSeparated, int iMaxLine, int iLineSize)) 0x004D5A40)
#define SpiriteGetHeight						((int(__thiscall*)(BYTE* thisa)) 0x00401C80)

class CCharMakeWin
{
public:
	CCharMakeWin( );
	virtual ~CCharMakeWin( );
	void Init();
	static void __thiscall SetLocationRF(BYTE * CButton, int cx, int cy, int eChangedPram);
public:
	POINTFLOAT m_ptPos;

	BYTE m_CharBtn[11][224];
};

extern CCharMakeWin g_CharMakeWin;