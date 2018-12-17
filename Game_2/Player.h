#pragma once

#include <Windows.h>
#include <stdio.h>
#include "macro.h"

class Player
{
public:
	int moving;

public:
	Player();
	~Player();

	int direction();
	void setKeydown();
};