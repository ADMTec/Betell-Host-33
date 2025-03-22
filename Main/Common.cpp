#include "stdafx.h"
#include "Common.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Util.h"
#include "ChatExpanded.h"
#include "CChatClassic.h"

BYTE GensBattleMapCount = 0;
BYTE GensMoveIndexCount = 0;
BYTE GensBattleMap[120];
BYTE GensMoveIndex[120];

int SkillPage;
int OpenSwicthSkill;
int DisableStaticEffect;
int DisableDynamicEffect;
int DisableSkillEffect;
int DisableGlowEffect;
int DisableObject;
int DisableShadow;
int Anisotropy;
int MaxAnisotropy;
int Linear;
int Fog;
int Tron;
int MiniMap;
int TimerBar;
int SeparateChat;
int HpPlayerBar;
int HpMonsterBar;
int HpBar;
int HPMonster;
char Main_Font_Name[100];
int Main_Font_Bold;
int Main_Font_Height;
int Main_Font_Italic;
int Main_Font_Unicode;
int Main_Font_Width;
int Main_Font_Underline;
int Main_Font_Quality;
int Main_Font_StrikeOut;
int SellPostColor;
int offhelper;
int MinimizarMiniMapa;
int MiniMapType;
int EnableEffect15;
int EnableObjects;
int Transparency1;
int Transparency2;
int Transparency3;
int Invisibility;
int NewStaticEffect;
int NewDynamicEffect;
int NewActiveShades;
int MinimizarParty;
int DisablePlayer;
int global_int = 17;
int PVPAttack;
int FontON;
int FontHeight;
int ChangeResolution;
int isHiddenPlayer;
int DisableWings;
int DisableWeapons;
int DisableCloack;

//---------------------------------------------------------------------------

bool validarLevel(DWORD level)
{
	if (level >= gProtect.m_MainInfo.ReduceMemory)
	{
		return true;
	}
	return false;
}

int GetMgTeleportLevel(int mapLevel)
{
	return mapLevel/* * 2 / 3*/;//floor(mapLevel*2/3);
}

__declspec(naked) void ChangeMGLevel()
{
	static DWORD TpLevel = 0;
	static DWORD retAddr = 0x00832ACE;
	//static int NewLevel=0;
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x30]
		MOV TpLevel, EAX
	}

	TpLevel = GetMgTeleportLevel(TpLevel);

	//TpLevel=TpLevel*2/3;
	__asm
	{
		MOV EAX, TpLevel
		MOV DWORD PTR SS : [EBP - 0x30] , EAX
		jmp retAddr
	}
}

__declspec(naked) void GlobalMessagem()
{
	static DWORD ADDS = 0x00597698;

	_asm
	{
		CMP DWORD PTR SS : [EBP - 8] , 1200
		JMP[ADDS]
	}
}

char ChatWindows(MUChat* This)
{
	This->WindowPosX = 0;

	if (gInterface.CheckWindow(ChatWindow))
	{
		This->WindowPosY = 382;
	}
	else
	{
		This->WindowPosY = 429;
	}

	sub_7889B0(This);
	return 1;
}

void SaveScreen_fix()
{
	*reinterpret_cast<bool*>(0x87933FB) = true; // GrabFirst = true;

	auto Buffer = new unsigned char[pWinWidth * pWinHeight * 4];

	glReadPixels(0, 0, pWinWidth, pWinHeight, GL_RGBA, GL_UNSIGNED_BYTE, &Buffer[0]);

	auto BufferNew = new unsigned char[pWinWidth * pWinHeight * 3];

	int counter = 0;
	for (int i = 0; i < pWinWidth * pWinHeight * 4; i += 4)
	{
		BufferNew[counter + 0] = Buffer[i + 0];
		BufferNew[counter + 1] = Buffer[i + 1];
		BufferNew[counter + 2] = Buffer[i + 2];

		counter += 3;
	}

	WriteJpeg(reinterpret_cast<char*>(0x8793278), pWinWidth, pWinHeight, BufferNew, 100);

	SAFE_DELETE_ARRAY(Buffer)
		SAFE_DELETE_ARRAY(BufferNew)

		* reinterpret_cast<int*>(0x8793404) = *reinterpret_cast<int*>(0x8793404) + 1; // GrabScreen++;
	*reinterpret_cast<int*>(0x8793404) = *reinterpret_cast<int*>(0x8793404) % 10000; // GrabScreen %= 10000;
}

