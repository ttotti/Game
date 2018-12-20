#include "MainScene.h"

MainScene::MainScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd), ClickMouse(false), selectMenu(0)
{
	mainScene = new gBitmap;
	mainScene->SetBitmap(hWnd, g_hInst, IDB_mainScene);

	StartIcon = new gBitmap;
	StartIcon->SetBitmap(hWnd, g_hInst, IDB_StartIcon);

	QuitIcon = new gBitmap;
	QuitIcon->SetBitmap(hWnd, g_hInst, IDB_QuitIcon);

	StartIcon2 = new gBitmap;
	StartIcon2->SetBitmap(hWnd, g_hInst, IDB_StartIcon2);

	QuitIcon2 = new gBitmap;
	QuitIcon2->SetBitmap(hWnd, g_hInst, IDB_QuitIcon2);
}

MainScene::~MainScene()
{
	delete mainScene;
	mainScene = NULL;

	delete StartIcon;
	StartIcon = NULL;

	delete QuitIcon;
	QuitIcon = NULL;

	delete StartIcon2;
	StartIcon = NULL;

	delete QuitIcon2;
	QuitIcon = NULL;

	printf("MainScene 클래스 소멸!\n");
	//system("pause");
}

void MainScene::setMouse(int M_x, int M_y, int C_x, int C_y)
{
	this->M_x = M_x;
	this->M_y = M_y;
	this->C_x = C_x;
	this->C_y = C_y;
}

void MainScene::DrawImage()
{
	this->Draw_BitBlt(mainScene);

	StartIcon->set_X((WIN_WIDTH / 2) / 2 - 50);
	StartIcon->set_Y((WIN_HEIGHT / 2) + 100);
	this->Draw_BitBlt(StartIcon);

	QuitIcon->set_X((WIN_WIDTH / 2));
	QuitIcon->set_Y((WIN_HEIGHT / 2) + 100);
	this->Draw_BitBlt(QuitIcon);

	if (M_x >= StartIcon->get_X() && M_x <= (StartIcon->get_X() + StartIcon->GetWidth()) && M_y >= StartIcon->get_Y() && M_y <= (StartIcon->get_Y() + StartIcon->GetHeight()))
	{
		printf("Start 버튼!\n");
		StartIcon2->set_X((WIN_WIDTH / 2) / 2 - 50);
		StartIcon2->set_Y((WIN_HEIGHT / 2) + 100);
		this->Draw_BitBlt(StartIcon2);
	}
	else if (M_x >= QuitIcon->get_X() && M_x <= (QuitIcon->get_X() + QuitIcon->GetWidth()) && M_y >= QuitIcon->get_Y() && M_y <= (QuitIcon->get_Y() + QuitIcon->GetHeight()))
	{
		printf("Quit 버튼!\n");
		QuitIcon2->set_X((WIN_WIDTH / 2));
		QuitIcon2->set_Y((WIN_HEIGHT / 2) + 100);
		this->Draw_BitBlt(QuitIcon2);
	}

	if (C_x >= StartIcon->get_X() && C_x <= (StartIcon->get_X() + StartIcon->GetWidth()) && C_y >= StartIcon->get_Y() && C_y <= (StartIcon->get_Y() + StartIcon->GetHeight()))
	{
		ClickMouse = true;
		selectMenu = GAMESCENE;
		printf("Start 클릭!\n");
	}
	else if (C_x >= QuitIcon->get_X() && C_x <= (QuitIcon->get_X() + QuitIcon->GetWidth()) && C_y >= QuitIcon->get_Y() && C_y <= (QuitIcon->get_Y() + QuitIcon->GetHeight()))
	{
		ClickMouse = true;
		selectMenu = QUIT;
		printf("Quit 클릭!\n");
	}

	this->Draw();
}

int MainScene::getSelectMenu()
{
	return selectMenu;
}
