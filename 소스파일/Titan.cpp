#include "stdafx.h"
#include "Titan.h"


Titan::Titan()
{
}


Titan::~Titan()
{
}

HRESULT Titan::init()
{
	KEYANIMANAGER->deleteAll();
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_image = IMAGEMANAGER->addFrameImage("player", "Image/player.bmp", 0, 0, 400, 288, 25, 18, true, RGB(255, 0, 255));
	_rc = RectMake(_x + 5, _y + 12, _image->getFrameWidth() * scale,_image->getFrameHeight() * scale);
	Arrow = new ARROW;
	Arrow->init(_rc.left + 3,_rc.top  + 3 );
	ArrowPulling = false;
	playerDirection = PLAYERDIRECTION::RIGHT_STOP;


	int rightStop[] = {0};
	KEYANIMANAGER->addArrayFrameAnimation("playerRightStop", "player", rightStop, 1, 1, true);
	int upStop[] = { 25 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUpStop", "player", upStop, 1, 1, true);
	int leftStop[] = { 50 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftStop", "player", leftStop, 1, 1, true);
	int downStop[] = { 75 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownStop", "player", downStop, 1, 1, true);
	int rightdownStop[] = { 100 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownStop", "player", rightdownStop, 1, 1, true);
	int leftdownStop[] = { 125 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownStop", "player", leftdownStop, 1, 1, true);
	int leftupStop[] = { 150 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpStop", "player", leftupStop, 1, 1, true);
	int rightupStop[] = { 175 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpStop", "player", rightupStop, 1, 1, true);


	int rightMove[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "player", rightMove, 6, 6, true);
	int upMove[] = { 25,26,27,28,29,30 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUpMove", "player", upMove, 6, 6, true);
	int leftMove[] = { 50,51,52,53,54,55 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftMove", "player", leftMove, 6, 6, true);
	int downMove[] = { 75,76,77,78,79,80 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownMove", "player", downMove, 6, 6, true);
	int rightdownMove[] = { 100,101,102,103,104,105 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownMove", "player", rightdownMove, 6,6, true);
	int leftdownMove[] = { 125,126,127,128,129,130 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownMove", "player", leftdownMove, 6, 6, true);
	int leftupMove[] = { 150,151,152,153,154,155 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpMove", "player", leftupMove, 6, 6, true);
	int rightupMove[] = { 175,176,177,178,179,180 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpMove", "player", rightupMove, 6, 6, true);


	int rightRoll[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightRoll", "player", rightRoll, 6, 10,		false, RightStopMotion,this);
	int upRoll[] = { 31,32,33,34,35,36};
	KEYANIMANAGER->addArrayFrameAnimation("playerUpRoll", "player", upRoll, 6, 10,				false, UpStopMotion,this);
	int leftRoll[] = { 56,57,58,59,60,61 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftRoll", "player", leftRoll, 6, 10,			false, LeftStopMotion,this);
	int downRoll[] = { 81,82,83,84,85,86 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownRoll", "player", downRoll, 6, 10,			false, DownStopMotion,this);
	int rightdownRoll[] = { 106,107,108,109,110,111 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownRoll", "player", rightdownRoll, 6, 10,false, RightDownStopMotion,this);
	int leftdownRoll[] = { 131,132,133,134,135,136 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownRoll", "player", leftdownRoll, 6, 10,  false, LeftDownStopMotion, this);
	int leftupRoll[] = { 156,157,158,159,160,161 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpRoll", "player", leftupRoll, 6, 10,		false, LeftUpStopMotion, this);
	int rightupRoll[] = { 181,182,183,184,185,186 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpRoll", "player", rightupRoll, 6, 10,	false, RightUpStopMotion, this);

	int rightDead[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDead", "player", rightDead, 1, 1, true);
	int upDead[] = { 37 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUpDead", "player", upDead, 1, 1, true);
	int leftDead[] = { 62 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDead", "player", leftDead, 1, 1, true);
	int downDead[] = { 87 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownDead", "player", downDead, 1, 1, true);
	int rightdownDead[] = { 112 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownDead", "player", rightdownDead, 1, 1, true);
	int leftdownDead[] = { 137 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownDead", "player", leftdownDead, 1, 1, true);
	int leftupDead[] = { 162 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpDead", "player", leftupDead, 1, 1, true);
	int rightupDead[] = { 187 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpDead", "player", rightupDead, 1, 1, true);


	int rightShot[] = { 13 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightShot", "player", rightShot, 1, 1, false);
	int upShot[] = { 38 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUpShot", "player", upShot, 1, 1, false);
	int leftShot[] = { 63 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftShot", "player", leftShot, 1, 1, false);
	int downShot[] = { 88 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownShot", "player", downShot, 1, 1, false);
	int rightdownShot[] = { 113 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownShot", "player", rightdownShot, 1, 1, false);
	int leftdownShot[] = { 138 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownShot", "player", leftdownShot, 1, 1, false);
	int leftupShot[] = { 163 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpShot", "player", leftupShot, 1, 1, false);
	int rightupShot[] = { 188 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpShot", "player", rightupShot, 1, 1, false);

	int rightReload[] = { 14 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightReload", "player", rightReload, 1, 1, true);
	int upReload[] = { 39 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUpReload", "player", upReload, 1, 1, true);
	int leftReload[] = { 64 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftReload", "player", leftReload, 1, 1, true);
	int downReload[] = { 89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDownReload", "player", downReload, 1, 1, true);
	int rightdownReload[] = { 114 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownReload", "player", rightdownReload, 1, 1, true);
	int leftdownReload[] = { 139 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownReload", "player", leftdownReload, 1, 1, true);
	int leftupReload[] = { 164 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftUpReload", "player", leftupReload, 1, 1, true);
	int rightupReload[] = { 189 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightUpReload", "player", rightupReload, 1, 1, true);

	
	playerMotion = KEYANIMANAGER->findAnimation("playerUpStop");
	move_speed = 3;
	roll_speed = 5;
	power = 0;
	isShot = false;
	shot_ready = false;
	ShowArrow = false;
	isShotDirection = false;
	shotDelay = 100;
	isDead = false;


	return S_OK;
}

void Titan::release()
{
	SAFE_RELEASE(_image);
	SAFE_DELETE(_image);
	//SAFE_DELETE(boss);
	//KEYANIMANAGER->release();
	//Arrow->release();
}

void Titan::shake()
{
	isShake = true;
	CAMERAMANAGER->setSingleFocus(_x + 10, _y);
}

void Titan::update()
{
	if (isShake)
	{
		CAMERAMANAGER->setSingleFocus(_x -10, _y);
		isShake = false;
	}
	else
	{


		CAMERAMANAGER->setSingleFocus(_x, _y);
	}
	if (shotDelay >= 1)
	{
		shotDelay+= 1;
	}

	_rc = RectMake(_x + 5, _y + 12, _image->getFrameWidth() * scale, _image->getFrameHeight() * scale);


	rt = PointMake(_rc.right - 10, _rc.top);
	rb = PointMake(_rc.right - 10, _rc.bottom);
	lt = PointMake(_rc.left, _rc.top);
	lb = PointMake(_rc.left, _rc.bottom);

	pt = PointMake(_rc.left + (_rc.right - _rc.left) / 2, _rc.top + (_rc.bottom - _rc.top) / 2);
	if (isDead)
	{
	}
	else
	{
		switch (playerDirection) // 플레이어 움직임 변경
		{
		case PLAYERDIRECTION::UP_MOVE:
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				playerDirection = PLAYERDIRECTION::RIGHTUP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightUpMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				playerDirection = PLAYERDIRECTION::LEFTUP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpMove");
				playerMotion->start();
			}
		}
		break;
		case PLAYERDIRECTION::DOWN_MOVE:
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				playerDirection = PLAYERDIRECTION::RIGHTDOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightDownMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				playerDirection = PLAYERDIRECTION::LEFTDOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownMove");
				playerMotion->start();
			}
		}
		break;
		case PLAYERDIRECTION::LEFT_MOVE:
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				playerDirection = PLAYERDIRECTION::LEFTDOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				playerDirection = PLAYERDIRECTION::LEFTUP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpMove");
				playerMotion->start();
			}
			break;
		case PLAYERDIRECTION::RIGHT_MOVE:
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				playerDirection = PLAYERDIRECTION::RIGHTDOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightDownMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				playerDirection = PLAYERDIRECTION::RIGHTUP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightUpMove");
				playerMotion->start();
			}
			break;
		case PLAYERDIRECTION::RIGHTUP_MOVE:
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				playerDirection = PLAYERDIRECTION::UP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerUpMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				playerDirection = PLAYERDIRECTION::RIGHT_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
				playerMotion->start();
			}
			break;
		case PLAYERDIRECTION::RIGHTDOWN_MOVE:
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				playerDirection = PLAYERDIRECTION::DOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerDownMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				playerDirection = PLAYERDIRECTION::RIGHT_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
				playerMotion->start();
			}
			break;
		case PLAYERDIRECTION::LEFTDOWN_MOVE:
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				playerDirection = PLAYERDIRECTION::DOWN_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerDownMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				playerDirection = PLAYERDIRECTION::LEFT_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
				playerMotion->start();
			}
			break;
		case PLAYERDIRECTION::LEFTUP_MOVE:
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				playerDirection = PLAYERDIRECTION::UP_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerUpMove");
				playerMotion->start();
			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				playerDirection = PLAYERDIRECTION::LEFT_MOVE;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
				playerMotion->start();
			}
			break;
		}

		if (playerDirection == PLAYERDIRECTION::DOWN_ROLL ||
			playerDirection == PLAYERDIRECTION::UP_ROLL ||
			playerDirection == PLAYERDIRECTION::LEFT_ROLL ||
			playerDirection == PLAYERDIRECTION::RIGHT_ROLL ||
			playerDirection == PLAYERDIRECTION::LEFTUP_ROLL ||
			playerDirection == PLAYERDIRECTION::LEFTDOWN_ROLL ||
			playerDirection == PLAYERDIRECTION::RIGHTUP_ROLL ||
			playerDirection == PLAYERDIRECTION::RIGHTDOWN_ROLL
			)
		{
		}
		else // 구르는 동안에는 키 입력 불가
		{
			if (!isShotDirection)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) // 플레이어 움직임
				{

					playerDirection = PLAYERDIRECTION::RIGHT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
					playerMotion->start();

				}
				else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && playerDirection == PLAYERDIRECTION::RIGHT_MOVE)
				{

					playerDirection = PLAYERDIRECTION::RIGHT_STOP;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightStop");
					playerMotion->start();
				}

				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					playerDirection = PLAYERDIRECTION::LEFT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
					playerMotion->start();
				}
				else if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && playerDirection == PLAYERDIRECTION::LEFT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::LEFT_STOP;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftStop");
					playerMotion->start();
				}

				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{

					playerDirection = PLAYERDIRECTION::UP_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerUpMove");
					playerMotion->start();

				}
				else if (KEYMANAGER->isOnceKeyUp(VK_UP) && playerDirection == PLAYERDIRECTION::UP_MOVE)
				{
					playerDirection = PLAYERDIRECTION::UP_STOP;
					playerMotion = KEYANIMANAGER->findAnimation("playerUpStop");
					playerMotion->start();
				}
				if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
				{
					playerDirection = PLAYERDIRECTION::DOWN_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerDownMove");
					playerMotion->start();
				}
				else if (KEYMANAGER->isOnceKeyUp(VK_DOWN) && playerDirection == PLAYERDIRECTION::DOWN_MOVE)
				{
					playerDirection = PLAYERDIRECTION::DOWN_STOP;
					playerMotion = KEYANIMANAGER->findAnimation("playerDownStop");
					playerMotion->start();
				}

				if (KEYMANAGER->isOnceKeyDown('X')) // 구르기
				{
					SOUNDMANAGER->play("roll");
					if (playerDirection == PLAYERDIRECTION::LEFT_MOVE || playerDirection == PLAYERDIRECTION::LEFT_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFT_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::UP_MOVE || playerDirection == PLAYERDIRECTION::UP_STOP)
					{
						playerDirection = PLAYERDIRECTION::UP_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerUpRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE || playerDirection == PLAYERDIRECTION::RIGHT_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHT_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::DOWN_MOVE || playerDirection == PLAYERDIRECTION::DOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::DOWN_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerDownRoll");
						playerMotion->start();
					}

					if (playerDirection == PLAYERDIRECTION::RIGHTDOWN_MOVE || playerDirection == PLAYERDIRECTION::RIGHTDOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHTDOWN_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightDownRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::LEFTDOWN_MOVE || playerDirection == PLAYERDIRECTION::LEFTDOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFTDOWN_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::LEFTUP_MOVE || playerDirection == PLAYERDIRECTION::LEFTUP_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFTUP_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpRoll");
						playerMotion->start();
					}
					if (playerDirection == PLAYERDIRECTION::RIGHTUP_MOVE || playerDirection == PLAYERDIRECTION::RIGHTUP_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHTUP_ROLL;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightUpRoll");
						playerMotion->start();
					}
				}
			}

			//쏘기


			if (!isShot)
			{
				if (KEYMANAGER->isStayKeyDown('C') && shotDelay >= 30 &&
					(playerDirection != PLAYERDIRECTION::DOWN_RELOAD || playerDirection != PLAYERDIRECTION::UP_RELOAD
						|| playerDirection != PLAYERDIRECTION::RIGHTDOWN_RELOAD || playerDirection != PLAYERDIRECTION::LEFTDOWN_RELOAD
						|| playerDirection != PLAYERDIRECTION::LEFT_RELOAD || playerDirection != PLAYERDIRECTION::RIGHT_RELOAD
						|| playerDirection != PLAYERDIRECTION::RIGHTUP_RELOAD || playerDirection != PLAYERDIRECTION::LEFTUP_RELOAD)) // 화살 발사
				{
					ShotReady();

					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						playerDirection = PLAYERDIRECTION::LEFT_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftShot");

						playerMotion->start();
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						playerDirection = PLAYERDIRECTION::RIGHT_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightShot");
						playerMotion->start();
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						playerDirection = PLAYERDIRECTION::UP_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerUpShot");
						playerMotion->start();
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						playerDirection = PLAYERDIRECTION::DOWN_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerDownShot");
						playerMotion->start();
					}
					switch (playerDirection)
					{
					case  PLAYERDIRECTION::LEFT_SHOT:
						if (KEYMANAGER->isStayKeyDown(VK_UP) && KEYMANAGER->isStayKeyDown(VK_LEFT))
						{
							playerDirection = PLAYERDIRECTION::LEFTUP_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpShot");
							playerMotion->start();
						}
						if (KEYMANAGER->isStayKeyDown(VK_DOWN) && KEYMANAGER->isStayKeyDown(VK_LEFT))
						{
							playerDirection = PLAYERDIRECTION::LEFTDOWN_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownShot");
							playerMotion->start();
						}
					case  PLAYERDIRECTION::UP_SHOT:
						if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_UP))
						{
							playerDirection = PLAYERDIRECTION::LEFTUP_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpShot");
							playerMotion->start();
						}
						if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_UP))
						{
							playerDirection = PLAYERDIRECTION::RIGHTUP_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightUpShot");
							playerMotion->start();
						}
					case  PLAYERDIRECTION::RIGHT_SHOT:
						if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_UP))
						{
							playerDirection = PLAYERDIRECTION::RIGHTUP_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightUpShot");
							playerMotion->start();
						}
						if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_DOWN))
						{
							playerDirection = PLAYERDIRECTION::RIGHTDOWN_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightDownShot");
							playerMotion->start();
						}
					case  PLAYERDIRECTION::DOWN_SHOT:
						if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_DOWN))
						{
							playerDirection = PLAYERDIRECTION::LEFTDOWN_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownShot");
							playerMotion->start();
						}
						if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_DOWN))
						{
							playerDirection = PLAYERDIRECTION::RIGHTDOWN_SHOT;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightDownShot");
							playerMotion->start();
						}
					}


					scale += 0.2; // 커짐
					if (scale > 2.5)
						scale = 2.5;
					power += 1;
					if (power > 30)
						power = 30;

				}
				if (KEYMANAGER->isOnceKeyUp('C') && shotDelay >= 30 && (playerDirection != PLAYERDIRECTION::DOWN_RELOAD || playerDirection != PLAYERDIRECTION::UP_RELOAD
					|| playerDirection != PLAYERDIRECTION::RIGHTDOWN_RELOAD || playerDirection != PLAYERDIRECTION::LEFTDOWN_RELOAD
					|| playerDirection != PLAYERDIRECTION::LEFT_RELOAD || playerDirection != PLAYERDIRECTION::RIGHT_RELOAD
					|| playerDirection != PLAYERDIRECTION::RIGHTUP_RELOAD || playerDirection != PLAYERDIRECTION::LEFTUP_RELOAD))
				{
					scale = 2;
					isShotDirection = false;
					if (power <= 10)
					{
						ShowArrow = false;
					}
					else
					{
						SOUNDMANAGER->play("arrow_shoot");
						ShowArrow = true;
						Shot();
						shake();
						isShot = true;
						shotDelay = 0;
					}
					Arrow->setPower(power);
					switch (playerDirection)
					{
					case PLAYERDIRECTION::LEFT_SHOT:
						playerDirection = PLAYERDIRECTION::LEFT_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::RIGHT_SHOT:
						playerDirection = PLAYERDIRECTION::RIGHT_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::UP_SHOT:
						playerDirection = PLAYERDIRECTION::UP_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerUpShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::DOWN_SHOT:
						playerDirection = PLAYERDIRECTION::DOWN_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerDownShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::LEFTDOWN_SHOT:
						playerDirection = PLAYERDIRECTION::LEFTDOWN_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::RIGHTDOWN_SHOT:
						playerDirection = PLAYERDIRECTION::RIGHTDOWN_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightDownShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::LEFTUP_SHOT:
						playerDirection = PLAYERDIRECTION::LEFTUP_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpShot");
						playerMotion->start();
						break;

					case PLAYERDIRECTION::RIGHTUP_SHOT:
						playerDirection = PLAYERDIRECTION::RIGHT_STOP;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightUpShot");
						playerMotion->start();
						break;
					}
				}
			}

			if (isShot) // 리로드
			{
				if (KEYMANAGER->isOnceKeyUp('C'))
				{
					SOUNDMANAGER->stop("arrow_retrieval");
				}
				if (KEYMANAGER->isStayKeyDown('C'))
				{
					Arrow->StartMove();
					float temp_angle = getAngle(_x, _y, Arrow->getX(), Arrow->getY());
					Arrow->setPower(5);
					if (temp_angle < PI)
						Arrow->setAngle(PI + temp_angle);
					else
						Arrow->setAngle(temp_angle - PI);
					RECT temp;
					if (IntersectRect(&temp, &_rc, &Arrow->getRect())) //받앗다
					{
						isShot = false;
						ShowArrow = false;
						shotDelay = 1;
						SOUNDMANAGER->stop("arrow_retrieval");
						switch (playerDirection)
						{
						case PLAYERDIRECTION::LEFT_RELOAD:
							playerDirection = PLAYERDIRECTION::LEFT_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::RIGHT_RELOAD:
							playerDirection = PLAYERDIRECTION::RIGHT_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::UP_RELOAD:
							playerDirection = PLAYERDIRECTION::UP_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerUpStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::DOWN_RELOAD:
							playerDirection = PLAYERDIRECTION::DOWN_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerDownStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::LEFTDOWN_RELOAD:
							playerDirection = PLAYERDIRECTION::LEFTDOWN_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::RIGHTDOWN_RELOAD:
							playerDirection = PLAYERDIRECTION::RIGHTDOWN_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightDownStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::LEFTUP_RELOAD:
							playerDirection = PLAYERDIRECTION::LEFTUP_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpStop");
							playerMotion->start();
							break;

						case PLAYERDIRECTION::RIGHTUP_RELOAD:
							playerDirection = PLAYERDIRECTION::RIGHT_STOP;
							playerMotion = KEYANIMANAGER->findAnimation("playerRightUpStop");
							playerMotion->start();
							break;
						}
					}
				}
				else
				{
					Arrow->setPower(Arrow->getPower() - 0.5);

					if (Arrow->getPower() <= 0)
						Arrow->setPower(0);

				}

			}
			if (KEYMANAGER->isOnceKeyDown('C') && (playerDirection != PLAYERDIRECTION::DOWN_RELOAD || playerDirection != PLAYERDIRECTION::UP_RELOAD
				|| playerDirection != PLAYERDIRECTION::RIGHTDOWN_RELOAD || playerDirection != PLAYERDIRECTION::LEFTDOWN_RELOAD
				|| playerDirection != PLAYERDIRECTION::LEFT_RELOAD || playerDirection != PLAYERDIRECTION::RIGHT_RELOAD
				|| playerDirection != PLAYERDIRECTION::RIGHTUP_RELOAD || playerDirection != PLAYERDIRECTION::LEFTUP_RELOAD)) // 활 쏘기
			{
				Arrow->StartMove();
				ShowArrow = true;
				if (isShot)
				{
					float temp_angle = getAngle(_x, _y, Arrow->getX(), Arrow->getY());
					SOUNDMANAGER->play("arrow_retrieval");
					if ((temp_angle > 0 && temp_angle < PI2 / 16 * 1))
					{// || (temp_angle > PI2 / 16 * 15 && temp_angle < PI2)
						playerDirection = PLAYERDIRECTION::RIGHT_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 1 && temp_angle < PI2 / 16 * 3)
					{
						playerDirection = PLAYERDIRECTION::RIGHTUP_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightUpReload");
						playerMotion->start();
						Arrow->setDirection(ARROWDIRECTION::RIGHTUP);
					}
					else if (temp_angle > PI2 / 16 * 3 && temp_angle < PI2 / 16 * 5)
					{
						playerDirection = PLAYERDIRECTION::UP_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerUpReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 5 && temp_angle < PI2 / 16 * 7)
					{
						playerDirection = PLAYERDIRECTION::LEFTUP_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 7 && temp_angle < PI2 / 16 * 9)
					{
						playerDirection = PLAYERDIRECTION::LEFT_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 9 && temp_angle < PI2 / 16 * 11)
					{
						playerDirection = PLAYERDIRECTION::LEFTDOWN_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 11 && temp_angle < PI2 / 16 * 13)
					{
						playerDirection = PLAYERDIRECTION::DOWN_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerDownReload");
						playerMotion->start();
					}
					else if (temp_angle > PI2 / 16 * 13 && temp_angle < PI2 / 16 * 15)
					{
						playerDirection = PLAYERDIRECTION::RIGHTDOWN_RELOAD;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightDownReload");
						playerMotion->start();
					}
				}
				else
				{
					SOUNDMANAGER->play("arrow_charge");
					ShotReady();
					isShot = false; // tmep
					power = 0; // temp
					Arrow->setPower(power);
					isShotDirection = true;
					if (playerDirection == PLAYERDIRECTION::LEFT_MOVE || playerDirection == PLAYERDIRECTION::LEFT_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFT_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 15);
					}
					if (playerDirection == PLAYERDIRECTION::UP_MOVE || playerDirection == PLAYERDIRECTION::UP_STOP)
					{
						playerDirection = PLAYERDIRECTION::UP_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerUpShot");
						playerMotion->start();
						Arrow->setXY(_x + 8, _y + 10);
					}
					if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE || playerDirection == PLAYERDIRECTION::RIGHT_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHT_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 15);
					}
					if (playerDirection == PLAYERDIRECTION::DOWN_MOVE || playerDirection == PLAYERDIRECTION::DOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::DOWN_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerDownShot");
						playerMotion->start();
						Arrow->setXY(_x + 8, _y + 10);
					}

					if (playerDirection == PLAYERDIRECTION::RIGHTDOWN_MOVE || playerDirection == PLAYERDIRECTION::RIGHTDOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHTDOWN_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightDownShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 5);
					}
					if (playerDirection == PLAYERDIRECTION::LEFTDOWN_MOVE || playerDirection == PLAYERDIRECTION::LEFTDOWN_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFTDOWN_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 5);
					}
					if (playerDirection == PLAYERDIRECTION::LEFTUP_MOVE || playerDirection == PLAYERDIRECTION::LEFTUP_STOP)
					{
						playerDirection = PLAYERDIRECTION::LEFTUP_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 5);
					}
					if (playerDirection == PLAYERDIRECTION::RIGHTUP_MOVE || playerDirection == PLAYERDIRECTION::RIGHTUP_STOP)
					{
						playerDirection = PLAYERDIRECTION::RIGHTUP_SHOT;
						playerMotion = KEYANIMANAGER->findAnimation("playerRightUpShot");
						playerMotion->start();
						Arrow->setXY(_x + 5, _y + 5);
					}
				}
			}
		}


		switch (playerDirection)
		{

		case PLAYERDIRECTION::LEFT_MOVE:
			_x += cosf(PI) * move_speed;
			_y += -sinf(PI) * move_speed;
			break;
		case PLAYERDIRECTION::RIGHT_MOVE:
			_x += cosf(0) * move_speed;
			_y += -sinf(0) * move_speed;
			break;
		case PLAYERDIRECTION::UP_MOVE:
			
			_x += cosf(PI / 2) * move_speed;
			_y += -sinf(PI / 2) * move_speed;
			break;
		case PLAYERDIRECTION::DOWN_MOVE:
			_x += cosf(PI / 2 * 3) * move_speed;
			_y += -sinf(PI / 2 * 3) * move_speed;
			break;

		case PLAYERDIRECTION::LEFTDOWN_MOVE:
			_x += cosf(PI / 4 * 5) * move_speed;
			_y += -sinf(PI / 4 * 5) * move_speed;
			break;
		case PLAYERDIRECTION::RIGHTDOWN_MOVE:
			_x += cosf(PI / 4 * 7) * move_speed;
			_y += -sinf(PI / 4 * 7) * move_speed;
			break;
		case PLAYERDIRECTION::LEFTUP_MOVE:
			_x += cosf(PI / 4 * 3) * move_speed;
			_y += -sinf(PI / 4 * 3) * move_speed;
			break;
		case PLAYERDIRECTION::RIGHTUP_MOVE:
			_x += cosf(PI / 4 * 1) * move_speed;
			_y += -sinf(PI / 4 * 1) * move_speed;
			break;

		case PLAYERDIRECTION::LEFT_ROLL:
			_x += cosf(PI) * roll_speed;
			_y += -sinf(PI) * roll_speed;

			break;
		case PLAYERDIRECTION::RIGHT_ROLL:
			_x += cosf(0) * roll_speed;
			_y += -sinf(0) * roll_speed;

			break;
		case PLAYERDIRECTION::UP_ROLL:
	
			_x += cosf(PI / 2) * roll_speed;
			_y += -sinf(PI / 2) * roll_speed;

			break;
		case PLAYERDIRECTION::DOWN_ROLL:
			_x += cosf(PI / 2 * 3) * roll_speed;
			_y += -sinf(PI / 2 * 3) * roll_speed;
			break;
		case PLAYERDIRECTION::LEFTDOWN_ROLL:
			_x += cosf(PI / 4 * 5) * roll_speed;
			_y += -sinf(PI / 4 * 5) * roll_speed;
			break;
		case PLAYERDIRECTION::RIGHTDOWN_ROLL:
			_x += cosf(PI / 4 * 7) * roll_speed;
			_y += -sinf(PI / 4 * 7) * roll_speed;
			break;
		case PLAYERDIRECTION::LEFTUP_ROLL:
			_x += cosf(PI / 4 * 3) * roll_speed;
			_y += -sinf(PI / 4 * 3) * roll_speed;
			break;
		case PLAYERDIRECTION::RIGHTUP_ROLL:
			_x += cosf(PI / 4 * 1) * roll_speed;
			_y += -sinf(PI / 4 * 1) * roll_speed;
			break;

		}

		//계단
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), rt.x, lt.y + (rt.y - lt.y) / 2);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 0 && b == 0))
			{
				if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::RIGHT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
					//playerMotion->start();
					_x += cosf(PI / 2) *   move_speed;
					_y += -sinf(PI / 2) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::RIGHT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::RIGHT_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightRoll");
					//playerMotion->start();
					_x += cosf(PI / 2) *  roll_speed;
					_y += -sinf(PI / 2) *  roll_speed;
				}
			}
			if ((r == 255 && g == 255 && b == 0))
			{
				if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::RIGHT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
					//playerMotion->start();
					_x += cosf(PI / 2 * 3) *  move_speed;
					_y += -sinf(PI / 2 * 3) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::RIGHT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::RIGHT_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightRoll");
					//playerMotion->start();
					_x += cosf(PI / 2 * 3) *   roll_speed;
					_y += -sinf(PI / 2 * 3) *  roll_speed;
				}
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lt.x, lt.y + (rt.y - lt.y) / 2);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 0 && b == 0))
			{
				if (playerDirection == PLAYERDIRECTION::LEFT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::LEFT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
					//playerMotion->start();
					_x += cosf(PI / 2 * 3)  *  move_speed;
					_y += -sinf(PI / 2 * 3) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::LEFT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::LEFT_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftRoll");
					//playerMotion->start();
					_x += cosf(PI / 2 * 3)  * roll_speed;
					_y += -sinf(PI / 2 * 3) * roll_speed;
				}
			}
			if (r == 255 && g == 255 && b == 0)
			{
				if (playerDirection == PLAYERDIRECTION::LEFT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::LEFT_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
					//	playerMotion->start();
					_x += cosf(PI / 2)  *  move_speed;
					_y += -sinf(PI / 2) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::LEFT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::LEFT_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftRoll");
					//	playerMotion->start();
					_x += cosf(PI / 2)  *  roll_speed;
					_y += -sinf(PI / 2) *  roll_speed;
				}
			}
		}


		//픽셀충돌
		if (playerDirection == PLAYERDIRECTION::LEFT_MOVE || playerDirection == PLAYERDIRECTION::LEFT_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lt.x, lt.y + (rt.y - lt.y) / 2);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::LEFT_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftStop");
				playerMotion->start();
				_x += cosf(0) * move_speed;
				_y += -sinf(0) * move_speed;
			}
			/*if ((r == 255 && g == 255 && b == 0))
			{
				if (playerDirection == PLAYERDIRECTION::LEFT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::LEFTUP_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftMove");
					playerMotion->start();
					_x += cosf(PI / 2) *  move_speed;
					_y += -sinf(PI / 2) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::LEFT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::LEFTUP_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftRoll");
					playerMotion->start();
					_x += cosf(PI / 2) *   move_speed;
					_y += -sinf(PI / 2) *  move_speed;
				}
			}
			if (r == 255 && g == 0 && b == 0)
			{
				if (playerDirection == PLAYERDIRECTION::LEFT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::LEFTDOWN_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownMove");
					playerMotion->start();
				}
				else if (playerDirection == PLAYERDIRECTION::LEFT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::LEFTUP_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownRoll");
					playerMotion->start();
				}
			}*/
		}
		else if (playerDirection == PLAYERDIRECTION::LEFTDOWN_MOVE || playerDirection == PLAYERDIRECTION::LEFTDOWN_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lb.x, lb.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::LEFTDOWN_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownStop");
				playerMotion->start();
				_x += cosf(PI / 4 * 1) *  move_speed;
				_y += -sinf(PI / 4 * 1) * move_speed;
			}
		}
		else if (playerDirection == PLAYERDIRECTION::DOWN_MOVE || playerDirection == PLAYERDIRECTION::DOWN_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lb.x + (rb.x - lb.x) / 2, lb.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::DOWN_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerDownStop");
				playerMotion->start();
				_x += cosf(PI / 2) *  move_speed;
				_y += -sinf(PI / 2) * move_speed;
			}
		}
		else if (playerDirection == PLAYERDIRECTION::RIGHTDOWN_MOVE || playerDirection == PLAYERDIRECTION::RIGHTDOWN_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), rb.x, rb.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::RIGHTDOWN_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightDownStop");
				playerMotion->start();
				_x += cosf(PI / 4 * 3) *  move_speed;
				_y += -sinf(PI / 4 * 3) * move_speed;
			}
		}
		else if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE || playerDirection == PLAYERDIRECTION::RIGHT_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), rt.x, lt.y + (rt.y - lt.y) / 2);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::RIGHT_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightStop");
				playerMotion->start();
				_x += cosf(PI) *  move_speed;
				_y += -sinf(PI) * move_speed;
			}

			/*if (r == 255 && g == 255 && b == 0)
			{
				if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE)
				{
					playerDirection = PLAYERDIRECTION::RIGHTDOWN_MOVE;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightMove");
					playerMotion->start();
					_x += cosf(PI / 2 * 3) *  move_speed;
					_y += -sinf(PI /2 * 3) *  move_speed;
				}
				else if (playerDirection == PLAYERDIRECTION::RIGHT_ROLL)
				{
					playerDirection = PLAYERDIRECTION::RIGHTUP_ROLL;
					playerMotion = KEYANIMANAGER->findAnimation("playerRightDownRoll");
					playerMotion->start();
					_x += cosf(PI / 2 * 3) *  roll_speed;
					_y += -sinf(PI / 2 * 3) * roll_speed;
				}
			}*/
		}
		else if (playerDirection == PLAYERDIRECTION::RIGHTUP_MOVE || playerDirection == PLAYERDIRECTION::RIGHTUP_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), rt.x, rt.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::RIGHTUP_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerRightUpStop");
				playerMotion->start();
				_x += cosf(PI / 4 * 5) *  move_speed;
				_y += -sinf(PI / 4 * 5) * move_speed;
			}
		}
		else if (playerDirection == PLAYERDIRECTION::UP_MOVE || playerDirection == PLAYERDIRECTION::UP_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lt.x + (rt.x - lt.x) / 2, rt.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::UP_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerUpStop");
				playerMotion->start();
				_x += cosf(PI / 4 * 6) *  move_speed;
				_y += -sinf(PI / 4 * 6) * move_speed;
			}
		}
		else if (playerDirection == PLAYERDIRECTION::LEFTUP_MOVE || playerDirection == PLAYERDIRECTION::LEFTUP_ROLL)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(pxCollision)->getMemDC(), lt.x, lt.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				playerDirection = PLAYERDIRECTION::LEFTUP_STOP;
				playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpStop");
				playerMotion->start();
				_x += cosf(PI / 4 * 7) *  move_speed;
				_y += -sinf(PI / 4 * 7) * move_speed;
			}
		}
		KEYANIMANAGER->update();
		Arrow->update();
		Arrow->move();
	}
}

