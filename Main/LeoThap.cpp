#include "StdAfx.h"
#if(LEOTHAP == 1)
#include "LeoThap.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Protect.h"
#include "CustomFont.h"
//#include "GLFont.h"
#include "Interface.h"
LeoThap gLeoThap;

LeoThap::LeoThap(void)
{
}

LeoThap::~LeoThap(void)
{
}

void LeoThap::GCData(PMSG_LEOTHAP_TIME* lpMsg) // OK
{
	this->m_TimeCount = lpMsg->TimeCount;
	this->m_Map = lpMsg->Map;
	this->State = lpMsg->State;
	this->eventTime = lpMsg->eventTime;
}

void LeoThap::GCData2(PMSG_LEOTHAP_TIME2* lpMsg) // OK
{
	this->m_TimeCount2 = lpMsg->TimeCount;
	this->m_Map2 = lpMsg->Map;
	this->State2 = lpMsg->State;
}

void LeoThap::LeoThapCountdown()
{
	float MainWidth = 210.0;
	float MainHeight = 14.0;
	float StartY = 100.0;
	float StartX = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	int TxtCount = -1;
	int TxtStart = StartY + 88;

	if(pMapNumber == this->m_Map && this->m_TimeCount > 0)
	{
		pDrawGUI(81538, 518.5, 350, 120.0, 76.0);
		char text1[20];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;
		//------------
		
		totalseconds	= this->m_TimeCount;
		if(this->State == 0)
		{
			totalseconds = totalseconds - (this->eventTime/3 * 2 * 60);
		}
		if(this->State == 1)
		{
			totalseconds = totalseconds - (this->eventTime/3 * 60);
		}

		hours			= totalseconds/3600;
		minutes			= (totalseconds/60) % 60;  
		seconds			= totalseconds % 60;
		
		if (hours > 23)
		{
			days = hours/24;
			wsprintf(text1, "%d day(s)+", days);
		}
		else
		{
			wsprintf(text1, "%02d:%02d", minutes, seconds);
		}
		//------------

		CustomFont.Draw(CustomFont.FontNormal, StartX + (MainWidth / 2) + 320 + (/*g_fsFrame.fScreenWinAdd*/ - 110), TxtStart + (33.0f * TxtCount) + 210, 0xFFF370FF, 0x0, 108, 0, 3, "Tiempo restante:" );

		CustomFont.Draw(CustomFont.FontBold, StartX + (MainWidth / 2) + 320 + /*g_fsFrame.fScreenWinAdd*/ - 110, TxtStart + (33.0f * TxtCount) + 235, 0xFFF370FF, 0x0, 108, 0, 3, text1);
	}
}

void LeoThap::LeoThapDelayTime()
{
	if(this->m_TimeCount2 > 0)
	{
		if(this->State2 == 1)
		{
			/*g_pRenderText.SetTextColor(0xFF,0xFF,0xFF,0xFF);
			g_pRenderText.SetFont(m_hFontBold);
			g_pRenderText.CRenderText(-3, 140,"Đăng ký Vượt Tháp : %d (s)", this->m_TimeCount2,0);*/
			CustomFont.Draw(CustomFont.FontBold, 0, 190, 0xD517EBFF, 0x0, 115, 0, 3, "Regístrese en Tower Over : %d (s)", this->m_TimeCount2);
		}
		if(this->State2 == 2)
		{
			CustomFont.Draw(CustomFont.FontBold, 0, 190, 0xD517EBFF, 0x0, 115, 0, 3, "Preparate para pelear: %d (s)", this->m_TimeCount2);
		}
	}
}

void LeoThap::ResetData()
{
	this->m_TimeCount = 0;
	this->m_TimeCount2 = 0;
}
void LeoThap::DrawLeoThap()
{
    if( !gInterface.Data[eLEOTHAP_MAIN].OnShow )
    {
        return;
    }
    // ----
    DWORD ItemNameColor     = eWhite;
    float MainWidth         = 230.0;
    float MainHeight        = 313.0;
    float StartY            = 100.0;
    float StartX            = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
    float MainCenter        = StartX + (MainWidth / 3);
    float ButtonX           = MainCenter - (29.0 / 2);
    // ----
    gInterface.DrawGUI(eLEOTHAP_MAIN, StartX - 170, StartY - 50);
    gInterface.DrawGUI(eLEOTHAP_TITLE, StartX - 170, StartY - 50);
    StartY = gInterface.DrawRepeatGUI(eLEOTHAP_FRAME, StartX - 170, StartY + 17.0, 13);
    gInterface.DrawGUI(eLEOTHAP_FOOTER, StartX - 170, StartY);
    gInterface.DrawGUI(eLEOTHAP_CLOSE, StartX + MainWidth - gInterface.Data[eLEOTHAP_CLOSE].Width - 170, gInterface.Data[eLEOTHAP_TITLE].Height + gInterface.Data[eLEOTHAP_CLOSE].Height - 47);
    // ----
    if( gInterface.IsWorkZone(eLEOTHAP_BUTTON_GATE1) )
    {
        if( gInterface.Data[eLEOTHAP_BUTTON_GATE1].OnClick )
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 28, 0, 30);
        }
        else
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 28, 0, 29);
        }
    }
    else
    {
        gInterface.DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 28, 0, 0);
    }
 
    if( gInterface.IsWorkZone(eLEOTHAP_BUTTON_GATE2) )
    {
        if( gInterface.Data[eLEOTHAP_BUTTON_GATE2].OnClick )
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 63, 0, 30);
        }
        else
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 63, 0, 29);
        }
    }
    else
    {
        gInterface.DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 63, 0, 0);
    }
 
    if( gInterface.IsWorkZone(eLEOTHAP_BUTTON_GATE3) )
    {
        if( gInterface.Data[eLEOTHAP_BUTTON_GATE3].OnClick )
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 98, 0, 30);
        }
        else
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 98, 0, 29);
        }
    }
    else
    {
        gInterface.DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 98, 0, 0);
    }
 
    if( gInterface.IsWorkZone(eLEOTHAP_BUTTON_GATE4) )
    {
        if( gInterface.Data[eLEOTHAP_BUTTON_GATE4].OnClick )
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 133, 0, 30);
        }
        else
        {
            gInterface.DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 133, 0, 29);
        }
    }
    else
    {
        gInterface.DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, gInterface.Data[eLEOTHAP_MAIN].Y + 133, 0, 0);
    }
 
	if( gInterface.IsWorkZone(eLEOTHAP_CLOSE) )
    {
        DWORD Color = eGray100;
        // ----
        if( gInterface.Data[eLEOTHAP_CLOSE].OnClick )
        {
            Color = eGray150;
        }
        // ----
        gInterface.DrawColoredGUI(eLEOTHAP_CLOSE, gInterface.Data[eLEOTHAP_CLOSE].X, gInterface.Data[eLEOTHAP_CLOSE].Y, Color);
        gInterface.DrawToolTip(gInterface.Data[eLEOTHAP_CLOSE].X + 5, gInterface.Data[eLEOTHAP_CLOSE].Y + 25, "Cerrar");
    }
    // ----
    //this->DrawFormat(eGold, StartX - 160, 60, 210, 3, "Khiêu Chiến Boss");
	CustomFont.Draw(CustomFont.FontBold, 125, 60, 0xFFFF00FF, 0x0, 0, 0, 0, "TORRE EXITOSA");
    // ----
    gInterface.DrawGUI(eLEOTHAP_POINT, StartX - 150, gInterface.Data[eLEOTHAP_MAIN].Y + 42); //
    gInterface.DrawFormat(eOrange, StartX - 135, gInterface.Data[eLEOTHAP_MAIN].Y + 43, 200, 1, "Puerta 1");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 43, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, gInterface.Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, gInterface.Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
    // ----
    gInterface.DrawGUI(eLEOTHAP_POINT, StartX - 150, gInterface.Data[eLEOTHAP_MAIN].Y + 82-5); //
    gInterface.DrawFormat(eOrange, StartX - 135, gInterface.Data[eLEOTHAP_MAIN].Y + 83-5, 200, 1, "Puerta 2");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 83-5, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, gInterface.Data[eLEOTHAP_MAIN].Y + 100-5, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, gInterface.Data[eLEOTHAP_MAIN].Y + 100-5, 82.0, 2.0); // gạch ngang
    // ----
    gInterface.DrawGUI(eLEOTHAP_POINT, StartX - 150, gInterface.Data[eLEOTHAP_MAIN].Y + 122-10); //
    gInterface.DrawFormat(eOrange, StartX - 135, gInterface.Data[eLEOTHAP_MAIN].Y + 123-10, 200, 1, "Puerta 3");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 123-10, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, gInterface.Data[eLEOTHAP_MAIN].Y + 140-10, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, gInterface.Data[eLEOTHAP_MAIN].Y + 140-10, 82.0, 2.0); // gạch ngang
    // ----
    gInterface.DrawGUI(eLEOTHAP_POINT, StartX - 150, gInterface.Data[eLEOTHAP_MAIN].Y + 162-15); //
    gInterface.DrawFormat(eOrange, StartX - 135, gInterface.Data[eLEOTHAP_MAIN].Y + 163-15, 200, 1, "Puerta 4");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 163-15, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, gInterface.Data[eLEOTHAP_MAIN].Y + 180-15, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, gInterface.Data[eLEOTHAP_MAIN].Y + 180-15, 82.0, 2.0); // gạch ngang
    // ----
	gInterface.DrawFormat(eWhite, StartX - 150, gInterface.Data[eLEOTHAP_MAIN].Y + 233-10, 200, 1, "Después de seleccionar la entrada adecuada, muévete y prepárate para destruir al Boss");
	gInterface.DrawFormat(eExcellent, StartX - 125, gInterface.Data[eLEOTHAP_MAIN].Y + 248-10, 200, 1, "- Cuidado con otros jugadores");
	gInterface.DrawFormat(eExcellent, StartX - 125, gInterface.Data[eLEOTHAP_MAIN].Y + 248+5, 200, 1, "- Cuando se lleve a cabo el Evento, la entrada estará cerrada.");
	CustomFont.Draw(CustomFont.FontBold, 55, 288, 0xFF0000FF, 0x0, 0, 0, 0, "Nota: ");

	pSetCursorFocus = true;
}
// ----------------------------------------------------------------------------------------------

bool LeoThap::EventLeoThap_Main(DWORD Event)
{
	this->EventLeoThap_All(Event);
	this->EventLeoThap_Close(Event);
	return true;
}

// ----------------------------------------------------------------------------------------------

bool LeoThap::EventLeoThap_All(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if( !gInterface.Data[eLEOTHAP_MAIN].OnShow )
	{
		return false;
	}

	int ObjectIDs[4] = 
	{ 
		eLEOTHAP_BUTTON_GATE1, 
		eLEOTHAP_BUTTON_GATE2, 
		eLEOTHAP_BUTTON_GATE3, 
		eLEOTHAP_BUTTON_GATE4, 
	};
	gLeoThap.ResetData();
	for (int i = 0; i < 4; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 500 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();;
			gInterface.Data[eLEOTHAP_MAIN].Close();
			PMSG_LEOTHAP_SEND pRequest;
			pRequest.Number = i;
			pRequest.header.set(0xFF,0x90,sizeof(pRequest));
			DataSend((BYTE*)&pRequest,pRequest.header.size);
		}
	}
	return false;
}

// ----------------------------------------------------------------------------------------------
bool LeoThap::EventLeoThap_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eLEOTHAP_CLOSE].EventTick);
	// ----
	if( !gInterface.Data[eLEOTHAP_MAIN].OnShow || !gInterface.IsWorkZone(eLEOTHAP_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eLEOTHAP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eLEOTHAP_CLOSE].OnClick = false;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	gInterface.Data[eLEOTHAP_CLOSE].EventTick = GetTickCount();

	gInterface.Data[eLEOTHAP_MAIN].Close();
	// ----
	return false;
}
#endif
