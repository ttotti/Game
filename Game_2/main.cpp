#include <Windows.h> // 헤더파일

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
#pragma comment(lib,"Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst; // 많은 API함수들이 인스턴스 값을 요구하는데 hInstance 인수는 지역변수이기 때문에 WinMain 밖에서 쓸수없다 그래서 전역변수 g_hinst에 대입해둔다
LPCTSTR lpszClass = TEXT("Class");

// 시작점
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0; // 일종의 예약영역 윈도우즈가 내부적으로 사용하며 아주 특수한 목적에 사용되는 여분의 공간이다
	WndClass.cbWndExtra = 0; // 예약영역을 사용하지 않을 경우 0으로 지정한다
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 이 색상은 사용자가 제어판에서 선택한 윈도우의 배경색이며 시스템 색상이라고 한다(시스템 설정에 따라 바뀔수있다(범용성))
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 윈도우가 사용할 마우스 커서와 아이콘을 지정한다
	WndClass.hIcon = LoadIcon(NULL, IDI_ERROR);
	WndClass.hInstance = hInstance; // 윈도우 클래스를 등록하는 프로그램의 번호이며 WinMain의 인수로 전달된 hinstance값을 그대로 대입하면 된다
	WndClass.lpfnWndProc = WndProc; // 윈도우의 메시지 처리 함수를 지정한다
	WndClass.lpszClassName = lpszClass; // 윈도우 클래스의 이름을 문자열로 정의한다
	WndClass.lpszMenuName = NULL; // 이 프로그램이 사용할 메뉴를 지정한다 // 리소스 에디터에 의해 별도로 만들어져 링크시에 같이 합쳐진다
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // 윈도우가 어떤 형태를 가질 것인가를 지정하는 멤버
	RegisterClass(&WndClass); // WNDCLASS 구조체의 번지를 전달한다 // 이런 특성을 가진 윈도우를 앞으로 사용하겠다는 등록 과정이다

							  // 윈도우 생성
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);
	// 메모리에 만들어진 윈도우를 화면에 보이게 하는 함수
	ShowWindow(hWnd, nCmdShow);

	// 메시지 루프
	while (GetMessage(&Message, NULL, 0, 0)) // LPMSG IpMsg 첫번째 인수 // 메시지 큐에서 메시지를 읽어드려 WN_QUIT 일경우 FALSE를 리턴하며 나머지는 TRUE를 리턴한다 // 나머지인수는 잘 안쓴다
	{
		TranslateMessage(&Message); // 키보드 입력 메시지를 가공하여 프로그램에서 쉽게 쓸 수 있도록 한다
		DispatchMessage(&Message); // 메시지 큐에서 꺼낸 메시지를 윈도우의 메시지 처리 함수(WndProc)로 전달한다
	}

	return (int)Message.wParam;
}

void MyText(HDC hdc, int x, int y, LPCTSTR Text)
{
	TextOut(hdc, x, y, Text, lstrlen(Text));
}

#include "GameLoop.h"

GameLoop gameloop;

// 사용자와 시스템이 보내오는 메시지를 처리하는 아주 중요한 일을 한다
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