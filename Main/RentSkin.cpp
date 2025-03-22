#include "StdAfx.h"
#include "RentSkin.h"
#include "Import.h"
#include "Interface.h"
#include "CustomFont.h"
#include "Character.h"
#include "Util.h"
#include "TMemory.h"

cRentSkin RentSkin;

cRentSkin::cRentSkin()
{
	this->Init();
}


cRentSkin::~cRentSkin()
{
}

bool IsWorkZone10(float x, float y, float x2, float y2)
{
	bool result = GetForegroundWindow() == pGameWindow && pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
	return result;
}
void cRentSkin::SetRect(float a1, float a2, float a3, float a4)
{
	this->x = a1;
	this->y = a2;
	this->w = a3;
	this->h = a4;
}
bool cRentSkin::CheckRect()
{
	return this->Drawing && IsWorkZone10(x, y, w, h);
}



void __declspec(naked) RenderSkin()
{
	static DWORD ModelID = 0;
	static DWORD AddressExit = 0x0057306B;
	static DWORD AddressJmp = 0x0057301F;

	_asm
	{
		mov edx, dword ptr[ecx + 0x34]
		mov ModelID, edx
	}
	if (ModelID == 537 || (ModelID >= 910 + 644 && ModelID <= 940 + 644 ))
	{
		_asm
		{
			jmp AddressJmp;
		}
	}
	else
	{
		_asm
		{
			jmp AddressExit;
		}
	}

}

void __declspec(naked) CheckRenderSkin()
{
	static DWORD ModelID = 0;
	static DWORD AddressExit = 0x00572BDB;
	static DWORD AddressJmp = 0x00572BB3;
	_asm
	{
		mov edx, dword ptr[ecx + 0x34]
		mov ModelID, edx
	}
	if (ModelID == 537 || (ModelID >= 910 + 644 && ModelID <= 940 + 644 ))
	{
		_asm
		{
			jmp AddressExit;
		}
	}
	else
	{
		_asm
		{
			jmp AddressJmp;
		}
	}
}

void cRentSkin::Init()
{
	this->Drawing = false;
	this->SetRect(120, 70, 400, 255);

	SetRange(0x00573016, 9, 144);
	SetJmp((LPVOID)0x00573016, RenderSkin);
	SetRange(0x00572BAA, 9, 144);
	SetJmp((LPVOID)0x00572BAA, CheckRenderSkin);
}

void cRentSkin::Draw()
{
	if (GetKeyState(VK_F8) & 0x4000 && this->TickCount + 350 < GetTickCount()) /// open F8
	{
		this->Drawing = !this->Drawing;
		this->TickCount = GetTickCount();
		if(!this->Drawing)
		{
			this->SendRequest(0x2, 0);
		}
		else
		{
			this->SendRequest(0x0, this->Selected);
		}
	}

	if (!this->Drawing)
	{
		return;
	}
	//==========
	glAlphaFunc(GL_GREATER, 0.0f);

	CustomFont.Draw(CustomFont.FontBold, x, y, 0x0, 0x373b45ff, w, h, 1, " ");

	RenderBitmap(31355, x, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);
	RenderBitmap(31356, x + w - 21.f, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);

	RenderBitmap(31353, x, y, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 60, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 130, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 200, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 270, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 340, y, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);

	RenderBitmap(31357, x, y + 212, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 60, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 130, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 200, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 270, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 340, y + 212, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);




	if (pIsKeyRelease(VK_LBUTTON) && IsWorkZone10(x + w - 25, y + 5, 20, 18))
	{
		this->SendRequest(0x2, 0);
		this->Drawing = false;
	}

	glAlphaFunc(GL_GREATER, 0.25f);


	this->DrawButton(32331, x + 14 + 75 * 4, y + h - 70, 73, 27, 128.0, 128.0, RentSkin.BuyAction);
	this->DrawButton(32331, x + 14 + 75 * 3, y + h - 40, 73, 27, 128.0, 128.0, RentSkin.PrevAction);
	this->DrawButton(32331, x + 14 + 75 * 4, y + h - 40, 73, 27, 128.0, 128.0, RentSkin.NextAction);

	
	CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, "Next");
	CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 3, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, "Prev");

	CustomFont.Draw(CustomFont.FontBold, x, y + 12, 0xffffffff, 0x0, w, 0, 3, "Skin System");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 *1, 0x0, 0x87CEFA, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 *2, 0x0, 0x00F5FF, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 *3, 0x0, 0x00FA9A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 *4, 0x0, 0xCAFF70, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 *5, 0x0, 0xFF6A6A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 20, y + 50 + 25 *6, 0x0, 0xed260cff, 110, 15, 0, " ");

	RENT_SKIN_DATA* skin = this->FindId(this->Selected);

	if (skin != 0)
	{
		CustomFont.Draw(CustomFont.FontNormal, x , y + 80, 0xffffffff, 0x0, 150, 0, 3, "Price (Wcoin) : %d", skin->Price);

		CustomFont.Draw(CustomFont.FontNormal, x , y + 105, 0xffffffff, 0x0, 150, 0, 3, "Damage: %d", skin->Value1);
		CustomFont.Draw(CustomFont.FontNormal, x , y + 130, 0xffffffff, 0x0, 150, 0, 3, "Def: %d", skin->Value2);
		CustomFont.Draw(CustomFont.FontNormal, x , y + 155, 0xffffffff, 0x0, 150, 0, 3, "HP: %d", skin->Value3);
		CustomFont.Draw(CustomFont.FontNormal, x , y + 180, 0xffffffff, 0x0, 150, 0, 3, "Mana: %d", skin->Value4); 
		CustomFont.Draw(CustomFont.FontNormal, x , y + 205, 0xffffffff, 0x0, 150, 0, 3, "Change Characters For Effect");




		if (skin->Skin == abs(this->Skin))
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 34 + 75 * 2, y + 35, 0x0, 0x00F5FF, 80, 10, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, x + 4 + 75 * 2, y + 35, 0xffffffff, 0x0, 150, 0, 3, "Active");
			
			CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 62.5, 0xffffffff, 0x0, 73, 0, 3, this->Skin < 0 ? "Use" : "Dont Use");
		}
		else
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 34 + 75 * 2, y + 35, 0x0, 0x00F5FF, 80, 10, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, x + 4 + 75 * 2, y + 35, 0xffffffff, 0x0, 150, 0, 3,"No Active");
			CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 62.5, 0xffffffff, 0x0, 73, 0, 3, "Buy");
		}

		character.DrawClone(x + 80, y + 10, 200, 200);
	}
	else
	{
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);

		CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 13 * 1, 0xffffffff, 0x0, 150, 0, 0, buf, "...");
	}
}

