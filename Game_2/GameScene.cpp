#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::GameScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd), hWnd(hWnd), g_hInst(g_hInst), enemyCount(0)
{
	background = new gBitmap;
	background->SetBitmap(hWnd, g_hInst, IDB_background);

	player = new Player(hWnd, g_hInst);

	background->set_X(-background->get_W() / 4 + player->moving_x);
	background->set_Y(-background->get_H() / 4 + player->moving_y);

	player->setRECT_left(player->getRECT_left() - background->get_X());
	player->setRECT_top(player->getRECT_top() - background->get_Y());

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i] = NULL;
	}
}

GameScene::~GameScene()
{
	delete background;
	background = NULL;

	delete player;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
			delete enemy[i];
	}

	printf("gamescene Å¬·¡½º ¼Ò¸ê!\n");
}

void GameScene::Loop()
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
			delete enemy[i];
			enemy[i] = NULL;
			enemyCount -= 1;
		}
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

	this->Draw();
}