void Titan::ShotReady()
{

	switch (playerDirection)
	{
	case PLAYERDIRECTION::LEFT_SHOT:
		Arrow->setDirection(ARROWDIRECTION::LEFT);
		Arrow->setAngle(PI);
		break;

	case PLAYERDIRECTION::RIGHT_SHOT:
		Arrow->setDirection(ARROWDIRECTION::RIGHT);
		Arrow->setAngle(0);
		break;

	case PLAYERDIRECTION::UP_SHOT:
		Arrow->setDirection(ARROWDIRECTION::UP);
		Arrow->setAngle(PI/2);
		break;

	case PLAYERDIRECTION::DOWN_SHOT:
		Arrow->setDirection(ARROWDIRECTION::DOWN);
		Arrow->setAngle(PI/2 * 3);
		break;

	case PLAYERDIRECTION::LEFTDOWN_SHOT:
		Arrow->setDirection(ARROWDIRECTION::LEFTDOWN);
		Arrow->setAngle(PI/4 * 5);
		break;

	case PLAYERDIRECTION::RIGHTDOWN_SHOT:
		Arrow->setDirection(ARROWDIRECTION::RIGHTDOWN);
		Arrow->setAngle(PI /4 * 7);
		break;

	case PLAYERDIRECTION::LEFTUP_SHOT:
		Arrow->setDirection(ARROWDIRECTION::LEFTUP);
		Arrow->setAngle(PI/4 * 3);
		break;

	case PLAYERDIRECTION::RIGHTUP_SHOT:
		Arrow->setDirection(ARROWDIRECTION::RIGHTUP);
		Arrow->setAngle(PI / 4 * 1);
		break;
	}
}

