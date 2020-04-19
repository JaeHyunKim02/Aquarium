#pragma once
#include"H_lib.h"


typedef struct tagSTARFISH {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	float w, h;


	int cx, cy;

	int state;

	int KeyCode;

	int Speed;

}STARFISH;

STARFISH* InitSTARFISH(HDC hdcBacktBuffer);

void Update(STARFISH* Obj);
void Draw(STARFISH* Obj);

void Release(STARFISH* Obj);

inline void SetCoord(STARFISH* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(STARFISH* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }