//		QQ		:	394899990
//		�ٶ�ID	:	�ж�־����
#include <windows.h>
#include <fstream>

struct DataTag
	{
		TCHAR	szLastFileName[100];	// ���һ����ȡ���ļ�������
		int     iFileNum;	// �������ļ�����
		int		iCntChar;	// �ַ���(����ʾ�Ļس�����, ע�ͳ���, �հ׷�(�ո�, tap)����)
		int		iCntLetter;	// ��ĸ��((����ʾ�Ļس�����, ע�ͳ���))
		int     iCntFuHao;	// ������(, ; / * () {} & ...)
		int		iCntRow;	// ����
		int		iDigit;		// ���������ָ���
		int		iCnHalf;	// ��ע�����ĸ���(�ַ���, �����ּ�����ĺ�(#define ����), ����...)
		int		iCnHalfAnt;	// ע�����ĸ���
		int		iCntCharAnt;// ע���ַ�����(�س�������, �����հ׷�(�ո�, tap��һ���ַ�)
	} Data = {0};
DataTag temp = {0};
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, 
				    HINSTANCE hPrevInstance, 
				    PSTR szCmdLine, int iCmdShow)
{
	TCHAR		szAppName[] = TEXT("���۴���ͳ����");
	WNDCLASS	wndclass;
	HWND		hwnd;
	MSG			message;

	wndclass.cbClsExtra			= 0;
	wndclass.cbWndExtra			= 0;
	wndclass.hbrBackground		= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance			= hInstance;
	wndclass.lpfnWndProc		= WndProc;
	wndclass.lpszClassName		= szAppName;
	wndclass.lpszMenuName		= NULL;
	wndclass.style				= CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndclass);

	hwnd = CreateWindow(szAppName, szAppName, 
						WS_OVERLAPPEDWINDOW, 
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}
void ScanFile(TCHAR * FILENAME, DataTag & Data);
void ShowData(HWND hwnd, DataTag & Data, int x = 0, int y = 0);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT		ps;
	HDC				hdc;
	static HWND		hwndList;
	static int		cxClient, cyClient;
	TCHAR			szBuffer[MAX_PATH + 1];  // ���ڱ��浱ǰĿ¼���ļ�����Ŀ¼���ļ����ȵ�

	switch (message)
	{
	case WM_CREATE:

			// �����б��

		hwndList = CreateWindow(TEXT("listbox"), NULL, WS_CHILDWINDOW | WS_VISIBLE | LBS_STANDARD/*��ʾ���ļ�������*/,
			0, 0, 0, 0,
			hwnd, (HMENU)'L', (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		
			// ���ļ�Ŀ¼�б�(��Ŀ¼�ʹ���������)д���б��

		SendMessage(hwndList, LB_DIR, DDL_READWRITE/*�ļ�����*/, (LPARAM)TEXT("*.h"));  // lParam������ָ���ļ��޶��ַ�������("*.*")��ָ��, ���ļ��޶���Ӱ���б���а�������Ŀ¼;
		SendMessage(hwndList, LB_DIR, DDL_READWRITE/*�ļ�����*/, (LPARAM)TEXT("*.c"));  // lParam������ָ���ļ��޶��ַ�������("*.*")��ָ��, ���ļ��޶���Ӱ���б���а�������Ŀ¼;
		SendMessage(hwndList, LB_DIR, DDL_READWRITE/*�ļ�����*/, (LPARAM)TEXT("*.cpp"));  // lParam������ָ���ļ��޶��ַ�������("*.*")��ָ��, ���ļ��޶���Ӱ���б���а�������Ŀ¼;

			// ��ʼͳ��
		for (int i = 0; ; i++)
		{
			if (LB_ERR == SendMessage(hwndList, LB_GETTEXT, i, (LPARAM)szBuffer))
				break;
			ScanFile(szBuffer, Data);
		}
		return 0;
	
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		MoveWindow(hwndList, 0, 0, cxClient / 4, cyClient, TRUE);

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		ShowData(hwnd, Data);	// ��ʾ�ļ����µ������ļ������ܺ�
		if (temp.iFileNum == 1)
		{
			TextOut(hdc, cxClient / 4 + 30, 245, temp.szLastFileName, lstrlen(temp.szLastFileName));
			ShowData(hwnd, temp, 0, 250);	// ��ʾѡ���ļ�������
		}
		GetCurrentDirectory(MAX_PATH + 1, szBuffer);
		lstrcat(szBuffer, TEXT("  ͳ�ƽ���..."));
		TextOut(hdc, cxClient / 4 + 30, 0, szBuffer, lstrlen(szBuffer));
		EndPaint(hwnd, &ps);
		return 0;

	case WM_COMMAND:
		int		iSelect;
		if (LOWORD(wParam) == 'L' && HIWORD(wParam) == LBN_DBLCLK)
		{
				// ��ȡ��ǰѡ���������ֵ ���û��ѡ����, ��������LB_ERR(-1)

			if (LB_ERR == (iSelect = SendMessage(hwndList, LB_GETCURSEL, 0, 0)))
				break;

				// ����ǰѡ����ı����������szBuffer  (��������p328.txt, ��ôszBuffer�б������"p328.txt", ��������Ŀ¼)

			SendMessage(hwndList, LB_GETTEXT, iSelect, (LPARAM)szBuffer);

			std::ifstream fin;
			fin.open(szBuffer);
			if (!fin.is_open())
			{
				MessageBox(hwnd, TEXT("�޷����ļ�!"), szBuffer, MB_ICONERROR | MB_OK);
				return 0;
			}
			DataTag t = {0};
			temp = t;
			ScanFile(szBuffer, temp);
			InvalidateRect(hwnd, NULL, TRUE);
			UpdateWindow(hwnd);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void ScanFile(TCHAR * FILENAME, DataTag & Data)
{
	char	ch;				// ��ʱ����ÿ����ȡ���ַ�
	enum annotation{ifAnt, isAnt, notAnt, isAnt2};
	annotation	Ant = notAnt;	// ע���ж�
		
	
		// ���ļ�, ������

	std::ifstream fin;	// �ļ��������
	fin.open(FILENAME);
	if (!fin.is_open())
	{
		MessageBox(NULL, TEXT("�����ļ��򿪴���, �����쳣�˳�!"), TEXT("Error"), MB_ICONERROR | MB_OK);
		exit(EXIT_FAILURE);
	}

		// ��ʼͳ��

	lstrcpy(Data.szLastFileName, FILENAME);
	Data.szLastFileName;
	Data.iFileNum++;
	ch = fin.get();	
	int chNum = 0;
	while (fin.good())
	{
			// ������ѭ��

		if (chNum++ >= 100000)
		{
			MessageBox(NULL, TEXT("�ļ�ͳ�Ƴ���, ��ȷ���ļ��Ǳ�׼��c/c++/h�ļ�!"), FILENAME, MB_ICONERROR | MB_OK);
			exit(EXIT_FAILURE);
		}
			// ���Ĵ���

		if ((ch > 255 || ch < 0) 
			&& isAnt != Ant && isAnt2 != Ant)	// �ų�����ע��
		{
			ch = fin.get();
			Data.iCnHalf++;
			continue;
		}

			// ͳ������
		if (ch == '\n')
			Data.iCntRow++;

			// ����ע�� "//"
		if ('/' == ch && notAnt == Ant)	// "//" ? "/" ? "/*" ? "*/"
			Ant = ifAnt;
		else if ('/' == ch && ifAnt == Ant)
			Ant = isAnt;
		else if (isAnt == Ant)
		{
			int flag = 0;
			do{	// ʹ��do-whileʹ�� "//"��ߵĵ�һ���ַ�Ҳ�ܽ����ж�
				if (ch == EOF)
				{
					flag = 1;
					break;
				}
				if (ch < 0 || ch > 255)
					Data.iCnHalfAnt++;
				else
					Data.iCntCharAnt++;
			}while('\n' != (ch = fin.get()));	// �Ե�ע��
			Data.iCntCharAnt += 2;	// "//"����Ҳ������ע���ַ�
			if (flag)
				break;
			Data.iCntRow++;	// �������е�ע��, �����������ǵü���
			Ant = notAnt;
		}

			// ����ע�� "/* */"
		else if ('*' == ch && ifAnt == Ant)
			Ant = isAnt2;
		else if (isAnt2 == Ant)
		{
			Ant = notAnt;
			int flag = 0;	// Ѱ�� "*/" �ı��
				
				// һֱɾ��ע��, ֱ��ע�ͽ���
			
			do{	// ��ֹ/*��ߵĵ�һ���ַ�������, ���Ҳ���do-while�Ļ�, /**/�����
				if (ch < 0 || ch > 255)
					Data.iCnHalfAnt++;
				else if ('*' == ch)
				{
					flag = 1;
					Data.iCntCharAnt++;
				}
				else if (flag && '/' == ch)
					break;
				else
				{
					if ('\n' == ch)	// ע�͵�����Ҳ������, ���ǲ���ע���ַ�
						Data.iCntRow++;
					else
						Data.iCntCharAnt++;
					flag = 0;
				}
			} while (ch = fin.get());
			Data.iCntCharAnt += 3;	// "/*", '/'
		}

			// ͳ���ַ�, ��ĸ����
		else if (isgraph(ch))	// �ַ�
		{
			Ant = notAnt;
			Data.iCntChar++;
			if (isalpha(ch))	// ��ĸ����
				Data.iCntLetter++;
			else if (ispunct(ch))	// ��������
				Data.iCntFuHao++;
			else if (isdigit(ch))	// ���ָ���
				Data.iDigit++;	
		}
		ch = fin.get();
	}
	Data.iCntRow++;
}

#define TEXTOUT TextOut(hdc, (rcClient.right - rcClient.left) / 4 + 30 + x, i++ * 20 + y, szBuffer, lstrlen(szBuffer))

void ShowData(HWND hwnd, DataTag & Data, int x, int y)
{
		// ���������ʾ
	static HDC	hdc = GetDC(hwnd);	// �����GetDC������hdc�Ͳ���releaseDC�ͷ���, ����ִ�������Լ��ͷŰ�, ��һ��, Ҳ��ռ�����ڴ�
	SelectObject(hdc, GetStockObject(SYSTEM_FIXED_FONT));

	int i = 1;
	TCHAR		szBuffer[512];
	RECT		rcClient;
	GetClientRect(hwnd, &rcClient);
	wsprintf(szBuffer, TEXT("ͳ�� %d ���ļ����..."), Data.iFileNum);
	TEXTOUT;
	wsprintf(szBuffer, TEXT(" ���� : %d"), Data.iCntRow);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("���ַ�: %d"), Data.iCntChar + Data.iCnHalf / 2 + Data.iCntCharAnt + Data.iCnHalfAnt / 2);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("    ��ע���ַ���: %d"),Data.iCntChar + Data.iCnHalf / 2);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        ��ĸ��: %d"), Data.iCntLetter);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        ������: %d"), Data.iCntFuHao);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        ������: %d"), Data.iDigit);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        ������: %d"), Data.iCnHalf / 2);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("    ע���ַ���: %d"), Data.iCntCharAnt + Data.iCnHalfAnt / 2);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        ������: %d"), Data.iCnHalfAnt / 2);
	TEXTOUT;
	wsprintf(szBuffer, TEXT("        �ַ���: %d"), Data.iCntCharAnt);
	TEXTOUT;
	
	/*cout << "\nͳ���ļ� "		<< FILENAME						<< " ���...\n";
	cout << " ���� : "			<< ++Data.iCntRow					<< endl;
	cout << "���ַ�: "			<< Data.iCntChar + Data.iCnHalf / 2 + Data.iCntCharAnt + Data.iCnHalfAnt / 2 << endl;
	cout << "\t��ע���ַ���: "	<< Data.iCntChar + Data.iCnHalf / 2		<< endl;
	cout << "\t\t��ĸ��: "		<< Data.iCntLetter					<< endl;
	cout << "\t\t������: "		<< Data.iCntFuHao					<< endl;
	cout << "\t\t������: "		<< Data.iDigit						<< endl;
	cout << "\t\t������: "		<< Data.iCnHalf / 2					<< endl;
	cout << "\tע���ַ���: "	<< Data.iCntCharAnt + Data.iCnHalfAnt / 2	<< endl;
	cout << "\t\t������: "		<< Data.iCnHalfAnt / 2				<< endl;
	cout << "\t\t�ַ���: "		<< Data.iCntCharAnt					<< endl;*/
}