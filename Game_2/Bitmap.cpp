#include "Bitmap.h"

gBitmap::gBitmap()
{
}

gBitmap::~gBitmap()
{
	DeleteObject(map);
	printf("Bitmap Å¬·¡½º ¼Ò¸ê!\n");
	//system("pause");
}

void gBitmap::SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName)
{
	map = LoadBitmap(hInstance, MAKEINTRESOURCE(IpBitmapName));

	x = 0;
	y = 0;
	w = GetWidth();
	h = GetHeight();
} 

int gBitmap::GetWidth()
{
	GetObject(map, sizeof(BITMAP), &bit);
	return bit.bmWidth;
}

int gBitmap::GetHeight()
{
	GetObject(map, sizeof(BITMAP), &bit);
	return bit.bmHeight;
}

HBITMAP gBitmap::Getbitmap()
{
	return map;
}

float gBitmap::get_X()
{
	return x;
}

float gBitmap::get_Y()
{
	return y;
}

float gBitmap::get_W()
{
	return w;
}

float gBitmap::get_H()
{
	return h;
}

void gBitmap::set_X(float x)
{
	this->x = x;
}

void gBitmap::set_Y(float y)
{
	this->y = y;
}

void gBitmap::set_W(float w)
{
	this->w = w;
}

void gBitmap::set_H(float h)
{
	this->h = h;
}

void gBitmap::set_AllPoint(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
