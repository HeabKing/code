#include <windows.h>
#include "����2048��Ϸ1.0.h"
#include <ctime>
#include <process.h>
#pragma comment(lib, "WINMM.LIB")  // ��֤PlaySound()����ִ�� #pragma��������ָ������Դ������

TCHAR	szAppName[]		= TEXT("����2048��Ϸ1.0");	// �������༰������
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void	RandBox(Box DivBox[][4]);	// �����ʾһ��Box

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	WNDCLASS	wndclass;

		// ��������������ע��

	wndclass.cbClsExtra			= 0;
	wndclass.cbWndExtra			= 0;
	wndclass.hbrBackground			= CreateSolidBrush(RGB(143, 146, 139));
	wndclass.hCursor				= LoadCursor(NULL, IDI_APPLICATION);
	wndclass.hIcon					= LoadIcon(NULL, IDC_ARROW);
	wndclass.hInstance				= hInstance;
	wndclass.lpfnWndProc			= WndProc;
	wndclass.lpszClassName			= szAppName;
	wndclass.lpszMenuName			= NULL;
	wndclass.style					= CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("ע����������ʧ��!"), TEXT("����"), MB_ICONERROR);
		return 0;
	}

		// ����������

	HWND hwnd = CreateWindow(szAppName, szAppName, 
							  WS_OVERLAPPED |	// (�ص�ʽ���ڣ���ʽ�����ڴ���һ���������ͱ߿� ),
							  WS_CAPTION |		// (���ھ��б����������� WS_BODER)),
							  WS_SYSMENU,		// (���� SYSTEM �˵�����������ָ�� WS_CAPTION ʽ��),
													// WS_THICKFRAM		(���пɵ��߿�), 
							  //WS_MINIMIZEBOX,	// (������С����ť),
													// WS_MAXIMIZEBOX	(������󻯰�ť)
							  200, 100, 300, 400,
							  NULL, NULL, hInstance, NULL);
	
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	
		// ��Ϣѭ��

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

void PlayBackgroundMusic(void *)
{
	PlaySound(TEXT("����2048��Ϸ1.0��������.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC				hdc;
	PAINTSTRUCT		ps;
	static Box		BoxDiv[DIVISION][DIVISION];
	static int		cxClient, cyClient;
	static RECT		rcClient;
	bool			isMove = false;		// ��������Ƿ���һ�ΰ�������Box�ƶ�

	switch (message)
	{
	case WM_CREATE:

			// �������еĴ���(λ�úʹ�Сδ�趨);

		for (int x = 0; x < DIVISION; x++)
			for (int y = 0; y < DIVISION; y++)
				BoxDiv[y][x].CreateBox(hwnd, y << 8 | x);
		
		PlaySound(TEXT("����2048��Ϸ1.0��ʼ��.wav"), NULL, SND_FILENAME | SND_SYNC);
		_beginthread(PlayBackgroundMusic, 0, nullptr);
		return 0;
	case WM_SIZE:
			
			// ������Box���ú��ʵĴ�С��λ��(Ĭ�ϲ���ʾ);

		GetClientRect(hwnd, &rcClient);
		for (int x = 0; x < DIVISION; x++)
		{
			for (int y = 0; y < DIVISION; y++)
			{
				BoxDiv[y][x].MoveBox(rcClient);
			}
		}

			// �����ʾһ��Box, ��ֵ 2 / 4 �����ʾ
		RandBox(BoxDiv);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			for (int x = 0; x < DIVISION; x++)
				for (int y = 0; y < DIVISION; y++)
					if (BoxDiv[y][x].OffsetBox(BoxDiv, EnumLeft))
						isMove = true;
			break;
		case VK_UP:
			for (int x = 0; x < DIVISION; x++)
				for (int y = 0; y < DIVISION; y++)
					if (BoxDiv[y][x].OffsetBox(BoxDiv, EnumUp))
						isMove = true;
			break;
		case VK_RIGHT:
			for (int x = DIVISION - 1; x >= 0; x--)
				for (int y = DIVISION - 1; y >= 0; y--)
					if (BoxDiv[y][x].OffsetBox(BoxDiv, EnumRight))
						isMove = true;
			break;
		case VK_DOWN:
			for (int x = DIVISION - 1; x >= 0; x--)
				for (int y = DIVISION - 1; y >= 0; y--)
					if (BoxDiv[y][x].OffsetBox(BoxDiv, EnumDown))
						isMove = true;
			break;
		//case VK_SPACE:  // lParam: 373553 wParam: 32
		//	TCHAR szBuffer[100];
		//	wsprintf(szBuffer, TEXT("%d"), VK_SPACE);
		//	MessageBox(NULL, szBuffer, NULL, NULL);
			break;
		default: return 0;
		}
		PlaySound(TEXT("����2048��Ϸ1.0������Ч.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (isMove)
			RandBox(BoxDiv);
		break;

		// ��ֹ����Box������Box�����뽹���ʹ�÷����ʧ��
	case WM_COMMAND:
		SetFocus(hwnd);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int x = 0; x < DIVISION; x++)
			for (int y = 0; y < DIVISION; y++)
			{
				FrameRect(hdc, &BoxDiv[x][y].GetRcBoxPos(), (HBRUSH)GetStockObject(WHITE_BRUSH));
			}
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void RandBox(Box DivBox[][4])
{
	int isHide[DIVISION * DIVISION] = {0};
	int Offset = 0;
		
		// Ѱ��û����ʾ��Box, ����ID˳�η���isHide��

	for (int x = 0; x < DIVISION; x++)
		for (int y = 0; y < DIVISION; y++)
			if (DivBox[y][x].GetIsShow() == false)
				isHide[Offset++] = y << 8 |x;
	
		// �������Box����ʾ��, ���������ж�

	if (0 == Offset)
	{
			// �ж��Ƿ�����Box�п����ںϵ�
		for (int x = 0; x < DIVISION; x++)
			for (int y = 0; y < DIVISION - 1; y++)
				if (DivBox[x][y].GetBoxSumNum() == DivBox[x][y+1].GetBoxSumNum())
					return;

			// �ж��Ƿ�����Box�п����ںϵ�
		for (int y = 0; y < DIVISION; y++)
			for (int x = 0; x < DIVISION - 1; x++)
				if (DivBox[x][y].GetBoxSumNum() == DivBox[x+1][y].GetBoxSumNum())
					return;

			// ���û�п��Ժϲ���Box, ���е�Box��ȫ����ʾ��, ��Ϸ����
		MessageBox(NULL, TEXT("��������  QQ: 394899990  �ٶ�ID: �ж�־����"), TEXT("������"), NULL);
		SendMessage(GetParent(DivBox[0][0].GetBoxHwnd()), WM_DESTROY, 0, 0);
		return;
	}

		// ��û����ʾ��Box�������ѡһ��Box��ʾ, ����Box�ڵ����������һ��2 / 4	

	srand((unsigned long)time(0));
	int yx = isHide[rand() % Offset];
	DivBox[yx >> 8][yx & 0xff].Show();
	srand((unsigned long)(time(0) + 25));
	DivBox[yx >> 8][yx & 0xff].SetBoxSumNum(rand() % 2 * 2 + 2);
}