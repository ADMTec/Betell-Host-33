#pragma once
#if(CAMARA==0)
#define ROTATION_SENS	5//5
#define ZOOM_MAX		60//60
#define ZOOM_MIN		15
#define ZOOM_INTER		1
#define CAMERA_DEBUG	0
#define PERCF(x, y)		((float)x / 100.0f * (float)y)
// ----------------------------------------------------------------------------------------------

typedef struct
{
	float* RotX;
	float	Zoom;
	float	RotationY;
	float	RotationZ;
	float	PositionZ;
	double	ClipX;
	float	ClipY;
	double	ClipZ;
	double	ClipX2;
	float	ClipY2;
	float	ClipZ2;
	float	ClipGL;
	//
	float	Z3;
	float	Z6;
	float	Y3;
	float	Y6;
} DefaultData, *lpDefData;

// ----------------------------------------------------------------------------------------------

struct CAMERA_ADDR
{
	float* Zoom;
	float* RotX;
	float* RotY;
	double* PosZ;
	double* ClipX[2];
	float* ClipY[2];
	float* ClipGL;
};


class Camera
{
public:
	Camera();
	~Camera();

	void		Load();
	// ----
	void		Init();
	void		Switch();
	void		Run(MOUSEHOOKSTRUCTEX * Mouse, WPARAM wParam);
	void		Rotate();
	static void RotateDmg(float& X, float& Y, float D);
	static void RotateFix();
	// ----
	bool		IsActive;
	float		ZoomPercent;
	void		Reset();
	bool        getEnabled();
	void        Toggle();
	void        Restore();
	
	// ----
	DefaultData Default;
private:
	BYTE		RotateMode;
	CAMERA_ADDR m_Address;
	bool		InMove;
	int			TempCursorX;
	int			TempCursorY;
	// ----
}; extern Camera gCamera;
// ----------------------------------------------------------------------------------------------
#endif

// Camera.h: interface for the CCamera class.
//
//////////////////////////////////////////////////////////////////////
#if (CAMARA)
#pragma once

struct CAMERA_ZOOM
{
	float MinPercent;
	float MaxPercent;
	float MinLimit;
	float MaxLimit;
	float Precision;
};

struct CAMERA_ADDR
{
	float* Zoom;
	float* RotX;
	float* RotY;
	double* PosZ;
	double* ClipX[2];
	float* ClipY[2];
	float* ClipGL;
};

struct CAMERA_INFO
{
	int IsLoad;
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
	double ClipX[2];
	float ClipY[2];
	float ClipGL;
};

class CCamera
{
public:
	CCamera();
	virtual ~CCamera();
	void Toggle();
	void Restore();
	void SetIsMove(BOOL IsMove);
	void SetCursorX(LONG CursorX2);
	void SetCursorY(LONG CursorY2);
	void Zoom(MOUSEHOOKSTRUCTEX* lpMouse);
	void Move(MOUSEHOOKSTRUCTEX* lpMouse);
	void SetCurrentValue();
	void SetDefaultValue();
	bool getEnabled();
	static void RotateDmg(float& X, float& Y, float D);
	static void RotateFix();
private:
	BOOL m_Enable;
	BOOL m_IsMove;
	LONG m_CursorX;
	LONG m_CursorY;
	CAMERA_ZOOM m_Zoom;
	CAMERA_ADDR m_Address;
	CAMERA_INFO m_Default;
};

extern CCamera gCamera;
#endif