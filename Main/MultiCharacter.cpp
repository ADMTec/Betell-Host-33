#include "stdafx.h"
#if (SELECTCHARACTER==1)
#include "MultiCharacter.h"
#include "Interface.h"
#include "User.h"
#include "Offset.h"
#include "Protocol.h"
#include "Import.h"
#include "Defines.h"
#include "Protect.h"

CSelectChar gSelectChar;


CSelectChar gSelectCharMulti;


CSelectChar::CSelectChar()
{

}
// -------------------------------------------------------------------------------

CSelectChar::~CSelectChar()
{
	// ----
}
//int MultiCharacter = 1;

void CSelectChar::SelectChar()

{
	
	{
		gObjUser.Refresh();

		if (*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
		{
			
			if (gProtect.m_MainInfo.MultiCharacterEnable == 1)
			
			gInterface.DrawFormat(eGold, 299, 428, 40, 3, "Page: %d", gSelectChar.m_CharacterPage);

			if (gSelectCharMulti.m_CharacterPage > 1)
			{
				gInterface.DrawButton(eSELECTCHAR_LEFT, 283, 420, 0, 0);
				gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 420, 0, 0);

				if (gInterface.IsWorkZone(eSELECTCHAR_LEFT))
				{
					DWORD Color = eAncient;
					// ----
					if (gInterface.Data[eSELECTCHAR_LEFT].OnClick)
					{
						Color = eAncient;
					}
					// ----
					gInterface.DrawColoredGUI(eSELECTCHAR_LEFT, gInterface.Data[eSELECTCHAR_LEFT].X, gInterface.Data[eSELECTCHAR_LEFT].Y, Color);
				}
			}
			if (gSelectCharMulti.m_CharacterPage < 2)
			{
				gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 420, 0, 0);
				gInterface.DrawButton(eSELECTCHAR_LEFT, 283, 420, 0, 0);

				if (gInterface.IsWorkZone(eSELECTCHAR_RIGHT))
				{
					DWORD Color = eAncient;
					// ----
					if (gInterface.Data[eSELECTCHAR_RIGHT].OnClick)
					{
						Color = eAncient;
					}
					// ----
					gInterface.DrawColoredGUI(eSELECTCHAR_RIGHT, gInterface.Data[eSELECTCHAR_RIGHT].X, gInterface.Data[eSELECTCHAR_RIGHT].Y, Color);
				}
			}

		}

		((void(__cdecl*)())0x005BB0B0)();
	}
}
// ----------------------------------------------------------------------------------------------

void CSelectChar::EventSelectChar(DWORD Event)
{

if (MultiCharacter == 0)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	// ----
	if (*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		return;
	}
	// ----
	if (gInterface.IsWorkZone(eSELECTCHAR_LEFT))
	{
		if (this->m_CharacterPage <= 1)
		{
			return;
		}

		DWORD Delay = (CurrentTick - gInterface.Data[eSELECTCHAR_LEFT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSELECTCHAR_LEFT].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eSELECTCHAR_LEFT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eSELECTCHAR_LEFT].EventTick = GetTickCount();
		// ----
		this->m_CharacterPage--;
		CGSendMultiChar(this->m_CharacterPage);
		((int(__cdecl*)(int Num)) 0x0057D620)(-1);
		*(BYTE*)0xE8CB4E = 0;
		*(DWORD*)(MAIN_SCREEN_STATE) = SwitchCharacter;
		*(DWORD*)0x87935A4 = 50;
	}
	else if (gInterface.IsWorkZone(eSELECTCHAR_RIGHT))
	{
		if (this->m_CharacterPage >= 2)
		{
			return;
		}

		DWORD Delay = (CurrentTick - gInterface.Data[eSELECTCHAR_RIGHT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSELECTCHAR_RIGHT].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eSELECTCHAR_RIGHT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eSELECTCHAR_RIGHT].EventTick = GetTickCount();
		// ----
		this->m_CharacterPage++;
		CGSendMultiChar(this->m_CharacterPage);
		((int(__cdecl*)(int Num)) 0x0057D620)(-1);
		*(BYTE*)0xE8CB4E = 0;
		*(DWORD*)(MAIN_SCREEN_STATE) = SwitchCharacter;
		*(DWORD*)0x87935A4 = 50;
	}
}
// ----------------------------------------------------------------------------------------------
#endif