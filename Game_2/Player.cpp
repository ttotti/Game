#include "Player.h"

Player::Player()
{
	moving = 0;
}

Player::~Player()
{
	printf("Player �Ҹ�!\n");
}

int Player::direction()
{
	return moving;
}

void Player::setKeydown()
{
	//printf("setKeydown() ȣ��!\n");

	// GetKeyState() - ���� Ű�� ��� ���¸� �� �� �ִ�
	// GetAsyncKeyState() - ���� Ű�� ������ �� �� �ִ�

	if (GetAsyncKeyState(VK_LEFT))
	{
		printf("LEFT �Է�!\n");
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		printf("RIGHT �Է�!\n");
	}
	if (GetAsyncKeyState(VK_UP))
	{
		printf("UP �Է�!\n");
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		printf("DOWN �Է�!\n");
	}

	//switch (wParam)
	//{
	//case VK_LEFT:
	//	printf("LEFT �Է�!\n");
	//	break;

	//case VK_RIGHT:
	//	printf("RIGHT �Է�!\n");
	//	break;

	//case VK_UP:
	//	printf("UP �Է�!\n");
	//	break;

	//case VK_DOWN:
	//	printf("DOWN �Է�!\n");
	//	break;

	//default:
	//	break;
	//}
}
