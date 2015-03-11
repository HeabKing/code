#include <windows.h>
#define  ID_TIMER	1

void FindWindowSize(int *, int *);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR	szAppName[] = TEXT("p281��״̬������ʹ�ü�ʱ��");
	HWND			hwnd;
	int				cxWindow, cyWindow;
	MSG				msg;
	WNDCLASS		wndclass;

	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
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
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	FindWindowSize(&cxWindow, &cyWindow);

	hwnd = CreateWindow(szAppName, szAppName, 
						WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_BORDER/*�̶���С�Ĵ���*/,
						CW_USEDEFAULT, CW_USEDEFAULT, cxWindow, cyWindow,
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

void FindWindowSize(int * pcxWindow, int * pcyWindow)
{
	HDC			hdcScreen;
	TEXTMETRIC	tm;

	hdcScreen = CreateIC(TEXT("DISPLAY"), NULL, NULL, NULL);  // ����Ƶ��ʾ�豸��ȡһ����Ϣ�豸����
	GetTextMetrics(hdcScreen, &tm);  // ��ȡ�ı��Ĵ�С
	DeleteDC(hdcScreen);

	*pcxWindow = 2 * GetSystemMetrics(SM_CXBORDER)/*��ȡ���ұ߿�Ŀ�ȵ�������*/ + 12 * tm.tmAveCharWidth;
	*pcyWindow = 2 * GetSystemMetrics(SM_CYBORDER)/*��ȡ���±߿�ĺ�ȵ�������*/ + GetSystemMetrics(SM_CYCAPTION)/*��ȡ���������*/ + 2 * tm.tmHeight;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static COLORREF		cr, crLast;
	static HDC			hdcScreen;
	HDC					hdc;
	PAINTSTRUCT			ps;
	POINT				pt;
	RECT				rc;
	TCHAR				szBuffer[16];

	switch (message)
	{
	case WM_CREATE:
		hdcScreen = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);  // Ϊ������Ƶ��ʾ����һ���豸����
		
		SetTimer(hwnd, ID_TIMER, 100, NULL);
		return 0;

	case WM_TIMER:
		GetCursorPos(&pt);  // ��ȡ��굱ǰλ��
		cr = GetPixel(hdcScreen, pt.x, pt.y);  // ��õ�ǰ���λ�õ�������ɫ
		//TextOut(hdcScreen, 100, 100, TEXT("daxionggege"), lstrlen(TEXT("daxionggege")));

		//SetPixel(hdcScreen, pt.x, pt.y, 0);  // ��һ����  ��˵������, �ոյõ���������ɫ, ���������Ϳ��, ���

		if (cr != crLast)
		{
			crLast = cr;
			InvalidateRect(hwnd, NULL, FALSE);  // ������Ȼд����FALSE, �������ڻ�ͼģʽ�ǲ�͸����, �����ı��еİ�ɫ���ԭ�����ָ����ǵ�
		}

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rc);

		wsprintf(szBuffer, TEXT("  %02X %02X %02X   "), GetRValue(cr), GetGValue(cr), GetBValue(cr));
		DrawText(hdc, szBuffer, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		DeleteDC(hdcScreen);
		KillTimer(hwnd, ID_TIMER);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}