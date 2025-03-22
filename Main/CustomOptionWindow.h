#pragma once

#if(CreateOptionWindows)

#define sub_630BC0   ((bool(*)()) 0x630BC0)
#define sub_596AC0	((int(__cdecl*)(int a1)) 0x596AC0)
#define sub_407B20	((int (__cdecl*)( )) 0x00407B20)
#define sub_785720	((char(__thiscall*)(DWORD This, int a2, int a3, int a4, int a5)) 0x785870)
#define sub_830A20	((char(__thiscall*)(DWORD This, int a2, int a3, int a4)) 0x830B70)
#define sub_779410 ((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x007792C0)

#define CNewUIButton_ChangeButtonInfo     ((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x779410)
#define CNewUIButton_ChangeButtonImgState ((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define CNewUIButton_ChangeImgColor       ((int(__thiscall*)(int This, int a5, int a6))0x00779740)
#define CNewUIButton_ChangeTextBackColor  ((int(__thiscall*)(int This, int a6))0x007C1C80)

#define SetEffectVolumeLevel              ((char(__cdecl *)(signed int a1)) 0x004D5B70)
#define CheckMouseIn				      ((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define WindowsOptionPanel                ((int(__thiscall*)(int This))0x00861620)

class COptionWindow{
    public:
	    COptionWindow();
	    ~COptionWindow();
	    void Main();
		static int SetButtonInfo(int a1);
		static void RenderFrame(int a1);
		static int RenderContents(int a1);
		static void RenderButtons(int a1);

		static bool SetEffectLevel();
		static bool SetSlideHelp();
		static bool SetAutoAttack();
		static bool SetWhisperSound();
		static bool SetGameSound();
		static bool SetFocus();

		static void ResolutionInGame(int a1, int a2);
		static LONG ResolutionReqKey(BYTE data);

	    static HFONT Func_NormalFont();
		static HFONT Func_BoldFont();
		static HFONT Func_BigBoldFont();
		static int FontSizeInGame(int a1);

		static void sub_10012A90();
		static int sub_10012AB0();

		static bool CheckButtonPressed(int x, int y, int w, int h);
    private:
		DWORD Delay_AntiLag;
};extern COptionWindow gOptionWindow;

#endif