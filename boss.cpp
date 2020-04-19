#include"H_lib.h"


BOSS* InitBOSS(HDC hdcBacktBuffer) {
	BOSS* temp;
	temp = (BOSS*)malloc(sizeof(BOSS));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "boss.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 0;	temp->y = 0;
	temp->w = 160;	temp->h = 160;

	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;
	temp->Speed = 20;

	return temp;

}

void LWalk(BOSS* Obj)
{
	if (Obj->cx >= 9)      Obj->cx = 0;
	else				   Obj->cx++;//

	if (Obj->x>=0)//(INPUT->KeyPress('a'))//왼쪽 끝에 도달했을 때
	{
		Obj->cy = 1;
		Obj->cx = 0;
		Obj->state = LTURN;
		//if (INPUT->KeyUp == true) {
		//	Obj->state = STOP;

		//}

	}
	else Obj->x -= Obj->Speed;//이동속도

}

void RWalk(BOSS* Obj)
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

void LTurn(BOSS* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 2;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(BOSS* Obj)
{
	if (Obj->cx <= 0) {
		Obj->cy = 0;
		Obj->cx = 0;
		Obj->state = LWALK;
	}

	else Obj->cx--;
}

void Update(BOSS* Obj) {
	switch (Obj->state) {
	case LWALK: LWalk(Obj); break;
	case RWALK: RWalk(Obj); break;
	case LTURN: LTurn(Obj); break;
	case RTURN: RTurn(Obj); break;
	}
	/*if (Obj->x <= 160)   Obj->x = 600;
	else            Obj->x -= 20;
	if (Obj->cx >= 10)   Obj->cx = 0;
	else            Obj->cx++;*/
}

void Draw(BOSS* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(BOSS* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}