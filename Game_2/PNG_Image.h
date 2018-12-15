#pragma once

//#pragma comment(lib,"Gdiplus.lib")

#include <Windows.h>
#include <stdio.h>
#include <gdiplus.h>

using namespace Gdiplus;

class PNG_Image
{
private:
	ULONG_PTR gdiplusToken;

	GdiplusStartupInput gdiplusStartupInput;
	
	Image* image;

private:
	float x, y, w, h;
	int bmWidth, bmHeight;

public:
	inline float get_X() { return x; }
	inline float get_Y() { return y; }
	inline float get_W() { return w; }
	inline float get_H() { return h; }

	inline int GetWidth() { return image->GetWidth(); }
	inline int GetHeight() { return image->GetHeight(); }

	inline void set_X(float x) { this->x = x; }
	inline void set_Y(float y) { this->y = y; }
	inline void set_W(float w) { this->w = w; }
	inline void set_H(float h) { this->h = h; }
	inline void set_AllPoint(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

public:
	PNG_Image();
	PNG_Image(HMODULE hModule, int IpPngName);
	~PNG_Image();

	Image* LoadPNG(HMODULE hModule, LPCWSTR ResourceName);
	void LoadPNG(HMODULE hModule, int IpPngName);

	Image* GetImage();
};