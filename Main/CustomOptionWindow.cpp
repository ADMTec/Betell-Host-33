#include "stdafx.h"
#include "CustomOptionWindow.h"
#include "Import.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "Interface.h"
#include "CustomMessage.h"
#include "CustomFog.h"
#include "CustomDisableSystem.h"
#include "WindowsStruct.h"
#include "Common.h"

#if(CreateOptionWindows)

CHAR ReturnedString1[20];
CHAR ReturnedString2[20];
CHAR ReturnedString3[20];
CHAR ReturnedString4[20];
int FontSize = GetPrivateProfileIntA("FontConfig", "Main_Font_Height", 13, "./Settings.ini");;
int dword_10407904;
int dword_10407908;
int dword_1040790C;
int dword_10407910;
int dword_10407914;
int Resolucion;
int TickCount;
float flt_1040F5CC;
int dword_1040F5E8;
float flt_1040F5D0;
float flt_1040F5D4;
float flt_1040F5D8;
int dword_1040F5E0;

COptionWindow gOptionWindow;

COptionWindow::COptionWindow(void){
}

COptionWindow::~COptionWindow(void){
}

bool COptionWindow::CheckButtonPressed(int x, int y, int w, int h){
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}

void COptionWindow::Main(){
	SetCompleteHook(0xE8, 0x00848CB6, &COptionWindow::SetButtonInfo);
	SetCompleteHook(0xE8, 0x008491AE, &COptionWindow::RenderFrame);
	SetCompleteHook(0xE8, 0x008491B6, &COptionWindow::RenderContents);
	SetCompleteHook(0xE8, 0x008491BE, &COptionWindow::RenderButtons);

	SetCompleteHook(0xE8, 0x00849087, &COptionWindow::SetEffectLevel);
	SetCompleteHook(0xE8, 0x00848F07, &COptionWindow::SetSlideHelp);
	SetCompleteHook(0xE8, 0x00848E5D, &COptionWindow::SetAutoAttack);
	SetCompleteHook(0xE8, 0x00848EB2, &COptionWindow::SetWhisperSound);
	SetCompleteHook(0xE8, 0x00848F4B, &COptionWindow::SetGameSound);
	SetCompleteHook(0xE8, 0x008490F5, &COptionWindow::SetFocus);

	SetCompleteHook(0xE8, 0x772960, (int)COptionWindow::sub_10012A90);
	SetCompleteHook(0xE8, 0x7729B3, (int)COptionWindow::sub_10012AB0);
}

