#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "User.h"
//--
#include "InterEx.h"
#include "SelectChar.h"
#include "postInterface.h"
#include "StatsAdvance.h"
#include "CustomBow.h"
#include "CustomGloves.h"
#include "CustomPet.h"
#include "Pet.h"
#include "PetHook.h"
#include "CustomCloak.h"
#include "cape.h"
#include "ItemTRSData.h"
#include "CustomEffectRemake.h"
#include "ItemRemake.h"
#include "ItemManager.h"
#include "ItemInfoEx.h"
#include "CSCharacterS13.h"
#include "CNewUIScene.h"
#include "CScene97.h"
#include "SCharacterS4.h"
#include "CSceneS2.h"
#include "SCharacterS8.h"
#include "CustomItemPrice.h"
#include "MonsterGlow.h"
#include "CustomMonsterGlow.h"
#include "ModelEffect.h"
#include "CChatEx.h"
#include "CustomPetEffect.h"
#include "CChatClassic.h"
#include "CMacroUIEx.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "SItemOption.h"
#include "ItemTooltip.h"
#include "PetMontura.h"
#include "Central.h"
#include "BuffIcon.h"
#include "MuHelper.h"
//--
#include "Inter3.h"
#include "CChatClassic.h"
#include "cCPetRenderMesh.h"
#include "MultiSelect.h"
#include "JCRendernoItemGlow.h"
#include "ItemGlow.h"
#include "Font.h"
#include "EventTimer.h"
#include "WeatherFix.h"
#include "GuildAssistantAcceptRequest.h"
#include "ResetSystem.h"
#include "Monster.h"
#include "TMemory.h"
#include "Util.h"
#include "CustomEarthQuake.h"
#include "ServerInfo.h"
#include "GetBarPlayer.h"
#include "BufferSystem.h"
#include "MapTeleport.h"
#include "PKClear.h"
#include "GrandResetSystem.h"
#include "CustomJewelBank.h"
#include "CustomOptionWindow.h"
#include "MuunOption.h"
#include "UIControl.h"
#include "NewUIMyInventory.h"
#include "ShopSearch.h"
#include "ItemMarket.h"
#include "AtlansAbbys.h"
#include "MessageBox.h"
#include "NewParty.h"
#include "CustomNPC.h"
#include "AutoLogin.h"
#include "QuickCommandWindow.h"
#include "Luna_CNewFlag.h"
#include "ConnectServer.h"
#include "ServerInfo.h"
#include "ServerSelWin.h"
#include "CUIMng.h"
#include "Config.h"
#include "CustomNotice.h"
#include "LoginMainWin.h"
#include "SCharacterBetell.h"
#include "Slide.h"
#include "QuestSystem.h"


#include "SkyBox.h"

#include "JCGrowLancer.h"
#include "ScriptItem.h"
#include "CharMakeWin.h"
#include "ZzzCharacter.h"
#include "ZzzInterface.h"
#include "CustomFont.h"
HINSTANCE hins;

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

__declspec(naked) void OffButtonQuestInStats()
{
	static DWORD ButtonAddress = 0x0077EBB5;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonPetsInStats()
{
	static DWORD ButtonAddress = 0x0077EC5E;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonSkillMasterInStats()
{
	static DWORD ButtonAddress = 0x0077ECE7;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonInventoryExt()
{
	static DWORD ButtonAddress = 0x00836A28;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonOpenStore()
{
	static DWORD ButtonAddress = 0x008369B4;
	_asm{jmp ButtonAddress}
}
__declspec(naked) void OffButtonRepeirInInventory()
{
	static DWORD ButtonAddress = 0x00836941;
	_asm{jmp ButtonAddress}
}

extern "C" _declspec(dllexport) void EntryProc() // OK


{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);

	if (gProtect.ReadMainFile("PremiumBH") == 0)
	{
		MessageBox(0, "Licencia Pemium Corrompida!", "Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadTooltipTRSData( "Data\\Local\\TooltipTRSData.bmd" ) == 0)
	{
		MessageBox(0, "Data\\Local\\TooltipTRSData.bmd missing or File corrupt!" ,"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadMakeViewTRSData("Data\\Local\\MakeWorldTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\MakeWorldTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadPetEffectBMD("Data\\Local\\EffectTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\EffectTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	#if(SOIITEM)
		g_pQuickCommandWindow.szInit();
		#endif

	//gInfoLog.Load();

		
		
	SetByte(0x00E61144,0xA0); // Accent
	SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
	SetByte(0x004D228D,0xE9); // Crack (GameGuard)
	SetByte(0x004D228E,0x8B); // Crack (GameGuard)
	SetByte(0x004D228F,0x00); // Crack (GameGuard)
	SetByte(0x004D2290,0x00); // Crack (GameGuard)
	SetByte(0x004D2291,0x00); // Crack (GameGuard)
	SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)
	SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC,0x50); // Login Screen
	SetByte(0x0040B4C5,0x50); // Login Screen
	SetByte(0x0040B4CF,0x18); // Login Screen
	SetByte(0x0040AF0A,0x00); // Login Screen
	SetByte(0x0040AFD5,0xEB); // Login Screen
	SetByte(0x00777FD6,0x70); // Item Text Limit
	SetByte(0x00777FD7,0x17); // Item Text Limit
	SetByte(0x004EBEC7,0x3C); // Item Text Limit
	SetByte(0x005C4004,0x3C); // Item Text Limit
	SetByte(0x007E40BB,0x3C); // Item Text Limit
	SetByte(0x0081B546,0x3C); // Item Text Limit
	SetByte(0x0081B58D,0x3C); // Item Text Limit
	SetByte(0x0086E284,0x3C); // Item Text Limit
	SetByte(0x0086E44C,0x3C); // Item Text Limit
	SetByte(0x0086E573,0x3C); // Item Text Limit
	SetByte(0x0086F8FC,0x3C); // Item Text Limit
	SetByte(0x007DA373,0xB7); // Item Type Limit
	SetByte(0x007E1C44,0xB7); // Item Type Limit
	SetByte(0x0052100D,0xEB); // Ctrl Fix
	SetByte((LPVOID)0x0052101B,0x02); //Fix CTRL Freeze
	SetByte(0x009543C4,0x00); // Move Vulcanus
	SetCompleteHook(0xE9, 0x005880F0, 0x0058811F); //Fix gm wing on Blood castle
	SetDword(0x00588444 + 3, 4095);
	SetCompleteHook(0xE9, 0x004D1CF0, 0x004D1DC2); //-- Remoce MuError.DMP
	MemorySet(0x00D20170, 0x90, 0x1B); //-- Remove Creation MuError.log
	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0) ? 0xEB : 0x75)); //-- Helper Message Box

	//SetDword(0x00856131 + 1, (DWORD)"\\Slide"); //Slide.bmd
	  

	// ->Walk with Full Map Open
	MemorySet(0x82AC07, 0x90, 0x5); //Background
	MemorySet(0x82B03D, 0x90, 0x5); //Moldura
	MemorySet(0x82B0A7, 0x90, 0x5); //Moldura
	MemorySet(0x82B18B, 0x90, 0x5); //Moldura
	MemorySet(0x82B1FA, 0x90, 0x5); //Moldura
	MemorySet(0x82B21B, 0x90, 0x5); //Moldura
	MemorySet(0x82B2CB, 0x90, 0x5); //Moldura
	MemorySet(0x82B339, 0x90, 0x5); //Moldura
	MemorySet(0x82B3B7, 0x90, 0x5); //Moldura
	MemorySet(0x82B3CA, 0x90, 0x5); //Button
	MemorySet(0x82B772, 0x90, 0x5); //Walk



	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); //-- Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); //-- Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); //-- Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); //-- Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); //-- Version
	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); //-- IpAddressPort
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);
	SetDword(0x7B55338,(DWORD)10);
	SetDword(0x004D597B,(DWORD)&MainTickCount);
	SetDword(0x004DA289,(DWORD)&MainTickCount);
	SetDword(0x004DA297,(DWORD)&MainTickCount);
	SetDword(0x004DA3A2,(DWORD)&MainTickCount);
	SetDword(0x004DA3CE,(DWORD)&MainTickCount);
	SetDword(0x004DA3D9,(DWORD)&MainTickCount);
	SetDword(0x0063D326,(DWORD)&MainTickCount);
	SetDword(0x00642112,(DWORD)&MainTickCount);
	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);

	//SetDword(0x00856131 + 1, (DWORD)"\\Slide"); //Slide.bmd

	SetDword(0x00954148 + 1, (DWORD)gProtect.m_MainInfo.ServerName1); //-> (Gold)
	SetDword(0x00954115 + 1, (DWORD)gProtect.m_MainInfo.ServerName2); //-> (Gold PVP)
	SetDword(0x009540E2 + 1, (DWORD)gProtect.m_MainInfo.ServerName3); //-> (Non-PVP)
	SetDword(0x009540AC + 1, (DWORD)gProtect.m_MainInfo.ServerName4); //-> Sem Nada

	SetByte(0x004030D1 + 3, (BYTE)gProtect.m_MainInfo.MaxClassTypes); //-> Max Razes

	SetFloat(0x0D27B1C, gProtect.m_MainInfo.CameraRange); //-> Camera Range 1000.000 default

	MemorySet(0x00792B7F, 0x90, 0x05);	// Fix Button Crywolf Gatekeeper (Third Quest)

	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); // Helper + Inventory

	SetByte(0x005C914B+3, 0x00); //-- LuckItemmove

	MemorySet(0x0063E908,0x90,20); //-- C1:F3:04

	SetCompleteHook(0xE9,0x0064452A,0x00644537); //-- Fix montura

	MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); //-- IpAddress

	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); //-- ClientSerial

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);

	SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);

	SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

	SetCompleteHook(0xE8, 0x005B96E8, &DrawHealthBar);

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);

	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomCommandInfo.Load(gProtect.m_MainInfo.CustomCommandInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);
	//--
	gCustomBattleGloves.Load(gProtect.m_MainInfo.CustomGloves);

	gCustomBow.Load(gProtect.m_MainInfo.CustomBowInfo);

	gCustomPet2.Load(gProtect.m_MainInfo.CustomPetInfo);

	gCloak.Load(gProtect.m_MainInfo.m_CustomCloak);

	ItemTRSData.Load(gProtect.m_MainInfo.CustomPosition);

	gCustomRemake.Load(gProtect.m_MainInfo.CustomRemake);

	gItemManager.Load(gProtect.m_MainInfo.m_ItemInfoEx);

	gCustomModelEffect.Load(gProtect.m_MainInfo.m_CustomModelInfo);
	//--
	gCustomCEffectPet.Load(gProtect.m_ReadBMD.m_PetCEffectBMD);

	gCustomWingEffect.Load(gProtect.m_ReadBMD.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_ReadBMD.DynamicWingEffectInfo);

	cRender.Load(gProtect.m_ReadBMD.RenderMeshPet);

	gCustomMonsterGlow.LoadGlow(gProtect.m_ReadBMD.m_CustomMonsterGlow);

	gCustomMonsterGlow.LoadBrightness(gProtect.m_ReadBMD.m_CustomMonsterbrightness);

	JCEffectMonster.Load( gProtect.m_ReadBMD.m_CustomMonsterEffect );

	JCRemoveGlow.Load( gProtect.m_ReadBMD.m_JCWRemoveGlow );
#if UPDATE > 15
	JCRender.Load( gProtect.m_ReadBMD.m_JCWRenderMesh );
#endif
//--
	gIconBuff.LoadEng(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataEng);
	
	gIconBuff.LoadSpn(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataSpn);
	
	gIconBuff.LoadPor(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataPor);

	GInfo.loadnInformation( gProtect.m_ReadTooltipTRSData.m_TRSTooltipData );

	GInfo.loadnText( gProtect.m_ReadTooltipTRSData.m_TRSTooltipText );


//--
#if UPDATE >= 15
	gSelectCharRamdon.LoadMultiChar(gProtect.m_MakeViewTRSData.m_RenderSelect);
#endif
	gEventTimer.Load(gProtect.m_MainInfo.CustomEventTime);

	gCustomMonsterNameColor.Load(gProtect.m_MainInfo.CustomMonsterNameColor);

	if (gProtect.m_MainInfo.CustomEffectEarthQuake == 1){
		gCustomEarthQuake.Load(gProtect.m_MainInfo.m_EarthQuakeLoad);
	}
//--
	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckLauncherCommandLine();

	gProtect.CheckClientFile();

	gProtect.CheckHackFile();

	gProtect.CheckPlugin1File();
	gProtect.CheckPlugin2File();
	gProtect.CheckPlugin3File();
	gProtect.CheckPlugin4File();
	gProtect.CheckPlugin5File();
	gProtect.CheckPlugin6File();
	gProtect.CheckPlugin7File();
	gProtect.CheckPlugin8File();
	gProtect.CheckPlugin9File();
	gProtect.CheckPlugin0File();
	gProtect.CheckPlugin1FileCrc();
	gProtect.CheckPlugin2FileCrc();

	gProtect.CheckCameraFile();

	InitHackCheck();

	gTrayMode.Load();

	gNPC.Load(); //NPC CUSTOM UP17

	InitCommon();

	AutoLogin.Load();

	gServerInfo.Load();

	//gSkyBox.Load();

	gCMacroUIEx.Load();
	#if(SWITCH_SERVER==1)
	ConnectServer.Load();

	
#endif

	JCRemoveGlow.Init();
#if UPDATE > 15
	JCRender.Init();
#endif
	gCentral.InitCentral();//-- Control: camara||mouse

	gItemInfoEx.Load();

	gMuHelper.LoadHelper();

	

	if(gProtect.m_MainInfo.SelectCharAnimate == 1)
	{
		gSelectChar.Load();
	}

/////-----------SELECT SERVER E CHARACTER -------------////////////
	gInterface.RenderObjectSystem();
	gSlide.Load();
	if (gProtect.m_MainInfo.CustomSelectServerX700 ==5) 
	{
	gCSCharacterS13.Load();
       
	  CScene();
	  gSlide.Load();
	}
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 1)
	{
		gCSceneA.Load();
		gSlide.Load();
	}
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 2)
	{
		CSceneS2();
		gSlide.Load();
		
	}

	if (gProtect.m_MainInfo.CustomSelectServerX700 == 3)
	{
		SCharacterS4();
		gSlide.Load();
		
	//	SetByte(0x004D76EC, (BYTE)1);
	}
	
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 4)
	{
	SCharacterS8(); //->Load Season 8 Character Scene
	gSlide.Load();
		
	}
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 7)
	{
	SCharacterBetell(); //->Load Season 6 Character Scene Betell
	gSlide.Load();

	}

	if (gProtect.m_MainInfo.CustomSelectServerX700 == 6)
	{
	#if UPDATE >= 15
	gSelectCharRamdon.InitMultiChar();
	gSlide.Load();
	#endif
	if(gProtect.m_MainInfo.SelectCharS13 == 1)
	{
	gCSCharacterS13.Load();
	gSlide.Load();
	}
	}




///////////////////////////////////////////////////////////////////////////////
	ItemTRSData.Init();

	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCapeAnimation.Load();
	}

	if(gProtect.m_MainInfo.DisableCustomPet == 0)
	{
		gCustomPet.Load();

		gObjCreatePetExHook();

		gCustomCEffectPet.Init();

		initmontura();
	}

	

	InitItem();

	InitJewel();

	InitPrintPlayer();

	InitReconnect();

	InitResolution();

	gController.Load();

	CustomFont.load();

	InitWing();

	gObjUser.Load();

	
	gRenderMap.MiniMapload();

	InitFonts();

	
		

	if (gProtect.m_MainInfo.WeatherFix == 1)
	{
		gWeatherFix.Load();
	}
	
	gGuildAssistantAcceptRequest.Load();

	gResetSystem.Load();

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
		case 1:
		case 2:
			InitInter3();
			gCChatClassic.Load();
			break;
		case 3:
			gCRenderEx700.Init();
			gCChatEx.Load();
			//InitSeason15();
			break;
		case 4:
			gCRenderEx700.Init();
			gCChatEx.Load();
			break;
	}
	
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		g_StatsAdvance.Load();	//<-- Advanced
	}
	gOffTrade.Init();

	gFog.Init();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();
	}

	InitloadGlow();

	if(gProtect.m_MainInfo.DisableCustomBow == 0)
	{
		gCustomBow.Init();
	}

	if(gProtect.m_MainInfo.DisableCustomClaws == 0)
	{
		gCustomBattleGloves.Init();
	}

	gCustomMap.Load();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);
		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);
	}

	//-> Remove Creation MuError.log
	if (gProtect.m_MainInfo.RemoveMuErrorLog == 1)
	{
		MemorySet(0x00D20170, 0x90, 0x1B);
	}

	if (gProtect.m_MainInfo.RemoveGLOWLANCER == 0)
	{
		SetByte(0x004030D1 + 0x3, SYSTEM_CLASS); //-- Create Btn
	}

	if (gProtect.m_MainInfo.RemoveClass == 4)
	{
		SetByte(0x004030D1+3,7);
	}

	if(gProtect.m_MainInfo.RemoveClass == 3)
	{
		SetByte(0x004030D1+3,6);
	}

	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x004030D1+3,5);
	}
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x004030D1+3,4);
		
	}

	SetWord(0x00405B7C, gProtect.m_MainInfo.ReduceMemory);
	SetWord(0x0040CC40, gProtect.m_MainInfo.ReduceMemory);
	
	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8); //Remove Master Skill Tree Window(A Buttom)
	}

	if(gProtect.m_MainInfo.EffectPlus15 == 0)
	{
		MemorySet(0x006097B0,0x90,0x69D);
	}

	if(gProtect.m_MainInfo.DisableGens == 1)
	{
		MemorySet(0x007C5AD2, 0x90, 0x05);			//-> Disable Gens (Key B)
	}

	if(gProtect.m_MainInfo.DisableTabMap == 1)
	{
		MemorySet(0x0062F876, 0x90, 0x30);			//-> Disable ViewMap (Key TAB)
	}
	//-- disables
	if(gProtect.m_MainInfo.DisableRepeirInInventory == 1)
	{
		SetCompleteHook(0xE9, 0x0083693C, &OffButtonRepeirInInventory);
	}

	if(gProtect.m_MainInfo.DisableButtonOpenStore == 1)
	{
		SetCompleteHook(0xE9, 0x008369AF, &OffButtonOpenStore);
	}

	if(gProtect.m_MainInfo.DisableButtonInventoryExt == 1)
	{
		SetCompleteHook(0xE9, 0x00836A23, &OffButtonInventoryExt);
	}

	if(gProtect.m_MainInfo.DisableButtonQuestInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EBB0, &OffButtonQuestInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonPetsInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EC59, &OffButtonPetsInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonSkillMaster == 1)
	{
		SetCompleteHook(0xE9, 0x0077ECE2, &OffButtonSkillMasterInStats);
	}

	if(gProtect.m_MainInfo.DisableEffectRemake == 0)
	{
		gCreateEffect.Load();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetByte(0x005528A0, 0xC3); // [Fix] Remover Recuo PVP
		MemorySet(0x008684F0, 0x90, 0x52);			//-> Disable FastMenu (Key U)
	}

	if(gProtect.m_MainInfo.DisableHelper == 1)
	{
		MemorySet(0x0085B6AC, 0x90, 0x05);			//-> Remove Helper Top Screen
		MemorySet(0x0085CC50, 0x90, 0x05);			//-> Disable Helper (Key Z)
		MemorySet(0x007D40A2, 0x90, 0x05);			//-> Disable Helper (Key Home)
	}

	if(gProtect.m_MainInfo.DisableSocketInvetori == 1)
	{
		RemoveSocket();
	}

	//-> Remove Battle Zone in Warp Window
	if (gProtect.m_MainInfo.DisableBattleZoneWindow == 1)
	{
		SetCompleteHook(0xE9, 0x00832862, 0x00832897);
	}

	if (gProtect.m_MainInfo.DisableBCDSCCMaster == 1)
	{
		SetCompleteHook(0xE9, 0x007E4CA4, 0x007E4D16);
		MemorySet(0x00878B5F, 0x90, 0x5);
		MemorySet(0x0087500F, 0x90, 0x5);
		SetByte((PVOID)(0x008743FC + 3), 7);
		SetByte((PVOID)(0x00874D54 + 6), 7);
		SetByte((PVOID)(0x007E4CB9 + 1), 0);
		SetByte((PVOID)(0x00877EDC + 3), 6);
	}

	if (gProtect.m_MainInfo.Disable380MixChaosMachine == 1)
	{
		MemorySet(0x007AA3BA, 0x90, 0x5);
		MemorySet(0x007AA39C, 0x90, 0x5);
		MemorySet(0x007AA9B3, 0x90, 0x5);
	}

	BYTE WCoinPValue = 0;
	BYTE WCoinGValue = 0;

	if (gProtect.m_MainInfo.DisableWCoinCCashShop != 0)
	{
		SetRange(0x0094346B, 0x3A, ASM::NOP); // Disable WCoin Text in CashShop
		SetRange(0x009434A5, 0x38, ASM::NOP); // Disable WCoin Value in CashShop
		WCoinPValue += 15;
		WCoinGValue += 15;
	}

	if (gProtect.m_MainInfo.DisableWCoinPCashShop != 0)
	{
		SetRange(0x00943524, 0x3A, ASM::NOP); // Disable WCoinP Text in CashShop
		SetRange(0x0094355E, 0x38, ASM::NOP); // Disable WCoinP Value in CashShop
		WCoinGValue += 15;
	}
	else
	{
		SetByte(0x00943541, *(BYTE*)0x00943541 - WCoinPValue);// WcoinP Text X position. Default 65
		SetByte(0x00943578, *(BYTE*)0x00943578 - WCoinPValue);// WCoinP Value X position. Default 65
	}

	if (gProtect.m_MainInfo.DisableWCoinGCashShop != 0)
	{
		SetRange(0x009435DD, 0x3A, ASM::NOP); // Disable GoblinPoint Text in CashShop
		SetRange(0x00943617, 0x38, ASM::NOP); // Disable GoblinPoint Value in CashShop
	}
	else
	{
		SetByte(0x009435FA, *(BYTE*)0x009435FA - WCoinGValue);// GoblinPoint Text X position. Default 80
		SetByte(0x00943631, *(BYTE*)0x00943631 - WCoinGValue);// GoblinPoint Value X position. Default 80
	}

	if (gProtect.m_MainInfo.Unicode == 1)
	{
		SetByte((0x00958D4C + 3), 0xA8);	//1 Codepage utf China lang
		SetByte((0x00958D4C + 4), 0x03);	//2	Codepage utf China lang

		SetByte(0x004215A7, 0xEB);	//[0-9A-Za-z] Name
		SetByte((0x00507AEA + 1), 0x72); //can not use symbol
		SetByte(0x00507AFD, 0xEB);	//[0-9A-Za-z] Guild

		SetByte((0x00958D56 + 0x3), 0x04); //  Message Limit
	}

	if (gProtect.m_MainInfo.MiniMapHover == 1)
	{
		//Minimap hover
		SetByte(0x0082BAB5 + 1, 0); // ��������� ����������� ���� ��� �� ���������
		SetRange(0x0082BAB7, 0x2, ASM::NOP);
		SetRange(0x0082B7FA, 0xA0, ASM::NOP);
	}


	if (gProtect.m_MainInfo.SafeZoneEnable == 1)
	{
		
			//Fenrir SafeZone (Struct +14)
			SetByte(0x00501955 + 2, 0);
			MemorySet(0x0054EAE1, 0x90, 0x06);//SetPlayerStop
			MemorySet(0x0054FC92, 0x90, 0x06);//SetPlayerWalk

			//Horse SafeZone (Struct +14)
			SetByte(0x00502269 + 2, 0);
			MemorySet(0x0054ECA3, 0x90, 0x6);
			MemorySet(0x0054FCEC, 0x90, 0x6);

			//Dinorant e Uniria (Struct +14)
			SetByte(0x00502C4B + 2, 0);
			MemorySet(0x0054ED6D, 0x90, 0x6);
			MemorySet(0x0054FD5F, 0x90, 0x6);
			MemorySet(0x0054FE3E, 0x90, 0x6);

			//Raven (Struct +14)
			SetByte(0x00502C44 + 2, 0);
			MemorySet(0x0054FD23, 0x90, 0x6);

		
	}

	//-> Custom Interface Helper Bar
	if (gProtect.m_MainInfo.CustomInterfaceHelperBar == 0)
	{
		MemorySet(0x0085B6AC, 0x90, 0x05);	//-> Remove Helper Top Screen
		SetByte((PVOID)(0x007D410F + 1), 0xFF); //-> Disable Z Key
	}

	//-> Custom Interface Helper Bar
	if (gProtect.m_MainInfo.CustomInterfaceHelperBar == 1)
	{
		MemorySet(0x0085B6AC, 0x90, 0x05);	//-> Remove Helper Top Screen
	}

	//-> Custom Interface Helper Bar (S4)
	if (gProtect.m_MainInfo.CustomInterfaceHelperBar == 2)
	{
		//MuHelper Dimensionamento
		MemorySet(0x007D2DEE, 0x90, 0x5);
		MemorySet(0x007D2E31, 0x90, 0x5);
		MemorySet(0x007D2D18, 0x90, 0x5);
		SetByte((PVOID)(0x007D2D52 + 3), -74);		//INTERFACE MINIMAPC
		SetByte((PVOID)(0x007D2771 + 3), -117);	//START MUHELPER
		SetByte((PVOID)(0x007D281C + 3), -117);	//STOP MUHELPER
		SetByte((PVOID)(0x007D26D5 + 3), -117);	//CONFIG MUHELPER
		SetDword(0x007D2F0A + 1, (DWORD)"Interface\\Minimap_positionC.tga");
	}

	

	gPostInterface.Load();	//<-- post item

	gCItemSetOption.Load();

	if (gProtect.m_MainInfo.AlwaysnameShowType != 0)
	{
		JumPlayer.Load();
	}

	//-> Show Name
	//if (gProtect.m_MainInfo.AlwaysnameShowType == 1)
	//{
	//	SetByte((PVOID)(0x81C03FA), 0x01);
	//}
	//
	////-> Show Name + Guild Logo
	//if (gProtect.m_MainInfo.AlwaysnameShowType == 2)
	//{
	//	SetByte((PVOID)(0x81C03FA), 0x01);
	//	JumPlayer.Load();
	//}

	gCustomJewelBank.Load();

	g_BufferSystem.Load();

