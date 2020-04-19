#include"H_lib.h"


PRESTO* InitPRESTO(HDC hdcBacktBuffer) {
	PRESTO* temp;
	temp = (PRESTO*)malloc(sizeof(PRESTO));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "presto.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 100;	temp->y = 300;
	temp->w = 80;	temp->h = 80;//크기


	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;

	temp->Speed = 10;

	return temp;

}
void LWalk(PRESTO* Obj)
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

void RWalk(PRESTO* Obj)
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

void LTurn(PRESTO* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 3;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(PRESTO* Obj)
{
	if (Obj->cx <= 0) {
		Obj->cy = 0;
		Obj->cx = 0;
		Obj->state = LWALK;
	}

	else Obj->cx--;
}

void Update(PRESTO* Obj) {

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


void Draw(PRESTO* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(PRESTO* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}