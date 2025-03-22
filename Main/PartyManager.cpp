#include "StdAfx.h"
#include "Util.h"
#include "SEASON3B.h"
#include "NewUISystem.h"
#include "PartyManager.h"

CPartyManager g_pPartyManager;
BYTE PartyArray[32 * MAX_PARTYS];
PARTY_BUFFS_DATA PartyEffect[MAX_PARTYS];

CPartyManager::CPartyManager(void)
{
	this->pbyPagekey = 0;
	memset(this->BtnPartyExit, 0, sizeof(this->BtnPartyExit));
}

CPartyManager::~CPartyManager(void)
{
}

void CPartyManager::LoadImages()
{
	((void(__cdecl*)())0x0084C9A0)();
}

__declspec(naked) void PartyListBGColor_1()
{
	static DWORD var_addr = 0x0084B6E5;
	static DWORD var_list1 = (DWORD)&g_pPartyManager.iPartyListBGColor;
	static DWORD var_list2 = (DWORD)&g_pPartyManager.bPartyMemberoutofSight;

	_asm
	{
		mov       eax, dword ptr ss : [var_list1]
		mov       dword ptr ds : [eax + edx] , 0
		mov       ecx, dword ptr ss : [var_list2]
		add       ecx, dword ptr ss : [ebp - 0x10]
		mov       byte ptr ds : [ecx] , 0
		jmp[var_addr]
	}
}

void CPartyManager::SetListBGColor(DWORD* This)
{
	int result;
	int i;

	PARTY_D* p = (PARTY_D*)&PartyArray;
	for (i = 0; i < PartyNumber; ++i)
	{
		g_pPartyManager.iPartyListBGColor[i] = PARTY_LIST_BGCOLOR_DEFAULT;

		if (p[i].index == -1)
		{
			g_pPartyManager.iPartyListBGColor[i] = PARTY_LIST_BGCOLOR_RED;
		}
		if (p[i].index > -1)
		{
			g_pPartyManager.iPartyListBGColor[i] = PARTY_LIST_BGCOLOR_GREEN;
		}
	}
}

bool CPartyManager::BtnProcess(DWORD This)
{
	int x = *(DWORD*)(This + 16);
	int y = *(DWORD*)(This + 20);

	if (PartyNumber <= 5)
	{
		g_pPartyManager.pbyPagekey = 0;
	}

	if (IsRelease(VK_LBUTTON) && pCheckInMouse(x + 131, y + 395, 17, 18) && (PartyNumber > 5))
	{
		g_pPartyManager.pbyPagekey = (g_pPartyManager.pbyPagekey == 0) ? 1 : 0;
		return true;
	}
	else if (IsRelease(VK_LBUTTON) && pCheckInMouse(x + 153, y + 395, 17, 18) && (PartyNumber > 5))
	{
		g_pPartyManager.pbyPagekey = (g_pPartyManager.pbyPagekey == 1) ? 0 : 1;
		return true;
	}
	else if (IsRelease(VK_LBUTTON) && pCheckInMouse(x + 169, y + 7, 13, 12))
	{
		g_pNewUISystem->Hide(SEASON6B::INTERFACE_PARTY);
		return true;
	}
	else if (UpdateBtnMouseEvent((BYTE*)(This + 24)) == 1)
	{
		g_pNewUISystem->Hide(SEASON6B::INTERFACE_PARTY);
		return true;
	}
	else
	{
		if ((unsigned __int8)(*(int(__thiscall**)(int))(*(DWORD*)This + 24))(This))
		{
			PARTY_D* party = (PARTY_D*)&PartyArray;
			int iIndex = 0;

			for (int i = 0; i < PartyNumber; ++i)
			{
				iIndex = (g_pPartyManager.pbyPagekey == 1 && i >= 5) ? (i - 5) : i;

				if (!strcmp(party[0].Name, (char*)(Hero + 56)) || !strcmp(party[i].Name, (char*)(Hero + 56)))
				{
					if (UpdateBtnMouseEvent((BYTE*)(This + 172 * iIndex + 196)))
					{
						LeaveParty(This, i);
						return true;
					}
				}
			}
		}
	}
	return false;
}

void btnProgress(int Image, float x, float y, bool active)
{
	if (pCheckInMouse(x, y, 17, 18) && MouseLButton)
	{
		RenderImageD(Image, x, y, 17.f, 18.f, 0.0, 18.f);
	}
	else
	{
		RenderImageD(Image, x, y, 17.f, 18.f, 0.0, (active == true) ? 0.0 : 18.f);
	}
}

void CPartyManager::RenderMemberStatue(DWORD* This, int iIndex, int pMember, bool bExitBtnRender)
{
	float x = (float)This[4];
	float y = (float)This[5] + 395.f;

	btnProgress(31658, x + 131.f, y, (PartyNumber > 5));
	btnProgress(31659, x + 153.f, y, (PartyNumber > 5));

	if (g_pPartyManager.pbyPagekey == 0 && iIndex >= 5)
	{
		return;
	}
	else if (g_pPartyManager.pbyPagekey == 1)
	{
		if (iIndex < 5) { return; }
		iIndex -= 5;
	}
	RenderMember_Statue(This, iIndex, pMember, bExitBtnRender);
}

__declspec(naked) void PartyListButton_1()
{
	static DWORD var_addr = 0x0084B64E;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, dword ptr ss : [var_25C]
		push      ecx
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton_2()
{
	static DWORD var_addr = 0x0084B76B;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, dword ptr ss : [var_25C]
		push      ecx
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton1()
{
	static DWORD var_addr = 0x0084B81D;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, [var_25C]
		lea       ecx, [ecx + eax]
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton2()
{
	static DWORD var_addr = 0x0084B85B;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, [var_25C]
		lea       ecx, [ecx + eax]
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton3()
{
	static DWORD var_addr = 0x0084B943;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, dword ptr ss : [var_25C]
		lea       ecx, dword ptr ds : [ecx + eax]
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton4()
{
	static DWORD var_addr = 0x0084BA08;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       edx, dword ptr ss : [var_25C]
		lea       ecx, dword ptr ds : [edx + ecx]
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton5()
{
	static DWORD var_addr = 0x0084BBC4;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       eax, dword ptr ss : [var_25C]
		lea       ecx, dword ptr ds : [eax + edx]
		jmp[var_addr]
	}
}

__declspec(naked) void PartyListButton6()
{
	static DWORD var_addr = 0x0084C41E;
	static DWORD var_25C = (DWORD)&g_pPartyManager.BtnPartyExit;

	_asm
	{
		mov       ecx, dword ptr ss : [var_25C]
		lea       ecx, dword ptr ds : [ecx + eax]
		jmp[var_addr]
	}
}

__declspec(naked) void RenderizarFlag()
{
	static DWORD addr_jmp = 0x0084AE59;

	if (g_pPartyManager.pbyPagekey == 0)
	{
		addr_jmp = 0x0084ADAF;
	}
	else
	{
		addr_jmp = 0x0084AE59;
	}
	_asm
	{
		mov     edx, dword ptr ds : [0xE8C58C]
		push    edx
		jmp[addr_jmp]
	}
}

void CPartyManager::Init()
{
	SetCompleteHook(0xE9, 0x0084ADA8, &RenderizarFlag);
	//-- change structu life
	SetByte(0x0064E1DE + 2, sizeof(PRECEIVE_PARTY_LIST)); //-- sizebuttonparty
	//-- PartyList Process
	SetCompleteHook(0xE9, 0x0084B6CA, &PartyListBGColor_1);
	SetCompleteHook(0xE9, 0x0084BAB0, &CPartyManager::SetListBGColor);
	//-- PartyInfo Process
	SetCompleteHook(0xE8, 0x0084B7D3, &CPartyManager::LoadImages);
	SetCompleteHook(0xE8, 0x0084A3BA, &CPartyManager::BtnProcess);
	SetCompleteHook(0xE8, 0x0084A757, &CPartyManager::RenderMemberStatue);
	//--
	SetCompleteHook(0xE9, 0x0084B816, &PartyListButton1);
	SetCompleteHook(0xE9, 0x0084B854, &PartyListButton2);
	SetCompleteHook(0xE9, 0x0084B93C, &PartyListButton3);
	SetCompleteHook(0xE9, 0x0084BA01, &PartyListButton4);
	SetCompleteHook(0xE9, 0x0084BBBD, &PartyListButton5);
	SetCompleteHook(0xE9, 0x0084C417, &PartyListButton6);
	SetCompleteHook(0xE9, 0x0084B647, &PartyListButton_1);
	SetCompleteHook(0xE9, 0x0084B764, &PartyListButton_2);
	//--
	static float Flagwidth = 9.f;
	static float Flagheight = 10.f;
	SetDword(0x0084AE06 + 2, (DWORD)&Flagwidth); //-- sizeback
	SetDword(0x0084ADFC + 2, (DWORD)&Flagheight); //-- sizeback
	SetByte(0x0084A19A + 1, 11); //-- sizebuttonparty
	SetByte(0x0084A19C + 1, 11); //-- sizebuttonparty
	SetByte(0x0084B1E2 + 1, 11); //-- sizebuttonparty
	SetByte(0x0084B1E4 + 1, 11); //-- sizebuttonparty
	//--
	SetByte(0x0084B640 + 1, MAX_PARTYS); //-- Create PartyList Button1
	SetByte(0x0084B6C1 + 3, MAX_PARTYS); //-- Create PartyList BGColor
	//--
	SetByte(0x0084B75D + 1, MAX_PARTYS); //-- Releas PartyList Button1
	SetByte(0x0084B7EA + 3, MAX_PARTYS); //-- Move PartyList Button1
	SetByte(0x0084B901 + 3, MAX_PARTYS); //-- Update PartyList Button2
	SetByte(0x0084B9B9 + 3, MAX_PARTYS); //-- Render PartyList Button3
	//--
	SetDword(0x0051C3D6, (DWORD)&PartyArray);
	SetDword(0x0051C4D7, (DWORD)&PartyArray);
	SetDword(0x0051C62B, (DWORD)&PartyArray);
	SetDword(0x00578DC2, (DWORD)&PartyArray);
	SetDword(0x005A7B4D, (DWORD)&PartyArray);
	SetDword(0x005B7C04, (DWORD)&PartyArray);
	SetDword(0x005B7F65, (DWORD)&PartyArray);
	SetDword(0x005BA7B9, (DWORD)&PartyArray);
	SetDword(0x0064E173, (DWORD)&PartyArray);
	SetDword(0x0064E242, (DWORD)&PartyArray);
	SetDword(0x0064E398, (DWORD)&PartyArray);
	SetDword(0x0064E3B1, (DWORD)&PartyArray);
	SetDword(0x0078F28B, (DWORD)&PartyArray);
	SetDword(0x0084A33D, (DWORD)&PartyArray);
	SetDword(0x0084A35E, (DWORD)&PartyArray);
	SetDword(0x0084A6FB, (DWORD)&PartyArray);
	SetDword(0x0084A711, (DWORD)&PartyArray);
	SetDword(0x0084A732, (DWORD)&PartyArray);
	SetDword(0x0084BB82, (DWORD)&PartyArray);
	SetDword(0x0084BBA3, (DWORD)&PartyArray);
	SetDword(0x0084BC84, (DWORD)&PartyArray);
	SetDword(0x0084C24B, (DWORD)&PartyArray);
	SetDword(0x0084C301, (DWORD)&PartyArray);
	SetDword(0x0084C3D9, (DWORD)&PartyArray);
	SetDword(0x0084C3FB, (DWORD)&PartyArray);
	SetDword(0x0084C48F, (DWORD)&PartyArray);
	SetDword(0x0091CCED, (DWORD)&PartyArray);
	//--
	SetDword(0x0084BAA4 + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BAED + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BB0D + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BC39 + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BD9D + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BEF7 + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084BF9A + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084C18A + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0084C28C + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0095FEAA + 2, (DWORD)(PartyArray + 28));
	SetDword(0x0095FF91 + 2, (DWORD)(PartyArray + 28));
	//--
	SetDword(0x0084C33D + 3, (DWORD)(PartyArray + 24));
	SetDword(0x0084C358 + 3, (DWORD)(PartyArray + 24));
	SetDword(0x0095FED9 + 3, (DWORD)(PartyArray + 24));
	SetDword(0x0084B11F + 3, (DWORD)(PartyArray + 11));
}