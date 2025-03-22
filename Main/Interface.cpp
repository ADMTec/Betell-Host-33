#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "NPCRuud.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
//#include "ExQuestWinSystem.h"
#include "Achievements.h"
#include "EventTimer.h"
#include "Font.h"
#include "Ranking.h"
#include "ShopSearch.h"
#include "ChangeClass.h"
#include "NewParty.h"
#include "ResetSystem.h"
#include "ServerInfo.h"
#include "UserPanel.h"
#include "Smithy.h"
#include "BufferSystem.h"
#include "MapTeleport.h"
#include "TeleportPanel.h"
#include "PKClear.h"
#include "GrandResetSystem.h"
#include "LuckySpin.h"
#include "CustomJewelBank.h"
#include "ItemMarket.h"
#include "MonsterQuest.h"
#include "CustomFont.h"
#include "Bytes.h"
#include "SCharFrameHIght.h"
#include "MultiCharacter.h"
#include "CMacroUIEx.h"
#include "NewsBoard.h"
#include "NUTHUONGDAN.h"
#include "MiniMap.h"
#include "SelectWareHouse.h"
#include "MuaVip.h"
#include "DanhHieu.h"
#include "TuChanInterface.h"
#include "LeoThap.h"
#include "RentSkin.h"
#include "WindowsQuest.h"
#include "WindowsStruct.h"
#include <shellapi.h>

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}

#if WINDOWS_QUEST
void NewModelRender3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	glViewport2(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	gluPerspective2(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700u);
	glPushMatrix();
	glLoadIdentity();
	GetOpenGLMatrix(0x87933A0);
	EnableDepthTest();
	EnableDepthMask();

	RenderItem3D(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor4f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);
	pSetBlend(false);
}
#endif

void Interface::RenderObjectSystem()
{
	InitEncDec(); //Emoji
	if (gProtect.m_MainInfo.MonitorMS == 1) {
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if (gProtect.m_MainInfo.MonitorFPS == 1) {
		gInterface.iniciador = 1;
	}
	//51522
	//--
	//--
	//this->BindObject(FPS2, 30847, 131, 70, -1, -1);
	this->BindObject(eTIME, 30847, 131, 70, -1, -1);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	//--
	this->BindObject(eCTC_MINI_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCTC_MINI_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCTC_MINI_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCTC_MINI_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCTC_MINI_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCTC_MINI_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eBATTLEFIELD_MAIN, 0x7A5A, 222, 300, -1, -1);
	this->BindObject(eBATTLEFIELD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eBATTLEFIELD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eBATTLEFIELD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eBATTLEFIELD_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eBATTLEFIELD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);

	this->BindObject(EXBEXO_MUA_VIP_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_MUA_VIP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_MUA_VIP_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	if(gProtect.m_MainInfo.CustomInterfaceType == 0||gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
	}
	if (gProtect.m_MainInfo.CustomMenuType == 2){
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
	}
	}
	if(gProtect.m_MainInfo.CustomInterfaceType == 3||gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	#if(CHARACTER_INFO==1)
		if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
	this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		if (gProtect.m_MainInfo.CustomMenuType == 2)
	{
		this->BindObject(eMenu, 120111, 12, 10, -1, -1);
		}
#else
	this->BindObject(eMenu, 120111, 16, 12, -1, -1);
#endif
	}

	//Custom Store
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
		/*this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);*/
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);

	if (gProtect.m_MainInfo.MultiCharacterEnable == 1)
	{
#if (SELECTCHARACTER==1)
	//this->BindObject(eSELECTCHAR_LEFT, 0x7912, 25, 40, -1, -1);
	//this->BindObject(eSELECTCHAR_RIGHT, 0x7911, 25, 40, -1, -1);

	this->BindObject(eSELECTCHAR_LEFT, 32342, 20, 23, -1, -1);
	this->BindObject(eSELECTCHAR_RIGHT, 32343, 20, 23, -1, -1);
	//SetCompleteHook(0xFF, 0x004D5EE6, &gSelectChar.SelectChar);
	//gSelectChar.m_CharacterPage = 1;
#endif
	}

	


#if(LEOTHAP == 1)
	// Leo thap
	this->BindObject(eLEOTHAP_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eLEOTHAP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eLEOTHAP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eLEOTHAP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eLEOTHAP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eLEOTHAP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eLEOTHAP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE1, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE2, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE3, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE4, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE5, 0x7A5B, 54, 30, -1, -1);
#endif

	


	//this->Data[eTIME].OnShow = true;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--
	this->BindObject(eJewelOfBank, 51522, 230.0, 270.0, -1, -1);
	this->BindObject(eJewelOfBankPush, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankRemove, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankClose, 71521, 59, 28, -1, -1);

	switch (gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:

		
		//--
		//--
		//this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		//---
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);

		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 51522, 19, 19, -1, -1);
			this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		}*/

		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	//default:
		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}*/
		break;
	}
	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x8909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x8910, 75, 13, -1, -1);
		this->BindObject(eMoney3, 0x8911, 75, 13, -1, -1);
	}
	if (gProtect.m_MainInfo.DisableAdvance == 0)
	{
		g_StatsAdvance.Bind();
	}

	// ----
	this->BindObject(ePARTYSETTINGS_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(ePARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_GROW_LANCER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);

	this->BindObject(ePARTYSEARCH_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(ePARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	this->BindObject(ePARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);

	this->BindObject(eSTATSADD_MAIN, 0x7A5A, 222, 226, -1, -1);
	this->BindObject(eSTATSADD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSTATSADD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSTATSADD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSTATSADD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSTATSADD_TEXTBOX01, 0x9307, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX01, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX02, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX03, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX04, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX05, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	//
	this->BindObject(eRESETSTATS_MAIN, 0x7A5A, 222, 140, -1, -1);
	this->BindObject(eRESETSTATS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eRESETSTATS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eRESETSTATS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eRESETSTATS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eRESETSTATS_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eRESETSTATS_CHECK_WC, 0x7BAE, 15, 15, 390, 132);
	this->BindObject(eRESETSTATS_CHECK_STAT, 0x7BAE, 15, 15, 390, 152);
	this->BindObject(eRESETMASTER_CHECK_WC, 0x7BAE, 15, 15, 390, 172);
	this->BindObject(eRESETMASTER_CHECK_STAT, 0x7BAE, 15, 15, 390, 192);
	this->BindObject(eRESETSTATS_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	//
	this->BindObject(eCHARINFO_BTN_STAT, 0x7AA4, 16, 15, 475, 73);
	this->BindObject(eCHARINFO_BTN_RESSTAT, 0x7AA4, 16, 15, 475, 94);

	this->BindObject(eARROW_LEFT2, 0x7E59, 20, 22, -1, -1);
	this->BindObject(eARROW_RIGHT2, 0x7E5A, 20, 22, -1, -1);
	this->BindObject(eEVENTTABLE_MAIN, 0x7A5A, 190, 428, -1, -1);
	this->BindObject(eEVENTTABLE_TITLE, 0x7A79, 190, 64, -1, -1);
	this->BindObject(eEVENTTABLE_LEFT, 0x7A7B, 21, 320, -1, -1);
	this->BindObject(eEVENTTABLE_RIGHT, 0x7A7C, 21, 320, -1, -1);
	this->BindObject(eEVENTTABLE_FOOTER, 0x7A7D, 190, 45, -1, -1);
	this->BindObject(eEVENTTABLE_DIV, 0x7A62, 183, 21, -1, -1);
	this->BindObject(eEVENTTABLE_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eFruitClose, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eCHANGINGCLASS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_GL, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eRESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eRESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eRESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eRESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eRESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eRESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eRESET_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eRESET_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eRESET_FINISH, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eGRESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eGRESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eGRESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eGRESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eGRESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eGRESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eGRESET_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eGRESET_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eGRESET_FINISH, 0x7A5E, 128, 29, -1, -1);

	this->BindObject(eNextWare, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevWare, 31658, 17, 18, -1, -1);
	this->BindObject(eWAREHOUSE_MAIN, 0x7A5A, 222, 211, -1, -1);
	this->BindObject(eWAREHOUSE_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eWAREHOUSE_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eWAREHOUSE_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eWAREHOUSE_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eWAREHOUSE_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM1, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM2, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM3, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM4, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM5, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM6, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM7, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM8, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM9, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM10, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM11, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM12, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM13, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM14, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM15, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM16, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM17, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM18, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM19, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM20, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM21, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM22, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM23, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM24, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM25, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM26, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM27, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM28, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM29, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM30, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM31, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM32, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM33, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM34, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM35, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM36, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM37, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM38, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM39, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM40, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM41, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM42, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM43, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM44, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM45, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM46, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM47, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM48, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM49, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM50, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM51, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM52, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM53, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM54, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM55, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM56, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM57, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM58, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM59, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM60, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM61, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM62, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM63, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM64, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM65, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM66, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM67, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM68, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM69, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM70, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM71, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM72, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM73, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM74, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM75, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM76, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM77, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM78, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM79, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM80, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM81, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM82, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM83, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM84, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM85, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM86, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM87, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM88, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM89, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM90, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM91, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM92, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM93, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM94, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM95, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM96, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM97, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM98, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM99, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM100, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM101, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM102, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM103, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM104, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM105, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM106, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM107, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM108, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM109, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM110, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM111, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM112, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM113, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM114, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM115, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM116, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM117, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM118, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM119, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM120, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM121, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM122, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM123, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM124, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM125, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM126, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM127, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM128, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM129, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM130, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM131, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM132, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM133, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM134, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM135, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM136, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM137, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM138, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM139, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM140, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM141, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM142, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM143, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM144, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM145, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM146, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM147, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM148, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM149, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM150, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM151, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM152, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM153, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM154, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM155, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM156, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM157, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM158, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM159, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM160, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eSETTINGS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSETTINGS_OPTION, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eSETTINGS_LINE, 0x7B67, 154, 2, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX1, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX2, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX3, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX4, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX5, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX6, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX7, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX8, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX9, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX10, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX11, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX12, 0x7BAE, 15, 15, -1, -1);


#if(BOTOES_FUNCOES)
	this->BindObject(EXBEXO_AUTORESET_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_QUESTCLASS_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_OFFATTACK_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_UYTHAC_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_TAYDIEM_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_TAYDIEMMASTER_INTERFACE, 0x313A, 78, 22, -1, -1);
#endif
	




	//this->BindObject(eMenuBackground, 0x7912, 300, 25, -1, -1);
	//this->BindObject(eARROW_LEFT, 0x7913, 20, 19, -1, -1);
	//this->BindObject(eARROW_RIGHT, 0x7914, 20, 19, -1, -1);

	//this->BindObject(eCameraStart, 0x7915, 19, 19, -1, -1);
	//this->BindObject(eCameraRestore, 0x7916, 19, 19, -1, -1);

	//this->BindObject(eUserPanelButton, 0x7917, 102, 29, -1, -1);

		///emoji
	if (gProtect.m_MainInfo.Emoji != 0)
	{
		myheart::MUEmoji::Init(TEXTURE_EMOJI_LIST_ARROW, TEXTURE_EMOJI_LIST_ON, TEXTURE_EMOJI_LIST_BTN, 20, 14, 4, 0);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST1, 361);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST2, 309);
		myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST3, 118);
	}
	
#if(FACEBOOK)
	
	
		this->BindObject(eNAPTHE, 31461, 35, 14, -1, -1);  // 31461
		this->BindObject(eFACEBOOK, 31461, 35, 14, -1, -1);  // 31461
		//this->BindObject(eFANPAGE, 31461, 35, 14, -1, -1);  // 31461
		//this->BindObject(eGOUP, 31461, 35, 14, -1, -1);  // 31461
	
#endif

	//
	this->BindObject(eLuckySpinRoll, 0x788E, 52, 22, -1, -1);
	this->BindObject(eLuckySpinClose, 0x7EC5, 36, 29, -1, -1);
	//

	this->BindObject(eJewelBank_MAIN, 0x7A5A, 222, 240, -1, -1);
	this->BindObject(eJewelBank_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eJewelBank_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eJewelBank_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eJewelBank_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eJewelBank_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eJewelBank_NEXT, 0x7903, 25, 40, -1, -1);
	this->BindObject(eJewelBank_PREV, 0x7904, 25, 40, -1, -1);

	this->BindObject(eCONFIRM_MUUNBTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_MUUNBTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eCHAR_POINT, 32506, 4, 4, -1, -1); //Char Other
	this->BindObject(eOTHERCHAR_POINT, 32507, 4, 4, -1, -1); //Monter

	for (int i = 0; i < 50; i++)
	{
		this->BindObject(eJewelBank_WITHDRAW + i, 31743, 16, 32, -1, -1);
	}

	this->BindObject(eUSERPANEL_MAIN, 0x7A5A, 190, 428, -1, -1);
	this->BindObject(eUSERPANEL_TITLE, 0x7A79, 190, 64, -1, -1);
	this->BindObject(eUSERPANEL_LEFT, 0x7A7B, 21, 320, -1, -1);
	this->BindObject(eUSERPANEL_RIGHT, 0x7A7C, 21, 320, -1, -1);
	this->BindObject(eUSERPANEL_FOOTER, 0x7A7D, 190, 45, -1, -1);
	this->BindObject(eUSERPANEL_DIV, 0x7A62, 183, 21, -1, -1);
	this->BindObject(eUSERPANEL_CLOSE, 0x7EC5, 36, 29, -1, -1);

	#if WINDOWS_QUEST
	gWinQuestSystem.BindImages();
#endif

#if (SELECTCHARACTER==1)
	SetCompleteHook(0xFF, 0x004D5EE6, &gSelectChar.SelectChar);
	gSelectChar.m_CharacterPage = 1;
#endif
	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);
	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}

	gNewInterface.Load();
	g_PersonalShopEx.BindImages();
	gAchievements.BindImages();
	
	gSmithy.BindImg();

	g_BufferSystem.BindImages();

#if(CUSTOM_MAP_TELEPORT)
	g_MapTeleport.BindTeleportEx();
#endif
#if(CUSTOM_EX_TELEPORT_EVO==TRUE)
	g_ExTeleportEvo.BindImages();
#endif
#if(CUSTOM_PKCLEAR_NPC==TRUE)
	g_PKClear.BindImages();
#endif

#if(DEV_PLAYERSHOP)
	g_ItemMarket.Bind();
#endif

#if(ENABLE_MONSTER_QUEST)
	gMonsterQuest.InterfaceLoad();
#endif
}


void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Ruud, MoneyBuff2, 0);
	//pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	//gInterface.DrawFormat(eWhite180, v11 + 18, v10 + 367, 20, 1, "Z");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	//gInterface.DrawFormat(eWhite180, v11 + 102, v10 + 367, 20, 1, "R");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	//gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	//gInterface.DrawFormat(eBlack, v11 + 17, v10 + 380, 20, 1, "WC");
	//gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney3, v11 + 102, v10 + 378);
	//gInterface.DrawFormat(eBlack, v11 + 98, v10 + 380, 20, 1, "C");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();

#if SKIN
	pLoadModel(910 + 644, "Data\\Custom\\Skin\\Skin\\", "bann", -1);
	pLoadTexture(910 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(911 + 644, "Data\\Custom\\Skin\\Skin\\", "kakashi", -1);
	pLoadTexture(911 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(912 + 644, "Data\\Custom\\Skin\\Skin\\", "FreddyKrueger", -1);
	pLoadTexture(912 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(913 + 644, "Data\\Custom\\Skin\\Skin\\", "monster110", -1);
	pLoadTexture(913 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(914 + 644, "Data\\Custom\\Skin\\Skin\\", "sasuke", -1);
	pLoadTexture(914 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(915 + 644, "Data\\Custom\\Skin\\Skin\\", "SkinGoku", -1);
	pLoadTexture(915 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(916 + 644, "Data\\Custom\\Skin\\Skin\\", "Teste", -1);
	pLoadTexture(916 + 644, "Custom\\Skin\\Skin\\", 10497, 9728, 1);

	pLoadModel(917 + 644, "Data\\Custom\\Skin\\Skin2\\", "Boss", -1);
	pLoadTexture(917 + 644, "Custom\\Skin\\Skin2\\", 10497, 9728, 1);

	pLoadModel(918 + 644, "Data\\Custom\\Skin\\Skin2\\", "Boss106", -1);
	pLoadTexture(918 + 644, "Custom\\Skin\\Skin2\\", 10497, 9728, 1);

	pLoadModel(919 + 644, "Data\\Custom\\Skin\\Skin2\\", "Ichigo", -1);
	pLoadTexture(919 + 644, "Custom\\Skin\\Skin2\\", 10497, 9728, 1);

	pLoadModel(920 + 644, "Data\\Custom\\Skin\\Skin2\\", "yasou", -1);
	pLoadTexture(920 + 644, "Custom\\Skin\\Skin2\\", 10497, 9728, 1);

	pLoadModel(921 + 644, "Data\\Custom\\Skin\\Skin2\\", "LeeSin", -1);
	pLoadTexture(921 + 644, "Custom\\Skin\\Skin2\\", 10497, 9728, 1);

	//Add LuisGaming New Skin

	pLoadModel(922 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add922", -1);
	pLoadTexture(922 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(923 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add923", -1);
	pLoadTexture(923 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(924 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add924", -1);
	pLoadTexture(924 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(925 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add925", -1);
	pLoadTexture(925 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(926 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add926", -1);
	pLoadTexture(926 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(927 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add927", -1);
	pLoadTexture(927 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(928 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add928", -1);
	pLoadTexture(928 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(929 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add929", -1);
	pLoadTexture(929 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(930 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add930", -1);
	pLoadTexture(930 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(931 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add931", -1);
	pLoadTexture(931 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(932 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add932", -1);
	pLoadTexture(932 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(933 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add932", -1);
	pLoadTexture(933 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(934 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add933", -1);
	pLoadTexture(934 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(935 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add934", -1);
	pLoadTexture(935 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(936 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add935", -1);
	pLoadTexture(936 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(937 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add936", -1);
	pLoadTexture(937 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(938 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add937", -1);
	pLoadTexture(938 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(939 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add938", -1);
	pLoadTexture(939 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(940 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add939", -1);
	pLoadTexture(940 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(941 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add940", -1);
	pLoadTexture(941 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	pLoadModel(941 + 644, "Data\\Custom\\Skin\\SkinAdd\\", "Add941", -1);
	pLoadTexture(941 + 644, "Custom\\Skin\\SkinAdd\\", 10497, 9728, 1);

	// add in here skin  :::: 910 => 941 , name file bmd
#endif
}

void Interface::LoadImages()
{
	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x8909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x8910, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money3.tga", 0x8911, 0x2601, 0x2901, 1, 0);
	}

	//pLoadImage("Custom\\Interface97\\Layout.tga", 51523, 0x2601, 0x2901, 1, 0);
	//
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

#if(FACEBOOK)
	LoadBitmapA("Custom\\Interface\\Nut.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Nut_80_25.tga", 0x313A, 0x2601, 0x2900, 1, 0); // NÚT BUTTON
	pLoadImage("Custom\\Interface\\Khung.tga", 0x9331, 0x2601, 0x2900, 1, 0); // NÚT BUTTON
#endif


	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900, 1, 0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	pLoadImage("Custom\\Maps\\edBtUcxv2.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\time700.tga", 32458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	if(gProtect.m_MainInfo.CustomInterfaceType == 0||gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	if (gProtect.m_MainInfo.CustomMenuType == 2){
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}
	pLoadImage("Custom\\Interface\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);
	}

	if (gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);


#if(LOGIN_REGISTER==1)
	pLoadImage("Custom\\Desig\\eventbar.tga", 91990, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\eventbar2.tga", 91991, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\bg460.tga", 631177, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\khung1.tga", 500001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Desig\\Rong1.tga", 500004, 0x2601, 0x2900, 1, 0);
	LoadBitmapA("Custom\\Desig\\BXH.tga", 531116, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\Muun4.tga", 11111, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\1000.tga", 0x9960, 0x2601, 0x2900, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);


	

	LoadBitmapA("Custom\\Desig\\Login.tga", 71621, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\1.tga", 71622, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\2.tga", 71623, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\3.tga", 71624, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\4.tga", 71625, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\5.tga", 71626, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\6.tga", 71627, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\8.tga", 71629, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\9.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\10.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_back.tga", 71631, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\reloadcap.jpg", 71632, GL_LINEAR, GL_CLAMP, 1, 0);
#endif

	//pLoadImage("Custom\\Interface\\itembackpanel.tga", ex_SMITHY_ITEM, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\Interface\\newui_cha_textbox03.tga", ex_TEXT_BOX3, 0x2601, 0x2900, 1, 0);


#if(CHARACTER_INFO==1)
	////abcd
	LoadBitmapA("Custom\\Event\\NhanVat\\1.tga", 531008, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DK1.tga", 531009, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DW1.tga", 531010, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\ELF1.tga", 531011, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\MG1.tga", 531012, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DL1.tga", 531013, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\SM1.tga", 531014, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\RF1.tga", 531015, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\GL1.tga", 531015, GL_LINEAR, GL_CLAMP, 1, 0);
	/////
#endif
	


	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	//
	switch (gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
			
			//--
		}

		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Custom\\InterfaceS2\\MacroUI_Menu.tga", 120111, GL_LINEAR, GL_CLAMP, 1, 0);
		
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
	LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Folder MacroUI
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		if (gProtect.m_MainInfo.CustomMenuType == 1)
	    {
		pLoadImage("Custom\\Interface\\Menu3.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	    }	
		if (gProtect.m_MainInfo.CustomMenuType == 2)
	    {
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 120111, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		pLoadImage("Interface\\GFx\\MacroUI\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);//nueva
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 30847, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.DisableEffectRemake == 0)
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 0x7898, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Info_Block.tga", 0x7899, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Title.tga", 0x9306, GL_LINEAR, GL_REPEAT, 1, 0);
	//pLoadImage("Custom\\Interface\\Title.tga", 30847, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\newui_cha_textbox01.tga", 0x9307, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\ui-dialog1_hr.tga", iNewuiDialogHr, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\ui_dialog_e.tga", iGfxDialoge, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\ui_dialog_be.tga", iGfxDialoge2, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Newui_dialog_btn_small2.tga", iGfxBtnSmall2, GL_LINEAR, GL_REPEAT, 1, 0);
	//LoadBitmapA("Custom\\Interface\\MacroUI_Menu.tga", 120111, GL_LINEAR, GL_CLAMP, 1, 0);

	pLoadImage("Custom\\Interface\\pm_flag.tga", 0x789A, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Logo\\Mu-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Logo\\Mu-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);

	if (gProtect.m_MainInfo.CustomSelectServerX700 == 3)
	{
		pLoadImage("Logo\\sos3sky01.jpg", 531013, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\sos3sky02.jpg", 531014, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\New_Login_Back01.jpg", 531011, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\New_Login_Back02.jpg", 531012, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
		LoadBitmapA("World78\\bg_b_08.jpg", 532029, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("World78\\bg_b_05.jpg", 532028, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 2)
	{
		pLoadImage("Logo\\Login_Back01.jpg", 500021, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\Login_Back02.jpg", 500022, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	//pLoadImage("Custom\\Interface\\menubg.tga", 0x7912, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\arrowleft.tga", 0x7913, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\arrowright.tga", 0x7914, GL_LINEAR, GL_CLAMP, 1, 0);

	//LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_CameraStart.tga", 0x7915, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_CameraRestore.tga", 0x7916, GL_LINEAR, GL_CLAMP, 1, 0);

	//LoadBitmapA("Custom\\Interface\\UserPanelButton.tga", 0x7917, GL_LINEAR, GL_CLAMP, 1, 0);

	//LoadBitmapA("Custom\\Interface\\button_ui_cancel.tga", 71555, GL_LINEAR, GL_CLAMP, 1, 0);

	pLoadImage("Custom\\Interface\\itembackpanel.tga", 0x9327, GL_LINEAR, GL_CLAMP, 1, 0);


	pLoadImage("Custom\\Interface\\TimeLeoThap.tga", 81538, 0x2601, 0x2900, 1, 0); //leothap

	pLoadImage("Custom\\Interface\\top.tga", 31400, 0x2601, 0x2900, 1, 0); //Painel News


	if (gProtect.m_MainInfo.MultiCharacterEnable == 1)
	{
#if (SELECTCHARACTER==1)
	pLoadImage("Custom\\Interface\\Next.tga", 32342, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 32343, 0x2601, 0x2901, 1, 0);
#endif
}
	//LoadBitmapA("Custom\\Interface\\newui_btn_npc.tga", 541018, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Custom\\Maps\\map_radar.tga", 61519, 0x2601, 0x2901, 1, 0); 

	pLoadImage("Interface\\GFx\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Interface\\GFx\\Party\\newui_bar.tga", 81528, GL_LINEAR, GL_CLAMP, 1, 0);
	//--
	pLoadImage("Interface\\GFx\\Party\\PartyBar.tga", 81525, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\newui_Party_Manabar02.jpg", 81526, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\Party\\PartyPlayerInfo.tga", 81527, 0x2601, 0x2901, 1, 0);
	//--
		//////////emoji
	if (gProtect.m_MainInfo.Emoji != 0)
	{
		pLoadImage("Interface\\GFx\\emojis_f.tga", TEXTURE_EMOJI_LIST1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emojis_f2.tga", TEXTURE_EMOJI_LIST2, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emojis_f3.tga", TEXTURE_EMOJI_LIST3, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\emoji_list_btn.tga", TEXTURE_EMOJI_LIST_BTN, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\newui_chat_emoji_on.jpg", TEXTURE_EMOJI_LIST_ON, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\btn_arrow.tga", TEXTURE_EMOJI_LIST_ARROW, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\GFx\\newui_chat_back.jpg", 31279, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//--

	//-> News System
	pLoadImage("Custom\\Noticias.jpg", 0x9969, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\NewTable.tga", 0x9970, GL_LINEAR, GL_CLAMP, 1, 0);





	pDrawMessage(Notice_1, 0);
	pDrawMessage(Notice_2, 1);
	pDrawMessage(Notice_3, 2);
	pDrawMessage(Notice_4, 3);
	pDrawMessage(Notice_5, 4);
	pDrawMessage(Notice_6, 5);
	pDrawMessage(Notice_7, 6);

	//=== CTC Mini UI ==//
	pLoadImage("Custom\\CTCMini\\UiCtc.tga", 32584, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CTCMiniMap.tga", 32583, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\StartCTC.tga", 32585, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\WinCTC.tga", 32586, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\LoseCTC.tga", 32589, 9729, 10496, 1, 0); //Trung voi ID effect 32587
	pLoadImage("Custom\\CTCMini\\DialogCTC.tga", 32588, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CharPoint.tga", 32506, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\OtherCharPoint.tga", 32507, 9729, 10496, 1, 0);

	LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); // Ruud Classic Interface

	pLoadImage("Custom\\HPPanel.tga", 90014, 0x2601, 0x2901, 1, 0); // coppy 
	//gCloak.LoadTexture();
	#if WINDOWS_QUEST
	gWinQuestSystem.ImageLoad();
#endif

	if (gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	gAchievements.LoadImages();
	
	gRanking.ImageLoad();
	gSmithy.LoadImg();
#if(CUSTOM_MAP_TELEPORT)
	g_MapTeleport.LoadTeleportEx();
#endif
#if(CUSTOM_EX_TELEPORT_EVO==TRUE)
	g_ExTeleportEvo.LoadImages();
#endif
	//--
	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick = 0;
	this->Data[MonsterID].OnClick = false;
	this->Data[MonsterID].OnShow = false;
	this->Data[MonsterID].ModelID = ModelID;
	this->Data[MonsterID].Width = Width;
	this->Data[MonsterID].Height = Height;
	this->Data[MonsterID].X = X;
	this->Data[MonsterID].Y = Y;
	this->Data[MonsterID].MaxX = X + Width;
	this->Data[MonsterID].MaxY = Y + Height;
	this->Data[MonsterID].Attribute = 0;
}

void Interface::DrawGU1(short ObjectID, float PosX, float PosY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}



void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, ScaleX, ScaleY, 1, 1, 0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, ScaleX, ScaleY, 1, 1, 0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if (this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1)
	{
		this->Data[ObjectID].X = -1;
		this->Data[ObjectID].Y = -1;
		this->Data[ObjectID].MaxX = -1;
		this->Data[ObjectID].MaxY = -1;
	}
}



void Interface::ResetDrawIMG2(short ObjectID)
{
	if (this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1)
	{
		this->Data[ObjectID].X = -1;
		this->Data[ObjectID].Y = -1;
		this->Data[ObjectID].MaxX = -1;
		this->Data[ObjectID].MaxY = -1;
	}
}

////////////JANELA ANUNCIO /////////////////
bool Janela = true;
void funcaoclairton()
{
	if (!pCheckWindow(pWindowThis(),ChatWindow) && pIsKeyRelease('N'))
	{
		if (Janela == false)
		{
			Janela = true;
		}
		else
		{
			Janela = false;
		}
	}

	//100 ~ 110

	if (Janela == true)
	{
		//Janela
		pDrawGUI(31400, 220, 100, 222, 260);
		//RenderBitmap(531019, 220, 100, 222, 240 ,0 ,0);
		//RenderBitmap(31400, 230, 90, 350, 290, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

		//char* Texts[] = {"Oi", "Ola", "Hi", "Arigato",  "XingLing",  "BugaBuga",  "Texto",  "Dece",  "entro",  "Big"};

		for (int i = 0; i < 10; i++)
		{
			pSetBlend(1);
			gInterface.DrawFormat(eGold, 218, 170 + (i * 13), 222, 3, gCustomMessage.GetMessage(169 + i));

		}

		for (int i = 0; i < 1; i++)
		{
			pSetBlend(1);
			gInterface.DrawFormat(eGray100, 218, 150 + (i * 13), 222, 3, gCustomMessage.GetMessage(179));

			}



		



		//Botão fechar cinza
		glColor4f(0.50, 0.50, 0.50, 1.0);
		pDrawBarForm(304, 300, 50, 20, 0, 0);
		glColor4f(1.0, 1.0, 1.0, 1.0);

		//Texto fechar no botão
		pSetBlend(1);
		gInterface.DrawFormat(eGold, 304, 305, 50, 3, "Fechar");

		//Mouse soubre fechar + click = fechar janela
		if (pCheckMouseOver(309, 280, 50, 30) && pIsKeyRelease(VK_LBUTTON))
		{
			Janela = false;
		}

		//Mouse sobre janela nao anda
		if (pCheckMouseOver(100, 100, 222, 240))
		{
			pMyFocus = true;
		}
		else
		{
			pMyFocus = false;
		}
		pSetBlend(0);
	}
}




void Interface::Work()
{
	if (gProtect.m_MainInfo.EnablenoticiasInGame == 1)
	{
		funcaoclairton();

	}
	
#if(FACEBOOK)
	gInterface.DarwinNapThe();

	gInterface.DarwinFacebook();

	//gInterface.DrawFanpage();

	//gInterface.DrawGoup();
#endif
	   


#if(SWITCH_SERVER==1)

	gInterface.SetCursorFocus();



#endif
	gObjUser.Refresh();

#if(MAINBETELL==1)

	if (gProtect.m_MainInfo.EnableMainWindowbetell == 1)
	{
		gInterface.MainWindowbetell();  //->Main Descrição Betell

	}

#endif


	gInterface.RightMiniInfoY = 430;

	jCRenderRuud.CheckOpen();

	if (gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4, 255)
		|| gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4, 255))
	{
		gInterface.PetY = 38.0f;

	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if (gObjUser.lpViewPlayer->PetSlot != -1)
	{
		gInterface.PetX = 61.0f;
	}
	else
	{
		gInterface.PetX = 0;
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}





	gInterface.DrawMiniMap();

	gRenderMap.AutoSendMove();

	gInterface.DrawTimeUI();

	gCustomRanking.DrawRankPanelWindow();

	gCustomEventTime.DrawEventTimePanelWindow();

	

	ReconnectMainProc();

	gInterface.DrawVipWindow();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

	gInterface.DrawPartySettingsWindow();
	gInterface.DrawPartySearchWindow();

	gInterface.DrawStatsAddWindow();
	gInterface.DrawResetStatsWindow();

	gAchievements.Draw();
	

	gTuChanInterface.DrawTuChanWindow();

	gInterface.DrawEventTableWindow();

	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();

	G_BEXO_MUA_VIP.DRAW_MUA_VIP();



#if(LEOTHAP == 1)
	// Leo thap
	gLeoThap.DrawLeoThap();
	gLeoThap.LeoThapCountdown();
	gLeoThap.LeoThapDelayTime();
#endif
	#if WINDOWS_QUEST
	gWinQuestSystem.Draw();
	gWinQuestSystem.DrawOpenWQ();
#endif

	gRanking.Draw();

	gInterface.DrawFruit();

	g_PersonalShopEx.Draw();

	gNewInterface.Work();

	gInterface.DrawChangingClassWindow();

	gInterface.DrawResetWindow();

	gUserPanel.DrawUserPanelV2();

	gInterface.DrawWarehouseWindow();

	gInterface.DrawSettingsUI();

	
#if(BOTOES_FUNCOES)
	gInterface.DRAW_TINHNANG_INTERFACE();
#endif


	if (gTuChanInterface.CheckTuChanWindow())
	{
		gTuChanInterface.CloseTuChanWindow();
	}

	gTuChanInterface.loadBind();

	gInterface.WindowsKG();
#if(SLIDE == 1)
	gInterface.DrawTextTTTTTT();
#endif


	//gUserPanel.DrawUserPanelButton();

//	gInterface.DrawCameraUI();
	#if (CAMARA==0)
	gCamera.Init();
#endif

	gSmithy.Draw();

	g_BufferSystem.Draw();

#if(CUSTOM_MAP_TELEPORT)
	g_MapTeleport.DrawTeleportEx();
#endif

#if(CUSTOM_EX_TELEPORT_EVO==TRUE)
	g_ExTeleportEvo.Draw();
#endif
#if(CUSTOM_PKCLEAR_NPC==TRUE)
	g_PKClear.Draw();
#endif


	gLuckySpin.Draw();

	gInterface.DrawGrandResetWindow();

	gCustomJewelBank.DrawJewelBankWindow();

	gInterface.DrawCTCMiNiMap(); //LOad de draw
	gInterface.DrawCTCMiniWindow();//LOad de draw
	gInterface.DrawChienTruongCo();
	gInterface.DrawTimeCTC();

	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	RentSkin.Draw();

	pDrawInterface();


	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{

		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}



	}
	g_StatsAdvance.DrawInfo();
	//gCRuudShop.RuudShop();



#if(DEV_PLAYERSHOP)
	g_ItemMarket.DrawMain();
#endif

#if(ENABLE_MONSTER_QUEST)
	gMonsterQuest.DrawMainTable();
#endif

	gInterface.DrawLogo(0);
}

void Interface::WindowsKG() {
	char interaltas[500];
	if (gInterface.validar == 0)
	{
		if (gInterface.ultimo_Ping > 0) {
			sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name);
		}
		else {
			sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name);
		}
		SetWindowText(pGameWindow, interaltas);
	}
}





void Interface::SwitchMiniMap()
{
	if ((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics", "MiniMap", "0", "./Settings.ini");
	}
	else
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics", "MiniMap", "1", "./Settings.ini");
	}
}




void Interface::DrawTimeUI()
{
	if (!TimerBar)
	{
		return;
	}

	if (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}
	if (gProtect.m_MainInfo.ServerLocal == 1)
	{

		time_t TimeServer, TimeLocal;
		struct tm* ServerT, * LocalT;
		time(&TimeServer);
		time(&TimeLocal);
		// ----
		ServerT = gmtime(&TimeServer);
		char ServerTimeName[25] = "Server:";
		char ServerTime[30];
		sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT) % 24, ServerT->tm_min, ServerT->tm_sec);

		LocalT = localtime(&TimeLocal);
		char LocalTimeName[25] = "Local:";
		char LocalTimeName1[25] = "MuOnline";
		//char LocalTimeName2[25] = "Emulator 2022";
		char LocalTime[30];
		sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);

		this->DrawGUI(eTIME, -7, 360);
		this->DrawFormat(eGold, 5, 392, 0, 1, ServerTimeName);
		this->DrawFormat(eWhite, 45, 392, 50, 1, ServerTime);
		this->DrawGUI(eTIME, -7, 380);
		this->DrawFormat(eGold, 5, 412, 0, 1, LocalTimeName);
		this->DrawFormat(eWhite, 45, 412, 50, 1, LocalTime);
		this->DrawFormat(eGold, 20, 435, 50, 1, LocalTimeName1);

	
	}
}



int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char* Line = strtok(Buff, "\n");

	while (Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}

	return PosY;
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if ((pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY))
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if (pWinWidth == 800)
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if (pWinWidth != 1024)
	{
		return this->Data[ObjectID].X - 16.0;
	}

	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}



void Interface::DrawVipWindow()
{

	if (!this->Data[eVip_MAIN].OnShow)
	{
		return;
	}

	if (gProtect.m_MainInfo.EnableVipShop != 1)
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
			&& this->CheckWindow(ExpandInventory)
			&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
			&& this->CheckWindow(Warehouse)
			&& this->CheckWindow(ExpandWarehouse)))
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth = 230.0;
	float MainHeight = 180.0;
	float StartBody = 50.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	this->DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)15.0, 16);
	this->DrawGUI(eVip_FOOTER, StartX, StartY);
	this->DrawGUI(eVip_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eVip_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVip_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eVip_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eVip_CLOSE].X + 5, StartBody + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	// ----
	this->DrawGUI(eVip_DIV, StartX, StartBody + 70);
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for (int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++)
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
		// ---- bronze start 
		if (IsWorkZone(eVip_BRONZE))
		{
			if (this->Data[eVip_BRONZE].OnClick)
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 58);
			else
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
		}
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 0);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 90, 220 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
		// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
		// ---- Silver start ------------------------------------
		if (IsWorkZone(eVip_SILVER))
		{
			if (this->Data[eVip_SILVER].OnClick)
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 58);
			else
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
		}
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 250 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
		// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
		// ---- gold start ------------------------------------
		if (IsWorkZone(eVip_GOLD))
		{
			if (this->Data[eVip_GOLD].OnClick)
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 58);
			else
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
		}
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 280 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
		// ---- gold end ------------------------------------
	}
}


bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y, float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY, ScaleX, ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = X;
		this->Data[ObjectID].Y = Y;
		this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount() + 1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH / 2) - (150 / 2), (MAX_WIN_HEIGHT / 2) - (114 / 2));
			}
			//g_ExWinQuestSystem.SwitchStatsWindowState();
			this->CloseMenuWindowTwo();

			return;
		}
	}
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if (gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(8)
		|| gInterface.CheckWindow(12)
		|| gInterface.CheckWindow(9)
		|| gInterface.CheckWindow(7)
		|| gInterface.CheckWindow(14)
		|| gInterface.CheckWindow(15)
		|| gInterface.CheckWindow(60)
		|| gInterface.CheckWindow(76))
	{
		visual = true;
	}
	else
	{
		if (gInterface.CheckWindow(16) && (gInterface.CheckWindow(4) || gInterface.CheckWindow(69)))
		{
			visual = true;
		}
		else
		{
			if (gInterface.CheckWindow(16) && gInterface.CheckWindow(11))
			{
				visual = true;
			}
			else
			{
				if (gInterface.CheckWindow(27))
				{
					visual = true;
				}
				else
				{
					if (gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74))
					{
						visual = true;
					}
					else
					{
						if (gInterface.CheckWindow(79))
						{
							if (gInterface.CheckWindow(80))
							{
								visual = true;
							}
							else
							{
								visual = true;
							}
						}
					}
				}
			}
		}
	}

	if (gInterface.CheckWindow(77))
	{
		if (gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if (gInterface.CheckWindow(78))
	{
		visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
			&& this->CheckWindow(Warehouse)
			&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
			&& this->CheckWindow(Character)
			&& this->CheckWindow(Store)))
		return true;
	return false;
}
/*
bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}*/

void Interface::CloseCustomWindow()
{
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow = false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
			&& this->CheckWindow(ExpandInventory)
			&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
			&& this->CheckWindow(Warehouse)
			&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posiçăo do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funăo que mostra o BMD

	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if (!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if (!this->Data[eCONFIRM_MAIN].OnShow)
	{
		return;
	}

	float StartX;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody = 90.0;
	float StartY = 90.0;

	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, 0);

	if (this->IsWorkZone(eCONFIRM_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eCONFIRM_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, 0);

	if (this->IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eCONFIRM_BTN_CANCEL].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED, sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg, pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::UPDATE_FPS() {
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL); // Movimento FPS
}

void Interface::guiMonitore() {
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(450.0, 0.0, 180.0, 15.0, 0.0f, 0);  //barra do ping e FPS
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if (gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0x77, sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing, sizeof(pMsgPing));
		gInterface.iniciador = 2;
	}
	else if (gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000) {
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0x77, sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing, sizeof(pMsgPing));
			gInterface.iniciador = 2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing / 2));
	// ----
	gInterface.validar = 0;

	if (gInterface.msPing > 0) {
		//----
		this->DrawFormat(eGold, 500, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 550, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar = 1;
	}

	if (gInterface.validar == 0)
	{
		if (gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 330, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 270, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 330, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if ((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting", "SeparateChat", "0", "./Settings.ini");
	}
	else
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting", "SeparateChat", "1", "./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if (type == 0)
	{
		if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400
			|| this->CheckWindow(ChatWindow)
			|| this->CheckWindow(MuHelper)
			|| this->CheckWindow(Inventory)
			|| this->CheckWindow(Store)
			|| this->CheckWindow(Character)
			|| this->CheckWindow(CreateGuild))
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if (type == 1)
	{
		if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
#if(CAMARA==0)
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if ((GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000)
	{
		return;
	}

	if (pMapNumber == 62)
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Reset();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Switch();

	if (gCamera.IsActive)
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit() {

	if ((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.IsActive)
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Reset();
	}
}
#else
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Restore();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Toggle();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}
}
#endif

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}

bool Interface::EventoDrewNapThe_Open(DWORD Event)
{
	return false;
}

bool Interface::EventoDarwinFacebook_Open(DWORD Event)
{
	return false;
}

bool Interface::IsWorkZone4(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event) {
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}

	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
			this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}

	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event) {
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}

	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}

	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{
	if (this->MiniMapCheck() || (this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		|| this->CheckWindow(FastMenu) || this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char* Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}


void Interface::DrawStatsAddWindow()
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}
	char szCharNames[5][32];
	memcpy(szCharNames[0], gCustomMessage.GetMessage(142), sizeof(szCharNames[0]));
	memcpy(szCharNames[1], gCustomMessage.GetMessage(143), sizeof(szCharNames[1]));
	memcpy(szCharNames[2], gCustomMessage.GetMessage(144), sizeof(szCharNames[2]));
	memcpy(szCharNames[3], gCustomMessage.GetMessage(145), sizeof(szCharNames[3]));
	memcpy(szCharNames[4], gCustomMessage.GetMessage(146), sizeof(szCharNames[4]));
	/*
	char szCharNames[5][32] =
	{
	"Strength:",
	"Agility:",
	"Vitality:",
	"Energy:",
	"Command:",
	};
	*/
	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	if (this->Data[eSTATSADD_MAIN].ByClose == false)
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue < 0)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue += this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue >= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 15;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue > 0)
			{
				this->Data[eSTATSADD_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue > -226)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue -= this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 20;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -226)
			{
				//this->Data[eSTATSADD_MAIN].OpenedValue = 100;
				this->Data[eSTATSADD_MAIN].Close();
				/*
				this->Data[eSTATSADD_STEP10].Attribute = 0;
				this->Data[eSTATSADD_STEP100].Attribute = 0;
				this->Data[eSTATSADD_STEP1000].Attribute = 0;
				*/
				for (int i = 0; i < ObjectCount; i++)
				{
					this->Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}

	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = this->Data[eSTATSADD_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawAnimatedGUI(eSTATSADD_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eSTATSADD_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSTATSADD_FRAME, StartX, StartY + 67.0, 8);
	this->DrawAnimatedGUI(eSTATSADD_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eSTATSADD_CLOSE, StartX + MainWidth - this->Data[eSTATSADD_CLOSE].Width, this->Data[eSTATSADD_MAIN].Y - 2);
	// ----

	// ----
	if (this->IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSTATSADD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSTATSADD_CLOSE, this->Data[eSTATSADD_CLOSE].X, this->Data[eSTATSADD_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSTATSADD_CLOSE].X + 5, this->Data[eSTATSADD_CLOSE].Y + 25, gCustomMessage.GetMessage(14));
	}
	// ----
	DWORD StatPoints = ViewPoint;

	for (int i = 0; i < ObjectCount; i++)
	{
		StatPoints -= atoi(this->Data[ObjectIDs[i]].StatValue);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 8, 210, 3, gCustomMessage.GetMessage(127));

	this->DrawAnimatedGUI(eSTATSADD_TEXTBOX01, ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 28);
	this->DrawFormat(eWhite, StartX - 40, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, gCustomMessage.GetMessage(128));

	char Value[50];
	ZeroMemory(Value, sizeof(Value));
	pGetMoneyFormat((double)StatPoints, Value, 0);
	GetFormat(Value, ',', ' ');

	////console.Log("", "Point %d Value %s",StatPoints,Value);

	this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "%s", Value);

	this->DrawFormat(eWhite, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 55, 210, 3, gCustomMessage.GetMessage(129));
	/*
	this->DrawFormat(eWhite, StartX + 30, this->Data[eSTATSADD_MAIN].Y + 69, 30, 3, "Step value:");

	this->DrawFormat(eWhite, StartX + 80, this->Data[eSTATSADD_MAIN].Y + 70, 10, 3, "10");
	this->DrawFormat(eWhite, StartX + 120, this->Data[eSTATSADD_MAIN].Y + 70, 15, 3, "100");
	this->DrawFormat(eWhite, StartX + 162, this->Data[eSTATSADD_MAIN].Y + 70, 20, 3, "1000");

	if (this->Data[eSTATSADD_STEP10].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP100].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP1000].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}*/

	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
		{
			sprintf(this->Data[ObjectIDs[i]].StatValue, "0");
		}
		this->DrawAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21));
		this->DrawFormat(eWhite, StartX - 38, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, szCharNames[i]);
		this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, this->Data[ObjectIDs[i]].StatValue);
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (this->Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			this->DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21), Color);
		}
	}

	this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, 0);

	if (this->IsWorkZone(eSTATSADD_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eSTATSADD_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, ScaleY);
	}

	//login_me
	//newui_button_cancel
	//newui_button_ok
	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------

void Interface::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}

void Interface::EventStatsAddWindow_Close(DWORD Event)
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j < ObjectCount; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 5; i < 5; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 5; j < 8; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}


	if (IsWorkZone(eSTATSADD_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_BTN_OK].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
		PMSG_UPDATE_STATS_SEND pMsg;
		pMsg.Str = atoi(this->Data[eSTATSADD_STATBOX01].StatValue);
		pMsg.Agi = atoi(this->Data[eSTATSADD_STATBOX02].StatValue);
		pMsg.Vit = atoi(this->Data[eSTATSADD_STATBOX03].StatValue);
		pMsg.Ene = atoi(this->Data[eSTATSADD_STATBOX04].StatValue);
		pMsg.Com = 0;
		if (ObjectCount == 5)
		{
			pMsg.Com = atoi(this->Data[eSTATSADD_STATBOX05].StatValue);
		}
		CGSendStatsAdd(pMsg);
	}

	if (IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
	}

	// ----
	return;
}

// ----------------------------------------------------------------------------------------------
void Interface::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);
	// ----
	if (!this->CheckWindow(Character))
	{
		return;
	}
	// ----
	if (IsWorkZone(eCHARINFO_BTN_STAT))
	{
		//if (gConfig.GetCustomState(CUSTOM_STATSADD) == 0)
		//{
		//	return;
		//}
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
		this->SwitchStatsWindowState();
		////console.Log("", "AddStat switchstate");
	}

	if (IsWorkZone(eCHARINFO_BTN_RESSTAT))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_RESSTAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_RESSTAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_RESSTAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_RESSTAT].EventTick = GetTickCount();
		this->SwitchResetStatsWindowState();
	}
	//if( !this->CheckWindow(Character) || !IsWorkZone(eCHARINFO_BTN_STAT) )
	//{
	//	return;
	//}
	//// ----
	//if( Event == WM_LBUTTONDOWN )
	//{
	//	this->Data[eCHARINFO_BTN_STAT].OnClick = true;
	//	return;
	//}
	//// ----
	//this->Data[eCHARINFO_BTN_STAT].OnClick = false;
	//// ----
	//if( Delay < 500 )
	//{
	//	return;
	//}
	//// ----
	//this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
	//this->SwitchStatsWindowState();
}

void Interface::DrawResetStatsWindow()
{
	if (!this->Data[eRESETSTATS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);

	pSetCursorFocus = true;
	// ----

	this->DrawGUI(eRESETSTATS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eRESETSTATS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eRESETSTATS_FRAME, StartX, StartY + 67.0, 2);
	this->DrawGUI(eRESETSTATS_FOOTER, StartX, StartY);
	this->DrawGUI(eRESETSTATS_CLOSE, StartX + MainWidth - this->Data[eRESETSTATS_CLOSE].Width, this->Data[eRESETSTATS_TITLE].Height + this->Data[eRESETSTATS_CLOSE].Height + 2);

	// ----
	if (this->IsWorkZone(eRESETSTATS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESETSTATS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESETSTATS_CLOSE, this->Data[eRESETSTATS_CLOSE].X, this->Data[eRESETSTATS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eRESETSTATS_CLOSE].X + 5, this->Data[eRESETSTATS_CLOSE].Y + 25, gCustomMessage.GetMessage(14));
	}
	// ----

	int x = GetPrivateProfileIntA("Custom", "X", -35, "./Settings.ini");
	int y = GetPrivateProfileIntA("Custom", "Y", 60, "./Settings.ini");

	int StatPoints = ViewStrength + ViewDexterity + ViewVitality + ViewEnergy + (ViewLeadership - (gResetSystem.m_BonusCommand * ViewReset) + (gGRSystem.m_BonusCommand * ViewGReset));

	StatPoints -= (gObjUser.d_Strength + gObjUser.d_Dexterity + gObjUser.d_Vitality + gObjUser.d_Energy + gObjUser.d_Leadership);

	/*
	if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
	{
	StatPoints -= gObjUser.m_CustomResetPointPriceZen(ViewAccountLevel);
	if (StatPoints < 0)
	{
	StatPoints = 0;
	}
	}
	*/

	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gCustomMessage.GetMessage(122));
	//Reset Point
	if (this->m_ResetPointCheckBox == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 33); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 34, 100, 1, gCustomMessage.GetMessage(123), gObjUser.GetResetPointPriceWC(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 45, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 45, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 53); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 54, 100, 1, gCustomMessage.GetMessage(124), gObjUser.GetResetPointPriceZen(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 65, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 65, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Master Point Reset
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 73); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 74, 115, 1, gCustomMessage.GetMessage(125), gObjUser.GetResetMasterSkillPriceWC(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 85, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 85, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 93); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 94, 115, 1, gCustomMessage.GetMessage(126), gObjUser.GetResetMasterSkillPriceZen(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 105, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 105, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetPointCheckBox == 1)
	{
		//Reset Point
		if (this->Data[eRESETSTATS_CHECK_WC].Attribute == true)
		{
			this->DrawButton(eRESETSTATS_CHECK_WC, 385, 132, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETSTATS_CHECK_WC, 385, 132, 0, 0);
		}
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
		{
			this->DrawButton(eRESETSTATS_CHECK_STAT, 385, 152, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETSTATS_CHECK_STAT, 385, 152, 0, 0);
		}
	}

	//this->DrawFormat(eYellow, StartX + 50, this->Data[eRESETSTATS_MAIN].Y + 75, 45, 3, "Reward Points:");
	//pDrawGUI(0x7895, StartX + 120, this->Data[eRESETSTATS_MAIN].Y + 71.5, 50, 16);
	//this->DrawFormat(eWhite, StartX + 110, this->Data[eRESETSTATS_MAIN].Y + 75, 50, 3, "%d", StatPoints);
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Master Point Reset
		if (this->Data[eRESETMASTER_CHECK_WC].Attribute == true)
		{
			this->DrawButton(eRESETMASTER_CHECK_WC, 385, 172, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETMASTER_CHECK_WC, 385, 172, 0, 0);
		}
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		if (this->Data[eRESETMASTER_CHECK_STAT].Attribute == true)
		{
			this->DrawButton(eRESETMASTER_CHECK_STAT, 385, 192, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETMASTER_CHECK_STAT, 385, 192, 0, 0);
		}
	}
	this->Data[eRESETSTATS_BTN_OK].Attribute = false;

	if (this->Data[eRESETSTATS_CHECK_WC].Attribute || this->Data[eRESETSTATS_CHECK_STAT].Attribute || this->Data[eRESETMASTER_CHECK_WC].Attribute || this->Data[eRESETMASTER_CHECK_STAT].Attribute)
	{
		this->DrawButton(eRESETSTATS_BTN_OK, StartX + 85, this->Data[eRESETSTATS_MAIN].Y + 108, 0, 0);

		if (this->IsWorkZone(eRESETSTATS_BTN_OK))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eRESETSTATS_BTN_OK].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eRESETSTATS_BTN_OK, StartX + 85, this->Data[eRESETSTATS_MAIN].Y + 108, 0, ScaleY);
		}
		this->Data[eRESETSTATS_BTN_OK].Attribute = true;
	}
}

void Interface::EventResetStatsWindow(DWORD Event)
{
	if (!this->Data[eRESETSTATS_MAIN].OnShow)
	{
		return;
	}

	this->EventResetStatsWindow_Close(Event);

	int eObjectIDs[4] =
	{
		eRESETSTATS_CHECK_WC,
		eRESETSTATS_CHECK_STAT,
		eRESETMASTER_CHECK_WC,
		eRESETMASTER_CHECK_STAT,
	};

	DWORD CurrentTick = GetTickCount();

	for (int i = 0; i < 4; i++)
	{
		DWORD Delay = (CurrentTick - this->Data[eObjectIDs[i]].EventTick);
		// ----
		if (!IsWorkZone(eObjectIDs[i]))
		{
			continue;
		}
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eObjectIDs[i]].OnClick = true;
			break;;
		}
		// ----
		this->Data[eObjectIDs[i]].OnClick = false;
		// ----
		if (Delay < 500)
		{
			break;
		}
		// ----
		this->Data[eObjectIDs[i]].EventTick = GetTickCount();
		if (this->m_ResetPointCheckBox == 1)
		{
			if (eObjectIDs[i] == eRESETSTATS_CHECK_WC)
			{
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 1;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetPointCheckBox1 == 1)
		{
			if (eObjectIDs[i] == eRESETSTATS_CHECK_STAT)
			{
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 1;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetMasterSkillCheckBox == 1)
		{
			//Reset Master Point
			if (eObjectIDs[i] == eRESETMASTER_CHECK_WC)
			{
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 1;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetMasterSkillCheckBox1 == 1)
		{
			if (eObjectIDs[i] == eRESETMASTER_CHECK_STAT)
			{
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 1;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
			}
		}
	}

	DWORD Delay = (CurrentTick - this->Data[eRESETSTATS_BTN_OK].EventTick);
	// ----
	if (!IsWorkZone(eRESETSTATS_BTN_OK) || !this->Data[eRESETSTATS_BTN_OK].Attribute)
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESETSTATS_BTN_OK].OnClick = true;
		return;
	}
	// ----
	this->Data[eRESETSTATS_BTN_OK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eRESETSTATS_BTN_OK].EventTick = GetTickCount();
	if (this->m_ResetPointCheckBox == 1)
	{
		//Reset Point
		if (this->Data[eRESETSTATS_CHECK_WC].Attribute == true)
		{
			CGSendResetStats(0);
		}
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
		{
			CGSendResetStats(1);
		}
	}
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Reset Master Skill
		if (this->Data[eRESETMASTER_CHECK_WC].Attribute == true)
		{
			CGSendResetStats(2);
		}
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		if (this->Data[eRESETMASTER_CHECK_STAT].Attribute == true)
		{
			CGSendResetStats(3);
		}
	}
	this->SwitchResetStatsWindowState();
}

void Interface::EventResetStatsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESETSTATS_CLOSE].EventTick);
	// ----
	if (!this->Data[eRESETSTATS_MAIN].OnShow || !IsWorkZone(eRESETSTATS_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESETSTATS_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eRESETSTATS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eRESETSTATS_CLOSE].EventTick = GetTickCount();
	this->SwitchResetStatsWindowState();

}

//void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
//{
//	this->Data[ObjectID].X = PosX;
//	this->Data[ObjectID].Y = PosY;
//	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
//	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
//	// ----
//	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
//		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
//}

void Interface::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	//if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	//{
	this->Data[ObjectID].X = X;
	this->Data[ObjectID].Y = Y;
	this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	//if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	//{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}


int Wnext = 0;
bool Interface::WareNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextWare].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevWare].EventTick);

	if (!gInterface.Data[eWAREHOUSE_MAIN].OnShow || Wnext == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextWare))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNextWare].OnClick = true;
		return true;
	}


	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextWare].OnClick = false;

	this->Page++;

	gInterface.Data[eNextWare].EventTick = GetTickCount();


	return true;
}

int Wprev = 0;
bool Interface::WarePrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevWare].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextWare].EventTick);

	if (!gInterface.Data[eWAREHOUSE_MAIN].OnShow || Wprev == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevWare))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[ePrevWare].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevWare].OnClick = false;

	gInterface.Data[ePrevWare].EventTick = GetTickCount();

	this->Page--;

	return true;
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...)
{
	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	int v13; // ST1C_4@1
	int v15; // ST20_4@1
	pSetFont(pTextThis(), (int)Font);
	v13 = sub_41FFE0_Addr(pTextThis());
	v15 = sub_420010_Addr(pTextThis());
	SetTextColorByHDC(pTextThis(), Color);
	sub_4200F0_Addr(pTextThis(), Arg7);
	pSetBkColor(pTextThis(), 255, 255, 255, 0);
	pDrawText(pTextThis(), PosX, PosY, TextBuff, Width, Arg5, (int*)Align, 0);
	SetTextColorByHDC(pTextThis(), v13);
	sub_4200F0_Addr(pTextThis(), v15);
}

