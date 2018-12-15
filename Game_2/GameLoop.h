#pragma once

#include "MainScene.h"
#include "macro.h"

class GameLoop
{
public:
	MainScene* mainscene;

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