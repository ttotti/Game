#include <Windows.h> // �������

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
#pragma comment(lib,"Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // ���� API�Լ����� �ν��Ͻ� ���� �䱸�ϴµ� hInstance �μ��� ���������̱� ������ WinMain �ۿ��� �������� �׷��� �������� g_hinst�� �����صд�
LPCTSTR lpszClass = TEXT("Class");

// ������
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; // ������ ���࿵�� ������� ���������� ����ϸ� ���� Ư���� ������ ���Ǵ� ������ �����̴�
	WndClass.cbWndExtra = 0; // ���࿵���� ������� ���� ��� 0���� �����Ѵ�
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // �� ������ ����ڰ� �����ǿ��� ������ �������� �����̸� �ý��� �����̶�� �Ѵ�(�ý��� ������ ���� �ٲ���ִ�(���뼺))
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // �����찡 ����� ���콺 Ŀ���� �������� �����Ѵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_ERROR);
	WndClass.hInstance = hInstance; // ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ�̸� WinMain�� �μ��� ���޵� hinstance���� �״�� �����ϸ� �ȴ�
	WndClass.lpfnWndProc = WndProc; // �������� �޽��� ó�� �Լ��� �����Ѵ�
	WndClass.lpszClassName = lpszClass; // ������ Ŭ������ �̸��� ���ڿ��� �����Ѵ�
	WndClass.lpszMenuName = NULL; // �� ���α׷��� ����� �޴��� �����Ѵ� // ���ҽ� �����Ϳ� ���� ������ ������� ��ũ�ÿ� ���� ��������
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // �����찡 � ���¸� ���� ���ΰ��� �����ϴ� ���
	RegisterClass(&WndClass); // WNDCLASS ����ü�� ������ �����Ѵ� // �̷� Ư���� ���� �����츦 ������ ����ϰڴٴ� ��� �����̴�

							  // ������ ����
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);
	// �޸𸮿� ������� �����츦 ȭ�鿡 ���̰� �ϴ� �Լ�
	ShowWindow(hWnd, nCmdShow);

	// �޽��� ����
	while (GetMessage(&Message, NULL, 0, 0)) // LPMSG IpMsg ù��° �μ� // �޽��� ť���� �޽����� �о��� WN_QUIT �ϰ�� FALSE�� �����ϸ� �������� TRUE�� �����Ѵ� // �������μ��� �� �Ⱦ���
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽����� �����Ͽ� ���α׷����� ���� �� �� �ֵ��� �Ѵ�
		DispatchMessage(&Message); // �޽��� ť���� ���� �޽����� �������� �޽��� ó�� �Լ�(WndProc)�� �����Ѵ�
	}

	return (int)Message.wParam;
}

void MyText(HDC hdc, int x, int y, LPCTSTR Text)
{
	TextOut(hdc, x, y, Text, lstrlen(Text));
}

#include "GameLoop.h"

GameLoop gameloop;

// ����ڿ� �ý����� �������� �޽����� ó���ϴ� ���� �߿��� ���� �Ѵ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HWND hWndMain;

	switch (iMessage)
	{
	case WM_CREATE:
		hWndMain = hWnd;
		SetTimer(hWnd, 1, 10, NULL);

		gameloop.init(g_hInst, hWnd);
		return 0;
	
	case WM_TIMER:
		srand(GetTickCount());
		gameloop.Loop();
		return 0;

	case WM_MOUSEMOVE:
		gameloop.M_x = LOWORD(lParam);
		gameloop.M_y = HIWORD(lParam);
		printf("x = %d, y = %d\n", LOWORD(lParam), HIWORD(lParam));
		return 0;

	case WM_LBUTTONDOWN:
		gameloop.C_x = LOWORD(lParam);
		gameloop.C_y = HIWORD(lParam);
		return 0;

	case WM_LBUTTONUP:
		gameloop.C_x = 0;
		gameloop.C_y = 0;
		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}