int  getNumberOfDays(int month, int year)
{
	//leap year condition, if month is 2
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	//months which has 31 days
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
	{
		return 31;
	}

	return 30;
}

void Interface::DrawEventTableWindow()
{

	if (!this->Data[eEVENTTABLE_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float MainWidth = 190.0;
	float MainHeight = this->Data[eEVENTTABLE_MAIN].Height;
	float StartY = 0;
	float StartX = MAX_WIN_WIDTH - this->Data[eEVENTTABLE_MAIN].Width;
	float MainCenter = StartX + (MainWidth / 3);
	//int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	//int y = GetPrivateProfileIntA("Graphics", "Y", 60, "./Settings.ini");

	this->DrawGUI(eEVENTTABLE_MAIN, StartX, StartY);
	this->DrawGUI(eEVENTTABLE_LEFT, StartX, StartY + this->Data[eEVENTTABLE_TITLE].Height);
	this->DrawGUI(eEVENTTABLE_RIGHT, MAX_WIN_WIDTH - this->Data[eEVENTTABLE_LEFT].Width, StartY + this->Data[eEVENTTABLE_TITLE].Height);
	this->DrawGUI(eEVENTTABLE_TITLE, StartX, StartY);
	this->DrawGUI(eEVENTTABLE_FOOTER, StartX, 384);
	this->DrawGUI(eEVENTTABLE_CLOSE, StartX + MainWidth - this->Data[eEVENTTABLE_CLOSE].Width + 3, -1);
	// ----
	//gNewInterface.TextDraw(StartX + MainWidth/2,MainHeight-50,0,1,eGold,0,eCenter,gFont[ARIAL_BLACK_16]->m_Font,"%d / %d",gEventTimer.m_CurrentPage+1,gEventTimer.m_PageCount+1);

	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 87, MainHeight - 50, Fcolor->White, Fcolor->Trans, 15, (LPINT)5, "%d / %d", gEventTimer.m_CurrentPage + 1, gEventTimer.m_PageCount + 1);

	gInterface.DrawGUI(eARROW_LEFT2, StartX + 60, MainHeight - 57);

	gInterface.DrawGUI(eARROW_RIGHT2, StartX + 110, MainHeight - 57);
	// ----
	//gNewInterface.TextDraw(StartX+MainWidth/2,StartY+12,0,1,eWhite,0,8,pFontBold,"[Event Table]"); // Window Name
	gFont[TAHOMA_BOLD_14]->DrawText(StartX + 70, StartY + 12, Fcolor->Red, Fcolor->Trans, 15, (LPINT)5, "Event Timer");
	// ----
	int max_per_page = 20;
	int count = 0;

	//g_Console.AddMessage(5,"MaxGroup = %d",gEventTimer.m_MaxGroup);
	CTime local_time(time(0) - this->m_TimeDiff);

	/*
	int font = ARIAL_BLACK_16;

	if (*(DWORD*)MAIN_RESOLUTION == 1)
	{
	font = ARIAL_BLACK_12;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 2)
	{
	font = ARIAL_BLACK_13;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 3)
	{
	font = ARIAL_BLACK_14;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 15)
	{
	font = ARIAL_BLACK_12;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 17)
	{
	font = ARIAL_BLACK_14;
	}
	*/
	int group = -1;
	for (group = gEventTimer.m_CurrentPage * max_per_page; group < gEventTimer.m_MaxGroup + 1; group++) // switch for all grouos
	{
		if (count >= max_per_page)
		{
			break;
		}
		CTime min_time = (local_time.GetTime() + 86400);
		int min_index = -1;
		std::vector<EVENTTIMER_INFO> mTimer = gEventTimer.getEventTimerByGroup(group); // get all events for this group

		for (int i = 0; i < mTimer.size(); i++) //switch for all events in this group
		{
			if (mTimer.at(i).DayOfWeek == -1)
			{
				CTime eventtime(local_time.GetYear(), local_time.GetMonth(), local_time.GetDay(), mTimer.at(i).Hour, mTimer.at(i).Minute, 0, -1); //get time for this event

				if (eventtime < local_time)
				{
					eventtime += 86400; // åñëè åâåíò óæå áûë ñåãîäíÿ, òî ïðèáàâëÿåì ñóòêè, ñëåäîâàòåëüíî åâåíò äîëæåí áûòü çàâòðà
				}

				if (eventtime < min_time)
				{
					min_time = eventtime;
					min_index = i;
				}

			}
			else
			{
				for (int j = 0; j < 8; j++)
				{
					int year = local_time.GetYear();
					int month = local_time.GetMonth();
					int day = local_time.GetDay();

					if (local_time.GetDay() + j > getNumberOfDays(month, year))
					{
						day = local_time.GetDay() + j - getNumberOfDays(month, year);
						if (month + 1 > 12)
						{
							year++;
							month = 1;
						}
						else
						{
							month++;
						}

					}

					//CTime eventTime(local_time.GetYear(),local_time.GetMonth(),local_time.GetDay()+j,gEventTimer.m_EventTimerInfo[i].Hour,gEventTimer.m_EventTimerInfo[i].Minute,0,-1);
					CTime eventTime(year, month, day, gEventTimer.m_EventTimerInfo[i].Hour, gEventTimer.m_EventTimerInfo[i].Minute, 0, -1);
					if (eventTime.GetDayOfWeek() == mTimer.at(i).DayOfWeek)
					{
						if (eventTime.GetDay() == local_time.GetDay() && eventTime.GetHour() <= local_time.GetHour() && eventTime.GetMinute() < local_time.GetMinute())
						{
							continue;
						}

						min_time = eventTime;
						min_index = i;
					}
				}
			}
		}

		if (min_index != -1)
		{
			CTimeSpan lol = min_time - local_time;

			//gNewInterface.TextDraw(StartX+15,StartY+55+(count*15),0,1,eGold,0,eLeftToRight,gFont[font]->m_Font,"%d. %s:",group+1,mTimer[min_index].Name);
			//gNewInterface.TextDraw(StartX+15,StartY+55+(count*15),0,1,eGold,0,eLeftToRight,gFont[font]->m_Font,"%d. %s:",group+1,gEventTimer.GetText(mTimer.at(min_index).TextIndex));
			//gNewInterface.TextDraw(StartX+MainWidth-15,StartY+55+(count*15),0,1,eBlue,0,eRightToLeft,gFont[font]->m_Font,"%dd %dh %dm %ds",(int)lol.GetDays(),lol.GetHours(),lol.GetMinutes(),lol.GetSeconds());
			gFont[TAHOMA_BOLD_13]->DrawText(StartX + 15, StartY + 55 + (count * 15), Fcolor->White, Fcolor->Trans, 15, (LPINT)5, "%d. %s:", group + 1, gEventTimer.GetText(mTimer.at(min_index).TextIndex));
			gFont[TAHOMA_BOLD_13]->DrawText(StartX + 120, StartY + 55 + (count * 15), Fcolor->Orange, Fcolor->Trans, 15, (LPINT)5, "%dd %dh %dm %ds", (int)lol.GetDays(), lol.GetHours(), lol.GetMinutes(), lol.GetSeconds());

			pDrawGUI(0x7B5E, StartX + 13, StartY + 55 + (count * 15) + 10, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
			pDrawGUI(0x7B5E, StartX + 13 + 82, StartY + 55 + (count * 15) + 10, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

			count++;
		}
	}
	// ----
	if (this->IsWorkZone(eEVENTTABLE_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eEVENTTABLE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eEVENTTABLE_CLOSE, StartX + MainWidth - this->Data[eEVENTTABLE_CLOSE].Width + 3, -1, Color);
		this->DrawToolTip(this->Data[eEVENTTABLE_CLOSE].X + 5, this->Data[eEVENTTABLE_CLOSE].Y + 24, "Close");
	}

	if (this->IsWorkZone(eARROW_LEFT2))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eARROW_LEFT2].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eARROW_LEFT2, StartX + 60, MainHeight - 57, Color);
	}

	if (this->IsWorkZone(eARROW_RIGHT2))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eARROW_RIGHT2].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eARROW_RIGHT2, StartX + 110, MainHeight - 57, Color);
	}
}

