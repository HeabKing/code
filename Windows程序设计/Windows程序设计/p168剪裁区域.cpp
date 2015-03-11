#include <math.h>
#define SZAPPNAME "p168�ü�����"
#define TWO_PI (2.0 * 3.1415926)
#include "DX_WinMain.cpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HRGN hRgnClib;
	static int  cxClient, cyClient;
	double      fAngle/*�Ƕ�*/, fRadius/*�뾶 �����ĵ��ͻ�������ľ���*/;
	HCURSOR     hCursor;
	HDC         hdc;
	HRGN        hRgnTemp[6];
	int         i;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		hCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
		ShowCursor(TRUE);

		if (hRgnClib)
			DeleteObject(hRgnClib);

		// �����ĸ���Ա����, ����������
		hRgnTemp[0] = CreateEllipticRgn(0, cyClient / 3, cxClient / 2, 2 * cyClient / 3);  // �� �� �� ��
		hRgnTemp[1] = CreateEllipticRgn(cxClient / 2, cyClient / 3, cxClient, 2 * cyClient / 3);
		hRgnTemp[2] = CreateEllipticRgn(cxClient / 3, 0, 2 * cxClient / 3, cyClient / 2);
		hRgnTemp[3] = CreateEllipticRgn(cxClient / 3, cyClient / 2, 2 * cxClient / 3, cyClient);
		hRgnTemp[4] = CreateRectRgn(0, 0, 1, 1);
		hRgnTemp[5] = CreateRectRgn(0, 0, 1, 1);
		hRgnClib    = CreateRectRgn(0, 0, 1, 1);

		CombineRgn(hRgnTemp[4], hRgnTemp[0], hRgnTemp[1], RGN_OR);  // �ͻ�������ߺ��ұߵ�������Բ�ϲ� 
		CombineRgn(hRgnTemp[5], hRgnTemp[2], hRgnTemp[3], RGN_OR);  // ���� RGN_OR ȫ���ϲ�
		CombineRgn(hRgnClib,    hRgnTemp[4], hRgnTemp[5], RGN_XOR); // RGN_XOR ��ȥ�������ֵ�ȫ���ϲ� �ų��ص�

		for (i = 0; i < 6; i++)
			DeleteObject(hRgnTemp[i]);
		SetCursor(hCursor);
		ShowCursor(FALSE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);  // ���ӿ�ԭ�������ڿͻ�������(����ʹ�û�ֱ�߸�����)
		SelectClipRgn(hdc, hRgnClib);  // ����������ѡ���豸������Ϊ��������

		fRadius = _hypot(cxClient / 2.0, cyClient / 2.0);

		for (fAngle = 0.0; fAngle < TWO_PI; fAngle += TWO_PI / 360)  // һ����360��, ÿһ�Ȼ�һ��
		{
			MoveToEx(hdc, 0, 0, NULL);
			LineTo(hdc, (int)(fRadius * cos(fAngle) + 0.5), (int)(-fRadius * sin(fAngle) + 0.5));
		}

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		DeleteObject(hRgnClib);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}