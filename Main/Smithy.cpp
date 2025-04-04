#include "stdafx.h"
#include "Smithy.h"
#include "Interface.h"
#include "Console.h"
#include "Item.h"
#include "User.h"
#include "CustomWing.h"
#include "CustomMessage.h"
#include "Protect.h"
#include "PrintPlayer.h"

CSmithy gSmithy;

CSmithy::CSmithy()
{
	this->Init();
}

CSmithy::~CSmithy()
{
}

void CSmithy::Init()
{
	this->itemdata.clear();
	this->m_AncData.clear();
	this->m_SocketData.clear();
	this->MainPage = 0;
	this->Class = 0;
	this->Category = 0;
	this->CategoryPage = 0;
	this->Item = 0;
	this->ItemLevel = 0;
	this->ItemLuck = false;
	this->ItemAdd = false;
	this->ItemAnc = 0;
	this->ItemOpt1 = false;
	this->ItemOpt2 = false;
	this->ItemOpt3 = false;
	this->ItemOpt4 = false;
	this->ItemOpt5 = false;
	this->ItemOpt6 = false;
	this->ItemSocket = false;
	this->MaxLevel = 0;
	this->AllowAncExce = 0;
	this->LevelPrice = 0;
	this->LuckPrice = 0;
	this->AddPrice = 0;
	this->Opt1Price = 0;
	this->Opt2Price = 0;
	this->Opt3Price = 0;
	this->Opt4Price = 0;
	this->Opt5Price = 0;
	this->Opt6Price = 0;
	this->MaxExlOpt = 0;
	this->AncientPrice = 0;
	this->SocketPrice = 0;
	this->PriceType = 0;
}

void CSmithy::Load()
{
	this->Init();
}

void CSmithy::LoadImg()
{
	pLoadImage("Custom\\Interface\\newui_cha_textbox04.tga", ex_SMITHY_TEXT, 0x2601, 0x2900, 1, 0);
}

void CSmithy::BindImg()
{
	gInterface.BindObject(eSMITHY_MAIN, 0x7A5A, 222, 303 + 26+(15*5), -1, -1);
	gInterface.BindObject(eSMITHY_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eSMITHY_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eSMITHY_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eSMITHY_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eSMITHY_DIV2, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eSMITHY_INFOBG, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eSMITHY_BACK, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT2, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT3, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT4, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT5, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT6, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT7, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT8, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT9, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_TEXT10, ex_SMITHY_TEXT, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_L, 0x7BAA, 17, 17, -1, -1);
	gInterface.BindObject(eSMITHY_R, 0x7BAB, 17, 17, -1, -1);
	gInterface.BindObject(eSMITHY_INFOBG2, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_INFOBG3, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSMITHY_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eSMITHY_POINT, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK0, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK1, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK2, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK3, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK4, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK5, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK6, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECK7, 0x7B69, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEUP, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEDN, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_BT1, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eSMITHY_BT2, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eSMITHY_PAGEDN3, 0x7C0D, 15, 15, -1, -1);

	gInterface.BindObject(eSMITHY_CHECKWIN_MAIN, 0x7A5A, 222, 110, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_OK, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eSMITHY_CHECKWIN_CLOSE, 0x7A5F, 62, 27, -1, -1);
}

