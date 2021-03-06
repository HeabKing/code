#include <windows.h>
#include <process.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND hwnd;
int cxClient, cyClient;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("RndRctMT");
	MSG					msg;
	WNDCLASS			wndclass;

	wndclass.cbClsExtra			= 0;
	wndclass.cbWndExtra			= 0;
	wndclass.hbrBackground		= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance			= hInstance;
	wndclass.lpfnWndProc		= WndProc;
	wndclass.lpszClassName		= szAppName;
	wndclass.lpszMenuName		= NULL;
	wndclass.style				= CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("Random Rectangles"), 
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT, 
						CW_USEDEFAULT, CW_USEDEFAULT,
						NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

VOID Thread(PVOID pvoid)
{
	HBRUSH	hBrush;
	HDC		hdc;
	int		xLeft, xRight, yTop, yBottom, iRed, iGreen, iBlue;

	while (1)
	{
		if (cxClient != 0 || cyClient != 0)
		{
			xLeft	= rand() % cxClient;
			xRight	= rand() % cxClient;
			yTop	= rand() % cyClient;
			yBottom	= rand() % cyClient;
			iRed	= rand() & 255;
			iGreen	= rand() & 255;
			iBlue	= rand() & 255;

			hdc		= GetDC(hwnd);
			hBrush	= CreateSolidBrush(RGB(iRed, iGreen, iBlue));
			SelectObject(hdc, hBrush);
			Rectangle(hdc, min(xLeft, xRight), min(yTop, yBottom), max(xLeft, xRight), max(yTop, yBottom));
			ReleaseDC(hwnd, hdc);
			DeleteObject(hBrush);
		}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		_beginthread(Thread, 0, NULL);
		return 0;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}