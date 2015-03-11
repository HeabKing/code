#include <Windows.h>
#include <cstdlib>
#include <ctime>
#define		SNAKEWIDTH			20		// ������
#define		SNAKEMOVETIME		300		// �ߵ��ƶ�ʱ����(����)
#define		SNAKEMOVEDISTANCE	20		// �ߵ��ƶ�������(����)
const RECT	SNAKEINITPOS		= {100, 100, 100 + SNAKEWIDTH, 100 + SNAKEWIDTH};
int			iNum_Snake			= 4;	// ������(�����ʼ�����ǳ�ʼ����)
int			xMove				= SNAKEWIDTH;	// ��x�����ƶ�����
int			yMove				= 0;			// ��y�����ƶ�����
int			xPrevMove;							// �ڳ����߳��Լ����������Ҫ�ָ�ԭ�����ƶ�״̬
int			yPrevMove;					

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void initSnake(RECT *, BOOL = FALSE);			// ��ʼ���ߵ�����
void drawSnake(HDC, RECT *);					// �������껭��
void MoveSnake(RECT *);							// �ƶ���
void SetFoodPos(HWND, RECT &, const RECT *);	// ����ʳ��λ��
BOOL isDied(HWND, const RECT *);				// �����ж�
BOOL isEat(RECT *, const RECT *);				// �ж��Ƿ�Ե���ʳ�� ����Ե���, ������������������

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR	szAppName[] = TEXT("����̰����1.0");
	MSG				msg;
	WNDCLASS		wndclass;
	HWND			hwnd;

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

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT		rcSnake[1000] = {SNAKEINITPOS.left, SNAKEINITPOS.top, SNAKEINITPOS.right, SNAKEINITPOS.bottom};
	initSnake		(rcSnake);
	static int		cxClient, cyClient;
	PAINTSTRUCT		ps;
	HDC				hdc;
	static RECT		rcFood;  // ���ʳ��λ��

	switch (message)
	{
	case WM_CREATE:

			// ����������

		SetTimer(hwnd, 1, SNAKEMOVETIME, NULL);  // ʹ�ü�ʱ��IDΪ1�ļ�ʱ��

		break;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

			// �������ʳ��λ��

		SetFoodPos(hwnd, rcFood, rcSnake);

		return 0;

	case WM_TIMER:
			// �ƶ���

		MoveSnake(rcSnake);
		
			// �����ж�
	
		if (isDied(hwnd, rcSnake))
		{
			*rcSnake = SNAKEINITPOS;
			initSnake(rcSnake, TRUE);	// ��ʼ���ߵ�λ��, TRUEʹ��initSnake�����ܹ��ڶ���ʹ��
			KillTimer(hwnd, 1);		// ֹͣ����WM_TIMER, ��Ϸ����
			MessageBox(hwnd, TEXT("������!"), TEXT("���۸����ܰ����"), MB_OKCANCEL);
		}

			// �Ƿ�Ե���ʳ��

		if (isEat(rcSnake, &rcFood))
		{
			SetFoodPos(hwnd, rcFood, rcSnake);  // ����ʳ��
			iNum_Snake++;
		}

			// ���¿ͻ���

		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
			// ����

		drawSnake(hdc, rcSnake);

			// ��ʳ��

		Rectangle(hdc, rcFood.left, rcFood.top, rcFood.right, rcFood.bottom);
		InvertRect(hdc, &rcFood);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_KEYUP:
		int xTemp;
		int yTemp;
		xTemp = xMove;
		yTemp = yMove;

		switch (wParam)
		{
		case VK_UP:		xMove = 0;				yMove = -SNAKEWIDTH;	break;
		case VK_DOWN:	xMove = 0;				yMove = SNAKEWIDTH;		break;
		case VK_LEFT:	xMove = -SNAKEWIDTH;	yMove = 0;				break;
		case VK_RIGHT:	xMove = SNAKEWIDTH;		yMove = 0;				break;
		}

		if (xTemp != xMove || yTemp != yMove)  // ��ֹ�����������ƶ���ʱ�򷴸���VK_DOWNʹ��xPrevMoveҲ����"�߳Բ���"���ƶ�����;
		{
			xPrevMove = xTemp;
			yPrevMove = yTemp;
		}
		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, 1);  // �رռ�����1
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void initSnake(RECT * rcSnake, BOOL b)
{
	static BOOL flag = FALSE;
	if (flag && !b)
		return;
	for (int i = 1; i < iNum_Snake; i++)
	{
		rcSnake[i] = rcSnake[i-1];
		OffsetRect(&rcSnake[i], -SNAKEWIDTH, 0);
	}
	flag = TRUE;
}