void Interface::EventEventTableWindow(DWORD Event)
{
	if (!this->Data[eEVENTTABLE_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (this->IsWorkZone(eEVENTTABLE_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eEVENTTABLE_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eEVENTTABLE_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eEVENTTABLE_CLOSE].EventTick = GetTickCount();
		gEventTimer.EventTimerSwitch();
	}
	else if (this->IsWorkZone(eARROW_LEFT2))
	{
		DWORD Delay = (CurrentTick - this->Data[eARROW_LEFT2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eARROW_LEFT2].OnClick = true;
			return;
		}
		// ----
		this->Data[eARROW_LEFT2].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eARROW_LEFT2].EventTick = GetTickCount();
		//
		if (gEventTimer.m_CurrentPage > 0)
			gEventTimer.m_CurrentPage--;
	}
	else if (this->IsWorkZone(eARROW_RIGHT2))
	{
		DWORD Delay = (CurrentTick - this->Data[eARROW_RIGHT2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eARROW_RIGHT2].OnClick = true;
			return;
		}
		// ----
		this->Data[eARROW_RIGHT2].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eARROW_RIGHT2].EventTick = GetTickCount();
		//
		if (gEventTimer.m_CurrentPage < gEventTimer.m_PageCount)
		{
			gEventTimer.m_CurrentPage++;
		}
	}
	// ----
}

bool Interface::CursorZoneButton(float X, float Y, float MaxX, float MaxY)
{
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

void Interface::DrawFruit()
{
	if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(MoveList) ||
		this->CheckWindow(SkillTree))
		return;

	if (!this->Data[eFruitMain].OnShow)
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pDrawImage(iGfxDialoge, StartX + 50, StartY + 50, 150, 200, 1, 1, 1.0, 1.0, 1, 1, 0); //223 280
	pDrawImage(iNewuiDialogHr, StartX + 50, StartY + 115, 145, 5, 1, 1, 1.0, 1.0, 1, 1, 0); //235 210

	this->DrawFormat(eGold, StartX + 15, StartY + 63, 223, 3, gCustomMessage.GetMessage(150));
	int TotalPoint;
	TotalPoint = gObjUser.FStrength + gObjUser.FDexterity + gObjUser.FVitality + gObjUser.FEnergy + gObjUser.FLeadership;
	glColor4f(0.0, 0.0, 0.0, 0.7);
	float BarWidth = 130.1f * (TotalPoint / (TotalPoint + gObjUser.FMaxPoint * 1.0f));
	pDrawBarForm((float)StartX + 60, (float)StartY + 85, 130, 10.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 134, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 154, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 174, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 194, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 214, 30, 13.0, 0, 0);
	glColor3f(2.0, 2.0, 0.0);
	pDrawBarForm((float)StartX + 62, (float)StartY + 87, BarWidth, 6, 0, 0);
	this->DrawItem2(StartX + 40, StartY + 100, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(3), 0, 0, 0); //Str
	this->DrawItem2(StartX + 40, StartY + 120, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(2), 0, 0, 0); //Agi
	this->DrawItem2(StartX + 40, StartY + 140, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(1), 0, 0, 0); //Vit
	this->DrawItem2(StartX + 40, StartY + 160, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(0), 0, 0, 0); //Ene
	this->DrawItem2(StartX + 40, StartY + 180, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(4), 0, 0, 0); //Cmd
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 100, StartY + 100, Fcolor->Gold, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(151), TotalPoint, gObjUser.FMaxPoint);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 135, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(152));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 155, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(153));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 175, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(154));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 195, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(155));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 215, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(156));

	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 135, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FStrength);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 155, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FDexterity);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 175, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FVitality);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 195, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FEnergy);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 215, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FLeadership);

	this->DrawGUI(eFruitClose, StartX + 165, StartY + 55);
	if (this->IsWorkZone(eFruitClose))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eFruitClose].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eFruitClose, this->Data[eFruitClose].X, this->Data[eFruitClose].Y, Color);
	}
}

void Interface::EventFruitWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!gInterface.Data[eFruitMain].OnShow)
	{
		return;
	}

	if (this->IsWorkZone(eFruitClose))
	{
		DWORD Delay = (CurrentTick - this->Data[eFruitClose].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFruitClose].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eFruitClose].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eFruitClose].EventTick = GetTickCount();
		//Func
		this->Fruit_State();
	}
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}

bool Interface::CheckWindowEx(int WindowID)
{
	return this->Data[WindowID].OnShow;
}

int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}

int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

void Interface::OpenWindowEx(int WindowID)
{
	Data[WindowID].Open();
}

