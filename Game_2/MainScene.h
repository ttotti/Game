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
	int M_x, M_y, C_x, C_y;
	bool ClickMouse;
	int selectMenu;

public:
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void setMouse(int M_x, int M_y, int C_x, int C_y);
	void DrawImage();

	int getSelectMenu();
};