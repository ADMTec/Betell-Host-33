#pragma once
// -------------------------------------------------------------------------------
#include "Protocol.h"
// -------------------------------------------------------------------------------

#define BUTTONS_COUNT 13
#define MAX_ON_PAGE 4
#define MAX_ON_PAGE2 13

enum eUserPanelButtons
{
	eUserEventTimer,
	eUserBuyVip,
	eUserJewelsBank,
	eUserSettings,
	eUserAchievements,
	eUserPartySettings,
	eUserChangeClass,
	eUserFruitBank,
	eUserRanking,
	eUserCommand,
	eUserSmithy,
	eUserLuckyWheel,
};

struct PMSG_USER_PANEL_SETTINGS_RECV
{
	PSWMSG_HEAD header;
	bool buttons_active[BUTTONS_COUNT];
	char buttons_text[BUTTONS_COUNT][32];
};

class CUserPanel
{
public:
	CUserPanel();
	~CUserPanel();
	// ----
	void DrawUserPanelV2();
	bool EventUserPanelV2(DWORD Event, MOUSEHOOKSTRUCTEX* Mouse);
	void EventUserPanelWindow(DWORD Event);
	void UserPanelSwitchStateV2();
	bool check_chaos_castleV2(int MapNumber);
	void Init();
	void CGUserPanelSettingsRecv(PMSG_USER_PANEL_SETTINGS_RECV* lpMsg);
	// ----
private:
	int StartIndex;
	bool buttons_active_[BUTTONS_COUNT];
	char buttons_text_[BUTTONS_COUNT][32];
	// ----
}; extern CUserPanel gUserPanel;
// -------------------------------------------------------------------------------
