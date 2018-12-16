#pragma once

#include "Layer.h"
#include "macro.h"

class GameScene : public Layer
{
public:
	gBitmap* background;

public:
	GameScene();
	GameScene(HINSTANCE g_hInst, HWND hWnd);
	~GameScene();

	void DrawImage();
};