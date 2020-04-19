#pragma once
#include"H_lib.h"


typedef struct tagRUFUS {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed;

}RUFUS;

RUFUS* InitRUFUS(HDC hdcBacktBuffer);

void Update(RUFUS* Obj);
void Draw(RUFUS* Obj);

void Release(RUFUS* Obj);

inline void SetCoord(RUFUS* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(RUFUS* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }