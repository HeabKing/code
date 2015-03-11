#include <windows.h>
#include "p075TextOut��ʽ����������.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("SysMets1");
	HWND hwnd;
	MSG  msg;
	WNDCLASS wndclass;

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("Get System Metrics No.1"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
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
	static int cxChar, cxCaps, cyChar;  // c: count �������������
	HDC hdc;
	int i;
	PAINTSTRUCT ps;  // ps.hdc ����BeginPaint�������ص�hdc, ps.fErase ʹ��Ч������Ч��ʱ���Ƿ�����˱���, �� FALSE, �� TRUE(����Invalidate�������һ������FALSEָ�����ܲ�������, ��ô������Ƿ�TRUE); 
	// ps.rcPaint ʹ�õ����߼���������, ������һ���ü�����, ����ζ��windows���ѻ���������������������Ч������;
	TCHAR szBuffer[10];
	TEXTMETRIC tm;

	switch (message)
	{ 
		// windows�������е�ʱ��, ϵͳ���岻��仯, ���, Ӧ�ó���ֻ��Ҫ����һ��GetTextMetrics����, ��õ�ʱ������WM_CREATE���д��ڳ�ʼ����ʱ��;
	case WM_CREATE:  // ����CreatWindow()��ʱ����յ���һ����Ϣ(WM_CREATE)
		hdc = GetDC(hwnd);  // ��ȡ���ڵ��豸�������, �����ȡ�ľ����BeginPaint�������صĲ�ͬ, ����豸��������еĲü������������ͻ���(����û����Ч����Ҳ�ܻ���), GetDCҲ����ʹ��Ч������Ч��(validateRect(hwnd, NULL));
		
		GetTextMetrics(hdc, &tm);  // ��ȡĬ��ϵͳ����ĳߴ� ����Ҫһ���豸�������, ��Ϊ����Ҫ֪���豸�����ṹ�е�������Ϣ, Ȼ�󽫸���Ϣ���Ƶ�TEXTMETRICS��;
		cxChar = tm.tmAveCharWidth;  // ƽ���ַ����
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;  // ��д�ַ���ƽ�����(�ڱ��������, cxCaps��ΪcxChar��1.5��) tmPitchAndFamily�ֶεĵ�λ���������Ƿ�Ϊ�ȿ�����: 1����������, 0����ȿ�����
		cyChar = tm.tmHeight + tm.tmExternalLeading;  // �ַ����ܸ߶�(�����ⲿ���)
	
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		for (i = 0; i < NUMLINES; i++)
		{
			// TextOut�����򴰿ڵĿͻ������һ���ַ���.
			// TextOut(hdc,  // �豸������� �������ı����ԺͲü������ // �������е�GDI��������Ҫ��������Ϊ�����ĵ�һ������
			//     x, y,  // �ַ����ڿͻ����Ŀ�ʼλ�� �õ����߼���������` Ĭ�ϵ��豸���������, ����ԭ���ڿͻ��������Ͻ�
			//     psText,  // ָ���ַ�����ָ��
			//     iLength  // �ַ����ĳ���(���ַ�Ϊ��λ));
			// TextOut()������Ϊ�ַ���β��Ϊ0�ֽڱ�ʾ�ַ�������, ������iLength�����������ַ����ĳ���.
			TextOut(ps.hdc/*��ʵ��ͼ�ṹ�е�һ�����Ծ���DC���*/, 0, cyChar * i, sysmetrics[i].szLabel, lstrlen(sysmetrics[i].szLabel));
			TextOut(hdc, 22 * cxCaps, cyChar * i, sysmetrics[i].szDesc, lstrlen(sysmetrics[i].szDesc));

			// ֪ͨwindows��̵�TextOut��������ʹ�õ�����ӿͻ��������Ͻǿ�ʼ���������Ͻ�
			SetTextAlign(hdc, TA_RIGHT | TA_TOP);  // ָ����ʾ�Ľ���λ�ö����ǿ�ʼλ��

			TextOut(hdc, 22 * cxCaps + 40 * cxChar, cyChar * i, szBuffer, wsprintf(szBuffer, TEXT("%5d"), GetSystemMetrics(sysmetrics[i].Index)));
			
			// �����뷽ʽ����Ϊ����
			SetTextAlign(hdc, TA_LEFT | TA_TOP);
		}
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}