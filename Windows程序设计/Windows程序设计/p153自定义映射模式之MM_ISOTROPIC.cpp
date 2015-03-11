// ͬ������������������, ������߱�����ʾ�豸�޹ص�ͼ��;
// Ĭ�ϵ�ӳ��ΪMM_LOMETRIC, ���ı䷶Χ��ʱ��, �µ�x, y�᷽��������SetWindowExtEx��SetViewportExtExʱx1*x2��y1*y2��ֵ���������Ǹ���
#define		SZAPPNAME	"p153�Զ���ӳ��ģʽ֮MM_ISOTROPIC"
#include				"DX_WinMain.cpp"

HDC SetMode(HWND hwnd, HDC hdc);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT		ps;
	HDC				hdc;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, CreatePen(PS_SOLID, 20, RGB(0xff, 0, 0)));
		hdc = SetMode(hwnd, hdc);

		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 0, 1000);
		MoveToEx(hdc, 1000, 0, NULL);
		LineTo(hdc, -1000, 0);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 0, -1000);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 1000, 0);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

HDC SetMode(HWND hwnd, HDC hdc)
{
	RECT rcTemp;
	GetClientRect(hwnd, &rcTemp);
	SetMapMode(hdc, MM_ISOTROPIC);

	SetWindowExtEx(hdc, 1000, 1000, NULL);  // ���߼�����ĵ�һ������(1000, 1000)��Ӧ�豸�����������(rcTemp.right, -rcTemp.bottom);
												// ͬ��, д            (-1000, -1000)                  (-rcTemp.right, rcTemp.bottom)Ч����һ����;
	SetViewportExtEx(hdc, rcTemp.right, -rcTemp.bottom, NULL);

		// �߼�����ԭ���ڿͻ������½�

	//SetWindowOrgEx(hdc, 0, 1000, NULL);  // ����д�ǲ��Ե�, �ڿ�ȴ��ڸ߶ȵ�ʱ��ᵼ���߼�ԭ�㱻̧��
	//SetViewportOrgEx(hdc, 0, rcTemp.bottom, NULL);  // ����д���ǶԵ�

		// �߼�����ԭ���ڿͻ������Ͻ�

	//SetWindowOrgEx(hdc, 0, 1000, NULL);  // ͬ��, ����ֻ������д

		// �߼�����ԭ���ڿͻ�������
	SetViewportExtEx(hdc, rcTemp.right / 2, -rcTemp.bottom / 2, NULL);  // �����������Ӧ����һ��
	SetViewportOrgEx(hdc, rcTemp.right / 2, rcTemp.bottom / 2, NULL);

	return hdc;
}