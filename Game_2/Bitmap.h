#pragma once

#include <Windows.h>
#include <stdio.h>

#include "resource.h"

class gBitmap
{
private:
	float x, y, w, h;
	int bmWidth, bmHeight;

public:
	float get_X();
	float get_Y();
	float get_W();
	float get_H();

	int GetWidth();
	int GetHeight();

	HBITMAP Getbitmap();

	void set_X(float x);
	void set_Y(float y);
	void set_W(float w);
	void set_H(float h);
	void set_AllPoint(float x, float y, float w, float h);

public:
	BITMAP bit;

	HBITMAP map;

public:
	gBitmap();
	~gBitmap();

	void SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName);
};