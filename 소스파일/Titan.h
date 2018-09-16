#pragma once
#include "gameNode.h"
#include "Arrow.h"

class Boss;
enum class PLAYERDIRECTION
{
	RIGHT_STOP,
	LEFT_STOP,
	UP_STOP,
	DOWN_STOP,
	RIGHTUP_STOP,
	RIGHTDOWN_STOP,
	LEFTUP_STOP,
	LEFTDOWN_STOP,

	RIGHT_MOVE,
	LEFT_MOVE,
	UP_MOVE,
	DOWN_MOVE,
	RIGHTUP_MOVE,
	RIGHTDOWN_MOVE,
	LEFTUP_MOVE,
	LEFTDOWN_MOVE,

	RIGHT_ROLL,
	LEFT_ROLL,
	UP_ROLL,
	DOWN_ROLL,
	RIGHTUP_ROLL,
	RIGHTDOWN_ROLL,
	LEFTUP_ROLL,
	LEFTDOWN_ROLL,

	RIGHT_DEAD,
	LEFT_DEAD,
	UP_DEAD,
	DOWN_DEAD,
	RIGHTUP_DEAD,
	RIGHTDOWN_DEAD,
	LEFTUP_DEAD,
	LEFTDOWN_DEAD,

	RIGHT_SHOT,
	LEFT_SHOT,
	UP_SHOT,
	DOWN_SHOT,
	RIGHTUP_SHOT,
	RIGHTDOWN_SHOT,
	LEFTUP_SHOT,
	LEFTDOWN_SHOT,

	RIGHT_RELOAD,
	LEFT_RELOAD,
	UP_RELOAD,
	DOWN_RELOAD,
	RIGHTUP_RELOAD,
	RIGHTDOWN_RELOAD,
	LEFTUP_RELOAD,
	LEFTDOWN_RELOAD,
};

class Titan : public gameNode
{

	PLAYERDIRECTION playerDirection;

	image* _image;
	float _x,  _y;
	RECT _rc;
	float move_speed;
	float roll_speed;
	float power;
	bool isShot;
	bool shot_ready;
	ARROW* Arrow;
	bool ArrowPulling;
	animation* playerMotion;

	bool ShowArrow;

	float shotDelay;
	Boss *boss;
	bool isShotDirection;

	POINT rt;
	POINT rb;
	POINT lt;
	POINT lb;

	POINT pt;

	bool isDead;
	bool isShake;

	string pxCollision;
	


public:
	Titan();
	~Titan();

	HRESULT init();
	void release();
	void update();
	void render();
	void setBoss(Boss * b) { boss = b; }
	static void RightStopMotion(void* obj);
	static void LeftStopMotion(void* obj);
	static void UpStopMotion(void* obj);
	static void DownStopMotion(void* obj);
	static void RightUpStopMotion(void* obj);
	static void RightDownStopMotion(void* obj);
	static void LeftUpStopMotion(void* obj);
	static void LeftDownStopMotion(void* obj);
	//static void rightStop(void* obj);
	//static void leftStop(void* obj);
	//static void upStop(void* obj);
	//static void downStop(void* obj);
	//static void rightSitFire(void* obj);
	//static void leftSitFire(void* obj);

	void ShotReady();
	void Shot();
	PLAYERDIRECTION getPlayerDirection() {return playerDirection;}
	void setPlayerDirection(PLAYERDIRECTION direction) { playerDirection = direction; }

	animation* getPlayerMotion(void) { return playerMotion; }
	void setPlayertMotion(animation* ani) { playerMotion = ani; }

	RECT getRect() { return _rc; }
	RECT getArrowRect() { return Arrow->getRect(); }
	ARROW *getArrow() { return Arrow; }
	void setXY(float x, float y) {_x = x;	_y = y;}
	POINT getPt() { return pt; }
	void Dead();
	bool getDead() { return isDead; }
	float getX() { return _x; }
	float getY() { return _y; }
	void shake();
	void setMap(string str) {
		pxCollision = str;
	}
};

