#include <math.h>
#define SZAPPNAME "p120 �������Ҳ�"
#include "DX_WinMain.cpp"
#define POLYLINE  // POLYLINE �� LINETO
#define NUM 1000
#define TWOPI (2 * 3.14159)

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int cxClient, cyClient;
	int i;
	HDC hdc;
	PAINTSTRUCT ps;
	POINT apt[NUM];
	
	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		for (i = 0; i < NUM; i++)
		{
			apt[i].x = i * cxClient / NUM;
			apt[i].y =(int)((1 - sin((double)i/*������ﲻ����double�Ļ�i/num��С����������ת�������εĻ�����0��*/ / NUM * TWOPI)) * cyClient / 2);
#if defined LINETO
			LineTo(hdc, apt[i].x, apt[i].y);
		}
#elif defined POLYLINE
		}
		Polyline(hdc, apt, NUM);  // ��ΪPolyline���������豸��������Ĳ����ʵ�ֵ�, ������ȵ���1000��LineTo����Ҫ��;
#endif
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}