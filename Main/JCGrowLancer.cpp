#include "StdAfx.h"
#include "JCGrowLancer.h"
#include "Import.h"
#include "Util.h"
#include "InfoLog.h"
#include "Minimap.h"
#include "Defines.h"
#include "ZzzCharacter.h"
#include "Object.h"
#include "MultiSelect.h"

JCGrowLancer JCGetModelPJ;

JCGrowLancer::JCGrowLancer( )
{
}

JCGrowLancer::~JCGrowLancer( )
{
}

//----- (00587380) --------------------------------------------------------
char __cdecl CChangeServerClassTypeToClientClassType(unsigned __int8 a1)
{
	if( a1 == 224)
	{
		return ((((signed int)a1 >> 1 ) & 1) << 6) | 32 * (((signed int)a1 >> 2) & 1) | ((signed int)a1 >> 4) | 16 * (((signed int)a1 >> 3) & 1);
	}
	else
	{
		return 16 * (((signed int)a1 >> 3) & 1) | ((signed int)a1 >> 5) | 8 * (((signed int)a1 >> 4) & 1);
	}
}

//----- (00405230) --------------------------------------------------------
int JCGetBaseClass(char a1)
{
	int v2; // [sp+0h] [bp-4h]@1

	v2 = a1 & 7;

	return v2;
}

int MuHelperGL(char a1)
{
	int v2; // [sp+0h] [bp-4h]@1

	v2 = a1 & 7;

	return ( v2 == CLASS_GROWLANCER ) ? CLASS_MAGUMSA : v2;
}

int JCGetGlobalGL(char a1)
{
	int v2; // [sp+0h] [bp-4h]@1

	v2 = a1 & 7;

	if(*(DWORD*)(0xE609E8) == 4)
	{
		return v2;
	}
	else
	{
		return ( v2 == CLASS_GROWLANCER ) ? CLASS_KNIGHT : v2;
	}
}

char JCGetSkinModelIndex(unsigned __int8 a1)
{
	char v2; // [sp+0h] [bp-4h]@1
	char v3; // [sp+2h] [bp-2h]@1
	char v4; // [sp+3h] [bp-1h]@5

	v2 = a1 & 7;
	v3 = ((signed int)a1 >> 4) & 1;
	if ( a1 & 7 && v2 != 1 && v2 != 2 && v2 != 5 )
		v4 = 16 * v3 + v2;
	else
		v4 = 8 * (v3 + (((signed int)a1 >> 3) & 1)) + v2;
	return v4;
}

//----- (0057F020) --------------------------------------------------------
int __cdecl sub_57F020(int a1)
{
	int result; // eax@1
	float RenderSize; // eax@2
	float RenderMonk; // eax@3

	lpViewObj Object = &*(ObjectPreview*)oUserPreviewStruct;

	result = a1;
	if (!*(BYTE*)(a1 + 15))
	{
		if (*(WORD*)(a1 + 268) != 4755
			&& *(WORD*)(a1 + 268) != 4757
			&& *(WORD*)(a1 + 268) != 4818
			&& *(WORD*)(a1 + 268) != 4823
			&& *(WORD*)(a1 + 268) != 4820
			&& *(WORD*)(a1 + 268) != 4825
			&& ((signed int) * (WORD*)(a1 + 268) < 4765 || (signed int) * (WORD*)(a1 + 268) > 4768))
		{
			*(WORD*)(a1 + 232) = -1;
		}
		else
		{
			*(WORD*)(a1 + 232) = (unsigned __int8)JCGetSkinModelIndex(*(BYTE*)(a1 + 19)) + 9389;
		}
		if (*(DWORD*)0xE609E8 == 4 || *(DWORD*)0xE609E8 == 5)
		{
			/*	if (*(DWORD*)0xE609E8 == 5)
				{
					if (Object->InSafeZone)
					{
						RenderSize = 0.40f;
						RenderMonk = 0.60f;
					}
					else
					{
						RenderSize = 0.80f;
						RenderMonk = 1.00f;
					}
				}*/

			if (*(DWORD*)0xE609E8 == 5)
			{
				RenderSize = 0.90f;
				RenderMonk = 1.00f;
			}

			if (*(DWORD*)0xE609E8 == 4)
			{
				RenderSize = (gSelectCharRamdon.RenderSelect.ModelScale > 0) ? ((double)((1.2f / 100) * gSelectCharRamdon.RenderSelect.ModelScale)) : 1.2f;
				RenderMonk = (gSelectCharRamdon.RenderSelect.ModelScale > 0) ? ((double)((1.35f / 100) * gSelectCharRamdon.RenderSelect.ModelScale)) : 1.35f;
			}

			if (*(BYTE*)(a1 + 20))
			{
				result = JCGetBaseClass(*(BYTE*)(a1 + 19));
				switch (result)
				{
				case CLASS_WIZARD:
					result = a1;
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_KNIGHT:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_ELF:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_MAGUMSA:
					result = a1;
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_DARKLORD:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_SUMMONER:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_MONK:
					result = a1;
					*(float*)(a1 + 872) = RenderMonk;
					break;
				default:
					*(float*)(a1 + 872) = RenderSize;
					break;
				}
			}
			else
			{
				result = JCGetBaseClass(*(BYTE*)(a1 + 19));
				switch (result)
				{
				case CLASS_WIZARD:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_KNIGHT:
					result = a1;
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_ELF:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_MAGUMSA:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_DARKLORD:
					result = a1;
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_SUMMONER:
					*(float*)(a1 + 872) = RenderSize;
					break;
				case CLASS_MONK:
					*(float*)(a1 + 872) = RenderMonk;
					break;
				default:
					*(float*)(a1 + 872) = RenderSize;
					break;
				}
			}
		}
		else if (*(BYTE*)(a1 + 20))
		{
			result = JCGetBaseClass(*(BYTE*)(a1 + 19));
			switch (result)
			{
			case CLASS_WIZARD:
				*(float*)(a1 + 872) = 0.93000001;
				break;
			case CLASS_KNIGHT:
				*(float*)(a1 + 872) = 0.93000001;
				break;
			case CLASS_ELF:
				result = a1;
				*(float*)(a1 + 872) = 0.86000001;
				break;
			case CLASS_MAGUMSA:
				*(float*)(a1 + 872) = 0.94999999;
				break;
			case CLASS_DARKLORD:
				*(float*)(a1 + 872) = 0.92000002;
				break;
			case CLASS_SUMMONER:
				result = a1;
				*(float*)(a1 + 872) = 0.89999998;
				break;
			case CLASS_MONK:
				*(float*)(a1 + 872) = 1.03;
				break;
			default:
				*(float*)(a1 + 872) = 0.94999999;
				break;
			}
		}
		else
		{
			result = JCGetBaseClass(*(BYTE*)(a1 + 19));
			switch (result)
			{
			case CLASS_WIZARD:
				result = a1;
				*(float*)(a1 + 872) = 0.89999998;
				break;
			case CLASS_KNIGHT:
				*(float*)(a1 + 872) = 0.89999998;
				break;
			case CLASS_ELF:
				*(float*)(a1 + 872) = 0.88;
				break;
			case CLASS_MAGUMSA:
				result = a1;
				*(float*)(a1 + 872) = 0.94999999;
				break;
			case CLASS_DARKLORD:
				*(float*)(a1 + 872) = 0.92000002;
				break;
			case CLASS_SUMMONER:
				*(float*)(a1 + 872) = 0.89999998;
				break;
			case CLASS_MONK:
				result = a1;
				*(float*)(a1 + 872) = 1.03;
				break;
			default:
				*(float*)(a1 + 872) = 0.93000001;
				break;
			}
		}
	}
	return result;
}
// E609E8: using guessed type int dword_E609E8;

//----- (005875C0) --------------------------------------------------------
char CGetCharacterClass(unsigned __int8 a1)
{
	char v2; // [sp+4h] [bp-4h]@1
	char v3; // [sp+6h] [bp-2h]@1
	char v4; // [sp+7h] [bp-1h]@1

	v2 = 0;
	v3 = ((signed int)a1 >> 3) & 1;
	v4 = ((signed int)a1 >> 4) & 1;
	switch ( a1 & 7 )
	{
	case 0:
		if ( v4 )
		{
			v2 = 11;
		}
		else if ( v3 )
		{
			v2 = 7;
		}
		else
		{
			v2 = 0;
		}
		break;
	case 1:
		if ( v4 )
		{
			v2 = 12;
		}
		else if ( v3 )
		{
			v2 = 8;
		}
		else
		{
			v2 = 1;
		}
		break;
	case 2:
		if ( v4 )
		{
			v2 = 13;
		}
		else if ( v3 )
		{
			v2 = 9;
		}
		else
		{
			v2 = 2;
		}
		break;
	case 3:
		if ( v4 )
			v2 = 14;
		else
			v2 = 3;
		break;
	case 4:
		if ( v4 )
			v2 = 15;
		else
			v2 = 4;
		break;
	case 5:
		if ( v4 )
		{
			v2 = 16;
		}
		else if ( v3 )
		{
			v2 = 10;
		}
		else
		{
			v2 = 5;
		}
		break;
	case 6:
		if ( v4 )
			v2 = 17;
		else
			v2 = 6;
		break;
	case 7:
		if ( v4 )
		{
			v2 = 22;
		}
		else if ( v3 )
		{
			v2 = 21;
		}
		else
		{
			v2 = 20;
		}
		break;

	default:
		return v2;
	}
	return v2;
}

//----- (00587620) --------------------------------------------------------
int JCGetClassname (unsigned __int8 a4)
{
	int result; // eax@2
	char v5; // [sp+1h] [bp-1h]@1

	v5 = CGetCharacterClass( a4 );

	if ( v5 )
	{
		switch ( v5 )
		{
			case 1: //-- Dark Knight
				result = (int)pGetTextLine(pTextLineThis, 21);
				break;
			case 2: //-- Elf
				result = (int)pGetTextLine(pTextLineThis, 22);
				break;
			case 3: //-- Magic Gladiator
				result = (int)pGetTextLine(pTextLineThis, 23);
				break;
			case 4: //-- Dark Lord
				result = (int)pGetTextLine(pTextLineThis, 24);
				break;
			case 5: //-- Summoner
				result = (int)pGetTextLine(pTextLineThis, 1687);
				break;
			case 6: //-- Rage Fighter
				result = (int)pGetTextLine(pTextLineThis, 3150);
				break;
			case 7: //-- Soul Master
				result = (int)pGetTextLine(pTextLineThis, 25);
				break;
			case 8: //-- Blade Knight
				result = (int)pGetTextLine(pTextLineThis, 26);
				break;
			case 9: //-- Muse Elf
				result = (int)pGetTextLine(pTextLineThis, 27);
				break;
			case 10: //-- Bloody Summoner
				result = (int)pGetTextLine(pTextLineThis, 1688);
				break;
			case 11: //-- Grand Master
				result = (int)pGetTextLine(pTextLineThis, 1669);
				break;
			case 12: //-- Blade Master
				result = (int)pGetTextLine(pTextLineThis, 1668);
				break;
			case 13: //-- High Elf
				result = (int)pGetTextLine(pTextLineThis, 1670);
				break;
			case 14: //-- Dual Master
				result = (int)pGetTextLine(pTextLineThis, 1671);
				break;
			case 15: //-- Lord Emperor
				result = (int)pGetTextLine(pTextLineThis, 1672);
				break;
			case 16: //-- Dimension Master
				result = (int)pGetTextLine(pTextLineThis, 1689);
				break;
			case 17: //-- Fist Master
				result = (int)pGetTextLine(pTextLineThis, 3151);
				break;
			case 20: //-- Grow Lancer
				result = (int)pGetTextLine(pTextLineThis, 3175);
				break;
			case 21: //-- Mirage Lancer
				result = (int)pGetTextLine(pTextLineThis, 3176);
				break;
			case 22: //-- Shining Lancer
				result = (int)pGetTextLine(pTextLineThis, 3176);
				break;
			default: //-- Error Code :
				result = (int)pGetTextLine(pTextLineThis, 2305);
			break;
		}
	}
	else
	{
		//-- Dark Wizard
		result = (int)pGetTextLine(pTextLineThis, 20);
	}
	return result;
}

void JCGrowLancer::Load( )
{
	//-- Fix MuHelper
/*	SetCompleteHook(0xE8, 0x007F80E1, &MuHelperGL);
	//-- Usar Skill
	SetCompleteHook(0xE9, 0x00405230, &JCGetGlobalGL);
	//-- Fix name pj
	SetCompleteHook(0xE9, 0x00587620, &JCGetClassname);
	SetCompleteHook(0xE9, 0x00587500, &JCGetSkinModelIndex);*/

	//-- Fix Scale
	SetCompleteHook(0xE8, 0x0057F8E5, &sub_57F020);
	SetCompleteHook(0xE8, 0x0057FB05, &sub_57F020);
	SetCompleteHook(0xE8, 0x00580AB9, &sub_57F020);
	SetCompleteHook(0xE8, 0x0058309D, &sub_57F020);
	SetCompleteHook(0xE8, 0x00584358, &sub_57F020);
	SetCompleteHook(0xE8, 0x00584ABB, &sub_57F020);
	SetCompleteHook(0xE8, 0x00584BE0, &sub_57F020);
	SetCompleteHook(0xE8, 0x00585234, &sub_57F020);
	SetCompleteHook(0xE8, 0x00585394, &sub_57F020);
	SetCompleteHook(0xE8, 0x00585A9C, &sub_57F020);
	SetCompleteHook(0xE8, 0x00587007, &sub_57F020);
	SetCompleteHook(0xE8, 0x00641981, &sub_57F020);
	SetCompleteHook(0xE8, 0x009090DB, &sub_57F020);
	SetCompleteHook(0xE8, 0x009118C9, &sub_57F020);
}