#include "PNG_Image.h"

PNG_Image::PNG_Image()
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

PNG_Image::PNG_Image(HMODULE hModule, int IpPngName)
{
	image = LoadPNG(hModule, MAKEINTRESOURCE(IpPngName));

	x = 0;
	y = 0;
	w = GetWidth();
	h = GetHeight();
}

PNG_Image::~PNG_Image()
{
	delete image;
	GdiplusShutdown(gdiplusToken);
	printf("PNG Å¬·¡½º ¼Ò¸ê!\n");
}

Image * PNG_Image::LoadPNG(HMODULE hModule, LPCWSTR ResourceName)
{
	Image* image = NULL;
	IStream* pStream = NULL;

	HRSRC hResource = FindResource(hModule, ResourceName, L"PNG");

	if (CreateStreamOnHGlobal(NULL, TRUE, &pStream) == S_OK)
	{
		PVOID pResourceData = LockResource(LoadResource(hModule, hResource));
		DWORD imageSize = SizeofResource(hModule, hResource);
		DWORD dwReadWrite = 0;
		pStream->Write(pResourceData, imageSize, &dwReadWrite);
		image = Image::FromStream(pStream);
		pStream->Release();
	}

	return image;
}

void PNG_Image::LoadPNG(HMODULE hModule, int IpPngName)
{
	image = LoadPNG(hModule, MAKEINTRESOURCE(IpPngName));

	x = 0;
	y = 0;
	w = GetWidth();
	h = GetHeight();
}

Image* PNG_Image::GetImage()
{
	return image;
}
