#include "Enemy.h"

Enemy::Enemy(HWND hWnd, HINSTANCE g_hInst)
{
	/*for (int i = 0; i < 2; i++)
	{
		enemyImage[i] = new gBitmap;
		enemyImage[i]->SetBitmap(hWnd, g_hInst, IDB_Enemy1 + i);
	}*/

	enemyImage[0] = new gBitmap;
	enemyImage[0]->SetBitmap(hWnd, g_hInst, IDB_Enemy1);

	enemyImage[1] = new gBitmap;
	enemyImage[1]->SetBitmap(hWnd, g_hInst, IDB_Enemy3);

	moving_x = 2.0f;
	moving_y = 2.0f;
	speed_x = 2.0f;
	speed_y = 2.0f;
	Image_toggle = 1;

	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;
}

Enemy::~Enemy()
{
	for (int i = 0; i < 2; i++)
	{
		delete enemyImage[i];
		enemyImage[i] = NULL;
	}

	printf("Enemy ¼Ò¸ê!\n");
}
