#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::GameScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd), hWnd(hWnd), g_hInst(g_hInst), enemyCount(0), Alpha(0), ClickMouse(false)
{
	background = new gBitmap;
	background->SetBitmap(hWnd, g_hInst, IDB_background);

	player = new Player(hWnd, g_hInst);

	gameover_ground = new gBitmap;
	gameover_ground->SetBitmap(hWnd, g_hInst, IDB_Gameover_ground);

	background->set_X(-background->get_W() / 4 + player->moving_x);
	background->set_Y(-background->get_H() / 4 + player->moving_y);

	Gameover_Icon = new gBitmap;
	Gameover_Icon->SetBitmap(hWnd, g_hInst, IDB_Gameover_Icon);
	Gameover_Icon->set_X((WIN_WIDTH / 2)-120);
	Gameover_Icon->set_Y(150);

	for (int i = 0; i < 2; i++)
	{
		ReStart_Icon[i] = new gBitmap;
		MainScene_Icon[i] = new gBitmap;

		ReStart_Icon[i]->SetBitmap(hWnd, g_hInst, IDB_ReStart_Icon + i);
		ReStart_Icon[i]->set_X(Gameover_Icon->get_X());
		ReStart_Icon[i]->set_Y(Gameover_Icon->get_Y() + 100);

		MainScene_Icon[i]->SetBitmap(hWnd, g_hInst, IDB_MainScene_Icon + i);
		MainScene_Icon[i]->set_X(Gameover_Icon->get_X());
		MainScene_Icon[i]->set_Y(Gameover_Icon->get_Y() + 200);
	}

	player->setRECT_left(player->getRECT_left() - background->get_X());
	player->setRECT_top(player->getRECT_top() - background->get_Y());

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i] = NULL;
	}

	select = GAMESTART;
}

GameScene::~GameScene()
{
	delete background;
	background = NULL;
	//printf("background ¼Ò¸ê!\n");

	delete player;
	player = NULL;
	//printf("player ¼Ò¸ê!\n");

	delete gameover_ground;
	gameover_ground = NULL;
	//printf("gameover_ground ¼Ò¸ê!\n");

	delete Gameover_Icon;
	Gameover_Icon = NULL;
	//printf("Gameover_Icon ¼Ò¸ê!\n");

	for (int i = 0; i < 2; i++)
	{
		delete ReStart_Icon[i];
		ReStart_Icon[i] = NULL;

		delete MainScene_Icon[i];
		MainScene_Icon[i] = NULL;
	}
	//printf("Re,Main_Icon ¼Ò¸ê!\n");

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{
			delete enemy[i];
			enemy[i] = NULL;
		}
	}
	//printf("enemy ¼Ò¸ê!\n");

	printf("gamescene Å¬·¡½º ¼Ò¸ê!\n");
	//system("pause");
}

