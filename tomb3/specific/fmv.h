#pragma once
#include "../global/vars.h"

void inject_fmv(bool replace);

#ifdef TROYESTUFF
bool LoadWinPlay();
#endif

long FMV_Play(char* name);
long FMV_PlayIntro(char* name1, char* name2);
void WinPlayFMV(const char* name, bool play);
void WinStopFMV(bool play);

extern long fmv_playing;
