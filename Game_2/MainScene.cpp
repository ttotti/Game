#include "MainScene.h"

MainScene::MainScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	mainScene = new gBitmap;
	mainScene->SetBitmap(hWnd, g_hInst, IDB_mainScene);

	StartIcon = new gBitmap;
	StartIcon->SetBitmap(hWnd, g_hInst, IDB_StartIcon);

	QuitIcon = new gBitmap;
	QuitIcon->SetBitmap(hWnd, g_hInst, IDB_QuitIcon);
}

MainScene::~MainScene()
{
	delete mainScene;
	mainScene = NULL;

	delete StartIcon;
	StartIcon = NULL;

	delete QuitIcon;
	QuitIcon = NULL;

	printf("MainScene 클래스 소멸!\n");
	system("pause");
}

void MainScene::setCilck(int C_x, int C_y)
{
	this->C_x = C_x;
	this->C_y = C_y;
}

void MainScene::DrawImage()
{
	this->Draw_BitBlt(mainScene);

	StartIcon->set_X((WIN_WIDTH / 2)/2-50);
	StartIcon->set_Y((WIN_HEIGHT / 2)+100);
	this->Draw_BitBlt(StartIcon);

	QuitIcon->set_X((WIN_WIDTH / 2));
	QuitIcon->set_Y((WIN_HEIGHT / 2) + 100);
	this->Draw_BitBlt(QuitIcon);

	if (C_x >= QuitIcon->get_X() && C_x <= (QuitIcon->get_X() + QuitIcon->GetWidth()) && C_y >= QuitIcon->get_Y() && C_y <= (QuitIcon->get_Y() + QuitIcon->GetHeight()))
	{
		printf("Quit 클릭!\n");
	}

	this->Draw();
}
