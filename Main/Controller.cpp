#include "stdafx.h"
#include "resource.h"
#include "Controller.h"

#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "PartySearch.h"
#include "ControllerTextBox.h"
#include "PartySearchSettings.h"
//#include "ExQuestWinSystem.h"
#include "Achievements.h"
#include "EventTimer.h"
#include "Ranking.h"
#include "ShopSearch.h"
#include "NewParty.h"
#include "UserPanel.h"
#include "NewInterface.h"
#include "CustomRanking.h"
#include "Smithy.h"
#include "BufferSystem.h"
#include "MapTeleport.h"
#include "TeleportPanel.h"
#include "PKClear.h"
#include "LuckySpin.h"
#include "CustomJewelBank.h"
#include "ItemMarket.h"
#include "MonsterQuest.h"
#include "MultiCharacter.h"
#include "NewsBoard.h"
#include "MuaVip.h"
#include "DanhHieu.h"
#include "TuChanInterface.h"
#include "LeoThap.h"
#include "WindowsQuest.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------


char Notice_1[1024];
char Notice_2[1024];
char Notice_3[1024];
char Notice_4[1024];
char Notice_5[1024];
char Notice_6[1024];
char Notice_7[1024];
BOOL isNotice;


void __declspec(naked) iconHook()
{
	//- Custom Client Ico (S8)
	if (gProtect.m_MainInfo.CustomClientIconType == 1)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON2));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}

	//- Custom Client Ico (EX)
	if (gProtect.m_MainInfo.CustomClientIconType == 2)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON3));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}

	//- Custom Client Ico (Mu Plasma)
	if (gProtect.m_MainInfo.CustomClientIconType == 3)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON4));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}

	//- Custom Client Ico (Mu Plasma)
	if (gProtect.m_MainInfo.CustomClientIconType == 4)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON5));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}

	//- Custom Client Ico (Mu HX)
	if (gProtect.m_MainInfo.CustomClientIconType == 5)
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON6));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}

	//- Custom Client Ico (Classic)
	else
	{
		static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));

		static DWORD dwJmp = 0x004D0E3C;

		_asm
		{
			MOV EAX, dwIcon
			JMP dwJmp
		}
	}
}


bool Controller::Load()
{
	GetPrivateProfileString("Notice", "Notice_1", "", Notice_1, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_2", "", Notice_2, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_3", "", Notice_3, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_4", "", Notice_4, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_5", "", Notice_5, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_6", "", Notice_6, 1024, ".\\data\\Custom\\Notice.ini");
	GetPrivateProfileString("Notice", "Notice_7", "", Notice_7, 1024, ".\\data\\Custom\\Notice.ini");
	isNotice = FALSE;


	this->Instance = Instance;
	this->VKF9_State = 0;
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookExA(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
	}
	// ----
	if( !this->KeyboardHook )
	{
		this->KeyboardHook = SetWindowsHookExA(WH_KEYBOARD, this->Keyboard, gController.Instance, GetCurrentThreadId());
	}

	if (!this->KeyboardHook2)
	{
		this->KeyboardHook2 = SetWindowsHookEx(WH_KEYBOARD_LL, this->Keyboard2, gController.Instance, NULL);
		// ----
		if (!this->KeyboardHook2)
		{
			return false;
		}
	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if(GetForegroundWindow() != pGameWindow)
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}

	gController.wMouse = wParam;

	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;

	//gUserPanel.EventUserPanel(wParam, Mouse);
	#if (CAMARA==0)
	gCamera.Run(Mouse, wParam);
#endif
	gController.wMouse = wParam;
	#if(DEV_PLAYERSHOP)
	g_ItemMarket.Mouse(Mouse, wParam);
	#endif
	switch(wParam)
	{
		#if (CAMARA==0)
	case WM_MOUSEWHEEL:
		break;
#endif
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gInterface.EventVipWindow_Close(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);




			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);

			gInterface.EventBattlefieldWindow_Main(wParam);
			gInterface.EventBattlefieldWindow_Close(wParam);

			gInterface.EventCTCMiniWindow_Main(wParam);
			gInterface.EventCTCMiniWindow_Close(wParam);

			gInterface.EventPartySettingsWindow_Main(wParam);
			gInterface.EventPartySearchWindow_All(wParam);

			gInterface.EventCharacterWindow(wParam);
			gInterface.EventStatsAddWindow(wParam);
			gInterface.EventResetStatsWindow(wParam);
			


			G_BEXO_MUA_VIP.BEXO_CLICK_TRANG_MUA_VIP(wParam);
			G_BEXO_MUA_VIP.MAIN_MUA_VIP(wParam);

			G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
			G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);

			


#if (SELECTCHARACTER==1)
			gSelectChar.EventSelectChar(wParam);
#endif

			gAchievements.Button(wParam);

			gTuChanInterface.EventTuChanWindow_Main(wParam);

			gCMacroUIEx.ButtonNew(wParam);
			gCMacroUIEx.Button(wParam);

			
			#if WINDOWS_QUEST
			gWinQuestSystem.Button(wParam); // donde esta central
            #endif
			

			gCMacroUIEx.ButtonNew(wParam);
			gCMacroUIEx.Button(wParam);

			gInterface.EventEventTableWindow(wParam);

			gInterface.EventFruitWindow_Main(wParam);

			g_PersonalShopEx.Button(wParam);

			gInterface.EventChangingClassWindow_Main(wParam);

			gSmithy.Button(wParam);


			gInterface.EventResetWindow_Main(wParam);

			gInterface.EventWarehouseWindow_Main(wParam);
			gInterface.WareNext(wParam);
			gInterface.WarePrev(wParam);

#if(FACEBOOK)
			gInterface.EventoDrewNapThe_Open(wParam);
			gInterface.EventoDarwinFacebook_Open(wParam);
			//gInterface.EventDrawFanpage_Open(wParam);
			//gInterface.EventDrawGoup_Open(wParam);
#endif

#if(BOTOES_FUNCOES)
			gInterface.EVENT_TINHNANG_INTERFACE(wParam);
#endif

			gInterface.EventSettingsUI(wParam);

			//gUserPanel.EventUserPanelButton(wParam);

			gUserPanel.EventUserPanelWindow(wParam);

			g_BufferSystem.ButtonEvent(wParam);




#if(LEOTHAP == 1)
			gLeoThap.EventLeoThap_All(wParam);
			gLeoThap.EventLeoThap_Close(wParam);
            #endif


#if(CUSTOM_EX_TELEPORT_EVO==TRUE)
			g_ExTeleportEvo.Button(wParam);
#endif

#if(CUSTOM_MAP_TELEPORT)
			g_MapTeleport.MouseTeleportEx(wParam);
#endif
#if(CUSTOM_PKCLEAR_NPC==TRUE)
			g_PKClear.EventButton(wParam);
#endif
			gInterface.EventGrandResetWindow_Main(wParam);

			gLuckySpin.EventWindow_Main(wParam);

			gCustomJewelBank.CommandNext(wParam);
			gCustomJewelBank.CommandPrev(wParam);
			gCustomJewelBank.EventJewelBankWindow_Close(wParam);
			gCustomJewelBank.EventJewelBankWithDraw(wParam);

#if(ENABLE_MONSTER_QUEST)
				gMonsterQuest.EventCloseMainTable(wParam);
				gMonsterQuest.EventFinishMainTable(wParam);
#endif





			
			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);



			if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
			{
				if (gNewInterface.EventAllWindow(wParam, Mouse) == true)
				{
					return 1;
				}
			}
		}
		
		break;
		#if (CAMARA==0)
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);
break;
#endif
#if (CAMARA)
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Move(Mouse);
			}
			break;
		case WM_MBUTTONDOWN:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(1);
				gCamera.SetCursorX(Mouse->pt.x);
				gCamera.SetCursorY(Mouse->pt.y);
			}
			break;
		case WM_MBUTTONUP:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(0);
			}
			break;
		case WM_MOUSEWHEEL:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Zoom(Mouse);
			}
			break;
	
		#endif

	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( ((lParam >> 31) & 1) && (Code == HC_ACTION) )
	{
		if(GetForegroundWindow() != pGameWindow || pPlayerState != GameProcess)
		{
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}

		gController.wKeyBord = wParam;

	}

	if(GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess)
	{
		if(Code == HC_ACTION)
		{
			if(((lParam >> 31) & 1))
			{
				#if(DEV_PLAYERSHOP)
				g_ItemMarket.Keyboard(wParam);
				#endif
			}
		}
	}

	return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard2(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook2, Code, wParam, lParam);
	}
