#include "stdafx.h"
#include "SelectWareHouse.h"
#include "Interface.h"
#include "User.h"
#include "Central.h"
#include "ServerInfo.h"

CWareHouseInfo gWareHouseInfo;

CWareHouseInfo::CWareHouseInfo()
{

}

void CWareHouseInfo::Load()
{
}

void CWareHouseInfo::RecvWareHouseInfo(PMSG_WARE_INFO_RECV* Data)
{
	this->AnimatedWarehouse = Data->CustomWarehouseAnimated;
}

void Interface::DrawWarehouseUI()
{
	float PosX = this->GetResizeX(eWAREHOUSE);
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	this->DrawGUI(eWAREHOUSE, PosX, 348);
	this->DrawGUI(eWAREHOUSE1, PosX + 45, 348);
	this->DrawFormat(eWhite, PosX + 33, 350, 10, 1, "%d/5", gObjUser.m_WarehouseNumber + 1);
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		if (this->Data[eWAREHOUSE].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(255, 204, 20, 200));
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		if (this->Data[eWAREHOUSE1].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(255, 204, 20, 200));
	}
}

// ----------------------------------------------------------------------------------------------

void Interface::EventWarehouseUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber > 0)
		{
			gObjUser.m_WarehouseNumber--;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE1].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber < 4)
		{
			gObjUser.m_WarehouseNumber++;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
}

