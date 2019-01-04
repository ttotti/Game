#pragma once

#include <Windows.h>
#include "Layer.h"
#include "macro.h"
#include "Character.h"

class Player : public Character
{
public:
	gBitmap* playerImage[2];
	gBitmap* HPbar;
	gBitmap* HP;

	float moving_x;
	float moving_y;

	int life;

public:
	Player(HWND hWnd, HINSTANCE g_hInst);
	~Player();

	void setKeydown();
	bool Gameover();
};