void Interface::CloseWindowEx(int WindowID)
{
	Data[WindowID].Close();
}

void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eCHANGINGCLASS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eCHANGINGCLASS_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eCHANGINGCLASS_FOOTER, StartX, StartY);
	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + MainWidth - this->Data[eCHANGINGCLASS_CLOSE].Width, this->Data[eCHANGINGCLASS_TITLE].Height + this->Data[eCHANGINGCLASS_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eCHANGINGCLASS_CLOSE].X + 5, this->Data[eCHANGINGCLASS_CLOSE].Y + 25, gCustomMessage.GetMessage(70));
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gCustomMessage.GetMessage(158));
	// ----
	if (gChangeClass.m_PriceType == 0)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(159));
	}
	else if (gChangeClass.m_PriceType == 1)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(160));
	}
	else if (gChangeClass.m_PriceType == 2)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(161));
	}
	else if (gChangeClass.m_PriceType == 3)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(162));
	}
	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, 365);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	//if( gObjUser.m_CreditsCount
	//	< gChangeClass.m_Price )
	//{
	//	pGetMoneyFormat((double)gChangeClass.m_Price, 
	//		MoneyBuff, 0);
	//	pGetMoneyFormat((double)gChangeClass.m_Price - gObjUser.m_CreditsCount, 
	//		MoneyBuff2, 0);
	//	this->DrawFormat(eRed, StartX + 70, 369, 170, 1, "%s\n(Need still %s)", 
	//		MoneyBuff, MoneyBuff2);
	//}
	//else
	//{
	pGetMoneyFormat((double)gChangeClass.m_Price,
		MoneyBuff, 0);
	this->DrawFormat(eGold, StartX + 70, 372, 70, 1, "%s",
		MoneyBuff);
	//}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 330, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 338, 210, 3, "Before make changing class need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	//this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "Dark Wizard class");
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 24));
	// ----
	//if (gProtect.m_MainInfo.MaxClassTypes >= 6)
	//{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 1687));
	//}
	// ----
	//if (gProtect.m_MainInfo.MaxClassTypes >= 7)
	//{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 3150));
	//}

	//if (gProtect.m_MainInfo.MaxClassTypes >= 8)
	//{
		this->DrawGUI(eCHANGINGCLASS_GL, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX + 10, this->Data[eCHANGINGCLASS_MAIN].Y + 160, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 3175));
	//}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 212);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	this->Data[eCHANGINGCLASS_GL].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.MaxClassTypes >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.MaxClassTypes >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

	if (IsWorkZone(eCHANGINGCLASS_GL))
	{
		if (gProtect.m_MainInfo.MaxClassTypes >= 8)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_GL].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_GL, this->Data[eCHANGINGCLASS_GL].X, this->Data[eCHANGINGCLASS_GL].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

void Interface::EventChangingClassWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DW].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DW].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(0);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DK].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DK].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(16);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_ELF].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_ELF].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(32);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_MG].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_MG].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(48);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DL].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DL].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow == true)
		{
			gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
			pSetCursorFocus = false;
		}

		// ----
		this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(64);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.MaxClassTypes < 6)
		{
			return;
		}
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_SUM].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_SUM].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(80);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.MaxClassTypes < 7)
		{
			return;
		}
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_RF].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_RF].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(96);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_GL))
	{
		if (gProtect.m_MainInfo.MaxClassTypes < 7)
		{
			return;
		}
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_GL].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_GL].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_GL].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(112);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
		//Func
		this->Data[eCHANGINGCLASS_MAIN].Close();
	}
}

void Interface::DrawResetWindow()
{


	if (!this->Data[eRESET_MAIN].OnShow)
	{
		return;
	}

	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawGUI(eRESET_MAIN, StartX, StartY + 2);
	this->DrawGUI(eRESET_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eRESET_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eRESET_FOOTER, StartX, StartY);
	this->DrawGUI(eRESET_CLOSE, StartX + MainWidth - this->Data[eRESET_CLOSE].Width, this->Data[eRESET_TITLE].Height + this->Data[eRESET_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eRESET_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESET_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESET_CLOSE, this->Data[eRESET_CLOSE].X, this->Data[eRESET_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eRESET_CLOSE].X + 5, this->Data[eRESET_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "Reset Master");
	// ----
	this->DrawGUI(eRESET_INFOBG, StartX + 30, 140);
	this->DrawFormat(eGold, StartX + 35, 145, 70, 3, "Next Reset:");
	this->DrawFormat(eWhite, StartX + 135, 145, 70, 1, "%d", ViewReset + 1);
	this->DrawGUI(eRESET_INFOBG, StartX + 30, 160);
	this->DrawFormat(eGold, StartX + 35, 165, 70, 3, "Reward Points:");
	this->DrawFormat(eWhite, StartX + 135, 165, 70, 1, "%d", gResetSystem.GetRewardPoints() + gObjUser.m_QuestStat);
	// ----
	this->DrawGUI(eRESET_DIV, StartX, 185);
	// ----
	this->DrawFormat(eGold, StartX + 30, 215, 210, 1, "Required Level:");
	// ----
	if (gObjUser.lpPlayer->Level < gResetSystem.m_ResetData.ReqLevel)//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel] )
	{
		this->DrawFormat(eRed, StartX + 30, 225, 210, 1, "- %d (Your: %d)",
			gResetSystem.m_ResetData.ReqLevel, gObjUser.lpPlayer->Level);
		//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel], gObjUser.lpPlayer->Level);
	}
	else
	{
		this->DrawFormat(eWhite, StartX + 30, 225, 210, 1, "- %d",
			gResetSystem.m_ResetData.ReqLevel);
		//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel]);
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 240, 210, 1, "Required Items:");
	// ----
	for (int i = 0; i < gResetSystem.m_ResetData.ItemCount/*gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemCount*/; i++)
	{
		char ItemNameBuff[150], LevelBuff[25], OptionBuff[25];
		// ----
		ZeroMemory(ItemNameBuff, sizeof(ItemNameBuff));
		// ----
		//if (gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemData[i].Count > 1)
		if (gResetSystem.m_ResetData.ItemData[i].Count > 0)
		{
			char buff[25];
			sprintf(buff, " %dx ", gResetSystem.m_ResetData.ItemData[i].Count/*gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemData[i].Count*/);
			strcat(ItemNameBuff, buff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsExcellent)
		{
			strcat(ItemNameBuff, "Excellent ");
			ItemNameColor = eExcellent;
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsAncient)
		{
			strcat(ItemNameBuff, "Ancient ");
			ItemNameColor = eAncient;
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsSocket)
		{
			strcat(ItemNameBuff, "Socket ");
			ItemNameColor = eSocket;
		}
		// ----
		strcat(ItemNameBuff, (char*)(*(DWORD*)0x8128AC0 + 84 *
			gResetSystem.m_ResetData.ItemData[i].ID));
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].MinLevel
			== gResetSystem.m_ResetData.ItemData[i].MaxLevel)
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d, ", gResetSystem.m_ResetData.ItemData[i].MinLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		else
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d~%d, ",
				gResetSystem.m_ResetData.ItemData[i].MinLevel,
				gResetSystem.m_ResetData.ItemData[i].MaxLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].MinOption
			== gResetSystem.m_ResetData.ItemData[i].MaxOption)
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d] ", gResetSystem.m_ResetData.ItemData[i].MinOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		else
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d~%d] ",
				gResetSystem.m_ResetData.ItemData[i].MinOption * 4,
				gResetSystem.m_ResetData.ItemData[i].MaxOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsLuck == 0)
		{
			//strcat(ItemNameBuff, "+ Without Luck ");
		}
		else if (gResetSystem.m_ResetData.ItemData[i].IsLuck == 1)
		{
			strcat(ItemNameBuff, "+ Luck ");
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsSkill == 0)
		{
			//strcat(ItemNameBuff, "+ Without Skill");
		}
		else if (gResetSystem.m_ResetData.ItemData[i].IsSkill == 1)
		{
			strcat(ItemNameBuff, "+ Skill");
		}
		// ----
		if (!gObjUser.m_ResetItemCheck[i])
		{
			pDrawGUI(0x7BC4, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		else
		{
			pDrawGUI(0x7BC1, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		// ----
		this->DrawFormat(ItemNameColor, StartX + 30, 250 + (i * 8), 210, 1, ItemNameBuff);

	}
	// ----
	if (gResetSystem.m_ResetData.ItemCount <= 0)
	{
		this->DrawFormat(eWhite, StartX + 30, 250, 210, 1, "- None");
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 295, 210, 1, "Required Zen:");
	this->DrawGUI(eRESET_MONEYBG, StartX + 30, 305);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	if (gObjUser.lpPlayer->MoneyInventory
		< gResetSystem.GetResetMoney())
	{
		pGetMoneyFormat((double)gResetSystem.GetResetMoney(),
			MoneyBuff, 0);
		pGetMoneyFormat((double)gResetSystem.GetResetMoney() - gObjUser.lpPlayer->MoneyInventory,
			MoneyBuff2, 0);
		this->DrawFormat(eRed, StartX + 70, 309, 170, 1, "%s\n(Need still %s)",
			MoneyBuff, MoneyBuff2);
	}
	else
	{
		pGetMoneyFormat((double)gResetSystem.GetResetMoney(),
			MoneyBuff, 0);
		this->DrawFormat(eGold, StartX + 70, 312, 70, 1, "%s",
			MoneyBuff);
	}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 340, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 348, 210, 3, "Before make reset you need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eRESET_FINISH, ButtonX, this->Data[eRESET_FOOTER].Y + 10);
	this->DrawFormat(eWhite, StartX + 8, this->Data[eRESET_FOOTER].Y + 20, 210, 3, "Make Reset");
	this->DrawGUI(eRESET_DIV, StartX, this->Data[eRESET_FOOTER].Y - 10);
	// ----
	if (!gResetSystem.CheckAllReq())
	{
		this->Data[eRESET_FINISH].Attribute = false;
		this->DrawColoredGUI(eRESET_FINISH, this->Data[eRESET_FINISH].X, this->Data[eRESET_FINISH].Y, eGray150);
		return;
	}
	// ----
	this->Data[eRESET_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eRESET_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESET_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESET_FINISH, this->Data[eRESET_FINISH].X, this->Data[eRESET_FINISH].Y, Color);
	}
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Main(DWORD Event)
{
	this->EventResetWindow_Close(Event);
	this->EventResetWindow_Finish(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESET_CLOSE].EventTick);
	// ----
	if (!this->Data[eRESET_MAIN].OnShow || !IsWorkZone(eRESET_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESET_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eRESET_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eRESET_CLOSE].EventTick = GetTickCount();
	this->Data[eRESET_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESET_FINISH].EventTick);
	// ----
	if (!this->Data[eRESET_MAIN].OnShow || !IsWorkZone(eRESET_FINISH)
		|| !this->Data[eRESET_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESET_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eRESET_FINISH].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eRESET_FINISH].EventTick = GetTickCount();
	gResetSystem.ReqResetFinish();
	// ----
	return false;
}






// ----------------------------------------------------------------------------------------------

void Interface::DrawSettingsUI()
{
	if (!this->Data[eSETTINGS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;

	this->DrawGUI(eSETTINGS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eSETTINGS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSETTINGS_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eSETTINGS_FOOTER, StartX, StartY);

	int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");

	this->DrawGUI(eSETTINGS_CLOSE, StartX + MainWidth - this->Data[eSETTINGS_CLOSE].Width, this->Data[eSETTINGS_CLOSE].Height + this->Data[eSETTINGS_CLOSE].Height + 40);
	// ----

	if (this->IsWorkZone(eSETTINGS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSETTINGS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSETTINGS_CLOSE, this->Data[eSETTINGS_CLOSE].X, this->Data[eSETTINGS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSETTINGS_CLOSE].X + 5, this->Data[eSETTINGS_CLOSE].Y + 25, "Close");
	}
	// ----

	int ObjectIDs[7] =
	{
		eSETTINGS_CHECKBOX1,
		eSETTINGS_CHECKBOX2,
		eSETTINGS_CHECKBOX3,
		eSETTINGS_CHECKBOX4,
		eSETTINGS_CHECKBOX5,
		eSETTINGS_CHECKBOX6,
		eSETTINGS_CHECKBOX7,
	};

	char szCharNames[7][32] =
	{
		"Separate Chat",
		"Fog",
		"Player Health Bar",
		"Monster Health Bar",
		"Time Bar",
		"Mini Map",
		"Quest Info"
	};

	for (int i = 0; i < 7; i++)
	{
		this->DrawGUI(eSETTINGS_LINE, StartX + 30, this->Data[eSETTINGS_MAIN].Y + 55 + (20 * i));

		this->DrawGUI(eSETTINGS_OPTION, StartX + 35, this->Data[eSETTINGS_MAIN].Y + 38 + (20 * i));

		this->DrawFormat(eWhite, StartX + 50, this->Data[eSETTINGS_MAIN].Y + 40 + (20 * i), 125, 1, szCharNames[i]);

		this->DrawButton(ObjectIDs[i], ButtonX + 100, this->Data[eSETTINGS_MAIN].Y + 37 + (20 * i), 0, 15 * gServerInfo.GetSettingsInfo(i));
	}
	// ----
}

void Interface::EventSettingsUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (this->IsWorkZone(eSETTINGS_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSETTINGS_CLOSE].EventTick);
		// ----
		if (!this->Data[eSETTINGS_MAIN].OnShow)
		{
			return;
		}
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSETTINGS_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSETTINGS_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSETTINGS_CLOSE].EventTick = GetTickCount();
		this->SwitchSettingsWindowState();
		// ----
	}

	int ObjectIDs[7] =
	{
		eSETTINGS_CHECKBOX1,
		eSETTINGS_CHECKBOX2,
		eSETTINGS_CHECKBOX3,
		eSETTINGS_CHECKBOX4,
		eSETTINGS_CHECKBOX5,
		eSETTINGS_CHECKBOX6,
		eSETTINGS_CHECKBOX7,
	};

	for (int i = 0; i < 7; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eSETTINGS_MAIN].OnShow)
			{
				return;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gServerInfo.SetSettingsInfo(i);
		}
	}
}

void Interface::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
	float v1, v2;

	if (W) {
		W /= ScaleW;
		v1 = ScaleW / (SourceW / W);
	}
	else {
		v1 = ScaleW;
	}

	if (H) {
		H /= ScaleH;
		v2 = ScaleH / (SourceH / H);
	}
	else {
		v2 = ScaleH;
	}
	pNIDrawGUI(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0);
}


void Interface::DrawWindowBG(float a1, float a2) {
	static float v1;
	static float v2;
	static float v3;

	v1 = a2 + 74 / scale_ratio;
	v2 = v1 + 179 / scale_ratio;
	v3 = scale_height / 1.3;
	gInterface.DrawFrame(0xF1003, a1, a2, 325, 74, 652, 106, 1024, 512, scale_width, scale_height, 0);
	gInterface.DrawFrame(0xF1003, a1, v1, 325, 179, 326, 1, 1024, 512, scale_width, scale_height, 0);
	gInterface.DrawFrame(0xF1003, a1, v2, 325, 386, 0, 1, 1024, 512, scale_width, v3, 0);
}

bool Interface::IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5)
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
			return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
		return false;
	return true;
}


void Interface::DrawCheckLineEx(bool isChecked, int PointID, int CheckID, int LineID, float X, float Y, DWORD Color, char* Text)
{
	//this->DrawAnimatedGUI(PointID, X + 20, Y - 4); // Point
	this->DrawFormat(eWhite, X + 50, Y + 1, 200, 1, Text);

	if (isChecked)
	{
		this->DrawAnimatedButton(CheckID, X + 190, Y - 6, 0, 0);
	}
	else
	{
		this->DrawAnimatedButton(CheckID, X + 190, Y - 6, 0, 15);
	}

	//this->DrawAnimatedGUI(LineID, X + 33, Y + 10);
}

bool checkBtn(int obj)
{
	if (gObjUser.m_CursorX < gInterface.Data[obj].X || gObjUser.m_CursorX > gInterface.Data[obj].MaxX ||
		gObjUser.m_CursorY < gInterface.Data[obj].Y || gObjUser.m_CursorY > gInterface.Data[obj].MaxY)
	{
		//g_Console.AddMessage(5,"false!");
		return false;
	}
	return true;
}




void Interface::PartUPandDNEx(int PointID, int UpID, int DownID, int LineID, float X, float Y, DWORD Color, int Value, char* Text)
{
	//this->DrawAnimatedGUI(PointID, X + 20, Y - 4); // Point

	this->DrawFormat(eWhite, X + 50, Y + 1, 200, 1, Text);

	this->DrawAnimatedButton(DownID, X + 150, Y - 6, 0, 0); // 

	if (checkBtn(DownID))
	{
		//g_Console.AddMessage(3," %d ", this->Data[DownID].OnClick);
		if (this->Data[DownID].OnClick)
		{
			//g_Console.AddMessage(3,"CLICK!");
			this->DrawAnimatedButton(DownID, X + 150, Y - 6, 0, 16);
		}
	}

	//this->DrawToolTip(X+x, Y+y, "%d", Value);
	pSetBlend(true);
	this->DrawBarForm(X + 168, Y - 5, 19, 13, 0.0, 0.0, 0.0, 1.0);//ReqItems
	glColor3f(1, 1, 1);
	pSetBlend(false);
	char szText[10];
	sprintf(szText, "%d", Value);
	gNewInterface.TextDraw(X + 128, Y - 2, 100, 1, eWhite, 0, 3, pFontNormal, "%d", Value);
	//TestDrawText(szText, X+128, Y-2, 100, 1, eWhite, 0, 3,pFontNormal);
	//this->DrawBarForm(X+x, Y+y,w,h,0.04,0.34,0.0,1.0);//ReqItems

	this->DrawAnimatedButton(UpID, X + 190, Y - 6, 0, 0); // 

	if (checkBtn(UpID))
	{
		//g_Console.AddMessage(3," %d ", this->Data[UpID].OnClick);
		if (this->Data[UpID].OnClick)
		{
			//g_Console.AddMessage(3,"CLICK!");
			this->DrawAnimatedButton(UpID, X + 190, Y - 6, 0, 16);
		}
	}

	this->DrawGUI(LineID, X + 33, Y + 10);
}

