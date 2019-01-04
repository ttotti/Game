#pragma once

#include "Layer.h"
//#include "macro.h"

#include "Player.h"
#include "Enemy.h"

#define MAX_ENEMY 1

class GameScene : public Layer
{
private:
	enum SELECT { GAMESTART, RESTART, MAINSCENE, PAUSE };

	HWND hWnd;
	HINSTANCE g_hInst;

	Player* player;
	Enemy* enemy[MAX_ENEMY];
	//Character* player;
	//Character* enemy[MAX_ENEMY];

	gBitmap* background;

public:
	SELECT select;
	int enemyCount;

public:
	GameScene();
	GameScene(HINSTANCE g_hInst, HWND hWnd);
	~GameScene();

	void Loop();
	void DrawImage();

	// �簢�� �浹 ����
	// RECT1�� Left �� RECT2�� Right ���� �۾ƾ� �Ѵ�
	// RECT1�� Top �� RECT2�� Bottom ���� �۾ƾ� �Ѵ�
	// RECT1�� Right �� RECT2�� Left ���� Ŀ�� �Ѵ�
	// RECT1�� Bottom �� RECT2�� Top ���� Ŀ�� �Ѵ�
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