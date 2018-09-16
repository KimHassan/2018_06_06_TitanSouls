#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	_btnSceneChange->init("��ư", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		DATABASE->setElementAngle("battle", DATABASE->getElementData("battle")->angle += 0.2f);
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		DATABASE->setElementAngle("battle", DATABASE->getElementData("battle")->angle -= 0.2f);
	}

	_btnSceneChange->update();
}

void selectScene::render() 
{
	_btnSceneChange->render();
	TextOut(getMemDC(), WINSIZEX / 2 + 150, WINSIZEY / 2, "����Ʈ��!", strlen("����Ʈ��"));
}

void selectScene::cbSceneChange()
{
	SCENEMANAGER->changeScene("��Ÿ��");
}