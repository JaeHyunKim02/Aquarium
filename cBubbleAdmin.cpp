#include "cBubbleAdmin.h"
#include"H_lib.h"

#include "cBubbleAdmin.h"

#include "cBubble.h"


cBubbleAdmin::cBubbleAdmin(HWND hwnd,HDC Ang)
	:Ong(Ang), m_hwnd(hwnd)
{
}


cBubbleAdmin::~cBubbleAdmin()
{
	Release();
}

void cBubbleAdmin::Init()
{
}

void cBubbleAdmin::Update()
{

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_hwnd, &pt);

	if (GetAsyncKeyState(VK_LBUTTON))
		m_Bubble.push_back(new cBubble(pt.x, pt.y, Ong));

	for (auto iter : m_Bubble)
		iter->Update();

	for (auto iter = m_Bubble.begin(); iter != m_Bubble.end();) {
		if ((*iter)->GetDel()) {
			delete(*iter);
			*iter = NULL;

			iter = m_Bubble.erase(iter);
		}
		else
			++iter;
	}
}

void cBubbleAdmin::Render()
{
	for (auto iter : m_Bubble)
		iter->Render();
}

void cBubbleAdmin::Release()
{
	for (auto iter : m_Bubble) {
		delete(iter);
		iter = NULL;
	}
	m_Bubble.clear();
}

//cBubbleAdmin::cBubbleAdmin()
//{
//
//}
//
//cBubbleAdmin::~cBubbleAdmin()
//{
//	Release();
//
//}
//
//void cBubbleAdmin::Init(HDC hdc)
//{
//	m_HDC = hdc;
//}
//
//void cBubbleAdmin::Update()
//{
//
//	if (INPUT->KeyDown('S')) {
//		m_Bubble.push_back(new cBubble(100,100,m_HDC));
//	}
//	for (auto iter : m_Bubble) {//생성된 모든 객체를 돌림
//		iter->Update();
//	}
//
//	for (auto iter = m_Bubble.begin(); iter != m_Bubble.end();) {
//		if ((*iter)->GetDel()) {
//			delete(*iter);
//			*iter - NULL;
//
//			iter = m_Bubble.erase(iter);
//
//		}
//		else
//			++iter;
//
//	}
//}
//
//void cBubbleAdmin::Render()
//{
//	for (auto iter : m_Bubble) {//생성된 모든 객체를 돌림
//		iter->Render();
//	}
//
//}
//
//void cBubbleAdmin::Release()
//{
//	for (auto iter : m_Bubble) {
//		delete(iter);
//		iter = NULL;
//	}
//
//	m_Bubble.clear();//벡터를 다 없앰 이래야 누수 안남
//}
