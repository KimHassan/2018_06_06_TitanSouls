#include "stdafx.h"
#include "golam.h"
#include "Titan.h"


Golam::Golam()
{
}


Golam::~Golam()
{
}

HRESULT Golam::init()
{
	myScale = 3;
	body.img = IMAGEMANAGER->addImage("golam_body", "Image/golam_body.bmp", 160, 110, true, RGB(255, 0, 255));
	LeftFist.img = IMAGEMANAGER->addFrameImage("golam_fist", "Image/golam_fist.bmp", 94 + 47, 90,3,2, true, RGB(255, 0, 255));
	RightFist.img = IMAGEMANAGER->addFrameImage("golam_fist2", "Image/golam_fist.bmp", 94 + 47, 90, 3, 2, true, RGB(255, 0, 255));
	head.img = IMAGEMANAGER->addFrameImage("golam_head", "Image/golam_head.bmp", 265, 55, 5, 1, true, RGB(255, 0, 255));
	LeftShadow.img = IMAGEMANAGER->addImage("golam_shadow", "Image/golam_shadow.bmp", 39, 20, true, RGB(255, 0, 255));
	RightShadow.img = IMAGEMANAGER->addImage("golam_shadow", "Image/golam_shadow.bmp", 39, 20, true, RGB(255, 0, 255));
	explosion = IMAGEMANAGER->addFrameImage("explosion", "Image/explosion.bmp", 832, 62,26,1, true, RGB(255, 0, 255));

	body.x = x;
	body.y = y;
	body.rc = RectMake(body.x, body.y, body.img->getWidth() * myScale, body.img->getHeight() * myScale);
	heart = RectMakeCenter(body.x + 78 * myScale, body.y + 52 * myScale, 20 * myScale, 20 * myScale);
	head.x = body.x + 53 * myScale;
	head.y = body.y - 32 * myScale;
	head.rc = RectMake(head.x, head.y, head.img->getFrameWidth() * myScale, head.img->getFrameHeight() * myScale);

	RightFist.x = body.x + 113 * myScale + 20;
	RightFist.y = body.y + 43 * myScale - 100;


	RightFist.rc = RectMake(RightFist.x, RightFist.y, 
		RightFist.img->getFrameWidth() * myScale,
		RightFist.img->getFrameHeight() *myScale);

	RightFist.img->setFrameY(1);
	//LeftFist.x = heart.left; 
	//LeftFist.y = heart.bottom + 110;
	LeftFist.x = body.x + myScale - 20;
	LeftFist.y = body.y + 43 * myScale - 100;
	LeftFist.img->setFrameY(0);
	LeftFist.rc = RectMake(LeftFist.x, LeftFist.y,
		LeftFist.img->getFrameWidth() *  myScale,
		LeftFist.img->getFrameHeight() * myScale);

	LeftShadow.x = LeftFist.x + 20;
	LeftShadow.y = LeftFist.y + 200;

	RightShadow.x = RightFist.x + 20;
	RightShadow.y = RightFist.y + 200;


	atack_start = false;
	isAtack = false;
	LeftAtack = true;
	speed = 4;
	heat = false;
	startFight = false;
	delay = 100;
	
	st = y - 300;
	count = 0;
	isDead = false;
	return S_OK;
}

void Golam::update()
{
	if(isDead)
	{
		count++;
		if (count % 3 == 0)
		{
			explosion->setFrameX(explosion->getFrameX() + 1);
			if (explosion->getFrameX() > explosion->getMaxFrameX())
			{
				heat = true;
			}
		}
	}
	else
	{
		if (startFight == false)
		{
			body.y -= 3;
			head.y = body.y - 32 * myScale;
			if (body.y <= st)
			{
				body.rc = RectMake(body.x, body.y, body.img->getWidth() * myScale, body.img->getHeight() * myScale);
				heart = RectMakeCenter(body.x + 78 * myScale, body.y + 52 * myScale, 30 * myScale, 30 * myScale);
				startFight = true;
			}
		}
		else
		{
			if (PtInRect(&heart, PointMake(titan->getArrow()->getX(), titan->getArrow()->getX())))
			{
				isDead = true;
			}
			delay++;
			RightFist.rc = RectMake(RightFist.x, RightFist.y + 80,
				RightFist.img->getFrameWidth() * myScale,
				(RightFist.img->getFrameHeight() - 30)* myScale);
			LeftFist.rc = RectMake(LeftFist.x, LeftFist.y + 80,
				LeftFist.img->getFrameWidth() * myScale,
				(LeftFist.img->getFrameHeight() - 30) * myScale);
			count++;
			if (count % 10 == 0)
			{
				head.img->setFrameX(head.img->getFrameX() + 1);
				if (head.img->getFrameX() >= head.img->getMaxFrameX())
				{
					head.img->setFrameX(0);
				}
			}
			if (!isAtack)
				atackReady();
			else
				atack();
			//RECT temp;

			RECT temp;
			if (IntersectRect(&temp, &titan->getArrow()->getRect(), &heart))
			{
				isDead = true;
			}
			if (PtInRect(&LeftFist.rc, titan->getPt()) && isAtack && atack_start && getDistance(LeftFist.x,LeftFist.y,LeftShadow.x,LeftShadow.y) < 50)
			{
				titan->Dead();
			}
			else if (PtInRect(&RightFist.rc, titan->getPt()) && isAtack && atack_start && getDistance(RightFist.x, RightFist.y, RightShadow.x, RightShadow.y) < 50)
			{
				titan->Dead();
			}
		}
	}
}

void Golam::UpRender()
{
	if (heat)
	{

	}
	else
	{
		if (titan->getRect().bottom > LeftShadow.y)
		{
			CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), LeftShadow.img, LeftShadow.x, LeftShadow.y, myScale, 100);
		}
		if (titan->getRect().bottom > RightShadow.y)
		{
			CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), RightShadow.img, RightShadow.x, RightShadow.y, myScale, 100);
		}
		if (titan->getRect().top > LeftFist.rc.bottom)
		{
			CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), LeftFist.img, LeftFist.x, LeftFist.y, myScale);
		}
		if (titan->getRect().top > RightFist.rc.bottom)
		{
			CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), RightFist.img, RightFist.x, RightFist.y, myScale);
		}
	}

}
void Golam::DownRender()
{
	if (heat)
	{

	}
	else
	{
		if (titan->getRect().bottom < LeftShadow.y)
		{
			CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), LeftShadow.img, LeftShadow.x, LeftShadow.y, myScale, 100);
		}
		if (titan->getRect().bottom < RightShadow.y)
		{
			CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), RightShadow.img, RightShadow.x, RightShadow.y, myScale, 100);
		}
		if (titan->getRect().top <= LeftFist.rc.bottom)
		{
			CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), LeftFist.img, LeftFist.x, LeftFist.y, myScale);
		}
		if (titan->getRect().top <= RightFist.rc.bottom)
		{
			CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), RightFist.img, RightFist.x, RightFist.y, myScale);
		}
	}

}

void Golam::BodyRender()
{

	if (heat)
	{

	}
	else
	{
		CAMERAMANAGER->scaleRenderObject(getMemDC(), body.img, body.x, body.y, myScale);
		CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), head.img, head.x, head.y, myScale);
		if (isDead)
		{
			CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), explosion, body.x + 100, body.y - 70, myScale + 6);
		}
	}
}
void Golam::render()
{
	if (heat)
	{

	}
	else
	{
		CAMERAMANAGER->scaleRenderObject(getMemDC(), body.img, body.x, body.y, myScale);
		CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), head.img, head.x, head.y, myScale);
		CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), RightFist.img, RightFist.x, RightFist.y, myScale);
		CAMERAMANAGER->scaleFrameRenderObject(getMemDC(), LeftFist.img, LeftFist.x, LeftFist.y, myScale);
		CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), LeftShadow.img, LeftShadow.x, LeftShadow.y, myScale, 100);
		CAMERAMANAGER->scaleAlphaRenderObject(getMemDC(), RightShadow.img, RightShadow.x, RightShadow.y, myScale, 100);
		//	CAMERAMANAGER->renderObject(getMemDC(), body.img, body.x, body.y);

		//body.img->scaleRender(getMemDC(), body.x, body.y, scale);
		//head.img->scaleFrameRender(getMemDC(), head.x, head.y, scale);
		//RightFist.img->scaleFrameRender(getMemDC(), RightFist.x, RightFist.y, scale);
		//LeftFist.img->scaleFrameRender(getMemDC(), LeftFist.x, LeftFist.y, scale);
		//LeftShadow.img->alphaScaleRender(getMemDC(), LeftShadow.x, LeftShadow.y, scale - 1, 126);
		//RightShadow.img->alphaScaleRender(getMemDC(), RightShadow.x, RightShadow.y, scale - 1, 126);

		if (KEYMANAGER->isToggleKey(VK_F1))
		{

			Rectangle(getMemDC(), head.rc.left, head.rc.top, head.rc.right, head.rc.bottom);
			Rectangle(getMemDC(), RightFist.rc.left, RightFist.rc.top, RightFist.rc.right, RightFist.rc.bottom);
			Rectangle(getMemDC(), LeftFist.rc.left, LeftFist.rc.top, LeftFist.rc.right, LeftFist.rc.bottom);
			//Rectangle(getMemDC(), body.rc.left, body.rc.top, body.rc.right, body.rc.bottom);

			Rectangle(getMemDC(), heart.left, heart.top, heart.right, heart.bottom);
		}


	}
}

void Golam::release()
{
	SAFE_RELEASE(LeftFist.img);
	SAFE_RELEASE(LeftFist.img);
	SAFE_RELEASE(RightFist.img);
	SAFE_RELEASE(body.img);
	SAFE_RELEASE(head.img);
	SAFE_RELEASE(LeftShadow.img);

	SAFE_DELETE(LeftFist.img);
	SAFE_DELETE(LeftFist.img);
	SAFE_DELETE(RightFist.img);
	SAFE_DELETE(body.img);
	SAFE_DELETE(head.img);
	SAFE_DELETE(LeftShadow.img);
}

void Golam::atack()
{
	if (LeftAtack)
	{
		RightFist.img->setFrameX(2);
		RightFist.x += cosf(getAngle(RightShadow.x, RightShadow.y, heart.left, heart.bottom + 150)) * (speed - 2);
		RightFist.y += -sinf(getAngle(RightShadow.x, RightShadow.y, heart.left, heart.bottom + 150)) *(speed - 2);
		RightShadow.x = RightFist.x + 20;
		RightShadow.y = RightFist.y + 200;
		RightFist.rc = RectMake(RightFist.x, RightFist.y,
			RightFist.img->getFrameWidth() * myScale,
			(RightFist.img->getFrameHeight() - 10) * myScale);
		if (delay > 50)
		{
			RECT temp2;
			if (IntersectRect(&temp2, &titan->getArrow()->getRect(), &RightFist.rc))
			{
				titan->getArrow()->Block();
				delay = 0;
			}
		}
		if (atack_start)
		{
			LeftFist.img->setFrameX(0);
			LeftFist.y += speed;
			if (LeftFist.y + 50 > LeftShadow.y)
			{
				SOUNDMANAGER->play("Hit1");
				titan->shake();
				atack_start = false;
			}
		}
		else
		{
			LeftFist.img->setFrameX(1);
			LeftFist.y -= speed;
			if (LeftFist.y < LeftFistY)
			{
				isAtack = false;
				LeftAtack = false;
			}
		}
	}
	else
	{
		LeftFist.img->setFrameX(2);
		LeftFist.x += cosf(getAngle(LeftShadow.x, LeftShadow.y, heart.left, heart.bottom + 150)) * (speed - 2);
		LeftFist.y += -sinf(getAngle(LeftShadow.x, LeftShadow.y, heart.left, heart.bottom + 150)) *(speed - 2);
		LeftFist.rc = RectMake(LeftFist.x, LeftFist.y,
			LeftFist.img->getFrameWidth() * myScale,
			(LeftFist.img->getFrameHeight() - 10) * myScale);
		LeftShadow.x = LeftFist.x + 20;
		LeftShadow.y = LeftFist.y + 200;
		if (delay > 50)
		{
			RECT temp;
			if (IntersectRect(&temp, &titan->getArrow()->getRect(), &LeftFist.rc))
			{
				titan->getArrow()->Block();
				delay = 0;
			}
		}
		if (atack_start)
		{
			RightFist.img->setFrameX(0);
			RightFist.y += speed;
			if (RightFist.y + 50 > RightShadow.y)
			{
				SOUNDMANAGER->play("Hit1");
				titan->shake();
				atack_start = false;
			}
		}
		else
		{
			RightFist.img->setFrameX(1);
			RightFist.y -= speed;
			if (RightFist.y < RightFistY)
			{
				isAtack = false;
				LeftAtack = true;
			}
		}
	}
	
}

