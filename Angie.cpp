#include"H_lib.h"



ANGIE* InitAngie(HDC hdcBacktBuffer) {
	ANGIE* temp;
	temp = (ANGIE*)malloc(sizeof(ANGIE));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "angie.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 100;	temp->y = 200;
	temp->w = 80;	temp->h = 80;

	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;
	
	temp->Speed = 14;

	return temp;

}
void LWalk(ANGIE* Obj)
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

void RWalk(ANGIE* Obj)
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

void LTurn(ANGIE* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 2;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(ANGIE* Obj)
{
	if (Obj->cx <= 0) {
		Obj->cy = 0;
		Obj->cx = 0;
		Obj->state = LWALK;
	}

	else Obj->cx--;
}

void Update(ANGIE* Obj) {

	switch (Obj->state) {
	case LWALK: LWalk(Obj); break;
	case RWALK: RWalk(Obj); break;
	case LTURN: LTurn(Obj); break;
	case RTURN: RTurn(Obj); break;
	}
}
//if (Obj->x <= 160)   Obj->x = 600;
//else            Obj->x -= 10;
//if (Obj->cx >= 10)   Obj->cx = 0;
//else            Obj->cx++;


void Draw(ANGIE* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(ANGIE* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}