#include "stdafx.h"
#include "GrandResetSystem.h"
#include "User.h"
#include "Protocol.h"
#include "Interface.h"
#include "PrintPlayer.h"
#include "MemScript.h"
#include "Util.h"


GRSystem gGRSystem;

GRSystem::GRSystem()
{
	this->Init();
}

GRSystem::~GRSystem()
{
	
}

void GRSystem::Init()
{
	//ZeroMemory(this->m_GroupData, sizeof(this->m_GroupData));
	//this->m_GroupLoadedCount	= 0;
}

void GRSystem::Load()
{
	//this->Init();
	//this->ReadGroupData("Data\\Custom\\GrandResetGroup.txt");
}

void GRSystem::ReadGroupData(char* path)
{
	//CMemScript* lpMemScript = new CMemScript;

	//if(lpMemScript == 0)
	//{
	//	ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
	//	return;
	//}

	//if(lpMemScript->SetBuffer(path) == 0)
	//{
	//	ErrorMessageBox(lpMemScript->GetLastError());
	//	delete lpMemScript;
	//	return;
	//}

	//try
	//{
	//	while(true)
	//	{
	//		if(lpMemScript->GetToken() == TOKEN_END)
	//		{
	//			break;
	//		}

	//		if(strcmp("end",lpMemScript->GetString()) == 0)
	//		{
	//			break;
	//		}

	//		int GroupID = lpMemScript->GetNumber();;
	//		// ----
	//		this->m_GroupData[GroupID].MinGReset		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].MaxGReset		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqReset[0]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqReset[1]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqReset[2]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqReset[3]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqLevel			= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[0]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[1]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[2]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[3]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ItemCount	= lpMemScript->GetAsNumber();
	//		// ----
	//		int RewardPerGroup	= 0;
	//		// ----
	//		while(true)
	//		{
	//			if( RewardPerGroup >= 7 )
	//			{
	//				break;
	//			}
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].LevelPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].GensPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].WCoinC = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].WCoinP = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].GoblinPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].Credits = lpMemScript->GetAsNumber();
	//			// ----
	//			RewardPerGroup++;
	//		}
	//		// ----
	//		int ItemPerGroup = 0;
	//		// ----
	//		while(true)
	//		{
	//			if( ItemPerGroup >= this->m_GroupData[GroupID].ItemCount )
	//			{
	//				break;
	//			}
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].ID			= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MinLevel		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MaxLevel		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MinOption		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MaxOption		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsLuck		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsSkill		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsExcellent	= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsAncient		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsSocket		= lpMemScript->GetAsNumber();
	//			// ----
	//			ItemPerGroup++;
	//		}
	//		// ----
	//		this->m_GroupLoadedCount++;
	//	}
	//}
	//catch(...)
	//{
	//	ErrorMessageBox(lpMemScript->GetLastError());
	//}
	//delete lpMemScript;
}

int GRSystem::GetResetMoney()
{
	return this->GResetMoney;
}

//int GRSystem::GetResetGroup()
//{
//	for( int Group = 0; Group < this->m_GroupLoadedCount; Group++ )
//	{
//		if( ViewGReset >= this->m_GroupData[Group].MinGReset 
//			&& ViewGReset < this->m_GroupData[Group].MaxGReset )
//		{
//			return Group;
//		}
//	}
//	// ----
//	return -1;
//}

bool GRSystem::CheckAllReq()
{
	if( gObjUser.lpPlayer->MoneyInventory 
		< this->GetResetMoney() )
	{
		return false;
	}
	// ----
	if (ViewReset < this->m_GRData.ReqReset/*this->m_GroupData[this->GetResetGroup()].ReqReset[ViewAccountLevel]*/)
	{
		return false;
	}
	// ----
	if( gObjUser.lpPlayer->Level < this->m_GRData.ReqLevel/*this->m_GroupData[this->GetResetGroup()].ReqLevel*/ )
	{
		return false;
	}
	// ----
	for( int i = 0; i < this->m_GRData.ItemCount/*this->m_GroupData[this->GetResetGroup()].ItemCount*/; i++ )
	{
		if( !gObjUser.m_ResetItemCheck[i] )
		{
			return false;
		}
	}
	// ----
	return true;
}

void GRSystem::SetData(GR_ANS_USERDATA * aRecv)
{
	ZeroMemory(gObjUser.m_ResetItemCheck, sizeof(gObjUser.m_ResetItemCheck));
	// ----
	ViewReset = aRecv->Reset;
	ViewGReset = aRecv->GrandReset;

	this->GResetMoney = aRecv->GResetMoney;
	this->m_BonusCommand = aRecv->CommandPerGReset;

	gObjUser.m_QuestStat = aRecv->QuestStat;

	this->m_GRData = aRecv->GrData;

	////console.Log("", "[ResetSystem]\t\tReset=[%d] GReset=[%d]", aRecv->Reset, aRecv->GrandReset);
	// ----
	for( int i = 0; i < 5; i++ )
	{
		gObjUser.m_ResetItemCheck[i] = aRecv->ItemCheck[i];
	}
	// ----
	if( aRecv->ByDialog )
	{
		gInterface.Data[eGRESET_MAIN].Open();
	}
}

void GRSystem::ReqResetFinish()
{
	GR_REQ_USERDATA pRequest;
	pRequest.h.set(0xFF,0x0E,sizeof(pRequest));
	DataSend((BYTE*)&pRequest,pRequest.h.size);
}

void GRSystem::GetResetResult()
{
	gInterface.Data[eGRESET_MAIN].Close();
}

int GRSystem::GetRewardPoints(int add)
{
	/*int Group = this->GetResetGroup();

	if (Group == -1)
	{
		return 0;
	}

	int plus = 0;

	if (type == 0)
	{
		plus = 1;
	}

	return this->m_GroupData[Group].RewardData[gObjUser.lpPlayer->Class&7].LevelPoint * (ViewGReset + plus);*/
	return this->m_GRData.RewardData.LevelPoint * (ViewGReset + add);
}
