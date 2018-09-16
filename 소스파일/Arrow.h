#pragma once
#include "gameNode.h"

enum class ARROWDIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFTUP,
	LEFTDOWN,
	RIGHTUP,
	RIGHTDOWN
};

class ARROW :
	public gameNode
{
private:
	image * image;
	RECT rc;
	float x;
	float y;
	float angle;
	ARROWDIRECTION direction;
	int scale;
	bool powerDown;
	bool isStop;
	float power;
	string pxCollision;

public:
	HRESULT init(int _x, int _y);
	void update();
	void render(int scale);
	void release();
	void Shot();
	ARROW();
	~ARROW();

	float getX() { return x; }
	float getY() { return y; }
	void setX(float _x) { x = _x; }
	void setY(float _y) { y = _y; }
	void setXY(float _x, float _y) { x = _x; y = _y; }
	void move();
	ARROWDIRECTION getDirection() { return direction; }
	void setDirection(ARROWDIRECTION _direction) { direction = _direction; }
	float getAngle() { return angle; }
	void setAngle(float _angle) { angle = _angle; }
	void Block();
	void Stop() { isStop = true; }
	void StartMove() { isStop = false; }
	void setPower(float _power) { power = _power; }
	RECT getRect() { return rc; }
	float getPower() { return power; }
	void PowerOff() { power = 0; }
	void setMap(string str) {
		pxCollision = str;
	}

};

