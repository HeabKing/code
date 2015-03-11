#define SZAPPNAME		"p215 �ı��༭���ĳ���"
#define BUFFER(x, y)	*(pBuffer + y * cxBuffer + x)
#include				"DX_WinMain.cpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static DWORD	dwCharSet	= DEFAULT_CHARSET;
	static int		cxChar, cyChar, cxClient, cyClient, cxBuffer, cyBuffer, xCaret, yCaret;
	static TCHAR *	pBuffer		= NULL;

	HDC				hdc;
	int				x, y, i;
	PAINTSTRUCT		ps;
	TEXTMETRIC		tm;

	switch (message)
	{
	case WM_INPUTLANGCHANGE:  // ֻҪ��ʹ������֪ͨ����ĵ����˵��ı��˼��̲���, windows�ͻ��WM_INPUTLANGCHANGE��Ϣ���ݸ���Ĵ��ڹ���
		dwCharSet = wParam;
		
	case WM_CREATE:
		hdc = GetDC(hwnd);

		SelectObject(hdc, CreateFont(0, 0, 0, 0, 0, 0, 0, 0, 
			dwCharSet, 0, 0, 0, FIXED_PITCH, NULL));

		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight;

		DeleteObject(SelectObject(hdc, GetStockObject(SYSTEM_FONT)));
		ReleaseDC(hwnd, hdc);

	case WM_SIZE:

								// ��ȡ��Ļ���ش�С

		if (message == WM_SIZE)
		{
			cxClient = LOWORD(lParam);
			cyClient = HIWORD(lParam);
		}

		cxBuffer = max(1, cxClient / cxChar);  // �ͻ������Ա���ĵȿ���������
		cyBuffer = max(1, cyClient / cyChar);  // �ͻ������Ա���ĵȿ���������

								// ��Buffer��������ڴ�

		if (pBuffer != NULL)
			free(pBuffer);

		pBuffer = (TCHAR *)malloc(cxBuffer * cyBuffer * sizeof(TCHAR));

		for (y = 0; y < cyBuffer; y++)
			for (x = 0; x < cxBuffer; x++)
				BUFFER(x, y) = '_';

								// ���ò������

		xCaret = 0;
		yCaret = 0;

		if (hwnd == GetFocus())  // ��ȡ���뽹�㴰��
			SetCaretPos(xCaret * cxChar, cyChar * yCaret);  // ���ò������λ��

		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_SETFOCUS:
								// ��������ʾ�������

		CreateCaret(hwnd, NULL, cxChar, cyChar);
		SetCaretPos(xCaret * cxChar, yCaret * cyChar);
		ShowCaret(hwnd);

		return 0;

	case WM_KILLFOCUS:
								// ���غ����ٲ������

		HideCaret(hwnd);
		DestroyCaret();
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_HOME:
			xCaret = 0;
			break;

		case VK_END:
			xCaret = cxBuffer - 1;
			break;

		case VK_PRIOR:
			yCaret = 0;
			break;

		case VK_NEXT:
			yCaret = cyBuffer - 1;
			break;

		case VK_LEFT:
			xCaret = max(xCaret - 1, 0);
			break;

		case VK_RIGHT:
			xCaret = min(xCaret + 1, cxBuffer - 1);
			break;

		case VK_UP:
			yCaret = max(yCaret - 1, 0);
			break;

		case VK_DOWN:
			yCaret = max(yCaret + 1, cyBuffer - 1);
			break;

		case VK_DELETE:
			for (x = xCaret; x < cxBuffer - 1; x++)
				BUFFER(x, yCaret) = BUFFER(x + 1, yCaret);

			BUFFER(cxBuffer - 1, yCaret) = 'L';
			
			HideCaret(hwnd);
			hdc = GetDC(hwnd);

			SelectObject(hdc, CreateFont(0, 0, 0, 0, 0, 0, 0, 0,
				dwCharSet, 0, 0, 0, FIXED_PITCH, NULL));
			TextOut(hdc, xCaret * cxChar, yCaret * cyChar, &BUFFER(xCaret, yCaret), cxBuffer - xCaret);
			
			DeleteObject(SelectObject(hdc, GetStockObject(SYSTEM_FONT)));
			ReleaseDC(hwnd, hdc);
			ShowCaret(hwnd);
			break;
		}
		SetCaretPos(xCaret * cxChar, yCaret * cyChar);
		return 0;

	case WM_CHAR:
		for (i = 0; i < (int)LOWORD(lParam); i++)
		{
			switch (wParam)
			{
			case '\b':
				if (xCaret > 0)
				{
					xCaret--;
					SendMessage(hwnd, WM_KEYDOWN, VK_DELETE, 1);
				}
				break;

			case '\t':
				do
				{
					SendMessage(hwnd, WM_CHAR, ' ', 1);
				}while (xCaret % 8 != 0);

			case '\n':
				if (++yCaret == cyBuffer)
					yCaret = 0;
				break;
				
			case '\r':
				xCaret = 0;
				if (++yCaret == cyBuffer)
					yCaret = 0;
				break;

			case '\x1B':  // escape
				for (y = 0; y < cyBuffer; y++)
					for (x = 0; x < cxBuffer; x++)
						BUFFER(x, y) = ' ';

				xCaret = 0;
				yCaret = 0;

				InvalidateRect(hwnd, NULL, FALSE);  // FALSE????? ʹ�������ͻ�����Ч, ���ǲ������ñ�����ˢͿ��ԭ��������, ֱ��д�µ�;
				break;

			default:  // character codes
				BUFFER(xCaret, yCaret) = (TCHAR)wParam;

				HideCaret(hwnd);  // ������ڹ��̴������һ����WM_PAINT��Ϣ, ����Ҫ�ڴ����л���ĳЩ������ʱ��, �������HideCaret���ز������, �����ڴ����ڵĻ��ƽ������ٵ���ShowCaret����ʾ�������.
				hdc = GetDC(hwnd);
				SelectObject(hdc, CreateFont(0, 0, 0, 0, 0, 0, 0, 0,
					dwCharSet, 0, 0, 0, FIXED_PITCH, NULL));
				TextOut(hdc, xCaret * cxChar, yCaret * cyChar, &BUFFER(xCaret, yCaret), 1);

				DeleteObject(SelectObject(hdc, GetStockObject(SYSTEM_FONT)));
				ReleaseDC(hwnd, hdc);
				ShowCaret(hwnd);

				if (++xCaret == cxBuffer)
				{
					xCaret = 0;
					if (++yCaret == cxBuffer)
						yCaret = 0;
				}
				break;
			}
		}
		SetCaretPos(xCaret * cxChar, yCaret * cyChar);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, CreateFont(0, 0, 0, 0, 0, 0, 0, 0,
			dwCharSet, 0, 0, 0, FIXED_PITCH, NULL));

		for (y = 0; y < cyBuffer; y++)
			TextOut(hdc, 0, y * cyChar, &BUFFER(0, y), cxBuffer);
			
		DeleteObject(SelectObject(hdc, GetStockObject(SYSTEM_FONT)));
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}