#include"H_lib.h"


BKGD* InitBackground(const char* strFilename, HDC hdcBacktBuffer) {
	BKGD* temp;

	temp = (BKGD*)malloc(sizeof(BKGD));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->BackGroundDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmBackGround = (HBITMAP)LoadImage(hInstance, strFilename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	SelectObject(temp->BackGroundDC, temp->hbmBackGround);

	return temp;
}

void Draw(BKGD* Obj) {

	BitBlt(Obj->BackBuffer, 0, 0, WIDTH, HEIGHT, Obj->BackGroundDC, 0, 0, SRCCOPY);
}

void Release(BKGD * Obj)
{
	DeleteObject(Obj->hbmBackGround);
	DeleteDC(Obj->BackGroundDC);
	free(Obj);
		
}
