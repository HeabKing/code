#define SZAPPNAME	"p271����ʱ��"
#define ID_TIMER	1
#include			"DX_WinMain.cpp"

void DisplayDigit(HDC hdc, int iNumber)
{
	static BOOL	fSevenSegment[10][7] ={
				1, 1, 1, 0, 1, 1, 1,  // 0
				0, 0, 1, 0, 0, 1, 0,  // 1
				1, 0, 1, 1, 1, 0, 1,  // 2
				1, 0, 1, 1, 0, 1, 1,  // 3
				0, 1, 1, 1, 0, 1, 0,  // 4
				1, 1, 0, 1, 0, 1, 1,  // 5
				1, 1, 0, 1, 1, 1, 1,  // 6
				1, 0, 1, 0, 0, 1, 0,  // 7
				1, 1, 1, 1, 1, 1, 1,  // 8
				1, 1, 1, 1, 0, 1, 1	};// 9
	static POINT ptSegment[7][6] = {
		7, 6, 11, 2, 31, 2, 35, 6, 31, 10, 11, 10,
		6, 7, 10, 11, 10, 31, 6, 35, 2, 31, 2, 11,
		36, 7, 40, 11, 40, 31, 36, 35, 32, 31, 32, 11,
		7, 36, 11, 32, 31, 32, 35, 36, 31, 40, 11, 40,
		6, 37, 10, 41, 10, 61, 6, 65, 2, 61, 2, 41,
		36, 37, 40, 41, 40, 61, 36, 65, 32, 61, 32, 41,
		7, 66, 11, 62, 31, 62, 35, 66, 31, 70, 11, 70 };
	int iSeg;	
	for (iSeg = 0; iSeg < 7; iSeg++)
		if (fSevenSegment[iNumber][iSeg])
			Polygon(hdc, ptSegment[iSeg], 6);
}

void DisplayTwoDigits(HDC hdc, int iNumber, BOOL fSuppress)  // ����������
{
	if (!fSuppress || (iNumber / 10 != 0))
		DisplayDigit(hdc, iNumber / 10);
	OffsetWindowOrgEx(hdc, -42, 0, NULL);  // ԭ�����������ߵ����ֵ����Ͻ�, OffsetWindowOrgEx�����ɴ��ڵ�ԭ�������ƶ�42����λ, ����, ��������ʹ��ͬ���������������ֺ�ð��, ���ܸ�ͼ���ڴ��ڵ�ʵ��λ������;
	DisplayDigit(hdc, iNumber % 10);
	OffsetWindowOrgEx(hdc, -42, 0, NULL);
}

void DisplayColon(HDC hdc)  // ��ð��
{
	POINT ptColon[2][4] = {2, 21, 6, 17, 10, 21, 6, 25,
							2, 51, 6, 47, 10, 51, 6, 55};

	Polygon(hdc, ptColon[0], 4);
	Polygon(hdc, ptColon[1], 4);

	OffsetWindowOrgEx(hdc, -12, 0, NULL);
}

void DisplayTime(HDC hdc, BOOL f24Hour, BOOL fSuppress)
{
	SYSTEMTIME	st;

	GetLocalTime(&st);  // GetLocalTime��ȡ����ʱ��, GetSystemTime��������ʱ��(�������α�׼ʱ��);

	if (f24Hour)
		DisplayTwoDigits(hdc, st.wHour, fSuppress);
	else
		DisplayTwoDigits(hdc, (st.wHour %= 12) ? st.wHour : 12, fSuppress);

	DisplayColon(hdc);
	DisplayTwoDigits(hdc, st.wMinute, FALSE);
	DisplayColon(hdc);
	DisplayTwoDigits(hdc, st.wSecond, FALSE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static BOOL		f24Hour, fSuppress;
	static HBRUSH	hBrushRed;
	static int		cxClient, cyClient;
	HDC				hdc;
	PAINTSTRUCT		ps;
	TCHAR			szBuffer[2];  // szBuffer[1]���ڱ���'\0'

	switch (message)
	{
	case WM_CREATE:
		hBrushRed = CreateSolidBrush(RGB(255, 0, 0));
		SetTimer(hwnd, ID_TIMER, 1000, NULL);

												// fall through

	case WM_SETTINGCHANGE:  // �û��ı����κ�ϵͳ����

		// GetLocalInfo���ַ�������ʽ����������Ϣ
		GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_ITIME, szBuffer, 2);  // ȷ����12Сʱ��24Сʱ��ʽ
		f24Hour = (szBuffer[0] == '1');

		GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_ITLZERO, szBuffer, 2);  // ȥ��Сʱ��ͷΪ0�����
		fSuppress = (szBuffer[0] == '0');

		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	case WM_TIMER:
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetMapMode(hdc, MM_ISOTROPIC);  // ��ӳ��ģʽ�ĳ�MM_ISOTROPIC, ��������ʹ������̶ȵ�������, ����������ˮƽ����ʹ�ֱ����Ŀ̶�����ȵ�(�̶���SetWindowExtEx����);
		// ����SetWIndowExtEx����ʱ, �Ѳ����趨Ϊ�����õ����߼����ڵ��߼���С;
		// ����SetViewportExtEx����, �Ѳ����趨Ϊʵ�ʵĸ߶ȺͿ��;
		SetWindowExtEx(hdc, 276, 72, NULL);	// ���ÿ̶�, ˮƽ276����λ, ��ֱ72����λ(��ʱ�����ֵĳߴ�ͼ�����);
												// ������42����λ��, ð����12����λ��, 6 * 42 + 12 * 2 = 276
		SetViewportExtEx(hdc, cxClient, cyClient, NULL);

		SetWindowOrgEx(hdc, 138, 36, NULL);  // ������ԭ��������(138, 36)��, ���Ǵ������������;
		SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);  // �����ӿ�ԭ��ΪcxClient/2, cyClient/2, ����ζ��ʱ�ӻ���ʾ�ڿͻ���������;
		SelectObject(hdc, hBrushRed);

		DisplayTime(hdc, f24Hour, fSuppress);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, ID_TIMER);
		DeleteObject(hBrushRed);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}