void Golam::atackReady()
{
	if (LeftAtack)
	{
		if (delay > 50)
		{
			RECT temp2;
			if (IntersectRect(&temp2, &titan->getArrow()->getRect(), &RightFist.rc))
			{
				titan->getArrow()->Block();
				delay = 0;
			}
		}
		RightFist.img->setFrameX(2);
		RightFist.x += cosf(getAngle(RightShadow.x, RightShadow.y,  heart. left,heart.bottom + 150)) * (speed -2);
		RightFist.y += -sinf(getAngle(RightShadow.x, RightShadow.y, heart.left, heart.bottom + 150)) * (speed -2);
		RightShadow.x = RightFist.x + 20;
		RightShadow.y = RightFist.y + 200;
		RightFist.rc = RectMake(RightFist.x, RightFist.y,
			RightFist.img->getFrameWidth() * myScale,
			(RightFist.img->getFrameHeight() - 10) * myScale);
		LeftFist.img->setFrameX(1);


		LeftShadow.x += cosf(getAngle(LeftShadow.x, LeftShadow.y, titan->getRect().left - 50  , titan->getRect().top - 20)) * speed ;
		LeftShadow.y += -sinf(getAngle(LeftShadow.x, LeftShadow.y, titan->getRect().left -50, titan->getRect().top   - 20)) * speed ;
		LeftFist.x = LeftShadow.x - 20;
		LeftFist.y = LeftShadow.y - 200;

		if (getDistance(LeftShadow.x, LeftShadow.y, titan->getRect().left - 50 , titan->getRect().top - 20) < 3)
		{
			LeftFistY = LeftFist.y;
			atack_start = true;
			isAtack = true;
		}
	}
	else
	{
		if (delay > 50)
		{
			RECT temp;
			if (IntersectRect(&temp, &titan->getArrow()->getRect(), &LeftFist.rc))
			{
				titan->getArrow()->Block();
				delay = 0;
			}
		}
		LeftFist.img->setFrameX(2);
		LeftFist.x += cosf(getAngle(LeftShadow.x, LeftShadow.y,  heart.left, heart.bottom + 150)) * (speed-2);
		LeftFist.y += -sinf(getAngle(LeftShadow.x, LeftShadow.y, heart.left, heart.bottom + 150)) * (speed-2);
		LeftShadow.x = LeftFist.x + 20;
		LeftShadow.y = LeftFist.y + 200;
		LeftFist.rc = RectMake(LeftFist.x, LeftFist.y,
			LeftFist.img->getFrameWidth() * myScale,
			(LeftFist.img->getFrameHeight() - 10) * myScale);

		RightFist.img->setFrameX(1);
		RightShadow.x += cosf( getAngle(RightShadow.x, RightShadow.y, titan->getRect().left - 50 , titan->getRect().top - 20)) * speed;
		RightShadow.y += -sinf(getAngle(RightShadow.x, RightShadow.y, titan->getRect().left - 50,  titan->getRect().top - 20)) * speed;
		RightFist.x = RightShadow.x - 20;
		RightFist.y = RightShadow.y - 200;

		if (getDistance(RightShadow.x , RightShadow.y, titan->getRect().left - 50, titan->getRect().top - 20) < 3)
		{
			RightFistY = RightFist.y;
			atack_start = true;
			isAtack = true;
		}
	}


}

void Golam::start()
{



}