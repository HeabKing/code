// �����嵥 9.9
#include <iostream>
// constants(����)
const int ArSize = 10;
// function prototype(ԭ��)
extern "C++" void strcount(const char * str); // extern ˵����Ϊ�ⲿ���Ӿ�̬����, extern�ǿ�ѡ��, ������static����Ϊֻ�ڱ��ļ�ʹ��
	// "c++" ˵����ָ��ʹ�õ���"c++"������������
extern const int i = 1;

int main()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, ArSize);  // �������ArSize���ַ�, �����뻻�з������������������
	while (cin)             // ��ͼ��cin.get(char *, int); ��ȡ���н��ᵼ��cinΪfalse
	{
		cin.get(next);
		while (next != '\n') // string didn't fit!(����)
			cin.get(next);   // dispose(����) of remainder 
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArSize);
	}
	cout << "Bye.\n";

	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0;  // static local variable
	int count = 0;         // auto local variable

	cout << "\"" << str << "\" contains ";
	while (*str++)   // go to end of string
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}