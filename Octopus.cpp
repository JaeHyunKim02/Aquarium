#include"H_lib.h"


OCTOPUS* InitOctopus(HDC hdcBacktBuffer) {
	OCTOPUS* temp;
	temp = (OCTOPUS*)malloc(sizeof(OCTOPUS));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "psychosquid.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 500;	temp->y = 300;
	temp->w = 160;	temp->h = 160;

	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;

	temp->Speed = 8;
	temp->Randpos = 0;

	return temp;

}

void Random(OCTOPUS* Obj) {
	//srand((unsigned int)time(NULL));

}
void LWalk(OCTOPUS* Obj)
{
	if (Obj->cx >= 9)      Obj->cx = 0;
	else               Obj->cx++;

	if (Obj->x <= 0)
	{
		Obj->cy = 1;
		Obj->state = LTURN;
	}
	else Obj->x -= Obj->Speed;
}

void RWalk(OCTOPUS* Obj)
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

void LTurn(OCTOPUS* Obj)
{
	if (Obj->cx >= 9) {
		Obj->cy = 5;
		Obj->cx = 0;
		Obj->state = RWALK;
	}

	else Obj->cx++;
}

void RTurn(OCTOPUS* Obj)
{
	if (Obj->cx <= 0) {
	Obj->cy = 0;
	Obj->cx = 0;
	Obj->state = LWALK;
	}

	else Obj->cx--;
}
void Update(OCTOPUS* Obj) {

	switch (Obj->state) {
	case LWALK: LWalk(Obj); break;
	case RWALK: RWalk(Obj); break;
	case LTURN: LTurn(Obj); break;	
	case RTURN: RTurn(Obj); break;
	}

	//if (Obj->x <= 160)
	//{
	//	//Obj->x = 600;
	//	Obj->state = TURN;

	//}

	//else
	//{
	//	if (Obj->state == TURN) Obj->x = Obj = x;
	//	else Obj->x -= 5;
	//}

	//if (Obj->cx >= 10)   Obj->cx = 0;

	//else            Obj->cx++;
}

void Draw(OCTOPUS* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(0, 0, 0));
}


void Release(OCTOPUS* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}