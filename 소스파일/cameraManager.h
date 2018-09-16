#pragma once
#include "singletonBase.h"
#include "image.h"
#include <vector>

struct tagMULTICAM
{
	int camNum;
	float destX;
	float destY;
	float cameraWidth;
	float focusX;
	float focusY;
	float width;
	float height;
};

class cameraManager : public singletonBase<cameraManager>
{
private:
	float _focusX;
	float _focusY;
	float _width;
	float _height;
	BLENDFUNCTION	_blendFunc;		//알파블렌드 함수
	vector<tagMULTICAM> _vMulticam;
	vector<tagMULTICAM>::iterator _viMulticam;

public:
	HRESULT init(void);
	void release(void);

	void setSingleFocus(float x, float y);
	void setSingleFocus(float x, float y, float width);
	void setDoubleFocus(float x1, float y1, float x2, float y2, float blankRatio);
	void setMulticam(int camNum, float destX, float destY, float width);
	float getX(float x);
	float getY(float y);
	float getMousePointX(float mousePtX);
	float getMousePointY(float mousePtY);

	void renderBackground(HDC hdc, image* img);
	void renderBackground(HDC hdc, image* img, int camNum);
	void renderMap(HDC hdc, image* img,float scale);

	void renderMap(HDC hdc, image* img, int x, int y);
	//void renderMap(HDC hdc, image* img, int camNum);
	void renderObject(HDC hdc, image* img, float destX, float destY);
	void renderObject(HDC hdc, image* img, int camNum, float destX, float destY);
	void halfRenderObject(HDC hdc, image* img, float destX, float destY);
	void frameRenderObject(HDC hdc, image* img, float destX, float destY);
	void aniRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY);
	void aniRenderObject(HDC hdc, image* img, int camNum, animation* ani, float destX, float destY);
	void aniHalfRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY);
	void scaleFrameRenderObject(HDC hdc, image* img, float destX, float destY, float scale);
	void scaleAniRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY, float scale);
	void scaleRenderObject(HDC hdc, image* img, float destX, float destY,float scale);
	void scaleAlphaRenderObject(HDC hdc, image * img, int destX, int destY, float scale, BYTE alpha);
	cameraManager();
	~cameraManager();
};

