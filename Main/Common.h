#pragma once

#define Offset_CreateFontA1 0x004060D0
#define Offset_CreateFontA2 0x004D2882
#define Offset_CreateFontA3    0x004D28EB
#define Offset_CreateFontA4 0x004D2957
#define Offset_CreateFontA5 0x004D29C1


#define pWinWidth				*(GLsizei*)0x0E61E58
#define pWinHeight				*(GLsizei*)0x0E61E5C
#define WriteJpeg				((bool(__cdecl*)(char*,int,int,BYTE*,int)) 0x00771B00)
#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p)  { if(p) { delete [] (p);     (p)=NULL; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

void InitCommon();
char FixHelperMouseClick(int a1); //Dupe ChaosMachine
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int& EffectID, float StartX, float StartY, float StartWidth, float StartHeight);
void Copyright();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int DisableObject;
extern int DisableShadow;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int SeparateChat;
extern int TimerBar;
extern int HpPlayerBar;
extern int HpMonsterBar;
extern int HpBar;
extern int HPMonster;
extern char Main_Font_Name[100];
extern int Main_Font_Bold;
extern int Main_Font_Height;
extern int Main_Font_Italic;
extern int Main_Font_Unicode;
extern int Main_Font_Width;
extern int Main_Font_Underline;
extern int Main_Font_Quality;
extern int Main_Font_StrikeOut;
extern int SellPostColor;
extern int offhelper;
extern int OpenSwicthSkill;
extern int SkillPage;
extern int MinimizarMiniMapa;
extern int MiniMapType;
extern int EnableEffect15;
extern int EnableObjects;
extern int Transparency1;
extern int Transparency2;
extern int Transparency3;
extern int Invisibility;
extern int NewStaticEffect;
extern int NewDynamicEffect;
extern int NewActiveShades;
extern int MinimizarParty;
extern int DisablePlayer;
extern int global_int;
extern int PVPAttack;
extern int FontON;
extern int FontHeight;
extern int ChangeResolution;
extern int isHiddenPlayer;
extern int DisableWings;
extern int DisableWeapons;
extern int DisableCloack;