void cRentSkin::SendRequest(BYTE type, int value)
{
	PMSG_RENT_SKIN_SEND pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFF, 0x01, sizeof(pRequest));
	pRequest.Type = type;
	pRequest.Value = value;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}


void cRentSkin::RecvData(BYTE* a)
{
	PMSG_SENT_SKIN_RECV* Packet = (PMSG_SENT_SKIN_RECV*)a;

	this->Skin = Packet->Skin;
	
	if (Packet->Data.Id == -1)
	{
		return;
	}

	this->Selected = Packet->Data.Id;
	
	RENT_SKIN_DATA* skin = this->FindId(Packet->Data.Id);

	if (skin != 0)
	{
		skin->Id = Packet->Data.Id;
		skin->Skin = Packet->Data.Skin;
		skin->Price = Packet->Data.Price;
		skin->Value1 = Packet->Data.Value1;
		skin->Value2 = Packet->Data.Value2;
		skin->Value3 = Packet->Data.Value3;
		skin->Value4 = Packet->Data.Value4;
	}
	else
	{
		RENT_SKIN_DATA new_skin;
		new_skin.Id = Packet->Data.Id;
		new_skin.Skin = Packet->Data.Skin;
		new_skin.Price = Packet->Data.Price;
		new_skin.Value1 = Packet->Data.Value1;
		new_skin.Value2 = Packet->Data.Value2;
		new_skin.Value3 = Packet->Data.Value3;
		new_skin.Value4 = Packet->Data.Value4;

		this->m_Data.push_back(new_skin);
		return;
	}
}


void cRentSkin::Clear()
{
	this->TickCount = 0;
	this->Skin = 0;
	this->Selected = 0;
	this->m_Data.clear();
}

RENT_SKIN_DATA* cRentSkin::FindSkin(int id)
{
	for (int i = 0; i < this->m_Data.size(); i++)
	{
		if (this->m_Data[i].Skin == id)
		{
			return &this->m_Data[i];
		}
	}
	return 0;
}
RENT_SKIN_DATA* cRentSkin::FindId(int id)
{
	for (int i = 0; i < this->m_Data.size(); i++)
	{
		if (this->m_Data[i].Id == id)
		{
			return &this->m_Data[i];
		}
	}
	return 0;
}


void cRentSkin::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc) {
	if (IsWorkZone10(x, y, w, h)) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
		}
		else {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
		}
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pCallbackFunc(this);
			return;
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}


void cRentSkin::BuyAction(LPVOID pClass)
{
	cRentSkin* This = (cRentSkin*)pClass;


	RENT_SKIN_DATA* skin = This->FindId(This->Selected);

	if (skin != 0)
	{
		if (skin->Skin == abs(This->Skin))
		{
			This->SendRequest(0x3, abs(This->Skin) >= 0);
		}
		else
		{
			This->SendRequest(0x1, This->Selected);
		}
	}
}

void cRentSkin::NextAction(LPVOID pClass)
{
	cRentSkin* This = (cRentSkin*)pClass;

	This->SendRequest(0x0, This->Selected + 1);
}

void cRentSkin::PrevAction(LPVOID pClass)
{
	cRentSkin* This = (cRentSkin*)pClass;
	if (This->Selected > 0)
	{
		This->SendRequest(0x0, This->Selected - 1);
	}
}