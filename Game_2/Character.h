#pragma once

#include "Layer.h"

class Character
{
public:
	float speed_x;
	float speed_y;

	int Image_toggle;

protected:
	RECT rect;

public:
	Character()
	{
		speed_x = 2.0f;
		speed_y = 2.0f;
		Image_toggle = 1;

		rect.left = 0;
		rect.top = 0;
		rect.right = 0;
		rect.bottom = 0;
	};
	~Character() { printf("Character Å¬·¡½º ¼Ò¸ê!\n"); }

	void setSpeed(float speed) { speed_x = speed;  speed_y = speed; }
	void setSpeed_x(float speed) { speed_x = speed; }
	void setSpeed_y(float speed) { speed_y = speed; }

	void setRECT_Point(int rect_left, int rect_top)
	{
		rect.left = rect_left;
		rect.top = rect_top;
	}

	void setRECT_left(float RECT_left) { rect.left = RECT_left; }
	void setRECT_right(float RECT_right) { rect.right = RECT_right; }
	void setRECT_top(float RECT_top) { rect.top = RECT_top; }
	void setRECT_bottom(float RECT_bottom) { rect.bottom = RECT_bottom; }

	int getRECT_left() { return rect.left; }
	int getRECT_right() { return rect.right; }
	int getRECT_top() { return rect.top; }
	int getRECT_bottom() { return rect.bottom; }
};