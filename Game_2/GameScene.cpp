#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::GameScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	background = new gBitmap;
	background->SetBitmap(hWnd, g_hInst, IDB_background);
}

GameScene::~GameScene()
{
	delete background;
	background = NULL;

	printf("gamescene Å¬·¡½º ¼Ò¸ê!\n");
}

void GameScene::DrawImage()
{
	this->Draw_BitBlt(background);

	this->Draw();
}
