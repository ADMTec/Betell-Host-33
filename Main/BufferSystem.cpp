#include "stdafx.h"
#include "BufferSystem.h"
#include "Interface.h"
#include "Protocol.h"
#include "Console.h"

#if(CUSTOM_NPC_BUFFER==TRUE)

BufferSystem g_BufferSystem;
// ----------------------------------------------------------------------------------------------

void BufferSystem::Init()
{
	this->Buff1_Result = 0;
	this->Buff1_ZenMoney = 0;
	this->Buff1_JewelOfBless = 0;
	this->Buff1_JewelOfSoul = 0;
	this->Buff1_Bonus = 0;

	this->Buff2_Result = 0;
	this->Buff2_ZenMoney = 0;
	this->Buff2_JewelOfBless = 0;
	this->Buff2_JewelOfSoul = 0;
	this->Buff2_Bonus = 0;

	this->Buff3_Result = 0;
	this->Buff3_ZenMoney = 0;
	this->Buff3_JewelOfBless = 0;
	this->Buff3_JewelOfSoul = 0;
	this->Buff3_Bonus = 0;

	this->Buff4_Result = 0;
	this->Buff4_ZenMoney = 0;
	this->Buff4_JewelOfBless = 0;
	this->Buff4_JewelOfSoul = 0;
	this->Buff4_Bonus = 0;

	this->Buff5_Result = 0;
	this->Buff5_ZenMoney = 0;
	this->Buff5_JewelOfBless = 0;
	this->Buff5_JewelOfSoul = 0;
	this->Buff5_Bonus = 0;

	this->Buff6_Result = 0;
	this->Buff6_ZenMoney = 0;
	this->Buff6_JewelOfBless = 0;
	this->Buff6_JewelOfSoul = 0;
	this->Buff6_Bonus = 0;	

	this->LoadBuffCount = 0;
	ZeroMemory(&this->DataBuff, sizeof(this->DataBuff));
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::Load()
{
	this->Init();
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::GC_OpenWindow()
{
	gInterface.OpenWindowEx(exWinNPCBuffer);
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::BindImages()
{
	gInterface.BindObject(eNPC_BUFF_MAIN, 0x7A5A, 222, 303, -1, -1);
	gInterface.BindObject(eNPC_BUFF_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eNPC_BUFF_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eNPC_BUFF_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eNPC_BUFF_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eNPC_BUFF_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eNPC_BUFF_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT1, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT2, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT3, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT4, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT5, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT6, 0x7A5F, 62, 27, -1, -1);
	gInterface.BindObject(eNPC_BUFF_BT7, 0x7A5F, 62, 27, -1, -1);
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::Draw()
{
	if(!gInterface.CheckWindowEx(exWinNPCBuffer))
	{
		return;
	}

	pSetCursorFocus = true;

	// ----
	DWORD ItemNameColor		= eWhite;
	float MainWidth			= 230.0;
	float MainHeight		= 313.0;
	float StartY			= 100;	//100
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (29.0 / 2);

	float ContentX          = StartX;
	float ContentY			= StartY;

	// ----
	gInterface.DrawGUI(eNPC_BUFF_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(eNPC_BUFF_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eNPC_BUFF_FRAME, StartX, StartY + 67.0, 13);
	gInterface.DrawGUI(eNPC_BUFF_FOOTER, StartX, StartY);
	gInterface.DrawGUI(eNPC_BUFF_CLOSE, StartX + MainWidth - gInterface.Data[eNPC_BUFF_CLOSE].Width, ContentY);
	// ----
	if( gInterface.IsWorkZone(eNPC_BUFF_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( gInterface.Data[eNPC_BUFF_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eNPC_BUFF_CLOSE, gInterface.Data[eNPC_BUFF_CLOSE].X, gInterface.Data[eNPC_BUFF_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[eNPC_BUFF_CLOSE].X + 5, gInterface.Data[eNPC_BUFF_CLOSE].Y + 25, "Close");
	}
	// ----

	gInterface.DrawFormat(eGold, ContentX + 10, ContentY + 10, 210, 3, "Buffer");

	// -> Content

	ContentX += 20 + 15;
	ContentY += 30;

	int res = true;

	gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT1, ContentX+100, ContentY+5, this->Buff1_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff1_ZenMoney, NULL, this->Buff1_JewelOfBless, this->Buff1_JewelOfSoul, NULL, this->Buff1_Bonus, NULL);
	this->BuffDraw(41, ContentX, ContentY + 5);

	ContentY += 45;

	// ----
	
	gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT2, ContentX+100, ContentY+5, this->Buff2_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff2_ZenMoney, NULL, this->Buff2_JewelOfBless, this->Buff2_JewelOfSoul, NULL, this->Buff2_Bonus, NULL);
	this->BuffDraw(44, ContentX, ContentY+5);
	ContentY += 45;

	// ----

	gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT3, ContentX+100, ContentY+5, this->Buff3_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff3_ZenMoney, NULL, this->Buff3_JewelOfBless, this->Buff3_JewelOfSoul, NULL, this->Buff3_Bonus, NULL);
	this->BuffDraw(45, ContentX, ContentY+5);
	ContentY += 45;

	// ----

	gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT4, ContentX+100, ContentY+5, this->Buff4_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff4_ZenMoney, NULL, this->Buff4_JewelOfBless, this->Buff4_JewelOfSoul, NULL, this->Buff4_Bonus, NULL);
	this->BuffDraw(46, ContentX, ContentY + 5);
	ContentY += 45;

	// ----

	gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT5, ContentX+100, ContentY+5, this->Buff5_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff5_ZenMoney, NULL, this->Buff5_JewelOfBless, this->Buff5_JewelOfSoul, NULL, this->Buff5_Bonus, NULL);
	this->BuffDraw(47, ContentX, ContentY + 5);
	ContentY += 45;

	// ----
	
	//gInterface.DrawGUI(eNPC_BUFF_LINE, ContentX,  ContentY + 40);
	gInterface.DrawButtonMini(eNPC_BUFF_BT6, ContentX+100, ContentY+5, this->Buff6_Result, "Buy");
	gInterface.DrawPrice(ContentX+10, ContentY, this->Buff6_ZenMoney, NULL, this->Buff6_JewelOfBless, this->Buff6_JewelOfSoul, NULL, this->Buff6_Bonus, NULL);
	this->BuffDraw(90, ContentX, ContentY + 5);
	ContentY += 45;

}
// ----------------------------------------------------------------------------------------------

void BufferSystem::BuffDraw(int BuffID, int X, int Y)
{
	float High	= 28.0;
	float Whith = 20.0;

	int BuffIndex = BuffID;	//BuffID

	int Model = 0;
	int v6 = 0;

	if( BuffIndex > 0 && BuffIndex <= 80)
	{
		Model = 0x7BED;
		v6 = (BuffIndex - 1) % 80;
	}
	else if (BuffIndex > 80 && BuffIndex <= 160)
	{
		Model = 0x7BEE;
		v6 = (BuffIndex - 81) % 80;
	}
	else
	{
		Model = 0x7BEF;
		v6 = (BuffIndex - 161) % 80;
	}
    
	float CritX = (double)(v6 % 10) * Whith / 256;
	float CritY = (double)(v6 / 10) * High / 256;

	float standartWhith = Whith / 256;
	float standartHight = High / 256;

	pDrawCircle(Model, X, Y, Whith, High, CritX, CritY, standartWhith, standartHight, TRUE, TRUE, 0.0);

	// ----

	if(gInterface.IsWorkZone2(X, Y, X + Whith, Y + High))
	{
		gIconBuff.sub_777FB0(BuffID, 3600, X, Y);		
	}
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::RecvData(GC_BuffNpcOpen* aRecv)
{
	

	this->Buff1_Result = aRecv->Result1;
	this->Buff1_ZenMoney = aRecv->Zen1;
	this->Buff1_JewelOfBless = aRecv->Bless1;
	this->Buff1_JewelOfSoul = aRecv->Soul1;
	this->Buff1_Bonus = aRecv->Bonus1;

	this->Buff2_Result = aRecv->Result2;
	this->Buff2_ZenMoney = aRecv->Zen2;
	this->Buff2_JewelOfBless = aRecv->Bless2;
	this->Buff2_JewelOfSoul = aRecv->Soul2;
	this->Buff2_Bonus = aRecv->Bonus2;

	this->Buff3_Result = aRecv->Result3;
	this->Buff3_ZenMoney = aRecv->Zen3;
	this->Buff3_JewelOfBless = aRecv->Bless3;
	this->Buff3_JewelOfSoul = aRecv->Soul3;
	this->Buff3_Bonus = aRecv->Bonus3;

	this->Buff4_Result = aRecv->Result4;
	this->Buff4_ZenMoney = aRecv->Zen4;
	this->Buff4_JewelOfBless = aRecv->Bless4;
	this->Buff4_JewelOfSoul = aRecv->Soul4;
	this->Buff4_Bonus = aRecv->Bonus4;

	this->Buff5_Result = aRecv->Result5;
	this->Buff5_ZenMoney = aRecv->Zen5;
	this->Buff5_JewelOfBless = aRecv->Bless5;
	this->Buff5_JewelOfSoul = aRecv->Soul5;
	this->Buff5_Bonus = aRecv->Bonus5;

	this->Buff6_Result = aRecv->Result6;
	this->Buff6_ZenMoney = aRecv->Zen6;
	this->Buff6_JewelOfBless = aRecv->Bless6;
	this->Buff6_JewelOfSoul = aRecv->Soul6;
	this->Buff6_Bonus = aRecv->Bonus6;

	if(!gInterface.CheckWindowEx(exWinNPCBuffer))
	{
		gInterface.OpenWindowEx(exWinNPCBuffer);
	}
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::ButtonEvent(DWORD Event)
{
	if(!gInterface.CheckWindowEx(exWinNPCBuffer))
	{
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_CLOSE, false ) )
	{
		gInterface.CloseWindowEx(exWinNPCBuffer);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT1, true ) )
	{
		this->CG_SendResult(1);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT2, true ) )
	{
		this->CG_SendResult(2);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT3, true ) )
	{
		this->CG_SendResult(3);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT4, true ) )
	{
		this->CG_SendResult(4);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT5, true ) )
	{
		this->CG_SendResult(5);
		return;
	}

	if( gInterface.ButtonEx(Event, eNPC_BUFF_BT6, true ) )
	{
		this->CG_SendResult(6);
		return;
	}
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::CG_SendResult(int id)
{
	CG_BuffNpcResult pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFF, 0x27, sizeof(pRequest));
	pRequest.Result = (BYTE)id;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}
// ----------------------------------------------------------------------------------------------

void BufferSystem::BindIcon(BYTE Index, char* Name, char* Text)
{
	this->DataBuff[this->LoadBuffCount].Index = Index;
	strncpy(this->DataBuff[this->LoadBuffCount].Name, Name, 50);
	strncpy(this->DataBuff[this->LoadBuffCount].Text, Text, 200);

	this->LoadBuffCount++;
}
// ------------------------------------------------------------------------------
#endif