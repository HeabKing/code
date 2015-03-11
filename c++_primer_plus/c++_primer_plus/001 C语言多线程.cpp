#include <iostream>
#include <process.h>
#include <string>
#include <windows.h>
using namespace std;

void thread0(void * pparams)
{
	string paramlocal = *(string *)pparams;
	cout << "thread0: " << paramlocal << endl;
	_endthread();
}

typedef struct
{
	string strParam;
	HANDLE handleParam;
} PARAM;

void thread1(void * pparams)
{
	PARAM temp = *(PARAM *)pparams;
	WaitForSingleObject(temp.handleParam, INFINITE);	// infinite
	cout << "Thread1: " << temp.strParam << endl;
}

int main()
{
	cout << "����һ���߳�0: \n";
	string param = "�������̴߳����߳�0������";
	_beginthread(thread0, 0, &param);

	HANDLE hEvent = CreateEvent(nullptr, false, false, nullptr);
	string strparam = "�������̴߳����¼��߳�1������";
	PARAM P = {strparam, hEvent};
	_beginthread(thread1, 0, &P);
	Sleep(2000);
	SetEvent(hEvent);

	Sleep(20);
}