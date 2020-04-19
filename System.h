#ifndef _SYSTEM_H_
#define _SYSTEM_H_



BOOL WinInit(const char* pWinName);

HWND WinCreate(const char* pClassName,const char* pWindowName, HINSTANCE hInst, int nWindowStyle, RECT rtWindowSize);

VOID MsgLoop();

int GameLoop();


#endif