void Interface::MiniButtonDraw(int BtnID, float X, float Y, bool isHover, char* Text)
{
	//int x = GetPrivateProfileIntA("Custom", "X", -35, "./Settings.ini");
	//int y = GetPrivateProfileIntA("Custom", "Y", 60, "./Settings.ini");

	if (isHover)
	{
		this->DrawAnimatedButton(BtnID, X, Y, 0, 29);
	}
	else
	{
		this->DrawAnimatedButton(BtnID, X, Y, 0, 0);
	}
	this->DrawFormat(eWhite, X + 7, Y + 9, 50, 3, Text);
	//this->DrawGUI(LineID, X+33, Y+10);
}

bool Interface::ButtonEx2(DWORD Event, int ButtonID, bool Type)
{
	//g_Console.AddMessage(5,"ENTER");
	//if( !this->IsWorkZone(ButtonID) )
	//g_Console.AddMessage(5,"%f - %f | %f - %f", this->Data[ButtonID].X, this->Data[ButtonID].MaxX,this->Data[ButtonID].Y, this->Data[ButtonID].MaxY );
	//if (!this->IsWorkZone(this->Data[ButtonID].X, this->Data[ButtonID].MaxX,this->Data[ButtonID].Y, this->Data[ButtonID].MaxY))
	if (!checkBtn(ButtonID))
	{
		//g_Console.AddMessage(3,"return because its shit");
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			//g_Console.AddMessage(3,"return2");
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return true;
	}
	if (Event != WM_LBUTTONUP)
	{
		return false;
	}
	/*if(Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
	this->Data[ButtonID].OnClick = false;
	return true;
	}*/
	// ----
	if (Delay < 500)
	{
		//g_Console.AddMessage(3,"return3");
		return false;
	}
	// ----

	//G_BEXO_MUA_VIP.OPEN_WINDOW_MUA_VIP();

	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	//g_Console.AddMessage(3,"return successfully");
	return true;
}

void Interface::DrawButtonMini(int id, int X, int Y, int res, char* Text)
{
	int StartX = X;
	int StartY = Y;

	gInterface.DrawGUI(id, StartX, StartY);
	gInterface.DrawFormat(eWhite, StartX + 5, StartY + 10, 50, 3, Text);

	if (!res)
	{
		gInterface.Data[id].Attribute = false;
		gInterface.DrawColoredGUI(id, gInterface.Data[id].X, gInterface.Data[id].Y, eGray150);
	}
	else
	{
		gInterface.Data[id].Attribute = true;
		if (gInterface.IsWorkZone(id))
		{
			DWORD Color = eGray100;
			// ----
			if (gInterface.Data[id].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(id, gInterface.Data[id].X, gInterface.Data[id].Y, Color);
		}
	}
}

void Interface::DrawPrice(int X, int Y, int iZen, int iChaos, int iBless, int iSoul, int iLife, int iBonus, int iCredit)
{
	int total = 0;

	if (iZen > 0)
	{
		total++;
	}
	if (iChaos > 0)
	{
		total++;
	}
	if (iBless > 0)
	{
		total++;
	}
	if (iSoul > 0)
	{
		total++;
	}
	if (iLife > 0)
	{
		total++;
	}
	if (iBonus > 0)
	{
		total++;
	}
	if (iCredit > 0)
	{
		total++;
	}

	int StartX = X;
	int StartY = Y;

	if (total == 1)
	{
		StartY += 15;
	}
	else if (total == 2)
	{
		StartY += 10;
	}
	else if (total == 3)
	{
		StartY += 5;
	}

	int ContentY = StartY;

	if (iZen > 0)
	{
		char MoneyBuff[50];
		pGetMoneyFormat((double)iZen, MoneyBuff, 0);
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "%s Zen", MoneyBuff);
		ContentY += 10;
	}

	if (iChaos > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "Jewel Of Chaos x %d", iChaos);
		ContentY += 10;
	}
	if (iBless > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "Jewel Of Bless x %d", iBless);
		ContentY += 10;
	}
	if (iSoul > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "Jewel Of Soul x %d", iSoul);
		ContentY += 10;
	}
	if (iLife > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "Jewel Of Soul x %d", iLife);
		ContentY += 10;
	}
	if (iBonus > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "%d Coin", iBonus);
		ContentY += 10;
	}
	if (iCredit > 0)
	{
		gInterface.DrawFormat(eYellow, StartX, ContentY, 100, 3, "%d Credit", iCredit);
		ContentY += 10;
	}
}

void Interface::DrawFormatEx(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	pDrawColorText(Buff, PosX, PosY, Width, 0, Color, 0, Align);
}

int Interface::DrawFormat_Ex(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	int LineCount = 0;
	// ----
	char* Line = strtok(Buff, "/");
	// ----
	while (Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "/");
	}
	// ----
	return PosY;
}

void Interface::DrawGUI2(short ObjectID)
{
	pDrawGUI(this->Data[ObjectID].ModelID, this->Data[ObjectID].X, this->Data[ObjectID].Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);

	this->m_iDrawObjectID = ObjectID;
}

void Interface::DrawColoredGUI2(short ObjectID, DWORD Color)
{
	pDrawColorButton(this->Data[ObjectID].ModelID, this->Data[ObjectID].X, this->Data[ObjectID].Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawButtonBig(int ObjID, bool bActive, float fX, float fY, char* Text)
{
	gInterface.DrawGUI(ObjID, fX, fY);
	gInterface.DrawFormat(eWhite, fX + 4, fY + 10, 100, 3, Text);
	if (bActive)
	{
		gInterface.Data[ObjID].Attribute = true;
		if (gInterface.IsWorkZone(ObjID))
		{
			DWORD Color = eGray100;
			if (gInterface.Data[ObjID].OnClick)
			{
				Color = eGray150;
			}
			gInterface.DrawColoredGUI(ObjID, gInterface.Data[ObjID].X, gInterface.Data[ObjID].Y, Color);
		}
	}
	else
	{
		gInterface.Data[ObjID].Attribute = false;
		gInterface.DrawColoredGUI(ObjID, gInterface.Data[ObjID].X, gInterface.Data[ObjID].Y, eGray150);
	}
}



void Interface::DrawGrandResetWindow()
{
	if (!this->Data[eGRESET_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eGRESET_MAIN, StartX, StartY + 2);
	this->DrawGUI(eGRESET_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eGRESET_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eGRESET_FOOTER, StartX, StartY);
	this->DrawGUI(eGRESET_CLOSE, StartX + MainWidth - this->Data[eGRESET_CLOSE].Width, this->Data[eGRESET_TITLE].Height + this->Data[eGRESET_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eGRESET_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eGRESET_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eGRESET_CLOSE, this->Data[eGRESET_CLOSE].X, this->Data[eGRESET_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eGRESET_CLOSE].X + 5, this->Data[eGRESET_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "Grand Reset Master");
	// ----
	this->DrawGUI(eGRESET_INFOBG, StartX + 30, 140);
	this->DrawFormat(eGold, StartX + 35, 145, 70, 3, "Next Grand Reset:");
	this->DrawFormat(eWhite, StartX + 135, 145, 70, 1, "%d", ViewGReset + 1);
	this->DrawGUI(eGRESET_INFOBG, StartX + 30, 160);
	this->DrawFormat(eGold, StartX + 35, 165, 70, 3, "Reward Points:");
	this->DrawFormat(eWhite, StartX + 135, 165, 70, 1, "%d", gGRSystem.GetRewardPoints(1) + gObjUser.m_QuestStat);
	// ----
	this->DrawGUI(eGRESET_DIV, StartX, 185);
	// ----
	this->DrawFormat(eGold, StartX + 30, 200, 210, 1, "Required Level:");
	// ----
	if (gObjUser.lpPlayer->Level < gGRSystem.m_GRData.ReqLevel)
	{
		this->DrawFormat(eRed, StartX + 30, 210, 210, 1, "- %d (Your: %d)",
			gGRSystem.m_GRData.ReqLevel, gObjUser.lpPlayer->Level);
	}
	else
	{
		this->DrawFormat(eWhite, StartX + 30, 210, 210, 1, "- %d",
			gGRSystem.m_GRData.ReqLevel);
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 220, 210, 1, "Required Reset:");
	// ----
	if (ViewReset < gGRSystem.m_GRData.ReqReset)
	{
		this->DrawFormat(eRed, StartX + 30, 230, 210, 1, "- %d (Your: %d)",
			gGRSystem.m_GRData.ReqReset, ViewReset);
	}
	else
	{
		this->DrawFormat(eWhite, StartX + 30, 230, 210, 1, "- %d",
			gGRSystem.m_GRData.ReqReset);
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 240, 210, 1, "Required Items:");
	// ----
	for (int i = 0; i < gGRSystem.m_GRData.ItemCount; i++)
	{
		char ItemNameBuff[150], LevelBuff[25], OptionBuff[25];
		// ----
		ZeroMemory(ItemNameBuff, sizeof(ItemNameBuff));
		// ----
		if (gGRSystem.m_GRData.ItemData[i].IsExcellent)
		{
			strcat(ItemNameBuff, "Excellent ");
			ItemNameColor = eExcellent;
		}
		// ----
		if (gGRSystem.m_GRData.ItemData[i].IsAncient)
		{
			strcat(ItemNameBuff, "Ancient ");
			ItemNameColor = eAncient;
		}
		// ----
		if (gGRSystem.m_GRData.ItemData[i].IsSocket)
		{
			strcat(ItemNameBuff, "Socket ");
			ItemNameColor = eSocket;
		}
		// ----
		strcat(ItemNameBuff, (char*)(*(DWORD*)0x8128AC0 + 84 *
			gGRSystem.m_GRData.ItemData[i].ID));
		// ----
		if (gGRSystem.m_GRData.ItemData[i].MinLevel
			== gGRSystem.m_GRData.ItemData[i].MaxLevel)
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d, ", gGRSystem.m_GRData.ItemData[i].MinLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		else
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d~%d, ",
				gGRSystem.m_GRData.ItemData[i].MinLevel,
				gGRSystem.m_GRData.ItemData[i].MaxLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		// ----
		if (gGRSystem.m_GRData.ItemData[i].MinOption
			== gGRSystem.m_GRData.ItemData[i].MaxOption)
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d] ", gGRSystem.m_GRData.ItemData[i].MinOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		else
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d~%d] ",
				gGRSystem.m_GRData.ItemData[i].MinOption * 4,
				gGRSystem.m_GRData.ItemData[i].MaxOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		// ----
		if (gGRSystem.m_GRData.ItemData[i].IsLuck == 0)
		{
			//strcat(ItemNameBuff, "+ Without Luck ");
		}
		else if (gGRSystem.m_GRData.ItemData[i].IsLuck == 1)
		{
			strcat(ItemNameBuff, "+ Luck ");
		}
		// ----
		if (gGRSystem.m_GRData.ItemData[i].IsSkill == 0)
		{
			//strcat(ItemNameBuff, "+ Without Skill");
		}
		else if (gGRSystem.m_GRData.ItemData[i].IsSkill == 1)
		{
			strcat(ItemNameBuff, "+ Skill");
		}
		// ----
		if (!gObjUser.m_ResetItemCheck[i])
		{
			pDrawGUI(0x7BC4, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		else
		{
			pDrawGUI(0x7BC1, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		// ----
		this->DrawFormat(ItemNameColor, StartX + 30, 250 + (i * 8), 210, 1, ItemNameBuff);
	}
	// ----
	if (gGRSystem.m_GRData.ItemCount <= 0)
	{
		this->DrawFormat(eWhite, StartX + 30, 250, 210, 1, "- None");
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 295, 210, 1, "Required Zen:");
	this->DrawGUI(eGRESET_MONEYBG, StartX + 30, 305);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	if (gObjUser.lpPlayer->MoneyInventory
		< gGRSystem.GetResetMoney())
	{
		pGetMoneyFormat((double)gGRSystem.GetResetMoney(), MoneyBuff, 0);
		pGetMoneyFormat((double)gGRSystem.GetResetMoney() - gObjUser.lpPlayer->MoneyInventory, MoneyBuff2, 0);
		this->DrawFormat(eRed, StartX + 70, 309, 170, 1, "%s\n(Need still %s)", MoneyBuff, MoneyBuff2);
	}
	else
	{
		pGetMoneyFormat((double)gGRSystem.GetResetMoney(), MoneyBuff, 0);
		this->DrawFormat(eGold, StartX + 70, 312, 70, 1, "%s", MoneyBuff);
	}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 340, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 348, 210, 3, "Before make grand reset you need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eGRESET_FINISH, ButtonX, this->Data[eGRESET_FOOTER].Y + 10);
	this->DrawFormat(eWhite, StartX + 8, this->Data[eGRESET_FOOTER].Y + 20, 210, 3, "Make Grand Reset");
	this->DrawGUI(eGRESET_DIV, StartX, this->Data[eGRESET_FOOTER].Y - 10);
	// ----
	if (!gGRSystem.CheckAllReq())
	{
		this->Data[eGRESET_FINISH].Attribute = false;
		this->DrawColoredGUI(eGRESET_FINISH, this->Data[eGRESET_FINISH].X, this->Data[eGRESET_FINISH].Y, eGray150);
		return;
	}
	// ----
	this->Data[eGRESET_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eGRESET_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eGRESET_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eGRESET_FINISH, this->Data[eGRESET_FINISH].X, this->Data[eGRESET_FINISH].Y, Color);
	}
}
// ----------------------------------------------------------------------------------------------

void Interface::EventGrandResetWindow_Main(DWORD Event)
{
	this->EventGrandResetWindow_Close(Event);
	this->EventGrandResetWindow_Finish(Event);
}
// ----------------------------------------------------------------------------------------------

void Interface::EventGrandResetWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eGRESET_CLOSE].EventTick);
	// ----
	if (!this->Data[eGRESET_MAIN].OnShow || !IsWorkZone(eGRESET_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eGRESET_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eGRESET_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eGRESET_CLOSE].EventTick = GetTickCount();
	this->Data[eGRESET_MAIN].Close();
	// ----
	return;
}
// ----------------------------------------------------------------------------------------------

void Interface::EventGrandResetWindow_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eGRESET_FINISH].EventTick);
	// ----
	if (!this->Data[eGRESET_MAIN].OnShow || !IsWorkZone(eGRESET_FINISH)
		|| !this->Data[eGRESET_FINISH].Attribute)
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eGRESET_FINISH].OnClick = true;
		return;
	}
	// ----
	this->Data[eGRESET_FINISH].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eGRESET_FINISH].EventTick = GetTickCount();
	gGRSystem.ReqResetFinish();
	this->Data[eGRESET_MAIN].Close();
	// ----
	return;
}

bool Interface::IsWorkZone3(short ObjectID)
{
	float PosX = this->Data[ObjectID].X;
	float MaxX = PosX + this->Data[ObjectID].Width;

	if (((float)pCursorX < PosX || (float)pCursorX > MaxX) || ((float)pCursorY < this->Data[ObjectID].Y || (float)pCursorY > this->Data[ObjectID].MaxY))
	{
		return false;
	}

	return true;
}



void Interface::DrawColorGUI(int MainID, int X, int Y, int Width, int Height, DWORD Color)
{
	pDrawColorButton(MainID, X, Y, Width, Height, 0, 0, Color);
}

