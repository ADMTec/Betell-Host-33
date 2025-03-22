#include "StdAfx.h"
#include "Util.h"
#include "SEASON3B.h"
#include "ZzzCharacter.h"
#include "Defines.h"
#include "ZzzInterface.h"
#include "NewUIMyInventory.h"
ZzzInterface g_pInterface;

ZzzInterface::ZzzInterface(void)
{
}


ZzzInterface::~ZzzInterface(void)
{
}

void ReceiveMagicList( BYTE *ReceiveBuffer )
{
	sub_63EF10(ReceiveBuffer);

	LPPHEADER_MAGIC_LIST_COUNT Data = (LPPHEADER_MAGIC_LIST_COUNT)ReceiveBuffer;
	int Offset = sizeof(PHEADER_MAGIC_LIST_COUNT);

	if(Data->Value == 0xFF)
	{
	}
	else if(Data->Value == 0xFE)
	{
	}
	else if ( Data->ListType==0x02 )
	{
	}
	else
	{
		for(int i=0; i<Data->Value; i++)
		{
			LPPRECEIVE_MAGIC_LIST Data2 = (LPPRECEIVE_MAGIC_LIST)(ReceiveBuffer+Offset);
			*(WORD *)(*(DWORD*)0x8128AC8 + 2 * Data2->Index + 120) = Data2->Type;
			Offset += sizeof(PRECEIVE_MAGIC_LIST);
		}
	}
}

struct PMSG_SKILL_ATTACK_SEND
{
	PBMSG_HEAD header;
	BYTE skill[2];
	BYTE index[2];
	BYTE dis;
};

void SendRequestMagic(int SkillNumber, WORD aIndex)
{
	if ( !FindText2((char *)(Hero + 56), "webzen", 0) && (SkillTypeDef(SkillNumber) || (Skill_absDef(GetTickCount() - g_dwLatestMagicTick) > 300)) )
	{
		g_dwLatestMagicTick = GetTickCount();
		
		PMSG_SKILL_ATTACK_SEND SendByte;

		SendByte.header.setE(0x19, sizeof(SendByte));
		SendByte.skill[0] = SET_NUMBERHB(SkillNumber);
		SendByte.skill[1] = SET_NUMBERLB(SkillNumber);
		SendByte.index[0] = SET_NUMBERHB(aIndex);
		SendByte.index[1] = SET_NUMBERLB(aIndex);
		SendByte.dis = 0;
		DataSend((BYTE*)&SendByte, SendByte.header.size);
	}
}

void CreateEffectS13(int Type,vec3_t Position,vec3_t Angle,vec3_t Light,int SubType,OBJECT *Owner,short PKKey, WORD SkillIndex,WORD Skill,WORD SkillSerialNum, float Scale, short int sTargetIndex)
{
	BYTE * Effects = (BYTE*)0x8967FE8;
	for(int i = 0; i < 200 ; i++)
	{
		OBJECT *o = (OBJECT*)&Effects[648 * i];

		if(!o->Live)
		{
			o->Live        = true;
			o->Type        = Type;
			o->SubType     = SubType;
			o->LightEnable = true;
			o->HiddenMesh  = -1;
			o->BlendMesh   = -1;
			o->BlendMeshLight = 1.f;
			o->BlendMeshTexCoordU = 0.f;
			o->BlendMeshTexCoordV = 0.f;
			o->AnimationFrame = 0.f;
			o->AlphaEnable    = false;
			o->Alpha          = 1.f;
			o->PriorAnimationFrame = 0.f;

			if(Scale <= 0.0f)
				o->Scale          = 0.9f;
			else
				o->Scale		  = Scale;
			
			if(Owner) 
				o->Owner		  = Owner;
			else
				o->Owner		  = NULL;

            o->Velocity       = 0.3f;
			o->PKKey          = PKKey;
			o->Kind           = Skill;
			o->Skill          = SkillIndex;
            o->RenderType     = NULL;
            o->AttackPoint[0] = 0;
			o->CurrentAction = 0;
			o->m_bySkillSerialNum = (BYTE)SkillSerialNum;
			o->m_sTargetIndex = sTargetIndex;

			//Vector(1.f,1.f,1.f,o->Light);
			VectorCopy(Light,o->Light);
			VectorCopy(Angle,o->Angle);
			VectorCopy(Position,o->Position);
    		Vector(0.f,0.f,0.f,o->Direction);
			float Matrix[3][4];
			vec3_t p1,p2;

			switch(Type)
			{
				case 3322:
				{
					o->Alpha = 0.05;
					o->LifeTime = 18;
					o->Scale = 0.8f;
					o->BlendMeshTexCoordU = 15.f;
					o->BlendMeshTexCoordV = 15.f;
					return;
				}
				break;
			}
		}
	}
}

void MoveEffectS13( OBJECT *o, int iIndex)
{
	if(o->Type != 3322)
	{
		MoveEffect(o, iIndex);
	}
	else
	{
		int Index;
		vec3_t Light, Angle;
		vec3_t p,Position;
		float Matrix[3][4];
		float Height;
		float Luminosity = (float)(rand()%4+7)*0.1f;

		if(o->LifeTime < 5)
		{
			Luminosity -= (5-o->LifeTime)*0.2f;
			if(Luminosity < 0.f) Luminosity = 0.f;
		}
		Vector(1.f,1.f,1.f,Light);

		vec3_t Temp_Pos;
		int b = GetBMDModel(BMDthisa(), o->Owner->Type);
		TransformByObjectBone(b, Temp_Pos, o->Owner, 18, NULL);
		Temp_Pos[2] -= 30.0f;
		VectorCopy(Temp_Pos, o->Position);
		/*o->LifeTime = 100;*/

		o->LifeTime--;
		if(o->LifeTime <= 0)
		{
			o->Live = false;
			o->Owner = NULL;
		}
	}
}

void RenderEffectsS13( bool bRenderBlendMesh)
{
	RenderEffects(bRenderBlendMesh);

	int iEffectSize = 200;
	BYTE * Effects = (BYTE*)0x8967FE8;

	for(int i = 0; i < iEffectSize; ++i)
	{
		OBJECT *o = (OBJECT*)&Effects[648 * i];
		if(o->Type != 3322)
		{
			continue;
		}

		if(o->Live)
		{
			o->Visible = TestFrustrum(o->Position,400.f);

			if(o->Visible)
			{
				if ( bRenderBlendMesh )
				{
					if ( o->BlendMesh==-1 || o->BlendMesh<-2 ) continue;
					const int b = GetBMDModel(BMDthisa(), o->Type);
					if ( (signed int)*(WORD *)(b + 36) < o->BlendMesh ) continue;
				}
			}
			RenderObject(o, 0, 0, 0);
			return;
		}
	}
}

void Draw_RenderObject(OBJECT *o, int Translate, int Select, int ExtraMon)
{
	Draw_RenderObjectR(o, Translate, Select, ExtraMon);

	if ( o->Type == 3322 )
	{
		int b = GetBMDModel(BMDthisa(), o->Type);
		//RenderMesh(b, 0,RENDER_TEXTURE|RENDER_BRIGHT, 1.f, o->BlendMesh, o->BlendMeshLight, o->BlendMeshTexCoordU, WorldTime*0.0006f, 32222);
		RenderBody(b, 66, o->Alpha, 0, o->BlendMeshLight, o->BlendMeshTexCoordU, o->BlendMeshTexCoordV + WorldTime*0.0006f, -1, -1);
		//RenderMesh(b, 0,70, o->Alpha, o->BlendMesh, o->BlendMeshLight, o->BlendMeshTexCoordU, WorldTime*0.0006f, -1);
	}
}

