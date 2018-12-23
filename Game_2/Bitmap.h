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
	BITMAP bit;

	HBITMAP map;

public:
	float get_X() { return x; }
	float get_Y() { return y; }
	float get_W() { return w; }
	float get_H() { return h; }

	int GetWidth()
	{
		GetObject(map, sizeof(BITMAP), &bit);
		return bit.bmWidth;
	}
	int GetHeight()
	{
		GetObject(map, sizeof(BITMAP), &bit);
		return bit.bmHeight;
	}

	HBITMAP Getbitmap() { return map; }

	void set_X(float x) { this->x = x; }
	void set_Y(float y){ this->y = y; }
	void set_W(float w){ this->w = w; }
	void set_H(float h){ this->h = h; }

	void set_AllPoint(float x, float y, float w, float h) 
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

public:
	gBitmap();
	~gBitmap();

	void SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName);
};