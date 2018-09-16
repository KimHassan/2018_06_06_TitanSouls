#pragma once
#include "gameNode.h"
#include "MainScene.h"
#include "LoginScene.h"
#include "cubeScene.h"
class playGround : public gameNode
{
private:
	

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);

	

	playGround();
	~playGround();
};

