// ���߼������óɿͻ�������, Ȼ��һ����������
#define SZAPPNAME "p146�߼���λ�����ĵ���������.cpp"
#include "DX_WinMain.cpp"
#include <cmath>


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;
	static int	cxClient, cyClient;
	TCHAR       szBuffer[200];

	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);  
		cyClient = HIWORD(lParam);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		//SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);  // # 1
		SetWindowOrgEx(hdc, -cxClient / 2, -cyClient / 2, NULL);  // # 2 
		// GetVieportOrgEx()��, �õ���(x, y)���豸����ϵ����(���Ͻ�Ϊ(0, 0))��ʾ�ӿ�ԭ��λ��, �����ͱ�ʶ�����ӿ�ԭ���λ��;
		// GetWindowOrgEx()��, �õ���(x, y)���߼�����ϵ(����ԭ��Ϊ(0, 0))��ʾ�ӿ�ԭ��λ��, �����ͱ�ʶ���˴���ԭ���λ��;
		// ������Ϊֻ����������ϵͳ, һ�����豸����ϵͳ, һֱ�����Ͻ�Ϊ(0, 0) �����ʶ�ӿ�ԭ��λ�ý�����ʶ����ԭ��λ��, Ȼ�����߼�����ϵͳ, ����������;
		// # 1 �ӿ�ԭ�� ����ԭ�� �Ƶ�����, ��ʾ�ӿ�ԭ��(504, 244), ����ԭ��(0, 0);
		// # 2 �ӿ�ԭ�� �����Ͻ�, �ӿ�ԭ��(0, 0) ����ԭ�� ������ ����ԭ��(-504, -244);
		// # 1 # 2 �ӿ�ԭ�� ������ �ӿ�ԭ��(504, 244) ����ԭ�� �����½� ����ԭ��(-504, -244);
		MoveToEx(hdc, -cxClient / 2, 0, NULL);  // ��ʼ����Ĭ����(0, 0)��������߼�ԭ���;
		LineTo(hdc, cxClient / 2, 0);
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, 0, -cyClient / 2);
		MoveToEx(hdc, 0, 0, NULL);
		int x, y;
		for (int i = 0; i < 1000; i++)
		{
			x = i * cxClient / 2 / 1000;  // i / 1000 * (cxClient / 2)
			y = -(int)(sin(i * 2 * 3.1415926 / 1000) * cyClient / 2);  // i / 1000 * 2PIE
			LineTo(hdc, x, y);
		}

		// ����ӿ�ԭ�� ����ԭ�� �����Ӵ�ת��
		POINT ptOrg;
		GetWindowOrgEx(hdc, &ptOrg);
		TextOut(hdc, 20, 20, szBuffer, wsprintf(szBuffer, TEXT("����ԭ��: (%d, %d)"), ptOrg.x, ptOrg.y));
		LPtoDP(hdc, &ptOrg, 1);
		TextOut(hdc, 200, 20, szBuffer, wsprintf(szBuffer, TEXT("LPtoDP: (%d, %d)"), ptOrg.x, ptOrg.y));
		GetViewportOrgEx(hdc, &ptOrg);
		TextOut(hdc, 20, 50, szBuffer, wsprintf(szBuffer, TEXT("�ӿ�ԭ��: (%d, %d)"), ptOrg.x, ptOrg.y));
		DPtoLP(hdc, &ptOrg, 1);
		TextOut(hdc, 200, 50, szBuffer, wsprintf(szBuffer, TEXT("DPtoLP: (%d, %d)"), ptOrg.x, ptOrg.y));

		EndPaint(hwnd, &ps);
		return 0;

		// �����������
	case WM_MOUSEMOVE:
		static int xMouse, yMouse;
		hdc = GetDC(hwnd);

		// ���켣ɾ��  ����ɾ���켣��ȫ�����ð�ɫ�����ԭ���ָ����, �����Ҳ���ʹ�ð�ɫ��;
		RECT rectMouse;
			// ��Ч������Ⱥڿ���10px, �����ڿ�򱻲����Ժ�����ھ��������10px��Ч����ʱ����WM_PAINTʱ��Ч������;
		rectMouse.left = xMouse - 30;
		rectMouse.top  = yMouse - 26;
		rectMouse.right = xMouse + 100;
		rectMouse.bottom = yMouse + 40;
		
		InvalidateRect(hwnd, &rectMouse, TRUE);  // ��һ��������Ч��, Send��WM_PAINT������������, ��WM_MOUSEMOVE��Ϣ�������ڴ���WM_PAINT��ô����Ч�����Ķ����͸���û��;
		UpdateWindow(hwnd);  // ����, ����Postһ����Ϣ�ȽϿ���; Post��Ϣ�Ժ�, �����ǵ��߳�, ֻ����ȥ����WM_PAINT, ��������UpdateWindow��������ִ����, ����ִ���±ߵĶ���;
		
		rectMouse.left = xMouse - 10;
		rectMouse.top  = yMouse - 6;
		rectMouse.right = xMouse + 80;
		rectMouse.bottom = yMouse + 20;
		
		// �úڿ����ʾ���µ�����
		static POINT apt[5];
			// �ڿ�켣ɾ�� �����һ��ð�ɫ����, �����������, ����������һ������, ������������������������Ҳ�������� �����������---// ��Ч������Ⱥڿ���10px, �����ڿ�򱻲����Ժ�����ھ��������20px��Ч����ʱ����WM_PAINTʱ��Ч������;;
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		Polyline(hdc, apt, 5);
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		apt[0].x = apt[1].x = rectMouse.left;
		apt[0].y = apt[3].y = rectMouse.top;
		apt[1].y = apt[2].y = rectMouse.bottom;
		apt[2].x = apt[3].x = rectMouse.right;
		apt[4] = apt[0];
		Polyline(hdc, apt, 5);
		// ���������
		xMouse = LOWORD(lParam); // ���������豸�����ȡ������ֵ!
		yMouse = HIWORD(lParam);
		TextOut(hdc, xMouse + 10, yMouse, szBuffer, wsprintf(szBuffer, TEXT("(%d, %d)"), xMouse, yMouse));

		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}