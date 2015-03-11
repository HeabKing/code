#define SZAPPNAME "p158 ���ֶ���ģʽ��ʾ���ڿͻ���.cpp"
#include "DX_WinMain.cpp"

void Show(HWND hwnd, HDC hdc, int xText, int yText, int iMapMode, TCHAR * szMapMode)
{
	TCHAR szBuffer[60];
	RECT  rect;

	SaveDC(hdc);  // idSaved = SavedDC(hdc);  �����豸����
	SetMapMode(hdc, iMapMode);
	// ӳ��ģʽ���豸�������Ե�һ����, ����ֻ��ʹ�����豸���������Ϊ������GDI�����Ż�ʹ��ӳ��ģʽ��Ч
	GetClientRect(hwnd, &rect);  // ����û��ʹ��hdc, ���������������豸��λ(����)����ʽִ��;
	// rect.right�ǿͻ����Ŀ��, rect.bottom�ǿͻ����ĸ߶�;
	DPtoLP(hdc, (PPOINT)&rect, 2);  // ���豸��λת�����߼���λ ��ת���ĵ�ĸ�����2 �����2ָ�����������㼴����x, y
	RestoreDC(hdc, -1);  // RestoreDC(hdc, idSaved);  ��ԭ�豸���� -1ʹ���豸������ԭ�����һ��ʹ��SaveDC���������״̬;

	TextOut(hdc, xText, yText, szBuffer, wsprintf(szBuffer, TEXT("%-20s %7d %7d %7d %7d"), szMapMode, rect.left, rect.right, rect.top, rect.bottom));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static TCHAR szHeading[] = TEXT("        Mapping Mode      Left   Right    Top Bottom");
	static TCHAR szUndLine[] = TEXT("------------------------- --- ----------- --- ------");
	static int   cxChar, cyChar;
	HDC          hdc;
	PAINTSTRUCT  ps;
	TEXTMETRIC   tm;

	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);

		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));  // ʹ�õȿ�����, windows3.0֮ǰϵͳ�ȿ�������Ĭ������
		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight + tm.tmExternalLeading;

		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
		// ֻ��MM_ISOTROPIC(����ͬ��)��MM_ANISOTROPIC(��������)����ģʽ����ı��ӿںʹ��ڷ�Χ;
		SetMapMode(hdc, MM_ANISOTROPIC);  // MM_ANISOTROPICӳ��ģʽ�����ϵ��߼���λ����Ϊ�ֺ�;
		SetWindowExtEx(hdc, 1, 1, NULL);
		SetViewportExtEx(hdc, cxChar, cyChar, NULL);

		TextOut(hdc, 1, 1, szHeading, lstrlen(szHeading));
		TextOut(hdc, 1, 2, szUndLine, lstrlen(szUndLine));

		Show(hwnd, hdc, 1, 3, MM_TEXT, TEXT("TEXT(pixes)"));
		Show(hwnd, hdc, 1, 4, MM_LOMETRIC, TEXT("LOMETRIC(.1 mm)"));
		Show(hwnd, hdc, 1, 5, MM_HIMETRIC, TEXT("HIMETRIC(.01 mm)"));
		Show(hwnd, hdc, 1, 6, MM_LOENGLISH, TEXT("LOENGLISH(.01 in)"));
		Show(hwnd, hdc, 1, 7, MM_HIENGLISH, TEXT("HIENGLISH(.001 in)"));
		Show(hwnd, hdc, 1, 8, MM_TWIPS, TEXT("TWIPS(1/1440 in)"));

		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}