// Build: 2014-10-5 19:01:10
// ��̬���Ӳ���Ҫ.lib��.h�ļ�
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HINSTANCE hInst = LoadLibrary(TEXT("C++ DLL.dll"));	// ӳ��ָ���Ŀ�ִ��ģ�鵽һ�����ý��̵ĵ�ַ�ռ�
		// �˺������Լ��ڶ�̬��Ҳ���Լ��ؿ�ִ�г���
		// ����ģ��ľ��HMODULE, ������ʵ�����ͨ��

	typedef int (*ADDPROC)(int a, int b);
	//ADDPROC Add = (ADDPROC)GetProcAddress(hInst, "add");
	ADDPROC Add = (ADDPROC)GetProcAddress(hInst, MAKEINTRESOURCEA(1)); // ʹ�����ʵ�ֵ��� MAKEINTERSOURCE(1)�����ת����һ���ַ���
		// ��ȡָ���ĵ�����̬�⺯���ĵ�ַ
		// �ɹ�: ���ض�̬���ӿ�ĵ�ַ    ʧ��: null
	
	if (!Add)
		MessageBox(nullptr, TEXT("��ȡ������ַʧ��"), nullptr, MB_OK);
	else
	{
		WCHAR buf[20];
		wsprintf(buf, TEXT("5 + 3 = %d"), Add(5, 3));
		MessageBox(nullptr, buf, nullptr, MB_OK);
	}
}