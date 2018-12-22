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
				//enemy[i]->enemyImage[0]->set_X(enemy[i]->getfield_x() + background->get_X());
				enemyCount += 1;
			}
		}
	}
}

void GameScene::DrawImage()
{
	background->set_X(-background->get_W() / 4 + player->moving_x);
	background->set_Y(-background->get_H() / 4 + player->moving_y);
	this->Draw_BitBlt(background);

	if (player->Image_toggle == 1)
	{
		this->Draw_TransparentBlt(player->playerImage[0], 255, 255, 255);
	}
	else if (player->Image_toggle == -1)
	{
		this->Draw_TransparentBlt(player->playerImage[1], 255, 255, 255);
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{

			enemy[i]->enemyImage[0]->set_X(enemy[i]->getfield_x() + background->get_X());
			enemy[i]->enemyImage[0]->set_Y(enemy[i]->getfield_y() + background->get_Y());

			enemy[i]->enemyImage[1]->set_X(enemy[i]->enemyImage[0]->get_X());
			enemy[i]->enemyImage[1]->set_Y(enemy[i]->enemyImage[0]->get_Y());

			if (player->playerImage[0]->get_X() > enemy[i]->enemyImage[0]->get_X())
			{
				this->Draw_TransparentBlt(enemy[i]->enemyImage[0], 255, 255, 255);
			}
			else
			{
				this->Draw_TransparentBlt(enemy[i]->enemyImage[1], 255, 255, 255);
			}
		}
	}

	this->Draw();
}
