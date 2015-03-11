#include <windows.h>
#define	DIVSIONS	5

LRESULT CALLBACK WndProc		(HWND, UINT, WPARAM, LPARAM);  // �����ڴ��ڹ���
LRESULT CALLBACK ChildWndProc	(HWND, UINT, WPARAM, LPARAM);  // 25���Ӵ��ڴ��ڹ���

TCHAR	szChildClass[] = TEXT("p240����������Ӵ���_�Ӵ�����");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR	szAppName[] = TEXT("p240����������Ӵ���");
	HWND			hwnd;
	MSG				msg;
	WNDCLASS		wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows 7 !"), szAppName, MB_ICONERROR);
		return 0;
	}

	wndclass.lpfnWndProc	= ChildWndProc;
	wndclass.cbWndExtra		= sizeof(long);  // ֪ͨWindows���ڲ��ṹ�и���������������ÿ������Ԥ��sizeof(long)���ֽڵĶ���ռ�  ͨ��SetWindowWord�������������������ռ�
											 // �û�����������Щ�ռ�Ϊÿ�����ڱ��治ͬ����Ϣ;
	wndclass.hIcon			= NULL;  // ����Ҫͼ��
	wndclass.lpszClassName	= szChildClass;  // �Ӵ�������

	RegisterClass(&wndclass);

	hwnd = CreateWindow(szAppName, szAppName,
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						NULL/*�����ھ��*/, NULL/*�˵����*/, hInstance/*ʵ�����*/, NULL/*�������*/);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND	hWndChild[DIVSIONS][DIVSIONS];
	int			cxBlock, cyBlock, x, y;

	switch (message)
	{
	case WM_CREATE:
		for (x = 0; x < DIVSIONS; x++)
			for (y = 0; y < DIVSIONS; y++)
				hWndChild[x][y] = CreateWindow(szChildClass, NULL, 
												WS_CHILDWINDOW | WS_VISIBLE,
												0, 0, 0, 0, // ����λ�úʹ�С�ں����WndProc�����ж���, ��MoveWindow�������õ�ʱ����е�����
												hwnd/*�����ھ��*/, (HMENU)(y << 8 | x)/*������������˵����ǲ˵����, �����Ӵ�����˵, �ò�����Ϊ"��ID"��"�Ӵ���ID", ����һ������Ψһ��ʶ�Ӵ��ڵ���ֵ*/,
																// ����򵥵Ľ��Ӵ���ID���ó���x��y�����
																// ��Ӧ��, ��ȡ�Ӵ���ID�ĺ����� 1. idChild = GetWindowLong(hwndChild, GWL_ID);  2, idChild = GetDlgCtrlId(hwndChild);
												(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE)/*ʵ�����, ��WinMain��, �����׻�ȡ������, ��Ϊ����WinMain�е�һ������*/,
														// �����ȡ��hInstance�������ô������б����ȥ��
												// �������Ӵ���ʱ, ����������GetWindowLong��Windows�����ڱ����Ľṹ����ȡhInstance��ֵ;
												NULL/*�������*/);
		return 0;

	case WM_SIZE:
		cxBlock = LOWORD(lParam) / DIVSIONS;
		cyBlock = HIWORD(lParam) / DIVSIONS;

		for (x = 0; x < DIVSIONS; x++)
			for (y = 0; y < DIVSIONS; y++)
				// MoveWindow�����Ĳ��������Ӵ������Ͻ�����ڸ����ڿͻ���������, �Ӵ��ڵĿ�Ⱥ͸߶��Լ��Ƿ���Ҫ�ػ��Ӵ��ڵı�־
				MoveWindow(hWndChild[x][y],  // ������Ϊÿ���Ӵ��ڱ�����һ����ͬ�Ĵ��ھ��; 
					x * cxBlock, y * cyBlock,  // �Ӵ������Ͻ�����ڸ����ڿͻ���������
					cxBlock, cyBlock,  // �Ӵ��ڵĿ�Ⱥ͸߶�
					TRUE);  // �Ƿ���Ҫ�ػ��Ӵ��ڵı�־
		return 0;

	case WM_LBUTTONDOWN:
		MessageBeep(0);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

// ������ڹ���Ϊ���е�25���Ӵ��ڴ�����Ϣ
LRESULT CALLBACK ChildWndProc(HWND hwnd,  // ������Ϣ���Ӵ��ھ��
							  UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	switch (message)
	{
	case WM_CREATE:  // һ������25��, ��Ϊ����25���Ӵ���
		SetWindowLong(hwnd, 0, 0);  // on/off flag  �����ڴ��ڽṹԤ���Ķ���ռ��б���һ��0
				// ChildWndProc�������ֵ������εĵ�ǰ״̬(x�λ�û��x��)
		return 0;

	case WM_LBUTTONDOWN:
		SetWindowLong(hwnd, 0, 1 ^ GetWindowLong(hwnd, 0));
		InvalidateRect(hwnd, NULL, FALSE);  // �����������εĴ�С��ͻ����Ĵ�Сһ��, ��������WM_PAINT�Ĵ���ͼ򵥵Ķ���;
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);  // �����hwnd��һ���Ӵ���, ����Clientָ�����Ӵ��ڿͻ���, rect��������Ӵ��ڿͻ���
		Rectangle(hdc, 0, 0, rect.right, rect.bottom);

		if (GetWindowLong(hwnd, 0))
		{
			MoveToEx(hdc, 0, 0, NULL);
			LineTo(hdc, rect.right, rect.bottom);
			MoveToEx(hdc, 0, rect.bottom, NULL);
			LineTo(hdc, rect.right, 0);
		}

		EndPaint(hwnd, &ps);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}