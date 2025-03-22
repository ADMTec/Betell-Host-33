
#pragma once
#if (SELECTCHARACTER==1)
#include "Protocol.h"

#define MultiCharacter 1

class CSelectChar
{
public:
	CSelectChar();
	~CSelectChar();
	// ----
	static void SelectChar();
	void	EventSelectChar(DWORD Event);
	// ----
public:
	int m_CharacterPage;
	// ----
}; extern CSelectChar gSelectChar;
#endif