#include"H_lib.h"
#include "cBubbleAdmin.h"
extern BOOL bIsActive;



HDC ScreenDC;//���� ����

HDC MemoryDC;//�ĸ� ����
HBITMAP hBM;

int nFPS;
int nCount;

BKGD* Background = NULL;
AMP* Amp = NULL;
OCTOPUS* Octo = NULL;
BOSS* Boss = NULL;
STARFISH* Star = NULL;
ANGIE* Angie = NULL;
RUFUS* Rufus = NULL;
PRESTO* Presto = NULL;
//BUBBLE* Bubble = NULL;
cBubbleAdmin * m_Bubble = nullptr;

BUBBLE_* RUNBUBBLE = NULL;




int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInstance = GetModuleHandle(NULL);

	ScreenDC = GetDC(hWnd);//������� ��

	//�޸� �ε�, ��  
	MemoryDC = CreateCompatibleDC(ScreenDC);
	hBM = CreateCompatibleBitmap(ScreenDC, WIDTH, HEIGHT);
	SelectObject(MemoryDC, hBM);

	INPUT->Init(hWnd);

	Background = InitBackground("Background.bmp", MemoryDC);
	Amp = InitAMP(MemoryDC);
	Octo = InitOctopus(MemoryDC);
	Boss = InitBOSS(MemoryDC);
	Star = InitSTARFISH(MemoryDC);
	Angie = InitAngie(MemoryDC);
	Rufus = InitRUFUS(MemoryDC);
	Presto = InitPRESTO(MemoryDC);
	//Bubble = InitBUBBLE(MemoryDC);
	RUNBUBBLE = InitBUBBLE_(MemoryDC);


	m_Bubble = new cBubbleAdmin(hWnd,MemoryDC);
	//m_Bubble = new cBubbleAdmin();
	//m_Bubble->Init(MemoryDC);

	bIsActive = true;

	SetTimer(hWnd, 0, 1000, NULL);
	SetTimer(hWnd, 1, 100, NULL);
	return 1;

}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	switch (wParam)
	{
	case 0:
		nFPS = nCount;
		nCount = 0;
		break;

	case 1:
		Update(Amp);
		Update(Octo);
		Update(Boss);
		Update(Angie);
		Update(Star);
		Update(Rufus);
		Update(Presto);
		m_Bubble->Update();
	}

	return 1;
}


int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	Release(Amp);
	Release(Octo);
	Release(Boss);
	Release(Star);
	Release(Angie);
	Release(Rufus);
	Release(Presto);
	delete(m_Bubble);
	m_Bubble = nullptr;

	Release(Background);
	

	DeleteObject(hBM);

	DeleteDC(MemoryDC);
	DeleteDC(ScreenDC);

	bIsActive = false;

	PostQuitMessage(0);

	return 1;
}



void Run()
{
	char strBuffer[16];
	//RECT rtImg = { 0, 0, 640, 480 };


	Draw(Background);
	//����� �׸���. -> �ĸ���ۿ�




	//��������Ʈ ĳ���͸� �׸���. -> �ĸ���ۿ�
	Draw(Amp);
	Draw(Octo);
	Draw(Boss);
	Draw(Star);
	Draw(Angie);
	Draw(Rufus);
	Draw(Presto);
	m_Bubble->Render();


	INPUT->Update();

	////������ǥ��
	sprintf(strBuffer, "FPS = %3d", nFPS);
	TextOut(MemoryDC, 0, 0, strBuffer, strlen(strBuffer));

	//�ĸ���ۿ��� ������۷� �̵�
	BitBlt(ScreenDC, 0, 0, WIDTH, HEIGHT, MemoryDC, 0, 0, SRCCOPY);

	nCount++;
}