void Interface::DrawItem1(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::DrawItemToolTipText(void* item, int x, int y)
{
	static DWORD mem = 0;
	_asm
	{
		PUSH 0
		PUSH 0
		PUSH 0
		PUSH item
		PUSH y
		PUSH x
		MOV mem, 0x00861110
		CALL mem
		MOV ECX, EAX
		MOV mem, 0x00861AA0
		CALL mem
		MOV ECX, EAX
		MOV mem, 0x007E3E30
		CALL mem
	}
}
void Interface::KeyBoxEvent(DWORD Event, char* kText, int MaxText)
{
	int Len = strlen(kText);

	if (kText[0] == '0')
	{
		kText[0] = 0;
	}

	switch (Event)
	{
	case VK_0:
	case VK_NUMPAD0:
	{
		if (Len < MaxText)
		{
			strcat(kText, "0");
		}
	}
	break;
	case VK_1:
	case VK_NUMPAD1:
	{
		if (Len < MaxText)
			strcat(kText, "1");
	}
	break;
	case VK_2:
	case VK_NUMPAD2:
	{
		if (Len < MaxText)
			strcat(kText, "2");
	}
	break;
	case VK_3:
	case VK_NUMPAD3:
	{
		if (Len < MaxText)
			strcat(kText, "3");
	}
	break;
	case VK_4:
	case VK_NUMPAD4:
	{
		if (Len < MaxText)
			strcat(kText, "4");
	}
	break;
	case VK_5:
	case VK_NUMPAD5:
	{
		if (Len < MaxText)
			strcat(kText, "5");
	}
	break;
	case VK_6:
	case VK_NUMPAD6:
	{
		if (Len < MaxText)
			strcat(kText, "6");
	}
	break;
	case VK_7:
	case VK_NUMPAD7:
	{
		strcat(kText, "7");
	}
	break;
	case VK_8:
	case VK_NUMPAD8:
	{
		if (Len < MaxText)
			strcat(kText, "8");
	}
	break;
	case VK_9:
	case VK_NUMPAD9:
	{
		if (Len < MaxText)
			strcat(kText, "9");
	}
	break;
	case VK_BACK:
	{
		if (Len > 0)
			kText[Len - 1] = 0;
	}
	break;
	}

	if (kText[0] == 0)
	{
		strcpy(kText, "0");
	}

	//int GetNum = atoi(this->KeyText);
	//gConsole.Output(cGREY, "atoi: %d", GetNum);
}

bool Interface::ButtonExR(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_RBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_RBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

//===========
void CGMoveCTCMini(int Type)
{
	if (Type > 0)
	{
		CTCMINI_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x39, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}
DWORD ClickTickCount = 0;

void Interface::DrawCTCMiniWindow()
{

	if (!this->Data[eCTC_MINI_MAIN].OnShow)
	{
		return;
	}
	pSetCursorFocus = true;

	float MainWidth, MainHeight, StartY, StartBody;
	MainWidth = 230.0;
	MainHeight = 180.0;
	StartY = 50.0f;
	StartBody = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	DWORD Color = eGray100;
	this->DrawGUI(eCTC_MINI_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eCTC_MINI_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eCTC_MINI_FRAME, StartX, StartY + (float)15.0, 16);
	this->DrawGUI(eCTC_MINI_FOOTER, StartX, StartY);
	this->DrawGUI(eCTC_MINI_CLOSE, StartX + MainWidth - this->Data[eCTC_MINI_CLOSE].Width, StartBody);
	if (this->IsWorkZone(eCTC_MINI_CLOSE)) {
		if (this->Data[eCTC_MINI_CLOSE].OnClick) {
			Color = eGray150;
		}
		this->DrawColoredGUI(eCTC_MINI_CLOSE, this->Data[eCTC_MINI_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eCTC_MINI_CLOSE].X + 5, StartBody + 25, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY - 245, 0xB8E600FF, 0x0, MainWidth, 0, 3, "CTC Mini"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY - 190, 200, 1); //-- Divisor
	//====================================
	StartY = StartY - 185;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (MainWidth / 10), StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Entire Guild: +25000 Dedication for Gate Breaking"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (MainWidth / 10), StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Entire guild: +30000 dedication during Occupy"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (MainWidth / 10), StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Entire guild: +10000 dedication when Win Event"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (MainWidth / 10), StartY, 0x00FFCCFF, 0x0, MainWidth, 0, 1, "Note: Guild Occupying 2 or more turrets will win."); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (MainWidth / 10), StartY, 0x00FF90FF, 0x0, MainWidth, 0, 1, "Previous Event Winner Guild Will Enter 'Territory'"); //
	StartY = StartY + 25;
	pDrawGUI(32583, StartX, StartY, 128.0f, 128.0f); //Huong Dan CTC

	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (MainWidth / 2);
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTC_MINI_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveCTCMini(1);
				this->Data[eCTC_MINI_MAIN].OnShow = 0;
				gInterface.Data[eCTC_MINI_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Port 1"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 2
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTC_MINI_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(2);
				this->Data[eCTC_MINI_MAIN].OnShow = 0;
				gInterface.Data[eCTC_MINI_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Port 2"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 3
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTC_MINI_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(3);
				this->Data[eCTC_MINI_MAIN].OnShow = 0;
				gInterface.Data[eCTC_MINI_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Port 3"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 4
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTC_MINI_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(4);
				this->Data[eCTC_MINI_MAIN].OnShow = 0;
				gInterface.Data[eCTC_MINI_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Port 4"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button Lanh Dia
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && CheckVaoLanhDia)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTC_MINI_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(5);
				this->Data[eCTC_MINI_MAIN].OnShow = 0;
				gInterface.Data[eCTC_MINI_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else if (!CheckVaoLanhDia) {
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Manor"); //Buoc Vao
	//=====================================
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawCTCMiNiMap()
{
	if (pPlayerState < GameProcess) {
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (gObjUser.m_MapNumber != 98) {
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	pDrawGUI(32584, StartX, StartY, 128.0f, 157.0f); //UI
	pDrawGUI(32583, StartX, StartY + 28.0, 128.0f, 128.0f); //MAP
	//== Cong Vao 1
	if (CTCMINI_Cong[0] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 96 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 2
	if (CTCMINI_Cong[1] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 128 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 3
	if (CTCMINI_Cong[2] == 0) {
		RenderBitmap(31681, (float)(StartX - 2.5 + 161 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}

	//Tru Chua Cong 1 //31683 Thuoc Ve Guild
	if (CTCMINI_Tru[0] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else {
		RenderBitmap(31683, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 2
	if (CTCMINI_Tru[1] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else {
		RenderBitmap(31683, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 3
	if (CTCMINI_Tru[2] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else {
		RenderBitmap(31683, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//pDrawGUI(32585, 640/2-(210/2), 480/2-(94/2),210,94);

	int Model;

	for (int i = 0; i < 400; i++)
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if (!Model) {
			continue;
		}
		if (Model
			&& *(BYTE*)(Model + 780)
			&& *(BYTE*)(Model + 800) == emPlayer
			)
		{
			if (Model != *(DWORD*)0x7BC4F04) {
				this->DrawGUI(eOTHERCHAR_POINT, (float)(StartX - 1 + *(DWORD*)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD*)(Model + 176)) / 2));
			}
			else {
				this->DrawGUI(eCHAR_POINT, (float)(StartX - 1 + *(DWORD*)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD*)(Model + 176)) / 2));
			}
		}
		
	}
}

#if(BOTOES_FUNCOES)
void Interface::DRAW_TINHNANG_INTERFACE()
{

	if (gProtect.m_MainInfo.EnableBotoesFuncoes != 0)
	{

		float MainWidth = 30.0;
		float MainHeight = 20.0;
		float StartY = 20.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		if (this->CheckWindow(ObjWindow::Character))
		{
			// AutoReset
			this->DrawGUI(EXBEXO_AUTORESET_INTERFACE, StartX + 180, StartY + 52);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_Autoreset = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_Autoreset); //set font
			pSetTextColor(pTextThis(), 255, 255, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 473, 77, gCustomMessage.GetMessage(180), 150, 0, (LPINT)0, 0); // "Tự động Reset"
			//Giải phóng
			DeleteObject(TextFontBold_Autoreset);
			//--------------------------------------------------------------------------------------------
			// QuestClass
			this->DrawGUI(EXBEXO_QUESTCLASS_INTERFACE, StartX + 239, StartY + 52);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_NhiemVu = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_NhiemVu); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 558, 77, gCustomMessage.GetMessage(181), 150, 0, (LPINT)0, 0); // "Làm Nhiệm Vụ"
			//Giải phóng
			DeleteObject(TextFontBold_NhiemVu);
			//--------------------------------------------------------------------------------------------
			// OffAttack
			this->DrawGUI(EXBEXO_OFFATTACK_INTERFACE, StartX + 160, StartY + 74);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_OffAttack = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_OffAttack); //set font
			pSetTextColor(pTextThis(), 255, 0, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 473, 100, gCustomMessage.GetMessage(182), 150, 0, (LPINT)0, 0); // "ATTACK"
			//Giải phóng
			DeleteObject(TextFontBold_OffAttack);
			//--------------------------------------------------------------------------------------------
			// UyThac
			this->DrawGUI(EXBEXO_UYTHAC_INTERFACE, StartX + 239, StartY + 74);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_UyThac = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_UyThac); //set font
			pSetTextColor(pTextThis(), 0, 255, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 558, 100, gCustomMessage.GetMessage(183), 150, 0, (LPINT)0, 0); // "OFF ATTACK"
			//Giải phóng
			DeleteObject(TextFontBold_UyThac);
			//--------------------------------------------------------------------------------------------
			// TayDiem
			this->DrawGUI(EXBEXO_TAYDIEM_INTERFACE, StartX + 159, StartY + 351);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_TayDiem = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_TayDiem); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 488, 377, gCustomMessage.GetMessage(184), 150, 0, (LPINT)0, 0); // "Tẩy Điểm"
			//Giải phóng
			DeleteObject(TextFontBold_TayDiem);
			//--------------------------------------------------------------------------------------------
			// TayDiemMaster
			this->DrawGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, StartX + 239, StartY + 351);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_TayDiemMaster = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_TayDiemMaster); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 565, 377, gCustomMessage.GetMessage(165), 150, 0, (LPINT)0, 0); // "Tẩy Điểm Master"
			//Giải phóng
			DeleteObject(TextFontBold_TayDiemMaster);
			//--------------------------------------------------------------------------------------------
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_AUTORESET_INTERFACE, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].X, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].Y, Color);
			}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_QUESTCLASS_INTERFACE, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].X, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].Y, Color);
			}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_OFFATTACK_INTERFACE, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].X, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].Y, Color);
			}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_UYTHAC_INTERFACE, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].X, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].Y, Color);
			}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_TAYDIEM_INTERFACE, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].Y, Color);
			}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
			if (gInterface.IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].Y, Color);
			}
	}
}

bool Interface::EVENT_TINHNANG_INTERFACE(DWORD Event)
{
	this->EVENT_AUTORESET_INTERFACE(Event);
	this->EVENT_LAMNHIEMVU_INTERFACE(Event);
	this->EVENT_OFFATTACK_INTERFACE(Event);
	this->EVENT_UYTHAC_INTERFACE(Event);
	this->EVENT_TAYDIEM_INTERFACE(Event);
	this->EVENT_TAYDIEM_MASTER_INTERFACE(Event);
	return true;
}
bool Interface::EVENT_AUTORESET_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x23, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);

	return true;

}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_LAMNHIEMVU_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x24, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_OFFATTACK_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x25, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_UYTHAC_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x26, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x27, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x28, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
void Interface::DarwinNapThe()
{
}
void Interface::DarwinFacebook()
{
}
// ----------------------------------------------------------------------------------------------
#endif



	
void Interface::DrawChienTruongCo()
{
	if (!this->Data[eBATTLEFIELD_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float MainWidth, MainHeight, StartY, StartBody;
	MainWidth = 230.0;
	MainHeight = 180.0;
	StartY = 50.0f;
	StartBody = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	DWORD Color = eGray100;
	this->DrawGUI(eBATTLEFIELD_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eBATTLEFIELD_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eBATTLEFIELD_FRAME, StartX, StartY + (float)15.0, 16);
	this->DrawGUI(eBATTLEFIELD_FOOTER, StartX, StartY);
	this->DrawGUI(eBATTLEFIELD_CLOSE, StartX + MainWidth - this->Data[eBATTLEFIELD_CLOSE].Width, StartBody);
	if (this->IsWorkZone(eBATTLEFIELD_CLOSE)) {
		if (this->Data[eBATTLEFIELD_CLOSE].OnClick) {
			Color = eGray150;
		}
		this->DrawColoredGUI(eBATTLEFIELD_CLOSE, this->Data[eBATTLEFIELD_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eBATTLEFIELD_CLOSE].X + 5, StartBody + 25, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY - 245, 0xB8E600FF, 0x0, MainWidth, 0, 3, "Ancient Battlefield"); //
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY - 180, 200, 1); //-- Divisor
	StartX = StartX + (MainWidth / 8);
	StartY = StartY - 175;
	//====================================
	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xE6FCF7FF, 0x0, MainWidth, 0, 1, "Time remaining:"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + 70, StartY, 0x16FAC1FF, 0x0, MainWidth, 0, 1, "%02d:%02d:%02d", hours, minutes, seconds); //
	//===================================
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Defeating 1 monster gets %d Points", CTC_PointKillQuai); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Join the Party to get %d Points", CTC_PartyKillPoint); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, MainWidth, 0, 1, "- Killing %d will drop random Item", CTC_MonterYeuCau); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0x26FFD0FF, 0x0, MainWidth, 0, 1, "- Ability to drop Feathers"); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY, 0xFF7226FF, 0x0, MainWidth, 0, 1, "Note: Free PK Area, be careful"); //


	//============Button
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX - 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBATTLEFIELD_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 1;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				this->Data[eBATTLEFIELD_MAIN].OnShow = 0;
				gInterface.Data[eBATTLEFIELD_MAIN].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Come in"); //Buoc Vao

	//=====================================
	//=====================Button 2
	if (pCheckMouseOver(StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBATTLEFIELD_MAIN].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(0.72f, 0.438f, 0.0432f);

				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 2;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				//pDrawMessage ( "Button 2", 0 );		  
				gInterface.Data[eBATTLEFIELD_MAIN].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX + SizeButtonW + 5, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "More Time"); //
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau

}

void Interface::EventCTCMiniWindow_Close(DWORD Event)
{
}

void Interface::EventBattlefieldWindow_Main(DWORD Event)
{
	this->EventBattlefieldWindow(Event);
	this->EventBattlefieldWindow_Close(Event);
}

void Interface::EventBattlefieldWindow(DWORD Event)
{
	if (!this->Data[eBATTLEFIELD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (this->IsWorkZone(eBATTLEFIELD_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eBATTLEFIELD_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eBATTLEFIELD_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eBATTLEFIELD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eBATTLEFIELD_CLOSE].EventTick = GetTickCount();
		SwitchBattlefieldWindowState();
	}

}




void Interface::EventBattlefieldWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eBATTLEFIELD_CLOSE].EventTick);
	// ----
	if (!this->Data[eBATTLEFIELD_CLOSE].OnShow || !IsWorkZone(eBATTLEFIELD_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eBATTLEFIELD_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eBATTLEFIELD_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eBATTLEFIELD_CLOSE].EventTick = GetTickCount();
	this->Data[eBATTLEFIELD_MAIN].Close(MAX_WIN_HEIGHT, 20);
	// ----
	return;
}



void Interface::DrawTimeCTC()
{

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (pMapNumber != 97) {
		return;
	}
	float CuaSoW = 130.0;
	float CuaSoH = 81.0;

	float StartX = 516.0;
	float StartY = 348.0;
	//RenderBitmap(31566, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);
	pDrawGUI(31650, 412.0f, 342.0f, 227.0f, 87.0f);
	int PhanTramKill;
	if (CTC_MonterYeuCau > 0) {
		PhanTramKill = (CTC_QuaiVatDaKill * 100) / CTC_MonterYeuCau;
		if (PhanTramKill > 100) { PhanTramKill = 100; }
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 5, 0xFF7226FF, 0x0, CuaSoW, 0, 3, "Kill: %d/%d", CTC_QuaiVatDaKill, CTC_MonterYeuCau); //
	}
	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (CTC_TimeConLai > 0)
		{
			CTC_TimeConLai = CTC_TimeConLai - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 35, 0x16FAC1FF, 0x0, CuaSoW, 0, 3, "Time : %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================
	float TyLeTGA = (166.0 * PhanTramKill) / 100;
	if (TyLeTGA > 166.0) { TyLeTGA = 166.0; }
	pDrawGUI(31653, 471.5f, 421.0f, TyLeTGA, 7.0f);


}








void Interface::EventCTCMiniWindow_Main(DWORD Event)
{
}

void Interface::EventCTCMiniWindow(DWORD Event)
{
}

void Interface::SwitchPartySettingsWindowState()
{
	Data[ePARTYSETTINGS_MAIN].OnShow == true ? Data[ePARTYSETTINGS_MAIN].Close() : Data[ePARTYSETTINGS_MAIN].Open();
}

void Interface::DrawPartySettingsWindow()
{
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(ePARTYSETTINGS_MAIN, StartX, StartY + 2);
	this->DrawGUI(ePARTYSETTINGS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(ePARTYSETTINGS_FRAME, StartX, StartY + 67.0, 16);
	this->DrawGUI(ePARTYSETTINGS_FOOTER, StartX, StartY);
	this->DrawGUI(ePARTYSETTINGS_CLOSE, StartX + MainWidth - this->Data[ePARTYSETTINGS_CLOSE].Width + 2, 49);
	// ----
	if (this->IsWorkZone(ePARTYSETTINGS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[ePARTYSETTINGS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(ePARTYSETTINGS_CLOSE, this->Data[ePARTYSETTINGS_CLOSE].X, this->Data[ePARTYSETTINGS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSETTINGS_CLOSE].X + 5, this->Data[ePARTYSETTINGS_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 60, 210, 3, "Party Search Settings");
	///////////////////////////////////////////ACTIVE SYSTEM///////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 33, 200, 1, "Active System");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		this->DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 0);
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 15);
	}
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 40); // Äĺëčňĺëü áîëüřîé
/////////////////////////////////////////ACTIVE SYSTEM END/////////////////////////////////////////

/////////////////////////////////////////////MAX LEVEL/////////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 60, 200, 1, "Max Level");
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 67); // Äĺëčňĺëü áîëüřîé

	/*int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");*/
	this->DrawToolTip(StartX + 174, this->Data[ePARTYSETTINGS_MAIN].Y + 62, "%d", gPartySearchSettings.m_Level);

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); // 
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0); // 

		if (this->IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS))
		{
			if (this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick)
			{
				this->DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); //
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0); //

		if (this->IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS))
		{
			if (this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick)
			{
				this->DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	///////////////////////////////////////////MAX LEVEL END///////////////////////////////////////////

	///////////////////////////////////////////////GUILD///////////////////////////////////////////////

	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 87, 200, 1, "Only Guild");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OnlyGuild == false)
		{
			this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 0);
		}
		else
		{
			this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 15);
		}
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 30);
	}

	pDrawGUI(0x7B5E, StartX + 30, this->Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0); // Äĺëčňĺëü ěĺëęčé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0); // Äĺëčňĺëü ěĺëęčé 2

	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 109, 200, 1, "Only One Class");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OneClass == false)
		{
			this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 0);
		}
		else
		{
			this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 15);
		}
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 30);
	}

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 115);// 94 // Äĺëčňĺëü áîëüřîé
/////////////////////////////////////////////GUILD END/////////////////////////////////////////////
	char szCharNames[8][32] =
	{
		"Dark Wizard",
		"Dard Knight",
		"Elf",
		"Magic Gladiator",
		"Dark Lord",
		"Summoner",
		"Rage Fighter"
		"Grow Lancer"
	};

	int ObjectIDs[8] =
	{
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER,
		ePARTYSETTINGS_GROW_LANCER,


	};

	for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
	{
		this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 135 + (i * 22), 200, 1, szCharNames[i]);

		bool ClassValue = 0;
		switch (i)
		{
		case 0:
			ClassValue = gPartySearchSettings.m_DarkWizard;
			break;
		case 1:
			ClassValue = gPartySearchSettings.m_DarkKnight;
			break;
		case 2:
			ClassValue = gPartySearchSettings.m_Elf;
			break;
		case 3:
			ClassValue = gPartySearchSettings.m_MagicGladiator;
			break;
		case 4:
			ClassValue = gPartySearchSettings.m_DarkLord;
			break;
		case 5:
			ClassValue = gPartySearchSettings.m_Summoner;
			break;
		case 6:
			ClassValue = gPartySearchSettings.m_RageFighter;
			break;
		case 7:
			ClassValue = gPartySearchSettings.m_GrowLancer;
			break;
		}


		if (gPartySearchSettings.m_SystemActive)
		{
			if (ClassValue == false)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 0);
			}
			else
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 15);
			}
		}
		else
		{
			this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 30);
		}

		pDrawGUI(0x7B5E, StartX + 30, this->Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0); // Äĺëčňĺëü ěĺëęčé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0); // Äĺëčňĺëü ěĺëęčé 2
	}

	/*int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");*/

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 290); // Äĺëčňĺëü áîëüřîé

	//if (gPartySearchSettings.m_SystemActive)
	//{
	this->DrawButton(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width / 2 - this->Data[ePARTYSETTINGS_OK].Width / 2, this->Data[ePARTYSETTINGS_MAIN].Y + 310, 0, 0);

	if (this->IsWorkZone(ePARTYSETTINGS_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[ePARTYSETTINGS_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width / 2 - this->Data[ePARTYSETTINGS_OK].Width / 2, this->Data[ePARTYSETTINGS_MAIN].Y + 310, 0, ScaleY);
	}
	//}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventPartySettingsWindow_Main(DWORD Event)
{
	this->EventPartySettingsWindow_Close(Event);
	this->EventPartySettingsWindow_All(Event);
	// ----
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventPartySettingsWindow_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(ePARTYSETTINGS_SYSTEM_ACTIVE))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;

		for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{
			gPartySearchSettings.m_SystemActive == true ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
			//gPartySearchSettings.ChangeClassValue(i);
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level <= 0)
		{
			gPartySearchSettings.m_Level = 0;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level >= 400)
		{
			gPartySearchSettings.m_Level = 400;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_ONLY_GUILD))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}

	if (IsWorkZone(ePARTYSETTINGS_ONE_CLASS))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;

		for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{
			gPartySearchSettings.m_OneClass == false ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
			//gPartySearchSettings.ChangeClassValue(i);
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_OK))
	{
		/*if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}*/

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_OK].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_OK].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->SwitchPartySettingsWindowState();
	}

	int ObjectIDs[8] =
	{
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER,
		ePARTYSETTINGS_GROW_LANCER,
	};

	for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.ChangeClassValue(i);

			if (gPartySearchSettings.m_OneClass == true)
			{
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
	return false;
}

