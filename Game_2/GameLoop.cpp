#include "GameLoop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
	delete mainscene;
	mainscene = NULL;

	delete gamescene;
	gamescene = NULL;
}

void GameLoop::init(HINSTANCE g_hInst, HWND hWnd)
{
	this->g_hInst = g_hInst;
	this->hWnd = hWnd;

	selectMenu = MAINSCENE;

	mainscene = NULL;
}

void GameLoop::Loop()
{
	switch (selectMenu)
	{
	case MAINSCENE:
		if (mainscene == NULL)
		{
			mainscene = new MainScene(g_hInst, hWnd);
		}

		mainscene->setCilck(C_x, C_y);
		mainscene->DrawImage();

		if (mainscene->ClickMouse)
		{
			switch (mainscene->selectMenu)
			{
			case GAMESCENE:
				selectMenu = GAMESCENE;

				delete mainscene;
				mainscene = NULL;

				break;

			case QUIT:
				selectMenu = QUIT;

				delete mainscene;
				mainscene = NULL;

				break;

			default:
				break;
			}
		}

		break;

	case GAMESCENE:
		if (gamescene == NULL)
		{
			gamescene = new GameScene(g_hInst, hWnd);
		}

		gamescene->Loop();
		gamescene->DrawImage();

		break;

	case QUIT:
		DestroyWindow(hWnd);
		break;

	default:
		break;
	}
}
