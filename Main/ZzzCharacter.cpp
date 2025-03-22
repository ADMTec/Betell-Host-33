#include "StdAfx.h"
#include "Util.h"
#include "ZzzCharacter.h"
#include "UIControl.h"
#include "SEASON3B.h"
#include "Defines.h"
#include "Extras.h"


ZzzCharacter g_pModelViewChar;

ZzzCharacter::ZzzCharacter(void)
{
}


ZzzCharacter::~ZzzCharacter(void)
{
}

char GetFirstClass(char a1)
{
  return a1 & 0xF;
}

bool IsSecondClass(unsigned __int8 a1)
{
  return (((signed int)a1 >> 4) & 1) != 0;
}

bool IsThirdClass(unsigned __int8 a1)
{
  return (((signed int)a1 >> 5) & 1) != 0;
}

bool IsFourthClass(unsigned __int8 a1)
{
  return (((signed int)a1 >> 6) & 1) != 0;
}

bool isEvo3(BYTE a1)
{
	return GetFirstClass(a1) == 3 || GetFirstClass(a1) == 4 || GetFirstClass(a1) == 6 || GetFirstClass(a1) == 7;
}

void ZzzCharacter::SetExtendObjectModel()
{
	//-- Fix Evolucionar
	SetDword(0x0057F9FA + 3, EQUIP_BODY_ARMOR); //-- Check slot armor
	SetDword(0x0057FA3D + 3, EQUIP_BODY_PANTS); //-- Check slot pants
	SetDword(0x0057FA7F + 3, EQUIP_BODY_GLOVES); //-- Check slot glove
	SetDword(0x0057FAC1 + 3, EQUIP_BODY_BOOTS); //-- Check slot boot
	//-- Fix DL
	SetDword(0x00574DB6 + 2, (MODEL_BODY_ARMOR + CLASS_DARK_LORD)); //-- DL Armor
	SetDword(0x00575AC4 + 1, (MODEL_BODY_ARMOR + CLASS_DARK_LORD)); //-- DL Armor
	SetDword(0x00575D47 + 1, (MODEL_BODY_ARMOR + CLASS_DARK_LORD)); //-- DL Armor
	SetDword(0x00575D47 + 2, (MODEL_BODY_ARMOR + CLASS_DARK_LORD)); //-- DL Armor
	SetDword(0x00575DC5 + 2, (MODEL_BODY_ARMOR + CLASS_DARK_LORD)); //-- DL Armor
	//-- Fix RF
	SetDword(0x00606CBF + 3, (MODEL_BODY_ARMOR  + 16 + CLASS_RAGEFIGHTER)); //-- RF Armor
	SetDword(0x00606CC8 + 3, (MODEL_BODY_PANTS  + 16 + CLASS_RAGEFIGHTER)); //-- RF Pants
	SetDword(0x00606CD1 + 3, (MODEL_BODY_GLOVES + 16 + CLASS_RAGEFIGHTER)); //-- RF Gloves
	SetDword(0x00606CDA + 3, (MODEL_BODY_BOOTS  + 16 + CLASS_RAGEFIGHTER)); //-- RF Boots

	SetDword(0x0048F2CD + 2, MODEL_BODY_HELM);
	SetDword(0x0048F653 + 1, MODEL_BODY_HELM);
	SetDword(0x0048F678 + 2, MODEL_BODY_HELM);
	SetDword(0x0050E3A6 + 3, MODEL_BODY_HELM);
	SetDword(0x0057F0D6 + 2, MODEL_BODY_HELM);
	SetDword(0x0048F2CD + 2, MODEL_BODY_HELM);
	SetDword(0x0057F645 + 2, MODEL_BODY_HELM);
	SetDword(0x0057F9BF + 1, MODEL_BODY_HELM);
	SetDword(0x0057F9C9 + 2, MODEL_BODY_HELM);
	SetDword(0x00580698 + 2, MODEL_BODY_HELM);
	SetDword(0x00586F3F + 1, MODEL_BODY_HELM);
	SetDword(0x0060820C + 3, MODEL_BODY_HELM);
	SetDword(0x00608FBC + 3, MODEL_BODY_HELM);
	SetDword(0x00614F16 + 2, MODEL_BODY_HELM);
	SetDword(0x00614FE2 + 1, MODEL_BODY_HELM + 8); //-- evo2
	SetDword(0x0061508F + 2, MODEL_BODY_HELM + 16); //-- evo3
	SetDword(0x00616C48 + 1, MODEL_BODY_HELM);
	SetDword(0x00641343 + 2, MODEL_BODY_HELM);
	//--
	SetDword(0x0048F318 + 1, MODEL_BODY_ARMOR);
	SetDword(0x0048F6B3 + 1, MODEL_BODY_ARMOR);
	SetDword(0x0057F693 + 2, MODEL_BODY_ARMOR);
	SetDword(0x0057FA01 + 2, MODEL_BODY_ARMOR);
	SetDword(0x0057FA0C + 2, MODEL_BODY_ARMOR);
	SetDword(0x0058070D + 1, MODEL_BODY_ARMOR);
	SetDword(0x00586F5A + 1, MODEL_BODY_ARMOR);
	SetDword(0x00614F39 + 2, MODEL_BODY_ARMOR);
	SetDword(0x00615004 + 2, MODEL_BODY_ARMOR + 8); //-- evo2
	SetDword(0x006150B2 + 1, MODEL_BODY_ARMOR + 16); //-- evo3
	SetDword(0x00616C6A + 2, MODEL_BODY_ARMOR);
	SetDword(0x006413D5 + 2, MODEL_BODY_ARMOR);
	//--
	SetDword(0x0048F362 + 2, MODEL_BODY_PANTS);
	SetDword(0x0048F6ED + 2, MODEL_BODY_PANTS);
	SetDword(0x0057F6E1 + 2, MODEL_BODY_PANTS);
	SetDword(0x0057FA44 + 2, MODEL_BODY_PANTS);
	SetDword(0x0057FA4F + 1, MODEL_BODY_PANTS);
	SetDword(0x00580780 + 2, MODEL_BODY_PANTS);
	SetDword(0x00586F75 + 1, MODEL_BODY_PANTS);
	SetDword(0x00614F5C + 1, MODEL_BODY_PANTS);
	SetDword(0x00615027 + 2, MODEL_BODY_PANTS + 8); //-- evo2
	SetDword(0x006150D4 + 2, MODEL_BODY_PANTS + 16); //-- evo3
	SetDword(0x00616C8D + 2, MODEL_BODY_PANTS);
	SetDword(0x00641467 + 2, MODEL_BODY_PANTS);
	//--
	SetDword(0x0048F3AC + 2, MODEL_BODY_GLOVES);
	SetDword(0x0048F727 + 2, MODEL_BODY_GLOVES);
	SetDword(0x0057F72F + 2, MODEL_BODY_GLOVES);
	SetDword(0x0057FA86 + 1, MODEL_BODY_GLOVES);
	SetDword(0x0057FA90 + 2, MODEL_BODY_GLOVES);
	SetDword(0x005807F7 + 2, MODEL_BODY_GLOVES);
	SetDword(0x00586F90 + 1, MODEL_BODY_GLOVES);
	SetDword(0x00614F7E + 2, MODEL_BODY_GLOVES);
	SetDword(0x0061504A + 1, MODEL_BODY_GLOVES + 8); //-- evo2
	SetDword(0x006150F7 + 2, MODEL_BODY_GLOVES + 16); //-- evo3
	SetDword(0x00616CB0 + 1, MODEL_BODY_GLOVES);
	SetDword(0x006414F9 + 2, MODEL_BODY_GLOVES);
	//--
	SetDword(0x0048F3F4 + 1, MODEL_BODY_BOOTS);
	SetDword(0x0048F762 + 1, MODEL_BODY_BOOTS);
	SetDword(0x0057F77D + 2, MODEL_BODY_BOOTS);
	SetDword(0x0057FAC8 + 2, MODEL_BODY_BOOTS);
	SetDword(0x0057FAD3 + 2, MODEL_BODY_BOOTS);
	SetDword(0x00580869 + 1, MODEL_BODY_BOOTS);
	SetDword(0x00586FAB + 1, MODEL_BODY_BOOTS);
	SetDword(0x00614FA1 + 2, MODEL_BODY_BOOTS);
	SetDword(0x0061506C + 2, MODEL_BODY_BOOTS + 8); //-- evo2
	SetDword(0x0061511A + 1, MODEL_BODY_BOOTS + 16); //-- evo2
	SetDword(0x00616CD2 + 2, MODEL_BODY_BOOTS);
	SetDword(0x0064158B + 2, MODEL_BODY_BOOTS);
}

int MuSkillClass(BYTE a1)
{
	int result;

	result = a1 & 7;

	if(result == CLASS_GROWLANCER )
	{
		result = CLASS_KNIGHT1;
	}
	return result;
}

int MuHelperClass(char a1)
{
	int v2; // [sp+0h] [bp-4h]@1

	v2 = a1 & 7;

	return ( v2 == CLASS_GROWLANCER ) ? CLASS_DARK : v2;
}

void OpenPlayers( )
{
	sub_614E60( );

	int max_class = 8;
	
	for (int i = 0; i < max_class; ++i )
	{
		AccessModel(i + MODEL_BODY_HELM, "Data\\Player\\", "HelmClass", i + 1);
		AccessModel(i + MODEL_BODY_ARMOR, "Data\\Player\\", "ArmorClass", i + 1);
		AccessModel(i + MODEL_BODY_PANTS, "Data\\Player\\", "PantClass", i + 1);
		AccessModel(i + MODEL_BODY_GLOVES, "Data\\Player\\", "GloveClass", i + 1);
		AccessModel(i + MODEL_BODY_BOOTS, "Data\\Player\\", "BootClass", i + 1);
		if (i != 3 && i != 4 && i != 6 && i != 7)
		{
			AccessModel(i + MODEL_BODY_HELM + max_class, "Data\\Player\\", "HelmClass2", i + 1);
			AccessModel(i + MODEL_BODY_ARMOR + max_class, "Data\\Player\\", "ArmorClass2", i + 1);
			AccessModel(i + MODEL_BODY_PANTS + max_class, "Data\\Player\\", "PantClass2", i + 1);
			AccessModel(i + MODEL_BODY_GLOVES + max_class, "Data\\Player\\", "GloveClass2", i + 1);
			AccessModel(i + MODEL_BODY_BOOTS + max_class, "Data\\Player\\", "BootClass2", i + 1);
		}
		AccessModel(i + MODEL_BODY_HELM + (max_class*2), "Data\\Player\\", "HelmClass3", i + 1);
		AccessModel(i + MODEL_BODY_ARMOR + (max_class*2), "Data\\Player\\", "ArmorClass3", i + 1);
		AccessModel(i + MODEL_BODY_PANTS + (max_class*2), "Data\\Player\\", "PantClass3", i + 1);
		AccessModel(i + MODEL_BODY_GLOVES + (max_class*2), "Data\\Player\\", "GloveClass3", i + 1);
		AccessModel(i + MODEL_BODY_BOOTS + (max_class*2), "Data\\Player\\", "BootClass3", i + 1);
	}

	//this->SpeedModelAction(PLAYER_STOP_GROW, 0.23999999);

	//this->SpeedModelAction(PLAYER_STOP_LANCE, 0.30000001);
}

