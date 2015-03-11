#include <windows.h>
#include <math.h>

// ����ѡ��
#define �����Ҳ�
//#define ������
//#define ��һ������1
//#define ��һ������2

#define NUM 1000
#define TWOPI (2 * 3.14159)

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("p120�������Ҳ�");
	HWND hwnd;
	MSG  msg;
	WNDCLASS wndclass;

	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
	static int  cxClient,cyClient;
	int         i;
	HDC         hdc;
	PAINTSTRUCT ps;
	POINT       apt[NUM];
	POINT arpt[5] = {100, 100, 200, 100, 200, 200, 100, 200, 100, 100};

	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	// �����Ҳ�
	// ͨ�����Ƽ��������̵�����������һ�����ӵ����Ҳ�, ��������㹻��, �㹻��, ��ô������������һ������������һ������.
#ifdef �����Ҳ�
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		MoveToEx(hdc, 0, cyClient / 2, NULL);  // �趨��ǰλ��, NULL������ʾ������֮ǰ�ĵ�ǰλ��
		// ϵͳĬ�ϵ���BLACK_PEN����
		LineTo(hdc, cxClient, cyClient / 2);   // �ӵ�ǰλ��(������)��ֱ���ƶ���һ��λ��(����)

		for (i = 0; i < NUM; i++)
		{
			apt[i].x = i * cxClient / NUM;  // i * (cxClient / NUM); Ϊ�˱�֤����Ӧ���ȳ˺��
			apt[i].y =(int)((1 - sin((double)i/*������ﲻ����double�Ļ�i/num��С����������ת�������εĻ�����0��*/ / NUM * TWOPI)) * cyClient / 2);
			//apt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI * i / NUM))); 
		}

		Polyline(hdc, apt, NUM);

		EndPaint(hwnd, &ps);
		return 0;
#endif

	// ������
#ifdef ������
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (i = 0; i < cxClient; i += 100)
		{
			MoveToEx(hdc, i, 0, NULL);
			LineTo(hdc, i, cyClient);
		}
		for (i = 0; i < cyClient; i += 100)
		{
			MoveToEx(hdc, 0, i, NULL);
			LineTo(hdc, cxClient, i);  // �ӵ�ǰλ��(��������ǰλ��)ָ��λ��(����ָ��λ��)
		}
		EndPaint(hwnd, &ps);
		return 0;
#endif

	// ��һ������1
#ifdef ��һ������1
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		MoveToEx(hdc, arpt[0].x, arpt[0].y, NULL);
		for (i = 1; i < 5; i++)
			LineTo(hdc, arpt[i].x, arpt[i].y);

		EndPaint(hwnd, &ps);
		return 0;
#endif

	// ��һ������2
#ifdef ��һ������2
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		Polyline(hdc, arpt, 5);  // Polyline()��������ʹ�ú͸ı䵱ǰλ��. ��PolylineTo()��ʹ�ú͸ı䵱ǰλ��, �����ߺ�, �Ὣ��ǰλ������Ϊ���һ���ߵ��յ�.

		EndPaint(hwnd, &ps);
		return 0;
#endif

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}