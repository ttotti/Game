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
	playerImage[1] = new gBitmap;
	playerImage[1]->SetBitmap(hWnd, g_hInst, IDB_Player3);

	player = new Player;
}

GameScene::~GameScene()
{
	delete background;
	background = NULL;

	delete[] playerImage;

	delete player;

	printf("gamescene Å¬·¡½º ¼Ò¸ê!\n");
}

void GameScene::Loop()
{
	player->setKeydown();
}

void GameScene::DrawImage()
{
	this->Draw_BitBlt(background);

	this->Draw();
}
