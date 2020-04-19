#pragma once
#include"H_lib.h"


typedef struct tagANGIE {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed;

}ANGIE;

ANGIE* InitAngie(HDC hdcBacktBuffer);

void Update(ANGIE* Obj);
void Draw(ANGIE* Obj);

void Release(ANGIE* Obj);

inline void SetCoord(ANGIE* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(ANGIE* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }