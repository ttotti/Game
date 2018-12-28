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

	player->setfield_x(player->getfield_x() - background->get_X());
	player->setfield_y(player->getfield_y() - background->get_Y());

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
	player->setSpeed_x(15.0f);
	player->setSpeed_y(15.0f);

	if (enemyCount < MAX_ENEMY)
	{
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (enemy[i] == NULL)
			{
				enemy[i] = new Enemy(hWnd, g_hInst);
				enemy[i]->setfield_Point(rand() % Drawmap_WIDTH + 0, rand() % Drawmap_HEIGHT + 0);
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

		if (player->getfield_x() != enemy[i]->getfield_x() || player->getfield_y() != enemy[i]->getfield_y())
		{
		//	printf("player->getfield_x = %f\n", player->getfield_x());
		//	printf("player->getfield_y = %f\n\n", player->getfield_y());
		//	printf("enemy->getfield_x = %f\n", enemy[0]->getfield_x());
		    //printf("enemy->getfield_y = %f\n\n", enemy[0]->getfield_y());

			if (player->getfield_x() > enemy[i]->getfield_x())
			{
				enemy[i]->setfield_x(enemy[i]->getfield_x() + enemy[i]->moving_x);
			}

			if (player->getfield_y() > enemy[i]->getfield_y())
			{
				enemy[i]->setfield_y(enemy[i]->getfield_y() + enemy[i]->moving_y);
			}

			if (player->getfield_x() < enemy[i]->getfield_x())
			{
				enemy[i]->setfield_x(enemy[i]->getfield_x() - enemy[i]->moving_x);
			}

			if (player->getfield_y() < enemy[i]->getfield_y())
			{
				enemy[i]->setfield_y(enemy[i]->getfield_y() - enemy[i]->moving_y);
			}

			enemy[i]->setfield_w(enemy[i]->getfield_x() + 50);
			enemy[i]->setfield_h(enemy[i]->getfield_y() + 50);
		}

		if (player->getfield_x() <= enemy[i]->getfield_x() &&
			player->getfield_w() >= enemy[i]->getfield_x() &&
			player->getfield_y() <= enemy[i]->getfield_y() &&
			player->getfield_h() >= enemy[i]->getfield_y())
		{
			delete enemy[i];
			enemy[i] = NULL;
			enemyCount -= 1;
		}


		//if (player->getfield_x() == enemy[i]->getfield_x() 
		//	&& player->getfield_x()+50
		//	&& player->getfield_y() == enemy[i]->getfield_y())
		//{
		//	delete enemy[i];
		//	enemy[i] = NULL;
		//	enemyCount -= 1;
		//}
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
			enemy[i]->enemyImage[0]->set_X(enemy[i]->getfield_x() + background->get_X());
			enemy[i]->enemyImage[0]->set_Y(enemy[i]->getfield_y() + background->get_Y());

			enemy[i]->enemyImage[1]->set_X(enemy[i]->enemyImage[0]->get_X());
			enemy[i]->enemyImage[1]->set_Y(enemy[i]->enemyImage[0]->get_Y());

			this->Draw_TransparentBlt(enemy[i]->enemyImage[enemy[i]->Image_toggle], 255, 255, 255);
		}
	}

	this->Draw();
}
