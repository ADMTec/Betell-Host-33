#include "stdafx.h"
#include "Camera.h"
#include "TMemory.h"
#include "Interface.h"
#include "User.h"
#include "Util.h"
#include "Import.h"
#if(CAMARA==0)
float TenFix;

// ----------------------------------------------------------------------------------------------

Camera	gCamera;
// ----------------------------------------------------------------------------------------------

Camera::~Camera()
{

}
// ----------------------------------------------------------------------------------------------

void Camera::Load()
{

}

Camera::Camera()
{
	this->m_Address.RotX = (float*)0x087933D8;
	this->Default.Zoom = *(float*)oCam_Zoom;
	this->Default.RotationY = *(float*)oCam_RotY;
	this->Default.RotationZ = *(float*)oCam_RotZDef;
	this->Default.PositionZ = *(float*)oCam_PosZ;
	this->Default.ClipX = *(double*)oCam_ClipX;
	this->Default.ClipY = *(float*)oCam_ClipY;
	this->Default.ClipZ = *(double*)oCam_ClipZ;
	this->Default.ClipX2 = *(double*)oCam_ClipX2;
	this->Default.ClipY2 = *(float*)oCam_ClipY2;
	this->Default.ClipZ2 = *(float*)oCam_ClipZ2;
	this->Default.ClipGL = *(float*)oCam_ClipGL;
	//
	this->Default.Z3 = *(float*)oCam_Zoom + 7;
	this->Default.Y3 = *(float*)oCam_RotY - 3;
	this->Default.Z6 = *(float*)oCam_Zoom + 15;
	this->Default.Y6 = *(float*)oCam_RotY - 7;
	// ----
	this->InMove = 0;
	this->IsActive = 0;
	this->RotateMode = 2;
	this->ZoomPercent = 0.0;
	this->TempCursorX = 0;
	this->TempCursorY = 0;
	// ----
	this->ZoomPercent = this->Default.Zoom / ((float)ZOOM_MAX / 100.0f);

	SetCompleteHook(0xE9, 0x0063764C, &RotateFix);
	SetCompleteHook(0xE9, 0x005DB322, 0x5DB408); //-> Fix 3D Cam in Santa Village
}

void Camera::Reset()
{
	if (pPlayerState != GameProcess)
	{
		return;
	}
	// ----

	SetFloat((LPVOID)oCam_Zoom, this->Default.Zoom);
	SetFloat((LPVOID)oCam_RotY, this->Default.RotationY);
	SetFloat((LPVOID)oCam_RotZ, this->Default.RotationZ);
	SetFloat((LPVOID)oCam_PosZ, this->Default.PositionZ);

	SetDouble((LPVOID)oCam_ClipX, this->Default.ClipX + 500);
	SetFloat((LPVOID)oCam_ClipGL, this->Default.ClipGL + 200); //Full HD

	SetFloat((LPVOID)oCam_ClipY, this->Default.ClipY);
	SetDouble((LPVOID)oCam_ClipZ, this->Default.ClipZ);
	SetDouble((LPVOID)oCam_ClipX2, this->Default.ClipX2);
	SetFloat((LPVOID)oCam_ClipY2, this->Default.ClipY2);
	SetFloat((LPVOID)oCam_ClipZ2, this->Default.ClipZ2);


	// ----
	this->ZoomPercent = *(float*)oCam_Zoom / ((float)ZOOM_MAX / 100.0f);

	TenFix = this->ZoomPercent;
}

bool Camera::getEnabled()
{
	return false;
}

void Camera::Toggle()
{
}

void Camera::Restore()
{
}

void Camera::Init()
{
	if (pPlayerState != GameProcess)
	{
		return;
	}
	// ---
	//SetFloat((LPVOID)0x0D27B1C, 1100.000);
	SetDouble((LPVOID)oCam_ClipX, PERCF(PERCF(this->Default.ClipX, 500), this->ZoomPercent));
	SetFloat((LPVOID)oCam_ClipY, PERCF(PERCF(this->Default.ClipY, 285), this->ZoomPercent));
	SetDouble((LPVOID)oCam_ClipZ, PERCF(PERCF(this->Default.ClipZ, -395), this->ZoomPercent));
	SetDouble((LPVOID)oCam_ClipX2, PERCF(PERCF(this->Default.ClipX2, 235), this->ZoomPercent));
	SetFloat((LPVOID)oCam_ClipY2, PERCF(PERCF(this->Default.ClipY2, 195), this->ZoomPercent));
	SetFloat((LPVOID)oCam_ClipZ2, PERCF(PERCF(this->Default.ClipZ2, -4000), this->ZoomPercent));
	SetFloat((LPVOID)oCam_ClipGL, PERCF(PERCF(this->Default.ClipGL, 250), this->ZoomPercent));
}

// ----------------------------------------------------------------------------------------------

void Camera::Switch()
{
	if (pPlayerState != GameProcess)
	{
		return;
	}
	// ----
	this->IsActive = !this->IsActive;
}
// ----------------------------------------------------------------------------------------------

void Camera::Run(MOUSEHOOKSTRUCTEX * Mouse, WPARAM wParam)
{
	/*if (pMapNumber == 30 || pMapNumber == 62)
	{
	this->IsActive = false;
	this->Init();
	}*/
	// ----
	switch (wParam)
	{
	case WM_MOUSEWHEEL:
	{
		if (!this->IsActive
			|| gInterface.CheckWindow(MoveList)
			)
		{
			return;
		}
		// ----
		if ((int)Mouse->mouseData > 0)
		{
			if (*(float*)oCam_Zoom < ZOOM_MAX)
			{
				SetFloat((LPVOID)oCam_Zoom, *(float*)oCam_Zoom + ZOOM_INTER);
			}
			else
			{
				SetFloat((LPVOID)oCam_Zoom, (float)ZOOM_MAX);
			}
		}
		else if ((int)Mouse->mouseData < 0)
		{
			if (*(float*)oCam_Zoom > ZOOM_MIN)
			{
				SetFloat((LPVOID)oCam_Zoom, *(float*)oCam_Zoom - ZOOM_INTER);
			}
			else
			{
				SetFloat((LPVOID)oCam_Zoom, (float)ZOOM_MIN);
			}
		}
		// ----
		this->ZoomPercent = *(float*)oCam_Zoom / ((float)ZOOM_MAX / 100.0f);
		// ----

		{


			SetDouble((LPVOID)oCam_ClipX, PERCF(PERCF(this->Default.ClipX, 500), this->ZoomPercent));
			SetFloat((LPVOID)oCam_ClipY, PERCF(PERCF(this->Default.ClipY, 285), this->ZoomPercent));
			SetDouble((LPVOID)oCam_ClipZ, PERCF(PERCF(this->Default.ClipZ, -150), this->ZoomPercent));
			SetDouble((LPVOID)oCam_ClipX2, PERCF(PERCF(this->Default.ClipX2, 235), this->ZoomPercent));
			SetFloat((LPVOID)oCam_ClipY2, PERCF(PERCF(this->Default.ClipY2, 195), this->ZoomPercent));
			SetFloat((LPVOID)oCam_ClipZ2, PERCF(PERCF(this->Default.ClipZ2, -150), this->ZoomPercent));
			SetFloat((LPVOID)oCam_ClipGL, PERCF(PERCF(this->Default.ClipGL, 250), this->ZoomPercent));
		}
	}
	break;
	// --
	case WM_MBUTTONDOWN:
	{
		this->InMove = true;
	}
	break;
	// --
	case WM_MBUTTONUP:
	{
		this->InMove = false;
	}
	break;
	}
	this->Rotate();
}
// ----------------------------------------------------------------------------------------------

void Camera::Rotate()
{
	if (!this->IsActive)
	{
		return;
	}
	// ----
	if (this->RotateMode == 1) //-> Auto rotation
	{
		if (gObjUser.m_CursorX <= 150)
		{
			SetFloat((LPVOID)oCam_RotZ, *(float*)oCam_RotZ - ROTATION_SENS);
		}
		else if (gObjUser.m_CursorX >= 500)
		{
			SetFloat((LPVOID)oCam_RotZ, *(float*)oCam_RotZ + ROTATION_SENS);
		}
	}
	else if (this->RotateMode == 2 && this->InMove) //-> Manual rotation
	{
		if (this->TempCursorX < gObjUser.m_CursorX)
		{
			SetFloat((LPVOID)oCam_RotZ, *(float*)oCam_RotZ + ROTATION_SENS);
		}
		else if (this->TempCursorX > gObjUser.m_CursorX)
		{
			SetFloat((LPVOID)oCam_RotZ, *(float*)oCam_RotZ - ROTATION_SENS);
		}
		// ----
		this->TempCursorX = gObjUser.m_CursorX;
	}
}
// ----------------------------------------------------------------------------------------------

void Camera::RotateDmg(float& X, float& Y, float D)
{
	const float Rad = 0.01745329f;
	float sinTh = sin(Rad * (*(float*)0x87933D8));
	float cosTh = cos(Rad * (*(float*)0x87933D8));

	X += D / 0.7071067f * cosTh / 2;
	Y -= D / 0.7071067f * sinTh / 2;
}

void __declspec(naked) Camera::RotateFix()
{
	static DWORD jmpBack = 0x0063752D;

	_asm
	{
		Lea Eax, [Ebp - 0x38];
		Lea Ecx, [Ebp - 0x3C];
		Push Dword Ptr[Ebp + 0x18];
		Push Eax;
		Push Ecx;
		Call RotateDmg;
		Add Esp, 0xC;
		jmp[jmpBack];
	}
}
#endif
#include "stdafx.h"
#if (CAMARA)
// Camera.cpp: implementation of the CCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "Camera.h"
#include "Offset.h"
#include "Util.h"

CCamera gCamera;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCamera::CCamera() // OK
{
	this->m_Enable = 0;

	this->m_IsMove = 0;

	this->m_CursorX = 0;

	this->m_CursorY = 0;

	this->m_Zoom.MinPercent = 50.0;

	this->m_Zoom.MaxPercent = 130.0;

	this->m_Zoom.Precision = 2.0;

	this->m_Address.Zoom = (float*)0x00D27BFC;

	this->m_Address.RotX = (float*)0x087933D8;

	this->m_Address.RotY = (float*)0x00D27B88;

	this->m_Address.PosZ = (double*)0x00D255A0;

	this->m_Address.ClipX[0] = (double*)0x00D2C848;

	this->m_Address.ClipX[1] = (double*)0x00D2C898;

	this->m_Address.ClipY[0] = (float*)0x00D2C894;

	this->m_Address.ClipY[1] = (float*)0x00D2C8A8;

	this->m_Address.ClipGL = (float*)0x00D2570C;

	this->m_Default.IsLoad = 0;
	
	SetCompleteHook(0xE9, 0x0063764C, &RotateFix);
	SetCompleteHook(0xE9, 0x005DB322, 0x5DB408); //-> Fix 3D Cam in Santa Village
}

CCamera::~CCamera() // OK
{

}

void CCamera::Toggle() // OK
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		this->m_Enable ^= 1;

		if(((this->m_Default.IsLoad==0)?(this->m_Default.IsLoad++):this->m_Default.IsLoad) == 0)
		{
			this->m_Default.Zoom = (*this->m_Address.Zoom);

			this->m_Default.RotX = (*this->m_Address.RotX);

			this->m_Default.RotY = (*this->m_Address.RotY);

			this->m_Default.PosZ = (*this->m_Address.PosZ);

			this->m_Default.ClipX[0] = (*this->m_Address.ClipX[0]);

			this->m_Default.ClipX[1] = (*this->m_Address.ClipX[1]);

			this->m_Default.ClipY[0] = (*this->m_Address.ClipY[0]);

			this->m_Default.ClipY[1] = (*this->m_Address.ClipY[1]);

			this->m_Default.ClipGL = (*this->m_Address.ClipGL);
		}
	}
}

bool CCamera::getEnabled()
{
	return this->m_Enable != 0;
}

