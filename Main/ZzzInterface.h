#pragma once
#include "Protocol.h"
#include "Extras.h"
#define AT_SKILL_STUN							67
#define AT_SKILL_REMOVAL_BUFF					72
#define	AutoMouseLimitTime						3600.0f
#define TargetX									*(DWORD*)0x81C038C
#define TargetY									*(DWORD*)0x81C0388
#define Attacking								*(DWORD*)0xE61738
#define AttackPlayer							*(DWORD*)0x8793740

#define SelectedCharacter						*(int*)0xE61730
#define EnableFastInput							*(BYTE*)0x81C042C
#define g_iFollowCharacter						*(DWORD*)0xE6173C
#define byte_81C0398							*(BYTE*)0x81C0398
#define dword_81C039C							*(DWORD*)0x81C039C
#define dword_81C03A4							*(DWORD*)0x81C03A4
#define MovementSkilliTarget					*(DWORD*)0x81C03A0
#define g_dwLatestMagicTick						*(DWORD*)0x8793708
#define g_iLimitAttackTime						*(DWORD*)0xE616C4
#define g_MovementSkill_m_bMagic				*(BYTE*)0x81C0398
#define g_MovementSkill_m_iSkill				*(DWORD*)0x81C039C
#define g_MovementSkill_m_iTarget				*(DWORD*)0x81C03A0

#define DontMove								*(bool*)0x81C03AA
#define MOVEMENT_MOVE    0
#define MOVEMENT_GET     1
#define MOVEMENT_TALK    2
#define MOVEMENT_ATTACK  3
#define MOVEMENT_OPERATE 4
#define MOVEMENT_SKILL	 5




#define SendMove								((bool(__cdecl*)(int c, int o)) 0x005A3C70)

#define PathFinding2							((bool(__cdecl*)(int sx,int sy,int tx,int ty, int a, float fDistance, int iDefaultWall)) 0x00542D20)
#define CheckSkillDelay							((bool(__cdecl*)(int SkillIndex)) 0x00596500)
#define IsAutoAttack							((bool(__thiscall*)(int thisa)) 0x00849DC0)
#define SkillKeyPush							((bool(__cdecl*)(int Skill)) 0x005B4920)
#define GetScreenWidth							((int(*)()) 0x005C6E80)
#define CheckAttack								((bool(*)())0x0059A8B0)
#define CheckTile								((bool(__cdecl*)(int c, int a2, int a3, float Distance)) 0x0059A010)
#define CheckTarget								((bool(__cdecl*)(int c)) 0x005AAF20)
#define CheckWall								((bool(__cdecl*)(int sx1, int sy1, int sx2, int sy2, char a5)) 0x0059A190)
//--
#define SetAction								((void(__cdecl*)(OBJECT *o, int Action, bool bBlending)) 0x00542310) 
#define GetHandOfWeapon							((int(__cdecl*)(OBJECT* o)) 0x00556BD0)

#define TransformByObjectBone					((int(__thiscall*)(int thisa, vec3_t vResultPosition, OBJECT * pObject, int iBoneNumber, vec3_t vRelativePosition)) 0x00544E60)
#define TransformPosition						((int(__thiscall*)(int thisa, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define sub_645BA0								((signed int(__cdecl*)(BYTE *ReceiveBuffer, int Size, BOOL bEncrypted)) 0x00645BA0)

#define CreateForce								((void(__cdecl*)(OBJECT* o, vec3_t Pos)) 0x006D8760)
#define CreateParticle							((int(__cdecl*)(int index, vec3_t Posicion, vec3_t Angle, vec3_t color, int a5, float size, OBJECT * pHeroObject)) 0x0074CD30)
#define CreateJoint								((void(__cdecl*)(int Type,vec3_t Position,vec3_t TargetPosition,vec3_t Angle,int SubType, OBJECT *Target,float Scale,short PK, WORD SkillIndex,WORD SkillSerialNum, int iChaIndex, const float* vColor, short int sTargetIndex )) 0x0072D1B0)
#define CreateEffect							((int(__cdecl*) (int Type,vec3_t Position,vec3_t Angle,vec3_t Light,int SubType,OBJECT *Target,short PKKey,WORD SkillIndex,WORD Skill,WORD SkillSerialNum, float Scale, short int sTargetIndex)) 0x006D9070)
#define CreateSprite							((int(__cdecl*)(int Type, vec3_t Position, float Scale, vec3_t Light, OBJECT *Owner, float Rotation, int SubType)) 0x00771310)
#define DeleteEffect							((bool(__cdecl*) (int Type, int o, int a3)) 0x006D8980)
#define MoveEffect								((void(__cdecl*) ( OBJECT *o, int iIndex)) 0x006F1100)
#define RenderEffects							((void(__cdecl*) ( bool bRenderBlendMesh)) 0x00721DB0)
#define TestFrustrum							((bool(__cdecl*) (vec3_t Position,float Range)) 0x005DBFF0)
#define RenderObject							((void(__cdecl*) (OBJECT *o,bool Translate,int Select, int ExtraMon)) 0x005EBBB0)
#define Draw_RenderObjectR						((void(__cdecl*)(OBJECT *o, int Translate, int Select, int ExtraMon)) 0x005DE260)
#define RenderMesh								((void(__thiscall*)(int thisa, int NumMeshs, int RenderFlag, float Alpha, int BlendMesh, float BlendMeshLight, float BlendMeshTexCoordU, float BlendMeshTexCoordV, int MeshTexture)) 0x005468A0)
#define RenderBody								((int(__thiscall*)(int thisa, int RenderFlag,float Alpha,int BlendMesh,float BlendMeshLight,float BlendMeshTexCoordU,float BlendMeshTexCoordV,int HiddenMesh,int Texture)) 0x005494C0)

