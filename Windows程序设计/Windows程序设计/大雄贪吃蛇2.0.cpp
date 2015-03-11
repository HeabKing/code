// 2014.05
#include <windows.h> 
#include <fstream>
#include <ctime>
#include "����̰����2.0.h"
#pragma comment(lib, "WINMM.LIB")  // ��֤PlaySound()����ִ�� #pragma��������ָ������Դ������

const WCHAR * szAppName = TEXT("����̰����2.0");
const int	SnakeMoveTime	= 300;	// �ߵ��ƶ�ʱ����(����)
const int	SnakeWidth		= 20;	// ������

LRESULT CALLBACK WndProc		(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndPlayProc	(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndScoreProc	(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
WNDPROC OldPlayProc;
enum WindowID		{IDPlay, IDScore, IDLv};
enum StatusFlag		{wellcome, playing};
StatusFlag	Status = wellcome;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	PlaySound(TEXT("����̰����2.0 ��������.wav"), NULL, SND_FILENAME | SND_ASYNC);

	WNDCLASS wndclass;

	wndclass.cbClsExtra			= 0;
	wndclass.cbWndExtra			= 0;
	wndclass.hbrBackground		= (HBRUSH)(COLOR_BTNFACE + 1);
	wndclass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance			= hInstance;
	wndclass.lpfnWndProc		= WndProc;
	wndclass.lpszClassName		= szAppName;
	wndclass.lpszMenuName		= NULL;
	wndclass.style				= CS_VREDRAW | CS_HREDRAW;

	RegisterClass(&wndclass);

	HWND hwnd = CreateWindow(szAppName, szAppName, 
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME, 
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

void Wellcome(HWND);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND			hwndPlay;
	static HWND			hwndScore;
	static HWND			hwndLv;
	static int			cxClient, cyClient;
	static HBRUSH		hbrushRed = CreateSolidBrush(RGB(255, 0, 0));
	
	switch (message)
	{
	case WM_CREATE:
		Status = wellcome;	// ��״̬��ʼ��Ϊ��ӭ����
		HINSTANCE hInstance;
		hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);

			// ������̬�ؼ�

		hwndPlay	= CreateWindow(TEXT("static"), NULL, SS_WHITERECT | WS_CHILD, 0, 0, 0, 0, hwnd, (HMENU)IDPlay , hInstance, NULL);
		hwndScore	= CreateWindow(TEXT("static"), NULL, SS_WHITERECT | WS_CHILD, 0, 0, 0, 0, hwnd, (HMENU)IDScore, hInstance, NULL);
		hwndLv		= CreateWindow(TEXT("static"), NULL, SS_WHITERECT | WS_CHILD, 0, 0, 0, 0, hwnd, (HMENU)IDLv   , hInstance, NULL);
			
			// �����µľ�̬���ڹ��̵ĵ�ַ, ͬʱ������о�̬���ڹ��̵ĵ�ַ

		OldPlayProc = (WNDPROC)SetWindowLong(hwndPlay, GWL_WNDPROC, (LONG)WndPlayProc);
					// �������ؼ��Ĵ��ڹ�����windows�ڲ�, ����ͨ��GetWindowLong����ȡ������ڹ��̵ĵ�ַ;
					// ������ͨ��SetWindowLongΪ����������һ���µĴ��ڹ���, ���ּ�����Ϊ"��������"
					// �µĴ��ڹ���ͨ��CallWindowProc�����þɵĴ��ڹ���;
		(WNDPROC)SetWindowLong(hwndScore, GWL_WNDPROC, (LONG)WndScoreProc);

		return 0;

	case WM_SIZE:
		cxClient	= LOWORD(lParam);
		cyClient	= HIWORD(lParam);

			// ���þ�̬�ؼ���С��λ��

		MoveWindow(hwndPlay, cxClient / 40, cyClient * 2 / 20, cxClient * 38 / 40, cyClient * 17 / 20, TRUE);
		MoveWindow(hwndLv, cxClient / 40, cyClient / 80, cxClient * 7 / 40, cyClient * 3 / 40, TRUE);
		MoveWindow(hwndScore, cxClient * 32 / 40, cyClient / 80, cxClient * 7 / 40, cyClient * 3 / 40, TRUE);

		return 0;

	case WM_PAINT:
		HDC hdc;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);

		switch (Status)
		{
		case wellcome:
			Wellcome(hwnd);
			ShowWindow(hwndPlay , SW_HIDE);
			ShowWindow(hwndLv	 , SW_HIDE);
			ShowWindow(hwndScore, SW_HIDE);
			break;
		case playing:

				// ��ʾ��̬����

			ShowWindow(hwndPlay , SW_SHOW);
			ShowWindow(hwndLv	 , SW_SHOW);
			ShowWindow(hwndScore, SW_SHOW);

			break;
		default:
			break;
		}
		
		EndPaint(hwnd, &ps);
		return 0;

	case WM_SETFOCUS:
		SetFocus(hwndPlay);
		return 0;

	case WM_TIMER:
		SendMessage(hwndPlay, message, wParam, lParam);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			Status = playing;
			SetTimer(hwnd, 1, SnakeMoveTime, NULL);	// ʹ�ü�ʱ��IDΪ1�ļ�ʱ��
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
		default:
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK WndPlayProc	(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT			rcPlay;
	HDC				hdc;
	PAINTSTRUCT		ps;
	static Snake	sk;
	static Snake::MoveDir StatusMove = Snake::RIGHT;
	static int		flag = 0;
	switch (message)
	{
	case WM_PAINT:	 
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rcPlay);
		Rectangle(hdc, rcPlay.left, rcPlay.top, rcPlay.right, rcPlay.bottom);
		sk.Draw(hdc);
		sk.ShowFood(hwnd);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			SendMessage(GetParent(hwnd), message, wParam, lParam);
			break;
		case VK_LEFT:
			StatusMove = Snake::LEFT;
			break;
		case VK_RIGHT:
			StatusMove = Snake::RIGHT;
			break;
		case VK_UP:
			StatusMove = Snake::UP;
			break;
		case VK_DOWN:
			StatusMove = Snake::DOWN;
			break;
		case VK_SPACE:
			if (!flag)
				KillTimer(GetParent(hwnd), 1);
			else
			{
				SetTimer(GetParent(hwnd), 1, SnakeMoveTime, NULL);
				SendMessage(GetParent(hwnd), WM_TIMER, 0, 0);
			}
			flag ^= 1;
			break;
		default:
			break;
		}
		return 0;

	case WM_TIMER:
		if (!sk.Move(hwnd, StatusMove) && Status == playing)
		{
			// ������ҲҪ����������һ���߳������ָ��û�, �ﵽ���û������Լ�Ϊʲô����Ŀ��
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
			
			sk.Resert();
			KillTimer(GetParent(hwnd), 1);
			flag ^= 1;
			Status = wellcome;
			SendMessage(GetDlgItem(GetParent(hwnd), IDScore), WM_USER + 2, 0, 0);	  // ���÷���
			MessageBox(NULL, TEXT("������"), TEXT("��Ϸ����"), 0);
			InvalidateRect(GetParent(hwnd), NULL, TRUE);
			UpdateWindow(GetParent(hwnd));
			return 0;
		}
		if (sk.IsEat())
		{
			sk.RandomFood(hwnd);
			sk.Add();
			SendMessage(GetDlgItem(GetParent(hwnd), IDScore), WM_USER + 1, 0, 0);
		}
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
		return 0;
	}
	return CallWindowProc(OldPlayProc, hwnd, message, wParam, lParam);
}

	// ��ӭ����
void Wellcome(HWND hwnd)
{
	using namespace std;
	const char	FileName[]	= "����̰����2.0 ��ӭ����.txt";
	const int	BufSize		= 512;
	char		Buffer[BufSize];
	ifstream	fin;

	fin.open(FileName);
	if (!fin.is_open())
		MessageBox(NULL, TEXT("���ܴ��ļ�����̰����2.0 ��ӭ����.txt"), TEXT("Error"), 0);
	
	HDC		hdc = GetDC(hwnd);
	RECT	rc;
	GetWindowRect	(hwnd, &rc);
	SelectObject	(hdc, GetStockObject	(SYSTEM_FIXED_FONT));
	SetBkColor		(hdc, GetSysColor		(COLOR_BTNFACE));

	int i = 0;
	for (fin.getline(Buffer, BufSize); fin.good(); fin.getline(Buffer, BufSize))
		TextOutA(hdc, (rc.right - rc.left) / 2 - 280, i++ * 20 + (rc.bottom - rc.top) / 2 - 240, (LPCSTR)Buffer, strlen(Buffer));
						// ���ﲻ��ȥrc.leftҲ��ʵ��, �����ڴ���������ϻд��ڵ�ʱ��, ��ʹ���������;
	
	ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndScoreProc	(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int			Score2 = 3;
	static int			Score  = 0;
	static ZoomDigit	digit(hwnd, 0, 0, 0, 32);
	static ZoomDigit	digit2(hwnd, 32, 0, 0, 32);
	switch (message)
	{
	case WM_USER + 1:
		if (++Score2 == 10)
		{
			Score2 = 0;
			if (++Score == 10)
				Score = 0;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_USER + 2:	// ����
		Score = 0;
		Score2 = 3;
		return 0;

	case WM_PAINT:
		HDC			hdc;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		srand((unsigned long)(time(0)));

		digit.HideDigit();
		digit.SetDigit(Score);
		digit.SetColor(RGB(rand() % 256, rand() % 256, rand() % 256));
		digit.ShowDigit();
		
		srand((unsigned long)(time(0) + rand()));
		digit2.HideDigit();
		digit2.SetDigit(Score2);
		digit2.SetColor(RGB(rand() % 256, rand() % 256, rand() % 256));
		digit2.ShowDigit();
		

		EndPaint(hwnd, &ps);
		return 0;
	}
	return CallWindowProc(OldPlayProc, hwnd, message, wParam, lParam);
}