//fix CPU
__declspec(naked) void ReduceCPU()
{
	static DWORD JmpBack = 0x00662725;

	__asm
	{
		Push 1;
		Call Dword Ptr Ds : [0x0075615C] ;
		Call Dword Ptr Ds : [0x00756140] ;
		Jmp[JmpBack];
	}
}

void InitCommon() // OK
{
	SetCompleteHook(0xE9, 0x0040B154, &LoginTab);

	SetCompleteHook(0xFF, 0x0064A79A, &CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF, 0x0064A85F, &CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF, 0x00656E03, &CheckMasterLevel); // C1:48

	SetCompleteHook(0xFF, 0x0064AB3D, &CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF, 0x0064AC02, &CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF, 0x0063DDF2, &CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF, 0x0063DF89, &CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF, 0x0063EA4C, &CheckMasterLevel); // C1:F3:04

	SetCompleteHook(0xFF, 0x0064CA0C, &CheckMasterLevel); // LevelUp

	SetCompleteHook(0xFF, 0x0077FAF9, &CheckMasterLevel); // Print Level

	SetCompleteHook(0xFF, 0x0081071B, &CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF, 0x0081079B, &CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF, 0x0047FE31, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x0059890D, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x0059A399, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x0059A93C, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x0059B13B, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x005A4261, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x005A4D52, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x005B6117, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x0065A6CE, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x00727987, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x007861F1, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x007D32FA, &CheckGensBattleMap);

	SetCompleteHook(0xFF, 0x007D3B0D, &CheckGensBattleMap);

	SetCompleteHook(0xE9, 0x008317BD, &CompareGensMoveIndex);
	#if(SWITCH_SERVER==0)
	SetCompleteHook(0xE8, 0x007D2B0C, &FixHelperMouseClick); //Dupe Fix
#endif
	if (gProtect.m_MainInfo.ChangeMGLevel == 1)
	{
		SetCompleteHook(0xE9, 0x00832ABB, &ChangeMGLevel);
	}

	SetCompleteHook(0xE9, 0x00597691, &GlobalMessagem);

	SeparateChat = GetPrivateProfileIntA("Setting", "SeparateChat", 0, "./Settings.ini");
	HpPlayerBar = GetPrivateProfileIntA("Setting", "HpPlayerBar", 0, "./Settings.ini");
	HpMonsterBar = GetPrivateProfileIntA("Setting", "HpMonsterBar", 0, "./Settings.ini");
	TimerBar = GetPrivateProfileIntA("Setting", "TimerBar", 0, "./Settings.ini");
	MiniMap = GetPrivateProfileIntA("Setting", "MiniMap", 0, "./Settings.ini");
	MiniMapType = GetPrivateProfileIntA("Setting", "MiniMapType", 0, "./Settings.ini");

	Anisotropy = GetPrivateProfileIntA("Graphics", "Anisotropy", 1, "./Settings.ini");
	MaxAnisotropy = GetPrivateProfileIntA("Graphics", "MaxAnisotropy", 1, "./Settings.ini");
	Linear = GetPrivateProfileIntA("Graphics", "Linear", 1, "./Settings.ini");

	Fog = GetPrivateProfileIntA("Effects", "Fog", 0, "./Settings.ini");
	DisableGlowEffect = GetPrivateProfileIntA("Effects", "DeleteGlow", 0, "./Settings.ini");
	EnableEffect15 = GetPrivateProfileIntA("Effects", "DeleteFOEffect", 0, "./Settings.ini");
	EnableObjects = GetPrivateProfileIntA("Effects", "DeleteObjects", 0, "./Settings.ini");
	Transparency1 = GetPrivateProfileIntA("Effects", "DeleteArmor", 0, "./Settings.ini");
	Transparency2 = GetPrivateProfileIntA("Effects", "DeleteWeapon", 0, "./Settings.ini");
	Transparency3 = GetPrivateProfileIntA("Effects", "DeleteWings", 0, "./Settings.ini");
	Invisibility = GetPrivateProfileIntA("Effects", "DeletePlayer", 0, "./Settings.ini");
	NewStaticEffect = GetPrivateProfileIntA("Effects", "DeleteStaticEffect", 0, "./Settings.ini");
	NewDynamicEffect = GetPrivateProfileIntA("Effects", "DeleteDynamicEffect", 0, "./Settings.ini");
	NewActiveShades = GetPrivateProfileIntA("Effects", "DeleteShadows", 0, "./Settings.ini");


	GetPrivateProfileStringA("MainConfig", "Main_Font_Name", "Arial", Main_Font_Name, 100, ".\\Settings.ini");
	Main_Font_Bold = GetPrivateProfileIntA("MainConfig", "Main_Font_Bold", 1, "./Settings.ini");
	Main_Font_Height = GetPrivateProfileIntA("MainConfig", "Main_Font_Height", 11, "./Settings.ini");
	Main_Font_Italic = GetPrivateProfileIntA("MainConfig", "Main_Font_Italic", 0, "./Settings.ini");
	Main_Font_Unicode = GetPrivateProfileIntA("MainConfig", "Main_Font_Unicode", 1, "./Settings.ini");
	Main_Font_Width = GetPrivateProfileIntA("MainConfig", "Main_Font_Width", 0, "./Settings.ini");
	Main_Font_Underline = GetPrivateProfileIntA("MainConfig", "Main_Font_Underline", 0, "./Settings.ini");
	Main_Font_Quality = GetPrivateProfileIntA("MainConfig", "Main_Font_Quality", 3, "./Settings.ini");
	Main_Font_StrikeOut = GetPrivateProfileIntA("MainConfig", "Main_Font_StrikeOut", 0, "./Settings.ini");

	//-- Minimizar MiniMapa
	MinimizarMiniMapa = 0;
	//--
	SkillPage = 1;
	offhelper = 0;
	MinimizarParty = 0;

	gChatExpanded.m_separate = SeparateChat;

	if (SeparateChat == 1)
	{
		gChatExpanded.Load();
	}

	SetCompleteHook(0xE8, 0x0078B09A, &ChatWindows); //ChatPosition
	SetCompleteHook(0xE8, 0x004D9CF0 + 0x609, &SaveScreen_fix); //Fix SaveScreen crash on big resolutions
	SetCompleteHook(0xE9, 0x0066271F, &ReduceCPU); //fix CPU

}

