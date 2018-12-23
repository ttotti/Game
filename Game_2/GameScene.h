#pragma once

#include "Layer.h"
#include "macro.h"

#include "Player.h"
#include "Enemy.h"

#define MAX_ENEMY 500

class GameScene : public Layer
{
private:
	HWND hWnd;
	HINSTANCE g_hInst;

	Player* player;
	Enemy* enemy[MAX_ENEMY];

	gBitmap* background;

public:
	int enemyCount;

public:
	GameScene();
	GameScene(HINSTANCE g_hInst, HWND hWnd);
	~GameScene();

	void Loop();
	void DrawImage();
};