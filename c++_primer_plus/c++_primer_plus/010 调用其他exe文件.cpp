// Build: 2014-10-11 17:46:36
// system();	�൱��ֱ����dos��д������
// WinExec��Ϊ�򵥣�ShellExecute��WinExec���һЩ��CreateProcess��Ϊ����;

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	system("\"010 Console ִ��������س�.exe\"");
	cout << "ִ�� 010 Console ִ��������س�.exe ���\n";

	system("\"010 Console ִ�����˳�.exe\"");
	cout << "ִ�� 010 Console ִ�����˳�.exe ���\n";

	system("���۴���ͳ����.exe");
	cout << "ִ�� ���۴���ͳ����.exe ���\n\n";


	WinExec("\"010 Console ִ��������س�.exe\"", SW_HIDE /*SW_SHOW*/);	 // ������񿪱�������һ���߳�	 ���ڿ���̨ SW_HIDE SW_SHOW��һ��, ������ͬһ������̨
	cout << "ִ�� 010 Console ִ��������س�.exe ���\n";

	WinExec("\"010 Console ִ�����˳�.exe\"", SW_SHOW);
	cout << "ִ�� 010 Console ִ�����˳�.exe ���\n";

	WinExec("���۴���ͳ����.exe", SW_SHOWMINIMIZED /*SW_HIDE*/ /*SW_SHOW*/);
}