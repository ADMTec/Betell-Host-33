#pragma once
#include "defines.h"
#include "Protocol.h"

struct PMSG_WARE_INFO_RECV
{
	PSBMSG_HEAD	header;
	int CustomWarehouseAnimated;
	
};


class CWareHouseInfo
{
public:
	CWareHouseInfo();
	void Load();
	void RecvWareHouseInfo(PMSG_WARE_INFO_RECV* Data);
	int AnimatedWarehouse;


private:

}; extern CWareHouseInfo gWareHouseInfo;