#pragma once
#include"H_lib.h"


typedef struct tagBOSS {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;

	int cx, cy;
	int state;
	int Speed;

}BOSS;

BOSS* InitBOSS(HDC hdcBacktBuffer);

void Update(BOSS* Obj);
void Draw(BOSS* Obj);

void Release(BOSS* Obj);

inline void SetCoord(BOSS* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(BOSS* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }