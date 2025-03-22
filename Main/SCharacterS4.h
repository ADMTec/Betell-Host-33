#pragma once
#define SceneFlag							*(int*)0x0E609E8
#define World								*(int*)0x0E61E18
#define BeginRender							((void(__thiscall*)(float a2)) 0x00546860)
#define RenderMesh							((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
#define EndRender							((void(__cdecl*)()) 0x00546880)
#define BeginBitmap				((void(*)()) 0x637770)
#define EndOpengl				((void(*)()) 0x6366F0)
#define CryingWolf2ndObjectVisual3	((void(__cdecl*)(int a1, int a2)) 0x009108F0)
#define camaramove				((void(*)()) 0x4D84E0)
#define RenderBitmap				((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)) 0x00637C60)
#define AlphaBlendType              *(int*)0x8793258
#define sub_635EB0     ((int(*)(void)) 0x635EB0)
#define sub_635E60      ((int(*)(void)) 0x635E60)
#define sub_4DDF50         ((int(*)(void)) 0x4DDF50)
#define sub_4DB060                     ((bool(__thiscall*)(int a1)) 0x4DB060 )
#define RenderBitmapLocalRotate					((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)

void SCharacterS4();