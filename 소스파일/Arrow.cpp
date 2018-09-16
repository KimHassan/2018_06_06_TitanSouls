#include "stdafx.h"
#include "Arrow.h"


HRESULT ARROW::init(int _x, int _y)
{
	image = IMAGEMANAGER->addFrameImage("Arrow", "Image/arrow.bmp", 0, 0, 11, 88, 1, 8, true, RGB(255, 0, 255));
	x = _x;
	y = _y;
	powerDown = false;
	isStop = false;
	power = 0;
	return S_OK;
}


void ARROW::update()
{


		if ((angle > 0 && angle < PI2 / 16 * 1) || (angle > PI2 / 16 * 15 && angle < PI2))
		{// || (angle > PI2 / 16 * 15 && angle < PI2)
			direction = ARROWDIRECTION::RIGHT;
			rc = RectMake(x, y + 4, 2, 3);
			image->setFrameY(0);
		}
		else if (angle > PI2 / 16 * 1 && angle < PI2 / 16 * 3)
		{
			direction = ARROWDIRECTION::RIGHTUP;
			rc = RectMake(x + 9, y, 2 * 3, 2 * 3);
			image->setFrameY(4);
		}
		else if (angle > PI2 / 16 * 3 && angle < PI2 / 16 * 5)
		{
			direction = ARROWDIRECTION::UP;
			rc = RectMake(x + 4, y, 3 * 3, 2 * 3);
			image->setFrameY(2);
		}
		else if (angle > PI2 / 16 * 5 && angle < PI2 / 16 * 7)
		{
			direction = ARROWDIRECTION::LEFTUP;
			rc = RectMake(x, y, 2 * 3, 2 * 3);
			image->setFrameY(6);
		}
		else if (angle > PI2 / 16 * 7 && angle < PI2 / 16 * 9)
		{
			direction = ARROWDIRECTION::LEFT;
			rc = RectMake(x + 9, y + 4, 2 * 3, 3 * 3);
			image->setFrameY(1);
		}
		else if (angle > PI2 / 16 * 9 && angle < PI2 / 16 * 11)
		{
			direction = ARROWDIRECTION::LEFTDOWN;
			rc = RectMake(x, y + 9, 2 * 3, 2 * 3);
			image->setFrameY(7);
		}
		else if (angle > PI2 / 16 * 11 && angle < PI2 / 16 * 13)
		{
			direction = ARROWDIRECTION::DOWN;
			rc = RectMake(x + 4, y + 9, 3 * 3, 2 * 3);
			image->setFrameY(3);
		}
		else if (angle > PI2 / 16 * 13 && angle < PI2 / 16 * 15)
		{
			direction = ARROWDIRECTION::RIGHTDOWN;
			rc = RectMake(x + 9, y + 9, 2 * 3, 2 * 3);
			image->setFrameY(5);
		}
	
	rc = RectMakeCenter(x +10 , y  + 10, 15, 15);
	
}

void ARROW::move()
{

	if (isStop)
	{
		
	}
	else
	{
		x += cosf(angle) * power;
		y += -sinf(angle) * power;
	}
	COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), x, y);

	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);

	if ((r == 255 && g == 0 && b == 255))
	{
		Block();

		x += cosf(angle)  * 7;
		y += -sinf(angle) * 7;
	}
}


void ARROW::render(int scale)
{
	CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), image, x, y, scale);
	//image->scaleFrameRender(getMemDC(), x, y, scale);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
	char str[126];
	sprintf(str, "%d", power);
	TextOut(getMemDC(), 700, 400, str, strlen(str));
}

void ARROW::Shot()
{
}

ARROW::ARROW()
{
}


ARROW::~ARROW()
{
}

void ARROW::Block()
{
	if (power > 0)
	{
		//SOUNDMANAGER->play("ArrowImpact1");
	}
	powerDown = true;
	if (power <= 0)
	{

	}
	else
	{
		power = 10;
	}
	if (angle > PI)
	{
		angle = angle - PI;
	}
	else
	{
		angle = angle + PI;
	}
}
void ARROW::release()
{
	SAFE_RELEASE(image);
	SAFE_DELETE(image);
}