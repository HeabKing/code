// �����嵥 5.18
#include <iostream>
int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	//cin.get(ch);
	while (EOF != (ch = cin.get())) // ��cin.get()û�в�����ʱ��, ���᷵�ض�ȡ���ַ�
	//while (cin.get(ch))
	//while (cin)                // ����cin.get(char)����ֵ��һ��cin����Ȼ��istream���ṩ��һ�����Խ�istream����(��cin)ת����boolֵ�ĺ���, ��cin��������Ҫboolֵ�ĵط�ʱ, �ú�����������, ���� �����ȡ�ɹ��˷���ֵΪtrue����Ϊfalse
	//while (cin.fail() == false) // text for EOF
	{
		//cout << ch;           // echo character
		++count;
		//cin.get(ch);
	}
	cout << endl << count << " characters read\n";

	return 0;
}
// �����������:
// 12[ctrl+z]34
// [ctrl+z]
// ��ôͳ�Ƴ������� 3���ַ�, ��ֻͳ����12[ctrl+z]
// ###### ģ��EOF���ַ������[Ctrl+z]+[Enter]