#pragma once
#include "NewInterface.h"
#if(SWITCH_SERVER==1)
struct SERVERINFO_DATA
{
	char ServerName[20];
	int SubServerNum;
	char ServerText[256];
};
class CServerInfo
{
public:
	CServerInfo();
	~CServerInfo();
	void Load();
};extern CServerInfo g_ServerInfo;
#endif
class ServerInfo
{
public:
	~ServerInfo();
	void Load();
	void SetSettingsInfo(int index);
	int GetSettingsInfo(int index);
	MU_4float MenuBackground;
	MU_4float MenuButton;
	MU_4float MenuButtonHover;
	MU_4float MenuButtonClick;
	int AnimatedWarehouse;
private:
	HANDLE hThread;
}; extern ServerInfo gServerInfo;