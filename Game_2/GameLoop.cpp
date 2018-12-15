#include "GameLoop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
	delete mainscene;
	mainscene = NULL;
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

		break;

	default:
		break;
	}
}