void CreateCircleInfernal(OBJECT * o)
{
	vec3_t p,p2,Angle,Light;
	float Matrix[3][4];
	Vector(1.f,1.f,1.f,Light);
	for(int j = 0 ; j < 8 ;j++)
	{
		Vector(0.f,-150.f,0.f,p);
		Vector(0.f,0.f,j*45.f,Angle);
		AngleMatrix_S6(Angle,Matrix);
		VectorRotate_S6(p,Matrix,p2);
		VectorAdd(o->Position, p2, p2);
		CreateParticle(32371, p2, Angle, Light, 5, 1.0f, NULL);
	}
}

__declspec(naked) void CheckJumpAttack()
{
	static DWORD Addr_main;
	static DWORD SkillAttributeUsed; // [sp+2130h] [bp-10h]@12

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		MOV SkillAttributeUsed, ECX
	}

	if (SkillAttributeUsed != 47
		&& SkillAttributeUsed != 43
		&& SkillAttributeUsed != 49
		&& SkillAttributeUsed != 60
		&& SkillAttributeUsed != 509
		&& SkillAttributeUsed != 61
		&& SkillAttributeUsed != 74
		&& SkillAttributeUsed != 336
		&& SkillAttributeUsed != 339
		&& SkillAttributeUsed != 342
		&& SkillAttributeUsed != 514
		&& SkillAttributeUsed != 508
		//-- GL agregado
		&& SkillAttributeUsed != 340
		&& SkillAttributeUsed != 343
		&& SkillAttributeUsed != 271 //-- Spin Step 
		&& SkillAttributeUsed != 687 //-- Spin Step Improved
		&& SkillAttributeUsed != 690 //-- Spin Step Enhanced
		&& SkillAttributeUsed != 274 //-- Magic Pin 
		&& SkillAttributeUsed != 692 //-- Magic Pin Improved
		&& SkillAttributeUsed != 694 //-- Magic Pin Enhanced
		&& SkillAttributeUsed != 695 //-- Magic Pin Mastered
		&& SkillAttributeUsed != 276 //-- Harsh Strike 
		&& SkillAttributeUsed != 688 //-- Harsh Strike Improved
		&& SkillAttributeUsed != 691 //-- Harsh Strike Enhanced
		&& SkillAttributeUsed != 277 //-- Shining Peak 
		&& SkillAttributeUsed != 699 //-- Shining Peak Improved
		&& SkillAttributeUsed != 279 //-- Breche 
		&& SkillAttributeUsed != 696 //-- Breche Improved
		&& SkillAttributeUsed != 697 //-- Breche Enhanced
		&& SkillAttributeUsed != 698 //-- Breche Mastered
		)
	{
		Addr_main = 0x0059CAA0;
	}
	else
	{
		Addr_main = 0x0059CB07;
	}
	_asm
	{
		JMP[Addr_main]
	}
}


bool isBuffGrowLancer(int nSkill)
{
	bool bSuccess = false;
	switch(nSkill)
	{
		case 272: //-- Circle Shield 
		case 703: //-- Circle Shield Improved
		case 706: //-- Circle Shield Enhanced
		//--
		case 273: //-- Obsidian 
		case 693: //-- Obsidian Improved
		//--
		case 278: //-- Wrath 
		case 708: //-- Wrath Improved
		case 709: //-- Wrath Enhanced
		case 710: //-- Wrath Mastered
		//--
		case 700: //-- Add Burst
		case 701: //-- Add Burst Improved
			bSuccess =  true;
			break;
		default:
			bSuccess =  false;
			break;
	}
	return bSuccess;
}

bool isSkillGrowLancer(int nSkill)
{
	bool bSuccess = false;
	switch(nSkill)
	{
		//--
		case 271: //-- Spin Step
		case 687: //-- Spin Step Improved
		case 690: //-- Spin Step Enhanced
		//--
		case 274: //-- Magic Pin 
		case 692: //-- Magic Pin Improved
		case 694: //-- Magic Pin Enhanced
		case 695: //-- Magic Pin Mastered
		//--
		case 276: //-- Harsh Strike 
		case 688: //-- Harsh Strike Improved
		case 691: //-- Harsh Strike Enhanced
		//--
		case 277: //-- Shining Peak 
		case 699: //-- Shining Peak Improved
		//--
		case 279: //-- Breche 
		case 696: //-- Breche Improved
		case 697: //-- Breche Enhanced
		case 698: //-- Breche Mastered
		//--
		case 275: //-- Clash
			bSuccess =  true;
			break;
		default:
			bSuccess =  false;
			break;
	}
	return bSuccess;
}

__declspec(naked) void SetEffectLith()
{
	static DWORD addr_jmp;
	static DWORD animate;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVZX EAX,WORD PTR DS:[EDX+0x12]
		MOV animate,EAX
	}

	if (animate == 255 || animate == 256 || animate == 295 || animate == 296|| animate == 299 )
	{
		addr_jmp = 0x0050F58D;
	}
	else
	{
		addr_jmp = 0x0050F690;
	}
	_asm
	{
		JMP[addr_jmp]
	}
}

__declspec(naked) void CheckSkillAttack()
{
	static DWORD Addr_main;
	static DWORD SkillAttributeUsed; // [sp+2130h] [bp-10h]@12

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		MOV SkillAttributeUsed, ECX
	}

	if ( SkillAttributeUsed != 60
		&& SkillAttributeUsed != 61
		&& SkillAttributeUsed != 509
		&& SkillAttributeUsed != 74
		&& SkillAttributeUsed != 78
		&& SkillAttributeUsed != 518
		&& SkillAttributeUsed != 260
		&& SkillAttributeUsed != 261
		&& SkillAttributeUsed != 551
		&& SkillAttributeUsed != 552
		&& SkillAttributeUsed != 554
		&& SkillAttributeUsed != 555
		&& SkillAttributeUsed != 514
		&& SkillAttributeUsed != 518
		//-- GL agregado
		&& SkillAttributeUsed != 275 //-- Spin Step 

		&& SkillAttributeUsed != 271 //-- Spin Step 
		&& SkillAttributeUsed != 687 //-- Spin Step Improved
		&& SkillAttributeUsed != 690 //-- Spin Step Enhanced
		&& SkillAttributeUsed != 274 //-- Magic Pin 
		&& SkillAttributeUsed != 692 //-- Magic Pin Improved
		&& SkillAttributeUsed != 694 //-- Magic Pin Enhanced
		&& SkillAttributeUsed != 695 //-- Magic Pin Mastered
		&& SkillAttributeUsed != 276 //-- Harsh Strike 
		&& SkillAttributeUsed != 688 //-- Harsh Strike Improved
		&& SkillAttributeUsed != 691 //-- Harsh Strike Enhanced
		&& SkillAttributeUsed != 277 //-- Shining Peak 
		&& SkillAttributeUsed != 699 //-- Shining Peak Improved
		&& SkillAttributeUsed != 279 //-- Breche 
		&& SkillAttributeUsed != 696 //-- Breche Improved
		&& SkillAttributeUsed != 697 //-- Breche Enhanced
		&& SkillAttributeUsed != 698 //-- Breche Mastered
		)
	{
		Addr_main = 0x0059C5AF;
	}
	else
	{
		Addr_main = 0x0059C601;
	}
	_asm
	{
		JMP[Addr_main]
	}
}

