#include "stdafx.h"
#include "CSceneS2.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Protect.h"
#include "Import.h"
#include "Config.h"
//#include "CScene.h"

void LoginScreenS2(int a1, DWORD* a2)
{
	if (pMapNumber == 55)
	{
		glColor3f(1.0, 1.0, 1.0);
		BeginBitmap();
		pDrawImage(500021, 0.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		pDrawImage(500022, 320.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		EndOpengl();
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 330000.0;
		*(float*)0x87933D0 = -96.5;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -36.0;
		*(float*)0x87933DC = 12778.0;
		*(float*)0x87933E0 = 12678.0;
		*(float*)0x87933E4 = 579.0;
		*(float*)0xE61E40 = 35.0;
	}
}

void LogoMUmS2()
{
	if (SceneFlag == 2)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if (*(float*)0xE8CB18 > 10.0) *(float*)0xE8CB18 = 10.0;
		EnableAlphaBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		RenderBitmap(531019, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EnableAlphaTest(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		RenderBitmap(531018, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
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

void sub_4D5EC0S2()
{
	LogoMUmS2();
	sub_4D5EC0R();
}

__declspec(naked) void SelectCharacterMap()
{
	static DWORD SelectCharacterMap_buff = 0x004D6C35;
	_asm
	{
		MOV DWORD PTR DS : [0xE61E18] , 0x36 //0x4A
		MOV EAX, DWORD PTR DS : [0xE61E18]
		jmp[SelectCharacterMap_buff]
	}
}

__declspec(naked) void SelectCharacterCord()
{

	static float D27B98 = -84.50000f;
	static float D25708 = -45.00000f;
	static float D27B94 = 8898.929687f;
	static float D27B90 = 18513.10938f;
	static float D27B8C = 550.5000f;
	static float D27B88 = -48.50000;
	static DWORD SelectCharacterCord_buff = 0x004D8B57;
	static DWORD SCCordJMP = 0x004D8B42;
	_asm
	{
		//CMP DWORD PTR DS:[0xE609E8],0x4
		//JNZ SCCordJNZ
		FLD DWORD PTR DS : [D27B98]
		FSTP DWORD PTR DS : [0x87933D0]
		FLDZ
		FSTP DWORD PTR DS : [0x87933D4]
		FLD DWORD PTR DS : [D25708]
		FSTP DWORD PTR DS : [0x87933D8]
		FLD DWORD PTR DS : [D27B94]
		FSTP DWORD PTR DS : [0x87933DC]
		FLD DWORD PTR DS : [D27B90]
		FSTP DWORD PTR DS : [0x87933E0]
		FLD DWORD PTR DS : [D27B8C]
		FSTP DWORD PTR DS : [0x87933E4]
		JMP SCCordJMP
		FLD DWORD PTR DS : [D27B88]
		FSTP DWORD PTR DS : [0x87933D0]
		FLD DWORD PTR DS : [0x87933D0]
		FADD DWORD PTR DS : [0x8787D48]
		FSTP DWORD PTR DS : [0x87933D0]
		MOV EDX, DWORD PTR SS : [EBP - 0x68]
		jmp[SelectCharacterCord_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ1()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
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

__declspec(naked) void SelectCharacterCordPJ21()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
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

__declspec(naked) void SelectCharacterCordPJ2()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
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

__declspec(naked) void SelectCharacterCordPJ22()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
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

__declspec(naked) void SelectCharacterCordPJ3()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
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

__declspec(naked) void SelectCharacterCordPJ23()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
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

__declspec(naked) void SelectCharacterCordPJ4()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
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

__declspec(naked) void SelectCharacterCordPJ24()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
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

__declspec(naked) void SelectCharacterCordPJ5()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
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

__declspec(naked) void SelectCharacterCordPJ25()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
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

void CSceneS2()
{
	SetCompleteHook(0xE8, 0x004D7EB1, &sub_4D5EC0S2);
	SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenS2);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenS2);//Select Server
	SetDword((LPVOID)0x004D75F0, 55);

	SetRange((LPVOID)0x004D6C26, 5, ASM::NOP);
	SetOp((LPVOID)0x004D6C26, (LPVOID)SelectCharacterMap, ASM::JMP);

	SetRange((LPVOID)0x004D8AF0, 5, ASM::NOP);//0x004D8AE7
	SetOp((LPVOID)0x004D8AF0, (LPVOID)SelectCharacterCord, ASM::JMP);

	SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1, ASM::JMP);
	SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21, ASM::JMP);

	SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2, ASM::JMP);
	SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22, ASM::JMP);

	SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3, ASM::JMP);
	SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23, ASM::JMP);

	SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4, ASM::JMP);
	SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24, ASM::JMP);

	SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5, ASM::JMP);
	SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25, ASM::JMP);
	SetByte((LPVOID)0x0057F0FC, 0xE9);
	SetByte((LPVOID)0x0057F0FD, 0x4A);
	SetByte((LPVOID)0x0057F0FE, 0x01);
	SetByte((LPVOID)0x0057F0FF, 0x00);
	SetByte((LPVOID)0x0057F100, 0x00);
	SetByte((LPVOID)0x0057F101, 0x90);
}
