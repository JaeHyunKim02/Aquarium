#include "cInputManager.h"



cInputManager::cInputManager()
{
}


cInputManager::~cInputManager()
{
}

bool cInputManager::MouseLPress()//마우스 누르는 중
{
	return (NowMouse[0] == true && OldMouse[0] == true);//지금도 누르고 있고 아까도 누르고 있음

}

bool cInputManager::MouseLUp()//마우스 땜
{
	return (NowMouse[0] ==false &&OldMouse[0]==true);//지금은 안누르고 있지만 방금 누르고 있었음
}

bool cInputManager::MouseLDown()//마우스 누름
{
	
	return (NowMouse[0] ==true&&OldMouse[0]==false);//지금  눌렀고 아까는 안누름
}

bool cInputManager::MouseRPress()
{
	return (NowMouse[1] == true && OldMouse[1] == true);
}

bool cInputManager::MouseRUp()
{
	return (NowMouse[1] == false && OldMouse[1] == true);
}

bool cInputManager::MouseRDown()
{
	return (NowMouse[1] == true && OldMouse[1] == false);

}

bool cInputManager::KeyPress(int key)
{
	return (NowInput[key] == true && OldInput[key] == true);
}

bool cInputManager::KeyUp(int key)
{
	
	return (NowInput[key] == false && OldInput[key] == true);
}

bool cInputManager::KeyDown(int key)
{
	return (NowInput[key] == true && OldInput[key] == false);
}

void cInputManager::Init(HWND hWnd)
{
	m_hWnd = hWnd;

}

void cInputManager::Update()
{
	for (int i = 0; i < 2; i++) {
		OldMouse[0] = NowMouse[0];
	}

	for (int i = 0; i < 256; i++) {
		OldInput[i] = NowInput[i];
	}

	for (int i = 0; i < 256; i++) {
		if (GetAsyncKeyState(i)) {
			NowInput[i] = true;
		}
		else
			NowInput[i] = false;

	}
	if (GetAsyncKeyState(VK_LBUTTON)) {
		NowMouse[0] = true;
	}
	
	else
		NowMouse[0] = false;
	
	if (GetAsyncKeyState(VK_RBUTTON)) {
		NowMouse[1] = true;
	}
	
	else
		NowMouse[1] = false;
}