__declspec(naked) void ShiningPeakBodyEffect()
{
	static DWORD var_addr = 0x006EF31E;
	static DWORD TypeE = 0;
	static int Obje = 0;

	_asm
	{
		mov     edx, dword ptr ss:[ebp-0x8]
		mov     Obje, edx
	}

	*(float *)(Obje + 96) = 1.0;
	*(float *)(Obje + 120) = 0.4f;
	if(*(DWORD *)(Obje + 48) == 512 )
	{
		*(DWORD *)(Obje + 64) = 12;
	}
	else if(*(DWORD *)(Obje + 48) == 513 )
	{
		*(DWORD *)(Obje + 64) = 10;
	}
	*(WORD *)(Obje + 18) = 6;

	_asm
	{
		JMP     [var_addr]
	}
}

__declspec(naked) void Burst_06Effect()
{
	static DWORD var_addr = 0x006EF31E;
	static DWORD TypeE = 0;
	static int Obje = 0;

	_asm
	{
		mov     edx, dword ptr ss:[ebp-0x8]
		mov     Obje, edx
	}

	*(float *)(Obje + 96) = 1.0;
	*(float *)(Obje + 120) = 0.4f;
	/*if(*(DWORD *)(Obje + 48) == 512 )
	{*/
		*(DWORD *)(Obje + 64) = 26;
	/*}
	else if(*(DWORD *)(Obje + 48) == 513 )
	{
		*(DWORD *)(Obje + 64) = 10;
	}*/
	*(WORD *)(Obje + 18) = 6;

	_asm
	{
		JMP     [var_addr]
	}
}

void PlayerStopAnimationSetting(CHARACTER c, OBJECT * o)
{
	int Animation;

	Animation = *(WORD *)((int)o + 18);

	if ( Animation == 231 || Animation == 232 )
	{
		if ( !*(BYTE *)((int)c + 4) )
		{
			*(BYTE *)((int)c + 4) = true;
			CreateBlood(o);
		}
		return;
	}

	if ( (Animation >= 289 && Animation <= 300) || (Animation < 15
		|| Animation >= 223 && Animation <= 225
		|| Animation >= 88 && Animation <= 89
		|| Animation >= 247
		&& Animation <= 282
		&& (Animation < 270 || Animation > 273)
		&& (Animation < 259 || Animation > 261)
		|| Animation == 283
		|| Animation >= 38
		&& Animation <= 230
		&& Animation != 143
		&& Animation != 144
		&& Animation != 74
		&& Animation != 75
		&& Animation != 72
		&& Animation != 77
		&& Animation != 79
		&& (Animation < 110 || Animation > 121)
		&& Animation != 246) )
	{
		SetPlayerStop((int)c);
	}
	if (Animation == 72 )
	{
		o->AnimationFrame = 0.0;
	}
}

void SpeedModelAction(int action, float Speed)
{
	*(float *)(GetModelPlaySpeed(Singleton(), action) + 4) = Speed;
}

void SetAttackSpeed( )
{
	SetAnimationSpeed();

	float AttackSpeed1;
	float MagicSpeed1;
	float MagicSpeed2;

	AttackSpeed1 = (double)*(WORD *)(CharacterAttribute + 84) * 0.002f;
	MagicSpeed1 = (double)*(WORD *)(CharacterAttribute + 96) * 0.004f;
	MagicSpeed2 = (double)*(WORD *)(CharacterAttribute + 96) * 0.002f;

	SpeedModelAction(290, AttackSpeed1 + 0.35f );
	SpeedModelAction(291, AttackSpeed1 + 0.12f );
	SpeedModelAction(292, AttackSpeed1 + 0.16f );
	SpeedModelAction(293, AttackSpeed1 + 0.5f );
	SpeedModelAction(294, AttackSpeed1 + 0.16f );
	SpeedModelAction(295, 0.35f );
	SpeedModelAction(296, 0.35f );
	SpeedModelAction(297, MagicSpeed2 + 0.35f );
	SpeedModelAction(298, MagicSpeed2 + 0.35f );
	SpeedModelAction(299, MagicSpeed2 + 0.35f );
}

bool pCheckSkillDelay ( int a4 )
{
	int v5; // [sp+0h] [bp-Ch]@12
	int v6; // [sp+4h] [bp-8h]@1
	int v7; // [sp+8h] [bp-4h]@1

	v7 = *(WORD *)(*(DWORD*)0x8128AC8 + 2 * a4 + 120);
	v6 = *(DWORD *)(*(DWORD*)0x8128ABC + 88 * v7 + 44);

	if ( v6 > 0 )
	{
		if ( *(DWORD *)(*(DWORD*)0x8128AC8 + 4 * a4 + 2072) > 0 )
			return 0;
		GetSkillInformation_Charisma(v7, &v5);
		if ( v5 > *(WORD *)(*(DWORD*)0x8128AC8 + 62) + *(WORD *)(*(DWORD*)0x8128AC8 + 32) )
			return 0;
	}

	return true;
}

void SetSkillDelay ( int SkillIndex )
{
	int Skill = *(WORD *)(CharacterAttribute + 2 * SkillIndex + 120);
	int Delay = *(DWORD *)(*(DWORD*)0x008128ABC + 88 * Skill + 44);

	if ( Delay>0 )
	{
		if ( *(DWORD *)(CharacterAttribute + 4 * SkillIndex + 2072) > 0 )
			return;
		*(DWORD *)(CharacterAttribute + 4 * SkillIndex + 2072) = Delay;
	}
}

void UseSkillGrowLancer(CHARACTER pCha, OBJECT *pObj)
{
	int iSkill = g_MovementSkill_m_bMagic ? *(WORD *)(CharacterAttribute + 2 * g_MovementSkill_m_iSkill + 120) : g_MovementSkill_m_iSkill;

	LetHeroStop(NULL, 0);
	*(BYTE *)((int)pCha + 120) = false;

	if(pObj->Type == 1163)
	{
		//g_CMonkSystem.SetRageSkillAni(iSkill, pObj);
		SetAttackSpeed();
	}
	CheckSkillDelay(*(BYTE *)(Hero + 50));
	SendRequestMagic(iSkill, *(WORD*)((int)pCha + 126));

	/*if(rand()%2==0)
	{
		SetAction(pObj, 256, 1);
		PlayBuffer(951, 0, 0);
	}
	else
	{
		SetAction(pObj, 255, 1);
		PlayBuffer(950, 0, 0);
	}*/
	//sub_511360((int)&unk_EBCD98, a1, (int)a2, a3, a5, v171);
}


