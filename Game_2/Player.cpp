#include "Player.h"

Player::Player()
{
	moving_x = 0.0f;
	moving_y = 0.0f;
	speed_x = 1.0f;
	speed_y = 1.0f;
	Image_toggle = 1;
}

Player::~Player()
{
	printf("Player �Ҹ�!\n");
}

int Player::direction()
{
	return 0; //moving;
}

void Player::setKeydown()
{
	//printf("setKeydown() ȣ��!\n");

	// GetKeyState() - ���� Ű�� ��� ���¸� �� �� �ִ�
	// GetAsyncKeyState() - ���� Ű�� ������ �� �� �ִ�

	if (GetAsyncKeyState(VK_LEFT))
	{
		moving_x += speed_x;
		Image_toggle = -1;
		printf("LEFT �Է�!\n");
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		moving_x -= speed_x;
		Image_toggle = 1;
		printf("RIGHT �Է�!\n");
	}
	if (GetAsyncKeyState(VK_UP))
	{
		moving_y += speed_y;
		printf("UP �Է�!\n");
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		moving_y -= speed_y;
		printf("DOWN �Է�!\n");
	}
}

void Player::setSpeed_x(float speed)
{
	speed_x = speed;
}

void Player::setSpeed_y(float speed)
{
	speed_y = speed;
}