void Interface::DrawWarehouseWindow()
{

	if (!gInterface.Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	if (gServerInfo.AnimatedWarehouse == 1)
	{
		if (this->Data[eWAREHOUSE_MAIN].OpenedValue > 100)
		{
			this->Data[eWAREHOUSE_MAIN].OpenedValue -= this->Data[eWAREHOUSE_MAIN].Speed;

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue <= 250)
			{
				this->Data[eWAREHOUSE_MAIN].Speed = 15;
			}

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue < 100)
			{
				this->Data[eWAREHOUSE_MAIN].OpenedValue = 100;
			}
		}
	}

	// ----
	float MainWidth = 218;
	float MainHeight = 325.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	if (gServerInfo.AnimatedWarehouse == 1)
	{
		StartY = this->Data[eWAREHOUSE_MAIN].OpenedValue;//100.0;
	}
	// ----
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	//-----
	gInterface.DrawGUI(eWAREHOUSE_CLOSE, StartX + MainWidth - 30, StartBody - 7);
	if (this->IsWorkZone(eWAREHOUSE_CLOSE))
	{
		DWORD Color = eGray150;
		// ----
		if (this->Data[eWAREHOUSE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_CLOSE, this->Data[eWAREHOUSE_CLOSE].X, this->Data[eWAREHOUSE_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eWAREHOUSE_CLOSE].X - 7, this->Data[eWAREHOUSE_CLOSE].Y + 15, "Fechar");
	}
	// ----
	gInterface.DrawFormat(eGold180, (int)StartX + 10, (int)StartBody + 8, 210, 3, "Selecione o Baú");
	this->DrawFormat(eWhite, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 53, 210, 3, "BEM-VINDO %s, DE VOLTA AO BAÚ...", gObjUser.lpPlayer->Name);

	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 14, 200, 1); //-- Divisor


	if ((this->Page == 0) || (this->Page == 1) || (this->Page == 2) || (this->Page == 3) || (this->Page == 4) || (this->Page == 5) || (this->Page == 6))
	{
		gInterface.DrawGUI(eNextWare, StartX + MainWidth - 1, StartBody + 80);
	}
	else
	{
		gInterface.ResetDrawIMG(eNextWare);
	}

	if (this->Page == 1 || this->Page == 2 || this->Page == 3 || this->Page == 4 || this->Page == 5 || this->Page == 6 || this->Page == 7)
	{
		gInterface.DrawGUI(ePrevWare, StartX - 18, StartBody + 80);
	}
	else
	{
		gInterface.ResetDrawIMG(ePrevWare);
	}
	if ((this->Page == 1) || (this->Page == 2) || (this->Page == 3) || (this->Page == 4) || (this->Page == 5) || (this->Page == 6) || (this->Page == 7))
	{
		this->DrawFormat(eRed, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "SLOT VAZIO");
		this->DrawFormat(eRed, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "EMPTY SLOT");
		this->DrawFormat(eRed, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "RANURA VACÍA");
	}
	if ((this->Page == 0) || (this->Page == 1) || (this->Page == 2) || (this->Page == 3) || (this->Page == 4) || (this->Page == 5) || (this->Page == 6) || (this->Page == 7))
	{
		this->DrawFormat(eRed, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "SLOT VAZIO");
		this->DrawFormat(eRed, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "EMPTY SLOT");
		this->DrawFormat(eRed, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "RANURA VACÍA");
	}
	if (this->Page == 0)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM1, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 0");
		// ----
		if (gObjUser.m_MaxWarehouse >= 2)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM2, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 1");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 3)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM3, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 2");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 4)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM4, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 3");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 5)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM5, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 4");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 6)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM6, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 5");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 7)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM7, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 6");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 8)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM8, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 7");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 9)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM9, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 8");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 10)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM10, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 9");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 11)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM11, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 10");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 12)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM12, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 11");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 13)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM13, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 12");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 14)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM14, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 13");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 15)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM15, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 14");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 16)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM16, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 15");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 17)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM17, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 16");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 18)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM18, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 17");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 19)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM19, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 18");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 20)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM20, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 19");
		}
		// ----
		if (IsWorkZone(eWAREHOUSE_NUM1))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM1].OnClick)
			{
				eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM1, this->Data[eWAREHOUSE_NUM1].X, this->Data[eWAREHOUSE_NUM1].Y, Color);
		}
		if (gObjUser.m_MaxWarehouse >= 2)
		{
			if (IsWorkZone(eWAREHOUSE_NUM2))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM2].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM2, this->Data[eWAREHOUSE_NUM2].X, this->Data[eWAREHOUSE_NUM2].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 3)
		{
			if (IsWorkZone(eWAREHOUSE_NUM3))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM3].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM3, this->Data[eWAREHOUSE_NUM3].X, this->Data[eWAREHOUSE_NUM3].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 4)
		{
			if (IsWorkZone(eWAREHOUSE_NUM4))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM4].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM4, this->Data[eWAREHOUSE_NUM4].X, this->Data[eWAREHOUSE_NUM4].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 5)
		{
			if (IsWorkZone(eWAREHOUSE_NUM5))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM5].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM5, this->Data[eWAREHOUSE_NUM5].X, this->Data[eWAREHOUSE_NUM5].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 6)
		{
			if (IsWorkZone(eWAREHOUSE_NUM6))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM6].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM6, this->Data[eWAREHOUSE_NUM6].X, this->Data[eWAREHOUSE_NUM6].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 7)
		{
			if (IsWorkZone(eWAREHOUSE_NUM7))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM7].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM7, this->Data[eWAREHOUSE_NUM7].X, this->Data[eWAREHOUSE_NUM7].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 8)
		{
			if (IsWorkZone(eWAREHOUSE_NUM8))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM8].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM8, this->Data[eWAREHOUSE_NUM8].X, this->Data[eWAREHOUSE_NUM8].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 9)
		{
			if (IsWorkZone(eWAREHOUSE_NUM9))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM9].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM9, this->Data[eWAREHOUSE_NUM9].X, this->Data[eWAREHOUSE_NUM9].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 10)
		{
			if (IsWorkZone(eWAREHOUSE_NUM10))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM10].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM10, this->Data[eWAREHOUSE_NUM10].X, this->Data[eWAREHOUSE_NUM10].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 11)
		{
			if (IsWorkZone(eWAREHOUSE_NUM11))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM11].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM11, this->Data[eWAREHOUSE_NUM11].X, this->Data[eWAREHOUSE_NUM11].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 12)
		{
			if (IsWorkZone(eWAREHOUSE_NUM12))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM12].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM12, this->Data[eWAREHOUSE_NUM12].X, this->Data[eWAREHOUSE_NUM12].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 13)
		{
			if (IsWorkZone(eWAREHOUSE_NUM13))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM13].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM13, this->Data[eWAREHOUSE_NUM13].X, this->Data[eWAREHOUSE_NUM13].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 14)
		{
			if (IsWorkZone(eWAREHOUSE_NUM14))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM14].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM14, this->Data[eWAREHOUSE_NUM14].X, this->Data[eWAREHOUSE_NUM14].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 15)
		{
			if (IsWorkZone(eWAREHOUSE_NUM15))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM15].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM15, this->Data[eWAREHOUSE_NUM15].X, this->Data[eWAREHOUSE_NUM15].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 16)
		{
			if (IsWorkZone(eWAREHOUSE_NUM16))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM16].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM16, this->Data[eWAREHOUSE_NUM16].X, this->Data[eWAREHOUSE_NUM16].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 17)
		{
			if (IsWorkZone(eWAREHOUSE_NUM17))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM17].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM17, this->Data[eWAREHOUSE_NUM17].X, this->Data[eWAREHOUSE_NUM17].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 18)
		{
			if (IsWorkZone(eWAREHOUSE_NUM18))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM18].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM18, this->Data[eWAREHOUSE_NUM18].X, this->Data[eWAREHOUSE_NUM18].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 19)
		{
			if (IsWorkZone(eWAREHOUSE_NUM19))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM19].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM19, this->Data[eWAREHOUSE_NUM19].X, this->Data[eWAREHOUSE_NUM19].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 20)
		{
			if (IsWorkZone(eWAREHOUSE_NUM20))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM20].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM20, this->Data[eWAREHOUSE_NUM20].X, this->Data[eWAREHOUSE_NUM20].Y, Color);
			}
		}
	}
	// ----
	if (this->Page == 1)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM1);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM2);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM3);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM4);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM5);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM6);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM7);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM8);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM9);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM10);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM11);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM12);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM13);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM14);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM15);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM16);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM17);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM18);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM19);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM20);
	}
	//-----
	if (this->Page == 1)
	{
		if (gObjUser.m_MaxWarehouse >= 21)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM21, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 20");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 22)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM22, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 21");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 23)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM23, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 22");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 24)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM24, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 23");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 25)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM25, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 24");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 26)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM26, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 25");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 27)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM27, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 26");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 28)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM28, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 27");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 29)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM29, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 28");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 30)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM30, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 29");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 31)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM31, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 30");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 32)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM32, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 31");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 33)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM33, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 32");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 34)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM34, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 33");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 35)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM35, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 34");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 36)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM36, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 35");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 37)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM37, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 36");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 38)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM38, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 37");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 39)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM39, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 38");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 40)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM40, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 39");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 21)
		{
			if (IsWorkZone(eWAREHOUSE_NUM21))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM21].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM21, this->Data[eWAREHOUSE_NUM21].X, this->Data[eWAREHOUSE_NUM21].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 22)
		{
			if (IsWorkZone(eWAREHOUSE_NUM22))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM22].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM22, this->Data[eWAREHOUSE_NUM22].X, this->Data[eWAREHOUSE_NUM22].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 23)
		{
			if (IsWorkZone(eWAREHOUSE_NUM23))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM23].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM23, this->Data[eWAREHOUSE_NUM23].X, this->Data[eWAREHOUSE_NUM23].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 24)
		{
			if (IsWorkZone(eWAREHOUSE_NUM24))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM24].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM24, this->Data[eWAREHOUSE_NUM24].X, this->Data[eWAREHOUSE_NUM24].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 25)
		{
			if (IsWorkZone(eWAREHOUSE_NUM25))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM25].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM25, this->Data[eWAREHOUSE_NUM25].X, this->Data[eWAREHOUSE_NUM25].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 26)
		{
			if (IsWorkZone(eWAREHOUSE_NUM26))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM26].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM26, this->Data[eWAREHOUSE_NUM26].X, this->Data[eWAREHOUSE_NUM26].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 27)
		{
			if (IsWorkZone(eWAREHOUSE_NUM27))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM27].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM27, this->Data[eWAREHOUSE_NUM27].X, this->Data[eWAREHOUSE_NUM27].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 28)
		{
			if (IsWorkZone(eWAREHOUSE_NUM28))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM28].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM28, this->Data[eWAREHOUSE_NUM28].X, this->Data[eWAREHOUSE_NUM28].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 29)
		{
			if (IsWorkZone(eWAREHOUSE_NUM29))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM29].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM29, this->Data[eWAREHOUSE_NUM29].X, this->Data[eWAREHOUSE_NUM29].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 30)
		{
			if (IsWorkZone(eWAREHOUSE_NUM30))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM30].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM30, this->Data[eWAREHOUSE_NUM30].X, this->Data[eWAREHOUSE_NUM30].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 31)
		{
			if (IsWorkZone(eWAREHOUSE_NUM31))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM31].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM31, this->Data[eWAREHOUSE_NUM31].X, this->Data[eWAREHOUSE_NUM31].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 32)
		{
			if (IsWorkZone(eWAREHOUSE_NUM32))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM32].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM32, this->Data[eWAREHOUSE_NUM32].X, this->Data[eWAREHOUSE_NUM32].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 33)
		{
			if (IsWorkZone(eWAREHOUSE_NUM33))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM33].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM33, this->Data[eWAREHOUSE_NUM33].X, this->Data[eWAREHOUSE_NUM33].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 34)
		{
			if (IsWorkZone(eWAREHOUSE_NUM34))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM34].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM34, this->Data[eWAREHOUSE_NUM34].X, this->Data[eWAREHOUSE_NUM34].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 35)
		{
			if (IsWorkZone(eWAREHOUSE_NUM35))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM35].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM35, this->Data[eWAREHOUSE_NUM35].X, this->Data[eWAREHOUSE_NUM35].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 36)
		{
			if (IsWorkZone(eWAREHOUSE_NUM36))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM36].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM36, this->Data[eWAREHOUSE_NUM36].X, this->Data[eWAREHOUSE_NUM36].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 37)
		{
			if (IsWorkZone(eWAREHOUSE_NUM37))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM37].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM37, this->Data[eWAREHOUSE_NUM37].X, this->Data[eWAREHOUSE_NUM37].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 38)
		{
			if (IsWorkZone(eWAREHOUSE_NUM38))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM38].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM38, this->Data[eWAREHOUSE_NUM38].X, this->Data[eWAREHOUSE_NUM38].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 39)
		{
			if (IsWorkZone(eWAREHOUSE_NUM39))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM39].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM39, this->Data[eWAREHOUSE_NUM39].X, this->Data[eWAREHOUSE_NUM39].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 40)
		{
			if (IsWorkZone(eWAREHOUSE_NUM40))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM40].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM40, this->Data[eWAREHOUSE_NUM40].X, this->Data[eWAREHOUSE_NUM40].Y, Color);
			}
		}
	}
	// ----
	if (this->Page == 2)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM21);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM22);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM23);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM24);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM25);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM26);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM27);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM28);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM29);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM30);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM31);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM32);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM33);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM34);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM35);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM36);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM37);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM38);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM39);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM40);
	}
	//-----
	if (this->Page == 2)
	{
		if (gObjUser.m_MaxWarehouse >= 41)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM41, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 40");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 42)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM42, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 41");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 43)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM43, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 42");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 44)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM44, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 43");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 45)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM45, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 44");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 46)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM46, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 45");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 47)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM47, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 46");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 48)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM48, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 47");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 49)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM49, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 48");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 50)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM50, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 49");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 51)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM51, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 50");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 52)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM52, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 51");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 53)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM53, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 52");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 54)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM54, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 53");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 55)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM55, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 54");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 56)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM56, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 55");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 57)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM57, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 56");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 58)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM58, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 57");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 59)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM59, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 58");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 60)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM60, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 59");
		}
		if (gObjUser.m_MaxWarehouse >= 41)
		{
			if (IsWorkZone(eWAREHOUSE_NUM41))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM41].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM41, this->Data[eWAREHOUSE_NUM41].X, this->Data[eWAREHOUSE_NUM41].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 42)
		{
			if (IsWorkZone(eWAREHOUSE_NUM42))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM42].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM42, this->Data[eWAREHOUSE_NUM42].X, this->Data[eWAREHOUSE_NUM42].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 43)
		{
			if (IsWorkZone(eWAREHOUSE_NUM43))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM43].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM43, this->Data[eWAREHOUSE_NUM43].X, this->Data[eWAREHOUSE_NUM43].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 44)
		{
			if (IsWorkZone(eWAREHOUSE_NUM44))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM44].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM44, this->Data[eWAREHOUSE_NUM44].X, this->Data[eWAREHOUSE_NUM44].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 45)
		{
			if (IsWorkZone(eWAREHOUSE_NUM45))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM45].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM45, this->Data[eWAREHOUSE_NUM45].X, this->Data[eWAREHOUSE_NUM45].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 46)
		{
			if (IsWorkZone(eWAREHOUSE_NUM46))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM46].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM46, this->Data[eWAREHOUSE_NUM46].X, this->Data[eWAREHOUSE_NUM46].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 47)
		{
			if (IsWorkZone(eWAREHOUSE_NUM47))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM47].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM47, this->Data[eWAREHOUSE_NUM47].X, this->Data[eWAREHOUSE_NUM47].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 48)
		{
			if (IsWorkZone(eWAREHOUSE_NUM48))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM48].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM48, this->Data[eWAREHOUSE_NUM48].X, this->Data[eWAREHOUSE_NUM48].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 49)
		{
			if (IsWorkZone(eWAREHOUSE_NUM49))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM49].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM49, this->Data[eWAREHOUSE_NUM49].X, this->Data[eWAREHOUSE_NUM49].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 50)
		{
			if (IsWorkZone(eWAREHOUSE_NUM50))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM50].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM50, this->Data[eWAREHOUSE_NUM50].X, this->Data[eWAREHOUSE_NUM50].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 51)
		{
			if (IsWorkZone(eWAREHOUSE_NUM51))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM51].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM51, this->Data[eWAREHOUSE_NUM51].X, this->Data[eWAREHOUSE_NUM51].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 52)
		{
			if (IsWorkZone(eWAREHOUSE_NUM52))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM52].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM52, this->Data[eWAREHOUSE_NUM52].X, this->Data[eWAREHOUSE_NUM52].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 53)
		{
			if (IsWorkZone(eWAREHOUSE_NUM53))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM53].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM53, this->Data[eWAREHOUSE_NUM53].X, this->Data[eWAREHOUSE_NUM53].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 54)
		{
			if (IsWorkZone(eWAREHOUSE_NUM54))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM54].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM54, this->Data[eWAREHOUSE_NUM54].X, this->Data[eWAREHOUSE_NUM54].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 55)
		{
			if (IsWorkZone(eWAREHOUSE_NUM55))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM55].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM55, this->Data[eWAREHOUSE_NUM55].X, this->Data[eWAREHOUSE_NUM55].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 56)
		{
			if (IsWorkZone(eWAREHOUSE_NUM56))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM56].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM56, this->Data[eWAREHOUSE_NUM56].X, this->Data[eWAREHOUSE_NUM56].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 57)
		{
			if (IsWorkZone(eWAREHOUSE_NUM57))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM57].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM57, this->Data[eWAREHOUSE_NUM57].X, this->Data[eWAREHOUSE_NUM57].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 58)
		{
			if (IsWorkZone(eWAREHOUSE_NUM58))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM58].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM58, this->Data[eWAREHOUSE_NUM58].X, this->Data[eWAREHOUSE_NUM58].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 59)
		{
			if (IsWorkZone(eWAREHOUSE_NUM59))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM59].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM59, this->Data[eWAREHOUSE_NUM59].X, this->Data[eWAREHOUSE_NUM59].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 60)
		{
			if (IsWorkZone(eWAREHOUSE_NUM60))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM60].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM60, this->Data[eWAREHOUSE_NUM60].X, this->Data[eWAREHOUSE_NUM60].Y, Color);
			}
		}
	}
	if (this->Page == 3)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM41);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM42);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM43);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM44);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM45);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM46);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM47);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM48);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM49);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM50);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM51);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM52);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM53);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM54);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM55);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM56);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM57);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM58);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM59);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM60);
	}
	//-----
	if (this->Page == 3)
	{
		if (gObjUser.m_MaxWarehouse >= 61)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM61, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 60");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 62)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM62, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 61");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 63)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM63, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 62");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 64)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM64, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 63");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 65)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM65, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 64");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 66)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM66, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 65");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 67)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM67, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 66");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 68)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM68, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 67");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 69)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM69, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 68");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 70)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM70, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 69");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 71)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM71, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 70");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 72)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM72, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 71");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 73)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM73, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 72");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 74)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM74, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 73");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 75)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM75, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 74");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 76)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM76, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 75");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 77)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM77, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 76");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 78)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM78, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 77");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 79)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM79, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 78");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 80)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM80, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 79");
		}
		if (gObjUser.m_MaxWarehouse >= 61)
		{
			if (IsWorkZone(eWAREHOUSE_NUM61))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM61].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM61, this->Data[eWAREHOUSE_NUM61].X, this->Data[eWAREHOUSE_NUM61].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 62)
		{
			if (IsWorkZone(eWAREHOUSE_NUM62))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM62].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM62, this->Data[eWAREHOUSE_NUM62].X, this->Data[eWAREHOUSE_NUM62].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 63)
		{
			if (IsWorkZone(eWAREHOUSE_NUM63))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM63].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM63, this->Data[eWAREHOUSE_NUM63].X, this->Data[eWAREHOUSE_NUM63].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 64)
		{
			if (IsWorkZone(eWAREHOUSE_NUM64))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM64].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM64, this->Data[eWAREHOUSE_NUM64].X, this->Data[eWAREHOUSE_NUM64].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 65)
		{
			if (IsWorkZone(eWAREHOUSE_NUM65))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM65].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM65, this->Data[eWAREHOUSE_NUM65].X, this->Data[eWAREHOUSE_NUM65].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 66)
		{
			if (IsWorkZone(eWAREHOUSE_NUM66))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM66].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM66, this->Data[eWAREHOUSE_NUM66].X, this->Data[eWAREHOUSE_NUM66].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 67)
		{
			if (IsWorkZone(eWAREHOUSE_NUM67))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM67].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM67, this->Data[eWAREHOUSE_NUM67].X, this->Data[eWAREHOUSE_NUM67].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 68)
		{
			if (IsWorkZone(eWAREHOUSE_NUM68))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM68].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM68, this->Data[eWAREHOUSE_NUM68].X, this->Data[eWAREHOUSE_NUM68].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 69)
		{
			if (IsWorkZone(eWAREHOUSE_NUM69))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM69].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM69, this->Data[eWAREHOUSE_NUM69].X, this->Data[eWAREHOUSE_NUM69].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 70)
		{
			if (IsWorkZone(eWAREHOUSE_NUM70))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM70].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM70, this->Data[eWAREHOUSE_NUM70].X, this->Data[eWAREHOUSE_NUM70].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 71)
		{
			if (IsWorkZone(eWAREHOUSE_NUM71))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM71].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM71, this->Data[eWAREHOUSE_NUM71].X, this->Data[eWAREHOUSE_NUM71].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 72)
		{
			if (IsWorkZone(eWAREHOUSE_NUM72))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM72].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM72, this->Data[eWAREHOUSE_NUM72].X, this->Data[eWAREHOUSE_NUM72].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 73)
		{
			if (IsWorkZone(eWAREHOUSE_NUM73))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM73].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM73, this->Data[eWAREHOUSE_NUM73].X, this->Data[eWAREHOUSE_NUM73].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 74)
		{
			if (IsWorkZone(eWAREHOUSE_NUM74))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM74].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM74, this->Data[eWAREHOUSE_NUM74].X, this->Data[eWAREHOUSE_NUM74].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 75)
		{
			if (IsWorkZone(eWAREHOUSE_NUM75))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM75].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM75, this->Data[eWAREHOUSE_NUM75].X, this->Data[eWAREHOUSE_NUM75].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 76)
		{
			if (IsWorkZone(eWAREHOUSE_NUM76))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM76].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM76, this->Data[eWAREHOUSE_NUM76].X, this->Data[eWAREHOUSE_NUM76].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 77)
		{
			if (IsWorkZone(eWAREHOUSE_NUM77))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM77].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM77, this->Data[eWAREHOUSE_NUM77].X, this->Data[eWAREHOUSE_NUM77].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 78)
		{
			if (IsWorkZone(eWAREHOUSE_NUM78))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM78].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM78, this->Data[eWAREHOUSE_NUM78].X, this->Data[eWAREHOUSE_NUM78].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 79)
		{
			if (IsWorkZone(eWAREHOUSE_NUM79))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM79].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM79, this->Data[eWAREHOUSE_NUM79].X, this->Data[eWAREHOUSE_NUM79].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 80)
		{
			if (IsWorkZone(eWAREHOUSE_NUM80))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM80].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM80, this->Data[eWAREHOUSE_NUM80].X, this->Data[eWAREHOUSE_NUM80].Y, Color);
			}
		}
	}
	if (this->Page == 4)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM61);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM62);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM63);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM64);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM65);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM66);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM67);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM68);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM69);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM70);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM71);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM72);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM73);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM74);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM75);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM76);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM77);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM78);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM79);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM80);
	}
	//-----
	if (this->Page == 4)
	{
		if (gObjUser.m_MaxWarehouse >= 81)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM81, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 80");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 82)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM82, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 81");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 83)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM83, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 82");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 84)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM84, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 83");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 85)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM85, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 84");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 86)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM86, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 85");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 87)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM87, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 86");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 88)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM88, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 87");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 89)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM89, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 88");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 90)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM90, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 89");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 91)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM91, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 90");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 92)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM92, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 91");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 93)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM93, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 92");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 94)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM94, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 93");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 95)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM95, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 94");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 96)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM96, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 95");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 97)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM97, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 96");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 98)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM98, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 97");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 99)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM99, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 98");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 100)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM100, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 99");
		}
		if (gObjUser.m_MaxWarehouse >= 81)
		{
			if (IsWorkZone(eWAREHOUSE_NUM81))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM81].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM81, this->Data[eWAREHOUSE_NUM81].X, this->Data[eWAREHOUSE_NUM81].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 82)
		{
			if (IsWorkZone(eWAREHOUSE_NUM82))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM82].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM82, this->Data[eWAREHOUSE_NUM82].X, this->Data[eWAREHOUSE_NUM82].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 83)
		{
			if (IsWorkZone(eWAREHOUSE_NUM83))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM83].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM83, this->Data[eWAREHOUSE_NUM83].X, this->Data[eWAREHOUSE_NUM83].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 84)
		{
			if (IsWorkZone(eWAREHOUSE_NUM84))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM84].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM84, this->Data[eWAREHOUSE_NUM84].X, this->Data[eWAREHOUSE_NUM84].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 85)
		{
			if (IsWorkZone(eWAREHOUSE_NUM85))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM85].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM85, this->Data[eWAREHOUSE_NUM85].X, this->Data[eWAREHOUSE_NUM85].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 86)
		{
			if (IsWorkZone(eWAREHOUSE_NUM86))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM86].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM86, this->Data[eWAREHOUSE_NUM86].X, this->Data[eWAREHOUSE_NUM86].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 87)
		{
			if (IsWorkZone(eWAREHOUSE_NUM87))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM87].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM87, this->Data[eWAREHOUSE_NUM87].X, this->Data[eWAREHOUSE_NUM87].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 88)
		{
			if (IsWorkZone(eWAREHOUSE_NUM88))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM88].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM88, this->Data[eWAREHOUSE_NUM88].X, this->Data[eWAREHOUSE_NUM88].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 89)
		{
			if (IsWorkZone(eWAREHOUSE_NUM89))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM89].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM89, this->Data[eWAREHOUSE_NUM89].X, this->Data[eWAREHOUSE_NUM89].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 90)
		{
			if (IsWorkZone(eWAREHOUSE_NUM90))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM90].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM90, this->Data[eWAREHOUSE_NUM90].X, this->Data[eWAREHOUSE_NUM90].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 91)
		{
			if (IsWorkZone(eWAREHOUSE_NUM91))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM91].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM91, this->Data[eWAREHOUSE_NUM91].X, this->Data[eWAREHOUSE_NUM91].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 92)
		{
			if (IsWorkZone(eWAREHOUSE_NUM92))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM92].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM92, this->Data[eWAREHOUSE_NUM92].X, this->Data[eWAREHOUSE_NUM92].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 93)
		{
			if (IsWorkZone(eWAREHOUSE_NUM93))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM93].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM93, this->Data[eWAREHOUSE_NUM93].X, this->Data[eWAREHOUSE_NUM93].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 94)
		{
			if (IsWorkZone(eWAREHOUSE_NUM94))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM94].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM94, this->Data[eWAREHOUSE_NUM94].X, this->Data[eWAREHOUSE_NUM94].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 95)
		{
			if (IsWorkZone(eWAREHOUSE_NUM95))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM95].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM95, this->Data[eWAREHOUSE_NUM95].X, this->Data[eWAREHOUSE_NUM95].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 96)
		{
			if (IsWorkZone(eWAREHOUSE_NUM96))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM96].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM96, this->Data[eWAREHOUSE_NUM96].X, this->Data[eWAREHOUSE_NUM96].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 97)
		{
			if (IsWorkZone(eWAREHOUSE_NUM97))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM97].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM97, this->Data[eWAREHOUSE_NUM97].X, this->Data[eWAREHOUSE_NUM97].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 98)
		{
			if (IsWorkZone(eWAREHOUSE_NUM98))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM98].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM98, this->Data[eWAREHOUSE_NUM98].X, this->Data[eWAREHOUSE_NUM98].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 99)
		{
			if (IsWorkZone(eWAREHOUSE_NUM99))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM99].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM99, this->Data[eWAREHOUSE_NUM99].X, this->Data[eWAREHOUSE_NUM99].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 100)
		{
			if (IsWorkZone(eWAREHOUSE_NUM100))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM100].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM100, this->Data[eWAREHOUSE_NUM100].X, this->Data[eWAREHOUSE_NUM100].Y, Color);
			}
		}
	}
	if (this->Page == 5)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM81);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM82);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM83);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM84);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM85);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM86);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM87);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM88);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM89);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM90);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM91);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM92);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM93);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM94);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM95);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM96);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM97);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM98);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM99);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM100);
	}
	//-----
	if (this->Page == 5)
	{
		if (gObjUser.m_MaxWarehouse >= 101)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM101, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 100");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 102)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM102, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 101");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 103)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM103, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 102");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 104)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM104, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 103");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 105)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM105, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 104");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 106)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM106, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 105");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 107)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM107, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 106");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 108)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM108, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 107");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 109)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM109, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 108");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 110)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM110, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 109");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 111)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM111, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 110");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 112)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM112, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 111");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 113)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM113, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 112");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 114)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM114, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 113");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 115)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM115, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 114");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 116)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM116, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 115");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 117)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM117, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 116");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 118)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM118, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 117");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 119)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM119, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 118");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 120)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM120, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 119");
		}
		if (gObjUser.m_MaxWarehouse >= 101)
		{
			if (IsWorkZone(eWAREHOUSE_NUM101))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM101].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM101, this->Data[eWAREHOUSE_NUM101].X, this->Data[eWAREHOUSE_NUM101].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 102)
		{
			if (IsWorkZone(eWAREHOUSE_NUM102))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM102].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM102, this->Data[eWAREHOUSE_NUM102].X, this->Data[eWAREHOUSE_NUM102].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 103)
		{
			if (IsWorkZone(eWAREHOUSE_NUM103))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM103].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM103, this->Data[eWAREHOUSE_NUM103].X, this->Data[eWAREHOUSE_NUM103].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 104)
		{
			if (IsWorkZone(eWAREHOUSE_NUM104))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM104].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM104, this->Data[eWAREHOUSE_NUM104].X, this->Data[eWAREHOUSE_NUM104].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 105)
		{
			if (IsWorkZone(eWAREHOUSE_NUM105))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM105].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM105, this->Data[eWAREHOUSE_NUM105].X, this->Data[eWAREHOUSE_NUM105].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 106)
		{
			if (IsWorkZone(eWAREHOUSE_NUM106))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM106].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM106, this->Data[eWAREHOUSE_NUM106].X, this->Data[eWAREHOUSE_NUM106].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 107)
		{
			if (IsWorkZone(eWAREHOUSE_NUM107))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM107].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM107, this->Data[eWAREHOUSE_NUM107].X, this->Data[eWAREHOUSE_NUM107].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 108)
		{
			if (IsWorkZone(eWAREHOUSE_NUM108))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM108].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM108, this->Data[eWAREHOUSE_NUM108].X, this->Data[eWAREHOUSE_NUM108].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 109)
		{
			if (IsWorkZone(eWAREHOUSE_NUM109))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM109].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM109, this->Data[eWAREHOUSE_NUM109].X, this->Data[eWAREHOUSE_NUM109].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 110)
		{
			if (IsWorkZone(eWAREHOUSE_NUM110))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM110].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM110, this->Data[eWAREHOUSE_NUM110].X, this->Data[eWAREHOUSE_NUM110].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 111)
		{
			if (IsWorkZone(eWAREHOUSE_NUM111))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM111].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM111, this->Data[eWAREHOUSE_NUM111].X, this->Data[eWAREHOUSE_NUM111].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 112)
		{
			if (IsWorkZone(eWAREHOUSE_NUM112))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM112].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM112, this->Data[eWAREHOUSE_NUM112].X, this->Data[eWAREHOUSE_NUM112].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 113)
		{
			if (IsWorkZone(eWAREHOUSE_NUM113))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM113].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM113, this->Data[eWAREHOUSE_NUM113].X, this->Data[eWAREHOUSE_NUM113].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 114)
		{
			if (IsWorkZone(eWAREHOUSE_NUM114))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM114].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM114, this->Data[eWAREHOUSE_NUM114].X, this->Data[eWAREHOUSE_NUM114].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 115)
		{
			if (IsWorkZone(eWAREHOUSE_NUM115))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM115].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM115, this->Data[eWAREHOUSE_NUM115].X, this->Data[eWAREHOUSE_NUM115].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 116)
		{
			if (IsWorkZone(eWAREHOUSE_NUM116))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM116].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM116, this->Data[eWAREHOUSE_NUM116].X, this->Data[eWAREHOUSE_NUM116].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 117)
		{
			if (IsWorkZone(eWAREHOUSE_NUM117))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM117].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM117, this->Data[eWAREHOUSE_NUM117].X, this->Data[eWAREHOUSE_NUM117].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 118)
		{
			if (IsWorkZone(eWAREHOUSE_NUM118))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM118].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM118, this->Data[eWAREHOUSE_NUM118].X, this->Data[eWAREHOUSE_NUM118].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 119)
		{
			if (IsWorkZone(eWAREHOUSE_NUM119))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM119].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM119, this->Data[eWAREHOUSE_NUM119].X, this->Data[eWAREHOUSE_NUM119].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 120)
		{
			if (IsWorkZone(eWAREHOUSE_NUM120))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM120].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM120, this->Data[eWAREHOUSE_NUM120].X, this->Data[eWAREHOUSE_NUM120].Y, Color);
			}
		}
	}
	if (this->Page == 6)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM101);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM102);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM103);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM104);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM105);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM106);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM107);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM108);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM109);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM110);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM111);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM112);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM113);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM114);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM115);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM116);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM117);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM118);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM119);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM120);
	}
	//-----
	if (this->Page == 6)
	{
		if (gObjUser.m_MaxWarehouse >= 121)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM121, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 120");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 122)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM122, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 121");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 123)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM123, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 122");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 124)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM124, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 123");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 125)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM125, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 124");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 126)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM126, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 125");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 127)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM127, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 126");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 128)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM128, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 127");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 129)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM129, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 128");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 130)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM130, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 129");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 131)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM131, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 130");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 132)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM132, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 131");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 133)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM133, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 132");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 134)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM134, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 133");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 135)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM135, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 134");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 136)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM136, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 135");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 137)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM137, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 136");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 138)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM138, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 137");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 139)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM139, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 138");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 140)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM140, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 139");
		}
		if (gObjUser.m_MaxWarehouse >= 121)
		{
			if (IsWorkZone(eWAREHOUSE_NUM121))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM121].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM121, this->Data[eWAREHOUSE_NUM121].X, this->Data[eWAREHOUSE_NUM121].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 122)
		{
			if (IsWorkZone(eWAREHOUSE_NUM122))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM122].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM122, this->Data[eWAREHOUSE_NUM122].X, this->Data[eWAREHOUSE_NUM122].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 123)
		{
			if (IsWorkZone(eWAREHOUSE_NUM123))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM123].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM123, this->Data[eWAREHOUSE_NUM123].X, this->Data[eWAREHOUSE_NUM123].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 124)
		{
			if (IsWorkZone(eWAREHOUSE_NUM124))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM124].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM124, this->Data[eWAREHOUSE_NUM124].X, this->Data[eWAREHOUSE_NUM124].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 125)
		{
			if (IsWorkZone(eWAREHOUSE_NUM125))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM125].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM125, this->Data[eWAREHOUSE_NUM125].X, this->Data[eWAREHOUSE_NUM125].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 126)
		{
			if (IsWorkZone(eWAREHOUSE_NUM126))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM126].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM126, this->Data[eWAREHOUSE_NUM126].X, this->Data[eWAREHOUSE_NUM126].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 127)
		{
			if (IsWorkZone(eWAREHOUSE_NUM127))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM127].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM127, this->Data[eWAREHOUSE_NUM127].X, this->Data[eWAREHOUSE_NUM127].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 128)
		{
			if (IsWorkZone(eWAREHOUSE_NUM128))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM128].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM128, this->Data[eWAREHOUSE_NUM128].X, this->Data[eWAREHOUSE_NUM128].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 129)
		{
			if (IsWorkZone(eWAREHOUSE_NUM129))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM129].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM129, this->Data[eWAREHOUSE_NUM129].X, this->Data[eWAREHOUSE_NUM129].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 130)
		{
			if (IsWorkZone(eWAREHOUSE_NUM130))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM130].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM130, this->Data[eWAREHOUSE_NUM130].X, this->Data[eWAREHOUSE_NUM130].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 131)
		{
			if (IsWorkZone(eWAREHOUSE_NUM131))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM131].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM131, this->Data[eWAREHOUSE_NUM131].X, this->Data[eWAREHOUSE_NUM131].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 132)
		{
			if (IsWorkZone(eWAREHOUSE_NUM132))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM132].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM132, this->Data[eWAREHOUSE_NUM132].X, this->Data[eWAREHOUSE_NUM132].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 133)
		{
			if (IsWorkZone(eWAREHOUSE_NUM133))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM133].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM133, this->Data[eWAREHOUSE_NUM133].X, this->Data[eWAREHOUSE_NUM133].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 134)
		{
			if (IsWorkZone(eWAREHOUSE_NUM134))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM134].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM134, this->Data[eWAREHOUSE_NUM134].X, this->Data[eWAREHOUSE_NUM134].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 135)
		{
			if (IsWorkZone(eWAREHOUSE_NUM135))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM135].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM135, this->Data[eWAREHOUSE_NUM135].X, this->Data[eWAREHOUSE_NUM135].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 136)
		{
			if (IsWorkZone(eWAREHOUSE_NUM136))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM136].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM136, this->Data[eWAREHOUSE_NUM136].X, this->Data[eWAREHOUSE_NUM136].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 137)
		{
			if (IsWorkZone(eWAREHOUSE_NUM137))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM137].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM137, this->Data[eWAREHOUSE_NUM137].X, this->Data[eWAREHOUSE_NUM137].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 138)
		{
			if (IsWorkZone(eWAREHOUSE_NUM138))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM138].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM138, this->Data[eWAREHOUSE_NUM138].X, this->Data[eWAREHOUSE_NUM138].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 139)
		{
			if (IsWorkZone(eWAREHOUSE_NUM139))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM139].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM139, this->Data[eWAREHOUSE_NUM139].X, this->Data[eWAREHOUSE_NUM139].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 140)
		{
			if (IsWorkZone(eWAREHOUSE_NUM140))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM140].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM140, this->Data[eWAREHOUSE_NUM140].X, this->Data[eWAREHOUSE_NUM140].Y, Color);
			}
		}
	}
	if (this->Page == 7)
	{
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM121);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM122);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM123);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM124);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM125);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM126);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM127);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM128);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM129);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM130);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM131);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM132);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM133);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM134);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM135);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM136);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM137);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM138);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM139);
		gInterface.ResetDrawIMG(eWAREHOUSE_NUM140);
	}
	//-----
	if (this->Page == 7)
	{
		if (gObjUser.m_MaxWarehouse >= 141)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM141, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 140");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 142)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM142, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 141");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 143)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM143, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 142");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 144)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM144, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 143");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 145)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM145, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 144");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 146)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM146, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 145");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 147)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM147, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 146");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 148)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM148, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 147");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 149)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM149, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 148");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 150)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM150, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 149");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 151)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM151, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 69);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 79, 210, 3, "WAREHOUSE 150");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 152)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM152, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 100);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 110, 210, 3, "WAREHOUSE 151");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 153)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM153, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 131);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 141, 210, 3, "WAREHOUSE 152");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 154)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM154, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 162);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 172, 210, 3, "WAREHOUSE 153");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 155)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM155, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 193);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 203, 210, 3, "WAREHOUSE 154");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 156)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM156, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 224);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 234, 210, 3, "WAREHOUSE 155");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 157)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM157, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 255);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 265, 210, 3, "WAREHOUSE 156");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 158)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM158, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 286);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 296, 210, 3, "WAREHOUSE 157");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 159)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM159, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 317);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 327, 210, 3, "WAREHOUSE 158");
		}
		// ----
		if (gObjUser.m_MaxWarehouse >= 160)
		{
			this->DrawAnimatedGUI(eWAREHOUSE_NUM160, ButtonX + 53, this->Data[eWAREHOUSE_MAIN].Y + 348);
			this->DrawFormat(eWhite, StartX + 60, this->Data[eWAREHOUSE_MAIN].Y + 358, 210, 3, "WAREHOUSE 159");
		}
		if (gObjUser.m_MaxWarehouse >= 141)
		{
			if (IsWorkZone(eWAREHOUSE_NUM141))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM141].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM141, this->Data[eWAREHOUSE_NUM141].X, this->Data[eWAREHOUSE_NUM141].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 142)
		{
			if (IsWorkZone(eWAREHOUSE_NUM142))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM142].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM142, this->Data[eWAREHOUSE_NUM142].X, this->Data[eWAREHOUSE_NUM142].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 143)
		{
			if (IsWorkZone(eWAREHOUSE_NUM143))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM143].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM143, this->Data[eWAREHOUSE_NUM143].X, this->Data[eWAREHOUSE_NUM143].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 144)
		{
			if (IsWorkZone(eWAREHOUSE_NUM144))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM144].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM144, this->Data[eWAREHOUSE_NUM144].X, this->Data[eWAREHOUSE_NUM144].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 145)
		{
			if (IsWorkZone(eWAREHOUSE_NUM145))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM145].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM145, this->Data[eWAREHOUSE_NUM145].X, this->Data[eWAREHOUSE_NUM145].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 146)
		{
			if (IsWorkZone(eWAREHOUSE_NUM146))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM146].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM146, this->Data[eWAREHOUSE_NUM146].X, this->Data[eWAREHOUSE_NUM146].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 147)
		{
			if (IsWorkZone(eWAREHOUSE_NUM147))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM147].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM147, this->Data[eWAREHOUSE_NUM147].X, this->Data[eWAREHOUSE_NUM147].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 148)
		{
			if (IsWorkZone(eWAREHOUSE_NUM148))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM148].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM148, this->Data[eWAREHOUSE_NUM148].X, this->Data[eWAREHOUSE_NUM148].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 149)
		{
			if (IsWorkZone(eWAREHOUSE_NUM149))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM149].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM149, this->Data[eWAREHOUSE_NUM149].X, this->Data[eWAREHOUSE_NUM149].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 150)
		{
			if (IsWorkZone(eWAREHOUSE_NUM150))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM150].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM150, this->Data[eWAREHOUSE_NUM150].X, this->Data[eWAREHOUSE_NUM150].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 151)
		{
			if (IsWorkZone(eWAREHOUSE_NUM151))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM151].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM151, this->Data[eWAREHOUSE_NUM151].X, this->Data[eWAREHOUSE_NUM151].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 152)
		{
			if (IsWorkZone(eWAREHOUSE_NUM152))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM152].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM152, this->Data[eWAREHOUSE_NUM152].X, this->Data[eWAREHOUSE_NUM152].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 153)
		{
			if (IsWorkZone(eWAREHOUSE_NUM153))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM153].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM153, this->Data[eWAREHOUSE_NUM153].X, this->Data[eWAREHOUSE_NUM153].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 154)
		{
			if (IsWorkZone(eWAREHOUSE_NUM154))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM154].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM154, this->Data[eWAREHOUSE_NUM154].X, this->Data[eWAREHOUSE_NUM154].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 155)
		{
			if (IsWorkZone(eWAREHOUSE_NUM155))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM155].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM155, this->Data[eWAREHOUSE_NUM155].X, this->Data[eWAREHOUSE_NUM155].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 156)
		{
			if (IsWorkZone(eWAREHOUSE_NUM156))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM156].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM156, this->Data[eWAREHOUSE_NUM156].X, this->Data[eWAREHOUSE_NUM156].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 157)
		{
			if (IsWorkZone(eWAREHOUSE_NUM157))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM157].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM157, this->Data[eWAREHOUSE_NUM157].X, this->Data[eWAREHOUSE_NUM157].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 158)
		{
			if (IsWorkZone(eWAREHOUSE_NUM158))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM158].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM158, this->Data[eWAREHOUSE_NUM158].X, this->Data[eWAREHOUSE_NUM158].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 159)
		{
			if (IsWorkZone(eWAREHOUSE_NUM159))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM159].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM159, this->Data[eWAREHOUSE_NUM159].X, this->Data[eWAREHOUSE_NUM159].Y, Color);
			}
		}
		if (gObjUser.m_MaxWarehouse >= 160)
		{
			if (IsWorkZone(eWAREHOUSE_NUM160))
			{
				DWORD Color = eGray100;
				// ----
				if (this->Data[eWAREHOUSE_NUM160].OnClick)
				{
					eGray150;
				}
				// ----
				this->DrawColoredGUI(eWAREHOUSE_NUM160, this->Data[eWAREHOUSE_NUM160].X, this->Data[eWAREHOUSE_NUM160].Y, Color);
			}
		}
	}
}

