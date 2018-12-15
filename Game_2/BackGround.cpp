#include "BackGround.h"

BackGround::BackGround(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	background = new gBitmap;
	background->SetBitmap(hWnd, g_hInst, IDB_background);

	mainScene = new gBitmap;
	mainScene->SetBitmap(hWnd, g_hInst, IDB_mainScene);
}

BackGround::~BackGround()
{
	delete background;
	background = NULL;

	delete mainScene;
	mainScene = NULL;

	printf("Background Å¬·¡½º ¼Ò¸ê!\n");
	system("pause");
}

void BackGround::DrawImage()
{
	this->Draw_BitBlt(mainScene);
	//this->Draw_BitBlt(background);

	this->Draw();
}
