#include "stdafx.h"
#if WINDOWS_QUEST
#include "WindowsQuest.h"
#include "Interface.h"
#include "Protocol.h"
#include "Item.h"
#include "Offset.h"
#include "Item.h"
#include "Defines.h"
#include "CustomMap.h"
#include "Common.h"
#include "Protect.h"
#include "Central.h"

// ----------------------------------------------------------------------------------------------

WinQuestSystem gWinQuestSystem;
// ----------------------------------------------------------------------------------------------

WinQuestSystem::WinQuestSystem()
{
	this->Init();
}
// ----------------------------------------------------------------------------------------------

WinQuestSystem::~WinQuestSystem()
{
	// --
}
// ----------------------------------------------------------------------------------------------

void WinQuestSystem::Init()
{
	// --
	this->DrawMiniInfoFlag = false;
	ZeroMemory(&this->ewdata, sizeof(this->ewdata));
}
// ----------------------------------------------------------------------------------------------

void WinQuestSystem::Load()
{
	this->Init();
}
// ----------------------------------------------------------------------------------------------

void WinQuestSystem::ImageLoad()
{
	pLoadImage("Custom\\Interface\\Party_info_block.tga", ex_INFO_2, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\newui_cha_textbox03.tga", ex_TEXT_BOX3, 0x2601, 0x2900, 1, 0);
}
// ----------------------------------------------------------------------------------------------

void WinQuestSystem::BindImages()
{
	int eWHig;

	eWHig = 423;
	gInterface.BindObject(OBJECT_WIN_QUEST_FINISH, 0x7A62, 90, 15.5, -1, -1); //Boton Accept Quest
	gInterface.BindObject(OBJECT_WIN_QUEST_MAIN, 0x7A5A, 222, eWHig, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_DIV, 0x7A62, 223, 21, -1, -1); //Dividor lineas 
	gInterface.BindObject(OBJECT_WIN_QUEST_CLOSE, 51522, 16, 16, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_TAB, 51522, 166, 22, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_TAB1, 51522, 70, 15, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_TAB2, 51522, 70, 15, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_TAB3, 51522, 70, 15, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_COUNT1, 0x7BAC, 168, 18, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_COUNT2, 0x7BAC, 168, 18, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_COUNT3, 0x7BAC, 168, 18, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_INFOBG, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_INFOBG2, 0x7AA1, 170, 22, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_LINE1, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_POINT1, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_INFO, ex_INFO_2, 22, 19, -1, -1);
	gInterface.BindObject(OBJECT_WIN_QUEST_INFOBG3, ex_TEXT_BOX3, 170, 21, -1, -1);
	gInterface.BindObject(OPEN_QUEST, 0x7904, 25, 40, -1, -1);
}
// ----------------------------------------------------------------------------------------------

void WinQuestSystem::Draw()
{
	if (!gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	pSetBlend(true);

	int a = this->OpenTab;

	//	int Addradd = pWinWidth / pWinHeightReal / 2 - 320;
	DWORD ItemNameColor = eWhite;
	float MainWidth = 210.0;
	float MainHeight = 400.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	float ContentX = StartX;
	float ContentY = StartY;

	float TabX = StartX + 30;
	float TabY = ContentY + 30 + 5;
	float InfoX = 0;
	float InfoY = 0;
	int InfoA = 0;
	int InfoM = 0;
	int bColor = 0;
	//--
	gInterface.Data[OBJECT_WIN_QUEST_MAIN].MaxX = StartX + MainWidth;
	gInterface.Data[OBJECT_WIN_QUEST_MAIN].MaxY = StartY + MainHeight;

	gCentral.DrawDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.DrawFormat(eBlue250, (int)StartX, (int)StartY + 10, 210, 3, "Windows Quest");



	gInterface.DrawGUI(OBJECT_WIN_QUEST_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_WIN_QUEST_CLOSE].Width - 5, ContentY + 5);
	gCentral.DrawDropBox(StartX + MainWidth - gInterface.Data[OBJECT_WIN_QUEST_CLOSE].Width - 5, ContentY + 5, 16, 16, 0, 0);
	gInterface.DrawText603(eRed, StartX + MainWidth - gInterface.Data[OBJECT_WIN_QUEST_CLOSE].Width - 26, ContentY + 8, 60, 3, "X");
	// ----
	if (gInterface.IsWorkZone(OBJECT_WIN_QUEST_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_WIN_QUEST_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_WIN_QUEST_CLOSE, gInterface.Data[OBJECT_WIN_QUEST_CLOSE].X, gInterface.Data[OBJECT_WIN_QUEST_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_WIN_QUEST_CLOSE].X + 5, gInterface.Data[OBJECT_WIN_QUEST_CLOSE].Y + 25, "Close");
	}
	// ------------------------------------
	if (this->OpenTab == 0)
	{
		gInterface.DrawGUI(OBJECT_WIN_QUEST_TAB1, TabX, TabY);
		gCentral.DrawDropBox(TabX, TabY, 70, 15, 0, 0);

		gInterface.DrawGUI(OBJECT_WIN_QUEST_TAB2, TabX + 80, TabY);
		gCentral.DrawDropBox(TabX + 80, TabY, 70, 15, 0, 0);
	}
	else if (this->OpenTab == 1)
	{
		gInterface.DrawGUI(OBJECT_WIN_QUEST_TAB1, TabX, TabY);
		gCentral.DrawDropBox(TabX, TabY, 70, 15, 0, 0);

		gInterface.DrawGUI(OBJECT_WIN_QUEST_TAB2, TabX + 80, TabY);
		gCentral.DrawDropBox(TabX + 80, TabY, 70, 15, 0, 0);
	}

	if (this->ewdata[0].b_End)
	{
		gInterface.DrawText603(eRed, TabX + 2, TabY + 3, 60, 3, "Off");
	}
	else
	{
		gInterface.DrawText603(eGold, TabX + 2, TabY + 3, 60, 3, "first Quest");


	}
	if (this->ewdata[1].b_End)
	{
		gInterface.DrawText603(eRed, TabX + 80, TabY + 3, 60, 3, "Off");
	}
	else
	{
		gInterface.DrawText603(eGold, TabX + 82, TabY + 3, 60, 3, "second Quest");
	}

	// ------------------------------------
	// -> End Quest
	// ------------------------------------
	if (this->ewdata[a].b_End)
	{
		float EndY = ContentY + 53;
		gInterface.DrawGUI(OBJECT_WIN_QUEST_INFOBG3, StartX + 30, EndY + 12);
		gInterface.DrawText603(eAncient, ContentX + 30, EndY + 17, 170, 3, "End");
		gInterface.Data[OBJECT_WIN_QUEST_FINISH].Attribute = false;
		return;
	}
	// ------------------------------------
	// -> Content Need
	// ------------------------------------
	float NeededY = ContentY + 53;

	gInterface.DrawText603(eAncient, ContentX + 20, TabY + 20, 180, 3, "%s", this->ewdata[a].NameQuest);

	gCentral.DrawDropBox(StartX + 5, TabY + 37, 200, 0.5, 0, 0); // Divisor 1

	gInterface.DrawText603(eAncient, ContentX + 20, TabY + 36, 170, 3, "Requisitos");

	float CountNeededY = NeededY + 30;

	gInterface.DrawText603(eWhite, StartX + 30, CountNeededY + 6, 100, 1, "Level:");

	if (this->ewdata[a].b_Level)
	{
		bColor = eGold;
	}
	else
	{
		bColor = eRed;
	}

	gInterface.DrawText603(bColor, StartX + 60, CountNeededY + 6, 100, 1, "%d", this->ewdata[a].NeedLevel);
	gInterface.DrawText603(eWhite, StartX + 90, CountNeededY + 6, 100, 1, "Reset:");

	if (this->ewdata[a].b_Reset)
	{
		bColor = eGold;
	}
	else
	{
		bColor = eRed;
	}

	gInterface.DrawText603(bColor, StartX + 120, CountNeededY + 6, 100, 1, "%d", this->ewdata[a].NeedReset);
	gInterface.DrawText603(eWhite, StartX + 150, CountNeededY + 6, 100, 1, "GReset:");

	if (this->ewdata[a].b_Grand)
	{
		bColor = eGold;
	}
	else
	{
		bColor = eRed;
	}

	gInterface.DrawText603(bColor, StartX + 185, CountNeededY + 6, 100, 1, "%d", this->ewdata[a].NeedGrand);

	CountNeededY += 21;
	// ------------------------------------
	// -> Content Mission
	// ------------------------------------
	float MissionX = StartX - 10;
	float MissionY = ContentY + 53 + 40;

	MissionY += 10;

	float CountMissionY = MissionY + 20;

	//----------------------------------------------------

	for (int m = 0; m < EW_MAX_MISSION; m++)
	{
		if (this->ewdata[a].MissionType[m] == Hunting ||
			this->ewdata[a].MissionType[m] == Droping ||
			this->ewdata[a].MissionType[m] == Searching)
		{
			if (this->ewdata[a].b_Mission[m])
			{
				bColor = eExcellent;
			}
			else
			{
				bColor = eWhite;
			}

			CountMissionY += 10;

			if (this->ewdata[a].MissionType[m] == Hunting)
			{
				if (this->ewdata[a].MissionID[m] == 65535)
				{
					gInterface.DrawText603(bColor, MissionX + 30 + 5 + 15, CountMissionY, 200, 1, "- Kill Level %d~%d: %d/%d",
						this->ewdata[a].MissionOpt[m], this->ewdata[a].MissionExl[m], this->ewdata[a].Count[m], this->ewdata[a].MissionCount[m]);
				}
				else
				{
					gInterface.DrawText603(bColor, MissionX + 30 + 5 + 15, CountMissionY, 200, 1, "- %s: %d/%d", pGetMonsterName(this->ewdata[a].MissionID[m]/*gMonster.GetMonsterName(this->ewdata[a].MissionID[m]*/), this->ewdata[a].Count[m], this->ewdata[a].MissionCount[m]);
				}
			}
			else if (this->ewdata[a].MissionType[m] == Droping)
			{
				gInterface.DrawText603(bColor, MissionX + 30 + 5 + 15, CountMissionY, 200, 1, "- %s: %d/%d", getItemName(GET_ITEM(this->ewdata[a].MissionID[m], this->ewdata[a].MissionIndex[m])), ewdata[a].Count[m], ewdata[a].MissionCount[m]);
			}
			else if (this->ewdata[a].MissionType[m] == Searching)
			{
				gInterface.DrawText603(bColor, MissionX + 30 + 5 + 15, CountMissionY, 200, 1, "- %s (%d)", getItemName(GET_ITEM(this->ewdata[a].MissionID[m], this->ewdata[a].MissionIndex[m])), this->ewdata[a].MissionCount[m]);
			}
		}
	}
	// ------------------------------------
	// -> Content Reward
	// ------------------------------------
	float RewardY = ContentY + 53 + 100 + 42 + 15;

	gCentral.DrawDropBox(StartX + 5, RewardY, 200, 0.5, 0, 0);

	gInterface.DrawText603(eAncient, ContentX + 20, RewardY + 6, 170, 3, "Reward");

	float CountRewardY = RewardY + 34 - 4;

	for (int r = 0; r < EW_MAX_REWARD; r++)
	{
		if (this->ewdata[a].RewardType[r] == ewZen ||
			this->ewdata[a].RewardType[r] == ewFreePoint ||
			this->ewdata[a].RewardType[r] == ewItem ||
			this->ewdata[a].RewardType[r] == ewBonus ||
			this->ewdata[a].RewardType[r] == ewBuff)
		{
			if (this->ewdata[a].RewardType[r] == ewZen)
			{
				char RewardMSG[64] = { 0 };
				gInterface.DrawText603(eWhite, StartX + 30 + 5, CountRewardY + 5, 100, 1, "Zen:");
				pGetMoneyFormat((double)(int)this->ewdata[a].RewardCount[r], RewardMSG, 0);
				gInterface.DrawText603(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", RewardMSG);
			}
			else if (this->ewdata[a].RewardType[r] == ewFreePoint)
			{
				gInterface.DrawFormat(eWhite, StartX + 30 + 5, CountRewardY + 5, 100, 1, "Lvl Point:");
				gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%d", this->ewdata[a].RewardCount[r]);
			}
			else if (this->ewdata[a].RewardType[r] == ewItem)
			{

				ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(this->ewdata[a].RewardItemType[r], this->ewdata[a].RewardItemIndex[r]));


				const int WidthValue = 24;
				const int HeightValue = 26;
				float barWidth = WidthValue * ItemInfo->ItemWidth;
				float barHeight = HeightValue * ItemInfo->ItemHeight;

				if (this->ewdata[a].RewardItemLevel[r] > 0)
				{
					gInterface.DrawText603(eGold, StartX + 20, CountRewardY + 5, 100, 3, "- %s +%d x%d",
						getItemName(GET_ITEM(this->ewdata[a].RewardItemType[r], this->ewdata[a].RewardItemIndex[r])), this->ewdata[a].RewardItemLevel[r], this->ewdata[a].RewardCount[r]);
				}
				else
				{
					gInterface.DrawText603(eGold, StartX + 20, CountRewardY + 5, 100, 3, "- %s x %d",
						getItemName(GET_ITEM(this->ewdata[a].RewardItemType[r], this->ewdata[a].RewardItemIndex[r])), this->ewdata[a].RewardCount[r]);
				}

				//	ObjectItem* item_data = (ObjectItem*)&item__;

				if (pCheckMouseOver((int)(StartX + 20), (int)(CountRewardY + 5), 100, 7))
				{
					NewModelRender3D(StartX + 155, ContentX + 40, barWidth, barHeight, GET_ITEM(this->ewdata[a].RewardItemType[r], this->ewdata[a].RewardItemIndex[r]), this->ewdata[a].RewardItemLevel[r], 1, 0, 0);

					//Tooltip imcompleto
				/*	JCCoord B;

					B.X = 196;
					B.Y = (int)130;

					sub_7E3E30(*(DWORD*)(GetInstance() + 308), B, (int)item_data, 0, 0, 0);

					pSetBlend(false);*/
				}
			}
			else if (this->ewdata[a].RewardType[r] == ewBonus)
			{
				gInterface.DrawFormat(eWhite, StartX + 30 + 5, CountRewardY + 5, 100, 1, "WCoin:");
				gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%d", this->ewdata[a].RewardCount[r]);
			}
			else if (this->ewdata[a].RewardType[r] == ewBuff)
			{
				gInterface.DrawText603(eWhite, StartX + 30 + 5, CountRewardY + 5, 100, 1, "Buff:");

				switch (this->ewdata[a].RewardItemType[r])
				{
				case 1:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Experience: + 15%%");
					break;
				case 2:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Dmg: +10%%/Wizard Dmg: +10%%");
					break;
				case 3:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Defence: +10%%");
					break;
				case 4:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Exel Dmg Rate: +5%%/Ctcal Dmg Rate: +5%%");
					break;
				case 5:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Zen Drop: +50%%");
					break;
				case 6:
					gInterface.DrawFormat(eGold, StartX + 30 + 70, CountRewardY + 5, 100, 3, "%s", "Double Damage: +5%%");
					break;
				}
			}

			CountRewardY += 21;
		}
	}
	// ------------------------------------
	// -> Finish
	// ------------------------------------
	bool Finish = 0;

	if (this->ewdata[a].Start)
	{
		Finish = this->ewdata[a].b_done;
	}
	else
	{
		Finish = this->ewdata[a].b_accept;
	}

	//------
	if (gInterface.IsWorkZone(OBJECT_WIN_QUEST_FINISH))
	{
		if (gInterface.Data[OBJECT_WIN_QUEST_FINISH].OnClick)
		{
			gInterface.DrawButtonRender(OBJECT_WIN_QUEST_FINISH, StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 0, 28);
			gCentral.DrawDropBox(StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 108, 20, 0, 0);
		}
		else
		{
			gInterface.DrawButtonRender(OBJECT_WIN_QUEST_FINISH, StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 0, 0);
			gCentral.DrawDropBox(StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 108, 20, 0, 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(OBJECT_WIN_QUEST_FINISH, StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 0, 0);
		gCentral.DrawDropBox(StartX + (MainWidth / 2) - (110 / 2), StartY + MainHeight - 32, 108, 20, 0, 0);
	}

	if (this->ewdata[a].Start)
	{

		gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (70 / 2), StartY + MainHeight - 25, 59, 3, "Done");

	}
	else
	{

		gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (70 / 2), StartY + MainHeight - 25, 59, 3, "Accept");

	}
	//------
	if (!Finish)
	{
		gInterface.Data[OBJECT_WIN_QUEST_FINISH].Attribute = false;
	}
	else
	{
		// ----
		gInterface.Data[OBJECT_WIN_QUEST_FINISH].Attribute = true;
		// ----
	}

	pSetBlend(false);
}

void WinQuestSystem::DrawMiniInfo()
{

	try
	{
		if (gInterface.MiniMapCheck() || gInterface.CheckWindow(FullMap)
			|| gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree)
			|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu)
			|| gInterface.CheckWindow(Character))
		{
			return;
		}

		/*		if (gProtect.m_MainInfo.MiniMapType == 1)
				{
					if (MiniMap == 1)
					{
						return;
					}
				}
		*/
		int qCount = 0;
		int mCount = 0;
		bool DrInfo = false;

		for (int a = 0; a < EW_MAX_ACT; a++)
		{
			if (this->ewdata[a].Start == TRUE)
			{
				qCount += 15;

				for (int m = 0; m < EW_MAX_MISSION; m++)
				{
					if (this->ewdata[a].MissionType[m] == Hunting ||
						this->ewdata[a].MissionType[m] == Droping ||
						this->ewdata[a].MissionType[m] == Searching)
					{
						mCount += 10;
						DrInfo = true;
					}
				}
			}
		}

		if (DrInfo == false)
		{

			return;
		}

		float iX = 530; //posicion MiniInfoQuest
		float iY = 320; //posicion MiniInfoQuest
		float Wind = 100; //posicion MiniInfoQuest
		float Hig = qCount + mCount;

		float StartiY = 420; //posicion MiniInfoQuest

		iY = StartiY - Hig;

		pSetBlend(true);

		pDrawColorButton(0x7980, iX, iY, Wind, Hig, NULL, NULL, Color4f(0, 0, 0, 100));

		iY += 3;

		for (int a = 0; a < EW_MAX_ACT; a++)
		{
			if (this->ewdata[a].Start == TRUE)
			{
				gInterface.DrawText603(eOrange, iX + 2, iY, 200, 2, "%s", this->ewdata[a].NameQuest);

				for (int m = 0; m < EW_MAX_MISSION; m++)
				{
					if (this->ewdata[a].MissionType[m] == Hunting ||
						this->ewdata[a].MissionType[m] == Droping ||
						this->ewdata[a].MissionType[m] == Searching)
					{
						iY += 10;

						if (this->ewdata[a].MissionType[m] == Hunting)
						{
							if (this->ewdata[a].MissionID[m] == 65535)
							{
								gInterface.DrawText603(eWhite, iX + 2, iY, 200, 2, "- Kill Level %d~%d: %d/%d",
									this->ewdata[a].MissionOpt[m], this->ewdata[a].MissionExl[m], this->ewdata[a].Count[m], this->ewdata[a].MissionCount[m]);
							}
							else
							{
								gInterface.DrawText603(eWhite, iX + 2, iY, 200, 2, "- %s: %d/%d", pGetMonsterName(this->ewdata[a].MissionID[m]/*gMonster.GetMonsterName(this->ewdata[a].MissionID[m]*/), this->ewdata[a].Count[m], this->ewdata[a].MissionCount[m]);
							}
						}
						else if (this->ewdata[a].MissionType[m] == Droping)
						{
							gInterface.DrawText603(eWhite, iX + 2, iY, 200, 2, "- %s: %d/%d", getItemName(GET_ITEM(this->ewdata[a].MissionID[m], this->ewdata[a].MissionIndex[m])), ewdata[a].Count[m], ewdata[a].MissionCount[m]);
						}
						else if (this->ewdata[a].MissionType[m] == Searching)
						{
							gInterface.DrawText603(eWhite, iX + 2, iY, 200, 2, "- %s (%d)", getItemName(GET_ITEM(this->ewdata[a].MissionID[m], this->ewdata[a].MissionIndex[m])), this->ewdata[a].MissionCount[m]);
						}
					}
				}

				iY += 15;
			}
		}

		pSetBlend(false);
	}
	catch (...)
	{
	}
}
//// ----------------------------------------------------------------------------------------------
void WinQuestSystem::DrawOpenWQ()
{
	if (gInterface.Data[OPEN_QUEST].OnShow)
	{
		gInterface.Data[OPEN_QUEST].OnShow = false;
	}

	if (gInterface.MiniMapCheck() || gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu)
		|| gInterface.CheckWindow(Character))
	{
		return;
	}


	//	  int Addradd = pWinWidth / pWinHeightReal / 2 - 320;

	gInterface.Data[OPEN_QUEST].OnShow = true;

	gInterface.DrawGUI(OPEN_QUEST, 610, 200);

	if (gInterface.IsWorkZone(OPEN_QUEST))
	{
		pSetCursorFocus = true; // Bloqueo de Cursor Al Señalar :)
		gInterface.DrawToolTip(520, 210, "WINDOWS QUEST");
		// ----
		if (gInterface.Data[OPEN_QUEST].OnClick)
		{
			gInterface.DrawColoredGUI(OPEN_QUEST, 610, 200, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		gInterface.DrawColoredGUI(OPEN_QUEST, 610, 200, pMakeColor(255, 204, 20, 200));
	}

}
//
int WinQuestSystem::Button(DWORD Event)
{
	if (gInterface.ButtonEx(Event, OPEN_QUEST, false))
	{
		if (gInterface.MiniMapCheck() || gInterface.CheckWindow(FullMap)
			|| gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree)
			|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu)
			|| gInterface.CheckWindow(Character))
		{
			return 0;
		}

		PMSG_CHARACTER_LIST_SEND pMsg;
		pMsg.header.set(0xDE, 0x21, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.header.size);
		return true;
	}

	if (!gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow)
	{
		return false;
	}

	if (gInterface.ButtonEx(Event, OBJECT_WIN_QUEST_FINISH, true))
	{
		this->CG_AcñeptQuest();

		return true;
	}
	else if (gInterface.ButtonEx(Event, OBJECT_WIN_QUEST_CLOSE, false))
	{
		pSetCursorFocus = false;
		gInterface.Data[OBJECT_WIN_QUEST_MAIN].Close();

		return true;
	}
	else if (gInterface.ButtonEx(Event, OBJECT_WIN_QUEST_TAB1, false))
	{
		this->OpenTab = 0;

		return true;
	}
	else if (gInterface.ButtonEx(Event, OBJECT_WIN_QUEST_TAB2, false))
	{
		this->OpenTab = 1;

		return true;
	}
	else if (gInterface.ButtonEx(Event, OBJECT_WIN_QUEST_TAB3, false))
	{
		this->OpenTab = 2;

		return true;
	}

	return false;
}
//// ----------------------------------------------------------------------------------------------
//
void WinQuestSystem::GC_RecvMain(GC_MainPacket* aRecv)
{
	for (int a = 0; a < EW_MAX_ACT; a++)
	{
		strncpy(this->ewdata[a].NameQuest, aRecv->xQuest[a].NameQuest, 25);
		this->ewdata[a].b_accept = aRecv->xQuest[a].b_accept;
		this->ewdata[a].b_done = aRecv->xQuest[a].b_done;
		this->ewdata[a].b_End = aRecv->xQuest[a].b_End;
		// -> user send
		this->ewdata[a].Start = aRecv->xQuest[a].Start;
		this->ewdata[a].Number = aRecv->xQuest[a].Number;
		for (int m = 0; m < EW_MAX_MISSION; m++)
		{
			this->ewdata[a].Count[m] = aRecv->xQuest[a].Count[m];
		}
		// -> need send
		this->ewdata[a].b_Level = aRecv->xQuest[a].b_Level;
		this->ewdata[a].b_Reset = aRecv->xQuest[a].b_Reset;
		this->ewdata[a].b_Grand = aRecv->xQuest[a].b_Grand;

		this->ewdata[a].NeedLevel = aRecv->xQuest[a].NeedLevel;
		this->ewdata[a].NeedReset = aRecv->xQuest[a].NeedReset;
		this->ewdata[a].NeedGrand = aRecv->xQuest[a].NeedGrand;
		// -> mission send
		for (int m = 0; m < EW_MAX_MISSION; m++)
		{
			this->ewdata[a].b_Mission[m] = aRecv->xQuest[a].b_Mission[m];
			this->ewdata[a].MissionType[m] = aRecv->xQuest[a].MissionType[m];
			this->ewdata[a].MissionID[m] = aRecv->xQuest[a].MissionID[m];
			this->ewdata[a].MissionIndex[m] = aRecv->xQuest[a].MissionIndex[m];
			this->ewdata[a].MissionLevel[m] = aRecv->xQuest[a].MissionLevel[m];
			this->ewdata[a].MissionLuck[m] = aRecv->xQuest[a].MissionLuck[m];
			this->ewdata[a].MissionOpt[m] = aRecv->xQuest[a].MissionOpt[m];
			this->ewdata[a].MissionExl[m] = aRecv->xQuest[a].MissionExl[m];
			this->ewdata[a].MissionCount[m] = aRecv->xQuest[a].MissionCount[m];
			this->ewdata[a].MissionProcent[m] = aRecv->xQuest[a].MissionProcent[m];
		}
		for (int r = 0; r < EW_MAX_REWARD; r++)
		{

			this->ewdata[a].RewardType[r] = aRecv->xQuest[a].RewardType[r];
			this->ewdata[a].RewardCount[r] = aRecv->xQuest[a].RewardCount[r];
			this->ewdata[a].RewardItemType[r] = aRecv->xQuest[a].RewardItemType[r];
			this->ewdata[a].RewardItemIndex[r] = aRecv->xQuest[a].RewardItemIndex[r];
			this->ewdata[a].RewardItemLevel[r] = aRecv->xQuest[a].RewardItemLevel[r];
		}
	}

	if (aRecv->isOpenWindow)
	{
		if (!gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow)
		{
			this->SwitchStatsWindowState();
			pSetCursorFocus = true;
		}
	}

}
//// ----------------------------------------------------------------------------------------------
//
void WinQuestSystem::CG_AcñeptQuest()
{
	CG_Accept_Done pReq = { 0 };
	pReq.h.set(0xDE, 0x0D, sizeof(pReq));
	pReq.Result = this->OpenTab;
	DataSend((LPBYTE)&pReq, pReq.h.size);
}
//// ----------------------------------------------------------------------------------------------
//
void WinQuestSystem::GC_MiniInfoRecv(GC_WinMiniInfo* aRecv)
{
	for (int a = 0; a < EW_MAX_ACT; a++)
	{
		strncpy(this->ewdata[a].NameQuest, aRecv->xQuest[a].NameQuest, 25);

		this->ewdata[a].Start = aRecv->xQuest[a].Start;

		for (int m = 0; m < EW_MAX_MISSION; m++)
		{
			this->ewdata[a].Count[m] = aRecv->xQuest[a].WQuestCount[m];
			this->ewdata[a].MissionType[m] = aRecv->xQuest[a].MissionType[m];
			this->ewdata[a].MissionID[m] = aRecv->xQuest[a].MissionID[m];
			this->ewdata[a].MissionIndex[m] = aRecv->xQuest[a].MissionIndex[m];
			this->ewdata[a].MissionLevel[m] = aRecv->xQuest[a].MissionLevel[m];
			this->ewdata[a].MissionLuck[m] = aRecv->xQuest[a].MissionLuck[m];
			this->ewdata[a].MissionOpt[m] = aRecv->xQuest[a].MissionOpt[m];
			this->ewdata[a].MissionExl[m] = aRecv->xQuest[a].MissionExl[m];
			this->ewdata[a].MissionCount[m] = aRecv->xQuest[a].MissionCount[m];
		}
	}
}
//// ----------------------------------------------------------------------------------------------
//
void WinQuestSystem::GC_MiniInfoRecv(GC_WinMiniInfox* aRecv)
{
	int a = aRecv->a;
	int m = aRecv->m;

	if (a < 0 || a >= EW_MAX_ACT)
	{
		return;
	}

	if (m < 0 && m >= EW_MAX_MISSION)
	{
		return;
	}

	this->ewdata[a].Count[m]++;
}
//// ----------------------------------------------------------------------------------------------
//
void WinQuestSystem::GC_Start(GC_WinStart* aRecv)
{
	int a = aRecv->Act;
	int s = aRecv->Start;

	if (a < 0 || a >= EW_MAX_ACT)
	{
		return;
	}

	if (s == true)
	{
		this->ewdata[a].Start = true;
	}
}
//// ----------------------------------------------------------------------------------------------
#endif