void AttackGrowLancer(CHARACTER pCha, int nSkill, float fDistance)
{
	OBJECT *pObj = &pCha->Object;

	int iMana, iSkillMana;
	GetSkillInformation(nSkill, 1, NULL, &iMana, NULL, &iSkillMana);
	
	if(*(WORD *)(CharacterAttribute + 64) < iMana)
	{
		/*int Index = g_pMyInventory.FindManaItemIndex();
		if(Index != -1)
			SendRequestUse(Index, 0);*/
		return;
	}

	if(iSkillMana > *(WORD *)(CharacterAttribute + 64) || !pCheckSkillDelay(*(BYTE *)(Hero + 50)))
	{
		return;
	}

	bool bSuccess = CheckTarget((int)pCha);
	bool bCheckAttack = CheckAttack();
	g_MovementSkill_m_bMagic = TRUE;
	g_MovementSkill_m_iSkill = *(BYTE *)(Hero + 50);

	if(bCheckAttack)
	{
		g_MovementSkill_m_iTarget = SelectedCharacter;
		int var_19 = CharactersClient(CList(), SelectedCharacter);
		dword_81C03A4 = ( var_19 ) ? *(WORD *)(var_19 + 126) : 0;
	}
	else
	{
		g_MovementSkill_m_iTarget = -1;
		dword_81C03A4 = 0;
	}
	if ( !bSuccess )
		return;
	switch(nSkill)
	{
		case 272: //-- Circle Shield 
		case 703: //-- Circle Shield Improved
		case 706: //-- Circle Shield Enhanced
		//--
		case 273: //-- Obsidian 
		case 693: //-- Obsidian Improved
		//--
		case 278: //-- Wrath 
		case 708: //-- Wrath Improved
		case 709: //-- Wrath Enhanced
		case 710: //-- Wrath Mastered
		//--
		case 700: //-- Add Burst
		case 701: //-- Add Burst Improved
			UseSkillGrowLancer(pCha, pObj);
			break;
		//--
		case 271: //-- Spin Step
		case 687: //-- Spin Step Improved
		case 690: //-- Spin Step Enhanced
		//--
		case 274: //-- Magic Pin 
		case 692: //-- Magic Pin Improved
		case 694: //-- Magic Pin Enhanced
		case 695: //-- Magic Pin Mastered
		//--
		case 276: //-- Harsh Strike 
		case 688: //-- Harsh Strike Improved
		case 691: //-- Harsh Strike Enhanced
		//--
		case 277: //-- Shining Peak 
		case 699: //-- Shining Peak Improved
		//--
		case 279: //-- Breche 
		case 696: //-- Breche Improved
		case 697: //-- Breche Enhanced
		case 698: //-- Breche Mastered
		//--
		case 275: //-- Clash
			CastWarriorSkill((int)pCha, (int)pObj, (DWORD*)(*(int*)0x8128AC4 + 4672), nSkill);
			break;
	}
}

