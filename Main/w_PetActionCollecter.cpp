#include "StdAfx.h"
#include "Util.h"
#include "SEASON3B.h"
#include "w_PetActionCollecter.h"
#include "Extras.h"
#include "Import.h"
#include "zzzmathlib.h"

PetActionCollecter actionCollecter[10];

PetActionCollecter::PetActionCollecter(void)
{
	m_Type = 0;
	GetitemType = -1;
	m_startTick = 0;
	m_isRooting = false;
	m_dwSendDelayTime = 0;
	m_dwRootingTime = 0;
	m_dwRoundCountDelay = 0;
	m_state = eAction_Stand;
	m_obj = NULL;
}

PetActionCollecter::~PetActionCollecter(void)
{
}

void SendRequestGetItem(int p_Key)
{
	if (SendGetItem == -1)
	{
		SendGetItem = p_Key;

		CStreamPacketEngine spe;
		spe.Init(0xC1, 0x22);
		spe.Rightshift1((BYTE)((p_Key) >> 8));
		spe.Rightshift1((BYTE)((p_Key) & 0xff));
		spe.Send(TRUE);
	}
}

void PetActionCollecter::Init()
{
	if (m_obj == NULL)
	{
		int byclass = new_Class(0x288u);

		if (byclass)
		{
			m_obj = (OBJECT*)new_OBJECT(byclass);
		}
		else
		{
			m_obj = NULL;
		}
	}
}

void PetActionCollecter::DeletPet(int Owner)
{
	if (m_obj)
	{
		if (m_obj->Live)
		{
			if ((int)m_obj->Owner == Owner)
			{
				m_obj->Live = 0;
			}
		}
	}
}

bool PetActionCollecter::Create(int itemType, int modelType, vec3_t Position, int Owner, int SubType, int LinkBone)
{
	this->Init();

	if (m_obj->Live)
	{
		return FALSE;
	}
	m_Type = -1;
	m_obj->Type = modelType;
	m_obj->Live = TRUE;
	m_obj->Visible = FALSE;
	m_obj->LightEnable = TRUE;
	m_obj->ContrastEnable = FALSE;
	m_obj->AlphaEnable = FALSE;
	m_obj->EnableBoneMatrix = FALSE;
	m_obj->Owner = (OBJECT*)Owner;
	m_obj->SubType = SubType;
	m_obj->HiddenMesh = -1;
	m_obj->BlendMesh = -1;
	m_obj->BlendMeshLight = 1.f;
	m_obj->Scale = 0.7f;
	m_obj->LifeTime = 30;
	m_obj->Alpha = 0.f;
	m_obj->AlphaTarget = 1.f;

	VectorCopy(Position, m_obj->Position);
	VectorCopy(m_obj->Owner->Angle, m_obj->Angle);
	Vector(3.f, 3.f, 3.f, m_obj->Light);

	m_obj->PriorAnimationFrame = 0.f;
	m_obj->AnimationFrame = 0.f;
	m_obj->Velocity = 0.5f;
	GetitemType = -1;
	//-- llaman al pet
	PART_PET_INFO* PetInfo = g_MuunPet.GetInfoPet(itemType);

	if (PetInfo)
	{
		m_obj->Scale = PetInfo->Scale[2];
		m_Type = PetInfo->PetType;
		GetitemType = PetInfo->GetItem; //-- aquí va el index del item que quieren recoger
	}

	ActionType[eAction_Stand] = 0;
	ActionType[eAction_Move] = 2;
	ActionType[eAction_Get] = 0;
	ActionType[eAction_Return] = 2;
	//--
	ActionStand[eAction_Stand] = 0;
	ActionStand[eAction_Stand + 1] = 1;

	return TRUE;
}

void PetActionCollecter::Render(bool bForceRender)
{
	if (m_obj)
	{
		if (m_obj->Live)
		{
			AI_Alpha(m_obj);

			m_obj->Visible = (bForceRender == FALSE ? TestFrustrum2D(m_obj->Position[0] * 0.01f, m_obj->Position[1] * 0.01f, -20.f) : TRUE);

			if (m_obj->Visible)
			{
				int State = 0;
				if (m_obj->Owner)
				{
					if (g_isCharacterBuff((DWORD*)(*(DWORD*)((int)m_obj + 472) + 484), 18) == 1)
					{
						State = 10;
					}
				}

				Render_Object((int)m_obj, FALSE, 0, State);

				if (m_Type == 8)
				{
					Effect(bForceRender);
					Sound(bForceRender);
				}
			}
		}
	}
}