//----- (00848CD0) --------------------------------------------------------
int COptionWindow::SetButtonInfo(int a1){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = *(_DWORD *)(This + 16) + 80;
	int StartY = *(_DWORD *)(This + 20) + 230;
	int Width  = 53;
	int Height = 30;
	
    CNewUIButton_ChangeTextBackColor(This + 24, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0));
    CNewUIButton_ChangeButtonImgState(This + 24, 1, 31325, 1, 0, 0);
    CNewUIButton_ChangeButtonInfo((char *)(This + 24), StartX, StartY, Width, Height);
    CNewUIButton_ChangeImgColor(This + 24, 0, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
    return CNewUIButton_ChangeImgColor(This + 24, 1, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
}

//----- (008494B0) --------------------------------------------------------
void COptionWindow::RenderFrame(int a1){
	int This = *(DWORD *)(GetInstance() + 160);
    float StartX; // [sp+2Ch] [bp-8h]@1
    float StartY; // ST34_4@1
	float Width;
	float Height;

    StartX = (double)*(signed int *)(This + 16);
    StartY = (double)*(signed int *)(This + 20);
    Width  = 435.0f;
	Height = 260.0f;

	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	pDrawBarForm(StartX - 120, StartY + 5, Width, Height, 0, 0);

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	/*Title*/
	pSetFont(pTextThis(), (int) pFontNormal);
	pSetTextColor(pTextThis(), 211, 211, 211, 211);
	sub_4200F0_Addr(pTextThis(), 0);
	pSetBackgroundTextColor(pTextThis(), 0.04, 0.34, 0.0, 1.0);

	char * Title[] = {"OPTIONS"};
	char * SubTitle[] = {"ANTILAG", "GENERAL", "RESOLUTION", "FONT"};

	/*Options>Bar*/  gInterface.DrawBarForm(StartX - 120, StartY + 5, 435.0f, 12.0f, 0.4, 0.0, 0.0, 1.0);
	/*Options>Text*/ pDrawText(pTextThis(), StartX + 75, StartY + 7, Title[0], 60, 0,(LPINT) 3, 0);

	/*AntiLag*/      pDrawText((LPVOID)pTextThis(), StartX - 90, StartY + 25, SubTitle[0], 0, 0, (LPINT)1, 0);
	/*General*/      pDrawText((LPVOID)pTextThis(), StartX + 40, StartY + 25, SubTitle[1], 0, 0, (LPINT)1, 0);
	/*Resolution*/   pDrawText((LPVOID)pTextThis(), StartX + 190, StartY + 25, SubTitle[2], 0, 0, (LPINT)1, 0);
	/*Font*/         pDrawText((LPVOID)pTextThis(), StartX + 275, StartY + 25, SubTitle[3], 0, 0, (LPINT)1, 0);

    pSetBlend(false);
}

//----- (00849730) --------------------------------------------------------
int COptionWindow::RenderContents(int a1){
	int This = *(DWORD *)(GetInstance() + 160);
    int StartY_Text; // ST04_4@1
    int StartX_Text; // ST00_4@1

	pSetTextColor(pTextThis(), 211, 211, 211, 211);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

    StartY_Text = *(_DWORD *)(This + 20) + 48;
    StartX_Text = *(_DWORD *)(This + 16) + 40;

    /*Attack*/    pDrawText((LPVOID)pTextThis(), StartX_Text - 7, StartY_Text + 0, pGetTextLine(pTextLineThis, 386), 0, 0, (LPINT)1, 0);
    /*Whisper*/   pDrawText((LPVOID)pTextThis(), StartX_Text - 7, StartY_Text + 20, pGetTextLine(pTextLineThis, 387), 0, 0, (LPINT)1, 0);
	/*SlideHelp*/ pDrawText((LPVOID)pTextThis(), StartX_Text - 7, StartY_Text + 41, pGetTextLine(pTextLineThis, 919), 0, 0, (LPINT)1, 0);

    /*Volumen*/   pDrawText((LPVOID)pTextThis(), StartX_Text - 25, StartY_Text + 66, pGetTextLine(pTextLineThis, 389), 0, 0, (LPINT)1, 0);

	/*Effect*/    pDrawText((LPVOID)pTextThis(), StartX_Text - 26, StartY_Text + 108, pGetTextLine(pTextLineThis, 1840), 0, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 211, 211, 211, 211);

	char * TextPanel_AntiLag[] = {"Delete Fog", "Delete Glow", "Delete FOEffect", "Delete Object", "Delete Armor", "Delete Weapon",
	    "Delete Wings", "Delete Player", "Delete Static", "Delete Dynamic", "Delete Shades"};

	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 0,   TextPanel_AntiLag[0],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 20,  TextPanel_AntiLag[1],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 40,  TextPanel_AntiLag[2],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 60,  TextPanel_AntiLag[3],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 80,  TextPanel_AntiLag[4],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 100, TextPanel_AntiLag[5],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 120, TextPanel_AntiLag[6],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 140, TextPanel_AntiLag[7],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 160, TextPanel_AntiLag[8],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 180, TextPanel_AntiLag[9],  0, 0, (LPINT)1, 0);
	pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 200, TextPanel_AntiLag[10], 0, 0, (LPINT)1, 0);

    return pDrawText((LPVOID)pTextThis(), StartX_Text - 120, StartY_Text + 200, TextPanel_AntiLag[10], 0, 0, (LPINT)1, 0);
}

