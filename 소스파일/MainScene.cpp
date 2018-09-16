#include "stdafx.h"
#include "MainScene.h"
#include "golam.h"

HRESULT MainScene::init()
{
	
	titan = new Titan;
	titan->init();
	titan->setXY(4125 / 2, 4615 - 100);

	titan->setXY(DATABASE->getElementsData("0")->x,	DATABASE->getElementsData("0")->y);
	if (titan->getX() > 4125 || titan->getY() > 4615 || titan->getX() < 100)
	{
		titan->setXY(4125 / 2 - 25, 4615 - 100);
	}
	//titan->setXY(1900, 1520);
	DATABASE->setXY("0", 4125 / 2 - 25, 4615 - 100);
	bg = IMAGEMANAGER->addImage("map1", "Image/map.bmp", 4125, 4615,true,RGB(255,0,255));
	bg_collision = IMAGEMANAGER->addImage("map_collision", "Image/map_collision2.bmp", 4125, 4615, false, RGB(0, 0, 0));
	obj1 = IMAGEMANAGER->addImage("obj1", "Image/object1.bmp",228, 364, true, RGB(255, 0, 255));
	obj2 = IMAGEMANAGER->addImage("obj2", "Image/object2.bmp", 196, 320, true, RGB(255, 0, 255));
	obj3 = IMAGEMANAGER->addImage("obj3", "Image/object3.bmp", 1393, 265, true, RGB(255, 0, 255));
	obj4 = IMAGEMANAGER->addImage("obj4", "Image/object4.bmp", 433, 337, true, RGB(255, 0, 255));
	golam = new Golam;
	golam->setXY(1830, 1120);
	golam->init();
	golam->setTitan(titan);
	titan->setBoss(golam);
	titan->setMap("map_collision");
	titan->getArrow()->setMap("map_collision_arrow");
	golam_fight = false;
	golam_Rect = RectMake(1986,1070,146,118 );


	alpha = IMAGEMANAGER->findImage("alpha");
	fade = 255;
	start = true;
	dead = false;
	SOUNDMANAGER->Allstop();
	SOUNDMANAGER->play("main");

	cube_scene = RectMake(1195, 2456, 190, 127);
	ice_scene = RectMake(2760, 2338, 141, 242);
	cube_scene_count = 0;
	ice_scene_count = 0;
	return S_OK;
}

void MainScene::setGolam()
{
	golam_fight = true;
}
void MainScene::update()
{
	//CAMERAMANAGER->setSingleFocus(titan->getX(), titan->getY());
	//DATABASE->setTime("0", TIMEMANAGER->getWorldTime());
	//DATABASE->save();
	if (start)
	{
		fade -= 2;
		if (fade <= 0)
		{
			fade = 0;
			start = false;
		}
	}
	if (golam_fight)
	{
		golam->update();
		if (golam->isHeat())
		{
			golam_fight = false;
		}
	}
	titan->update();
	RECT temp;
	if (IntersectRect(&temp, &golam_Rect, &titan->getArrow()->getRect()) && golam_fight == false)
	{
		SOUNDMANAGER->pause("main");
		SOUNDMANAGER->play("boss");
		setGolam();
		titan->getArrow()->PowerOff();

	}
	if (titan->getDead())
	{
		fade += 2;
		if (fade >= 255)
		{
			fade = 255;
			SCENEMANAGER->changeScene("ÀÎ°ÔÀÓ¾À");
		}
	}

	if (PtInRect(&cube_scene, titan->getPt()))
	{
		cube_scene_count++;
		fade += 20;
		if (cube_scene_count > 30)
		{
			DATABASE->setXY("0", cube_scene.left + 50, cube_scene.bottom + 100);
			SCENEMANAGER->changeScene("Å¥ºê¾À");
		}
	}
	else
	{
		cube_scene_count = 0;

	}
	if (PtInRect(&ice_scene, titan->getPt()))
	{
		ice_scene_count++;
		fade += 20;
		if (ice_scene_count > 30)
		{
			DATABASE->setXY("0", ice_scene.left + 50, ice_scene.bottom + 100);
			SCENEMANAGER->changeScene("Å¥ºê¾À");
		}
	}
	else
	{
		ice_scene_count = 0;

	}

}

void MainScene::render()
{

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		CAMERAMANAGER->renderMap(getMemDC(), bg_collision, scale / 2);
	}
	else
	{
		CAMERAMANAGER->renderMap(getMemDC(), bg, scale / 2);
	}
	if (golam_fight)
	{
		golam->BodyRender();
		if(!golam->bossJun())
			CAMERAMANAGER->renderObject(getMemDC(), obj4, 1844, 1138);
	}
	if (golam_fight)
	{

		golam->UpRender();
	
	}
	titan->render();
	if (golam_fight)
	{
		golam->DownRender();
	}

	CAMERAMANAGER->renderObject(getMemDC(), obj1, 2707, 2245);
	CAMERAMANAGER->renderObject(getMemDC(), obj2, 1195, 2276);
	CAMERAMANAGER->renderObject(getMemDC(), obj3, 1357, 1765);


	alpha->alphaRender(getMemDC(), fade);

	//char str[128];
	//sprintf(str, "DB: %d %d %d %d %d",
	//	DATABASE->getElementsData("0")->time,
	//	DATABASE->getElementsData("0")->death,
	//	DATABASE->getElementsData("0")->boss_count,
	//	DATABASE->getElementsData("0")->x,
	//	DATABASE->getElementsData("0")->y
	//);
	//TextOut(getMemDC(), 200, 700, str, strlen(str));
}

void MainScene::release()
{
	titan->release();
	bg->release();
	//if (golam_fight)
	//{
	//	golam->release();
	//}

	SAFE_RELEASE(bg);
	SAFE_RELEASE(bg_collision);
	SAFE_DELETE(bg);
	SAFE_DELETE(bg_collision);
}

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}
