#include "Bitmap.h"

gBitmap::gBitmap()
{
}

gBitmap::~gBitmap()
{
	DeleteObject(map);
	printf("Bitmap Ŭ���� �Ҹ�!\n");
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