#define CLinkBone								((int(__thiscall*)(OBJECT * o, int a2)) 0x004CD7F0)
#define BMDthisa								((int(*)( )) 0x004CDA10)
#define GetBMDModel								((int(__thiscall*)(int thisa, int Type)) 0x00969C50)
#define ZzzCharacter_AttackStage				((bool(__cdecl*)(CHARACTER c, OBJECT * o)) 0x00556C10)
#define CRenderTerrainAlphaBitmap				((int(__cdecl*)(int Texture,float xf,float yf,float SizeX,float SizeY, vec3_t Light, float Rotation,float Alpha, float Height, bool acti)) 0x005DAD80)
//--
#define ZzzInterface_UseSkillWarrior			((void(__cdecl*)(int c, int o)) 0x0059C260)

#define FindText2								((bool(__cdecl*)(char *Text,char *Token,bool First)) 0x00512DC0)
#define Skill_absDef							((int (__cdecl*)(int a1)) 0x009D670A)
#define SkillTypeDef							((bool(__cdecl*)(int p_Type)) 0x00596760)
#define SkillWarrior							((bool(__cdecl*)(int c, int Itemp)) 0x0059B580)
#define SkillElf								((bool(__cdecl*)(int c, int Itemp)) 0x005A0A30)
#define AttackElf								((void(__cdecl*)(CHARACTER c, int Skill, float Distance)) 0x005AB0B0)
#define AttackKnight							((void(__cdecl*)(CHARACTER c, int Skill, float Distance)) 0x005AD040)
#define AttackRagefighter						((void(__cdecl*)(CHARACTER c, int Skill, float Distance)) 0x0059FCA0)
#define AttackWizard							((void(__cdecl*)(CHARACTER c, int Skill, float Distance)) 0x005B0170)
#define AttackCommon							((void(__cdecl*)(CHARACTER c, int Skill)) 0x005B3310)
#define SetPlayerAttack							((void(__cdecl*)(int c)) 0x005518F0)
#define LetHeroStop								((void(__cdecl*)(int c, BOOL bSetMovementFalse)) 0x0059B2B0)
#define CastWarriorSkill						((bool(__cdecl*)(int a4, int a5, DWORD* a6, int a7)) 0x0059B3C0)
//--
#define SendPetCommand							((bool(__cdecl*)(int c, int Index)) 0x004F8F40)
#define GetSkillDistance						((double(__cdecl*)(int Index, int c)) 0x005964B0)

#define GetSkillInformation_Charisma			((void(__cdecl*)(int iType, int *piCharisma)) 0x00596450)
#define GetSkillInformation_Energy				((void(__cdecl*)(int iType, int *piEnergy)) 0x00596370)
#define GetSkillInformation						((void(__cdecl*)( int iType, int iLevel, char *lpszName, int *piMana, int *piDistance, int *piSkillMana)) 0x005961F0)
#define IsPartyMember							((bool(__stdcall*)(int a1)) 0x0091CC90)
#define IsCursedTemple							((bool(*)()) 0x004DB1F0)
#define InBloodCastle							((bool(__cdecl*)(int MapNumber)) 0x004E65C0)
#define IsCursedTempleSkillKey					((bool(__stdcall*)(int thisa, int charSelect)) 0x0086DBB0)
#define IsCorrectSkillType_FrendlySkill			((BOOL(__cdecl*)(int a1)) 0x0058A650)
#define IsCorrectSkillType_Buff					((BOOL(__cdecl*)(int a1)) 0x0058A670)
#define CheckSkillUseCondition					((bool(__cdecl*)(int o, int Type)) 0x005B8A20)
#define DemendConditionCheckSkill				((BOOL(__cdecl*)(WORD SkillType)) 0x004AD0E0)
#define SetCursedTempleSkill					((void(__thiscall*)(int thisa, int c, int o, int Select)) 0x0086FF10)

#define Singleton								((int(*)())0x004CDA10)
#define SetPlayerStop							((void(__cdecl*)(int Character)) 0x0054EA80)
#define CreateBlood								((void(__cdecl*)(OBJECT * thisa)) 0x0072A3D0)
#define RenderCharacter							((void(__cdecl*)(int a1, int a2, int a3)) 0x0056F210)
#define pGetCharacterClass						((char(__cdecl*)(unsigned __int8 byClass)) 0x005873C0)
#define SetAnimationSpeed						((void(*)()) 0x005509C0)

#define GetModelPlaySpeed						((int(__thiscall*)(int thisa, int Action)) 0x0051A220)

#define sub_63EF10								((int(__cdecl*)(BYTE* ReceiveBuffer)) 0x0063EF10)

typedef struct {
	PBMSG_HEAD    Header;
	BYTE          MagicH;
	BYTE          MagicL;
	BYTE          SourceKeyH;
	BYTE          SourceKeyL;
	BYTE          TargetKeyH;
	BYTE          TargetKeyL;
} PRECEIVE_MAGIC, * LPPRECEIVE_MAGIC;

typedef struct {
	PBMSG_HEAD Header;
	BYTE         SubCode;
	BYTE         Value;
    BYTE         ListType;
} PHEADER_MAGIC_LIST_COUNT, * LPPHEADER_MAGIC_LIST_COUNT;

#pragma pack(push, 1)
typedef struct {
	BYTE          Index;
	WORD		  Type;
	BYTE          Level;
} PRECEIVE_MAGIC_LIST, * LPPRECEIVE_MAGIC_LIST;
#pragma pack(pop)

void SetAttackSpeed( );
void CRenderCharacter(int a1, int a2, int a3);

class ZzzInterface
{
public:
	ZzzInterface(void);
	virtual ~ZzzInterface(void);

	void Init();
};

extern ZzzInterface g_pInterface;