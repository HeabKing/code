// �������߳̽�����, ������Ҫ֪ͨ���߳�, ����, ��ʱ���߳�Ҳ��Ҫ֪ͨ�����߳���ֹ����, ��������ݾ�չʾ�����ʵ�����̺߳Ͷ����߳�֮��Ľ���
// �ڿͻ����������, ���ڹ��̰�iStatus���ó�STATUS_WORKING, ����ʼ��PARAMS�������ֶ�, hwnd�ֶα�����Ϊ���ھ��, bContinue������ΪTRUE, ���Ŵ��ڹ��̵���_beginthread()����(������ֱ����WM_CREATE��ʱ������������)
// KillThread����ֻ���������˳�û��ʵ�ֵ�ʱ���ʹ��, ����Ҫ��Ϊ�˷�ֹ��Դ(���������ڴ�)�޷��ͷ�, ����ڴ����˳�ʱû�б��ͷ�, ���ͻ�һֱռ���ǿ��ڴ�, �̲߳��ǽ���: ��Ϊͬһ������������Դ�ᱻ�����̹߳���, �����߳��˳�ʱ��Դ���ᱻ�Զ��ͷ�, �õĳ������Ҫ���߳��ڽ���ʱ�ͷ������������Դ
#include <windows.h> 
#include <math.h> 
#include <process.h> 
#define REP      1000000	// 100W
#define STATUS_READY		0
#define STATUS_WORKING      1 
#define STATUS_DONE			2 
#define WM_CALC_DONE		(WM_USER + 0)	// �ɹ�����100W�μ���
#define WM_CALC_ABORTED     (WM_USER + 1)	// �ڽ��м����ʱ�����߳�(�û����Ҽ�����)��ֹ
typedef struct	// ����һ����̬�ṹ�����ڴ��ڹ��̺Ͷ����߳�֮�乲������
{ 
	HWND hwnd ; 
	BOOL bContinue ;	// ����ָʾ�߳��Ƿ�Ӧ�ü�������
} PARAMS, *PPARAMS ; 
LRESULT APIENTRY	WndProc (HWND, UINT, WPARAM, LPARAM) ; 
int		WINAPI		WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{ 
	static TCHAR	szAppName[] = TEXT ("BigJob1") ; 
	HWND			hwnd ; 
	MSG				msg ; 
	WNDCLASS		wndclass ; 
	
	wndclass.style				= CS_HREDRAW | CS_VREDRAW ; 
	wndclass.lpfnWndProc		= WndProc ; 
	wndclass.cbClsExtra			= 0 ; 
	wndclass.cbWndExtra			= 0 ; 
	wndclass.hInstance			= hInstance ; 
	wndclass.hIcon				= LoadIcon (NULL, IDI_APPLICATION) ; 
	wndclass.hCursor			= LoadCursor (NULL, IDC_ARROW) ; 
	wndclass.hbrBackground		= (HBRUSH) GetStockObject (WHITE_BRUSH) ; 
	wndclass.lpszMenuName		= NULL ; 
	wndclass.lpszClassName		= szAppName ; 

	if (!RegisterClass (&wndclass)) 
	{ 
		MessageBox (  NULL, TEXT ("This program requires Windows NT!"), szAppName, MB_ICONERROR) ; 
		return 0 ; 
	} 
	hwnd = CreateWindow (	szAppName, TEXT ("Multithreading Demo"), 
							WS_OVERLAPPEDWINDOW, 
							CW_USEDEFAULT, CW_USEDEFAULT, 
							CW_USEDEFAULT, CW_USEDEFAULT, 
							NULL, NULL, hInstance, NULL) ; 
	ShowWindow (hwnd, iCmdShow) ; 
	UpdateWindow (hwnd) ; 
	while (GetMessage (&msg, NULL, 0, 0)) 
	{ 
		TranslateMessage (&msg) ; 
		DispatchMessage (&msg) ; 
	} 
	return msg.wParam ; 
} 
void Thread (PVOID pvoid) 
{ 
	double		A = 1.0 ; 
	INT			i ; 
	LONG		lTime ; 
	volatile    PPARAMS pparams ;	// ʹ��volatileָ���ñ�����������ִ��֮�ⱻ�޸�(����ͨ����һ���߳�), ����������Ż����ܻ�������ÿ��ѭ���м��bContinue�Ĵ�����Ϊ����ѭ����û�б��޸�, volatile��ֹ�����Ż�
	pparams	=	(PPARAMS) pvoid ; 
	lTime	=	GetCurrentTime () ;	// �Ժ���Ϊ��λ��ȡ��ǰʱ��

	for (i = 0 ; i < REP && pparams->bContinue ; i++)	// ѭ��100W�μ���, �ڼ�ֻ��ͨ�����̵߳Ķ�bContinue�ĸ�������ֹ����
		A = tan (atan (exp (log (sqrt (A * A))))) + 1.0 ; 
	if (i == REP)	// ��������100W�μ���
	{ 
		lTime = GetCurrentTime () - lTime ;	// �ٴε���GetCurrentTime()���㾭����ʱ�� 
		SendMessage (pparams->hwnd, WM_CALC_DONE, 0, lTime) ;	// ���������Ϣ
	} 
	else 
		SendMessage (pparams->hwnd, WM_CALC_ABORTED, 0, 0) ;	// ���㱻��ֹ��Ϣ
	_endthread () ; 
} 
LRESULT CALLBACK WndProc (  HWND  hwnd,  UINT  message,  WPARAM  wParam,  LPARAM lParam) 
{ 
	static    INT		iStatus ; 
	static    LONG      lTime ; 
	static    PARAMS	params ; 
	static    TCHAR *	szMessage[]  =  {  TEXT  ("Ready  (left  mouse  button begins)"), TEXT ("Working (right mouse button ends)"), TEXT ("%d repetitions in %ld msec") } ; 
	HDC					hdc ; 
	PAINTSTRUCT			ps ; 
	RECT				rect ; 
	TCHAR				szBuffer[64] ; 
	switch (message) 
	{ 
	case    WM_LBUTTONDOWN: 
		if (iStatus == STATUS_WORKING) 
		{ 
			MessageBeep (0) ; 
			return 0 ; 
		} 
		iStatus				= STATUS_WORKING ; 
		params.hwnd			= hwnd ; 
		params.bContinue	= TRUE ; 
		_beginthread (Thread, 0, &params) ;	// ���û������ͻ����Ժ�ʼִ�ж����߳�
			// ÿ��ִ�����������ʱ�򶼴���һ���µ��߳�, ���ڽ�����ʱ����ֹ����߳�, ��Ȼ, ������Ҫһ�ָ�����Ч���߳�ʹ�÷�ʽ
				// 1.	һ��˼·���ڳ����������������ֻ����һ������һ�������߳�, ������Ҫ��ʱ��ŵ�������߳�, ������ "�¼�" ������֮��;
				// 2.	һ���¼�����������״̬: �ѱ�����(����)��δ������(��λ)
				// 3.	����һ���¼�����: hEvent = CreateEvent(&sa, fManula, fInitial, pszName);
					// &sa, һ��ָ��SECURITY_ATTRIBUTES�ṹ��ָ��, pszNameֻ���¼������ڽ��̼乲��ʱ��������, ��һ��������, ��Щ����ͨ��������ΪNULL. fManulaָʾ�¼��Ĵ���״̬
					// setEvent(hEvent) ����һ�������¼��Ķ��� ResetEvent(hEvent)�Ӵ�һ���¼�����Ĵ���״̬ WaitForSingleObject(hEvent, dwTimeout) �ȴ�һ���¼�������, ����¼������Ѿ�������, ������������, ����, �����ͻ�ȴ�dwTimeout����, dwTimeOut�����ó�INFINITE, �����ͻ�һֱ���¼����󱻴����ŷ���, ����ʼCreateEvent������fManual���������ó�false, ��ô������WaitForSingleObject���غ�, �¼������״̬�ᱻ�Զ�����Ϊδ����, �����Ͳ��õ���ResetEvent����ȥ�����¼�����״̬

		InvalidateRect (hwnd, NULL, TRUE) ; 
		return 0 ; 
	
	case    WM_RBUTTONDOWN: 
		params.bContinue = FALSE ; 
		return 0 ; 
	
	case    WM_CALC_DONE: 
		lTime	= lParam ; 
		iStatus = STATUS_DONE ; 
		InvalidateRect (hwnd, NULL, TRUE) ; 
		return 0 ; 
	
	case    WM_CALC_ABORTED: 
		iStatus = STATUS_READY ; 
		InvalidateRect (hwnd, NULL, TRUE) ; 
		return 0 ; 
	
	case    WM_PAINT: 
		hdc = BeginPaint (hwnd, &ps) ; 
		GetClientRect (hwnd, &rect) ; 
		wsprintf (szBuffer, szMessage[iStatus], REP, lTime) ; 
		DrawText (hdc, szBuffer, -1, &rect, 
		DT_SINGLELINE | DT_CENTER | DT_VCENTER) ; 
		EndPaint (hwnd, &ps) ; 
		return 0 ; 
	
	case    WM_DESTROY: 
		PostQuitMessage (0) ; 
		return 0 ; 
	} 
	return DefWindowProc (hwnd, message, wParam, lParam) ; 
}