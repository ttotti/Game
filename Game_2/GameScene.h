#pragma once

#include "Layer.h"
#include "macro.h"

#include "Player.h"

class GameScene : public Layer
{
private:
	Player* player;

	gBitmap* background;
	gBitmap* playerImage[2];

public:
	GameScene();
	GameScene(HINSTANCE g_hInst, HWND hWnd);
	~GameScene();

	void Loop();
	void DrawImage();
};