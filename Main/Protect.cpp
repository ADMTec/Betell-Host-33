// Protect.cpp: implementation of the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Protect.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Util.h"
#include "TMemory.h"

CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{

}

CProtect::~CProtect() // OK
{

}

bool CProtect::ReadPetEffectBMD(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_ReadBMDFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( PETEFFECT_BMD ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_ReadBMD, sizeof(PETEFFECT_BMD), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( PETEFFECT_BMD ) ; n++ )
	{
		((BYTE*)&this->m_ReadBMD)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_ReadBMD)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadTooltipTRSData(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_ReadTooltipTRSDataFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( TOOLTIP_BMD ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_ReadTooltipTRSData, sizeof(TOOLTIP_BMD), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( TOOLTIP_BMD ) ; n++ )
	{
		((BYTE*)&this->m_ReadTooltipTRSData)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_ReadTooltipTRSData)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadMakeViewTRSData(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_MakeViewTRSDataFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( RENDER_MAKE_VIEW ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_MakeViewTRSData, sizeof(RENDER_MAKE_VIEW), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( RENDER_MAKE_VIEW ) ; n++ )
	{
		((BYTE*)&this->m_MakeViewTRSData)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_MakeViewTRSData)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadMainFile(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name,&this->m_ClientFileCRC,1024) == 0)
	{
		return 0;
	}

	HANDLE file = CreateFile(name,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,0);

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if(GetFileSize(file,0) != sizeof(MAIN_FILE_INFO))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile(file,&this->m_MainInfo,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&this->m_MainInfo)[n] += (BYTE)(0x95^HIBYTE(n));
		((BYTE*)&this->m_MainInfo)[n] ^= (BYTE)(0xDA^LOBYTE(n));
	}

	CloseHandle(file);
	return 1;
}
//--
void CProtect::CheckLauncher() // OK
{
	if((this->m_MainInfo.LauncherType & 1) == 0)
	{
		return;
	}

	if (FindWindow(0, gProtect.m_MainInfo.LauncherName) == 0)
	{
		ExitProcess(0);
	}
}
//--
void CProtect::CheckInstance() // OK
{
	if (this->m_MainInfo.LauncherType != 3)
	{
		return;
	}

	char buff[256];

	wsprintf(buff, "XTEAM_MAIN_10405_%s", this->m_MainInfo.IpAddress);

	if (OpenMutex(MUTEX_ALL_ACCESS, 0, buff) == 0)
	{
		CreateMutex(0, 0, buff);
	}
	else
	{
		ExitProcess(0);
	}
}

void CProtect::CheckLauncherCommandLine()
{
	if (this->m_MainInfo.LauncherType == 2)
	{
		char** Command = 0;
		CommandLineToArg(GetCommandLine(), &Command);
		if (strcmp("Updater", Command[1]) != 0)
		{
			char path[255] = "Launcher.exe";
			ShellExecute(0, "open", path, "", 0, SW_SHOW); //запускаем
			ExitProcess(0);
		}
	}

	if (this->m_MainInfo.LauncherType == 4)
	{
		char** Command = 0;
		CommandLineToArg(GetCommandLine(), &Command);
		if (strcmp(this->m_MainInfo.ClientName, Command[0]) != 0)
		{
			char path[255] = "Launcher.exe";
			ShellExecute(0, "open", path, "", 0, SW_SHOW); //запускаем
			ExitProcess(0);
		}
	}


}
//--
void CProtect::CheckClientFile() // OK
{
	if(this->m_MainInfo.ClientCRC32 == 0)
	{
		return;
	}

	char name[MAX_PATH] = {0};

	if(GetModuleFileName(0,name,sizeof(name)) == 0)
	{
		ExitProcess(0);
	}

	if(_stricmp(ConvertModuleFileName(name),this->m_MainInfo.ClientName) != 0)
	{
		ExitProcess(0);
	}

	CCRC32 CRC32;

	DWORD ClientCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.ClientName,&ClientCRC32,1024) == 0)
	{
		MessageBox(0,"Main.exe CRC error!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.ClientCRC32 != ClientCRC32)
	{
		MessageBox(0,"Main.exe CRC error!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
}
//--
void CProtect::CheckHackFile() // OK
{
	
	if(this->m_MainInfo.HackCRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.HackName,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.HackCRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.HackName);

	if(module == 0)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error Antihack",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPlugin1File() // OK
{
	if (this->m_MainInfo.Plugin1CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin1CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin1Name, &Plugin1CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin1CRC32 != Plugin1CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin1Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin2File() // OK
{
	if (this->m_MainInfo.Plugin2CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin2CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin2Name, &Plugin2CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin2CRC32 != Plugin2CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin2Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin3File() // OK
{
	if (this->m_MainInfo.Plugin3CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin3CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin3Name, &Plugin3CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin3CRC32 != Plugin3CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin3Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin4File() // OK
{
	if (this->m_MainInfo.Plugin4CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin4CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin4Name, &Plugin4CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin4CRC32 != Plugin4CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin4Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin5File() // OK
{
	if (this->m_MainInfo.Plugin5CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin5CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin5Name, &Plugin5CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin5CRC32 != Plugin5CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin5Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin6File() // OK
{
	if (this->m_MainInfo.Plugin6CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin6CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin6Name, &Plugin6CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin6CRC32 != Plugin6CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin6Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin7File() // OK
{
	if (this->m_MainInfo.Plugin7CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin7CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin7Name, &Plugin7CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin7CRC32 != Plugin7CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin7Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin8File() // OK
{
	if (this->m_MainInfo.Plugin8CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin8CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin8Name, &Plugin8CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin8CRC32 != Plugin8CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin8Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin9File() // OK
{
	if (this->m_MainInfo.Plugin9CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin9CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin9Name, &Plugin9CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin9CRC32 != Plugin9CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin9Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin0File() // OK
{
	if (this->m_MainInfo.Plugin0CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin0CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin0Name, &Plugin0CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin0CRC32 != Plugin0CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.Plugin0Name);

	if (module == 0)
	{
		ExitProcess(0);
	}

	void(*EntryProc)() = (void(*)())GetProcAddress(module, "EntryProc");

	if (EntryProc != 0)
	{
		EntryProc();
	}
}



void CProtect::CheckPlugin1FileCrc() // OK
{
	if (this->m_MainInfo.Plugin11CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin11CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin1Crc, &Plugin11CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin11CRC32 != Plugin11CRC32)
	{
		ExitProcess(0);
	}

}

void CProtect::CheckPlugin2FileCrc() // OK
{
	if (this->m_MainInfo.Plugin12CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin12CRC32;

	if (CRC32.FileCRC(this->m_MainInfo.Plugin2Crc, &Plugin12CRC32, 1024) == 0)
	{
		ExitProcess(0);
	}

	if (this->m_MainInfo.Plugin12CRC32 != Plugin12CRC32)
	{
		ExitProcess(0);
	}

}
//--
void CProtect::CheckCameraFile() // OK
{
	if(this->m_MainInfo.CameraCRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD CameraCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.CameraName,&CameraCRC32,1024) == 0)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.CameraCRC32 != CameraCRC32)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.CameraName);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

DWORD CProtect::GetFileCRC(const char* szFileName)
{
	CCRC32 CRC32;

	DWORD Buffer;

	if (CRC32.FileCRC(szFileName, &Buffer, 1024) == 0)
	{
		return 0;
	}

	return Buffer;
}