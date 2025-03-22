#include "stdafx.h"
#include "SCharacterBetell.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "Util.h"
#include "Config.h"
#include "Interface.h"

#include "zzzmathlib.h"

void LoginScreen2(int a1, DWORD* a2)
{
	if (SceneFlag == 4) //Select Character
	{

		//SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		//SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 20000.0;
		*(float*)0x87933D0 = -84.5;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -80.0;
		*(float*)0x87933DC = 15215.08887;
		*(float*)0x87933E0 = 12186.53613;
		*(float*)0x87933E4 = 495.500061;
		*(float*)0xE61E40 = 35.0;

	}
	if (World == 60) //Select Server
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 33000.0;
		*(float*)0x87933D0 = -84.0;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -45.0;
		*(float*)0x87933DC = 24475.79687;
		*(float*)0x87933E0 = 7581.581055;
		*(float*)0x87933E4 = 1834.539917;
		*(float*)0xE61E40 = 35.0;
	}
}

void RenderSSCObjectVisual2(int a1, int a2)
{
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;

	//Select Server
	if (World == 60)
	{
		switch (*(DWORD*)(a1 + 48))
		{
		case 1:
		{
			BeginRender(1.0);
			*(DWORD*)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 4000;
			float v551 = ((int)(v552 - timeGetTime() * 0.75f) % 4001) * 0.0002500000118743628;
			RenderMesh(a2,
				0,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				v551,
				-1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}
		break;

		case 5:
		{
			BeginRender(1.0);
			*(BYTE*)(a2 + 136) = 0;
			*(float*)(a2 + 72) = 0.80000001;
			*(float*)(a2 + 76) = 0.69999999;
			*(float*)(a2 + 80) = 0.30000001;
			RenderMesh(a2,
				0,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				23,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				23,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				24,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				24,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				25,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				25,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				26,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				26,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				27,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				27,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			RenderMesh(a2,
				28,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				-1);
			RenderMesh(a2,
				28,
				68,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				*(float*)(a1 + 108),
				32042);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
			float v409 = (double)(rand() % 10) / 20.0 + 1.399999976158142;
			float v19 = v409 - 0.300000011920929;
			Vector(0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, Joint(37), WorldPos, Bone, 0);
			Vector(1.0, 0.30000001, 0.0, Color);
			CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
			CreateSprite(32114, Bone, v19, Color, a1, 0.0, 0);
			v409 = (double)(rand() % 10) / 20.0 + 1.0;
			float v20 = v409 + 0.300000011920929;
			CreateSprite(32002, Bone, v20, Color, a1, 0.0, 0);
			v409 = (double)(rand() % 8) / 20.0 + 0.4000000059604645;
			CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
			float v21 = v409 - 0.2000000029802322;
			CreateSprite(32114, Bone, v21, Color, a1, 0.0, 0);
		}
		break;

		case 38:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 6))
			{
				Vector(0.020, 0.020, 0.050, Color);
				CreateParticle(32146, a1 + 252, a1 + 264, Color, 20, *(float*)(a1 + 96), a2);
			}
		}
		break;

		case 54:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 2))
			{
				Vector(0.22, 0.15000001, 0.15000001, Color);
				CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float*)(a1 + 96), 0);
			}
		}
		break;
		}
	}

	//Select Character
	if (World == 95)
	{
		switch (*(DWORD*)(a1 + 48))
		{
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		{
			*(DWORD*)(a1 + 60) = -2;
		}
		break;

		case 24:
		case 25:
		case 26:
		{
			BeginRender(1.0);
			*(DWORD*)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 2000;
			float v551 = ((int)(v552 - timeGetTime()) % 2001) * 0.0005000000237487257;
			RenderMesh(a2,
				0,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				v551,
				-1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}
		break;

		case 31:
		{
			Vector(0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, (int)&BoneTransform, WorldPos, Bone, 0);
			Vector(0.98000002, 0.94, 0.94, Color);
			CreateSprite(32604, Bone, 1.0, Color, a1, 0.0, 0);
			Vector(0.77999997, 0.44, 0.75, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x30, WorldPos, Bone, 0);
			CreateSprite(32604, Bone, 1.2, Color, a1, 0.0, 0);
			Vector(0.57999998, 0.07, 0.56, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x60, WorldPos, Bone, 0);
			CreateSprite(32604, Bone, 0.80000001, Color, a1, 0.0, 0);
		}
		break;

		case 38:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 6))
			{
				Vector(0.02, 0.02, 0.050000001, Color);
				CreateParticle(32146, a1 + 252, a1 + 264, Color, 20, *(float*)(a1 + 96), 0);
			}
		}
		break;

		case 39:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 100))
			{
				Vector(0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector(0.02, 0.02, 0.050000001, Color);
				CreateEffect2(700, Bone, a1 + 264, Color, 0, a1, -1, 0, 0, 0, 0.0, -1);
			}
		}
		break;

		case 40:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 200))
			{
				Vector(0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector(0.02, 0.02, 0.050000001, Color);
				CreateEffect2(701, Bone, a1 + 264, Color, 1, a1, -1, 0, 0, 0, 0.0, -1);
			}
		}
		break;

		case 54:
		{
			*(DWORD*)(a1 + 60) = -2;
			if (!(rand() % 2))
			{
				Vector(1.0, 1.0, 1.0, Color);
				CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float*)(a1 + 96), 0);
			}
		}
		break;

		case 55:
		{
			*(DWORD*)(a1 + 60) = -2;
			Vector(1.0, 1.0, 1.0, Color);
			CreateParticle(32289, a1 + 252, a1 + 264, Color, 14, *(float*)(a1 + 96) + *(float*)(a1 + 96), 0);
		}
		break;

		case 56:
		{
			*(DWORD*)(a1 + 60) = -2;
			Vector(1.0, 1.0, 1.0, Color);
			if (!(rand() % 3))
			{
				CreateParticle(32288, a1 + 252, a1 + 264, Color, 2, *(float*)(a1 + 96), 0);
			}
		}
		break;

		case 73:
		{
			Vector(0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, Joint(1), WorldPos, Bone, 0);
			Vector(0.5, 1.0, 0.98000002, Color);
			float v51 = ((int)timeGetTime() % 3600) * 0.1000000014901161;
			float v32 = -v51;
			float v50 = ((int)timeGetTime() % 30) / 90.0;
			float v33 = v50 + 1.200000047683716;
			CreateSprite(32114, Bone, v33, Color, a1, v32, 0);
			CreateSprite(32779, Bone, 0.20, Color, a1, 0.0, 0);
			if (!((int)timeGetTime() % 3))
			{
				Vector(1.0, 1.0, 1.0, Color);
				v50 = *(float*)(a1 + 96) * 1.799999952316284;
				float v34 = v50;
				CreateParticle2(32284, Bone, a1 + 264, Color, 0, v34, 0);
			}
		}
		break;

		case 80:
		{
			*(DWORD*)(a1 + 60) = -2;
			Vector(0.98000002, 0.89999998, 0.89999998, Color);
			if (!(rand() % 8))
			{
				CreateParticle(32101, a1 + 252, a1 + 264, Color, 69, *(float*)(a1 + 96), 0);
			}
		}
		break;

		}
	}
	//
	RenderCryingWolf2ndObjectVisual(a1, a2);
}

