#pragma once
#include "gameNode.h"
class LoginScene :
	public gameNode
{
	image *bg;
	image *cursor;
	bool start;
	int fade;
	bool saveScene;

	char kill[128];
	char death[128];
	char time[128];


public:
	HRESULT init();
	void update();
	void render();
	void release();
	LoginScene();
	~LoginScene();
};

