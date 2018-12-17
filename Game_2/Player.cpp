#include "Player.h"

Player::Player()
{
	moving = 0;
}

Player::~Player()
{
	printf("Player 소멸!\n");
}

int Player::direction()
{
	return moving;
}

void Player::setKeydown()
{
	//printf("setKeydown() 호출!\n");

	// GetKeyState() - 현재 키의 토글 상태를 알 수 있다
	// GetAsyncKeyState() - 현재 키의 눌림을 알 수 있다

	if (GetAsyncKeyState(VK_LEFT))
	{
		printf("LEFT 입력!\n");
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		printf("RIGHT 입력!\n");
	}
	if (GetAsyncKeyState(VK_UP))
	{
		printf("UP 입력!\n");
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		printf("DOWN 입력!\n");
	}

	//switch (wParam)
	//{
	//case VK_LEFT:
	//	printf("LEFT 입력!\n");
	//	break;

	//case VK_RIGHT:
	//	printf("RIGHT 입력!\n");
	//	break;

	//case VK_UP:
	//	printf("UP 입력!\n");
	//	break;

	//case VK_DOWN:
	//	printf("DOWN 입력!\n");
	//	break;

	//default:
	//	break;
	//}
}
