#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

class SOLAR_BUTTON_HUONGDAN
{
public:
	//===================================================================================================================================================================
	SOLAR_BUTTON_HUONGDAN();
	void DRAW_BUTTON();
	//===================================================================================================================================================================
	void		OPEN_WINDOW_BUTTON() { gInterface.Data[SOLAR_BUTTON_HUONGDAN_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_BUTTON() { gInterface.Data[SOLAR_BUTTON_HUONGDAN_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_BUTTON() { return gInterface.Data[SOLAR_BUTTON_HUONGDAN_MAIN].OnShow; };
	void		DRAW_WINDOW_BUTTON();
	void        DrawTextTTTTTT();
	void        DrawTextTTTTTT2();
	bool        QuayLai;
	bool        QuayLai2;

struct LoadTypeMap
{
	/*+0*/   DWORD ModelID;
	/*+4*/   DWORD XSW_Minimap_Frame;
	/*+8*/   DWORD YSW_Minimap_Frame;
	/*+12*/  DWORD XSW_Minimap;
	/*+16*/  DWORD YSW_Minimap;
	/*+20*/  DWORD XSW_Time_Frame;
	/*+24*/  DWORD YSW_Time_Frame;
	/*+92*/  DWORD This_92;
	/*+96*/  DWORD This_96;
	/*+100*/ DWORD DropMoveUserX;
	/*+104*/ DWORD DropMoveUserY;
	/*+108*/ DWORD This_108;
	/*+112*/ DWORD This_112;
	/*+116*/ float CurrentMoveX;
	/*+120*/ float CurrentMoveY;
	/*+124*/ DWORD Scale;
	/*+126*/ DWORD TimerEventVK;
	/*+128*/ float Alpha;
};
	LoadTypeMap DataMap;

	DWORD DelayMove;
	bool Moving;
	short maxX;
	short maxY;
	DWORD ultimoX;
	DWORD ultimoY;

}; extern SOLAR_BUTTON_HUONGDAN G_SOLAR_BUTTON_HUONGDAN;
//===================================================================================================================================================================
//===================================================================================================================================================================
