#pragma once
#include"H_lib.h"
class cBubble;
class cBubbleAdmin
{
private:
	HDC Ong;
	vector<cBubble *> m_Bubble;
	HWND m_hwnd;
public:
	cBubbleAdmin(HWND hwnd, HDC Ang);
	~cBubbleAdmin();
	
	void Init();
	void Update();
	void Render();
	void Release();
};

//#pragma once
//#include"H_lib.h"
//
//class cBubble;
//class cBubbleAdmin {
//private:
//	vector <cBubble *> m_Bubble;
//	HDC m_HDC;
//public:
//	cBubbleAdmin();
//	~cBubbleAdmin();
//
//	void Init(HDC hdc);
//	void Update();
//	void Render();
//	void Release();
//
//};