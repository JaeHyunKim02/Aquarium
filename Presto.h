#pragma once
#include"H_lib.h"


typedef struct tagPRESTO {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed;

}PRESTO;

PRESTO* InitPRESTO(HDC hdcBacktBuffer);

void Update(PRESTO* Obj);
void Draw(PRESTO* Obj);

void Release(PRESTO* Obj);

inline void SetCoord(PRESTO* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(PRESTO* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }