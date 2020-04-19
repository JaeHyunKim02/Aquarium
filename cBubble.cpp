#include "H_lib.h"
#include "cBubble.h"



cBubble::cBubble(int X, int Y , HDC hdcBacktBuffer)
	: x(X) , y(Y) , OldY(Y)
{ 
	HINSTANCE hInstance = GetModuleHandle(NULL);

	BackBuffer = hdcBacktBuffer;
		
	ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	hbmImage = (HBITMAP)LoadImage(hInstance, "CKbubble.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(ImageDC, hbmImage);

	w = 225;	h = 225;//크기

	cx = 0; cy = 0;

	state = LWALK;

	Speed = 15;

	b_Del = false;
}


cBubble::~cBubble()
{
	DeleteObject(hbmImage);
	DeleteDC(ImageDC);
}

void cBubble::Update()//행동할것
{
	if (y > OldY - 100) {
		y -= 10;
	}
	else
		b_Del = true;
	//if (y < 500) {
	//	y -= 324;//속도
	//}
	//else
	//	b_Del = true;

}

void cBubble::Render()//이미지 출력
{
	TransparentBlt(BackBuffer,
		x, y, w, h,
		ImageDC,
		cx*w,
		cy*h,
		w, h,
		RGB(255, 0, 255));
}