__declspec(naked) void SwitchCharacterView2()
{
	static float View = 33000.0f;
	static DWORD SwitchCharacter_buff = 0x004D87D4;
	_asm
	{
		FLD DWORD PTR DS : [View]
		FSTP DWORD PTR DS : [View]
		jmp[SwitchCharacter_buff]
	}
}

__declspec(naked) void GameProcessView2()
{
	static float View = 0.0f;
	static DWORD GameProcess_buff = 0x004D8808;
	_asm
	{
		FLD DWORD PTR DS : [View]
		FSTP DWORD PTR DS : [View]
		jmp[GameProcess_buff]
	}
}

DWORD PlayerID2_Offset = 0x005DB532;
void __declspec(naked) PlayerID2()
{
	_asm
	{
		CMP DWORD PTR DS : [0xE609E8] , 0x2
		je ReturnLoad
		CMP DWORD PTR DS : [0xE609E8] , 0x4
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp PlayerID2_Offset
	}
}

void LogoMUm2()
{
	int JCWinWidth;

	JCWinWidth = pWinWidth / pWinHeightReal / 2 + 125;
	if (SceneFlag == 2)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if (*(float*)0xE8CB18 > 10.0)
			*(float*)0xE8CB18 = 10.0;
		EnableAlphaBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		RenderBitmap(531019, JCWinWidth - 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EnableAlphaTest(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		RenderBitmap(531018, JCWinWidth - 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		//
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
		
		
		//-> Custom Server News
		if (gProtect.m_MainInfo.ServerNews == 1)
		{
			int PosX;
			PosX = 470;



			pDrawGUI(0x9969, (float)455, (float)70 - 40, 173, 406);

			gInterface.DrawFormat(Color4f(Config.ColorText0_R, Config.ColorText0_G, Config.ColorText0_B, 255), 510, 47, 250, 1, Config.NewsText0);
			gInterface.DrawFormat(Color4f(Config.ColorText1_R, Config.ColorText1_G, Config.ColorText1_B, 255), 480, 77, 250, 1, Config.NewsText1);
			gInterface.DrawFormat(Color4f(Config.ColorText2_R, Config.ColorText2_G, Config.ColorText2_B, 255), 480, 87, 250, 1, Config.NewsText2);
			gInterface.DrawFormat(Color4f(Config.ColorText3_R, Config.ColorText3_G, Config.ColorText3_B, 255), 480, 97, 250, 1, Config.NewsText3);
			gInterface.DrawFormat(Color4f(Config.ColorText4_R, Config.ColorText4_G, Config.ColorText4_B, 255), 480, 107, 250, 1, Config.NewsText4);
			gInterface.DrawFormat(Color4f(Config.ColorText5_R, Config.ColorText5_G, Config.ColorText5_B, 255), 480, 117, 250, 1, Config.NewsText5);
			gInterface.DrawFormat(Color4f(Config.ColorText6_R, Config.ColorText6_G, Config.ColorText6_B, 255), 480, 127, 250, 1, Config.NewsText6);
			gInterface.DrawFormat(Color4f(Config.ColorText7_R, Config.ColorText7_G, Config.ColorText7_B, 255), 480, 137, 250, 1, Config.NewsText7);
			gInterface.DrawFormat(Color4f(Config.ColorText8_R, Config.ColorText8_G, Config.ColorText8_B, 255), 480, 147, 250, 1, Config.NewsText8);
			gInterface.DrawFormat(Color4f(Config.ColorText9_R, Config.ColorText9_G, Config.ColorText9_B, 255), 480, 157, 250, 1, Config.NewsText9);
			gInterface.DrawFormat(Color4f(Config.ColorText10_R, Config.ColorText10_G, Config.ColorText10_B, 255), 480, 167, 250, 1, Config.NewsText10);
			gInterface.DrawFormat(Color4f(Config.ColorText11_R, Config.ColorText11_G, Config.ColorText11_B, 255), 480, 177, 250, 1, Config.NewsText11);
			gInterface.DrawFormat(Color4f(Config.ColorText12_R, Config.ColorText12_G, Config.ColorText12_B, 255), 480, 187, 250, 1, Config.NewsText12);
			gInterface.DrawFormat(Color4f(Config.ColorText13_R, Config.ColorText13_G, Config.ColorText13_B, 255), 480, 197, 250, 1, Config.NewsText13);
			gInterface.DrawFormat(Color4f(Config.ColorText14_R, Config.ColorText14_G, Config.ColorText14_B, 255), 480, 207, 250, 1, Config.NewsText14);
			gInterface.DrawFormat(Color4f(Config.ColorText15_R, Config.ColorText15_G, Config.ColorText15_B, 255), 480, 217, 250, 1, Config.NewsText15);
			gInterface.DrawFormat(Color4f(Config.ColorText16_R, Config.ColorText16_G, Config.ColorText16_B, 255), 480, 227, 250, 1, Config.NewsText16);
			gInterface.DrawFormat(Color4f(Config.ColorText17_R, Config.ColorText17_G, Config.ColorText17_B, 255), 480, 237, 250, 1, Config.NewsText17);
			gInterface.DrawFormat(Color4f(Config.ColorText18_R, Config.ColorText18_G, Config.ColorText18_B, 255), 480, 247, 250, 1, Config.NewsText18);
			gInterface.DrawFormat(Color4f(Config.ColorText19_R, Config.ColorText19_G, Config.ColorText19_B, 255), 480, 257, 250, 1, Config.NewsText19);
			gInterface.DrawFormat(Color4f(Config.ColorText20_R, Config.ColorText20_G, Config.ColorText20_B, 255), 480, 267, 250, 1, Config.NewsText20);
			gInterface.DrawFormat(Color4f(Config.ColorText21_R, Config.ColorText21_G, Config.ColorText21_B, 255), 480, 277, 250, 1, Config.NewsText21);
			gInterface.DrawFormat(Color4f(Config.ColorText22_R, Config.ColorText22_G, Config.ColorText22_B, 255), 480, 287, 250, 1, Config.NewsText22);
			gInterface.DrawFormat(Color4f(Config.ColorText23_R, Config.ColorText23_G, Config.ColorText23_B, 255), 480, 297, 250, 1, Config.NewsText23);
			gInterface.DrawFormat(Color4f(Config.ColorText24_R, Config.ColorText24_G, Config.ColorText24_B, 255), 480, 307, 250, 1, Config.NewsText24);
			gInterface.DrawFormat(Color4f(Config.ColorText25_R, Config.ColorText25_G, Config.ColorText25_B, 255), 480, 317, 250, 1, Config.NewsText25);
			gInterface.DrawFormat(Color4f(Config.ColorText26_R, Config.ColorText26_G, Config.ColorText26_B, 255), 480, 327, 250, 1, Config.NewsText26);
			gInterface.DrawFormat(Color4f(Config.ColorText27_R, Config.ColorText27_G, Config.ColorText27_B, 255), 480, 337, 250, 1, Config.NewsText27);
			gInterface.DrawFormat(Color4f(Config.ColorText28_R, Config.ColorText28_G, Config.ColorText28_B, 255), 480, 347, 250, 1, Config.NewsText28);
			gInterface.DrawFormat(Color4f(Config.ColorText29_R, Config.ColorText29_G, Config.ColorText29_B, 255), 480, 357, 250, 1, Config.NewsText29);
			gInterface.DrawFormat(Color4f(Config.ColorText30_R, Config.ColorText30_G, Config.ColorText30_B, 255), 480, 367, 250, 1, Config.NewsText30);
			gInterface.DrawFormat(Color4f(Config.ColorText31_R, Config.ColorText31_G, Config.ColorText31_B, 255), 480, 377, 250, 1, Config.NewsText31);
			gInterface.DrawFormat(Color4f(Config.ColorText32_R, Config.ColorText32_G, Config.ColorText32_B, 255), 480, 387, 250, 1, Config.NewsText32);
			gInterface.DrawFormat(Color4f(Config.ColorText33_R, Config.ColorText33_G, Config.ColorText33_B, 255), 480, 397, 250, 1, Config.NewsText33);
			gInterface.DrawFormat(Color4f(Config.ColorText34_R, Config.ColorText34_G, Config.ColorText34_B, 255), (MAX_WIN_WIDTH / 2) - 74, 459, 150, 3, Config.NewsText34);
			gInterface.DrawFormat(Color4f(Config.ColorText35_R, Config.ColorText35_G, Config.ColorText35_B, 255), (MAX_WIN_WIDTH / 2) - 74, 469, 150, 3, Config.NewsText35);
		}
	}
}

void RenderInfomation2(int a1)
{
	LogoMUm2();
	RenderInfomationR();
}
__declspec(naked) void SelectCharacterCordPJ31SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
		FLD DWORD PTR DS : [D41DCC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DC8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D27AE0]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ30SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
		FLD DWORD PTR DS : [D41DCC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DC8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D27AE0]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ9SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
		FLD DWORD PTR DS : [D41DC4]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DC0]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D254C0]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ29SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
		FLD DWORD PTR DS : [D41DC4]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DC0]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D254C0]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ8SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
		FLD DWORD PTR DS : [D41DBC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DB8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D2B954]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ28SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
		FLD DWORD PTR DS : [D41DBC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DB8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D2B954]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ11SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
		FLD DWORD PTR DS : [D41DB4]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DB0]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D2577C]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ27SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
		FLD DWORD PTR DS : [D41DB4]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DB0]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D2577C]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ6SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
		FLD DWORD PTR DS : [D41DAC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DA8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D27BFC]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ26SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
		FLD DWORD PTR DS : [D41DAC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DA8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D27BFC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ5_buff]
	}
}

