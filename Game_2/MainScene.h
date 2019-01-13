#pragma once

#include "Layer.h"
#include "macro.h"

class MainScene :public Layer
{
public:
	gBitmap* mainScene;

	gBitmap* StartIcon;
	gBitmap* StartIcon2;
	gBitmap* QuitIcon;
	gBitmap* QuitIcon2;

public:
	bool ClickMouse;
	int selectMenu;

public:
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void DrawImage();

	int getSelectMenu(){ return selectMenu; }

public:
	HWND hWnd;
	POINT pt;
};