void CSmithy::Draw()
{
	if(!gInterface.CheckWindowEx(eSMITHY_MAIN))
	{
		return;
	}

	/*if( gInterface.CheckWindowEx(exWinRanking) ||
	gInterface.CheckWindowEx(exWinPersonalPrice) ||
	gInterface.CheckWindowEx(exWinAchievements) ||
	gInterface.CheckWindowEx(exWinAchievementsPower) ||
	gInterface.CheckWindowEx(exWinWeekQuest) ||
	gInterface.CheckWindowEx(exWinAddPoints) ||
	gInterface.CheckWindowEx(exWinAddResetPoint) ||
	gInterface.CheckWindowEx(exWinBuild) ||
	gInterface.CheckWindowEx(exWinShopPrice) ||
	gInterface.CheckWindowEx(exWinReferralSystem)
	)
	{
	return;
	}*/



	if(this->DrawCheckBuy() == true)
	{
		return;
	}

	pSetCursorFocus = true;

	DWORD Color				= eGray100;
	float MainWidth			= 230.0;
	float StartY			= 5.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (29.0 / 2);
	float CenterX			= StartX + (MainWidth / 2);

	float ContentX = StartX+30;
	float ContentY = StartY+40;

	gInterface.DrawAnimatedGUI(eSMITHY_MAIN, StartX+4, StartY + 4);
	gInterface.DrawAnimatedGUI(eSMITHY_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eSMITHY_FRAME, StartX, StartY + 67.0, 20);
	gInterface.DrawAnimatedGUI(eSMITHY_FOOTER, StartX, StartY);
	gInterface.DrawAnimatedGUI(eSMITHY_CLOSE, StartX + MainWidth - gInterface.Data[eSMITHY_CLOSE].Width, ContentY-40);
	if(gInterface.IsWorkZone(eSMITHY_CLOSE))
	{
		if(gInterface.Data[eSMITHY_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(eSMITHY_CLOSE, gInterface.Data[eSMITHY_CLOSE].X, gInterface.Data[eSMITHY_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[eSMITHY_CLOSE].X + 5, gInterface.Data[eSMITHY_CLOSE].Y + 25, "Close");
	}
	gInterface.DrawFormat(eGold, StartX + 10, ContentY-32, 210, 3, "Donate Shop");




	if(this->MainPage == SMITHY_CLASS)
	{
		for(int i=0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{

			ContentY += 25;
			int objid = eSMITHY_TEXT+i;
			gInterface.DrawAnimatedGUI(objid, ContentX, ContentY);
			if(gInterface.IsWorkZone(objid))
			{
				gInterface.DrawFormat(eGold, ContentX-20, ContentY+5, 210, 3, Menu1[i]);
			}
			else
			{
				gInterface.DrawFormat(eWhite, ContentX-20, ContentY+5, 210, 3, Menu1[i]);
			}

		}

		/*gInterface.DrawFormat(eBlue, ContentX+15, ContentY+25, 150, 1, "If you need special items, contact administrator!");*/
		gInterface.DrawAnimatedGUI(eSMITHY_INFOBG2, ContentX+2, ContentY+35);

		if (PriceType == 0)
		{
		gInterface.DrawFormat(eWhite, ContentX+20, ContentY+40, 210, 1, "Your %s:",gCustomMessage.GetMessage(82));
		gInterface.DrawFormat(eGold, ContentX+115, ContentY+40, 210, 1, "%d", Zen);
		}
		else if (PriceType == 1)
		{
		gInterface.DrawFormat(eWhite, ContentX+20, ContentY+40, 210, 1, "Your %s:",gCustomMessage.GetMessage(83));
		gInterface.DrawFormat(eGold, ContentX+115, ContentY+40, 210, 1, "%d", Coin1);
		}
		else if (PriceType == 2)
		{
		gInterface.DrawFormat(eWhite, ContentX+20, ContentY+40, 210, 1, "Your %s:",gCustomMessage.GetMessage(84));
		gInterface.DrawFormat(eGold, ContentX+115, ContentY+40, 210, 1, "%d", Coin2);
		}
		else if (PriceType == 3)
		{
		gInterface.DrawFormat(eWhite, ContentX+20, ContentY+40, 210, 1, "Your %s:",gCustomMessage.GetMessage(85));
		gInterface.DrawFormat(eGold, ContentX+115, ContentY+40, 210, 1, "%d", Coin3);
		}
		else if (PriceType == 4)
		{
		gInterface.DrawFormat(eWhite, ContentX+20, ContentY+40, 210, 1, "Your %s:",gCustomMessage.GetMessage(86));
		gInterface.DrawFormat(eGold, ContentX+115, ContentY+40, 210, 1, "%d", Ruud);
		}
	}
	else if(this->MainPage == SMITHY_CATEGORY)
	{
		ContentY -= 5;
		for(int i=0; i < 9; i++)
		{
			int objid = eSMITHY_TEXT+i;
			gInterface.DrawAnimatedGUI(objid, ContentX, ContentY);

			if(gInterface.IsWorkZone(objid))
			{
				gInterface.DrawFormat(eGold, ContentX-20, ContentY+5, 210, 3, Menu2[i]);
			}
			else
			{
				gInterface.DrawFormat(eWhite, ContentX-20, ContentY+5, 210, 3, Menu2[i]);
			}
			ContentY += 25;

		}
		//gInterface.DrawFormat(eBlue, ContentX+15, ContentY, 150, 1, "If you need special items, contact administrator!");
	}
	else if(this->MainPage == SMITHY_ITEM)
	{
		ContentY -= 10;
		int n = 0;
		for(int i = 0; i < this->itemdata.size(); i++)
		{
			if(this->Class == this->itemdata[i].Class)
			{
				if(this->Category == this->GetCategory(this->itemdata[i].Type))
				{
					int max_n = this->CategoryPage * 10 + 10;
					int min_n = this->CategoryPage * 10;
					if(n >= min_n && n < max_n)
					{
						int objid = eSMITHY_TEXT+n-min_n;
						gInterface.DrawAnimatedGUI(objid, ContentX, ContentY);		
						if(gInterface.IsWorkZone(objid))
						{
							gInterface.DrawFormat(eGold, ContentX - 20, ContentY + 5, 210, 3, GetItemName(GET_ITEM(this->itemdata[i].Type, this->itemdata[i].Index)));
						}
						else
						{
							gInterface.DrawFormat(eWhite, ContentX - 20, ContentY + 5, 210, 3, GetItemName(GET_ITEM(this->itemdata[i].Type, this->itemdata[i].Index)));
						}
						ContentY += 21;				
					}
					n++;
				}
			}
		}
		ContentY = 350;
		ContentX -= 30;
		gInterface.DrawAnimatedGUI(eSMITHY_L, ContentX + 80, ContentY+2);
		gInterface.DrawAnimatedGUI(eSMITHY_R, ContentX + 130, ContentY+2);
		if(gInterface.IsWorkZone(eSMITHY_L))
		{
			if(gInterface.Data[eSMITHY_L].OnClick)
			{
				Color = eGray150;
			}
			gInterface.DrawColoredGUI(eSMITHY_L, gInterface.Data[eSMITHY_L].X, gInterface.Data[eSMITHY_L].Y, Color);
		}
		if(gInterface.IsWorkZone(eSMITHY_R))
		{
			if(gInterface.Data[eSMITHY_R].OnClick)
			{
				Color = eGray150;
			}
			gInterface.DrawColoredGUI(eSMITHY_R, gInterface.Data[eSMITHY_R].X, gInterface.Data[eSMITHY_R].Y, Color);
		}
		//gInterface.DrawFormat(eBlue, ContentX+45, ContentY-8, 150, 1, "If you need special items, contact administrator!");
		gInterface.DrawFormat(eGold, ContentX+97, ContentY+6, 100, 1, "Page: %d/%d", this->CategoryPage+1,n/10+1);
	}
	else if(this->MainPage == SMITHY_OPTION)
	{
		gInterface.DrawAnimatedGUI(eSMITHY_TEXT, ContentX, ContentY-10);		
		gInterface.DrawFormat(eExcellent, ContentX, ContentY - 5, 170, 3, GetItemName(GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index)));
		ContentY+=20;

		pSetBlend(true);
		ItemBmdStruct* ItemInfo = pGetItemBmdStruct(GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index));
		const int WidthValue = 18;
		const int HeightValue = 20;
		float barWidth = WidthValue*ItemInfo->ItemWidth;
		float barHeight = HeightValue*ItemInfo->ItemHeight;

		gInterface.DrawBarForm(CenterX-(WidthValue*(float)(ItemInfo->ItemWidth/2.0f)),ContentY-10,barWidth,barHeight,0.04,0.34,0.0,1.0);//ReqItems
		gInterface.DrawItem2(CenterX-(WidthValue*(float)(ItemInfo->ItemWidth/2.0f)),ContentY-10,barWidth,barHeight,GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index),SET_ITEMOPT_LEVEL(this->ItemLevel),this->CheckExc(),this->ItemAnc != 0 ? 1 : 0,0);

		ContentY+=barHeight;
		gInterface.DrawAnimatedGUI(eSMITHY_DIV2, StartX, ContentY-20);
		//ContentY+=10;
		//gInterface.DrawAnimatedGUI(eSMITHY_TEXT, ContentX, ContentY-10);		
		//gInterface.DrawFormat(eExcellent, ContentX, ContentY-5, 170, 3, gItem.getItemName(GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index)));
		//gInterface.DrawAnimatedGUIEx(eSMITHY_DIV2, StartX, ContentY);
		//#if (TEMP_S == FALSE)
		//ContentY += 10;
		/*if(this->CheckFenrir() == true)
		{
		gInterface.DrawCheckLineEx(this->ItemOpt1, eSMITHY_POINT, eSMITHY_CHECK1, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Fenrir1");
		ContentY += 20;
		gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Fenrir1");
		ContentY += 20;
		gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Fenrir1");
		ContentY += 20;
		gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Fenrir1");
		} else 
		{*/
		if(this->CheckOther() == false)
		{
			//#if (TEMP_S == FALSE)
			gInterface.PartUPandDNEx(eSMITHY_POINT, eSMITHY_PAGEUP, eSMITHY_PAGEDN, eSMITHY_LINE, ContentX-30, ContentY, eWhite, this->ItemLevel, "Item Level");
			ContentY += 20;
			//#endif
			gInterface.DrawCheckLineEx(this->ItemLuck, eSMITHY_POINT, eSMITHY_CHECK0, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Luck Option +25%%");
			//#if (TEMP_S == FALSE)
			ContentY += 20;
			gInterface.PartUPandDNEx(eSMITHY_POINT, eSMITHY_PAGEUP2, eSMITHY_PAGEDN2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, this->ItemAdd, "Add Option");
			//#endif
			//anc
			if(this->CheckAnc() == true)
			{
				//g_Console.AddMessage(5,"IsAnc");
				ContentY += 20;
				//gInterface.DrawCheckLineEx(this->ItemAncient, eSMITHY_POINT, eSMITHY_CHECK7, eSMITHY_LINE, ContentX-30, ContentY, eBlue, "+ Ancient Status");
				gInterface.PartUPandDNEx(eSMITHY_POINT, eSMITHY_PAGEUP3, eSMITHY_PAGEDN3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, this->ItemAnc, "+Ancient Status (Type)");
			}
			if (this->CheckSocket() == true)
			{
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemSocket, eSMITHY_POINT, eSMITHY_CHECK7, eSMITHY_LINE, ContentX-30, ContentY, eBlue, "+ Socket Status");
			}
			ContentY += 20;
			// -> Wings
			if(this->CheckWingLevel() == 1)
			{

			}
			else if(this->CheckWingLevel() == 2)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Attackin(Wizardy) speed +5");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Max Ag +50 Increased");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor Optionent's defensive power by 3%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Mana +50 Increased");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "HP +50 Increased");
			}
			else if(this->CheckWingLevel() == 3)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recovery of Mana in 5%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recovery of Life in 5%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Return the enemy attack power in 5%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor openent defensive power by 5%%");
			}
			else if(this->CheckWingLevel() == 4)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recovery of Mana in 5%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recovery of Life in 5%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Return the enemy attack power in 5%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor openent defensive power by 5%%");
			}
			else if(this->CheckWingLevel() == 5)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete reco of Mana in 7%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recoy of Life in 7%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Return the enemy attack power in 11%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor openent defensive power by 10%%");
			}
			else if(this->CheckWingLevel() == 6)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete reco of Mana in 8%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recoy of Life in 8%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Return the enemy attack power in 12%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor openent defensive power by 11%%");
			}
			else if(this->CheckWingLevel() == 7)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete reco of Mana in 10%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Complete recoy of Life in 10%% rate");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Return the enemy attack power in 15%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ignor openent defensive power by 13%%");
			}
			else if(this->CheckPend() == true)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt1, eSMITHY_POINT, eSMITHY_CHECK1, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Excellent Damage rate +10%%");
				ContentY += 20;
				//if(this->itemdata[this->Item].Type == 5)
				//{
				//	gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardry Damage +level/20");
				//	ContentY += 20;
				//	gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardry Damage +2%%");
				//}
				//else
				{
					gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardy Dmg +level/20");
					ContentY += 20;
					gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardy Dmg +2%%");
				}	
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Attacking(Wizardy) speed +7");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increases life +life/8");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increases mana +mana/8");
				/*//anc
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemAncient, eSMITHY_POINT, eSMITHY_CHECK7, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ancient Status");*/
			}
			else if(this->itemdata[this->Item].Type > 5 || this->CheckRing() == true)
			{
				gInterface.DrawCheckLineEx(this->ItemOpt1, eSMITHY_POINT, eSMITHY_CHECK1, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Max HP +4%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Max Mana +5%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Damage Decrease +4%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Reflect Damage +5%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Defense success rate +10%%");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increases Zen drop +30%%");
				/*//anc
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemAncient, eSMITHY_POINT, eSMITHY_CHECK7, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ancient Status");*/
			}
			else
			{
				gInterface.DrawCheckLineEx(this->ItemOpt1, eSMITHY_POINT, eSMITHY_CHECK1, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Excellent Damage rate +10%%");
				ContentY += 20;
				if(this->itemdata[this->Item].Type == 5)
				{
					gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardry Damage + level/20");
					ContentY += 20;
					gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Wizardry Damage +2%%");
				}
				else
				{
					gInterface.DrawCheckLineEx(this->ItemOpt2, eSMITHY_POINT, eSMITHY_CHECK2, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Damage + level/20");
					ContentY += 20;
					gInterface.DrawCheckLineEx(this->ItemOpt3, eSMITHY_POINT, eSMITHY_CHECK3, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Damage +2%%");
				}	
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt4, eSMITHY_POINT, eSMITHY_CHECK4, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increase Attacking(Wizardy)speed +7");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt5, eSMITHY_POINT, eSMITHY_CHECK5, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increases life +life/8");
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemOpt6, eSMITHY_POINT, eSMITHY_CHECK6, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Increases mana +mana/8");
				/*//anc
				ContentY += 20;
				gInterface.DrawCheckLineEx(this->ItemAncient, eSMITHY_POINT, eSMITHY_CHECK7, eSMITHY_LINE, ContentX-30, ContentY, eWhite, "Ancient Status");*/

			}
		}
		//#endif
		ContentY = 326;
		gInterface.DrawAnimatedGUI(eSMITHY_INFOBG2, ContentX, ContentY);
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Item Price:");

		if (PriceType == 0)
		{
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d %s", this->GetItemPrice(),gCustomMessage.GetMessage(82));
		}
		else if (PriceType == 1)
		{
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d %s", this->GetItemPrice(),gCustomMessage.GetMessage(83));
		}
		else if (PriceType == 2)
		{
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d %s", this->GetItemPrice(),gCustomMessage.GetMessage(84));
		}
		else if (PriceType == 3)
		{
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d %s", this->GetItemPrice(),gCustomMessage.GetMessage(85));
		}
		else if (PriceType == 4)
		{
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d %s", this->GetItemPrice(),gCustomMessage.GetMessage(86));
		}
		ContentY += 20;
		gInterface.DrawAnimatedGUI(eSMITHY_INFOBG2, ContentX, ContentY);

		if (PriceType == 0)
		{
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Your %s:",gCustomMessage.GetMessage(82));
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d", Zen);
		}
		else if (PriceType == 1)
		{
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Your %s:",gCustomMessage.GetMessage(83));
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d", Coin1);
		}
		else if (PriceType == 2)
		{
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Your %s:",gCustomMessage.GetMessage(84));
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d", Coin2);
		}
		else if (PriceType == 3)
		{
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Your %s:",gCustomMessage.GetMessage(85));
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d", Coin3);
		}
		else if (PriceType == 4)
		{
		gInterface.DrawFormat(eWhite, ContentX+30, ContentY+5, 210, 1, "Your %s:",gCustomMessage.GetMessage(86));
		gInterface.DrawFormat(eGold, ContentX+120, ContentY+5, 210, 1, "%d", Ruud);
		}
	}

	gInterface.DrawAnimatedGUI(eSMITHY_DIV, StartX, gInterface.Data[eSMITHY_FOOTER].Y - 5);
	if(this->MainPage == SMITHY_OPTION)
	{
		bool bPrice = true;

		if(this->GetItemPrice() > Zen && Coin1 && Coin2 && Coin3 && Ruud)
		{
			bPrice = false;
		}

		//#if (TEMP_S == FALSE)
		gInterface.MiniButtonDraw(eSMITHY_BT1, StartX+40, gInterface.Data[eSMITHY_FOOTER].Y + 10, true, "Back");
		gInterface.MiniButtonDraw(eSMITHY_BT2, StartX+120, gInterface.Data[eSMITHY_FOOTER].Y + 10, bPrice, "Buy");
		//#endif
	}
	else
	{
		gInterface.DrawAnimatedGUI(eSMITHY_BACK, ButtonX, gInterface.Data[eSMITHY_FOOTER].Y + 10);
		if(this->MainPage == SMITHY_CLASS)
		{
			gInterface.DrawFormat(eWhite, StartX + 8, gInterface.Data[eSMITHY_FOOTER].Y + 20, 210, 3, "Exit");
		}
		else if(this->MainPage == SMITHY_CATEGORY || this->MainPage == SMITHY_ITEM)
		{
			gInterface.DrawFormat(eWhite, StartX + 8, gInterface.Data[eSMITHY_FOOTER].Y + 20, 210, 3, "Back");
		}

		if(gInterface.IsWorkZone(eSMITHY_BACK))
		{
			if(gInterface.Data[eSMITHY_BACK].OnClick)
			{
				Color = eGray150;
			}
			gInterface.DrawColoredGUI(eSMITHY_BACK, gInterface.Data[eSMITHY_BACK].X, gInterface.Data[eSMITHY_BACK].Y, Color);
		}
	}
}

bool CSmithy::DrawCheckBuy()
{
	if(!gInterface.CheckWindowEx(eSMITHY_CHECKWIN_MAIN))
	{
		return false;
	}

	pSetCursorFocus = true;

	DWORD ItemNameColor		= eWhite;
	float MainWidth			= 230.0;
	float MainHeight		= 130;
	float StartY			= 100.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (29.0 / 2);
	// ----
	gInterface.DrawAnimatedGUI(eSMITHY_CHECKWIN_MAIN, StartX+4, StartY + 4);
	gInterface.DrawAnimatedGUI(eSMITHY_CHECKWIN_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eSMITHY_CHECKWIN_FRAME, StartX, StartY + 67.0, 0);
	gInterface.DrawAnimatedGUI(eSMITHY_CHECKWIN_FOOTER, StartX, StartY);
	// ----
	gInterface.DrawFormat(eGold, StartX + 10, 110, 210, 3, "Check Buy");
	// ---- 
	gInterface.DrawFormat(eWhite, StartX + 10, 110 + 50 - 20, 210, 3, "Check Buy Item?");
	gInterface.DrawAnimatedGUI(eSMITHY_CHECKWIN_OK, StartX+30, StartY /*- 5*/);
	gInterface.DrawFormat(eWhite, StartX + 35, StartY+5 + 5, 50, 3, "Yes");

	if( gInterface.IsWorkZone(eSMITHY_CHECKWIN_OK) )
	{
		DWORD Color = eGray100;
		// ----
		if( gInterface.Data[eSMITHY_CHECKWIN_OK].OnClick )
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eSMITHY_CHECKWIN_OK, gInterface.Data[eSMITHY_CHECKWIN_OK].X, gInterface.Data[eSMITHY_CHECKWIN_OK].Y, Color);
	}
	// ---- 
	gInterface.DrawAnimatedGUI(eSMITHY_CHECKWIN_CLOSE, StartX + 70 + 62, StartY /*- 5*/ );
	gInterface.DrawFormat(eWhite, StartX + 75 + 62, StartY+5 + 5, 50, 3, "No");

	if( gInterface.IsWorkZone(eSMITHY_CHECKWIN_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( gInterface.Data[eSMITHY_CHECKWIN_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eSMITHY_CHECKWIN_CLOSE, gInterface.Data[eSMITHY_CHECKWIN_CLOSE].X, gInterface.Data[eSMITHY_CHECKWIN_CLOSE].Y, Color);
	}

	return true;
}

void CSmithy::Button(DWORD Event)
{
	if (Event != WM_LBUTTONUP)
	{
	return;
	}

	if(gInterface.CheckWindowEx(eSMITHY_CHECKWIN_MAIN))
	{
		//#if(TEMP_S == FALSE)
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECKWIN_OK, false))
		{
			this->CGCreateItem();		
			gInterface.CloseWindowEx(eSMITHY_CHECKWIN_MAIN);
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECKWIN_CLOSE, false))
		{		
			gInterface.CloseWindowEx(eSMITHY_CHECKWIN_MAIN);
		}
		return;
		//#endif
	}

	if(!gInterface.CheckWindowEx(eSMITHY_MAIN))
	{
		return;
	}


	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSMITHY_MAIN].EventTick);

	if( Delay < 50 )
	{
		return;
	}

	gInterface.Data[eSMITHY_MAIN].EventTick = GetTickCount();

	if(this->MainPage == SMITHY_CLASS)
	{
		//#if(TEMP_S == FALSE)
		for(int i=0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{
			int objid = eSMITHY_TEXT+i;
			if (gInterface.ButtonEx2(Event, objid, false))
			{
				this->Class = i;
				this->MainPage = SMITHY_CATEGORY;
				//g_Console.AddMessage(5,"LULS");
			}
		}
		//#endif
	}
	else if(this->MainPage == SMITHY_CATEGORY)
	{
		//#if(TEMP_S == FALSE)
		for(int i=0; i < 9; i++)
		{
			int objid = eSMITHY_TEXT+i;
			if (gInterface.ButtonEx2(Event, objid, false))
			{
				this->Category = i;
				this->MainPage = SMITHY_ITEM;
				//g_Console.AddMessage(5,"LULS2");
			}
		}
		//#endif
	}
	else if(this->MainPage == SMITHY_ITEM)
	{
		int n = 0;
		for(int i = 0; i < this->itemdata.size(); i++)
		{
			if(this->Class == this->itemdata[i].Class)
			{
				if(this->Category == this->GetCategory(this->itemdata[i].Type))
				{
					int max_n = this->CategoryPage * 10 + 10;
					int min_n = this->CategoryPage * 10;
					if(n >= min_n && n < max_n)
					{
						int objid = eSMITHY_TEXT+n-min_n;
						//#if(TEMP_S == FALSE)
						if (gInterface.ButtonEx2(Event, objid, false))
						{
							this->Item = i;
							this->MainPage = SMITHY_OPTION;
						}
						//#endif
					}
					n++;
				}
			}
		}
		//#if(TEMP_S == FALSE)
		if (gInterface.ButtonEx2(Event, eSMITHY_L, false))
		{
			if(this->CategoryPage > 0)
			{
				this->CategoryPage--;
			}
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_R, false))
		{
			if(this->CategoryPage < this->GetMaxItemCategory()/10)
			{
				this->CategoryPage++;
			}
		}
		//#endif
	}
	else if(this->MainPage == SMITHY_OPTION)
	{
		//#if(TEMP_S == FALSE)
		if (gInterface.ButtonEx2(Event, eSMITHY_PAGEUP, false) && this->ItemLevel < this->MaxLevel)
		{
			this->ItemLevel++;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_PAGEDN, false) && this->ItemLevel > 0)
		{
			this->ItemLevel--;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_PAGEUP2, false) && this->ItemAdd < 7)
		{
			this->ItemAdd++;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_PAGEDN2, false) && this->ItemAdd > 0)
		{
			this->ItemAdd--;
		}
		if (this->CheckAnc())
		{
			if (gInterface.ButtonEx2(Event, eSMITHY_PAGEDN3, false) && this->ItemAnc > 0)
			{
				if (this->AllowAncExce == 1)
				{
					this->ItemAnc--;
				}
				else
				{
					if (this->CheckExc() == false)
					{
						this->ItemAnc--;
					}
				}
			}
			int count = this->GetCountOfAnc();
			//g_Console.AddMessage(5,"Count = %d",count);
			if (gInterface.ButtonEx2(Event, eSMITHY_PAGEUP3, false) && this->ItemAnc < count)
			{
				if (this->AllowAncExce == 1)
				{
					this->ItemAnc++;
				}
				else
				{
					if (this->CheckExc() == false)
					{
						this->ItemAnc++;
					}
				}
			}
		}

		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK0, false))
		{
			this->ItemLuck = !this->ItemLuck;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK1, false))
		{
			if (!this->ItemOpt1 && !this->CheckExlOpt())
			{
				return;
			}

			this->ItemOpt1 = !this->ItemOpt1;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK2, false))
		{
			if (!this->ItemOpt2 && !this->CheckExlOpt())
			{
				return;
			}

			this->ItemOpt2 = !this->ItemOpt2;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK3, false))
		{
			if (!this->ItemOpt3 && !this->CheckExlOpt())
			{
				return;
			}

			this->ItemOpt3 = !this->ItemOpt3;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK4, false))
		{
			if (!this->ItemOpt4 && !this->CheckExlOpt())
			{
				this->ItemOpt4 = !this->ItemOpt4;
			}

			this->ItemOpt4 = !this->ItemOpt4;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK5, false))
		{
			if (!this->ItemOpt5 && !this->CheckExlOpt())
			{
				return;
			}

			this->ItemOpt5 = !this->ItemOpt5;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK6, false))
		{
			if (!this->ItemOpt6 && !this->CheckExlOpt())
			{
				return;
			}

			this->ItemOpt6 = !this->ItemOpt6;
		}

		if (gInterface.ButtonEx2(Event, eSMITHY_CHECK7, false))
		{
			this->ItemSocket = !this->ItemSocket;
		}
		//#endif
	}
	//#if(TEMP_S == FALSE)
	if(this->MainPage == SMITHY_OPTION)
	{
		if (gInterface.ButtonEx2(Event, eSMITHY_BT1, false))
		{
			this->MainPage--;
		}
		if (gInterface.ButtonEx2(Event, eSMITHY_BT2, false))
		{
			if(this->GetItemPrice() > Zen && Coin1 && Coin2 && Coin3 && Ruud)
			{
				return;
			}
			gInterface.OpenWindowEx(eSMITHY_CHECKWIN_MAIN);	
		}
	}
	else
	{
		if (gInterface.ButtonEx2(Event, eSMITHY_BACK, false))
		{
			if(this->MainPage == SMITHY_CLASS)
			{
				gInterface.CloseWindowEx(eSMITHY_MAIN);
				this->CloseWindow();
			}
			else if(this->MainPage > 0)
			{
				this->MainPage--;
			}
		}
	}
	//#endif
	if (gInterface.ButtonEx2(Event, eSMITHY_CLOSE, false))
	{
		this->MainPage = SMITHY_CLASS;
		gInterface.CloseWindowEx(eSMITHY_MAIN);
		this->CloseWindow();
	}
}

