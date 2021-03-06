#pragma once

#include "Layer.h"
//#include "macro.h"

#include "Player.h"
#include "Enemy.h"

#define MAX_ENEMY 10

class GameScene : public Layer
{
private:
	HWND hWnd;
	HINSTANCE g_hInst;

	POINT pt;

	Player* player;
	Enemy* enemy[MAX_ENEMY];
	//Character* player;
	//Character* enemy[MAX_ENEMY];

	gBitmap* background;
	gBitmap* gameover_ground;

	gBitmap* Gameover_Icon;
	gBitmap* ReStart_Icon[2];
	gBitmap* MainScene_Icon[2];

public:
	enum SELECT { GAMESTART, RESTART, MAINSCENE, PAUSE };

	int select;
	int enemyCount;
	int Alpha;

	bool ClickMouse;

public:
	GameScene();
	GameScene(HINSTANCE g_hInst, HWND hWnd);
	~GameScene();

	void Loop();
	void DrawImage();

	// 사각형 충돌 조건
	// RECT1의 Left 가 RECT2의 Right 보다 작아야 한다
	// RECT1의 Top 가 RECT2의 Bottom 보다 작아야 한다
	// RECT1의 Right 가 RECT2의 Left 보다 커야 한다
	// RECT1의 Bottom 가 RECT2의 Top 보다 커야 한다
	bool isCollision(const RECT& rc1, const RECT& rc2)
	{
		if (rc1.left < rc2.right&&
			rc1.top < rc2.bottom&&
			rc1.right > rc2.left&&
			rc1.bottom > rc2.top)
		{
			return true;
		}

		return false;
	}
};