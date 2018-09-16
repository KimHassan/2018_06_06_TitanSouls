#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

HRESULT gameNode::init()
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if ( _managerInit )
	{
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		SOUNDMANAGER->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
		DATABASE->init();
		CAMERAMANAGER->init();
	}

	return S_OK;
}

void gameNode::release()
{
	if ( _managerInit )
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		INIDATA->releaseSingleton();
		DATABASE->releaseSingleton();
		CAMERAMANAGER->releaseSingleton();
	}
	
	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update()	
{
	//InvalidateRect(_hWnd, NULL, false);
}

void gameNode::render(void)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//HWND : 윈도우 핸들
	//iMessage : 메시지 구분 번호
	//wParam : 키보드 입력 및 마우스 클릭 구분
	//lParam : 마우스 좌표 입력

	PAINTSTRUCT ps;
	HDC			hdc;		//Handle Device Context

	switch (iMessage)
	{
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;

		//윈도우 창이 종료될때 발생하는 메시지
		case WM_DESTROY:
			if (TIMEMANAGER->getWorldTime() > DATABASE->getSaveTime() || DATABASE->getSaveTime()==0)
			{
				DATABASE->setTime("0", DATABASE->getElementsData("0")->time + TIMEMANAGER->getWorldTime() - DATABASE->getSaveTime());
				//DATABASE->setTime("0", 100);
				DATABASE->save();
			}
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
