// һЩ���õ�WM��Ϣ�����⴦����;
#include <windows.h>
#ifndef DXWM_CPP
#define DXWM_CPP
// �������ʾ����ĺ���;
void WM_MouseMove_ShowCoordinate(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int	xMouse, yMouse;
	TCHAR       szBuffer[200];
	HDC			hdc;
	hdc = GetDC(hwnd);

	// ���켣ɾ��  ����ɾ���켣��ȫ�����ð�ɫ�����ԭ���ָ����, �����Ҳ���ʹ�ð�ɫ��;
	RECT rectMouse;
		// ��Ч������Ⱥڿ���10px, �����ڿ�򱻲����Ժ�����ھ��������10px��Ч����ʱ����WM_PAINTʱ��Ч������;
	rectMouse.left   = xMouse - 30;
	rectMouse.top    = yMouse - 26;
	rectMouse.right  = xMouse + 100;
	rectMouse.bottom = yMouse + 40;
		
	InvalidateRect  (hwnd, &rectMouse, TRUE);  // ��һ��������Ч��, Send��WM_PAINT������������, ��WM_MOUSEMOVE��Ϣ�������ڴ���WM_PAINT��ô����Ч�����Ķ����͸���û��;
	UpdateWindow    (hwnd);  // ����, ����Postһ����Ϣ�ȽϿ���; Post��Ϣ�Ժ�, �����ǵ��߳�, ֻ����ȥ����WM_PAINT, ��������UpdateWindow��������ִ����, ����ִ���±ߵĶ���;
		
	rectMouse.left   = xMouse - 10;
	rectMouse.top    = yMouse - 6;
	rectMouse.right  = xMouse + 80;
	rectMouse.bottom = yMouse + 20;
		
	// �úڿ����ʾ���µ�����
	static POINT      apt[5];
		// �ڿ�켣ɾ�� �����һ��ð�ɫ����, �����������, ����������һ������, ������������������������Ҳ�������� �����������---// ��Ч������Ⱥڿ���10px, �����ڿ�򱻲����Ժ�����ھ��������20px��Ч����ʱ����WM_PAINTʱ��Ч������;;
	SelectObject    (hdc, GetStockObject(WHITE_PEN));
	Polyline        (hdc, apt, 5);
	SelectObject    (hdc, GetStockObject(BLACK_PEN));
	apt[0].x = apt[1].x = rectMouse.left;
	apt[0].y = apt[3].y = rectMouse.top;
	apt[1].y = apt[2].y = rectMouse.bottom;
	apt[2].x = apt[3].x = rectMouse.right;
	apt[4]   = apt[0];
	Polyline        (hdc, apt, 5);
	// ���������
	xMouse           = LOWORD(lParam); // ���������豸�����ȡ������ֵ!
	yMouse           = HIWORD(lParam);
	TextOut(hdc, xMouse + 10, yMouse, szBuffer, wsprintf(szBuffer, TEXT("(%d, %d)"), xMouse, yMouse));

	ReleaseDC(hwnd, hdc);
}

#endif