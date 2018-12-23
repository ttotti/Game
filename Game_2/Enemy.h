#pragma once

#include <Windows.h>
#include "Layer.h"
#include <stdio.h>

class Enemy
{
public:
	gBitmap* enemyImage[2];

	float moving_x;
	float moving_y;

	int Image_toggle;

private:
	float speed_x;
	float speed_y;

	float field_x;
	float field_y;

public:
	Enemy(HWND hWnd, HINSTANCE g_hInst);
	~Enemy();

	void setSpeed_x(float speed) { speed_x = speed; }
	void setSpeed_y(float speed) { speed_y = speed; }

	void setfield_Point(float field_x, float field_y)
	{
		this->field_x = field_x;
		this->field_y = field_y;
	}
	void setfield_x(float field_x) { this->field_x = field_x; }
	void setfield_y(float field_y) { this->field_y = field_y; }

	float getfield_x() { return field_x; }
	float getfield_y() { return field_y; }
};