// ?????????????????????????????δ���?????????????????????????

// Ĭ��ӳ��ģʽ ӳ��ģʽ������ ӳ��ģʽ�Ĳ鿴
// Ĭ��ӳ��ģʽ��MM_TEXT, ����ӳ��ģʽ��, �߼���λ������λ��ͬ, ����������ֱ��������Ϊ��λ����;
#define SZAPPNAME "p145 Ĭ��ӳ��ģʽ.cpp"
#include "DX_WinMain.cpp"
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC         hdc;
	int         iMapMode;
	TCHAR       szBuffer[100];
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		// Ĭ�ϵ�WM_TEXTӳ��ģʽ��, �߼���λ��pixel;
		TextOut(hdc, 96, 96, TEXT("MM_TEXT: 96px, 96px"), lstrlen(TEXT("MM_TEXT: 96px, 96px")));

		// MM_LOENGLISH �;���Ӣ��ӳ��ģʽ��, �߼���λ��0.01in.;
		iMapMode = GetMapMode(hdc);
		SetMapMode(hdc, MM_LOENGLISH);
		TextOut(hdc, 100, -100, TEXT("MM_LOENGLISH: 100in., -100in."), lstrlen(TEXT("MM_LOENGLISH: 100in., -100in.")));
		SetMapMode(hdc, iMapMode);
		TextOut(hdc, 0, 0, szBuffer, wsprintf(szBuffer, TEXT("%d"), GetDeviceCaps(hdc, HORZRES) / GetDeviceCaps(hdc, HORZSIZE)));
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}