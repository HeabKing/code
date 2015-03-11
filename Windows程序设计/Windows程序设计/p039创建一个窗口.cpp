
// 1. ����������, ����ֵ    2. register����    3. ���ڴ�Create����(���ش��ھ��)    4. ����ʾ��show����    5. update����

// MSG ��Ϣ�ṹ WNDCLASS ������ṹ PAINTSTRUCT ���ƽṹ RECT ���νṹ
// HINSTANCE ʵ�����-������ HWND ���ھ�� HDC �豸�������

#include <windows.h>
#pragma comment(lib, "WINMM.LIB")  // ��֤PlaySound()����ִ�� #pragma��������ָ������Դ������

// ���ڹ��̺��� ����������ᴦ��������Ϊ������Ĵ��ڵ�������Ϣ, ��������Ǵ����ഴ����, ������ָ���˴��ڹ���, ���˴����ഴ���Ķ�����ڶ�������һ�����ڹ���;
// ���ڹ��̵�ǰ�ĸ��ֶ�����MSG�ṹ�Ķ�ǰ�ĸ��ֶ�һһ��Ӧ��
LRESULT /*�ȼ���LONG*/ CALLBACK /*WndProc����������*/ WndProc(HWND,  // ��MSG�ṹ�ĵ�һ��������Ӧ ������Ϣ�Ĵ��ڵľ��, ����CreatWindow�������صľ����ͬ
													  UINT,  // ��MSG�ṹ�ĵڶ�������message��Ӧ, ��һ����ʾ��Ϣ������
													  WPARAM, LPARAM);  // ���������������ṩ����Ϣ���ӷḻ����Ϣ