void OpenPlayerTextures( )
{
	sub_616A50( );

	int max_class = 8;
	
	LoadBitmapA("Player\\skin_Class108.jpg", 30516, GL_LINEAR, GL_REPEAT, 1, 0);
	LoadBitmapA("Player\\skin_Class308.jpg", 30517, GL_LINEAR, GL_REPEAT, 1, 0);
	LoadBitmapA("Player\\hair_Class108.tga", 30528, GL_LINEAR, GL_REPEAT, 1, 0); //-- Hair normal
	LoadBitmapA("Player\\hair_Class108.tga", 30529, GL_LINEAR, GL_REPEAT, 1, 0); //-- Hair Evolution
	//--
	LoadBitmapA("Effect\\Shockwave2.jpg", 532028, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Effect\\wratha_00000.jpg", 532029, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Effect\\Burst_00000.jpg", 533030, GL_LINEAR, GL_CLAMP, 1, 0);
	
	AccessModel(512, "Data\\Effect\\", "shiningpeakbody", -1);
	OpenTexture(512, "Effect\\", 0x2901, 0x2600, 1);
	AccessModel(513, "Data\\Effect\\", "magicpina02", -1);
	OpenTexture(513, "Effect\\", 0x2901, 0x2600, 1);
	//--
	/*AccessModel(3322, "Data\\Effect\\", "obsidiana", -1);
	OpenTexture(3322, "Effect\\", 0x2901, 0x2600, 1);*/

	for (int i = 0; i < max_class; ++i )
	{
		OpenTexture(MODEL_BODY_HELM + i, "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_ARMOR + i, "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_PANTS + i, "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_GLOVES + i, "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_BOOTS + i, "Player\\", 10497, 9728, 1);

		if (i != 3 && i != 4 && i != 6 && i != 7)
		{
			OpenTexture(MODEL_BODY_HELM + i + max_class, "Player\\", 10497, 9728, 1);
			OpenTexture(MODEL_BODY_ARMOR + i + max_class, "Player\\", 10497, 9728, 1);
			OpenTexture(MODEL_BODY_PANTS + i + max_class, "Player\\", 10497, 9728, 1);
			OpenTexture(MODEL_BODY_GLOVES + i + max_class, "Player\\", 10497, 9728, 1);
			OpenTexture(MODEL_BODY_BOOTS + i + max_class, "Player\\", 10497, 9728, 1);
		}
		OpenTexture(MODEL_BODY_HELM + i + (max_class * 2), "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_ARMOR + i + (max_class * 2), "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_PANTS + i + (max_class * 2), "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_GLOVES + i + (max_class * 2), "Player\\", 10497, 9728, 1);
		OpenTexture(MODEL_BODY_BOOTS + i + (max_class * 2), "Player\\", 10497, 9728, 1);
	}
}

char ChangeServerClassTypeToClientClassType(unsigned __int8 byServerClassType)
{
	return ((((signed int)byServerClassType >> 1) & 1) << 6) | 32 * (((signed int)byServerClassType >> 2) & 1) | ((signed int)byServerClassType >> 4) | 16 * (((signed int)byServerClassType >> 3) & 1);
}

BOOL IsFemale(BYTE a1)
{
	return GetBaseClass(a1) == 2 || GetBaseClass(a1) == 5 || GetBaseClass(a1) == 7;
}

char GetHelperCharacterClass(unsigned __int8 byClass)
{
	char byFirstClass; // [sp+Bh] [bp-1h]@1

	char byCharacterClass; // [sp+7h] [bp-5h]@1
	char bySecondClass; // [sp+9h] [bp-3h]@1
	char byThirdClass; // [sp+Ah] [bp-2h]@1

	byCharacterClass = 0;
	byFirstClass = byClass & 0x7;
	bySecondClass = ((signed int)byClass >> 3) & 1;
	byThirdClass = ((signed int)byClass >> 4) & 1;

	switch ( byFirstClass )
	{
	case CLASS_WIZARD1:
		byCharacterClass = (( byThirdClass ) ? 11 : (( bySecondClass ) ? 7 : 0));
		break;
	case CLASS_KNIGHT1:
		byCharacterClass = (( byThirdClass ) ? 12 : (( bySecondClass ) ? 8 : 1));
		break;
	case CLASS_ELF1:
		byCharacterClass = (( byThirdClass ) ? 13 : (( bySecondClass ) ? 9 : 2));
		break;
	case CLASS_DARK:
		byCharacterClass = (( byThirdClass ) ? 14 : 3);
		break;
	case CLASS_DARK_LORD:
		byCharacterClass = (( byThirdClass ) ? 15 : 4);
		break;
	case CLASS_SUMMONER1:
		byCharacterClass = (( byThirdClass ) ? 16 : (( bySecondClass ) ? 10 : 5));
		break;
	case CLASS_RAGEFIGHTER:
		byCharacterClass = (( byThirdClass ) ? 17 : 6);
		break;
	case CLASS_GROWLANCER:
		byCharacterClass = (( byThirdClass ) ? 22 : 20);
		break;
	default:
		return byCharacterClass;
	}

	return byCharacterClass;
}
char GetCharacterClass(unsigned __int8 byClass)
{
	char byFirstClass; // [sp+Bh] [bp-1h]@1
	char byCharacterClass; // [sp+7h] [bp-5h]@1
	char bySecondClass; // [sp+9h] [bp-3h]@1
	char byThirdClass; // [sp+Ah] [bp-2h]@1

	byCharacterClass = 0;
	byFirstClass = byClass & 0x7;
	bySecondClass = ((signed int)byClass >> 3) & 1;
	byThirdClass = ((signed int)byClass >> 4) & 1;

	switch ( byFirstClass )
	{
	case CLASS_WIZARD1:
		byCharacterClass = (( byThirdClass ) ? 12 : (( bySecondClass ) ? 8 : 0));
		break;
	case CLASS_KNIGHT1:
		byCharacterClass = (( byThirdClass ) ? 13 : (( bySecondClass ) ? 9 : 1));
		break;
	case CLASS_ELF1:
		byCharacterClass = (( byThirdClass ) ? 14 : (( bySecondClass ) ? 10 : 2));
		break;
	case CLASS_DARK:
		byCharacterClass = (( byThirdClass ) ? 15 : 3);
		break;
	case CLASS_DARK_LORD:
		byCharacterClass = (( byThirdClass ) ? 16 : 4);
		break;
	case CLASS_SUMMONER1:
		byCharacterClass = (( byThirdClass ) ? 17 : (( bySecondClass ) ? 11 : 5));
		break;
	case CLASS_RAGEFIGHTER:
		byCharacterClass = (( byThirdClass ) ? 18 : 6);
		break;
	case CLASS_GROWLANCER:
		byCharacterClass = (( byThirdClass ) ? 19 : 7);
		break;
	default:
		return byCharacterClass;
	}

	return byCharacterClass;
}

void ZzzCharacter::MasterLevelType(int thisa, char byClass)
{
	switch ( byClass )
	{
	case 13:
		*(DWORD *)(thisa + 272) = 1; //-- blade master
		break;
	case 12:
		*(DWORD *)(thisa + 272) = 2; //-- gran master
		break;
	case 14:
		*(DWORD *)(thisa + 272) = 4; //-- muse elf
		break;
	case 17:
		*(DWORD *)(thisa + 272) = 8; //-- blody summoner
		break;
	case 15:
		*(DWORD *)(thisa + 272) = 16; //-- magic gladiator
		break;
	case 16:
		*(DWORD *)(thisa + 272) = 32; //-- dark lord
		break;
	case 18:
		*(DWORD *)(thisa + 272) = 64; //-- rage figther
		break;
	case 19:
		*(DWORD *)(thisa + 272) = 128; //-- grow lancer
		break;
	default:
		break;
	}
	LoadSkillTreeData(thisa);
	LoadSkillTooltip(thisa);
	switch ( byClass )
	{
	case 0:
	case 8:
	case 12:
		*(DWORD *)(thisa + 300) = 1751;
		*(DWORD *)(thisa + 304) = 1669;
		break;
	case 1:
	case 9:
	case 13:
		*(DWORD *)(thisa + 300) = 1755;
		*(DWORD *)(thisa + 304) = 1668;
		break;
	case 2:
	case 10:
	case 14:
		*(DWORD *)(thisa + 300) = 1759;
		*(DWORD *)(thisa + 304) = 1670;
		break;
	case 3:
	case 15:
		*(DWORD *)(thisa + 300) = 1763;
		*(DWORD *)(thisa + 304) = 1671;
		break;
	case 4:
	case 16:
		*(DWORD *)(thisa + 300) = 1767;
		*(DWORD *)(thisa + 304) = 1672;
		break;
	case 5:
	case 11:
	case 17:
		*(DWORD *)(thisa + 300) = 3136;
		*(DWORD *)(thisa + 304) = 1689;
		break;
	case 6:
	case 18:
		*(DWORD *)(thisa + 300) = 3330;
		*(DWORD *)(thisa + 304) = 3151;
		break;
	case 7:
	case 19:
		*(DWORD *)(thisa + 300) = 3170; //-- donde inicia el nombre de las filas de skill
		*(DWORD *)(thisa + 304) = 3176; //-- nombre de la class
		break;
	default:
		break;
	}
}

BYTE GetSkinModelIndex(BYTE byClass)
{
	char v2; // [sp+3h] [bp-5h]@1
	char v3; // [sp+7h] [bp-1h]@2

	v2 = byClass & 0xF;

	if ( isEvo3(byClass) )
		v3 = v2 + 8 * ((((signed int)(unsigned __int8)byClass >> 6) & 1) + 2 * (((signed int)(unsigned __int8)byClass >> 5) & 1));
	else
		v3 = v2 + 8 * ((((signed int)(unsigned __int8)byClass >> 6) & 1) 
			+ (((signed int)(unsigned __int8)byClass >> 5) & 1) 
			+ (((signed int)(unsigned __int8)byClass >> 4) & 1));

	return v3;
}

int GetCharacterClassText (unsigned __int8 byClass)
{
	int result; // eax@2
	char byCharacterClass; // [sp+1h] [bp-1h]@1

	byCharacterClass = GetCharacterClass( byClass );

	if ( byCharacterClass )
	{
		switch ( byCharacterClass )
		{
			case 0: //-- Soul Master
				result = (int)GlobalText(GlobalLine, 20);
				break;
			case 8: //-- Soul Master
				result = (int)GlobalText(GlobalLine, 25);
				break;
			case 12: //-- Grand Master
				result = (int)GlobalText(GlobalLine, 1669);
				break;
			//--
			case 1: //-- Dark Knight
				result = (int)GlobalText(GlobalLine, 21);
				break;
			case 9: //-- Blade Knight
				result = (int)GlobalText(GlobalLine, 26);
				break;
			case 13: //-- Blade Master
				result = (int)GlobalText(GlobalLine, 1668);
				break;
			case 2: //-- Elf
				result = (int)GlobalText(GlobalLine, 22);
				break;
			case 10: //-- Muse Elf
				result = (int)GlobalText(GlobalLine, 27);
				break;
			case 14: //-- High Elf
				result = (int)GlobalText(GlobalLine, 1670);
				break;
			case 3: //-- Magic Gladiator
				result = (int)GlobalText(GlobalLine, 23);
				break;
			case 15: //-- Dual Master
				result = (int)GlobalText(GlobalLine, 1671);
				break;
			case 4: //-- Dark Lord
				result = (int)GlobalText(GlobalLine, 24);
				break;
			case 16: //-- Lord Emperor
				result = (int)GlobalText(GlobalLine, 1672);
				break;
			case 5: //-- Summoner
				result = (int)GlobalText(GlobalLine, 1687);
				break;
			case 11: //-- Bloody Summoner
				result = (int)GlobalText(GlobalLine, 1688);
				break;
			case 17: //-- Dimension Master
				result = (int)GlobalText(GlobalLine, 1689);
				break;
			case 6: //-- Rage Fighter
				result = (int)GlobalText(GlobalLine, 3150);
				break;
			case 18: //-- Fist Master
				result = (int)GlobalText(GlobalLine, 3151);
				break;
			case 7: //-- Grow Lancer
				result = (int)GlobalText(GlobalLine, 3175);
				break;
			case 19: //-- Mirage Lancer
				result = (int)GlobalText(GlobalLine, 3176);
				break;
			case 27: //-- Shining Lancer
				result = (int)GlobalText(GlobalLine, 3176);
				break;
			case 24:
			case 25:
			case 26:
				result = (int)GlobalText(GlobalLine, 3179);
				break;
			default: //-- Error Code :
				result = (int)GlobalText(GlobalLine, 2305);
			break;
		}
	}
	else
	{
		//-- Dark Wizard
		result = (int)GlobalText(GlobalLine, 20);
	}
	return result;
}

void ZzzCharacter::CRenderMeshBMD(int thisa, int NumMeshs, int RenderFlag, float Alpha, int BlendMesh, float BlendMeshLight, float BlendMeshTexCoordU, float BlendMeshTexCoordV, int MeshTexture)
{
	if ( NumMeshs < *(WORD *)(thisa + 36) && NumMeshs >= 0 )
	{
		if( *(BYTE *)(thisa + 152) == 14)
		{
			*(BYTE *)(thisa + 152) = 15;
		}
	}
	RenderMesh(thisa, NumMeshs, RenderFlag, Alpha, BlendMesh, BlendMeshLight, BlendMeshTexCoordU, BlendMeshTexCoordV, MeshTexture);
}

//----- (0057F020) --------------------------------------------------------
int SetCharacterScale(int a1)
{
	int result;
	float RenderSize;
	float RenderMonk;

	result = a1;
	if ( !*(BYTE *)(a1 + 15) )
	{
		if ( *(WORD *)(a1 + 268) != 4755
			&& *(WORD *)(a1 + 268) != 4757
			&& *(WORD *)(a1 + 268) != 4818
			&& *(WORD *)(a1 + 268) != 4823
			&& *(WORD *)(a1 + 268) != 4820
			&& *(WORD *)(a1 + 268) != 4825
			&& ((signed int)*(WORD *)(a1 + 268) < 4765 || (signed int)*(WORD *)(a1 + 268) > 4768) )
		{
			*(WORD *)(a1 + 232) = -1;
		}
		else
		{
			*(WORD *)(a1 + 232) = GetSkinModelIndex(*(BYTE *)(a1 + 19)) + MODEL_BODY_HELM;
		}
		if ( *(DWORD *)0xE609E8 == 4 )
		{
			RenderSize = 1.2f;
			RenderMonk = 1.35f;

			if ( *(BYTE *)(a1 + 20) )
			{
				result = GetBaseClass(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD1:
					result = a1;
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_KNIGHT1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_ELF1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_DARK:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_DARK_LORD:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_SUMMONER1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_RAGEFIGHTER:
						result = a1;
						*(float *)(a1 + 872) = RenderMonk;
						break;
					default:
						if ( g_isCharacterBuff((DWORD *)(a1 + 1260), 218) )
						{
							*(float *)(a1 + 872) = RenderSize + 0.2;
						}
						else
						{
							*(float *)(a1 + 872) = RenderSize;
						}
						break;
				}
			}
			else
			{
				result = GetBaseClass(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_KNIGHT1:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_ELF1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_DARK:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_DARK_LORD:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_SUMMONER1:
						*(float *)(a1 + 872) = RenderSize;
						break;
					case CLASS_RAGEFIGHTER:
						*(float *)(a1 + 872) = RenderMonk;
						break;
					default:
						if ( g_isCharacterBuff((DWORD *)(a1 + 1260), 218) )
						{
							*(float *)(a1 + 872) = RenderSize + 0.2;
						}
						else
						{
							*(float *)(a1 + 872) = RenderSize;
						}
						
						break;
				}
			}
		}
		else if ( *(BYTE *)(a1 + 20) )
		{
			result = GetBaseClass(*(BYTE *)(a1 + 19));
			switch ( result )
			{
			case CLASS_WIZARD1:
				*(float *)(a1 + 872) = 0.93000001;
				break;
			case CLASS_KNIGHT1:
				*(float *)(a1 + 872) = 0.93000001;
				break;
			case CLASS_ELF1:
				result = a1;
				*(float *)(a1 + 872) = 0.86000001;
				break;
			case CLASS_DARK:
				*(float *)(a1 + 872) = 0.94999999;
				break;
			case CLASS_DARK_LORD:
				*(float *)(a1 + 872) = 0.92000002;
				break;
			case CLASS_SUMMONER1:
				result = a1;
				*(float *)(a1 + 872) = 0.89999998;
				break;
			case CLASS_RAGEFIGHTER:
				*(float *)(a1 + 872) = 1.03;
				break;
			default:
				{
					if ( g_isCharacterBuff((DWORD *)(a1 + 1260), 218) )
					{
						*(float *)(a1 + 872) = 0.94999999 + 0.2;
					}
					else
					{
						*(float *)(a1 + 872) = 0.94999999;
					}
				}
				break;
			}
		}
		else
		{
			result = GetBaseClass(*(BYTE *)(a1 + 19));
			switch ( result )
			{
			case CLASS_WIZARD1:
				result = a1;
				*(float *)(a1 + 872) = 0.89999998;
				break;
			case CLASS_KNIGHT1:
				*(float *)(a1 + 872) = 0.89999998;
				break;
			case CLASS_ELF1:
				*(float *)(a1 + 872) = 0.88;
				break;
			case CLASS_DARK:
				result = a1;
				*(float *)(a1 + 872) = 0.94999999;
				break;
			case CLASS_DARK_LORD:
				*(float *)(a1 + 872) = 0.92000002;
				break;
			case CLASS_SUMMONER1:
				*(float *)(a1 + 872) = 0.89999998;
				break;
			case CLASS_RAGEFIGHTER:
				result = a1;
				*(float *)(a1 + 872) = 1.03;
				break;
			default:
				{
					if ( g_isCharacterBuff((DWORD *)(a1 + 1260), 218) )
					{
						*(float *)(a1 + 872) = 0.94999999 + 0.2;
					}
					else
					{
						*(float *)(a1 + 872) = 0.94999999;
					}
				}
				break;
			}
		}
	}
	return result;
}

__declspec(naked) void SendPacketScrollUsed()
{
	static DWORD main_addr = 0x0083A6D6;
	static DWORD iTemp; // ST10_4@12

	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP - 0x898]
		MOVSX EAX, WORD PTR DS : [EDX]
		MOV iTemp, EAX
	}

	if ((iTemp < ITEM_ETC(0) || iTemp >= ITEM_ETC(0)+512)
		&& (iTemp < ITEM_WING(7) || iTemp > ITEM_WING(14))
		&& (iTemp < ITEM_WING(16) || iTemp > ITEM_WING(19))
		&& iTemp != ITEM_WING(20)
		&& (iTemp < ITEM_WING(21) || iTemp > ITEM_WING(24))
		&& (iTemp < ITEM_WING(271) || iTemp > ITEM_WING(277))
		&& iTemp != 6179 && iTemp != 6188
		&& iTemp != 6191 && iTemp != 6190
		&& iTemp != 6189 && iTemp != 6192
		&& iTemp != 7709 && iTemp != 7708
		)
	{
		main_addr = 0x0083A9C7;
	}
	else
	{
		main_addr = 0x0083A6D6;
	}

	_asm
	{
		JMP[main_addr]
	}
}

