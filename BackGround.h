#pragma once

typedef struct tagBKGD
{

	HDC BackBuffer;

	HDC BackGroundDC;
	HBITMAP hbmBackGround;



}BKGD;

BKGD* InitBackground(const char* strFilename, HDC hdcBackBuffer);

void Draw(BKGD* Obj);

void Release(BKGD* Obj);