void Titan::Shot()
{

}

void Titan::render()
{
	
	//_image->aniRender(getMemDC(), _x, _y, playerMotion,scale);
	CAMERAMANAGER->scaleAniRenderObject(getMemDC(), _image, playerMotion,_x,_y,scale);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	//if(isShot || shot_ready)
	if(ShowArrow)
		Arrow->render(scale);
	//char str[126];
	//sprintf(str, "%f", shotDelay);
	//TextOut(getMemDC(), 200, 700, str, strlen(str));

}


void Titan::RightStopMotion(void* obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::RIGHT_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::RIGHT_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::RIGHT_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightMove"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::RIGHT_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightMove"));
		p->getPlayerMotion()->start();
	}
}

void Titan::LeftStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::LEFT_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::LEFT_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::LEFT_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftMove"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::LEFT_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftMove"));
		p->getPlayerMotion()->start();
	}
}
void Titan::UpStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::UP_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::UP_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerUpStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::UP_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerUpMove"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::UP_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerUpMove"));
		p->getPlayerMotion()->start();
	}
}
void Titan::DownStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::DOWN_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::DOWN_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerDownStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::DOWN_STOP);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerDownStop"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::DOWN_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerDownMove"));
		p->getPlayerMotion()->start();
	}
}
void Titan::RightUpStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::RIGHTUP_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::RIGHTUP_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightUpStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::RIGHTUP_STOP);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightUpStop"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::RIGHTUP_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightUpMove"));
		p->getPlayerMotion()->start();
	}
}
void Titan::RightDownStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::RIGHTDOWN_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::RIGHTDOWN_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightDownStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::RIGHTDOWN_STOP);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightDownStop"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::RIGHTDOWN_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerRightDownMove"));
		p->getPlayerMotion()->start();
	}
}