//selec char size solo 5 personajes
/*
__declspec(naked) void SelectCharacterSize1()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F165;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[ECX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize2()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F154;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EAX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize3()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F176;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EDX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize4()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F143;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EDX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize5()
{

	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F187;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EAX+0x368]
		JMP [Bufferx]

	}
}


__declspec(naked) void SelectCharacterPetSize()
{
	static float D27AF0 = 1.7f;
	static DWORD jmpBack = 0x0050387C;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0];
		FSTP DWORD PTR DS:[Eax + 0x60];
		JMP[jmpBack];
	}
}*/



void SCharacterBetell()
{
	SetDword((LPVOID)0x004D75F0, 60);//Select Server
	SetDword((LPVOID)0x004D6C2C, 95);//Select Character

	SetCompleteHook(0xE8, 0x004D76FB, &LoginScreen2);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &LoginScreen2);//Select Server
	SetCompleteHook(0xE8, 0x004D712A, &LoginScreen2);//Select Character

	SetDword((PVOID)(0x004D7A0E), 480);//Select Server
	SetByte((PVOID)(0x004D7A18), 0);//Select Server
	SetDword((PVOID)(0x004D7179), 480);//Select Character
	SetByte((PVOID)(0x004D7183), 0);//Select Character

	SetCompleteHook(0xE8, 0x005EDDA9, &RenderSSCObjectVisual2);

	SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacterView2, ASM::JMP);
	SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcessView2, ASM::JMP);
	SetOp((LPVOID)0x005DB52B, (LPVOID)PlayerID2, ASM::JMP);

	SetCompleteHook(0xE8, 0x004D7EB1, &RenderInfomation2);
	//---------
	SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ31SS, ASM::JMP);
	SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ30SS, ASM::JMP);

	SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ9SS, ASM::JMP);
	SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ29SS, ASM::JMP);

	SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ8SS, ASM::JMP);
	SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ28SS, ASM::JMP);

	SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ8SS, ASM::JMP);
	SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ26SS, ASM::JMP);

	SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ6SS, ASM::JMP);
	SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ26SS, ASM::JMP);

	/* SetOp((LPVOID)0x0057F159, (LPVOID)SelectCharacterSize1, ASM::JMP);
	 SetOp((LPVOID)0x0057F148, (LPVOID)SelectCharacterSize2, ASM::JMP);
	 SetOp((LPVOID)0x0057F16A, (LPVOID)SelectCharacterSize3, ASM::JMP);
	 SetOp((LPVOID)0x0057F137, (LPVOID)SelectCharacterSize4, ASM::JMP);
	 SetOp((LPVOID)0x0057F17B, (LPVOID)SelectCharacterSize5, ASM::JMP);
	 //pets size selechar
	 SetOp((LPVOID)0x00503839, (LPVOID)SelectCharacterPetSize, ASM::JMP);*/
}

