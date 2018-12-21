#pragma once

#include <Windows.h>
#include "Layer.h"
#include "macro.h"

class Player
{
public:
	gBitmap* playerImage[2];

public:
	float moving_x;
	float moving_y;

	int Image_toggle;
	
private:
	float speed_x;
	float speed_y;

	float field_x;
	float field_y;

public:
	Player(HWND hWnd, HINSTANCE g_hInst);
	~Player();

	int direction();
	void setKeydown();

	void setSpeed_x(float speed);
	void setSpeed_y(float speed);

	float getfield_x();
	float getfield_y();
};