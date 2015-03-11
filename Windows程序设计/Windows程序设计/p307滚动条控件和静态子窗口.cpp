// 1. �˽�������;�̬�Ӵ��ڵ�ʹ��
// 2. ����̽����ɫԭ��

#include <windows.h>

LRESULT CALLBACK WndProc		(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ScrollProc	(HWND, UINT, WPARAM, LPARAM);

int		idFocus;
WNDPROC	OldScroll[3];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("p307�������ռ�;�̬�Ӵ���");
	HWND hwnd;
	MSG  msg;
	WNDCLASS wndclass;

	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hbrBackground = CreateSolidBrush(0);
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance     = hInstance;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName  = NULL;
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndclass);

	hwnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
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
	static COLORREF		crPrim[3] = {RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255)};
	static HBRUSH		hBrush[3], hBrushStatic;
	static HWND			hwndScroll[3], hwndLabel[3], hwndValue[3], hwndRect;
	static int			color[3], cyChar;
	static RECT			rcColor;
	static TCHAR *		szColorLabel[] = {TEXT("Red"), TEXT("Green"), TEXT("Blue")};
	HINSTANCE			hInstance;
	int					i, cxClient, cyClient;
	TCHAR				szBuffer[10];

	switch (message)
	{
	case WM_CREATE:
		hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);

			// ������ɫ��̬IDΪ9���Ӵ���, �����������ؼ�����������Ӵ����ϱ�;

		hwndRect = CreateWindow(TEXT("static"), NULL, WS_CHILD | WS_VISIBLE | SS_WHITERECT/*��̬����ɫ����*/,
			0, 0, 0, 0,// �Ӵ��ڵ�λ�úʹ�С�Ǹ��ݿͻ���������, �������ʱ��ͻ�����С��λ����δ֪��, ������MoveWindow�������������
			hwnd, (HMENU)9, hInstance, NULL);

			// ���������������ؼ�, ���ù������ؼ�ID, ��������Χ
			// ����������̬�ؼ�, ������ʾ����̬����ɫ, ���þ�̬�ؼ�ID, ���ÿؼ��ı�
			// ����������̬�ؼ�, ������ʾ����������ֵ, ���þ�̬�ؼ�ID, ���ÿؼ���ʼֵ
			// �ı�������ؼ��Ĵ��ڹ���;

		for (i = 0; i < 3; i++)
		{

			// ����������IDλ0 - 2, ��ΧΪ 0 - 255

			hwndScroll[i] = CreateWindow(TEXT("scrollbar"), NULL,
				WS_CHILD | WS_VISIBLE | WS_TABSTOP | SBS_VERT, // SBS_VERT��ͬ��SB_VERT, ����ǹ������ؼ������Ǵ��ڹ�����
				0, 0, 0, 0,
				hwnd, (HMENU)i, hInstance, NULL);

			SetScrollRange(hwndScroll[i], SB_CTL, 0, 255, FALSE);
			SetScrollPos(hwndScroll[i], SB_CTL, 0, FALSE);

				// ������������ɫ��ǩ��̬�ؼ�IDΪ 3, 4, 5, �ı�Ϊ "Red", "Green", "Blue";

			hwndLabel[i] = CreateWindow(TEXT("static"), szColorLabel[i], 
				WS_CHILD | WS_VISIBLE | SS_CENTER,  // SS_CENTER �������ж�����ı�
				0, 0, 0, 0,
				hwnd, (HMENU)(i + 3), hInstance, NULL);

				// ������������ֵ��С��̬�ؼ�IDΪ6, 7, 8, ��ʼ��ֵΪ"0"

			hwndValue[i] = CreateWindow(TEXT("static"), TEXT("0"),
				WS_CHILD | WS_VISIBLE | SS_CENTER,
				0, 0, 0, 0,
				hwnd, (HMENU)(i + 6), hInstance, NULL);

				// �����µĹ��������ڹ��̵ĵ�ַ, ͬʱ������й��������ڹ��̵ĵ�ַ;

			OldScroll[i] = (WNDPROC)SetWindowLong(hwndScroll[i], GWL_WNDPROC, (LONG)ScrollProc);  
					// �������ؼ��Ĵ��ڹ�����windows�ڲ�, ����ͨ������GetWindowLong����ȡ������ڹ��̵ĵ�ַ
					// ������ͨ������SetWindowLongΪ����������һ���µĴ��ڹ���, ���ּ�����Ϊ"��������"
					// �µĴ��ڹ���ͨ��CallWindowProc�����þ͵ù��������ڹ���;

				// ��ˢ���óɹ���������ԭɫ���ƶ�Ӧ����ɫ
			
			hBrush[i] = CreateSolidBrush(crPrim[i]);
		}

		hBrushStatic = CreateSolidBrush(GetSysColor(COLOR_BTNHIGHLIGHT));

		cyChar = HIWORD(GetDialogBaseUnits());
		return 0;

		// �������пؼ���λ��

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		SetRect(&rcColor, cxClient / 2, 0, cxClient, cyClient);  // �����ͻ������Ұ벿��

			// ����̬�Ӵ��ڿؼ�����Ϊ�����ͻ�������벿��

		MoveWindow(hwndRect, 0, 0, cxClient / 2, cyClient, TRUE);

			// ���������Ÿ��ؼ���λ��

		for (i = 0; i < 3; i++)
		{
			MoveWindow(hwndScroll[i], (2 * i + 1) * cxClient / 14, 2 * cyChar, cxClient / 14, cyClient - 4 * cyChar, TRUE);
			MoveWindow(hwndLabel[i] , (4 * i + 1) * cxClient / 28, cyChar / 2, cxClient / 7 , cyChar, TRUE);
			MoveWindow(hwndValue[i] , (4 * i + 1) * cxClient / 28, cyClient - 3 * cyChar / 2, cxClient / 7, cyChar, TRUE);
		}

			// ����WM_SETFOCUS��Ϣ

		SetFocus(hwnd);
		return 0;

	case WM_SETFOCUS:
		SetFocus(hwndScroll[idFocus]);
		return 0;

		// ����������������ɫ���߼�, ����λ���߼�, ��ɫ��ֵ����

	case WM_VSCROLL:
		i = GetWindowLong((HWND)lParam, GWL_ID);

		switch (LOWORD(wParam))
		{
		case SB_PAGEDOWN:
			color[i] += 15;
								// fall through

		case SB_LINEDOWN:
			color[i] = min(255, color[i] + 1);
			break;

		case SB_PAGEUP:
			color[i] -= 15;
							// fall through

		case SB_LINEUP:
			color[i] = max(0, color[i] - 1);
			break;

		case SB_TOP:
			color[i] = 0;
			break;

		case SB_BOTTOM:
			color[i] = 255;
			break;

		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
			color[i] = HIWORD(wParam);
			break;
		}

			// ���û���λ��

		SetScrollPos(hwndScroll[i], SB_CTL, color[i], TRUE);

			// ������ɫ��ֵ�Ĵ�С

		wsprintf(szBuffer, TEXT("%i"), color[i]);
		SetWindowText(hwndValue[i], szBuffer);

			// �����������ڿؼ�ԭ���Ļ�ˢɾ��, ���ӽ�ȥ�µĹ�����������ɫ�Ļ�ˢ

		DeleteObject((HBRUSH)
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (LONG) // SetClassLong: ����SetWindowLong�������ô��ڹ���һ��, SetClassLong�������ô�����ṹ
				CreateSolidBrush(RGB(color[0], color[1], color[2]))));

			// ʹ�������ͻ����Ұ벿����Ч

		InvalidateRect(hwnd, &rcColor, TRUE);
		return 0;

		// �������ؼ���ɫ������

	case WM_CTLCOLORSCROLLBAR:
		i = GetWindowLong((HWND)lParam, GWL_ID);
		return (LRESULT)hBrush[i];  // ͨ���������Ϣ�·���һ����ˢ���޸�ԭ������ɫ;

		// ��̬�ؼ��ı���ɫ������

	case WM_CTLCOLORSTATIC:
		i = GetWindowLong((HWND)lParam, GWL_ID);

		if (i >= 3 && i <= 8)  // ����Ǿ�̬�ı��ؼ��Ļ�
		{
			SetTextColor((HDC)wParam, crPrim[i % 3]);  // �����ı���ɫ
			SetBkColor((HDC)wParam, GetSysColor(COLOR_BTNHIGHLIGHT));  // �����ı��ı�����ɫ ! �������õ����ı��ı���������������̬�ؼ��ı���, ������ͨ�����ڹ��̷���COLOR_BTNHIGHLIGHT��ɫ�Ļ�ˢ���ʵ�ֵ�;
			return (LRESULT)hBrushStatic;
		}
		break;

	case WM_SYSCOLORCHANGE:  // ��ֹCOLOR_BTNHIGHLIGHT��ɫ�ڳ������й����б��ı��������Ӱ��;
		DeleteObject(hBrushStatic);
		hBrushStatic = CreateSolidBrush(GetSysColor(COLOR_BTNHIGHLIGHT));
		return 0;

	case WM_DESTROY:
		DeleteObject((HBRUSH)
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (LONG)
			GetStockObject(WHITE_BRUSH)));

		for (i = 0; i < 3; i++)
			DeleteObject(hBrush[i]);

		DeleteObject(hBrushStatic);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK ScrollProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int id = GetWindowLong(hwnd, GWL_ID);

	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_TAB)
			SetFocus(GetDlgItem(GetParent(hwnd), (id + (GetKeyState(VK_SHIFT) < 0 ? 2 : 1)) % 3));
		break;
	
	case WM_SETFOCUS:
		idFocus = id;
		break;
	}
	return CallWindowProc(OldScroll[id], hwnd, message, wParam, lParam);
}