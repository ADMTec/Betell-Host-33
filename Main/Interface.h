#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"

#define MAX_OBJECT 	1000
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480

#define VK_0 	0x30 //	0 key
#define VK_1 	0x31 //	1 key
#define VK_2 	0x32 //	2 key
#define VK_3 	0x33 // 3 key
#define VK_4 	0x34 //	4 key
#define VK_5 	0x35 //	5 key
#define VK_6 	0x36 //	6 key
#define VK_7 	0x37 //	7 key
#define VK_8 	0x38 //	8 key
#define VK_9 	0x39 //	9 key 

#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
#define sub_4DB0C0					((double(__cdecl*)(float a1))0x4DB0C0)
#define resizeGuiRate				1.875
#define resizeGuiScaleRateX			(float)*(DWORD*)MAIN_RESOLUTION_X / 800.0f
#define resizeGuiScaleRateY			(float)*(DWORD*)MAIN_RESOLUTION_Y / 600.0f
#define resizeGuiRateX				resizeGuiRate * resizeGuiScaleRateX
#define resizeGuiRateY				resizeGuiRate * resizeGuiScaleRateY

#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))

enum ObjectID
{
	eFlag01=1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,
	eFPS,
	FPS2,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
	ePrevWare,
	eNextWare,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	//--custom money
	eMoney1,
	eMoney2,
	eMoney3,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,
	eJewelOfBank,
	eJewelOfBankPush,
	eJewelOfBankRemove,
	eJewelOfBankClose,

		


		eMenu_MAINTWO,

		eVAULT_MAIN,
		eCHANGE_RESET_MAIN,
		eLuckyWheelMain,
		eLuckyWheelStart,
		eLuckyWheelPanel,
		eCloseLuckyWheel,
		//Smith
		eSMITH_MAIN,
		eSMITH_MAIN_EX,
		eJEWELBANK_MAIN,
		eMenu_MAIN,
		EXBEXO_MUA_VIP_MAIN,
		EXBEXO_MUA_VIP_CLOSE,
		EXBEXO_MUA_VIP_NANG_CAP,
		EXBEXO_DANH_HIEU_MAIN,
		EXBEXO_DANH_HIEU_CLOSE,
		EXBEXO_DANH_HIEU_NANG_CAP,
		eTUCHAN_MAIN,
		eTUCHAN_TITLE,
		eTUCHAN_FRAME,
		eTUCHAN_FOOTER,
		eTUCHAN_DIV,
		eTUCHAN_CLOSE,
		eTUCHAN_SYSTEM_ACTIVE,
		ePrevEventTC,
		eNextEventTC,
		eTuChanSend,
		eShowTuChan,


		eAUTORESET,
		eATTACK,
		eOFFATTACK,


#if(SLIDE== 1)
		SOLAR_BUTTON_HUONGDAN_MAIN,
		SOLAR_BUTTON_HUONGDAN_CLOSE,
		SOLAR_NEW_MENU_MAIN,
		SOLAR_NAPTHE_MAIN,
		SOLAR_NAPTHE_BUTTON_MAIN,
#endif

#if(LEOTHAP == 1)
		// Leo thap
		eLEOTHAP_MAIN,
		eLEOTHAP_TITLE,
		eLEOTHAP_FRAME,
		eLEOTHAP_FOOTER,
		eLEOTHAP_DIV,
		eLEOTHAP_CLOSE,
		eLEOTHAP_POINT,
		eLEOTHAP_BUTTON_GATE1,
		eLEOTHAP_BUTTON_GATE2,
		eLEOTHAP_BUTTON_GATE3,
		eLEOTHAP_BUTTON_GATE4,
		eLEOTHAP_BUTTON_GATE5,
#endif
		///CustomNotices New ////
	// SERVER NEWS
		eNextNotice,
		ePrevNotice,
		eNotice_MAIN,
		eNotice_TITLE,
		eNotice_FRAME,
		eNotice_FOOTER,
		eNotice_CLOSE,


#if (SELECTCHARACTER==1)
		eSELECTCHAR_LEFT,
		eSELECTCHAR_RIGHT,
#endif

	ePARTYSETTINGS_MAIN,
	ePARTYSETTINGS_TITLE,
	ePARTYSETTINGS_FRAME,
	ePARTYSETTINGS_FOOTER,
	ePARTYSETTINGS_DIV,
	ePARTYSETTINGS_CLOSE,
	ePARTYSETTINGS_SYSTEM_ACTIVE,
	ePARTYSETTINGS_ONLY_GUILD,
	ePARTYSETTINGS_ONE_CLASS,
	ePARTYSETTINGS_DARK_WIZARD,
	ePARTYSETTINGS_DARK_KNIGHT,
	ePARTYSETTINGS_ELF,
	ePARTYSETTINGS_MAGIC_GLADIATOR,
	ePARTYSETTINGS_DARK_LORD,
	ePARTYSETTINGS_SUMMONER,
	ePARTYSETTINGS_RAGE_FIGHTER,
	ePARTYSETTINGS_GROW_LANCER,
	ePARTYSETTINGS_LEVEL_MINUS,
	ePARTYSETTINGS_LEVEL_PLUS,
	ePARTYSETTINGS_OK,
	ePARTYSEARCH_LEFT,
	ePARTYSEARCH_RIGHT,

