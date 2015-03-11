#define		SZAPPNAME	"p233���в���"	
#define		DIVISIONS	5
#include	"DX_WinMain.cpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool		fState[DIVISIONS][DIVISIONS];  // �����״̬
	static int		cxBlock, cyBlock;  // һ������ĳ��Ⱥ͸߶�
	HDC				hdc;
	int				x, y;
	PAINTSTRUCT		ps;
	RECT			rect;

	switch (message)
	{
	case WM_SIZE:
		cxBlock = LOWORD(lParam) / DIVISIONS;
		cyBlock = HIWORD(lParam) / DIVISIONS;
		return 0;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam) / cxBlock;
		y = HIWORD(lParam) / cyBlock;

		if (x < DIVISIONS && y < DIVISIONS)
		{
			fState[x][y] ^= 1;  // ��λ���(Xor)

			rect.left	= x * cxBlock - 20;
			rect.top	= y * cyBlock - 20;
			rect.right	= (x + 1) * cxBlock - 20;
			rect.bottom	= (y + 1) * cyBlock - 20;

			InvalidateRect(hwnd, &rect, FALSE);  // ����FALSE��TRUE������???????????? ����д��FALSE��ʾ�����򲻽��б�����ˢ����, ����WM_PAINT�е�Rectangle���Ƶľ��ο�Ĭ���ڲ������ɫ(��ɫ)���ڲ��ĶԽ��߸�������;
		}
		else
			MessageBeep(0);  // ����ͻ����Ŀ�Ȼ�߶Ȳ��ܱ�5����, �ͻ�������߻�ײ��ͻ����һ��С��������, ���ᱻ���θ���, ����ʵ����һ��������, ����굥����Ƭ�����ʱ��, ��������MessageBeep����������Ӧ;
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		for (x = 0; x < DIVISIONS; x++)
			for (y = 0; y < DIVISIONS; y++)
			{
				Rectangle(hdc, x * cxBlock, y * cyBlock, (x + 1) * cxBlock, (y + 1) * cyBlock);

				if (fState[x][y])
				{
					MoveToEx	(hdc, x * cxBlock, y * cyBlock, NULL);
					LineTo		(hdc, (x + 1) * cxBlock, (y + 1) * cyBlock);
					MoveToEx	(hdc, x * cxBlock, (y + 1) * cyBlock, NULL);
					LineTo		(hdc, (x + 1) * cxBlock, y * cyBlock);
				}
			}

		EndPaint(hwnd, &ps);
		return 0;

	case WM_CLOSE:
		if (MessageBox(hwnd, TEXT("ȷ���˳�?"), TEXT("�˳�"), MB_YESNO) != IDYES)
			return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}