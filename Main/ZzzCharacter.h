#pragma once
//#include "_struct.h"
#define MAX_MASTERSKILLTREEDATA				1024
#define MAX_LINE_SKILL						750

enum CLASS_TYPE
{
// 1�� ����
	CLASS_WIZARD1 = 0,		// �渶����
	CLASS_KNIGHT1,			// ����
	CLASS_ELF1,				// ����
	CLASS_DARK,				// ���˻�
	CLASS_DARK_LORD,		// ��ũ�ε�
	CLASS_SUMMONER1,			// ��ȯ����
	CLASS_RAGEFIGHTER,
	CLASS_GROWLANCER,
	CLASS_RUNERWIZZARD,
};

#define sub_614E60							((void(__cdecl*)( )) 0x00614E60)
#define sub_616A50							((void(__cdecl*)( )) 0x00616A50)
#define RenderMesh							((void(__thiscall*)(int thisa, int NumMeshs, int RenderFlag, float Alpha, int BlendMesh, float BlendMeshLight, float BlendMeshTexCoordU, float BlendMeshTexCoordV, int MeshTexture)) 0x005468A0)
#define LoadSkillTreeData					((void (__thiscall*)(int thisa)) 0x00819BD0)
#define LoadSkillTooltip					((void (__thiscall*)(int thisa)) 0x00819C80)

class ZzzCharacter
{
public:
	ZzzCharacter(void);
	virtual ~ZzzCharacter(void);
	void Init();
	void SetExtendObjectModel();
	static void __thiscall MasterLevelType(int thisa, char byClass);
	static void __thiscall CRenderMeshBMD(int thisa, int NumMeshs, int RenderFlag, float Alpha, int BlendMesh, float BlendMeshLight, float BlendMeshTexCoordU, float BlendMeshTexCoordV, int MeshTexture);

public:
	BYTE * MasterSkillTreeData[MAX_MASTERSKILLTREEDATA * 24];
};

extern ZzzCharacter g_pModelViewChar;