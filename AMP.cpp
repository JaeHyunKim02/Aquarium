#include"H_lib.h"


AMP* InitAMP(HDC hdcBacktBuffer) {
	AMP* temp;
	temp = (AMP*)malloc(sizeof(AMP));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "amp.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 100;	temp->y = 300;
	temp->w = 160;	temp->h = 60;//크기


	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;

	temp->Speed = 10;
	PlaySound(".\\The Lion Sleeps Tonight.wav", NULL, SND_ASYNC | SND_LOOP);//브금재생

	return temp;

}
void LWalk(AMP* Obj)
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

void RWalk(AMP* Obj)
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

void LTurn(AMP* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 2;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(AMP* Obj)
{
	if (Obj->cx <= 0) {
		Obj->cy = 0;
		Obj->cx = 0;
		Obj->state = LWALK;
	}

	else Obj->cx--;
}

void Update(AMP* Obj) {

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
 

void Draw(AMP* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(AMP* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}