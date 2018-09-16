#pragma once
#include "gameNode.h"
class Titan;
class Boss :
	public gameNode
{
protected:
	float x, y;
	Titan *titan;
	UINT count;


public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	void setTitan(Titan* _titan) { titan = _titan; }
	void setXY(float _x, float _y) { x = _x; y = _y; }
	virtual RECT getAtackRect();
	virtual RECT getHeartRect();
	virtual RECT getAtackRect2();
	Boss();
	~Boss();
};