void CSmithy::GCItemInit(GC_SmithyInit* aRecv)
{
	if(aRecv->result)
	{
		this->itemdata.clear();
		gInterface.Data[eSMITHY_MAIN].Open();
	}
}

void CSmithy::GCItemSend(GC_SmithyDATA* aRecv)
{
	SmithyDATA pData;
	pData.Class = aRecv->Class;
	pData.Type = aRecv->Type;
	pData.Index = aRecv->Index;
	pData.Price = aRecv->Price;
	this->itemdata.push_back(pData);
	//g_Console.AddMessage(5,"Recv");
}

void CSmithy::GCSettingsRecv(GC_SmithySettings* aRecv)
{
	this->AllowAncExce = aRecv->AllowAncExce;
	this->MaxLevel = aRecv->MaxLevel;
	this->LevelPrice = aRecv->LevelPrice;
	this->LuckPrice = aRecv->LuckPrice;
	this->AddPrice = aRecv->AddPrice;
	this->Opt1Price = aRecv->Opt1Price;
	this->Opt2Price = aRecv->Opt2Price;
	this->Opt3Price = aRecv->Opt3Price;
	this->Opt4Price = aRecv->Opt4Price;
	this->Opt5Price = aRecv->Opt5Price;
	this->Opt6Price = aRecv->Opt6Price;
	this->MaxExlOpt = aRecv->MaxExlOpt;
	this->AncientPrice = aRecv->AncientPrice;
	this->SocketPrice = aRecv->SocketPrice;
	this->PriceType = aRecv->PriceType;
}

bool CSmithy::CheckExlOpt()
{
	int iTotalExlOpt = this->ItemOpt1 + this->ItemOpt2 + this->ItemOpt3 + this->ItemOpt4 + this->ItemOpt5 + this->ItemOpt6;

	if (iTotalExlOpt >= this->MaxExlOpt)
	{
		return false;
	}

	return true;
}

void CSmithy::GCAncientRecv(int Index,BYTE count[2])
{
	SmithyAncDATA pData;
	pData.Index = Index;
	/*if (Index == (GET_ITEM(8,1)))
	{
	g_Console.AddMessage(5,"Recv %d %d",count[0],count[1]);
	}*/
	pData.AncCount[0] = count[0];
	pData.AncCount[1] = count[1];
	this->m_AncData.push_back(pData);
}

void CSmithy::GCSocketRecv(int Index)
{
	SmithySocketDATA pData;
	pData.Index = Index;
	this->m_SocketData.push_back(pData);
}


void CSmithy::ClearAncientList()
{
	this->m_AncData.clear();
}

void CSmithy::ClearSocketList()
{
	this->m_SocketData.clear();
}



void CSmithy::CGCreateItem()
{
	CG_SmithyCreateItem pMsg;
	pMsg.h.set(0xFF, 0x17,  sizeof(pMsg));
	pMsg.Item = this->Item;
	pMsg.ItemLevel = this->ItemLevel;
	pMsg.ItemAdd = this->ItemAdd;
	pMsg.ItemLuck = this->ItemLuck;
	pMsg.ItemOpt1 = this->ItemOpt1;
	pMsg.ItemOpt2 = this->ItemOpt2;
	pMsg.ItemOpt3 = this->ItemOpt3;
	pMsg.ItemOpt4 = this->ItemOpt4;
	pMsg.ItemOpt5 = this->ItemOpt5;
	pMsg.ItemOpt6 = this->ItemOpt6;
	//pMsg.ItemAncient = this->ItemAnc;
	int value = this->GetAncientOption();
	//g_Console.AddMessage(5,"Send = %d", value);
	pMsg.ItemAncient = value;
	pMsg.ItemSocket = this->ItemSocket;
	DataSend((LPBYTE)&pMsg, sizeof(pMsg));
}

void CSmithy::CGSmithySend()
{
	CG_SMITHY_REQ pRequest;
	pRequest.h.set(0xFF,0x16,sizeof(pRequest));

	DataSend((BYTE*)&pRequest,pRequest.h.size);
}


int CSmithy::GetCategory(int Type)
{
	switch(Type)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: return 0;
	case 6: return 1;
	case 7: return 2;
	case 8: return 3;
	case 9: return 4;
	case 10:return 5;
	case 11:return 6;
	case 12:return 7;
	case 13:return 8;
	}
	return -1;
}

int CSmithy::GetMaxItemCategory()
{
	int n = 0;
	for(int i = 0; i < this->itemdata.size(); i++)
	{
		if(this->Class == this->itemdata[i].Class)
		{
			if(this->Category == this->GetCategory(this->itemdata[i].Type))
			{
				n++;
			}
		}
	}
	return n;
}

int CSmithy::GetItemPrice()
{
	unsigned int result = 0;

	result = this->itemdata[this->Item].Price;
	result += this->ItemLevel * this->LevelPrice;
	result += this->ItemAdd * this->AddPrice;

	if(this->ItemLuck)
	{
		result += this->LuckPrice;
	}
	/*if(this->ItemAdd)
	{
	result += this->AddPrice;
	}*/
	if(this->ItemOpt1)
	{
		result += this->Opt1Price;
	}
	if(this->ItemOpt2)
	{
		result += this->Opt2Price;
	}
	if(this->ItemOpt3)
	{
		result += this->Opt3Price;
	}
	if(this->ItemOpt4)
	{
		result += this->Opt4Price;
	}
	if(this->ItemOpt5)
	{
		result += this->Opt5Price;
	}
	if(this->ItemOpt6)
	{
		result += this->Opt6Price;
	}
	if(this->ItemAnc)
	{
		result += this->AncientPrice;
	}
	if(this->ItemSocket)
	{
		result += this->SocketPrice;
	}

	return result;
}

