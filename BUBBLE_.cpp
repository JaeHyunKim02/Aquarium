#include"H_lib.h"



BUBBLE_* InitBUBBLE_(HDC hdcBacktBuffer) {
	BUBBLE_* temp;
	temp = (BUBBLE_*)malloc(sizeof(BUBBLE_));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "bubbles.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->size=BUBBLE_::S1;

	temp->x = 100;	temp->y = 300;
	temp->w = 30;	temp->h = 30;//크기

	temp->cy = temp->size;	



	temp->cx = 0;
	temp->cy = 0;

	temp->state = LWALK;

	temp->Speed = 10;

	return temp;

}
void LWalk(BUBBLE_* Obj)
{
	if (Obj->cx >= 9)      Obj->cx = 0;
	else				   Obj->cx++;//

	if (Obj->x <= 0)//왼쪽 끝에 도달했을 때
	{
		Obj->cy = 1;
		Obj->cx = 0;
		Obj->state = LTURN;
	}
	else Obj->x -= Obj->Speed;//이동속도

}

void RWalk(BUBBLE_* Obj)
{
	if (Obj->cx >= 9) Obj->cx = 0;
	else Obj->cx++;//애니메이션

	if (Obj->x >= 400)
	{
		Obj->cy = 1;
		Obj->cx = 9;
		Obj->state = RTURN;
	}
	else Obj->x += Obj->Speed;
}

void LTurn(BUBBLE_* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 2;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(BUBBLE_* Obj)
{
	if (Obj->cx <= 0) {
		Obj->cy = 0;
		Obj->cx = 0;
		Obj->state = LWALK;
	}

	else Obj->cx--;
}

void Update(BUBBLE_* Obj) {


}
//if (Obj->x <= 160)   Obj->x = 600;
//else            Obj->x -= 10;
//if (Obj->cx >= 10)   Obj->cx = 0;
//else            Obj->cx++;


void Draw(BUBBLE_* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(BUBBLE_* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}