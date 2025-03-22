#pragma once

#pragma comment(lib,"wzMUQuiz.lib") //soiitem


typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define DLL_VERSION "1.0"

// System Include
#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include "detours.h"
#include <Shellapi.h>
#include <vector>
#include <map>
#include <winioctl.h>
#include <atltime.h>
#include <functional>
#include <fstream>
#include "macro.h"
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")

#include "..\\..\\Util\\lua\\include\\lua.hpp"
#pragma comment(lib, "..\\..\\Util\\lua\\lib\\lua52.lib")

#define PREMIUN					1
#define MAX_CHAT_TYPE1			10
#define SOIITEM					1

#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20
	

#define MAX_CUSTOM_WING			100
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	1000
#define MAX_POSITION_ITEM		1000
//--
#define MAX_CUSTOPETEFFECT			2000
#define MAX_DYNAMIC_WING_EFFECT		5000
#define MAX_CUSTOM_WING_EFFECT		5000

#define CUSTOM_MAP_TELEPORT		1
#define CUSTOM_EX_TELEPORT_EVO	TRUE
#define CUSTOM_PKCLEAR_NPC		TRUE
#define ENABLE_MONSTER_QUEST	1
#define CUSTOM_FLAGS            1
#define selectchars13     1
#define SWITCH_SERVER     1
#define SWITCH_SERVER1    1
#define LOGIN_REGISTER    1
#define CHARACTER_INFO    1
#define AUTOMOVE          1
#define MAINMUNFT         1
#define NEWBOARD          0
#define SLIDE             1
#define DEBUG_CURSOR      0
#define CAMARA            1

#define FACEBOOK          1

#define BOTOES_FUNCOES    1

#define OFF_VAR_X803      0

#define LEOTHAP 1

#define UPDATE 15

#define SELECTCHARACTER       1

#define THUE_VIP_NEW	      1

#define SKIN             1

#define WINDOWS_QUEST   1

#define CUSTOM_NPC_BUFFER		TRUE

#define CreateOptionWindows		0

#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

//void InitLoginThemeS4();
//void InitLoginThemeS2();
typedef char textlist[100];