////-> Black Bar Size
//if (gProtect.m_MainInfo.SelectLoginThemeType != 0 && gProtect.m_MainInfo.SelectLoginThemeType != 1 && gProtect.m_MainInfo.SelectLoginThemeType != 2)
//{
//	SetDword((PVOID)(0x004D7A0E), 480);//Select Server
//	SetByte((PVOID)(0x004D7A18), 0);//Select Server
//	SetDword((PVOID)(0x004D7179), 480);//Select Character
//	SetByte((PVOID)(0x004D7183), 0);//Select Character
//}
#if(SWITCH_SERVER==0)
char FixHelperMouseClick(int a1) // Dupe Fix
{
	if (gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
		return 0;

	return pHelperMouseClick(a1);
}
#endif

BOOL CheckIsLuckyItem(int ItemID) // OK
{
	bool result;

	if (ItemID < 4158 || ItemID > 4168)
	{
		if (ItemID < 3646 || ItemID > 3656)
		{
			if (ItemID < 5694 || ItemID > 5704)
			{
				if (ItemID < 5182 || ItemID > 5192)
					result = ItemID >= 4670 && ItemID <= 4680;
				else
					result = 1;
			}
			else
			{
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	else
	{
		result = 1;
	}
	return result;
}

BOOL CheckGensBattleMap(int map) // OK
{
	for (int n = 0; n < GensBattleMapCount; n++)
	{
		if (GensBattleMap[n] == map)
		{
			return 1;
		}
	}

	return 0;
}

BOOL CheckGensMoveIndex(int idx) // OK
{
	for (int n = 0; n < GensMoveIndexCount; n++)
	{
		if (GensMoveIndex[n] == idx)
		{
			return 1;
		}
	}

	return 0;
}

__declspec(naked) void LoginTab() // OK
{
	static DWORD LoginTabAddress1 = 0x0040B16F;

	__asm
	{
		Push 0
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x350]
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Eax, Dword Ptr Ds : [Edx + 0x350]
		Mov Edx, Dword Ptr Ds : [Eax]
		Call Dword Ptr Ds : [Edx + 0x30]
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x354]
		Push Ecx
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Edx + 0x350]
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Edx, Dword Ptr Ds : [Eax + 0x350]
		Mov Eax, Dword Ptr Ds : [Edx]
		Call Dword Ptr Ds : [Eax + 0x58]
		Mov Ecx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Edx, Dword Ptr Ds : [Ecx + 0x350]
		Push Edx
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x354]
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Eax, Dword Ptr Ds : [Edx + 0x354]
		Mov Edx, Dword Ptr Ds : [Eax]
		Call Dword Ptr Ds : [Edx + 0x58]
		Jmp[LoginTabAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x005875A0;

	_asm
	{
		Push Ebp
		Mov Ebp, Esp
		Mov Eax, Dword Ptr Ds : [MAIN_CHARACTER_STRUCT]
		Xor Ecx, Ecx
		Mov Cx, Word Ptr Ds : [Eax + 0x0E]
		Cmp Ecx, 0x190
		Je NEXT
		Xor Eax, Eax
		Jmp EXIT
		NEXT :
		Xor Edx, Edx
			Mov Dl, Byte Ptr Ss : [Ebp + 0x08]
			Push Edx
			Call[CheckMasterLevelAddress1]
			Add Esp, 0x04
			EXIT :
			Pop Ebp
			Retn
	}
}

__declspec(naked) void CompareGensMoveIndex() // OK
{
	static DWORD CheckGensMoveIndexAddress1 = 0x0051B090;
	static DWORD CheckGensMoveIndexAddress2 = 0x008317FC;
	static DWORD CheckGensMoveIndexAddress3 = 0x008317EA;

	__asm
	{
		Lea Ecx, Dword Ptr Ss : [Ebp - 0x08]
		Call[CheckGensMoveIndexAddress1]
		Mov Ecx, Dword Ptr Ds : [Eax]
		Mov Edx, Dword Ptr Ds : [Ecx]
		Push Edx
		Call[CheckGensMoveIndex]
		Add Esp, 0x04
		Test Eax, Eax
		Jnz EXIT
		Jmp[CheckGensMoveIndexAddress2]
		EXIT:
		Jmp[CheckGensMoveIndexAddress3]
	}
}

void DrawEffectsPic(int& EffectID, float StartX, float StartY, float StartWidth, float StartHeight)
{
	if (EffectID > 0 && EffectID < 180)
	{
		int EffectValue = (EffectID - 1) % 80;
		float SourceX = (double)(EffectValue % 10) * StartWidth / 256.0;
		float SourceY = (double)(EffectValue / 10) * StartHeight / 256.0;
		float SourceWidth = StartWidth / 256.0;
		float SourceHeight = StartHeight / 256.0;
		RenderBitmap((EffectID - 1) / 80 + 31725, StartX, StartY, StartWidth, StartHeight, SourceX, SourceY, SourceWidth, SourceHeight, 1, 1, 0);
	}
}

__declspec(naked) void Copyright()
{

	static DWORD	Test_Buff;

	static char		Test_LevelBuff[40];
	//
	gInterface.DrawFormat(eYellow, (MAX_WIN_WIDTH / 2) - 74, 470, 100, 3, "Gaming Master");
	_asm
	{
		lea eax, Test_LevelBuff
		push eax
		//	// ----
	}

	_asm
	{
		mov Test_Buff, 0x004D7D1D
		jmp Test_Buff
	}
}