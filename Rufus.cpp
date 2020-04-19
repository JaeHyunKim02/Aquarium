#include"H_lib.h"


RUFUS* InitRUFUS(HDC hdcBacktBuffer) {
	RUFUS* temp;
	temp = (RUFUS*)malloc(sizeof(RUFUS));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "rufus.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 100;	temp->y = 370;
	temp->w = 80;	temp->h = 80;//크기


	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;

	temp->Speed = 3;

	return temp;

}
void LWalk(RUFUS* Obj)
{
	if (Obj->cx >= 9)      Obj->cx = 0;
	else				   Obj->cx++;

	if (Obj->x <= 0)//왼쪽 끝에 도달했을 때
	{
		Obj->cy = 1;
		Obj->cx = 0;
		Obj->state = RWALK;
	}
	else Obj->x -= Obj->Speed;//이동속도

}

void RWalk(RUFUS* Obj)
{
	if (Obj->cx >= 9) Obj->cx = 0;
	else Obj->cx++;//애니메이션

	if (Obj->x >= 400)
	{
		Obj->cy = 0;
		Obj->cx = 9;
		Obj->state = LWALK;
	}
	else Obj->x += Obj->Speed;
}

//void LTurn(RUFUS* Obj)
//{
//	if (Obj->cx >= 9) {
//		Obj->cy = 2;
//		Obj->cx = 0;
//		Obj->state = RWALK;
//	}
//
//	else Obj->cx++;
//}

//void RTurn(RUFUS* Obj)
//{
//	if (Obj->cx <= 0) {
//		Obj->cy = 0;
//		Obj->cx = 0;
//		Obj->state = LWALK;
//	}
//
//	else Obj->cx--;
//}

void Update(RUFUS* Obj) {

	switch (Obj->state) {
	case LWALK: LWalk(Obj); break;
	case RWALK: RWalk(Obj); break;
	//case LTURN: LTurn(Obj); break;
	//case RTURN: RTurn(Obj); break;
	}
}
//if (Obj->x <= 160)   Obj->x = 600;
//else            Obj->x -= 10;
//if (Obj->cx >= 10)   Obj->cx = 0;
//else            Obj->cx++;


void Draw(RUFUS* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(RUFUS* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}