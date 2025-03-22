#include "stdafx.h"
#include "UserPanel.h"
#include "User.h"
#include "Interface.h"
#include "NewInterface.h"
#include "Controller.h"
#include "ServerInfo.h"
#include "Achievements.h"
#include "PartySearchSettings.h"
#include "Ranking.h"
#include "Smithy.h"
#include "MapTeleport.h"
#include "LuckySpin.h"
#include "CustomJewelBank.h"
#include "Util.h"
#include "ItemMarket.h"
#include "Font.h"
#include "MuaVip.h"
// -------------------------------------------------------------------------------

CUserPanel gUserPanel;
// -------------------------------------------------------------------------------

CUserPanel::CUserPanel()
{
	this->Init();
}
// -------------------------------------------------------------------------------

CUserPanel::~CUserPanel()
{

}
// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------


void CUserPanel::DrawUserPanelV2()
{
	if (!gInterface.Data[eUSERPANEL_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	float MainWidth = 190.0;
	float MainHeight = gInterface.Data[eUSERPANEL_MAIN].Height;
	float StartY = 0;
	float StartX = MAX_WIN_WIDTH - gInterface.Data[eUSERPANEL_MAIN].Width;
	float MainCenter = StartX + (MainWidth / 2);

	gInterface.DrawGUI(eUSERPANEL_MAIN, StartX, StartY);
	gInterface.DrawGUI(eUSERPANEL_LEFT, StartX, StartY + gInterface.Data[eUSERPANEL_TITLE].Height);
	gInterface.DrawGUI(eUSERPANEL_RIGHT, MAX_WIN_WIDTH - gInterface.Data[eUSERPANEL_LEFT].Width, StartY + gInterface.Data[eUSERPANEL_TITLE].Height);
	gInterface.DrawGUI(eUSERPANEL_TITLE, StartX, StartY);
	gInterface.DrawGUI(eUSERPANEL_FOOTER, StartX, 384);
	gInterface.DrawGUI(eUSERPANEL_CLOSE, StartX + MainWidth - gInterface.Data[eUSERPANEL_CLOSE].Width + 3, -1);

	gFont[TAHOMA_BOLD_14]->DrawText(StartX + 85, StartY + 12, Fcolor->Red, Fcolor->Trans, 15, (LPINT)5, "User Panel");

	if (gInterface.IsWorkZone(eUSERPANEL_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eUSERPANEL_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eUSERPANEL_CLOSE, StartX + MainWidth - gInterface.Data[eUSERPANEL_CLOSE].Width + 3, -1, Color);
		gInterface.DrawToolTip(gInterface.Data[eUSERPANEL_CLOSE].X + 5, gInterface.Data[eUSERPANEL_CLOSE].Y + 24, "Close");
	}


	int count = 0;
	
	for (int i = this->StartIndex; i < BUTTONS_COUNT; i++)
	{
		if (count == MAX_ON_PAGE2)
		{
			return;
		}

		if (!this->buttons_active_[i])
		{
			continue;
		}

		gNewInterface.DrawButton(eUserPanelBtn1 + i, StartX + 30, StartY + 50 + (count * 25), 130, 20, &gServerInfo.MenuButton, &gServerInfo.MenuButtonClick, &gServerInfo.MenuButtonHover, this->buttons_text_[i]);
		count++;
	}
}

bool CUserPanel::EventUserPanelV2(DWORD Event, MOUSEHOOKSTRUCTEX* lpMouse)
{
	if (!gInterface.Data[eUSERPANEL_MAIN].OnShow)
	{
		return false;
	}

	float MainWidth = 190.0;
	float MainHeight = gInterface.Data[eUSERPANEL_MAIN].Height;
	float StartY = 0;
	float StartX = MAX_WIN_WIDTH - gInterface.Data[eUSERPANEL_MAIN].Width;
	float MainCenter = StartX + (MainWidth / 3);

	if (gNewInterface.IsWorkZone(StartX+30, StartY+50, 105 + 500, 380 + 30))
	{
		if (Event == WM_MOUSEWHEEL)
		{
			if (((int)lpMouse->mouseData) > 0)
			{
				if (this->StartIndex > 0)
				{
					this->StartIndex--;
				}
			}

			if (((int)lpMouse->mouseData) < 0)
			{
				if (this->StartIndex < BUTTONS_COUNT - MAX_ON_PAGE)
				{
					this->StartIndex++;
				}
			}
			return true;
		}

		DWORD CurrentTick = GetTickCount();

		for (int i = 0; i < BUTTONS_COUNT; i++)
		{
			int index = i + eUserPanelBtn1;

			if (gNewInterface.IsWorkZone(index))
			{
				if (!this->buttons_active_[i])
				{
					continue;
				}

				DWORD Delay = (CurrentTick - gNewInterface.m_Data[index].EventTick);

				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[index].OnClick = true;
					continue;
				}

				gInterface.Data[index].OnClick = false;

				if (Delay < 500)
				{
					continue;
				}

				gInterface.Data[index].EventTick = GetTickCount();

				this->UserPanelSwitchStateV2();
				switch (i)
				{
				case 0: //Event Timer
					gEventTimer.EventTimerSwitch();
					break;
				case 1: //Buy Vip
					gInterface.OpenVipWindow();
					break;
				case 2: //Jewels Bank
					gCustomJewelBank.OpenWindow();
					break;
				case 3: //Settings
					gInterface.SwitchSettingsWindowState();
					break;
				case 4: //Achievements
					gAchievements.CGWindowOpen();
					break;
				case 5: //ParrtySettings
					gInterface.SwitchPartySettingsWindowState();
					break;
				case 6: //Change Class
					gInterface.ChangingClassWindowState();
					break;
				case 7: //Fruit Bank
					gInterface.Fruit_State();
					break;
				case 8: //Ranking
					CG_RequestSend(0xFF, 0x21);
					gRanking.Show = true;
					break;
				case 9: //Command Window
					gCustomCommandInfo.OpenCommandWindow();
					break;
				case 10: //Smithy
					gSmithy.SwitchSmithyWindowState();
					break;
				case 11:
					gLuckySpin.SwitchLuckySpinWindowState();
					break;
				case 12:
					g_ItemMarket.SwitchResetStatsWindowState();
					g_ItemMarket.CGReqItemList(); ///fix
					break;
				case 13:
					//G_BEXO_MUA_VIP.OPEN_WINDOW_MUA_VIP();  funcaoclairton()
					break;
				default:
					MessageBox(0, "Error! Contact server administrator", "Error [0x01]", 0); 
				}
				return true;
			}
		}

		return true;
	}
	return false;
}

void CUserPanel::EventUserPanelWindow(DWORD Event)
{
	if (!gInterface.Data[eUSERPANEL_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(eUSERPANEL_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eUSERPANEL_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eUSERPANEL_CLOSE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eUSERPANEL_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eUSERPANEL_CLOSE].EventTick = GetTickCount();
		gUserPanel.UserPanelSwitchStateV2();
	}
}

void CUserPanel::UserPanelSwitchStateV2()
{
	//gNewInterface.m_Data[eUserPanel].OnShow == true ? gNewInterface.m_Data[eUserPanel].Close() : gNewInterface.m_Data[eUserPanel].Open(430);
	if (gInterface.Data[eUSERPANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eUSERPANEL_MAIN].Close();
	}
	else
	{
		this->StartIndex = 0;
		gInterface.Data[eUSERPANEL_MAIN].Open();
	}
}

bool CUserPanel::check_chaos_castleV2(signed int MapNumber)
{
	gUserPanel.UserPanelSwitchStateV2();
	return 1;
}

void CUserPanel::Init()
{
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		this->buttons_active_[i] = 0;
	}

	SetCompleteHook(0xE8, 0x00811D18, &CUserPanel::check_chaos_castleV2);
	this->StartIndex = 0;
}
// -------------------------------------------------------------------------------

void CUserPanel::CGUserPanelSettingsRecv(PMSG_USER_PANEL_SETTINGS_RECV* lpMsg)
{
	for(int i=0;i<BUTTONS_COUNT;i++)
	{
		this->buttons_active_[i] = lpMsg->buttons_active[i];
		strcpy_s(this->buttons_text_[i], lpMsg->buttons_text[i]);
	}
}
// ----------------------------------------------------------------------------------------------