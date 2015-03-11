// 1. ��δ���һ���б��
// 2. �������б����ı���Ŀ
// 3. ��ν��������б�����Ϣ
// 4. �����ȡ�ַ���
#define SZAPPNAME	"p324�򵥵��б�����"
#define CHANGEWNDCLASS
#define ID_LIST		1
#define ID_TEXT		2
#include			"DX_WinMain.cpp"

	// �������ڵ�Ĭ��WHITE_BRUSH����

void ChangeWndClass(WNDCLASS * pwndclass)
{
	pwndclass->hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
}

	// ��ȡ�����������ַ���, �������������ַ������ݷŵ��б����

void FillListBox(HWND hwndList)
{
	int			iLength;
	TCHAR *		pVarBlock, * pVarBeg, * pVarEnd, * pVarName;

	pVarBlock = GetEnvironmentStrings();  // ��ȡһ��ָ���ڴ���ָ��, ���ڴ���д������л������������ƺ�ֵ;
	//MessageBox(NULL, pVarBlock, NULL, MB_OK);
	while (*pVarBlock)
	{
		if (*pVarBlock != '=')  // Skip variable ������'='��ͷ
		{
			pVarBeg = pVarBlock;  // ����VarBlock���ڴ�Ŀ�ʼλ��
			while(*pVarBlock++ != '=');
			pVarEnd = pVarBlock - 1;  // ָ��'='���� ����VarBlock�ڴ����λ�ú�ߵ�'='
			iLength = pVarEnd - pVarBeg;  // VarBlock�ж��ٸ�TCHAR�ڴ��С

				// ������������ռ�, ������������ֵ�����������ַ���'\0'��β

			pVarName = (TCHAR *)calloc(iLength + 1, sizeof(TCHAR));
			CopyMemory(pVarName, pVarBeg, iLength * sizeof(TCHAR));
			pVarName[iLength] = '\0';

				// �ѱ������Ž��б��, �ͷ��ڴ�

			SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)pVarName);
			free(pVarName);
		}
		while(*pVarBlock++ != '\0');
	}
	//FreeEnvironmentStrings(pVarBlock);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND		hwndList, hwndText;
	int				iIndex, iLength, cxChar, cyChar;
	TCHAR			* pVarName, * pVarValue;

	switch (message)
	{
	case WM_CREATE:
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

			// �����б��;�̬�ı���

		hwndList = CreateWindow(TEXT("listbox"), NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, 
			cxChar, cyChar * 3, cxChar * 16 + GetSystemMetrics(SM_CXVSCROLL),
			cyChar * 5, 
			hwnd, (HMENU)ID_LIST, 
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

		hwndText = CreateWindow(TEXT("static"), NULL,
			WS_CHILD | WS_VISIBLE | SS_LEFT,
			cxChar, cyChar,
			GetSystemMetrics(SM_CXSCREEN), cyChar,
			hwnd, (HMENU)ID_TEXT, 
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

			// �������������ݷŵ��б��

		FillListBox(hwndList);
		return 0;

	case WM_SETFOCUS:
		SetFocus(hwndList);
		return 0;

	case WM_COMMAND:
		if (LOWORD(wParam) == ID_LIST/*�б�����ID*/ && HIWORD(wParam) == LBN_SELCHANGE)
		{

				// ��ȡ��ǰѡ��, �õ�ѡ����Ŀ���ı�(��������������), ���浽pVarName��

			iIndex		= SendMessage(hwndList, LB_GETCURSEL, 0, 0);
			iLength		= SendMessage(hwndList, LB_GETTEXTLEN, iIndex, 0) + 1;
			pVarName	= (TCHAR *)calloc(iLength, sizeof(TCHAR));
			SendMessage(hwndList, LB_GETTEXT, iIndex, (LPARAM)pVarName);  // ʹ��LB_GETTEXT�õ�ѡ������ı�, ����������������;

				// ��ȡ�����������Ӧ�Ļ����ַ���
			 
			iLength		= GetEnvironmentVariable(pVarName, NULL, 0);  // ʹ��GetEnvironmentVariable��û����������Ӧ�Ļ����ַ���
			pVarValue	= (TCHAR *)calloc(iLength, sizeof(TCHAR));
			GetEnvironmentVariable(pVarName, pVarValue, iLength);

				// �ھ�̬�ı�������ʾ�����ַ���

			SetWindowText(hwndText, pVarValue);  // ��ʹ��SetWindowText������ַ����͵���̬�Ӵ��ڿؼ���ȥ��ʾ
			free(pVarName);
			free(pVarValue);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}