void ZzzCharacter::Init()
{
	this->SetExtendObjectModel();
	SetCompleteHook(0xE8, 0x00633EEA, &OpenPlayers);
	SetCompleteHook(0xE8, 0x00633FB3, &OpenPlayerTextures);
	SetCompleteHook(0xE9, 0x0083A5A3, &SendPacketScrollUsed);
	//--
	BYTE var_58h = 88;
	SetDword(0x004AD0EA + 1, MAX_LINE_SKILL);
	SetDword(0x004CFA09 + 3, MAX_LINE_SKILL);
	SetDword(0x004D2CCF + 1, MAX_LINE_SKILL * var_58h);
	SetDword(0x004D2DC6 + 1, MAX_LINE_SKILL * var_58h); //-- MaxData
	SetDword(0x0058A421 + 2, MAX_LINE_SKILL);
	SetDword(0x0058A448 + 2, MAX_LINE_SKILL);
	SetDword(0x0058A483 + 2, MAX_LINE_SKILL);
	SetDword(0x0058A517 + 6, MAX_LINE_SKILL);
	SetDword(0x0058A5E3 + 3, MAX_LINE_SKILL);
	SetDword(0x005965F2 + 3, MAX_LINE_SKILL);
	SetDword(0x00596603 + 3, MAX_LINE_SKILL);
	SetDword(0x0063F0B5 + 3, MAX_LINE_SKILL); //-- recibe skill
	SetDword(0x0063F197 + 3, MAX_LINE_SKILL); //-- recibe skill
	SetDword(0x00658DCF + 3, MAX_LINE_SKILL);
	SetDword(0x0095FC7F + 3, MAX_LINE_SKILL);
	SetDword(0x0081C5F7 + 3, MAX_LINE_SKILL);
	//--
	SetByte(0x0081959B + 2, 10); //-- Move Byte 1024 Line
	SetByte(0x008195BF + 2, 10); //-- Move Byte 1024 Line
	SetByte(0x008195F7 + 2, 10); //-- Move Byte 1024 Line
	SetDword(0x00819688 + 6, MAX_MASTERSKILLTREEDATA); //-- MaxData
	SetDword(0x00819BF3 + 3, MAX_MASTERSKILLTREEDATA); //-- MaxData
	SetDword(0x008196BB + 2, (DWORD)&MasterSkillTreeData);
	SetDword(0x00819C02 + 3, (DWORD)&MasterSkillTreeData);
	SetDword(0x00819C15 + 3, (DWORD)((int)MasterSkillTreeData + 2));
	SetDword(0x00819C36 + 1, (DWORD)&MasterSkillTreeData);
	SetDword(0x00819C42 + 2, (DWORD)&MasterSkillTreeData);
	//--
	SetCompleteHook(0xE9, 0x0049CE10, &IsFemale);
	SetCompleteHook(0xE8, 0x00593B48, &MuSkillClass);
	SetCompleteHook(0xE8, 0x005B49FE, &MuSkillClass);
	SetCompleteHook(0xE8, 0x005B58CD, &MuSkillClass);
	SetCompleteHook(0xE8, 0x007F80E1, &MuHelperClass);
	SetCompleteHook(0xE8, 0x0080D723, &MuHelperClass);
	SetCompleteHook(0xE9, 0x0057F020, &SetCharacterScale);
	SetCompleteHook(0xE9, 0x00587500, &GetSkinModelIndex);
	SetByte(0x00578B54 + 2, 8); //-- check soulmaster
	SetCompleteHook(0xE9, 0x005873C0, &GetCharacterClass);
	SetCompleteHook(0xE9, 0x00587620, &GetCharacterClassText);
	SetCompleteHook(0xE8, 0x007802A4, &GetHelperCharacterClass);
	SetCompleteHook(0xE9, 0x008199F0, &ZzzCharacter::MasterLevelType);
	//SetCompleteHook(0xE9, 0x00587380, &ChangeServerClassTypeToClientClassType);
	SetCompleteHook(0xE8, 0x00549787, &ZzzCharacter::CRenderMeshBMD);
}
