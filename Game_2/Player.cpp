#include "Player.h"

Player::Player(HWND hWnd, HINSTANCE g_hInst)
{
	playerImage[0] = new gBitmap;
	playerImage[0]->SetBitmap(hWnd, g_hInst, IDB_Player1);
	playerImage[0]->set_X(WIN_WIDTH / 2 - playerImage[0]->get_W() / 2);
	playerImage[0]->set_Y(WIN_HEIGHT / 2 - playerImage[0]->get_H() / 2);

	playerImage[1] = new gBitmap;
	playerImage[1]->SetBitmap(hWnd, g_hInst, IDB_Player3);
	playerImage[1]->set_X(WIN_WIDTH / 2 - playerImage[1]->get_W() / 2);
	playerImage[1]->set_Y(WIN_HEIGHT / 2 - playerImage[1]->get_H() / 2);

	HPbar = new gBitmap;
	HPbar->SetBitmap(hWnd, g_hInst, IDB_HPbar);
	HPbar->set_X(playerImage[0]->get_X() + 5);
	HPbar->set_Y(playerImage[0]->get_Y() - 10);
	HPbar->set_W(HPbar->get_W() - 10);

	HP = new gBitmap;
	HP->SetBitmap(hWnd, g_hInst, IDB_HP);
	HP->set_X(HPbar->get_X());
	HP->set_Y(HPbar->get_Y());
	HP->set_W(HPbar->get_W());

	moving_x = 0.0f;
	moving_y = 0.0f;
	speed_x = 2.0f;
	speed_y = 2.0f;
	Image_toggle = 1;

	field_x = playerImage[0]->get_X();
	field_y = playerImage[0]->get_Y();
	field_w = field_x + playerImage[0]->get_W();
	field_h = field_y + playerImage[0]->get_H();
}

Player::~Player()
{
	for (int i = 0; i < 2; i++)
	{
		delete playerImage[i];
		playerImage[i] = NULL;
	}

	delete HPbar;
	HPbar = NULL;

	printf("Player 소멸!\n");
}

void Player::setKeydown()
{
	//printf("setKeydown() 호출!\n");

	// GetKeyState() - 현재 키의 토글 상태를 알 수 있다
	// GetAsyncKeyState() - 현재 키의 눌림을 알 수 있다

	if (GetAsyncKeyState(VK_LEFT))
	{
		moving_x += speed_x;
		field_x -= speed_x;
		Image_toggle = 1;

		//printf("field = %f\n", field_x);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		moving_x -= speed_x;
		field_x += speed_x;
		Image_toggle = 0;

		//printf("field = %f\n", field_x);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		moving_y += speed_y;
		field_y -= speed_y;

		//printf("UP 입력!\n");
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		moving_y -= speed_y;
		field_y += speed_y;

		//printf("DOWN 입력!\n");
	}

	field_w = field_x + 50;
	field_h = field_y + 50;
}