	ePARTYSEARCH_MAIN,
	ePARTYSEARCH_TITLE,
	ePARTYSEARCH_FRAME,
	ePARTYSEARCH_FOOTER,
	ePARTYSEARCH_DIV,
	ePARTYSEARCH_CLOSE,

	eSTATSADD_MAIN,
	eSTATSADD_TITLE,
	eSTATSADD_FRAME,
	eSTATSADD_FOOTER,
	eSTATSADD_CLOSE,
	eSTATSADD_TEXTBOX01,
	eSTATSADD_STATBOX01,
	eSTATSADD_STATBOX02,
	eSTATSADD_STATBOX03,
	eSTATSADD_STATBOX04,
	eSTATSADD_STATBOX05,
	eSTATSADD_BTN_OK,
	eRESETSTATS_MAIN,
	eRESETSTATS_TITLE,
	eRESETSTATS_FRAME,
	eRESETSTATS_FOOTER,
	eRESETSTATS_CLOSE,
	eRESETSTATS_POINT,
	eRESETSTATS_CHECK_WC,
	eRESETSTATS_CHECK_STAT,
	eRESETMASTER_CHECK_WC,
	eRESETMASTER_CHECK_STAT,
	eRESETSTATS_BTN_OK,
	eCHARINFO_BTN_STAT,
	eCHARINFO_BTN_RESSTAT,


#if(BOTOES_FUNCOES)
	EXBEXO_AUTORESET_INTERFACE,
	EXBEXO_QUESTCLASS_INTERFACE,
	EXBEXO_OFFATTACK_INTERFACE,
	EXBEXO_UYTHAC_INTERFACE,
	EXBEXO_TAYDIEM_INTERFACE,
	EXBEXO_TAYDIEMMASTER_INTERFACE,
#endif



	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,

	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,
    OPEN_QUEST,

	eARROW_RIGHT2,
	eARROW_LEFT2,
	eEVENTTABLE_MAIN,
	eEVENTTABLE_TITLE,
	eEVENTTABLE_LEFT,
	eEVENTTABLE_RIGHT,
	eEVENTTABLE_FOOTER,
	eEVENTTABLE_DIV,
	eEVENTTABLE_CLOSE,


    eMenu_CUSTOM_VIP,

	eFruitMain,
	eFruitClose,

	ePT_PERSONAL_SEARCH_MAIN,
	ePT_PERSONAL_SEARCH_TITLE,
	ePT_PERSONAL_SEARCH_FRAME,
	ePT_PERSONAL_SEARCH_FOOTER,
	ePT_PERSONAL_SEARCH_DIV,
	ePT_PERSONAL_SEARCH_CLOSE,
	ePT_PERSONAL_SEARCH_L,
	ePT_PERSONAL_SEARCH_R,
	ePT_PERSONAL_SEARCH_PAGEUP1,
	ePT_PERSONAL_SEARCH_PAGEUP2,
	ePT_PERSONAL_SEARCH_PAGEUP3,
	ePT_PERSONAL_SEARCH_PAGEUP4,
	ePT_PERSONAL_SEARCH_PAGEUP5,
	ePT_PERSONAL_SEARCH_PAGEUP6,
	ePT_PERSONAL_SEARCH_PAGEUP7,
	ePT_PERSONAL_SEARCH_PAGEUP8,
	ePT_PERSONAL_SEARCH_PAGEUP9,
	ePT_PERSONAL_SEARCH_PAGEUP10,

	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,
	eCHANGINGCLASS_GL,

	eRESET_MAIN,
	eRESET_TITLE,
	eRESET_FRAME,
	eRESET_FOOTER,
	eRESET_DIV,
	eRESET_INFOBG,
	eRESET_MONEYBG,
	eRESET_CLOSE,
	eRESET_FINISH,

	eGRESET_MAIN,
	eGRESET_TITLE,
	eGRESET_FRAME,
	eGRESET_FOOTER,
	eGRESET_DIV,
	eGRESET_INFOBG,
	eGRESET_MONEYBG,
	eGRESET_CLOSE,
	eGRESET_FINISH,

