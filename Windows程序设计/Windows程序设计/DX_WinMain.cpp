#include <windows.h>
#ifndef DXWINMAIN_CPP
#define DXWINMAIN_CPP
#include "DX_WM.CPP"
#ifndef SZAPPNAME
#define SZAPPNAME "DX_WinMain.cpp"
#endif
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#ifdef PEEKMESSAGE
void PeekMessageInsertCode(void);
#endif

#ifdef CHANGEWNDCLASS
void ChangeWndClass(WNDCLASS *);
#endif

#ifdef CHANGECREATEWINDOW
HWND ChangeCreateWindow(HINSTANCE);
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT(SZAPPNAME);
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

#ifdef CHANGEWNDCLASS
	ChangeWndClass(&wndclass);
#endif

	RegisterClass(&wndclass);

#ifdef CHANGECREATEWINDOW
	hwnd = ChangeCreateWindow(hInstance);
#else
	hwnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
#endif

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

#ifdef PEEKMESSAGE
	while (TRUE)
	{
		// GetMessage����������ѿ���Ȩ��������, �������ӳ������Ϣ�����л������Ϣ.
		// PeekMessage����������������, ������Ϣ�Ƿ����. �������Ϣ, ����TRUE, ���򷵻�FALSE
		if (PeekMessage(&msg, NULL, // ���ھ������
			0, 0,  // ��Ϣ��Χ����   �������������ó�NULL��0, ��ʾ������ʹ��PeekMessage()�������س����е����д��ڵ�������Ϣ��Ϣ
			PM_REMOVE))  // �����ɾ����Ϣ�����е���Ϣ, ���Դ˴����ó�PM_REMOVE, ����ɾ��, ���ó�PM_NOREMOVE
			// ����ʹ��PM_REMOVE����ɾ��WM_PAINT��Ϣ֮���������Ϣ, �������������Ч�������Ч, WM_PAINT����һֱ����, ����Ҳ����������ѭ��
		{
			if (msg.message == WM_QUIT)  // ������ ���� ��ȷ���WM_QUIT��Ϣ, ��һ����������Ϣѭ����, ����Ҫ��ô��, ��Ϊ��ȡһ��WM_QUIT��Ϣʱ, GetMessage�����ķ���ֵ��FALSE(0), ����PeekMessage�����ķ���ֵ�Ǳ�ʾ��Ϣ�������Ƿ�����Ϣ, ��˼��WM_QUIT�Ǳ�Ҫ��.
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			PeekMessageInsertCode();
	}
#else
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#endif

	return msg.wParam;
}
#endif