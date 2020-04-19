#pragma once
#include"H_lib.h"



#define SPEED 10;
typedef struct tagOctopus {
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;

	int cx, cy;
	int state;

	int Speed;

	int Randpos;

}OCTOPUS;

OCTOPUS* InitOctopus(HDC hdcBacktBuffer);

void Update(OCTOPUS* Obj);

void Draw(OCTOPUS* Obj);

void Release(OCTOPUS* Obj);

inline void SetCoord(OCTOPUS* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(OCTOPUS* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }