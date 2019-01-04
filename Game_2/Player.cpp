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
	HPbar->set_X(playerImage[0]->get_X());
	HPbar->set_Y(playerImage[0]->get_Y() - 10);
	HPbar->set_W(HPbar->get_W());

	HP = new gBitmap;
	HP->SetBitmap(hWnd, g_hInst, IDB_HP);
	HP->set_X(HPbar->get_X());
	HP->set_Y(HPbar->get_Y());
	HP->set_W(HPbar->get_W());

	moving_x = 0.0f;
	moving_y = 0.0f;
	life = 0;

	rect.left = playerImage[0]->get_X();
	rect.top = playerImage[0]->get_Y();
	rect.right = rect.left + playerImage[0]->get_W();
	rect.bottom = rect.top + playerImage[0]->get_H();
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

	delete HP;
	HP = NULL;

	printf("Player 소멸!\n");
}

void Player::setKeydown()
{
	//printf("setKeydown() 호출!\n");

	// GetKeyState() - 현재 키의 토글 상태를 알 수 있다
	// GetAsyncKeyState() - 현재 키의 눌림을 알 수 있다
	if (GetAsyncKeyState(VK_LEFT))
	{
		moving_x += speed;
		rect.left -= speed;
		Image_toggle = 1;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		moving_x -= speed;
		rect.left += speed;
		Image_toggle = 0;

		//printf("field = %f\n", field_x);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		moving_y += speed;
		rect.top -= speed;
		//printf("UP 입력!\n");
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		moving_y -= speed;
		rect.top += speed;

		//printf("DOWN 입력!\n");
	}

	rect.right = rect.left + 50;
	rect.bottom = rect.top + 50;

	//printf("speed_L = %f\n", speed_L);
	//printf("speed_R = %f\n", speed_R);
	//printf("speed_U = %f\n", speed_U);
	//printf("speed_D = %f\n", speed_D);
}

bool Player::Gameover()
{
	life += 10;

	HP->set_W(HPbar->get_W() - life);

	if (life > 40)
	{
		return true;
	}

	return false;
}
