#define	SZAPPNAME	"p300�Ի水ť"
#define ID_SMALLER	1
#define ID_LARGER	2
#define BTN_WIDTH	(8 * cxChar)
#define BTN_HEIGHT	(4 * cyChar)
#include "DX_WinMain.cpp"

	// �� ��������ģʽ ��pt�����еõ����ӳ�һ�����ͼ��

void Triangle(HDC hdc, POINT pt[])
{
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
	Polygon(hdc, pt, 3);
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND		hwndSmaller, hwndLarger;
	static int		cxClient, cyClient, cxChar, cyChar;
	int				cx, cy;
	LPDRAWITEMSTRUCT pdis;  // ָ��һ��DRAWITEMSTRUCT���͵Ľṹ, ����ṹ���б�Ҫ����Ϣ������������ư�ť: hDC(��ť�豸����), rcItem(RECT�ṹ, �ṩ��ť�ĳߴ�), CtlID(�ؼ�����ID), itemState(��ť�Ƿ��»�������뽹��)
	POINT			pt[3];
	RECT			rc;  // ���洰�ھ������豸�����λ��

	switch (message)
	{
	case WM_CREATE:
		cxChar = LOWORD(GetDialogBaseUnits());  // �˺���������ȡ�ַ���Ĭ������Ŀ�Ⱥ͸߶�, �Ի���ʹ�����������ȡ����ߴ�, �ú�������һ��32λֵ, ��λ�ֺ͸�λ�ֱַ����Ӵ��ڵĿ�Ⱥ͸߶�; 
		cyChar = HIWORD(GetDialogBaseUnits());

			// �����Ի水ť

		hwndSmaller	= CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
			0, 0, BTN_WIDTH, BTN_HEIGHT, hwnd, (HMENU)ID_SMALLER, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

		hwndLarger		= CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
			0, 0, BTN_WIDTH, BTN_HEIGHT, hwnd, (HMENU)ID_LARGER, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

		return 0;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

			// ���Ӵ��ڰ�ť�ƶ����ͻ�������

		MoveWindow(hwndSmaller, cxClient / 2 - 3 * BTN_WIDTH / 2, cyClient / 2 - BTN_HEIGHT / 2, BTN_WIDTH, BTN_HEIGHT, TRUE);
		MoveWindow(hwndLarger , cxClient / 2 + 3 * BTN_WIDTH / 2, cyClient / 2 - BTN_HEIGHT / 2, BTN_WIDTH, BTN_HEIGHT, TRUE);

		return 0;

	case WM_COMMAND:  // wParam ��λ����֪ͨ�� ��λ�����Ӵ���ID  lParam �Ӵ��ھ��
		GetWindowRect(hwnd, &rc);  // �������GetClientRect, ����ǻ�ȡ�Ĵ������豸�����µ�λ��

			// ���������ڷŴ����С10%

		switch (wParam)
		{
		case ID_SMALLER:
			rc.left			+= cxClient / 20;
			rc.right		-= cxClient / 20;
			rc.top			+= cyClient / 20;
			rc.bottom		-= cyClient / 20;
			break;

		case ID_LARGER:
			rc.left			-= cxClient / 20;
			rc.right		+= cxClient / 20;
			rc.top			-= cyClient / 20;
			rc.bottom		+= cyClient / 20;
			break;
		}

		MoveWindow(hwnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);  // MoveWindow�����ܹ��ƶ��Ӵ���, �����ƶ���������

		return 0;

	case WM_DRAWITEM:  // ����BS_OWNERDRAW��ʽ�İ�ť, ����Ҫ���»���ʱ, �������丸���ڷ���WM_DRAWITEM��Ϣ
		// lParam ָ��һ��DRAWITEMSTRUCT���͵Ľṹ;
		pdis = (LPDRAWITEMSTRUCT)lParam;  // DRAWITEMSTRUCT���͵Ľṹ, ����ṹ���б�Ҫ����Ϣ������������ư�ť: hDC(��ť�豸����), rcItem(RECT�ṹ, �ṩ��ť�ĳߴ�), CtlID(�ؼ�����ID), itemState(��ť�Ƿ��»�������뽹��)

			// ����һ���׵׺ڿ������

		FillRect(pdis->hDC, &pdis->rcItem, (HBRUSH)GetStockObject(WHITE_BRUSH));
		FrameRect(pdis->hDC, &pdis->rcItem, (HBRUSH)GetStockObject(BLACK_BRUSH));

			// ���ư�ť�ڵ��������͵�������

		cx = pdis->rcItem.right - pdis->rcItem.left;
		cy = pdis->rcItem.bottom - pdis->rcItem.top;

		switch (pdis->CtlID)
		{
		case ID_SMALLER:
			pt[0].x = 3 * cx / 8;		pt[0].y = 1 * cy / 8;
			pt[1].x = 5 * cx / 8;		pt[1].y = 1 * cy / 8;
			pt[2].x = 4 * cx / 8;		pt[2].y = 3 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 7 * cx / 8;		pt[0].y = 3 * cy / 8;
			pt[1].x = 7 * cx / 8;		pt[1].y = 5 * cy / 8;
			pt[2].x = 5 * cx / 8;		pt[2].y = 4 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 5 * cx / 8;		pt[0].y = 7 * cy / 8;
			pt[1].x = 3 * cx / 8;		pt[1].y = 7 * cy / 8;
			pt[2].x = 4 * cx / 8;		pt[2].y = 5 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 1 * cx / 8;		pt[0].y = 5 * cy / 8;
			pt[1].x = 1 * cx / 8;		pt[1].y = 3 * cy / 8;
			pt[2].x = 3 * cx / 8;		pt[2].y = 4 * cy / 8;
			Triangle(pdis->hDC, pt);
			break;

		case ID_LARGER:
			pt[0].x = 5 * cx / 8;		pt[0].y = 3 * cy / 8;
			pt[1].x = 3 * cx / 8;		pt[1].y = 3 * cy / 8;
			pt[2].x = 4 * cx / 8;		pt[2].y = 1 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 5 * cx / 8;		pt[0].y = 5 * cy / 8;
			pt[1].x = 5 * cx / 8;		pt[1].y = 3 * cy / 8;
			pt[2].x = 7 * cx / 8;		pt[2].y = 4 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 3 * cx / 8;		pt[0].y = 5 * cy / 8;
			pt[1].x = 5 * cx / 8;		pt[1].y = 5 * cy / 8;
			pt[2].x = 4 * cx / 8;		pt[2].y = 7 * cy / 8;
			Triangle(pdis->hDC, pt);
			pt[0].x = 3 * cx / 8;		pt[0].y = 3 * cy / 8;
			pt[1].x = 3 * cx / 8;		pt[1].y = 5 * cy / 8;
			pt[2].x = 1 * cx / 8;		pt[2].y = 4 * cy / 8;
			Triangle(pdis->hDC, pt);
			break;
		}

			// �����ť��ѡ��, ��ת��������������

		if (pdis->itemState & ODS_SELECTED)
			InvertRect(pdis->hDC, &pdis->rcItem);

			// �����ť�������뽹��, ��һ�����߿�

		if (pdis->itemState & ODS_FOCUS)
		{
			pdis->rcItem.left	+= cx / 16;
			pdis->rcItem.top	+= cy / 16;
			pdis->rcItem.right	-= cx / 16;
			pdis->rcItem.bottom	-= cy / 16;
			DrawFocusRect(pdis->hDC, &pdis->rcItem);
		}

		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}