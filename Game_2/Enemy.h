#pragma once

#include <Windows.h>
#include "Layer.h"
#include <stdio.h>
#include "Character.h"

class Enemy : public Character
{
public:
	gBitmap* enemyImage[2];

public:
	Enemy(HWND hWnd, HINSTANCE g_hInst);
	~Enemy();
};