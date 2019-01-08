#pragma once

#include "MainScene.h"
#include "GameScene.h"
#include "macro.h"

class GameLoop
{
public:
	//std::unique_ptr<MainScene> mainscene;
	MainScene* mainscene;
	GameScene* gamescene;

public:
	HINSTANCE g_hInst;
	HWND hWnd;

	int selectMenu;

	int M_x, M_y, C_x, C_y;

public:
	GameLoop();
	~GameLoop();

	void init(HINSTANCE g_hInst, HWND hWnd);
	void Loop();
};