int WINAPI /*WinMain����������*/ WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, // PSTR ��ʾһ��ָ��ǿ��ַ�����ָ��, ��char*
				   int iCmdShow)  // �ò��������Ŵ�������Ļ�ϳ�ʼ��ʾ����ʽ(����/���/��С��)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND       hwnd;
	MSG        msg;
	WNDCLASS   wndclass;  // ������ȷ���˴�������Ϣ�Ĵ��ڹ���

	wndclass.style         = CS_HREDRAW | CS_VREDRAW;  // ���ۺ�ʱ���ڵ�ˮƽ�ߴ�(CS_HREDRAW)��ֱ�ߴ�(CS_VREDRAW)���ı�, ���л��ڸô�����Ĵ��ڶ��������»��� ֻҪ�ߴ�ı�, ����ʹ !��������! ʧЧ, Ȼ��ͷ���WM_PAINT�����ػ�
							// ���ﵱ�ߴ�ı��ʱ����ʹ�ͻ�����Ч����ʹ !����������Ч!;

	// ���ڸô���������д��ڵĴ��ڹ��̵ĵ�ַ
	wndclass.lpfnWndProc   = WndProc;  // lpfn(long pointer to a function ָ�����ĳ�ָ��)
	
	wndclass.cbWndExtra    = 0;  // cb��ʾ�ֽ���, �����ʾ����������Ա�����Ϊһ��"�ֽ���"
	wndclass.cbClsExtra    = 0;
	wndclass.hInstance     = hInstance;  // ��ʾӦ�ó����ʵ�����
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION/*IDI(ID for an icon)*/);  // Ϊ���л��ڸô�����Ĵ����趨һ��ͼ�� Ϊ�˻�ȡԤ����ͼ��ľ��, ��Ҫ���ú���LoadIcon, ���������ĵ�һ��������ΪNULL LoadIcon���ظ�ͼ��ľ��
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);  // ���������, �Թ�����ʹ��
	wndclass.hbrBackground /*hbr��ʾ"��ˢ�ľ��"(handle to a brush)*/ = (HBRUSH)GetStockObject(WHITE_BRUSH);  // ��ȡһ��ͼ�ζ���. ������һ�������Դ��ڵı��������ػ�Ļ�ˢ
	wndclass.lpszMenuName  = NULL;
	wndclass.lpszClassName = szAppName;  // �����������

	if (!RegisterClass(&wndclass))  // ΪӦ�ó���Ĵ���ע��һ��������
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);  // ��ʾ��Ϣ��
		return 0;
	}

	// ���ڴ����ഴ��һ������ CreatWindow()�ķ���ֵΪһ��ָ�����������ڵľ�� windows��ÿһ�����ڶ���һ�����, �ڳ����п����þ���Դ��ڽ�������
	hwnd = CreateWindow(szAppName,   // window class name  ���������� ����ΪszAppName, ������ո�ע��Ĵ��ڵ�����. ������Ҫ�����Ĵ�������ͨ�����ַ�ʽ�봰���ཨ���˹���
		TEXT("The Hello Program"),    // window caption(����)
		WS_OVERLAPPEDWINDOW,          // window style  �������õ���һ����׼�Ĵ��ڷ��
		CW_USEDEFAULT,                // initial x position  ָ���˴������Ͻ��������Ļ���Ͻǵĳ�ʼλ��
		CW_USEDEFAULT,                // initial y position
		CW_USEDEFAULT,                // initial x size
		CW_USEDEFAULT,                // initial y size
		NULL,                         // parent window handle  ����½�����Ϊ��������(����Ӧ�ó��򴰿�), ����Ӧ�����ó�NULL
		NULL,                         // window menu handle 
		hInstance,                    // program instance handle  ����ʵ�����
		NULL);                        // creation parameters n. ������������parameter�ĸ����� �������� ���Խ��ò���ָ��ĳЩ���ݳ�Ա, �Ա�����ڳ����м�������

	// ��CreatWindow���÷���ʱ, ��������Windows�ڲ�����, windows�Ѿ�������һ���ڴ�������CreatWindow������ָ���Ĵ�����Ϣ�Լ�һЩ������Ϣ. windows����ͨ���������ȡ��Щ��Ϣ
	// ����, Ҫ��������ʾ����Ļ��, ���������ǲ����� 

	// ����Ļ����ʾ����  ��ʱ��ʾ�Ĵ�������Ч��, ��ΪӦ�ó���δ�ڿͻ����ϻ����κζ���, UpdateWIndow��post��ϢWM_PAINT
	ShowWindow(hwnd,  // ��һ��������CreatWindow���ڴ��д����Ĵ��ڵľ��
		iCmdShow);      // �ڶ���������WinMain���������ܵ�iCmdShowֵ, �ò��������Ŵ�������Ļ�ϳ�ʼ��ʾ����ʽ(����/���/��С��), �����SW_SHOWNORMAL, �򴰿ڵĿͻ������ڴ�������ָ���ı�����ˢ����;

	// ���ShowWindow()�ĵڶ���������SW_SHOWNORMAL, ��ô��ڵĿͻ��������ڴ���������ָ���ı�����ˢ����
	UpdateWindow(hwnd);  // ָʾ���ڶ�����������ػ�
	// ����ͨ�����ڹ��̷���һ��WM_PAINT��Ϣ����ɵ��ػ�

	while (GetMessage(&msg,  // ֻ����GetMessage�õ���һ����Ϣ, ���Ż᷵��;
		NULL, 0, 0))  // NULL, 0, 0�����ĳ���ϣ����ȡ�ɸó��򴴽������д��ڵ���Ϣ;
	{
		TranslateMessage(&msg);  // ����һЩ������Ϣ
		DispatchMessage(&msg);  // ��msg�ṹ������windows, ������ windows�Ὣ������Ϣ���͸����ʵĴ��ڹ���������
		// ֻ���ڴ��ڹ���ִ������, DispatchMessage�Ż᷵��;
	}

	return msg.wParam;  // msg�ṹ��wParam�ֶ��Ǵ��ݸ�PostQuitMessage������ֵ, ͨ�������Ϊ0, �÷�����佫��WinMain���˳�������������
}

