#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>


class elements
{
public:
	int time;
	int death;
	int boss_count;

	
	float x;
	float y;

};

class database : public singletonBase<database>
{
private:
	typedef vector<string> arrElements;
	typedef vector<string>::iterator iterElements;

	typedef map<string, elements*> arrElement;
	typedef map<string, elements*>::iterator iterElement;

	arrElement _mTotalElement;

	int thisTime;
public:
	HRESULT init();
	void release();
	void loadDatabase(string name);



	void setTime(string str, int t);
	void setDeath(string str, int d);
	void setBoss(string str, int b);
	void setXY(string str, float x, float y);
	void saveTime(int b) {
		thisTime = b;
	}
	int getSaveTime() {
		return thisTime;
	};

	elements* getElementsData(string str) {
		return _mTotalElement.find(str)->second;
	}
	void save();
};