//----- (008499E0) --------------------------------------------------------
void COptionWindow::RenderButtons(int a1){
	int This = *(DWORD *)(GetInstance() + 160);
    float v16; // ST10_4@10
    float v17; // ST0C_4@10
    float v18; // ST3C_4@11
    float v19; // ST10_4@11
    float v20; // ST0C_4@11
    float v21; // ST10_4@12
    float v22; // ST0C_4@12
    float v23; // ST24_4@13
    float v24; // ST10_4@13
    float v25; // ST0C_4@13

    sub_7798F0(a1 + 24, 0);

    v16 = (double)(*(_DWORD *)(This + 20) + 115);
    v17 = (double)(*(_DWORD *)(This + 16) + 45);

	/*BUTTONS = Inicio Anti-Lag System*/
	/*>FOG*/
	if(!gFog.EnableFog){
		pDrawButton(31743, v17 - 145, v16 - 70, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 - 70, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 - 70, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!gFog.EnableFog){
			gFog.EnableFog = true;
		}else{
			gFog.EnableFog = false;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>GLOW*/
	if(DisableGlowEffect){
		pDrawButton(31743, v17 - 145, v16 - 50, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 - 50, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 - 50, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!DisableGlowEffect){
			DisableGlowEffect = 1;
		}else{
			DisableGlowEffect = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>FOEffect*/
	if(EnableEffect15){
		pDrawButton(31743, v17 - 145, v16 - 30, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 - 30, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 - 30, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!EnableEffect15){
			gCDisableSystem.KG_ActivateEffect15_1();
			EnableEffect15 = 1;
		}else{
			gCDisableSystem.KG_ActivateEffect15_2();
			EnableEffect15 = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>OBJECT*/
	if(EnableObjects){
		pDrawButton(31743, v17 - 145, v16 - 10, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 - 10, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 - 10, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!EnableObjects){
			gCDisableSystem.KG_ActivateInvisibleObjects_1();
			EnableObjects = 1;
		}else{
			gCDisableSystem.KG_ActivateInvisibleObjects_2();
			EnableObjects = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>ARMOR*/
	if(Transparency1){
		pDrawButton(31743, v17 - 145, v16 + 10, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 10, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 10, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!Transparency1){
			gCDisableSystem.KG_ActivateInvisibleArmors_1();
			Transparency1 = 1;
		}else{
			gCDisableSystem.KG_ActivateInvisibleArmors_2();
			gCDisableSystem.KG_ActivateInvisibleArmors_X();
			Transparency1 = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>WEAPON*/
	if(Transparency2){
		pDrawButton(31743, v17 - 145, v16 + 30, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 30, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 30, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!Transparency2){
			gCDisableSystem.KG_ActivateInvisibleWeapons_1();
			Transparency2 = 1;
		}else{
			gCDisableSystem.KG_ActivateInvisibleWeapons_2();
			Transparency2 = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>WING*/
	if(Transparency3){
		pDrawButton(31743, v17 - 145, v16 + 50, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 50, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 50, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!Transparency3){
			gCDisableSystem.KG_ActivateInvisibleWings_1();
			Transparency3 = 1;
		}else{
			gCDisableSystem.KG_ActivateInvisibleWings_2();
			Transparency3 = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>PLAYER*/
	if(Invisibility){
		pDrawButton(31743, v17 - 145, v16 + 70, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 70, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 70, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!Invisibility){
			gCDisableSystem.KG_ActivateInvisiblePlayer_1();
			Invisibility = 1;
		}else{
			gCDisableSystem.KG_ActivateInvisiblePlayer_2();
			Invisibility = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>STATIC*/
	if(NewStaticEffect){
		pDrawButton(31743, v17 - 145, v16 + 90, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 90, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 90, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!NewStaticEffect){
			gCDisableSystem.KG_ActivateStaticEffect_1();
			NewStaticEffect = 1;
		}else{
			gCDisableSystem.KG_ActivateStaticEffect_2();
			NewStaticEffect = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>DYNAMIC*/
	if(NewDynamicEffect){
		pDrawButton(31743, v17 - 145, v16 + 110, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 110, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 110, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!NewDynamicEffect){
			gCDisableSystem.KG_ActivateDynamicEffect_1();
			NewDynamicEffect = 1;
		}else{
			gCDisableSystem.KG_ActivateDynamicEffect_2();
			NewDynamicEffect = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*>SHADES*/
	if(NewActiveShades){
		pDrawButton(31743, v17 - 145, v16 + 130, 16, 16, 0, 16);
	}else{
		pDrawButton(31743, v17 - 145, v16 + 130, 16, 16, 0, 0);
	}
	if(gOptionWindow.CheckButtonPressed(v17 - 145, v16 + 130, 16, 16) && GetTickCount() >= gOptionWindow.Delay_AntiLag + 250) {
		if(!NewActiveShades){
			gCDisableSystem.KG_ActiveShades_1();
			NewActiveShades = 1;
		}else{
			gCDisableSystem.KG_ActiveShades_2();
			NewActiveShades = 0;
		}
		gOptionWindow.Delay_AntiLag = GetTickCount();
	}
	/*BUTTONS = Fin Anti-Lag System*/

	/*BUTTONS = Inicio General System*/
	float StartX = v17;
	float StartY = v16;
	
	/*Automatic Attack*/
    if ( *(_BYTE *)(This + 196) ){
        pDrawButton(31593, StartX - 30, StartY - 70, 15.0, 15.0, 0.0, 0.0);
    }else{
        pDrawButton(31593, StartX - 30, StartY - 70, 15.0, 15.0, 0.0, 15.0);
    }

	/*Whisper*/
    if ( *(_BYTE *)(This + 197) ){
        pDrawButton(31593, StartX - 30, StartY - 50, 15.0, 15.0, 0.0, 0.0);
    }else{
        pDrawButton(31593, StartX - 30, StartY - 50, 15.0, 15.0, 0.0, 15.0);
    }

	/*Slide Help*/
    if ( *(_BYTE *)(This + 198) ){
        pDrawButton(31593, StartX - 30, StartY - 30, 15.0, 15.0, 0.0, 0.0);
    }else{
        pDrawButton(31593, StartX - 30, StartY - 30, 15.0, 15.0, 0.0, 15.0);
    }

	/*Volumen*/
    pDrawGUI(31596, StartX - 32, StartY + 10, 124.0, 16.0);
    if ( *(_DWORD *)(This + 200) > 0 ){
        float NW = (double)*(signed int *)(This + 200) * 12.40000057220459;
        pDrawGUI(31597, StartX - 32, StartY + 10, NW, 16.0);
    }
	SetEffectVolumeLevel(*(_DWORD *)(This + 200));

	/*Effect*/
    pDrawGUI(31594, StartX - 32, StartY + 50, 141.0, 29.0);
    if ( *(_DWORD *)(This + 204) >= 0 ){
        float MW = (double)(*(_DWORD *)(This + 204) + 1) * 28.20000076293945;
        pDrawGUI(31595, StartX - 32, StartY + 50, MW, 29.0);
    }
    /*BUTTONS = Fin General System*/

    /*BUTTONS = Inicio Resolution System*/

	char * TxtResolution[] = {"640x480","800x600","1024x768","1280x1024","1366x768","1440x900","1600x900","1680x1050","1600x1280","1920x1080"};

	pSetTextColor(pTextThis(), 211, 211, 211, 211);
	pSetBackgroundTextColor(pTextThis(), 0.04, 0.34, 0.0, 1.0);

	/*640x480*/
    if ( pWinWidth == 640 && pWinHeight == 480){
		gInterface.DrawBarForm(StartX + 140, StartY - 70, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY - 70, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY - 70, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(640, 480);
		gOptionWindow.ResolutionReqKey(0);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY - 64, TxtResolution[0], 0, 0, (LPINT)1, 0);

	/*800x600*/
    if ( pWinWidth == 800 && pWinHeight == 600){
		gInterface.DrawBarForm(StartX + 140, StartY - 50, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY - 50, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY - 50, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(800, 600);
		gOptionWindow.ResolutionReqKey(1);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY - 44, TxtResolution[1], 0, 0, (LPINT)1, 0);

	/*1024x768*/
    if ( pWinWidth == 1024 && pWinHeight == 768){
		gInterface.DrawBarForm(StartX + 140, StartY - 30, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY - 30, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY - 30, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1024, 768);
		gOptionWindow.ResolutionReqKey(2);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY - 24, TxtResolution[2], 0, 0, (LPINT)1, 0);

	/*1280x1024*/
    if ( pWinWidth == 1280 && pWinHeight == 1024){
		gInterface.DrawBarForm(StartX + 140, StartY - 10, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY - 10, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY - 10, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1280, 1024);
		gOptionWindow.ResolutionReqKey(3);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY - 4, TxtResolution[3], 0, 0, (LPINT)1, 0);

	/*1366x768*/
    if ( pWinWidth == 1366 && pWinHeight == 768){
		gInterface.DrawBarForm(StartX + 140, StartY + 10, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 10, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 10, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1366, 768);
		gOptionWindow.ResolutionReqKey(4);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 14, TxtResolution[4], 0, 0, (LPINT)1, 0);

	/*1440x900*/
    if ( pWinWidth == 1440 && pWinHeight == 900){
		gInterface.DrawBarForm(StartX + 140, StartY + 30, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 30, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 30, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1440, 900);
		gOptionWindow.ResolutionReqKey(5);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 34, TxtResolution[5], 0, 0, (LPINT)1, 0);

	/*1600x900*/
    if ( pWinWidth == 1600 && pWinHeight == 900){
		gInterface.DrawBarForm(StartX + 140, StartY + 50, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 50, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 50, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1600, 900);
		gOptionWindow.ResolutionReqKey(6);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 54, TxtResolution[6], 0, 0, (LPINT)1, 0);

	/*1680x1050*/
    if ( pWinWidth == 1680 && pWinHeight == 1050){
		gInterface.DrawBarForm(StartX + 140, StartY + 70, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 70, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 70, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1680, 1050);
		gOptionWindow.ResolutionReqKey(7);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 74, TxtResolution[7], 0, 0, (LPINT)1, 0);

	/*1600x1280*/
    if ( pWinWidth == 1600 && pWinHeight == 1280){
		gInterface.DrawBarForm(StartX + 140, StartY + 90, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 90, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 90, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1600, 1280);
		gOptionWindow.ResolutionReqKey(8);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 95, TxtResolution[8], 0, 0, (LPINT)1, 0);

	/*1920x1080*/
    if ( pWinWidth == 1920 && pWinHeight == 1080){
		gInterface.DrawBarForm(StartX + 140, StartY + 110, 65.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
    }else{
        gInterface.DrawBarForm(StartX + 140, StartY + 110, 65.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
    }
	if(gOptionWindow.CheckButtonPressed(StartX + 140, StartY + 110, 65.0f, 20.0f)){
		gOptionWindow.ResolutionInGame(1920, 1080);
		gOptionWindow.ResolutionReqKey(9);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 154, StartY + 115, TxtResolution[9], 0, 0, (LPINT)1, 0);

	/*BUTTONS = Fin Resolution System*/

	/*BUTTONS = Inicio Font System*/

	char * TxtFontSize[] = {"9","11","13","15","17","19","21","23","25"};

	if( pWinFontHeight == 9){
		gInterface.DrawBarForm(StartX + 230, StartY - 70, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY - 70, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY - 70, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(9);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 239, StartY - 65, TxtFontSize[0], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 11){
		gInterface.DrawBarForm(StartX + 230, StartY - 50, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY - 50, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY - 50, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(11);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY - 45, TxtFontSize[1], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 13){
		gInterface.DrawBarForm(StartX + 230, StartY - 30, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY - 30, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY - 30, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(13);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY - 25, TxtFontSize[2], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 15){
		gInterface.DrawBarForm(StartX + 230, StartY - 10, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY - 10, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY - 10, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(15);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY - 5, TxtFontSize[3], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 17){
		gInterface.DrawBarForm(StartX + 230, StartY + 10, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY + 10, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY + 10, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(17);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY + 15, TxtFontSize[4], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 19){
		gInterface.DrawBarForm(StartX + 230, StartY + 30, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY + 30, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY + 30, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(19);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY + 35, TxtFontSize[5], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 21){
		gInterface.DrawBarForm(StartX + 230, StartY + 50, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY + 50, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY + 50, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(21);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY + 55, TxtFontSize[6], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 23){
		gInterface.DrawBarForm(StartX + 230, StartY + 70, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY + 70, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY + 70, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(23);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY + 75, TxtFontSize[7], 0, 0, (LPINT)1, 0);

	if( pWinFontHeight == 25){
		gInterface.DrawBarForm(StartX + 230, StartY + 90, 25.0f, 20.0f, 0.7, 0.0, 0.0, 1.0);
	}else{
		gInterface.DrawBarForm(StartX + 230, StartY + 90, 25.0f, 20.0f, 0.4, 0.0, 0.0, 1.0);
	}
	if(gOptionWindow.CheckButtonPressed(StartX + 230, StartY + 90, 25.0f, 20.0f)){
		gOptionWindow.FontSizeInGame(25);
	}
	pDrawText((LPVOID)pTextThis(), StartX + 237, StartY + 95, TxtFontSize[8], 0, 0, (LPINT)1, 0);

	/*BUTTONS = Fin Font System*/
}

bool COptionWindow::SetAutoAttack(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16);
	int StartY = (double)*(signed int *)(This + 20);
	return CheckMouseIn(StartX + 15, StartY + 45, 10, 12);
}

bool COptionWindow::SetWhisperSound(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16);
	int StartY = (double)*(signed int *)(This + 20);
	return CheckMouseIn(StartX + 15, StartY + 65, 10, 12);
}

bool COptionWindow::SetSlideHelp(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16);
	int StartY = (double)*(signed int *)(This + 20);
	return CheckMouseIn(StartX + 15, StartY + 85, 12, 12);
}

bool COptionWindow::SetGameSound(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16);
	int StartY = (double)*(signed int *)(This + 20);
	return CheckMouseIn(StartX + 10, StartY + 120, 141.0f, 16.0f);
}

bool COptionWindow::SetEffectLevel(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16);
	int StartY = (double)*(signed int *)(This + 20);
	return CheckMouseIn(StartX + 10, StartY + 170, 141.0f, 29.0f);
}

bool COptionWindow::SetFocus(){
	int This = *(DWORD *)(GetInstance() + 160);
	int StartX = (double)*(signed int *)(This + 16) - 14;
	int StartY = (double)*(signed int *)(This + 20) - 14;
	return CheckMouseIn(StartX - 120, StartY, 435.0f, 280.0f);
}

LONG COptionWindow::ResolutionReqKey(BYTE Data){
    HKEY v1;			// ecx@0
    HKEY phkResult;	// [sp+0h] [bp-4h]@1
    phkResult = v1;
    if ( !RegOpenKeyA(HKEY_CURRENT_USER, "Software\\Webzen\\Mu\\Config", &phkResult) )
        RegSetValueExA(phkResult, "Resolution", 0, 4u, &Data, 4u);
    return RegCloseKey(phkResult);
}

void COptionWindow::ResolutionInGame(int a1, int a2){
    int v2;		// esi@1
    DWORD v3;	// edi@1
    int v4;		// eax@2
    int v5;		// eax@2
    DWORD *v6;	// esi@2
    v2 = a2;
    v3 = a1;
    if ( pMUIsLoaded ){
        pWinWidth = a1;
        pWinHeight = a2;
        pWinWidthReal = (double)(signed int)a1 / 640.0;
		pWinHeightReal = (double)a2 / 480.0;
        SetWindowPos(pGameWindow, 0, 0, 0, a1, a2 + 30, 0x116u);
        sub_630BC0();
        sub_596AC0(1);
        v4 = (int)sub_482B70();
        *(DWORD*)(v4 + 40) = v3;
        *(DWORD*)(v4 + 44) = v2;
        v5 = (int)sub_407B20();
        *(DWORD*)(v5 + 40) = v3;
        *(DWORD*)(v5 + 44) = v2;
        v6 = (DWORD*)pWindowThis();
        sub_785720(v6[3], *v6, v6[4], 0, 382);
        pWinFontHeight = FontSize;
        sub_830A20(v6[45], *v6, 1, 1);
		SetDouble((LPVOID)oCam_ClipX,2000.0f);
	    SetDouble((LPVOID)oCam_ClipXCS,1000.0f);
    }
}

HFONT COptionWindow::Func_NormalFont(){
    HFONT result; // eax@2
    if ( !strcmp(ReturnedString1, "0") )
        result = CreateFontA(dword_10407904, 0, 0, 0, 700, 0, 0, 0, 1u, 0, 0, 3u, 0, 0);
    else
        result = CreateFontA(dword_10407904, 0, 0, 0, 700, 0, 0, 0, 1u, 0, 0, 3u, 0, ReturnedString1);
    return result;
}

HFONT COptionWindow::Func_BoldFont(){
    HFONT result; // eax@2
    if ( !strcmp(ReturnedString2, "0") )
        result = CreateFontA(dword_10407908, 0, 0, 0, 400, 0, 0, 0, 1u, 0, 0, 3u, 0, 0);
    else
        result = CreateFontA(dword_10407908, 0, 0, 0, 400, 0, 0, 0, 1u, 0, 0, 3u, 0, ReturnedString2);
    return result;
}

HFONT COptionWindow::Func_BigBoldFont(){
    HFONT result; // eax@2
    if ( !strcmp(ReturnedString3, "0") )
        result = CreateFontA(dword_1040790C, 0, 0, 0, 700, 0, 0, 0, 1u, 0, 0, 3u, 0, 0);
    else
        result = CreateFontA(dword_1040790C, 0, 0, 0, 700, 0, 0, 0, 1u, 0, 0, 3u, 0, ReturnedString3);
    return result;
}

int COptionWindow::FontSizeInGame(int a1){
    int v1; // esi@1
    DWORD *v2; // eax@1
    int result; // eax@1
    FontSize = a1;
    v1 = a1;
    pWinFontHeight = a1;
    dword_10407904 = a1;
    dword_10407908 = a1;
    dword_1040790C = a1 + 1;
    dword_10407910 = a1;
    dword_10407914 = a1;
    pFontNormal = gOptionWindow.Func_NormalFont();
    pFontBold = gOptionWindow.Func_BoldFont();
    pFontBigBold = gOptionWindow.Func_BigBoldFont();;
    pFontNormal2 = gOptionWindow.Func_BoldFont();
    switch ( v1 ){
        case 9:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 9", ".\\Settings.ini");
            break;
        case 11:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 11", ".\\Settings.ini");
            break;
        case 13:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 13", ".\\Settings.ini");
            break;
        case 15:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 15", ".\\Settings.ini");
            break;
        case 17:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 17", ".\\Settings.ini");
            break;
        case 19:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 19", ".\\Settings.ini");
            break;
        case 21:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 21", ".\\Settings.ini");
            break;
        case 23:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 23", ".\\Settings.ini");
            break;
        case 25:
            result = WritePrivateProfileStringA("FontConfig", "Main_Font_Height", " 25", ".\\Settings.ini");
            break;
        default:
            return result;
    }
    return result;
}

void COptionWindow::sub_10012A90(){
  return sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
}

int COptionWindow::sub_10012AB0(){
  float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
  return sub_6358A0_Addr(1.0, v2, 20.0, 2000.0);
}

#endif