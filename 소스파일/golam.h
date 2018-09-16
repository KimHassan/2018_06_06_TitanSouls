#pragma once
#include "gameNode.h"
#include "Boss.h"


struct part
{
	image* img;
	RECT rc;
	float x;
	float y;
	

};
class Golam :
	public Boss
{
private:
	part LeftFist;
	part RightFist;
	part body;
	part head;
	part LeftShadow;
	part RightShadow;
	bool atack_start;
	bool isAtack;
	float LeftFistY;
	float RightFistY;
	float speed;
	bool LeftAtack;
	RECT heart;
	bool heat;
	UINT delay;
	float myScale;

	bool startFight;

	int count;
	UINT st;

	image *explosion;
	bool isDead;
public:
	Golam();
	~Golam();
	HRESULT init();
	void update();
	void render();
	void UpRender();
	void DownRender();
	void BodyRender();
	void release();
	void atackReady();
	void atack();
	void start();
	RECT getAtackRect() { return LeftFist.rc; }
	RECT getAtackRect2() { return RightFist.rc; }
	RECT getHeartRect() { return body.rc; }
	RECT getLeftFist() { return LeftFist.rc; }
	RECT getRightFist() {return RightFist.rc;}
	RECT getBody()		 { return body.rc; }
	bool bossJun() {
		return startFight;
	}

	bool isHeat() {
		return heat;
	}
	
};

