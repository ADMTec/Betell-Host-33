#pragma once

struct STATS_ADVANCE_DATA{
	int Level;
	int MasterLevel;
	int Reset;
	int MasterReset;
	int TotalDamageReflect;
	int FullDamageReflectRate;
	int CriticalDamageRate;
	int CriticalDamagePVM;
	int CriticalDamagePVP;
	int ExellentDamageRate;
	int ExellentDamagePVM;
	int ExellentDamagePVP;
	int DoubleDamageRate;
	int TripleDamageRate;
	int DamageReductionRate;
	int ShieldSkillDamageReductionRate;
	int SDDamageReductionRate;
	int SDDecreaseDamageRate;
	int IgnoreDefenceRate;
	int IgnoreSDRate;
	int IncreaseDamagePvP;
	int IncreaseDefencePvP;
	int ResistDoubleDamageRate;
	int ResistIgnoreDefenceRate;
	int ResistIgnoreSDRate;
	int ResistCriticalDamageRate;
	int ResistExellentDamageRate;
	int ResistStumRate;
	int IncreaseIce;
	int IncreasePoison;
	int IncreaseLighting;
	int IncreaseFire;
	int IncreaseEarth;
	int IncreaseWind;
	int IncreaseWater;
	int ResistIce;
	int ResistPoison;
	int ResistLighting;
	int ResistFire;
	int ResistEarth;
	int ResistWind;
	int ResistWater;
	int FullHPRestoreRateDef;
	int FullMPRestoreRateDef;
	int FullSDRestoreRateDef;
	int FullHPRestoreRate;
	int FullMPRestoreRate;
	int FullSDRestoreRate;
};


struct PMSG_STATS_ADVANCE
{
	PBMSG_HEAD2 h;
	BYTE Result;
	STATS_ADVANCE_DATA StatInfo;
};

class CStatsAdvance
{
public:
	CStatsAdvance();
	~CStatsAdvance();
	void Bind();
	void Load();
	void DrawInfo();
	float DrawLine(float PosX, float PosY, int Width, LPCSTR Text, ...);
	float DrawLine1(float PosX, float PosY, int Width, LPCSTR Text, ...);
	float DrawLine2(float PosX, float PosY, int Width, LPCSTR Text, ...);
	void Recv(PMSG_STATS_ADVANCE* lpMsg);

	bool m_Enable;
	bool m_Loaded;

	float m_CharX;
	float m_CharY;

	STATS_ADVANCE_DATA m_Data;
};

extern CStatsAdvance g_StatsAdvance;