void Attack(CHARACTER c)
{
	if((MouseOnWindow || !pCheckInMouse(0, 0, GetScreenWidth(), 429)) && MouseLButtonPush) 
	{
		MouseRButtonPop = false;
		MouseRButtonPush= false;
		MouseRButton	= false;
		MouseRButtonPress = 0;
		return;
	}

	if( g_isCharacterBuff((DWORD *)((int)c + 1260), 61)
		|| g_isCharacterBuff((DWORD *)((int)c + 1260), 72)
		|| g_isCharacterBuff((DWORD *)(Hero + 1260), 98)
		) 
	{
		return;
	}

	OBJECT *o = &c->Object;
	int ClassIndex = GetBaseClass (c->Class);

	if(o->Teleport == 1)
	{
		o->Alpha -= 0.1f;
		if(o->Alpha < 0.1f)
		{
			o->Teleport = 2;
		}
	}

	bool Success = false;
	bool CursedTempleSkillSuccess = false;
	int Skill = *(WORD *)(CharacterAttribute + 2 * *(BYTE *)(Hero + 50) + 120); 

	float Distance = (float)GetSkillDistance(Skill, (int)c);

	if(EnableFastInput)
	{
		if(MouseLButtonPush || MouseLButton)
		{
			MouseLButtonPush = 0;
			Success = true;
		}
	}
	else
	{
		if ( MouseRButtonPress!=0 )
		{
			if ( MouseRButtonPop || SkillKeyPush(Skill) || MouseRButtonPress > 0x1F4)
			{
				MouseRButtonPop = false;
				MouseRButtonPush= false;
				MouseRButton	= false;
				MouseRButtonPress = 0;
				Success = true;
			}
			else
			{
				int ButtonPress = MouseRButtonPress;
				ButtonPress++;
				MouseRButtonPress = ButtonPress;
			}
		}
		else if ( (MouseRButtonPush || MouseRButton) && !MouseLButtonPush && !MouseLButton && !*(BYTE *)((int)c + 120) )
		{
			if ( Skill == 40 )
			{
				if ( *(BYTE *)((int)o + 23) != 3 && *(BYTE *)((int)o + 23) )
				{
					return;
				}
				int iReqEng = 0;
				GetSkillInformation_Energy(Skill, &iReqEng);

				if ( *(WORD *)(CharacterAttribute + 56) + *(WORD *)(CharacterAttribute + 30) < iReqEng )
				{
					return;
				}
				MouseRButtonPress = 1;
				*(BYTE *)(Hero + 809) = 0;
				Skill = 58;
			}
			BackupPickedItem();
			MouseRButtonPush = false;
			Success = true;
		}
		if(IsAutoAttack(*(DWORD *)(GetInstance( ) + 160))
			&& World != 6 
			&& InChaosCastle(World) == false
			&& Attacking == 2 
			&& SelectedCharacter != -1 )
		{
			Success = true;
		}
		if ( Success )
		{
			RButtonPressTime = (WorldTime - RButtonPopTime) / CLOCKS_PER_SEC;
			if ( RButtonPressTime >= AutoMouseLimitTime )
			{
				MouseRButtonPush = false;
				MouseRButton = false;
				Success = false;
			}
		}
		else
		{
			RButtonPopTime = WorldTime;
			RButtonPressTime = 0.0;
		}
	}

	if ( Success )
	{
		g_iFollowCharacter = -1;
		if ( !g_isCharacterBuff((DWORD *)(Hero + 1260), 18) && SendPetCommand((int)c, *(BYTE *)(Hero + 50)) == true )
		{
			return;
		}
		if ( IsCursedTemple() )
		{
			if ( IsCursedTempleSkillKey(*(DWORD *)(GetInstance() + 208), SelectedCharacter) )
			{
				CursedTempleSkillSuccess = true;
			}
			else
			{
				if ( IsPartyMember(SelectedCharacter) == 1 )
				{
					if ( !IsCorrectSkillType_FrendlySkill(Skill) && !IsCorrectSkillType_Buff(Skill) ) {return;}
				}
				else if ( (IsCorrectSkillType_FrendlySkill(Skill) || IsCorrectSkillType_Buff(Skill)) && SelectedCharacter != -1 )
				{
					return;
				}
				if ( !CheckSkillUseCondition((int)o, Skill) ) {return;}
			}
		}
		else if ( !CheckSkillUseCondition((int)o, Skill) )
		{
			return;
		}

		if ( Skill >= 223 && Skill <= 225 )
		{
			CheckTarget((int)c);
			if ( !CheckTile((int)c, TargetX, TargetY, Distance) ) {return;}
		}

		if ( (!Success || DemendConditionCheckSkill(Skill)) && Success && !*(BYTE *)((int)c + 36) )
		{
			if ( !c->SafeZone && CursedTempleSkillSuccess )
			{
				SetCursedTempleSkill(*(DWORD *)(GetInstance() + 208), (int)c, (int)o, SelectedCharacter);
				return;
			}
			if ( (!c->SafeZone || InBloodCastle(World) == 1 || InChaosCastle(World) == 1)
			&& (!c->SafeZone
				|| Skill == 26 || Skill == 27 || Skill == 28
				|| Skill == 16 || Skill == 48 || Skill == 77
				|| Skill == 233 || Skill == 234 || Skill == 218
				|| Skill == 469 || Skill == 470 || Skill == 472
				|| Skill == 417 || Skill == 420 || Skill == 403
				|| Skill == 413 || Skill == 356 || Skill == 360
				|| Skill == 380 || Skill == 383 || Skill == 404
				|| Skill == 422 || Skill == 423 || Skill == 441 
				|| Skill == 53 || Skill == 64 || Skill == 511
				|| Skill == 515 || Skill == 517 || Skill == 63
				|| Skill >= 67 && Skill <= 72
				|| Skill == 75
				|| Skill >= 266 && Skill <= 268
				|| Skill == 569 || Skill == 572 || Skill == 575
				|| isBuffGrowLancer(Skill)) )
			{
				if ( IsAutoAttack(*(DWORD *)(GetInstance( ) + 160)) && World != 6  && InChaosCastle(World)==false )
				{
					if ( ClassIndex != CLASS_ELF1
					|| Skill == 24
					|| Skill == 235
					|| Skill == 414
					|| Skill == 25
					|| Skill == 52
					|| Skill == 54
					|| Skill == 76
					|| Skill == 416
					|| Skill == 418 )
					{
						if ( (ClassIndex != CLASS_KNIGHT1 || Skill != 48 && Skill != 356 && Skill != 360) ||
							(ClassIndex != CLASS_GROWLANCER 
							|| isSkillGrowLancer(Skill)))
						{
							if ( ClassIndex != CLASS_DARK_LORD || Skill != 64 && Skill != 63 && Skill != 511 && Skill != 515 && Skill != 517 )
							{
								if ( ClassIndex || Skill != 58 && Skill != 40 )
								{
									if ( Skill < 67 || Skill > 72 )
									{
										if ( Skill == 75 )
										{
											Attacking = -1;
										}
										else if ( Skill != 217 && Skill != 454
												&& Skill != 218 && Skill != 219
												&& Skill != 469 && Skill != 470
												&& Skill != 472 && Skill != 220
												&& Skill != 221 && Skill != 222 )
										{
											if ( (Skill < 266 || Skill > 268) && Skill != 569 && Skill != 572 && Skill != 575 )
												Attacking = 2;
											else
												Attacking = -1;
										}
										else
										{
											Attacking = -1;
										}
									}
									else
									{
										Attacking = -1;
									}
								}
								else
								{
									Attacking = -1;
								}
							}
							else
							{
								Attacking = -1;
							}
						}
						else
						{
							Attacking = -1;
						}
					}
					else
					{
						Attacking = -1;
					}
				}
				if(o->Type == 1163)
				{
					if (o->CurrentAction < 1
					|| o->CurrentAction > 14
					&& o->CurrentAction != 142
					&& o->CurrentAction != 72
					&& o->CurrentAction != 76
					&& o->CurrentAction != 78
					&& o->CurrentAction != 122
					&& o->CurrentAction != 123
					&& o->CurrentAction != 124
					&& o->CurrentAction != 125
					&& (o->CurrentAction < 274 || (o->CurrentAction > 277 
					&& o->CurrentAction != 284 && o->CurrentAction != 285
					&& o->CurrentAction != 286 && o->CurrentAction != 287
					&& o->CurrentAction != 288))
					&& o->CurrentAction != 261
					&& o->CurrentAction != 283 )
					{
						MouseRButtonPress = 0;
						return;
					}
				}
				else
				{
					if(o->CurrentAction < 0 || o->CurrentAction > 1) 
					{
						return;
					}
				}
				if ( ClassIndex != CLASS_WIZARD1 && Skill != 270 )
				{
					CheckTarget((int)c);
					if ( CheckWall(c->PositionX, c->PositionY, TargetX, TargetY, 0) )
					{
						for (int i = 0; i <= 1; ++i )
						{
							if ( ClassIndex == CLASS_KNIGHT1 || ClassIndex == CLASS_DARK || ClassIndex == CLASS_DARK_LORD 
								|| ClassIndex == CLASS_RAGEFIGHTER)
							{
								bool bOk = true;
								if ( *(WORD *)((int)c + 556) == 7829
									|| *(WORD *)((int)c + 556) == 7830
									|| *(WORD *)((int)c + 556) == 7831
									|| *(WORD *)((int)c + 556) == 7864 )
								{
									if ( Skill > 238 )
									{
										switch ( Skill )
										{
											case 336:
											case 339:
											case 342:
											case 508:
											case 509:
											case 510:
											case 512:
											case 514:
											case 516:
											case 518:
											case 519:
											case 523:
											//--
											case 43:
											case 47:
											case 49:
											case 60:
											case 61:
											case 62:
											case 65:
											case 74:
											case 76:
											case 78:
												goto LABEL_203;
											default:
											break;
										}
									}
									else if ( Skill == 238 )
									{
LABEL_203:
										bOk = 1;
									}
								}
								else
								{
									bOk = 1;
								}
								if ( bOk )
								{
									byte_81C0398 = TRUE;
									dword_81C039C = *(BYTE *)(Hero + 50);
									if ( CheckAttack() )
									{
										MovementSkilliTarget = SelectedCharacter;
										int v19 = CharactersClient(CList( ), SelectedCharacter);
										dword_81C03A4 = ( v19 ) ? *(WORD *)((int)v19 + 126) : 0;
									}
									else
									{
										MovementSkilliTarget = -1;
										dword_81C03A4 = 0;
									}
									if ( SkillWarrior((int)c, *(DWORD*)0x8128AC4 + 107 * i + 4672) )
									{
										return;
									}
								}
							}
							if(ClassIndex==CLASS_ELF1 && SkillElf((int)c,*(DWORD*)0x8128AC4 + 107 * i + 4672))
							{
								return;
							}
						}
					}
					else
					{
						ZeroMemory(&byte_81C0398, 16);
						MovementSkilliTarget = -1;
						dword_81C03A4 = 0;
					}
				}

				if ( ClassIndex == CLASS_ELF1 )
					AttackElf(c, Skill, Distance);
				if( ClassIndex == CLASS_GROWLANCER )
					AttackGrowLancer(c, Skill, Distance);
				if ( ClassIndex == CLASS_KNIGHT1 || ClassIndex == CLASS_DARK || ClassIndex == CLASS_DARK_LORD)
					AttackKnight(c, Skill, Distance);
				if ( ClassIndex == CLASS_RAGEFIGHTER )
					AttackRagefighter(c, Skill, Distance);
				if ( !ClassIndex || ClassIndex == CLASS_DARK || ClassIndex == CLASS_SUMMONER1 )
					AttackWizard(c, Skill, Distance);
				if ( Skill >= AT_SKILL_STUN && Skill <= AT_SKILL_REMOVAL_BUFF )
					AttackCommon(c, Skill);
			}
		}
	}
}

