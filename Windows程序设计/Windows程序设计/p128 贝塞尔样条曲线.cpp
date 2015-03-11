#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("p128 ��������������");
	HWND         hwnd;
	MSG			 msg;
	WNDCLASS     wndclass;

	wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.cbClsExtra     = 0;
	wndclass.cbWndExtra     = 0;
	wndclass.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance      = hInstance;
	wndclass.lpfnWndProc    = WndProc;
	wndclass.lpszClassName  = szAppName;
	wndclass.lpszMenuName   = NULL;
	wndclass.style          = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Windows 7 is needed!"),
					TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("Bezier Splines"),
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

void DrawBezier(HDC hdc, POINT apt[])
{
	PolyBezier(hdc, apt, 4);

	MoveToEx(hdc, apt[0].x,apt[0].y, NULL);
	LineTo(hdc, apt[1].x, apt[1].y);

	MoveToEx(hdc, apt[2].x, apt[2].y, NULL);
	LineTo(hdc, apt[3].x, apt[3].y);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static POINT apt[4];
	HDC          hdc;
	int          cxClient, cyClient;
	PAINTSTRUCT  ps;

	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		apt[0].x  = cxClient / 4;  // ���
		apt[0].y  = cyClient / 2;

		apt[1].x = cxClient / 2;  // ��һ���ص����ʼλ��
		apt[1].y = cyClient / 4;

		apt[2].x = cxClient / 2;  // �ڶ����ص����ʼλ��
		apt[2].y = 3 * cyClient / 4;

		apt[3].x = 3 * cxClient / 4;
		apt[3].y = cyClient / 2;  // �յ�

		return 0;

	// ���������Ϣ, wParam����궯��, lParam�����λ��;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MOUSEMOVE:  // ����Ϣȷ�� �϶��ص� ��ʵ��
		if (wParam & MK_LBUTTON || wParam & MK_RBUTTON)
		{
			hdc = GetDC(hwnd);

			// ȷ���켣���ᱻ����(��������ԭ��λ��)
			SelectObject(hdc, GetStockObject(WHITE_PEN));  // GetStockObject(WHITE_PEN) ���ػ��ʵľ�� SelectObject(hdc, hPen) ������ѡ���豸���� ��������ǰѡ���豸�����Ļ��ʵľ��
			DrawBezier(hdc, apt);  // ��������ԭ�����������»�����һ��, ֻ������һ���õ��ǰ���, ���Ժ��������ԭ�������Ƶ�;

			if (wParam & MK_LBUTTON)
			{
				apt[1].x = LOWORD(lParam);  // �����λ�ñ�������
				apt[1].y = HIWORD(lParam);
			}

			if (wParam & MK_RBUTTON)
			{
				apt[2].x = LOWORD(lParam);
				apt[2].y = HIWORD(lParam);
			}

			// ���߻�����λ��
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			DrawBezier(hdc, apt);

			ReleaseDC(hwnd, hdc);
		}
		return 0;

	case WM_PAINT:
		InvalidateRect(hwnd, NULL, TRUE);  // ���ָ���Ǹ�ʲô�õİ�????
		hdc = BeginPaint(hwnd, &ps);
		
		DrawBezier(hdc, apt);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}