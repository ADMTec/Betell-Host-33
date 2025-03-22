#pragma once
#include "Defines.h"
// ----------------------------------------------------------------------------------------------
#define Main_PrintGlobal 00597630H;

//#define RenderBoolean		((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
//#define CreateGuildMark		((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)
//
//#define CreateGuildMark ((void(__cdecl*)(int nMarkIndex, bool blend)) 0x005FA170)
//#define RenderBoolean ((void(__cdecl*)(int x, int y, DWORD c)) 0x0053F870)

#define RenderBoolean									((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
#define CreateGuildMark									((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)
#define RenderBitmap									((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)


class Other
{
public:
	float	Zoom;
	float	RotationY;
	void	Load();
	// ----
	void	Crack();

	char TextVN[500][500];

#if(SACHTHUOCTINH_NEW == 1)
	char TextVN_SachThuocTinh[120][120];
#endif

#if(PHUKIEN_NEW == 1)
	char TextVN_PhuKien[120][120];
#endif

#if(DANH_HIEU_NEW)
	char TextVN_DanhHieu[120][120];
#endif

#if(TU_LUYEN_NEW)
	char TextVN_TuLuyen[205][205];
#endif



	static HFONT LoadNewFontA(int nHeight,
	int nWidth,
	int nEscapement,
	int nOrientation,
	int fnWeight,
	DWORD fdwItalic,
	DWORD fdwUnderline,
	DWORD fdwStrikeOut,
	DWORD fdwCharSet,
	DWORD fdwOutputPrecision,
	DWORD fdwClipPrecision,
	DWORD fdwQuality,
	DWORD fdwPitchAndFamily,
	LPCTSTR lpszFace);

}; extern Other gOther;

#define TEXTVN_FILE "./Data/Custom/TextVN.dat"

extern int Server;
// ----------------------------------------------------------------------------------------------