		eWAREHOUSE,
		eWAREHOUSE1,
		eWAREHOUSE_MAIN,
		eWAREHOUSE_TITLE,
		eWAREHOUSE_FRAME,
		eWAREHOUSE_FOOTER,
		eWAREHOUSE_DIV,
		eWAREHOUSE_CLOSE,
		eWAREHOUSE_NUM1,
		eWAREHOUSE_NUM2,
		eWAREHOUSE_NUM3,
		eWAREHOUSE_NUM4,
		eWAREHOUSE_NUM5,
		eWAREHOUSE_NUM6,
		eWAREHOUSE_NUM7,
		eWAREHOUSE_NUM8,
		eWAREHOUSE_NUM9,
		eWAREHOUSE_NUM10,
		eWAREHOUSE_NUM11,
		eWAREHOUSE_NUM12,
		eWAREHOUSE_NUM13,
		eWAREHOUSE_NUM14,
		eWAREHOUSE_NUM15,
		eWAREHOUSE_NUM16,
		eWAREHOUSE_NUM17,
		eWAREHOUSE_NUM18,
		eWAREHOUSE_NUM19,
		eWAREHOUSE_NUM20,
		eWAREHOUSE_NUM21,
		eWAREHOUSE_NUM22,
		eWAREHOUSE_NUM23,
		eWAREHOUSE_NUM24,
		eWAREHOUSE_NUM25,
		eWAREHOUSE_NUM26,
		eWAREHOUSE_NUM27,
		eWAREHOUSE_NUM28,
		eWAREHOUSE_NUM29,
		eWAREHOUSE_NUM30,
		eWAREHOUSE_NUM31,
		eWAREHOUSE_NUM32,
		eWAREHOUSE_NUM33,
		eWAREHOUSE_NUM34,
		eWAREHOUSE_NUM35,
		eWAREHOUSE_NUM36,
		eWAREHOUSE_NUM37,
		eWAREHOUSE_NUM38,
		eWAREHOUSE_NUM39,
		eWAREHOUSE_NUM40,
		eWAREHOUSE_NUM41,
		eWAREHOUSE_NUM42,
		eWAREHOUSE_NUM43,
		eWAREHOUSE_NUM44,
		eWAREHOUSE_NUM45,
		eWAREHOUSE_NUM46,
		eWAREHOUSE_NUM47,
		eWAREHOUSE_NUM48,
		eWAREHOUSE_NUM49,
		eWAREHOUSE_NUM50,
		eWAREHOUSE_NUM51,
		eWAREHOUSE_NUM52,
		eWAREHOUSE_NUM53,
		eWAREHOUSE_NUM54,
		eWAREHOUSE_NUM55,
		eWAREHOUSE_NUM56,
		eWAREHOUSE_NUM57,
		eWAREHOUSE_NUM58,
		eWAREHOUSE_NUM59,
		eWAREHOUSE_NUM60,
		eWAREHOUSE_NUM61,
		eWAREHOUSE_NUM62,
		eWAREHOUSE_NUM63,
		eWAREHOUSE_NUM64,
		eWAREHOUSE_NUM65,
		eWAREHOUSE_NUM66,
		eWAREHOUSE_NUM67,
		eWAREHOUSE_NUM68,
		eWAREHOUSE_NUM69,
		eWAREHOUSE_NUM70,
		eWAREHOUSE_NUM71,
		eWAREHOUSE_NUM72,
		eWAREHOUSE_NUM73,
		eWAREHOUSE_NUM74,
		eWAREHOUSE_NUM75,
		eWAREHOUSE_NUM76,
		eWAREHOUSE_NUM77,
		eWAREHOUSE_NUM78,
		eWAREHOUSE_NUM79,
		eWAREHOUSE_NUM80,
		eWAREHOUSE_NUM81,
		eWAREHOUSE_NUM82,
		eWAREHOUSE_NUM83,
		eWAREHOUSE_NUM84,
		eWAREHOUSE_NUM85,
		eWAREHOUSE_NUM86,
		eWAREHOUSE_NUM87,
		eWAREHOUSE_NUM88,
		eWAREHOUSE_NUM89,
		eWAREHOUSE_NUM90,
		eWAREHOUSE_NUM91,
		eWAREHOUSE_NUM92,
		eWAREHOUSE_NUM93,
		eWAREHOUSE_NUM94,
		eWAREHOUSE_NUM95,
		eWAREHOUSE_NUM96,
		eWAREHOUSE_NUM97,
		eWAREHOUSE_NUM98,
		eWAREHOUSE_NUM99,
		eWAREHOUSE_NUM100,
		eWAREHOUSE_NUM101,
		eWAREHOUSE_NUM102,
		eWAREHOUSE_NUM103,
		eWAREHOUSE_NUM104,
		eWAREHOUSE_NUM105,
		eWAREHOUSE_NUM106,
		eWAREHOUSE_NUM107,
		eWAREHOUSE_NUM108,
		eWAREHOUSE_NUM109,
		eWAREHOUSE_NUM110,
		eWAREHOUSE_NUM111,
		eWAREHOUSE_NUM112,
		eWAREHOUSE_NUM113,
		eWAREHOUSE_NUM114,
		eWAREHOUSE_NUM115,
		eWAREHOUSE_NUM116,
		eWAREHOUSE_NUM117,
		eWAREHOUSE_NUM118,
		eWAREHOUSE_NUM119,
		eWAREHOUSE_NUM120,
		eWAREHOUSE_NUM121,
		eWAREHOUSE_NUM122,
		eWAREHOUSE_NUM123,
		eWAREHOUSE_NUM124,
		eWAREHOUSE_NUM125,
		eWAREHOUSE_NUM126,
		eWAREHOUSE_NUM127,
		eWAREHOUSE_NUM128,
		eWAREHOUSE_NUM129,
		eWAREHOUSE_NUM130,
		eWAREHOUSE_NUM131,
		eWAREHOUSE_NUM132,
		eWAREHOUSE_NUM133,
		eWAREHOUSE_NUM134,
		eWAREHOUSE_NUM135,
		eWAREHOUSE_NUM136,
		eWAREHOUSE_NUM137,
		eWAREHOUSE_NUM138,
		eWAREHOUSE_NUM139,
		eWAREHOUSE_NUM140,
		eWAREHOUSE_NUM141,
		eWAREHOUSE_NUM142,
		eWAREHOUSE_NUM143,
		eWAREHOUSE_NUM144,
		eWAREHOUSE_NUM145,
		eWAREHOUSE_NUM146,
		eWAREHOUSE_NUM147,
		eWAREHOUSE_NUM148,
		eWAREHOUSE_NUM149,
		eWAREHOUSE_NUM150,
		eWAREHOUSE_NUM151,
		eWAREHOUSE_NUM152,
		eWAREHOUSE_NUM153,
		eWAREHOUSE_NUM154,
		eWAREHOUSE_NUM155,
		eWAREHOUSE_NUM156,
		eWAREHOUSE_NUM157,
		eWAREHOUSE_NUM158,
		eWAREHOUSE_NUM159,
		eWAREHOUSE_NUM160,

	// ----
	eSETTINGS_MAIN,
	eSETTINGS_TITLE,
	eSETTINGS_FRAME,
	eSETTINGS_FOOTER,
	eSETTINGS_DIV,
	eSETTINGS_CLOSE,
	eSETTINGS_OPTION,
	eSETTINGS_LINE,
	eSETTINGS_CHECKBOX1,
	eSETTINGS_CHECKBOX2,
	eSETTINGS_CHECKBOX3,
	eSETTINGS_CHECKBOX4,
	eSETTINGS_CHECKBOX5,
	eSETTINGS_CHECKBOX6,
	eSETTINGS_CHECKBOX7,
	eSETTINGS_CHECKBOX8,
	eSETTINGS_CHECKBOX9,
	eSETTINGS_CHECKBOX10,
	eSETTINGS_CHECKBOX11,
	eSETTINGS_CHECKBOX12,

	eARROW_RIGHT,
	eARROW_LEFT,

	eMenuBackground,

	eCameraStart,
	eCameraRestore,
	eUserPanelButton,

	// ----
	eSMITHY_MAIN,
	eSMITHY_TITLE,
	eSMITHY_FRAME,
	eSMITHY_FOOTER,
	eSMITHY_DIV,
	eSMITHY_DIV2,
	eSMITHY_INFOBG,
	eSMITHY_CLOSE,
	eSMITHY_BACK,
	eSMITHY_TEXT,
	eSMITHY_TEXT2,
	eSMITHY_TEXT3,
	eSMITHY_TEXT4,
	eSMITHY_TEXT5,
	eSMITHY_TEXT6,
	eSMITHY_TEXT7,
	eSMITHY_TEXT8,
	eSMITHY_TEXT9,
	eSMITHY_TEXT10,
	eSMITHY_L,
	eSMITHY_R,
	eSMITHY_INFOBG2,
	eSMITHY_INFOBG3,
	eSMITHY_LINE,
	eSMITHY_POINT,
	eSMITHY_CHECK0,
	eSMITHY_CHECK1,
	eSMITHY_CHECK2,
	eSMITHY_CHECK3,
	eSMITHY_CHECK4,
	eSMITHY_CHECK5,
	eSMITHY_CHECK6,
	eSMITHY_CHECK7,
	eSMITHY_PAGEUP,
	eSMITHY_PAGEDN,
	eSMITHY_BT1,
	eSMITHY_BT2,
	eSMITHY_PAGEUP2,
	eSMITHY_PAGEDN2,
	eSMITHY_PAGEUP3,
	eSMITHY_PAGEDN3,
	eSMITHY_CHECKWIN_MAIN,
	eSMITHY_CHECKWIN_TITLE,
	eSMITHY_CHECKWIN_FRAME,
	eSMITHY_CHECKWIN_FOOTER,
	eSMITHY_CHECKWIN_DIV,
	eSMITHY_CHECKWIN_OK,
	eSMITHY_CHECKWIN_CLOSE,
	// --
	eNPC_BUFF_MAIN,
	eNPC_BUFF_TITLE,
	eNPC_BUFF_FRAME,
	eNPC_BUFF_FOOTER,
	eNPC_BUFF_DIV,
	eNPC_BUFF_CLOSE,
	eNPC_BUFF_LINE,
	eNPC_BUFF_BT1,
	eNPC_BUFF_BT2,
	eNPC_BUFF_BT3,
	eNPC_BUFF_BT4,
	eNPC_BUFF_BT5,
	eNPC_BUFF_BT6,
	eNPC_BUFF_BT7,
	exWinNPCBuffer,

#if(CUSTOM_MAP_TELEPORT)
	eMAPTELEPORT_MAIN,
	eMAPTELEPORT_TEST,

	eMAPTELEPORT_POINT1,
	eMAPTELEPORT_POINT2,
	eMAPTELEPORT_POINT3,
	eMAPTELEPORT_POINT4,
	eMAPTELEPORT_POINT5,
	eMAPTELEPORT_POINT6,
	eMAPTELEPORT_POINT7,
	eMAPTELEPORT_POINT8,
	eMAPTELEPORT_POINT9,
	eMAPTELEPORT_POINT10,

	eMAPTELEPORT_POINT11,
	eMAPTELEPORT_POINT12,
	eMAPTELEPORT_POINT13,
	eMAPTELEPORT_POINT14,
	eMAPTELEPORT_POINT15,
	eMAPTELEPORT_POINT16,
	eMAPTELEPORT_POINT17,
	eMAPTELEPORT_POINT18,
	eMAPTELEPORT_POINT19,
	eMAPTELEPORT_POINT20,

	eMAPTELEPORT_POINT21,
	eMAPTELEPORT_POINT22,
	eMAPTELEPORT_POINT23,
	eMAPTELEPORT_POINT24,
	eMAPTELEPORT_POINT25,
	eMAPTELEPORT_POINT26,
	eMAPTELEPORT_POINT27,
	eMAPTELEPORT_POINT28,
	eMAPTELEPORT_POINT29,
	eMAPTELEPORT_POINT30,

	eMAPTELEPORT_POINT31,
	eMAPTELEPORT_POINT32,
	eMAPTELEPORT_POINT33,
	eMAPTELEPORT_POINT34,
	eMAPTELEPORT_POINT35,
	eMAPTELEPORT_POINT36,
	eMAPTELEPORT_POINT37,
	eMAPTELEPORT_POINT38,
	eMAPTELEPORT_POINT39,
	eMAPTELEPORT_POINT40,
	exWinMapTeleport,

	ex_MAPTELEPORT_MAIN,
	ex_MAPTELEPORT_TEST,
	eINVENTORY_FOOTER,
	eINVENTORY_BORDER,
	eINVENTORY_ITEMBOX,
	eINVENTORY_USEBOX,
#endif

	ex_EXTELEPORT_TITLE,
	eTELEPORT_MAIN,
	eTELEPORT_TITLE,
	eTELEPORT_FRAME,
	eTELEPORT_FOOTER,
	eTELEPORT_DIV,
	eTELEPORT_CLOSE,
	eTELEPORT_LINE,
	eTELEPORT_POINT,

	eTELEPORT_BT1,
	eTELEPORT_BT2,
	eTELEPORT_BT3,
	eTELEPORT_BT4,
	eTELEPORT_BT5,
	eTELEPORT_BT6,
	eTELEPORT_BT7,
	eTELEPORT_BT8,
	eTELEPORT_BT9,
	eTELEPORT_BT10,

	eTELEPORT_BT_CANCELE,
	eTELEPORT_PAGEUP1,
	eTELEPORT_PAGEUP2,
	eTELEPORT_PAGEUP3,
	eTELEPORT_PAGEUP4,
	eTELEPORT_PAGEUP5,
	eTELEPORT_PAGEUP6,
	eTELEPORT_PAGEUP7,
	eTELEPORT_PAGEUP8,
	eTELEPORT_PAGEUP9,
	eTELEPORT_PAGEUP10,
	eTELEPORT_MAPNAME,
	eTELEPORT_INFOBG,
	exWinTeleportEvo,

	ePKCLEAR_MAIN,
	ePKCLEAR_TITLE,
	ePKCLEAR_FRAME,
	ePKCLEAR_FOOTER,
	ePKCLEAR_DIV,
	ePKCLEAR_OK,
	ePKCLEAR_CLOSE,
	exWinPKClear,

	eLuckySpin,
	eLuckySpinRoll,
	eLuckySpinClose,

	eJewelBank_MAIN,
	eJewelBank_TITLE,
	eJewelBank_FRAME,
	eJewelBank_FOOTER,
	eJewelBank_DIV,
	eJewelBank_CLOSE,
	eJewelBank_NEXT,
	eJewelBank_PREV,

	eCONFIRM_MUUN,
    eCONFIRM_MUUNBTN_OK,
    eCONFIRM_MUUNBTN_CANCEL,

	// --
	eMARKET_MAIN,
	eMARKET_TITLE, 
	eMARKET_FRAME,
	eMARKET_FOOTER,
	eMARKET_DIV,
	eMARKET_OK,
	eMARKET_CLOSE,
	eMARKET_INFOBG,
	eMARKET_INFOBG2,
	eMARKET_INFOBG3,
	eMARKET_SCROLL,
	eMARKET_BUY,

	eMARKET_PRICE_MAIN,
	eMARKET_PRICE_TITLE, 
	eMARKET_PRICE_FRAME,
	eMARKET_PRICE_FOOTER,
	eMARKET_PRICE_OK,
	eMARKET_PRICE_CLOSE,
	eMARKET_PRICE_INFOBG,
	eMARKET_PRICE_CHECK1,
	eMARKET_PRICE_CHECK2,
	eMARKET_PRICE_CHECK3,
	eMARKET_PRICE_POINT, 
	eMARKET_PRICE_LINE,