void Titan::LeftUpStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::LEFTUP_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::LEFTUP_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftUpStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::LEFTUP_STOP);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftUpStop"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::LEFTUP_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftUpMove"));
		p->getPlayerMotion()->start();
	}
}
void Titan::LeftDownStopMotion(void * obj)
{
	Titan *p = (Titan*)obj;
	if (p->getPlayerDirection() == PLAYERDIRECTION::LEFTDOWN_SHOT)
	{
		//p->setPlayerDirection(PLAYERDIRECTION::LEFTDOWN_STOP);
		//p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftDownStop"));
		//p->getPlayerMotion()->start();
		p->setPlayerDirection(PLAYERDIRECTION::LEFTDOWN_STOP);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftDownStop"));
		p->getPlayerMotion()->start();
	}
	else
	{
		p->setPlayerDirection(PLAYERDIRECTION::LEFTDOWN_MOVE);
		p->setPlayertMotion(KEYANIMANAGER->findAnimation("playerLeftDownMove"));
		p->getPlayerMotion()->start();
	}
}

void Titan::Dead()
{
	if (isDead == false)
	{
		int d = DATABASE->getElementsData("0")->death + 1;
		DATABASE->setDeath("0", d);
	}
	isDead = true;
	if (playerDirection == PLAYERDIRECTION::DOWN_MOVE || playerDirection == PLAYERDIRECTION::DOWN_ROLL ||
		playerDirection == PLAYERDIRECTION::DOWN_STOP || playerDirection == PLAYERDIRECTION::DOWN_RELOAD ||
		playerDirection == PLAYERDIRECTION::DOWN_SHOT)
	{
		playerDirection = PLAYERDIRECTION::DOWN_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerDownDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::LEFT_MOVE || playerDirection == PLAYERDIRECTION::LEFT_ROLL ||
		playerDirection == PLAYERDIRECTION::LEFT_STOP || playerDirection == PLAYERDIRECTION::LEFT_RELOAD ||
		playerDirection == PLAYERDIRECTION::LEFT_SHOT)
	{
		playerDirection = PLAYERDIRECTION::LEFT_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerLeftDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::RIGHT_MOVE || playerDirection == PLAYERDIRECTION::RIGHT_ROLL ||
		playerDirection == PLAYERDIRECTION::RIGHT_STOP || playerDirection == PLAYERDIRECTION::RIGHT_RELOAD ||
		playerDirection == PLAYERDIRECTION::RIGHT_SHOT)
	{
		playerDirection = PLAYERDIRECTION::RIGHT_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerRightDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::UP_MOVE || playerDirection == PLAYERDIRECTION::UP_ROLL ||
		playerDirection == PLAYERDIRECTION::UP_STOP || playerDirection == PLAYERDIRECTION::UP_RELOAD ||
		playerDirection == PLAYERDIRECTION::UP_SHOT)
	{
		playerDirection = PLAYERDIRECTION::UP_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerUpDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::LEFTUP_MOVE || playerDirection == PLAYERDIRECTION::LEFTUP_ROLL ||
		playerDirection == PLAYERDIRECTION::LEFTUP_STOP || playerDirection == PLAYERDIRECTION::LEFTUP_RELOAD ||
		playerDirection == PLAYERDIRECTION::LEFTUP_SHOT)
	{
		playerDirection = PLAYERDIRECTION::LEFTUP_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerLeftUpDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::RIGHTUP_MOVE || playerDirection == PLAYERDIRECTION::RIGHTUP_ROLL ||
		playerDirection == PLAYERDIRECTION::RIGHTUP_STOP || playerDirection == PLAYERDIRECTION::RIGHTUP_RELOAD ||
		playerDirection == PLAYERDIRECTION::RIGHTUP_SHOT)
	{
		playerDirection = PLAYERDIRECTION::RIGHTUP_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerRightUpDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::LEFTDOWN_MOVE || playerDirection == PLAYERDIRECTION::LEFTDOWN_ROLL ||
		playerDirection == PLAYERDIRECTION::LEFTDOWN_STOP || playerDirection == PLAYERDIRECTION::LEFTDOWN_RELOAD ||
		playerDirection == PLAYERDIRECTION::LEFTDOWN_SHOT)
	{
		playerDirection = PLAYERDIRECTION::LEFTDOWN_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerLeftDownDead");
		playerMotion->start();
	}
	else if (playerDirection == PLAYERDIRECTION::RIGHTDOWN_MOVE || playerDirection == PLAYERDIRECTION::RIGHTDOWN_ROLL ||
		playerDirection == PLAYERDIRECTION::RIGHTDOWN_STOP || playerDirection == PLAYERDIRECTION::RIGHTDOWN_RELOAD ||
		playerDirection == PLAYERDIRECTION::RIGHTDOWN_SHOT)
	{
		playerDirection = PLAYERDIRECTION::RIGHTDOWN_DEAD;
		playerMotion = KEYANIMANAGER->findAnimation("playerRightDownDead");
		playerMotion->start();
	}

}