bool AttackStage(CHARACTER c, OBJECT* o)
{
	int Hand = GetHandOfWeapon(o);
	CHARACTER tc;
	BYTE AttackTime;
	vec3_t TempPos;

	 g_iLimitAttackTime = 15;

	tc =(CHARACTER)CharactersClient(CList( ),*(WORD *)((int)c + 128));
	AttackTime = *(BYTE *)((int)c + 34);

	switch(*(WORD *)((int)c + 38))
	{
	case 339:
	case 342:
		{
			PlayBuffer(113, 0, 0);
			SetAction(o, 71, 1);
			int b = GetBMDModel(BMDthisa(), o->Type);
			if ( AttackTime >= 1  && AttackTime <= 8)
			{
				for ( int j = 0; j < 3; ++j)
				{
					vec3_t CurPos;
					VectorCopy( o->Position, CurPos);
					CurPos[2] += 120.0f;
					vec3_t TempPos;
					GetNearRandomPos( CurPos, 300, TempPos);
					float fDistance = 1400.0f;
					TempPos[0] += -fDistance * sinf( o->Angle[2]*Q_PI/180.0f);
					TempPos[1] += fDistance * cosf( o->Angle[2]*Q_PI/180.0f);
					CreateJoint( 322, TempPos, TempPos, o->Angle, 2, o, 40.0f, -1, 0, 0, -1, NULL, -1);
				}
			}
			if ( AttackTime <= 8)
			{
				vec3_t Position2 = { 0.0f, 0.0f, 0.0f};
				int LinkBoneP = CLinkBone(o, *(BYTE *)((int)c + 36 * Hand + 453));
				if ( !LinkBoneP )
					goto LABEL_19;
				TransformPosition(b, LinkBoneP, Position2, o->m_vPosSword,true);

				float fDistance = 300.0f;
				o->m_vPosSword[0] += fDistance * sinf( o->Angle[2]*Q_PI/180.0f);
				o->m_vPosSword[1] += -fDistance * cosf( o->Angle[2]*Q_PI/180.0f);
			}

			if ( AttackTime >= 1 && AttackTime <= 12)
			{
				vec3_t Position;
				vec3_t Position2 = { 0.0f, 0.0f, 0.0f};

				int LinkBoneP = CLinkBone(o, *(BYTE *)((int)c + 36 * Hand + 453));
				if ( !LinkBoneP )
					goto LABEL_19;
				TransformPosition(b, LinkBoneP, Position2, Position, true);

				float fDistance = 100.0f + ( float)( c->AttackTime - 8) * 10.0f;
				Position[0] += fDistance * sinf( o->Angle[2]*Q_PI/180.0f);
				Position[1] += -fDistance * cosf( o->Angle[2]*Q_PI/180.0f);
				vec3_t Light = { 1.0f, 1.0f, 1.0f};
				CreateEffect( 2696, Position, o->Angle, Light, 1, o, -1, 0, 0, 0, 0.0f, -1);
				CreateEffect( 2696, Position, o->Angle, Light, 1, o, -1, 0, 0, 0, 0.0f, -1);

				if ( tc )
				{
					OBJECT *to = &tc->Object;
					if ( AttackTime >= 10 )
					{
						if(to->Live)
							to->m_byHurtByOneToOne = 35;
					}
				}
				if ( AttackTime >= 12 )
					*(BYTE *)((int)c + 34) = g_iLimitAttackTime;
			}
			return true;
		}
	case 271: //-- Spin Step
	case 687: //-- Spin Step Improved
	case 690: //-- Spin Step Enhanced
		{
			SetAction(o, 291, 1);
			PlayBuffer(114, 0, 0);
			if ( tc )
			{
				OBJECT *to = &tc->Object;
				if ( AttackTime > 1 && AttackTime < 6)
				{
					CreateJoint(32229, to->Position, to->Position, to->Angle, 50, NULL, 40.0, 0, 0, 0, -1, 0, -1);
				}
				if ( AttackTime > 3 )
				{
					vec3_t Light = { 1.0f, 0.60000002f, 0.60000002f};
					CreateEffect(32066, to->Position, to->Angle, Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
				}
				if ( *(BYTE *)((int)c + 34) >= 10 )
				{
					if(to->Live)
						to->m_byHurtByOneToOne = 35;
				}
			}
			if ( AttackTime >= 12 )
				*(BYTE *)((int)c + 34) = g_iLimitAttackTime;
			return true;
		}
	case 275:
		{
			SetAction(o, 298, 1);
			PlayBuffer(114, 0, 0);
			*(BYTE *)((int)c + 34) = g_iLimitAttackTime;
			return true;
		}
	case 277: //-- Shining Peak 
	case 699: //-- Shining Peak Improved
		{
			SetAction(o, 297, 1);
			int b = GetBMDModel(BMDthisa(), o->Type);
			if(AttackTime > 11 )
			{
				CreateEffect(328, o->Position, o->Angle, o->Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
			}
			if ( AttackTime == 10 )
			{
				VectorCopy( o->Position, TempPos);
				TempPos[2] += 120.0f;
				CreateEffect(512, TempPos, o->Angle, o->Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
			}
			if ( AttackTime >= 13 )
				c->AttackTime = g_iLimitAttackTime;
			return true;
		}
	case 276: //-- Harsh Strike 
	case 688: //-- Harsh Strike Improved
	case 691: //-- Harsh Strike Enhanced
		{
			SetAction(o, 290, 1);
			if(o->AnimationFrame>6.f)
			{
				CreateEffect(328, o->Position, o->Angle, o->Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
			}
			if ( o->AnimationFrame>5.f )
			{
				CreateJoint(32131, o->Position, o->Position, o->Angle, 23, NULL, 40.f, 0, 0, 0,-1, 0,-1 );
				CreateJoint(32131, o->Position, o->Position, o->Angle, 23, NULL, 40.f, 1, 0, 0,-1, 0,-1 );
				CreateJoint(32131, o->Position, o->Position, o->Angle, 23, NULL, 40.f, 4, 0, 0,-1, 0,-1 );
				c->AttackTime = 15;
				PlayBuffer (687,0,0 );
			}
			else if ( o->AnimationFrame>2.3f && o->AnimationFrame<2.6f )
			{
				CreateJoint ( 32131, o->Position, o->Position, o->Angle, 23, NULL, 40.f, 2, 0, 0,-1, 0,-1 );
				CreateJoint ( 32131, o->Position, o->Position, o->Angle, 23, NULL, 40.f, 3, 0, 0,-1, 0,-1 );
				PlayBuffer (687,0,0 );
			}
			g_iLimitAttackTime = 15;
			return true;
		}
	case 274: //-- Magic Pin 
	case 692: //-- Magic Pin Improved
	case 694: //-- Magic Pin Enhanced
	case 695: //-- Magic Pin Mastered
		{
			SetAction(o, 292, 1);

			if(AttackTime == 2 || AttackTime == 4 || AttackTime == 6)
			{
				VectorCopy( o->Position, TempPos);
				TempPos[2] += 120.0f;
				CreateEffect(513, TempPos, o->Angle, o->Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
				CreateEffect(328, o->Position, o->Angle, o->Light, 0, o, o->PKKey, 0, 0, 0, 0.0, -1);
			}
			if ( AttackTime >= 13 )
				c->AttackTime = g_iLimitAttackTime;
			return true;
		}
	case 279: //-- Breche 
	case 696: //-- Breche Improved
	case 697: //-- Breche Enhanced
	case 698: //-- Breche Mastered
		{
			SetAction(o, 294, 1);
			PlayBuffer(837, 0, 0);
			if(AttackTime > 2 && AttackTime < 5)
			{
				vec3_t vLight;
				Vector(1.0f, 0.6f, 0.6f, vLight);
				CreateEffect(628, o->Position, o->Angle, vLight, 2, o, -1, 0, 0, 0, 0.5f, -1);
				CreateCircleInfernal(o);
			}
			if ( AttackTime >= 10 )
				c->AttackTime = g_iLimitAttackTime;
			return true;
		}
	}
LABEL_19:
	return ZzzCharacter_AttackStage(c, o);
}

int ReceiveMagic(BYTE *ReceiveBuffer, int Size, BOOL bEncrypted)
{
	if ( bEncrypted )
	{
		LPPRECEIVE_MAGIC Data = (LPPRECEIVE_MAGIC)ReceiveBuffer;
		int SourceKey = ((int)(Data->SourceKeyH )<<8) + Data->SourceKeyL;
		int TargetKey = ((int)(Data->TargetKeyH )<<8) + Data->TargetKeyL;
		int Success = (TargetKey>>15);

		WORD MagicNumber = ((WORD)(Data->MagicH )<<8) + Data->MagicL;

		if ( MagicNumber != 28 && MagicNumber != 27 && MagicNumber != 417 
			&& MagicNumber != 420 && MagicNumber != 422 && MagicNumber != 423 )
		{
			TargetKey &= 0x7FFF;

			int Index       = FindCharacterIndex(SourceKey);
			int TargetIndex = FindCharacterIndex(TargetKey);
			if(TargetIndex == 400)
				return ( TRUE);

			AttackPlayer = Index;
			CHARACTER sc = (CHARACTER)CharactersClient(CList( ),Index);
			CHARACTER tc = (CHARACTER)CharactersClient(CList( ),TargetIndex);
			OBJECT *so = &sc->Object;
			OBJECT *to = &tc->Object;

			switch(MagicNumber)
			{
			case 275: //-- Spin Step
				sc->AttackTime = 1;
				SetAction(so, 298, 1);
				break;
			case 339:
			case 342:
				sc->AttackTime = 1;
				break;
			case 271: //-- Spin Step
			case 687: //-- Spin Step Improved
			case 690: //-- Spin Step Enhanced
				sc->AttackTime = 1;
				break;
			case 272: //-- Circle Shield 
			case 703: //-- Circle Shield Improved
			case 706: //-- Circle Shield Enhanced
				{
					vec3_t Position;
					PlayBuffer(946, 0, 0);
					SetAction(so, 299, 1);

					for(int i = 0; i < 15; i++)
					{
						VectorCopy ( so->Position, Position );
						CreateForce(so, Position);
					}
					/*int Model = GetBMDModel(BMDthisa(), so->Type);

					for (int n = 0; n < 40; n += 2 )
					{
						if ( !*(BYTE *)(*(DWORD *)(Model + 44) + 140 * n + 34) && n < *(WORD *)(Model + 34) )
						{
							int v759 = CLinkBone(so, n);
							if ( !v759 )
								break;
							TransformPosition(Model, v759, p, Position, true);
							for (int ii = 0; ii < 5 + 1; ++ii )
							{
								CreateParticle( 32002, Position, so->Angle, Light, 6, 1.3f+(5*0.08f), 0);
							}
						}
					}
					vec3_t Light, p, Position;
					Vector ( 0.3f, 0.3f, 1.f, Light );
					Vector ( 0.f, 0.f, 0.f, p );
					
					for( int i=0;i<10;i++)
					{
						int v759 = CLinkBone(so, rand()%32);
						TransformPosition(Model, v759, p, Position, true);
						CreateParticle(32002, Position, so->Angle, Light, 5, 0.5f+(rand()%100)/50.f, 0);
					}*/

					//CreateEffect(239, so->Position, so->Angle, so->Light, 2, so, -1, 0, 0, 0, 0.0, -1);
					//DeleteEffect(554, (int)so, -1);
					//CreateEffect(554, so->Position, so->Angle, so->Light, 0, so, -1, 0, 0, 0, 0.0, -1);
					//goto LABEL_40;
				}
				break;
			case 278: //-- Wrath 
			case 708: //-- Wrath Improved
			case 709: //-- Wrath Enhanced
			case 710: //-- Wrath Mastered
				SetAction(so, 296, 1);
LABEL_40:

				PlayBuffer(946, 0, 0);
				vec3_t vLight;
				Vector(0.2f, 0.4f, 1.0f, vLight);
				CreateEffect(32281, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);

				Vector(0.65f, 0.8f, 1.0f, vLight);
				for(int i=0; i < 3; ++i)
				{
					CreateEffect(31738, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);
				}
				Vector(0.5f, 0.55f, 0.9f, vLight);
				CreateEffect(32140, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);
				break;
			case 700:   //-- Burst 
			case 700+1: //-- Burst Improved
				{
					SetAction(so, 297, 1);
					PlayBuffer(946, 0, 0);
					vec3_t vLight;
					Vector(1.0f, 0.4f, 0.2f, vLight);
					CreateEffect(32281, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);

					Vector(1.0f, 0.8f, 0.65f, vLight);
					for(int i=0; i < 3; ++i)
					{
						CreateEffect(31738, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);
					}
					Vector(0.5f, 0.55f, 0.9f, vLight);
					CreateEffect(32140, so->Position, so->Angle, vLight, 0, so, -1, 0, 0, 0, 1.0f, 0);
				}
				break;
			case 273: //-- Obsidian 
			case 693: //-- Obsidian Improved
				{
					SetAction(so, 295, 1);
					DeleteEffect(554, (int)so, -1);
					//CreateEffectS13(3322, so->Position, so->Angle, so->Light, 0, so, -1, 0, 0, 0, 0.0, -1);
					CreateEffect(554, so->Position, so->Angle, so->Light, 0, so, -1, 0, 0, 0, 0.0, -1);
					goto LABEL_40;
				}
				break;
			case 276: //-- Harsh Strike 
			case 688: //-- Harsh Strike Improved
			case 691: //-- Harsh Strike Enhanced
				sc->AttackTime = 1;
				break;
			case 277: //-- Shining Peak 
			case 699: //-- Shining Peak Improved
				sc->AttackTime = 1;
				break;
			case 274: //-- Magic Pin 
			case 692: //-- Magic Pin Improved
			case 694: //-- Magic Pin Enhanced
			case 695: //-- Magic Pin Mastered
				sc->AttackTime = 1;
				break;
			case 279: //-- Breche 
			case 696: //-- Breche Improved
			case 697: //-- Breche Enhanced
			case 698: //-- Breche Mastered
				{
					sc->AttackTime = 1;
					CreateEffect(32371, to->Position, to->Angle, to->Light, 2, to, -1, 0, 0, 0, 0.5f, -1);
				}
				break;
			}
		}
	}

	return sub_645BA0(ReceiveBuffer, Size, bEncrypted);
}

float cUltimoTime = 0.0;

void CRenderCharacter(int a1, int a2, int a3)
{
	CHARACTER c = (CHARACTER)a1;
	OBJECT* o = (OBJECT *)a2;
//	RenderCharacter((int)c, (int)o, a3);
	int Model = GetBMDModel(BMDthisa(), o->Type);
	if(Model)	
	{
		unsigned __int8 byClass =(unsigned __int8)pGetCharacterClass(c->Class);

		if ( g_isCharacterBuff((DWORD *)((int)c + 1260), 218)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 223)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 224)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 225)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 219)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 226))
		{
			float cTime01, cTime02, cCal;
			vec3_t Light, Light2;
			int TypeFlare01 = 0;
			int TypeEffect0001 = 0;

			if(cUltimoTime > 3.5f) { cUltimoTime = 0.0; }

			float Ctime1 = cUltimoTime + 0.25;
			cUltimoTime += 0.25;
			cCal = 1.f - (cUltimoTime / 5.5f);
			Vector( cCal, cCal, cCal, Light);

			EnableAlphaBlend();
			if(g_isCharacterBuff((DWORD *)((int)c + 1260), 219)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 226))
			{
				TypeFlare01 = 32229;
				TypeFlare01 = 32231;
				TypeEffect0001 = 533030;
				Vector(0.95, 0.1, 0.18, Light2);

				vec3_t Light_1, Angle, _vPos;
				int arr[] = { 2,3,4,5,10,11,12,18,19,25,26,27,34,35,36,20,37,28 };

				for ( int i = 0; i < 17; ++i )
				{
					int v759 = CLinkBone(o, arr[i]);
					if ( v759 )
					{
						float v92 = (double)(rand() % 15) / 37.5;
						float v183 = v92 + 0.5;
						Vector(v183 * 0.95, v183 * 0.25, v183 * 0.18, Light_1);

						Vector(0.0, 0.0, 0.0, Angle);
						TransformPosition(Model, v759, Angle, _vPos, 1);
				//		CreateParticle(32002, _vPos, o->Angle, Light_1, 5, 0.001f+(rand()%100)/70.f, 0);
					}
				}
			}
			else
			{
				TypeFlare01 = 32229;
				TypeEffect0001 = 532029;
				Vector(0.18, 0.1, 0.95, Light2);

				vec3_t Light_1, Angle, _vPos;
				int arr[] = { 2,3,4,5,10,11,12,18,19,25,26,27,34,35,36,20,37,28 };

				for ( int i = 0; i < 17; ++i )
				{
					int v759 = CLinkBone(o, arr[i]);
					if ( v759 )
					{
						float v92 = (double)(rand() % 15) / 37.5;
						float v183 = v92 + 0.5;
						Vector(v183 * 0.25, v183 * 0.5, v183 * 0.75, Light_1);

						Vector(0.0, 0.0, 0.0, Angle);
						TransformPosition(Model, v759, Angle, _vPos, 1);
					//	CreateParticle(32002, _vPos, o->Angle, Light_1, 5, 0.001f+(rand()%100)/70.f, 0);
					}
				}
			}

			CRenderTerrainAlphaBitmap(TypeEffect0001, o->Position[0], o->Position[1], Ctime1, Ctime1, Light, timeGetTime() * 0.08, 1.0, 2.0, 1);
			cTime01 = sub_4EC46D(3.5, 0.0) * 0.4000000059604645;
			cTime02 = sub_4EC46D(3.5, 0.0) * 2.2;
			cCal = 1.0 - cTime01 * 2.25;
			Vector(cCal * 1.0, cCal * 1.0, cCal * 1.0, Light);
			CRenderTerrainAlphaBitmap(532028, o->Position[0], o->Position[1], Ctime1, Ctime1, Light, timeGetTime() * 0.0, 1.0, 2.0, 1);
			CRenderTerrainAlphaBitmap(32002, o->Position[0], o->Position[1], 5.0, 5.0, Light2, timeGetTime() * 0.0, 1.0, 2.0, 1);
			Vector(0.5, 0.5, 0.5, Light);
			CRenderTerrainAlphaBitmap(TypeFlare01, o->Position[0], o->Position[1], 2.0, 2.0, Light, timeGetTime() * 0.0, 1.0, 2.0, 1);
			CRenderTerrainAlphaBitmap(TypeFlare01, o->Position[0], o->Position[1], 2.0, 2.0, Light, timeGetTime() * -0.025, 1.0, 2.0, 1);
			DisableAlphaBlend();
			//--
		}
		else if(g_isCharacterBuff((DWORD *)((int)c + 1260), 216)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 221)
			|| g_isCharacterBuff((DWORD *)((int)c + 1260), 222) )
		{
			vec3_t Light, p, Position;
			Vector ( 0.3f, 0.3f, 1.f, Light );
			Vector ( 0.f, 0.f, 0.f, p );
					
			for( int i=0 ; i < 10 ; i++)
			{
				int v759 = CLinkBone(o, rand()%32);
				TransformPosition(Model, v759, p, Position, true);
				CreateParticle(32002, Position, o->Angle, Light, 5, 0.5f+(rand()%100)/50.f, 0);
			}
		}
		/*CreateEffect(423, o->Position, o->Angle, o->Light, 2, o, -1, 0, 0, 0, 0.0, -1);
		CreateEffect(425, o->Position, o->Angle, o->Light, 2, o, -1, 0, 0, 0, 0.0, -1);
		CreateEffect(398, o->Position, o->Angle, o->Light, 1, o, -1, 0, 0, 0, 0.0, -1);*/

	}
}

