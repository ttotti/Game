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

	speed = 2.0f;
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
