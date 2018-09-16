#include "stdafx.h"
#include "cubeScene.h"


cubeScene::cubeScene()
{

}


cubeScene::~cubeScene()
{
}

HRESULT cubeScene::init()
{

	SOUNDMANAGER->Allstop();
	SOUNDMANAGER->play("cube_scene");
	bg = IMAGEMANAGER->addImage("cube_map", "Image/cube_map.bmp", 1867, 1501, false, RGB(255, 0, 255));
	bg_collision = IMAGEMANAGER->addImage("cube_map_collision", "Image/cube_map_collision.bmp", 1867, 1501, false, RGB(255, 0, 255));
	titan = new Titan;
	titan->init();
	titan->setXY(923, 1037);
	alpha = IMAGEMANAGER->findImage("alpha");
	fade = 255;
	start = true;
	titan->setMap("cube_map_collision");
	titan->getArrow()->setMap("cube_map_collision");
	boss_rc = RectMake(877,493, 127, 127);
	portal = RectMake(859, 1100, 163, 21);
	return S_OK;
}

void cubeScene::update()
{
	CAMERAMANAGER->setSingleFocus(titan->getX(), titan->getY());
	if (start)
	{
		fade -= 2;
		if (fade <= 0)
		{
			fade = 0;
			start = false;
		}
	}

	titan->update();
	if(PtInRect(&boss_rc,PointMake(titan->getArrow()->getX(), titan->getArrow()->getY())))
	{
		titan->getArrow()->Block();
	}
	if (PtInRect(&portal, titan->getPt()))
	{
		SCENEMANAGER->changeScene("ÀÎ°ÔÀÓ¾À");
	}
}

void cubeScene::render()
{
	CAMERAMANAGER->renderMap(getMemDC(), bg,1);
	//bg->render(getMemDC());
	titan->render();
	alpha->alphaRender(getMemDC(), fade);
}

void cubeScene::release()
{
	SAFE_RELEASE(bg);
	SAFE_DELETE(bg);
	SAFE_RELEASE(bg_collision);
	SAFE_DELETE(bg_collision);
	SAFE_RELEASE(alpha);
	SAFE_DELETE(alpha);
	titan->release();
}
