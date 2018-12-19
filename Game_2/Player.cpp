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
	printf("Player 소멸!\n");
}

int Player::direction()
{
	return 0; //moving;
}

void Player::setKeydown()
{
	//printf("setKeydown() 호출!\n");

	// GetKeyState() - 현재 키의 토글 상태를 알 수 있다
	// GetAsyncKeyState() - 현재 키의 눌림을 알 수 있다

	if (GetAsyncKeyState(VK_LEFT))
	{
		moving_x += speed_x;
		Image_toggle = -1;
		printf("LEFT 입력!\n");
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		moving_x -= speed_x;
		Image_toggle = 1;
		printf("RIGHT 입력!\n");
	}
	if (GetAsyncKeyState(VK_UP))
	{
		moving_y += speed_y;
		printf("UP 입력!\n");
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		moving_y -= speed_y;
		printf("DOWN 입력!\n");
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
