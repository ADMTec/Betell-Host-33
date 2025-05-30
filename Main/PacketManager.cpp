// PacketManager.cpp: implementation of the CPacketManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PacketManager.h"

CPacketManager gPacketManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPacketManager::CPacketManager() // OK
{
	this->Init();
}

CPacketManager::~CPacketManager() // OK
{

}

void CPacketManager::Init() // OK
{
	memset(&this->m_Encryption,0,sizeof(this->m_Encryption));
	memset(&this->m_Decryption,0,sizeof(this->m_Decryption));

	this->m_SaveLoadXor[0] = 0x3F08A79B;
	this->m_SaveLoadXor[1] = 0xE25CC287;
	this->m_SaveLoadXor[2] = 0x93D27AB9;
	this->m_SaveLoadXor[3] = 0x20DEA7BF;

	memset(this->m_buff,0,sizeof(this->m_buff));

	this->m_size = 0;

	this->m_XorFilter[0] = 0xAB;
	this->m_XorFilter[1] = 0x11;
	this->m_XorFilter[2] = 0xCD;
	this->m_XorFilter[3] = 0xFE;
	this->m_XorFilter[4] = 0x18;
	this->m_XorFilter[5] = 0x23;
	this->m_XorFilter[6] = 0xC5;
	this->m_XorFilter[7] = 0xA3;
	this->m_XorFilter[8] = 0xCA;
	this->m_XorFilter[9] = 0x33;
	this->m_XorFilter[10] = 0xC1;
	this->m_XorFilter[11] = 0xCC;
	this->m_XorFilter[12] = 0x66;
	this->m_XorFilter[13] = 0x67;
	this->m_XorFilter[14] = 0x21;
	this->m_XorFilter[15] = 0xF3;
	this->m_XorFilter[16] = 0x32;
	this->m_XorFilter[17] = 0x12;
	this->m_XorFilter[18] = 0x15;
	this->m_XorFilter[19] = 0x35;
	this->m_XorFilter[20] = 0x29;
	this->m_XorFilter[21] = 0xFF;
	this->m_XorFilter[22] = 0xFE;
	this->m_XorFilter[23] = 0x1D;
	this->m_XorFilter[24] = 0x44;
	this->m_XorFilter[25] = 0xEF;
	this->m_XorFilter[26] = 0xCD;
	this->m_XorFilter[27] = 0x41;
	this->m_XorFilter[28] = 0x26;
	this->m_XorFilter[29] = 0x3C;
	this->m_XorFilter[30] = 0x4E;
	this->m_XorFilter[31] = 0x4D;
}

bool CPacketManager::LoadEncryptionKey(char* name) // OK
{
	return this->LoadKey(name,4370,0);
}

bool CPacketManager::LoadDecryptionKey(char* name) // OK
{
	return this->LoadKey(name,4370,1);
}

bool CPacketManager::LoadKey(char* name,WORD header,bool type) // OK
{
	ENCDEC_HEADER HeaderInfo;

	HANDLE file = CreateFile(name,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD size;

	ReadFile(file,&HeaderInfo,sizeof(HeaderInfo),&size,0);

	if(HeaderInfo.header != header || HeaderInfo.size != (sizeof(HeaderInfo)+sizeof(ENCDEC_DATA)))
	{
		CloseHandle(file);
		return 0;
	}

	ENCDEC_DATA* lpData;

	if(type == 0)
	{
		lpData = &this->m_Encryption;
	}
	else
	{
		lpData = &this->m_Decryption;
	}

	DWORD table[4];

	ReadFile(file,table,sizeof(table),&size,0);

	for(int n=0;n < 4;n++)
	{
		lpData->Modulus[n] = this->m_SaveLoadXor[n]^table[n];
	}

	ReadFile(file,table,sizeof(table),&size,0);

	for(int n=0;n < 4;n++)
	{
		lpData->Key[n] = this->m_SaveLoadXor[n]^table[n];
	}

	ReadFile(file,table,sizeof(table),&size,0);

	for(int n=0;n < 4;n++)
	{
		lpData->Xor[n] = this->m_SaveLoadXor[n]^table[n];
	}

	CloseHandle(file);
	return 1;
}

int CPacketManager::Encrypt(BYTE* lpTarget,BYTE* lpSource,int size) // OK
{
	int OriSize = size;
	int TempSize1,TempSize2;

	BYTE* lpTempSource = lpSource;
	BYTE* lpTempTarget = lpTarget;

	int dec = (size+7)/8;

	size = ((dec+(dec*4))*2)+dec;

	if(lpTarget != 0)
	{
		TempSize1 = OriSize;

		for(int n=0;n < TempSize1;n+=8,OriSize-=8,lpTempTarget+=11)
		{
			TempSize2 = OriSize;

			if(OriSize >= 8)
			{
				TempSize2 = 8;
			}

			this->EncryptBlock(lpTempTarget,&lpTempSource[n],TempSize2);
		}
	}

	return size;
}

int CPacketManager::Decrypt(BYTE* lpTarget,BYTE* lpSource,int size) // OK
{
	int result = (size*8)/11;
	int DecSize = 0;

	BYTE* lpTempSource = lpSource;
	BYTE* lpTempTarget = lpTarget;

	if(lpTarget != 0 && size > 0)
	{
		result = 0;

		while(DecSize < size)
		{
			int TempResult = this->DecryptBlock(lpTempTarget,lpTempSource);

			if(result < 0)
			{
				return result;
			}

			result += TempResult;
			DecSize += 11;
			lpTempSource += 11;
			lpTempTarget += 8;
		}
	}

	return result;
}

int CPacketManager::EncryptBlock(BYTE* lpTarget,BYTE* lpSource,int size) // OK
{
	DWORD EncBuffer[4] = {0};
	DWORD EncValue = 0;

	BYTE* lpTempSource = lpSource;
	BYTE* lpTempTarget = lpTarget;

	memset(lpTempTarget,0,11);

	for(int n=0;n < 4;n++)
	{
		EncBuffer[n] = (((this->m_Encryption.Xor[n]^((WORD*)lpTempSource)[n])^EncValue)*this->m_Encryption.Key[n])%this->m_Encryption.Modulus[n];
		EncValue = (WORD)EncBuffer[n];
	}

	for(int n=0;n < 3;n++)
	{
		EncBuffer[n] = (EncBuffer[n]^this->m_Encryption.Xor[n])^(WORD)EncBuffer[n+1];
	}

	int BitPos = 0;

	for(int n=0;n < 4;n++)
	{
		BitPos = this->AddBits(lpTempTarget,BitPos,(BYTE*)&EncBuffer[n],0,16);
		BitPos = this->AddBits(lpTempTarget,BitPos,(BYTE*)&EncBuffer[n],22,2);
	}

	BYTE CheckSum = 0xF8;

	for(int n=0;n < 8;n++)
	{
		CheckSum ^= lpTempSource[n];
	}

	((BYTE*)&EncValue)[0] = (CheckSum^size)^0x3D;
	((BYTE*)&EncValue)[1] = CheckSum;

	return this->AddBits(lpTempTarget,BitPos,(BYTE*)&EncValue,0,16);
}

int CPacketManager::DecryptBlock(BYTE* lpTarget,BYTE* lpSource) // OK
{
	DWORD DecBuffer[4] = {0};

	BYTE* lpTempSource = lpSource;
	BYTE* lpTempTarget = lpTarget;

	memset(lpTempTarget,0,8);

	int BitPos = 0;

	for(int n=0;n < 4;n++)
	{
		this->AddBits((BYTE*)&DecBuffer[n],0,lpTempSource,BitPos,16);
		BitPos += 16;
		this->AddBits((BYTE*)&DecBuffer[n],22,lpTempSource,BitPos,2);
		BitPos += 2;
	}

	for(int n=2;n >= 0;n--)
	{
		DecBuffer[n] = (DecBuffer[n]^this->m_Decryption.Xor[n])^(WORD)DecBuffer[n+1];
	}

	DWORD value = 0;

	for(int n=0;n < 4;n++)
	{
		((WORD*)lpTempTarget)[n] = (WORD)((((this->m_Decryption.Key[n]*DecBuffer[n])%this->m_Decryption.Modulus[n])^this->m_Decryption.Xor[n])^value);
		value = (WORD)DecBuffer[n];
	}

	DecBuffer[0] = 0;

	this->AddBits((BYTE*)DecBuffer,0,lpTempSource,BitPos,16);

	((BYTE*)DecBuffer)[0] = (((BYTE*)DecBuffer)[0]^((BYTE*)DecBuffer)[1])^0x3D;

	BYTE CheckSum = 0xF8;

	for(int n=0;n < 8;n++)
	{
		CheckSum ^= lpTempTarget[n];
	}

	if(CheckSum != ((BYTE*)DecBuffer)[1])
	{
		return -1;
	}
	
	return ((BYTE*)DecBuffer)[0];
}

int CPacketManager::AddBits(BYTE* lpTarget,int TargetBitPos,BYTE* lpSource,int SourceBitPos,int size) // OK
{
	int SourceBitSize = SourceBitPos+size;
	int TempSize1 = this->GetByteOfBit(SourceBitSize-1)+(1-this->GetByteOfBit(SourceBitPos));

	BYTE* lpTempBuff = new BYTE[TempSize1+1];

	memset(lpTempBuff,0,TempSize1+1);

	memcpy(lpTempBuff,&lpSource[this->GetByteOfBit(SourceBitPos)],TempSize1);

	if((SourceBitSize%8) != 0)
	{
		lpTempBuff[TempSize1-1] &= 0xFF << (8-(SourceBitSize%8));
	}

	int ShiftLeft = (SourceBitPos%8);
	int ShiftRight = (TargetBitPos%8);

	this->Shift(lpTempBuff,TempSize1,-ShiftLeft);
	this->Shift(lpTempBuff,TempSize1+1,ShiftRight);

	int TempSize2 = ((ShiftRight<=ShiftLeft)?0:1)+TempSize1;

	BYTE* lpTempTarget = &lpTarget[this->GetByteOfBit(TargetBitPos)];

	for(int n=0;n < TempSize2;n++)
	{
		lpTempTarget[n] |= lpTempBuff[n];
	}

	delete[] lpTempBuff;

	return TargetBitPos+size;
}

int CPacketManager::GetByteOfBit(int value) // OK
{
	return value >> 3;
}

void CPacketManager::Shift(BYTE* lpBuff,int size,int ShiftSize) // OK
{
	BYTE* lpTempBuff = lpBuff;

	if(ShiftSize != 0)
	{
		if(ShiftSize > 0)
		{
			if((size-1) > 0)
			{
				for(int n=(size-1);n > 0;n--)
				{
					lpTempBuff[n] = (lpTempBuff[n-1] << (8-ShiftSize)) | (lpTempBuff[n] >> ShiftSize);
				}
			}

			lpTempBuff[0] >>= ShiftSize;
		}
		else
		{
			ShiftSize = -ShiftSize;

			if((size-1) > 0)
			{
				for(int n=0;n < (size-1);n++)
				{
					lpTempBuff[n] = (lpTempBuff[n+1] >> (8-ShiftSize)) | (lpTempBuff[n] << ShiftSize);
				}
			}

			lpTempBuff[size-1] <<= ShiftSize;
		}
	}
}

bool CPacketManager::AddData(BYTE* lpBuff,int size) // OK
{
	if(size <= 0 || size >= 2048)
	{
		return 0;
	}

	memcpy(this->m_buff,lpBuff,size);
	this->m_size = size;
	return 1;
}

bool CPacketManager::ExtractPacket(BYTE* lpBuff) // OK
{
	int size,end;

	switch(this->m_buff[0])
	{
		case 0xC1:
		case 0xC3:
			size = this->m_buff[1];
			end = 2;
			break;
		case 0xC2:
		case 0xC4:
			size = MAKEWORD(this->m_buff[2],this->m_buff[1]);
			end = 3;
			break;
		default:
			return 0;
	}

	if(this->m_size < ((DWORD)size))
	{
		return 0;
	}

	this->XorData((end+1),size);

	memcpy(lpBuff,this->m_buff,size);

	return 1;
}

void CPacketManager::XorData(int start,int end) // OK
{
	if(start > end)
	{
		return;
	}

	for(int n=start;n < end;n++)
	{
		this->m_buff[n] ^= this->m_buff[n-1]^this->m_XorFilter[n%32];
	}
}
