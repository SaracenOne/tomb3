#pragma once
#include "../global/vars.h"

void inject_audio(bool replace);

BOOL __stdcall ACMEnumCallBack(HACMDRIVERID hadid, DWORD_PTR dwInstance, DWORD fdwSupport);
void ACMCloseFile();
bool ACMOpenFile(const char* name);
void ACMEmulateCDStop();
void ACMEmulateCDPlay(long track, long mode);
void ThreadACMEmulateCDPlay(long track, long mode);
long ACMGetTrackLocation();
#ifdef TROYESTUFF
void ACMMute();
#endif
void ACMSetVolume(long volume);
long ACMHandleNotifications();
long ACMSetupNotifications();
bool ACMInit();
void ACMClose();
