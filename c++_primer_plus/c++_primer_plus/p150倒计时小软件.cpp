// ��ϰ: 2014 08 15
// ��ϰ: 2014 08 18 # 1 ���е�ʱ��Ī������Ĳ�ˢ��ʱ����

// ��д���
#include <iostream>
#include <ctime>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "winmm.lib")	// ��֤PlaySound()��ִ��
bool isStop = false;
void playsound(void *)
{
	if (!isStop)
		PlaySound(L"C:\\Users\\daxiong\\desktop\\VS2012\\Code\\Windows���򷢲�\\Windows���򷢲�\\����2048��Ϸ1.0��������.wav", NULL, SND_FILENAME | SND_ASYNC);
	else
		PlaySound(nullptr, nullptr, SND_FILENAME | SND_ASYNC);
	_endthread();	// # 1
}
int main()
{
	using namespace std;
	cout << "������Ҫ�ӳٵ�ʱ��(��):\n";
	float input;
	while (cin >> input)
	{
		isStop = true;
		_beginthread(playsound, 0, nullptr);
		clock_t delay = static_cast<clock_t>(input * CLOCKS_PER_SEC);
		clock_t start;
		start = clock();
		int i = 1;
		//int c;
		clock_t temp;
		while((temp = clock() - start) < delay)
		{
			if ((clock() - start) / CLOCKS_PER_SEC > i )	// �������Է�ֹ���ٷ�����������1s�ж�û��ִ��������һ�������i��Զ�޷����¸��� clock() - start # 1    -- ����ǵ��²����µ�ԭ����? 
			//if (clock() - start == i * CLOCKS_PER_SEC)// ???????????Ϊʲô������???	// ��Ϊ��ȵ�������������ִ�б������ʱ������ # 1
			{
				system("cls");
				cout << --input << "\n";
				i++;
			}
		}
		cout << "ʱ�䵽��!\a\a\a\a\a\n";
		isStop = false;
		_beginthread(playsound, 0, nullptr);
		cout << "������Ҫ�ӳٵ�ʱ��(��):\n";
	}

	return 0;
}