#define SZAPPNAME	"p328�б���µ�HEAD����"
#define CHANGEWNDCLASS
#define CHANGECREATEWINDOW
#define ID_LIST		1
#define ID_TEXT		2
#define MAXREAD		8129
#define DIRATTR		(DDL_READWRITE/*��ͨ�ļ�*/ | DDL_READONLY/*ֻ���ļ�*/ | DDL_HIDDEN/*�����ļ�*/ | DDL_SYSTEM/*ϵͳ�ļ�*/ | DDL_DIRECTORY/*��Ŀ¼*/ | DDL_ARCHIVE/*�����˴浵λ���ļ�*/ | DDL_DRIVES/*�����������ַ�*/)  /*DDL_EXCLUSIVE ֻ����ָ����ֵ*/ /*DDL: dialog directory list(�Ի���Ŀ¼�б�)*/
#define DTFLAGS		(DT_WORDBREAK | DT_EXPANDTABS | DT_NOCLIP | DT_NOPREFIX)
#include			"DX_WinMain.cpp"

WNDPROC OldList;

void ChangeWndClass(WNDCLASS * wndclass)
{
	wndclass->hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
}

HWND ChangeCreateWindow(HINSTANCE hInstance)
{
	return CreateWindow(TEXT(SZAPPNAME), TEXT(SZAPPNAME), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
}

LRESULT CALLBACK ListProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static BOOL		bValidFile;
	static BYTE		buffer[MAXREAD];  // ���ڱ����ļ��е�����
	static HWND		hwndList, hwndText;
	static TCHAR	szFile[MAX_PATH + 1];
	static RECT		rect;  // ������ʾ�ļ������ݵ�����
	HANDLE			hFile;
	HDC				hdc;
	int				i, cxChar, cyChar;
	PAINTSTRUCT		ps;
	TCHAR			szBuffer[MAX_PATH + 1];  // ���ڱ��浱ǰĿ¼���ļ�����Ŀ¼���ļ����ȵ�

	switch (message)
	{
	case WM_CREATE:
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

		rect.left = 20 * cxChar;
		rect.top  = 3  * cyChar;

			// �����б��

		hwndList = CreateWindow(TEXT("listbox"), NULL, WS_CHILDWINDOW | WS_VISIBLE | LBS_STANDARD/*��ʾ���ļ�������*/,
			cxChar, cyChar * 3, 
			cxChar * 13 + GetSystemMetrics(SM_CXVSCROLL), cyChar * 10,
			hwnd, (HMENU)ID_LIST, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

			// ��ȡ��ǰĿ¼

		GetCurrentDirectory(MAX_PATH + 1, szBuffer);  // ����ǳ���ոտ�ʼִ�е�ʱ��Ĭ����ʾ������
		//MessageBox(NULL, szBuffer, NULL, NULL);

			// �����ı���

		hwndText = CreateWindow(TEXT("static"), 
			szBuffer, // ����ʼ��ʱ����ʾ�� �������Ŀ¼λ��
			WS_CHILDWINDOW | WS_VISIBLE | SS_LEFT,
			cxChar, cyChar, cxChar * MAX_PATH, cyChar, 
			hwnd, (HMENU)ID_TEXT, 
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

			// ���µĴ��ڹ����滻�б��ԭ���Ĵ��ڹ���

		OldList = (WNDPROC)SetWindowLong(hwndList, GWL_WNDPROC, (LPARAM)ListProc);

			// ���ļ�Ŀ¼�б�(��Ŀ¼�ʹ���������)д���б��

		SendMessage(hwndList, LB_DIR, DIRATTR/*�ļ�����*/, (LPARAM)TEXT("*.*"));  // lParam������ָ���ļ��޶��ַ�������("*.*")��ָ��, ���ļ��޶���Ӱ���б���а�������Ŀ¼;
		return 0;

	case WM_SIZE:
		rect.right		= LOWORD(lParam);
		rect.bottom		= HIWORD(lParam);

				// ����֤ʵrect��λ�� - ������ʾ�ļ������ݵ�����

		FrameRect(GetDC(hwnd), &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		return 0;

	case WM_SETFOCUS:
		SetFocus(hwndList);
		return 0;

	case WM_COMMAND:
		if (LOWORD(wParam) == ID_LIST && HIWORD(wParam) == LBN_DBLCLK)
		{

				// ��ȡ��ǰѡ���������ֵ ���û��ѡ����, ��������LB_ERR(-1)

			if (LB_ERR == (i = SendMessage(hwndList, LB_GETCURSEL, 0, 0)))
				break;

				// ����ǰѡ����ı����������szBuffer  (��������p328.txt, ��ôszBuffer�б������"p328.txt", ��������Ŀ¼)

			SendMessage(hwndList, LB_GETTEXT, i, (LPARAM)szBuffer);

				// ���ѡ������һ���ļ��Ļ�

			if (INVALID_HANDLE_VALUE != (hFile = CreateFile(szBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)))
			{  // valid ��Ч��               //  CreateFile���������ļ��ľ��, ����ļ�����������ݸ�Windows����ReadFile��CloseHandle;
			   // invalid ��Ч��        	  // CreateFile����б��е�ѡ����, ������ش���, ����ѡ�еĲ���һ���ļ�, ������һ����Ŀ¼

					// �ر��ļ����
				CloseHandle(hFile);

					// ��һ����Ч���ļ�
				bValidFile = TRUE;

					// ���ļ�Ŀ¼+���ָ��Ƹ�szFile
				lstrcpy(szFile, szBuffer);

					// ��ȡ��ǰ�ļ�Ŀ¼
				GetCurrentDirectory(MAX_PATH + 1, szBuffer);

					// ��ֹĿ¼����һ���ַ�����'\'�ַ�
				if (szBuffer[lstrlen(szBuffer) - 1] != '\\')
					lstrcat(szBuffer, TEXT("\\"));

					// ���ļ�Ŀ¼���ļ����ּӵ�һ��, �ŵ���̬�ı�����
				SetWindowText(hwndText, lstrcat(szBuffer, szFile));
			}

				// �������һ����Ч�ļ�, ��ô������һ��Ŀ¼������һ��������	
	 
			else
			{
					// ����һ����Ч�ļ�
				bValidFile = FALSE;

					// ��ѡ���ı����һ��']'�ĳ�'\0'
					// �����Ŀ¼: "[windows�������]" ����ļ������ĳ��� "[windows�������\0"
					// ���������: "[-g-]" ��������̸ĳ��� "[-g-\0"

				szBuffer[lstrlen(szBuffer) - 1] = '\0';

					// if�е�SetCurrentDirectory����, �����һ����Ŀ¼, ֱ�Ӵ�, �������ifѭ��
					// �����һ������, ��ô����if, �򿪵�������
					// �����ѡ����������, ��ô��SetCurrentDirectory�����������

				if (!SetCurrentDirectory(szBuffer + 1))
				{
					szBuffer[3] = ':';
					szBuffer[4] = '\0';
					SetCurrentDirectory(szBuffer + 2);  // szBuffer����������Ļ��ַ�����"[-g-\0", ����Ĳ��轫���ĳ���"[-g:\0", szBuffer������"g:"
				}

					// ��ȡ�µ�Ŀ¼��, Ȼ��������ı���

				GetCurrentDirectory(MAX_PATH + 1, szBuffer);
				SetWindowText(hwndText, szBuffer);
						// ��������
				SendMessage(hwndList, LB_RESETCONTENT, 0, 0);
						// ѡ�����ʾ���ļ�������
				SendMessage(hwndList, LB_DIR, DIRATTR, (LPARAM)TEXT("*.*"));
			}
			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;

	case WM_PAINT:

			// ���������Ч�ļ�, ֱ���˳�

		if (!bValidFile)  
			break;

			// ���һ��, �������Ч�ļ�, ֱ���˳�

		if (INVALID_HANDLE_VALUE == (hFile = CreateFile(szFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)))
		{
			bValidFile = FALSE;
			break;
		}

			// �������Ч�ļ�, ��ô���ж�ȡ, �����ݱ��浽buffer��, i������buffer�е�λ��

		ReadFile(hFile, buffer, MAXREAD, (LPDWORD)&i, NULL);
		CloseHandle(hFile);

			// Ϊ�ı���������豸����

		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));
		SetTextColor(hdc, GetSysColor(COLOR_BTNTEXT));
		SetBkColor(hdc, GetSysColor(COLOR_BTNFACE));

			// Assume the file is ASCII

		DrawTextA(hdc, (LPCSTR)buffer, i, &rect, DTFLAGS);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK ListProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_KEYDOWN && wParam == VK_RETURN)
		SendMessage(GetParent(hwnd), WM_COMMAND, MAKELONG(1, LBN_DBLCLK), (LPARAM)hwnd);
	
	return CallWindowProc(OldList, hwnd, message, wParam, lParam);
}