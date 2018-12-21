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


	moving_x = 0.0f;
	moving_y = 0.0f;
	speed_x = 2.0f;
	speed_y = 2.0f;
	Image_toggle = 1;

	field_x = 0.0f;
	field_y = 0.0f;
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

void Enemy::setSpeed_x(float speed)
{
	speed_x = speed;
}

void Enemy::setSpeed_y(float speed)
{
	speed_y = speed;
}

void Enemy::setfield_Point(float field_x, float field_y)
{
	this->field_x = field_x;
	this->field_y = field_y;
}

void Enemy::setfield_x(float field_x)
{
	this->field_x = field_x;
}

void Enemy::setfield_y(float field_y)
{
	this->field_y = field_y;
}

float Enemy::getfield_x()
{
	return field_x;
}

float Enemy::getfield_y()
{
	return field_y;
}
