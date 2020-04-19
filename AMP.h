#pragma once
#include"H_lib.h"


typedef struct tagAMP {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;
	
	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed;

}AMP;

AMP* InitAMP(HDC hdcBacktBuffer);

void Update(AMP* Obj);
void Draw(AMP* Obj);

void Release(AMP* Obj);

inline void SetCoord(AMP* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(AMP* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }