// ���õݹ�ʵ�ֽ��Ƶ�ת��
#include <iostream>
#include <cstdio>
void change(long long int);
int main()
{
	using namespace std;
	long long int input;

	puts ("������Ҫ���н���ת��������: (�������˳�)");
	while (cin >> input)
	{
		if (input <= 0)
		{
			cout << "�������, ���������0������!\n";
			cin.clear();
			continue;
		}
		else
		{
			cout << "������: "; 
			change(input);
			printf ("\n�˽���: %#o\n", input);
			printf ("16����: %#x\n", input);
		}
	}

	return 0;
}

void change(long long int input)
{
	using namespace std;
	if (input >= 2)
		change(long long int(input / 2));
	cout << input % 2;
}