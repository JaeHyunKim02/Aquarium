#pragma once
#include"H_lib.h"


typedef struct tagBUBBLE_{
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed;
	
	int size;
	enum { S1, S2, S3, S4, S5 };//딱히 구현하지 않으면 0,1,2,3,4가 들어감
}BUBBLE_;

BUBBLE_* InitBUBBLE_(HDC hdcBacktBuffer);

void Update(BUBBLE_* Obj);
void Draw(BUBBLE_* Obj);
void Release(BUBBLE_* Obj);


inline void SetCoord(BUBBLE_* Obj, int x, int y) { Obj->x = x; Obj->y = y; }
inline void SetCell(BUBBLE_* Obj, int cx, int cy) { Obj->cx = cx, Obj->cy = cy; }