	eMARKET_FILTER_MAIN,
	eMARKET_FILTER_TITLE, 
	eMARKET_FILTER_FRAME,
	eMARKET_FILTER_FOOTER,
	eMARKET_FILTER_POINT, 
	eMARKET_FILTER_PAGEUP, 
	eMARKET_FILTER_PAGEDN, 
	eMARKET_FILTER_LINE,
	eMARKET_FILTER_CHECK1,
	eMARKET_FILTER_CHECK2,
	eMARKET_FILTER_CHECK3,
	eMARKET_FILTER_CHECK4,
	eMARKET_FILTER_CHECK5,
	eMARKET_FILTER_CHECK6,
	eMARKET_FILTER_NAME,
	eMARKET_FILTER_CAATEGORY,
	eMARKET_FILTER_DIV,

	eMARKET_ITEM_MAIN,
	eMARKET_ITEM_TITLE,
	eMARKET_ITEM_FRAME,
	eMARKET_ITEM_FOOTER,
	eMARKET_ITEM_BG,
	eMARKET_ITEM_OK,
	eMARKET_ITEM_CLOSE,

	eMARKET_L,
	eMARKET_R,

	eMQUEST_MAIN,
	eMQUEST_TITLE,
	eMQUEST_FRAME,
	eMQUEST_FOOTER,
	eMQUEST_DIV,
	eMQUEST_CLOSE,
	eMQUEST_INFOBG,
	eMQUEST_INFOBG2,
	eMQUEST_MONEYBG,
	eMQUEST_FINISH,
	eMQUEST_COUNT,

	////////////////////////
	eCTCMiniWindow,
	eOTHERCHAR_POINT,
	eCHAR_POINT,
	/////////////////////
	eTimeCTC,
	eCuaSoCTC,
	////////////////////
	///
	///
	eUSERPANEL_MAIN,
	eUSERPANEL_TITLE,
	eUSERPANEL_LEFT,
	eUSERPANEL_RIGHT,
	eUSERPANEL_FOOTER,
	eUSERPANEL_DIV,
	eUSERPANEL_CLOSE,

	eCTC_MINI_MAIN,
	eCTC_MINI_TITLE,
	eCTC_MINI_FRAME,
	eCTC_MINI_FOOTER,
	eCTC_MINI_DIV,
	eCTC_MINI_CLOSE,

	eBATTLEFIELD_MAIN,
	eBATTLEFIELD_TITLE,
	eBATTLEFIELD_FRAME,
	eBATTLEFIELD_FOOTER,
	eBATTLEFIELD_DIV,
	eBATTLEFIELD_CLOSE,
	
	eMenu,
	eMenuBG,

	iNewuiDialogHr = 0x9308,
	iGfxDialoge = 0x9309,
	iGfxDialoge2 = 0x9310,
	iGfxBtnSmall2 = 0x788E,

#if(FACEBOOK)
	eNAPTHE,
	eFACEBOOK,
	eFANPAGE,
	eGOUP,
#endif



	eJewelBank_WITHDRAW,
};

struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	char	StatValue[20];
	bool	FirstLoad;
	bool	ByClose;
	BYTE	Speed;
	long	OpenedValue;

	void Open()
	{
		this->OnShow = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; 
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; 
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}
};

enum ObjWindowsEx
{
	exWinItemMarket,
	exWinItemMarketPrice,
};

void NewModelRender3D(float x, float y, float Width, float Height, int ItemID, int Level = 0, int Excl = 0, int Anc = 0, bool OnMouse = 0);

class Interface
{
public:
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	int Page;
	int Count;
	InterfaceElement Data[MAX_OBJECT];
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	static void LoadImages();
	static void LoadModels();
	static void Work();
	void        WindowsKG();
	static void CLoadBitmap(char* Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6);
	
#if(SLIDE == 1)
	void DrawTextTTTTTT();
	void DrawTextTTTTTT2();
#endif

//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
	void CloseMenuWindowTwo() { this->Data[eMenu_MAINTWO].OnShow = false; };
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	void ResetDrawIMG2(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone(short ObjectID);
	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	//-- Party Bar ex700
	void		BarPartyNew();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();
	bool QuayLai;
	bool QuayLai2;

	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	void		DrawWarehouseUI();
	void		EventWarehouseUI(DWORD Event);

#if(BOTOES_FUNCOES)
	void		DRAW_TINHNANG_INTERFACE();
	bool		EVENT_TINHNANG_INTERFACE(DWORD Event);
	bool		EVENT_AUTORESET_INTERFACE(DWORD Event);
	bool		EVENT_LAMNHIEMVU_INTERFACE(DWORD Event);
	bool		EVENT_OFFATTACK_INTERFACE(DWORD Event);
	bool		EVENT_UYTHAC_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event);
#endif

#if(FACEBOOK)
	void DarwinNapThe();
	void DarwinFacebook();
	//void DrawFanpage();
	//void DrawGoup();

	bool		EventoDrewNapThe_Open(DWORD Event);
	bool		EventoDarwinFacebook_Open(DWORD Event);
	//bool		EventDrawFanpage_Open(DWORD Event);
	//bool		EventDrawGoup_Open(DWORD Event);
#endif