#if(CUSTOM_MAP_TELEPORT)
	g_MapTeleport.Load();
#endif
#if(CUSTOM_PKCLEAR_NPC==TRUE)
	g_PKClear.Load();
#endif
#if(CreateOptionWindows)
    gOptionWindow.Main();
#endif
	gSkyBox.Load();

	if (gProtect.m_MainInfo.DisableMoveWindow == 1)
	{
		MemorySet(0x00830BA6, 0x90, 0x05);
		MemorySet(0x00832ED8, 0x90, 0x05);
		MemorySet(0x0083279C, 0x90, 0x05);
		MemorySet(0x008329A2, 0x90, 0x05);
	}

	SetCompleteHook(0xE9, 0x0071B1A3, 0x00720894); //-- Fix RF

	InitAttackSpeed(); //-- Fix Agilidad

	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); //-- Fix RF

	SetRange(0x0077EECD, 0x18, 0x90); //-- Press Middle Mouse button to add stats quickly

	if (gProtect.m_MainInfo.CustomEffectEarthQuake == 1){
		gCustomEarthQuake.LoadRenderSkill();
	}

	//-> Cinematic Black Bar
	if(gProtect.m_MainInfo.CinematicBarSizeEnable == 1)
	{
	SetDword((PVOID)(0x004D7A0E),gProtect.m_MainInfo.CinematicBarUpSizeServer);//Select Server
	SetByte((PVOID)(0x004D7A18),gProtect.m_MainInfo.CinematicBarDownSizeServer);//Select Server
	//--
	SetDword((PVOID)(0x004D7179),gProtect.m_MainInfo.CinematicBarUpSizeCharacter);//Select Character
	SetByte((PVOID)(0x004D7183),gProtect.m_MainInfo.CinematicBarDownSizeCharacter);//Select Character
	}

	gGRSystem.Load();
	g_PersonalShopEx.Load();

	

	if (gProtect.m_MainInfo.EnableCustomFlag == 1)
	{
		Flag.Load();
	}


	if (gProtect.m_MainInfo.EnableLoading == 1)
	{
		gCUIMng.Load();  //->Load Loading MuArchangel 

	}


	if (gProtect.m_MainInfo.EnableLoading == 2)
	{
		gCUIMng.Load();  //->Load Loading MuLegend 

	}

	if (gProtect.m_MainInfo.EnableLoading == 3)
	{
		gCUIMng.Load();  //->Load Loading MuBetell 

	}

	if (gProtect.m_MainInfo.EnableLoading == 4)
	{
		gCUIMng.Load();  //->Load Loading BK 

	}

	if (gProtect.m_MainInfo.EnableLoading == 5)
	{
		gCUIMng.Load();  //->Load Loading BK 

	}

	if (gProtect.m_MainInfo.EnableLoading == 6)
	{
		gCUIMng.Load();  //->Load Loading BK 

	}

	if (gProtect.m_MainInfo.EnableLoading == 7)
	{
		gCUIMng.Load();  //->Load Loading BK 

	}

	if (gProtect.m_MainInfo.EnableMoveServerList == 1)
	{
		g_ServerSelWin.Init();  //->MoveServerList 

	}

	//-> Config Load
	Config.Load();


	


	//-> Custom Server News
	if (gProtect.m_MainInfo.ServerNews == 1)
	{
		InitNotices();
	}

	#if(LOGIN_REGISTER==1)
	g_pLoginMainWin.Init();
    #endif
    if(gProtect.m_MainInfo.EnableMuunSystem == 1)
	{
	g_MuunSystem.Init();
	g_pRenderText.Init();
	g_Option.Init();
}
	#if(DEV_PLAYERSHOP)
	if(gProtect.m_MainInfo.EnableItemMarket == 1)
	{
	g_ItemMarket.Load();
	}
	#endif

	InitAtlansAbbys();

	 GetPartyBar.Load();

	gNPC.Load();

	JCGetModelPJ.Load();
	//#if GROWLANCER
		g_ScriptItem.Init();
		g_pModelViewChar.Init();
		g_pInterface.Init();
//		if (ZxProtect.m_MainInfo.TypeSelectChar == 0 && ZxProtect.m_MainInfo.RemoveClass == 0)
//		{
			g_CharMakeWin.Init();
//		}
//#endif

	//Error Message Box Texture fail
	gMessageBoxPopUp.InitPopUp();

	//GInfo.IniInformation();
}



BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			gController.Instance = hModule;
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}

void SelectCharS0()
{
}
