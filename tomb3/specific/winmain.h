#pragma once
#include "../global/vars.h"

void inject_winmain(bool replace);

bool WinDXInit(DEVICEINFO* device, DXCONFIG* config, bool createNew);
void WinAppExit();
LRESULT CALLBACK WinAppProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
long WinRegisterWindow(HINSTANCE hinstance);
#ifdef TROYESTUFF
HWND WinCreateWindow(HINSTANCE hinstance, long nCmdShow, RECT* r);
#else
HWND WinCreateWindow(HINSTANCE hinstance, long nCmdShow);
#endif
float WinFrameRate();
void WinFreeDX(bool free_dd);
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd);
void S_ExitSystem(const char* msg);
void Log(const char* s, ...);		//NOT present in original code

#ifdef DO_LOG
extern FILE* logF;
#endif