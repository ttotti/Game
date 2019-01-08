#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "PNG_Image.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define Drawmap_WIDTH 1800
#define Drawmap_HEIGHT 1000

class Layer
{
private:
	HDC hdc, MemDC, BackDC;
	HWND hWnd;
	HINSTANCE g_hInst;

	HBITMAP b_BackImage;
	HBITMAP b_hPreBit;

	BLENDFUNCTION m_BlendFunction;

public:
	Layer();
	Layer(HINSTANCE g_hInst, HWND hWnd);
	~Layer();

	void Init();
	void DeleteImage();

	void Draw();

	void Draw_BitBlt(gBitmap* bitmap);
	void Draw_StretchBit(gBitmap* bitmap);
	void Draw_TransparentBlt(gBitmap* bitmap, int r, int g, int b);
	void Draw_AlphaBlend(gBitmap* bitmap, BYTE SourceConstantAlpha, BYTE BlendOp = AC_SRC_OVER, BYTE BlendFlags = 0, BYTE AlphaFormat = 0);

	void Draw_PNGImage(PNG_Image* image);

	HWND Get_hWnd();
	HINSTANCE Get_g_hInst();
};