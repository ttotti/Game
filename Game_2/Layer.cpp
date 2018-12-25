#include "Layer.h"

Layer::Layer()
{
	Init();
}

Layer::Layer(HINSTANCE g_hInst, HWND hWnd)
{
	this->g_hInst = g_hInst;
	this->hWnd = hWnd;
	Init();
}

Layer::~Layer()
{
	DeleteImage();
}

void Layer::Init()
{
	hdc = GetDC(hWnd);
	MemDC = CreateCompatibleDC(hdc);
	BackDC = CreateCompatibleDC(hdc);
	b_BackImage = CreateCompatibleBitmap(hdc, Drawmap_WIDTH, Drawmap_HEIGHT);

	b_hPreBit = (HBITMAP)SelectObject(MemDC, b_BackImage);
}

void Layer::DeleteImage()
{
	SelectObject(MemDC, b_hPreBit);

	DeleteObject(BackDC);
	DeleteObject(b_BackImage);
	DeleteDC(MemDC);

	DeleteObject(b_Image);

	ReleaseDC(hWnd, hdc);

	//printf("Layer Å¬·¡½º ¼Ò¸ê!\n");
}

void Layer::Draw()
{
	BitBlt(hdc, 0, 0, Drawmap_WIDTH, Drawmap_HEIGHT, MemDC, 0, 0, SRCCOPY);

	DeleteImage();

	Init();
}

void Layer::Draw_BitBlt(gBitmap* bitmap)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	BitBlt(MemDC, bitmap->get_X(), bitmap->get_Y(), bitmap->get_W(), bitmap->get_H(), BackDC, 0, 0, SRCCOPY);
}

void Layer::Draw_StretchBit(gBitmap* bitmap)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	StretchBlt(MemDC, bitmap->get_X(), bitmap->get_Y(), bitmap->get_W(), bitmap->get_H(), BackDC, 0, 0, bitmap->GetWidth(), bitmap->GetHeight(), SRCCOPY);
}

void Layer::Draw_TransparentBlt(gBitmap* bitmap, int r, int g, int b)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	TransparentBlt(MemDC, bitmap->get_X(), bitmap->get_Y(), bitmap->get_W(), bitmap->get_H(), BackDC, 0, 0, bitmap->GetWidth(), bitmap->GetHeight(), RGB(r, g, b));
}

void Layer::Draw_PNGImage(PNG_Image* image)
{
	Graphics graphics(MemDC);

	graphics.DrawImage(image->GetImage(), image->get_X(), image->get_Y(), image->get_W(), image->get_H());
}

HWND Layer::Get_hWnd()
{
	return hWnd;
}

HINSTANCE Layer::Get_g_hInst()
{
	return g_hInst;
}
