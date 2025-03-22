#define SceneFlag							*(int*)0x0E609E8
#define World								*(int*)0x0E61E18
#define BeginRender							((void(__thiscall*)(float a2)) 0x00546860)
#define RenderMesh							((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
#define EndRender							((void(__cdecl*)()) 0x00546880)
#define TransformPosition					((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define Joint(x)							((0x30 * x) + 0x7BC08A0)
#define CreateSprite						((int(__cdecl*)(int a1, vec3_t Bone1, float size, vec3_t color, int ObjPos, float, int)) 0x00771310)
#define CreateParticle						((int(__cdecl*)(int a1, int a2, int a3, vec3_t color, int a5, float a6, int a7)) 0x0074CD30)
#define CreateParticle2						((int(__cdecl*)(int a1, vec3_t Bone1, int a3, vec3_t color, int a5, float size, int a7)) 0x0074CD30)
#define BoneTransform						*(int*)0x7BC09C0
#define CreateEffect2						((int(__cdecl*)(int a4, vec3_t Bone1, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)
#define RenderCryingWolf2ndObjectVisual		((void(__cdecl*)(int a1, int a2)) 0x008D1C00)
#define RenderBitmap						((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, int Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)
#define EnableAlphaBlend					((void(__cdecl*)()) 0x636070)
#define EnableAlphaTest						((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define RenderInfomationR					((int(*)()) 0x4D5EC0)

void SCharacterBetell();
