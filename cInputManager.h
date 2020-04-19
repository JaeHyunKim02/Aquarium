#pragma once
#include"H_lib.h"
#include"Singleton.h"

class cInputManager : public Singleton<cInputManager>
{
private:
	HWND m_hWnd;

	bool NowMouse[2];
	bool OldMouse[2];

	bool NowInput[256];
	bool OldInput[256];

public:


public:
	cInputManager();
	virtual	~cInputManager();
	
	bool MouseLPress();
	bool MouseLUp();
	bool MouseLDown();

	bool MouseRPress();
	bool MouseRUp();
	bool MouseRDown();

	bool KeyPress(int key);
	bool KeyUp(int key);
	bool KeyDown(int key);

	void Init(HWND hWnd);
	void Update();

	POINT GetMousePos() {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(m_hWnd, &pt);
		
		return pt;

	}
};
#define INPUT cInputManager::GetInstance()