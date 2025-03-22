#pragma once
#include "NewUIMyInventory.h"
#pragma once
#define BMODEL_PEGASUS						323
#define BMODEL_UNICON						233
#define ITEM_MODEL_PANDA					7907
#define CIRCLE_STAND_RADIAN					50.f



#define IA_AlphaPet					((void(__cdecl*)(int obj)) 0x00541460)
#define sinf_						((float(__cdecl*)(float in)) 0x004DB0C0)
#define cosf_						((float(__cdecl*)(float in)) 0x004F6150)
#define new_OBJECT					((int(__thiscall*)(int Class)) 0x004CD230)
#define Angle_Matrix				((void(__cdecl*)(int angles, int matrix)) 0x00959CE0)
#define Vector_Rotate				((void(__cdecl*)(int in1, int in2, int out)) 0x0095A1E0)
//--
#define MoveHumming					((float(__cdecl*)(vec3_t Position,vec3_t Angle,vec3_t TargetPosition,float Turn)) 0x00541210)
#define MovePosition				((void(__cdecl*)(vec3_t Position,vec3_t Angle,vec3_t Speed)) 0x00541330)
#define CalcTargetPos				((BYTE(__cdecl*)( float x, float y, int Tx, int Ty )) 0x00541390)

//--
#define Render_Object				((int(__cdecl*)(int o, bool Translate,int Select, int ExtraMon)) 0x005EBBB0)
#define Play_Animation				((bool(__thiscall*)(int thisa, int AnimationFrame, int PriorAnimationFrame, int PriorAction,float Speed, int Origin, int Angle)) 0x00545180)
#define Animation					((bool(__thiscall*)(int thisa, int bonetrans, float AnimationFrame,float PriorAnimationFrame,unsigned short PriorAction,vec3_t Angle,vec3_t HeadAngle,bool Parent,bool Translate)) 0x005440B0)

typedef struct _RootingItem
{
	int itemIndex;
	vec3_t position;
}RootingItem;

class PetActionCollecter
{
public:
	PetActionCollecter(void);
	virtual ~PetActionCollecter(void);

	void Init();
	bool Move();
	void FindZen();
	void DeletPet(int Owner);
	void Render(bool bForceRender = false);
	bool Create(int itemType, int modelType, vec3_t Position, int Owner, int SubType, int LinkBone);

	bool Effect(bool bForceRender);
	bool Sound(bool bForceRender);

	bool CompTimeControl(const DWORD& dwCompTime, DWORD& dwTime);
public:
	enum ActionState
	{
		eAction_Stand = 0,
		eAction_Move = 1,
		eAction_Get = 2,
		eAction_Return = 3,

		eAction_End_NotUse,
	};
	OBJECT* m_obj;
private:
	RootingItem m_RootItem;
	bool m_isRooting;
	DWORD m_Type;
	int GetitemType;
	DWORD m_startTick;
	DWORD m_dwSendDelayTime;
	DWORD m_dwRootingTime;
	DWORD m_dwRoundCountDelay;
	ActionState m_state;

	unsigned short ActionType[eAction_End_NotUse];
	unsigned short ActionStand[2];
};

extern PetActionCollecter actionCollecter[10];