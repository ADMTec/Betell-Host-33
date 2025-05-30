#include "stdafx.h"
#include "ControllerTextBox.h"
#include "Interface.h"
#include "PartySearch.h"
#include "User.h"
#include "PrintPlayer.h"

CTextBoxController gTextBoxController;

short CTextBoxController::GetSymbolFromVK(WPARAM wParam)
{
	BYTE btKeyState[256];
	HKL hklLayout = GetKeyboardLayout(0);
	WORD Symbol;
	GetKeyboardState(btKeyState);
	if ((ToAsciiEx(wParam, MapVirtualKey(wParam, 0), btKeyState, &Symbol, 0, hklLayout) == 1))
	{
		return Symbol;
	}
	return 0;
}

bool CTextBoxController::ControlTextBox(KBDLLHOOKSTRUCT Hook)
{
	if (gInterface.Data[eSTATSADD_MAIN].OnShow)
	{
		char Value[20];
		int IsBackspace = false;
		int IsDelete = false;
		int IsTab = false;

		int ObjectCount = 4;

		if ((gObjUser.lpPlayer->Class & 7) == 4)
		{
			ObjectCount = 5;
		}

		int SelectedIndex = 0;

		if (Hook.vkCode == VK_BACK)
		{
			IsBackspace = true;
		}
		else if (Hook.vkCode == VK_DELETE)
		{
			IsDelete = true;
		}
		else if (Hook.vkCode == VK_TAB)
		{
			IsTab = true;
		}
		else if ((Hook.vkCode >= 0x30 && Hook.vkCode <= 0x39) || (Hook.vkCode >= 0x60 && Hook.vkCode <= 0x69))
		{
			int Symbol = GetSymbolFromVK(Hook.vkCode);
			if (Symbol == 0)
			{
				return true;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(Value, buff);
			////console.Log("", buff);
			//int Value = atoi(buff);
		}
		else
		{
			return true;
		}
		int ObjectIDs[5] =
		{
			eSTATSADD_STATBOX01,
			eSTATSADD_STATBOX02,
			eSTATSADD_STATBOX03,
			eSTATSADD_STATBOX04,
			eSTATSADD_STATBOX05,
		};

		for (int i = 0; i<ObjectCount; i++)
		{
			if (gInterface.Data[ObjectIDs[i]].Attribute == 1)
			{
				SelectedIndex = i;
				if (IsBackspace == true)
				{
					gInterface.Data[ObjectIDs[i]].StatValue[strlen(gInterface.Data[ObjectIDs[i]].StatValue) - 1] = '\0';

					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue) == 0)
					{
						strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
					}
					break;
				}
				else if (IsDelete == true)
				{
					strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
				}
				else if (IsTab == true)
				{
					gInterface.Data[ObjectIDs[i]].Attribute = 0;

					if (i == ObjectCount - 1)
					{
						gInterface.Data[ObjectIDs[0]].Attribute = 1;
					}
					else
					{
						gInterface.Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else
				{
					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue)<8)
					{
						if (!strcmp(gInterface.Data[ObjectIDs[i]].StatValue, "0"))
						{
							strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, Value);
						}
						else
						{
							strcat_s(gInterface.Data[ObjectIDs[i]].StatValue, Value);
						}
					}
				}
			}
		}

		int StatPoints = 0;

		for (int i = 0; i<ObjectCount; i++)
		{
			if (i == SelectedIndex)
			{
				continue;
			}
			StatPoints += atoi(gInterface.Data[ObjectIDs[i]].StatValue);
		}

		if (StatPoints + atoi(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue) > ViewPoint)
		{
			char buff[20];
			sprintf(buff, "%d", ViewPoint - StatPoints);
			strcpy_s(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}

		if (atoi(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue) > gObjUser.GetMaxStatPoint(ViewAccountLevel))
		{
			char buff[20];
			sprintf(buff, "%d", gObjUser.GetMaxStatPoint(ViewAccountLevel));
			//strcat_s(this->Data[ObjectIDs[SelectedIndex]].StatValue, buff);
			strcpy_s(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}
	}

	return false;
}
