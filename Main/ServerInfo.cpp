#include "stdafx.h"
#include "ServerInfo.h"
#include "Common.h"
#include "CustomFog.h"
#include "ChatExpanded.h"
#include "JCEntryproy.h"
//#include "ExQuestWinSystem.h"
#include "ConnectServer.h"
#include "Util.h"
#include "TMemory.h"
#if(SWITCH_SERVER==1)
CServerInfo g_ServerInfo;

CServerInfo::CServerInfo()
{
	
}

CServerInfo::~CServerInfo()
{
}
#endif
ServerInfo gServerInfo;

ServerInfo::~ServerInfo()
{
}

void ServerInfo::Load()
{
	this->MenuButton.Red = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtn_Red", FLOATTORGB(0.6), ".\\Settings.ini"));
	this->MenuButton.Green = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtn_Green", FLOATTORGB(0.6), ".\\Settings.ini"));
	this->MenuButton.Blue = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtn_Blue", FLOATTORGB(0.6), ".\\Settings.ini"));
	this->MenuButton.Alpha = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtn_Alpha", FLOATTORGB(1.0), ".\\Settings.ini"));

	this->MenuButtonHover.Red = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnHover_Red", FLOATTORGB(0.0), ".\\Settings.ini"));
	this->MenuButtonHover.Green = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnHover_Green", FLOATTORGB(0.0), ".\\Settings.ini"));
	this->MenuButtonHover.Blue = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnHover_Blue", FLOATTORGB(0.8), ".\\Settings.ini"));
	this->MenuButtonHover.Alpha = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnHover_Alpha", FLOATTORGB(1.0), ".\\Settings.ini"));

	this->MenuButtonClick.Red = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnMouse_Red", FLOATTORGB(0.8), ".\\Settings.ini"));
	this->MenuButtonClick.Green = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnMouse_Green", FLOATTORGB(0.0), ".\\Settings.ini"));
	this->MenuButtonClick.Blue = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnMouse_Blue", FLOATTORGB(0.0), ".\\Settings.ini"));
	this->MenuButtonClick.Alpha = RGBTOGLFLOAT(GetPrivateProfileInt("Menu", "MenuBtnMouse_Alpha", FLOATTORGB(1.0), ".\\Settings.ini"));
}

void ServerInfo::SetSettingsInfo(int index)
{
	if (index == 0)
	{
		gChatExpanded.m_separate ^= 1;
	}
	else if (index == 1)
	{
		Fog ^= 1;
	}
	else if (index == 2)
	{
		HpPlayerBar ^= 1;
	}
	else if (index == 3)
	{
		HpMonsterBar ^= 1;
	}
	else if (index == 4)
	{
		TimerBar ^= 1;
	}
	else if (index == 5)
	{
		MiniMap ^= 1;
	}
	else if (index == 6)
	{
//		g_ExWinQuestSystem.DrawMiniInfoFlag ^= 1;
	}
}

int ServerInfo::GetSettingsInfo(int index)
{
	if (index == 0)
	{
		return gChatExpanded.m_separate;
	}
	else if (index == 1)
	{
		return Fog;
	}
	else if (index == 2)
	{
		return HpPlayerBar;
	}
	else if (index == 3)
	{
		return HpMonsterBar;
	}
	else if (index == 4)
	{
		return TimerBar;
	}
	else if (index == 5)
	{
		return MiniMap;
	}
	else if (index == 6)
	{
//		return g_ExWinQuestSystem.DrawMiniInfoFlag;
	}
}
#if(SWITCH_SERVER==1)
Naked(DynamicTypeServer)
{
	static DWORD Address1 = 0x08128ADC;
	static DWORD Address2 = 0x00402320;
	static DWORD Address3 = 0x00D4F798;
	static DWORD Address4 = 0x009CF6AA;
	static DWORD Address5 = 0x0095415C;
	static DWORD SubCode = 0;
	static char * formatText;
	_asm{
		mov edx, [ebp + 0x0C]
		mov SubCode, edx
	}
	switch (ConnectServer.getServerType(SubCode))
	{
	//case 0:
	//	formatText = gProtect.m_MainInfo.ServerGold;//"%s-%d(PvP) %s";
	//	break;
	//case 1:
	//	formatText = gProtect.m_MainInfo.ServerGoldPVP;//"%s-%d(Non-PvP) %s";
	//	break;
	//case 2:
	//	formatText = gProtect.m_MainInfo.ServerNonPVP;//"%s-%d(Non-PvP) %s";
	//	break;	
   // case 3:
		//formatText = gProtect.m_MainInfo.ServerName4;//"%s-%d(Non-PvP) %s";
		//break;
        //case 4:
		//formatText = gProtect.m_MainInfo.ServerName2;//"%s-%d(Non-PvP) %s";
		//break;
       // case 5:
		//formatText = gProtect.m_MainInfo.ServerName3;//"%s-%d(Non-PvP) %s";
		//break;
       // case 6:
		//formatText = gProtect.m_MainInfo.ServerName4;//"%s-%d(Non-PvP) %s";
		//break;
        // default:
	//	formatText =gProtect.m_MainInfo.ServerName4;//"%s-%d %s";
	//	break;
	}
		
	_asm{
		mov edx, [ebp - 0x10]
		push edx
		mov ecx, Address1
		call Address2
		push eax
		mov eax, [ebp - 0x14]
		mov ecx, [eax + 0x08]
		push ecx
		mov edx, [ebp + 0x08]
		add edx, 0x2D
		push edx
		push formatText
		mov eax, [ebp - 0x14]
		add eax, 0x15
		push eax
		call Address4
		add esp, 0x14
		jmp Address5

	}
}
void CServerInfo::Load()
{
	SetRange((LPVOID)0x00954071, 10, ASM::NOP);
	SetOp((LPVOID)0x00954071, DynamicTypeServer, ASM::JMP);
}
#endif
