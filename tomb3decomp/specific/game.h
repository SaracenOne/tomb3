#pragma once
#include "../global/vars.h"

void inject_sgame(bool replace);

long GetRandomControl();
void SeedRandomControl(long seed);
long GetRandomDraw();
void SeedRandomDraw(long seed);

#define mGetAngle	( (ulong(__cdecl*)(long, long, long, long)) 0x00483860)