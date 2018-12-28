#pragma once

class Character
{
public:
	float moving_x;
	float moving_y;

	int Image_toggle;

private:
	float speed_x;
	float speed_y;

	float field_x;
	float field_y;
	float field_w;
	float field_h;

public:
	Character() {};
	~Character() {};

	void setSpeed_x(float speed) { speed_x = speed; }
	void setSpeed_y(float speed) { speed_y = speed; }

	void setfield_x(float field_x) { this->field_x = field_x; }
	void setfield_y(float field_y) { this->field_y = field_y; }
	void setfield_w(float field_w) { this->field_w = field_w; }
	void setfield_h(float field_h) { this->field_h = field_h; }

	float getfield_x() { return field_x; }
	float getfield_y() { return field_y; }
	float getfield_w() { return field_w; }
	float getfield_h() { return field_h; }
};