void CSmithy::CloseWindow()
{
	this->MainPage = 0;
	this->Class = 0;
	this->Category = 0;
	this->CategoryPage = 0;
	this->Item = 0;
	this->ItemLevel = 0;
	this->ItemLuck = false;
	this->ItemAdd = false;
	this->ItemOpt1 = false;
	this->ItemOpt2 = false;
	this->ItemOpt3 = false;
	this->ItemOpt4 = false;
	this->ItemOpt5 = false;
	this->ItemOpt6 = false;
	this->ItemSocket = false;
	this->ItemAnc = 0;
	//this->ItemAncient = false;
}

bool CSmithy::CheckRing()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	switch(iType)
	{
	case GET_ITEM(13, 8):
	case GET_ITEM(13, 9):
	case GET_ITEM(13, 21):
	case GET_ITEM(13, 22):
	case GET_ITEM(13, 23):
	case GET_ITEM(13, 24):
		return true;
	}
	return false;
}

bool CSmithy::CheckPend()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	switch(iType)
	{
	case GET_ITEM(13, 12):
	case GET_ITEM(13, 13):
	case GET_ITEM(13, 25):
	case GET_ITEM(13, 26):
	case GET_ITEM(13, 27):
	case GET_ITEM(13, 28):
		return true;
	}
	return false;
}