int Xor_ConvertBuffer( void *lpBuffer, int iSize, int iKey)
{
	return iKey;
}

void CErrorReport_Create(void *thisa, char *lpszFileName)
{
}

void UseSkillWarrior(int c, int o)
{
	ZzzInterface_UseSkillWarrior(c, o);
	CheckSkillDelay(*(BYTE *)(Hero + 50));
}


void ZzzInterface::Init()
{
	/*SetCompleteHook(0xE8, 0x0056F476, &Draw_RenderObject);
	SetCompleteHook(0xE8, 0x005EBBE6, &Draw_RenderObject);
	//--
	SetCompleteHook(0xE8, 0x006D7DC7, &MoveEffectS13);
	SetCompleteHook(0xE8, 0x00720C48, &MoveEffectS13);
	SetCompleteHook(0xE8, 0x00720C7A, &MoveEffectS13);
	SetCompleteHook(0xE8, 0x007217E4, &MoveEffectS13);
	//--
	SetCompleteHook(0xE8, 0x004D735E, &RenderEffectsS13);
	SetCompleteHook(0xE8, 0x004D7AAE, &RenderEffectsS13);
	SetCompleteHook(0xE8, 0x004D9AAF, &RenderEffectsS13);
	SetCompleteHook(0xE8, 0x004D9BD0, &RenderEffectsS13);*/

	//--
	SetCompleteHook(0xE9, 0x0050F56C, &SetEffectLith);
	//--
	SetDword(0x00644F74 + 3, 250); //-- recv Effect
	SetDword(0x006450B1 + 3, 250); //-- recv Effect
	SetDword(0x006591D1 + 3, 250); //-- recv Effect
	SetDword(0x004ADCC0 + 3, 250); //-- Check Buff
	SetDword(0x004ADD59 + 3, 250); //-- Register Buff
	SetDword(0x004B25FB + 3, 250); //-- Insete Buff
	SetDword(0x00777EC4 + 2, 250); //-- Icon buff
	SetDword(0x005599C7 + 1, 300); //-- ampliar sistema de accion
	SetDword(0x00616478 + 3, 300); //-- ampliar sistema de accion

	SetCompleteHook(0xE8, 0x0096AE79, &Xor_ConvertBuffer);
	SetCompleteHook(0xE8, 0x0096AA50, &CErrorReport_Create);
	//--
	SetCompleteHook(0xE8, 0x0059B4FB, &UseSkillWarrior);
	//--
	SetCompleteHook(0xE8, 0x005B7740, &Attack);
	SetCompleteHook(0xE8, 0x0055B3C7, &AttackStage);
	
	SetCompleteHook(0xE9, 0x0059C51D, &CheckSkillAttack);
	SetCompleteHook(0xE9, 0x0059CA3C, &CheckJumpAttack);
	SetCompleteHook(0xE8, 0x006642A6, &ReceiveMagic);
	//-- Buffos
	/*SetCompleteHook(0xE8, 0x0040487D, &CRenderCharacter);
	SetCompleteHook(0xE8, 0x0048E56C, &CRenderCharacter);
	SetCompleteHook(0xE8, 0x0057D4FF, &CRenderCharacter);
	SetCompleteHook(0xE8, 0x0057D513, &CRenderCharacter);*/
	SetCompleteHook(0xE8, 0x0055A34D, &PlayerStopAnimationSetting);
	SetCompleteHook(0xE9, 0x006E1A79, &ShiningPeakBodyEffect);
	
	SetCompleteHook(0xE8, 0x0055179F, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00551911, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x0055272F, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x0059C2DE, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x0059D02E, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x0059E6A9, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AC570, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AD840, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005ADAE8, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005ADE42, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AE1D1, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AE870, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AEB93, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AF1CD, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005AF522, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B05E7, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B073E, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B0C23, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B0DA8, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B1898, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B22B3, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B2CB4, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x005B3870, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00616A1A, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x0063F4A7, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00645712, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00647503, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00647594, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00647BDC, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00749B83, &SetAttackSpeed);
	SetCompleteHook(0xE8, 0x00749C03, &SetAttackSpeed);
}
