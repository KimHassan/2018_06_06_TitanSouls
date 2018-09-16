#include "stdafx.h"
#include "database.h"

HRESULT database::init()
{
	loadDatabase("savefile.txt");
	thisTime = 0;
	return S_OK;
}

void database::release()
{
	
}
void database::save()
{
	iterElement mIter = _mTotalElement.find("0");
	//char str[128];
	//
	//string sss = str;

	//TXTDATA->txtSave("savefile.txt", );
	HANDLE file;

	char str[128];
	sprintf(str,"|,0,%d,%d,%d,%d,%d,|", mIter->second->time, mIter->second->death, mIter->second->boss_count, mIter->second->x, mIter->second->y);

	DWORD write;

	//속성값에, 붙인 것들을 str에 복사한다

	file = CreateFile("savefile.txt", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);
	CloseHandle(file);
}
void database::loadDatabase(string name)
{
	arrElements vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());

	string str;
	int count = 0;



	/*elements* em = new elements;
	int i = 0;
	str = vTemp[i + 1];
	_mTotalElement.insert(pair<string, elements*>(vTemp[i + 1], em));

	iterElement mIter = _mTotalElement.find(str);

	if (i == count + 1) mIter->second->time = atoi(vTemp[i].c_str());
	else if (i == count + 2) mIter->second->time = atoi(vTemp[i].c_str());
	else if (i == count + 3) mIter->second->death = atoi(vTemp[i].c_str());
	else if (i == count + 4) mIter->second->boss_count = atoi(vTemp[i].c_str());
	else if (i == count + 5) mIter->second->x = atof(vTemp[i].c_str());
	else if (i == count + 6) mIter->second->y = atof(vTemp[i].c_str());
*/
	//0		   1  		  2	         3	     4		5
	//슬롯		시간      죽음		 보스	 x		y
	for(int i = 0; i < vTemp.size(); i++)
	{
		if (vTemp[i] == "|")
		{
			elements* em = new elements;
			str = vTemp[i + 1];

			_mTotalElement.insert(pair<string, elements*>(vTemp[i + 1], em));

		}

		iterElement mIter = _mTotalElement.find(str);
		if (i == count + 1) mIter->second->time = atoi(vTemp[i].c_str());
		else if (i == count + 2) mIter->second->time = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->death = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->boss_count = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->x = atof(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->y = atof(vTemp[i].c_str());
	}
	vTemp.clear();
}

void database::setTime(string str, int t)
{
	iterElement mIter = _mTotalElement.find(str);

	mIter->second->time = t;
}

void database::setDeath(string str, int d)
{
	iterElement mIter = _mTotalElement.find(str);

	mIter->second->death = d;
}

void database::setBoss(string str, int b)
{
	iterElement mIter = _mTotalElement.find(str);
	mIter->second->boss_count = b;
}

void database::setXY(string str, float x, float y)
{
	iterElement mIter = _mTotalElement.find(str);
	mIter->second->x = x;
	mIter->second->y = y;
}
