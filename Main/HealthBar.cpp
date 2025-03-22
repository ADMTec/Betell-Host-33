#include "stdafx.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Util.h"
#include "Object.h"
#include "User.h"
#include "Defines.h"
#include "MonsterHpBar.h"
#include "Import.h"
#include "CustomRankUser.h"
#include "Protect.h"
#include "Import.h"
#include "Common.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
	}
}

void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = lpInfo->index;
			gNewHealthBar[n].type = lpInfo->type;
			gNewHealthBar[n].rate = lpInfo->rate;
			gNewHealthBar[n].monsterid = lpInfo->monsterid;
			gNewHealthBar[n].Life = lpInfo->Life;
			gNewHealthBar[n].MaxLife = lpInfo->MaxLife;
			gNewHealthBar[n].Level = lpInfo->Level;
			gNewHealthBar[n].Reset = lpInfo->Reset;
			gNewHealthBar[n].Shield = lpInfo->Shield;
			gNewHealthBar[n].MaxShield = lpInfo->MaxShield;
			gNewHealthBar[n].SDrate = lpInfo->SDrate;
			gNewHealthBar[n].isSameGuild = lpInfo->isSameGuild;
			gNewHealthBar[n].HaveGuild = lpInfo->HaveGuild;
			if (lpInfo->type == emPlayer && lpInfo->HaveGuild)
			{
				memcpy(gNewHealthBar[n].GuildName, lpInfo->GuildName, sizeof(gNewHealthBar[n].GuildName));
				char kek[65];

				for (int i = 0; i < 32; i++)
				{
					sprintf(&kek[i * 2], "%02x", lpInfo->Mark[i]);
				}
				kek[64] = '\0';

				for (int i = 0; i < 64; i++)
				{
					if (kek[i] >= 97)
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 87;
					}
					else
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 48;
					}

				}

				//g_Console.AddMessage(5,"Logo setted!");
			}
			return;
		}
	}
}
#include "Interface.h"
#include "Character.h"
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}
void DrawHealthBar(void* item_data)
{
	((void(*)())0x005BA770)();
	int PosX, PosY;
	float LifeBarWidth = 66.95;
	VAngle Angle;

	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		lpViewObj lpObj = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		lpViewObj lpTarget = gObjUser.lpViewTarget;

		bool isTarget = 1;

		if (!lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex)
		{
			isTarget = 0;
		}

		if (!lpObj)
		{
			continue;
		}

		if (lpObj->m_Model.Unknown4 == 0)
		{
			continue;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(lpObj->aIndex, lpObj->m_Model.ObjectType);

		if (lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate / 10;
		float BarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
		float SDBarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

		Angle.X = lpObj->m_Model.VecPos.X;
		Angle.Y = lpObj->m_Model.VecPos.Y;
		Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		pSetBlend(true);

		if (lpNewHealthBar->type == emPlayer/* && istarget*/)
		{
			bool isPartyMember = IsPartyMember(n);
			if (!isTarget && !isPartyMember && !lpNewHealthBar->isSameGuild)
			{
				continue;
			}


			if (isPartyMember)
			{

			}
			else if (lpNewHealthBar->isSameGuild)
			{

			}
			else
			{

			}

			if (!isTarget)
			{

			}
			else
			{

			}

			if (!isTarget)
			{

			}
			else
			{

			}

		}
		else
		{
			if (!isTarget)
			{
				continue;
			}
			CUSTOM_HPBAR* HpBarEx = gMonsterHpBar.GetHpBar(lpNewHealthBar->monsterid);


			RenderBitmap(90014, 496, 0.3, 237.0, 90.0, 0.0, 0.0, 1.0, 0.55, 1, 1, 0.0);

			character.DrawTarget(570, -5, 90, 90);

			if (HpBarEx == 0)
			{

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара

				pDrawBarForm(518, 13.5, 66.95, 6, 0.0, 0); // Фон хпбара

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

				pDrawBarForm(519, 15, BarWidth, 3, 0.0, 0); // ХпБар

				if (!isTarget)
				{
					DrawInterfaceText(lpObj->Name, 517, 2, 66.95, 1, eBlue, 9, 3); // Драв имени
				}
				else
				{
					char Text[100];
					char Text2[100];
					sprintf(Text, "%d", lpNewHealthBar->Level);

					sprintf(Text2, "%2d%%", lpNewHealthBar->rate);

					DrawInterfaceText(lpObj->Name, 517, 2, 67, 1, eExcellent, 9, 3); // Драв имени
					DrawInterfaceText(Text, 475, 2, 67, 1, eBlue, 9, 3); // Драв инфы
					DrawInterfaceText(Text2, 520, 13, 67, 1, eShinyGreen, 9, 3); // Драв инфы
				}

			}
			else
			{

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара

				pDrawBarForm(518, 13.5, 66.95, 6, 0.0, 0); // Фон хпбара

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

				pDrawBarForm(519, 15, BarWidth, 3, 0.0, 0); // ХпБар

				if (!isTarget)
				{
					DrawInterfaceText(lpObj->Name, 517, 2, 66.95, 1, eBlue, 9, 3); // Драв имени
				}
				else
				{
					char Text[100];
					char Text2[100];
					sprintf(Text, "%d", lpNewHealthBar->Level);

					sprintf(Text2, "%2d%%", lpNewHealthBar->rate);

					DrawInterfaceText(lpObj->Name, 517, 2, 67, 1, eExcellent, 9, 3); // Драв имени
					DrawInterfaceText(Text, 475, 2, 67, 1, eBlue, 9, 3); // Драв инфы
					DrawInterfaceText(Text2, 520, 13, 67, 1, eShinyGreen, 9, 3); // Драв инфы
				}
			}

		}

		pGLSwitch();
	}
	gCustomRankUser.DrawInfo();

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}

bool IsPartyMember(int ViewportID)
{


#if (_NEW_PARTY_SYSTEM_ == TRUE )
	for (int PartySlot = 0; PartySlot < g_Party.PartyMemberCount; PartySlot++)
#else
	for (int PartySlot = 0; PartySlot < pPartyMemberCount; PartySlot++)
#endif
	{
		PartyList PartyMember = *(PartyList*)((char*)&pPartyListStruct + sizeof(PartyList) * PartySlot);
		if (ViewportID == PartyMember.ViewportID)
		{
			return true;
		}
	}

	return false;
}