	bool IsWorkZone4(float X, float Y, float MaxX, float MaxY);

	void DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	int DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);

	void		DrawStatsAddWindow();
	void		EventStatsAddWindow(DWORD Event);
	void		EventStatsAddWindow_Close(DWORD Event);
	void		SwitchStatsWindowState() { (Data[eSTATSADD_MAIN].OnShow == true) ? Data[eSTATSADD_MAIN].CloseAnimated(15) : Data[eSTATSADD_MAIN].Open(-226, 20); };
	void		CloseStatsAddWindow() { this->Data[eSTATSADD_MAIN].OnShow = false; };
	//
	void		DrawResetStatsWindow();
	void		EventResetStatsWindow(DWORD Event);
	void		EventResetStatsWindow_Close(DWORD Event);
	void		SwitchResetStatsWindowState() { (Data[eRESETSTATS_MAIN].OnShow == true) ? Data[eRESETSTATS_MAIN].Close() : Data[eRESETSTATS_MAIN].Open(); };
	void		CloseResetStatsWindow() { this->Data[eRESETSTATS_MAIN].OnShow = false; };
	void		EventCharacterWindow(DWORD Event);
	void	DrawAnimatedGUI(short ObjectID, float PosX, float PosY);
	void	DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color);
	void	DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	void	TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...);

	void		DrawEventTableWindow();
	void		EventEventTableWindow(DWORD Event);
	void		CloseEventTableWindow() { this->Data[eEVENTTABLE_MAIN].OnShow = false; };
	
	bool		CursorZoneButton(float X, float Y, float MaxX, float MaxY);

	void		DrawFruit();
	void		EventFruitWindow_Main(DWORD Event);
	void		Fruit_State(){ (Data[eFruitMain].OnShow == true) ? Data[eFruitMain].Close() : Data[eFruitMain].Open(); };
	void		CloseFruitWindow() { this->Data[eFruitMain].OnShow = false; };

	bool		CheckWindow(int WindowID);
	int			CloseWindow(int WindowID);
	int			OpenWindow(int WindowID);
	bool		CheckWindowEx(int WindowID);
	void		OpenWindowEx(int WindowID);
	void		CloseWindowEx(int WindowID);
	//
	void		DrawChangingClassWindow();
	void		ChangingClassWindowState(){ (Data[eCHANGINGCLASS_MAIN].OnShow == true) ? Data[eCHANGINGCLASS_MAIN].Close() : Data[eCHANGINGCLASS_MAIN].Open(); };
	void		EventChangingClassWindow_Main(DWORD Event);
	void		CloseChangingClassWindow() { this->Data[eCHANGINGCLASS_MAIN].OnShow = false; };
	// ----
	void		DrawResetWindow();
	bool		EventResetWindow_Main(DWORD Event);
	bool		EventResetWindow_Close(DWORD Event);
	bool		EventResetWindow_Finish(DWORD Event);
	// ----
	// ----
	void		DrawGrandResetWindow();
	void		EventGrandResetWindow_Main(DWORD Event);
	void		EventGrandResetWindow_Close(DWORD Event);
	void		EventGrandResetWindow_Finish(DWORD Event);
	// ----
	// ----
	void		DrawWarehouseWindow();
	void		EventWarehouseWindow_Main(DWORD Event);
	void		EventWarehouseWindow_Close(DWORD Event);
	// ----
	void		DrawSettingsUI();
	void		EventSettingsUI(DWORD Event);
	void		SwitchSettingsWindowState() { (Data[eSETTINGS_MAIN].OnShow == true) ? Data[eSETTINGS_MAIN].Close() : Data[eSETTINGS_MAIN].Open(); };

	void		DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 1024, float SourceH = 512, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	void		DrawWindowBG(float, float);
	//-- Minimizar MiniMapa
	void		MiniMapMini();
	//-- Mover MiniMapa
	bool		IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5);
	//Smithy
	void		DrawCheckLineEx(bool isChecked, int PointID, int CheckID, int LineID, float X, float Y, DWORD Color, char* Text);
	void		PartUPandDNEx(int PointID, int UpID, int DownID, int LineID, float X, float Y, DWORD Color, int Value, char* Text);
	void		MiniButtonDraw(int BtnID, float X, float Y, bool isHover, char* Text);
	bool		ButtonEx2(DWORD Event, int ButtonID, bool Type);

	void		DrawButtonMini(int id, int X, int Y, int res, char* Text);
	void		DrawPrice(int X, int Y, int iZen, int iChaos, int iBless, int iSoul, int iLife, int iBonus, int iCredit);
	void		DrawFormatEx(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	int			DrawFormat_Ex(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);

	void		DrawGUI2(short ObjectID);
	void        DrawGU1(short ObjectID, float PosX, float PosY);
	short		m_iDrawObjectID;
	void		DrawColoredGUI2(short ObjectID, DWORD Color);

	void		DrawButtonBig(int ObjID, bool bActive, float fX, float fY, char* Text);
	float		RightMiniInfoY;
	bool		IsWorkZone3(short ObjectID);
	void		DrawColorGUI(int MainID, int X, int Y, int Width, int Height, DWORD Color);
	void		DrawItem1(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void DrawItemToolTipText ( void * item, int x, int y );
	void		KeyBoxEvent(DWORD Event, char* kText, int MaxText);
	bool		ButtonExR(DWORD Event, int ButtonID, bool Type);
	//////CTCmini//////////
	void		DrawCTCMiNiMap();
	void		DrawCTCMiniWindow();
	void		DrawChienTruongCo();
	void		DrawTimeCTC();
	void		EventCTCMiniWindow_Main(DWORD Event);
	void		EventCTCMiniWindow(DWORD Event);
	void		EventCTCMiniWindow_Close(DWORD Event);
	void		SwitchCTCMiniWindowState() { (Data[eCTC_MINI_MAIN].OnShow == true) ? Data[eCTC_MINI_MAIN].Close() : Data[eCTC_MINI_MAIN].Open(); };
	void		EventBattlefieldWindow_Main(DWORD Event);
	void		EventBattlefieldWindow(DWORD Event);
	void		EventBattlefieldWindow_Close(DWORD Event);
	void		SwitchBattlefieldWindowState() { (Data[eBATTLEFIELD_MAIN].OnShow == true) ? Data[eBATTLEFIELD_MAIN].Close() : Data[eBATTLEFIELD_MAIN].Open(); };

	void		DrawPartySettingsWindow();
	void		SwitchPartySettingsWindowState();
	bool		EventPartySettingsWindow_Main(DWORD Event);
	bool  		EventPartySettingsWindow_Close(DWORD Event);
	void        DrawnNapThe();

	bool EventDrawnNapThe_Open(DWORD Event);

	void DrawnFacebook();

	bool EventDrawnFacebook_Open(DWORD Event);
	
	bool		EventPartySettingsWindow_All(DWORD Event);
	// ----
	void		DrawPartySearchWindow();
	void		SwitchPartySearchWindowState() {(Data[ePARTYSEARCH_MAIN].OnShow == true)? Data[ePARTYSEARCH_MAIN].Close():Data[ePARTYSEARCH_MAIN].Open();};
	void		EventPartySearchWindow_All(DWORD Event);
	#if (SWITCH_SERVER==1)
	void		OpenMenuWindow() { this->Data[eMenu].OnShow = true;};// pSetCursorFocus = true; };
	void CloseMenuWindow() {this->Data[eMenu].OnShow = false; };
	bool CheckMenuWindow() { return this->Data[eMenu].OnShow; };
	void		SetCursorFocus();
	bool IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false); //ZEUS UP19 NEW NOTICIAS
	void SwitchFenrir();    //ZEUS UP19 NEW NOTICIAS
	bool WareNext(DWORD Event);
	bool WarePrev(DWORD Event);

	void		OpenVaultWindow() { this->Data[eVAULT_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CloseVaultWindow() { this->Data[eVAULT_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CheckVaultWindow() { return this->Data[eVAULT_MAIN].OnShow; };
	#if WINDOWS_QUEST
	void        DrawText603(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void NewModelRender3D(float x, float y, float Width, float Height, int ItemID, int Level = 0, int Excl = 0, int Anc = 0, bool OnMouse = 0);


	
	


#endif
	void SwitchTuChan();
	void DrawMenu();
	
#endif
#if(MAINBETELL==1)
	void        MainWindowbetell();
#endif
	//////////////
	// ----
	BYTE m_SettingButton;
	BYTE m_RolltheDiceButton;
	BYTE m_HeadsTailsButton;
	BYTE m_LuckyNumberButton;
	BYTE m_SmithItemButton;
	BYTE m_TitleManagerButton;
	BYTE m_PartySearchSettingButton;
	BYTE m_OffAttackButton;
	BYTE m_BuyVipButton;
	BYTE m_ChangeClassButton;
	BYTE m_ResetPointCheckBox;
	BYTE m_ResetPointCheckBox1;
	BYTE m_ResetMasterSkillCheckBox;
	BYTE m_ResetMasterSkillCheckBox1;
	BYTE m_AccountSecurityButton;
	BYTE m_JewelsBankButton;
	BYTE m_RenameButton;
	BYTE m_TopPlayer;
	BYTE m_PShopCurrency;
	BYTE m_PShopOffStore;
	BYTE m_RPSMode;
	BYTE m_NewsBoard;
	BYTE m_FruitMain;
	BYTE m_LuckySpinMain;
	BYTE m_GiftCode;
	BYTE m_PSBless;
	BYTE m_PSSoul;
	BYTE m_PSChaos;
	BYTE m_PSWcoinC;
	BYTE m_PSWcoinP;
	BYTE m_PSWcoinG;
	BYTE m_QuickAdd;
	BYTE m_ResetStats;
	BYTE m_EventTimer;
	BYTE m_CustomWare;
	BYTE m_PartyLeader;
	BYTE m_PartyTrace;

	long long m_TimeDiff;
	
	//--
private:
	
};
extern Interface gInterface;
