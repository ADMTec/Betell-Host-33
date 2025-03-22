#include "stdafx.h"
#include "NUTHUONGDAN.h"
//#include "SOLAR_CUSTOM_TEXT.h"
#include "CustomMessage.h"
#include "Interface.h"
#include "User.h"
#include "Defines.h"
#include "Protocol.h"
#include "Common.h"
#include "Glow.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "StatsAdvance.h"
#include "CustomFont.h"

SOLAR_BUTTON_HUONGDAN G_SOLAR_BUTTON_HUONGDAN;

SOLAR_BUTTON_HUONGDAN::SOLAR_BUTTON_HUONGDAN()
{
	G_SOLAR_BUTTON_HUONGDAN.DataMap.XSW_Minimap = 119; //-- MiniMapX (Mover Minimapa Izquierda o Derecha) //toa do nut
	G_SOLAR_BUTTON_HUONGDAN.DataMap.YSW_Minimap = 27; //-- MiniMapY (Minimapa Arriba) (Mover Minimapa Arriba o Abajo)
}

void SOLAR_BUTTON_HUONGDAN::DRAW_BUTTON()
{
	DRAW_WINDOW_BUTTON();
}

void SOLAR_BUTTON_HUONGDAN::DRAW_WINDOW_BUTTON()
{	

	//if (!gInterface.CheckWindow(Character))
	//{
	//	return;
	//}

	if (gInterface.CheckWindow(Inventory)
	|| gInterface.CheckWindow(Character) //-- 13 & 16
	|| gInterface.CheckWindow(Warehouse) //-- 8
	|| gInterface.CheckWindow(Shop) //-- 12
	|| gInterface.CheckWindow(ChaosBox) //-- 9
	|| gInterface.CheckWindow(Trade) //-- 7
	|| gInterface.CheckWindow(Store) //-- 14
	|| gInterface.CheckWindow(OtherStore) //-- 15
	|| gInterface.CheckWindow(LuckyCoin1) //-- 60
	|| gInterface.CheckWindow(NPC_ChaosMix)
	|| gInterface.CheckWindow(MoveList) //-- 76
	|| gInterface.Data[SOLAR_NEW_MENU_MAIN].OnShow == true)
	{
		return;
	}

//	if (!gInterface.CheckWindow(Character))
//
//	{
//
//		return;
//	}
//
//		pSetCursorFocus = true;

	//kiem tra dieu kien




	float v10; // ST08_4@1
	float v11; // ST04_4@1
	float v12; // ST08_4@1
	float v13; // ST04_4@1


	v10 = (double) G_SOLAR_BUTTON_HUONGDAN.DataMap.YSW_Minimap;
	v11 = (double) G_SOLAR_BUTTON_HUONGDAN.DataMap.XSW_Minimap;
	
	//--Mover Barra MiniMapa
		float InitialX = v11;
		float InitialY = v10;
		float InitialXx = v13;
		float InitialYy = v12;
		float cursorX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
		float cursorY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;
		float cursorXx = pCursorXx >= MAX_WIN_WIDTH ? 0 : pCursorXx;
		float cursorYy = pCursorYy >= MAX_WIN_HEIGHT ? 0 : pCursorYy;

	//	if (gInterface.IsWorkZone3(InitialX, InitialY, 30, 30, true)) {  //vi tri keo tha
	//		if (!G_SOLAR_BUTTON_HUONGDAN.Moving && GetKeyState(VK_LBUTTON) & 0x8000 && GetTickCount() >= G_SOLAR_BUTTON_HUONGDAN.DelayMove + 150) {
	//			G_SOLAR_BUTTON_HUONGDAN.Moving = true;
	//			G_SOLAR_BUTTON_HUONGDAN.maxX = cursorX;
	//			G_SOLAR_BUTTON_HUONGDAN.maxY = cursorY;
	//			G_SOLAR_BUTTON_HUONGDAN.DelayMove = GetTickCount();
	//		}	
	//	}
	//	if (G_SOLAR_BUTTON_HUONGDAN.Moving) {
	//		InitialX = v11 + (cursorX - G_SOLAR_BUTTON_HUONGDAN.maxX);
	//		InitialY = v10 + (cursorY - G_SOLAR_BUTTON_HUONGDAN.maxY);
	//		InitialX = InitialX < 5 ? 5 : InitialX;
	//		InitialX = InitialX > 630 ? 630 : InitialX;
	//		InitialY = InitialY < 5 ? 5 : InitialY;
	//		InitialY = InitialY > 410 ? 410 : InitialY;
	//		G_SOLAR_BUTTON_HUONGDAN.ultimoX = InitialX;
	//		G_SOLAR_BUTTON_HUONGDAN.ultimoY = InitialY;
	//	}
	//	if (G_SOLAR_BUTTON_HUONGDAN.Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
	//		G_SOLAR_BUTTON_HUONGDAN.Moving = false;
	//		G_SOLAR_BUTTON_HUONGDAN.DataMap.XSW_Minimap = InitialX;
	//		G_SOLAR_BUTTON_HUONGDAN.DataMap.YSW_Minimap = InitialY;
	//		G_SOLAR_BUTTON_HUONGDAN.ultimoX = InitialX;
	//		G_SOLAR_BUTTON_HUONGDAN.ultimoY = InitialY;
	//	}
	//-- Mover Barra MiniMapa Termina

	int x, y, w, h, x1, y1, w1, h1 ,f, w2, h2;

	//-- Boton Acercar
	x = InitialX; //Minimapa v2
	y = InitialY; //Minimapa v2
	w = 90; //toa do hinh anh nut
	h = 60;
	w2 = 170; //toa do hinh anh
	h2 = 340;


	x1 = InitialX; //Minimapa v2
	y1 = InitialY; //Minimapa v2
	w1 = 65; //vi tri hien menu tren nut
	h1 = 30;
	f = 80;
	

	if(pCheckMouseOver(x, y, w + 20, h+ 30 ))
	{
		pSetCursorFocus = true;
	}
	//RenderBitmap(0x9980, x, y, w1, h1 + 30, 0, 0, 1, 1, 1, 1, 0.0);
	//gInterface.DrawGUI(eSAMPLEBUTTON2, x, y + 210);

	if(pCheckMouseOver( x1, y1, w1, h1 ))// buuton even
	{
		

		pSetCursorFocus = true;
	if( *(BYTE*)0x8793386 )
			{
				if( GetTickCount() >= G_SOLAR_BUTTON_HUONGDAN.DataMap.TimerEventVK + 200 )
				{
				
				//PMSG_TICKET_SEND pMsg;
				//pMsg.header.set(0xFB, 57, sizeof(pMsg));
				//DataSend((BYTE*)&pMsg, pMsg.header.size);
					
					
			//=================================================================
				G_SOLAR_BUTTON_HUONGDAN.DataMap.TimerEventVK = GetTickCount();
				}
			}


	}

}

void SOLAR_BUTTON_HUONGDAN::DrawTextTTTTTT()
{
}
void SOLAR_BUTTON_HUONGDAN::DrawTextTTTTTT2()
{
}
