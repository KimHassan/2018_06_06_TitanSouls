#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	scale = 2;
	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ư", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("alpha", "Image/alpha.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("map_collision_arrow", "Image/map_collision_arrow.bmp", 4125, 4615, false, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("main", "SOUND/main.mp3", true, true);
	SOUNDMANAGER->addSound("cube_scene", "SOUND/cube_scene.mp3", true, true);
	SOUNDMANAGER->addSound("boss", "SOUND/boss.mp3", true, true);
	SOUNDMANAGER->addSound("login", "SOUND/login.mp3", true, true);
	SOUNDMANAGER->addSound("click", "SOUND/click.mp3", false, false);
	SOUNDMANAGER->addSound("roll", "SOUND/Roll.ogg", false, false);
	SOUNDMANAGER->addSound("arrow_charge", "SOUND/arrow_charge.ogg", false, false);
	SOUNDMANAGER->addSound("arrow_retrieval", "SOUND/arrow_retrieval.ogg", false, false);
	SOUNDMANAGER->addSound("arrow_shoot", "SOUND/arrow_shoot.ogg", false, false);
	SOUNDMANAGER->addSound("ArrowImpact1", "SOUND/ArrowImpact1.ogg", false, false);
	SOUNDMANAGER->addSound("Hit1", "SOUND/Hit1.ogg", false, false);
	SCENEMANAGER->addScene("�ΰ��Ӿ�", new MainScene);
	SCENEMANAGER->addScene("�α��ξ�", new LoginScene);
	SCENEMANAGER->addScene("ť���", new cubeScene);
	//����Ʈ������ �ٲ۴�
	SCENEMANAGER->changeScene("�α��ξ�");

	return S_OK;
}

void playGround::release()
{
	gameNode::release();

}

void playGround::update()
{
	gameNode::update();

	

	SCENEMANAGER->update();
	
}
void playGround::render(void)
{
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================================
	//IMAGEMANAGER->findImage("���")->render(getMemDC());

	SCENEMANAGER->render();
	

	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());
	//==================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