bool Interface::EventPartySettingsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_CLOSE].EventTick);
	// ----
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow || !IsWorkZone(ePARTYSETTINGS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[ePARTYSETTINGS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].EventTick = GetTickCount();
	this->Data[ePARTYSETTINGS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

#if(FACEBOOK)

void Interface::DrawnNapThe()
{
	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eNAPTHE].OnShow)
	{
		this->Data[eNAPTHE].OnShow = false;
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))

	{
		return;
	}

	this->Data[eNAPTHE].OnShow = true;
}

bool Interface::EventDrawnNapThe_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eNAPTHE].EventTick);
	// ----
	if (!this->Data[eNAPTHE].OnShow || !IsWorkZone(eNAPTHE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		//{
		//	pSetCursorFocus = false;
		//}
		this->Data[eNAPTHE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eNAPTHE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eNAPTHE].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		//ShellExecute(NULL, "open", "https://www.facebook.com/hieudaica2020/", NULL, NULL, SW_MAXIMIZE);
		//ShellExecute(NULL, "open", gCustomMessage.GetMessage(166), NULL, NULL, SW_MAXIMIZE);
		//ShellExecute(NULL, "open", gCustomMessage.GetMessage(166), NULL, NULL, SW_SHOW);
		//ShellExecute(0, 0, "http://www.google.com", 0, 0, SW_SHOW);
		

	}
	return false;
}

void Interface::DrawnFacebook()
{
	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eFACEBOOK].OnShow)
	{
		this->Data[eFACEBOOK].OnShow = false;
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}

	this->Data[eFACEBOOK].OnShow = true;
}

bool Interface::EventDrawnFacebook_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eFACEBOOK].EventTick);
	// ----
	if (!this->Data[eFACEBOOK].OnShow || !IsWorkZone(eFACEBOOK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		//{
		//	pSetCursorFocus = false;
		//}
		this->Data[eFACEBOOK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eFACEBOOK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eFACEBOOK].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		//ShellExecute(NULL, "open", "https://www.facebook.com/hieudaica2020/", NULL, NULL, SW_MAXIMIZE);
		//ShellExecute(NULL, "open", gCustomMessage.GetMessage(168), NULL, NULL, SW_MAXIMIZE);
		//ShellExecute(NULL, "open", gCustomMessage.GetMessage(168), NULL, NULL, SW_SHOW);
		
	}

	return false;
}


//void Interface::DrawFanpage()
//{
//	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
//	//{
//	//	return;
//	//}
//
//	if (this->Data[eFANPAGE].OnShow)
//	{
//		this->Data[eFANPAGE].OnShow = false;
//	}
//
//	if (gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::FriendList)
//		|| gInterface.CheckWindow(ObjWindow::MoveList)
//		|| gInterface.CheckWindow(ObjWindow::Party)
//		|| gInterface.CheckWindow(ObjWindow::Quest)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		|| gInterface.CheckWindow(ObjWindow::Guild)
//		|| gInterface.CheckWindow(ObjWindow::Trade)
//		|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		|| gInterface.CheckWindow(ObjWindow::Inventory)
//		|| gInterface.CheckWindow(ObjWindow::Store)
//		|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		|| gInterface.CheckWindow(ObjWindow::HeroList)
//		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		|| gInterface.CheckWindow(ObjWindow::Options)
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
//		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//
//	this->Data[eFANPAGE].OnShow = true;
//}
//
//bool Interface::EventDrawFanpage_Open(DWORD Event)
//{
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[eFANPAGE].EventTick);
//	// ----
//	if (!this->Data[eFANPAGE].OnShow || !IsWorkZone(eFANPAGE))
//	{
//		return false;
//	}
//	// ----
//	if (Event == WM_LBUTTONDOWN)
//	{
//
//		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
//		//{
//		//	pSetCursorFocus = false;
//		//}
//		this->Data[eFANPAGE].OnClick = true;
//		return true;
//	}
//	// ----
//	this->Data[eFANPAGE].OnClick = false;
//	// ----
//	if (Delay < 500)
//	{
//		return false;
//	}
//
//	// ----
//	this->Data[eFANPAGE].EventTick = GetTickCount();
//
//	if (GetForegroundWindow() == pGameWindow)
//	{
//		//ShellExecute(NULL, "open", "https://www.facebook.com/MuOlnine2022", NULL, NULL, SW_MAXIMIZE);
//		ShellExecute(NULL, "open", gCustomMessage.GetMessage(87), NULL, NULL, SW_MAXIMIZE);
//	}
//
//	return false;
//}
//
//void Interface::DrawGoup()
//{
//	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
//	//{
//	//	return;
//	//}
//
//	if (this->Data[eGOUP].OnShow)
//	{
//		this->Data[eGOUP].OnShow = false;
//	}
//
//	if (gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::FriendList)
//		|| gInterface.CheckWindow(ObjWindow::MoveList)
//		|| gInterface.CheckWindow(ObjWindow::Party)
//		|| gInterface.CheckWindow(ObjWindow::Quest)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		|| gInterface.CheckWindow(ObjWindow::Guild)
//		|| gInterface.CheckWindow(ObjWindow::Trade)
//		|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		|| gInterface.CheckWindow(ObjWindow::Inventory)
//		|| gInterface.CheckWindow(ObjWindow::Store)
//		|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		|| gInterface.CheckWindow(ObjWindow::HeroList)
//		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		|| gInterface.CheckWindow(ObjWindow::Options)
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
//		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//
//	this->Data[eGOUP].OnShow = true;
//}
//
//bool Interface::EventDrawGoup_Open(DWORD Event)
//{
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[eGOUP].EventTick);
//	// ----
//	if (!this->Data[eGOUP].OnShow || !IsWorkZone(eGOUP))
//	{
//		return false;
//	}
//	// ----
//	if (Event == WM_LBUTTONDOWN)
//	{
//
//		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
//		//{
//		//	pSetCursorFocus = false;
//		//}
//		this->Data[eGOUP].OnClick = true;
//		return true;
//	}
//	// ----
//	this->Data[eGOUP].OnClick = false;
//	// ----
//	if (Delay < 500)
//	{
//		return false;
//	}
//
//	// ----
//	this->Data[eGOUP].EventTick = GetTickCount();
//
//	if (GetForegroundWindow() == pGameWindow)
//	{
//
//		ShellExecute(NULL, "open", gCustomMessage.GetMessage(88), NULL, NULL, SW_MAXIMIZE);
//		//ShellExecute(NULL, "open", "https://www.facebook.com/groups/843355849734618", NULL, NULL, SW_MAXIMIZE);
//
//	}
//
//	return false;
//}
#endif



void Interface::DrawPartySearchWindow()
{
	if (!this->Data[ePARTYSEARCH_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(ePARTYSEARCH_MAIN, StartX, StartY + 2);
	this->DrawGUI(ePARTYSEARCH_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(ePARTYSEARCH_FRAME, StartX, StartY + 67.0, 16);
	this->DrawGUI(ePARTYSEARCH_FOOTER, StartX, StartY);
	this->DrawGUI(ePARTYSEARCH_CLOSE, StartX + MainWidth - this->Data[ePARTYSEARCH_CLOSE].Width + 2, 49);
	// ----
	if (this->IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[ePARTYSEARCH_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(ePARTYSEARCH_CLOSE, this->Data[ePARTYSEARCH_CLOSE].X, this->Data[ePARTYSEARCH_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSEARCH_CLOSE].X + 5, this->Data[ePARTYSEARCH_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 60, 210, 3, "Party Search");
	// ----
	int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	//int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	//int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");
	// ----
	this->DrawFormat(eWhite, StartX + 20, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "Status:");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		this->DrawFormat(eRed, StartX + 42, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "OFF");
	}
	else
	{
		this->DrawFormat(eShinyGreen, StartX + 42, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	}

	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 40); // Äĺëčňĺëü áîëüřîé
	// ----
	this->DrawFormat(eWhite, StartX + 5, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	// ----
	this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	// ----
	this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	// ----
	this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	// ----
	this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Count");
	// ----
	this->DrawFormat(eWhite, StartX + 170, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Join");
	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 60); // Äĺëčňĺëü áîëüřîé
	// ----
	if (gPartySearch.CountPages > 1)
	{
		this->DrawFormat(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}

	if (gPartySearch.Page + 1 > 1)
	{
		this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}

	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}

	int DrawnItems = 0;

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		pDrawGUI(0x7898, StartX + 10, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);

		this->DrawFormat(eYellow, StartX + 15, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);

		this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, gObjUser.GetMapName(info->Map));

		this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);

		this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);

		this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 5", info->Count);

		pDrawGUI(0x7899, StartX + 178, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20), 22, 19);

		if (info->ButtonActive == true)
		{
			pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}

		int X = StartX + 203;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;

		if (info->ButtonActive == true)
		{
			if (IsWorkZone2(X, Y, MaxX, MaxY))
			{
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
				//pDrawButton(0x7AA4, X, Y,16, 15, 0, 16);
			}
		}

		DrawnItems++;
	}

	DrawnItems = 0;

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		int X = StartX + 178;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;

		if (IsWorkZone2(X, Y, MaxX, MaxY))
		{
			char szText[2048];
			sprintf(szText, "Need to Party:\n_____________________\nLevel:%d", info->Level);

			if (info->DarkWizard == true)
			{
				strcat(szText, "\nDark Wizard");
			}
			if (info->DarkKnight == true)
			{
				strcat(szText, "\nDark Knight");
			}
			if (info->Elf == true)
			{
				strcat(szText, "\nElf");
			}
			if (info->MagicGladiator == true)
			{
				strcat(szText, "\nMagic Gladiator");
			}
			if (info->DarkLord == true)
			{
				strcat(szText, "\nDark Lord");
			}
			if (info->Summoner == true)
			{
				strcat(szText, "\nSummoner");
			}
			if (info->RageFighter == true)
			{
				strcat(szText, "\nRage Fighter");
			}

			if (info->RageFighter == true)
			{
				strcat(szText, "\nGrow Lancer");
			}
			if (info->OnlyGuild == true)
			{
				strcat(szText, "\nOnly Guild");
			}

			strcat(szText, "\n_____________________");

			this->DrawToolTipEx(eWhite, StartX + 230, this->Data[ePARTYSEARCH_MAIN].Y + 62 + (i * 20), 100, 30, 3, szText);
		}

		DrawnItems++;
	}

	if (gPartySearch.Page + 1 > 1)
	{
		if (IsWorkZone(ePARTYSEARCH_LEFT))
		{
			if (this->Data[ePARTYSEARCH_LEFT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		if (IsWorkZone(ePARTYSEARCH_RIGHT))
		{
			if (this->Data[ePARTYSEARCH_RIGHT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}

#if(MAINBETELL==1)
void Interface::MainWindowbetell()
{
	char test[300];
	sprintf_s(test, sizeof(test), "Server:MuOnline || Player: %s || Level: %d || Reset: %d ||  Wc: %d || Wp: %d || Gp: %d || NFT", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
	SetWindowText(pGameWindow, test);

}
#endif

void Interface::EventPartySearchWindow_All(DWORD Event)
{
	float StartX = (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (!this->Data[ePARTYSEARCH_MAIN].OnShow)
	{
		return;
	}

	if (IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->SwitchPartySearchWindowState();
	}
	if (IsWorkZone(ePARTYSEARCH_LEFT) && gPartySearch.Page + 1 > 1)
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_LEFT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page--;
		//gPartySearch.DrawnItems = 0;
	}
	if (IsWorkZone(ePARTYSEARCH_RIGHT) && gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page++;
		//gPartySearch.DrawnItems = 0;
	}

	int DrawnItems = 0;

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}
		//pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82+(i*20),16, 15, 0, 0);
		if (IsWorkZone2(StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), StartX + 203 + 16, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20) + 15))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
			// ----
			if (Delay < 100)
			{
				return;
			}
			// ----
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].ButtonActive == false)
			{
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
			// ----
			gPartySearch.SendPartyRequest(i + (10 * gPartySearch.Page));
			////console.Log("", "Map = %s", pGetMapName(info->Map));
		}
	}
}

#if SKIN
void Interface::SetCursorFocus()
{
	bool focus = false;

	bool focus1 = false;
	bool focus2 = false;

	focus = RentSkin.CheckRect();

	//focus1 = DailyReward.CheckRect();

	//focus2 = ThueFlag.CheckRect();

	if (focus)
	{
		if (!pSetCursorFocus)
		{
			pSetCursorFocus = true;
		}
	}

	if (focus1)
	{
		if (!pSetCursorFocus)
		{
			pSetCursorFocus = true;
		}
	}

	if (focus2)
	{
		if (!pSetCursorFocus)
		{
			pSetCursorFocus = true;
		}
	}
}
#endif

//#if(SWITCH_SERVER==1)
//void Interface::SetCursorFocus() {
//
//	bool focus = false;
//
//	focus = RentSkin.CheckRect();
//
//	if (focus)
//	{
//		if (!pSetCursorFocus)
//		{
//			pSetCursorFocus = true;
//		}
//	}
//}
//bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
//{
//	return false;
//}
//#endif
#if(SLIDE==1)
float VitriX = 15.0;
float VitriY = 420.0;
bool QuayLai = false;
void Interface::DrawTextTTTTTT()
{


	if (!QuayLai && VitriX < 380)
	{
		VitriX++;
	}
	else {
		QuayLai = true;
	}
	if (QuayLai && VitriX >= 100)
	{
		VitriX--;
	}
	else {
		QuayLai = false;
	}
	CustomFont.Draw(CustomFont.FontBold, VitriX, VitriY, 0xFFFAF0FF, 0x0, 0, 15, 3, "Servidor de Qualidade MuNFT");



}
#endif
#if(SLIDE==1)
float VitriXx = 15.0;
float VitriYy = 380.0;
bool QuayLai2 = true;
void Interface::DrawTextTTTTTT2()

{


	if (!QuayLai2 && VitriXx < 500)
	{
		VitriXx++;
	}
	else {
		QuayLai2 = true;
	}
	if (QuayLai2 && VitriXx >= 15)
	{
		VitriXx--;
	}
	else {
		QuayLai2 = false;
	}
	CustomFont.Draw(CustomFont.FontBold, VitriXx, VitriYy, 0xADFF2FFF, 0x0, 0, 20, 3, "Valorize mais"); //



}
#endif

void Interface::SwitchTuChan() {

	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}
	//melo920 revisar
	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	int ShowTuChan = GetPrivateProfileInt("TUCHAN", "OnOff", 1, ".\\Settings.ini");

	if (ShowTuChan != 0)
	{
		ShowTuChan = 0;
		WritePrivateProfileStringA("TUCHAN", "OnOff", " 0", "./Settings.ini");
	}
	else
	{
		ShowTuChan = 1;
		WritePrivateProfileStringA("TUCHAN", "OnOff", " 1", "./Settings.ini");
	}
}

void Interface::DrawMenu()
{
}
#if WINDOWS_QUEST
void Interface::DrawText603(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char* Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}
#endif





