#pragma once

#include <Windows.h>
#include "Layer.h"
#include "macro.h"

class Player
{
public:
	gBitmap* playerImage[2];
	gBitmap* HPbar;
	gBitmap* HP;

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

	void setKeydown();

	void setSpeed_x(float speed) { speed_x = speed; }
	void setSpeed_y(float speed) { speed_y = speed; }

	void setfield_x(float field_x) { this->field_x = field_x; }
	void setfield_y(float field_y) { this->field_y = field_y; }

	float getfield_x() { return field_x; }
	float getfield_y() { return field_y; }
};