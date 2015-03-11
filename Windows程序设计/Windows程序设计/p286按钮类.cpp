#include <windows.h>

struct
{
	int		iStyle;
	TCHAR *	szText;
}
button[] =
{
	BS_PUSHBUTTON,			TEXT("PUSHBUTTON"),
	BS_DEFPUSHBUTTON,		TEXT("DEFPUSHBUTTON"),
	BS_CHECKBOX,			TEXT("CHECKBOX"),
	BS_AUTOCHECKBOX,		TEXT("AUTOCHECKBOX"),
	BS_RADIOBUTTON,			TEXT("RADIOBUTTON"),
	BS_3STATE,				TEXT("3STATE"),
	BS_AUTO3STATE,			TEXT("AUTO3STATE"),
	BS_GROUPBOX,			TEXT("GROUPBOX"),
	BS_AUTORADIOBUTTON,		TEXT("AUTORADIOBUTTON"),
	BS_OWNERDRAW,			TEXT("OWNERDRAW")
};

#define NUM (sizeof button / sizeof button[0])

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR	szAppName[] = TEXT("p286��ť��");
	HWND			hwnd;
	MSG				msg;
	WNDCLASS		wndclass;

	wndclass.style				= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc		= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance			= hInstance;
	wndclass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground		= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName		= NULL;
	wndclass.lpszClassName		= szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("windows 7 need!"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND		hwndButton[NUM];
	static RECT		rect;
	static TCHAR	szTop[]		= TEXT("message			wParam			lParam"),
					szUnd[]		= TEXT("_______			______			______"),
					szFormat[]	= TEXT("%-16s%04x-%04x %04x-%04x"),
					szBuffer[50];
	static int		cxChar, cyChar;
	HDC				hdc;
	PAINTSTRUCT		ps;
	int				i;

	switch (message)
	{
	case WM_CREATE:
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

		for (i = 0;i < NUM; i++)
			hwndButton[i] = CreateWindow(TEXT("button"), // ����
			button[i].szText, // �����ı� Ҫ��û����ťһ����ʾ���ı�, ������ͨ����, ���������ʾ��ʾ�ڱ������е��ı�, ����������ʶ��ť��ʽ
			WS_CHILD | WS_VISIBLE/*����ڴ����Ӵ���ʱ�ڴ�������û�а���WS_VISIBLE, �Ӵ��ڽ�������ʾ, ���ǵ���ShowWindow, ���������WS_VISIBLE, ���������ShowWindow, ����, ���Ե���ShowWindow(hwndChild, SW_HIDE)�������������*/ | button[i].iStyle, // ������ʽ  �����Ӵ���: EnableWindow(hwndChild, FALSE), �������ڻ��ɻ�ɫ��
			cxChar, cyChar * (1 + 2 * i), // ��������
			20 * cxChar, 7 * cyChar / 4, // ���ڿ��
			hwnd, // �����ھ��
			(HMENU)i, // �Ӵ���ID ��ID�������ڹ���ȷ��WM_COMMAND��Ϣ�Ǵ��ĸ��Ӵ��ڷ�����;
			((LPCREATESTRUCT)lParam)->hInstance,  // �������  ��WM_CREATE��Ϣ��lParamʵ������һ��ָ��CREATESTRUCT�ṹ��ָ��, hInstance��������ṹ��һ����Ա;
			// ����Ҳ����ʹ��GetWindowLong(hwnd, GWL_HINSTANCE);
			NULL);  // �������
		return 0;

	case WM_SIZE:
		rect.left		= 24 * cxChar;
		rect.top		= 2  * cyChar;
		rect.right		= LOWORD(lParam);
		rect.bottom		= HIWORD(lParam);
		return 0;

	case WM_PAINT:
		InvalidateRect(hwnd, &rect, TRUE);

		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
		SetBkMode(hdc, TRANSPARENT);

		TextOut(hdc, 24 * cxChar, cyChar, szTop, lstrlen(szTop));
		TextOut(hdc, 24 * cxChar, cyChar, szUnd, lstrlen(szUnd));

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DRAWITEM:
	case WM_COMMAND:  // LOWORD(wParam)  �Ӵ���ID    HIWORD(wParam)  ֪ͨ��    lParam  �Ӵ��ھ��
		ScrollWindow(hwnd, 0, -cyChar, &rect, &rect);

		hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));

		TextOut(hdc, 24 * cxChar, cyChar * (rect.bottom / cyChar - 1), 
				szBuffer, 
				wsprintf(szBuffer, szFormat, 
						 message == WM_DRAWITEM ? TEXT("WM_DRAWITEM") : 
												 TEXT("WM_COMMAND"), 
						HIWORD(wParam), LOWORD(wParam),
						HIWORD(lParam), LOWORD(lParam)));

		ReleaseDC(hwnd, hdc);
		ValidateRect(hwnd, &rect);
		break;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}