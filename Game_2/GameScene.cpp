#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::GameScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	background = new gBitmap;
	background->SetBitmap(hWnd, g_hInst, IDB_background);

	playerImage[0] = new gBitmap;
	playerImage[0]->SetBitmap(hWnd, g_hInst, IDB_Player1);
	playerImage[0]->set_X(WIN_WIDTH / 2 - playerImage[0]->get_W() / 2);
	playerImage[0]->set_Y(WIN_HEIGHT / 2 - playerImage[0]->get_H() / 2);

	playerImage[1] = new gBitmap;
	playerImage[1]->SetBitmap(hWnd, g_hInst, IDB_Player3);
	playerImage[1]->set_X(WIN_WIDTH / 2 - playerImage[1]->get_W() / 2);
	playerImage[1]->set_Y(WIN_HEIGHT / 2 - playerImage[1]->get_H() / 2);

	player = new Player;
}

GameScene::~GameScene()
{
	delete background;
	background = NULL;

	for (int i = 0; i < 2; i++)
	{
		delete playerImage[i];
	}

	delete player;

	printf("gamescene Å¬·¡½º ¼Ò¸ê!\n");
}

void GameScene::Loop()
{
	player->setKeydown();
	//player->setSpeed_x(5.0f);
}

void GameScene::DrawImage()
{
	background->set_X(-background->get_W() / 4 + player->moving_x);
	background->set_Y(-background->get_H() / 4 + player->moving_y);
	this->Draw_BitBlt(background);

	if (player->Image_toggle == 1)
	{
		this->Draw_TransparentBlt(playerImage[0], 255, 255, 255);
	}
	else if (player->Image_toggle == -1)
	{
		this->Draw_TransparentBlt(playerImage[1], 255, 255, 255);
	}

	this->Draw();
}
