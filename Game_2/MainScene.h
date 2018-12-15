#pragma once

#include "Layer.h"
#include "macro.h"

class MainScene :public Layer
{
public:
	gBitmap* mainScene;
	gBitmap* StartIcon;
	gBitmap* QuitIcon;

public:
	int C_x, C_y;

public:
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void setCilck(int C_x, int C_y);
	void DrawImage();
};