#include "MainScene.h"

MainScene::MainScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd), ClickMouse(false), selectMenu(0), hWnd(hWnd)
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

void MainScene::DrawImage()
{
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	this->Draw_BitBlt(mainScene);

	StartIcon->set_X((WIN_WIDTH / 2) / 2 - 50);
	StartIcon->set_Y((WIN_HEIGHT / 2) + 100);
	this->Draw_BitBlt(StartIcon);

	QuitIcon->set_X((WIN_WIDTH / 2));
	QuitIcon->set_Y((WIN_HEIGHT / 2) + 100);
	this->Draw_BitBlt(QuitIcon);

	printf("x = %d, y = %d\n", pt.x, pt.y);

	if (pt.x >= StartIcon->get_X() && pt.x <= (StartIcon->get_X() + StartIcon->GetWidth()) && pt.y >= StartIcon->get_Y() && pt.y <= (StartIcon->get_Y() + StartIcon->GetHeight()))
	{
		printf("Start 버튼!\n");
		StartIcon2->set_X((WIN_WIDTH / 2) / 2 - 50);
		StartIcon2->set_Y((WIN_HEIGHT / 2) + 100);
		this->Draw_BitBlt(StartIcon2);

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			ClickMouse = true;
			selectMenu = GAMESCENE;
			printf("Start 클릭!\n");
		}
	}
	else if (pt.x >= QuitIcon->get_X() && pt.x <= (QuitIcon->get_X() + QuitIcon->GetWidth()) && pt.y >= QuitIcon->get_Y() && pt.y <= (QuitIcon->get_Y() + QuitIcon->GetHeight()))
	{
		printf("Quit 버튼!\n");
		QuitIcon2->set_X((WIN_WIDTH / 2));
		QuitIcon2->set_Y((WIN_HEIGHT / 2) + 100);
		this->Draw_BitBlt(QuitIcon2);

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			ClickMouse = true;
			selectMenu = QUIT;
			printf("Quit 클릭!\n");
		}
	}

	this->Draw();
}