void drawSnake(HDC hdc, RECT * rcBeg)
{
	HBRUSH hPrevBrush = (HBRUSH)GetCurrentObject(hdc, OBJ_BRUSH);
		
		// ����ͷ

	Rectangle(hdc, rcBeg->left, rcBeg->top, rcBeg->right, rcBeg->bottom);
	SelectObject(hdc, (HBRUSH)GetStockObject(BLACK_BRUSH));
	
		// ������

	for (int i = 1; i < iNum_Snake; i++)
		Rectangle(hdc, rcBeg[i].left, rcBeg[i].top, rcBeg[i].right, rcBeg[i].bottom);
	
	SelectObject(hdc, hPrevBrush);
}

void MoveSnake(RECT * rcSnake)
{

		// �ƶ���ͷ

	RECT rcTemp = *rcSnake;
	OffsetRect(&rcTemp, xMove, yMove);
	
		// �Ƴ���ͷ���߲��ӵĴ���

	POINT ptTemp = {rcTemp.left + SNAKEWIDTH / 2, rcTemp.top + SNAKEWIDTH / 2};
	if (PtInRect(&rcSnake[1], ptTemp))
	{
		xMove = xPrevMove;
		yMove = yPrevMove;
		return;
	}

		// �ƶ�����

	for (int i = iNum_Snake - 1; i > 0; i--)
		rcSnake[i] = rcSnake[i-1];
	rcSnake[0] = rcTemp;
}

BOOL isDied(HWND hwnd, const RECT * rcSnake)
{
	RECT rcClient;
	GetClientRect(hwnd, &rcClient);
	POINT ptTemp = {rcSnake->left + SNAKEWIDTH / 2, rcSnake->top + SNAKEWIDTH / 2};
	if (PtInRect(&rcClient, ptTemp))  // ײǽ�ж�
	{
		for (int i = 4; i < iNum_Snake; i++)  
			if (PtInRect(&rcSnake[i], ptTemp))  // �Գ��ж�
				return TRUE;
	}
	else
		return TRUE;
	return FALSE;
}

void SetFoodPos(HWND hwnd, RECT & rcFood, const RECT * rcSnake)
{
	RECT rcClient;
	GetClientRect(hwnd, &rcClient);
		
		// �������λ��

	srand(rand());
	rcFood.left		= rand() % rcClient.right  / SNAKEWIDTH * SNAKEWIDTH;  // ��֤ʳ���������ͬһˮƽ����
	rcFood.top		= rand() % rcClient.bottom / SNAKEWIDTH * SNAKEWIDTH;
	rcFood.right	= rcFood.left + SNAKEWIDTH;
	rcFood.bottom	= rcFood.top  + SNAKEWIDTH;

	////	// ��ֹ�����������

	//int flag = 0;
	//for (int i = 0; i < iNum_Snake; i++)  
	//	if (rcSnake[i].left		== rcFood.left	&&
	//		rcSnake[i].right	== rcFood.right	&&
	//		rcSnake[i].top		== rcFood.top	&&
	//		rcSnake[i].bottom	== rcFood.bottom)
	//		SetFoodPos(hwnd, rcFood, rcSnake);
			
}

BOOL isEat(RECT * rcSnake, const RECT * rcFood)
{
	POINT ptTemp = {rcSnake->left + SNAKEWIDTH / 2, rcSnake->top + SNAKEWIDTH / 2};
	if (PtInRect(rcFood, ptTemp))
	{
		for (int i = iNum_Snake - 1; i > 0; i--)
			rcSnake[i] = rcSnake[i-1];
		rcSnake[0] = *rcFood;	
		return TRUE;
	}
	return FALSE;
	
}