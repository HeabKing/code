#include <windows.h>
#include <stdio.h>

// ���ڹ��̺���
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WinMain(HINSTANCE hInstance, HINSTANCE
			hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ��ƴ�����
	WNDCLASS wndcls;  // һ��������
	wndcls.cbClsExtra = 0;  // �฽���ֽ���
	wndcls.cbWndExtra = 0;  // ���ڸ����ֽ���	
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);  // ������ɫ����(��ǿ������ת��)
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);  // ������� NULL ˵��ʹ�õ��Ǳ�׼���
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);  // ͼ��
	wndcls.hInstance = hInstance;  // Ӧ�ó���ʵ����
	wndcls.lpfnWndProc = WinSunProc;  // ���ڹ��̺���
	wndcls.lpszClassName = TEXT("wndcls�������");  // ��������
	wndcls.lpszMenuName = NULL;  // û�в˵�
	wndcls.style = CS_HREDRAW | CS_VREDRAW;  // ������ ˮƽ�ػ� shuzhichonghua
	RegisterClass(&wndcls);  // ע�ᴰ����

	HWND hwnd;  // ����һ�����
	hwnd = CreateWindow(TEXT("wndcls�������")/*����*/, TEXT("���Ǵ��ڵ�����"), WS_OVERLAPPEDWINDOW/*�������� ������ ��С�� ���*/, 0, 0,/*������ʱ��x, y����*/600, 400,/*���ڵĿ�Ⱥ͸߶�*/NULL,/*������*/ NULL, /*�˵�*/ hInstance, /*ʵ������ľ��*/ 0, 0,/*���ڴ�����ʱ���λ��*/ 600, 400,/*���ڵĴ�С*/ NULL,/*������*/NULL,/*�˵�*/hInstance,/*ʵ�����*/NULL/*���ڴ���������*/);
	ShowWindow(hwnd, SW_SHOWNORMAL);  // ��ʾ����
	UpdateWindow(hwnd);  // ����һ������

	// ��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CHAR:
		MessageBox(hwnd, TEXT("���̱�������"), TEXT("case WM_CHAR:"), 0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("��걻�����"), TEXT("case WM_LBUTTONDOWN"), 0);
		HDC hdc;
		hdc = GetDC(hwnd);
		TextOut(hdc, 0, 50, TEXT("case WM_LBUTTONDOWN"), strlen("case WM_LBUTTONDOWN"));
		
		break;
	case WM_PAINT:  // �����ػ�
		HDC hDc;
		PAINTSTRUCT ps;
		hDc = BeginPaint(hwnd, &ps);
		TextOut(hDc, 0, 0, TEXT("�����ػ���"), strlen("�����ػ���"));
		EndPaint(hwnd, &ps);
		ReleaseDC(hwnd, hDc);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, TEXT("�Ƿ���Ľ���?"), TEXT("case WM_CLOSE"), MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}
	return 0;
}