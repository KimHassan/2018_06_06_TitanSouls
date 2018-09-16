#pragma once
#include "gameNode.h"
#include "Titan.h"
#include "golam.h"

class MainScene :
	public gameNode
{
	Titan *titan;
	Golam *golam;
	image *bg;
	image *bg_collision;

	image *obj1;
	image *obj2;
	image *obj3;
	image *obj4;
	RECT cube_scene;
	RECT ice_scene;
	UINT cube_scene_count;
	UINT ice_scene_count;

	RECT golam_Rect;
	bool golam_fight;

	image *alpha;
	int fade;
	bool start;
	bool end;
	bool dead;
public:
	HRESULT init();
	void update();
	void render();
	void release();
	void setGolam();
	MainScene();
	~MainScene();
};