void GameScene::Loop()
{
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	printf("x = %d, y = %d\n", pt.x, pt.y);

	if (select == GAMESTART)
	{
		player->setKeydown();
		player->setSpeed(15.0f);

		if (enemyCount < MAX_ENEMY)
		{
			for (int i = 0; i < MAX_ENEMY; i++)
			{
				if (enemy[i] == NULL)
				{
					enemy[i] = new Enemy(hWnd, g_hInst);
					enemy[i]->setRECT_Point(rand() % Drawmap_WIDTH + 0, rand() % Drawmap_HEIGHT + 0);
					enemyCount += 1;
				}
			}
		}

		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (player->playerImage[player->Image_toggle]->get_X() > enemy[i]->enemyImage[enemy[i]->Image_toggle]->get_X())
			{
				enemy[i]->Image_toggle = 0;
			}
			else
			{
				enemy[i]->Image_toggle = 1;
			}

			if (player->getRECT_left() != enemy[i]->getRECT_left() || player->getRECT_top() != enemy[i]->getRECT_top())
			{
				if (player->getRECT_left() > enemy[i]->getRECT_left())
				{
					enemy[i]->setRECT_left(enemy[i]->getRECT_left() + enemy[i]->speed);
				}

				if (player->getRECT_top() > enemy[i]->getRECT_top())
				{
					enemy[i]->setRECT_top(enemy[i]->getRECT_top() + enemy[i]->speed);
				}

				if (player->getRECT_left() < enemy[i]->getRECT_left())
				{
					enemy[i]->setRECT_left(enemy[i]->getRECT_left() - enemy[i]->speed);
				}

				if (player->getRECT_top() < enemy[i]->getRECT_top())
				{
					enemy[i]->setRECT_top(enemy[i]->getRECT_top() - enemy[i]->speed);
				}

				enemy[i]->setRECT_right(enemy[i]->getRECT_left() + 50);
				enemy[i]->setRECT_bottom(enemy[i]->getRECT_top() + 50);
			}

			if (isCollision(player->getRECT(), enemy[i]->getRECT()))
			{
				if (player->Gameover())
				{
					select = PAUSE;
					break;
				}

				delete enemy[i];
				enemy[i] = NULL;
				enemyCount -= 1;
			}
		}
	}
	else if (select == PAUSE)
	{
		if (Alpha < 100)
			Alpha += 1;
	}
}

void GameScene::DrawImage()
{
	background->set_X(-background->get_W() / 4 + player->moving_x);
	background->set_Y(-background->get_H() / 4 + player->moving_y);
	this->Draw_BitBlt(background);

	this->Draw_BitBlt(player->HP);
	this->Draw_TransparentBlt(player->HPbar, 255, 255, 255);

	this->Draw_TransparentBlt(player->playerImage[player->Image_toggle], 255, 255, 255);

	for (int i = 0; i < enemyCount; i++)
	{
		if (enemy[i] != NULL)
		{
			enemy[i]->enemyImage[enemy[i]->Image_toggle]->set_X(enemy[i]->getRECT_left() + background->get_X());
			enemy[i]->enemyImage[enemy[i]->Image_toggle]->set_Y(enemy[i]->getRECT_top() + background->get_Y());

			this->Draw_TransparentBlt(enemy[i]->enemyImage[enemy[i]->Image_toggle], 255, 255, 255);
		}
	}

	if (select == PAUSE)
	{
		this->Draw_AlphaBlend(gameover_ground, 100 + Alpha);

		if (Alpha == 100)
		{
			this->Draw_TransparentBlt(Gameover_Icon, 0, 0, 0);

			if (pt.x >= ReStart_Icon[0]->get_X() && pt.x <= (ReStart_Icon[0]->get_X() + ReStart_Icon[0]->GetWidth()) && pt.y >= ReStart_Icon[0]->get_Y() && pt.y <= (ReStart_Icon[0]->get_Y() + ReStart_Icon[0]->GetHeight()))
			{
				this->Draw_TransparentBlt(ReStart_Icon[1], 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					ClickMouse = true;
					select = RESTART;
					printf("Start Å¬¸¯!\n");
				}
			}
			else
			{
				this->Draw_TransparentBlt(ReStart_Icon[0], 0, 0, 0);
			}

			if (pt.x >= MainScene_Icon[0]->get_X() && pt.x <= (MainScene_Icon[0]->get_X() + MainScene_Icon[0]->GetWidth()) && pt.y >= MainScene_Icon[0]->get_Y() && pt.y <= (MainScene_Icon[0]->get_Y() + MainScene_Icon[0]->GetHeight()))
			{
				this->Draw_TransparentBlt(MainScene_Icon[1], 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					ClickMouse = true;
					select = MAINSCENE;
					printf("Start Å¬¸¯!\n");
				}
			}
			else
			{
				this->Draw_TransparentBlt(MainScene_Icon[0], 0, 0, 0);
			}
		}
	}

	this->Draw();
}
