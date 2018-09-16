#pragma once
#include "gameNode.h"
#include "Titan.h"

class cubeScene :
	public gameNode
{
	image *bg;
	image *bg_collision;
	image *alpha;
	int fade;
	bool start;
	RECT boss_rc;
	RECT portal;

	Titan *titan;
	
public:
	cubeScene();
	~cubeScene();
	HRESULT init();
	void update();
	void render();
	void release();
};

