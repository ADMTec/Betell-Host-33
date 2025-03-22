#include "stdafx.h"
#include "InterEx.h"
#include "import.h"
#include "Util.h"
#include "SkillBox.h"

CSkillBox gCSkillBox;

bool Render_SkillFullMouser2(DWORD a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v62; // [sp+Ch] [bp-54h]@1
	int v64; // [sp+18h] [bp-48h]@84
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116*/
	signed int j; // [sp+10h] [bp-50h]@116
	signed int i; // [sp+20h] [bp-40h]@73

	v62 = a1;
	if (pCheckEffectPlayer((DWORD*)(*(DWORD*)0x7BC4F04 + 1260), 98))
	{
		*(BYTE*)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE*)(*(DWORD*)0x8128AC8 + 118);
		*(BYTE*)(v62 + 65) = 0;
		if ((signed int)v5 > 0)
		{
			//-- skill en uso
			v82 = 388.0;
			v87 = 445.0f;
			v70 = 25.0f;
			v75 = 32.0f;
			if (*(DWORD*)(v62 + 80) || *(BYTE*)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) != 1)
			{
				if (*(DWORD*)(v62 + 80) != 1 || *(BYTE*)0x8793384 || pCheckMouseOver(v82, v87, v70, v75))
				{
					if (*(DWORD*)(v62 + 80) != 1 || *(BYTE*)0x8793384 != 1 && *(BYTE*)0x8793380 != 1 || pCheckMouseOver(v82, v87, v70, v75) != 1)
					{
						if (*(DWORD*)(v62 + 80) != 2 || *(BYTE*)0x8793384 || *(BYTE*)0x8793380)
						{
							if (*(DWORD*)(v62 + 80) == 1)
							{
								*(BYTE*)(v62 + 65) = 1;
								*(DWORD*)(v62 + 68) = *(BYTE*)(*(DWORD*)0x7BC4F04 + 50);
								*(DWORD*)(v62 + 72) = v82 - 5.0;
								*(DWORD*)(v62 + 76) = v87;
								result = 0;
							}
							else if (*(DWORD*)(v62 + 80) == 2)
							{
								result = 0;
							}
							else
							{
								//-- DrawSkill Bar
								v83 = 330.0;
								v88 = 480.0f;
								v71 = 100.0;
								v76 = 20.0;
								if (*(DWORD*)(v62 + 80) || *(BYTE*)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1)
								{
									if (*(DWORD*)(v62 + 80) != 3 || *(BYTE*)0x8793384 || pCheckMouseOver(v83, v88, v71, v76))
									{
										if (*(DWORD*)(v62 + 80) != 3 || *(BYTE*)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1)
										{
											//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 480.0f;
											v72 = 20.0;
											v68 = 0;
											v67 = *(BYTE*)(v62 + 20) != 1 ? 1 : 6;
											while (v68 < 5)
											{
v84 = v84 + v72;
												if (v67 == 10)
													v67 = 0;
												if (pCheckMouseOver(v84, v89, v72, (float)32.0) == 1)
												{
													if (*(DWORD*)(v62 + 4 * v67 + 24) == -1)
													{
														if (*(DWORD*)(v62 + 80) == 3)
														{
															*(BYTE*)(v62 + 65) = 0;
															*(DWORD*)(v62 + 68) = -1;
														}
														if (*(DWORD*)(v62 + 80) == 4 && !*(BYTE*)0x8793384)
															*(DWORD*)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * *(DWORD*)(v62 + 4 * v67 + 24) + 120);
														if (v66 && ((signed int)v66 < 67 || (signed int)v66 > 72) && *(BYTE*)(*(DWORD*)0x8128ABC + 88 * v66 + 55) != 3)
														{
															if (*(DWORD*)(v62 + 80) == 3)
															{
																*(BYTE*)(v62 + 65) = 1;
																*(DWORD*)(v62 + 68) = *(DWORD*)(v62 + 4 * v67 + 24);
																*(DWORD*)(v62 + 72) = v84 - 5.0;
																*(DWORD*)(v62 + 76) = v89;
																return 1;
															}
															if (*(DWORD*)(v62 + 80) == 4 && !*(BYTE*)0x8793384)
															{
																if (*(DWORD*)(v62 + 68) == *(DWORD*)(v62 + 4 * v67 + 24))
																{
																	*(DWORD*)(v62 + 80) = 0;
																	*(WORD*)(v62 + 84) = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * *(BYTE*)(*(DWORD*)0x7BC4F04 + 50) + 120);
																	*(BYTE*)(*(DWORD*)0x7BC4F04 + 50) = *(BYTE*)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD*)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if (*(DWORD*)(v62 + 80) == 4)
											{
												//-- DrawSkill Bar
												if (*(BYTE*)0x8793384 || pCheckMouseOver((float)330.0, (float)480.0f, (float)100.0, (float)32.0))
												{
													result = 0;
												}
												else
												{
													*(DWORD*)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if (*(BYTE*)(v62 + 64))
											{
												//-- SkillBarSwitch
												v80 = 0;
												v78 = 0;
												v90 = 390.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD*)(v62 + 80);
												for (i = 0; i < 150; ++i)
												{
													v69 = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * i + 120);
													if (v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE*)(*(DWORD*)0x8128ABC + 88 * v69 + 55) != 3)
													{
														if (v80 == 11)
															v90 = v90 - v77;
														if (v80 >= 11)
														{
															if (v80 < 11 || v80 > 21)
																v85 = v79 - v73 * 11.0 + (double)(v80 - 21) * v73;
															else
																v85 = v79 - v73 * 6.0 + (double)(v80 - 10) * v73;
														}
														else
														{
v64 = v80 / 2;
															if (v80 % 2)
																v85 = v79 - (double)(v64 + 1) * v73;
															else
																v85 = (double)v64 * v73 + v79;
														}
														++v80;
														if (pCheckMouseOver(v85, v90, v73, v77) == 1)
														{
															v78 = 1;
															if (!*(DWORD*)(v62 + 80) && !*(BYTE*)0x8793384)
															{
																*(DWORD*)(v62 + 80) = 5;
																break;
															}
														}
														if (*(DWORD*)(v62 + 80) == 5 && *(BYTE*)0x8793384 == 1)
														{
															if (pCheckMouseOver(v85, v90, v73, v77) == 1)
															{
																*(DWORD*)(v62 + 80) = 6;
																break;
															}
														}
														if (*(DWORD*)(v62 + 80) == 5 && !*(BYTE*)0x8793384)
														{
															if (pCheckMouseOver(v85, v90, v73, v77) == 1)
															{
																*(BYTE*)(v62 + 65) = 1;
																*(DWORD*)(v62 + 68) = i;
																*(DWORD*)(v62 + 72) = v85;
																*(DWORD*)(v62 + 76) = v90;
															}
														}
														if (*(DWORD*)(v62 + 80) == 6 && !*(BYTE*)0x8793384 && *(DWORD*)(v62 + 68) == i)
														{
															if (pCheckMouseOver(v85, v90, v73, v77) == 1)
															{
																*(DWORD*)(v62 + 80) = 0;
																*(WORD*)(v62 + 84) = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * *(BYTE*)(*(DWORD*)0x7BC4F04 + 50) + 120);
																*(BYTE*)(*(DWORD*)0x7BC4F04 + 50) = i;
																*(BYTE*)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if (v81 == *(DWORD*)(v62 + 80))
												{
													if (*(DWORD*)(*(DWORD*)0x7BC4F04 + 676))
													{
														//-- SkillFixRaven
														v86 = 270.0;
														v91 = 350.0;
														v74 = 32.0;
														for (j = 150; j < 154; ++j)
														{
															if (pCheckMouseOver(v86, v91, v74, (float)38.0) == 1)
															{
																v78 = 1;
																if (!*(DWORD*)(v62 + 80) && !*(BYTE*)0x8793384)
																{
																	*(DWORD*)(v62 + 80) = 5;
																	return 1;
																}
																if (*(DWORD*)(v62 + 80) == 5 && *(BYTE*)0x8793384 == 1)
																{
																	*(DWORD*)(v62 + 80) = 6;
																	return 0;
																}
																if (*(DWORD*)(v62 + 80) == 5)
																{
																	*(BYTE*)(v62 + 65) = 1;
																	*(DWORD*)(v62 + 68) = j;
																	*(DWORD*)(v62 + 72) = v86;
																	*(DWORD*)(v62 + 76) = v91;
																}
																if (*(DWORD*)(v62 + 80) == 6 && !*(BYTE*)0x8793384 && *(DWORD*)(v62 + 68) == j)
																{
																	*(DWORD*)(v62 + 80) = 0;
																	*(WORD*)(v62 + 84) = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * *(BYTE*)(*(DWORD*)0x7BC4F04 + 50) + 120);
																	*(BYTE*)(*(DWORD*)0x7BC4F04 + 50) = j;
*(BYTE*)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if (v78 || *(DWORD*)(v62 + 80) != 5)
													{
														if (v78 || *(BYTE*)0x8793384 || *(DWORD*)(v62 + 80) != 6)
														{
															if (*(DWORD*)(v62 + 80) == 6)
															{
																if (*(BYTE*)0x8793384)
																{
																	result = 0;
																}
																else
																{
																	*(DWORD*)(v62 + 80) = 0;
																	result = 1;
																}
															}
															else
															{
																result = 1;
															}
														}
														else
														{
															*(DWORD*)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD*)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD*)(v62 + 80) || *(DWORD*)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD*)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD*)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD*)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							if (pCheckMouseOver(v82, v87, v70, v75) == 1)
							{
								*(BYTE*)(v62 + 64) = *(BYTE*)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD*)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD*)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD*)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD*)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD*)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

void RenderSkill_Raven2(DWORD* a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2

	v6 = *(DWORD*)a1;
	if (*(DWORD*)(*(DWORD*)0x7BC4F04 + 676))
	{
		v10 = 270.0;//X
		v11 = 350.0;//Y
		v8 = 32.0;
		v9 = 38.0;
		for (i = 150; i < 154; ++i)
		{
			if (i == *(BYTE*)(*(DWORD*)0x7BC4F04 + 50))
				pDrawGUI(31313, v10, v11, v8, v9);
			else
				pDrawGUI(31312, v10, v11, v8, v9);
			v4 = v11 + 6.0;
			v5 = v10 + 6.0;
			RenderShowSkill(a1, i, v5, v4, 20.0, 28.0);
			v10 = v10 + v8;
		}
	}
}

void Render_Funcion2_772EA0(int ThisR)
{
	static DWORD Addr1 = 0x00815040;
	static DWORD Addr2_Call = 0x00772EA0;
	static DWORD This = 0x00772EA0;

	This = ThisR;

	_asm
	{
PUSH 0; / Arg5 = 00000000
			PUSH 0; | Arg4 = 00000000
			MOV ECX, This; |
			PUSH ECX; | Arg3
			PUSH Addr1; | Arg2 = 00815040
			PUSH ECX; | Arg1
			FLD DWORD PTR DS : [0xD2CA40]; |
			FSTP DWORD PTR SS : [ESP]; |
			MOV EDX, This; |
			MOV ECX, DWORD PTR DS : [EDX + 0x10]; |
			CALL Addr2_Call; \main1.00772EA0
	}
}

char Render_SkillBarSwitch2(int This)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	int v7; // [sp+28h] [bp-34h]@1
	int v8; // [sp+30h] [bp-2Ch]@15
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3

	v7 = This;

	if ((signed int)*(BYTE*)(*(DWORD*)0x8128AC8 + 118) > 0 && *(BYTE*)(v7 + 64) == 1)
	{
		v17 = 390.0;//Y
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;//X
		v11 = 0;

		for (i = 0; i < 150; ++i)
		{
			v12 = *(WORD*)(*(DWORD*)0x8128AC8 + 2 * i + 120);

			if (*(WORD*)(*(DWORD*)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72))
			{
				v9 = *(BYTE*)(*(DWORD*)0x8128ABC + 88 * v12 + 55);
				if (v9 != 1 && v9 != 3)
				{
					if (v11 == 11)
					{
						v17 = v17 - v14;
					}
					if (v11 >= 11)
					{
						if (v11 < 11 || v11 > 21)
						{
							v16 = v10 - v13 * 11.0 + (double)(v11 - 21) * v13;
						}
						else
						{
							v16 = v10 - v13 * 6 + (double)(v11 - 10) * v13;
						}
					}
					else
					{
						v8 = v11 / 2;
						if (v11 % 2)
						{
							v16 = v10 - (double)(v8 + 1) * v13;
						}
						else
						{
							v16 = (double)v8 * v13 + v10;
						}
					}

					++v11;

					if (i == *(BYTE*)(*(DWORD*)0x7BC4F04 + 50))//-- Seleccionado
					{
						pDrawGUI(31313, v16, v17, v13, v14);
					}
					else
					{
						pDrawGUI(31312, v16, v17, v13, v14);
					}
					v4 = v17 + 6.0;
					v5 = v16 + 6.0;
					RenderShowSkill((DWORD*)This, i, v5, v4, 20.0, 28.0);
				}
			}
		}
		RenderSkill_Raven2((DWORD*)This);
	}

	if (*(BYTE*)(This + 65) == 1 && *(DWORD*)(This + 16))
	{
		Render_Funcion2_772EA0(This);
		*(BYTE*)(This + 65) = 0;
	}
	return 1;
}

void CSkillBox::Init()
{
	SetCompleteHook(0xE9, 0x008126C0, &Render_SkillFullMouser2);
	SetCompleteHook(0xE9, 0x00813970, &Render_SkillBarSwitch2);
}