LRESULT CALLBACK WndProc(HWND hwnd,  // ͨ��hwnd����֪���ǻ���ͬһ�����ഴ���Ķ�����ڵ��Ǹ����ڽ��յ�����Ϣ
						 UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;    // �豸�������
	PAINTSTRUCT ps;     // ��ͼ�ṹ
	RECT        rect;   // ���νṹ

	switch (message)
	{
	// WM_CREATE ��WndProc����ĵ�һ����Ϣ ��windows��WinMain�����д���CreatWindow�������õ�ʱ��, WndProc�����ܵ�����Ϣ
	// �ڳ������CreateWindowʱ, windows��������Ĳ���, �ڴ˹�����, windows��WndProc���е���, �������һ����������Ϊ�ô��ڵľ��, �����ڶ�����������ΪWM_CREATE
	// ͨ��, ���ڹ��̻���WM_CREATE��Ϣ�ڼ�Դ��ڽ���һ���Եĳ�ʼ��;
	case WM_CREATE:
		//MessageBox(hwnd, TEXT("�޷���������!"), TEXT("SoundError"), 0);
		PlaySound(TEXT("C:\\Users\\daxiong\\Desktop\\vs2012\\code\\Windows�������\\Windows�������\\p039����һ������.wav"), NULL, // ֻ�е������ļ���һ����Դʱ������;
			SND_FILENAME | SND_ASYNC);  // ��һ��������һ���ļ����Ҹö����������첽��ʽ���ŵ�, ������ָ���������ļ���ʼ���ŵ�ʱ��PlaySound������������, ����ȴ����ļ����Ž���;
		return 0;  // �����ڹ��̶���Ϣ���д������Ժ�Ӧ�÷���0
	
	// �����ڵĲ��ֻ�ȫ��"��Ч"�ұ���"����"��ʱ��, Ӧ�ó����õ���֪ͨ, ��Ҳ����ζ�Ŵ��ڱ����ػ�
	// �ͻ�����Ϊ��Ч�����: 1. �����ڱ��״δ�����ʱ��, �����ͻ���������Ч��, ��Ϊ��ʱӦ�ó�����δ�ڸô����ϻ����κζ���   -- ��һ��WM_PAINT��Ϣ��Ӧ�ó������WinMain�е�UpdateWindowʱ����, ��ָʾ���ڹ����ڴ��ڿͻ��������ػ�
						//	 2. �ڵ������ڵĳߴ��ʱ��, �ͻ���Ҳ���Ϊ��Ч  --  ǰ��ָʾwndclass�ṹ��style�ֶ�ΪCS_HREDRAM��CS_VREDRAM, �����ָʾwindows�����ڳߴ緢���仯��ʱ��, !��������! ��Ӧ������Ч, �ڴ�֮��, ���ڹ��̽����յ�һ��WM_PAINT��Ϣ
						//   3. ��С������, Ȼ�󽫴��ڻָ�.  --  ��ͼ�λ�����, ���������Ҫ����Ķ���̫����, �Դ�, windows��ȡ�Ĳ���������������Ч, ���ڹ��̽��յ�WM_PAINT��Ϣ��, �����лָ���������
						//   4. ����Ļ���϶����ڵ��´���֮�䷢���ص�ʱ, �������ǵ������ٺ������ٱ��ڵ�ʱ, ?����?�����Ϊ��Ч, ���ڹ����յ�WM_PAINT
	// ������ڹ��̲���WM_PAINT��Ϣ���д���, �������Ϣ���뽻��DefWindowsProc������, ��DefWindowsProc������ֻ�Ǽ򵥵�һ�ε���BeginPaint��EndPaint, ʹ�ÿͻ��������Ч
	case WM_PAINT:  // ��WM_PAINT��Ϣ�Ĵ���ͨ���ӵ���BeginPaint������ʼ, ��EndPaint��������
		// BeginPaint���� 1. ��ȥ��Ч����ı����Ա��ͼ(��WinMain��ʼ����ʱ��, ����ע�ᴰ�����WNDCLASS�ṹ�е�hbrBackground�ֶ�ָ����һ����ˢ, windows��ʹ�������ˢ����������)    2. ���ps�ṹ�ĸ����ֶ�
		hdc = BeginPaint(hwnd, &ps);  // BeginPaint�������ý�ʹ�������ͻ�����Ч, ������һ��"�豸�������" �豸���������ָ����������豸(����ʾ��)���������豸. ������Ҫ�豸����������ڴ��ڵĿͻ�����ʾ�ı���ͼ�� �豸��������޷��ڿͻ��������������л���
		
		GetClientRect(hwnd, &rect);  // �����ھ���Ŀͻ�����Ⱥ͸߶���Ϣ���ݸ�rect���νṹ

		DrawText(hdc, TEXT("Hello, the coding young man!"), -1/*��ʾ�ı��ַ�����0��β*/, &rect,  // ��rect���Ƶľ�������ʾ
			DT_SINGLELINE | DT_CENTER | DT_VCENTER/*�ı�Ӧ����rect�޶��ľ�����������ʾ, ����ˮƽ�ʹ�ֱ����*/);  // ��ʾһ���ı��ַ���
		EndPaint(hwnd, &ps);  // EndPaint���������ͷ��豸�������, ʹ����Ч
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);  // ��"WM_QUIT(�˳�)"��Ϣ������Ϣ���� GetMessage������WM_QUIT��Ϣ����0, ʹ���˳���Ϣѭ��
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);  // ִ��Ĭ�ϵ���Ϣ���� ���д��ڹ��̲����д������Ϣ�����봫������ΪDefWindowProc����, ��������ķ���ֵ����Ӵ��ڹ��̷���
}