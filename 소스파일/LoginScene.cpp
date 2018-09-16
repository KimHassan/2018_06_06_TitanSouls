#include "stdafx.h"
#include "LoginScene.h"


HRESULT LoginScene::init()
{
	bg = IMAGEMANAGER->addFrameImage("login", "Image/login.bmp", 4096, 768,4,1, true, RGB(255, 0, 255));
	cursor = IMAGEMANAGER->addImage("cursor", "Image/cursor.bmp", 26, 30, true, RGB(255, 0, 255));
	
	cursor->setX(230);
	cursor->setY(170);
	bg->setFrameX(0);
	start = false;
	fade = 255;
	saveScene = false;

		SOUNDMANAGER->play("login");
	sprintf(death,"%3d", DATABASE->getElementsData("0")->death);
	sprintf(kill, "%3d", DATABASE->getElementsData("0")->boss_count);
	int t = DATABASE->getElementsData("0")->time;
	int h = t / 3600;
	int m = t / 60;
	int s = t % 60;
	sprintf(time, "%02d : %02d : %02d", h,m,s);
	return S_OK;
}

void LoginScene::update()
{
	if (start)
	{
		fade	+= 2;
		if (fade >= 255)
		{
			release();
			int minusTime = TIMEMANAGER->getWorldTime();
			DATABASE->saveTime(minusTime);
			SOUNDMANAGER->pause("login");
			SCENEMANAGER->changeScene("ÀÎ°ÔÀÓ¾À");
		}
	}
	else
	{
		if (fade > 0)
		{
			fade -= 2;
			if (fade <= 0)
				fade = 0;
		}
		if (bg->getFrameX() == 3)
		{
			if (KEYMANAGER->isOnceKeyDown('C'))
			{
				bg->setFrameX(0);
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				cursor->setY(cursor->getY() + 130);
				if (cursor->getY() >= 170 + 130 * 4)
				{
					cursor->setY(170);
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				cursor->setY(cursor->getY() - 130);
				if (cursor->getY() < 170)
				{
					cursor->setY(170 + 130 * 3);
				}
			}
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				SOUNDMANAGER->play("click");
				start = true;
			}
			if (KEYMANAGER->isOnceKeyDown('C'))
			{
				bg->setFrameX(0);
			}
		}
		else
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				bg->setFrameX(bg->getFrameX() + 1);
				if (bg->getFrameX() >= 3)
				{
					bg->setFrameX(0);

				}

			}

			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				if (bg->getFrameX() <= 0)
				{
					bg->setFrameX(3);
				}
				bg->setFrameX(bg->getFrameX() - 1);

			}
			if (bg->getFrameX() == 0)
			{
				if (KEYMANAGER->isOnceKeyDown('X'))
				{
					SOUNDMANAGER->play("click");
					bg->setFrameX(3);
				}
			}

		}

	}
}

void LoginScene::render()
{
	bg->frameRender(getMemDC(),0,0);
	if (bg->getFrameX() == 3)
	{
		cursor->render(getMemDC());
		HFONT font, oldFont;
		font = CreateFont(20, 0, 0, 0, 600, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("°ß°íµñ"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		TextOut(getMemDC(), 425, 147, kill, strlen(kill));
		TextOut(getMemDC(), 425, 170, death, strlen(death));
		TextOut(getMemDC(), 425, 195, time, strlen(time));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
	}
	IMAGEMANAGER->findImage("alpha")->alphaRender(getMemDC(), fade);
	
	
}
LoginScene::LoginScene()
{
}


LoginScene::~LoginScene()
{
	
}

void LoginScene::release()
{
	SAFE_RELEASE(cursor);
	SAFE_RELEASE(bg);
	SAFE_DELETE(cursor);
	SAFE_DELETE(bg);
}