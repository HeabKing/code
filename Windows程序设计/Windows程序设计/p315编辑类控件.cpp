#define	SZAPPNAME	"p315�༭��ؼ�"
#define ID_EDIT		1
#include			"DX_WinMain.cpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndEdit;

	switch (message)
	{
	case WM_CREATE:
		hwndEdit = CreateWindow(TEXT("edit"), NULL, 
			WS_CHILD | WS_VISIBLE | 
			WS_HSCROLL | WS_VSCROLL | // ���ӱ༭�ؼ�������
			WS_BORDER | // Ĭ�������, һ���༭�ؼ� ��û�б߿��, ����������ӱ߿�
			ES_LEFT | // �༭�ؼ��е��ı���ʽ
			ES_MULTILINE | // Ĭ�������, һ���༭�ؼ�ֻ��һ��, ������ES_MULTILINE����һ�����б༭�ռ�
			ES_AUTOHSCROLL |  // ����һ�������Զ�ˮƽ�����ı༭�ؼ� 
			ES_AUTOVSCROLL,
			0, 0, 0, 0, hwnd, (HMENU)ID_EDIT,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		return 0;

	case WM_SETFOCUS:
		SetFocus(hwndEdit);
		return 0;

	case WM_SIZE:
		MoveWindow(hwndEdit, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);
		return 0;

	case WM_COMMAND:
		if (LOWORD(wParam) == ID_EDIT)
			if (HIWORD(wParam) == EN_ERRSPACE ||  // �༭�ؼ�û�пռ���
				HIWORD(wParam) == EN_MAXTEXT)  // �༭�ؼ�û�пռ���ɲ�����
				MessageBox(hwnd, TEXT("�ı��ؼ�վ������ô������"), TEXT(SZAPPNAME), MB_OK | MB_ICONSTOP);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}