#pragma once
#define sub_614E60					((char(__thiscall*)( )) 0x00614E60)
#define sub_587500					((DWORD(__cdecl*)(char a1)) 0x587500)
#define sub_54EA80					((int(__thiscall*)(int a1)) 0x0054EA80)
#define sub_56F210					((int(__cdecl*)(int ObjectPointer, int ModelPointer, int a3)) 0x0056F210)
#define sub_4F9930					((int(__cdecl*)(char *a1)) 0x4F9930)
#define JCGetCharClass				((int(__cdecl*)(char a1)) 0x00405230)


#define sub_77AC70					((BOOL(__thiscall*)(int a1, int a2)) 0x0077AC70)
#define JCMacroLoadConfig			((void *(__thiscall*)(int a1)) 0x007FA150)

#define sub_7F8260					((void (__thiscall*)(int a1, int a2)) 0x007F8260)

#define sub_5873C0					((char(__cdecl*)(unsigned __int8 a1)) 0x005873C0)


char CGetCharacterClass(unsigned __int8 a1);
char JCGetSkinModelIndex(unsigned __int8 a1);

int JCGetClassname (unsigned __int8 a4);

class JCGrowLancer
{
public:
	JCGrowLancer( );
	~JCGrowLancer( );
	void Load( );
};

extern JCGrowLancer JCGetModelPJ;