void CCamera::Restore() // OK
{
	if(this->m_Enable != 0 && *(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		this->SetDefaultValue();
	}
}

void CCamera::SetIsMove(BOOL IsMove) // OK
{
	if(this->m_Enable != 0 && *(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		this->m_IsMove = IsMove;
	}
}

void CCamera::SetCursorX(LONG CursorX) // OK
{
	if(this->m_Enable != 0 && *(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		this->m_CursorX = CursorX;
	}
}

void CCamera::SetCursorY(LONG CursorY) // OK
{
	if(this->m_Enable != 0 && *(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		this->m_CursorY = CursorY;
	}
}

void CCamera::Zoom(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if(this->m_Enable == 0 || this->m_IsMove != 0 || *(DWORD*)(MAIN_SCREEN_STATE) != 5)
	{
		return;
	}

	this->m_Zoom.MinLimit = (this->m_Default.Zoom/100)*this->m_Zoom.MinPercent;

	this->m_Zoom.MaxLimit = (this->m_Default.Zoom/100)*this->m_Zoom.MaxPercent;

	if(((int)lpMouse->mouseData) > 0)
	{
		if((*this->m_Address.Zoom) >= this->m_Zoom.MinLimit)
		{
			SetFloat((DWORD)this->m_Address.Zoom,((*this->m_Address.Zoom)-this->m_Zoom.Precision));
		}
	}

	if(((int)lpMouse->mouseData) < 0)
	{
		if((*this->m_Address.Zoom) <= this->m_Zoom.MaxLimit)
		{
			SetFloat((DWORD)this->m_Address.Zoom,((*this->m_Address.Zoom)+this->m_Zoom.Precision));
		}
	}

	this->SetCurrentValue();
}

void CCamera::Move(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if(this->m_Enable == 0 || this->m_IsMove == 0 || *(DWORD*)(MAIN_SCREEN_STATE) != 5)
	{
		return;
	}

	if(this->m_CursorX < lpMouse->pt.x)
	{
		if((*this->m_Address.RotX) > 309.0f)
		{
			SetFloat((DWORD)this->m_Address.RotX,-45.0f);
		}
		else
		{
			SetFloat((DWORD)this->m_Address.RotX,((*this->m_Address.RotX) + 6.0f));
		}
	}
	
	if(this->m_CursorX > lpMouse->pt.x)
	{
		if((*this->m_Address.RotX) < -417.0f)
		{
			SetFloat((DWORD)this->m_Address.RotX,-45.0f);
		}
		else
		{
			SetFloat((DWORD)this->m_Address.RotX,((*this->m_Address.RotX)-6.0f));
		}
	}

	if(this->m_CursorY < lpMouse->pt.y)
	{
		if((*this->m_Address.RotY) < -45.0f)
		{
			SetFloat((DWORD)this->m_Address.RotY,((*this->m_Address.RotY)+2.420f));
			SetDouble((DWORD)this->m_Address.PosZ,((*this->m_Address.PosZ)-44.0f));
		}
	}

	if(this->m_CursorY > lpMouse->pt.y)
	{
		if((*this->m_Address.RotY) > -90.0f)
		{
			SetFloat((DWORD)this->m_Address.RotY,((*this->m_Address.RotY)-2.420f));
			SetDouble((DWORD)this->m_Address.PosZ,((*this->m_Address.PosZ)+44.0f));
		}
	}

	this->m_CursorX = lpMouse->pt.x;

	this->m_CursorY = lpMouse->pt.y;

	this->SetCurrentValue();
}

void CCamera::SetCurrentValue() // OK
{
	SetDouble((DWORD)this->m_Address.ClipX[0],(4190.0f+(abs(((*this->m_Address.PosZ)-150.0f))*3.0f)));

	SetDouble((DWORD)this->m_Address.ClipX[1],(4190.0f+(abs(((*this->m_Address.PosZ)-150.0f))*3.0f)));

	SetFloat((DWORD)this->m_Address.ClipY[0],(5400.0f+(((float)abs(((*this->m_Address.PosZ)-150.0f)))*3.0f)));

	SetFloat((DWORD)this->m_Address.ClipY[1],(5400.0f+(((float)abs(((*this->m_Address.PosZ)-150.0f)))*3.0f)));

	SetFloat((DWORD)this->m_Address.ClipGL,(2100.0f+(((float)abs(((*this->m_Address.PosZ)-150.0f)))*3.0f)));
}

void CCamera::SetDefaultValue() // OK
{
	if(this->m_Default.IsLoad != 0)
	{
		SetFloat((DWORD)this->m_Address.Zoom,this->m_Default.Zoom);

		SetFloat((DWORD)this->m_Address.RotX,this->m_Default.RotX);

		SetFloat((DWORD)this->m_Address.RotY,this->m_Default.RotY);

		SetDouble((DWORD)this->m_Address.PosZ,this->m_Default.PosZ);

		SetDouble((DWORD)this->m_Address.ClipX[0],this->m_Default.ClipX[0]);

		SetDouble((DWORD)this->m_Address.ClipX[1],this->m_Default.ClipX[1]);

		SetFloat((DWORD)this->m_Address.ClipY[0],this->m_Default.ClipY[0]);

		SetFloat((DWORD)this->m_Address.ClipY[1],this->m_Default.ClipY[1]);

		SetFloat((DWORD)this->m_Address.ClipGL,this->m_Default.ClipGL);
	}
}

void CCamera::RotateDmg(float& X, float& Y, float D)
{
	const float Rad = 0.01745329f;
	float sinTh = sin(Rad * (*(float*)0x87933D8));
	float cosTh = cos(Rad * (*(float*)0x87933D8));

	X += D / 0.7071067f * cosTh / 2;
	Y -= D / 0.7071067f * sinTh / 2;
}

void __declspec(naked) CCamera::RotateFix()
{
	static DWORD jmpBack = 0x0063752D;

	_asm
	{
		Lea Eax, [Ebp - 0x38];
		Lea Ecx, [Ebp - 0x3C];
		Push Dword Ptr[Ebp + 0x18];
		Push Eax;
		Push Ecx;
		Call RotateDmg;
		Add Esp, 0xC;
		jmp[jmpBack];
	}
}
#endif