bool PetActionCollecter::Move()
{
	if (m_obj)
	{
		int b = g_Models(bthisa(), m_obj->Type);

		if (m_obj->Live && m_obj->Owner && b)
		{
			if (m_Type == 8)
			{
				FindZen();
				if (eAction_Stand == m_state && m_isRooting)
				{
					m_state = eAction_Move;
				}
				float FlyRange = 12.0f;

				float Angle, Speed, Distance;
				vec3_t TargetPos, Range, Direction;

				m_obj->Position[2] = m_obj->Owner->Position[2] + (50.0f * m_obj->Owner->Scale);

				VectorSubtract(m_obj->Position, m_obj->Owner->Position, Range);

				Distance = sqrtf(Range[0] * Range[0] + Range[1] * Range[1]);

				if (Distance > 900.0)
				{
					m_obj->Position[0] = m_obj->Owner->Position[0];
					m_obj->Position[1] = m_obj->Owner->Position[1];

					VectorCopy(m_obj->Owner->Angle, m_obj->Angle);

					m_state = eAction_Stand;
					m_isRooting = false;
				}

				switch (m_state)
				{
				case eAction_Stand:
				{
					TargetPos[0] = m_obj->Owner->Position[0];
					TargetPos[1] = m_obj->Owner->Position[1];
					TargetPos[2] = m_obj->Owner->Position[2];

					VectorSubtract(TargetPos, m_obj->Position, Range);
					Distance = sqrtf(Range[0] * Range[0] + Range[1] * Range[1]);

					if (80.0f >= FlyRange)
					{
						Angle = CreateAngle(m_obj->Position[0], m_obj->Position[1], TargetPos[0], TargetPos[1]); //test
						m_obj->Angle[2] = TurnAngle2(m_obj->Angle[2], Angle, 8.0f);
					}

					AngleMatrix(m_obj->Angle, m_obj->Matrix);
					VectorRotate(m_obj->Direction, m_obj->Matrix, Direction);
					VectorAdd(m_obj->Position, Direction, m_obj->Position);

					Speed = (FlyRange * FlyRange >= Distance) ? 0 : (float)log(Distance) * 2.3f;

					m_obj->Direction[0] = 0.0f;
					m_obj->Direction[1] = -Speed;
					m_obj->Direction[2] = 0.0f;
				}
				break;
				case eAction_Move:
				{
					if (!m_isRooting)
					{
						m_isRooting = false;
						m_state = eAction_Return;
						break;
					}

					TargetPos[0] = m_RootItem.position[0];
					TargetPos[1] = m_RootItem.position[1];
					TargetPos[2] = m_RootItem.position[2];

					VectorSubtract(TargetPos, m_obj->Position, Range);

					Distance = sqrtf(Range[0] * Range[0] + Range[1] * Range[1]);
					if (Distance >= FlyRange)
					{
						Angle = CreateAngle(m_obj->Position[0], m_obj->Position[1], TargetPos[0], TargetPos[1]); //test
						m_obj->Angle[2] = TurnAngle2(m_obj->Angle[2], Angle, 20.0f);
					}

					AngleMatrix(m_obj->Angle, m_obj->Matrix);
					VectorRotate(m_obj->Direction, m_obj->Matrix, Direction);
					VectorAdd(m_obj->Position, Direction, m_obj->Position);

					Speed = (20.0f >= Distance) ? 0 : (float)log(Distance) * 2.5f;

					m_obj->Direction[0] = 0.0f;
					m_obj->Direction[1] = -Speed;
					m_obj->Direction[2] = 0.0f;

					if (0 == Speed || CompTimeControl(100000, m_dwRootingTime))
					{
						m_dwSendDelayTime = GetTickCount();
						m_dwRootingTime = GetTickCount();
						m_state = eAction_Get;
					}
				}
				break;
				case eAction_Get:
				{
					if (!m_isRooting || 300.f < Distance || CompTimeControl(3000, m_dwRootingTime))
					{
						m_isRooting = false;
						m_dwRootingTime = GetTickCount();
						m_state = eAction_Return;
						break;
					}

					VectorCopy(m_RootItem.position, TargetPos);

					Angle = CreateAngle(m_obj->Position[0], m_obj->Position[1], TargetPos[0], TargetPos[1]);
					m_obj->Angle[2] = TurnAngle2(m_obj->Angle[2], Angle, 10.0f);

					if (CompTimeControl(1000, m_dwSendDelayTime)
						&& Hero + 776 == (int)m_obj->Owner)
					{
						SendRequestGetItem(m_RootItem.itemIndex);
					}
				}
				break;
				case eAction_Return:
				{
					TargetPos[0] = m_obj->Owner->Position[0];
					TargetPos[1] = m_obj->Owner->Position[1];
					TargetPos[2] = m_obj->Owner->Position[2];

					VectorSubtract(TargetPos, m_obj->Position, Range);

					Distance = sqrtf(Range[0] * Range[0] + Range[1] * Range[1]);
					if (Distance >= FlyRange)
					{
						Angle = CreateAngle(m_obj->Position[0], m_obj->Position[1], TargetPos[0], TargetPos[1]); //test
						m_obj->Angle[2] = TurnAngle2(m_obj->Angle[2], Angle, 20.0f);
					}

					AngleMatrix(m_obj->Angle, m_obj->Matrix);
					VectorRotate(m_obj->Direction, m_obj->Matrix, Direction);
					VectorAdd(m_obj->Position, Direction, m_obj->Position);

					Speed = (FlyRange >= Distance) ? 0 : (float)log(Distance) * 2.5f;

					m_obj->Direction[0] = 0.0f;
					m_obj->Direction[1] = -Speed;
					m_obj->Direction[2] = 0.0f;

					if (0 == Speed || CompTimeControl(3000, m_dwRootingTime))
					{
						m_state = eAction_Stand;
					}
				}
				break;
				}
			}

			if ((m_obj->Owner->CurrentAction < 15 || m_obj->Owner->CurrentAction > 37))
			{
				if (GetTickCount() <= (m_startTick + 800))
				{
					m_obj->CurrentAction = ActionStand[eAction_Stand + 1];
				}
				else if (GetTickCount() <= (m_startTick + 12000))
				{
					m_obj->CurrentAction = ActionStand[eAction_Stand];
				}
				else
				{
					m_startTick = GetTickCount();
				}
			}
			else
			{
				m_obj->CurrentAction = ActionType[eAction_Move];
			}

			*(WORD*)(b + 160) = m_obj->CurrentAction;
			PlayAnimation(b, &m_obj->AnimationFrame, &m_obj->PriorAnimationFrame, &m_obj->PriorAction, m_obj->Velocity, m_obj->Position, m_obj->Angle);
		}
	}
	return TRUE;
}

