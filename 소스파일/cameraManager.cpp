#include "stdafx.h"
#include "cameraManager.h"


cameraManager::cameraManager()
{
}


cameraManager::~cameraManager()
{

}

HRESULT cameraManager::init(void)
{
	return S_OK;
}

void cameraManager::release(void)
{

}

void cameraManager::renderBackground(HDC hdc, image* img)
{
	GdiTransparentBlt(hdc,
		0, 0, WINSIZEX, WINSIZEY,
		img->getMemDC(),
		0, 0,
		img->getWidth(), img->getHeight(),
		RGB(255, 0, 255));
}

void cameraManager::renderBackground(HDC hdc, image* img, int camNum)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt(hdc,
				_viMulticam->destX, _viMulticam->destY, _viMulticam->width, _viMulticam->width * WINSIZEY / WINSIZEX,
				img->getMemDC(),
				0, 0,
				img->getWidth(), img->getHeight(),
				RGB(255, 0, 255));

			break;
		}
	}
}

void cameraManager::renderMap(HDC hdc, image* img,float scale)
{
	scale = 1;
	if (_width >= img->getWidth())
	{
		_width = img->getWidth();
	
		_height = _width * WINSIZEY / WINSIZEX;

	}
	if (_height >= img->getHeight())
	{
		_height = img->getHeight();
		_width = _height * WINSIZEX / WINSIZEY;
	}
	if (_focusX <= _width / 2) _focusX = _width / 2;
	if (_focusX >= img->getWidth() - _width / 2) _focusX = img->getWidth() - _width / 2;
	if (_focusY <= _height / 2) _focusY = _height / 2;
	if (_focusY >= img->getHeight() - _height / 2) _focusY = img->getHeight() - _height / 2;
	GdiTransparentBlt(
		hdc,
		0,
		0, 
		WINSIZEX * scale,
		WINSIZEY *scale,
		img->getMemDC(), 
		_focusX - _width / 2,
		_focusY - _height / 2,
		_width,
		_height,
		RGB(255, 0, 255)
	);
}

void cameraManager::renderMap(HDC hdc, image* img, int x, int y)
{
	if (_width >= img->getWidth())
	{
		_width = img->getWidth() + x;
		_height = _width * WINSIZEY / WINSIZEX;
	}
	if (_height >= img->getHeight())
	{
		_height = img->getHeight();
		_width = _height * WINSIZEX / WINSIZEY;
	}
	if (_focusX <= _width / 2) _focusX = _width / 2;
	if (_focusX >= img->getWidth() - _width / 2) _focusX = img->getWidth() - _width / 2;
	if (_focusY <= _height / 2) _focusY = _height / 2;
	if (_focusY >= img->getHeight() - _height / 2) _focusY = img->getHeight() - _height / 2;
	GdiTransparentBlt(hdc, 0 + x, 0, WINSIZEX, WINSIZEY, img->getMemDC(), _focusX - _width / 2, _focusY - _height / 2, _width, _height, RGB(255, 0, 255));
}

//void cameraManager::renderMap(HDC hdc, image* img, int camNum)
//{
//	if (_width >= img->getWidth())
//	{
//		_width = img->getWidth();
//		_height = _width * WINSIZEY / WINSIZEX;
//	}
//	if (_height >= img->getHeight())
//	{
//		_height = img->getHeight();
//		_width = _height * WINSIZEX / WINSIZEY;
//	}
//	if (_focusX <= _width / 2) _focusX = _width / 2;
//	if (_focusX >= img->getWidth() - _width / 2) _focusX = img->getWidth() - _width / 2;
//	if (_focusY <= _height / 2) _focusY = _height / 2;
//	if (_focusY >= img->getHeight() - _height / 2) _focusY = img->getHeight() - _height / 2;
//	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
//	{
//		if (_viMulticam->camNum == camNum)
//		{
//			GdiTransparentBlt(hdc,
//				_viMulticam->destX, _viMulticam->destY, _viMulticam->width, _viMulticam->width * WINSIZEY / WINSIZEX,
//				img->getMemDC(),
//				_focusX - _width / 2,
//				_focusY - _height / 2,
//				_width, _height,
//				RGB(255, 0, 255));
//
//			break;
//		}
//	}
//}

void cameraManager::renderObject(HDC hdc, image* img, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getWidth() * WINSIZEX / _width,
		img->getHeight() * WINSIZEY / _height,
		img->getMemDC(),
		0, 0,
		img->getWidth(),
		img->getHeight(),
		RGB(255, 0, 255));
}

void cameraManager::scaleRenderObject(HDC hdc, image* img, float destX, float destY,float scale)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getWidth() * WINSIZEX / _width * scale,
		img->getHeight() * WINSIZEY / _height * scale,
		img->getMemDC(),
		0, 0,
		img->getWidth(),
		img->getHeight(),
		RGB(255, 0, 255));
}

void cameraManager::renderObject(HDC hdc, image* img, int camNum, float destX, float destY)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt
			(hdc,
				_viMulticam->destX + (destX - _focusX + _width / 2) * (_viMulticam->width) / _width,
				_viMulticam->destY + (destY - _focusY + _height / 2) * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getWidth() * (_viMulticam->width) / _width,
				img->getHeight() * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getMemDC(),
				0, 0,
				img->getWidth(),
				img->getHeight(),
				RGB(255, 0, 255));
		}
	}
}

void cameraManager::halfRenderObject(HDC hdc, image* img, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getWidth() / 2 * WINSIZEX / _width,
		img->getHeight() / 2 * WINSIZEY / _height,
		img->getMemDC(),
		0, 0,
		img->getWidth(),
		img->getHeight(),
		RGB(255, 0, 255));
}

void cameraManager::frameRenderObject(HDC hdc, image* img, float destX, float destY)
{
	GdiTransparentBlt(
		hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getFrameWidth() * WINSIZEX / _width,
		img->getFrameHeight() * WINSIZEY / _height,
		img->getMemDC(),
		img->getFrameX() * img->getFrameWidth(),
		img->getFrameY() * img->getFrameHeight(),
		img->getFrameWidth(),
		img->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::scaleFrameRenderObject(HDC hdc, image* img, float destX, float destY,float scale)
{
	GdiTransparentBlt(
		hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width ,
		(destY - _focusY + _height / 2) * WINSIZEY / _height ,
		img->getFrameWidth() * WINSIZEX / _width * scale,
		img->getFrameHeight() * WINSIZEY / _height * scale,
		img->getMemDC(),
		img->getFrameX() * img->getFrameWidth(),
		img->getFrameY() * img->getFrameHeight(),
		img->getFrameWidth(),
		img->getFrameHeight(),
		RGB(255, 0, 255));
}
void cameraManager::scaleAlphaRenderObject(HDC hdc,image * img, int destX, int destY, float scale, BYTE alpha)
{
	//실제 이미지에 알파블렌드를 접목시켜주는 함수
	_blendFunc.SourceConstantAlpha = alpha;		//0 ~ 255 로 투명도를 가진다


	BitBlt(img->getMemDC(), 0, 0, img->getFrameWidth() * WINSIZEX / _width * scale, img->getFrameHeight() * WINSIZEY / _height * scale,
		hdc, (destX - _focusX + _width / 2) * WINSIZEX / _width, (destY - _focusY + _height / 2) * WINSIZEY / _height, SRCCOPY);

	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getWidth() * WINSIZEX / _width * scale,
		img->getHeight() * WINSIZEY / _height * scale,
		img->getMemDC(),
		0, 0,
		img->getWidth(),
		img->getHeight(),
		RGB(255, 0, 255));

	AlphaBlend(hdc, (destX - _focusX + _width / 2) * WINSIZEX / _width, (destY - _focusY + _height / 2) * WINSIZEY / _height, img->getWidth(), img->getHeight(), img->getMemDC(), 0, 0, img->getWidth(), img->getHeight(), _blendFunc);

}
void cameraManager::aniRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		ani->getFrameWidth() * WINSIZEX / _width,
		ani->getFrameHeight() * WINSIZEY / _height,
		img->getMemDC(),
		ani->getFramePos().x, ani->getFramePos().y,
		ani->getFrameWidth(),
		ani->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::scaleAniRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY,float scale)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2)  * WINSIZEX / _width  +  (ani->getFrameWidth() * WINSIZEX / _width * scale)  / 2  - (ani->getFrameWidth() * WINSIZEX / _width/2),
		(destY - _focusY + _height / 2) * WINSIZEY / _height + (ani->getFrameHeight() * WINSIZEY / _height * scale) / 2 - (ani->getFrameHeight() * WINSIZEY / _height / 2),
		ani->getFrameWidth() * WINSIZEX / _width * scale,
		ani->getFrameHeight() * WINSIZEY / _height * scale,
		img->getMemDC(),
		ani->getFramePos().x,
		ani->getFramePos().y,
		ani->getFrameWidth(),
		ani->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::aniRenderObject(HDC hdc, image* img, int camNum, animation* ani, float destX, float destY)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt
			(hdc,
				_viMulticam->destX + (destX - _focusX + _width / 2) * (_viMulticam->width) / _width,
				_viMulticam->destY + (destY - _focusY + _height / 2) * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				ani->getFrameWidth() * (_viMulticam->width) / _width,
				ani->getFrameHeight() * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getMemDC(),
				ani->getFramePos().x, ani->getFramePos().y,
				ani->getFrameWidth(),
				ani->getFrameHeight(),
				RGB(255, 0, 255));
		}
	}
}

void cameraManager::aniHalfRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		ani->getFrameWidth() / 2 * WINSIZEX / _width,
		ani->getFrameHeight() / 2 * WINSIZEY / _height,
		img->getMemDC(),
		ani->getFramePos().x, ani->getFramePos().y,
		ani->getFrameWidth(),
		ani->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::setSingleFocus(float x, float y)
{
	_focusX = x;
	_focusY = y;
	_width = WINSIZEX;
	_height = WINSIZEY;
}

void cameraManager::setSingleFocus(float x, float y, float width)
{
	_focusX = x;
	_focusY = y;
	_width = width;
	_height = width * WINSIZEY / WINSIZEX;
}

void cameraManager::setDoubleFocus(float x1, float y1, float x2, float y2, float blankRatio)
{
	if (x1 >= x2)
	{
		_width = (x1 - x2) + (WINSIZEX * blankRatio);
	}
	else if (x2 >= x1)
	{
		_width = (x2 - x1) + (WINSIZEX * blankRatio);
	}
	_height = _width * WINSIZEY / WINSIZEX;
	_focusX = (x1 + x2) / 2;
	_focusY = (y1 + y2) / 2;
}

void cameraManager::setMulticam(int camNum, float destX, float destY, float width)
{
	tagMULTICAM temp;
	temp.camNum = camNum;
	temp.destX = destX;
	temp.destY = destY;
	temp.width = width;
	_vMulticam.push_back(temp);
}

float cameraManager::getX(float x)
{
	return (x - _focusX + _width / 2) * WINSIZEX / _width;
}
float cameraManager::getY(float y)
{
	return (y - _focusY + _height / 2) * WINSIZEY / _height;
}

float cameraManager::getMousePointX(float mousePtX)
{
	return (_focusX - _width / 2 + mousePtX * _width / WINSIZEX);
}

float cameraManager::getMousePointY(float mousePtY)
{
	return (_focusY - _height / 2 + mousePtY * _height / WINSIZEY);
}