// �����Bug:
//			Ϊʲô����Զ������껬����ʱ����˸;
// ֤���ı��ӿ�ԭ�㴰��ԭ����Ÿı�, �ı䴰��ԭ��, �ӿ�ԭ�㲻��;
// ע��: GetViewportOrgEx��GetWindowOrgEx���ǵõ��� �ӿ�ԭ�� ������, ֻ��һ�����豸����ϵ�µ�, һ�����߼�����ϵ�µ�;!!!!!!!!!!!!!!!!!!!!
// �ո�������ú����ӿ�ԭ��, ���һ�һ��ӿ�ԭ���ֻص������Ͻ�, ������Ϊ���ʱWM_PAINT��hdc��ִ�����˺�ͱ�������, Ȼ���һ�����WM_PAINT�Ժ����µ�hdc;
// ��סһ��: GetViewportOrgEx��GetWindowOrgEx���ص�ֵ�ھ���DPtoLP����Զ���;
#define SZAPPNAME "p147�ӿںʹ���.cpp"
#include "DX_WinMain.cpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT  ps;
	HDC          hdc;
	static POINT ptViewport, ptWindow;
	TCHAR        szBuffer[100];
	static enum{Neither, View, Wnd, All}ViewOrWnd = Neither;

	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);

		SetPixel(hdc, ptViewport.x, ptViewport.y, RGB(0xff, 0, 0));
		SetPixel(hdc, ptWindow.x, ptWindow.y, RGB(0xff, 0, 0));

		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		// �ӿ�ԭ�����ز���
		if (ViewOrWnd == View || ViewOrWnd == All)  // ѡ�������ӿڻ��Ǵ���(�������˻����һ���);
			SetViewportOrgEx(hdc, ptViewport.x, ptViewport.y, NULL);
		if (!GetViewportOrgEx(hdc, &ptViewport))
			MessageBox(NULL, TEXT("δ�ܳɹ���ȡ�ӿ�ԭ��"), TEXT("Error"), MB_ICONERROR);
		else
		{
			POINT ptTemp;
			ptTemp = ptViewport;  // ������������TextOut������߼�����ֵ;
			DPtoLP(hdc, &ptViewport, 1);  // GetViewprotOrgEx ��ȡ�����豸����ϵͳ��ֵ, Ҫת�����߼�����ֵ;
			TextOut(hdc, ptViewport.x, ptViewport.y, szBuffer, wsprintf(szBuffer, TEXT("�����ӿ�ԭ��: (%d, %d)"), ptTemp.x, ptTemp.y));
			MoveToEx(hdc, ptViewport.x + 100, ptViewport.y, NULL);
			LineTo(hdc, ptViewport.x, ptViewport.y);
			LPtoDP(hdc, &ptViewport, 1);  // ����Ҫ���û��豸����, ptViewport�Ǹ�static, Ҫ��֤�´ν���WM_PAINT��ʹû�����SetViewportOrgExʹ�õ�ʱ�����豸���굥λ�������߼����굥λ!
		}
		
		// ����ԭ�����ز���
		if (ViewOrWnd == Wnd || ViewOrWnd == All)
			SetWindowOrgEx(hdc, ptViewport.x - ptWindow.x, ptViewport.y - ptWindow.y, NULL);  // ���ô���ԭ��
		if (!GetWindowOrgEx(hdc, &ptWindow))
			MessageBox(NULL, TEXT("δ�ܳɹ���ȡ����ԭ��"), TEXT("Error"), MB_ICONERROR);
		else
		{
			// ����ӿ�ԭ���봰��ԭ����ͬһλ��, �������
			if (0 == ptWindow.x && 0 == ptWindow.y)
				TextOut(hdc, ptWindow.x + 200, ptWindow.y, szBuffer, wsprintf(szBuffer, TEXT("���ô���ԭ��: (%d, %d)"), ptWindow.x, ptWindow.y));
			else
				TextOut(hdc, 0, 0, szBuffer, wsprintf(szBuffer, TEXT("���ô���ԭ��: (%d, %d)"), ptWindow.x, ptWindow.y));
			
			MoveToEx(hdc, 0, 0 + 100, NULL);
			LineTo(hdc, 0, 0);
		}

		// �ڹ̶���������������߼�����������İ취
		POINT ptTemp2;
		ptTemp2.x = 500;
		ptTemp2.y = 0;
		DPtoLP(hdc, &ptTemp2, 1);
		if (ptWindow.x == 0 && ptWindow.y == 0)
			TextOut(hdc, ptTemp2.x, ptTemp2.y, TEXT("�ӿ�ԭ���봰��ԭ���� ͬһ�� λ��"), lstrlen(TEXT("�ӿ�ԭ���봰��ԭ���� ͬһ�� λ��")));
		else
			TextOut(hdc, ptTemp2.x, ptTemp2.y, TEXT("�ӿ�ԭ���봰��ԭ���� ��ͬ�� λ��"), lstrlen(TEXT("�ӿ�ԭ���봰��ԭ���� ��ͬ�� λ��")));

		EndPaint(hwnd, &ps);
		return 0;
  
	case WM_LBUTTONDOWN:
		// ���ʱ, �����λ�ñ�������, ����Ϊ�ӿ�ԭ��
		ptViewport.x = LOWORD(lParam);
		ptViewport.y = HIWORD(lParam);
		ViewOrWnd    = View;
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_RBUTTONDOWN: 
		// �һ�ʱ, �����λ�ñ�������, ����Ϊ����ԭ��
		ptWindow.x = LOWORD(lParam);
		ptWindow.y = HIWORD(lParam);  // ��ȡ���λ��DP
		ViewOrWnd  = Wnd;
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	// �����������
	case WM_MOUSEMOVE:
		WM_MouseMove_ShowCoordinate(hwnd, message, wParam, lParam);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}