bool PetActionCollecter::Sound(bool bForceRender)
{
	switch (m_state)
	{
	case eAction_Return:
		PlayBuffer(31, 0, 0);
		break;
	}
	return TRUE;
}


void PetActionCollecter::FindZen()
{
	char* _item;

	if (m_isRooting != true && GetitemType != -1)
	{
		float dx, dy, dl;
		WORD* word_81F6C02 = (WORD*)0x81F6C02;

		for (int i = 0; i < 1000; i++)
		{
			_item = (char*)&*(LPVOID*)0x81F6C70 + 848 * i;

			if (*((BYTE*)&*(LPVOID*)0x81F6C70 + 848 * i + 4))
			{
				if (_item[12])
				{
					dx = m_obj->Owner->Position[0] - *((float*)_item + 63);
					dy = m_obj->Owner->Position[1] - *((float*)_item + 64);

					dl = sqrtf(dx * dx + dy * dy);

					if (dl < 300.0 && (word_81F6C02[424 * i] == GetitemType)
						&& !m_isRooting)
					{
						m_isRooting = true;
						m_RootItem.itemIndex = i;

						VectorCopy(((float*)_item + 63), m_RootItem.position)
					}
				}
			}
		}
	}
}

bool PetActionCollecter::Effect(bool bForceRender)
{
	if (m_obj)
	{
		int b = g_Models(bthisa(), m_obj->Type);

		if (m_obj->Live && m_obj->Owner && b)
		{
			vec3_t Position, vRelativePos, Light;

			VectorCopy(m_obj->Position, (float*)(b + 108));
			Vector(0.f, 0.f, 0.f, vRelativePos);

			Animation(b, BoneTransform, m_obj->AnimationFrame, m_obj->PriorAnimationFrame, m_obj->PriorAction, m_obj->Angle, m_obj->HeadAngle, false, true);

			float fSize = 0.2f;
			float fSize2 = 1.0f;

			Vector(1.0f, 0.8f, 0.2f, Light);
			VectorCopy(m_obj->Position, Position);
			Position[2] += 30.0f;

			//CreateParticle(32113, Position, m_obj->Angle, Light, 7, 1.0, 0);

			switch (m_state)
			{
			case eAction_Move:
				/*fSize = 0.8f;
				fSize2 = 3.0f;*/
				break;
			case eAction_Get:
				/*fSize = 0.8f;
				fSize2 = 3.0f;*/
				break;
			case eAction_Return:
				CreateEffect(211, Position, m_obj->Angle, Light, 0, 0, -1, 0, 0, 0, 0.0, -1);
				break;
			}

			/*TransformPosition(b, BoneTransform + (0x30 * 10), vRelativePos, Position, false);
			Vector( 1.0f, 0.8f, 0.2f, Light);
			CreateSprite(32231, Position, (0.5f + fSize), Light, m_obj, 0.0, 0);
			Vector( 1.0f, 0.1f, 0.2f, Light);
			CreateSprite(32002, Position, (2.0f + fSize), Light, m_obj, 0.0, 0);

			int temp[] = { 19, 32, 33, 34, 35 };

			for(int i=0; i<5; i++)
			{
				TransformPosition(b, BoneTransform + (0x30 * temp[i]), vRelativePos, Position, false);

				Vector( 0.8f, 0.6f, 0.2f, Light);
				CreateSprite(32002, Position, (0.6f * fSize2), Light, m_obj, 0.0, 0);
				Vector( 0.8f, 0.8f, 0.2f, Light);
				CreateSprite(32114, Position, (0.4f * fSize2), Light, m_obj, 0.0, 0);
			}*/
		}
	}

	return TRUE;
}

bool PetActionCollecter::CompTimeControl(const DWORD& dwCompTime, DWORD& dwTime)
{
	if ((timeGetTime() - dwTime) > dwCompTime)
	{
		dwTime = timeGetTime();
		return true;
	}
	return false;
}