#pragma once

#include "Layer.h"
#include "macro.h"

class BackGround :public Layer
{
public:
	gBitmap* mainScene;
	gBitmap* background;

public:
	BackGround(HINSTANCE g_hInst, HWND hWnd);
	~BackGround();

	void DrawImage();
};