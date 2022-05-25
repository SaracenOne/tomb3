#pragma once
#include "../global/vars.h"

void inject_text(bool replace);

short T_GetStringLen(char* string);
long T_RemovePrint(TEXTSTRING* textstring);
void T_BottomAlign(TEXTSTRING* string, short flag);
void T_RightAlign(TEXTSTRING* string, short flag);
void T_CentreV(TEXTSTRING* string, short flag);
void T_CentreH(TEXTSTRING* string, short flag);
void T_RemoveOutline(TEXTSTRING* string);
void T_AddOutline(TEXTSTRING* string, short unused, short colour, ushort* gourptr, ushort flags);
void T_RemoveBackground(TEXTSTRING* string);
void T_AddBackground(TEXTSTRING* string, short xsize, short ysize, short x, short y, short z, short color, ushort* gourptr, ushort flags);
ulong GetTextScaleH(ulong h);
ulong GetTextScaleV(ulong v);
void draw_border(long x, long y, long z, long w, long h);
long T_GetTextWidth(TEXTSTRING* string);
void T_FlashText(TEXTSTRING* string, short flash, short rate);
void T_ChangeText(TEXTSTRING* string, char* pStr);
TEXTSTRING* T_Print(long x, long y, long z, char* pStr);

#define T_DrawText	( (void(__cdecl*)()) 0x0046B0F0 )
