#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include "Defines.h"
#include "Protect.h"
#include "StatsAdvance.h"

CStatsAdvance g_StatsAdvance;

CStatsAdvance::CStatsAdvance(){
	this->m_Enable = false;
	this->m_Loaded = false;
	memset(&this->m_Data, 0, sizeof(this->m_Data));
}

CStatsAdvance::~CStatsAdvance(){}

void CStatsAdvance::Bind(){
	gInterface.BindObject(eADVANCE_STAT_INFO, 0x7899, 20, 17, -1, -1);
}

void CStatsAdvance::Load(){
	this->m_Enable = true;
}

void CStatsAdvance::DrawInfo(){
	if (!this->m_Enable && !this->m_Loaded){
		return;
	}

	if (!gInterface.CheckWindow(ObjWindow::Character)){
		return;
	}
	pSetBlend(true);
	DWORD dwColor = eWhite;
	float flDrawX = this->m_CharX + 600; /*Position Horizontal Icone*/
	float flDrawY = this->m_CharY + 50; /*Position Vertical Icone*/
	gInterface.DrawGUI(eADVANCE_STAT_INFO, flDrawX, flDrawY);
	if (!gInterface.IsWorkZone(eADVANCE_STAT_INFO)){
		return;
	}
	flDrawX = this->m_CharX + 275;
	
	float flWidth = 175;
	float flHight = 420;

	flDrawY = 2;
	gInterface.DrawBarForm(flDrawX, flDrawY, flWidth, flHight, 0, 0, 0, 2); /*Position dentro de advance stats*/
;
	flDrawY = (this->DrawLine(280, 0, 0, ""),
		this->DrawLine1(420, 0, 0, "", this->m_Data.TotalDamageReflect));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Total Damage Reflect"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.TotalDamageReflect));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Full Damage Reflect Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.FullDamageReflectRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Critical Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.CriticalDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Critical Damage (PVM)"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.CriticalDamagePVM));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Critical Damage (PVP)"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.CriticalDamagePVP));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Exellent Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ExellentDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Exellent Damage (PVM)"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.ExellentDamagePVM));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Exellent Damage (PVP)"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.ExellentDamagePVP));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Double Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.DoubleDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Triple Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.TripleDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Damage Reduction Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.DamageReductionRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Shield Skill Damage Reduction Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ShieldSkillDamageReductionRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "SD Damage Reduction Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.SDDamageReductionRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "SD Decrease Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.SDDecreaseDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Ignore Defence Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.IgnoreDefenceRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Ignore SD Rate:"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.IgnoreSDRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Increase Damage PvP"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.IncreaseDamagePvP));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Increase Defence PvP"),
		this->DrawLine2(420, flDrawY, 0, "%d", this->m_Data.IncreaseDefencePvP));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist Double Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistDoubleDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist Ignore Defence Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistIgnoreDefenceRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist Ignore SD Rate:"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistIgnoreSDRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist Critical Damage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistCriticalDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist ExellentDamage Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistExellentDamageRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Resist Stum Rate"),
		this->DrawLine1(420, flDrawY, 0, "%d%%", this->m_Data.ResistStumRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Ice Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseIce, this->m_Data.ResistIce));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Poison Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreasePoison, this->m_Data.ResistPoison));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Lighting Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseLighting, this->m_Data.ResistLighting));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Fire Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseFire, this->m_Data.ResistFire));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Earth Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseEarth, this->m_Data.ResistEarth));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Wind Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseWind, this->m_Data.ResistWind));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Water Increase/Resist Rate:"),
		this->DrawLine2(420, flDrawY, 0, "%d/%d%%", this->m_Data.IncreaseWater, this->m_Data.ResistWater));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Full HP Restore Rate (Def, Att):"),
		this->DrawLine1(420, flDrawY, 0, "%d%%/%d%%", this->m_Data.FullHPRestoreRateDef, this->m_Data.FullHPRestoreRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Full MP Restore Rate (Def, Att):"),
		this->DrawLine1(420, flDrawY, 0, "%d%%/%d%%", this->m_Data.FullMPRestoreRateDef, this->m_Data.FullMPRestoreRate));
	flDrawY = (this->DrawLine(280, flDrawY, 0, "Full SD Restore Rate (Def, Att):"),
		this->DrawLine1(420, flDrawY, 0, "%d%%/%d%%", this->m_Data.FullSDRestoreRateDef, this->m_Data.FullSDRestoreRate));

	pSetBlend(false);
}

float CStatsAdvance::DrawLine(float PosX, float PosY, int Width, LPCSTR Text, ...){
	float flResult = 0.0;
	DWORD dwColor = eWhite;
	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);
	pDrawColorText(szBuff, PosX, PosY, Width, 0, dwColor, 0, 3);
	pDrawColorButton(0x7880, PosX + 10, PosY + 10, Width - 20, 0.85, NULL, NULL, eOrange);
	flResult = PosY + 12;
	return flResult;
}

float CStatsAdvance::DrawLine1(float PosX, float PosY, int Width, LPCSTR Text, ...){
	float flResult = 0.0;
	DWORD dwColor = eYellow170;
	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);
	pDrawColorText(szBuff, PosX, PosY, Width, 0, dwColor, 0, 3);
	pDrawColorButton(0x7880, PosX + 10, PosY + 10, Width - 20, 0.85, NULL, NULL, eOrange);
	flResult = PosY + 12;
	return flResult;
}

float CStatsAdvance::DrawLine2(float PosX, float PosY, int Width, LPCSTR Text, ...){
	float flResult = 0.0;
	DWORD dwColor = eRed2;
	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);
	pDrawColorText(szBuff, PosX, PosY, Width, 0, dwColor, 0, 3);
	pDrawColorButton(0x7880, PosX + 10, PosY + 10, Width - 20, 0.85, NULL, NULL, eOrange);
	flResult = PosY + 12;
	return flResult;
}

void CStatsAdvance::Recv(PMSG_STATS_ADVANCE* lpMsg){
	if (!lpMsg->Result){
		return;
	}
	memcpy(&this->m_Data, &lpMsg->StatInfo, sizeof(this->m_Data));
	this->m_Loaded = true;
}