//if (GetKeyState('N') & 0x4000)  //ZEUS UP19 NEW NOTICIAS
//{
//	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow) && !gInterface.CheckWindow(ObjWindow::Guild))
//	{
//		gNewsBoard.ReqOpenMain();
//		
//	}
//}

	



	if (Code < 0) return CallNextHookEx(gController.KeyboardHook2, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);

		if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			//gConsole.AddMessage(5, "Pressed: %d", Hook.vkCode);
			if (gTextBoxController.ControlTextBox(Hook))
			{
				return 1;
			}
		}

		switch(Hook.vkCode)
		{
			// --
		case VK_F4:
		{
			//gInterface.SwitchSettingsWindowState();
			//G_BEXO_MUA_VIP.OPEN_WINDOW_MUA_VIP();

		}
		break;
		case VK_F5:
		{
			//gTuChanInterface.OpenTuChanWindow();
		}
		break;
		case VK_F6:
		{
			//gInterface.ChangingClassWindowState();  gCustomJewelBank.OpenWindow();
		}
		break;
		case 'J':
		{
			gCustomJewelBank.OpenWindow();
		}
		break;
		case VK_INSERT:
		{
			gAchievements.CGWindowOpen();
		}
		break;
		case VK_DELETE:
		{
			gInterface.SwitchSettingsWindowState();
		}
		break;
		case VK_F7:
		{
#if(ENABLE_MONSTER_QUEST)
				gMonsterQuest.DrawInfoTable = !gMonsterQuest.DrawInfoTable;
#endif
		}
		break;
		case VK_F8:
		{
		}
		
		break;	
		case VK_F9:
		{
			//g_MapTeleport.KeyboardTeleportEx();
			//G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();
		}
		break;
		case VK_F10:
		{
			gInterface.SwitchCamera();
		}
		break;
		case VK_F11:
		{
			gInterface.CameraInit();
		}

		
		

		break;
		case VK_F12:
		{
			if (gTrayMode.TempWindowProc == NULL)
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}
		break;
		case VK_ESCAPE:
		{
			gInterface.CloseChangingClassWindow();
			gInterface.CloseCustomWindow();
			gInterface.CloseEventTableWindow();
			gInterface.CloseFruitWindow();
			gInterface.CloseResetStatsWindow();
			gInterface.CloseStatsAddWindow();
			gInterface.CloseVipWindow();
			
			gInterface.Data[eRESET_MAIN].Close();
			gInterface.Data[eGRESET_MAIN].Close();
			gInterface.Data[eUSERPANEL_MAIN].Close();;
			
		}

		if (gTuChanInterface.CheckTuChanWindow())
		{
			gTuChanInterface.CloseTuChanWindow();
			return -1;
		}

		if (gInterface.CheckVaultWindow())
		{
			gInterface.CloseVaultWindow();
			return -1;
		}
		break;
		case VK_END:
		{
			if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
			{
				gUserPanel.UserPanelSwitchStateV2();
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;


		default:
		break;
		}
	} 
	return (LRESULT) NULL;
	
}



LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


