#pragma once

#include <Windows.h>
#include <stdio.h>
#include "macro.h"

class Player
{
public:
	float moving_x;
	float moving_y;

	int Image_toggle;
	
private:
	float speed_x;
	float speed_y;

public:
	Player();
	~Player();

	int direction();
	void setKeydown();

	void setSpeed_x(float speed);
	void setSpeed_y(float speed);
};