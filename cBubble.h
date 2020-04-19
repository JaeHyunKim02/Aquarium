#pragma once
#include "H_lib.h"
class cBubble
{
private:
	HDC BackBuffer;

	HDC ImageDC;
	HBITMAP hbmImage;

	int x, y;
	int w, h;


	int cx, cy;

	int state;

	int Speed; 

	int OldY;

	bool b_Del;
public:
	cBubble(int X, int Y, HDC hdcBacktBuffer);
	~cBubble();

	void Update();
	void Render();

	bool GetDel() { return b_Del; }//b_Del¡¢±Ÿ
};

