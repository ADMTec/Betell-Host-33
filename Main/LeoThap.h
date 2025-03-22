#pragma once
#if(LEOTHAP == 1)
#include "Protocol.h"
#include "Interface.h"

struct PMSG_LEOTHAP_TIME
{
	PSBMSG_HEAD h;
	int TimeCount;
	int Map;
	int State;
	int eventTime;
};

struct PMSG_LEOTHAP_TIME2
{
	PSBMSG_HEAD h;
	int TimeCount;
	int Map;
	int State;
};

class LeoThap
{
public:
	LeoThap(void);
	~LeoThap(void);
	void		GCData(PMSG_LEOTHAP_TIME* lpMsg);
	void		GCData2(PMSG_LEOTHAP_TIME2* lpMsg);
	void		LeoThapCountdown();
	void		LeoThapDelayTime();
	void		ResetData();

	// Leo thap
	void		DrawLeoThap();
	bool		EventLeoThap_Main(DWORD Event);
	bool		EventLeoThap_Close(DWORD Event);
	bool		EventLeoThap_All(DWORD Event);

private:
	int			m_TimeCount;
	int			m_Map;
	int			State;
	int			eventTime;
	int			m_TimeCount2;
	int			m_Map2;
	int			State2;
};
extern LeoThap gLeoThap;

#endif