void Interface::EventWarehouseWindow_Main(DWORD Event)
{
	this->EventWarehouseWindow_Close(Event);


	DWORD CurrentTick = GetTickCount();

	if ((CurrentTick - this->Data[eWAREHOUSE_MAIN].EventTick) < 500)
	{
		return;
	}
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	int ObjectIDs[160] =
	{
		eWAREHOUSE_NUM1,
		eWAREHOUSE_NUM2,
		eWAREHOUSE_NUM3,
		eWAREHOUSE_NUM4,
		eWAREHOUSE_NUM5,
		eWAREHOUSE_NUM6,
		eWAREHOUSE_NUM7,
		eWAREHOUSE_NUM8,
		eWAREHOUSE_NUM9,
		eWAREHOUSE_NUM10,
		eWAREHOUSE_NUM11,
		eWAREHOUSE_NUM12,
		eWAREHOUSE_NUM13,
		eWAREHOUSE_NUM14,
		eWAREHOUSE_NUM15,
		eWAREHOUSE_NUM16,
		eWAREHOUSE_NUM17,
		eWAREHOUSE_NUM18,
		eWAREHOUSE_NUM19,
		eWAREHOUSE_NUM20,
		eWAREHOUSE_NUM21,
		eWAREHOUSE_NUM22,
		eWAREHOUSE_NUM23,
		eWAREHOUSE_NUM24,
		eWAREHOUSE_NUM25,
		eWAREHOUSE_NUM26,
		eWAREHOUSE_NUM27,
		eWAREHOUSE_NUM28,
		eWAREHOUSE_NUM29,
		eWAREHOUSE_NUM30,
		eWAREHOUSE_NUM31,
		eWAREHOUSE_NUM32,
		eWAREHOUSE_NUM33,
		eWAREHOUSE_NUM34,
		eWAREHOUSE_NUM35,
		eWAREHOUSE_NUM36,
		eWAREHOUSE_NUM37,
		eWAREHOUSE_NUM38,
		eWAREHOUSE_NUM39,
		eWAREHOUSE_NUM40,
		eWAREHOUSE_NUM41,
		eWAREHOUSE_NUM42,
		eWAREHOUSE_NUM43,
		eWAREHOUSE_NUM44,
		eWAREHOUSE_NUM45,
		eWAREHOUSE_NUM46,
		eWAREHOUSE_NUM47,
		eWAREHOUSE_NUM48,
		eWAREHOUSE_NUM49,
		eWAREHOUSE_NUM50,
		eWAREHOUSE_NUM51,
		eWAREHOUSE_NUM52,
		eWAREHOUSE_NUM53,
		eWAREHOUSE_NUM54,
		eWAREHOUSE_NUM55,
		eWAREHOUSE_NUM56,
		eWAREHOUSE_NUM57,
		eWAREHOUSE_NUM58,
		eWAREHOUSE_NUM59,
		eWAREHOUSE_NUM60,
		eWAREHOUSE_NUM61,
		eWAREHOUSE_NUM62,
		eWAREHOUSE_NUM63,
		eWAREHOUSE_NUM64,
		eWAREHOUSE_NUM65,
		eWAREHOUSE_NUM66,
		eWAREHOUSE_NUM67,
		eWAREHOUSE_NUM68,
		eWAREHOUSE_NUM69,
		eWAREHOUSE_NUM70,
		eWAREHOUSE_NUM71,
		eWAREHOUSE_NUM72,
		eWAREHOUSE_NUM73,
		eWAREHOUSE_NUM74,
		eWAREHOUSE_NUM75,
		eWAREHOUSE_NUM76,
		eWAREHOUSE_NUM77,
		eWAREHOUSE_NUM78,
		eWAREHOUSE_NUM79,
		eWAREHOUSE_NUM80,
		eWAREHOUSE_NUM81,
		eWAREHOUSE_NUM82,
		eWAREHOUSE_NUM83,
		eWAREHOUSE_NUM84,
		eWAREHOUSE_NUM85,
		eWAREHOUSE_NUM86,
		eWAREHOUSE_NUM87,
		eWAREHOUSE_NUM88,
		eWAREHOUSE_NUM89,
		eWAREHOUSE_NUM90,
		eWAREHOUSE_NUM91,
		eWAREHOUSE_NUM92,
		eWAREHOUSE_NUM93,
		eWAREHOUSE_NUM94,
		eWAREHOUSE_NUM95,
		eWAREHOUSE_NUM96,
		eWAREHOUSE_NUM97,
		eWAREHOUSE_NUM98,
		eWAREHOUSE_NUM99,
		eWAREHOUSE_NUM100,
		eWAREHOUSE_NUM101,
		eWAREHOUSE_NUM102,
		eWAREHOUSE_NUM103,
		eWAREHOUSE_NUM104,
		eWAREHOUSE_NUM105,
		eWAREHOUSE_NUM106,
		eWAREHOUSE_NUM107,
		eWAREHOUSE_NUM108,
		eWAREHOUSE_NUM109,
		eWAREHOUSE_NUM110,
		eWAREHOUSE_NUM111,
		eWAREHOUSE_NUM112,
		eWAREHOUSE_NUM113,
		eWAREHOUSE_NUM114,
		eWAREHOUSE_NUM115,
		eWAREHOUSE_NUM116,
		eWAREHOUSE_NUM117,
		eWAREHOUSE_NUM118,
		eWAREHOUSE_NUM119,
		eWAREHOUSE_NUM120,
		eWAREHOUSE_NUM121,
		eWAREHOUSE_NUM122,
		eWAREHOUSE_NUM123,
		eWAREHOUSE_NUM124,
		eWAREHOUSE_NUM125,
		eWAREHOUSE_NUM126,
		eWAREHOUSE_NUM127,
		eWAREHOUSE_NUM128,
		eWAREHOUSE_NUM129,
		eWAREHOUSE_NUM130,
		eWAREHOUSE_NUM131,
		eWAREHOUSE_NUM132,
		eWAREHOUSE_NUM133,
		eWAREHOUSE_NUM134,
		eWAREHOUSE_NUM135,
		eWAREHOUSE_NUM136,
		eWAREHOUSE_NUM137,
		eWAREHOUSE_NUM138,
		eWAREHOUSE_NUM139,
		eWAREHOUSE_NUM140,
			eWAREHOUSE_NUM141,
			eWAREHOUSE_NUM142,
			eWAREHOUSE_NUM143,
			eWAREHOUSE_NUM144,
			eWAREHOUSE_NUM145,
			eWAREHOUSE_NUM146,
			eWAREHOUSE_NUM147,
			eWAREHOUSE_NUM148,
			eWAREHOUSE_NUM149,
			eWAREHOUSE_NUM150,
			eWAREHOUSE_NUM151,
			eWAREHOUSE_NUM152,
			eWAREHOUSE_NUM153,
			eWAREHOUSE_NUM154,
			eWAREHOUSE_NUM155,
			eWAREHOUSE_NUM156,
			eWAREHOUSE_NUM157,
			eWAREHOUSE_NUM158,
			eWAREHOUSE_NUM159,
			eWAREHOUSE_NUM160,
	};

	for (int i = 0; i < 160; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			CGSendWarehouseOpen(i);
			this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
		}
	}
}

void Interface::EventWarehouseWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE_CLOSE].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow || !IsWorkZone(eWAREHOUSE_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWAREHOUSE_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].EventTick = GetTickCount();
	this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
	// ----
	return;
}

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}