bool CSmithy::CheckFenrir()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	switch(iType)
	{
	case GET_ITEM(13, 37):
		return true;
	}
	return false;
}

bool CSmithy::CheckOther()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	switch(iType)
	{
	case GET_ITEM(14, 174):
	case GET_ITEM(14, 175):
	case GET_ITEM(14, 176):
	case GET_ITEM(14, 177):
	case GET_ITEM(14, 178):
	case GET_ITEM(14, 179):
		return true;
	}
	return false;
}

bool CSmithy::CheckExc()
{
	bool value = false;
	if (this->ItemOpt1 || this->ItemOpt2 || this->ItemOpt3 || 
		this->ItemOpt4 || this->ItemOpt5 || this->ItemOpt6)
	{
		value = true;
	}
	return value;
}

bool CSmithy::CheckAnc()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	for	(int i=0;i<this->m_AncData.size();i++)
	{
		if (iType==this->m_AncData[i].Index)
		{
			return true;
		}
	}
	return false;
}

BYTE CSmithy::GetCountOfAnc()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	for	(int i=0;i<this->m_AncData.size();i++)
	{
		if (iType==this->m_AncData[i].Index)
		{
			int counter = 0;
			for	(int j=0;j<2;j++)
			{
				if (this->m_AncData[i].AncCount[j] != 0)
				{
					//g_Console.AddMessage(5,"check %d = %d",j,this->m_AncData[i].AncCount[j]);
					counter++;
				}
				/*counter+=this->m_AncData[i].AncCount[i];*/
			}
			return counter;
			//return this->m_AncData[i].AncCount;
		}
	}
	return 0;
}

BYTE CSmithy::GetAncientOption()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	//g_Console.AddMessage(5,"ID = %d Index = %d",this->itemdata[this->Item].Type,this->itemdata[this->Item].Index);

	for	(int i=0;i<this->m_AncData.size();i++)
	{
		if (iType==this->m_AncData[i].Index)
		{
			if (this->m_AncData[i].AncCount[this->ItemAnc-1] == 0)
			{
				return this->m_AncData[i].AncCount[1];
			}
			return this->m_AncData[i].AncCount[this->ItemAnc-1];
		}
	}

	return 0;
}

bool CSmithy::CheckSocket()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);
	for	(int i=0;i<this->m_SocketData.size();i++)
	{
		if (iType==this->m_SocketData[i].Index)
		{
			return true;
		}
	}
	return false;
}

unsigned char CSmithy::CheckWingLevel()
{
	short iType = GET_ITEM(this->itemdata[this->Item].Type, this->itemdata[this->Item].Index);

	if (iType == GET_ITEM(13,30))
	{
		return 2;
	}

	switch(iType)
	{
	case GET_ITEM(12, 0):
	case GET_ITEM(12, 1):
	case GET_ITEM(12, 2):
	case GET_ITEM(12, 41):
		return 1;
	case GET_ITEM(12, 3):
	case GET_ITEM(12, 4):
	case GET_ITEM(12, 5):
	case GET_ITEM(12, 6):
	case GET_ITEM(12, 52):
	case GET_ITEM(13, 30):
		return 2;
	case GET_ITEM(12, 36):
	case GET_ITEM(12, 37):
	case GET_ITEM(12, 38):
	case GET_ITEM(12, 39):
	case GET_ITEM(12, 40):
	case GET_ITEM(12, 43):
		return 3;
		/*case GET_ITEM(12, 180):
		case GET_ITEM(12, 181):
		case GET_ITEM(12, 182):
		case GET_ITEM(12, 183):
		case GET_ITEM(12, 184):
		case GET_ITEM(12, 185):
		case GET_ITEM(12, 186):
		return 4;
		case GET_ITEM(12, 187):
		case GET_ITEM(12, 188):
		case GET_ITEM(12, 189):
		case GET_ITEM(12, 190):
		case GET_ITEM(12, 191):
		case GET_ITEM(12, 192):
		case GET_ITEM(12, 193):
		return 5;
		case GET_ITEM(12, 194):
		case GET_ITEM(12, 195):
		case GET_ITEM(12, 196):
		case GET_ITEM(12, 197):
		case GET_ITEM(12, 198):
		case GET_ITEM(12, 199):
		case GET_ITEM(12, 200):
		return 6;
		case GET_ITEM(12, 201):
		case GET_ITEM(12, 202):
		case GET_ITEM(12, 203):
		case GET_ITEM(12, 204):
		case GET_ITEM(12, 205):
		case GET_ITEM(12, 206):
		case GET_ITEM(12, 207):
		return 7;*/
	}

	if (gCustomWing.CheckCustomWingByItem(iType) == 1)
	{
		return 4;
	}

	return 0;
}

void CSmithy::SwitchSmithyWindowState()
{
	(gInterface.Data[eSMITHY_MAIN].OnShow == true)? gInterface.Data[eSMITHY_MAIN].Close():this->CGSmithySend();
}