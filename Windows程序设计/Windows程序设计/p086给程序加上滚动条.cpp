#include <windows.h>
#include "p075TextOut��ʽ����������.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("�����˹������ĳ���");
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

	RegisterClass(&wndclass);
													//  �����������Ǵ��ڷ���ʾ��
	hwnd = CreateWindow(szAppName, TEXT("���˹�����"), WS_OVERLAPPEDWINDOW | WS_VSCROLL/*���������õĹ�����*/, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
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
	static int cxChar, cxCaps, cyChar, cyClient, iVscrollPos/*������ʾ����ĵ�ǰλ��*/;
	HDC         hdc;
	int         i, y;
	PAINTSTRUCT ps;
	TCHAR       szBuffer[10];
	TEXTMETRIC  tm;

	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);

		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
		cyChar = tm.tmHeight + tm.tmExternalLeading;

		ReleaseDC(hwnd, hdc);

		// �趨�������ķ�Χ
		SetScrollRange(hwnd, SB_VERT, 0, NUMLINES - 1/*��NUMLINES������, ���Թ������ķ�ΧΪ0~NUMLINES-1*/,  // �����������λ����0, ���һ��������ʾ�ڿͻ���, ���������ֵ�������л���ʾ�ڶ���. �����NUMLINES-1, �����һ����ʾ�ڶ���
			FALSE);  // �����Ҫwindows���ݷ�Χ���ػ������, ����ΪTRUE. ����������SetScrollRange()֮�󻹽�����������������������������ʾ, ����ý��������ó�false�Ա�������ػ�  
		SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);  // �趨��������λ��
		return 0;
	
	// �����ڴ�С�����仯��ʱ��, windows���򴰿ڹ��̷���һ��WM_SIZE��Ϣ.
	// lParam�����ĵ�λ���ǿͻ����Ŀ��, ��λ���Ǹ߶�.
	case WM_SIZE:
		cyClient = HIWORD(lParam);  // ����ȡ����lParam�ĸ���λ, ���ͻ����ĸ߶�
		// ����ͨ����GetClientRect()����ȡ�ͻ����Ĵ�С, �������ÿ����Ҫʱ��Ҫ�������������Ȼû��Ч��, ����û�в�ȡ���ִ�ʩ
		return 0;

	case WM_VSCROLL:
		// ���������Ǵ��ڵ�һ���ֵ�ʱ��, ���Ժ���lParam����, ��ֻ���ڹ��������Ӵ���ʱ, ͨ�����ڶԻ�����
		// wParam�ĵ�λ�ִ�������ڹ������ϵĶ���, ���ֵ��Ϊ"֪ͨ��".
		// ��֪ͨ��ΪSB_THUMBTRACK��ʱ��Ϊ�����Ż����϶�, ��ʱwParam�ĸ�λ��Ϊ�û��϶�����ĵ�ǰλ��
		// ��֪ͨ��ΪSB_THUMBPOSTION��ʱ��, wParam���û��ɿ���������λ��
		// ���������Ĺ���������, wParam�ĸ�λӦ�ñ�����
		switch (LOWORD(wParam))
		{
		case SB_LINEUP:
			iVscrollPos -= 1;
			break;
		case SB_LINEDOWN:
			iVscrollPos += 1;
			break;
		case SB_PAGEUP:
			iVscrollPos -= cyClient / cyChar;
			break;
		case SB_PAGEDOWN:
			iVscrollPos += cyClient / cyChar;
			break;

		////////////////////////////////////////////////////////////
		// ���������Լ����ϵ�, ��ʵ��������϶�����Ļ�ƶ���ͬ��
		case SB_THUMBTRACK:
			iVscrollPos = HIWORD(wParam);
			break;
		////////////////////////////////////////////////////////////
			
		case SB_THUMBPOSITION:
			iVscrollPos = HIWORD(wParam);
			break;
		default:
			break;
		}
		iVscrollPos = max(0, min(iVscrollPos, NUMLINES - 1));  // ȷ��iVscrollPos�ڷ�Χ��

		if (iVscrollPos != GetScrollPos(hwnd, SB_VERT))  // �����ǰλ��iVscrollPos����ǰλ��GetScrollPos()�����
		{
			SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);  // ���µ�ǰλ��
			InvalidateRect(hwnd, NULL, TRUE);  // ʹ����������Ч �˺���������WM_PAINT��Ϣ
			// Invalidate()���ص�WM_PAINT��Ϣ���ŵ�����Ϣ������, windows��WM_PAINT���������ȼ�����Ϣ����, ��ʱ���ܳ��ֵ����: ����رմ��ں���Ļ��ɰ׵�, �����ڵȴ�����.
			// �����Ҫ����������Ч����, ������ڵ���InvalidateRect()����������UpdateWindow(), ����ͻ������κ�һ��������Ч��, UpdateWindow()�����Ǵ��ڹ��������յ�һ��WM_PAINT��Ϣ. (��������ͻ�������Ч��, UpdateWindow��������ô��ڹ���.)��ʱ, WM_PAINT��Ϣ����Խ����Ϣ����, ֱ����Windows���ô��ڹ���, �����ڹ�����ɻ��ƺ�, UpdateWIndow����������Ȩ���ظ��������Ĵ���.
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		for (i = 0; i < NUMLINES; i++)
		{
			y = cyChar * (i - iVscrollPos);
			TextOut(hdc, 0, y, sysmetrics[i].szLabel, lstrlen(sysmetrics[i].szLabel));
			TextOut(hdc, 22 * cxCaps, y, sysmetrics[i].szDesc, lstrlen(sysmetrics[i].szDesc));
			SetTextAlign(hdc, TA_RIGHT | TA_TOP);
			TextOut(hdc, 22 * cxCaps + 40 * cxChar, y, szBuffer, wsprintf(szBuffer, TEXT("%5d"), GetSystemMetrics(sysmetrics[i].Index)));
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