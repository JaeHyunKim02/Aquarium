#include"H_lib.h"


STARFISH* InitSTARFISH(HDC hdcBacktBuffer) {
	STARFISH* temp;
	temp = (STARFISH*)malloc(sizeof(STARFISH));

	HINSTANCE hInstance = GetModuleHandle(NULL);

	temp->BackBuffer = hdcBacktBuffer;

	temp->ImageDC = CreateCompatibleDC(hdcBacktBuffer);//ScreenDC
	temp->hbmImage = (HBITMAP)LoadImage(hInstance, "starfish.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(temp->ImageDC, temp->hbmImage);

	temp->x = 560;	temp->y = 380;
	temp->w = 32.5;	temp->h = 54;

	temp->cx = 0; temp->cy = 0;

	temp->state = LWALK;

	temp->KeyCode = NULL;

	temp->Speed = 5;

	return temp;

}
void LWalk(STARFISH* Obj)
{
	if (Obj->cx >= 5)      Obj->cx = 0;
	else				   Obj->cx++;//

	if (Obj->x <= 0)//왼쪽 끝에 도달했을 때
	{
		Obj->cy = 1;
		Obj->cx = 0;
		Obj->state = RWALK;
	}
	//else Obj->x -= Obj->Speed;//이동속도

}

void RWalk(STARFISH* Obj)
{
	if (Obj->cx >= 5) Obj->cx = 0;
	else Obj->cx++;//애니메이션

	if (Obj->x >= 400)
	{
		Obj->cy = 1;
		Obj->cx = 5;
		Obj->state = LWALK;
	}
	//else Obj->x += Obj->Speed;
}

//void LTurn(STARFISH* Obj)
//{
//	if (Obj->cx >= 9) {
//		Obj->cy = 2;
//		Obj->cx = 0;
//		Obj->state = RWALK;
//	}
//
//	else Obj->cx++;
//}
//
//void RTurn(STARFISH* Obj)
//{
//	if (Obj->cx <= 0) {
//		Obj->cy = 0;
//		Obj->cx = 0;
//		Obj->state = LWALK;
//	}
//
//	else Obj->cx--;
//}

void Update(STARFISH* Obj) {
	

	switch(Obj->state){
	case LWALK: LWalk(Obj); break;
	case RWALK: RWalk(Obj); break;
	//default:
	//	Obj->KeyCode = NULL;




	//switch (Obj->state) {
	//case LWALK: LWalk(Obj); break;
	//case RWALK: RWalk(Obj); break;
	//case LTURN: LTurn(Obj); break;
	//case RTURN: RTurn(Obj); break;
	}
}
//if (Obj->x <= 160)   Obj->x = 600;
//else            Obj->x -= 10;
//if (Obj->cx >= 10)   Obj->cx = 0;
//else            Obj->cx++;


void Draw(STARFISH* Obj) {
	TransparentBlt(Obj->BackBuffer,
		Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->ImageDC,
		Obj->cx*Obj->w,
		Obj->cy*Obj->h,
		Obj->w, Obj->h,
		RGB(255, 0, 255));
}

void Release(STARFISH* Obj) {

	DeleteObject(Obj->hbmImage);
	DeleteDC(Obj->ImageDC);
	free(Obj);
}