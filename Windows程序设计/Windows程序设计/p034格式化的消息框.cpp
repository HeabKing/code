#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int CDECL MessageBoxPrintf(TCHAR * szCaption, TCHAR * szFormat, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList;  // typedef char * va_list;
	va_start(pArgList, szFormat);// pArgList = (char *) &szFormat + sizeof(szFormat); va_start�꽫pArg��Ϊָ��һ���ڶ�ջ����szFormat֮�ϵĶ�ջ����
	// va_arg(pArgList, int); �����ȡ��һ��int����ָ��ָ��sizeof(int)֮���ָ��;
	_vsntprintf_s(szBuffer, sizeof(szBuffer) / sizeof(TCHAR),  // ����ǿ��ַ�, ���صĽ�����ʵ���ַ�2�����ֽ���, ��������Ҫ����sizeof(TCHAR)
		szFormat, pArgList);
	va_end(pArgList);

	return MessageBox(NULL, szBuffer, szCaption, 0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	int cxScreen, cyScreen;

	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrintf(TEXT("ScrnSize"), TEXT("The screen is %i pixels wide by %i pixels high."), cxScreen, cyScreen);

	return 0;
}