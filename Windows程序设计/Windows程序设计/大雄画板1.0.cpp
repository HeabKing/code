#include <windows.h>

TCHAR			szBuffer[100];
int				iFocusToolBox, iPrevToolBox = 1000;
int				cLine = 1;


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
// ��һ�����߿�
void DrawToolBox(HDC hdc, RECT * reToolBox, TCHAR * szTemp = TEXT("No Tag"));
// �ж��Ƿ��˹���
bool isChangeToolBox(RECT *, POINT);

int WINAPI WinMain(HINSTANCE hInstance, 
				   HINSTANCE hPrevInstance, 
				   PSTR szCmdLine, int iCmdShow)
{
	TCHAR		szAppName[] = TEXT("���ۻ���1.0");
	WNDCLASS	wndclass;
	HWND		hwnd;
	MSG			message;

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

	RegisterClass(&wndclass);

	hwnd = CreateWindow(szAppName, szAppName, 
						WS_OVERLAPPEDWINDOW, 
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT		ps;
	HDC				hdc;
	RECT			reToolBox[3] = {0, 0, 70, 50, 100, 0, 170, 50, 200, 0, 270, 50};
	RECT			reTemp;

	switch (message)
	{
	case WM_CREATE:
		
		return 0;

	case WM_LBUTTONDOWN:
		// ��ֹ�����ʱ����豸ԭ�������һ���ߵ�ĩβ��ʼ������
		static POINT ptMouse;
		ptMouse.x = LOWORD(lParam);
		ptMouse.y = HIWORD(lParam);
		// �������ĳ������, ���Ӧ�Ĺ��߿��ɫ
		if (isChangeToolBox(reToolBox, ptMouse))
		{
			hdc = GetDC(hwnd);
			InflateRect(&reToolBox[iFocusToolBox], 1, 1);  // ǰһ����������, ��һ����������, ������ʾ����, ������ʾ��С;
			InvertRect(hdc, &reToolBox[iFocusToolBox]);
			InvertRect(hdc, &reToolBox[iPrevToolBox]);
			iPrevToolBox = iFocusToolBox;
			ReleaseDC(hwnd, hdc);
		}
	case WM_MOUSEMOVE:
		if (wParam & MK_LBUTTON)
		{
			HPEN hpen, hPrevPen;
			hdc = GetDC(hwnd);
			
			if (HIWORD(lParam) <= 50 && LOWORD(lParam) <= 270)  // ��ֹ��Box����������;
				return 0;
			if (cLine > 0)
			{
				hpen = CreatePen(PS_SOLID, cLine, 0x000000);
				hPrevPen = (HPEN)GetCurrentObject(hdc, OBJ_PEN);
				SelectObject(hdc, hpen);
				MoveToEx(hdc, ptMouse.x, ptMouse.y, NULL);
				ptMouse.x = LOWORD(lParam);
				ptMouse.y = HIWORD(lParam);
				LineTo(hdc, ptMouse.x, ptMouse.y);
				SetPixel(hdc, ptMouse.x, ptMouse.y, 0);  // Ϊʲô��Ҫ�����������ʵ��������ʾ����?
				DeleteObject(SelectObject(hdc, hPrevPen));
			}
			else
			{
				ptMouse.x = LOWORD(lParam);
				ptMouse.y = HIWORD(lParam);
				SetRect(&reTemp, ptMouse.x - 7, ptMouse.y - 7, ptMouse.x + 7, ptMouse.y + 7);
				InvalidateRect(hwnd, &reTemp, TRUE);
				UpdateWindow(hwnd);
			}

			ReleaseDC(hwnd, hdc);
		}
		return 0;
	
	case WM_SIZE:
		iPrevToolBox = 1000;  // ��ֹ�ڸı䴰�ڴ�С��ʱ������iPrevToolBox = 0���������Box��ͬ��ɫ;
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		DrawToolBox(hdc, reToolBox, TEXT("����"));
		DrawToolBox(hdc, &reToolBox[1], TEXT("��ˢ"));
		DrawToolBox(hdc, &reToolBox[2], TEXT("��Ƥ"));

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void DrawToolBox(HDC hdc, RECT * reToolBox, TCHAR * szTemp) 
{
	//HBRUSH	hBrush		 = CreateSolidBrush(0XFFFFf);  // ������ɫ��ˢ
	//HBRUSH  hPrevBrush	 = (HBRUSH)GetCurrentObject(hdc, OBJ_BRUSH);  // ��ȡ��ǰ��ˢ
	//SelectObject(hdc, hBrush);
	Rectangle(hdc, reToolBox->left, reToolBox->top, reToolBox->right, reToolBox->bottom);
	//DeleteObject(SelectObject(hdc, hPrevBrush));
	int hdcTemp = SaveDC(hdc);  // �����豸����
	SetBkMode(hdc, TRANSPARENT);  // ������ģʽ���ó�͸����;  // ��������ı��Ļ�������;
	//SetROP2(hdc, R2_WHITE);  // ����ͼģʽ���ó��ڱ�����ɫ�෴�����ܻ�����ɫ  // ��������ı��Ļ�����û���õ�;
	TextOut(hdc, reToolBox->left + 20, reToolBox->top + 18, szTemp, lstrlen(szTemp));
	RestoreDC(hdc, hdcTemp);  // �ָ��豸����
}

bool isChangeToolBox(RECT * re, POINT pt)
{
	if (PtInRect(&re[0], pt))
	{
		cLine = 1;
		iFocusToolBox = 0;
	}
	else if (PtInRect(&re[1], pt))
	{
		iFocusToolBox = 1;
		cLine = 15;
	}
	else if (PtInRect(&re[2], pt))
	{
		iFocusToolBox = 2;
		cLine = -1;
	}

	return true;
}